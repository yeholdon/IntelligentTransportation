#ifndef RIGHT_H
#define RIGHT_H

#include <QWidget>

namespace Ui {
class Right;
}

class Right : public QWidget
{
    Q_OBJECT

public:
    explicit Right(QWidget *parent = 0);
    ~Right();

private:
    Ui::Right *ui;
};

#endif // RIGHT_H
