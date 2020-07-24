#pragma once

#include <QObject>
#include "SmartCabinetBase.h"

class SmartCabinetCharge : public SmartCabinetBase
{
	Q_OBJECT

public:
	SmartCabinetCharge();
	virtual ~SmartCabinetCharge();

public:
	virtual bool InitSmartCabinetInfo();
};
