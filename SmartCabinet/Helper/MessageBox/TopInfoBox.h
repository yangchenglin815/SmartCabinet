#pragma once

#include <QDialog>
#include <QTimer>
#include "ui_TopInfoBox.h"

/**
* @brief The topInfoWidget class 置顶框类
*/
class TopInfoBox : public QDialog
{
	Q_OBJECT

public:
	static TopInfoBox * getBoxInstance();

	/**
	* @brief setStaticText 设置中部静态提示内容
	* @param str 提示内容
	*/
	void setStaticText(QString str);

public slots:
	/**
	* @brief showTopWidget 显示置顶框
	* @param str 提示内容
	* @param timeout_ms 超时时间，单位：毫秒 默认2000ms
	*/
	void showTopWidget(QString str, QString strMid = tr("data loading"), int iShowType = 0, int timeout_ms = 20000);

	/**
	* @brief hideTopWidget 隐藏置顶框
	*/
	void hideTopWidget(int iShowType = 0);
	void hideWidget();
	/**
	* @brief textSpangled 字体颜色闪烁
	*/
	void textSpangled();

	/**
	* @brief setLeastShowTime 设置最少界面显示时间
	* @param msec 时间，单位：毫秒 默认1500ms
	*/
	void setLeastShowTime(int msec = 1500);
	/**
	* @brief setLeastFlashTime 设置文字最少闪烁时间
	* @param msec 时间，单位：毫秒 默认300ms
	*/
	void setLeastFlashTime(int msec = 300);

private:
	TopInfoBox(QWidget *parent = Q_NULLPTR);
	~TopInfoBox();

private:
	Ui::TopInfoBox ui;
	static TopInfoBox * m_pBoxInstance;
	QTimer m_timeoutTimer;
	QTimer m_flashTimer;
	int flashCount;
	int m_leastShowTime;///< 最少界面显示时间
	int m_leastFlashTime;///< 文字最少闪烁时间
	int m_iShowType; //显示类型 0普通类型，1扫描物资类型
};
