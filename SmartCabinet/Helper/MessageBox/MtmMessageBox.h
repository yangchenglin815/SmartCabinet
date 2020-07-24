#include "MtmMessageBox_global.h"
#include <QWidget>

/**
* @brief The MtmMessageBox class ��ʾ��
* @see ���� InfoBox ��Ϣ��ʾ
* @see ���� systeminfo ѯ�ʿ�
* @see topInfoWidget ����ʹ��
*/
class InfoBox;
class MtmMessageBox
{

public:
	MtmMessageBox();

	~MtmMessageBox();

	/**
	* @brief setInfoBoxMovePosAlignment ������Ϣ��ʾ�ƶ�λ�ö��뷽ʽ
	* @param PosXAlignment
	* @param PosYAlignment
	* @details (PosXAlignment,PosYAlignment) 0,0 ���ϽǶ��� 0,1 ���ϽǶ��� 1,0 ���½Ƕ��� 1,1 ���½Ƕ���
	*/
	static void setInfoBoxMovePosAlignment(int PosXAlignment = 0, int PosYAlignment = 0);

	/**
	* @brief setInfoBoxMovePosition ������Ϣ��ʾ�ƶ���λ��
	* @param PositionX ����X
	* @param PositionY ����Y
	*/
	static void setInfoBoxMovePosition(int PositionX = 0, int PositionY = 0);

	/**
	* @brief setConfirmBoxMovePosAlignment ����ѯ�ʿ��ƶ�λ�ö��뷽ʽ
	* @param PosXAlignment
	* @param PosYAlignment
	* @details (PosXAlignment,PosYAlignment) 0,0 ���ϽǶ��� 0,1 ���ϽǶ��� 1,0 ���½Ƕ��� 1,1 ���½Ƕ���
	*/
	static void setConfirmBoxMovePosAlignment(int PosXAlignment = 0, int PosYAlignment = 0);

	/**
	* @brief setConfirmBoxMovePosition ����ѯ�ʿ��ƶ���λ��
	* @param PositionX ����X
	* @param PositionY ����Y
	*/
	static void setConfirmBoxMovePosition(int PositionX = 0, int PositionY = 0);

	/**
	* @brief closeBox �ر�
	*/
	static void closeBox();

	/**
	* @brief InfoShowBox ������������ʾ
	* @param msg ��ʾ����
	* @param type ��ʾ���Ĭ��Ϊ����
	*/
	static void InfoShowBox(QString msg, INFO_TYPE type = INFO_TYPE::MTMINFORMATION);

	/**
	* @brief InfoShowTtsBox ����������ʾ
	* @param msg ��ʾ����
	* @param type ��ʾ���Ĭ��Ϊ����
	*/
	static void InfoShowTtsBox(QString msg, bool IsPurgeBeforeSpeak = true, INFO_TYPE type = INFO_TYPE::MTMINFORMATION);

	/**
	* @brief MtmInfoBox ѯ�ʿ�
	* @param title ѯ�ʿ����
	* @param text ����
	* @param type ��ʾ���Ĭ��Ϊ����
	* @return true:���ȷ����ť false:���ȡ����ť
	*/
	static bool MtmInfoBox(const QString &title, const QString& text, INFO_TYPE type = INFO_TYPE::MTMINFORMATION, bool isAutoClickButtion = false, int timeoutSecond = 5, int buttonType = ConfirmButton);
	/**
	* @brief setInfoBoxParent ���ø���QWidget
	* @param parent
	* @details ������洰��ǰ����ʾ����
	*/
	static void setInfoBoxParent(QWidget* parent);
};
