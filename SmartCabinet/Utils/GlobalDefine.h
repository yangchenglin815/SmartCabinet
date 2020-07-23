#include <QDebug>
#include <QDateTime>
#include <QString>
#include <QSettings>
#include <QCoreApplication>
#include <map>
#include "mtmtype.h"
#include <QMap>
#include <QThread>

using namespace std;
/************************************************************************/
/* �������η�                                                            */
/************************************************************************/

#ifndef OUT
#define OUT                                                 /**< ����������η� */
#endif

#ifndef IN
#define IN                                                  /**< ����������η� */
#endif

#define STR_EMPTY ""

#define SERIAL_PORT_FOR_LOCK "CLockBoardOper"
#define SERIAL_PORT_FOR_GUN  "CLockGunOper"
#define SERIAL_PORT_FOR_RFID "CLockRFIDOper"


//supplies status
#define SUPPLIES_STATUS_GET_OUT        0       //ȡ��
#define SUPPLIES_STATUS_SAVE_IN        1       //����
#define SUPPLIES_STATUS_USE            2       //ʹ��
#define SUPPLIES_STATUS_RETRUN         3       //�黹

//
// Success codes
//
#define S_OK                                   ((HRESULT)0L)
#define S_FALSE                                ((HRESULT)1L)
//*************************
//sys log out

#ifdef QT_NO_DEBUG
#define LogInfo  qDebug()<<"["<<(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz")).toStdString().c_str() <<  "]" <<__LINE__<<__FUNCTION__<<QThread::currentThreadId()<<" : "
#else
#define LogInfo  qDebug()<<"["<<(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz")).toStdString().c_str() <<  "]" << __LINE__<<__FUNCTION__<<QThread::currentThreadId()<<" : "
#endif

//*************************
typedef int AssistIdType;
#ifndef _MESSAGEBOXSHOW_DEFINED
#define _MESSAGEBOXSHOW_DEFINED

#define MessageBoxShow(str) (MtmMessageBox::InfoShowTtsBox(str))

#endif // !_MESSAGEBOXSHOW_DEFINED

#ifndef _MESSGAESHOWANDLOG_DEFINED
#define _MESSGAESHOWANDLOG_DEFINED

#define MessageShowAndLog(str) (MtmMessageBox::InfoShowTtsBox(str),LogInfo << str)

#endif // !_MESSGAESHOWANDLOG_DEFINED

#ifndef UNIQUE_SLOT
#define UNIQUE_SLOT(a) &a,Qt::UniqueConnection              /**< Ψһ���ź����� */
#endif // !UNIQUE_SLOT

#define PERMISSION_ROLE_USER    "0" //�û�
#define PERMISSION_ROLE_ADMIN   "1" //����Ա
#define PERMISSION_ROLE_TMP     "2" //��ʱȨ��

/**
@brief MtmPermissionRoleType                             ��ɫȨ������
*/
enum MtmPermissionRoleType
{
	PermissionRoleDefault = -1,                             /**< ��Ȩ�� */
	PermissionRoleUser = 0,                                 /**< ʹ���ߣ�����Ա�� */
	PermissionRoleAdmin,                                    /**< ����Ա */
	PermissionRoleTempUser,                                 /**< ��ʱʹ���ߣ�����Ա�� */
};
typedef struct _LoginParam
{
	int iPort;//��¼�Ķ˿�
	int iDataMaxLen;//�������󳤶�
	QStringList IDLst; //��ʶ��ID�б�
	QString strUserID;//�û�ID
	QString strPwd;//�û�����
}LoginParam, *PLoginParam;


