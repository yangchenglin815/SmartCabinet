#include "mtmqsqlbase.h"

#include <QFileInfo>
#include <QCoreApplication>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlField>

#include "GlogManager.h"

MtmQSQLBase::MtmQSQLBase()
{
    m_isDebugMode = false;
}

MtmQSQLBase::~MtmQSQLBase()
{


    if(isOpen())
    {
        m_DB.close();
    }
}

void MtmQSQLBase::initSQLParameter(const QString strDatabaseName,const QString strDBType,const QString strServerHostName,const QString strUserName,const QString strPassword,int intPort)
{
    mutex.lock();

    m_strDBType = strDBType.toUpper();

    //mysql数据库
    if(m_strDBType == "QMYSQL" || m_strDBType == "MYSQL")
    {
        m_strDBType = "QMYSQL";
    }
    //sqlite3
    else if(m_strDBType == "QSQLITE" || m_strDBType == "SQLITE" || m_strDBType == "SQLITE3")
    {
        m_strDBType = "QSQLITE";
    }
    //sqlite3encrypt
    else if(m_strDBType == "QZSQLITE" || m_strDBType == "ZSQLITE" || m_strDBType == "QZSQLITE3")
    {
        m_strDBType = "QZSQLITE";
    }
    //其他数据库
    else
    {
        m_strDBType = "";

        LOG(INFO) << "DB type name invalid !";

        mutex.unlock();

        return;
    }

    if(m_strDBType == "QMYSQL" || m_strDBType == "QSQLITE" )
    {
        QString conname;
        QThread::msleep(1);
        {
            m_DB = QSqlDatabase();
            m_DB = QSqlDatabase::addDatabase(m_strDBType, QTime::currentTime().toString("hhmmsszzz"));
            //conname = QSqlDatabase::database().connectionName();
        }//超出作用域，隐含对象QSqlDatabase被删除。
        //QSqlDatabase::removeDatabase(conname);
    }
    else if(m_strDBType == "QZSQLITE")
    {
        QThread::msleep(1);
        {
//            m_DB = QSqlDatabase();
//            m_DB = QSqlDatabase::addDatabase(p_sqliteEncryptDriver, QTime::currentTime().toString("hhmmsszzz"));
        }//超出作用域，隐含对象QSqlDatabase被删除。

    }
    else
    {

    }

    {
        //QZSQLITE 多次调用崩溃
        query = QSqlQuery(m_DB);
    }//超出作用域，隐含对象QSqlQuery被删除。

    m_strDatabaseName = strDatabaseName;
    m_strLocalHostName = strServerHostName;
    m_strUserName = strUserName;
    m_strPassword = strPassword;
    m_intPort = intPort;

    mutex.unlock();
}


void MtmQSQLBase::setDebugMode(bool isDebugMode)
{
    m_isDebugMode = isDebugMode;
}

QString MtmQSQLBase::getDatabaseName()
{
    return m_strDatabaseName;
}

void MtmQSQLBase::setDatabaseName(QString strDatabaseName)
{
    m_strDatabaseName = strDatabaseName;
}

bool MtmQSQLBase::connectDB(bool isReconnect)
{
    mutex.lock();

    bool bRet = false;

    if(isOpen())
    {
        if(isReconnect)
        {
            closeDB();

            if("QMYSQL" == m_strDBType)
            {
                bRet = connectMySQL(m_strLocalHostName, m_strDatabaseName, m_strUserName, m_strPassword,m_intPort);
            }
            else if("QSQLITE" == m_strDBType)
            {
                bRet = connectSQLite3(m_strDatabaseName);
            }
            else if("QZSQLITE" == m_strDBType)
            {
                bRet = connectZSQLite3(m_strDatabaseName,m_strPassword);
            }
            else
            {
                bRet = false;
            }
        }
        else
        {
            bRet = true;
        }
    }
    else
    {
        if("QMYSQL" == m_strDBType)
        {
            bRet = connectMySQL(m_strLocalHostName, m_strDatabaseName, m_strUserName, m_strPassword,m_intPort);

        }
        else if("QSQLITE" == m_strDBType)
        {
            bRet = connectSQLite3(m_strDatabaseName);
        }
        else if("QZSQLITE" == m_strDBType)
        {
            bRet = connectZSQLite3(m_strDatabaseName,m_strPassword);
        }
        else
        {
            bRet = false;
        }
    }

    mutex.unlock();

    return bRet;
}

