//maxwell Sanders
//this file is the associate viewer

#ifndef __view_all_SA_H
#define __view_all_SA_H 2016
class view_all_SA : public Fl_Group{
	Fl_Button refresh;
	Fl_Button up;
	Fl_Button down;
	Fl_Output name;
	Fl_Output SN;
	Fl_Output cost;
	Fl_Box part;
	Fl_Choice SN_choice;
	int size = 0;
	int i = 0;

	void initialize_choices(){
	    size = database.getAssociateSize();
	    for(int x = 0; x < size; x ++){
		SN_choice.add((database.loadAssociate(x).getName() + " - " + to_string(database.loadAssociate(x).getPin())).c_str());
	    }
	}

	inline void select_i(){
	    i = SN_choice.value();
	    if(i == 0){
		up.deactivate();
	    }
	    else{
		up.activate();
	    }
	    if(i == size - 1){
		down.deactivate();
	    }	
	    else{
		down.activate();
	    }
	    popfields();
	}
	static void select(Fl_Widget* w, void * data){
	    ((view_all_SA*)data)->select_i();
	}

 	void popfields(){
	    string sSN;
	    string scost;
	    
	    name.value((database.loadAssociate(i)).getName().c_str());
	    sSN = to_string((database.loadAssociate(i)).getPin());
	    scost = to_string((database.loadAssociate(i)).getWage());
	    SN.value(sSN.c_str());
	    cost.value(scost.c_str());
	}

	inline void down_clicked_i(){
	    i++;
	    SN_choice.value(i);
	    if(i == database.getAssociateSize() - 1){
		down.deactivate();
	    }
	    up.activate();
	    popfields();
	};
	static void down_clicked(Fl_Widget* w, void* data){
	    ((view_all_SA*)data)->down_clicked_i();
	};

	inline void up_clicked_i(){
	    i--;
	    SN_choice.value(i);
	    if(i == 0){
		up.deactivate();
	    }
	    down.activate();
	    popfields();
	};
	static void up_clicked(Fl_Widget* w, void* data){
	    ((view_all_SA*)data)->up_clicked_i();
	};

	//for the refresh button, if someone builds a part and the down is deactivate then this will fix it
        inline void refresh_clicked_i(){
	    if(database.getAssociateSize() > i + 1){
		down.activate();
	    }
	    if(size < database.getAssociateSize()){
		for(int x = size; x < database.getAssociateSize(); x++){
		    SN_choice.add(((database.loadAssociate(x)).getName() + " - " + to_string((database.loadAssociate(x)).getPin())).c_str());
		}
	    }
	    size = database.getAssociateSize();
	};
	static void refresh_clicked(Fl_Widget* w, void* data){
	    ((view_all_SA*)data)->refresh_clicked_i();
	};

    public:
	view_all_SA():
	Fl_Group(0,0,1000,700),
	refresh(105, 40, 175, 25, "Refresh"),
	up(105,70,175,25,"@8>"),
	down(105, 130, 175, 25, "@2>"),
	name(400, 100, 200, 25, "Name"),
	SN(400, 130, 200, 25, "Pin"),
	cost(400, 160, 200, 25, "Wage (USD)"),
	part(450, 30, 100, 25, "Viewing Associates"),
	SN_choice(105, 100, 175, 25, "Part Selector"){
	    reset_values();
	    up.deactivate();
	    up.callback(up_clicked,this);
	    down.callback(down_clicked,this);
	    if(database.getAssociateSize() == 1){
	        down.deactivate();
	    }
	    refresh.callback(refresh_clicked, this);
	    initialize_choices();
	    SN_choice.callback(select,this);
	}

	void reset_values(){
	    i = 0;
	    SN_choice.value(0);
	    up.deactivate();

	    if(database.getAssociateSize() == 1){
	        down.deactivate();
	    }
	    if(database.getAssociateSize() >= 1){
		popfields();
	    }
	    else{
	 	name.value("");
	 	SN.value("");
	 	cost.value("");
	    }
	}
};
#endif
