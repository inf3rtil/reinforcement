#include "experiment.h"
#include <QDebug>
#include <random>

void Experiment::shuffleTestData(unsigned int index)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(tests[index].pic.begin(), tests[index].pic.end(), std::default_random_engine(seed));
}

Experiment::Experiment() {
}

void Experiment::setDataPath(QString dataPath)
{
    this->dataPath = dataPath;
}

// load each test image set
void Experiment::initTest()
{
    for(int i = 0; i < totalTests; i++) //TODO: get total tests dinamicaly
    {
        ImageTest img = ImageTest(dataPath, i);
        tests.append(img);
    }
}

//return the set of images for current test
ImageTest * Experiment::nextTest(bool random)
{
    unsigned int index = currentTest;
    if(random)
    {
        //TODO index = range betwen 0 and max tests
    }
    shuffleTestData(index);
    return &tests[index];
}

// handle answer and increment or not the test
void Experiment::setAnswer(int answer)
{
    Picture::TestChoice choice = tests[currentTest].pic[answer-1].choice; //pass index with -1 directly
    if(choice == Picture::TestChoice::RIGHT_ANSWER)
    {
        hits++;
        //TODO ring bell
        //create an object to store results
        qDebug() << "acertou";
        currentTest++;
    }
    else if(choice == Picture::TestChoice::WRONG_ANSWER)
    {
        qDebug() << "errou";
        currentTest++;
    }
    else if(choice == Picture::TestChoice::DISTRACTOR)
    {
        qDebug() << "distractor";
        //TODO special handle, return and blink the label
    }else if(choice == Picture::TestChoice::TIMEOUT)
    {
        qDebug() << "timeout";
        currentTest++;
    }

}
