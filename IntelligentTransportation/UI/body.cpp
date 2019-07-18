#include "body.h"

Body::Body(QWidget *parent) : QWidget(parent)
{
  initButtonGroup();
  initLabelsGroup();
  initLayout();
  jam_level_color[0] = "background-color:rgb(0, 255, 0)"; // 绿
  jam_level_color[1] = "background-color:rgb(255, 170, 0)"; // 橙
  jam_level_color[2] = "background-color:rgb(255, 0, 0)"; // 红
//  transparent[0] = "background-color:rgba(0, 255, 0,0.8)"; // 绿
//  transparent[1] = "background-color:rgba(255, 170, 0,0.8)"; // 橙
//  transparent[2] = "background-color:rgba(255, 0, 0,0.8)"; // 红
  memset(jam_level,0,sizeof(jam_level)); //构造函数中初始化每段路不拥堵

//  CarTimer *carTimer = new CarTimer;
//  carTimer->initAll();
//  connect(carTimer,SIGNAL(sendToWindowCarOnline(int,bool)),this,SLOT(receiveFromCarTimerSlot(int,bool)));


}

void Body::initButtonGroup()
{
    btnGroup=new QButtonGroup(this);
    for(int i=0;i<12;i++){
        QPushButton *btn=new QPushButton(QString::number(i+1),this);
        /*btn->set(true);//设置扁平化*/
        btn->setStyleSheet("background:transparent;"
                           "color:#FFFFFF;"
                           "font-weight:700;"
                           "font-style:bold");
        btn->setCursor(QCursor(Qt::PointingHandCursor));
        btnGroup->addButton(btn,i);
        connect(btn,SIGNAL(clicked()),this,SLOT(btnSlot()));
    }
}

void Body::initLayout()
{
    //水平布局
    h1=new QHBoxLayout;
    h1->addWidget(btnGroup->button(0));
    h1->addStretch();//加弹簧
    h1->addWidget(btnGroup->button(1));
    h1->addStretch();
    h1->addWidget(btnGroup->button(2));
    h1->addStretch();
    h1->addWidget(btnGroup->button(3));

    h2=new QHBoxLayout;
    h2->addWidget(btnGroup->button(4));
    h2->addStretch();//加弹簧
    h2->addWidget(btnGroup->button(5));
    h2->addStretch();
    h2->addWidget(btnGroup->button(6));
    h2->addStretch();
    h2->addWidget(btnGroup->button(7));


    h3=new QHBoxLayout;
    h3->addWidget(btnGroup->button(8));
    h3->addStretch();//加弹簧
    h3->addWidget(btnGroup->button(9));
    h3->addStretch();
    h3->addWidget(btnGroup->button(10));
    h3->addStretch();
    h3->addWidget(btnGroup->button(11));

    //垂直布局
    v1=new QVBoxLayout;
    v1->setMargin(0);
    v1->addLayout(h1);
    v1->addStretch();
    v1->addLayout(h2);
    v1->addStretch();
    v1->addLayout(h3);

    this->setLayout(v1);
}

void Body::initLabelsGroup()
{
    for(int i=0;i<ROAD_NUM;i++){
        labels[i]=new QLabel(this);
        labels[i]->setStyleSheet("background:transparent");
    }
}

int Body::resizeWidth(int rewidth)
{
    return width()*rewidth/805;
}

int Body::resizeHeight(int reheight)
{
    return height()*reheight/567;
}

void Body::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter p(this);
    QRect target(0,0,this->width(),this->height());
    p.drawImage(target,QImage(":/image/mymap.png"));
}

