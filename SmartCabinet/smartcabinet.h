#ifndef SMARTCABINET_H
#define SMARTCABINET_H

#include <QtWidgets/QMainWindow>
#include <QTimer>
#include <time.h>
#include "ui_smartcabinet.h"
#include "CommonData.h"

class SmartCabinet : public QMainWindow
{
	Q_OBJECT

public:
	SmartCabinet(QWidget *parent = 0);
	~SmartCabinet();

public:
	void OnDroneSignals(int type); //程序无人操作时，调用此函数，进行相关操作

private:
	void InitTimer();
	void InitConnect();
	void InitUI();

	bool InitMainBaseInfo();
	bool LoadSmartCabinetPlug();
	void InitDataThread();


	void SetAdminWidgetShow(bool bShow = false);//设置管理控件显示隐藏

	void PlayAdvertising();

protected:
	void showEvent(QShowEvent *event);

private slots:
	void OnTimeEvent();
	void OnClockEvent();
	void OnAppActivate();
	void OnInitLogin();
	void OnShutdown(); //定时关机定时器响应
	void OnAutoShutdown(bool isAutoShutdown);//自动关机

private:
	Ui::SmartCabinetClass ui;
	CommonData  m_CommonData; //通用数据
	QMap<int, LockBaseInfos> g_mpLockPtr; //需要运行的柜子库指针 map<下拉框索引(显示索引),柜子基础信息>

	QTimer *m_qAppTimer;     //检测app运行时间定时器
	QTimer *m_qClockTimer;   //时钟定时器
	QTimer *m_qShutdownTimer; //自动关机定时器
	int m_iAdvertByTimems;   //配置文件读取定时的时间
	int m_iAutoQuitByTimems; //配置文件读取定时的时间
	QString m_strShutDownTime; //自动关机时间
	time_t  m_lastActive;
	int m_iGetThirdData;//获取第三方数据

	bool m_bDroneSignQuit; //true 无人操作 false 有人操作 默认false  自动退出登录
	bool m_bDroneSignAd; //广告
};

#endif // SMARTCABINET_H
