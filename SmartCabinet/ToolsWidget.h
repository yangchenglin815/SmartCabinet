#pragma once

#include <QWidget>
#include "ui_ToolsWidget.h"

class ToolsWidget : public QWidget
{
	Q_OBJECT

public:
	ToolsWidget(QWidget *parent = Q_NULLPTR);
	~ToolsWidget();

private:
	Ui::ToolsWidget ui;
};
