#include "SuppliesIntactCheckDlg.h"
#include <QDesktopWidget>
#include "mtmerror.h"

#define BUTTON_OFFSET 80
#define MTM_TIME_MINUTE 1000

SuppliesIntactCheckDlg::SuppliesIntactCheckDlg(QWidget *parent)
	: QDialog(parent)
	, m_nAutoTimeOut(30)
	, m_bIsUp(true)
	, m_lDestopWidth(0)
	, m_lDestopHeight(0)
	, m_suppliesIntactStatus(INTACT_UNKNOWN)
{
	ui.setupUi(this);
	this->setModal(true);
	this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);//无标题

	m_lDestopWidth = QApplication::desktop()->width();
	m_lDestopHeight = QApplication::desktop()->height();
	this->move(m_lDestopWidth / 2 - this->width() / 2, m_lDestopHeight / 2 - this->height() / 2 - BUTTON_OFFSET);

	m_listMsgBtnName.push_back(tr("Supplies Normal"));
	m_listMsgBtnName.push_back(tr("Supplies Missing"));
	m_listMsgBtnName.push_back(tr("Supplies Bad"));

	connect(ui.btnClose, &QPushButton::clicked, this, &SuppliesIntactCheckDlg::onBtnClose);
	connect(&m_timer, &QTimer::timeout, this, &SuppliesIntactCheckDlg::onCanClick);
	connect(&m_timerAutoClick, &QTimer::timeout, this, &SuppliesIntactCheckDlg::onButtonNormalClicked);
	connect(ui.pushButtonNormal, &QPushButton::clicked, this, &SuppliesIntactCheckDlg::onButtonNormalClicked);
	connect(ui.pushButtonMissing, &QPushButton::clicked, this, &SuppliesIntactCheckDlg::onButtonMissingClicked);
	connect(ui.pushButtonBad, &QPushButton::clicked, this, &SuppliesIntactCheckDlg::onButtonBadClicked);
}

SuppliesIntactCheckDlg::~SuppliesIntactCheckDlg()
{

}

void SuppliesIntactCheckDlg::setContent(QString str)
{
	ui.labelContent->setText(str);
}

int SuppliesIntactCheckDlg::MessageBoxA(IN QString strMsg, IN QStringList listStrBtnName /*= QStringList()*/, IN MtmMessageType msgType /*= MtmMsgDefault*/, IN bool bAutoConfirm /*= true*/)
{
	m_suppliesIntactStatus = INTACT_COMPLETE; // 默认物资完整

	m_bIsUp = !m_bIsUp;
	int iMoveHeight = m_bIsUp ? BUTTON_OFFSET : -BUTTON_OFFSET;
	this->move(m_lDestopWidth / 2 - this->width() / 2, m_lDestopHeight / 2 - this->height() / 2 - iMoveHeight);

	ui.labelContent->setText(strMsg); // 设置消息内容

	mtm_vector<QPushButton*> vecBtn =
	{
		ui.pushButtonNormal,
		ui.pushButtonMissing,
		ui.pushButtonBad
	};

	MtmMsgType vecMsgType[] =
	{
		MtmMsgNormal,
		MtmMsgMissing,
		MtmMsgBad
	};

	if (MtmMsgDefault == msgType)
		listStrBtnName = m_listMsgBtnName;

	int idx = 0;
	for (int i = 0; i < MtmMsgCount; i++)
	{
		if (MtmMsgDefault == msgType || (0 != (vecMsgType[i] & msgType)))
		{
			vecBtn[i]->setText(listStrBtnName[idx]);
			vecBtn[i]->show();
			idx++;
		}
		else
		{
			vecBtn[i]->hide();
		}
	}

	this->show(); // 显示提示框

	m_timer.start(500);
	if (true == bAutoConfirm)
		m_timerAutoClick.start(MTM_TIME_MINUTE * m_nAutoTimeOut);

	ui.pushButtonNormal->blockSignals(true);
	ui.pushButtonMissing->blockSignals(true);
	ui.pushButtonBad->blockSignals(true);

	QEventLoop eventLoop;
	connect(this, &SuppliesIntactCheckDlg::suppliesIntactCheckSignal, &eventLoop, &QEventLoop::quit);
	eventLoop.exec();

	disconnect(this, &SuppliesIntactCheckDlg::suppliesIntactCheckSignal, &eventLoop, &QEventLoop::quit);
	return m_suppliesIntactStatus;
}

int SuppliesIntactCheckDlg::MessageBoxA(IN QString strMsg, IN int nTimeout, IN QStringList listStrBtnName /*= QStringList()*/, IN MtmMessageType msgType /*= MtmMsgDefault*/, IN bool bAutoConfirm /*= true*/)
{
	m_nAutoTimeOut = nTimeout;
	return MessageBoxA(strMsg, listStrBtnName, msgType, bAutoConfirm);
}

void SuppliesIntactCheckDlg::showEvent(QShowEvent *event)
{
	Q_UNUSED(event)
}

void SuppliesIntactCheckDlg::hideEvent(QHideEvent * event)
{
	Q_UNUSED(event)
}

void SuppliesIntactCheckDlg::closeEvent(QCloseEvent * event)
{
	Q_UNUSED(event)
	hide();
}

void SuppliesIntactCheckDlg::onCanClick()
{
	m_timer.stop();

	ui.pushButtonNormal->blockSignals(false);
	ui.pushButtonMissing->blockSignals(false);
	ui.pushButtonBad->blockSignals(false);
}

void SuppliesIntactCheckDlg::onBtnClose()
{
	m_timerAutoClick.stop();

	m_suppliesIntactStatus = INTACT_CLOSE;
	hide();

	emit suppliesIntactCheckSignal(m_suppliesIntactStatus);
}

void SuppliesIntactCheckDlg::onButtonNormalClicked()
{
	ui.pushButtonNormal->blockSignals(true);
	m_suppliesIntactStatus = INTACT_COMPLETE;
	hide();

	emit suppliesIntactCheckSignal(m_suppliesIntactStatus);
}

void SuppliesIntactCheckDlg::onButtonMissingClicked()
{
	m_timerAutoClick.stop();

	ui.pushButtonMissing->blockSignals(true);
	m_suppliesIntactStatus = INTACT_MISSING;
	hide();

	emit suppliesIntactCheckSignal(m_suppliesIntactStatus);
}

void SuppliesIntactCheckDlg::onButtonBadClicked()
{
	ui.pushButtonBad->blockSignals(true);
	m_suppliesIntactStatus = INTACT_DAMAGE;
	hide();

	emit suppliesIntactCheckSignal(m_suppliesIntactStatus);
}
