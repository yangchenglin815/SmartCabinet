#pragma once

#include <QDialog>
#include <QTimer>
#include "ui_InfoBox.h"
#include "MtmMessageBox_global.h"
#include "mtmtts.h"

/**
* @brief The InfoBox class 消息提示框基类
*/
class InfoBox : public QDialog
{
	Q_OBJECT

public:
	static InfoBox * getBoxInstance();

	/**
	* @brief setMovePosAlignment 设置信息提示移动位置对齐方式
	* @param PosXAlignment
	* @param PosYAlignment
	* @details (PosXAlignment,PosYAlignment) 0,0 左上角对齐 0,1 右上角对齐 1,0 左下角对齐 1,1 右下角对齐
	*/
	static void setMovePosAlignment(int PosXAlignment = 0, int PosYAlignment = 0);

	/**
	* @brief setMovePosition 设置信息提示移动的位置
	* @param PositionX 坐标X
	* @param PositionY 坐标Y
	*/
	static void setMovePosition(int PositionX = 0, int PositionY = 0);

	/**
	* @brief closeBox 关闭
	*/
	static void closeBox();

	/**
	* @brief InfoShowBox 不带语音的提示
	* @param msg 提示内容
	* @param type 提示类别，默认为警告
	*/
	static void InfoShowBox(QString msg, INFO_TYPE type = MTMWARNING);
	/**
	* @brief InfoShowTtsBox 带语音的提示
	* @param msg 提示内容
	* @param type 提示类别，默认为警告
	*/
	static void InfoShowTtsBox(QString msg, bool IsPurgeBeforeSpeak = true, INFO_TYPE type = MTMWARNING);

protected:
	/**
	* @brief showInfoMessge 提示
	* @param msg 提示内容
	* @param type 提示类别，默认为警告
	*/
	void showInfoMessge(QString msg, INFO_TYPE type = MTMWARNING);
	/**
	* @brief moveMessageBox 调整提示框的位置
	* @details PositionX的值越小，提示框的位置是往右，PositionY的值越小提示框越是往下面
	*/
	void moveMessageBox();

private:
	InfoBox(QWidget *parent = Q_NULLPTR);
	~InfoBox();

private:
	Ui::InfoBox ui;
	QTimer m_showTimer;
	static InfoBox * m_pBoxInstance;
	static MtmTTS * m_pttsInstance;

	static int m_PosXAlignment;
	static int m_PosYAlignment;
	static int m_PositionX;
	static int m_PositionY;
};
