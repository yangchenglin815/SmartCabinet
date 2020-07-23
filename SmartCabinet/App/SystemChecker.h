#pragma once

#include <QString>
#include <tchar.h>

class SystemChecker
{
public:
	/*��ȡMAC��ַ*/
    static QString getCurrentMacAddr();

	/*�ж�App�����Ƿ����*/
    static bool isAppInstanceExisted();

	/*�ж������������Ƿ����*/
	static bool isLauncherInstanceExisted();

	/*�ж�����������*/
	static void shutdownLauncherInstance();

	/*��������������*/
	static bool restartLauncherInstance();
 
private:
	/*��ȡ����ID*/
    static bool getProcessIdByName(const wchar_t* szProcessname, unsigned long* lpPID);
};

