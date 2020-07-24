#pragma once

#include <QDialog>
#include <QTimer>
#include "ui_TopInfoBox.h"

/**
* @brief The topInfoWidget class �ö�����
*/
class TopInfoBox : public QDialog
{
	Q_OBJECT

public:
	static TopInfoBox * getBoxInstance();

	/**
	* @brief setStaticText �����в���̬��ʾ����
	* @param str ��ʾ����
	*/
	void setStaticText(QString str);

public slots:
	/**
	* @brief showTopWidget ��ʾ�ö���
	* @param str ��ʾ����
	* @param timeout_ms ��ʱʱ�䣬��λ������ Ĭ��2000ms
	*/
	void showTopWidget(QString str, QString strMid = tr("data loading"), int iShowType = 0, int timeout_ms = 20000);

	/**
	* @brief hideTopWidget �����ö���
	*/
	void hideTopWidget(int iShowType = 0);
	void hideWidget();
	/**
	* @brief textSpangled ������ɫ��˸
	*/
	void textSpangled();

	/**
	* @brief setLeastShowTime �������ٽ�����ʾʱ��
	* @param msec ʱ�䣬��λ������ Ĭ��1500ms
	*/
	void setLeastShowTime(int msec = 1500);
	/**
	* @brief setLeastFlashTime ��������������˸ʱ��
	* @param msec ʱ�䣬��λ������ Ĭ��300ms
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
	int m_leastShowTime;///< ���ٽ�����ʾʱ��
	int m_leastFlashTime;///< ����������˸ʱ��
	int m_iShowType; //��ʾ���� 0��ͨ���ͣ�1ɨ����������
};
