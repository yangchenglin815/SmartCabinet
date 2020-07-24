#pragma once

#include <QDialog>
#include <QTimer>
#include "ui_SystemInfoBox.h"
#include "MtmMessageBox_global.h"

/**
* @brief The systeminfo class ѯ�ʿ����
*/
class SystemInfoBox : public QDialog
{
	Q_OBJECT

public:
	SystemInfoBox(QWidget *parent = Q_NULLPTR);
	~SystemInfoBox();

	static SystemInfoBox * getBoxInstance();

	/**
	* @brief setMovePosAlignment ����ѯ�ʿ��ƶ�λ�ö��뷽ʽ
	* @param PosXAlignment
	* @param PosYAlignment
	* @details (PosXAlignment,PosYAlignment) 0,0 ���ϽǶ��� 0,1 ���ϽǶ��� 1,0 ���½Ƕ��� 1,1 ���½Ƕ���
	*/
	static void setMovePosAlignment(int PosXAlignment = 0, int PosYAlignment = 0);//�����ƶ�λ�ö��뷽ʽ 0,0 ���ϽǶ��� 0,1 ���ϽǶ��� 1,0 ���½Ƕ��� 1,1 ���½Ƕ���

	/**
	* @brief setMovePosition ����ѯ�ʿ��ƶ���λ��
	* @param PositionX ����X
	* @param PositionY ����Y
	*/
	static void setMovePosition(int PositionX = 0, int PositionY = 0);//������ʾ���ƶ���λ��

	/**
	* @brief showOldMessageBox ѯ�ʿ�old
	* @param title ѯ�ʿ����
	* @param text ����
	* @param type ��ʾ���Ĭ��Ϊ����
	* @return true:���ȷ����ť false:���ȡ����ť
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

	static bool m_isAutoClickButtion;///<< �Ƿ��Զ������ť
	static QTimer m_autoClickTimer;///< �Զ�ȷ�ϵ���ʱ��ʱ��
	static QTimer m_autoClickTimerRefresh;///< �Զ�ȷ�ϵ���ʱˢ����
	static int m_autoClickButtonType;///< �Զ�����İ�ť���
	static QString m_ButtonText;///< �Զ������ť������

protected:
	/**
	* @brief showEasyInfoMessge ��ѯ�ʿ�
	* @details �����������ã�������ֱ�Ӳ���ui�����羲̬showMessageBox
	* @param titletype ѯ�ʿ����
	* @param msg ����
	*/
	void showEasyInfoMessge(QString title, QString msg);
	/**
	* @brief moveMessageBox ������ʾ���λ��
	* @details PositionX��ֵԽС����ʾ���λ�������ң�PositionY��ֵԽС��ʾ��Խ��������
	*/
	void moveMessageBox();

	void closeEvent(QCloseEvent *event);

private slots:
	void onCloseButtonClicked();
	void onConfirmButtonClicked();
	void onCancelButtonClicked();

	/**
	* @brief onAutoClickButtonTimeout ����ʱ�Զ����
	*/
	void onAutoClickButtonTimeout();
	/**
	* @brief onAutoClickButtonRefreshTimeout ����ˢ�¶�ʱ��
	*/
	void onAutoClickButtonRefreshTimeout();

};
