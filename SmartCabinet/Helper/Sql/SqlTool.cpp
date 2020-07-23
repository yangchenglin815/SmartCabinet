//#include "QTinclude.h"

#include <QtSql/QSqlQuery>
#include <QObject>
#include "SqlTool.h"
#include <QDebug>

#include <QSqlError>

SqlTool::SqlTool(QObject *parent) :
    QObject(parent)
{

}

SqlTool::~SqlTool()
{

}



//考虑插入时，主键冲突
QString SqlTool::insertSql(QString &strTableNameIn, QStringList &listColumnNameIn, QStringList &listValuesIn, QStringList listDataTypeIn)
{
    if (listColumnNameIn.size() != listValuesIn.size())
    {
        return QString("");
    }

    QString sqlResult = QString("insert into ") + strTableNameIn + QString("(");
    QString sqlColumnNames;
    QString sqlValues;
    QString sqlColumnNameTemp;
    QString sqlValueTemp;
    QString sqlUpdate = QString(" ON DUPLICATE KEY UPDATE ");
    //sqlresult = sql 头 + columnnames + values + ON DUPLICATE KEY UPDATE + name = value
    int i;

    for (i=0; i < listColumnNameIn.size(); i++)
    {
        sqlColumnNameTemp = listColumnNameIn.value(i);

        if (m_strSqlIntType.contains(listDataTypeIn.value(i).toUpper()))
        {
            if("" == listValuesIn.value(i))
            {
                sqlValueTemp =  QString("NULL");
            }
            else
            {
                sqlValueTemp = listValuesIn.value(i);
            }
        }
        else if(m_strSqlDateType.contains(listDataTypeIn.value(i).toUpper()))
        {
            if("" == listValuesIn.value(i))
            {
                sqlValueTemp =  QString("NULL");
            }
            else
            {
                sqlValueTemp =  QString("'") + listValuesIn.value(i) + QString("'");
            }
        }
        else
        {
            if("" == listValuesIn.value(i))
            {
                sqlValueTemp =  QString("NULL");
            }
            else
            {
                sqlValueTemp = QString("'") + listValuesIn.value(i) + QString("'");
            }
        }


        if (i != listColumnNameIn.size()-1)
        {
            sqlColumnNames = sqlColumnNames + sqlColumnNameTemp + QString(",");
            sqlValues = sqlValues + sqlValueTemp + QString(",");
            sqlUpdate = sqlUpdate + sqlColumnNameTemp + " = " + sqlValueTemp  + QString(",");
        }
        else
        {
            sqlColumnNames = sqlColumnNames + sqlColumnNameTemp;
            sqlValues = sqlValues + sqlValueTemp;
            sqlUpdate = sqlUpdate + sqlColumnNameTemp + " = " + sqlValueTemp;
        }
    }

    sqlResult = sqlResult + sqlColumnNames + QString(")") + QString("values(") + sqlValues + QString(")")
            + sqlUpdate;
    //qDebug()<<sqlResult;
    return sqlResult;
}


/*
    删除函数.
    构造SQL删除语句.
*/
QString SqlTool::del(QString &strTableNameIn, QString &strColumnNameIn, QString &strValuesIn, QString strDataTypeIn)
{
    //DELETE FROM 表名称 WHERE 列名称 = 值
    QString sql = QString("delete from ") + strTableNameIn + QString(" where ") + strColumnNameIn + " = ";
    if (m_strSqlIntType.contains(strValuesIn.toUpper()))
    {
        sql += strValuesIn;
    }
    else if(m_strSqlDateType.contains(strDataTypeIn.toUpper()))
    {
        if("" == strValuesIn)
        {
            sql +=  QString("NULL");
        }
        else
        {
            sql +=  QString("'") + strValuesIn + QString("'");
        }
    }
    else
    {
        sql += QString("'") + strValuesIn + QString("'");
    }


    return sql;
}

