//maxwell Sanders 1001069652
//This is the class for the salesman side of the salesfloor window, which will open the sales man windows

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
#include "gui_customer.h"
#include "gui_order.h"

#ifndef __pos_H
#define __pos_H 2016
class pos : public Fl_Window{
    Fl_Button logout;   
    Fl_Menu_Bar menu;
    gui_customer customer_win;
    gui_order order_win;
    Fl_Menu_Item commands[20] = {
	{"&Customers",FL_ALT+'c', 0, 0, FL_SUBMENU},
	{"Create &Customer",FL_ALT+'c', create_customer, this},
	{"&View Customers",FL_ALT+'v', 0, 0},
	{0},
	{"&Orders",FL_ALT+'o', 0, 0, FL_SUBMENU},	
	{"Create &Order",FL_ALT+'o', create_order, this},
	{"View My &Sales",FL_ALT+'s', 0, 0},
	{"View &Catalogue",FL_ALT+'c', 0, 0},
	{0},
	{"&Help", FL_ALT+ 'h', 0,0, FL_SUBMENU},
	{"&Clear Viewer", FL_ALT + 'c', 0,0},
	{"Change &Name", FL_ALT + 'n', 0,0},
	{0},
	{0}
    };

    //callback combo to create an order
    inline void create_order_i(){
	order_win.sales_reset_vals();
	order_win.show();
    }
    static void create_order(Fl_Widget*w, void*data){
	((pos*)data)->create_order_i();
    }

    //callback combo to create a customer
    inline void create_customer_i(){
	customer_win.reset_vals();
	customer_win.show();
    }
    static void create_customer(Fl_Widget*w, void*data){
	((pos*)data)->create_customer_i();
    }

    //callback combo to logout
    inline void logout_clicked_i(){
	this->hide();
	order_win.hide();
	customer_win.hide();
	((this->parent())->child(0))->show();
    }
    static void logout_clicked(Fl_Widget*w, void*data){
	((pos*)data)->logout_clicked_i();
    }

  public:
	pos() :
	Fl_Window(1000,700),
	logout(910,660,80,30, "Logout"),
	menu(0,0,1000,20){
	    menu.menu(commands);
	    logout.callback(logout_clicked, this);
        };
};
#endif
