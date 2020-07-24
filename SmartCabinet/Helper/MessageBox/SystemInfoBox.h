#pragma once

#include <QDialog>
#include <QTimer>
#include "ui_SystemInfoBox.h"
#include "MtmMessageBox_global.h"

/**
* @brief The systeminfo class 询问框基类
*/
class SystemInfoBox : public QDialog
{
	Q_OBJECT

public:
	SystemInfoBox(QWidget *parent = Q_NULLPTR);
	~SystemInfoBox();

	static SystemInfoBox * getBoxInstance();

	/**
	* @brief setMovePosAlignment 设置询问框移动位置对齐方式
	* @param PosXAlignment
	* @param PosYAlignment
	* @details (PosXAlignment,PosYAlignment) 0,0 左上角对齐 0,1 右上角对齐 1,0 左下角对齐 1,1 右下角对齐
	*/
	static void setMovePosAlignment(int PosXAlignment = 0, int PosYAlignment = 0);//设置移动位置对齐方式 0,0 左上角对齐 0,1 右上角对齐 1,0 左下角对齐 1,1 右下角对齐

	/**
	* @brief setMovePosition 设置询问框移动的位置
	* @param PositionX 坐标X
	* @param PositionY 坐标Y
	*/
	static void setMovePosition(int PositionX = 0, int PositionY = 0);//设置提示框移动的位置

	/**
	* @brief showOldMessageBox 询问框old
	* @param title 询问框标题
	* @param text 内容
	* @param type 提示类别，默认为警告
	* @return true:点击确定按钮 false:点击取消按钮
	*/
	static bool showMessageBox(const QString &title, const QString& text, INFO_TYPE type = MTMWARNING);

	static void setAutoClickButton(bool isAutoClickButtion = true, int timeoutSecond = 5, int buttonType = ConfirmButton);


private:
	Ui::SystemInfoBox ui;
	static SystemInfoBox * m_syspBoxInstance;
	static bool m_result;

	static int m_PosXAlignment;
	static int m_PosYAlignment;
	static int m_PositionX;
	static int m_PositionY;

	static bool m_isAutoClickButtion;///<< 是否自动点击按钮
	static QTimer m_autoClickTimer;///< 自动确认倒计时定时器
	static QTimer m_autoClickTimerRefresh;///< 自动确认倒计时刷新器
	static int m_autoClickButtonType;///< 自动点击的按钮类别
	static QString m_ButtonText;///< 自动点击按钮的文字

protected:
	/**
	* @brief showEasyInfoMessge 简单询问框
	* @details 用于其他调用，而不是直接操作ui，例如静态showMessageBox
	* @param titletype 询问框标题
	* @param msg 内容
	*/
	void showEasyInfoMessge(QString title, QString msg);
	/**
	* @brief moveMessageBox 调整提示框的位置
	* @details PositionX的值越小，提示框的位置是往右，PositionY的值越小提示框越是往下面
	*/
	void moveMessageBox();

	void closeEvent(QCloseEvent *event);

private slots:
	void onCloseButtonClicked();
	void onConfirmButtonClicked();
	void onCancelButtonClicked();

	/**
	* @brief onAutoClickButtonTimeout 倒计时自动点击
	*/
	void onAutoClickButtonTimeout();
	/**
	* @brief onAutoClickButtonRefreshTimeout 界面刷新定时器
	*/
	void onAutoClickButtonRefreshTimeout();

};
