//maxwell Sanders 1001069652
//this is a test file

#include <Fl/Fl.H>
#include <Fl/Fl_Group.H>
#include <Fl/Fl_Box.H>

#ifndef __testGroup_H
#define __testGroup_H 2016
class testGroup : public Fl_Group{
	Fl_Box test;	

    public:
	testGroup():
	Fl_Group(50,50,500,500),
	test(100,100,100,25, "Hello, I think this might work"){
	}
};
#endif
