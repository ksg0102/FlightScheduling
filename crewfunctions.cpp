#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <typeinfo> //must include typeinfo to use typeid
using namespace std;

#include "crewdata.h"
#include "crewcollections.h"

bool sortbyname (Crewdata* c1, Crewdata* c2)
{
	return c1->getname() < c2->getname();
}

void Crews::addcrew()
{
	string n; //name
	int id; //id
	int t; // number to choose crew role(pilot, co-pilot, crew)
	string s; //status
	string p; //position for the cabin crew
	string cr; // character rating code for pilot and co-pilot
	int fl; //integer for flight hours for pilot and co-pilot
	Pilot* temp1 = NULL; //**object that will be passed into vector list for pilot class
	CoPilot* temp2 = NULL; //**object that will be passed into vector list for copilot class
	CabinCrew* temp3 = NULL; //**object that will be passed into vector list for cabincrew class

	cout << endl;
	cout << "Please enter ID number of crew member: ";
	cin >> id;
	cin.ignore();
	cout << "Please enter full name of crew member: ";
	getline(cin, n);
	cout << "Please enter a number (1-3) to choose this crew member's role(Pilot = 1, Co-Pilot = 2, Cabin Crew = 3): ";
	cin >> t;
	cin.ignore();

	if(t == 1)
	{
		cout << "Please enter the 5 character rating code for the Pilot: ";
		getline(cin, cr);
		cout << "Please enter the cumulative flight hours as Pilot: ";
		cin >> fl;
		cin.ignore();
	}
	else if(t == 2)
	{
		cout << "Please enter the 4 character rating code for the Co-Pilot: ";
		getline(cin, cr);
		cout << "Please enter the cumulative flight hours as Co-Pilot: ";
		cin >> fl;
		cin.ignore();
	}
	else if(t == 3)
	{
		cout << "Please enter this cabin crew member's position on the plane(ex. FirstClass, BusinessClass, EconomyFront, EconomyRear, Lead): ";
		getline(cin, p);
	}
	cout << "Please enter the status of the crew member(available, on leave, sick): ";
	getline(cin, s);

	if(t == 1)
	{
		temp1 = new Pilot;
		temp1->setname(n);
		temp1->setid(id);
		temp1->setstat(s);
		temp1->setratcode(cr);
		temp1->setflighthours(fl);
		crewlist.push_back(temp1);
		cout << endl << "PILOT SUCCESSFULLY ADDED." << endl;
	}
	else if(t == 2)
	{
		temp2 = new CoPilot;
		temp2->setname(n);
		temp2->setid(id);
		temp2->setstat(s);
		temp2->setratcode(cr);
		temp2->setflighthours(fl);
		crewlist.push_back(temp2);
		cout << endl << "CO-PILOT SUCCESSFULLY ADDED." << endl;
	}
	else if(t == 3)
	{
		temp3 = new CabinCrew;
		temp3->setname(n);
		temp3->setid(id);
		temp3->setstat(s);
		temp3->setposition(p);
		crewlist.push_back(temp3);
		cout << endl << "CABIN CREW MEMBER SUCCESSFULLY ADDED." << endl;
	}

	cout << endl;
	++crewcount;
}

void Pilot::print() //sorted print
{
	cout << "Pilot ID: " << getid() << endl;
	cout << "Pilot name: " << getname() << endl;
	cout << "Pilot status(available, on leave, sick): " << getstat() << endl;
	cout << "Pilot rating code: " << getratcode() << endl;
	cout << "Pilot cumulative flight hours: " << getflighthours() << endl;
	cout << endl;
}

void CoPilot::print() //sorted print
{
	cout << "Co-Pilot ID: " << getid() << endl;
	cout << "Co-Pilot name: " << getname() << endl;
	cout << "Co-Pilot status(available, on leave, sick): " << getstat() << endl;
	cout << "Co-Pilot rating code: " << getratcode() << endl;
	cout << "Co-Pilot cumulative flight hours: " << getflighthours() << endl;
	cout << endl;
}

void CabinCrew::print() //sorted print
{
	cout << "Cabin crew member ID: " << getid() << endl;
	cout << "Cabin crew member name: " << getname() << endl;
	cout << "Cabin crew member status(available, on leave, sick): " << getstat() << endl;
	cout << "Cabin crew member position on the plane: " << getposition() << endl;
	cout << endl;
}

