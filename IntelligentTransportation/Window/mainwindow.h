#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QGraphicsOpacityEffect>
#include <QLabel>
#include <QDebug>
const int ROAD_NUM = 32;

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
    int jam_level[ROAD_NUM];
    QString jam_level_color[3];
    QGraphicsOpacityEffect *opacityEffect;
public:
    void initJamLabelGroup();
    void routePlanningAvoidJam();
    void routePlanningShortestPath();
private slots:
    void on_pushButton_clicked(); // 随机生成拥堵按钮槽函数
    void on_pushButton_2_clicked(); // 自动规划路径槽函数
};

#endif // MAINWINDOW_H
