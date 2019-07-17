#ifndef TRANSFERPROTOCOL_H
#define TRANSFERPROTOCOL_H

#include <QObject>

class TransferProtocol : public QObject
{
    Q_OBJECT
public:
    explicit TransferProtocol(QObject *parent = nullptr);

signals:

public slots:
};

#endif // TRANSFERPROTOCOL_H