#ifndef PICTURE_H
#define PICTURE_H

#include <qpixmap.h>
class Picture
{

public:
enum TestChoice{
    RIGHT_ANSWER,
    WRONG_ANSWER,
    DISTRACTOR,
    TIMEOUT
};
    TestChoice choice{WRONG_ANSWER};
    QPixmap image;
    Picture();
};

#endif // PICTURE_H