typedef struct _LOGIN_INFO
{
	bool    bLoginSuc; //�Ƿ��¼�ɹ�
	int     iCurAuthority;//��ǰ���û�Ȩ��
	QString strLoginUID;//��¼ID
	QString strLoginPwd;//����
	QString strUserPhone;//�绰
	QString strUserName;//����
	QString strDeptCode;//���ű���
	QString strDeptName;//��������
	QString strJobCode;//���ű���
	QString strJobName;//ְ�����ƣ�Web�˽�ɫ���ƣ�
	QString strFaceFilePath;//��������·��
	QString strUserAuthority;//�û�Ȩ��  ��1������Ա  "0"��ͨ�û�  2.3.4.5.����Ȩ��
	QString strCurAuthority; //�û���ǰʹ�õ�Ȩ�ޣ�����Ա����ʹ�����ֲ�ͬ��Ȩ��


	_LOGIN_INFO()
	{
		bLoginSuc = false;
		iCurAuthority = 0;
		strUserAuthority = PERMISSION_ROLE_USER;
		strCurAuthority = PERMISSION_ROLE_USER;
	}

	void Reset()
	{
		bLoginSuc = false;
		iCurAuthority = 0;
		strUserAuthority = PERMISSION_ROLE_USER;
		strCurAuthority = PERMISSION_ROLE_USER;
	}
}LOGIN_INFO;

//assist
#define PASSWORD_MAX_LENGTH     6
#define NORMAL_LENGTH           20
#define USER_ID_MAX_LENGTH      11

/**
@brief AssistID type    ��֤��ʽ������֤��ʽ�ַ�����Ӧ
@details ����+���� IC��+���� RFID+���� ָ��+����
*/
#define PASSWORD_AssistID_TYPE                0x0001                            ///< only password                    // 1
#define USERID_AssistID_TYPE                  0x0002                            ///< only user id                     // 2
#define IC_CARD_AssistID_TYPE                 0x0004                            ///< only ic card                     // 4
#define RFID_CARD_AssistID_TYPE               0x0008                            ///< only rfid card                   // 8
#define FINGERPRINT_AssistID_TYPE             0x0010                            ///< only fingetprint                 // 16
#define FACE_ID_AssistID_TYPE                 0x0020                            ///< only face id                     // 32
#define PASSWORD_FACE_ID_AssistID_TYPE        0x0021                            ///<  password and face id            // 33 = 1 | 32
#define IC_CARD_FACE_ID_AssistID_TYPE         0x0024                            ///<  ic card and face id             // 36 = 4 | 32
#define RFID_CARD_FACE_ID_AssistID_TYPE       0x0028                            ///<  rfid card and face id           // 40 = 8 | 32
#define FINGERPRINT_FACE_ID_AssistID_TYPE     0x0030                            ///<  fingetprint card and face id    // 48 = 16 | 32
#define USERID_FACE_ID_AssistID_TYPE          0x0022                            ///<  user id and face id             // 34 = 2 | 32

/**
@brief AssistID String                                   ��֤��ʽ�ַ���������֤��ʽ��Ӧ
*/
#define PASSWORD_METHOD                      "Password Method"                              /* ���뷽ʽ */
#define USERID_METHOD                        "UserID Method"                                /* �û���ŷ�ʽ */
#define IC_CARD_METHOD                       "IC Card Method"                               /* IC����ʽ */
#define RFID_CARD_METHOD                     "RFID Method"                                  /* RFID��ʽ */
#define FINGERPRINT_METHOD                   "FingerPrint Method"                           /* ָ��ʶ��ʽ */
#define FACE_ID_METHOD                       "FaceID Method"                                /* ����ʶ��ʽ */
#define PASSWORD_FACE_ID_METHOD              "Password And FaceID Method"                   /* ����������ʽ */
#define IC_CARD_FACE_ID_METHOD               "IC Card And FaceID Method"                    /* IC��������ʽ */
#define RFID_CARD_FACE_ID_METHOD             "RFID And FaceID Method"                       /* RFID������ʽ */
#define FINGERPRINT_FACE_ID_METHOD           "FingerPrint And FaceID Method"                /* ָ�ƺ�������ʽ */
#define USERID_FACE_ID_METHOD                "UserID And FaceID Method"                     /* �û���ź�������ʽ */


//Gui Define

