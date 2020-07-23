/********************************************************************************
** Form generated from reading UI file 'ToolsWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLSWIDGET_H
#define UI_TOOLSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToolsWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_title;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_free;
    QLabel *label_free_text;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_full;
    QLabel *label_full_text;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_use;
    QLabel *label_use_text;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_broken;
    QLabel *label_broken_text;
    QSpacerItem *horizontalSpacer;
    QListWidget *listWidget;

    void setupUi(QWidget *ToolsWidget)
    {
        if (ToolsWidget->objectName().isEmpty())
            ToolsWidget->setObjectName(QStringLiteral("ToolsWidget"));
        ToolsWidget->resize(765, 777);
        ToolsWidget->setStyleSheet(QLatin1String("#listWidget{\n"
"background:transparent;\n"
"border:none;\n"
"}"));
        verticalLayout = new QVBoxLayout(ToolsWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_title = new QWidget(ToolsWidget);
        widget_title->setObjectName(QStringLiteral("widget_title"));
        widget_title->setMinimumSize(QSize(0, 30));
        widget_title->setStyleSheet(QLatin1String("#label_free{\n"
"border-image: url(:/SmartCabinet/img/green.png);\n"
"}\n"
"#label_full{\n"
"border-image: url(:/SmartCabinet/img/red.png);\n"
"}\n"
"#label_use{\n"
"border-image: url(:/SmartCabinet/img/yellow.png);\n"
"}\n"
"#label_broken{\n"
"border-image: url(:/SmartCabinet/img/gray.png);\n"
"}"));
        horizontalLayout_5 = new QHBoxLayout(widget_title);
        horizontalLayout_5->setSpacing(25);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(9, 5, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_free = new QLabel(widget_title);
        label_free->setObjectName(QStringLiteral("label_free"));
        label_free->setMinimumSize(QSize(30, 30));
        label_free->setMaximumSize(QSize(30, 30));

        horizontalLayout->addWidget(label_free);

        label_free_text = new QLabel(widget_title);
        label_free_text->setObjectName(QStringLiteral("label_free_text"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_free_text->setFont(font);

        horizontalLayout->addWidget(label_free_text);


        horizontalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_full = new QLabel(widget_title);
        label_full->setObjectName(QStringLiteral("label_full"));
        label_full->setMinimumSize(QSize(30, 30));
        label_full->setMaximumSize(QSize(30, 30));

        horizontalLayout_2->addWidget(label_full);

        label_full_text = new QLabel(widget_title);
        label_full_text->setObjectName(QStringLiteral("label_full_text"));
        label_full_text->setFont(font);

        horizontalLayout_2->addWidget(label_full_text);


        horizontalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(5);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_use = new QLabel(widget_title);
        label_use->setObjectName(QStringLiteral("label_use"));
        label_use->setMinimumSize(QSize(30, 30));
        label_use->setMaximumSize(QSize(30, 30));

        horizontalLayout_3->addWidget(label_use);

        label_use_text = new QLabel(widget_title);
        label_use_text->setObjectName(QStringLiteral("label_use_text"));
        label_use_text->setFont(font);

        horizontalLayout_3->addWidget(label_use_text);


        horizontalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(5);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_broken = new QLabel(widget_title);
        label_broken->setObjectName(QStringLiteral("label_broken"));
        label_broken->setMinimumSize(QSize(30, 30));
        label_broken->setMaximumSize(QSize(30, 30));

        horizontalLayout_4->addWidget(label_broken);

        label_broken_text = new QLabel(widget_title);
        label_broken_text->setObjectName(QStringLiteral("label_broken_text"));
        label_broken_text->setFont(font);

        horizontalLayout_4->addWidget(label_broken_text);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        horizontalSpacer = new QSpacerItem(377, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget_title);

        listWidget = new QListWidget(ToolsWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);


        retranslateUi(ToolsWidget);

        QMetaObject::connectSlotsByName(ToolsWidget);
    } // setupUi

    void retranslateUi(QWidget *ToolsWidget)
    {
        ToolsWidget->setWindowTitle(QApplication::translate("ToolsWidget", "ToolsWidget", 0));
        label_free->setText(QString());
        label_free_text->setText(QApplication::translate("ToolsWidget", "\347\251\272\351\227\262", 0));
        label_full->setText(QString());
        label_full_text->setText(QApplication::translate("ToolsWidget", "\345\215\240\346\273\241", 0));
        label_use->setText(QString());
        label_use_text->setText(QApplication::translate("ToolsWidget", "\345\215\240\347\224\250", 0));
        label_broken->setText(QString());
        label_broken_text->setText(QApplication::translate("ToolsWidget", "\346\215\237\345\235\217", 0));
    } // retranslateUi

};

namespace Ui {
    class ToolsWidget: public Ui_ToolsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLSWIDGET_H
