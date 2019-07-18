#ifndef DATABASE_H
#define DATABASE_H
// 数据库操作类
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>  // 把MySQL报的错打印出来
#include <QDebug>
class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr);
    void initDatabase();

signals:

public slots:
private:
    // 数据库驱动对象指针
    // 数据库操作类一般封装为单例模式
    QSqlDatabase *db;
};

#endif // DATABASE_H
