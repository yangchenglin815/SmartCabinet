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
/* 参数修饰符                                                            */
/************************************************************************/

#ifndef OUT
#define OUT                                                 /**< 输出参数修饰符 */
#endif

#ifndef IN
#define IN                                                  /**< 输入参数修饰符 */
#endif

#define STR_EMPTY ""

#define SERIAL_PORT_FOR_LOCK "CLockBoardOper"
#define SERIAL_PORT_FOR_GUN  "CLockGunOper"
#define SERIAL_PORT_FOR_RFID "CLockRFIDOper"


//supplies status
#define SUPPLIES_STATUS_GET_OUT        0       //取出
#define SUPPLIES_STATUS_SAVE_IN        1       //存入
#define SUPPLIES_STATUS_USE            2       //使用
#define SUPPLIES_STATUS_RETRUN         3       //归还

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
#define UNIQUE_SLOT(a) &a,Qt::UniqueConnection              /**< 唯一性信号连接 */
#endif // !UNIQUE_SLOT

#define PERMISSION_ROLE_USER    "0" //用户
#define PERMISSION_ROLE_ADMIN   "1" //管理员
#define PERMISSION_ROLE_TMP     "2" //临时权限

/**
@brief MtmPermissionRoleType                             角色权限类型
*/
enum MtmPermissionRoleType
{
	PermissionRoleDefault = -1,                             /**< 无权限 */
	PermissionRoleUser = 0,                                 /**< 使用者（乘务员） */
	PermissionRoleAdmin,                                    /**< 管理员 */
	PermissionRoleTempUser,                                 /**< 临时使用者（乘务员） */
};
typedef struct _LoginParam
{
	int iPort;//登录的端口
	int iDataMaxLen;//密码的最大长度
	QStringList IDLst; //待识别ID列表
	QString strUserID;//用户ID
	QString strPwd;//用户密码
}LoginParam, *PLoginParam;


typedef struct _LOGIN_INFO
{
	bool    bLoginSuc; //是否登录成功
	int     iCurAuthority;//当前的用户权限
	QString strLoginUID;//登录ID
	QString strLoginPwd;//密码
	QString strUserPhone;//电话
	QString strUserName;//名称
	QString strDeptCode;//部门编码
	QString strDeptName;//部门名称
	QString strJobCode;//部门编码
	QString strJobName;//职务名称（Web端角色名称）
	QString strFaceFilePath;//人脸数据路径
	QString strUserAuthority;//用户权限  “1”管理员  "0"普通用户  2.3.4.5.其他权限
	QString strCurAuthority; //用户当前使用的权限，管理员可能使用两种不同的权限


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
@brief AssistID type    验证方式，与验证方式字符串对应
@details 密码+人脸 IC卡+人脸 RFID+人脸 指纹+人脸
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
@brief AssistID String                                   验证方式字符串，与验证方式对应
*/
#define PASSWORD_METHOD                      "Password Method"                              /* 密码方式 */
#define USERID_METHOD                        "UserID Method"                                /* 用户编号方式 */
#define IC_CARD_METHOD                       "IC Card Method"                               /* IC卡方式 */
#define RFID_CARD_METHOD                     "RFID Method"                                  /* RFID方式 */
#define FINGERPRINT_METHOD                   "FingerPrint Method"                           /* 指纹识别方式 */
#define FACE_ID_METHOD                       "FaceID Method"                                /* 人脸识别方式 */
#define PASSWORD_FACE_ID_METHOD              "Password And FaceID Method"                   /* 密码人脸方式 */
#define IC_CARD_FACE_ID_METHOD               "IC Card And FaceID Method"                    /* IC卡人脸方式 */
#define RFID_CARD_FACE_ID_METHOD             "RFID And FaceID Method"                       /* RFID人脸方式 */
#define FINGERPRINT_FACE_ID_METHOD           "FingerPrint And FaceID Method"                /* 指纹和人脸方式 */
#define USERID_FACE_ID_METHOD                "UserID And FaceID Method"                     /* 用户编号和人脸方式 */


//Gui Define

#define DLG_SHOW_TIME_MS 3000
#define DLG_STAND_BY_TIME_MS 120000  ///< 广告默认启动时间，单位：毫秒 120秒=2分钟
#define DLG_STAND_BY_TIME_MIN_MS 30000  ///< 广告启动最少时间，单位：毫秒 30秒
#define UPLOAD_OFFLINE_DATA_TIMING_TIME_MIN_MS 5000

#define PASSWORD_LONG 6
#define NORMAL_LONG 20
#define USER_ID_LENGTH 11

#define LOCKER_OPEN_STORE 0
#define LOCKER_OPEN_OUT   1
#define LOCKER_OPEN_ADMIN 2

#define ADVERTBYTIMER   1  //广告退出时间
#define AUTOQUITBYTIMER 2  //登陆退出时间
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
	SmartLockerPublic = 0,                                  ///< 公用智能柜
	SmartLockerInduction,                                   ///< 精准感应智能柜

	SmartLockerCount                                        ///< 智能柜种类
};

