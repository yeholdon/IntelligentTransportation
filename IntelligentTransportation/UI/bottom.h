#ifndef BOTTOM_H
#define BOTTOM_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPainter>
#include <QLineEdit>
#include <QPushButton>
#include "Background/background.h"

class Bottom : public QWidget
{
    Q_OBJECT
public:
    explicit Bottom(QWidget *parent = nullptr);
    void initLabel();
    void inittext();
    void initButton();
    int resizeWidth(int rewidth);
    int resizeHeight(int reheight);

signals:

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

public slots:

private:
    QLabel *auto_Label;  //提示标签
    QLineEdit *start_text;//开始位置输入文本框
    QLineEdit *end_text;//停止位置输入文本框
    QPushButton *autostart_Button;//自动规划开始按钮

};

#endif // BUTTOM_H
