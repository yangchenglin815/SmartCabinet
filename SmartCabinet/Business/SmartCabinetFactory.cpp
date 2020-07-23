#include "SmartCabinetFactory.h"

SmartCabinetFactory* SmartCabinetFactory::m_pInstance = Q_NULLPTR;

SmartCabinetFactory* SmartCabinetFactory::instance()
{
	if (m_pInstance == Q_NULLPTR)
	{
		m_pInstance = new SmartCabinetFactory;
	}
	return m_pInstance;
}

void SmartCabinetFactory::RegisterSmartCabinet(const QString& name, SmartCabinetBase* registrar)
{
	m_SmartCabinetRegistry[name] = registrar;
}

SmartCabinetFactory::SmartCabinetFactory()
{

}

SmartCabinetBase* SmartCabinetFactory::GetSmartCabinet(const QString& name)
{
	QMap<QString, SmartCabinetBase*>::iterator it;

	it = m_SmartCabinetRegistry.find(name);
	if (it != m_SmartCabinetRegistry.end()) {
		return it.value();
	}

	return nullptr;
}

SmartCabinetFactory::~SmartCabinetFactory()
{

}
