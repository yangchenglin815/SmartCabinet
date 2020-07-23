#include "DBOperate.h"
#include "GlogManager.h"
#include "SqlTool.h"

#include <QProcess>
#include <QtConcurrent>

DBOperate* DBOperate::m_pInstance = Q_NULLPTR;

DBOperate* DBOperate::instance()
{
	if (m_pInstance == Q_NULLPTR)
	{
		m_pInstance = new DBOperate;
	}
	return m_pInstance;
}

void DBOperate::initSQLParams(const QString strDatabaseName, const QString strServerHostName /*= "127.0.0.1"*/, 
	const QString strUserName /*= "root"*/, const QString strPassword /*= "123456"*/, int intPort /*= 3306*/, 
	int type /*= _LocalSql*/, const QString strDBType /*= "mysql"*/)
{
	if (_LocalSql == type)
	{
		m_LocalSql->initSQLParameter(strDatabaseName, strDBType, strServerHostName, strUserName, strPassword, intPort);
	}
	else if (_ServerSql == type)
	{
		m_ServerSqlIp       = strServerHostName;
		m_nCountofSynFailed = 0;
		m_ServerSql->initSQLParameter(strDatabaseName, strDBType, strServerHostName, strUserName, strPassword, intPort);
	}
}

void DBOperate::setTableNames(QStringList TableNames)
{
	m_listTableName = TableNames;
}

DBOperate::DBOperate(QObject *parent)
	: QObject(parent)
	, m_nTime(100000)
	, m_LocalSql(new MtmQSQLBase)
	, m_ServerSql(new MtmQSQLBase)
	, m_isSynOk(true)
{
	connect(this, &DBOperate::DBSyncSignal, this, &DBOperate::OnStartSync, Qt::QueuedConnection);
}

DBOperate::~DBOperate()
{
	if (NULL != m_LocalSql)
		delete m_LocalSql;

	if (NULL != m_ServerSql)
		delete m_ServerSql;
}

bool DBOperate::isOnline()
{
	bool ret = false;
	QProcess *cmd = new QProcess;
#ifdef _TTY_ARMV4_
	QString strArg = "ping -s 1 -c 1 " + m_ServerSqlIp;        //linux平台下的格式
#else
	QString strArg = "ping " + m_ServerSqlIp + " -n 1 -w " + QString::number(1000);  //windows下的格式
#endif
	cmd->start(strArg);
	cmd->waitForReadyRead();
	cmd->waitForFinished();

	QString retStr = cmd->readAll();
	if (retStr.indexOf("TTL") != -1)
	{
		ret = true;
		LOG(INFO) << _QLOG(m_ServerSqlIp) << "is online!\n";
	}
	else
	{
		ret = false;
		LOG(WARNING) << "error" << _QLOG(m_ServerSqlIp) << "is offline!\n";
	}
	retStr.clear();
	return ret;
}

void DBOperate::OnStartSync()
{
	m_isSynOk = false;
	LOG(INFO) << "start();";
}
