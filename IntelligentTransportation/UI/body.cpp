#include "body.h"

Body::Body(QWidget *parent) : QWidget(parent)
{
    jam_level_color[0] = "background:#7B5FB0";//紫色
    //jam_level_color[1] = "background:rgb(255, 170, 0)"; // 橙
    jam_level_color[1] = "background:#EBC626"; // 橙
    jam_level_color[2] = "background-color:rgb(255, 0, 0)"; // 红
  //  routeString="";
    flag=false;
    once=false;
    initButtonGroup();
    initLayout();
    initLabelsGroup();
    initLantern();
    memset(jam_level,0,sizeof(jam_level)); //构造函数中初始化每段路不拥堵
    qDebug()<<"body构造完毕";

    //将主控的信号与动画的槽函数绑定
    connect(Background::getBgPtr(),SIGNAL(infoForAnimation(int, QVector<int>,QVector<int>,QVector<int>)),
            this,SLOT(startAnimation(int, QVector<int>,QVector<int>,QVector<int>)));
    carLabel = new MyLabel(this);
    //carLabel->setGeometry(0,height()/48,width()/20,height()/12);
    int height = 1120,width = 781;
    carLabel->setGeometry(width/24.5,height/22,width/20,height/12);

}

void Body::initButtonGroup()
{
    btnGroup=new QButtonGroup(this);
    for(int i=0;i<12;i++){
        QPushButton *btn=new QPushButton(QString::number(i+1),this);
        /*btn->set(true);//设置扁平化*/
        btn->setStyleSheet("QPushButton{background:transparent;"
                           "color:#FFFFFF;"
                           "font-weight:700;"
                           "font-style:bold}"
                           );/*"QPushButton:hover{border:2px solid #ebbccb;"}*/
        btn->setCursor(QCursor(Qt::PointingHandCursor));
        btn->setEnabled(false);
        btnGroup->addButton(btn,i);
        connect(btn,SIGNAL(clicked()),this,SLOT(btnSlot()));
    }
}

void Body::initLabelsGroup()
{
    for(int i=0;i<ROAD_NUM;i++){
        labels[i]=new QLabel(this);
        labels[i]->setStyleSheet("background:transparent");

    }
}


void Body::initLantern(){
    for(int i=0;i<LANTERN_UD;i++){
        lanternUD[i]=new QLabel(this);
        lanternUD[i]->setStyleSheet("background:#FF0000");
    }
    for(int i=0;i<LANTERN_LR;i++){
        lanternLR[i]=new QLabel(this);
        lanternLR[i]->setStyleSheet("background:#00FF00");
    }
}
void Body::initLayout()
{
    //水平布局
    h1=new QHBoxLayout;
    h1->addStretch(43);
    h1->addWidget(btnGroup->button(0));
    h1->addStretch(340);//加弹簧
    h1->addWidget(btnGroup->button(1));
    h1->addStretch(340);
    h1->addWidget(btnGroup->button(2));
    h1->addStretch(340);
    h1->addWidget(btnGroup->button(3));
    h1->addStretch(45);

    h2=new QHBoxLayout;
    h2->addStretch(43);
    h2->addWidget(btnGroup->button(4));
    h2->addStretch(340);//加弹簧
    h2->addWidget(btnGroup->button(5));
    h2->addStretch(340);
    h2->addWidget(btnGroup->button(6));
    h2->addStretch(340);
    h2->addWidget(btnGroup->button(7));
    h2->addStretch(45);


    h3=new QHBoxLayout;
    h3->addStretch(43);
    h3->addWidget(btnGroup->button(8));
    h3->addStretch(340);//加弹簧
    h3->addWidget(btnGroup->button(9));
    h3->addStretch(340);
    h3->addWidget(btnGroup->button(10));
    h3->addStretch(340);
    h3->addWidget(btnGroup->button(11));
    h3->addStretch(45);

    //垂直布局
    v1=new QVBoxLayout;
    v1->setMargin(0);
    v1->addStretch(60);
    v1->addLayout(h1);
    v1->addStretch(314);
    v1->addLayout(h2);
    v1->addStretch(314);
    v1->addLayout(h3);
    v1->addStretch(75);

    this->setLayout(v1);
}

void Body::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter p(this);
    //QRect target(resizeWidth(31),resizeHeight(43),resizeWidth(1120),resizeHeight(781));
    QRect target(resizeWidth(31),resizeHeight(43),resizeWidth(1053),resizeHeight(686));
    p.drawImage(target,QImage(":/image/mymap.png"));
    //调整小车
    carLabel->resize(width()/20,height()/12);
}