#endif // _SMARTLOCKERSTYPE_DEFINED

//格子状态-1 损坏 0 空格子 1 占满2占用
enum BOX_STATE
{
	BOX_BROKEN = -1,
	BOX_NULL = 0,
	BOX_FILL = 1,
	BOX_NOFILL = 2
};

// supplies_status物资状态 -1 损坏 0 空格子 1 存入 2 领用 3 归还
enum SUPPLIES_STATUS
{
	SUPPLIES_BROKEN = -1,
	SUPPLIES_NULL = 0,
	SUPPLIES_EXIST = 1,
	SUPPLIES_INUSE = 2,
	SUPPLIES_RETURN = 3
};
//物资完整性状态 supplies_intact_status 0 正常 1 损坏 2 丢失
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
/* ID 长度                                                               */
/************************************************************************/

#ifndef _MTM_ID_LENGTH_DEFINED
#define _MTM_ID_LENGTH_DEFINED

enum MtmIdLength
{
	MtmLockerBoxIdLength = 8,                               /**< 柜子+格子ID长度 */
	MtmLockerIdLength = 4,                                  /**< 柜子ID长度 */
	MtmBoxIdLength = 3,                                     /**< 格子ID长度 */
};

#endif // !_MTM_ID_LENGTH_DEFINED


#ifndef _SENSOR_READ_MODE_TYPE_
#define _SENSOR_READ_MODE_TYPE_
enum SensorReadMode
{
	ReadModeDefault = 0,    ///< 默认模式：直接读取默认group的数据
	ReadModeNumberAttach    ///< 在默认groupName的基础上附加数字的模式，如智能柜不同模式下的数据获取
};
#endif // !_SENSOR_READ_MODE_TYPE_

#define LOCKERS_ROW_MAX_BOX 50
#define LOCKERS_TIMEOUT_MS 20000

//Face ID
#define FACE_REC_TIME_OUT 8000 //8s
#define FACE_REG_TIME_OUT 30000 //30s
#define FACE_REG_MAX_PIC_NUM 15
#define FACE_ATTENTION_TIME 6000 //6s 提醒调整人脸到识别区域时间

//user role
#define USER_ROLE_USER 0
#define USER_ROLE_ADMIN 1
#define USER_ROLE_OTHER 2


//supplies length
//#define SUPPLIES_LENGTH 30

//工具缩略图的显示模式
#define BOX_SHOW_MODEL_DEFAULT     0
#define BOX_SHOW_MODEL_REMOTE      1
#define BOX_SHOW_MODEL_TIMEOUT     2
#define BOX_SHOW_MODEL_NOTWORK     3
#define BOX_SHOW_MODEL_BROKENTHING 4

//加载界面的模式
enum{
	BOX_DETAIL_MAIN = 1,
	BOX_DETAIL_LOGIN = 2,
};

//boxdetail  显示方式
enum{
	BOX_DETAIL_DEFAULT = 1,
	BOX_DETAIL_REMOTE = 2,
};

//changepwd 文本框的类别
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
	DISCHECKED = 0,//红色X按钮
	SUPPLIESOK,//绿色对勾按钮，标志着扫描成功的物资
};

#define MIN_MOVE_DIS 50

#define CAR_NUM_LENGTH 10

//图片设置圆角的大小
#define PIC_RADIUS  10.0
//远程提料中 增加选择物资的按钮的大小
#define BUTTON_SIZE_WIDTH  130
#define BUTTON_SIZE_HEIGTH 40
#define BUTTON_MAX_SIZE 1000
#define BUTTON_RIGHT_LENGTH 200

//处理工具位置  01010302    "0101" 柜子号 "03"格子号  "02"位置编号
#define TOOLPICPOS_LOCKER_LENGTH 6 //柜子号+格子号
#define TOOLPICPOS_POSNUM_LENGTH 4 //格子号+位置编号
#define TOOLPICPOS_NODATA -2

