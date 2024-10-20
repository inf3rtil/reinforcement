#include "stimulus.h"
#include <QPainter>
Stimulus::Stimulus(QWidget *parent, Qt::WindowFlags f)
{

}

void Stimulus::drawError()
{
    QPixmap pix = this->pixmap();
    QPainter painter;
    painter.begin(&pix);
    painter.setPen(QPen(Qt::red, 20, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));
    painter.drawRect(QRect(0,0,200,200));
    painter.end();
    this->setPixmap(pix);
    update();
}
