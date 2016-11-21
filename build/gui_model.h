//maxwell sanders 1001069652
//this is the gui window to create the robopart

#include <Fl/Fl.H>
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Output.H>
#include <Fl/Fl_Input.H>
#include <Fl/Fl_Box.H>
#include <Fl/Fl_Button.H>
#include <Fl/Fl_Multiline_Input.H>
#include <Fl/Fl_Choice.H>
#include <Fl/Fl_Menu_Item.H>

#ifndef __gui_model_H
#define __gui_model_H 2016

class gui_model: public Fl_Window{

    Fl_Button refresh;
    Fl_Output torso_name;
    Fl_Output head_name;
    Fl_Output leg_name;
    Fl_Output arm1_name;
    Fl_Output arm2_name;
    Fl_Output bat1_name;
    Fl_Output bat2_name;
    Fl_Output bat3_name;
    Fl_Choice torso_pin;
    Fl_Choice head_pin;
    Fl_Choice leg_pin;
    Fl_Choice arm1_pin;
    Fl_Choice arm2_pin;
    Fl_Choice bat1_pin;
    Fl_Choice bat2_pin;
    Fl_Choice bat3_pin;
    Fl_Output bspace;
    Fl_Output speed;
    Fl_Output passiveLife;
    Fl_Output cost;
    Fl_Output weight;
    Fl_Box name_header;
    Fl_Box pin_header;
    Fl_Box stats_header;
    Fl_Box div1;
    Fl_Box div2;
    Fl_Box div3;
    Fl_Box arm_laser;
    Fl_Output activeLife;
    Fl_Box head_laser;
    Fl_Input name;
    Fl_Box name_error;
    Fl_Input MN;
    Fl_Box MN_error;
    Fl_Input price;
    Fl_Box price_error;
    Fl_Multiline_Input description;
    Fl_Box description_error;
    Fl_Button create;
    Fl_Button cancel;
    int headSize;
    int legSize;
    int torsoSize;
    int arm1Size;
    int arm2Size;
    int bat1Size;
    int bat2Size;
    int bat3Size;
    int bats = 1;
	
    int headlast = 0;
    int leglast = 0;
    int torsolast = 0;
    int arm1last = 0;
    int arm2last = 0;
    int bat1last = 0;
    int bat2last = 0;
    int bat3last = 0;

    double charge = 0;
    double act = 0;
    double pass = 0;
    double cos = 0;
    double wei = 0;

    bool arm2was = false;
    bool bat2was = false;
    bool bat3was = false;

    //intialize the choices
    void initialize_choices(){
	headSize = storage.headSize();
	head_pin.add("Choose Part");
	for(int x = 0; x < headSize; x ++){
		head_pin.add((to_string(storage.getHead(x).getSN()) + " - " + storage.getHead(x).getName()).c_str());
	}
	if(headSize > 0){
	    head_pin.value(0);
	}

        legSize = storage.legSize();
	leg_pin.add("Choose Part");
	for(int x = 0; x < legSize; x ++){
		leg_pin.add((to_string(storage.getLeg(x).getSN()) + " - " + storage.getLeg(x).getName()).c_str());
	}
	if(legSize > 0){
	    leg_pin.value(0);
	}

        torsoSize = storage.torsoSize();
	torso_pin.add("Choose Part");
	for(int x = 0; x < torsoSize; x ++){
		torso_pin.add((to_string(storage.getTorso(x).getSN()) + " - " + storage.getTorso(x).getName()).c_str());
	}
	if(torsoSize > 0){
	    torso_pin.value(0);
	}

        arm1Size = storage.armSize();
	arm2Size = arm1Size;
	arm1_pin.add("Choose Part");
	arm2_pin.add("Choose Part");
	for(int x = 0; x < arm1Size; x ++){
		arm1_pin.add((to_string(storage.getArm(x).getSN()) + " - " + storage.getArm(x).getName()).c_str());
		arm2_pin.add((to_string(storage.getArm(x).getSN()) + " - " + storage.getArm(x).getName()).c_str());	
	}
	if(arm1Size > 0){
	    arm1_pin.value(0);
	    arm2_pin.value(0);
	}

        bat1Size = storage.batterySize();
	bat2Size = bat1Size;
	bat3Size = bat1Size;
	bat1_pin.add("Choose Part");
	bat2_pin.add("Choose Part");
	bat3_pin.add("Choose Part");
	for(int x = 0; x < bat1Size; x ++){
		bat1_pin.add((to_string(storage.getBattery(x).getSN()) + " - " + storage.getBattery(x).getName()).c_str());
		bat2_pin.add((to_string(storage.getBattery(x).getSN()) + " - " + storage.getBattery(x).getName()).c_str());
		bat3_pin.add((to_string(storage.getBattery(x).getSN()) + " - " + storage.getBattery(x).getName()).c_str());
	}
	if(bat1Size > 0){
	    bat1_pin.value(0);
	    bat2_pin.value(0);
	    bat3_pin.value(0);
	}

    }

