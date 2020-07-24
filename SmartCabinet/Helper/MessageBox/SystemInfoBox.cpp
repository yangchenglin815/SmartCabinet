#include "SystemInfoBox.h"

SystemInfoBox *SystemInfoBox::m_syspBoxInstance = NULL;

bool SystemInfoBox::m_result = false;

int SystemInfoBox::m_PosXAlignment = 0;
int SystemInfoBox::m_PosYAlignment = 0;

int SystemInfoBox::m_PositionX = 0;
int SystemInfoBox::m_PositionY = 0;
QTimer SystemInfoBox::m_autoClickTimer;///< 自动确认倒计时定时器
QTimer SystemInfoBox::m_autoClickTimerRefresh;///< 自动确认倒计时刷新器
bool SystemInfoBox::m_isAutoClickButtion = false;
int SystemInfoBox::m_autoClickButtonType;///< 自动点击的按钮类别
QString SystemInfoBox::m_ButtonText = "";

void SystemInfoBox::showEasyInfoMessge(QString title, QString msg)
{
	ui.systitlelabel->setText(title);
	ui.sysinfolabel->setText(msg);
	exec();
}

void SystemInfoBox::moveMessageBox()
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

void SystemInfoBox::closeEvent(QCloseEvent *event)
{
	m_autoClickTimerRefresh.stop();
	m_autoClickTimer.stop();

	switch (m_autoClickButtonType) {
	case ConfirmButton:
		ui.confirmbutton->setText(m_ButtonText);
		break;
	default:
	case CancelButton:
		ui.cancelbutton->setText(m_ButtonText);
		break;
	}
}

void SystemInfoBox::onCloseButtonClicked()
{
	m_result = false;
	this->close();
}

void SystemInfoBox::onConfirmButtonClicked()
{
	m_result = true;
	this->accept();
}

void SystemInfoBox::onCancelButtonClicked()
{
	onCloseButtonClicked();
}

void SystemInfoBox::onAutoClickButtonTimeout()
{
	m_autoClickTimerRefresh.stop();
	m_autoClickTimer.stop();

	m_result = m_autoClickButtonType == ConfirmButton ? true : false;

	this->close();

	switch (m_autoClickButtonType) {
	case ConfirmButton:
		ui.confirmbutton->setText(m_ButtonText);
		break;
	default:
	case CancelButton:
		ui.cancelbutton->setText(m_ButtonText);
		break;
	}
}

void SystemInfoBox::onAutoClickButtonRefreshTimeout()
{
	QString infoData;
	switch (m_autoClickButtonType) {
	case ConfirmButton:
		infoData = QString("%1 ( %2 )")
			.arg(m_ButtonText)
			.arg(m_autoClickTimer.remainingTime() / 1000);
		ui.confirmbutton->setText(infoData);
		break;
	default:
	case CancelButton:
		infoData = QString("%1 ( %2 )")
			.arg(m_ButtonText)
			.arg(m_autoClickTimer.remainingTime() / 1000);
		ui.cancelbutton->setText(infoData);
		break;
	}
}

SystemInfoBox::SystemInfoBox(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);//置顶、去除标题栏
	setAttribute(Qt::WA_TranslucentBackground);
	setModal(true);
	moveMessageBox();

	connect(&m_autoClickTimer, &QTimer::timeout, this, &SystemInfoBox::onAutoClickButtonTimeout);
	connect(&m_autoClickTimerRefresh, &QTimer::timeout, this, &SystemInfoBox::onAutoClickButtonRefreshTimeout);
}

SystemInfoBox::~SystemInfoBox()
{

}

SystemInfoBox * SystemInfoBox::getBoxInstance()
{
	if (m_syspBoxInstance == NULL)
	{
		m_syspBoxInstance = new SystemInfoBox();
	}
	return m_syspBoxInstance;
}

void SystemInfoBox::setMovePosAlignment(int PosXAlignment /*= 0*/, int PosYAlignment /*= 0*/)
{
	m_PosXAlignment = PosXAlignment;
	m_PosYAlignment = PosYAlignment;
}

void SystemInfoBox::setMovePosition(int PositionX /*= 0*/, int PositionY /*= 0*/)
{
	m_PositionX = PositionX;
	m_PositionY = PositionY;
}

bool SystemInfoBox::showMessageBox(const QString &title, const QString& text, INFO_TYPE type /*= MTMWARNING*/)
{
	if (m_isAutoClickButtion)
	{
		m_autoClickTimerRefresh.start();
		m_autoClickTimer.start();
	}

	if (type == INFO_TYPE::MTMCRITICAL)
	{
		QIcon ico(":/img/msg_critical.png");
		getBoxInstance()->ui.pushButtonicoclose->setIcon(ico);
		getBoxInstance()->ui.cancelbutton->show();
	}
	else if (type == INFO_TYPE::MTMINFORMATION)
	{
		QIcon ico(":/img/msg_info.png");
		getBoxInstance()->ui.pushButtonicoclose->setIcon(ico);
		getBoxInstance()->ui.cancelbutton->show();
	}
	else if (type == INFO_TYPE::MTMQUESTION)
	{
		QIcon ico(":/img/msg_question.png");
		getBoxInstance()->ui.pushButtonicoclose->setIcon(ico);
		getBoxInstance()->ui.cancelbutton->show();
	}
	else if (type == INFO_TYPE::MTMWARNING)
	{
		QIcon ico(":/img/msg_warning.png");
		getBoxInstance()->ui.pushButtonicoclose->setIcon(ico);
		getBoxInstance()->ui.cancelbutton->hide();
	}
	else if (type == INFO_TYPE::MTMNOICON)
	{
		getBoxInstance()->ui.pushButtonicoclose->hide();
	}
	getBoxInstance()->ui.pushButtonicoclose->setIconSize(QSize(40, 40));

	getBoxInstance()->moveMessageBox();

	getBoxInstance()->showEasyInfoMessge(title, text);

	return m_result;
}

void SystemInfoBox::setAutoClickButton(bool isAutoClickButtion /*= true*/, int timeoutSecond /*= 5*/, int buttonType /*= ConfirmButton*/)
{
	m_isAutoClickButtion = isAutoClickButtion;

	m_autoClickButtonType = buttonType;

	switch (m_autoClickButtonType) {
	case ConfirmButton:
		m_ButtonText = getBoxInstance()->ui.confirmbutton->text();
		break;
	default:
	case CancelButton:
		m_ButtonText = getBoxInstance()->ui.cancelbutton->text();
		break;
	}

	m_autoClickTimerRefresh.setInterval(800);

	m_autoClickTimer.setInterval(timeoutSecond * 1000);
}
