#include "SmartCabinetBase.h"
#include "UserConfig.h"

SmartCabinetBase::SmartCabinetBase()
{

}

SmartCabinetBase::~SmartCabinetBase()
{

}

void SmartCabinetBase::InitSmartCabinetBaseConfig(QString node, QString className, QWidget * pLockBase)
{
	m_stBaseInfos.strClassName = className;
	m_stBaseInfos.strLockerType = INSTANCE_USER_CONFIG->readSetting(node, "LockerUseType");
	m_stBaseInfos.iDspRow = INSTANCE_USER_CONFIG->readSetting(node, "LockRow").toInt();
	m_stBaseInfos.iDspColum = INSTANCE_USER_CONFIG->readSetting(node, "LockCol").toInt();
	m_stBaseInfos.iBoxWidth = INSTANCE_USER_CONFIG->readSetting(node, "BoxWidth").toInt();
	m_stBaseInfos.iBoxHight = INSTANCE_USER_CONFIG->readSetting(node, "BoxHight").toInt();
	m_stBaseInfos.strLockNum = INSTANCE_USER_CONFIG->readSetting(node, "LockNo");
	m_stBaseInfos.iIndex = INSTANCE_USER_CONFIG->readSetting(node, "LockIndex").toInt();
	m_stBaseInfos.iAutoSendScan = INSTANCE_USER_CONFIG->readSetting(node, "AutoSendScan").toInt();
	m_stBaseInfos.iAutomaticMode = INSTANCE_USER_CONFIG->readSetting(node, "AutomaticMode").toInt();
	m_stBaseInfos.isUseCloseBoxSignal = INSTANCE_USER_CONFIG->readSetting(node, "UseCloseBoxSignal").toInt();
	m_stBaseInfos.iCloseWindowsTimeOut = INSTANCE_USER_CONFIG->readSetting(node, "CloseWindowsTimeOut").toInt();
	m_stBaseInfos.iChargeStateCheckTimeOut = INSTANCE_USER_CONFIG->readSetting(node, "ChargeStateCheckTimeOut").toInt();
	m_stBaseInfos.strChangeLockerSupType = INSTANCE_USER_CONFIG->readSetting(node, "ChangeLockerSupType");
	m_stBaseInfos.iShowChangeChoseOperTYpe = INSTANCE_USER_CONFIG->readSetting(node, "ShowChangeChoseOperTYpe").toInt();
	m_stBaseInfos.iAutoOpenBox = INSTANCE_USER_CONFIG->readSetting(node, "AutoOpenBox").toInt();
	m_stBaseInfos.iUseTmpShowWidget = INSTANCE_USER_CONFIG->readSetting(node, "UseTmpShowWidget").toInt();
	m_stBaseInfos.isShowCMessageBox = INSTANCE_USER_CONFIG->readSetting(node, "ShowCMessageBox").toInt();
	m_stBaseInfos.isUpdateSmartTable = INSTANCE_USER_CONFIG->readSetting(node, "UpdateSmartTable").toInt();
	m_stBaseInfos.strName = INSTANCE_USER_CONFIG->readSetting(node, "LockName");
	m_stBaseInfos.iShowDetails = INSTANCE_USER_CONFIG->readSetting(node, "ShowDetails").toInt();
	m_stBaseInfos.iUseRFID = INSTANCE_USER_CONFIG->readSetting(node, "UseRFID").toInt();
	m_stBaseInfos.iUseGUN = INSTANCE_USER_CONFIG->readSetting(node, "UseGUN").toInt();
	m_stBaseInfos.iShowChoseOperTYpe = INSTANCE_USER_CONFIG->readSetting("LockInfoBase", "ShowChoseOperTYpe").toInt();
	m_stBaseInfos.strIsJZWeightLocker = INSTANCE_USER_CONFIG->readSetting("LockInfoBase", "IsJZWeightLocker");
	m_stBaseInfos.isContinuityScanning = INSTANCE_USER_CONFIG->readSetting("LockInfoBase", "ContinuityScanning").toInt();
	if (!INSTANCE_USER_CONFIG->ReadIntSetting(node, "RequestUseAuthority", m_stBaseInfos.iRequestUseAuthority))
	{
		m_stBaseInfos.iRequestUseAuthority = 0;
	}
	if (!INSTANCE_USER_CONFIG->readStringSetting("LockInfoBase", "UseSuppSequence", m_stBaseInfos.strUseSuppSequence))
	{
		m_stBaseInfos.strUseSuppSequence = "11|2|8";
	}
	m_stBaseInfos.pLock = pLockBase;
}