    //callback combo to refresh the choices
    inline void refresh_choices_i(){
	int x = headSize;
	headSize = storage.headSize();
	for(; x < headSize; x ++){
		head_pin.add((to_string(storage.getHead(x).getSN()) + " - " + storage.getHead(x).getName()).c_str());
	}

	x = legSize;
        legSize = storage.legSize();
	for(; x < legSize; x ++){
		leg_pin.add((to_string(storage.getLeg(x).getSN()) + " - " + storage.getLeg(x).getName()).c_str());
	}

	x = torsoSize;
        torsoSize = storage.torsoSize();
	for(; x < torsoSize; x ++){
		torso_pin.add((to_string(storage.getTorso(x).getSN()) + " - " + storage.getTorso(x).getName()).c_str());
	}

	x = arm1Size;
        arm1Size = storage.armSize();
	arm2Size = arm1Size;
	for(; x < arm1Size; x ++){
		arm1_pin.add((to_string(storage.getArm(x).getSN()) + " - " + storage.getArm(x).getName()).c_str());
		arm2_pin.add((to_string(storage.getArm(x).getSN()) + " - " + storage.getArm(x).getName()).c_str());	
	}

	x = bat1Size;
        bat1Size = storage.batterySize();
	bat2Size = bat1Size;
	bat3Size = bat1Size;
	for(; x < bat1Size; x ++){
		bat1_pin.add((to_string(storage.getBattery(x).getSN()) + " - " + storage.getBattery(x).getName()).c_str());
		bat2_pin.add((to_string(storage.getBattery(x).getSN()) + " - " + storage.getBattery(x).getName()).c_str());
		bat3_pin.add((to_string(storage.getBattery(x).getSN()) + " - " + storage.getBattery(x).getName()).c_str());
	}

    }
    static void refresh_choices(Fl_Widget* w, void* data){
	((gui_model*)data)->refresh_choices_i();
    }

