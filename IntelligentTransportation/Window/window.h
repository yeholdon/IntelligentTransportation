#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QGraphicsOpacityEffect> // 透明效果
#include <QPainter>

namespace Ui {
class Window;
}

class Window : public QWidget
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();

private slots:
    void on_tabWidget_tabBarClicked(int index);
    
    void on_pushButton_clicked();

private:
    Ui::Window *ui;

public:
    void initLabelGroup();
};

#endif // WINDOW_H
