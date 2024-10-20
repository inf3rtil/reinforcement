#ifndef WIDGET_H
#define WIDGET_H

#include "config.h"
#include "experiment.h"
#include "stimulus.h"
#include <QWidget>
#include <qboxlayout.h>
#include <qlabel.h>
#include <qpicture.h>
#include <QTimer>

#define TIMEOUT_TEST_MS 6000
#define TIMEOUT_BLACK_SCREEN_MS 2000
#define CLEAR_SCREEN_TIMER_MS 2000
#define TOTAL_STIMULUS 9

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:

    void initLabelsArray(void);
    void updateLabelsArray(void);
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    config *configWidget;
    Experiment exp;
    QTimer updateTestTimer;
    QTimer timeoutTestTimer;
    QTimer clearScreenTimer;
    Stimulus *stimulus;
    QGridLayout *layout;

protected:
    void keyPressEvent(QKeyEvent *event) override;

public slots:
    void updateScreen(void);
    void timeoutScreen(void);
    void clearScreen(void);
};
#endif // WIDGET_H