bool MtmQSQLBase::isOpen()
{
    bool bRet = m_DB.isOpen();

    return bRet;
}

void MtmQSQLBase::closeDB()
{
    if(isOpen())
    {
        m_DB.close();

    }

}

bool MtmQSQLBase::lockTable(QString strTableName,bool isWriteLock /* = true*/)
{
    mutex.lock();
    //QMutexLocker locker(&mutex);
    bool bRet = false;

    if(!isOpen())
    {
        bRet = false;
    }
    else
    {
        int iRet = isTableLocked(strTableName);

        if(iRet == 0)
        {
            if("QMYSQL" == m_strDBType)
            {
                bRet = excuteNoQuerySQL(QString("LOCK TABLE `%1` %2").arg(strTableName).arg(isWriteLock?"WRITE":"READ"));
            }
            else if("QSQLITE" == m_strDBType)
            {
                bRet = false;
            }
            else if("QZSQLITE" == m_strDBType)
            {
                bRet = false;
            }
            else
            {
                bRet = false;
            }
        }
        else if(iRet == 1)
        {
            bRet = false;
        }
        else
        {
            bRet = false;
        }
    }

    mutex.unlock();

    return bRet;
}

bool MtmQSQLBase::lockTable(QList<QString> listTableName,bool isWriteLock)
{
    mutex.lock();
    bool bRet = false;

    if(!isOpen())
    {
        bRet = false;
    }
    else
    {
        int iRet = 0;

        for(int i = 0;i < listTableName.size();i++)
        {
            iRet += isTableLocked(listTableName.at(i));
        }

        if(iRet == 0)
        {
            if("QMYSQL" == m_strDBType)
            {
                QString sql = QString("LOCK TABLE `%1` %2").arg(listTableName.at(0)).arg(isWriteLock?"WRITE":"READ");
                for(int i = 1;i < listTableName.size();i++)
                {
                    sql += QString(",`%1` %2").arg(listTableName.at(i)).arg(isWriteLock?"WRITE":"READ");
                }
                bRet = excuteNoQuerySQL(sql);
            }
            else if("QSQLITE" == m_strDBType)
            {
                bRet = false;
            }
            else if("QZSQLITE" == m_strDBType)
            {
                bRet = false;
            }
            else
            {
                bRet = false;
            }
        }
        else if(iRet == 1)
        {
            bRet = false;
        }
        else
        {
            bRet = false;
        }
    }
    mutex.unlock();

    return bRet;
}

bool MtmQSQLBase::unlockTable()
{
    mutex.lock();
    bool bRet = false;

    if(!isOpen())
    {
        bRet = false;
    }
    else
    {
        if("QMYSQL" == m_strDBType)
        {
            bRet = excuteNoQuerySQL("UNLOCK TABLES;");
        }
        else if("QSQLITE" == m_strDBType)
        {
            bRet = false;
        }
        else if("QZSQLITE" == m_strDBType)
        {
            bRet = false;
        }
        else
        {
            bRet = false;
        }
    }
    mutex.unlock();

    return bRet;
}

int MtmQSQLBase::isTableLocked(QString strTableName)
{
    mutex.lock();
    //QMutexLocker locker(&mutex);
    int iRet = -1;
    //-1 异常 0 未被锁 1 锁定
    if("QMYSQL" == m_strDBType)
    {
        //MySQL judgement if the table is locked
        QString strSQL = QString("SHOW OPEN TABLES FROM %1 WHERE In_use > 0 AND `Table` = '%2';").arg(m_strDatabaseName).arg(strTableName);

        if (isOpen())
        {
            //clear last result
            query.clear();

            if(strSQL.isEmpty())
            {
                //空语句处理为异常
                iRet = -1;
            }
            else
            {
                if(query.exec(strSQL))
                {
                    if(getResultCount() > 0)
                    {
                        iRet = 1;
                    }
                    else
                    {
                        iRet = 0;
                    }
                }
                else
                {
                    LOG(INFO) << "[mtm] excute exec error";

                    iRet = -1;
                }
            }
        }
        else
        {
            LOG(INFO) << "[mtm] excute No Query error : database not open";

            iRet = -1;
        }
    }
    else if("QSQLITE" == m_strDBType)
    {
        iRet = 0;
    }
    else if("QZSQLITE" == m_strDBType)
    {
        iRet = 0;
    }
    else
    {
        iRet = -1;
    }

    mutex.unlock();

    return iRet;
}

