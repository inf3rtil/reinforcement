#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include "imagetest.h"
class Experiment
{
private:
    QString dataPath;
    int totalTests = {2};
    int currentTest = {0};
    int hits = {0};

    void shuffleTestData(unsigned int index);

public:
    Experiment();
    QList<ImageTest> tests;
    void setDataPath(QString dataPath);
    void initTest(void);
    ImageTest *nextTest(bool random);
    Picture::TestChoice setAnswer(int answer);
};

#endif // EXPERIMENT_H
