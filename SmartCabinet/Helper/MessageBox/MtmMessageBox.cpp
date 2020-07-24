#include "MtmMessageBox.h"
#include "Infobox.h"
#include "SystemInfoBox.h"
#include "globaldefine.h"

void MtmMessageBox::setInfoBoxMovePosAlignment(int PosXAlignment /*= 0*/, int PosYAlignment /*= 0*/)
{
	InfoBox::getBoxInstance()->setMovePosAlignment(PosXAlignment, PosYAlignment);
}

void MtmMessageBox::setInfoBoxMovePosition(int PositionX /*= 0*/, int PositionY /*= 0*/)
{
	InfoBox::getBoxInstance()->setMovePosition(PositionX, PositionY);
}

void MtmMessageBox::setConfirmBoxMovePosAlignment(int PosXAlignment /*= 0*/, int PosYAlignment /*= 0*/)
{
	SystemInfoBox::getBoxInstance()->setMovePosAlignment(PosXAlignment, PosYAlignment);
}

void MtmMessageBox::setConfirmBoxMovePosition(int PositionX /*= 0*/, int PositionY /*= 0*/)
{
	SystemInfoBox::getBoxInstance()->setMovePosition(PositionX, PositionY);
}

void MtmMessageBox::closeBox()
{
	InfoBox::closeBox();
}

void MtmMessageBox::InfoShowBox(QString msg, INFO_TYPE type /*= INFO_TYPE::MTMINFORMATION*/)
{
	InfoBox::getBoxInstance()->InfoShowBox(msg, type);
}

void MtmMessageBox::InfoShowTtsBox(QString msg, bool IsPurgeBeforeSpeak /*= true*/, INFO_TYPE type /*= INFO_TYPE::MTMINFORMATION*/)
{
	InfoBox::getBoxInstance()->InfoShowTtsBox(msg, IsPurgeBeforeSpeak, type);
}

bool MtmMessageBox::MtmInfoBox(const QString &title, const QString& text, INFO_TYPE type /*= INFO_TYPE::MTMINFORMATION*/, bool isAutoClickButtion /*= false*/, int timeoutSecond /*= 5*/, int buttonType /*= ConfirmButton*/)
{
	SystemInfoBox::setAutoClickButton(isAutoClickButtion, timeoutSecond, buttonType);

	return SystemInfoBox::showMessageBox(title, text, type);
}

void MtmMessageBox::setInfoBoxParent(QWidget* parent)
{
	if (NULL != parent)
		InfoBox::getBoxInstance()->setParent(parent, Qt::Window | Qt::FramelessWindowHint);
}

