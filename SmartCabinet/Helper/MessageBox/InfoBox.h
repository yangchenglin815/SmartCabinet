#pragma once

#include <QDialog>
#include <QTimer>
#include "ui_InfoBox.h"
#include "MtmMessageBox_global.h"
#include "mtmtts.h"

/**
* @brief The InfoBox class ��Ϣ��ʾ�����
*/
class InfoBox : public QDialog
{
	Q_OBJECT

public:
	static InfoBox * getBoxInstance();

	/**
	* @brief setMovePosAlignment ������Ϣ��ʾ�ƶ�λ�ö��뷽ʽ
	* @param PosXAlignment
	* @param PosYAlignment
	* @details (PosXAlignment,PosYAlignment) 0,0 ���ϽǶ��� 0,1 ���ϽǶ��� 1,0 ���½Ƕ��� 1,1 ���½Ƕ���
	*/
	static void setMovePosAlignment(int PosXAlignment = 0, int PosYAlignment = 0);

	/**
	* @brief setMovePosition ������Ϣ��ʾ�ƶ���λ��
	* @param PositionX ����X
	* @param PositionY ����Y
	*/
	static void setMovePosition(int PositionX = 0, int PositionY = 0);

	/**
	* @brief closeBox �ر�
	*/
	static void closeBox();

	/**
	* @brief InfoShowBox ������������ʾ
	* @param msg ��ʾ����
	* @param type ��ʾ���Ĭ��Ϊ����
	*/
	static void InfoShowBox(QString msg, INFO_TYPE type = MTMWARNING);
	/**
	* @brief InfoShowTtsBox ����������ʾ
	* @param msg ��ʾ����
	* @param type ��ʾ���Ĭ��Ϊ����
	*/
	static void InfoShowTtsBox(QString msg, bool IsPurgeBeforeSpeak = true, INFO_TYPE type = MTMWARNING);

protected:
	/**
	* @brief showInfoMessge ��ʾ
	* @param msg ��ʾ����
	* @param type ��ʾ���Ĭ��Ϊ����
	*/
	void showInfoMessge(QString msg, INFO_TYPE type = MTMWARNING);
	/**
	* @brief moveMessageBox ������ʾ���λ��
	* @details PositionX��ֵԽС����ʾ���λ�������ң�PositionY��ֵԽС��ʾ��Խ��������
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
