//Person.cpp
#include"Person.h"
Person::Person(){
	setName("",""); //initialize name 
	setId(""); //initialize age to zero
}

//sets the first and last names to the strings passed to the function
void Person::setName(string fname, string lname){
	first_name = fname;
	last_name = lname;
}

//sets the Id to the string passed to the function
void Person::setId(string id){
	this -> id = id;
}

//sets the type of the class
void Person::setType(string type)
{
	this -> type = type;
}

//sets the username
void Person::setUser(string username)
{
	user = username;
}

//sets the password
void Person::setPass(string password)
{
	pass = password;
}

string Person::getFirst()
{
	return first_name;
}

string Person::getLast()
{
	return last_name;
}

string Person::getId()
{
	return id;
}     

string Person::getUser()
{
	return user;
}

string Person::getPass()
{
	return pass;
}

string Person::getType()
{
	return type;
}
