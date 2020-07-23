#ifndef MTMQSQLBASE
#define MTMQSQLBASE

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDateTime>
#include <QMutex>
#include <QThread>
#include "GlobalDefine.h"

class   MtmQSQLBase
{
public:
    MtmQSQLBase();
    virtual ~MtmQSQLBase();

    /**
     * @brief initSQLParameter 初始化SQL参数
     * @param strDatabaseName 数据库名称
     * @param strDBType 数据库类别，目前支持目前支持MySQL、SQLite2、SQLite3
     * @param strServerHostName 服务器IP
     * @param strUserName 用户名
     * @param strPassword 密码
     * @param intPort 端口号
     */
    void initSQLParameter(const QString strDatabaseName,
                          const QString strDBType = "mysql",//目前支持目前支持MySQL、SQLite2、SQLite3
                          const QString strServerHostName = "127.0.0.1",
                          const QString strUserName = "",
                          const QString strPassword = "",
                          int intPort=0);

    /**
     * @brief setDebugMode 设置Debug模式，目前输出SQL语句
     * @param isDebugMode true 设置Debug模式，目前输出SQL语句 false 正常模式
     */
    void setDebugMode(bool isDebugMode);

    /**
     * @brief getDatabaseName 获取数据库名称
     * @return
     */
    QString getDatabaseName();
    /**
     * @brief setDatabaseName 设置数据库名称 变更数据库需要重新调用connectDB
     * @param strDatabaseName 数据库名称
     */
    void setDatabaseName(QString strDatabaseName);

    /**
     * @brief connectDB 连接数据库
     * @param isReconnect 是否重连
     * @return 是否成功连接数据库
     * @retval true 成功
     * @retval false 失败
     */
    bool connectDB(bool isReconnect = false);

    /**
     * @brief excuteQuerySQL 执行查询语句,
     * @param strSQL SQL语句
     * @return 返回结果条数
     */
    int excuteQuerySQL(const QString strSQL);
    /**
     * @brief FreeResult 释放查询的结果集
     */
    void FreeResult();

    /**
     * @brief excuteNoQuerySQL 执行非查询语句
     * @param strSQL 非查询语句
     * @return 执行是否成功
     */
    bool excuteNoQuerySQL(const QString strSQL);
    /**
     * @brief excuteNoQuerySQL 批量执行非查询语句
     * @param lstStrSQL 批量非查询语句
     * @return 执行是否成功
     */
    bool excuteNoQuerySQL(const QList<QString> lstStrSQL);

    /**
     * @brief lockTable 锁定表
     * @param strTableName 表名称
     * @param isWriteLock 是否为写锁 true 写锁 false 读锁
     * @return 是否成功
     */
    bool lockTable(QString strTableName,bool isWriteLock = true);
    /**
     * @brief lockTable 锁定多张表
     * @param listTableName 表名称列表
     * @param isWriteLock 是否为写锁 true 写锁 false 读锁
     * @return 是否成功
     */
    bool lockTable(QList<QString> listTableName,bool isWriteLock = true);
    /**
     * @brief unlockTable 解除锁定
     * @return
     */
    bool unlockTable();
    /**
     * @brief isTableLocked 表是否被锁定
     * @param strTableName 表名称
     * @return 锁定状态
     * @retval 0 未锁定
     * @retval 1 锁定
     * @retval -1 异常
     */
    int isTableLocked(QString strTableName);
    /**
     * @brief SetLockWaitTimeout 设置锁等待超时时间
     * @param second 等待超时时间单位秒，默认10
     * @return 是否成功
     */
    bool SetLockWaitTimeout(int second = 10);

    /**
     * @brief isOpen 数据库是否打开
     * @return 是否打开数据库
     */
    bool isOpen();
    /**
     * @brief closeDB 关闭数据库
     */
    void closeDB();
    /**
     * @brief isTableExist 表是否存在
     * @param strTable 表名称
     * @return 是否存在
     * @retval 0 不存在
     * @retval 1 存在
     * @retval -1 异常
     */
    int isTableExist(const QString strTable);

    /**
     * @brief getResultCount 获取结果集的总数目
     * @return 结果集的总数目
     */
    long getResultCount();

    /**
     * @brief first 指向结果集的第一条记录
     * @return
     */
    bool first();
    /**
     * @brief last 指向结果集的最后一条记录
     * @return
     */
    bool last();
    /**
     * @brief previous 指向上一条记录，每执行一次该函数，便指向相邻的上一条记录
     * @return
     */
    bool previous();
    /**
     * @brief next 指向下一条记录，每执行一次该函数，便指向相邻的下一条记录
     * @return
     */
    bool next();
    /**
     * @brief seek 指向结果集的第n条记录
     * @param n 第n条记录
     * @return
     */
    bool seek(int n);

    //========读取  开始==================================
    // row     ：行号
    // fd_name ：列字段名称
    // fd_num  ：列字段号
    // 注意    ：Get**Value系列函数的参数要确保正确，否则不保证返回值将正确