//感应式智能柜 查询数据处理
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
/* 物资权限                                                              */
/************************************************************************/

#ifdef _TRAINRELATION_DEFINED

enum MtmSqlType
{
	MtmSqlInsert = 0,                                       // INSERT INTO 列表
	MtmSqlValues,                                           // VALUES() 列表
	MtmSqlUpdate,                                           // key = Values(key) 列表
};

/**
@brief MTM_PERMISSION_DEFAULT
@details 该权限为默认无权限，比权限为多一位。如果有 4 种权限, 则值为 0b10000

@brief MTM_PERMISSION_MAX
@brief 最大权限，，比权限为多一位。如果有 4 种权限，则值为 0b11111
*/
#define MTM_PERMISSION_DEFAULT (MtmPermission(1 << PermissionMax))      /**< 默认权限，无权限，高位为占位字节 */
#define MTM_PERMISSION_MAX (MtmPermission((2 << PermissionMax) - 1))    /**< 最大权限，高位为占位字节 */
#define MTM_TRANSFROMPERMISSION_DIFF1(_per) ((MtmPermissionType)(_per - 1))
#define MTM_TRANSFROMPERMISSION_DIFF2(_per) ((MtmPermissionType)(_per - 2))

#define MTM_SqlFieldStatus_DEFAULT (QString("0"))
#define MTM_SqlFieldTime_DEFAULT (QString("0000-00-00T00:00:00"))       /**< 数据库时间字段默认值 */

#endif // _TRAINRELATION_DEFINED

/************************************************************************/
/* 字符串宏                                                              */
/************************************************************************/

#define SQL_NULL ((QString)"NULL")                          /**< SQL空 */
#define STR_NULL ""                                         /**< 空字符串 */
#define MQTTTOPIC_DEFAULT "ZhiYunSmartLockersBroadcast"     /**< MQTT主题默认值 */

