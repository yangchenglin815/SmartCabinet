#pragma once

#include "globaldefine.h"

typedef struct _CommonData
{
	int iModelTimeOut;   //;扫描时模态框显示时长
	int iShowNullBox;    //是否显示空格子
	_CommonData()
	{
		iModelTimeOut = 5000;
		iShowNullBox = 0;
	}
}CommonData;
Q_DECLARE_METATYPE(_CommonData)

typedef struct _LockBaseInfos
{
	QWidget       *pLock;//窗口指针
	int           iCurAuthority; //当前用户切换的权限
	int           iIndex;//窗口显示在登录界面的下拉框索引
	int           iDspRow;//每行显示的数量
	int           iDspColum;//每列显示的数量
	int           iBoxWidth;//盒子宽度
	int           iBoxHight;//盒子高度
	int           iShowDetails;//点击格子后，是否显示详细信息,0直接发送业务指令，1显示详细信息后，再由用户从详细页面发送业务指令
	int           iUseRFID;//是否使用RFID
	int           iUseGUN;//是否使用扫码枪
	int           iShowChoseOperTYpe;//是否显示操作类型
	int           iShowChangeChoseOperTYpe;//是否显示充电设备 选择操作类型界面
	int           iAutoSendScan;//是否自动弹出正在扫描框,如果RFID和扫码枪同时存在，则该项无效
	int           iAutoOpenBox;//是否自动弹开格子门
	int           iAutomaticMode;//是否自动模式
	int           isUseCloseBoxSignal;//是否使用关门信号，关门信号处理业务
	int           iCloseWindowsTimeOut;//关门超时时间
	int           iChargeStateCheckTimeOut;//充电设备在位查询超时时间(毫秒)
	int           iUseTmpShowWidget;//点击临时权限是否弹出领取界面
	int           isShowCMessageBox;//是否显示领取物资询问窗口
	int           isUpdateSmartTable;//是否更新Smart表
	int           iCurLockerType;//当前选择的柜子子类型，如充电柜
	bool          bInit;//柜子是否已经初始化过了
	bool          bCurSelected;//是否新的选中的柜子
	int           isContinuityScanning;//是否连续扫描
	int           iRequestUseAuthority;//是否请求领取权限
	QString       strLockerType;//物品使用类型0为普通，1为充电设备2异形3派工
	QString       strName;//柜子名称
	QString       strLockNum;//柜子编号
	QString       strClassName;//柜子类名
	QString       strUseSuppSequence;//有运安数据时，领取物资的顺序
	QString       strIsJZWeightLocker; //是否焦作计量柜
	QString       strChangeLockerSupType; //充电柜子类型
	_LockBaseInfos()
	{
		pLock = NULL;
		iIndex = 0;
		iDspRow = 0;
		iDspColum = 0;
		iBoxWidth = 0;
		iBoxHight = 0;
		iShowDetails = 0;
		iUseGUN = 0;
		iShowChoseOperTYpe = 0;
		iShowChangeChoseOperTYpe = 0;
		iUseRFID = 0;
		iCurLockerType = 0;
		iAutoOpenBox = 0;
		bCurSelected = false;
		iCloseWindowsTimeOut = 60;
		bInit = false;
		iAutomaticMode = 0;
		strName = STR_EMPTY;
		strLockerType = STR_EMPTY;
		strLockNum = STR_EMPTY;
		strClassName = STR_EMPTY;
		strUseSuppSequence = STR_EMPTY;
		iUseTmpShowWidget = 0;
		isShowCMessageBox = 0;
		isUpdateSmartTable = 0;
		iChargeStateCheckTimeOut = 3000;
		strChangeLockerSupType = STR_EMPTY;
		isUseCloseBoxSignal = 1;
		iRequestUseAuthority = 0;
	}
}LockBaseInfos;
Q_DECLARE_METATYPE(_LockBaseInfos)