    //calculates the cost weight and life of everything
    void calculatecwl(){
	if(headlast != 0){
	    act -= storage.getHead(headlast - 1).getDraw();
            pass -= storage.getHead(headlast - 1).getDraw();
	    cos -= storage.getHead(headlast - 1).getCost();
	    wei -= storage.getHead(headlast - 1).getWeight();
	}
	if(head_pin.value() != 0){
	    act += storage.getHead(head_pin.value() - 1).getDraw();
            pass += storage.getHead(head_pin.value() - 1).getDraw();
	    cos += storage.getHead(head_pin.value() - 1).getCost();
	    wei += storage.getHead(head_pin.value() - 1).getWeight();
	}

	if(torsolast != 0){
	    act -= storage.getTorso(torsolast - 1).getDraw();
            pass -= storage.getTorso(torsolast - 1).getDraw();
	    cos -= storage.getTorso(torsolast - 1).getCost();
	    wei -= storage.getTorso(torsolast - 1).getWeight();
	}
	if(torso_pin.value() != 0){
	    act += storage.getTorso(torso_pin.value() - 1).getDraw();
            pass += storage.getTorso(torso_pin.value() - 1).getDraw();
	    cos += storage.getTorso(torso_pin.value() - 1).getCost();
	    wei += storage.getTorso(torso_pin.value() - 1).getWeight();
	}

	if(leglast != 0){
	    act -= storage.getLeg(leglast - 1).getactiveDraw();
            pass -= storage.getLeg(leglast - 1).getpassiveDraw();
	    cos -= storage.getLeg(leglast - 1).getCost();
	    wei -= storage.getLeg(leglast - 1).getWeight();
	}
	if(leg_pin.value() != 0){
	    act += storage.getLeg(leg_pin.value() - 1).getactiveDraw();
            pass += storage.getLeg(leg_pin.value() - 1).getpassiveDraw();
	    cos += storage.getLeg(leg_pin.value() - 1).getCost();
	    wei += storage.getLeg(leg_pin.value() - 1).getWeight();
	}

	if(arm1last != 0){
	    act -= storage.getArm(arm1last - 1).getactiveDraw();
            pass -= storage.getArm(arm1last - 1).getpassiveDraw();
	    cos -= storage.getArm(arm1last - 1).getCost();
	    wei -= storage.getArm(arm1last - 1).getWeight();
	}
	if(arm1_pin.value() != 0){
	    act += storage.getArm(arm1_pin.value() - 1).getactiveDraw();
            pass += storage.getArm(arm1_pin.value() - 1).getpassiveDraw();
	    cos += storage.getArm(arm1_pin.value() - 1).getCost();
	    wei += storage.getArm(arm1_pin.value() - 1).getWeight();
	}

	if(arm2_pin.active()){
	    if(arm2was){
		if(arm2last != 0){
		    act -= storage.getArm(arm2last - 1).getactiveDraw();
		    pass -= storage.getArm(arm2last - 1).getpassiveDraw();
		    cos -= storage.getArm(arm2last - 1).getCost();
		    wei -= storage.getArm(arm2last - 1).getWeight();
		}
		if(arm2_pin.value() != 0){
		    act += storage.getArm(arm2_pin.value() - 1).getactiveDraw();
		    pass += storage.getArm(arm2_pin.value() - 1).getpassiveDraw();
		    cos += storage.getArm(arm2_pin.value() - 1).getCost();
		    wei += storage.getArm(arm2_pin.value() - 1).getWeight();
		}
	    }
	    else{
		if(arm2_pin.value() != 0){
		    act += storage.getArm(arm2_pin.value() - 1).getactiveDraw();
		    pass += storage.getArm(arm2_pin.value() - 1).getpassiveDraw();
		    cos += storage.getArm(arm2_pin.value() - 1).getCost();
		    wei += storage.getArm(arm2_pin.value() - 1).getWeight();
		}
		arm2was = true;
	    }
	}
	else if(arm2was){
	    if(arm2last != 0){
		act -= storage.getArm(arm2last - 1).getactiveDraw();
		pass -= storage.getArm(arm2last - 1).getpassiveDraw();
		cos -= storage.getArm(arm2last - 1).getCost();
    		wei -= storage.getArm(arm2last - 1).getWeight();
	    }
	    arm2was = false;
	}

	if(bat1last != 0){
	    charge -= storage.getBattery(bat1last - 1).getCharge();
	    cos -= storage.getBattery(bat1last - 1).getCost();
	    wei -= storage.getBattery(bat1last - 1).getWeight();
	}
	if(bat1_pin.value() != 0){
	    charge += storage.getBattery(bat1_pin.value() - 1).getCharge();
	    cos += storage.getBattery(bat1_pin.value() - 1).getCost();
	    wei += storage.getBattery(bat1_pin.value() - 1).getWeight();
	}

	if(bat2_pin.active()){
	    if(bat2was){
		if(bat2last != 0){
		    charge -= storage.getBattery(bat2last - 1).getCharge();
		    cos -= storage.getBattery(bat2last - 1).getCost();
		    wei -= storage.getBattery(bat2last - 1).getWeight();
		}
		if(bat2_pin.value() != 0){
		    charge += storage.getBattery(bat2_pin.value() - 1).getCharge();
		    cos += storage.getBattery(bat2_pin.value() - 1).getCost();
		    wei += storage.getBattery(bat2_pin.value() - 1).getWeight();
		}
	    }
	    else{
		if(bat2_pin.value() != 0){
		    charge += storage.getBattery(bat2_pin.value() - 1).getCharge();
		    cos += storage.getBattery(bat2_pin.value() - 1).getCost();
		    wei += storage.getBattery(bat2_pin.value() - 1).getWeight();
		}
		bat2was = true;
	    }
	}
	else if(bat2was){
	    if(bat2last != 0){
		charge -= storage.getBattery(bat2last - 1).getCharge();
		cos -= storage.getBattery(bat2last - 1).getCost();
    		wei -= storage.getBattery(bat2last - 1).getWeight();
	    }
	    bat2was = false;
	}

	if(bat3_pin.active()){
	    if(bat3was){
		if(bat3last != 0){
		    charge -= storage.getBattery(bat3last - 1).getCharge();
		    cos -= storage.getBattery(bat3last - 1).getCost();
		    wei -= storage.getBattery(bat3last - 1).getWeight();
		}
		if(bat3_pin.value() != 0){
		    charge += storage.getBattery(bat3_pin.value() - 1).getCharge();
		    cos += storage.getBattery(bat3_pin.value() - 1).getCost();
		    wei += storage.getBattery(bat3_pin.value() - 1).getWeight();
		}
	    }
	    else{
		if(bat3_pin.value() != 0){
		    charge += storage.getBattery(bat3_pin.value() - 1).getCharge();
		    cos += storage.getBattery(bat3_pin.value() - 1).getCost();
		    wei += storage.getBattery(bat3_pin.value() - 1).getWeight();
		}
		bat3was = true;
	    }
	}
	else if(bat3was){
	    if(bat3last != 0){
		charge -= storage.getBattery(bat3last - 1).getCharge();
		cos -= storage.getBattery(bat3last - 1).getCost();
    		wei -= storage.getBattery(bat3last - 1).getWeight();
	    }
	    bat3was = false;
	}

	if(pass == 0){
	    passiveLife.value("N/A");
	}
	else{
	    passiveLife.value(to_string(charge/pass).c_str());
	}
	if(act == 0){
	    activeLife.value("N/A");
	}
	else{
	    activeLife.value(to_string(charge/act).c_str());
	}
	cost.value(to_string(cos).c_str());
	weight.value(to_string(wei).c_str());
    }

