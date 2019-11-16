//createAdmin.cpp
#include "Person.h"
#include "Admin.h"
#include <fstream>
#include <stddef.h>

int createAdminMenu()
{
	int choice;
	system("CLS"); //clear screen 
	cout<<"Create New Admins\n"
		<<"*****************\n\n"
		<<"1. Create a new admin\n"
		<<"2. Exit\n"
		<<"Enter your choice";
	cin >>choice;
	return choice;
}

int main(int argc, char** argv) {
	
	Person* personPTR[100];
	Admin* adminPTR[100];
	int admCounter = 0;
	int persCounter = 0;
	string fname, lname, id, user, pass;
	int option;
	do{
		option =  createAdminMenu();
		if (option == 1)
		{
			Admin* adm = new Admin; //create new admin
			cout<<"Enter First and last name:"; //prompt and store first and last names
			cin >>fname>>lname; 
			cout<<"\nEnter Id: "; //prompt and store id
			cin >>id;
			cout<<"\nCreate Username: "; //prompt and store username
			cin >>user;
			cout<<"\nDefine Password: "; //prompt and store password
			cin >>pass;
			
			adm -> setName(fname, lname);
			adm -> setId(id);
			adm -> setUser(user);
			adm -> setPass(pass);
			personPTR[persCounter] = adm;
			adminPTR[admCounter] = adm;
			persCounter++;
			admCounter++;
		}
	}while(option != 2);
		
	
	

		


	return 0;
}