int Body::resizeWidth(int rewidth)
{
    return width()*rewidth/1120;
}

int Body::resizeHeight(int reheight)
{
    return height()*reheight/781;
}


void Body::resizeEvent(QResizeEvent *event)
{
    for(int i=0;i<12;i++){
        btnGroup->button(i)->setFixedSize(width()/14,height()/11);
    }

    labels[0]->setGeometry(resizeWidth(112),resizeHeight(43),resizeWidth(224),resizeHeight(29));
    labels[1]->setGeometry(resizeWidth(112),resizeHeight(74),resizeWidth(224),resizeHeight(29));
    labels[2]->setGeometry(resizeWidth(444),resizeHeight(43),resizeWidth(224),resizeHeight(29));
    labels[3]->setGeometry(resizeWidth(444),resizeHeight(74),resizeWidth(224),resizeHeight(29));
    labels[4]->setGeometry(resizeWidth(778),resizeHeight(43),resizeWidth(224),resizeHeight(29));
    labels[5]->setGeometry(resizeWidth(778),resizeHeight(74),resizeWidth(224),resizeHeight(29));

    labels[6]->setGeometry(resizeWidth(31),resizeHeight(126),resizeWidth(28),resizeHeight(204));
    labels[7]->setGeometry(resizeWidth(61),resizeHeight(126),resizeWidth(28),resizeHeight(204));
    labels[8]->setGeometry(resizeWidth(364),resizeHeight(126),resizeWidth(28),resizeHeight(204));
    labels[9]->setGeometry(resizeWidth(394),resizeHeight(126),resizeWidth(28),resizeHeight(204));
    labels[10]->setGeometry(resizeWidth(1028),resizeHeight(126),resizeWidth(29),resizeHeight(204));
    labels[11]->setGeometry(resizeWidth(1059),resizeHeight(126),resizeWidth(29),resizeHeight(204));

    labels[12]->setGeometry(resizeWidth(112),resizeHeight(358),resizeWidth(224),resizeHeight(29));
    labels[13]->setGeometry(resizeWidth(112),resizeHeight(389),resizeWidth(224),resizeHeight(29));
    labels[14]->setGeometry(resizeWidth(444),resizeHeight(358),resizeWidth(224),resizeHeight(29));
    labels[15]->setGeometry(resizeWidth(444),resizeHeight(389),resizeWidth(224),resizeHeight(29));
    labels[16]->setGeometry(resizeWidth(778),resizeHeight(358),resizeWidth(224),resizeHeight(29));
    labels[17]->setGeometry(resizeWidth(778),resizeHeight(389),resizeWidth(224),resizeHeight(29));

    labels[18]->setGeometry(resizeWidth(31),resizeHeight(440),resizeWidth(28),resizeHeight(204));//已完成
    labels[19]->setGeometry(resizeWidth(61),resizeHeight(440),resizeWidth(28),resizeHeight(204));
    labels[20]->setGeometry(resizeWidth(364),resizeHeight(440),resizeWidth(28),resizeHeight(204));
    labels[21]->setGeometry(resizeWidth(394),resizeHeight(440),resizeWidth(28),resizeHeight(204));
    labels[22]->setGeometry(resizeWidth(695),resizeHeight(440),resizeWidth(28),resizeHeight(204));
    labels[23]->setGeometry(resizeWidth(725),resizeHeight(440),resizeWidth(28),resizeHeight(204));
    labels[24]->setGeometry(resizeWidth(1028),resizeHeight(440),resizeWidth(29),resizeHeight(204));
    labels[25]->setGeometry(resizeWidth(1059),resizeHeight(440),resizeWidth(29),resizeHeight(204));

    labels[26]->setGeometry(resizeWidth(112),resizeHeight(668),resizeWidth(224),resizeHeight(29));
    labels[27]->setGeometry(resizeWidth(112),resizeHeight(699),resizeWidth(224),resizeHeight(29));
    labels[28]->setGeometry(resizeWidth(444),resizeHeight(668),resizeWidth(224),resizeHeight(29));
    labels[29]->setGeometry(resizeWidth(444),resizeHeight(699),resizeWidth(224),resizeHeight(29));
    labels[30]->setGeometry(resizeWidth(778),resizeHeight(668),resizeWidth(224),resizeHeight(29));
    labels[31]->setGeometry(resizeWidth(778),resizeHeight(699),resizeWidth(224),resizeHeight(29));


    lanternLR[0]->setGeometry(resizeWidth(365),resizeHeight(45),resizeWidth(5),resizeHeight(50));
    lanternLR[1]->setGeometry(resizeWidth(413),resizeHeight(45),resizeWidth(5),resizeHeight(50));
    lanternLR[2]->setGeometry(resizeWidth(697),resizeHeight(45),resizeWidth(5),resizeHeight(50));
    lanternLR[3]->setGeometry(resizeWidth(746),resizeHeight(45),resizeWidth(5),resizeHeight(50));
    lanternLR[4]->setGeometry(resizeWidth(79),resizeHeight(361),resizeWidth(5),resizeHeight(50));
    lanternLR[5]->setGeometry(resizeWidth(365),resizeHeight(361),resizeWidth(5),resizeHeight(50));
    lanternLR[6]->setGeometry(resizeWidth(413),resizeHeight(361),resizeWidth(5),resizeHeight(50));
    lanternLR[7]->setGeometry(resizeWidth(697),resizeHeight(361),resizeWidth(5),resizeHeight(50));
    lanternLR[8]->setGeometry(resizeWidth(746),resizeHeight(361),resizeWidth(5),resizeHeight(50));
    lanternLR[9]->setGeometry(resizeWidth(1030),resizeHeight(361),resizeWidth(5),resizeHeight(50));

    lanternLR[10]->setGeometry(resizeWidth(365),resizeHeight(675),resizeWidth(5),resizeHeight(50));
    lanternLR[11]->setGeometry(resizeWidth(413),resizeHeight(675),resizeWidth(5),resizeHeight(50));
    lanternLR[12]->setGeometry(resizeWidth(697),resizeHeight(675),resizeWidth(5),resizeHeight(50));
    lanternLR[13]->setGeometry(resizeWidth(746),resizeHeight(675),resizeWidth(5),resizeHeight(50));

    lanternLR[14]->setGeometry(resizeWidth(83),resizeHeight(45),resizeWidth(5),resizeHeight(50));
    lanternLR[15]->setGeometry(resizeWidth(1030),resizeHeight(45),resizeWidth(5),resizeHeight(50));
    lanternLR[16]->setGeometry(resizeWidth(83),resizeHeight(675),resizeWidth(5),resizeHeight(50));
    lanternLR[17]->setGeometry(resizeWidth(1030),resizeHeight(675),resizeWidth(5),resizeHeight(50));

    lanternUD[0]->setGeometry(resizeWidth(31),resizeHeight(96),resizeWidth(53),resizeHeight(5));
    lanternUD[1]->setGeometry(resizeWidth(365),resizeHeight(96),resizeWidth(53),resizeHeight(5));
    //lanternUD[2]->setGeometry(resizeWidth(697),resizeHeight(96),resizeWidth(53),resizeHeight(5));
    lanternUD[2]->setGeometry(resizeWidth(1030),resizeHeight(96),resizeWidth(53),resizeHeight(5));

    lanternUD[3]->setGeometry(resizeWidth(31),resizeHeight(357),resizeWidth(53),resizeHeight(5));
    lanternUD[4]->setGeometry(resizeWidth(31),resizeHeight(410),resizeWidth(53),resizeHeight(5));
    lanternUD[5]->setGeometry(resizeWidth(365),resizeHeight(357),resizeWidth(53),resizeHeight(5));
    lanternUD[6]->setGeometry(resizeWidth(365),resizeHeight(410),resizeWidth(53),resizeHeight(5));
    lanternUD[7]->setGeometry(resizeWidth(697),resizeHeight(410),resizeWidth(53),resizeHeight(5));
    lanternUD[8]->setGeometry(resizeWidth(1030),resizeHeight(357),resizeWidth(53),resizeHeight(5));
    lanternUD[9]->setGeometry(resizeWidth(1030),resizeHeight(410),resizeWidth(53),resizeHeight(5));

    lanternUD[10]->setGeometry(resizeWidth(31),resizeHeight(668),resizeWidth(53),resizeHeight(5));
    lanternUD[11]->setGeometry(resizeWidth(365),resizeHeight(668),resizeWidth(53),resizeHeight(5));
    lanternUD[12]->setGeometry(resizeWidth(697),resizeHeight(668),resizeWidth(53),resizeHeight(5));
    lanternUD[13]->setGeometry(resizeWidth(1030),resizeHeight(668),resizeWidth(53),resizeHeight(5));
}

