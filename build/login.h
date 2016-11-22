//maxwell Sanders 1001069652
//This is the class for the login window

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Box.H>
#include <Fl/Fl_Menu_Item.H>
#include <Fl/Fl_Choice.H>
#include "globals.h"
#include <iostream>

#ifndef __login_H
#define __login_H 2016
class login : public Fl_Window{
    Fl_Return_Button login_button;
    Fl_Int_Input pin_field;
    Fl_Choice clearance;
    Fl_Box response;    
    Fl_Menu_Item choices[6] = {
	{"Project Manager"},
	{"Beloved Customer"},
	{"Sales Associate"},
	{"Bossy Bossman"},
	{"System Admin"},
	{0}
    };	
    inline void progress_i(){
	if(clearance.value() == 0 && database.getPMPin() == atoi(pin_field.value())){
       	    this->hide();
	    response.label("");
	    ((this->parent())->child(1))->show();
	}
	else if(clearance.value() == 1 && database.checkPin(atoi(pin_field.value()))){
       	    this->hide();
	    currentpin = atoi(pin_field.value());
	    response.label("");
	    ((this->parent())->child(3))->show();
	}
	else if(clearance.value() == 2 && database.checkPinSales(atoi(pin_field.value()))){
       	    this->hide();
	    currentpin = atoi(pin_field.value());
	    response.label("");
	    ((this->parent())->child(2))->show();
	}
	else if(clearance.value() == 3 && database.getBossPin() == atoi(pin_field.value())){
       	    this->hide();
	    response.label("");
	    ((this->parent())->child(4))->show();
	}
	else if(clearance.value() == 4 && strcmp(pin_field.value(), "1337") == 0){
       	    this->hide();
	    response.label("");
	    ((this->parent())->child(5))->show();
	}
	else{
	    response.labelcolor(FL_RED);
	    response.label("Permission denied");
	}
	pin_field.value("");
    };
    static void progress(Fl_Widget* w, void* data){
	((login*)data)->progress_i();	
    };        
    public:
	login() :
	Fl_Window(1000,700,"Rob Robman's Rockin RoboShop - login"),
	login_button(450,350,100,50,"Login"),
        pin_field(450, 300, 100, 25, "Pin"),
        clearance(425, 250, 150, 25),
        response(575, 300, 150,25,""){
	login_button.callback(progress,this);
	clearance.menu(choices);
	end();
        };
};
#endif
