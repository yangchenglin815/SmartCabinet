#ifndef SMARTCABINET_H
#define SMARTCABINET_H

#include <QtWidgets/QMainWindow>
#include <QTimer>
#include <time.h>
#include "ui_smartcabinet.h"

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

	void PlayAdvertising();

private slots:
	void OnTimeEvent();
	void OnAppActivate();
	void OnInitLogin();

private:
	Ui::SmartCabinetClass ui;
	QTimer *m_qAppTimer;
	int m_iAdvertByTimems;///< 配置文件读取定时的时间
	int m_iAutoQuitByTimems;///< 配置文件读取定时的时间
	time_t  m_lastActive;

	bool m_bDroneSignQuit; //true 无人操作 false 有人操作 默认false  自动退出登录
	bool m_bDroneSignAd; //广告
};

#endif // SMARTCABINET_H
