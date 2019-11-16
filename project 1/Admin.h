//Admin.h
#include<iostream>
#include"Person.h"
using namespace std;
#ifndef ADMIN_H
#define ADMIN_H
class Admin: public Person{
	private:
		
	public:
		Admin();//default constructor
		
		
		void print(); //displays all the informatioin of the Admin
};
#endif
