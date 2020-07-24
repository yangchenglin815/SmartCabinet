#include <QProcess>
#include <QDesktopWidget>
#include <QtConcurrent>

#include "smartcabinet.h"
#include "UserConfig.h"
#include "GlogManager.h"
#include "GlobalDefine.h"
#include "GlobalSignal.h"
#include "CommonFunc.h"
#include "MtmMessageBox.h"
#include "SmartCabinetFactory.h"
#include "TopInfoBox.h"

SmartCabinet::SmartCabinet(QWidget *parent)
	: QMainWindow(parent)
	, m_qAppTimer(new QTimer(this))
	, m_qClockTimer(new QTimer(this))
	, m_qShutdownTimer(new QTimer(this))
	, m_lastActive(time(NULL))
	, m_bDroneSignQuit(false)
	, m_bDroneSignAd(false)
	, m_iGetThirdData(0)
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

	connect(m_qClockTimer, SIGNAL(timeout()), this, SLOT(OnClockEvent()));
	m_qClockTimer->start(1000);

	connect(m_qShutdownTimer, SIGNAL(timeout()), this, SLOT(OnShutdown()));

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
	ui.label_time->setText("0000-00-00 00:00:00");

	ui.labelUserRole_2->setText(QStringLiteral("普通用户"));
	ui.comboBoxUserRole->addItem(QStringLiteral("管理员"), 0);
	ui.comboBoxUserRole->addItem(QStringLiteral("普通用户"), 1);
	ui.comboBoxUserRole->setCurrentIndex(0);
}

bool SmartCabinet::InitMainBaseInfo()
{
	SetAdminWidgetShow();
	INSTANCE_USER_CONFIG->ReadIntSetting("LockInfoBase", "GetThirdData", m_iGetThirdData);
	if (1 == INSTANCE_USER_CONFIG->readSetting("LockInfoBase", "isAutoShutdown").toInt())
	{
		OnAutoShutdown(true);
	}
	MtmMessageBox::setConfirmBoxMovePosition(QApplication::desktop()->width() / 2 - 150, QApplication::desktop()->height() / 2 - 150);
	return true;
}

bool SmartCabinet::LoadSmartCabinetPlug()
{
	int iLockNum = -1;
	if (!INSTANCE_USER_CONFIG->ReadIntSetting("LockInfoBase", "LockNum", iLockNum))
	{
		LOG(INFO) << "error read LockInfo failed.";
		return false;
	}
	if (!INSTANCE_USER_CONFIG->ReadIntSetting("LockInfoBase", "ModelTimeOut", m_CommonData.iModelTimeOut))
	{
		LOG(INFO) << "error read ModelTimeOut failed.";
		return false;
	}
	if (!INSTANCE_USER_CONFIG->ReadIntSetting("LockInfoBase", "ShowNullBox", m_CommonData.iShowNullBox))
	{
		LOG(INFO) << "error read ShowNullBox failed.";
		return false;
	}

	int iLockerCount = 0;
	for (int i = 0, j = 0; i < iLockNum; i++)
	{
		QString strLockNode = QString("LockInfo%1").arg(i);
		QString strLockClass = INSTANCE_USER_CONFIG->readSetting(strLockNode, "LockClass");
		SmartCabinetBase *pbase = SmartCabinetFactory::instance()->GetSmartCabinet(strLockClass);
		if (pbase == nullptr)
		{
			LOG(INFO) << "error Create SmartCabinetBase is Null";
			return false;
		}

		pbase->InitSmartCabinetBaseConfig(strLockNode, strLockClass, (QWidget*)pbase);
		if (!pbase->m_stBaseInfos.strLockerType.isEmpty())
		{
			QStringList strInfoList = pbase->m_stBaseInfos.strLockerType.split("|");
			if (strInfoList.size() > 1)
			{
				foreach(QString strType, strInfoList)
				{
					QString strInfo = INSTANCE_USER_CONFIG->readSetting("SubLockerName", strType);
					ui.comboBox_lockType->addItem(strInfo, strType);
					g_mpLockPtr.insert(strType.toInt(), pbase->m_stBaseInfos);
					iLockerCount++;
					j++;
				}
			}
			else
			{
				ui.comboBox_lockType->addItem(pbase->m_stBaseInfos.strName, pbase->m_stBaseInfos.strLockerType);
				g_mpLockPtr.insert(pbase->m_stBaseInfos.strLockerType.toInt(), pbase->m_stBaseInfos);
				iLockerCount++;
				j++;
			}
		}
	}

	if (iLockerCount == 1)
		ui.comboBox_lockType->hide();

	return true;
}

