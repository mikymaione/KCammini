/*
 * File:   QGraphicsViewEc.cpp
 * Author: Michele
 *
 * Created on 14 luglio 2015, 18.59
 */

#ifndef QGRAPHICSVIEWEC_H
#define QGRAPHICSVIEWEC_H

#include <QGraphicsView>

class QGraphicsViewEc : public QGraphicsView {
    Q_OBJECT

public:
    QGraphicsViewEc(QWidget *parent = 0);

protected:
    virtual void wheelEvent(QWheelEvent* event);
};

#endif // QGRAPHICSVIEWEC_H
