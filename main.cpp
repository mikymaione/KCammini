/*
 * File:   main.cpp
 * Author: Michele
 *
 * Created on 14 luglio 2015, 17.40
 */

#include <QApplication>
#include <time.h>
#include "fGraphDesign.h"

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication app(argc, argv);

    fGraphDesign f;
    f.showMaximized();

    return app.exec();
}