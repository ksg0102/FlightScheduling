#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "planedata.h"
#include "planecollections.h"

void Planes::addplane()
{
	string m; //make of the plane
	string mod; //model of the plane
	string t; //tail number of plane
	int s; // # of seats on a plane
	int r; //range a plane can fly
	string stat; //out, in, repair
	Planedata temp; //**object that will be used to set/get data members and passed into the vector list
	
	cout << endl;
	cout << "Please enter the tail number of the plane: ";
	getline(cin, t);
	cout << "Please enter the status of the plane(out, in, repair): ";
	getline(cin, stat);
	cout << "Please enter the make of the plane: ";
	getline(cin, m);
	cout << "Please enter the model of the plane: ";
	getline(cin, mod);
	cout << "Please enter the number of seats on the plane: ";
	cin >> s;
	cin.ignore();
	cout << "Please enter the range of the plane (in miles): ";
	cin >> r;
	cin.ignore();
	
	temp.setmake(m); //initialize all values in class
	temp.setmodel(mod);
	temp.settailnum(t);
	temp.setseats(s);
	temp.setrange(r);
	temp.setstatus(stat);
	planelist.push_back(temp); //use the temp object to pass data into the vector list
	
	cout << endl;
	cout << "PLANE SUCCESSFULLY ADDED." << endl;
	cout << endl;

	++planecount;
}

void Planes::printplanes()
{
	if(planelist.empty() == true)
	{
		cout << endl << "NO PLANES HAVE BEEN ADDED." << endl;
		cout << endl;
		return;
	}
	
	cout << endl;
	cout << "****LIST OF PLANE ENTRIES****" << endl;
	cout << endl;
	for(int i = 0; i < planelist.size(); ++i)
	{
		cout << i + 1 << "." << endl;
		cout << "Plane tail number: " << planelist[i].gettailnum() << endl;
		cout << "Plane status(out, in, repair): " << planelist[i].getstatus() << endl;
		cout << "Plane make: " << planelist[i].getmake() << endl;
		cout << "Plane model: " << planelist[i].getmodel() << endl;
		cout << "Plane seat amount: " << planelist[i].getseats() << endl;
		cout << "Plane range(in miles): " << planelist[i].getrange() << endl;
		cout << endl;
	}
	
 cout << "ABOVE IS THE LIST OF ALL PLANE ENTRIES." << endl;
 cout << endl;
}

void Planes::deletelastentry()
{
	cout << endl;
	if(planelist.empty() == true)
	{
		cout << "NO PLANES HAVE BEEN ADDED." << endl;
		cout << endl;
		return;
	}
	
	planelist.pop_back();
	cout << "LAST ENTRY SUCCESSFULLY DELETED." << endl;
}

void Planes::changespecificvalue()
{
	string a;
	int b;
	int match = 0;
	
	string m; //make of the plane
	string mod; //model of the plane
	string t; //tail number of plane
	int s; // # of seats on a plane
	int r; //range a plane can fly
	string stat; //out, in, repair
	
	cout << endl;
	if(planelist.empty() == true)
	{
		cout << endl << "NO PLANES HAVE BEEN ADDED." << endl;
		cout << endl;
		return;
	}
	
	printplanes();
	
	bool exit = true;
	while(exit != false)
	{
		cout << "Please enter tail number of plane you wish to edit: ";
		getline(cin, a);
	
		for(int i = 0; i < planelist.size(); ++i)
		{
			if(planelist[i].gettailnum() == a)
			{
				++match;
				m1:
				cout << "Please enter a number (1-7) to choose from the menu options: " << endl;
				cout << endl;
				cout << "1. Update tail number of plane" << endl;
				cout << "2. Update status of the plane(out, in, repair)" << endl;
				cout << "3. Update make of plane" << endl;
				cout << "4. Update model of plane" << endl;
				cout << "5. Update number of seats on the plane" << endl;
				cout << "6. Update range of the plane(in miles)" << endl;
				cout << "7. Quit back to edit plane menu" << endl;
				
				cin >> b;
				cin.ignore();
				if(cin.fail())
				{
					cout << endl;
					cout << "INVALID ENTRY. ENTER AGAIN." << endl;
					cin.clear(); //clears error
					cin.ignore(10000, '\n'); //ignores everything in cin stream
					cout << endl;
					goto m1;
				}
				
				if(b == 1)
				{
					cout << endl;
					cout << "Enter new tail number: ";
					getline(cin, t);
					planelist[i].settailnum(t);
					cout << endl;
					cout << "Tail number successfully updated." << endl;
					cout << endl;
					goto m1;
				}	
				if(b == 2)
				{
					cout << endl;
					cout << "Enter new status(out, in, repair): ";
					getline(cin, stat);
					planelist[i].setstatus(stat);
					cout << endl;
					cout << "Status successfully updated." << endl;
					cout << endl;
					goto m1;
				}
				if(b == 3)
				{
					cout << endl;
					cout << "Enter new make: ";
					getline(cin, m);
					planelist[i].setmake(m);
					cout << endl;
					cout << "Make successfully updated." << endl;
					cout << endl;
					goto m1;
				}
				if(b == 4)
				{
					cout << endl;
					cout << "Enter new model: ";
					getline(cin, mod);
					planelist[i].setmodel(mod);
					cout << endl;
					cout << "Model successfully updated." << endl;
					cout << endl;
					goto m1;
				}
				if(b == 5)
				{
					cout << endl;
					cout << "Enter new number of seats: ";
					cin >> s;
					cin.ignore();
					planelist[i].setseats(s);
					cout << endl;
					cout << "Number of seats successfully updated." << endl;
					cout << endl;
					goto m1;
				}
				if(b == 6)
				{
					cout << endl;
					cout << "Enter new range: " << endl;
					cin >> r;
					cin.ignore();
					planelist[i].setrange(r);
					cout << endl;
					cout << "Range successfully updated." << endl;
					cout << endl;
					goto m1;
				}
				if(b == 7)
				{
					exit = false;
				}
				else
				{
					cout << "INVALID ENTRY. ENTER AGAIN." << endl;
					goto m1;
				}
			}
		}
		if(match == 0)
		{
			cout << endl;
			cout << "TAIL NUMBER " << a << " DOES NOT EXIST." << endl;
			cout << endl;
			exit = false;
		}
	}
}
	
