//Customer.cpp
#include"Customer.h"
//default constructor
Customer::Customer(){
	setType("Customer");
	setCheck(0);
	setSave(0);
	
}

Customer::setCheck(double checking){
	check = checking;
}

Customer::setSave(double saving){
	save = saving;
}


//displayes all the  information about the Customer
void Customer::print(){
	cout <<"This "<<type<<" has this information:\n"
		<<"Name: "<<first_name<<" "<<last_name<<"\n"
		<<"Id: "<<id<<"\n"
		<<"Username: "<<user<<endl;
}
