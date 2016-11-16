//maxwell sanders
//this is the thing that pops up when the Project manager wants to change his pin

#include <Fl/Fl.H>
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Input.H>
#include <Fl/Fl_Button.H>
#include <Fl/Fl_Box.H>
#include "globals.h"

#ifndef __gui_PMPin_H
#define __gui_PMPin_H 2016
class gui_PMPin : public Fl_Window{
    Fl_Input oldpass;
    Fl_Input newpass1;
    Fl_Input newpass2;
    Fl_Button confirm;
    Fl_Button cancel;

    void reset_vals(){
	oldpass.value("");
	newpass1.value("");
	newpass2.value("");
    }	

    public:
	gui_PMPin
};
#endif
