/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   fAbout.h
 * Author: mikym
 *
 * Created on 13 aprile 2016, 18.00
 */

#ifndef _FABOUT_H
#define _FABOUT_H

#include "ui_fAbout.h"

class fAbout : public QDialog {
    Q_OBJECT
public:
    fAbout();
    virtual ~fAbout();
private:
    Ui::fAbout widget;
};

#endif /* _FABOUT_H */