//设置按钮不可点击
void Body::setunabled(){
    for(int i=0;i<12;i++){
        btnGroup->button(i)->setEnabled(false);
    }
}

//设置可点击
void Body::setenabled(){
    for(int i=0;i<12;i++){
        btnGroup->button(i)->setEnabled(true);
    }
}

//设置终点
void Body::autoEndpointSlot(){
    setenabled();
}


//设置起点
void Body:: autoStartpointSlot(){
    vector.clear();
    once=true;
    setenabled();

}

//手动开始(开始选路口)后
void Body::manualChoiceSlot(){
    setenabled();
    once=false;
}


//点击路口后获取路口标号
void Body::btnSlot()
{
    QString text = ((QPushButton*)sender())->text();
    int index=text.toInt()-1;
    vector.append(index);
    for(int i=0;i<vector.size();i++){
        QString str=QString::number(vector.at(i));
        qDebug()<<"手动点击按钮的标号"<<str;
    }
    if(once)
        setunabled();
}
void Body::on_autoButton_clicked()
{
    if(vector.size()>=2){
        if(flag)
            for(int i=0;i<ROAD_NUM;i++){
                labels[i]->setStyleSheet(jam_level_color[jam_level[i]]);
            }
        else
            for(int i=0;i<ROAD_NUM;i++){
               labels[i]->setStyleSheet("background-color:transparent");
            }
        qDebug()<<"自动规划信号抵达body";
        crossingVector=Route::getRoutePtr()->minRouteJam(vector.at(0),vector.at(1),jam_level);
         emit autoPlanCrossingSignal(crossingVector);
        for(int i=0;i<crossingVector.size();i++){
            qDebug()<<"返回的路径"<<crossingVector.at(i);
        }

        for(int i=0;i<crossingVector.size()-1;i++){

            int crossingIndex=crossingVector.at(i);
            int crossingIndexNext=crossingVector.at(i+1);
            int roadIndex=Route::getRoutePtr()->getNodeToEdge(crossingIndex,crossingIndexNext);
            qDebug()<<"自动规划路口"<<crossingVector.at(i)<<" "<<crossingVector.at(i+1)<<"路线"<<roadIndex;

            labels[roadIndex]->setStyleSheet("border:5px solid #00FFFF;"+jam_level_color[jam_level[roadIndex]]);


        }
        crossingVector.clear();
    }
    else
        QMessageBox::critical(this,"错误","请选择起点与终点");
    vector.clear();

}
//手动 发送点击后,标记路线,清空路口vector
void Body::on_manualButton_clicked()
{
    if(vector.size()>=2){
        adjoin=true;
        routeString="";
        if(flag)
            for(int i=0;i<ROAD_NUM;i++){
                labels[i]->setStyleSheet(jam_level_color[jam_level[i]]);
            }
        else
            for(int i=0;i<ROAD_NUM;i++){
               labels[i]->setStyleSheet("background-color:transparent");
            }
        for(int i=0;i<vector.size()-1;i++){
            int crossingIndex=vector.at(i);
            int crossingIndexNext=vector.at(i+1);
            int roadIndex=Route::getRoutePtr()->getNodeToEdge(crossingIndex,crossingIndexNext);
            if(roadIndex==-1){
                QMessageBox::critical(this,"错误","请选择相邻的路口");
                vector.clear();
                adjoin=false;
                break;
            }
        }
        if(adjoin){
            emit crossingSignal(vector);  //发送拥堵信号接口.是否还需要?
            for(int i=0;i<vector.size()-1;i++){
                int crossingIndex=vector.at(i);
                int crossingIndexNext=vector.at(i+1);
                int roadIndex=Route::getRoutePtr()->getNodeToEdge(crossingIndex,crossingIndexNext);
                qDebug()<<"标记路线"<<QString::number(roadIndex);
                if(i==0){
                    routeString=QString::number(crossingIndex+1)+"->"+QString::number(crossingIndexNext+1);
                }
                else{
                    routeString=routeString+"->"+QString::number(crossingIndexNext+1);
                }
    //            routeString+=(i==0?""+crossingIndex:"->"+crossingIndex);

                labels[roadIndex]->setStyleSheet("border:5px solid #00FFFF;"+jam_level_color[jam_level[roadIndex]]);
            }
            setunabled();
            qDebug()<<routeString;
            emit routeView(routeString);

        }
    }else{
        QMessageBox::critical(this,"错误","请选择至少一条路线");
    }
    vector.clear();
}

void Body::roadConSlot(int index){
    if(index==0){
        flag=true;
        qsrand((unsigned)time(NULL));
        for(int i = 0; i < ROAD_NUM; i++)
        {
            int r = (round(1.0 * rand() / RAND_MAX * (3 - 0) - 0.5));
            jam_level[i] = r; // 记录当前生成的所有路段的拥堵等级，供路径规划使用
            labels[i]->setStyleSheet(jam_level_color[r]);
        }
    }
    else{
        flag=false;
        for(int i=0;i<ROAD_NUM;i++){
            jam_level[i]=0;
            labels[i]->setStyleSheet("background:transparent");
        }
    }

    emit roadConditionSignal(jam_level,ROAD_NUM);
}

//动画
void Body::initMap()
{
    QSettings set("rotateconfig.ini",QSettings::IniFormat);

    for(int i = 0;i<32;i++)
    {
        QString path = QString("TransToCmdSeqGroup/%1").arg(i);
        int rotate = set.value(path).toInt();
        map.insert(animal[i],rotate);
        qDebug()<<rotate;
    }
}
//将animal数组进行初始化
void Body::initAnimal()
{
      QSettings set("animationValue.ini",QSettings::IniFormat);
      QPointF startValue,endValue;
      float s_x,s_y,e_x,e_y;
      for(int i =0;i<32;i++)
      {
          QPropertyAnimation*  temp = new QPropertyAnimation(carLabel,"pos");
          QString pathX = QString("StartValueGroup/%1_x").arg(i);
          QString pathY = QString("StartValueGroup/%1_y").arg(i);
          s_x = set.value(pathX).toFloat()*1053/1120+31.0/1120;
          s_y = set.value(pathY).toFloat()*686/781+43.0/781;
          startValue.setX(s_x*width());
          startValue.setY(s_y*height());
          temp->setStartValue(startValue);
          pathX = QString("EndValueGroup/%1_x").arg(i);
          pathY = QString("EndValueGroup/%1_y").arg(i);
          e_x = set.value(pathX).toFloat()*1053/1120+31.0/1120;
          e_y = set.value(pathY).toFloat()*686/781+43.0/781;
          endValue.setX(e_x*width());
          endValue.setY(e_y*height());
          temp->setEndValue(endValue);
          temp->setDuration(3000);  //每段动画的放映时间
          animal.append(temp);
      }
}

void Body::setAnimationGroup(const QVector<QPropertyAnimation *> &vect)
{
    group = new QSequentialAnimationGroup();
    for(int i =0;i<vect.size();i++)
    {
        group->addAnimation(vect[i]);
    }
    //整个动画组只需要start一次
    //start()之后开辟一个子线程来播放动画
    group->start();
    animationTimer->start(200);
}

void Body::initAnimationTimer()
{
    animationTimer = new QTimer;
    animationTimer->setTimerType(Qt::PreciseTimer);
    //信号与槽函数的绑定
    connect(animationTimer,SIGNAL(timeout()),this,SLOT(animationTimerSlot()));
}

//动画定时器
void Body::animationTimerSlot()
{
    if(group->state() != QPropertyAnimation::Stopped)
    {
            //1.旋转角度和当前正在运行的动画有关
            int rotate = 360-map.value((QPropertyAnimation *)group->currentAnimation());
            //2.
            carLabel->setRotate(rotate);
     }
     else{
        animationTimer->stop();
        animationTimer->deleteLater();
    }
}

void Body::startAnimation(int car_num, const QVector<int> &crossing_vec, const QVector<int> &route_num, const QVector<int> &rotate_vec)
{
    Q_UNUSED(crossing_vec);
    Q_UNUSED(rotate_vec);
    //初始化定时器
    initAnimationTimer();
    //初始化动画
    initAnimal();
    //调用动画函数
    //由路的编号得到动画的编号
    QVector<QPropertyAnimation *> currentAnimal;
    for(int i = 0;i<route_num.size();i++)
    {
        currentAnimal.append(animal.at(route_num.at(i)));
    }
    setAnimationGroup(currentAnimal);
    //初始化map
    initMap();
}