bool MtmQSQLBase::SetLockWaitTimeout(int second)
{
    bool bRet = false;

    if(second <= 0 )
    {
        bRet = false;
    }
    else
    {
        if("QMYSQL" == m_strDBType)
        {
            //MySQL set lock_wait_timeout
            QList<QString> lstSQL;
            lstSQL.push_back(QString("set lock_wait_timeout=%1;").arg(second));
            lstSQL.push_back(QString("set global lock_wait_timeout=%1;").arg(second));

            if(excuteNoQuerySQL(lstSQL))
            {
                bRet = true;
            }
            else
            {
                bRet = false;
            }
        }
        else if("QSQLITE" == m_strDBType)
        {
            bRet = false;
        }
        else if("QZSQLITE" == m_strDBType)
        {
            bRet = false;
        }
        else
        {
            bRet = false;
        }
    }

    return bRet;
}

int MtmQSQLBase::isTableExist(const QString strTable)
{
    //0 不存在 1 存在 -1 异常
    int iRet = -1;
    if("QSQLITE" == m_strDBType)
    {
        QString sql = QString("select * from sqlite_master where type='table' and name='%1'").arg(strTable);
        iRet = excuteQuerySQL(sql);
    }
    else if("QMYSQL" == m_strDBType)
    {
        //selct table_name from INFORMATION_SCHEMA.TABLES where table_name 't5' and TABLE-SCHEMA='test';
        /*SELECT count( * )
        FROM information_schema.TABLES
        WHERE table_name = 'table name'
        AND TABLE_SCHEMA = 'database name'*/
        iRet = -1;
    }
    else if("QZSQLITE" == m_strDBType)
    {
        QString sql = QString("select * from sqlite_master where type='table' and name='%1'").arg(strTable);
        iRet = excuteQuerySQL(sql);
    }
    else
    {
        iRet = -1;
    }

    return iRet;
}

void MtmQSQLBase::FreeResult()
{
    if (isOpen())
    {
        query.clear();
    }
}

int MtmQSQLBase::excuteQuerySQL(const QString strSQL)
{
    mutex.lock();
    //执行查询语句, 返回结果条数
    int iRet = -1;
    if (isOpen())
    {
        //释放上次结果
        FreeResult();

        if(strSQL.isEmpty())
        {
            //空语句处理为false
            iRet = 0;
        }
        else
        {
            query.exec(strSQL);

            iRet = getResultCount();
        }

        if(m_isDebugMode)
        {
			LOG(INFO) << _QLOG(strSQL);

            if(query.isActive())
            {
                int count = query.record().count();

                if(iRet > 0)
                {
                    if(query.seek(0))
                    {
                        QString record;

                        for(int i = 0; i < count; i++)
                        {

                            record += query.record().fieldName(i);
                            record += " : ";
                            record += query.record().field(i).value().toString();

                            if(i != count - 1)
                            {
                                record += ", ";
                            }
                        }

						LOG(INFO) << "Query SQL Result[0] - " << _QLOG(record);
                    }
                    else
                    {
						LOG(INFO) << "[mtm] query seek error : " << _QLOG(query.lastError().text());
                    }
                }
                else
                {
                    LOG(INFO) << "[mtm] query result is empty";
                }
            }
            else
            {
				LOG(INFO) << "[mtm] query is not active : " << _QLOG(query.lastError().text());
            }
        }
    }
    else
    {
        LOG(INFO) << "[mtm] excute No Query error : database not open";

        iRet = 0;
    }
    mutex.unlock();

    return iRet;
}

bool MtmQSQLBase::excuteNoQuerySQL(const QString strSQL)
{
    mutex.lock();

    bool bRet = false;

    if(strSQL.isEmpty())
    {
        //空语句处理为完成
        bRet = true;
    }
    else
    {
        if (isOpen())
        {
            //释放上次结果，如果不释放可能会影响到事务，使其返回false
            FreeResult();

            if(m_isDebugMode)
            {
				LOG(INFO) << _QLOG(strSQL);
            }

            if(query.exec(strSQL))
            {

                bRet = true;

                if(m_isDebugMode)
                {
                    LOG(INFO) << "[mtm] excute No Query Success";
                }
            }
            else
            {
				LOG(INFO) << "[mtm] excute No Query error : " << _QLOG(query.lastError().text());
				LOG(INFO) << _QLOG(strSQL);

                bRet = false;
            }
        }
        else
        {
            LOG(INFO) << "[mtm] excute No Query error : database not open";

            bRet = false;
        }
    }
    mutex.unlock();

    return bRet;

}