    //callback combo to get out of the creator
    inline void cancel_clicked_i(){
	this->hide();
    }
    static void cancel_clicked(Fl_Widget* w, void* data){
 	((gui_model*)data)->cancel_clicked_i();
    }

    //callback combo to get the head update
    inline void head_select_i(){	
	calculatecwl();
	if(head_pin.value() > 0){
	    head_name.value(storage.getHead(head_pin.value() - 1).getName().c_str());
	    if(storage.getHead(head_pin.value() - 1).getLaser()){
		head_laser.label("Contains Head Laser");
	    }
	    else{
	        head_laser.label("");
	    }
 	}
	else{
	    head_name.value("");
	}
	headlast = head_pin.value();
    }
    static void head_select(Fl_Widget* w, void* data){
 	((gui_model*)data)->head_select_i();
    }

    //callback combo to get the leg update
    inline void leg_select_i(){
	calculatecwl();
	if(leg_pin.value() > 0){
	    leg_name.value(storage.getLeg(leg_pin.value() - 1).getName().c_str());
	    speed.value(to_string(storage.getLeg(leg_pin.value() - 1).getSpeed()).c_str()); 
 	}
	else{
	    leg_name.value("");
	    speed.value("0");
	}
	leglast = leg_pin.value();
    }
    static void leg_select(Fl_Widget* w, void* data){
 	((gui_model*)data)->leg_select_i();
    }

    //callback combo to get the torso update
    inline void torso_select_i(){
	if(torso_pin.value() > 0){
	    torso_name.value(storage.getTorso(torso_pin.value() - 1).getName().c_str());
	    bats = storage.getTorso(torso_pin.value() - 1).getBSpace();
	    bspace.value(to_string(bats).c_str());
	    if(bats > 1 && bat1_pin.value() != 0){
		bat2_name.activate();
		bat2_pin.activate();
	        if(bats > 2 && bat2_pin.value() != 0){
		    bat3_name.activate();
		    bat3_pin.activate();
	        }
	    }
	    if(bats == 1){
		bat2_name.deactivate();
		bat2_pin.deactivate();
		bat3_name.deactivate();
		bat3_pin.deactivate();
	    }
	    if(bats == 2){
		bat3_name.deactivate();
		bat3_pin.deactivate();
	    }
 	}
	else{
	    torso_name.value("");
	    bats = 1;
	    bat2_name.deactivate();
	    bat2_pin.deactivate();	
	    bat3_name.deactivate();
	    bat3_pin.deactivate();	 
	}
	calculatecwl();
	torsolast = torso_pin.value();
    }
    static void torso_select(Fl_Widget* w, void* data){
 	((gui_model*)data)->torso_select_i();
    }