#define DLG_SHOW_TIME_MS 3000
#define DLG_STAND_BY_TIME_MS 120000  ///< ���Ĭ������ʱ�䣬��λ������ 120��=2����
#define DLG_STAND_BY_TIME_MIN_MS 30000  ///< �����������ʱ�䣬��λ������ 30��
#define UPLOAD_OFFLINE_DATA_TIMING_TIME_MIN_MS 5000

#define PASSWORD_LONG 6
#define NORMAL_LONG 20
#define USER_ID_LENGTH 11

#define LOCKER_OPEN_STORE 0
#define LOCKER_OPEN_OUT   1
#define LOCKER_OPEN_ADMIN 2

#define ADVERTBYTIMER   1  //����˳�ʱ��
#define AUTOQUITBYTIMER 2  //��½�˳�ʱ��
//Gui info box

#define BOX_SHOW_WIDE 150
#define BOX_SHOW_HIGH 100

#define BOX_GAP_WIDE BOX_SHOW_WIDE+10
#define BOX_GAP_HIGH BOX_SHOW_HIGH+30


//*************************
//box Define
#define LOCKERS_ID_PR_LABEL  "ankang_"
#define LOCKERS_ID_LABEL  "ak_001_"
#define MAX_BOX_COUNT 300
#define LOCKERS_BOXID_ERROR "error"

#ifndef _SMARTLOCKERSTYPE_DEFINED
#define _SMARTLOCKERSTYPE_DEFINED

enum SmartLockersType
{
	SmartLockerPublic = 0,                                  ///< �������ܹ�
	SmartLockerInduction,                                   ///< ��׼��Ӧ���ܹ�

	SmartLockerCount                                        ///< ���ܹ�����
};

#endif // _SMARTLOCKERSTYPE_DEFINED

//����״̬-1 �� 0 �ո��� 1 ռ��2ռ��
enum BOX_STATE
{
	BOX_BROKEN = -1,
	BOX_NULL = 0,
	BOX_FILL = 1,
	BOX_NOFILL = 2
};

// supplies_status����״̬ -1 �� 0 �ո��� 1 ���� 2 ���� 3 �黹
enum SUPPLIES_STATUS
{
	SUPPLIES_BROKEN = -1,
	SUPPLIES_NULL = 0,
	SUPPLIES_EXIST = 1,
	SUPPLIES_INUSE = 2,
	SUPPLIES_RETURN = 3
};
//����������״̬ supplies_intact_status 0 ���� 1 �� 2 ��ʧ
enum SUPPLIES_INTACT_STATUS
{
	SUPPLIES_INTACT_NULL = -1,
	SUPPLIES_INTACT_OK = 0,
	SUPPLIES_INTACT_BROKEN = 1,
	SUPPLIES_INTACT_LOSE = 2,
};
enum TOOL_SENSOR_STATE
{
	TOOL_BROKEN = -1,
	TOOL_NON_SENSOR_EXIST = 0,
	TOOL_SENSOR_EXIST = 1,
	TOOL_INUSE = 2,
	TOOL_RETURN = 3
};

/************************************************************************/
/* ID ����                                                               */
/************************************************************************/

#ifndef _MTM_ID_LENGTH_DEFINED
#define _MTM_ID_LENGTH_DEFINED

enum MtmIdLength
{
	MtmLockerBoxIdLength = 8,                               /**< ����+����ID���� */
	MtmLockerIdLength = 4,                                  /**< ����ID���� */
	MtmBoxIdLength = 3,                                     /**< ����ID���� */
};

#endif // !_MTM_ID_LENGTH_DEFINED


#ifndef _SENSOR_READ_MODE_TYPE_
#define _SENSOR_READ_MODE_TYPE_
enum SensorReadMode
{
	ReadModeDefault = 0,    ///< Ĭ��ģʽ��ֱ�Ӷ�ȡĬ��group������
	ReadModeNumberAttach    ///< ��Ĭ��groupName�Ļ����ϸ������ֵ�ģʽ�������ܹ�ͬģʽ�µ����ݻ�ȡ
};
#endif // !_SENSOR_READ_MODE_TYPE_

#define LOCKERS_ROW_MAX_BOX 50
#define LOCKERS_TIMEOUT_MS 20000

