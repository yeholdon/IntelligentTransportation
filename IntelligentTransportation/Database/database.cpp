#include "database.h"

Database::Database(QObject *parent) : QObject(parent)
{
    db = new QSqlDatabase;
}

void Database::initDatabase()
{
    // 1.加载驱动,加载失败会自动抛异常
    *db = QSqlDatabase::addDatabase("QMYSQL");
    // 2. 设置IP地址
    db->setHostName("127.0.0.1");
    // 3. 设置端口
    db->setPort(3306);
    // 4. 设置用户名
    db->setUserName("root");
    // 5. 设置该用户名密码
    db->setPassword("625602");
    // 6. 设置用户
    db->setDatabaseName("test");
    // 7. 设置连接选项, 保持连接
    db->setConnectOptions("MYSQL_OPT_CONNECT_TIMEOUT");

    if(!db->open()) {
        qDebug() << "数据库连接失败：" << db->lastError();
    }
    else{
        qDebug() << "数据库连接成功";
    }

}
