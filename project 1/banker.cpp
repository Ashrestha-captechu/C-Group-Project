//Banker.cpp

#include"Banker.h"
//default constructor
Banker::Banker(){
	setType("Banker");
}



//displayes all the  information about the Banker
void Banker::print(){
	cout <<"This "<<type<<" has this information:\n"
		<<"Name: "<<first_name<<" "<<last_name<<"\n"
		<<"Id: "<<id<<"\n"
		<<"Username: "<<user<<endl;
}
