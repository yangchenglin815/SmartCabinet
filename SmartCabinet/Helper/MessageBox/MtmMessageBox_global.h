#pragma once

/**
* @brief The INFO_TYPE enum 消息类别
*/
enum INFO_TYPE
{
	MTMNOICON = 0, ///< 无图标
	MTMINFORMATION,///< 消息图标
	MTMWARNING,///< 警告图标
	MTMCRITICAL,///< 错误图标
	MTMQUESTION///< 询问图标
};

enum ButtonType
{
	ConfirmButton = 0, ///< 确认按钮
	CancelButton       ///< 取消按钮
};