#pragma once

#include <QDialog>
#include <QTimer>
#include "ui_SuppliesIntactCheckDlg.h"
#include "GlobalDefine.h"

typedef long MtmMessageType;

enum MtmMsgType
{
	MtmMsgDefault = 0x00,
	MtmMsgNormal = 0x01,
	MtmMsgMissing = 0x02,
	MtmMsgBad = 0x04,

	MtmMsgAll = (MtmMsgBad << 1) - 1,
	MtmMsgCount = 3
};

class SuppliesIntactCheckDlg : public QDialog
{
	Q_OBJECT

public:
	SuppliesIntactCheckDlg(QWidget *parent = Q_NULLPTR);
	~SuppliesIntactCheckDlg();

	/**
	* @brief setContent 设置完整性确认文字
	* @param str 文字内容
	*/
	void setContent(QString str);

	/**
	@brief MessageBoxA                                   显示提示框，并设置内容
	@param strMsg                                        提示内容
	*/
	int MessageBoxA(IN QString strMsg, IN QStringList listStrBtnName = QStringList(), IN MtmMessageType msgType = MtmMsgDefault, IN bool bAutoConfirm = true);

	int MessageBoxA(IN QString strMsg, IN int nTimeout, IN QStringList listStrBtnName = QStringList(), IN MtmMessageType msgType = MtmMsgDefault, IN bool bAutoConfirm = true);

	void showEvent(QShowEvent *event);
	void hideEvent(QHideEvent * event);
	void closeEvent(QCloseEvent * event);

signals:
	/**
	* @brief suppliesIntactCheckSignal 物资完整性信号
	* @param suppliesIntactStatus -1：未知错误 0：完整 1：缺失 2：损坏
	*/
	void suppliesIntactCheckSignal(IntactType suppliesIntactStatus);

private slots:
	void onCanClick();
	void onBtnClose();
	void onButtonNormalClicked();
	void onButtonMissingClicked();
	void onButtonBadClicked();

private:
	Ui::SuppliesIntactCheckDlg ui;

	bool m_bIsUp;
	long m_lDestopWidth;
	long m_lDestopHeight;

	QStringList m_listMsgBtnName;

	QTimer m_timer;
	QTimer m_timerAutoClick;
	int m_nAutoTimeOut; // 自动超时时间
	IntactType m_suppliesIntactStatus;///< 物资完整性
};

typedef mtm_stdptr<SuppliesIntactCheckDlg> suppliesIntactCheckPtr;
