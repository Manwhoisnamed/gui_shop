//maxwell sanders 1001069652
//this is the window which will hold all of the other windows

#include "login.h"
#include "pos.h"
#include "salesfloor.h"
#include "workshop.h"

#ifndef __father_H
#define __father_H 2016
class father : public Fl_Window{
    login login_win;
    pos sales_win;
    workshop pm_win;
    salesfloor customer_win;
    public:
        father() 
        : Fl_Window(1000,700, "Rob Robman's Rockin Roboshop System"){
	    this->add(login_win);
	    this->add(pm_win);
	    this->add(sales_win);
	    this->add(customer_win);
	    end();
        }
};
#endif
