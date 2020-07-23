#pragma once

#include <QObject>
#include <QMap>
#include "SmartCabinetBase.h"

class SmartCabinetFactory : public QObject
{
	Q_OBJECT

public:
	static SmartCabinetFactory* instance();

	void RegisterSmartCabinet(const QString& name, SmartCabinetBase* registrar);

	SmartCabinetBase* GetSmartCabinet(const QString& name);

private:
	SmartCabinetFactory();
	virtual ~SmartCabinetFactory();

	SmartCabinetFactory(const SmartCabinetFactory &);
	const SmartCabinetFactory &operator=(const SmartCabinetFactory &);

private:
	static SmartCabinetFactory* m_pInstance;
	QMap<QString, SmartCabinetBase*> m_SmartCabinetRegistry;
};
