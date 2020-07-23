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
	void OnDroneSignals(int type); //�������˲���ʱ�����ô˺�����������ز���

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
	int m_iAdvertByTimems;///< �����ļ���ȡ��ʱ��ʱ��
	int m_iAutoQuitByTimems;///< �����ļ���ȡ��ʱ��ʱ��
	time_t  m_lastActive;

	bool m_bDroneSignQuit; //true ���˲��� false ���˲��� Ĭ��false  �Զ��˳���¼
	bool m_bDroneSignAd; //���
};

#endif // SMARTCABINET_H
