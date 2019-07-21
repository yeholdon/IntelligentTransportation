#ifndef RIGHT_H
#define RIGHT_H
#include <QDebug>
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
#include <QString>
#include <QButtonGroup>
#include <QMessageBox>
#include "Background/background.h"
class Right : public QWidget
{
    Q_OBJECT
public:
    explicit Right(QWidget *parent = nullptr);

signals:
    void curCarIdSignal(int car_id);
    void parkCarIdPosSignal(int car_id, int park_index);
    void parkOutCarIdSignal(int car_id, QString tar_pt_id);
protected:
    void resizeEvent(QResizeEvent *event);
public slots:
    void viewRouteSlot(const QString& routeString);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void carRadBtnSlot();
    void receiveCarOnlineSlot(int car_number, bool flag);
    void receiveLightColor(QString color);
    void changeStatus(bool status);
    void changeSound(bool status);
public:
    int resizeWidth(int rewidth);
    int resizeHeight(int reheight);
    void initStyle();
public:
    int cur_car_id; // 当前选择的小车编号，通过radiobutton槽函数设置
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
    QPushButton *stop_start;
public:
    QButtonGroup *car_rad_btn_group;

    QTabWidget *plan_mode_tab_widget;
    QWidget *manu_plan_widget;
    QCheckBox *avoid_jam_checkbox;
    QTextBrowser *path_view_text_brow;
    QPushButton *start_btn;
    QPushButton *complete_btn;
    QWidget *auto_plan_widget;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_18;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_19;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_20;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_21;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_22;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *horizontalLayout_23;
    QPushButton *begin_btn;
    QLabel *avoid_jam_label;
    QComboBox *avoid_jam_combo_box;
    QPushButton *select_st_pt_btn;
    QLabel *select_st_pt_label;
    QLabel *select_end_pt_label;
    QPushButton *select_end_pt_btn;
    QLabel *voice_label;
    QPushButton *voice_btn;
    QComboBox *set_direcion_combo_box;
    QLabel *set_direcion_label;
    QGroupBox *park_lot_tab_widget;
    QTabWidget *pathPlan_2;
    QWidget *park_in_widget;
    QCheckBox *avoid_jam_checkbox_4;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_13;
    QLabel *car_lot1_label;
    QComboBox *car_select_combo_box;
    QHBoxLayout *horizontalLayout_14;
    QLabel *park_pos1_label;
    QComboBox *pos_select_combo_box;
    QPushButton *pushButton;
    QWidget *park_out_widget;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_15;
    QLabel *car_lot2_label;
    QComboBox *car_select2_combo_box;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *state_view_group_box;
    QWidget *layoutWidget3;
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
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *flow_view_check_box;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLabel *cmd_label;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *car_rad_btn1;
    QRadioButton *car_rad_btn2;

    // 加一个入库的获取当前起点编号的lineEdit以及相应的label与layout
    QLineEdit *lineEditin;
    QLabel *labelin;
    QHBoxLayout *horizontalLayout_16;