bool MtmQSQLBase::excuteNoQuerySQL(const QList<QString> lstStrSQL)
{
    mutex.lock();

    bool bRet = true;

    if (isOpen())
    {
        //释放上次结果，如果不释放可能会影响到事务，使其返回false
        FreeResult();

        //开始事务
        if(beginTransaction())
        {
            int sqlSize = lstStrSQL.size();
            for ( int i = 0; i != sqlSize; i++ )
            {
                if(lstStrSQL[i].isEmpty())
                {
                    continue;
                }

                if(m_isDebugMode)
                {
					LOG(INFO) << _QLOG(lstStrSQL[i]);
                }

                if(query.exec(lstStrSQL[i]))
                {
                    //不处理
                    if(m_isDebugMode)
                    {
                        LOG(INFO) << "[mtm] excute No Query Success";
                    }
                }
                else
                {
					QString logtext = QString("[mtm] excute No Query error - Error Code : %1, , Error Text : %2, SQL : %3").arg(query.lastError().type()).arg(query.lastError().text()).arg(lstStrSQL[i]);
					LOG(INFO) << _QLOG(logtext);

                    //回滚事务
                    if(rollbackTransaction())
                    {
                        //回滚成功
                        LOG(INFO) << "[mtm] rollback Transaction success";
                    }
                    else
                    {
                        LOG(INFO) << "[mtm] rollback Transaction error";
                    }

                    bRet = false;

                    //break;//退出for循环
                }
            }

            if(bRet)//执行正常
            {
                //提交事务
                if(commitTransaction())
                {
                    //执行成功
                }
                else
                {
                    LOG(INFO) << "[mtm] commit Transaction error";

                    bRet = false;
                }
            }
            else
            {
                //执行不正常
            }
        }
        else
        {
            LOG(INFO) << "[mtm] begin Transaction error";

            bRet = false;
        }
    }
    else
    {
        LOG(INFO) << "[mtm] excute No Query error : database not open";

        bRet = false;
    }

    mutex.unlock();

    return bRet;
}

long MtmQSQLBase::getResultCount()
{
    int iRet = -1;

    if (isOpen())
    {
        if(m_DB.driver()->hasFeature(QSqlDriver::QuerySize))
        {
            iRet = query.size();
        }
        else
        {
            int i = query.at();
            query.last();
            int iRows = query.at() + 1;
            query.seek(i);

            iRet = iRows;
        }
    }
    else
    {
        iRet = -1;
    }

    return iRet;
}

bool MtmQSQLBase::first()
{
    bool bRet = false;

    if (isOpen())
    {
        if(query.isActive())
        {
            bRet = query.first();
        }
        else
        {
            bRet = false;
        }
    }
    else
    {
        bRet = false;
    }

    return bRet;
}

bool MtmQSQLBase::previous()
{
    bool bRet = false;

    if (isOpen())
    {
        if(query.isActive())
        {
            bRet = query.previous();
        }
        else
        {
            bRet = false;
        }
    }
    else
    {
        bRet = false;
    }

    return bRet;
}

bool MtmQSQLBase::next()
{
    bool bRet = false;

    if (isOpen())
    {
        if(query.isActive())
        {
            bRet = query.next();
        }
        else
        {
            bRet = false;
        }
    }
    else
    {
        bRet = false;
    }

    return bRet;
}

bool MtmQSQLBase::last()
{
    bool bRet = false;

    if (isOpen())
    {
        if(query.isActive())
        {
            bRet = query.last();
        }
        else
        {
            bRet = false;
        }
    }
    else
    {
        bRet = false;
    }

    return bRet;
}

bool MtmQSQLBase::seek(int n)
{
    bool bRet = false;

    if (isOpen())
    {
        if(query.isActive())
        {
            bRet = query.seek(n);
        }
        else
        {
            bRet = false;
        }

    }
    else
    {
        bRet = false;
    }

    return bRet;
}

