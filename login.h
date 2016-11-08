//maxwell Sanders 1001069652
//This is the class for the login window

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Box.H>
#include <Fl/Fl_Menu_Item.H>
#include <Fl/Fl_Choice.H>

#ifndef __login_H
#define __login_H 2016
class login : public Fl_Window{
     
    public:
	login() :
	Fl_Window(1000,700,"Rob Robman's Rockin RoboShop - login"){};	
 
};
#endif
