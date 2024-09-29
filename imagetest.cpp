#include "imagetest.h"
#include <QPixmap>

void ImageTest::initImageData(void)
{

}

//TODO: split this function, use macros for sizes and positions
//TODO: create test types, some tests has 8 distractors one correct or one wrong

// 7D_1C_1E
// 8D_1C
// 8D_1E
ImageTest::ImageTest(QString path, int index)
{
    bool ret = false;
    int i = 0;

    //get distractor images
    for(; i <= 7; ++i)
    {
        QString fullpath = QString("%1/%2/%3.png").arg(path,QString::number(index),QString::number(i));
        QPixmap pixmap = QPixmap(fullpath);
        if(!pixmap.isNull())
        {
            pic[i].image = pixmap;
            pic[i].choice = Picture::TestChoice::DISTRACTOR;
        }
        else
        {
            break;
        }
    }

    //get right answer
    QString fullpath = QString("%1/%2/C.png").arg(path,QString::number(index));
    QPixmap pixmap = QPixmap(fullpath);
    if(!pixmap.isNull())
    {
        pic[i].image = pixmap;
        pic[i].choice = Picture::TestChoice::RIGHT_ANSWER;
        i++;
    }
    //get wrong answer
    fullpath = QString("%1/%2/E.png").arg(path,QString::number(index));
    pixmap = QPixmap(fullpath);
    if(!pixmap.isNull())
    {
        pic[i].image = pixmap;
        pic[i].choice = Picture::TestChoice::WRONG_ANSWER;
    }
}