#define MTM_TIMEUNIT_MINUTE 60 /* 时间单位，分钟，60秒 */
typedef struct _initPara
{
	QString strUrl;
	int nEffectiveDiffTime; //领取时间范围 分钟
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

// 键值向量
const MtmSqlKey YunanKeys[] =
{
	MTMSQL_KEYDEF_("unique_id"),                            // 出退勤单号
	MTMSQL_KEYDEF_("driver_user_id"),                       // 司机工号
	MTMSQL_KEYDEF_("driver_user_name"),                     // 司机姓名
	MTMSQL_KEYDEF_("driver_attendance_status"),             // 司机出勤状态
	MTMSQL_KEYDEF_("practice_driver_user_id"),              // 学习司机工号
	MTMSQL_KEYDEF_("practice_driver_user_name"),            // 学习司机姓名
	MTMSQL_KEYDEF_("practice_attendance_status"),           // 学习司机出勤状态
	MTMSQL_KEYDEF_("student_user_id"),                      // 学员工号
	MTMSQL_KEYDEF_("student_user_name"),                    // 学员姓名
	MTMSQL_KEYDEF_("student_attendance_status"),            // 学员出勤状态
	MTMSQL_KEYDEF_("return_user_ids"),                      // 归还人ID列表
	MTMSQL_KEYDEF_("return_user_names"),                    // 归还人姓名列表
	MTMSQL_KEYDEF_("model_num"),                            // 车型
	MTMSQL_KEYDEF_("train_num"),                            // 车号
	MTMSQL_KEYDEF_("model_num_2"),                          // 车型2
	MTMSQL_KEYDEF_("train_num_2"),                          // 车号2
	MTMSQL_KEYDEF_("train_line"),                           // 线路
	MTMSQL_KEYDEF_("train_departure_time"),                 // 开车时间
	MTMSQL_KEYDEF_("planned_attendance_time"),              // 出勤时间
	MTMSQL_KEYDEF_("use_status"),                           // 物资领用权限
	MTMSQL_KEYDEF_("return_status"),                        // 物资归还状态
	MTMSQL_KEYDEF_("role_id"),                              // 角色
	MTMSQL_KEYDEF_("use_effective_time"),                   // 有效时间
	MTMSQL_KEYDEF_("supplies_status"),                      // 物资总状态
	MTMSQL_KEYDEF_("train_code"),
	MTMSQL_KEYDEF_("remark"),                               // 备注
	MTMSQL_KEYDEF_("create_time"),                          // 创建时间
	MTMSQL_KEYDEF_("modify_time")                           // 修改时间
};

// 键值下标
typedef enum
{
	KEY_UNIQUEID,                                           // 出退勤单号
	KEY_DRIVERID,                                           // 司机工号
	KEY_DRIVERNAME,                                         // 司机姓名
	KEY_DRIVERATTENDANCE,                                   // 司机出勤状态
	KEY_PRACTICEID,                                         // 学习司机工号
	KEY_PRACTICENAME,                                       // 学习司机姓名
	KEY_PRACTICEATTENDANCE,                                 // 学习司机出勤状态
	KEY_STUDENTID,                                          // 学员工号
	KEY_STUDENTNAME,                                        // 学员姓名
	KEY_STUDENTATTENDANCE,                                  // 学员出勤状态
	KEY_RETURNIDS,                                          // 归还人ID列表
	KEY_RETURNNAMES,                                        // 归还人姓名列表
	KEY_TRAINTYPE,                                          // 车型
	KEY_TRAINNO,                                            // 车号
	KEY_TRAINTYPE_2,                                        // 车型2
	KEY_TRAINNO_2,                                          // 车号2
	KEY_TRAINLINE,                                          // 线路
	KEY_DEPARTURETIME,                                      // 开车时间
	KEY_ATTENDANCETIME,                                     // 出勤时间
	KEY_SUPPERMISSION,                                      // 物资领用权限
	KEY_RETURNSTATUS,                                       // 物资归还状态
	KEY_ROLETYPE,                                           // 角色
	KEY_EFFECTIVETIME,                                      // 有效时间
	KEY_SUPPLIESSTATUS,                                     // 物资总状态
	KEY_TRAINCODE,
	KEY_REMARK,                                             // 备注
	KEY_CREATETIME,                                         // 创建时间
	KEY_MODIFYTIME,                                         // 修改时间

	KEY_COUNT,                                              // 键值总数
	KEY_MAX = KEY_COUNT,                                    // 键值上限
} YunanIdxKeyEnum;

#endif //_YUNANKEYS_DEFINED

#define PERMISSION_TEST(_sper, _idx) (0 != (_sper & (1 << _idx)))      /**< 测试权限 */
#define PERMISSION_BLOCK(_idx) (MTM_PERMISSION_MAX & ~(1 << _idx))     /**< 屏蔽权限 */
#define PERMISSION_GRANT(_idx) (MTM_PERMISSION_DEFAULT | (1 << _idx))  /**< 赋予权限 */
#define _PERMISSION_BLOCK(_sper, _idx) (_sper &= (~(1 << _idx)))       /**< 屏蔽权限 */
#define _PERMISSION_GRANT(_sper, _idx) (_sper |= (1 << _idx))          /**< 赋予权限 */


// 运安系统数据信息
struct MtmTrainRelationInfo
{
	// 人-车-线信息
	MtmUserID userID;                                       /**< 工号 */
	MtmUserName userName;                                   /**< 姓名 */
	MtmTrainType trainType;                                 /**< 车型 */
	MtmTrainNo trainNo;                                     /**< 车号 */
	MtmTrainType trainType2;                                /**< 车型2 */
	MtmTrainNo trainNo2;                                    /**< 车号2 */
	MtmTrainLine trainLine;                                 /**< 火车线路 */

	// 其他信息
	MtmPermission supPermission;                            /**< 物资权限控制 */
	MtmPermissionRoleType roleType;                         /**< 数据的角色类型 */
	int iDataSynFlag;
	MtmUniqueID uniqueId;

private:
	// 唯一            /**< 唯一编号 */
	MtmSqlValue m_values[YunanIdxKeyEnum::KEY_COUNT];
	QSet<YunanIdxKeyEnum> m_setAloneValueKey; // 单独属性的Key集合

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
		// 车-线信息
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

		// 其他信息
		uniqueId = "0";

		for (int i = 0; i < YunanIdxKeyEnum::KEY_COUNT; i++)
		{
			m_values[i].clear();
		}

		// 物资信息
		m_values[KEY_RETURNSTATUS] = MTM_SqlFieldStatus_DEFAULT;

		// 时间信息
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
			_PERMISSION_BLOCK(supPermission, permissionType); // 屏蔽权限
		else
			_PERMISSION_GRANT(supPermission, permissionType); // 赋予权限

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