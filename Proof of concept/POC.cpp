#include <iostream>
using namespace std;

int main (){
bool USER = false;
bool ADMIN = false;

string user1 = "user1";
string pass1 = "pass1";

string user2 = "user2";
string pass2 = "pass2";

string user;
string pass;

cout<<"Enter Username and password: ";
	cin>>user>>pass;
	
	if (user==user1 && pass == pass1)
	{
		cout<<"Admin!";
		USER = true;
		
	}
	
	else if (user==user2 && pass==pass2)
	{
		cout<<"Banker! ";
		ADMIN = true;
	}
	
	else
	{
		if (ADMIN != true || USER != true);
		cout<<"Invalid user ";
	}
}

