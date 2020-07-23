/********************************************************************************
** Form generated from reading UI file 'LoginDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QGridLayout *gridLayout;
    QWidget *widget_main;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayoutTitle;
    QPushButton *btn_loginlogo;
    QLabel *labelTile;
    QHBoxLayout *horizontalLayoutSmartLockerInfo;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelLockersID_2;
    QLabel *labelLockersID;
    QSpacerItem *horizontalSpacer;
    QLabel *labelLockersModel_2;
    QLabel *labelLockersModel;
    QSpacerItem *horizontalSpacer_3;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QWidget *page_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelLoginMothed;
    QComboBox *cbxVerificationWays;
    QLabel *labelCompany;
    QLabel *labelVersion;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(400, 808);
        LoginDialog->setStyleSheet(QString::fromUtf8("#widget_main{\n"
"background-color: rgb(245, 245, 245);\n"
"}\n"
"QComboBox{\n"
"border: 1px solid rgb(200, 200, 200);\n"
"padding-left:30px;\n"
"background-color: rgb(18, 45, 177);\n"
"border-radius:5px;\n"
"font: 24pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"min-height:90px;\n"
"min-width:200px;\n"
"}\n"
"QComboBox:hover {\n"
"background-color: rgb(18, 45, 177);\n"
"border-radius:5px;\n"
"font: 24pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"}\n"
"QComboBox:pressed {\n"
"/*background-color: rgba(43, 102, 150,0.9);*/\n"
"}\n"
"QComboBox QAbstractItemView{\n"
"font: 24pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(181, 208, 214);\n"
"selection-color:rgb(186, 186, 186);\n"
"selection-background-color:rgba(56, 155, 173,0.9);\n"
"outline:0px;\n"
"min-height:100px;\n"
"border:1px solid  #339933;\n"
"margin: 0 0 0 0;\n"
"}\n"
"QComboBox QAbstractItemView::item {\n"
""
                        "font: 24pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"min-height:100px;\n"
