#ifndef RIGHT_H
#define RIGHT_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QLabel>
#include <QPainter>
#include <QPaintEvent>
class Right : public QWidget
{
    Q_OBJECT
public:
    explicit Right(QWidget *parent = nullptr);
    int resizeWidth(int rewidth);
    int resizeHeight(int reheight);
    void initButton();
    void initLabel();

signals:
protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    QPushButton *start_Button;//手动生成路径开始运行按钮
    QPushButton *stop_Button; //停止按钮
    QPushButton *roadCon_Button;//路况按钮
    QLabel *remind_Label;  //手动生成路径提示标签
    QLabel *roadCon_Label0;//roadCon_Label0  1  2  路况标识标签
    QLabel *roadCon_Label1;
    QLabel *roadCon_Label2;


public slots:
};

#endif // RIGHT_H