//Face ID
#define FACE_REC_TIME_OUT 8000 //8s
#define FACE_REG_TIME_OUT 30000 //30s
#define FACE_REG_MAX_PIC_NUM 15
#define FACE_ATTENTION_TIME 6000 //6s ���ѵ���������ʶ������ʱ��

//user role
#define USER_ROLE_USER 0
#define USER_ROLE_ADMIN 1
#define USER_ROLE_OTHER 2


//supplies length
//#define SUPPLIES_LENGTH 30

//��������ͼ����ʾģʽ
#define BOX_SHOW_MODEL_DEFAULT     0
#define BOX_SHOW_MODEL_REMOTE      1
#define BOX_SHOW_MODEL_TIMEOUT     2
#define BOX_SHOW_MODEL_NOTWORK     3
#define BOX_SHOW_MODEL_BROKENTHING 4

//���ؽ����ģʽ
enum{
	BOX_DETAIL_MAIN = 1,
	BOX_DETAIL_LOGIN = 2,
};

//boxdetail  ��ʾ��ʽ
enum{
	BOX_DETAIL_DEFAULT = 1,
	BOX_DETAIL_REMOTE = 2,
};

//changepwd �ı�������
enum{
	textUserId = 0,
	textUsetName,
	textPassword,
	textConfirmPasswoed
};

enum
{
	INDEX = 0,
	ICON,
	NAME,
	DESCR,
	STATE,
};

enum
{
	TRAINTYPE = 0,
	TRAINNO,
	TRAINLINE,
	DELL,
};
enum
{
	TRAININFO = 0,
	USERNAME,
	TEL,
	USETIME,
};
enum CheckBoxState
{
	DISCHECKED = 0,//��ɫX��ť
	SUPPLIESOK,//��ɫ�Թ���ť����־��ɨ��ɹ�������
};

#define MIN_MOVE_DIS 50

#define CAR_NUM_LENGTH 10

//ͼƬ����Բ�ǵĴ�С
#define PIC_RADIUS  10.0
//Զ�������� ����ѡ�����ʵİ�ť�Ĵ�С
#define BUTTON_SIZE_WIDTH  130
#define BUTTON_SIZE_HEIGTH 40
#define BUTTON_MAX_SIZE 1000
#define BUTTON_RIGHT_LENGTH 200

//������λ��  01010302    "0101" ���Ӻ� "03"���Ӻ�  "02"λ�ñ��
#define TOOLPICPOS_LOCKER_LENGTH 6 //���Ӻ�+���Ӻ�
#define TOOLPICPOS_POSNUM_LENGTH 4 //���Ӻ�+λ�ñ��
#define TOOLPICPOS_NODATA -2

//��Ӧʽ���ܹ� ��ѯ���ݴ���
#ifndef _INDUCTION_GETOUT_DEFINED
#define _INDUCTION_GETOUT_DEFINED

#define _INDUCTION_GETOUT_TYPEDEF_(_str) ((QString)_str)

