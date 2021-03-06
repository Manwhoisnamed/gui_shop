//maxwell Sanders 1001069652
//This is the class for the customer side of the salesfloor window, which will open the customer windows

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Box.H>
#include <Fl/Fl_Menu_Item.H>
#include <Fl/Fl_Choice.H>
#include <Fl/Fl_Menu.H>
#include <Fl/Fl_Menu_Bar.H>
#include "globals.h"
#include "gui_order.h"
#include "view_model.h"

#ifndef __salesfloor_H
#define __salesfloor_H 2016
class salesfloor : public Fl_Window{
    Fl_Button logout;   
    Fl_Menu_Bar menu;
    gui_order order_win;
    view_model model_view;
    Fl_Menu_Item commands[20] = {
	{"&Orders",FL_ALT+'o', 0, 0, FL_SUBMENU},	
	{"&Create Order",FL_ALT+'c', create_order, this},
	{"&View Catalogue",FL_ALT+'v', view_model_view, this},
	{0},
	{"&Help",FL_ALT+'h', 0, 0, FL_SUBMENU},	
	{"&Stop Viewing",FL_ALT+'s', hide_all, this},
	{0},
    };

    //callback combo to hide all
    inline void view_model_view_i(){
	hide_all_i();
	model_view.reset_values();
	model_view.show();
    }
    static void view_model_view(Fl_Widget*w, void*data){
	((salesfloor*)data)->view_model_view_i();
    }

    //callback combo to hide all
    inline void hide_all_i(){
	model_view.hide();
    }
    static void hide_all(Fl_Widget*w, void*data){
	((salesfloor*)data)->hide_all_i();
    }

    //callback combo to create an order
    inline void create_order_i(){
	order_win.cust_reset_vals();
	order_win.show();
    }
    static void create_order(Fl_Widget*w, void*data){
	((salesfloor*)data)->create_order_i();
    }

    //callback combo to logout
    inline void logout_clicked_i(){
	this->hide();
	hide_all_i();
	order_win.hide();
	((this->parent())->child(0))->show();
    }
    static void logout_clicked(Fl_Widget*w, void*data){
	((salesfloor*)data)->logout_clicked_i();
    }

  public:
	salesfloor() :
	Fl_Window(1000,700),
	logout(910,660,80,30, "Logout"),
	menu(0,0,1000,20){
	    menu.menu(commands);
	    logout.callback(logout_clicked, this);
	    this->add(model_view);
	    model_view.hide();
        };


};
#endif
