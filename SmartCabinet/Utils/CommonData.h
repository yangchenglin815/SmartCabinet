#pragma once

#include "globaldefine.h"

typedef struct _CommonData
{
	int iModelTimeOut;   //;ɨ��ʱģ̬����ʾʱ��
	int iShowNullBox;    //�Ƿ���ʾ�ո���
	_CommonData()
	{
		iModelTimeOut = 5000;
		iShowNullBox = 0;
	}
}CommonData;
Q_DECLARE_METATYPE(_CommonData)

typedef struct _LockBaseInfos
{
	QWidget       *pLock;//����ָ��
	int           iCurAuthority; //��ǰ�û��л���Ȩ��
	int           iIndex;//������ʾ�ڵ�¼���������������
	int           iDspRow;//ÿ����ʾ������
	int           iDspColum;//ÿ����ʾ������
	int           iBoxWidth;//���ӿ��
	int           iBoxHight;//���Ӹ߶�
	int           iShowDetails;//������Ӻ��Ƿ���ʾ��ϸ��Ϣ,0ֱ�ӷ���ҵ��ָ�1��ʾ��ϸ��Ϣ�������û�����ϸҳ�淢��ҵ��ָ��
	int           iUseRFID;//�Ƿ�ʹ��RFID
	int           iUseGUN;//�Ƿ�ʹ��ɨ��ǹ
	int           iShowChoseOperTYpe;//�Ƿ���ʾ��������
	int           iShowChangeChoseOperTYpe;//�Ƿ���ʾ����豸 ѡ��������ͽ���
	int           iAutoSendScan;//�Ƿ��Զ���������ɨ���,���RFID��ɨ��ǹͬʱ���ڣ��������Ч
	int           iAutoOpenBox;//�Ƿ��Զ�����������
	int           iAutomaticMode;//�Ƿ��Զ�ģʽ
	int           isUseCloseBoxSignal;//�Ƿ�ʹ�ù����źţ������źŴ���ҵ��
	int           iCloseWindowsTimeOut;//���ų�ʱʱ��
	int           iChargeStateCheckTimeOut;//����豸��λ��ѯ��ʱʱ��(����)
	int           iUseTmpShowWidget;//�����ʱȨ���Ƿ񵯳���ȡ����
	int           isShowCMessageBox;//�Ƿ���ʾ��ȡ����ѯ�ʴ���
	int           isUpdateSmartTable;//�Ƿ����Smart��
	int           iCurLockerType;//��ǰѡ��Ĺ��������ͣ������
	bool          bInit;//�����Ƿ��Ѿ���ʼ������
	bool          bCurSelected;//�Ƿ��µ�ѡ�еĹ���
	int           isContinuityScanning;//�Ƿ�����ɨ��
	int           iRequestUseAuthority;//�Ƿ�������ȡȨ��
	QString       strLockerType;//��Ʒʹ������0Ϊ��ͨ��1Ϊ����豸2����3�ɹ�
	QString       strName;//��������
	QString       strLockNum;//���ӱ��
	QString       strClassName;//��������
	QString       strUseSuppSequence;//���˰�����ʱ����ȡ���ʵ�˳��
	QString       strIsJZWeightLocker; //�Ƿ���������
	QString       strChangeLockerSupType; //����������
	_LockBaseInfos()
	{
		pLock = NULL;
		iIndex = 0;
		iDspRow = 0;
		iDspColum = 0;
		iBoxWidth = 0;
		iBoxHight = 0;
		iShowDetails = 0;
		iUseGUN = 0;
		iShowChoseOperTYpe = 0;
		iShowChangeChoseOperTYpe = 0;
		iUseRFID = 0;
		iCurLockerType = 0;
		iAutoOpenBox = 0;
		bCurSelected = false;
		iCloseWindowsTimeOut = 60;
		bInit = false;
		iAutomaticMode = 0;
		strName = STR_EMPTY;
		strLockerType = STR_EMPTY;
		strLockNum = STR_EMPTY;
		strClassName = STR_EMPTY;
		strUseSuppSequence = STR_EMPTY;
		iUseTmpShowWidget = 0;
		isShowCMessageBox = 0;
		isUpdateSmartTable = 0;
		iChargeStateCheckTimeOut = 3000;
		strChangeLockerSupType = STR_EMPTY;
		isUseCloseBoxSignal = 1;
		iRequestUseAuthority = 0;
	}
}LockBaseInfos;
Q_DECLARE_METATYPE(_LockBaseInfos)