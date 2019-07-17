/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QGraphicsView *graphicsView;
    QTabWidget *pathPlan;
    QWidget *widget;
    QPushButton *generate_jam_btn;
    QPushButton *auto_plan_btn;
    QCheckBox *avoid_jam_checkbox;
    QWidget *manuPlan;
    QPushButton *begin;
    QPushButton *finish;
    QPushButton *cancel;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QPushButton *crossing_1;
    QPushButton *crossing_2;
    QPushButton *crossing_3;
    QPushButton *crossing_4;
    QPushButton *crossing_5;
    QPushButton *crossing_6;
    QPushButton *crossing_7;
    QPushButton *crossing_8;
    QPushButton *crossing_9;
    QPushButton *crossing_10;
    QPushButton *crossing_11;
    QPushButton *crossing_12;
    QPushButton *start;
    QPushButton *pause;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1500, 720);
        graphicsView = new QGraphicsView(MainWindow);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1200, 720));
        graphicsView->setStyleSheet(QStringLiteral("border-image: url(:/image/mymap.png);"));
        pathPlan = new QTabWidget(MainWindow);
        pathPlan->setObjectName(QStringLiteral("pathPlan"));
        pathPlan->setGeometry(QRect(1220, 110, 271, 361));
        widget = new QWidget();
        widget->setObjectName(QStringLiteral("widget"));
        generate_jam_btn = new QPushButton(widget);
        generate_jam_btn->setObjectName(QStringLiteral("generate_jam_btn"));
        generate_jam_btn->setGeometry(QRect(140, 210, 111, 28));
        auto_plan_btn = new QPushButton(widget);
        auto_plan_btn->setObjectName(QStringLiteral("auto_plan_btn"));
        auto_plan_btn->setGeometry(QRect(10, 210, 93, 28));
        avoid_jam_checkbox = new QCheckBox(widget);
        avoid_jam_checkbox->setObjectName(QStringLiteral("avoid_jam_checkbox"));
        avoid_jam_checkbox->setGeometry(QRect(10, 290, 91, 19));
        pathPlan->addTab(widget, QString());
        manuPlan = new QWidget();
        manuPlan->setObjectName(QStringLiteral("manuPlan"));
        begin = new QPushButton(manuPlan);
        begin->setObjectName(QStringLiteral("begin"));
        begin->setGeometry(QRect(80, 10, 93, 28));
        finish = new QPushButton(manuPlan);
        finish->setObjectName(QStringLiteral("finish"));
        finish->setGeometry(QRect(80, 70, 93, 28));
        cancel = new QPushButton(manuPlan);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(80, 130, 93, 28));
        pathPlan->addTab(manuPlan, QString());
        label = new QLabel(MainWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(92, 10, 258, 20));
        label->setStyleSheet(QStringLiteral("background:transparent;"));
        label_2 = new QLabel(MainWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(92, 31, 258, 20));
        label_2->setStyleSheet(QStringLiteral("background:transparent;"));
        label_3 = new QLabel(MainWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(471, 10, 258, 20));
        label_3->setStyleSheet(QStringLiteral("background:transparent;"));
        label_4 = new QLabel(MainWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(471, 31, 258, 20));
        label_4->setStyleSheet(QStringLiteral("background:transparent;"));
        label_5 = new QLabel(MainWindow);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(851, 10, 258, 20));
        label_5->setStyleSheet(QStringLiteral("background:transparent;"));
        label_6 = new QLabel(MainWindow);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(851, 31, 258, 20));
        label_6->setStyleSheet(QStringLiteral("background:transparent;"));
        label_7 = new QLabel(MainWindow);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(9, 90, 20, 211));
        label_7->setStyleSheet(QStringLiteral("background:transparent;"));
        label_8 = new QLabel(MainWindow);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(31, 90, 20, 211));
        label_8->setStyleSheet(QStringLiteral("background:transparent;"));
        label_9 = new QLabel(MainWindow);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(389, 90, 20, 211));
        label_9->setStyleSheet(QStringLiteral("background:transparent;"));
        label_10 = new QLabel(MainWindow);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(411, 90, 20, 211));
        label_10->setStyleSheet(QStringLiteral("background:transparent;"));
        label_11 = new QLabel(MainWindow);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(1148, 90, 20, 211));
        label_11->setStyleSheet(QStringLiteral("background:transparent;"));
        label_12 = new QLabel(MainWindow);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(1170, 90, 20, 211));
        label_12->setStyleSheet(QStringLiteral("background:transparent;"));
        label_13 = new QLabel(MainWindow);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(92, 340, 258, 20));
        label_13->setStyleSheet(QStringLiteral("background:transparent;"));
        label_14 = new QLabel(MainWindow);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(92, 361, 258, 20));
        label_14->setStyleSheet(QStringLiteral("background:transparent;"));
        label_15 = new QLabel(MainWindow);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(471, 340, 258, 20));
        label_15->setStyleSheet(QStringLiteral("background:transparent;"));
        label_16 = new QLabel(MainWindow);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(471, 361, 258, 20));
        label_16->setStyleSheet(QStringLiteral("background:transparent;"));
        label_17 = new QLabel(MainWindow);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(851, 340, 258, 20));
        label_17->setStyleSheet(QStringLiteral("background:transparent;"));
        label_18 = new QLabel(MainWindow);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(851, 361, 258, 20));
        label_18->setStyleSheet(QStringLiteral("background:transparent;"));
        label_19 = new QLabel(MainWindow);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(9, 420, 20, 211));
        label_19->setStyleSheet(QStringLiteral("background:transparent;"));
        label_20 = new QLabel(MainWindow);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(31, 420, 20, 211));
        label_20->setStyleSheet(QStringLiteral("background:transparent;"));
        label_21 = new QLabel(MainWindow);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(388, 420, 20, 211));
        label_21->setStyleSheet(QStringLiteral("background:transparent;"));
        label_22 = new QLabel(MainWindow);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(410, 420, 20, 211));
        label_22->setStyleSheet(QStringLiteral("background:transparent;"));
        label_23 = new QLabel(MainWindow);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(766, 420, 20, 211));
        label_23->setStyleSheet(QStringLiteral("background:transparent;"));
        label_24 = new QLabel(MainWindow);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(788, 420, 20, 211));
        label_24->setStyleSheet(QStringLiteral("background:transparent;"));
        label_25 = new QLabel(MainWindow);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(1148, 420, 20, 211));
        label_25->setStyleSheet(QStringLiteral("background:transparent;"));
        label_26 = new QLabel(MainWindow);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(1170, 420, 20, 211));
        label_26->setStyleSheet(QStringLiteral("background:transparent;"));
        label_27 = new QLabel(MainWindow);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(92, 669, 258, 20));
        label_27->setStyleSheet(QStringLiteral("background:transparent;"));
        label_28 = new QLabel(MainWindow);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(92, 691, 258, 20));
        label_28->setStyleSheet(QStringLiteral("background:transparent;"));
        label_29 = new QLabel(MainWindow);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(471, 669, 258, 20));
        label_29->setStyleSheet(QStringLiteral("background:transparent;"));
        label_30 = new QLabel(MainWindow);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(471, 691, 258, 20));
        label_30->setStyleSheet(QStringLiteral("background:transparent;"));
        label_31 = new QLabel(MainWindow);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(851, 669, 258, 20));
        label_31->setStyleSheet(QStringLiteral("background:transparent;"));
        label_32 = new QLabel(MainWindow);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(850, 691, 258, 20));
        label_32->setStyleSheet(QStringLiteral("background:transparent;"));
        crossing_1 = new QPushButton(MainWindow);
        crossing_1->setObjectName(QStringLiteral("crossing_1"));
        crossing_1->setGeometry(QRect(0, 0, 62, 62));
        crossing_1->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));
        crossing_1->setFlat(true);
        crossing_2 = new QPushButton(MainWindow);
        crossing_2->setObjectName(QStringLiteral("crossing_2"));
        crossing_2->setGeometry(QRect(380, 0, 62, 62));
        crossing_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));
        crossing_2->setFlat(true);
        crossing_3 = new QPushButton(MainWindow);
        crossing_3->setObjectName(QStringLiteral("crossing_3"));
        crossing_3->setGeometry(QRect(760, 0, 62, 62));
        crossing_3->setAutoFillBackground(false);
        crossing_3->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));
        crossing_3->setFlat(true);
        crossing_4 = new QPushButton(MainWindow);
        crossing_4->setObjectName(QStringLiteral("crossing_4"));
        crossing_4->setGeometry(QRect(1140, 0, 62, 62));
        crossing_4->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));
        crossing_4->setFlat(true);
        crossing_5 = new QPushButton(MainWindow);
        crossing_5->setObjectName(QStringLiteral("crossing_5"));
        crossing_5->setGeometry(QRect(0, 330, 62, 62));
        crossing_5->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));
        crossing_5->setFlat(true);
        crossing_6 = new QPushButton(MainWindow);
        crossing_6->setObjectName(QStringLiteral("crossing_6"));
        crossing_6->setGeometry(QRect(380, 330, 62, 62));
        crossing_6->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));
        crossing_6->setFlat(true);
        crossing_7 = new QPushButton(MainWindow);
        crossing_7->setObjectName(QStringLiteral("crossing_7"));
        crossing_7->setGeometry(QRect(760, 330, 62, 62));
        crossing_7->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));
        crossing_7->setFlat(true);
        crossing_8 = new QPushButton(MainWindow);
        crossing_8->setObjectName(QStringLiteral("crossing_8"));
        crossing_8->setGeometry(QRect(1140, 330, 62, 62));
        crossing_8->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));
        crossing_8->setFlat(true);
        crossing_9 = new QPushButton(MainWindow);
        crossing_9->setObjectName(QStringLiteral("crossing_9"));
        crossing_9->setGeometry(QRect(0, 660, 62, 62));
        crossing_9->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));
        crossing_9->setFlat(true);
        crossing_10 = new QPushButton(MainWindow);
        crossing_10->setObjectName(QStringLiteral("crossing_10"));
        crossing_10->setGeometry(QRect(380, 660, 62, 62));
        crossing_10->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));
        crossing_10->setFlat(true);
        crossing_11 = new QPushButton(MainWindow);
        crossing_11->setObjectName(QStringLiteral("crossing_11"));
        crossing_11->setGeometry(QRect(760, 660, 62, 62));
        crossing_11->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));
        crossing_11->setFlat(true);
        crossing_12 = new QPushButton(MainWindow);
        crossing_12->setObjectName(QStringLiteral("crossing_12"));
        crossing_12->setGeometry(QRect(1140, 660, 62, 62));
        crossing_12->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));
        crossing_12->setFlat(true);
        start = new QPushButton(MainWindow);
        start->setObjectName(QStringLiteral("start"));
        start->setGeometry(QRect(1220, 500, 93, 28));
        pause = new QPushButton(MainWindow);
        pause->setObjectName(QStringLiteral("pause"));
        pause->setGeometry(QRect(1370, 500, 93, 28));

        retranslateUi(MainWindow);

        pathPlan->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Form", Q_NULLPTR));
        generate_jam_btn->setText(QApplication::translate("MainWindow", "\351\232\217\346\234\272\347\224\237\346\210\220\350\267\257\345\206\265", Q_NULLPTR));
        auto_plan_btn->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\350\247\204\345\210\222", Q_NULLPTR));
        avoid_jam_checkbox->setText(QApplication::translate("MainWindow", "\350\272\262\351\201\277\346\213\245\345\240\265 ", Q_NULLPTR));
        pathPlan->setTabText(pathPlan->indexOf(widget), QApplication::translate("MainWindow", "\350\207\252\345\212\250\350\247\204\345\210\222\350\267\257\345\276\204", Q_NULLPTR));
        begin->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", Q_NULLPTR));
        finish->setText(QApplication::translate("MainWindow", "\345\256\214\346\210\220", Q_NULLPTR));
        cancel->setText(QApplication::translate("MainWindow", "\345\217\226\346\266\210", Q_NULLPTR));
        pathPlan->setTabText(pathPlan->indexOf(manuPlan), QApplication::translate("MainWindow", "\346\211\213\345\212\250\350\247\204\345\210\222\350\267\257\345\276\204", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
        label_9->setText(QString());
        label_10->setText(QString());
        label_11->setText(QString());
        label_12->setText(QString());
        label_13->setText(QString());
        label_14->setText(QString());
        label_15->setText(QString());
        label_16->setText(QString());
        label_17->setText(QString());
        label_18->setText(QString());
        label_19->setText(QString());
        label_20->setText(QString());
        label_21->setText(QString());
        label_22->setText(QString());
        label_23->setText(QString());
        label_24->setText(QString());
        label_25->setText(QString());
        label_26->setText(QString());
        label_27->setText(QString());
        label_28->setText(QString());
        label_29->setText(QString());
        label_30->setText(QString());
        label_31->setText(QString());
        label_32->setText(QString());
        crossing_1->setText(QString());
        crossing_2->setText(QString());
        crossing_3->setText(QString());
        crossing_4->setText(QString());
        crossing_5->setText(QString());
        crossing_6->setText(QString());
        crossing_7->setText(QString());
        crossing_8->setText(QString());
        crossing_9->setText(QString());
        crossing_10->setText(QString());
        crossing_11->setText(QString());
        crossing_12->setText(QString());
        start->setText(QApplication::translate("MainWindow", "\345\207\272\345\217\221", Q_NULLPTR));
        pause->setText(QApplication::translate("MainWindow", "\346\232\202\345\201\234", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