void Body::resizeEvent(QResizeEvent *event)
{
    for(int i=0;i<12;i++){
        btnGroup->button(i)->setFixedSize(width()/14,height()/11);
    }
    labels[0]->setGeometry(resizeWidth(61),0,resizeWidth(173),resizeHeight(22));
    labels[1]->setGeometry(resizeWidth(61),resizeHeight(25),resizeWidth(173),resizeHeight(22));
    labels[2]->setGeometry(resizeWidth(317),0,resizeWidth(173),resizeHeight(22));
    labels[3]->setGeometry(resizeWidth(317),resizeHeight(25),resizeWidth(173),resizeHeight(22));
    labels[4]->setGeometry(resizeWidth(573),0,resizeWidth(173),resizeHeight(22));
    labels[5]->setGeometry(resizeWidth(573),resizeHeight(25),resizeWidth(173),resizeHeight(22));

    labels[6]->setGeometry(0,resizeHeight(69),resizeWidth(20),resizeHeight(171));
    labels[7]->setGeometry(resizeWidth(21),resizeHeight(69),resizeWidth(19),resizeHeight(171));
    labels[8]->setGeometry(resizeWidth(256),resizeHeight(69),resizeWidth(18),resizeHeight(171));
    labels[9]->setGeometry(resizeWidth(276),resizeHeight(69),resizeWidth(18),resizeHeight(171));
    labels[10]->setGeometry(resizeWidth(764),resizeHeight(69),resizeWidth(20),resizeHeight(171));
    labels[11]->setGeometry(resizeWidth(785),resizeHeight(69),resizeWidth(20),resizeHeight(171));

    labels[12]->setGeometry(resizeWidth(61),resizeHeight(260),resizeWidth(173),resizeHeight(22));
    labels[13]->setGeometry(resizeWidth(61),resizeHeight(285),resizeWidth(173),resizeHeight(22));

    labels[14]->setGeometry(resizeWidth(317),resizeHeight(260),resizeWidth(173),resizeHeight(22));
    labels[15]->setGeometry(resizeWidth(317),resizeHeight(285),resizeWidth(173),resizeHeight(22));

    labels[16]->setGeometry(resizeWidth(573),resizeHeight(260),resizeWidth(173),resizeHeight(22));
    labels[17]->setGeometry(resizeWidth(573),resizeHeight(285),resizeWidth(173),resizeHeight(22));

    labels[18]->setGeometry(resizeWidth(0),resizeHeight(328),resizeWidth(20),resizeHeight(173));//已完成
    labels[19]->setGeometry(resizeWidth(21),resizeHeight(328),resizeWidth(20),resizeHeight(173));
    labels[20]->setGeometry(resizeWidth(256),resizeHeight(328),resizeWidth(18),resizeHeight(173));
    labels[21]->setGeometry(resizeWidth(275),resizeHeight(328),resizeWidth(18),resizeHeight(173));
    labels[22]->setGeometry(resizeWidth(509),resizeHeight(328),resizeWidth(18),resizeHeight(173));
    labels[23]->setGeometry(resizeWidth(529),resizeHeight(328),resizeWidth(19),resizeHeight(173));
    labels[24]->setGeometry(resizeWidth(764),resizeHeight(328),resizeWidth(20),resizeHeight(173));
    labels[25]->setGeometry(resizeWidth(785),resizeHeight(328),resizeWidth(20),resizeHeight(173));

    labels[26]->setGeometry(resizeWidth(61),resizeHeight(520),resizeWidth(173),resizeHeight(22));
    labels[27]->setGeometry(resizeWidth(61),resizeHeight(545),resizeWidth(173),resizeHeight(22));
    labels[28]->setGeometry(resizeWidth(317),resizeHeight(520),resizeWidth(173),resizeHeight(22));
    labels[29]->setGeometry(resizeWidth(317),resizeHeight(545),resizeWidth(173),resizeHeight(22));
    labels[30]->setGeometry(resizeWidth(573),resizeHeight(520),resizeWidth(173),resizeHeight(22));
    labels[31]->setGeometry(resizeWidth(573),resizeHeight(545),resizeWidth(173),resizeHeight(22));


}
//手动点击路口后获取路口标号
void Body::btnSlot()
{
    QString text = ((QPushButton*)sender())->text();
    int index=text.toInt()-1;
    vector.append(index);
    for(int i=0;i<vector.size();i++){
        QString str=QString::number(vector.at(i));
        qDebug()<<"手动点击按钮的标号"<<str;
    }
}
//手动 开始点击后,标记路线,清空路口vector
void Body::on_manualButton_clicked()
{
    for(int i=0;i<ROAD_NUM;i++){
        labels[i]->setStyleSheet("background-color:transparent");
    }

    for(int i=0;i<vector.size()-1;i++){
        int crossingIndex=vector.at(i);
        int crossingIndexNext=vector.at(i+1);
        int roadIndex=Route::getRoutePtr()->getNodeToEdge(crossingIndex,crossingIndexNext);
        qDebug()<<"标记路线"<<QString::number(roadIndex);
        labels[roadIndex]->setStyleSheet(jam_level_color[jam_level[roadIndex]]);
    }
    vector.clear();
}

//void Body::receiveFromCarTimerSlot(int car_number, bool flag)
//{
//    if(flag)
//        {
//            if(car_number == 1)
//                ui->label_11->setStyleSheet("background-color:green;");  //一号车在线
//            else if(car_number == 2)
//                ui->label_12->setStyleSheet("background-color:green;"); //二号车在线
//        }
//        else
//        {
//            if(car_number == 1)
//                ui->label_11->setStyleSheet("background-color:red;");   //一号车掉线
//            else if(car_number == 2)
//                ui->label_12->setStyleSheet("background-color:red;");   //二号车掉线
//        }

//}

//自动规划  开始
void Body::on_autoButton_clicked(int start,int end)
{
    for(int i=0;i<ROAD_NUM;i++){
        labels[i]->setStyleSheet("background-color:transparent");
    }
    qDebug()<<"自动规划信号抵达body";
    vector=Route::getRoutePtr()->minRouteJam(start,end,jam_level);
    for(int i=0;i<vector.size();i++){
        qDebug()<<"返回的路径"<<vector.at(i);
    }

    for(int i=0;i<vector.size()-1;i++){

        int crossingIndex=vector.at(i);
        int crossingIndexNext=vector.at(i+1);
        int roadIndex=Route::getRoutePtr()->getNodeToEdge(crossingIndex,crossingIndexNext);
        qDebug()<<"自动规划路口"<<vector.at(i)<<" "<<vector.at(i+1)<<"路线"<<roadIndex;
        labels[roadIndex]->setStyleSheet(jam_level_color[jam_level[roadIndex]]);
    }
    vector.clear();
}


//随机生成路况
void Body::on_roadConButton_clicked()
{
   qsrand((unsigned)time(NULL));
   for(int i = 0; i < ROAD_NUM; i++) {
       int r = (round(1.0 * rand() / RAND_MAX * (3 - 0) - 0.5));
       jam_level[i] = r; // 记录当前生成的所有路段的拥堵等级，供路径规划使用
       labels[i]->setStyleSheet(jam_level_color[r]);
   }
   emit roadCondition(jam_level,ROAD_NUM);
}


