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
    Fl_Return_Button login_button;
    Fl_Input pin_field;
    Fl_Box clearance;
    Fl_Button change;
    Fl_Box response;    
    public:
	login() :
	Fl_Window(1000,700,"Rob Robman's Rockin RoboShop - login"),
	login_button(450,350,100,50,"Login"),
        pin_field(450, 300, 100, 25, "Pin"),
        clearance(425, 250, 150, 25, "Project Manager"),
        change(275, 250, 150, 25, "Change Permissions"),
        response(575, 300, 150,25,"currently uninstantiated"){
        };
};
#endif
