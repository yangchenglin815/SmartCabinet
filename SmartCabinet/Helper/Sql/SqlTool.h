
#ifndef SqlTool_H
#define SqlTool_H
#include <QObject>
#include <QString>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlQuery>
#include <QStringList>
#include <QtSql/QSqlDatabase>
#include <QSqlDatabase>
#include <QDateTime>

class SqlTool : public QObject
{
    Q_OBJECT
public:
    explicit SqlTool(QObject *parent = 0);
    ~SqlTool();

    /*
     * 插入数据
     * table 表名称
     * names 字段名称
     * values 字段值
     *
     * 返回值 成功 true 失败 false
    */

    QString insertSql(QString &strTableNameIn, QStringList &listColumnNameIn, QStringList &listValuesIn, QStringList listDataTypeIn);

    //bool SqlInsert(QString strTableName, QMap<QString, STTableInfo> mapTableInfo, QStringList &sqlResult);

    /************************************************
     * 更新数据
     * table 表名称
     * names 字段名称
     * values 字段值
     * expression 条件
     *
     * 返回值 成功 true 失败 false
    *************************************************/
    bool Updata(QString &table, QStringList &names,QStringList &values, QString &expression);

    /*
     * 删除所有
     * table 表名称
     * expression 条件
     *
     * 返回值 成功 true 失败 false
    */
    QString del(QString &strTableNameIn, QString &strColumnNameIn, QString &strValuesIn, QString strDataTypeIn);



private:

    QString m_strSqlIntType = QString("TINYINT,SMALLINT,MEDIUMIT,INT,BIGINT,FLOAT,DOUBLE,DECIMAL");
    QString m_strSqlDateType = QString("YEAR,TIME,DATE,DATETIME,TIMESTAMP");
    QString m_strSqlCharType = QString("CHAR,VARCHAR,BINARY,VARBINARY,BLOB,TEXT,ENUM,SET");

};

#endif // SqlTool_H
