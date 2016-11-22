//maxwell Sanders
//this is the file that holds the order creator window

#include <Fl/Fl.H>
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Output.H>
#include <Fl/Fl_Int_Input.H>
#include <Fl/Fl_Box.H>
#include <Fl/Fl_Button.H>
#include <Fl/Fl_Multiline_Input.H>
#include <Fl/Fl_Choice.H>

#ifndef __gui_order_H
#define __gui_order_H 2016
class gui_order: public Fl_Window{
    Fl_Output apin;
    Fl_Choice cpin;
    Fl_Choice models;
    Fl_Int_Input quantity;
    Fl_Output subtotal;
    Fl_Output total;
    Fl_Button refresh;
    Fl_Button confirm;
    Fl_Button cancel;
    Fl_Box cust_error;
    Fl_Box model_error;
    Fl_Box quantity_error;
    int modelsize = 0;
    int customersize = 0;

    //this is the callback combo to cancel out of the window
    inline void cancel_clicked_i(){
	this->hide();
    }
    static void cancel_clicked(Fl_Widget* w, void* data){
	((gui_order*)data)->cancel_clicked_i();
    }

    //this is the callback combo to refresh
    inline void refresh_clicked_i(){
	    for(int x = modelsize; x < storage.robomodelSize(); x ++){
		models.add((to_string(storage.getRoboModel(x).getMN()) + " - " + (storage.getRoboModel(x).getName())).c_str());
	    }

	    for(int x = customersize; x < database.getCustomerSize(); x ++){
		cpin.add((to_string(database.loadCustomer(x).getPin()) + " - " + (database.loadCustomer(x).getName())).c_str());
	    }
	modelsize = storage.robomodelSize();
	customersize = database.getCustomerSize();
    }
    static void refresh_clicked(Fl_Widget* w, void* data){
	((gui_order*)data)->refresh_clicked_i();
    }

    //callback combo for when a robomodel is selected
    inline void select_i(){
	if(models.value() != 0){
	    subtotal.value(to_string(storage.getRoboModel(models.value() - 1).getPrice() * atoi(quantity.value())).c_str());
	    total.value(to_string(storage.getRoboModel(models.value() - 1).getPrice() * atoi(quantity.value()) * 1.08).c_str());	    
  	}
	else{
	    subtotal.value("0");
	    total.value("0");
	}
    }
    static void select(Fl_Widget* w, void* data){
	((gui_order*)data)->select_i();
    }

    //this is the callback combo to cancel out of the window
    inline void confirm_clicked_i(){
	bool valid = true;
	if(cpin.active() && cpin.value() == 0){
	    cust_error.label("Pick One");
	    valid = false;
	}
	else{
	    cust_error.label("");
	}

	if(models.value() == 0){
	    model_error.label("Pick One");
	    valid = false;
	}
	else{
	    model_error.label("");
	}

	if(atoi(quantity.value()) == 0){
	    quantity_error.label("0 is invalid");
	    valid = false;
	}
	else{
	    quantity_error.label("");
	}

	if(valid){
	    Order order;
	    order.setCustomerPin(database.loadCustomer(cpin.value() - 1).getPin());
	    order.setModelNumber(storage.getRoboModel(models.value() - 1).getMN());
	    order.setQuantity(atoi(quantity.value()));
	    order.setAssociatePin(atoi(apin.value()));
	    database.addOrder(order);
	    database.saveData();
	    this->hide();
	}
    }
    static void confirm_clicked(Fl_Widget* w, void* data){
	((gui_order*)data)->confirm_clicked_i();
    }

    public:

    void cust_reset_vals(){
	refresh_clicked_i();
	apin.value("1000");
	cpin.value(database.loadCustomerPinIndex(currentpin) + 1);
	cpin.deactivate();
	models.value(0);
	quantity.value("");
	subtotal.value("0");
	total.value("0");
    }	

    void sales_reset_vals(){
	refresh_clicked_i();
	apin.value(to_string(currentpin).c_str());
	cpin.activate();
	cpin.value(0);
	models.value(0);
	quantity.value("");
	subtotal.value("0");
	total.value("0");
    }		

    gui_order():
	Fl_Window(350, 245, "Order Creator"),
	refresh(5,5,100,25,"Refresh"),
	apin(100, 35, 100, 25, "Associate"),
	cpin(100, 65, 100,25, "Customer"),
	models(100, 95, 100, 25, "Model"),
	quantity(100, 125, 100, 25, "Quantity"),
	cust_error(230, 65, 100,25, ""),
	model_error(230, 95, 100, 25, ""),
	quantity_error(230, 125, 100, 25, ""),
	subtotal(100, 155, 100, 25, "Subtotal"),
	total(100,185,100,25, "Total"),
	cancel(245, 215, 100, 25, "Cancel"),
	confirm(140, 215, 100, 25, "Confirm"){
	    cancel.callback(cancel_clicked, this);
	    confirm.callback(confirm_clicked, this);
	    cust_error.labelcolor(FL_RED);
	    model_error.labelcolor(FL_RED);
	    quantity_error.labelcolor(FL_RED);
	    models.callback(select,this);
	    quantity.callback(select, this);
	    models.add("Choose One");
	    cpin.add("Choose One");
	}
};
#endif
