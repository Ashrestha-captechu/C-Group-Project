#include <iostream>
#include "Person.h"
#include "Banker.h"
#include "Admin.h"
#include "Customer.h"
#include <fstream>
#include <stddef.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int createAdminMenu()
{
	int choice;
	system("CLS"); //clear screen 
	cout<<"Create New Admins\n"
		<<"*****************\n\n"
		<<"1. Create a new admin\n"
		<<"2. Save to file\n"
		<<"3. Exit\n"
		<<"Enter your choice: ";
	cin >>choice;
	return choice;
}


string retrieve_saved_file(Person* personPTR[100], Admin* adminPTR[100])
{   string first;
	string last;
	string id;
	string user;
	string pass;
	int personCounter;
	int adminCounter;

	ifstream readData; //create an instance of ifstream
	int count=0; //initialize count to zero
	readData.open("Admin.txt"); //open Admin.txt file
	while(!readData.eof()) //read while not End OF File
	{
		readData>>first
				>>last
				>>id
				>>user
				>>pass;				
				count++; //increment the count
    }
	readData.close(); //close the file
	cout<<first<<" "<<last<<" "<<id<<" "<<user<<" "<<pass;
	
//	return count; //return the count to main to add to current number of clients 
}

int main(int argc, char** argv) {
	
	Person* personPTR[100]; //array of poiters of type Person
	Banker* bankerPTR[100]; //array of pointers of type Banker
	Admin* adminPTR[100]; //array of pointers of type Admin
	Customer* customPTR[100]; //array of pointers of type customer
	string fname,lname, id, user, pass; //variables to store name, id, username and password 
	int admCounter = 0;
	int persCounter = 0;
	string savedData;
	int option;
	
	retrieve_saved_file();
	system("pause");
	
	
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
				file.open("Admin.txt", ios::app);
				for (int i = 0; i < persCounter; i++)
				{
					file<<adminPTR[i]->getFirst()<<" "
						<<adminPTR[i]->getLast()<<" "
						<<adminPTR[i]->getId()<<" "
						<<adminPTR[i]->getUser()<<" "
						<<adminPTR[i]->getPass()<<" ";
				}
				file.close();
			}
		}while(option != 3);
		
		
		
			
	
	
	
	
	return 0;
}
