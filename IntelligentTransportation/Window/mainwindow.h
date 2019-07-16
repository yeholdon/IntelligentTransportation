#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QGraphicsOpacityEffect>
#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include <QVector>

const qint32 ROAD_NUM = 32;
const qint32 CROSSING_NUM = 12;
namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLabel *labels[ROAD_NUM];
    QPushButton *crossing[CROSSING_NUM]; // 路口按钮
    int jam_level[ROAD_NUM];
    QString jam_level_color[3];
    QGraphicsOpacityEffect *opacityEffect;

    QVector<QPushButton *> vec;// 存手动规划的点
public:
    void initJamLabelGroup();
    void initCrossingGroup();
    void routePlanningAvoidJam();
    void routePlanningShortestPath();
private slots:
    void on_avoid_jam_checkbox_stateChanged(int arg1);
    void on_begin_clicked();
    void crossing_clicked(bool b);// 路口按钮统一的槽函数

    void on_cancel_clicked();
    void on_finish_clicked();
};

#endif // MAINWINDOW_H
