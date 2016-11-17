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
    Fl_Box old_error;
    Fl_Box new1_error;
    Fl_Box new2_error;
    Fl_Button confirm;
    Fl_Button cancel;

    //this is the callback combo to cancel out of the window
    inline void cancel_clicked_i(){
	this->hide();
    }
    static void cancel_clicked(Fl_Widget* w, void* data){
	((gui_PMPin*)data)->cancel_clicked_i();
    }

    //this is the callback combo to cancel out of the window
    inline void confirm_clicked_i(){
	bool valid = true;
	//if the old pass doesn't match
	if(atoi(oldpass.value()) != database.getPMPin()){
	    valid = false;
	    old_error.label("Incorrect Pass");	
	}
	else{
	    old_error.label("");
	}

	//if the new passes aren't ints
	if(!isInt(newpass1.value())){
	    valid = false;
	    new1_error.label("Needs Integer");
	}
	if(!isInt(newpass2.value())){
	    valid = false;
	    new2_error.label("Needs Integer");
	}  

	//if the new pins aren't equal
	if(atoi(newpass1.value()) != atoi(newpass2.value())){
	    valid = false;
	    new1_error.label("Doesn't match");
	    new2_error.label("Doesn't match");
	}

	if(valid){
	    this->hide();
	    database.changePMPin(atoi(newpass1.value()));
	    database.saveData();
	}
    }
    static void confirm_clicked(Fl_Widget* w, void* data){
	((gui_PMPin*)data)->confirm_clicked_i();
    }

    public:

    void reset_vals(){
	oldpass.value("");
	newpass1.value("");
	newpass2.value("");
	old_error.label("");
	new1_error.label("");
	new2_error.label("");
    }	

	gui_PMPin():
	Fl_Window(350, 125, "PM Password Changer"),
	oldpass(125, 5, 100, 25, "Old Pin"),
	old_error(230, 5, 100, 25, ""),
	newpass1(125, 35, 100, 25, "New Pin"),
	new1_error(230, 35, 100, 25, ""),
	newpass2(125, 65, 100, 25, "Confirm New"),
	new2_error(230, 65, 100, 25, ""),
	cancel(245, 95, 100, 25, "Cancel"),
	confirm(140, 95, 100, 25, "Confirm"){
	    cancel.callback(cancel_clicked, this);
	    confirm.callback(confirm_clicked, this);
	    reset_vals();
	    old_error.labelcolor(FL_RED);
	    new1_error.labelcolor(FL_RED);
	    new2_error.labelcolor(FL_RED);
	}
};
#endif
