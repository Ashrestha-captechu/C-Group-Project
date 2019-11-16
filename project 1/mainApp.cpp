#include <iostream>
#include "Person.h"
#include "Banker.h"
#include "Admin.h"
#include "Customer.h"
#include <fstream>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int createAdminMenu()
{
	int choice;
	system("CLS"); //clear screen 
	cout<<"Create New Admins\n"
		<<"*****************\n\n"
		<<"1. Create a new admin\n"
		<<"2. Save to file"
		<<"3. Exit\n"
		<<"Enter your choice: ";
	cin >>choice;
	return choice;
}


int main(int argc, char** argv) {
	
	Person* personPTR[100]; //array of poiters of type Person
	Banker* bankerPTR[100]; //array of pointers of type Banker
	Admin* adminPTR[100]; //array of pointers of type Admin
	Customer* customPTR[100]; //array of pointers of type customer
	string fname,lname, id, user, pass; //variables to store name, id, username and password 
	int admCounter = 0;
	int persCounter = 0;
	
	int option;
	bool NO_ADMIN = false;
	if (admCounter == 0)
		NO_ADMIN = true;
	
	if (NO_ADMIN == true)
		do{
			option =  createAdminMenu();
			if (option == 1)
			{
				Admin* adm = new Admin; //create new admin
				cout<<"Enter First and last name: "; //prompt and store first and last names
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
				NO_ADMIN = false;
				persCounter++;
				admCounter++;				
			}
			if (option == 2)
			//save to file
			{
				ofstream file;
				file.open("Admin.txt");
				for (int i = 0; i < persCounter; i++)
				{
					file<<adminPTR->getFirst()<<" "
						<<adm->getLast()<<" "
						<<adm->getId()<<" "
						<<adm->getUser()<<" "
						<<adm->getPass()<<" "
					adm++;
				}
				file.close();
			}
		}while(option != 3);
		
		
		
			
	
	
	
	
	return 0;
}
