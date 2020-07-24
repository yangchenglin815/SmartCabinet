#include "InfoBox.h"
#include "GlobalDefine.h"

InfoBox *InfoBox::m_pBoxInstance = NULL;
MtmTTS *InfoBox::m_pttsInstance = NULL;

int InfoBox::m_PosXAlignment = 0;
int InfoBox::m_PosYAlignment = 0;

int InfoBox::m_PositionX = 0;
int InfoBox::m_PositionY = 0;

InfoBox * InfoBox::getBoxInstance()
{
	if (m_pBoxInstance == NULL)
	{
		m_pBoxInstance = new InfoBox();
	}
	if (m_pttsInstance == NULL)
	{
		m_pttsInstance = new MtmTTS();
	}
	return m_pBoxInstance;
}

void InfoBox::setMovePosAlignment(int PosXAlignment /*= 0*/, int PosYAlignment /*= 0*/)
{
	m_PosXAlignment = PosXAlignment;
	m_PosYAlignment = PosYAlignment;
}

void InfoBox::setMovePosition(int PositionX /*= 0*/, int PositionY /*= 0*/)
{
	m_PositionX = PositionX;
	m_PositionY = PositionY;
}

void InfoBox::closeBox()
{
	if (m_pBoxInstance != NULL)
	{
		if (m_pBoxInstance->m_showTimer.isActive())
			m_pBoxInstance->m_showTimer.stop();
		m_pBoxInstance->close();
	}
}

void InfoBox::InfoShowBox(QString msg, INFO_TYPE type /*= MTMWARNING*/)
{
	InfoBox::getBoxInstance()->ui.infolabel->setText(msg);
	InfoBox::getBoxInstance()->moveMessageBox();
	InfoBox::getBoxInstance()->showInfoMessge(msg, type);
}

void InfoBox::InfoShowTtsBox(QString msg, bool IsPurgeBeforeSpeak /*= true*/, INFO_TYPE type /*= MTMWARNING*/)
{
	InfoShowBox(msg, type);
	m_pttsInstance->speak(msg, IsPurgeBeforeSpeak);
}

void InfoBox::showInfoMessge(QString msg, INFO_TYPE type /*= MTMWARNING*/)
{
	if (type == INFO_TYPE::MTMCRITICAL)
	{
		QIcon ico(":/SmartCabinet/img/msg_critical.png");
		ui.btn_ico->setIcon(ico);
	}
	else if (type == INFO_TYPE::MTMINFORMATION)
	{
		QIcon ico(":/SmartCabinet/img/msg_info.png");
		ui.btn_ico->setIcon(ico);
	}
	else if (type == INFO_TYPE::MTMQUESTION)
	{
		QIcon ico(":/SmartCabinet/img/msg_question.png");
		ui.btn_ico->setIcon(ico);
	}
	else if (type == INFO_TYPE::MTMWARNING)
	{
		QIcon ico(":/SmartCabinet/img/msg_warning.png");
		ui.btn_ico->setIcon(ico);
	}
	else if (type == INFO_TYPE::MTMNOICON)
	{
		ui.btn_ico->hide();
	}

	ui.btn_ico->setIconSize(QSize(40, 40));
	ui.infolabel->setText(msg);

	if (m_showTimer.isActive())
		m_showTimer.stop();

	show();
	m_showTimer.start(DLG_SHOW_TIME_MS);
}

void InfoBox::moveMessageBox()
{
	//0,0 左上角对齐 0,1 右上角对齐 1,0 左下角对齐 1,1 右下角对齐
	if (m_PosXAlignment == 0 && m_PosYAlignment == 0)//左上角对齐
	{
		this->move(m_PositionX, m_PositionY);
	}
	else if (m_PosXAlignment == 0 && m_PosYAlignment == 1)//右上角对齐
	{
		this->move(m_PositionX - this->width(), m_PositionY);
	}
	else if (m_PosXAlignment == 1 && m_PosYAlignment == 0)//左下角对齐
	{
		this->move(m_PositionX, m_PositionY - this->height());
	}
	else if (m_PosXAlignment == 1 && m_PosYAlignment == 1)//右下角对齐
	{
		this->move(m_PositionX - this->width(), m_PositionY - this->height());
	}
	else
	{
		this->move(m_PositionX, m_PositionY);
	}
}

InfoBox::InfoBox(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
	moveMessageBox();

	ui.infolabel->setWordWrap(true);
	ui.infolabel->setAlignment(Qt::AlignTop | Qt::AlignCenter);
	connect(&m_showTimer, &QTimer::timeout, this, &InfoBox::hide);
	m_showTimer.setSingleShot(true);
}

InfoBox::~InfoBox()
{
	if (m_showTimer.isActive())
	{
		m_showTimer.stop();
	}
	if (m_pttsInstance != NULL)
	{
		delete m_pttsInstance;
		m_pttsInstance = NULL;
	}
	close();
}
