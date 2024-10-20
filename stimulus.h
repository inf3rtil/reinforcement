#ifndef STIMULUS_H
#define STIMULUS_H

#include <QLabel>

class Stimulus : public QLabel
{
public:
    Stimulus(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    void drawError();
};

#endif // STIMULUS_H
