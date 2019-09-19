/*
 * File:   QGraphicsViewEc.cpp
 * Author: Michele
 *
 * Created on 14 luglio 2015, 18.59
 */

#include "QGraphicsViewEc.h"
#include "moc_QGraphicsViewEc.cpp"
#include "QWheelEvent"
#include "qmath.h"

QGraphicsViewEc::QGraphicsViewEc(QWidget* parent) : QGraphicsView(parent)
{
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
}

void QGraphicsViewEc::wheelEvent(QWheelEvent* event)
{
    qreal scaleFactor = qPow(2.0, event->delta() / 240.0);
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();

    if (0.05 < factor && factor < 10)
        scale(scaleFactor, scaleFactor);
}