#ifndef RIGHT_H
#define RIGHT_H

#include <QWidget>
#include <QComboBox>
#include <QTextBrowser>
#include <QTabWidget>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QRadioButton>
#include <QPushButton>
#include <QGroupBox>
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>

class Right : public QWidget
{
    Q_OBJECT
public:
    explicit Right(QWidget *parent = nullptr);

signals:
protected:
    void resizeEvent(QResizeEvent *event);
public slots:
public:
    int resizeWidth(int rewidth);
    int resizeHeight(int reheight);
public:
    /*
    QGroupBox *state_view_group_box;
    QLabel *car_label1, *car_label2, *light_label;
    QLineEdit *car_edit1, *car_edit2, *light_edit;

    QGroupBox *map_view_group_box;
    QCheckBox *flow_view_check_box;
    QLabel *cmd_label;
    QPushButton *state_btn;

    QRadioButton *car_rad_btn1, *car_rad_btn2;
    QTabWidget *plan_mode_tab_widget;
    QTextBrowser *path_view_text_brow;
    QPushButton *start_btn, *complete_btn;

    QTabWidget *park_lot_tab_widget;
    QLabel *car_lot1_label, *park_pos1_label;
    QComboBox *car_select_combo_box, *pos_select_combo_box;
    QPushButton *park_in_btn;

    QLabel *car_lot2_label;
    QComboBox *car_select2_combo_box;

    QVBoxLayout *v_layout;
    QHBoxLayout *h_layout, *h_rad_btn;
   */

    QTabWidget *plan_mode_tab_widget;
    QWidget *manu_plan_widget;
    QCheckBox *avoid_jam_checkbox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QTextBrowser *path_view_text_brow;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *start_btn;
    QPushButton *complete_btn;
    QWidget *auto_plan_widget;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *select_st_pt_label;
    QPushButton *select_st_pt_btn;
    QHBoxLayout *horizontalLayout_9;
    QLabel *select_end_pt_label;
    QPushButton *select_end_pt_btn;
    QHBoxLayout *horizontalLayout_10;
    QLabel *set_direcion_label;
    QComboBox *set_direcion_combo_box;
    QHBoxLayout *horizontalLayout_11;
    QLabel *voice_label;
    QPushButton *voice_btn;
    QHBoxLayout *horizontalLayout_12;
    QLabel *avoid_jam_label;
    QComboBox *avoid_jam_combo_box;
    QPushButton *begin_btn;
    QGroupBox *park_lot_tab_widget;
    QTabWidget *pathPlan_2;
    QWidget *park_in_widget;
    QCheckBox *avoid_jam_checkbox_4;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_13;
    QLabel *car_lot1_label;
    QComboBox *car_select_combo_box;
    QHBoxLayout *horizontalLayout_14;
    QLabel *park_pos1_label;
    QComboBox *pos_select_combo_box;
    QWidget *park_out_widget;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_15;
    QLabel *car_lot2_label;
    QComboBox *car_select2_combo_box;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *state_view_group_box;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *car_label1;
    QLabel *car_view_label1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *car_label2;
    QLabel *car_view_label2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *light_label;
    QLabel *car_view_label3;
    QGroupBox *map_view_group_box;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *flow_view_check_box;
    QHBoxLayout *horizontalLayout_4;
    QLabel *cmd_label;
    QPushButton *state_btn;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *car_rad_btn1;
    QRadioButton *car_rad_btn2;

    void setupUi(QWidget *Right)
    {
        if (Right->objectName().isEmpty())
            Right->setObjectName(QStringLiteral("Right"));
        Right->resize(369, 781);
        plan_mode_tab_widget = new QTabWidget(Right);
        plan_mode_tab_widget->setObjectName(QStringLiteral("plan_mode_tab_widget"));
        plan_mode_tab_widget->setGeometry(QRect(30, 230, 281, 301));
        manu_plan_widget = new QWidget();
        manu_plan_widget->setObjectName(QStringLiteral("manu_plan_widget"));
        avoid_jam_checkbox = new QCheckBox(manu_plan_widget);
        avoid_jam_checkbox->setObjectName(QStringLiteral("avoid_jam_checkbox"));
        avoid_jam_checkbox->setGeometry(QRect(10, 290, 91, 19));
        layoutWidget = new QWidget(manu_plan_widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 251, 241));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        path_view_text_brow = new QTextBrowser(layoutWidget);
        path_view_text_brow->setObjectName(QStringLiteral("path_view_text_brow"));