void Crews::printcrew()
{
	cout << endl;
	if(crewlist.empty() == true)
	{
		cout << "NO CREW HAS BEEN ADDED." << endl;
		cout << endl;
		return;
	}

	sort(crewlist.begin(), crewlist.end(), sortbyname);
	cout << endl;
	cout << "****LIST OF ALL CREW MEMBERS****" << endl;
	cout << endl;
	for(int i = 0; i < crewlist.size(); ++i)
	{
		cout << i + 1 << "." << endl;
		crewlist[i]->print();
	}
	cout << "ABOVE IS THE LIST OF ALL CREW MEMBERS SORTED BY FIRST NAME. " << endl;
	cout << endl;
}

void Crews::deletelastentry()
{
	cout << endl;
	if(crewlist.empty() == true)
	{
		cout << "NO CREW MEMBERS HAVE BEEN ADDED." << endl;
		cout << endl;
		return;
	}

	crewlist.pop_back();
	cout << "LAST ENTRY SUCCESSFULLY DELETED." << endl;
}

void Crews::changespecificvalue()
{
	int a; //id number from user
	int b; //menu option
	int match = 0;

	string n;
	int id;
	string t; //holds crew role(pilot, co-pilot, crew)
	string s;

	printcrew(); //calls printcrew() function

	if(crewlist.empty() == true)
	{
		return;
	}

	bool exit = true;
	while(exit != false)
	{
		f1:
		cout << "Please enter ID number of crew member you wish to edit: ";
		cin >> a;
		cin.ignore();
		if(cin.fail())
		{
			cout << endl;
			cout << "INVALID ENTRY. ENTER AGAIN." << endl;
			cin.clear(); //clears error
			cin.ignore(10000, '\n'); //ignores everything in cin stream
			cout << endl;
			goto f1;
		}

		for(int i = 0; i < crewlist.size(); ++i)
		{
			if(crewlist[i]->getid() == a)
			{
				++match;
				m2:
				cout << "Please enter a number (1-5) to choose from the menu options: " << endl;
				cout << endl;
				cout << "1. Update full name of crew member" << endl;
				cout << "2. Update ID number of crew member" << endl;
				//cout << "3. Update role of crew member(pilot, co-pilot, crew)" << endl;
				cout << "3. Update status of crew member(available, on leave, sick)" << endl;
				cout << "4. Quit back to edit plane menu" << endl;

				cin >> b;
				cin.ignore();
				if(cin.fail())
				{
					cout << endl;
					cout << "INVALID ENTRY. ENTER AGAIN." << endl;
					cin.clear(); //clears error
					cin.ignore(10000, '\n'); //ignores everything in cin stream
					cout << endl;
					goto m2;
				}
				if(b == 1)
				{
					cout << endl;
					cout << "Enter new full name: ";
					getline(cin, n);
					crewlist[i]->setname(n);
					cout << endl;
					cout << "Full name successfully updated." << endl;
					cout << endl;
					goto m2;
				}
				if(b == 2)
				{
					cout << endl;
					cout << "Enter new ID number: ";
					cin >> id;
					cin.ignore();
					crewlist[i]->setid(id);
					cout << endl;
					cout << "ID number successfully updated." << endl;
					cout << endl;
					goto m2;
				}
				/*if(b == 3)
				{
					cout << endl;
					cout << "Enter new role(pilot, co-pilot, crew): " << endl;
					getline(cin, t);
					crewlist[i]->settype(t);
					cout << endl;
					cout << "Role successfully updated." << endl;
					cout << endl;
					goto m2;
				}*/
				if(b == 3)
				{
					cout << endl;
					cout << "Enter new status(available, on leave, sick): ";
					getline(cin, s);
					crewlist[i]->setstat(s);
					cout << endl;
					cout << "Status successfully updated." << endl;
					cout << endl;
					goto m2;
				}
				if(b == 4)
				{
					exit = false;
				}
				else
				{
					cout << "INVALID ENTRY. ENTER AGAIN." << endl;
					goto m2;
				}
			}
		}
		if(match == 0)
		{
			cout << endl;
			cout << "ID NUMBER " << a << " DOES NOT EXIST." << endl;
			cout << endl;
			exit = false;
		}
	}
}