QVariant MtmQSQLBase::GetValue(int row, QString fd_name)
{
    mutex.lock();

    QVariant vRet = QVariant();

    if (isOpen())
    {
        if(query.isActive())
        {
            if(query.seek(row))
            {
                QVariant record = query.record().field(fd_name).value();

                vRet = record;
            }
            else
            {
                LogInfo  << "[mtm] query seek error : "  << query.lastError();

                vRet = QVariant();
            }


        }
        else
        {
			LOG(INFO) << "[mtm] query is not active : " << _QLOG(query.lastError().text());

            vRet = QVariant();
        }
    }
    else
    {
        LOG(INFO) << "[mtm] get Value error. DataBase not open";

        vRet = QVariant();
    }

    mutex.unlock();

    return vRet;
}

QVariant MtmQSQLBase::GetValue(int row, int fd_num)
{
    mutex.lock();

    QVariant vRet = QVariant();

    if (isOpen())
    {
        if(query.isActive())
        {
            if(query.seek(row))
            {
                QVariant record = query.record().field(fd_num).value();

                vRet = record;
            }
            else
            {
                LOG(INFO) << "[mtm] query seek error : " << _QLOG(query.lastError().text());

                vRet = QVariant();
            }
        }
        else
        {
			LOG(INFO) << "[mtm] query is not active : " << _QLOG(query.lastError().text());

            vRet = QVariant();
        }
    }
    else
    {
        LOG(INFO) << "[mtm] get Value error. DataBase not open";

        vRet = QVariant();
    }

    mutex.unlock();

    return vRet;
}

bool MtmQSQLBase::GetListValue(QString fd_name,QList<QVariant> & result)
{
    mutex.lock();

    bool bRet = true;

    if (isOpen())
    {
        if(query.isActive())
        {
            int count = getResultCount();
            for(int i = 0; i < count;i++)
            {
                if(query.seek(i))
                {
                    QVariant record = query.record().field(fd_name).value();

                    if(record.type() != QVariant::Invalid)
                    {
                        result.push_back(record);
                    }
                    else
                    {

                    }
                }
                else
                {
					LOG(INFO) << "[mtm] query seek error : " << _QLOG(query.lastError().text());

                    bRet = false;
                }
            }
        }
        else
        {
			LOG(INFO) << "[mtm] query is not active : " << _QLOG(query.lastError().text());

            bRet = false;
        }
    }
    else
    {
        LOG(INFO) <<"[mtm] get Value error. DataBase not open";

        bRet = false;
    }

    mutex.unlock();

    return bRet;
}

bool MtmQSQLBase::GetListValue(int fd_num, QList<QVariant> &result)
{
    mutex.lock();

    bool bRet = true;

    if (isOpen())
    {
        if(query.isActive())
        {
            int count = getResultCount();
            for(int i = 0; i < count; i++)
            {
                if(query.seek(i))
                {
                    QVariant record = query.record().field(fd_num).value();

                    if(record.type() != QVariant::Invalid)
                    {
                        result.push_back(record);
                    }
                }
                else
                {
					LOG(INFO) << "[mtm] query seek error : " << _QLOG(query.lastError().text());

                    bRet = false;
                }
            }
        }
        else
        {
			LOG(INFO) << "[mtm] query is not active : " << _QLOG(query.lastError().text());

            bRet = false;
        }
    }
    else
    {
        LOG(INFO) << "[mtm] get Value error. DataBase not open";

        bRet = false;
    }

    mutex.unlock();

    return bRet;
}

int MtmQSQLBase::GetIntValue(int row, QString fd_name)
{
    return GetValue(row, fd_name).toInt();
}

int MtmQSQLBase::GetIntValue(int row, int fd_num)
{
    return GetValue(row, fd_num).toInt();
}

bool MtmQSQLBase::GetIntListValue(QString fd_name,QList<int> &result)
{
    QList<QVariant> resultVariant;
    bool bRet = GetListValue(fd_name,resultVariant);
    if(bRet)
    {
        foreach(QVariant v, resultVariant)
        {
            result.push_back(v.toInt());
        }
    }

    return bRet;
}

bool MtmQSQLBase::GetIntListValue(int fd_num,QList<int> &result)
{
    QList<QVariant> resultVariant;
    bool bRet = GetListValue(fd_num,resultVariant);
    if(bRet)
    {
        foreach(QVariant v, resultVariant)
        {
            result.push_back(v.toInt());
        }
    }

    return bRet;
}

float MtmQSQLBase::GetFloatValue(int row,QString fd_name)
{
    return GetValue(row, fd_name).toFloat();
}

