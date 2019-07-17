#ifndef DATABASE_H
#define DATABASE_H
/*数据库操作类*/
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class database : public QObject
{
    Q_OBJECT
public:
    explicit database(QObject *parent = nullptr);
    void initDatabase();
    void createTable(); //建表
    void insertData(QString name,QString sex);  //插入数据
    void selectData();
private:
    QSqlDatabase *db;
signals:

public slots:
};

#endif // DATABASE_H
