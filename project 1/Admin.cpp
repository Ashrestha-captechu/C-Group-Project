//Admin.cpp
#include"Admin.h"

//default constructor
Admin::Admin(){
	setType("Admin");
}


//displays all the information about the Admin 
void Admin::print(){
	cout <<"This "<<type<<" has this information:\n"
		 <<"Name: "<<first_name<<" "<<last_name<<"\n"
		 <<"Id: "<<id<<"\n"
		 <<"Username: "<<user<<endl;
}