"border:none;\n"
"}\n"
"QComboBox QAbstractItemView::item:hover {\n"
"font: 24pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(181, 208, 214);\n"
"min-height:100px;\n"
"border:none;\n"
"}\n"
"QToolTip\n"
"{\n"
"font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"}\n"
"QComboBox::drop-down {\n"
"image: url(:/SmartCabinet/img/downarrow.png);\n"
"width:30px;\n"
"subcontrol-origin: padding;\n"
"subcontrol-position: top right;\n"
"}\n"
"QLabel{\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        gridLayout = new QGridLayout(LoginDialog);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget_main = new QWidget(LoginDialog);
        widget_main->setObjectName(QStringLiteral("widget_main"));
        widget_main->setStyleSheet(QString::fromUtf8("#btn_loginlogo{\n"
"border-image: url(:/SmartCabinet/img/logo2_lu3D.png);\n"
"background-color: rgba(255, 255, 255,0);\n"
"min-height:80px;\n"
"min-width:160px;\n"
"}\n"
"#labelLockersID{\n"
"color:rgb(0,0,0);\n"
"font-family: \"Microsoft YaHei\";\n"
"font-size: 20px;\n"
"}\n"
"QComboBox#cbxVerificationWays {\n"
"background-color: rgb(44, 155, 201);\n"
"color: rgb(0, 0, 0);\n"
"}\n"
"QComboBox#cbxVerificationWays QListView::item::hover\n"
"{\n"
"background-color: rgba(44, 110, 201,0.7);\n"
"}\n"
"#labelLoginMothed{\n"
"font: 24pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:rgba(0, 0, 0,244);\n"
"min-height:70px;\n"
"}\n"
"#labelCompany{\n"
"color:rgb(102,102,102);\n"
"}\n"
"#labelVersion{\n"
"color:rgb(153,153,153);\n"
"}"));
        verticalLayout = new QVBoxLayout(widget_main);
        verticalLayout->setSpacing(20);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayoutTitle = new QVBoxLayout();
        verticalLayoutTitle->setSpacing(6);
        verticalLayoutTitle->setObjectName(QStringLiteral("verticalLayoutTitle"));
        verticalLayoutTitle->setContentsMargins(-1, 5, 9, -1);
        btn_loginlogo = new QPushButton(widget_main);
        btn_loginlogo->setObjectName(QStringLiteral("btn_loginlogo"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_loginlogo->sizePolicy().hasHeightForWidth());
        btn_loginlogo->setSizePolicy(sizePolicy);
        btn_loginlogo->setMinimumSize(QSize(160, 80));
        btn_loginlogo->setMaximumSize(QSize(160, 80));
        btn_loginlogo->setLayoutDirection(Qt::RightToLeft);
        btn_loginlogo->setStyleSheet(QStringLiteral(""));

        verticalLayoutTitle->addWidget(btn_loginlogo);

        labelTile = new QLabel(widget_main);
        labelTile->setObjectName(QStringLiteral("labelTile"));
        labelTile->setEnabled(true);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(24);
        labelTile->setFont(font);
        labelTile->setAlignment(Qt::AlignCenter);

        verticalLayoutTitle->addWidget(labelTile);

        verticalLayoutTitle->setStretch(1, 1);

        verticalLayout->addLayout(verticalLayoutTitle);

        horizontalLayoutSmartLockerInfo = new QHBoxLayout();
        horizontalLayoutSmartLockerInfo->setSpacing(0);
        horizontalLayoutSmartLockerInfo->setObjectName(QStringLiteral("horizontalLayoutSmartLockerInfo"));
        horizontalLayoutSmartLockerInfo->setContentsMargins(0, -1, 0, -1);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutSmartLockerInfo->addItem(horizontalSpacer_2);

        labelLockersID_2 = new QLabel(widget_main);
        labelLockersID_2->setObjectName(QStringLiteral("labelLockersID_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        labelLockersID_2->setFont(font1);
        labelLockersID_2->setAlignment(Qt::AlignCenter);
        labelLockersID_2->setMargin(-5);

        horizontalLayoutSmartLockerInfo->addWidget(labelLockersID_2);

        labelLockersID = new QLabel(widget_main);
        labelLockersID->setObjectName(QStringLiteral("labelLockersID"));
        QFont font2;
        font2.setFamily(QStringLiteral("Microsoft YaHei"));
        labelLockersID->setFont(font2);

        horizontalLayoutSmartLockerInfo->addWidget(labelLockersID);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutSmartLockerInfo->addItem(horizontalSpacer);

        labelLockersModel_2 = new QLabel(widget_main);
        labelLockersModel_2->setObjectName(QStringLiteral("labelLockersModel_2"));
        labelLockersModel_2->setFont(font1);
        labelLockersModel_2->setAlignment(Qt::AlignCenter);

        horizontalLayoutSmartLockerInfo->addWidget(labelLockersModel_2);

        labelLockersModel = new QLabel(widget_main);
        labelLockersModel->setObjectName(QStringLiteral("labelLockersModel"));
        labelLockersModel->setFont(font1);

        horizontalLayoutSmartLockerInfo->addWidget(labelLockersModel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutSmartLockerInfo->addItem(horizontalSpacer_3);

        horizontalLayoutSmartLockerInfo->setStretch(1, 4);
        horizontalLayoutSmartLockerInfo->setStretch(2, 1);
        horizontalLayoutSmartLockerInfo->setStretch(4, 4);
        horizontalLayoutSmartLockerInfo->setStretch(5, 1);

        verticalLayout->addLayout(horizontalLayoutSmartLockerInfo);

        stackedWidget = new QStackedWidget(widget_main);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        stackedWidget->addWidget(page_3);

        verticalLayout->addWidget(stackedWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, -1, 10, -1);
        labelLoginMothed = new QLabel(widget_main);
        labelLoginMothed->setObjectName(QStringLiteral("labelLoginMothed"));
        labelLoginMothed->setMinimumSize(QSize(0, 70));
        labelLoginMothed->setMaximumSize(QSize(16777215, 16777215));
        labelLoginMothed->setStyleSheet(QString::fromUtf8("font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        labelLoginMothed->setTextFormat(Qt::AutoText);
        labelLoginMothed->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labelLoginMothed);

        cbxVerificationWays = new QComboBox(widget_main);
        cbxVerificationWays->setObjectName(QStringLiteral("cbxVerificationWays"));
        cbxVerificationWays->setMinimumSize(QSize(232, 92));
        cbxVerificationWays->setLayoutDirection(Qt::LeftToRight);
        cbxVerificationWays->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(cbxVerificationWays);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 8);

        verticalLayout->addLayout(horizontalLayout_2);

        labelCompany = new QLabel(widget_main);
        labelCompany->setObjectName(QStringLiteral("labelCompany"));
        labelCompany->setLayoutDirection(Qt::LeftToRight);
        labelCompany->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelCompany);

        labelVersion = new QLabel(widget_main);
        labelVersion->setObjectName(QStringLiteral("labelVersion"));
        labelVersion->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelVersion);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 6);
        verticalLayout->setStretch(3, 2);

        gridLayout->addWidget(widget_main, 0, 0, 1, 1);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "LoginDialog", 0));
        btn_loginlogo->setText(QString());
        labelTile->setText(QApplication::translate("LoginDialog", "<html><head/><body><p><span style=\" font-weight:600;\">\346\231\272\344\272\221\345\276\256\345\272\223</span></p></body></html>", 0));
        labelLockersID_2->setText(QApplication::translate("LoginDialog", "<html><head/><body><p><span style=\" font-size:14pt;\">\346\231\272\350\203\275\346\237\234\347\274\226\345\217\267\357\274\232</span></p></body></html>", 0));
        labelLockersID->setText(QApplication::translate("LoginDialog", "TextLabel", 0));
        labelLockersModel_2->setText(QApplication::translate("LoginDialog", "<html><head/><body><p><span style=\" font-size:14pt;\">\346\231\272\350\203\275\346\237\234\345\220\215\347\247\260\357\274\232</span></p></body></html>", 0));
        labelLockersModel->setText(QApplication::translate("LoginDialog", "TextLabel", 0));
        labelLoginMothed->setText(QApplication::translate("LoginDialog", "\347\231\273\345\275\225\346\226\271\345\274\217", 0));
        cbxVerificationWays->setCurrentText(QString());
        labelCompany->setText(QApplication::translate("LoginDialog", "\350\245\277\345\256\211\351\255\224\347\233\276\347\224\265\346\260\224\345\267\245\347\250\213\350\207\252\345\212\250\345\214\226\347\240\224\347\251\266\346\211\200", 0));
        labelVersion->setText(QApplication::translate("LoginDialog", "Version", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
