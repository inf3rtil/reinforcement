#include "widget.h"
#include "./ui_widget.h"
#include "experiment.h"
#include <QKeyEvent>
#include <qsizepolicy.h>
#include "imagetest.h"


//labels ptr for using with loop
void Widget::initLabelsArray()
{
    for (int i = 0; i < TOTAL_STIMULUS; i++)
    {
        layout->addWidget(&stimulus[i]);
    }
}

void Widget::updateLabelsArray()
{
    ImageTest *test = exp.nextTest(false);
    bool ret;
    for(int i=0; i < TOTAL_STIMULUS; i++){
        stimulus[i].setPixmap(test->pic[i].image);
    }
    timeoutTestTimer.start(TIMEOUT_TEST_MS);
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , stimulus(new Stimulus[TOTAL_STIMULUS])
//    , configWidget(new config())
{
    QObject::connect(&updateTestTimer, &QTimer::timeout, this, &Widget::updateScreen);
    QObject::connect(&timeoutTestTimer, &QTimer::timeout, this, &Widget::timeoutScreen);
    QObject::connect(&clearScreenTimer, &QTimer::timeout, this, &Widget::clearScreen);
    ui->setupUi(this);
    //configWidget->show();
    layout = new QGridLayout(this);
    layout->setHorizontalSpacing(20);
    layout->setVerticalSpacing(20);
    layout->setColumnMinimumWidth(2, 0);
    initLabelsArray();
    exp.setDataPath("/home/infertil/data/repos/koshlect/media"); //TODO: set dinamicaly
    exp.initTest(); //construct exp with datapath and initialize

    updateLabelsArray();

    timeoutTestTimer.setSingleShot(true);
    updateTestTimer.setSingleShot(true);
    clearScreenTimer.setSingleShot(true);
}

Widget::~Widget()
{
    delete layout;
    delete ui;
}

void Widget::clearScreen()
{
    for(int i=0; i < 9; i++){
        stimulus[i].clear();
    }
    this->updateTestTimer.start(TIMEOUT_BLACK_SCREEN_MS);
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    int answer = 0;
    timeoutTestTimer.stop();
    {
        if(event->key() == Qt::Key_1)
        {
            answer = 1;
        }
        else if(event->key() == Qt::Key_2)
        {
            answer = 2;
        }
        else if(event->key() == Qt::Key_3)
        {
            answer = 3;
        }
        else if(event->key() == Qt::Key_4)
        {
            answer = 4;
        }
        else if(event->key() == Qt::Key_5)
        {
            answer = 5;
        }
        else if(event->key() == Qt::Key_6)
        {
            answer = 6;
        }
        else if(event->key() == Qt::Key_7)
        {
            answer = 7;
        }
        else if(event->key() == Qt::Key_8)
        {
            answer = 8;
        }
        else if(event->key() == Qt::Key_9)
        {
            answer = 9;
        }
    }
    if(exp.setAnswer(answer) != Picture::TestChoice::RIGHT_ANSWER)
    {
        stimulus[answer-1].drawError();
    }
    //clearScreen();
    clearScreenTimer.start(CLEAR_SCREEN_TIMER_MS);
}

void Widget::updateScreen()
{
    updateLabelsArray();
}

void Widget::timeoutScreen()
{
    clearScreen();
}

