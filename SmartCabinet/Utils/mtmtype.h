/**
   @file mtmtype.h
   @brief 类型头文件
   @details 包括自定义类型
   @author wnyl
   @version 1.0.10.190211
   @date 2019-02-11
   @see 
 */
#ifndef __MTM_TYPE_H__
#define __MTM_TYPE_H__

#include <memory>
#include <qobject.h>

/************************************************************************/
/* using 别名 模板类型                                                    */
/************************************************************************/

#ifndef _STDMTM_PTR_DEFINED
#define _STDMTM_PTR_DEFINED

template <typename T>
using mtm_stdptr = std::shared_ptr<T>;

#endif // !_STDMTM_PTR_DEFINED

#ifndef _MVECTOR_DEFINED
#define _MVECTOR_DEFINED

template<typename T>
using mtm_vector = std::vector<T>;

#endif // !_MVECTOR_DEFINED


#ifndef _MTMBLOCKSIGNALS_DEFINED
#define _MTMBLOCKSIGNALS_DEFINED

/**
@brief MtmBlockSignals                                   信号屏蔽模板类
*/
template <typename T>
class MtmBlockSignals
{
public:
	MtmBlockSignals(T* pType)
	{
		_InitSignals(pType);
	}
	~MtmBlockSignals()
	{
		ReleaseSignals();
	}

	/**
	@brief ReleaseSignals                                主动释放信号锁
	*/
	void ReleaseSignals()
	{
		if (NULL != _pTy)
		{
			_pTy->blockSignals(false);
			_pTy = NULL;
		}
	}

private:
	void _InitSignals(T* pType)
	{
		_pTy = pType;
		if (NULL != _pTy)
			_pTy->blockSignals(true);
	}

private:
	T* _pTy; // 对象指针
};


#endif // !_MTMBLOCKSIGNALS_DEFINED

/************************************************************************/
/* typedef 别名 实体类                                                   */
/************************************************************************/

/************************************************************************/
/* HRESULT 类型定义                                                      */
/************************************************************************/

#ifndef _HRESULT_DEFINED
#define _HRESULT_DEFINED

typedef long HRESULT;

#endif // !_HRESULT_DEFINED

/************************************************************************/
/*                                                                      */
/************************************************************************/

#ifndef _LONGLONG_DEFINED
#define _LONGLONG_DEFINED

typedef __int64 LONGLONG;
typedef unsigned long ULONG;

#endif // !_LONGLONG_DEFINED

/*******/
#ifndef _MTMVALUETYPE_DEFINED
#define _MTMVALUETYPE_DEFINED

typedef QString MtmStringValue;
typedef long MtmNumberValue;

#endif // !_MTMVALUETYPE_DEFINED

/************************************************************************/
/* 物资完整性                                                             */
/************************************************************************/

#ifndef _INTACTTYPE_DEFINED
#define _INTACTTYPE_DEFINED

typedef int IntactType;
enum RtnType
{
    RTN_ERR = -1,
    RTN_OK = 0,
};

#endif // !_INTACTTYPE_DEFINED


#ifndef _USERROLETYPE_DEFINED
#define _USERROLETYPE_DEFINED

/**
* @brief The UserRoleType enum 用户角色
*/
enum UserRoleType
{
	UserRoleDefault = -1,                                   /**< 无权限 */
	UserRoleUser = 0,                                       /**< 使用者（乘务员） */
	UserRoleAdmin,                                          /**< 管理者 */
	UserRoleSearcher,                                       /**< 搜索员（其他权限者） */
	UserRoleTempUser,                                       /**< 临时使用者（乘务员） */
};

#define CAST_ENUM_USERROLETYPE(_n) ((UserRoleType)_n)

#endif // !_USERROLETYPE_DEFINED


#ifndef _PERMISSIONROLETYPE_DEFINED
#define _PERMISSIONROLETYPE_DEFINED



/**
   @brief MtmAttendanceStatus                               出勤状态
 */
enum MtmAttendanceStatus
{
	MtmAttendanceNotSigned = 0,                             /**< 未签到 */
	MtmAttendanceNotApproved,                               /**< 未通过 */
	MtmAttendanceCheckIn,                                   /**< 签到通过 */
};

#define CAST_ENUM_MTMPERMISSIONROLETYPE(_n) ((MtmPermissionRoleType)_n)

#endif // !_PERMISSIONROLETYPE_DEFINED


#ifndef _TRAINRELATION_DEFINED
#define _TRAINRELATION_DEFINED

typedef QString MtmSqlValue;
typedef QString MtmUniqueID;                                /**< 唯一编号 */
typedef QString MtmUserID;                                  /**< 用户ID */
typedef QString MtmUserName;                                /**< 用户姓名 */
typedef QString MtmTrainType;                               /**< 机车型号 */
typedef QString MtmTrainNo;                                 /**< 机车编号 */
typedef QString MtmTrainLine;                               /**< 机车线路 */
typedef unsigned int MtmPermission;                         /**< 权限控制 */
typedef QString MtmSuppliesID;                              /**< 物资ID */
typedef QString MtmSqlFieldTime;                            /**< SQL时间字段 */
typedef QString MtmDescription;                             /**< 说明/备注 */

enum MtmPermissionType
{
	PermissionInterphone = 0,                               /**< 对讲机权限 */
	PermissionSamPhone,                                     /**< SAM机权限 */
	PermissionToolkit,                                      /**< 工具包权限 */
	PermissionKeyFirst,                                     /**< 钥匙 1 权限 */
	PermissionKeySecond,                                    /**< 钥匙 2 权限 */

	PermissionMax                                           /**< 最大权限（不能直接使用），禁止在下面添加 */
};

#endif // !_TRAINRELATION_DEFINED

/************************************************************************/
/* MsgType                                                              */
/************************************************************************/

enum MtmMessageListType
{
	MtmMessageListText = 0,
	MtmMessageListTopic,
};

#endif // !__MTM_TYPE_H__
