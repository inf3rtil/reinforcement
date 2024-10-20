#include "widget.h"
#include "./ui_widget.h"
#include "experiment.h"
#include <QKeyEvent>
#include <qsizepolicy.h>
#include "imagetest.h"


//labels ptr for using with loop
void Widget::initLabelsArray()
{
    viewImages[0] = this->ui->label;
    viewImages[1] = this->ui->label_2;
    viewImages[2] = this->ui->label_3;
    viewImages[3] = this->ui->label_4;
    viewImages[4] = this->ui->label_5;
    viewImages[5] = this->ui->label_6;
    viewImages[6] = this->ui->label_7;
    viewImages[7] = this->ui->label_8;
    viewImages[8] = this->ui->label_9;
}

void Widget::updateLabelsArray()
{
    ImageTest *test = exp.nextTest(false);
    bool ret;
    for(int i=0; i < 9; i++){
        viewImages[i]->setPixmap(test->pic[i].image);
    }
    timeoutTestTimer.start(TIMEOUT_TEST_MS);
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
//    , configWidget(new config())
{
    QObject::connect(&updateTestTimer, &QTimer::timeout, this, &Widget::updateScreen);
    QObject::connect(&timeoutTestTimer, &QTimer::timeout, this, &Widget::timeoutScreen);
    ui->setupUi(this);
    //configWidget->show();
    initLabelsArray();
    exp.setDataPath("/home/infertil/data/repos/koshlect/media"); //TODO: set dinamicaly
    exp.initTest(); //construct exp with datapath and initialize
    updateLabelsArray();
    timeoutTestTimer.setSingleShot(true);
    updateTestTimer.setSingleShot(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::clearScreen()
{
    for(int i=0; i < 9; i++){
        viewImages[i]->clear();
    }
    this->updateTestTimer.start(TIMEOUT_BLACK_SCREEN_MS);
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    timeoutTestTimer.stop();
    {
        if(event->key() == Qt::Key_1)
        {
            exp.setAnswer(1);
            clearScreen();
        }
        else if(event->key() == Qt::Key_2)
        {
            exp.setAnswer(2);
            clearScreen();
        }
        else if(event->key() == Qt::Key_3)
        {
            exp.setAnswer(3);
            clearScreen();
        }
        else if(event->key() == Qt::Key_4)
        {
            exp.setAnswer(4);
            clearScreen();
        }
        else if(event->key() == Qt::Key_5)
        {
            exp.setAnswer(5);
            clearScreen();
        }
        else if(event->key() == Qt::Key_6)
        {
            exp.setAnswer(6);
            clearScreen();
        }
        else if(event->key() == Qt::Key_7)
        {
            exp.setAnswer(7);
            clearScreen();
        }
        else if(event->key() == Qt::Key_8)
        {
            exp.setAnswer(8);
            clearScreen();
        }
        else if(event->key() == Qt::Key_9)
        {
            exp.setAnswer(9);
            clearScreen();
        }
    }
}

void Widget::updateScreen()
{
    updateLabelsArray();
}

void Widget::timeoutScreen()
{
    clearScreen();
}

