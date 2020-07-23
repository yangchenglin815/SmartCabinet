/********************************************************************************
** Form generated from reading UI file 'SuppliesIntactCheckDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPLIESINTACTCHECKDLG_H
#define UI_SUPPLIESINTACTCHECKDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SuppliesIntactCheckDlg
{
public:
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_suppliesIntactCheck;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_title;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_title;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnClose;
    QWidget *widget_supp;
    QVBoxLayout *verticalLayout;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelContent;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonNormal;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonMissing;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonBad;

    void setupUi(QDialog *SuppliesIntactCheckDlg)
    {
        if (SuppliesIntactCheckDlg->objectName().isEmpty())
            SuppliesIntactCheckDlg->setObjectName(QStringLiteral("SuppliesIntactCheckDlg"));
        SuppliesIntactCheckDlg->resize(920, 494);
        SuppliesIntactCheckDlg->setStyleSheet(QLatin1String("#widget_suppliesIntactCheck\n"
"{\n"
"border:2px solid rgb(30, 103, 136);\n"
"border-radius:0px;\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(SuppliesIntactCheckDlg);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_suppliesIntactCheck = new QWidget(SuppliesIntactCheckDlg);
        widget_suppliesIntactCheck->setObjectName(QStringLiteral("widget_suppliesIntactCheck"));
        widget_suppliesIntactCheck->setStyleSheet(QLatin1String("#widget_title{\n"
"background-color: rgba(92, 170, 230);\n"
"border-top-left-radius:10px;\n"
"border-top-right-radius:10px;\n"
"}\n"
"#widget_supp{\n"
"background-color:rgb(61,149,217);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(widget_suppliesIntactCheck);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(1, 1, 1, 1);
        widget_title = new QWidget(widget_suppliesIntactCheck);
        widget_title->setObjectName(QStringLiteral("widget_title"));
        widget_title->setMinimumSize(QSize(0, 50));
        widget_title->setMaximumSize(QSize(16777215, 50));
        widget_title->setStyleSheet(QString::fromUtf8("QPushButton#btnClose\n"
"{\n"
"image: url(:/SmartCabinet/img/close.png);\n"
"background-color: rgba(56, 155, 173,0);\n"
"min-height:50px;\n"
"min-width:50px;\n"
"max-height:50px;\n"
"max-width:50px;\n"
"border:none;\n"
"}\n"
"\n"
"QPushButton#btnClose:hover\n"
"{\n"
"image: url(:/SmartCabinet/img/close_hover.png);\n"
"border-radius:5px;\n"
"background-color: rgba(56, 155, 173,0);\n"
"border:none;\n"
"}\n"
"QPushButton#btnClose:pressed{\n"
"image: url(:SmartCabinet/img/close_down.png);\n"
"background-color: rgba(56, 155, 173,0);\n"
"border:none;\n"
"}\n"
"#label_title{\n"
"font: 75 28pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"min-height:50px;\n"
"background-color: rgba(92, 170, 230);\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(widget_title);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        label_title = new QLabel(widget_title);
        label_title->setObjectName(QStringLiteral("label_title"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(28);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        label_title->setFont(font);
        label_title->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(label_title);

        horizontalSpacer_3 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btnClose = new QPushButton(widget_title);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnClose->sizePolicy().hasHeightForWidth());
        btnClose->setSizePolicy(sizePolicy);
        btnClose->setMinimumSize(QSize(50, 50));
        btnClose->setMaximumSize(QSize(50, 50));
        QPalette palette;
        QBrush brush(QColor(56, 155, 173, 0));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        btnClose->setPalette(palette);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(12);
        font1.setKerning(true);
        btnClose->setFont(font1);
        btnClose->setAutoFillBackground(false);
        btnClose->setStyleSheet(QStringLiteral(""));
        btnClose->setText(QStringLiteral(""));
        btnClose->setAutoExclusive(false);
        btnClose->setAutoDefault(false);
        btnClose->setFlat(false);

        horizontalLayout_2->addWidget(btnClose);


        verticalLayout_2->addWidget(widget_title);

        widget_supp = new QWidget(widget_suppliesIntactCheck);
        widget_supp->setObjectName(QStringLiteral("widget_supp"));
        widget_supp->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border: 1px solid rgb(200, 200, 200);\n"
"background-color: rgb(18, 45, 177);\n"
"/*background-color: rgba(0, 0, 159,0.7);*/\n"
"border-radius:5px;\n"
"font: 24pt \"Microsoft YaHei\";\n"
"/*color: rgb(0, 0, 0);*/\n"
"color: rgb(255, 255, 255);\n"
"min-height:90px;\n"
"min-width:200px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"border-radius:5px;\n"
"/*background-color: rgba(0, 0, 159,0.7);*/\n"
"background-color: rgb(18, 45, 177);\n"
"\n"
"font: 24pt \"Microsoft YaHei\";\n"
"color: rgb(255, 255, 255);\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: rgb(43, 102, 150);\n"
"}\n"
"QPushButton:disabled{\n"
"background-color: rgb(173, 173, 173)\n"
"}"));
        verticalLayout = new QVBoxLayout(widget_supp);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(widget_supp);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        labelContent = new QLabel(widget_4);
        labelContent->setObjectName(QStringLiteral("labelContent"));
        QPalette palette1;
        QBrush brush1(QColor(24, 80, 134, 127));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        labelContent->setPalette(palette1);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(30);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        labelContent->setFont(font2);
        labelContent->setStyleSheet(QStringLiteral(""));
        labelContent->setAlignment(Qt::AlignCenter);
        labelContent->setWordWrap(true);

        horizontalLayout_3->addWidget(labelContent);


        verticalLayout->addWidget(widget_4);

        widget_2 = new QWidget(widget_supp);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(9, 0, 9, 10);
        pushButtonNormal = new QPushButton(widget_2);
        pushButtonNormal->setObjectName(QStringLiteral("pushButtonNormal"));
        pushButtonNormal->setMinimumSize(QSize(202, 92));
        QFont font3;
        font3.setFamily(QStringLiteral("Microsoft YaHei"));
        font3.setPointSize(24);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        pushButtonNormal->setFont(font3);
        pushButtonNormal->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(pushButtonNormal);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonMissing = new QPushButton(widget_2);
        pushButtonMissing->setObjectName(QStringLiteral("pushButtonMissing"));
        pushButtonMissing->setMinimumSize(QSize(202, 92));
        pushButtonMissing->setFont(font3);
        pushButtonMissing->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(pushButtonMissing);

        horizontalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButtonBad = new QPushButton(widget_2);
        pushButtonBad->setObjectName(QStringLiteral("pushButtonBad"));
        pushButtonBad->setMinimumSize(QSize(202, 92));
        pushButtonBad->setFont(font3);
        pushButtonBad->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(pushButtonBad);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 2);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 2);

        verticalLayout->addWidget(widget_2);


        verticalLayout_2->addWidget(widget_supp);


        horizontalLayout_4->addWidget(widget_suppliesIntactCheck);


        retranslateUi(SuppliesIntactCheckDlg);

        btnClose->setDefault(false);


        QMetaObject::connectSlotsByName(SuppliesIntactCheckDlg);
    } // setupUi

    void retranslateUi(QDialog *SuppliesIntactCheckDlg)
    {
        SuppliesIntactCheckDlg->setWindowTitle(QApplication::translate("SuppliesIntactCheckDlg", "SuppliesIntactCheckDlg", 0));
        label_title->setText(QApplication::translate("SuppliesIntactCheckDlg", "\347\211\251\350\265\204\345\256\214\346\225\264\346\200\247\347\241\256\350\256\244", 0));
        labelContent->setText(QApplication::translate("SuppliesIntactCheckDlg", "\350\257\267\347\241\256\350\256\244\345\267\245\345\205\267\346\230\257\345\220\246\345\256\214\346\225\264\357\274\237", 0));
        pushButtonNormal->setText(QApplication::translate("SuppliesIntactCheckDlg", "\347\211\251\350\265\204\346\255\243\345\270\270", 0));
        pushButtonMissing->setText(QApplication::translate("SuppliesIntactCheckDlg", "\351\203\250\345\210\206\347\274\272\345\244\261", 0));
        pushButtonBad->setText(QApplication::translate("SuppliesIntactCheckDlg", "\351\203\250\345\210\206\346\215\237\345\235\217", 0));
    } // retranslateUi

};

namespace Ui {
    class SuppliesIntactCheckDlg: public Ui_SuppliesIntactCheckDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPLIESINTACTCHECKDLG_H
