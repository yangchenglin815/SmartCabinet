/********************************************************************************
** Form generated from reading UI file 'smartcabinet.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMARTCABINET_H
#define UI_SMARTCABINET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ToolsWidget.h"

QT_BEGIN_NAMESPACE

class Ui_SmartCabinetClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_top;
    QHBoxLayout *horizontalLayout;
    QLabel *label_logo;
    QLabel *label_title;
    QSpacerItem *horizontalSpacer;
    QLabel *label_yunan;
    QWidget *widget_info;
    QHBoxLayout *horizontalLayoutBaseInfo;
    QLabel *labelSpace;
    QLabel *labelSpace_2;
    QLabel *labelCarModel;
    QLabel *labelCarModelValue;
    QLabel *labelCarNum;
    QLabel *labelCarNumValue;
    QLabel *labelCarSegment;
    QLabel *labelCarSegmentValue;
    QLabel *labelSpace_3;
    QLabel *labelUserID;
    QLabel *labelUserIDValue;
    QLabel *labelUserRoleValue;
    QLabel *labelUserName;
    QLabel *labelUserNameValue;
    QLabel *labelUserRole;
    QLabel *labelUserRole_2;
    QComboBox *comboBoxUserRole;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_exit;
    QFrame *line_1;
    ToolsWidget *widget_main;
    QFrame *line_2;
    QWidget *widget_bottom;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_button;
    QWidget *widget_op;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_time;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *comboBox_lockType;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_logout;

    void setupUi(QMainWindow *SmartCabinetClass)
    {
        if (SmartCabinetClass->objectName().isEmpty())
            SmartCabinetClass->setObjectName(QStringLiteral("SmartCabinetClass"));
        SmartCabinetClass->resize(1597, 768);
        SmartCabinetClass->setStyleSheet(QLatin1String("#centralWidget{\n"
"background-color:rgb(61,149,217);\n"
"}"));
        centralWidget = new QWidget(SmartCabinetClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"border: 1px solid rgb(200, 200, 200);\n"
"padding-left:30px;\n"
"background-color: rgb(18, 45, 177);\n"
"border-radius:5px;\n"
"font: 24pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"min-height:90px;\n"
"min-width:200px;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"background-color: rgb(18, 45, 177);\n"
"border-radius:5px;\n"
"font: 24pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"}\n"
"QComboBox:pressed {\n"
"/*background-color: rgba(43, 102, 150,0.9);*/\n"
"}\n"
"\n"
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
"\n"
"QComboBox QAbstractItemView::item {\n"
"font: 24pt \"\345\276\256\350\275\257\351\233\205"
                        "\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"min-height:100px;\n"
"border:none;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item:hover {\n"
"font: 24pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(181, 208, 214);\n"
"min-height:100px;\n"
"border:none;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"image: url(:/SmartCabinet/img/downarrow.png);\n"
"width:30px;\n"
"subcontrol-origin: padding;\n"
"subcontrol-position: top right;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"border: 1px solid rgb(200, 200, 200);\n"
"background-color: rgb(18, 45, 177);\n"
"border-radius:5px;\n"
"font: 24pt \"Microsoft YaHei\";\n"
"color: rgb(255, 255, 255);\n"
"min-height:90px;\n"
"min-width:200px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"border-radius:5px;\n"
"background-color: rgb(18, 45, 177);\n"
"font: 24pt \"Microsoft YaHei\";\n"
"color: rgb(255, 255, 255);\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: rgb(43, 102, 150);\n"
"}\n"
"QPushButton:disabled{\n"
"background-color:"
                        " rgb(173, 173, 173)\n"
"}"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_top = new QWidget(centralWidget);
        widget_top->setObjectName(QStringLiteral("widget_top"));
        widget_top->setStyleSheet(QString::fromUtf8("#label_logo{\n"
"border-image: url(:/SmartCabinet/img/logo_32_32.png);\n"
"}\n"
"#pushButton_exit{\n"
"border-image: url(:/SmartCabinet/img/logo2_lu3D.png);\n"
"background-color: rgba(255, 255, 255,0);\n"
"}\n"
"#label_yunan{\n"
"font:16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"}"));
        horizontalLayout = new QHBoxLayout(widget_top);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 5, 0, 5);
        label_logo = new QLabel(widget_top);
        label_logo->setObjectName(QStringLiteral("label_logo"));
        label_logo->setMinimumSize(QSize(32, 32));
        label_logo->setMaximumSize(QSize(32, 32));

        horizontalLayout->addWidget(label_logo);

        label_title = new QLabel(widget_top);
        label_title->setObjectName(QStringLiteral("label_title"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(36);
        label_title->setFont(font);

        horizontalLayout->addWidget(label_title);

        horizontalSpacer = new QSpacerItem(262, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_yunan = new QLabel(widget_top);
        label_yunan->setObjectName(QStringLiteral("label_yunan"));

        horizontalLayout->addWidget(label_yunan);

        widget_info = new QWidget(widget_top);
        widget_info->setObjectName(QStringLiteral("widget_info"));
        widget_info->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font:16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"}\n"
"QComboBox{\n"
"min-height:70px;\n"
"min-width:220px;\n"
"}\n"
"QComboBox#comboBoxUserRole QListView::item::hover\n"
"{\n"
"background-color: rgba(44, 110, 201,0.7);\n"
"}\n"
""));
        horizontalLayoutBaseInfo = new QHBoxLayout(widget_info);
        horizontalLayoutBaseInfo->setSpacing(20);
        horizontalLayoutBaseInfo->setContentsMargins(11, 11, 11, 11);
        horizontalLayoutBaseInfo->setObjectName(QStringLiteral("horizontalLayoutBaseInfo"));
        horizontalLayoutBaseInfo->setContentsMargins(0, 0, 0, 0);
        labelSpace = new QLabel(widget_info);
        labelSpace->setObjectName(QStringLiteral("labelSpace"));

        horizontalLayoutBaseInfo->addWidget(labelSpace);

        labelSpace_2 = new QLabel(widget_info);
        labelSpace_2->setObjectName(QStringLiteral("labelSpace_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        labelSpace_2->setFont(font1);

        horizontalLayoutBaseInfo->addWidget(labelSpace_2);

        labelCarModel = new QLabel(widget_info);
        labelCarModel->setObjectName(QStringLiteral("labelCarModel"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(16);
        labelCarModel->setFont(font2);

        horizontalLayoutBaseInfo->addWidget(labelCarModel);

        labelCarModelValue = new QLabel(widget_info);
        labelCarModelValue->setObjectName(QStringLiteral("labelCarModelValue"));
        labelCarModelValue->setFont(font1);

        horizontalLayoutBaseInfo->addWidget(labelCarModelValue);

        labelCarNum = new QLabel(widget_info);
        labelCarNum->setObjectName(QStringLiteral("labelCarNum"));
        labelCarNum->setFont(font1);

        horizontalLayoutBaseInfo->addWidget(labelCarNum);

        labelCarNumValue = new QLabel(widget_info);
        labelCarNumValue->setObjectName(QStringLiteral("labelCarNumValue"));
        labelCarNumValue->setFont(font1);

        horizontalLayoutBaseInfo->addWidget(labelCarNumValue);

        labelCarSegment = new QLabel(widget_info);
        labelCarSegment->setObjectName(QStringLiteral("labelCarSegment"));
        labelCarSegment->setFont(font1);

        horizontalLayoutBaseInfo->addWidget(labelCarSegment);

        labelCarSegmentValue = new QLabel(widget_info);
        labelCarSegmentValue->setObjectName(QStringLiteral("labelCarSegmentValue"));
        labelCarSegmentValue->setFont(font1);

        horizontalLayoutBaseInfo->addWidget(labelCarSegmentValue);

        labelSpace_3 = new QLabel(widget_info);
        labelSpace_3->setObjectName(QStringLiteral("labelSpace_3"));
        labelSpace_3->setEnabled(true);
        labelSpace_3->setFont(font1);

        horizontalLayoutBaseInfo->addWidget(labelSpace_3);

        labelUserID = new QLabel(widget_info);
        labelUserID->setObjectName(QStringLiteral("labelUserID"));
        labelUserID->setFont(font1);

        horizontalLayoutBaseInfo->addWidget(labelUserID);

        labelUserIDValue = new QLabel(widget_info);
        labelUserIDValue->setObjectName(QStringLiteral("labelUserIDValue"));
        labelUserIDValue->setFont(font1);

        horizontalLayoutBaseInfo->addWidget(labelUserIDValue);

        labelUserRoleValue = new QLabel(widget_info);
        labelUserRoleValue->setObjectName(QStringLiteral("labelUserRoleValue"));
        labelUserRoleValue->setFont(font1);

        horizontalLayoutBaseInfo->addWidget(labelUserRoleValue);

        labelUserName = new QLabel(widget_info);
        labelUserName->setObjectName(QStringLiteral("labelUserName"));
        labelUserName->setFont(font1);

        horizontalLayoutBaseInfo->addWidget(labelUserName);

        labelUserNameValue = new QLabel(widget_info);
        labelUserNameValue->setObjectName(QStringLiteral("labelUserNameValue"));
        labelUserNameValue->setFont(font1);

        horizontalLayoutBaseInfo->addWidget(labelUserNameValue);

        labelUserRole = new QLabel(widget_info);
        labelUserRole->setObjectName(QStringLiteral("labelUserRole"));
        labelUserRole->setFont(font1);

        horizontalLayoutBaseInfo->addWidget(labelUserRole);

        labelUserRole_2 = new QLabel(widget_info);
        labelUserRole_2->setObjectName(QStringLiteral("labelUserRole_2"));
        labelUserRole_2->setFont(font1);

        horizontalLayoutBaseInfo->addWidget(labelUserRole_2);

        comboBoxUserRole = new QComboBox(widget_info);
        comboBoxUserRole->setObjectName(QStringLiteral("comboBoxUserRole"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBoxUserRole->sizePolicy().hasHeightForWidth());
        comboBoxUserRole->setSizePolicy(sizePolicy);
        comboBoxUserRole->setMinimumSize(QSize(252, 72));
        comboBoxUserRole->setMaximumSize(QSize(180, 70));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(24);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        comboBoxUserRole->setFont(font3);
        comboBoxUserRole->setStyleSheet(QStringLiteral(""));
        comboBoxUserRole->setInputMethodHints(Qt::ImhNone);

        horizontalLayoutBaseInfo->addWidget(comboBoxUserRole);

        horizontalLayoutBaseInfo->setStretch(0, 1);
        horizontalLayoutBaseInfo->setStretch(1, 1);
        horizontalLayoutBaseInfo->setStretch(2, 1);
        horizontalLayoutBaseInfo->setStretch(3, 1);
        horizontalLayoutBaseInfo->setStretch(4, 1);
        horizontalLayoutBaseInfo->setStretch(5, 1);
        horizontalLayoutBaseInfo->setStretch(6, 1);
        horizontalLayoutBaseInfo->setStretch(7, 1);
        horizontalLayoutBaseInfo->setStretch(8, 18);
        horizontalLayoutBaseInfo->setStretch(9, 2);
        horizontalLayoutBaseInfo->setStretch(10, 3);
        horizontalLayoutBaseInfo->setStretch(12, 1);
        horizontalLayoutBaseInfo->setStretch(13, 2);
        horizontalLayoutBaseInfo->setStretch(14, 1);
        horizontalLayoutBaseInfo->setStretch(16, 2);

        horizontalLayout->addWidget(widget_info);

        horizontalSpacer_2 = new QSpacerItem(261, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_exit = new QPushButton(widget_top);
        pushButton_exit->setObjectName(QStringLiteral("pushButton_exit"));
        pushButton_exit->setMinimumSize(QSize(202, 92));
        pushButton_exit->setMaximumSize(QSize(160, 80));

        horizontalLayout->addWidget(pushButton_exit);


        verticalLayout->addWidget(widget_top);

        line_1 = new QFrame(centralWidget);
        line_1->setObjectName(QStringLiteral("line_1"));
        line_1->setStyleSheet(QStringLiteral("background-color: rgba(16, 126, 211,0.6);"));
        line_1->setFrameShape(QFrame::HLine);
        line_1->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_1);

        widget_main = new ToolsWidget(centralWidget);
        widget_main->setObjectName(QStringLiteral("widget_main"));

        verticalLayout->addWidget(widget_main);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setStyleSheet(QStringLiteral("background-color: rgba(16, 126, 211,0.6);"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        widget_bottom = new QWidget(centralWidget);
        widget_bottom->setObjectName(QStringLiteral("widget_bottom"));
        horizontalLayout_3 = new QHBoxLayout(widget_bottom);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(10, 0, 10, 0);
        widget_button = new QWidget(widget_bottom);
        widget_button->setObjectName(QStringLiteral("widget_button"));

        horizontalLayout_3->addWidget(widget_button);

        widget_op = new QWidget(widget_bottom);
        widget_op->setObjectName(QStringLiteral("widget_op"));
        widget_op->setStyleSheet(QString::fromUtf8("#label_time{\n"
"font: 30pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"padding-left:20%;\n"
"}\n"
"QComboBox#comboBox_lockType QListView::item::hover\n"
"{\n"
"background-color: rgba(44, 110, 201,0.7);\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(widget_op);
        horizontalLayout_2->setSpacing(30);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(20, 0, 0, 0);
        label_time = new QLabel(widget_op);
        label_time->setObjectName(QStringLiteral("label_time"));

        horizontalLayout_2->addWidget(label_time);

        horizontalSpacer_3 = new QSpacerItem(539, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        comboBox_lockType = new QComboBox(widget_op);
        comboBox_lockType->setObjectName(QStringLiteral("comboBox_lockType"));
        comboBox_lockType->setMinimumSize(QSize(232, 92));

        horizontalLayout_2->addWidget(comboBox_lockType);

        horizontalSpacer_4 = new QSpacerItem(540, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        pushButton_logout = new QPushButton(widget_op);
        pushButton_logout->setObjectName(QStringLiteral("pushButton_logout"));
        pushButton_logout->setMinimumSize(QSize(202, 92));

        horizontalLayout_2->addWidget(pushButton_logout);


        horizontalLayout_3->addWidget(widget_op);


        verticalLayout->addWidget(widget_bottom);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(2, 7);
        verticalLayout->setStretch(3, 1);
        verticalLayout->setStretch(4, 1);
        SmartCabinetClass->setCentralWidget(centralWidget);

        retranslateUi(SmartCabinetClass);

        QMetaObject::connectSlotsByName(SmartCabinetClass);
    } // setupUi

    void retranslateUi(QMainWindow *SmartCabinetClass)
    {
        SmartCabinetClass->setWindowTitle(QApplication::translate("SmartCabinetClass", "SmartCabinet", 0));
        label_logo->setText(QString());
        label_title->setText(QApplication::translate("SmartCabinetClass", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:600;\">\346\231\272\344\272\221\345\276\256\345\272\223</span></p></body></html>", 0));
        label_yunan->setText(QApplication::translate("SmartCabinetClass", "\350\277\220\345\256\211\346\225\260\346\215\256\346\230\276\347\244\272", 0));
        labelSpace->setText(QString());
        labelSpace_2->setText(QString());
        labelCarModel->setText(QApplication::translate("SmartCabinetClass", "<html><head/><body><p><span style=\" font-size:14pt;\">\351\203\250\351\227\250\357\274\232</span></p></body></html>", 0));
        labelCarModelValue->setText(QApplication::translate("SmartCabinetClass", "<html><head/><body><p><span style=\" font-size:14pt;\">--</span></p></body></html>", 0));
        labelCarNum->setText(QApplication::translate("SmartCabinetClass", "<html><head/><body><p><span style=\" font-size:14pt;\">\350\201\214\345\212\241\357\274\232</span></p></body></html>", 0));
        labelCarNumValue->setText(QApplication::translate("SmartCabinetClass", "<html><head/><body><p>--</p></body></html>", 0));
        labelCarSegment->setText(QApplication::translate("SmartCabinetClass", "<html><head/><body><p><span style=\" font-size:14pt;\">\350\275\246\346\256\265\357\274\232</span></p></body></html>", 0));
        labelCarSegmentValue->setText(QApplication::translate("SmartCabinetClass", "<html><head/><body><p>--</p></body></html>", 0));
        labelSpace_3->setText(QString());
        labelUserID->setText(QApplication::translate("SmartCabinetClass", "<html><head/><body><p><span style=\" font-size:14pt;\">\347\224\250\346\210\267\347\274\226\345\217\267\357\274\232</span></p></body></html>", 0));
        labelUserIDValue->setText(QApplication::translate("SmartCabinetClass", "<html><head/><body><p><br/></p></body></html>", 0));
        labelUserRoleValue->setText(QApplication::translate("SmartCabinetClass", "<html><head/><body><p>--</p></body></html>", 0));
        labelUserName->setText(QApplication::translate("SmartCabinetClass", "<html><head/><body><p><span style=\" font-size:14pt;\">\345\247\223\345\220\215\357\274\232</span></p></body></html>", 0));
        labelUserNameValue->setText(QApplication::translate("SmartCabinetClass", "<html><head/><body><p>--</p></body></html>", 0));
        labelUserRole->setText(QApplication::translate("SmartCabinetClass", "<html><head/><body><p><span style=\" font-size:14pt;\">\350\247\222\350\211\262\357\274\232</span></p></body></html>", 0));
        labelUserRole_2->setText(QApplication::translate("SmartCabinetClass", "<html><head/><body><p>--</p></body></html>", 0));
        comboBoxUserRole->setCurrentText(QString());
        pushButton_exit->setText(QString());
        label_time->setText(QApplication::translate("SmartCabinetClass", "currTime", 0));
        pushButton_logout->setText(QApplication::translate("SmartCabinetClass", "\351\200\200\345\207\272\347\231\273\345\275\225", 0));
    } // retranslateUi

};

namespace Ui {
    class SmartCabinetClass: public Ui_SmartCabinetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMARTCABINET_H
