//maxwell Sanders 1001069652
//this is the file for the customer creator

#include <Fl/Fl.H>
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Input.H>
#include <Fl/Fl_Button.H>
#include <Fl/Fl_Box.H>
#include "globals.h"

#ifndef __gui_customer_H
#define __gui_customer_H 2016
class gui_customer: public Fl_Window{
    Fl_Input name;
    Fl_Input address;
    Fl_Input newpass1;
    Fl_Input newpass2;
    Fl_Box name_error;
    Fl_Box address_error;
    Fl_Box new1_error;
    Fl_Box new2_error;
    Fl_Button confirm;
    Fl_Button cancel;

    //this is the callback combo to cancel out of the window
    inline void cancel_clicked_i(){
	this->hide();
    }
    static void cancel_clicked(Fl_Widget* w, void* data){
	((gui_customer*)data)->cancel_clicked_i();
    }

    //this is the callback combo to cancel out of the window
    inline void confirm_clicked_i(){
	bool valid = true;
	//if the name isn't there
	if(strlen(name.value()) == 0){
	    valid = false;
	    name_error.label("Need Name");	
	}
	else{
	    name_error.label("");
	}

	//if the address isn't there
	if(strlen(address.value()) == 0){
	    valid = false;
	    address_error.label("Need Address");	
	}
	else{
	    address_error.label("");
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

	//if pin is already in use
	if(database.checkPin(atoi(newpass1.value()))){
	    valid = false;
	    new1_error.label("Pin in use");
	}
	if(database.checkPin(atoi(newpass2.value()))){
	    valid = false;
	    new2_error.label("Pin in use");
	}

	if(valid){
	    Customer customer(name.value(), atoi(newpass1.value()), address.value());
	    database.addCustomer(customer);
	    database.saveData();
	    this->hide();
	}
    }
    static void confirm_clicked(Fl_Widget* w, void* data){
	((gui_customer*)data)->confirm_clicked_i();
    }

    public:

    void reset_vals(){
	name.value("");
	address.value("");
	newpass1.value("");
	newpass2.value("");
	name_error.label("");
	new1_error.label("");
	new2_error.label("");
	address_error.label("");
    }		

    gui_customer():
	Fl_Window(350, 155, "Customer Creator"),
	name(125, 5, 100, 25, "Name"),
	name_error(230, 5, 100, 25, ""),
	address(125, 35, 100, 25, "Address"),
	address_error(230, 35, 100, 25, ""),
	newpass1(125, 65, 100, 25, "New Pin"),
	new1_error(230, 65, 100, 25, ""),
	newpass2(125, 95, 100, 25, "Confirm Pin"),
	new2_error(230, 95, 100, 25, ""),
	cancel(245, 125, 100, 25, "Cancel"),
	confirm(140, 125, 100, 25, "Confirm"){
	    cancel.callback(cancel_clicked, this);
	    confirm.callback(confirm_clicked, this);
	    reset_vals();
	    name_error.labelcolor(FL_RED);
	    new1_error.labelcolor(FL_RED);
	    new2_error.labelcolor(FL_RED);
	    address_error.labelcolor(FL_RED);
	}
};
#endif
