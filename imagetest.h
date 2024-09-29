#ifndef IMAGETEST_H
#define IMAGETEST_H


#include "picture.h"
class ImageTest
{
private:

    void initImageData(void);
public:
    std::array<Picture,9> pic = {};
    ImageTest(QString path, int index);

};

#endif // IMAGETEST_H
