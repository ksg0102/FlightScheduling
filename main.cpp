/*
Kevin Gonzalez
kevingonzalez2@my.unt.edu
CSCE 1040 - Computer Science II - Section 001
November 26, 2018

Brief Description:
The goal of this program is to build a flight management system.
This flight management system is able to: add planes, add crew members, add flights, as well as, 
manipulate, edit and remove the aforementioned.
*/

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "planedata.h"
#include "planecollections.h"
#include "crewdata.h"
#include "crewcollections.h"
#include "flightdata.h"
#include "flightcollections.h"

Planes plane; //object created to access class Plane data members
Crews crew; //object created to access class Crew data members
Flights flight; //object created to access class Flight data members

void storedata()
{
	plane.storeplanes();
	crew.storecrew();
	flight.storeflights();
	cout << "Data stored." << endl;
}

void loaddata()
{
	plane.loadplanes();
	crew.loadcrew();
	flight.loadflights();
	cout << "Data loading complete." << endl;
	cout << endl;
}

int main()
{
	cout << endl;
	cout << "+----------------------------------------------------+" << endl;
	cout << "|	   Computer Science and Engineering	     |" << endl;	
	cout << "|	    CSCE 1040 - Computer Science II          |" << endl;
	cout << "| Kevin Gonzalez  ksg0102  kevingonzalez2@my.unt.edu |" << endl;
	cout << "+----------------------------------------------------+" << endl;
	cout << endl;
	
	loaddata();
	
	int choice;
	bool exit = true;
	
	while(exit != false)
	{
		cout << "Please enter a number (1-15) to choose from the main menu options: " << endl;
		cout << endl;
		cout << "1. Add a new plane" << endl;
		cout << "2. Add a new crew member" << endl;
		cout << "3. Add a new flight" << endl;
		cout << "4. Print list of all planes" << endl;
		cout << "5. Print list of all crew members" << endl;
		cout << "6. Print list of all flights" << endl;
		cout << "7. Edit plane entries" << endl; //create sub menu
		cout << "8. Edit crew member entries" << endl; //create sub menu
		cout << "9. Edit flight entries" << endl; //create sub menu
		cout << "10. Cancel a flight" << endl;
		cout << "11. Print schedule for a plane(active assignments)" << endl; //print active assignments
		cout << "12. Print schedule for a crew member(active assignments)" << endl; //print active assignments
		cout << "13. Print flight schedules" << endl; // create sub menu, print active, completed, canceled
		cout << "14. Delete all canceled flights" << endl;
		cout << "15. Delete all completed flights" << endl;
		cout << "16. Quit" << endl;
		
		cin >> choice;
		cin.ignore();
		if(cin.fail()) //checks to see if there is an error in cin
		{
			cout << endl;
			cout << "Entry invalid." << endl;
			cin.clear(); //clears error
			cin.ignore(10000, '\n'); //ignores everything in cin stream
		}
		
		switch(choice)
		{
			case 1:
				plane.addplane();
				exit = true;
			break;
		
			case 2:
				crew.addcrew();
				exit = true;
			break;
			
			case 3:
				flight.addflight();
				exit = true;
			break;
			
			case 4:
				plane.printplanes();
				exit = true;
			break;
			
			case 5:
				crew.printcrew();
				exit = true;
			break;
			
			case 6:
				flight.printflights();
				exit = true;
			break;
			
			case 7:
			{
				int h;
				bool e = true;
				while(e != false)
				{
					cout << endl;
					cout << "Please enter a number (1-5) to choose from the edit plane menu options: " << endl;
					cout << endl;
					cout << "1. Delete last entry" << endl;
					cout << "2. Change specific value of an entry(change make, model, tailnum, etc. using tail number)" << endl;
					cout << "3. Delete an entry(using tail number)" << endl;
					cout << "4. Delete all plane entries" << endl;
					cout << "5. Quit to main menu" << endl;
					cin >> h;
					cin.ignore();
					if(cin.fail()) //checks to see if there is an error in cin
					{
						cout << endl;
						cout << "Invalid entry." << endl;
						cin.clear(); //clears error
						cin.ignore(10000, '\n'); //ignores everything in cin stream
					}
					switch(h)
					{
						case 1:
							plane.deletelastentry();
							e = true;
						break;
						
						case 2:
							plane.changespecificvalue();
							e = true;
						break;
						
						case 3:
							plane.deleteanentry();
							e = true;
						break;
						
						case 4:
							plane.deleteallentries();
							e = true;
						break;
						
						case 5:
							cout << endl;
							e = false; //quit case
						break;
						
						default:
							cout << endl;
							cout << "Selection not in menu. Enter again." << endl;
							e = true;
						break;
					}
				}
				exit = true;
			}
			break;
			
			case 8:
			{
				int a;
				bool x = true;
				while(x != false)
				{
					cout << endl;
					cout << "Please enter a number (1-5) to choose from the edit crew member menu options: " << endl;
					cout << endl;
					cout << "1. Delete last entry" << endl;
					cout << "2. Change specific value of an entry(change name, type, etc. using ID number)" << endl;
					cout << "3. Delete an entry(using ID number)" << endl;
					cout << "4. Delete all crew member entries" << endl;
					cout << "5. Quit to main menu" << endl;
					cin >> a;
					cin.ignore();
					if(cin.fail()) //checks to see if there is an error in cin
					{
						cout << endl;
						cout << "Invalid entry." << endl;
						cin.clear(); //clears error
						cin.ignore(10000, '\n'); //ignores everything in cin stream
					}
					switch(a)
					{
						case 1:
							crew.deletelastentry();
							x = true;
						break;
						
						case 2:
							crew.changespecificvalue();
							x = true;
						break;
						
						case 3:
							crew.deleteanentry();
							x = true;
						break;
						
						case 4:
							crew.deleteallentries();
							x = true;
						break;
						
						case 5:
							cout << endl;
							x = false; //quit case
						break;
						
						default:
							cout << endl;
							cout << "Selection not in menu. Enter again." << endl;
							x = true;
						break;
					}
				}
				exit = true;
			}
			break;
			
			case 9:
			{
				int b;
				bool i = true;
				while(i != false)
				{
					cout << endl;
					cout << "Please enter a number (1-5) to choose from the edit flight menu options: " << endl;
					cout << endl;
					cout << "1. Delete last entry" << endl;
					cout << "2. Change specific value of an entry(change ID's, departure/land date/time etc. using flight ID)" << endl;
					cout << "3. Delete an entry(using flight ID)" << endl;
					cout << "4. Delete all flight entries" << endl;
					cout << "5. Quit to main menu" << endl;
					cin >> b;
					cin.ignore();
					if(cin.fail()) //checks to see if there is an error in cin
					{
						cout << endl;
						cout << "Invalid entry." << endl;
						cin.clear(); //clears error
						cin.ignore(10000, '\n'); //ignores everything in cin stream
					}
					switch(b)
					{
						case 1:
							flight.deletelastentry();
							i = true;
						break;
						
						case 2:
							flight.changespecificvalue();
							i = true;
						break;
						
						case 3:
							flight.deleteanentry();
							i = true;
						break;
						
						case 4:
							flight.deleteallentries();
							i = true;
						break;
						
						case 5:
							cout << endl;
							i = false; //quit case
						break;
						
						default:
							cout << endl;
							cout << "Selection not in menu. Enter again." << endl;
							i = true;
						break;
					}
				}
				exit = true;
			}
			break;
			
			case 10:
				flight.cancelflight();
				exit = true;
			break;
			
			case 11:
				flight.printplaneschedule();
				exit = true;
			break;
			
			case 12:
				flight.printcrewschedule();
				exit = true;
			break;
			
			case 13:
			{
				int ch;
				bool t = true;
				while(t != false)
				{
					cout << endl;
					cout << "Please enter a number (1-4) to choose from the print flight schedule menu options: " << endl;
					cout << endl;
					cout << "1. Print active flights" << endl;
					cout << "2. Print completed flights" << endl;
					cout << "3. Print canceled flights" << endl;
					cout << "4. Quit to main menu" << endl;
					cin >> ch;
					cin.ignore();
					if(cin.fail()) //checks to see if there is an error in cin
					{
						cout << endl;
						cout << "Entry invalid." << endl;
						cin.clear(); //clears error
						cin.ignore(10000, '\n'); //ignores everything in cin stream
					}
					switch(ch)
					{
						case 1:
							flight.printflightsbystatus(ch);
							t = true;
						break;
						
						case 2:
							flight.printflightsbystatus(ch);
							t = true;
						break;
						
						case 3:
							flight.printflightsbystatus(ch);
							t = true;
						break;
						
						case 4:
							cout << endl;
							t = false; //quit case
						break;
						
						default:
							cout << endl;
							cout << "Selection not in menu. Enter again." << endl;
							t = true;
						break;
					}
				}
				exit = true;
			}
			break;
			
			case 14:
				flight.deletecanceledflights();
				exit = true;
			break;
			
			case 15:
				flight.deletecompletedflights();
				exit = true;
			break;
			
			case 16:
				exit = false; //quit case
			break;

			default:
				cout << endl;
				cout << "Selection not in menu. Enter again." << endl;
				cout << endl;
				exit = true;
			break;
		}
	}
	
	cout << endl;
	cout << "Program ended." << endl;
	
	storedata(); //store data

	plane.cleanup(); //.clear() vector lists
	crew.cleanup();
	flight.cleanup();
	
return 0;
}
	