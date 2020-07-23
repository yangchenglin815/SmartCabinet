#include "smartcabinet.h"
#include <QtWidgets/QApplication>
#include <QFont>
#include <QTextCodec>
#include <QMessageBox>

#include <windows.h>
#include "WindowsDump.h"
#include "AppEnvChecker.h"
#include "AppInitializer.h"
#include "GlogManager.h"
#include "AppCleaner.h"
#include "AppEventListener.h"

int main(int argc, char *argv[])
{
	//初始化Dump
	EnableAutoDump();

	QApplication a(argc, argv);

	//设置字体
	QFont font;
	font.setFamily(QString::fromLocal8Bit("微软雅黑"));
	a.setFont(font);

	//设置编码格式
	QTextCodec *codec = QTextCodec::codecForName("GB2312");
	QTextCodec::setCodecForLocale(codec);

	//检查环境（如是否单例等）
	AppEnvChecker envChecker;
	if (!envChecker.check()) {
		QString strTipHead = QString::fromLocal8Bit("提示");
		QString strTip = QString::fromLocal8Bit("应用程序已打开");
		QMessageBox::critical(NULL, strTipHead, strTip, QMessageBox::Yes, QMessageBox::Yes);
		return -1;
	}

	//初始化
	AppInitializer  initializer;
	initializer.init();
	LOG(INFO) << "App 启动.";

	//设置事件监听
	AppEventListener* listener = new AppEventListener;
	a.installEventFilter(listener);

	SmartCabinet w;
	w.show();

	int ret = a.exec();
	LOG(INFO) << "App 退出.";

	//清理
	AppCleaner cleaner;
	cleaner.clean();

	return ret;
}