//#define INDUCTION_OUTDEPOT_ID                       _INDUCTION_GETOUT_TYPEDEF_("unique_id")
#define INDUCTION_USER_ID                           _INDUCTION_GETOUT_TYPEDEF_("used_user_id")
#define INDUCTION_USER_NAME                         _INDUCTION_GETOUT_TYPEDEF_("user_name")
#define INDUCTION_SUPPLIES_ID                       _INDUCTION_GETOUT_TYPEDEF_("supplies_id")
#define INDUCTION_SUPPLIES_NAME                     _INDUCTION_GETOUT_TYPEDEF_("supplies_name")
#define INDUCTION_SUPPLIES_SPEC                     _INDUCTION_GETOUT_TYPEDEF_("supplies_specification")
#define INDUCTION_SUPPLIES_STATUS                   _INDUCTION_GETOUT_TYPEDEF_("supplies_status")
#define INDUCTION_POSTION_ID                        _INDUCTION_GETOUT_TYPEDEF_("position_id")
#define INDUCTION_BOX_ID                            _INDUCTION_GETOUT_TYPEDEF_("box_id")
#define INDUCTION_USE_TIME                          _INDUCTION_GETOUT_TYPEDEF_("use_time")
#define INDUCTION_PIC3D_X                           _INDUCTION_GETOUT_TYPEDEF_("pic_position_x")
#define INDUCTION_PIC3D_Y                           _INDUCTION_GETOUT_TYPEDEF_("pic_position_y")
#define INDUCTION_PIC3D_Z                           _INDUCTION_GETOUT_TYPEDEF_("pic_position_z")
#define INDUCTION_PIC3D_RX                          _INDUCTION_GETOUT_TYPEDEF_("pic_position_rx")
#define INDUCTION_PIC3D_RY                          _INDUCTION_GETOUT_TYPEDEF_("pic_position_ry")
#define INDUCTION_PIC3D_RZ                          _INDUCTION_GETOUT_TYPEDEF_("pic_position_rz")
#define INDUCTION_PIC_LONG                          _INDUCTION_GETOUT_TYPEDEF_("pic_long")
#define INDUCTION_PIC_WIDTH                         _INDUCTION_GETOUT_TYPEDEF_("pic_width")
#define INDUCTION_PIC_HEIGHT                        _INDUCTION_GETOUT_TYPEDEF_("pic_height")
#define INDUCTION_CREATE_TIME                       _INDUCTION_GETOUT_TYPEDEF_("create_time")
#define INDUCTION_MODIFY_TIME                       _INDUCTION_GETOUT_TYPEDEF_("modify_time")

#endif // !_INDUCTION_GETOUT_DEFINED

/************************************************************************/
/* ����Ȩ��                                                              */
/************************************************************************/

#ifdef _TRAINRELATION_DEFINED

enum MtmSqlType
{
	MtmSqlInsert = 0,                                       // INSERT INTO �б�
	MtmSqlValues,                                           // VALUES() �б�
	MtmSqlUpdate,                                           // key = Values(key) �б�
};

/**
@brief MTM_PERMISSION_DEFAULT
@details ��Ȩ��ΪĬ����Ȩ�ޣ���Ȩ��Ϊ��һλ������� 4 ��Ȩ��, ��ֵΪ 0b10000

@brief MTM_PERMISSION_MAX
@brief ���Ȩ�ޣ�����Ȩ��Ϊ��һλ������� 4 ��Ȩ�ޣ���ֵΪ 0b11111
*/
#define MTM_PERMISSION_DEFAULT (MtmPermission(1 << PermissionMax))      /**< Ĭ��Ȩ�ޣ���Ȩ�ޣ���λΪռλ�ֽ� */
#define MTM_PERMISSION_MAX (MtmPermission((2 << PermissionMax) - 1))    /**< ���Ȩ�ޣ���λΪռλ�ֽ� */
#define MTM_TRANSFROMPERMISSION_DIFF1(_per) ((MtmPermissionType)(_per - 1))
#define MTM_TRANSFROMPERMISSION_DIFF2(_per) ((MtmPermissionType)(_per - 2))

#define MTM_SqlFieldStatus_DEFAULT (QString("0"))
#define MTM_SqlFieldTime_DEFAULT (QString("0000-00-00T00:00:00"))       /**< ���ݿ�ʱ���ֶ�Ĭ��ֵ */

#endif // _TRAINRELATION_DEFINED

/************************************************************************/
/* �ַ�����                                                              */
/************************************************************************/

#define SQL_NULL ((QString)"NULL")                          /**< SQL�� */
#define STR_NULL ""                                         /**< ���ַ��� */
#define MQTTTOPIC_DEFAULT "ZhiYunSmartLockersBroadcast"     /**< MQTT����Ĭ��ֵ */

#define MTM_TIMEUNIT_MINUTE 60 /* ʱ�䵥λ�����ӣ�60�� */
typedef struct _initPara
{
	QString strUrl;
	int nEffectiveDiffTime; //��ȡʱ�䷶Χ ����
	_initPara()
	{
		strUrl = "";
		nEffectiveDiffTime = 0;
	}
}initParaST;

