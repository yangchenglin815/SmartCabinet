#include <QProcess>

#include "smartcabinet.h"
#include "UserConfig.h"
#include "GlogManager.h"
#include "GlobalDefine.h"
#include "GlobalSignal.h"

SmartCabinet::SmartCabinet(QWidget *parent)
	: QMainWindow(parent)
	, m_qAppTimer(new QTimer(this))
	, m_lastActive(time(NULL))
	, m_bDroneSignQuit(false)
	, m_bDroneSignAd(false)
{
	ui.setupUi(this);
	this->setWindowModality(Qt::ApplicationModal);//模态
	this->setWindowState(Qt::WindowMaximized);//初始最大化
	this->setWindowFlags(Qt::FramelessWindowHint);//无边框

	InitUI();
	InitConnect();
	InitTimer();
	QTimer::singleShot(50, this, SLOT(OnInitLogin()));
}

SmartCabinet::~SmartCabinet()
{

}

void SmartCabinet::OnDroneSignals(int type)
{
	if (type == ADVERTBYTIMER)//播放广告
	{
		LOG(INFO) << "ADVERTBYTIMER.";
		PlayAdvertising();
	}
	else if (type == AUTOQUITBYTIMER) //退出登录
	{
		//发送退出登录和关闭窗口信号
		LOG(INFO) << "AUTOQUITBYTIMER.";
	}
}

void SmartCabinet::InitTimer()
{
	if (INSTANCE_USER_CONFIG->ReadIntSetting("other", "adver_by_time_s", m_iAdvertByTimems))
	{
		m_iAdvertByTimems = (m_iAdvertByTimems < 20) ? 120 : m_iAdvertByTimems;
	}
	if (INSTANCE_USER_CONFIG->ReadIntSetting("other", "AutoQuitByTimems", m_iAutoQuitByTimems))
	{
		m_iAutoQuitByTimems = (m_iAutoQuitByTimems < 20) ? 120 : m_iAutoQuitByTimems;
	}
	LOG(INFO) << "advertByTimems=" << m_iAdvertByTimems << "AutoQuitByTimems=" << m_iAutoQuitByTimems;


	connect(m_qAppTimer, SIGNAL(timeout()), this, SLOT(OnTimeEvent()));
	m_qAppTimer->start(10);
}

void SmartCabinet::InitConnect()
{
	connect(GlobalSignal::instance(), SIGNAL(onAppActivateOn()), this, SLOT(OnAppActivate()));
}

void SmartCabinet::InitUI()
{
	ui.label_yunan->hide();
	ui.comboBox_lockType->setView(new QListView());
	ui.comboBoxUserRole->setView(new QListView());
}

bool SmartCabinet::InitMainBaseInfo()
{

	return true;
}

void SmartCabinet::PlayAdvertising()
{
	LOG(INFO) << "PlayAdvertising";

	QProcess *process = new QProcess;

	//目录结构
	QString DirPath = QCoreApplication::applicationDirPath() + "/MoutumAdvertPic.exe";
	process->start(DirPath);
}

void SmartCabinet::OnTimeEvent()
{
	time_t now = time(NULL);

	int elapsed = now - m_lastActive;
	if (m_lastActive > 0 && elapsed > m_iAdvertByTimems)
	{
		if (m_bDroneSignAd)
		{
			OnDroneSignals(ADVERTBYTIMER);
			m_lastActive = time(NULL);
			m_bDroneSignAd = false;
		}
	}
	if (m_lastActive > 0 && elapsed > m_iAutoQuitByTimems)
	{
		if (m_bDroneSignQuit)
		{
			OnDroneSignals(AUTOQUITBYTIMER);
			m_lastActive = time(NULL);
			m_bDroneSignQuit = false;
		}
	}
}

void SmartCabinet::OnAppActivate()
{
	m_bDroneSignAd = true;
	m_bDroneSignQuit = true;
	m_lastActive = time(NULL);
}

void SmartCabinet::OnInitLogin()
{
	if (!InitMainBaseInfo())
	{
		LOG(INFO) << "error Init main base info failed.";
		return;
	}
}
