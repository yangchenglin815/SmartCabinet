/**
   @file mtmerror.h
   @brief 错误返回值头文件
   @details 包括错误返回值类型及值的定义
   @author wnyl
   @version 1.0.10.190227
   @date 2019-02-27
   @see 
 */
#ifndef __MTM_ERROR_H__
#define __MTM_ERROR_H__


/**
   @brief HRESULT                                          返回值类型
   @details 通过返回值定义错误类型
 */
#ifndef _HRESULT_DEFINED
#define _HRESULT_DEFINED

typedef long HRESULT;

#endif // !_HRESULT_DEFINED

/**
   @brief _HRESULT_TYPEDEF_                                 定义 HRESULT 的返回值
 */
#ifndef _HRESULT_TYPEDEF_
#define _HRESULT_TYPEDEF_(_sc) ((HRESULT)_sc)




/************************************************************************/
/* HRESULT GetDataSuccess 获取数据成功                                    */
/************************************************************************/

// 本地数据库获取数据成功
#define S_GETDATA_LOCAL                  _HRESULT_TYPEDEF_(0x00004001L)

// 服务器端获取数据成功
#define S_GETDATA_SERVER                 _HRESULT_TYPEDEF_(0x00004002L)

// WEB 服务获取数据成功
#define S_GETDATA_WEB                    _HRESULT_TYPEDEF_(0x00004003L)

// 其他途径获取数据成功
#define S_GETDATA_OTHER                  _HRESULT_TYPEDEF_(0x00004004L)

//
// MessageId: E_NOTIMPL
//
// MessageText:
//
// Not implemented
//
#define E_NOTIMPL                        _HRESULT_TYPEDEF_(0x80004001L)

//
// MessageId: E_INVALIDARG
//
// MessageText:
//
// One or more arguments are invalid
//
#define E_INVALIDARG                     _HRESULT_TYPEDEF_(0x80070057L)

//
// MessageId: E_FAIL
//
// MessageText:
//
// Unspecified error
//
#define E_FAIL                           _HRESULT_TYPEDEF_(0x80004005L)

//
// MessageId: E_POINTER
//
// MessageText:
//
// Invalid pointer
//
#define E_POINTER                        _HRESULT_TYPEDEF_(0x80004003L)

// Parse 失败
#define E_JSON_PARSE_FAILED              _HRESULT_TYPEDEF_(0x80008001L)

//
#define E_JSON_NO_RIGHT                  _HRESULT_TYPEDEF_(0x80008002L)

// 
#define E_JSON_NO_TASK                   _HRESULT_TYPEDEF_(0x80008003L)

// 
#define E_JSON_NO_INVENTORY              _HRESULT_TYPEDEF_(0x80008004L)

// 
#define E_JSON_RETURN_INTERANL           _HRESULT_TYPEDEF_(0x80008005L)

// SQL 连接错误
#define E_SQL_CONNECT_FAILED             _HRESULT_TYPEDEF_(0x80008101L)

// SQL 表被锁超时
#define E_SQL_LOCKED_TIMEOUT             _HRESULT_TYPEDEF_(0x80008102L)

// SQL 执行失败
#define E_SQL_EXCUITE_FAILED             _HRESULT_TYPEDEF_(0x80008103L)

#endif // !_HRESULT_TYPEDEF_


/************************************************************************/
/* 物资完整性                                                             */
/************************************************************************/

#ifndef _INTACTTYPE_DEFINED
#define _INTACTTYPE_DEFINED

typedef int IntactType;

#endif  // !_INTACTTYPE_DEFINED


#ifndef _INTACT_TYPEDEF_
#define _INTACT_TYPEDEF_(_n) ((IntactType)_n)

// 未知错误
#define INTACT_UNKNOWN                               _INTACT_TYPEDEF_(-1)

// 完整
#define INTACT_COMPLETE                              _INTACT_TYPEDEF_(0)

// 损坏
#define INTACT_DAMAGE                                _INTACT_TYPEDEF_(1)

// 缺失
#define INTACT_MISSING                               _INTACT_TYPEDEF_(2)

// 退出
#define INTACT_CLOSE                                 _INTACT_TYPEDEF_(0x1000)

#endif // !_INTACT_TYPEDEF_



#endif // !__MTM_ERROR_H__
