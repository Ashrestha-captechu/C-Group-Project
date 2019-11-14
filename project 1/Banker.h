//Banker.h
#include<iostream>
#include"Person.h"
using namespace std;
#ifndef BANKER_H
#define BANKER_H

class Banker: public Person{
	private:
		
	public:
		Banker();
		void print();//displayes all the information about the Banker	
	
};
#endif