        verticalLayout_3->addWidget(path_view_text_brow);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        start_btn = new QPushButton(layoutWidget);
        start_btn->setObjectName(QStringLiteral("start_btn"));

        horizontalLayout_7->addWidget(start_btn);

        complete_btn = new QPushButton(layoutWidget);
        complete_btn->setObjectName(QStringLiteral("complete_btn"));

        horizontalLayout_7->addWidget(complete_btn);


        verticalLayout_3->addLayout(horizontalLayout_7);

        plan_mode_tab_widget->addTab(manu_plan_widget, QString());
        auto_plan_widget = new QWidget();
        auto_plan_widget->setObjectName(QStringLiteral("auto_plan_widget"));
        layoutWidget1 = new QWidget(auto_plan_widget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 251, 251));
        verticalLayout_4 = new QVBoxLayout(layoutWidget1);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        select_st_pt_label = new QLabel(layoutWidget1);
        select_st_pt_label->setObjectName(QStringLiteral("select_st_pt_label"));

        horizontalLayout_8->addWidget(select_st_pt_label);

        select_st_pt_btn = new QPushButton(layoutWidget1);
        select_st_pt_btn->setObjectName(QStringLiteral("select_st_pt_btn"));

        horizontalLayout_8->addWidget(select_st_pt_btn);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        select_end_pt_label = new QLabel(layoutWidget1);
        select_end_pt_label->setObjectName(QStringLiteral("select_end_pt_label"));

        horizontalLayout_9->addWidget(select_end_pt_label);

        select_end_pt_btn = new QPushButton(layoutWidget1);
        select_end_pt_btn->setObjectName(QStringLiteral("select_end_pt_btn"));

        horizontalLayout_9->addWidget(select_end_pt_btn);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        set_direcion_label = new QLabel(layoutWidget1);
        set_direcion_label->setObjectName(QStringLiteral("set_direcion_label"));

        horizontalLayout_10->addWidget(set_direcion_label);

        set_direcion_combo_box = new QComboBox(layoutWidget1);
        set_direcion_combo_box->setObjectName(QStringLiteral("set_direcion_combo_box"));

        horizontalLayout_10->addWidget(set_direcion_combo_box);


        verticalLayout_4->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        voice_label = new QLabel(layoutWidget1);
        voice_label->setObjectName(QStringLiteral("voice_label"));

        horizontalLayout_11->addWidget(voice_label);

        voice_btn = new QPushButton(layoutWidget1);
        voice_btn->setObjectName(QStringLiteral("voice_btn"));

        horizontalLayout_11->addWidget(voice_btn);


        verticalLayout_4->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        avoid_jam_label = new QLabel(layoutWidget1);
        avoid_jam_label->setObjectName(QStringLiteral("avoid_jam_label"));

        horizontalLayout_12->addWidget(avoid_jam_label);

        avoid_jam_combo_box = new QComboBox(layoutWidget1);
        avoid_jam_combo_box->setObjectName(QStringLiteral("avoid_jam_combo_box"));

        horizontalLayout_12->addWidget(avoid_jam_combo_box);


        verticalLayout_4->addLayout(horizontalLayout_12);

        begin_btn = new QPushButton(layoutWidget1);
        begin_btn->setObjectName(QStringLiteral("begin_btn"));

        verticalLayout_4->addWidget(begin_btn);

        plan_mode_tab_widget->addTab(auto_plan_widget, QString());
        park_lot_tab_widget = new QGroupBox(Right);
        park_lot_tab_widget->setObjectName(QStringLiteral("park_lot_tab_widget"));
        park_lot_tab_widget->setGeometry(QRect(30, 560, 281, 201));
        pathPlan_2 = new QTabWidget(park_lot_tab_widget);
        pathPlan_2->setObjectName(QStringLiteral("pathPlan_2"));
        pathPlan_2->setGeometry(QRect(0, 20, 281, 171));
        park_in_widget = new QWidget();
        park_in_widget->setObjectName(QStringLiteral("park_in_widget"));
        avoid_jam_checkbox_4 = new QCheckBox(park_in_widget);
        avoid_jam_checkbox_4->setObjectName(QStringLiteral("avoid_jam_checkbox_4"));
        avoid_jam_checkbox_4->setGeometry(QRect(10, 290, 91, 19));
        layoutWidget2 = new QWidget(park_in_widget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 20, 231, 111));
        verticalLayout_5 = new QVBoxLayout(layoutWidget2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        car_lot1_label = new QLabel(layoutWidget2);
        car_lot1_label->setObjectName(QStringLiteral("car_lot1_label"));

        horizontalLayout_13->addWidget(car_lot1_label);

        car_select_combo_box = new QComboBox(layoutWidget2);
        car_select_combo_box->setObjectName(QStringLiteral("car_select_combo_box"));

        horizontalLayout_13->addWidget(car_select_combo_box);


        verticalLayout_5->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        park_pos1_label = new QLabel(layoutWidget2);
        park_pos1_label->setObjectName(QStringLiteral("park_pos1_label"));

        horizontalLayout_14->addWidget(park_pos1_label);

        pos_select_combo_box = new QComboBox(layoutWidget2);
        pos_select_combo_box->setObjectName(QStringLiteral("pos_select_combo_box"));

        horizontalLayout_14->addWidget(pos_select_combo_box);


        verticalLayout_5->addLayout(horizontalLayout_14);

        pathPlan_2->addTab(park_in_widget, QString());
        park_out_widget = new QWidget();
        park_out_widget->setObjectName(QStringLiteral("park_out_widget"));
        layoutWidget3 = new QWidget(park_out_widget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 60, 251, 23));
        horizontalLayout_15 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        car_lot2_label = new QLabel(layoutWidget3);
        car_lot2_label->setObjectName(QStringLiteral("car_lot2_label"));

        horizontalLayout_15->addWidget(car_lot2_label);

        car_select2_combo_box = new QComboBox(layoutWidget3);
        car_select2_combo_box->setObjectName(QStringLiteral("car_select2_combo_box"));

        horizontalLayout_15->addWidget(car_select2_combo_box);

        pathPlan_2->addTab(park_out_widget, QString());
        layoutWidget4 = new QWidget(Right);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(30, 30, 311, 141));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        state_view_group_box = new QGroupBox(layoutWidget4);
        state_view_group_box->setObjectName(QStringLiteral("state_view_group_box"));
        widget = new QWidget(state_view_group_box);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(11, 22, 131, 91));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        car_label1 = new QLabel(widget);
        car_label1->setObjectName(QStringLiteral("car_label1"));

        horizontalLayout->addWidget(car_label1);

        car_view_label1 = new QLabel(widget);
        car_view_label1->setObjectName(QStringLiteral("car_view_label1"));

        horizontalLayout->addWidget(car_view_label1);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        car_label2 = new QLabel(widget);
        car_label2->setObjectName(QStringLiteral("car_label2"));

        horizontalLayout_2->addWidget(car_label2);

        car_view_label2 = new QLabel(widget);
        car_view_label2->setObjectName(QStringLiteral("car_view_label2"));

        horizontalLayout_2->addWidget(car_view_label2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        light_label = new QLabel(widget);
        light_label->setObjectName(QStringLiteral("light_label"));

        horizontalLayout_3->addWidget(light_label);

        car_view_label3 = new QLabel(widget);
        car_view_label3->setObjectName(QStringLiteral("car_view_label3"));

        horizontalLayout_3->addWidget(car_view_label3);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_5->addWidget(state_view_group_box);

        map_view_group_box = new QGroupBox(layoutWidget4);
        map_view_group_box->setObjectName(QStringLiteral("map_view_group_box"));
        layoutWidget5 = new QWidget(map_view_group_box);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(10, 20, 134, 58));
        verticalLayout_2 = new QVBoxLayout(layoutWidget5);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        flow_view_check_box = new QCheckBox(layoutWidget5);
        flow_view_check_box->setObjectName(QStringLiteral("flow_view_check_box"));

        verticalLayout_2->addWidget(flow_view_check_box);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        cmd_label = new QLabel(layoutWidget5);
        cmd_label->setObjectName(QStringLiteral("cmd_label"));

        horizontalLayout_4->addWidget(cmd_label);

        state_btn = new QPushButton(layoutWidget5);
        state_btn->setObjectName(QStringLiteral("state_btn"));

        horizontalLayout_4->addWidget(state_btn);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout_5->addWidget(map_view_group_box);

        layoutWidget6 = new QWidget(Right);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(40, 190, 281, 21));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        car_rad_btn1 = new QRadioButton(layoutWidget6);
        car_rad_btn1->setObjectName(QStringLiteral("car_rad_btn1"));

        horizontalLayout_6->addWidget(car_rad_btn1);

        car_rad_btn2 = new QRadioButton(layoutWidget6);
        car_rad_btn2->setObjectName(QStringLiteral("car_rad_btn2"));

        horizontalLayout_6->addWidget(car_rad_btn2);


        retranslateUi(Right);

        plan_mode_tab_widget->setCurrentIndex(0);
        pathPlan_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Right);
    } // setupUi

    void retranslateUi(QWidget *Right)
    {
        Right->setWindowTitle(QApplication::translate("Right", "Form", Q_NULLPTR));
        avoid_jam_checkbox->setText(QApplication::translate("Right", "\350\272\262\351\201\277\346\213\245\345\240\265 ", Q_NULLPTR));
        start_btn->setText(QApplication::translate("Right", "\345\274\200\345\247\213", Q_NULLPTR));
        complete_btn->setText(QApplication::translate("Right", "\345\217\221\351\200\201", Q_NULLPTR));
        plan_mode_tab_widget->setTabText(plan_mode_tab_widget->indexOf(manu_plan_widget), QApplication::translate("Right", "\346\211\213\345\212\250\346\250\241\345\274\217", Q_NULLPTR));
        select_st_pt_label->setText(QApplication::translate("Right", "\351\200\211\346\213\251\350\265\267\347\202\271:", Q_NULLPTR));
        select_st_pt_btn->setText(QApplication::translate("Right", "\351\200\211\346\213\251", Q_NULLPTR));
        select_end_pt_label->setText(QApplication::translate("Right", "\351\200\211\346\213\251\347\273\210\347\202\271:", Q_NULLPTR));
        select_end_pt_btn->setText(QApplication::translate("Right", "\351\200\211\346\213\251", Q_NULLPTR));
        set_direcion_label->setText(QApplication::translate("Right", "\350\256\276\345\256\232\346\226\271\345\220\221:", Q_NULLPTR));
        set_direcion_combo_box->clear();
        set_direcion_combo_box->insertItems(0, QStringList()
         << QApplication::translate("Right", "\344\270\212", Q_NULLPTR)
         << QApplication::translate("Right", "\344\270\213", Q_NULLPTR)
         << QApplication::translate("Right", "\345\267\246", Q_NULLPTR)
         << QApplication::translate("Right", "\345\217\263", Q_NULLPTR)
        );
        voice_label->setText(QApplication::translate("Right", "\350\257\255\351\237\263\346\222\255\346\212\245:", Q_NULLPTR));
        voice_btn->setText(QApplication::translate("Right", "\351\200\211\346\213\251", Q_NULLPTR));
        avoid_jam_label->setText(QApplication::translate("Right", "\350\272\262\351\201\277\346\213\245\345\240\265:", Q_NULLPTR));
        avoid_jam_combo_box->clear();
        avoid_jam_combo_box->insertItems(0, QStringList()
         << QApplication::translate("Right", "\345\274\200", Q_NULLPTR)
         << QApplication::translate("Right", "\345\205\263", Q_NULLPTR)
        );
        begin_btn->setText(QApplication::translate("Right", "\345\274\200\345\247\213", Q_NULLPTR));
        plan_mode_tab_widget->setTabText(plan_mode_tab_widget->indexOf(auto_plan_widget), QApplication::translate("Right", "\345\257\274\350\210\252\346\250\241\345\274\217", Q_NULLPTR));
        park_lot_tab_widget->setTitle(QApplication::translate("Right", "\345\201\234\350\275\246\345\234\272", Q_NULLPTR));
        avoid_jam_checkbox_4->setText(QApplication::translate("Right", "\350\272\262\351\201\277\346\213\245\345\240\265 ", Q_NULLPTR));
        car_lot1_label->setText(QApplication::translate("Right", "\345\260\217\350\275\246", Q_NULLPTR));
        car_select_combo_box->clear();
        car_select_combo_box->insertItems(0, QStringList()
         << QApplication::translate("Right", "\345\260\217\350\275\2461", Q_NULLPTR)
         << QApplication::translate("Right", "\345\260\217\350\275\2462", Q_NULLPTR)
        );
        car_select_combo_box->setCurrentText(QApplication::translate("Right", "\345\260\217\350\275\2461", Q_NULLPTR));
        park_pos1_label->setText(QApplication::translate("Right", "\345\201\234\350\275\246\344\275\215", Q_NULLPTR));
        pos_select_combo_box->clear();
        pos_select_combo_box->insertItems(0, QStringList()
         << QApplication::translate("Right", "\350\275\246\344\275\2151", Q_NULLPTR)
         << QApplication::translate("Right", "\350\275\246\344\275\2152", Q_NULLPTR)
         << QApplication::translate("Right", "\350\275\246\344\275\2153", Q_NULLPTR)
         << QApplication::translate("Right", "\350\275\246\344\275\2154", Q_NULLPTR)
        );
        pathPlan_2->setTabText(pathPlan_2->indexOf(park_in_widget), QApplication::translate("Right", "\345\205\245\345\272\223", Q_NULLPTR));
        car_lot2_label->setText(QApplication::translate("Right", "\345\260\217\350\275\246", Q_NULLPTR));
        car_select2_combo_box->clear();
        car_select2_combo_box->insertItems(0, QStringList()
         << QApplication::translate("Right", "\345\260\217\350\275\2461", Q_NULLPTR)
         << QApplication::translate("Right", "\345\260\217\350\275\2462", Q_NULLPTR)
        );
        pathPlan_2->setTabText(pathPlan_2->indexOf(park_out_widget), QApplication::translate("Right", "\345\207\272\345\272\223", Q_NULLPTR));
        state_view_group_box->setTitle(QApplication::translate("Right", "\347\212\266\346\200\201\346\230\276\347\244\272", Q_NULLPTR));
        car_label1->setText(QApplication::translate("Right", "\345\260\217\350\275\2461:", Q_NULLPTR));
        car_view_label1->setText(QApplication::translate("Right", "\347\246\273\347\272\277", Q_NULLPTR));
        car_label2->setText(QApplication::translate("Right", "\345\260\217\350\275\2462:", Q_NULLPTR));
        car_view_label2->setText(QApplication::translate("Right", "\347\246\273\347\272\277", Q_NULLPTR));
        light_label->setText(QApplication::translate("Right", "\344\272\244\351\200\232\347\201\257:", Q_NULLPTR));
        car_view_label3->setText(QApplication::translate("Right", "\347\272\242", Q_NULLPTR));
        map_view_group_box->setTitle(QApplication::translate("Right", "\345\234\260\345\233\276", Q_NULLPTR));
        flow_view_check_box->setText(QApplication::translate("Right", "\346\265\201\351\207\217\346\230\276\347\244\272", Q_NULLPTR));
        cmd_label->setText(QApplication::translate("Right", "\345\220\257\345\212\250", Q_NULLPTR));
        state_btn->setText(QApplication::translate("Right", "\346\232\202\345\201\234", Q_NULLPTR));
        car_rad_btn1->setText(QApplication::translate("Right", "\345\260\217\350\275\2461", Q_NULLPTR));
        car_rad_btn2->setText(QApplication::translate("Right", "\345\260\217\350\275\2462", Q_NULLPTR));
    } // retranslateUi



};

#endif // RIGHT_H