typedef struct _MtmTrainRelationData
{
	QString driverUserId;
	QString driverUserName;
	QString driverAttendanceStatus;
	QString practiceDriverUserId;
	QString practiceDriverUserName;
	QString practiceAttendanceStatus;
	QString studentUserId;
	QString studentUserName;
	QString studentAttendanceStatus;
	QString modelNum;
	QString trainNum;
	QString modelNum2;
	QString trainNum2;
	QString trainCode;
	QString trainLine;
	QString trainDepartureTime;
	QString plannedAttendanceTime;
	QString returnUserIds;


	_MtmTrainRelationData()
	{
		driverUserId = "";
		driverUserName = "";
		driverAttendanceStatus = "";
		practiceDriverUserId = "";
		practiceDriverUserName = "";
		practiceAttendanceStatus = "";
		studentUserId = "";
		studentUserName = "";
		studentAttendanceStatus = "";
		modelNum = "";
		trainNum = "";
		modelNum2 = "";
		trainNum2 = "";
		trainCode = "";
		trainLine = "";
		trainDepartureTime = "";
		plannedAttendanceTime = "";
		returnUserIds = "";
	}
}MtmTrainRelationWebData;

enum DataSynFlag{
	ErrorData,
	WebData = 1,
	LocalData = 2,
	ServerData = 4
};

#ifndef _YUNANKEYS_DEFINED
#define _YUNANKEYS_DEFINED
typedef QString MtmSqlKey;
#define MTMSQL_KEYDEF_(_str) ((MtmSqlKey)_str)

// ��ֵ����
const MtmSqlKey YunanKeys[] =
{
	MTMSQL_KEYDEF_("unique_id"),                            // �����ڵ���
	MTMSQL_KEYDEF_("driver_user_id"),                       // ˾������
	MTMSQL_KEYDEF_("driver_user_name"),                     // ˾������
	MTMSQL_KEYDEF_("driver_attendance_status"),             // ˾������״̬
	MTMSQL_KEYDEF_("practice_driver_user_id"),              // ѧϰ˾������
	MTMSQL_KEYDEF_("practice_driver_user_name"),            // ѧϰ˾������
	MTMSQL_KEYDEF_("practice_attendance_status"),           // ѧϰ˾������״̬
	MTMSQL_KEYDEF_("student_user_id"),                      // ѧԱ����
	MTMSQL_KEYDEF_("student_user_name"),                    // ѧԱ����
	MTMSQL_KEYDEF_("student_attendance_status"),            // ѧԱ����״̬
	MTMSQL_KEYDEF_("return_user_ids"),                      // �黹��ID�б�
	MTMSQL_KEYDEF_("return_user_names"),                    // �黹�������б�
	MTMSQL_KEYDEF_("model_num"),                            // ����
	MTMSQL_KEYDEF_("train_num"),                            // ����
	MTMSQL_KEYDEF_("model_num_2"),                          // ����2
	MTMSQL_KEYDEF_("train_num_2"),                          // ����2
	MTMSQL_KEYDEF_("train_line"),                           // ��·
	MTMSQL_KEYDEF_("train_departure_time"),                 // ����ʱ��
	MTMSQL_KEYDEF_("planned_attendance_time"),              // ����ʱ��
	MTMSQL_KEYDEF_("use_status"),                           // ��������Ȩ��
	MTMSQL_KEYDEF_("return_status"),                        // ���ʹ黹״̬
	MTMSQL_KEYDEF_("role_id"),                              // ��ɫ
	MTMSQL_KEYDEF_("use_effective_time"),                   // ��Чʱ��
	MTMSQL_KEYDEF_("supplies_status"),                      // ������״̬
	MTMSQL_KEYDEF_("train_code"),
	MTMSQL_KEYDEF_("remark"),                               // ��ע
	MTMSQL_KEYDEF_("create_time"),                          // ����ʱ��
	MTMSQL_KEYDEF_("modify_time")                           // �޸�ʱ��
};

