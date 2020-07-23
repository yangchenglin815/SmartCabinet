#include "AppEventListener.h"
#include <QCoreApplication>
#include <QLineEdit>
#include <QMouseEvent>
#include <QCursor>
#include <QTimer>
#include <QDesktopWidget>
#include <QApplication>
#include <Windows.h>

#include "UserConfig.h"
#include "SystemChecker.h"
#include "GlobalSignal.h"
#include "GlogManager.h"

AppEventListener::AppEventListener(QObject *parent)
	: QObject(parent)
{
   
}

AppEventListener::~AppEventListener()
{

}

bool AppEventListener::eventFilter(QObject *obj, QEvent *event)
{	
	Q_UNUSED(obj)
	if (event->type() == QEvent::MouseMove || event->type() == QEvent::MouseButtonPress) {
		GlobalSignal::instance()->onAppActivateOn();
	}
	else {
		//LOG(INFO) << "stop.";
	}

	return false;
}