    //通用类型
    /**
     * @brief GetValue 获取通用类型数据
     * @param row 行号 从0开始编号
     * @param fd_name 列字段名称
     * @return
     */
    QVariant GetValue(int row, QString fd_name);
    /**
     * @brief GetValue 获取通用类型数据
     * @param row 行号 从0开始编号
     * @param fd_num 列字段号
     * @return
     */
    QVariant GetValue(int row, int fd_num);
    /**
     * @brief GetListValue 获取通用类型数据列表
     * @param fd_name 列字段号
     * @param result 输出结果列表
     * @return
     */
    bool GetListValue(QString fd_name, QList<QVariant> &result);
    /**
     * @brief GetListValue 获取通用类型数据列表
     * @param fd_num 列字段号
     * @param result 输出结果列表
     * @return
     */
    bool GetListValue(int fd_num, QList<QVariant> &result);

    //获得整型值
    /**
     * @brief GetIntValue 获得整型值
     * @param row 行号 从0开始编号
     * @param fd_name 列字段名称
     * @return
     */
    int GetIntValue(int row, QString fd_name);
    /**
     * @brief GetIntValue 获得整型值
     * @param row 行号 从0开始编号
     * @param fd_num 列字段号
     * @return
     */
    int GetIntValue(int row, int fd_num);
    /**
     * @brief GetIntListValue 获得整型值列表
     * @param fd_name 列字段名称
     * @param result 输出结果列表
     * @return
     */
    bool GetIntListValue(QString fd_name,QList<int> &result);
    /**
     * @brief GetIntListValue 获得整型值列表
     * @param fd_num 列字段号
     * @param result 输出结果列表
     * @return
     */
    bool GetIntListValue(int fd_num,QList<int> &result);

    //获得符点型值
    /**
     * @brief GetFloatValue 获得符点型值
     * @param row 行号 从0开始编号
     * @param fd_name 列字段名称
     * @return
     */
    float GetFloatValue(int row,QString fd_name);
    /**
     * @brief GetFloatValue 获得符点型值
     * @param row 行号 从0开始编号
     * @param fd_num 列字段号
     * @return
     */
    float GetFloatValue(int row,int fd_num);
    /**
     * @brief GetFloatListValue 获得符点型值列表
     * @param fd_name 列字段名称
     * @param result 输出结果列表
     * @return
     */
    bool GetFloatListValue(QString fd_name,QList<float> &result);
    /**
     * @brief GetFloatListValue 获得符点型值列表
     * @param fd_num 列字段号
     * @param result 输出结果列表
     * @return
     */
    bool GetFloatListValue(int fd_num,QList<float> &result);

    //获得高精度符点型值
    /**
     * @brief GetDoubleValue 获得高精度符点型值
     * @param row 行号 从0开始编号
     * @param fd_name 列字段名称
     * @return
     */
    double GetDoubleValue(int row,QString fd_name);
    /**
     * @brief GetDoubleValue 获得高精度符点型值
     * @param row 行号 从0开始编号
     * @param fd_num 列字段号
     * @return
     */
    double GetDoubleValue(int row,int fd_num);
    /**
     * @brief GetDoubleListValue 获得高精度符点型值列表
     * @param fd_name 列字段名称
     * @param result 输出结果列表
     * @return
     */
    bool GetDoubleListValue(QString fd_name,QList<double> &result);
    /**
     * @brief GetDoubleListValue 获得高精度符点型值列表
     * @param fd_num 列字段号
     * @param result 输出结果列表
     * @return
     */
    bool GetDoubleListValue(int fd_num,QList<double> &result);

    //获得布尔型值
    /**
     * @brief GetBoolValue 获得布尔型值
     * @param row 行号 从0开始编号
     * @param fd_name 列字段名称
     * @return
     */
    bool GetBoolValue(int row,QString fd_name);
    /**
     * @brief GetBoolValue 获得布尔型值
     * @param row 行号 从0开始编号
     * @param fd_num 列字段号
     * @return
     */
    bool GetBoolValue(int row,int fd_num);
    /**
     * @brief GetBoolListValue 获得布尔型值列表
     * @param fd_name 列字段名称
     * @param result 输出结果列表
     * @return
     */
    bool GetBoolListValue(QString fd_name,QList<bool> &result);
    /**
     * @brief GetBoolListValue 获得布尔型值列表
     * @param fd_num 列字段号
     * @param result 输出结果列表
     * @return
     */
    bool GetBoolListValue(int fd_num,QList<bool> &result);