// ��ֵ�±�
typedef enum
{
	KEY_UNIQUEID,                                           // �����ڵ���
	KEY_DRIVERID,                                           // ˾������
	KEY_DRIVERNAME,                                         // ˾������
	KEY_DRIVERATTENDANCE,                                   // ˾������״̬
	KEY_PRACTICEID,                                         // ѧϰ˾������
	KEY_PRACTICENAME,                                       // ѧϰ˾������
	KEY_PRACTICEATTENDANCE,                                 // ѧϰ˾������״̬
	KEY_STUDENTID,                                          // ѧԱ����
	KEY_STUDENTNAME,                                        // ѧԱ����
	KEY_STUDENTATTENDANCE,                                  // ѧԱ����״̬
	KEY_RETURNIDS,                                          // �黹��ID�б�
	KEY_RETURNNAMES,                                        // �黹�������б�
	KEY_TRAINTYPE,                                          // ����
	KEY_TRAINNO,                                            // ����
	KEY_TRAINTYPE_2,                                        // ����2
	KEY_TRAINNO_2,                                          // ����2
	KEY_TRAINLINE,                                          // ��·
	KEY_DEPARTURETIME,                                      // ����ʱ��
	KEY_ATTENDANCETIME,                                     // ����ʱ��
	KEY_SUPPERMISSION,                                      // ��������Ȩ��
	KEY_RETURNSTATUS,                                       // ���ʹ黹״̬
	KEY_ROLETYPE,                                           // ��ɫ
	KEY_EFFECTIVETIME,                                      // ��Чʱ��
	KEY_SUPPLIESSTATUS,                                     // ������״̬
	KEY_TRAINCODE,
	KEY_REMARK,                                             // ��ע
	KEY_CREATETIME,                                         // ����ʱ��
	KEY_MODIFYTIME,                                         // �޸�ʱ��

	KEY_COUNT,                                              // ��ֵ����
	KEY_MAX = KEY_COUNT,                                    // ��ֵ����
} YunanIdxKeyEnum;

#endif //_YUNANKEYS_DEFINED

#define PERMISSION_TEST(_sper, _idx) (0 != (_sper & (1 << _idx)))      /**< ����Ȩ�� */
#define PERMISSION_BLOCK(_idx) (MTM_PERMISSION_MAX & ~(1 << _idx))     /**< ����Ȩ�� */
#define PERMISSION_GRANT(_idx) (MTM_PERMISSION_DEFAULT | (1 << _idx))  /**< ����Ȩ�� */
#define _PERMISSION_BLOCK(_sper, _idx) (_sper &= (~(1 << _idx)))       /**< ����Ȩ�� */
#define _PERMISSION_GRANT(_sper, _idx) (_sper |= (1 << _idx))          /**< ����Ȩ�� */


// �˰�ϵͳ������Ϣ
struct MtmTrainRelationInfo
{
	// ��-��-����Ϣ
	MtmUserID userID;                                       /**< ���� */
	MtmUserName userName;                                   /**< ���� */
	MtmTrainType trainType;                                 /**< ���� */
	MtmTrainNo trainNo;                                     /**< ���� */
	MtmTrainType trainType2;                                /**< ����2 */
	MtmTrainNo trainNo2;                                    /**< ����2 */
	MtmTrainLine trainLine;                                 /**< ����· */

	// ������Ϣ
	MtmPermission supPermission;                            /**< ����Ȩ�޿��� */
	MtmPermissionRoleType roleType;                         /**< ���ݵĽ�ɫ���� */
	int iDataSynFlag;
	MtmUniqueID uniqueId;

private:
	// Ψһ            /**< Ψһ��� */
	MtmSqlValue m_values[YunanIdxKeyEnum::KEY_COUNT];
	QSet<YunanIdxKeyEnum> m_setAloneValueKey; // �������Ե�Key����

public:
	MtmTrainRelationInfo()
	{
		YunanIdxKeyEnum vecIdxKey[] =
		{
			KEY_TRAINTYPE,
			KEY_TRAINNO,
			KEY_TRAINTYPE_2,
			KEY_TRAINNO_2,
			KEY_TRAINLINE,
			KEY_SUPPERMISSION,
			KEY_ROLETYPE,
			KEY_UNIQUEID
		};

		for (int i = 0; i < 8; i++)
			m_setAloneValueKey.insert(vecIdxKey[i]);

		resetData();
	}