void SmartCabinet::InitDataThread()
{
	for (auto &iter : g_mpLockPtr)
	{
		SmartCabinetBase *pLock = (SmartCabinetBase*)(iter.pLock);
		if (pLock == NULL)
		{
			LOG(INFO) << "error thread get lock data failed pLock is NULL";
			continue;
		}

		if (!pLock->InitSmartCabinetInfo())
		{
			LOG(INFO) << " thread get lock Init data failed";
			return;
		}
	}
}

void SmartCabinet::SetAdminWidgetShow(bool bShow /*= false*/)
{
	ui.widget_button->setHidden(!bShow);
	ui.widget_info->setHidden(!bShow);
	ui.pushButton_exit->setHidden(!bShow);
	ui.label_time->setHidden(bShow);
	ui.pushButton_logout->setHidden(!bShow);
	ui.comboBox_lockType->setHidden(!bShow);
}

void SmartCabinet::PlayAdvertising()
{
	LOG(INFO) << "PlayAdvertising";

	QProcess *process = new QProcess;

	//目录结构
	QString DirPath = QCoreApplication::applicationDirPath() + "/MoutumAdvertPic.exe";
	process->start(DirPath);
}

void SmartCabinet::showEvent(QShowEvent *event)
{
	this->setAttribute(Qt::WA_Mapped);
	OnClockEvent();

	QMainWindow::showEvent(event);
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

void SmartCabinet::OnClockEvent()
{
	ui.label_time->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
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
	if (!LoadSmartCabinetPlug())
	{
		LOG(INFO) << "error LoadLockPlug failed.";
		return;
	}

	QtConcurrent::run(this, &SmartCabinet::InitDataThread);
	TopInfoBox::getBoxInstance()->setStaticText(QStringLiteral("数据加载中..."));
	TopInfoBox::getBoxInstance()->showTopWidget(QStringLiteral("请稍候"));
}

void SmartCabinet::OnShutdown()
{
	m_qShutdownTimer->stop();
	QString infoData = QStringLiteral("自动关机");
	LOG(INFO) << _QLOG(infoData);
    
	CommonFunc::shutDownSystem();
}

void SmartCabinet::OnAutoShutdown(bool isAutoShutdown)
{
	m_qShutdownTimer->stop();
	if (isAutoShutdown)
	{
		//自动关机时间
		m_strShutDownTime = INSTANCE_USER_CONFIG->readSetting("LockInfoBase", "shutdownTime");
		if (m_strShutDownTime.toInt() < 0 || !QTime::fromString(m_strShutDownTime, "hh:mm").isValid())
		{
			m_strShutDownTime = QString("20:30");
			INSTANCE_USER_CONFIG->writeSetting("LockInfoBase", "shutdownTime", m_strShutDownTime);
		}

		QTime shutdownQTime = QTime::fromString(m_strShutDownTime, "hh:mm");

		int shutdownTimeMS = QTime::currentTime().msecsTo(shutdownQTime);
		if (shutdownTimeMS < 0)//如果时间小于当前时间，则为第二天触发
		{
			shutdownTimeMS = 86400000 + shutdownTimeMS;//1天 = 86400s
		}
		if (shutdownTimeMS > 0)
		{
			m_qShutdownTimer->setInterval(shutdownTimeMS);
			m_qShutdownTimer->start();
		}

		int leftHour = shutdownTimeMS / 3600000;
		int leftMinute = (shutdownTimeMS - leftHour * 3600000) / 60000;
		int leftSecond = (shutdownTimeMS - leftHour * 3600000 - leftMinute * 60000) / 1000;
		QString infoData = QStringLiteral("系统将于%1时%2分关机,距离现在%3小时%4分钟")
			.arg(shutdownQTime.hour())
			.arg(shutdownQTime.minute())
			.arg(leftHour)
			.arg(leftMinute)
			.arg(leftSecond);
		LOG(INFO) << _QLOG(infoData);
		MtmMessageBox::InfoShowTtsBox(infoData);
	}
}
