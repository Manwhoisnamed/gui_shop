//maxwell Sanders 1001069652
//this is the file that holds my global variables, really just my storage and database

#include "Storage.h"
#include "Database.h"
#include <ctype.h>

#ifndef __globals_H
#define __globals_H 2016

Storage storage;
Database database;
int currentpin;

bool isInt(const char* word){
    int len = strlen(word);
    if(len == 0){
 	return false;
    }
    for(int i = 0; i < len; i ++){
	if(!isdigit(word[i])){
	    return false;
	}
    }	
    return true;
}

bool isDouble(const char* word){
    int len = strlen(word);
    bool comma = false;
    if(len == 0){
 	return false;
    }
    if(word[0] == '.'){
	return false;
    }
    for(int i = 0; i < len; i ++){
	if(!(isdigit(word[i])||word[i]=='.')){
	    return false;
	}
	if(word[i] == '.'){
	    if(comma == true){
		return false;
	    }
	    else{
		comma = true;
	    }
	}
    }	
    return true;
}

#endif
