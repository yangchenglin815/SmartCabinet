#include "TopInfoBox.h"
#include <QDesktopWidget>

TopInfoBox *TopInfoBox::m_pBoxInstance = NULL;

TopInfoBox * TopInfoBox::getBoxInstance()
{
	if (m_pBoxInstance == NULL)
	{
		m_pBoxInstance = new TopInfoBox();
	}
	return m_pBoxInstance;
}

void TopInfoBox::setStaticText(QString str)
{
	ui.labelStaticInfo->setText(str);
}

void TopInfoBox::showTopWidget(QString str, QString strMid /*= tr("data loading")*/, int iShowType /*= 0*/, int timeout_ms /*= 20000*/)
{
	m_iShowType = iShowType;
	ui.labelDynamicInfo->setText(str);
	ui.labelStaticInfo->setText(strMid);

	m_timeoutTimer.stop();
	m_timeoutTimer.start(timeout_ms);

	m_flashTimer.stop();
	m_flashTimer.start();
	this->exec();
}

void TopInfoBox::hideTopWidget(int iShowType /*= 0*/)
{
	if (iShowType)
		return;

	//最少显示1.5秒
	int hideRemainTime = m_leastShowTime - m_timeoutTimer.interval() + m_timeoutTimer.remainingTime();

	if (hideRemainTime > 0)
	{
		if (m_timeoutTimer.isActive())
			m_timeoutTimer.stop();

		if (m_flashTimer.isActive())
			m_flashTimer.stop();

		QTimer::singleShot(hideRemainTime, this, SLOT(accept()));
	}
}

void TopInfoBox::hideWidget()
{
	TopInfoBox::hideTopWidget(0);
}

void TopInfoBox::textSpangled()
{
	if ((flashCount % 2) == 0)
	{
		ui.labelDynamicInfo->setStyleSheet("color:rgb(101,101,100);");
	}
	else if ((flashCount % 2) == 1)
	{
		ui.labelDynamicInfo->setStyleSheet("color:rgb(255,0,0);");
	}
	flashCount++;
}

void TopInfoBox::setLeastShowTime(int msec /*= 1500*/)
{
	if (msec < 1500)
		msec = 1500;

	m_leastShowTime = msec;
}

void TopInfoBox::setLeastFlashTime(int msec /*= 300*/)
{
	if (msec < 300)
		msec = 300;

	m_leastFlashTime = msec;
	m_flashTimer.setInterval(m_leastFlashTime);
}

TopInfoBox::TopInfoBox(QWidget *parent)
	: QDialog(parent)
	, m_leastShowTime(1500)
	, m_leastFlashTime(300)
	, flashCount(0)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Dialog);//顶层窗口；无标题栏
	setAttribute(Qt::WA_TranslucentBackground);//背景透明
	setModal(true);
	move((QApplication::desktop()->width()) / 2 - 250, (QApplication::desktop()->height()) / 2 - 200);

	connect(&m_timeoutTimer, &QTimer::timeout, this, &TopInfoBox::hideWidget);
	connect(&m_flashTimer, &QTimer::timeout, this, &TopInfoBox::textSpangled);
	m_flashTimer.setInterval(m_leastFlashTime);
}

TopInfoBox::~TopInfoBox()
{
	if (m_timeoutTimer.isActive())
		m_timeoutTimer.stop();
}
