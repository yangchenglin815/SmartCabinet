#include "MtmMessageBox_global.h"
#include <QWidget>

/**
* @brief The MtmMessageBox class 提示类
* @see 引用 InfoBox 信息提示
* @see 引用 systeminfo 询问框
* @see topInfoWidget 单独使用
*/
class InfoBox;
class MtmMessageBox
{

public:
	MtmMessageBox();

	~MtmMessageBox();

	/**
	* @brief setInfoBoxMovePosAlignment 设置信息提示移动位置对齐方式
	* @param PosXAlignment
	* @param PosYAlignment
	* @details (PosXAlignment,PosYAlignment) 0,0 左上角对齐 0,1 右上角对齐 1,0 左下角对齐 1,1 右下角对齐
	*/
	static void setInfoBoxMovePosAlignment(int PosXAlignment = 0, int PosYAlignment = 0);

	/**
	* @brief setInfoBoxMovePosition 设置信息提示移动的位置
	* @param PositionX 坐标X
	* @param PositionY 坐标Y
	*/
	static void setInfoBoxMovePosition(int PositionX = 0, int PositionY = 0);

	/**
	* @brief setConfirmBoxMovePosAlignment 设置询问框移动位置对齐方式
	* @param PosXAlignment
	* @param PosYAlignment
	* @details (PosXAlignment,PosYAlignment) 0,0 左上角对齐 0,1 右上角对齐 1,0 左下角对齐 1,1 右下角对齐
	*/
	static void setConfirmBoxMovePosAlignment(int PosXAlignment = 0, int PosYAlignment = 0);

	/**
	* @brief setConfirmBoxMovePosition 设置询问框移动的位置
	* @param PositionX 坐标X
	* @param PositionY 坐标Y
	*/
	static void setConfirmBoxMovePosition(int PositionX = 0, int PositionY = 0);

	/**
	* @brief closeBox 关闭
	*/
	static void closeBox();

	/**
	* @brief InfoShowBox 不带语音的提示
	* @param msg 提示内容
	* @param type 提示类别，默认为警告
	*/
	static void InfoShowBox(QString msg, INFO_TYPE type = INFO_TYPE::MTMINFORMATION);

	/**
	* @brief InfoShowTtsBox 带语音的提示
	* @param msg 提示内容
	* @param type 提示类别，默认为警告
	*/
	static void InfoShowTtsBox(QString msg, bool IsPurgeBeforeSpeak = true, INFO_TYPE type = INFO_TYPE::MTMINFORMATION);

	/**
	* @brief MtmInfoBox 询问框
	* @param title 询问框标题
	* @param text 内容
	* @param type 提示类别，默认为警告
	* @return true:点击确定按钮 false:点击取消按钮
	*/
	static bool MtmInfoBox(const QString &title, const QString& text, INFO_TYPE type = INFO_TYPE::MTMINFORMATION, bool isAutoClickButtion = false, int timeoutSecond = 5, int buttonType = ConfirmButton);
	/**
	* @brief setInfoBoxParent 设置父类QWidget
	* @param parent
	* @details 解决界面窗口前后显示问题
	*/
	static void setInfoBoxParent(QWidget* parent);
};
