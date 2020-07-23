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
	//��ʼ��Dump
	EnableAutoDump();

	QApplication a(argc, argv);

	//��������
	QFont font;
	font.setFamily(QString::fromLocal8Bit("΢���ź�"));
	a.setFont(font);

	//���ñ����ʽ
	QTextCodec *codec = QTextCodec::codecForName("GB2312");
	QTextCodec::setCodecForLocale(codec);

	//��黷�������Ƿ����ȣ�
	AppEnvChecker envChecker;
	if (!envChecker.check()) {
		QString strTipHead = QString::fromLocal8Bit("��ʾ");
		QString strTip = QString::fromLocal8Bit("Ӧ�ó����Ѵ�");
		QMessageBox::critical(NULL, strTipHead, strTip, QMessageBox::Yes, QMessageBox::Yes);
		return -1;
	}

	//��ʼ��
	AppInitializer  initializer;
	initializer.init();
	LOG(INFO) << "App ����.";

	//�����¼�����
	AppEventListener* listener = new AppEventListener;
	a.installEventFilter(listener);

	SmartCabinet w;
	w.show();

	int ret = a.exec();
	LOG(INFO) << "App �˳�.";

	//����
	AppCleaner cleaner;
	cleaner.clean();

	return ret;
}
