#pragma once

#include <QObject>
#include "CommonData.h"

class SmartCabinetBase : public QObject
{
	Q_OBJECT

public:
	SmartCabinetBase();
	virtual ~SmartCabinetBase();

	virtual bool InitSmartCabinetInfo() = 0;//获取柜子配置信息
	void InitSmartCabinetBaseConfig(QString node, QString className, QWidget * pLockBase);//读取柜子的基本配置文件信息

public:
	LockBaseInfos m_stBaseInfos;
};
