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
private:
    QGroupBox *state_view_group_box;
    QLabel *car_label1, *car_label2, *light_label;
    QLineEdit *car_edit1, *car_edit2, *light_edit;

    QGroupBox *map_view_group_box;
    QCheckBox *flow_view_check_box;
    QLabel *cmd_label;
    QPushButton *state_btn;

    QRadioButton *car_rad_btn1, *car_rad_btn2;
    QTabWidget *plan_mode_tab_widget;
    QTextBrowser *path_view;
    QPushButton *start_btn, *complete_btn;

    QTabWidget *park_lot;
    QLabel *car_lot1, *park_pos1;
    QComboBox *car_select, *pos_select;
    QPushButton *park_in_btn;

    QLabel *car_lot2;
    QComboBox *car_select2;

    QVBoxLayout *v_layout;
    QHBoxLayout *h_layout, *h_rad_btn;


};

#endif // RIGHT_H
