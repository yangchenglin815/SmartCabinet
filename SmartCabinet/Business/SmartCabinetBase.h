#pragma once

#include <QObject>
#include "CommonData.h"

class SmartCabinetBase : public QObject
{
	Q_OBJECT

public:
	SmartCabinetBase();
	virtual ~SmartCabinetBase();

	virtual bool InitSmartCabinetInfo() = 0;//��ȡ����������Ϣ
	void InitSmartCabinetBaseConfig(QString node, QString className, QWidget * pLockBase);//��ȡ���ӵĻ��������ļ���Ϣ

public:
	LockBaseInfos m_stBaseInfos;
};