void Planes::deleteanentry()
{
	string tn; //tail number variable
	int match = 0;
	
	
	cout << endl;
	if(planelist.empty() == true)
	{
		cout << endl << "NO PLANES HAVE BEEN ADDED." << endl;
		cout << endl;
		return;
	}
	
	printplanes();
	
	cout << endl << "ABOVE IS THE LIST OF ALL PLANES." << endl;
	cout << endl;
	bool exit = true;
	while(exit != false)
	{
		cout << "Please enter the tail number of the plane you would like to delete: ";
		getline(cin, tn);
	
		for(int i = 0; i < planelist.size(); ++i)
		{
			if(planelist[i].gettailnum() == tn)
			{
				++match;
				planelist.erase(planelist.begin() + i);
				exit = false;
			}
		}
		if(match == 0)
		{
			cout << endl;
			cout << "TAIL NUMBER " << tn << " DOES NOT EXIST." << endl;
			cout << endl;
			exit = false;
		}	
	}
	if(match > 0)
	{
		cout << endl << "PLANE WITH TAIL NUMBER " << tn << " SUCCESSFULLY DELETED." << endl;
		cout << endl;
	}
}

void Planes::deleteallentries()
{
	if(planelist.empty() == true)
	{
		cout << endl;
		cout << "NO PLANES HAVE BEEN ADDED." << endl;
		return;
	}
	
	planelist.clear();
	cout << endl << "ALL PLANE ENTRIES HAVE BEEN SUCCESSFULLY DELETED." << endl;
}

void Planes::storeplanes()
{
	ofstream fout;
	
	fout.open("planes.dat");
	fout << planelist.size() << endl;
	for(int i = 0; i < planelist.size(); ++i)
	{
		fout << planelist[i].getmake() << "\t" << planelist[i].getmodel() << "\t" << planelist[i].gettailnum() << "\t" 
		<< planelist[i].getseats() << "\t" << planelist[i].getrange() << "\t" << planelist[i].getstatus() << endl;
	}
	fout.close();
}

void Planes::loadplanes()
{
	ifstream fin;
	string m; //make of the plane
	string mod; //model of the plane
	string t; //tail number of plane
	int s; // # of seats on a plane
	int r; //range a plane can fly
	string stat; //out, in, repair
	Planedata temp; //**object that will be used to set/get data members and passed into the vector list
	
	fin.open("planes.dat");
	fin >> planecount;
	fin.ignore();
	
	if(planecount == 0)
	{
		return;
	}
	
	for(int i = 0; i < planecount; ++i)
	{
		getline(fin, m, '\t');
		getline(fin, mod, '\t');
		getline(fin, t, '\t');
		fin >> s >> r;
		fin.ignore();
		getline(fin, stat);
		
		temp.setmake(m); //initialize all values in class
		temp.setmodel(mod);
		temp.settailnum(t);
		temp.setseats(s);
		temp.setrange(r);
		temp.setstatus(stat);
		planelist.push_back(temp); //use the temp object to pass data into the vector list
	}
	fin.close();
}

void Planes::cleanup()
{
	planelist.clear();
}
	
	
