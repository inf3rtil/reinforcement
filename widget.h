#ifndef WIDGET_H
#define WIDGET_H

#include "config.h"
#include "experiment.h"
#include <QWidget>
#include <qlabel.h>
#include <qpicture.h>
#include <QTimer>

#define TIMEOUT_TEST_MS 4000
#define TIMEOUT_BLACK_SCREEN_MS 2000

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:

    QLabel *viewImages[9] = {nullptr};
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
    void clearScreen(void);

protected:
    void keyPressEvent(QKeyEvent *event) override;

public slots:
    void updateScreen(void);
    void timeoutScreen(void);
};
#endif // WIDGET_H