    void setupUi(QWidget *Right)
    {
        if (Right->objectName().isEmpty())
            Right->setObjectName(QStringLiteral("Right"));
        Right->resize(369, 781);
        plan_mode_tab_widget = new QTabWidget(Right);
        plan_mode_tab_widget->setObjectName(QStringLiteral("plan_mode_tab_widget"));
        plan_mode_tab_widget->setGeometry(QRect(30, 230, 320, 301));
//        plan_mode_tab_widget->setGeometry(QRect(30, 230, 281, 301));
        manu_plan_widget = new QWidget();
        manu_plan_widget->setObjectName(QStringLiteral("manu_plan_widget"));
        avoid_jam_checkbox = new QCheckBox(manu_plan_widget);
        avoid_jam_checkbox->setObjectName(QStringLiteral("avoid_jam_checkbox"));
        avoid_jam_checkbox->setGeometry(QRect(10, 290, 91, 19));
        path_view_text_brow = new QTextBrowser(manu_plan_widget);
        path_view_text_brow->setObjectName(QStringLiteral("path_view_text_brow"));
        path_view_text_brow->setGeometry(QRect(11, 11, 256, 181));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        path_view_text_brow->setFont(font);
        start_btn = new QPushButton(manu_plan_widget);
        start_btn->setObjectName(QStringLiteral("start_btn"));
        start_btn->setGeometry(QRect(30, 206, 80, 31));
        complete_btn = new QPushButton(manu_plan_widget);
        complete_btn->setObjectName(QStringLiteral("complete_btn"));
        complete_btn->setGeometry(QRect(160, 206, 80, 31));
        plan_mode_tab_widget->addTab(manu_plan_widget, QString());
        auto_plan_widget = new QWidget();
        auto_plan_widget->setObjectName(QStringLiteral("auto_plan_widget"));
        horizontalLayoutWidget_2 = new QWidget(auto_plan_widget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 0, 271, 51));
        horizontalLayout_18 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        horizontalLayout_18->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_3 = new QWidget(auto_plan_widget);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(0, 50, 271, 51));
        horizontalLayout_19 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        horizontalLayout_19->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_4 = new QWidget(auto_plan_widget);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(0, 100, 271, 41));
        horizontalLayout_20 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        horizontalLayout_20->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_5 = new QWidget(auto_plan_widget);
        horizontalLayoutWidget_5->setObjectName(QStringLiteral("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(-1, 140, 271, 41));
        horizontalLayout_21 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        horizontalLayout_21->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_6 = new QWidget(auto_plan_widget);
        horizontalLayoutWidget_6->setObjectName(QStringLiteral("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(0, 180, 261, 41));
        horizontalLayout_22 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_7 = new QWidget(auto_plan_widget);
        horizontalLayoutWidget_7->setObjectName(QStringLiteral("horizontalLayoutWidget_7"));
        horizontalLayoutWidget_7->setGeometry(QRect(0, 220, 261, 31));
        horizontalLayout_23 = new QHBoxLayout(horizontalLayoutWidget_7);
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        horizontalLayout_23->setContentsMargins(0, 0, 0, 0);
        begin_btn = new QPushButton(auto_plan_widget);
        begin_btn->setObjectName(QStringLiteral("begin_btn"));
        begin_btn->setGeometry(QRect(80, 220, 111, 31));
        avoid_jam_label = new QLabel(auto_plan_widget);
        avoid_jam_label->setObjectName(QStringLiteral("avoid_jam_label"));
        avoid_jam_label->setGeometry(QRect(12, 190, 141, 20));
        avoid_jam_combo_box = new QComboBox(auto_plan_widget);
        avoid_jam_combo_box->setObjectName(QStringLiteral("avoid_jam_combo_box"));
        avoid_jam_combo_box->setGeometry(QRect(139, 190, 111, 22));
        select_st_pt_btn = new QPushButton(auto_plan_widget);
        select_st_pt_btn->setObjectName(QStringLiteral("select_st_pt_btn"));
        select_st_pt_btn->setGeometry(QRect(139, 10, 111, 31));
        select_st_pt_label = new QLabel(auto_plan_widget);
        select_st_pt_label->setObjectName(QStringLiteral("select_st_pt_label"));
        select_st_pt_label->setGeometry(QRect(12, 12, 141, 31));
        select_end_pt_label = new QLabel(auto_plan_widget);
        select_end_pt_label->setObjectName(QStringLiteral("select_end_pt_label"));
        select_end_pt_label->setGeometry(QRect(12, 63, 141, 31));
        select_end_pt_btn = new QPushButton(auto_plan_widget);
        select_end_pt_btn->setObjectName(QStringLiteral("select_end_pt_btn"));
        select_end_pt_btn->setGeometry(QRect(139, 60, 111, 31));
        voice_label = new QLabel(auto_plan_widget);
        voice_label->setObjectName(QStringLiteral("voice_label"));
        voice_label->setGeometry(QRect(12, 150, 141, 21));
        voice_btn = new QPushButton(auto_plan_widget);
        voice_btn->setObjectName(QStringLiteral("voice_btn"));
        //voice_btn->setGeometry(QRect(139, 144, 111, 31));
        voice_btn->setGeometry(QRect(170,138,45,45));
        set_direcion_combo_box = new QComboBox(auto_plan_widget);
        set_direcion_combo_box->setObjectName(QStringLiteral("set_direcion_combo_box"));
        set_direcion_combo_box->setGeometry(QRect(139, 110, 111, 22));
        set_direcion_label = new QLabel(auto_plan_widget);
        set_direcion_label->setObjectName(QStringLiteral("set_direcion_label"));
        set_direcion_label->setGeometry(QRect(12, 114, 141, 16));
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
        layoutWidget = new QWidget(park_in_widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 261, 111));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        car_lot1_label = new QLabel(layoutWidget);
        car_lot1_label->setObjectName(QStringLiteral("car_lot1_label"));

        horizontalLayout_13->addWidget(car_lot1_label);

        car_select_combo_box = new QComboBox(layoutWidget);
        car_select_combo_box->setObjectName(QStringLiteral("car_select_combo_box"));

        horizontalLayout_13->addWidget(car_select_combo_box);


        verticalLayout_5->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        park_pos1_label = new QLabel(layoutWidget);
        park_pos1_label->setObjectName(QStringLiteral("park_pos1_label"));

        horizontalLayout_14->addWidget(park_pos1_label);

        pos_select_combo_box = new QComboBox(layoutWidget);
        pos_select_combo_box->setObjectName(QStringLiteral("pos_select_combo_box"));

        horizontalLayout_14->addWidget(pos_select_combo_box);


        verticalLayout_5->addLayout(horizontalLayout_14);
        // ///////////////// 新加的入库输入起点按钮
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        labelin = new QLabel(layoutWidget);
        labelin->setObjectName(QStringLiteral("label"));

        horizontalLayout_16->addWidget(labelin);

        lineEditin = new QLineEdit(layoutWidget);
        lineEditin->setObjectName(QStringLiteral("lineEditin"));

        horizontalLayout_16->addWidget(lineEditin);
        verticalLayout_5->addLayout(horizontalLayout_16);
        // /////////////////

        pushButton = new QPushButton(park_in_widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(190, 110, 80, 31)); // 190, 100, 80, 31
        pathPlan_2->addTab(park_in_widget, QString());
        park_out_widget = new QWidget();
        park_out_widget->setObjectName(QStringLiteral("park_out_widget"));
        layoutWidget1 = new QWidget(park_out_widget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 23, 251, 41));
        horizontalLayout_15 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        car_lot2_label = new QLabel(layoutWidget1);
        car_lot2_label->setObjectName(QStringLiteral("car_lot2_label"));

        horizontalLayout_15->addWidget(car_lot2_label);

        car_select2_combo_box = new QComboBox(layoutWidget1);
        car_select2_combo_box->setObjectName(QStringLiteral("car_select2_combo_box"));

        horizontalLayout_15->addWidget(car_select2_combo_box);

        pushButton_2 = new QPushButton(park_out_widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(170, 100, 80, 31));
        label_2 = new QLabel(park_out_widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 70, 121, 31));
        lineEdit = new QLineEdit(park_out_widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(140, 69, 121, 21));
        pathPlan_2->addTab(park_out_widget, QString());
        layoutWidget2 = new QWidget(Right);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(30, 30, 311, 141));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        state_view_group_box = new QGroupBox(layoutWidget2);
        state_view_group_box->setObjectName(QStringLiteral("state_view_group_box"));
        layoutWidget3 = new QWidget(state_view_group_box);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(11, 22, 131, 91));
        verticalLayout = new QVBoxLayout(layoutWidget3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        car_label1 = new QLabel(layoutWidget3);
        car_label1->setObjectName(QStringLiteral("car_label1"));

        horizontalLayout->addWidget(car_label1);

        car_view_label1 = new QLabel(layoutWidget3);
        car_view_label1->setObjectName(QStringLiteral("car_view_label1"));

        horizontalLayout->addWidget(car_view_label1);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        car_label2 = new QLabel(layoutWidget3);
        car_label2->setObjectName(QStringLiteral("car_label2"));

        horizontalLayout_2->addWidget(car_label2);

        car_view_label2 = new QLabel(layoutWidget3);
        car_view_label2->setObjectName(QStringLiteral("car_view_label2"));

        horizontalLayout_2->addWidget(car_view_label2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        light_label = new QLabel(layoutWidget3);
        light_label->setObjectName(QStringLiteral("light_label"));

        horizontalLayout_3->addWidget(light_label);

        car_view_label3 = new QLabel(layoutWidget3);
        car_view_label3->setObjectName(QStringLiteral("car_view_label3"));

        horizontalLayout_3->addWidget(car_view_label3);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_5->addWidget(state_view_group_box);

        map_view_group_box = new QGroupBox(layoutWidget2);
        map_view_group_box->setObjectName(QStringLiteral("map_view_group_box"));
        layoutWidget4 = new QWidget(map_view_group_box);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 20, 194, 58));
        verticalLayout_2 = new QVBoxLayout(layoutWidget4);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        flow_view_check_box = new QCheckBox(layoutWidget4);
        flow_view_check_box->setObjectName(QStringLiteral("flow_view_check_box"));

        verticalLayout_2->addWidget(flow_view_check_box);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(layoutWidget4);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

        cmd_label = new QLabel(layoutWidget4);
        cmd_label->setObjectName(QStringLiteral("cmd_label"));

        horizontalLayout_4->addWidget(cmd_label);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout_5->addWidget(map_view_group_box);

        layoutWidget5 = new QWidget(Right);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(40, 190, 281, 21));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        car_rad_btn1 = new QRadioButton(layoutWidget5);
        car_rad_btn1->setObjectName(QStringLiteral("car_rad_btn1"));

        horizontalLayout_6->addWidget(car_rad_btn1);

        car_rad_btn2 = new QRadioButton(layoutWidget5);
        car_rad_btn2->setObjectName(QStringLiteral("car_rad_btn2"));

        horizontalLayout_6->addWidget(car_rad_btn2);


        retranslateUi(Right);

        plan_mode_tab_widget->setCurrentIndex(1);
        pathPlan_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Right);
    } // setupUi

    void retranslateUi(QWidget *Right)
    {
        Right->setWindowTitle(QApplication::translate("Right", "Form", Q_NULLPTR));
        avoid_jam_checkbox->setText(QApplication::translate("Right", "\350\272\262\351\201\277\346\213\245\345\240\265 ", Q_NULLPTR));
        path_view_text_brow->setHtml(QApplication::translate("Right", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun'; font-size:9pt;\"><br /></p></body></html>", Q_NULLPTR));
        start_btn->setText(QApplication::translate("Right", "\345\274\200\345\247\213\347\202\271\345\207\273", Q_NULLPTR));
        complete_btn->setText(QApplication::translate("Right", "\345\217\221\351\200\201", Q_NULLPTR));
        plan_mode_tab_widget->setTabText(plan_mode_tab_widget->indexOf(manu_plan_widget), QApplication::translate("Right", "\346\211\213\345\212\250\346\250\241\345\274\217", Q_NULLPTR));
        begin_btn->setText(QApplication::translate("Right", "\345\274\200\345\247\213", Q_NULLPTR));
        avoid_jam_label->setText(QApplication::translate("Right", "\350\272\262\351\201\277\346\213\245\345\240\265:", Q_NULLPTR));
        avoid_jam_combo_box->clear();
        avoid_jam_combo_box->insertItems(0, QStringList()
         << QApplication::translate("Right", "\345\274\200", Q_NULLPTR)
         << QApplication::translate("Right", "\345\205\263", Q_NULLPTR)
        );
        select_st_pt_btn->setText(QApplication::translate("Right", "\351\200\211\346\213\251", Q_NULLPTR));
        select_st_pt_label->setText(QApplication::translate("Right", "\351\200\211\346\213\251\350\265\267\347\202\271:", Q_NULLPTR));
        select_end_pt_label->setText(QApplication::translate("Right", "\351\200\211\346\213\251\347\273\210\347\202\271:", Q_NULLPTR));
        select_end_pt_btn->setText(QApplication::translate("Right", "\351\200\211\346\213\251", Q_NULLPTR));
        voice_label->setText(QApplication::translate("Right", "\350\257\255\351\237\263\346\222\255\346\212\245:", Q_NULLPTR));
        //voice_btn->setText(QApplication::translate("Right", "\351\200\211\346\213\251", Q_NULLPTR));
        voice_btn->setText(QString());
        set_direcion_combo_box->clear();
        set_direcion_combo_box->insertItems(0, QStringList()
         << QApplication::translate("Right", "\344\270\212", Q_NULLPTR)
         << QApplication::translate("Right", "\344\270\213", Q_NULLPTR)
         << QApplication::translate("Right", "\345\267\246", Q_NULLPTR)
         << QApplication::translate("Right", "\345\217\263", Q_NULLPTR)
        );
        set_direcion_label->setText(QApplication::translate("Right", "\350\256\276\345\256\232\346\226\271\345\220\221:", Q_NULLPTR));
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
        );
        pushButton->setText(QApplication::translate("Right", "\345\205\245\345\272\223", Q_NULLPTR));
        pathPlan_2->setTabText(pathPlan_2->indexOf(park_in_widget), QApplication::translate("Right", "\345\205\245\345\272\223", Q_NULLPTR));
        car_lot2_label->setText(QApplication::translate("Right", "\345\260\217\350\275\246", Q_NULLPTR));
        car_select2_combo_box->clear();
        car_select2_combo_box->insertItems(0, QStringList()
         << QApplication::translate("Right", "\345\260\217\350\275\2461", Q_NULLPTR)
         << QApplication::translate("Right", "\345\260\217\350\275\2462", Q_NULLPTR)
        );
        pushButton_2->setText(QApplication::translate("Right", "\345\207\272\345\272\223", Q_NULLPTR));
        label_2->setText(QApplication::translate("Right", "\347\273\210\347\202\271", Q_NULLPTR));
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
        label->setText(QApplication::translate("Right", "\346\232\202\345\201\234", Q_NULLPTR));
        cmd_label->setText(QApplication::translate("Right", "\345\220\257\345\212\250", Q_NULLPTR));
        car_rad_btn1->setText(QApplication::translate("Right", "\345\260\217\350\275\2461", Q_NULLPTR));
        car_rad_btn2->setText(QApplication::translate("Right", "\345\260\217\350\275\2462", Q_NULLPTR));

        labelin->setText(QApplication::translate("Right", "\350\265\267\347\202\271:", Q_NULLPTR));
    } // retranslateUi




};



#endif // RIGHT_H
