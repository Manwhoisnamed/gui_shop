//maxwell Sanders 1001069652
//this is the file to view the arm

#include <Fl/Fl.H>
#include <Fl/Fl_Group.H>
#include <Fl/Fl_Box.H>

#ifndef __view_arm_H
#define __view_arm_H 2016
class view_arm : public Fl_Group{
	Fl_Box test;	

    public:
	view_arm():
	Fl_Group(50,50,500,500),
	test(100,100,100,25, "Hello, I think this might work"){
	}
};
#endif
