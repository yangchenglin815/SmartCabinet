#pragma once

#include <QObject>
#include <QMutex>
#include "CommEnum.h"
#include "mtmqsqlbase.h"

class DBOperate : public QObject
{
	Q_OBJECT

public:
	static DBOperate* instance();

	void initSQLParams(const QString strDatabaseName,
		const QString strServerHostName = "127.0.0.1",
		const QString strUserName = "root",
		const QString strPassword = "123456",
		int intPort = 3306,
		int type = _LocalSql,
		const QString strDBType = "mysql");

	void setTableNames(QStringList TableNames);

private:
	DBOperate(QObject *parent = 0);
	virtual ~DBOperate();

	bool isOnline();

public slots:
	void OnStartSync();

signals:
	void DBSyncSignal();

private:
	static DBOperate* m_pInstance;
	MtmQSQLBase *m_LocalSql;
	MtmQSQLBase *m_ServerSql;

	QStringList m_listTableName;
	QString m_ServerSqlIp;
	QMutex m_dbLocker;
	bool m_isSynOk;

	int m_nTime;
	int m_nCountofSynFailed;
};
