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


int adminMenu()
{
	int choice;
	system("CLS"); //clear screen 
	cout<<"Admin Menu\n"
		<<"**********\n\n"
		<<"1. Create Banker\n"
		<<"2. View Logs\n"
		<<"3. Exit\n"
		<<"Enter Your Choice: ";
	cin >>choice;
	return choice;
}

int bankerMenu()
{
	int choice;
	system("CLS"); //clear screen 
	cout<<"Banker Menu\n"
		<<"***********\n\n"
		<<"1. Transaction\n"
		<<"2. View Logs\n"
		<<"3. Create Customers\n"
		<<"4. Exit\n"
		<<"Enter Your Choice: ";
	cin >>choice;
	return choice;
}

int customerMenu()
{
	int choice;
	system("CLS"); //clear screen 
	cout<<"Customer Menu\n"
		<<"*************\n\n"
		<<"1. Withdraw\n"
		<<"2. Deposit\n"
		<<"3. Exit\n"
		<<"Enter Your Choice: ";
	cin >>choice;
	return choice;
}

void save_to_file(Person* personPTR[100], int persCounter)
{
	ofstream file;
	file.open("Users.txt", ios::app);
	for (int i = 0; i < persCounter; i++)
	{
		file<<personPTR[i]->getType()<<" "
			<<personPTR[i]->getFirst()<<" "
			<<personPTR[i]->getLast()<<" "
			<<personPTR[i]->getId()<<" "
			<<personPTR[i]->getUser()<<" "
			<<personPTR[i]->getPass()<<"\n";
			
	}
	file.close();
}



int retrieve_saved_file(Person* personPTR[100], int personCounter)
{   
	string type;
	string first;
	string last;
	string id;
	string user;
	string pass;
	double check;
	double save;
	personCounter = 0;
	ifstream readData; //create an instance of ifstream
	readData.open("Users.txt"); //open Admin.txt file
	while(!readData.eof()) //read while not End OF File
	{
		readData>>type
				>>first
				>>last
				>>id
				>>user
				>>pass;
		if (type == "Admin")
		{
			Admin* a = new Admin;
			a->setName(first, last);
			a->setId(id);
			a->setUser(user);
			a->setPass(pass);
			personPTR[personCounter] = a;
			personCounter++; //increment the count
		}
		else if (type == "Banker")
		{
			Banker* a = new Banker;
			a->setName(first, last);
			a->setId(id);
			a->setUser(user);
			a->setPass(pass);
			personPTR[personCounter] = a;
			personCounter++; //increment the count
		}
		else if (type == "Customer")
		{
			readData>>check>>save;
			Customer* a = new Customer;
			a->setName(first, last);
			a->setId(id);
			a->setUser(user);
			a->setPass(pass);
			a->setCheck(check);
			a->setSave(save);
			personPTR[personCounter] = a;
			personCounter++; //increment the count
		}

    }
	readData.close(); //close the file
	return personCounter;
//	return count; //return the count to main to add to current number of clients 
}

