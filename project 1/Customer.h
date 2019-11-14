//Customer.h
#include<iostream>
#include"Person.h"
using namespace std;
#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer: public Person{
	private:
		double checking;
		double saving;
	public:
		Customer();
		void print();//displayes all the information about the Customer
		void setCheck;
		void setSave;
	
};
#endif