    //callback combo to get the arm1 update
    inline void arm1_select_i(){
	if(arm1_pin.value() > 0){
	    arm1_name.value(storage.getArm(arm1_pin.value() - 1).getName().c_str());
	    arm2_pin.activate();	
	    arm2_name.activate();    
	    if(storage.getArm(arm1_pin.value() - 1).getLaser()){
		arm_laser.label("Arm laser equipped");
	    }
	    else{
		arm_laser.label("");
		if(arm2last != 0){
		    if(storage.getArm(arm2last - 1).getLaser()){
		        arm_laser.label("Arm laser equipped");
		    }
		}
	    }
 	}
	else{
	    arm1_name.value("");
	    arm2_pin.deactivate();
	    arm2_name.deactivate();
	    arm_laser.label("");
	}
	calculatecwl();
	arm1last = arm1_pin.value();
    }
    static void arm1_select(Fl_Widget* w, void* data){
 	((gui_model*)data)->arm1_select_i();
    }

    //callback combo to get the arm2 update
    inline void arm2_select_i(){
	if(arm2_pin.value() > 0){
	    arm2_name.value(storage.getArm(arm2_pin.value() - 1).getName().c_str());
	    if(storage.getArm(arm2_pin.value() - 1).getLaser() && storage.getArm(arm2_pin.value() - 1).getLaser()){
		arm_laser.label("Arm laser equipped");
	    }
	    else if(!storage.getArm(arm1_pin.value() - 1).getLaser()){
		arm_laser.label("");
	    }
 	}
	else{
	    arm2_name.value("");
	}
	calculatecwl();
	arm2last = arm2_pin.value();
    }
    static void arm2_select(Fl_Widget* w, void* data){
 	((gui_model*)data)->arm2_select_i();
    }

    //callback combo to get the bat1 update
    inline void bat1_select_i(){
	if(bat1_pin.value() > 0){
	    bat1_name.value(storage.getBattery(bat1_pin.value() - 1).getName().c_str());
	    if(bats > 1){
	 	bat2_name.activate();	
		bat2_pin.activate();
	    }
	    if(bats > 2 && bat2last != 0){
		bat3_name.activate();
		bat3_pin.activate();
	    }
 	}
	else{
	    bat1_name.value("");
	    bat2_name.deactivate();
	    bat2_pin.deactivate();
	    bat3_name.deactivate();
	    bat3_pin.deactivate();  	
	}
	calculatecwl();
	bat1last = bat1_pin.value();
    }
    static void bat1_select(Fl_Widget* w, void* data){
 	((gui_model*)data)->bat1_select_i();
    }

    //callback combo to get the bat2 update
    inline void bat2_select_i(){
	if(bat2_pin.value() > 0){
	    bat2_name.value(storage.getBattery(bat2_pin.value() - 1).getName().c_str());
	    if(bats > 2){
	 	bat3_name.activate();	
		bat3_pin.activate();
	    }
 	}
	else{
	    bat2_name.value("");
	    bat3_name.deactivate();
	    bat3_pin.deactivate();
	}
	calculatecwl();
	bat2last = bat2_pin.value();
    }
    static void bat2_select(Fl_Widget* w, void* data){
 	((gui_model*)data)->bat2_select_i();
    }

    //callback combo to get the bat3 update
    inline void bat3_select_i(){
	if(bat3_pin.value() > 0){
	    bat3_name.value(storage.getBattery(bat3_pin.value() - 1).getName().c_str());
 	}
	else{
	    bat3_name.value("");
	}
	calculatecwl();
	bat3last = bat3_pin.value();
    }
    static void bat3_select(Fl_Widget* w, void* data){
 	((gui_model*)data)->bat3_select_i();
    }
    

