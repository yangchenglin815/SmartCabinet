#pragma once

/**
* @brief The INFO_TYPE enum ��Ϣ���
*/
enum INFO_TYPE
{
	MTMNOICON = 0, ///< ��ͼ��
	MTMINFORMATION,///< ��Ϣͼ��
	MTMWARNING,///< ����ͼ��
	MTMCRITICAL,///< ����ͼ��
	MTMQUESTION///< ѯ��ͼ��
};

enum ButtonType
{
	ConfirmButton = 0, ///< ȷ�ϰ�ť
	CancelButton       ///< ȡ����ť
};