	void resetData()
	{
		// ��-����Ϣ
		userID = STR_NULL;
		userName = STR_NULL;
		trainType = STR_NULL;
		trainNo = STR_NULL;
		trainType2 = STR_NULL;
		trainNo2 = STR_NULL;
		trainLine = STR_NULL;
		supPermission = MTM_PERMISSION_DEFAULT;
		roleType = PermissionRoleDefault;
		iDataSynFlag = 0;

		// ������Ϣ
		uniqueId = "0";

		for (int i = 0; i < YunanIdxKeyEnum::KEY_COUNT; i++)
		{
			m_values[i].clear();
		}

		// ������Ϣ
		m_values[KEY_RETURNSTATUS] = MTM_SqlFieldStatus_DEFAULT;

		// ʱ����Ϣ
		m_values[KEY_DEPARTURETIME] = MTM_SqlFieldTime_DEFAULT;
		m_values[KEY_ATTENDANCETIME] = MTM_SqlFieldTime_DEFAULT;
		m_values[KEY_EFFECTIVETIME] = MTM_SqlFieldTime_DEFAULT;
		m_values[KEY_CREATETIME] = MTM_SqlFieldTime_DEFAULT;
		m_values[KEY_MODIFYTIME] = MTM_SqlFieldTime_DEFAULT;
	}

	bool isReceiveSupplies(IN const MtmPermissionType permissionType)
	{
		return PERMISSION_TEST(supPermission, permissionType);
	}

	void setReceiveSupplies(IN const MtmPermissionType permissionType, IN bool bBlockOrGrant)
	{
		if (true != bBlockOrGrant)
			_PERMISSION_BLOCK(supPermission, permissionType); // ����Ȩ��
		else
			_PERMISSION_GRANT(supPermission, permissionType); // ����Ȩ��

		setValue(KEY_SUPPERMISSION, supPermission);
	}

	void setValue(IN YunanIdxKeyEnum idxKey, IN MtmStringValue value)
	{
		m_values[idxKey] = value;
		if (m_setAloneValueKey.contains(idxKey))
			_setAloneValue(idxKey, m_values[idxKey]);
	}

	MtmStringValue getStringValue(IN YunanIdxKeyEnum idxKey)
	{
		return m_values[idxKey];
	}

	void setValue(IN YunanIdxKeyEnum idxKey, IN MtmNumberValue value)
	{
		m_values[idxKey] = QString::number(value);
		if (m_setAloneValueKey.contains(idxKey))
			_setAloneValue(idxKey, m_values[idxKey]);
	}

	MtmNumberValue getLongValue(IN YunanIdxKeyEnum idxKey)
	{
		return m_values[idxKey].toLong();
	}

	const MtmSqlValue* getValues()
	{
		return m_values;
	}

	MtmUniqueID getUniqueID()
	{
		return m_values[KEY_UNIQUEID];
	}

private:
	void _setAloneValue(IN YunanIdxKeyEnum idxKey, IN MtmStringValue& value)
	{
		switch (idxKey)
		{
		case KEY_TRAINTYPE:
			trainType = value;
			break;
		case KEY_TRAINNO:
			trainNo = value;
			break;
		case KEY_TRAINTYPE_2:
			trainType2 = value;
			break;
		case KEY_TRAINNO_2:
			trainNo2 = value;
			break;
		case KEY_TRAINLINE:
			trainLine = value;
			break;
		case KEY_SUPPERMISSION:
			supPermission = value.toUInt();
			break;
		case KEY_ROLETYPE:
			roleType = (MtmPermissionRoleType)value.toInt();
			break;
		case KEY_UNIQUEID:
			uniqueId = value;
			break;
		default:
			break;
		}
	}
};