    public:
	gui_model():
	Fl_Window(975, 315, "Rockin Robomodel Maker"),
	refresh(5,5,100,25,"Refresh"),
	torso_name(110,35,125,25, "Torso"),
	head_name(110,65,125,25, "Head"),
	leg_name(110,95,125,25, "Leg"),
	arm1_name(110,125,125,25, "Arm 1"),
	arm2_name(110,155,125,25, "Arm 2"),
	bat1_name(110,185,125,25, "Battery 1"),
	bat2_name(110,215,125,25, "Battery 2"),
	bat3_name(110,245,125,25, "Battery 3"),
	torso_pin(240,35,125,25, ""),
	head_pin(240,65,125,25, ""),
	leg_pin(240,95,125,25, ""),
	arm1_pin(240,125,125,25, ""),
	arm2_pin(240,155,125,25, ""),
	bat1_pin(240,185,125,25, ""),
	bat2_pin(240,215,125,25, ""),
	bat3_pin(240,245,125,25, ""),
	name_header(110,5,125,25, "Name"),
	pin_header(240,5,125,25, "SN"),
	stats_header(480,5,100,25, "Stats"),
	div1(370, 5, 5, 270, ""),
	div2(600, 5, 5, 270, ""),
	div3(5, 275, 600, 5, ""),
	bspace(500, 35, 100,25, "Battery Space"),
	speed(500,65,100,25,"Speed (Km\\Hr)"),
	head_laser(400,95,200,25,""),
	arm_laser(400,125,200,25,""),
	activeLife(500,155,100,25,"Active Life (Day)"),
	passiveLife(500,185,100,25,"Passive Life (Day)"),
	cost(500,215,100,25,"Cost (USD)"),
	weight(500,245,100,25,"Weight (Kg)"),
	name(50, 285, 100, 25, "Name"),
	name_error(155, 285, 100, 25, "Needs Name"),
	price(305, 285, 100, 25, "Price"),
	price_error(405, 285, 100,25, "Need Double"),
	MN(625, 285, 100, 25, "Model Number"),
	MN_error(730, 285, 100,25, "Need Integer"),
	description(690, 175, 175, 100, "Description"),
	description_error(590, 175, 125, 25, "Test"),
	create(870, 255, 100, 25, "Create"),
	cancel(870, 285, 100, 25, "Cancel"){
	    div1.box(FL_UP_BOX);
	    div1.color(FL_BLACK);
	    div2.box(FL_UP_BOX);
	    div2.color(FL_BLACK);
	    div3.box(FL_UP_BOX);
	    div3.color(FL_BLACK);
	    name_error.labelcolor(FL_RED);
	    MN_error.labelcolor(FL_RED);
	    description_error.labelcolor(FL_RED);
	    price_error.labelcolor(FL_RED);
	    initialize_choices();
	    cancel.callback(cancel_clicked, this);
	    head_pin.callback(head_select, this);
	    arm1_pin.callback(arm1_select, this);
	    arm2_pin.callback(arm2_select, this);
	    torso_pin.callback(torso_select, this);
	    leg_pin.callback(leg_select, this);
	    bat1_pin.callback(bat1_select, this);
	    bat2_pin.callback(bat2_select, this);
	    bat3_pin.callback(bat3_select, this);
	    refresh.callback(refresh_choices, this);
	}
		
	void reset_values(){
	     refresh_choices_i();
	     torso_name.value("");
	     arm1_name.value("");
	     arm2_name.value("");
	     arm2_name.deactivate();
	     bat1_name.value("");
	     bat2_name.value("");
	     bat2_name.deactivate();
	     bat3_name.value("");
	     bat3_name.deactivate();
	     head_name.value("");
	     leg_name.value("");

	     torso_pin.value(0);
	     arm1_pin.value(0);
	     arm2_pin.value(0);
	     arm2_pin.deactivate();
	     bat1_pin.value(0);
	     bat2_pin.value(0);
	     bat2_pin.deactivate();
	     bat3_pin.value(0);
	     bat3_pin.deactivate();
	     head_pin.value(0);
	     leg_pin.value(0);

             bspace.value("1");
	     speed.value("0");
	     head_laser.label("");
	     arm_laser.label("");
	     activeLife.value("0");
	     passiveLife.value("0");
	     cost.value("0");
	     weight.value("0");

	     name.value("");
	     description.value("");
	     MN.value("");
	     price.value("");

    	     headlast = 0;
    	     leglast = 0;
             torsolast = 0;
    	     arm1last = 0;
    	     arm2last = 0;
    	     bat1last = 0;
    	     bat2last = 0;
    	     bat3last = 0;

	     charge = 0;
	     wei = 0;
	     cos = 0;
	     pass = 0;
    	     act = 0;
 	     
	     arm2was = false;
	     bat2was = false;
	     bat3was = false;

	     bats = 1;
	}

};
#endif 