    //获得字符串值
    /**
     * @brief GetStringValue 获得字符串值
     * @param row 行号 从0开始编号
     * @param fd_name 列字段名称
     * @return
     */
    QString GetStringValue(int row,QString fd_name);
    /**
     * @brief GetStringValue 获得字符串值
     * @param row 行号 从0开始编号
     * @param fd_num 列字段号
     * @return
     */
    QString GetStringValue(int row,int fd_num);
    /**
     * @brief GetStringListValue 获得字符串值列表
     * @param fd_name 列字段名称
     * @param result 输出结果列表
     * @return
     */
    bool GetStringListValue(QString fd_name,QList<QString> &result);
    /**
     * @brief GetStringListValue 获得字符串值列表
     * @param fd_num 列字段号
     * @param result 输出结果列表
     * @return
     */
    bool GetStringListValue(int fd_num,QList<QString> &result);

    //获得日期时间型数据，以字符串形式表示
    /**
     * @brief GetDataTimeValue 获得日期时间型数据
     * @param row 行号 从0开始编号
     * @param fd_name 列字段名称
     * @return
     */
    QDateTime GetDataTimeValue(int row,QString fd_name);
    /**
     * @brief GetDataTimeValue 获得日期时间型数据
     * @param row 行号 从0开始编号
     * @param fd_num 列字段号
     * @return
     */
    QDateTime GetDataTimeValue(int row, int fd_num);
    /**
     * @brief GetDataTimeListValue 获得日期时间型数据列表
     * @param fd_name 列字段名称
     * @param result 输出结果列表
     * @return
     */
    bool GetDataTimeListValue(QString fd_name,QList<QDateTime> &result);
    /**
     * @brief GetDataTimeListValue 获得日期时间型数据列表
     * @param fd_num 列字段号
     * @param result 输出结果列表
     * @return
     */
    bool GetDataTimeListValue(int fd_num,QList<QDateTime> &result);
    //========读取  结束==================================

    /**
     * @brief getDBName 获取数据库名称
     * @return
     */
    QString getDBName() const;
    /**
     * @brief getVersion 获取版本号
     * @return
     */
    QString getVersion() const;

    QDateTime GetDateTimeValue(int row, QString fd_name);
protected:
    //bool connectSQLite2(const QString &strDatabaseName);//SQlite2数据库连接
    bool connectSQLite3(const QString &strDatabaseName);//SQLite3数据库连接
    bool connectZSQLite3(const QString &strDatabaseName, const QString strPassword);//SQLite3加密数据库连接
    bool connectMySQL(QString strServerHostName, const QString strDatabaseName, QString strUserName, const QString strPassword,const int intPort);//MySQL数据库连接

    //bool connectMDB(const QString strMDBname, QString strUserID = "sa", const QString strPassword = "");
    //bool connectMDBByUDL(const QString strUDL);
    //bool connectSqlServer(const QString strSvrName, const QString strDBname, const QString strUserID, const QString strUserPwd);

    //事务
    //MySQL 5.5支持(5.7不支持)
    bool beginTransaction();//开始事务
    bool commitTransaction();//提交事务
    bool rollbackTransaction();//回滚事务

private:
    /**
     * @brief m_strVersion 类库版本号
     */
    const QString m_strVersion = "MtmQSQL 1.6.2.190417";

    /**
     * @brief m_DB 数据库连接
     */
    QSqlDatabase m_DB;
    QSqlDatabase m_ServerDB;
    /**
     * @brief p_sqliteEncryptDriver sqlite encrypt db
     */
    //ZSQLiteCipherDriver * p_sqliteEncryptDriver;

    //QSqlDatabase支持的数据库类型
    //QMYSQL (MySql驱动)、QSQLITE (SQLite3或以上)、QSQLITE2 (SQLite2)、QOCI (Oracle接口驱动、QPSQL (PostgreSQL 驱动)、QODBC (ODBC驱动)、QDB2(IBM DB2)、QIBASE (Borland InterBase驱动)、QTDS (Sybase)
    /**
     * @brief m_strDBType 数据库类型，目前支持MySQL、SQLite3
     */
    QString m_strDBType;
    /**
     * @brief m_strDatabaseName 数据库名称
     */
    QString m_strDatabaseName;
    /**
     * @brief m_strLocalHostName IP
     */
    QString m_strLocalHostName;
    /**
     * @brief m_strUserName 用户名
     */
    QString m_strUserName;
    /**
     * @brief m_strPassword 密码
     */
    QString m_strPassword;
    /**
     * @brief m_intPort 端口号
     */
    int m_intPort;

//    QString m_strServerHostName;
//    QString m_strServerDatabaseName;
//    QString m_strServerUserName;
//    QString m_strServerPassword;
//    int m_intServerPort;
    /**
     * @brief query 查询结果集
     */
    QSqlQuery query;
//    QSqlQuery queryServer = QSqlQuery(m_ServerDB);

    /**
     * @brief mutex 线程安全
     */
    QMutex mutex;

    /**
     * @brief isDebugMode 是否为Debug模式，目前可以输出SQL，默认false
     */
    bool m_isDebugMode;
};

#endif // MTMQSQLBASE