int createBanker(Person* personPTR[100], int persCounter)
{
	string fname, lname, id, user, pass;
	
	cout<<"Enter first and last names: ";
	cin >>fname>>lname;
	cout<<"Enter id: ";
	cin >>id;
	cout<<"Enter username: ";
	cin >>user;
	cout<<"Enter Password: ";
	cin >>pass;
				
	Banker* bank = new Banker;
	bank->setName(fname,lname);
	bank->setId(id);
	bank->setUser(user);
	bank->setPass(pass);
	personPTR[persCounter] = bank;
	//persCounter++;
	ofstream file;
	file.open("Users.txt", ios::app);
	file<<personPTR[persCounter]->getType()<<" "
		<<personPTR[persCounter]->getFirst()<<" "
		<<personPTR[persCounter]->getLast()<<" "
		<<personPTR[persCounter]->getId()<<" "
		<<personPTR[persCounter]->getUser()<<" "
		<<personPTR[persCounter]->getPass()<<"\n";
	file.close();
	return persCounter;
	
}
int createCustomer(Person* personPTR[100], int persCounter)
{
	string fname, lname, id, user, pass;
	double check = 0.0;
	double save = 0.0;
	
	cout<<"Enter first and last names: ";
	cin >>fname>>lname;
	cout<<"Enter id: ";
	cin >>id;
	cout<<"Enter username: ";
	cin >>user;
	cout<<"Enter Password: ";
	cin >>pass;
	cout<<"Enter Checking Balance: ";
	cin >>check;
	cout<<"Enter Saving Balance: ";
	cin >>save;
				
	Customer* custom = new Customer;
	custom->setName(fname,lname);
	custom->setId(id);
	custom->setUser(user);
	custom->setPass(pass);
	custom->setCheck(check);
	custom->setSave(save);
	personPTR[persCounter] = custom;
	ofstream file;
	file.open("Users.txt", ios::app);
	file<<personPTR[persCounter]->getType()<<" "
		<<personPTR[persCounter]->getFirst()<<" "
		<<personPTR[persCounter]->getLast()<<" "
		<<personPTR[persCounter]->getId()<<" "
		<<personPTR[persCounter]->getUser()<<" "
		<<personPTR[persCounter]->getPass()<<" "
		<<custom->getCheck()<<" "
		<<custom->getSave()<<"\n";
		
	file.close();
	return persCounter;
	
}



int main(int argc, char** argv) {
	
	Person* personPTR[100]; //array of poiters of type Person
	
	string fname,lname, id, user, pass; //variables to store name, id, username and password 
	int persCounter = 0;

	int option;
	int adminChoice, bankerChoice, customerChoice; //stores user input from menu
	
	persCounter = retrieve_saved_file(personPTR, persCounter);
	
		
	bool NO_ADMIN = false;
	if (persCounter == 0)
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
				NO_ADMIN = false;
				persCounter++;
			}
			if (option == 2)
			//save to file
			save_to_file(personPTR, persCounter);
		}while(option != 3);
		
	//Login Screen
	
	cout<<"\t\tLOG IN\n"
		<<"\t\t``````\n"
		<<"Enter User Name: ";
	cin >>user;
	cout<<"Enter Password: ";
	cin>>pass;
	
	for (int i= 0; i < persCounter; i++)
	{
		if (personPTR[i]->getUser() == user && personPTR[i]->getPass() == pass)
		
		{
			cout<<"Access granted!\n";
			if (personPTR[i]->getType() == "Admin")
			{
				//admin menu
				do{
					adminChoice = adminMenu();
					switch (adminChoice)
					{
						case 1:persCounter = createBanker(personPTR, persCounter);
							persCounter++;
							break;
						case 2: //view logs *under construction*
							break;
						case 3: cout<<"Goodbye!"<<endl;//exit
							break;
						default: cout<<"Invalid choice";
					}
				}while(adminChoice != 3);
			}
			
			else if (personPTR[i]->getType() == "Banker")
			{
				//Banker menu
				do{
					bankerChoice = bankerMenu();
					switch (bankerChoice)
					{
						case 1:	//transaction						
							break;
						case 2: //view logs
							break;
						case 3: persCounter = createCustomer(personPTR, persCounter);//create customers
						persCounter++;
							break;
						case 4: cout<<"Goodbye!"<<endl; //exit
							break;
						default: cout<<"Invalid choice";
					}					
				}while(bankerChoice != 4);
			}
			else if (personPTR[i]->getType() == "Customer")
			{
				//customer menu
				do{
					customerChoice = customerMenu();
				}while(customerChoice != 3);
			}
			break; //exit out of the loop
		}
		else if (personPTR[i]->getUser() != user || personPTR[i]->getPass() != pass) //if the user or password is incorrect, displays message
		{
			cout<<"Wrong Username and/or Password"<<endl;
		}
		
	}
	
	
	
	
	
	return 0;
}
