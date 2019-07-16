#include "database.h"

database::database(QObject *parent) : QObject(parent)
{
    db = new QSqlDatabase;
}

void database::initDatabase()
{
    // //连接SqlLite数据库
    //*db = QSqlDatabase::addDatabase("QSQLITE");

    //连接MySQL数据库
    //1.加载驱动
    *db = QSqlDatabase::addDatabase("QMYSQL");
    //2.设置 IP地址
    db->setHostName("127.0.0.1");
    //3.设置 端口
    db->setPort(3306);
    //4.设置用户名
    db->setUserName("root");
    //5.设置该用户名密码
    db->setPassword("");
    //6.选择数据库
    db->setDatabaseName("test");
    //7.设置连接选项
    //意外断线重连
    //db->setConnectOptions("MYSQL_OPT_CONNECT_TIMEOUT"); //这句报错
    //8.判断是否连接成功
    if(db->open())
    {
        qDebug()<<"数据库连接成功！";
    }
    else
    {
        qDebug()<<"数据库连接失败";

    }
}

void database::createTable()
{
    QString sql  = "create table person("
                  "id int(20) PRIMARY KEY AUTO_INCREMENT,"
                  "name varchar(20) not null,"
                  "sex varchar(20) not null)"
                   "charset = utf8;";
    QSqlQuery query;
    if(query.exec(sql))
    {
        qDebug()<<"建表成功！";
    }
    else
    {
        qDebug()<<"建表失败！"<<query.lastError();
    }

}

void database::insertData(QString name, QString sex)
{
    //创建含参数的sql语句
    QString sql = "insert into person(name,sex) "
                  "values('%1','%2');";
    sql = sql.arg(name).arg(sex);
    QSqlQuery query;
    if(query.exec(sql))
    {
        qDebug()<<"插入数据成功！";
    }
    else
    {
        qDebug()<<"插入数据失败！"<<query.lastError();
    }

}

void database::selectData()
{
    QString sql = "select * from person";
    QSqlQuery query;
    if(query.exec(sql))
    {
        while(query.next())
        {
            int id = query.value("id").toInt();
            QString name = query.value("name").toString();
            QString sex = query.value("sex").toString();
            qDebug()<<"person 表中的数据如下：";
            qDebug()<<id<<"  "<<name<<"  "<<sex;

        }
    }
    else
    {
        qDebug()<<"查询失败"<<query.lastError();
    }
}
