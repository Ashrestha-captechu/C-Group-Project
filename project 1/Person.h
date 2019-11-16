 //Person.h
#include<iostream>
#include<string>
using namespace std;
#ifndef PERSON_H
#define PERSON_H
class Person //main class 
{
	protected: //class attributes shared by all child classes
		string first_name; //stores first name
		string last_name; //sotres last name
		string type; //stores type of class 
		string id; //stores id
		string user; //store username 
		string pass; //store password
	public:
		Person(); // default constructor 
		void setName(string, string); //shared function to set name
		void setId(string);// shared function to set id
		void setType(string); //shared function to determine type of class
		void setUser(string); //shared function to set username 
		void setPass(string); //shared function to set password
		string getFirst(); //return first name
		string getLast(); //return last name
		string getId(); //return id
		string getUser();//return username
		string getPass();//return password
		string getType();//return type
		virtual void print() = 0 ; //virtual function to display information of the class. NOTE: the function is set to equalt zero making this a fully abstract class
		
};

#endif