void Crews::deleteanentry()
{
	int a; //id number variable
	int match = 0;

	printcrew();
	if(crewlist.empty() == true)
	{
		return;
	}

	bool exit = true;
	while(exit != false)
	{
		f2:
		cout << "Please enter the ID number of the crew member you would like to delete: ";
		cin >> a;
		cin.ignore();
		if(cin.fail())
		{
			cout << endl;
			cout << "Invalid entry. Enter again." << endl;
			cin.clear(); //clears error
			cin.ignore(10000, '\n'); //ignores everything in cin stream
			cout << endl;
			goto f2;
		}

		for(int i = 0; i < crewlist.size(); ++i)
		{
			if(crewlist[i]->getid() == a)
			{
				++match;
				crewlist.erase(crewlist.begin() + i);
				exit = false;
			}
		}
		if(match == 0)
		{
			cout << endl;
			cout << "ID NUMBER " << a << " DOES NOT EXIST." << endl;
			cout << endl;
			exit = false;
		}
	}
	if(match > 0)
	{
		cout << endl << "CREW MEMBER WITH ID NUMBER " << a << " SUCCESSFULLY DELETED." << endl;
	}
}

void Crews::deleteallentries()
{
	if(crewlist.empty() == true)
	{
		cout << endl << "NO CREW MEMBERS HAVE BEEN ADDED." << endl;
		cout << endl;
		return;
	}

	crewlist.clear();
	cout << endl << "ALL CREW MEMBERS HAVE BEEN SUCCESSFULLY DELETED." << endl;
}

void Crews::storecrew()
{
	ofstream fout;

	fout.open("crew.dat");
	fout << crewlist.size() << endl;
	for (int i = 0; i < crewlist.size(); ++i)
    {
        fout << crewlist[i]->getname() << "\t" << crewlist[i]->getid() << "\t" << crewlist[i]->getstat() << "\t";

        if(typeid(*(crewlist[i])) == typeid(Pilot)) //checks if vector at i is of type Pilot, if true
        {
            Pilot *temp1 = dynamic_cast<Pilot*>(crewlist[i]); //dynamic cast checks if vector at i is of type Pilot
			fout << "1" << "\t" << temp1->getratcode() << "\t" << temp1->getflighthours() << endl; //use the pointer object to access the get functions
        }

       else if(typeid(*(crewlist[i])) == typeid(CoPilot)) //checks if vector at i is of type CoPilot, if true
        {
            CoPilot *temp2 = dynamic_cast<CoPilot*>(crewlist[i]); //dynamic cast checks if vector at i is of type CoPilot
			fout << "2" << "\t" << temp2->getratcode() << "\t" << temp2->getflighthours() << endl; //use the pointer object to access the get functions
        }
		else if(typeid(*(crewlist[i])) == typeid(CabinCrew)) //checks if vector at i is of type CabinCrew, if true
        {
            CabinCrew *temp3 = dynamic_cast<CabinCrew*>(crewlist[i]); //dynamic cast checks if vector at i is of type CabinCrew
			fout << "3" << "\t" << temp3->getposition() << endl; //use the pointer object to access the get functions
        }
	}
    fout.close();
}

void Crews::loadcrew()
{
	ifstream fin;
	string n; //name
	int id; //id
	string s; //status
	int type; //integer variable that holds the role of the crew member
	string p; //position for the cabin crew
	string cr; // character rating code for pilot and co-pilot
	int fl; //integer for flight hours for pilot and co-pilot
	Pilot* temp1 = NULL; //**object that will be passed into vector list for pilot class
	CoPilot* temp2 = NULL; //**object that will be passed into vector list for copilot class
	CabinCrew* temp3 = NULL; //**object that will be passed into vector list for cabincrew class

	fin.open("crew.dat");
	fin >> crewcount;
	fin.ignore();
	if(crewcount == 0)
	{
		return;
	}

	for(int i = 0; i < crewcount; ++i)
	{
		getline(fin, n, '\t');
		fin >> id;
		fin.ignore();
		getline(fin, s, '\t');
		fin >> type;
		fin.ignore();
		if(type == 1)
		{
			getline(fin, cr, '\t');
			fin >> fl;
			fin.ignore();

			temp1 = new Pilot;
			temp1->setname(n);
			temp1->setid(id);
			temp1->setstat(s);
			temp1->setratcode(cr);
			temp1->setflighthours(fl);
			crewlist.push_back(temp1);
		}
		else if(type == 2)
		{
			getline(fin, cr, '\t');
			fin >> fl;
			fin.ignore();

			temp2 = new CoPilot;
			temp2->setname(n);
			temp2->setid(id);
			temp2->setstat(s);
			temp2->setratcode(cr);
			temp2->setflighthours(fl);
			crewlist.push_back(temp2);
		}
		else if(type == 3)
		{
			getline(fin, p);

			temp3 = new CabinCrew;
			temp3->setname(n);
			temp3->setid(id);
			temp3->setstat(s);
			temp3->setposition(p);
			crewlist.push_back(temp3);
		}
	}
	fin.close();
}

void Crews::cleanup()
{
	crewlist.clear();
}
