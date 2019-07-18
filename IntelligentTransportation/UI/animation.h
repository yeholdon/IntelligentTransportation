#ifndef ANIMATION_H
#define ANIMATION_H

#include <QObject>

class Animation : public QObject
{
    Q_OBJECT
public:
    explicit Animation(QObject *parent = nullptr);

signals:

public slots:
};

#endif // ANIMATION_H