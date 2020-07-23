#pragma once

#include <QString>
#include <tchar.h>

class SystemChecker
{
public:
	/*获取MAC地址*/
    static QString getCurrentMacAddr();

	/*判断App进程是否存在*/
    static bool isAppInstanceExisted();

	/*判断启动器进程是否存在*/
	static bool isLauncherInstanceExisted();

	/*中断启动器进程*/
	static void shutdownLauncherInstance();

	/*重启启动器进程*/
	static bool restartLauncherInstance();
 
private:
	/*获取进程ID*/
    static bool getProcessIdByName(const wchar_t* szProcessname, unsigned long* lpPID);
};

