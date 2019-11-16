//Customer.cpp
#include"Customer.h"
//default constructor
Customer::Customer(){
	setType("Customer");
	setCheck(0);
	setSave(0);
	
}

void Customer::setCheck(double check){
	checking = check;
}

void Customer::setSave(double save){
	saving = save;
}


//displayes all the  information about the Customer
void Customer::print(){
	cout <<"This "<<type<<" has this information:\n"
		<<"Name: "<<first_name<<" "<<last_name<<"\n"
		<<"Id: "<<id<<"\n"
		<<"Username: "<<user<<endl;
}