float MtmQSQLBase::GetFloatValue(int row,int fd_num)
{
    return GetValue(row, fd_num).toFloat();
}

bool MtmQSQLBase::GetFloatListValue(QString fd_name, QList<float> &result)
{
    QList<QVariant> resultVariant;
    bool bRet = GetListValue(fd_name,resultVariant);
    if(bRet)
    {
        foreach(QVariant v, resultVariant)
        {
            result.push_back(v.toFloat());
        }
    }

    return bRet;
}

bool MtmQSQLBase::GetFloatListValue(int fd_num, QList<float> &result)
{
    QList<QVariant> resultVariant;
    bool bRet = GetListValue(fd_num,resultVariant);
    if(bRet)
    {
        foreach(QVariant v, resultVariant)
        {
            result.push_back(v.toFloat());
        }
    }

    return bRet;
}

double MtmQSQLBase::GetDoubleValue(int row,QString fd_name)
{
    return GetValue(row, fd_name).toDouble();
}

double MtmQSQLBase::GetDoubleValue(int row,int fd_num)
{
    return GetValue(row, fd_num).toDouble();
}

bool MtmQSQLBase::GetDoubleListValue(QString fd_name, QList<double> &result)
{
    QList<QVariant> resultVariant;
    bool bRet = GetListValue(fd_name,resultVariant);
    if(bRet)
    {
        foreach(QVariant v, resultVariant)
        {
            result.push_back(v.toDouble());
        }
    }

    return bRet;
}

bool MtmQSQLBase::GetDoubleListValue(int fd_num, QList<double> &result)
{
    QList<QVariant> resultVariant;
    bool bRet = GetListValue(fd_num,resultVariant);
    if(bRet)
    {
        foreach(QVariant v, resultVariant)
        {
            result.push_back(v.toDouble());
        }
    }

    return bRet;
}

bool MtmQSQLBase::GetBoolValue(int row,QString fd_name)
{
    return GetValue(row, fd_name).toBool();
}

bool MtmQSQLBase::GetBoolValue(int row,int fd_num)
{
    return GetValue(row, fd_num).toBool();
}

bool MtmQSQLBase::GetBoolListValue(QString fd_name, QList<bool> &result)
{
    QList<QVariant> resultVariant;
    bool bRet = GetListValue(fd_name,resultVariant);
    if(bRet)
    {
        foreach(QVariant v, resultVariant)
        {
            result.push_back(v.toBool());
        }
    }

    return bRet;
}

bool MtmQSQLBase::GetBoolListValue(int fd_num, QList<bool> &result)
{
    QList<QVariant> resultVariant;
    bool bRet = GetListValue(fd_num,resultVariant);
    if(bRet)
    {
        foreach(QVariant v, resultVariant)
        {
            result.push_back(v.toBool());
        }
    }

    return bRet;
}

QString MtmQSQLBase::GetStringValue(int row,QString fd_name)
{
    return GetValue(row, fd_name).toString();
}

QString MtmQSQLBase::GetStringValue(int row,int fd_num)
{
    return GetValue(row, fd_num).toString();
}

QDateTime MtmQSQLBase::GetDateTimeValue(int row,QString fd_name)
{
    return GetValue(row, fd_name).toDateTime();
}

bool MtmQSQLBase::GetStringListValue(QString fd_name, QList<QString> &result)
{
    QList<QVariant> resultVariant;
    bool bRet = GetListValue(fd_name,resultVariant);
    if(bRet)
    {
        foreach(QVariant v, resultVariant)
        {
            result.push_back(v.toString());
        }
    }

    return bRet;
}

bool MtmQSQLBase::GetStringListValue(int fd_num, QList<QString> &result)
{
    QList<QVariant> resultVariant;
    bool bRet = GetListValue(fd_num,resultVariant);
    if(bRet)
    {
        foreach(QVariant v, resultVariant)
        {
            result.push_back(v.toString());
        }
    }

    return bRet;
}

QDateTime MtmQSQLBase::GetDataTimeValue(int row,QString fd_name)
{
    return GetValue(row, fd_name).toDateTime();
}

QDateTime MtmQSQLBase::GetDataTimeValue(int row, int fd_num)
{
    return GetValue(row, fd_num).toDateTime();
}

