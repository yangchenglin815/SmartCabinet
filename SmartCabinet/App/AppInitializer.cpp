#include "AppInitializer.h"
#include <QMetaType>
#include <string>
#include <QDateTime>
#include <QDir>
#include <QTimer>
#include "UserConfig.h"
#include "GlogManager.h"
#include "DataPathManager.h"
#include "FileManager.h"
#include "SystemChecker.h"
#include "DBOperate.h"
#include "SmartCabinetFactory.h"
#include "SmartCabinetCharge.h"

AppInitializer::AppInitializer(QObject *parent) : QObject(parent)
{

}


AppInitializer::~AppInitializer(void)
{

}

void AppInitializer::initLog()
{
    //���������־
	clearOutdatedLogs();

    //��־ϵͳ��ʼ��
	INSTANCE_GLOG_MANAGER->init();
    INSTANCE_GLOG_MANAGER->setLogFileDir(DataPathManager::getLogDirPath().c_str());
    INSTANCE_GLOG_MANAGER->setInfoLogPrefix("Info");
    INSTANCE_GLOG_MANAGER->setWarningLogPrefix("Warnig");
    INSTANCE_GLOG_MANAGER->setErrorLogPrefix("Error");
    INSTANCE_GLOG_MANAGER->setMaxLogSize(5);
    INSTANCE_GLOG_MANAGER->setStopLoggingIfFullDisk(true);
    INSTANCE_GLOG_MANAGER->setLogbufCacheTime(0);
}

void AppInitializer::init()
{
    //��ʼ��
	initSingleObjects();
    initLog();
    checkDataDirs();
    //clearOutdatedLogs();
	initDatabase();
	initFactory();
}

void AppInitializer::checkDataDirs()
{
    //������Ӧ���ļ���
	QString logsDirPath = QString::fromLocal8Bit(DataPathManager::getLogDirPath().c_str()); 
	QString dumpDirPath = QString::fromLocal8Bit(DataPathManager::getDumpDirPath().c_str());
    FileManager::createDir(logsDirPath);
	FileManager::createDir(dumpDirPath);
}

void AppInitializer::clearOutdatedLogs()
{
    //������ڵ���־��Ϣ
	QString logsDir = QString::fromLocal8Bit(DataPathManager::getLogDirPath().c_str()); 
    QDir dir(logsDir);
    if (dir.exists()) {
        dir.setFilter(QDir::Files); 
        int currentDate = QDateTime::currentDateTime().toString("yyyyMMdd").toInt(); 
        foreach (QFileInfo mfi ,dir.entryInfoList()) {
            int logDate = mfi.fileName().mid(4, 8).toInt(); 
            if (currentDate - logDate > 7) { //ɾ��1������ǰ����־
                if (!QFile::remove(logsDir + "\\" + mfi.fileName())){
					LOG(ERROR)<<"�Ƴ���־�ļ�ʧ��!";
				}
            }
        }
    }
	else{
		LOG(ERROR)<<"Ӧ����־Ŀ¼������!";
	}
}


void AppInitializer::initDatabase()
{
	QString strConfigTableName = UserConfig::getInstance()->readSetting("MySql", "SYNTableName");
	DBOperate::instance()->setTableNames(strConfigTableName.split("|"));

	QString host     = UserConfig::getInstance()->readSetting("MySql", "Host");
	QString dataBase = UserConfig::getInstance()->readSetting("MySql", "DataBase");
	QString user     = UserConfig::getInstance()->readSetting("MySql", "User");
	QString pass     = UserConfig::getInstance()->readSetting("MySql", "Pwd");
	int     port     = UserConfig::getInstance()->readSetting("MySql", "Port").toInt();
	DBOperate::instance()->initSQLParams(dataBase, host, user, pass, port, _LocalSql);

	host     = UserConfig::getInstance()->readSetting("SqlRemote", "Host");
	dataBase = UserConfig::getInstance()->readSetting("SqlRemote", "DataBase");
	user     = UserConfig::getInstance()->readSetting("SqlRemote", "User");
	pass     = UserConfig::getInstance()->readSetting("SqlRemote", "Pwd");
	port     = UserConfig::getInstance()->readSetting("SqlRemote", "Port").toInt();
	DBOperate::instance()->initSQLParams(dataBase, host, user, pass, port, _ServerSql);
}


void AppInitializer::initFactory()
{
	SmartCabinetFactory::instance()->RegisterSmartCabinet("SmartCabinetCharge", new SmartCabinetCharge);
}

void AppInitializer::initSingleObjects()
{
	//ʵ��������
	INSTANCE_USER_CONFIG;
	INSTANCE_GLOG_MANAGER;
}