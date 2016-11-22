//maxwell sanders 1001069652
//this is the main file

#include "globals.h"
#include "father.h"
#include <iostream>

int main(void){
    storage.load();
    database.loadData(storage);
    father father_win;
    father_win.show();
    (father_win.child(0))->show();
    Fl::run();
}