bool MtmQSQLBase::GetDataTimeListValue(QString fd_name, QList<QDateTime> &result)
{
    QList<QVariant> resultVariant;
    bool bRet = GetListValue(fd_name,resultVariant);
    if(bRet)
    {
        foreach(QVariant v, resultVariant)
        {
            result.push_back(v.toDateTime());
        }
    }

    return bRet;
}

bool MtmQSQLBase::GetDataTimeListValue(int fd_num, QList<QDateTime> &result)
{
    QList<QVariant> resultVariant;
    bool bRet = GetListValue(fd_num,resultVariant);
    if(bRet)
    {
        foreach(QVariant v, resultVariant)
        {
            result.push_back(v.toDateTime());
        }
    }

    return bRet;
}

QString MtmQSQLBase::getDBName() const
{
    return m_strDatabaseName;
}

QString MtmQSQLBase::getVersion() const
{
    return m_strVersion;
}

bool MtmQSQLBase::connectSQLite3(const QString &strDatabaseName)
{
    bool bRet = false;

    QString strDB = strDatabaseName.trimmed();
    if(QFileInfo(strDB).fileName() == strDB)
    {
        strDB = QString("%1/%2").arg( QCoreApplication::applicationDirPath() ).arg( strDB );
    }
    else
    {

    }

    m_DB.setDatabaseName(strDB);

    if (m_DB.open())
    {
        bRet = true;
    }
    else
    {
        bRet = false;
    }

    return bRet;
}

bool MtmQSQLBase::connectZSQLite3(const QString &strDatabaseName, const QString strPassword)
{
    bool bRet = false;

    QString strDB = strDatabaseName.trimmed();
    if(QFileInfo(strDB).fileName() == strDB)
    {
        strDB = QString("%1/%2").arg( QCoreApplication::applicationDirPath() ).arg( strDB );
    }
    else
    {

    }

    m_DB.setDatabaseName(strDB);
    m_DB.setPassword(strPassword);
    if (m_DB.open())
    {
        bRet = true;
    }
    else
    {
        bRet = false;
    }

    return bRet;
}

bool MtmQSQLBase::connectMySQL(QString strServerHostName, const QString strDatabaseName, QString strUserName, const QString strPassword,int intPort)
{
    bool bRet = false;

    if(strServerHostName.length() < 1)
    {
        strServerHostName = "127.0.0.1";
    }

    if(strUserName.length() < 1)
    {
        strUserName = "root";
    }

    if(intPort == 0)
    {
        intPort = 3306;
    }

    if(strDatabaseName.length() < 1)
    {
        bRet = false;
    }
    else
    {
        m_DB.setHostName(strServerHostName);
        m_DB.setPort(intPort);
        m_DB.setDatabaseName(strDatabaseName);
        m_DB.setUserName(strUserName);
        m_DB.setPassword(strPassword);

        if(m_DB.open())
        {
            bRet = true;
        }
        else
        {
            bRet = false;
        }
        QSqlError error;
        error=m_DB.lastError();
        if(error.isValid())//发生错误时isValid()返回true
        {
            switch (error.type()) {
            case QSqlError::NoError:
                LogInfo<<"no error ";
                break;
            case QSqlError::ConnectionError://连接错语
                LogInfo<<"error "<<error.text();
                break;
            case QSqlError::StatementError://语句错语
                LogInfo<<"error "<<error.text();
                break;
            case QSqlError::TransactionError://事务错误
                LogInfo<<"error "<<error.text();
                break;
            default://未知错误
                LogInfo<<"error "<<error.text();
                break;
            }
        }

    }

    return bRet;
}

bool MtmQSQLBase::beginTransaction()
{
    bool bRet = false;

    if (m_DB.driver()->hasFeature(QSqlDriver::Transactions))
    {
         bRet = m_DB.transaction();
    }
    else
    {
        bRet = false;
    }

    return bRet;
}

bool MtmQSQLBase::commitTransaction()
{
    bool bRet = false;

    if (m_DB.driver()->hasFeature(QSqlDriver::Transactions))
    {
        bRet = m_DB.commit();
    }
    else
    {
        bRet = false;
    }

    return bRet;
}

bool MtmQSQLBase::rollbackTransaction()
{
    bool bRet = false;

    if (m_DB.driver()->hasFeature(QSqlDriver::Transactions))
    {
        bRet = m_DB.rollback();
    }
    else
    {
        bRet = false;
    }

    return bRet;
}
