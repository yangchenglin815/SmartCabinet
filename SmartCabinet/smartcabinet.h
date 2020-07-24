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
	void OnDroneSignals(int type); //�������˲���ʱ�����ô˺�����������ز���

private:
	void InitTimer();
	void InitConnect();
	void InitUI();

	bool InitMainBaseInfo();
	bool LoadSmartCabinetPlug();
	void InitDataThread();


	void SetAdminWidgetShow(bool bShow = false);//���ù���ؼ���ʾ����

	void PlayAdvertising();

protected:
	void showEvent(QShowEvent *event);

private slots:
	void OnTimeEvent();
	void OnClockEvent();
	void OnAppActivate();
	void OnInitLogin();
	void OnShutdown(); //��ʱ�ػ���ʱ����Ӧ
	void OnAutoShutdown(bool isAutoShutdown);//�Զ��ػ�

private:
	Ui::SmartCabinetClass ui;
	CommonData  m_CommonData; //ͨ������
	QMap<int, LockBaseInfos> g_mpLockPtr; //��Ҫ���еĹ��ӿ�ָ�� map<����������(��ʾ����),���ӻ�����Ϣ>

	QTimer *m_qAppTimer;     //���app����ʱ�䶨ʱ��
	QTimer *m_qClockTimer;   //ʱ�Ӷ�ʱ��
	QTimer *m_qShutdownTimer; //�Զ��ػ���ʱ��
	int m_iAdvertByTimems;   //�����ļ���ȡ��ʱ��ʱ��
	int m_iAutoQuitByTimems; //�����ļ���ȡ��ʱ��ʱ��
	QString m_strShutDownTime; //�Զ��ػ�ʱ��
	time_t  m_lastActive;
	int m_iGetThirdData;//��ȡ����������

	bool m_bDroneSignQuit; //true ���˲��� false ���˲��� Ĭ��false  �Զ��˳���¼
	bool m_bDroneSignAd; //���
};

#endif // SMARTCABINET_H
