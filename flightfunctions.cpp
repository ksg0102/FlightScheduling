#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <fstream>
using namespace std;

#include "flightdata.h"
#include "flightcollections.h"

bool sortbysacode (Flightdata c1, Flightdata c2) //sorting function, sorts by departure airport code(ascending)
{
	return c1.getsacode() < c2.getsacode();
}

void Flights::updatestatus()
{
	string stat; //string that holds status of a flight
	
	time_t now = time(0); //setting variable "now" to system time
	tm* gmttm = gmtime(&now); //setting "now" time to gmt
	
	for(int i = 0; i < flightlist.size(); ++i)
	{
		if(flightlist[i].getendmonth() <= (1 + gmttm->tm_mon) && flightlist[i].getendday() <= (gmttm->tm_mday) && flightlist[i].getendyear() <= (1900 + gmttm->tm_year))
		{
			if(flightlist[i].getendmonth() == (1 + gmttm->tm_mon) && flightlist[i].getendday() < (gmttm->tm_mday) && flightlist[i].getendyear() == (1900 + gmttm->tm_year))
			{
				stat = "completed";
				flightlist[i].setstat(stat);
			}
			if(flightlist[i].getendhour() <	(1 + gmttm->tm_hour))
			{	
				stat = "completed";
				flightlist[i].setstat(stat);
			}
			else if(flightlist[i].getendhour() == (1 + gmttm->tm_hour))
			{
				if(flightlist[i].getendmin() <= (1 + gmttm->tm_min))
				{
					stat = "completed";
					flightlist[i].setstat(stat);
				}
			}
		}
	}
}

void Flights::addflight()
{
	string tn; //tail number
	int p; //pilot id
	int copid; //copilot id
	int c[3]; //array of 3 crew id
	int m, d, y; //month, day, year
	int h, min; //hour, min
	string scode; //3 letter starting airport code
	string ecode; //3 letter ending airport code
	int num; //number of passengers on the flight
	string stat = "active"; //status of flight is set to active when adding a flight
	Flightdata temp; //**object to pass variables into vector list
	
	cout << endl;
	cout << "Please enter departure date of flight." << endl;
	cout << "Enter Month(mm): ";
	cin >> m;
	cin.ignore();
	cout << "Enter Day(dd): ";
	cin >> d;
	cin.ignore();
	cout << "Enter Year(yyyy): ";
	cin >> y;
	cin.ignore();
	cout << endl;
	
	cout << "Please enter departure time of flight(in GMT)." << endl;
	cout << "Hour(24-hour): ";
	cin >> h;
	cin.ignore();
	cout << "Minutes: ";
	cin >> min;
	cin.ignore();
	
	temp.setstartdate(m, d, y);
	temp.setstarttime(h, min);
	cout << endl;
	
	cout << "Please enter landing date of flight." << endl;
	cout << "Enter Month(mm): ";
	cin >> m;
	cin.ignore();
	cout << "Enter Day(dd): ";
	cin >> d;
	cin.ignore();
	cout << "Enter Year(yyyy): ";
	cin >> y;
	cin.ignore();
	cout << endl;
	
	cout << "Please enter landing time of flight(in GMT)." << endl;
	cout << "Hour(24-hour): ";
	cin >> h;
	cin.ignore();
	cout << "Minutes: ";
	cin >> min;
	cin.ignore();
	
	temp.setenddate(m, d, y);
	temp.setendtime(h, min);
	cout << endl;
	
	cout << "Please enter tail number of plane: ";
	getline(cin, tn);
	cout << endl;
	cout << "Please enter Pilot ID: ";
	cin >> p;
	cin.ignore();
	cout << "Please enter Co-Pilot ID: ";
	cin >> copid;
	cin.ignore();
	cout << endl << "Please enter 3 Crew Member ID's" << endl;
	for(int i = 0; i < 3; ++i)
	{
		cout << "Crew member #" << i + 1 << ": ";
		cin >> c[i];
		cin.ignore();
	}
	cout << endl;
	cout << "Please enter departure airport code(3 letter code): ";
	getline(cin, scode);
	cout << "Please enter landing airport code(3 letter code): ";
	getline(cin, ecode);
	cout << "Please enter number of passengers on the flight: ";
	cin >> num;
	cin.ignore();
	
	temp.settailnum(tn);
	temp.setpid(p);
	temp.setcpid(copid);
	temp.setcid(c);
	temp.setsacode(scode);
	temp.seteacode(ecode);
	temp.setnump(num);
	temp.setstat(stat);
	temp.setfid(); //sets a flight id to use for search
	flightlist.push_back(temp);
	
	cout << endl;
	cout << "FLIGHT SUCCESSFULLY SCHEDULED." << endl;
	cout << "FLIGHT SET AS ACTIVE." << endl;
	cout << "FLIGHT ID IS: " << flightlist[flightlist.size() - 1].getfid() << endl;
	cout << endl;
	
	++flightcount;
}

void Flights::printflights()
{
	int *a; //pointer used to point at array of crew id's to output
	
	updatestatus(); //this function only updates to completed, otherwise does nothing(flight stays active or user cancels flight)
	if(flightlist.empty() == true)
	{
		cout << endl;
		cout << "THERE ARE NO FLIGHTS SCHEDULED." << endl;
		cout << endl;
		return;
	}
	
	cout << endl;
	cout << "****LIST OF ALL FLIGHTS****" << endl;
	cout << endl;
	for(int i = 0; i < flightlist.size(); ++i)
	{
		cout << i + 1 << ". " << endl;
		cout << "Flight ID: " << flightlist[i].getfid() << endl;
		cout << "Status of flight: " << flightlist[i].getstat() << endl;
		cout << "Flight departure date: " << flightlist[i].getstartmonth() << "/" << flightlist[i].getstartday() << "/" << flightlist[i].getstartyear() << endl;
		cout << "Flight departure time(in GMT): " << flightlist[i].getstarthour() << ":" << flightlist[i].getstartmin() << endl;
		cout << "Flight landing date: " << flightlist[i].getendmonth() << "/" << flightlist[i].getendday() << "/" << flightlist[i].getendyear() << endl;
		cout << "Flight landing time(in GMT): " << flightlist[i].getendhour() << ":" << flightlist[i].getendmin() << endl;
		cout << "Departure airport code: " << flightlist[i].getsacode() << endl;
		cout << "Landing airport code: " << flightlist[i].geteacode() << endl;
		cout << "Tail number of plane: " << flightlist[i].gettailnum() << endl;
		cout << "Pilot ID: " << flightlist[i].getpid() << endl;
		cout << "Co-pilot ID: " << flightlist[i].getcpid() << endl;
		cout << "Crew member ID's: " << endl;
		a = flightlist[i].getcid();
		for(int j = 0; j < 3; ++j)
		{
			cout << "	Crew member ID " << j + 1 << ": " << a[j] << endl;
		}
		cout << "Number of passengers: " << flightlist[i].getnump() << endl;
		cout << endl;
	}	
	cout << "ABOVE IS A LIST OF ALL FLIGHT ENTRIES." << endl;
	cout << endl;
}

int Flightdata::print(int ch)
{
	int *a;
	int match = 0; //variable that will be incremented when there is a match
	
	if(ch == 1)
	{
		if(getstat() == "active")
		{
			++match;
			cout << "*" << endl;
			cout << "Departure airport code: " << getsacode() << endl;
			cout << "Landing airport code: " << geteacode() << endl;
			cout << "Flight ID: " << getfid() << endl;
			cout << "Status of flight: " << getstat() << endl;
			cout << "Flight departure date: " << getstartmonth() << "/" << getstartday() << "/" << getstartyear() << endl;
			cout << "Flight departure time(in GMT): " << getstarthour() << ":" << getstartmin() << endl;
			cout << "Flight landing date: " << getendmonth() << "/" << getendday() << "/" << getendyear() << endl;
			cout << "Flight landing time(in GMT): " << getendhour() << ":" << getendmin() << endl;
			cout << "Tail number of plane: " << gettailnum() << endl;
			cout << "Pilot ID: " << getpid() << endl;
			cout << "Co-pilot ID: " << getcpid() << endl;
			cout << "Crew member ID's: " << endl;
			a = getcid();
			for(int j = 0; j < 3; ++j)
			{
				cout << "	Crew member ID " << j + 1 << ": " << a[j] << endl;
			}
			cout << "Number of passengers: " << getnump() << endl;
		}	
	}
	else if(ch == 2)
	{
		if(getstat() == "completed")
		{
			++match;
			cout << "*" << endl;
			cout << "Departure airport code: " << getsacode() << endl;
			cout << "Landing airport code: " << geteacode() << endl;
			cout << "Flight ID: " << getfid() << endl;
			cout << "Status of flight: " << getstat() << endl;
			cout << "Flight departure date: " << getstartmonth() << "/" << getstartday() << "/" << getstartyear() << endl;
			cout << "Flight departure time(in GMT): " << getstarthour() << ":" << getstartmin() << endl;
			cout << "Flight landing date: " << getendmonth() << "/" << getendday() << "/" << getendyear() << endl;
			cout << "Flight landing time(in GMT): " << getendhour() << ":" << getendmin() << endl;
			cout << "Tail number of plane: " << gettailnum() << endl;
			cout << "Pilot ID: " << getpid() << endl;
			cout << "Co-pilot ID: " << getcpid() << endl;
			cout << "Crew member ID's: " << endl;
			a = getcid();
			for(int j = 0; j < 3; ++j)
			{
				cout << "	Crew member ID " << j + 1 << ": " << a[j] << endl;
			}
			cout << "Number of passengers: " << getnump() << endl;
		}
	}
	else if(ch == 3)
	{
		if(getstat() == "canceled")
		{
			++match;
			cout << "*" << endl;
			cout << "Departure airport code: " << getsacode() << endl;
			cout << "Landing airport code: " << geteacode() << endl;
			cout << "Flight ID: " << getfid() << endl;
			cout << "Status of flight: " << getstat() << endl;
			cout << "Flight departure date: " << getstartmonth() << "/" << getstartday() << "/" << getstartyear() << endl;
			cout << "Flight departure time(in GMT): " << getstarthour() << ":" << getstartmin() << endl;
			cout << "Flight landing date: " << getendmonth() << "/" << getendday() << "/" << getendyear() << endl;
			cout << "Flight landing time(in GMT): " << getendhour() << ":" << getendmin() << endl;
			cout << "Tail number of plane: " << gettailnum() << endl;
			cout << "Pilot ID: " << getpid() << endl;
			cout << "Co-pilot ID: " << getcpid() << endl;
			cout << "Crew member ID's: " << endl;
			a = getcid();
			for(int j = 0; j < 3; ++j)
			{
				cout << "	Crew member ID " << j + 1 << ": " << a[j] << endl;
			}
			cout << "Number of passengers: " << getnump() << endl;
		}
	}
return match;
}

void Flights::cancelflight()
{
	int flid; //variable for flight id
	string stat = "canceled";
	int match = 0;
	
	updatestatus();
	if(flightlist.empty() == true)
	{
		cout << endl;
		cout << "THERE ARE NO FLIGHTS SCHEDULED." << endl;
		cout << endl;
		return;
	}
	
	sort(flightlist.begin(), flightlist.end(), sortbysacode); // calling sorting function, sorts by departure airport code
	cout << endl;
	cout << "****LIST OF FLIGHTS****" << endl;
	for(int i = 0; i < flightlist.size(); ++i)
	{
		flightlist[i].print(1);
		cout << endl;
	}
	
	cout << "ABOVE IS THE LIST OF ALL ACTIVE FLIGHTS SORTED BY DEPARTURE CODE." << endl << endl;
	
	bool exit = true;
	while(exit != false)
	{	
		f3:
		cout << "Please enter the Flight ID of the flight you would like to cancel: ";
		cin >> flid;
		cin.ignore();
		if(cin.fail())
		{
			cout << endl;
			cout << "INVALID ENTRY. ENTER AGAIN." << endl;
			cin.clear(); //clears error
			cin.ignore(10000, '\n'); //ignores everything in cin stream
			cout << endl;
			goto f3;
		}
		for(int i = 0; i < flightlist.size(); ++i)
		{
			if(flightlist[i].getfid() == flid)
			{
				++match;
				flightlist[i].setstat(stat);
				exit = false;
			}
		}
		if(match == 0)
		{
			cout << endl;
			cout << "FLIGHT ID NUMBER DOES NOT EXIST." << endl;
			cout << endl;
			exit = false;
		}
	}
	if(match > 0)
	{
		cout << endl;
		cout << "FLIGHT WITH FLIGHT ID " << flid << " SUCCESSFULLY CANCELLED." << endl;
		cout << endl;
	}
}

void Flights::printflightsbystatus(int ch)
{
	int matchvalue;
	int val = 0;
	
	updatestatus();
	if(flightlist.empty() == true)
	{
		cout << endl;
		cout << "THERE ARE NO FLIGHTS SCHEDULED." << endl;
		cout << endl;
		return;
	}
	
	sort(flightlist.begin(), flightlist.end(), sortbysacode); // calling sorting function, sorts by departure airport code
	cout << endl;
	for(int i = 0; i < flightlist.size(); ++i)
	{
		matchvalue = flightlist[i].print(ch);
		if(matchvalue > 0)
		{
			++val;
		}
	}
	if(val == 0)
	{
		cout << "THE LIST FOR THE DESIRED FLIGHT SCHEDULE DOES NOT EXIST." << endl;
		cout << endl;
		return;
	}
	if(val > 0)
	{
		if(ch == 1)
		{
			cout << "ABOVE IS THE LIST OF ALL ACTIVE FLIGHTS SORTED BY DEPARTURE CODE." << endl;
			cout <<endl;
		}
		else if(ch == 2)
		{
			cout << "ABOVE IS THE LIST OF ALL COMPLETED FLIGHTS SORTED BY DEPARTURE CODE." << endl;
			cout << endl;
		}
		else if(ch == 3)
		{
			cout << "ABOVE IS THE LIST OF ALL CANCELLED FLIGHTS SORTED BY DEPARTURE CODE." << endl;
			cout << endl;
		}
	}
}

void Flights::deletecanceledflights()
{
	int match = 0;
	
	updatestatus();
	if(flightlist.empty() == true)
	{
		cout << endl;
		cout << "THERE ARE NO FLIGHTS SCHEDULED." << endl;
		cout << endl;
		return;
	}
	
	for(int i = 0; i < flightlist.size(); ++i)
	{
		if(flightlist[i].getstat() == "canceled")
		{
			++match;
			flightlist.erase(flightlist.begin() + i);
		}
	}
	if(match == 0)
	{
		cout << "THERE ARE NO CANCELLED FLIGHTS." << endl;
		cout << endl;
		return;
	}
	if(match > 0)
	{	
		cout << endl;
		cout << "CANCELLED FLIGHTS SUCCESSFULLY DELETED." << endl;
		cout << endl;
	}
}

void Flights::deletecompletedflights()
{
	int match = 0;
	
	updatestatus();
	if(flightlist.empty() == true)
	{
		cout << endl;
		cout << "THERE ARE NO FLIGHTS SCHEDULED." << endl;
		cout << endl;
		return;
	}
	
	for(int i = 0; i < flightlist.size(); ++i)
	{
		if(flightlist[i].getstat() == "completed")
		{
			++match;
			flightlist.erase(flightlist.begin() + i);
		}
	}
	if(match == 0)
	{
		cout << endl;
		cout << "THERE ARE NO COMPLETED FLIGHTS." << endl;
		cout << endl;
		return;
	}
	if(match > 0)
	{
		cout << endl;
		cout << "COMPLETED FLIGHTS SUCCESSFULLY DELETED." << endl;
		cout << endl;
	}
}

void Flights::deletelastentry()
{
	updatestatus();
	cout << endl;
	if(flightlist.empty() == true)
	{
		cout << "THERE ARE NO FLIGHTS SCHEDULED." << endl;
		cout << endl;
		return;
	}
	
	flightlist.pop_back();
	cout << "LAST ENTRY SUCCESSFULLY DELETED." << endl;
}

void Flights::changespecificvalue()
{
	int a;
	int b;
	int match = 0;
	
	string tn; //tail number
	int p; //pilot id
	int copid; //copilot id
	int c[3]; //array of 3 crew id
	int m, d, y; //month, day, year
	int h, min; //hour, min
	string scode; //3 letter starting airport code
	string ecode; //3 letter ending airport code
	int num; //number of passengers on the flight
	
	updatestatus();
	cout << endl;
	if(flightlist.empty() == true)
	{
		cout << "THERE ARE NO FLIGHTS SCHEDULED." << endl;
		cout << endl;
		return;
	}
	
	printflights();
	
	bool exit = true;
	while(exit != false)
	{
		f4:
		cout << "Please enter Flight ID of flight you wish to edit: ";
		cin >> a;
		cin.ignore();
		cout << endl;
		if(cin.fail())
		{
			cout << endl;
			cout << "INAVLID ENTRY. ENTER AGAIN." << endl;
			cin.clear(); //clears error
			cin.ignore(10000, '\n'); //ignores everything in cin stream
			cout << endl;
			goto f4;
		}
	
		for(int i = 0; i < flightlist.size(); ++i)
		{
			if(flightlist[i].getfid() == a)
			{
				++match;
				m3:
				cout << "Please enter a number (1-12) to choose from the menu options: " << endl;
				cout << endl;
				cout << "1. Update departure date of flight" << endl;
				cout << "2. Update departure time of flight(in GMT)" << endl;
				cout << "3. Update landing date of flight" << endl;
				cout << "4. Update landing time of flight(in GMT)" << endl;
				cout << "5. Update tail number of the plane" << endl;
				cout << "6. Update pilot ID" << endl;
				cout << "7. Update co-pilot ID" << endl;
				cout << "8. Update crew ID's" << endl;
				cout << "9. Update departure airport code" << endl;
				cout << "10. Update landing airport code" << endl;
				cout << "11. Update number of passengers" << endl;
				cout << "12. Quit back to edit plane menu" << endl;
				
				cin >> b;
				cin.ignore();
				if(cin.fail())
				{
					cout << endl;
					cout << "Invalid entry. Enter again." << endl;
					cin.clear(); //clears error
					cin.ignore(10000, '\n'); //ignores everything in cin stream
					cout << endl;
					goto m3;
				}
				
				if(b == 1)
				{
					cout << endl;
					cout << "Enter new departure date of flight." << endl;
					cout << "Enter Month(mm): ";
					cin >> m;
					cin.ignore();
					cout << "Enter Day(dd): ";
					cin >> d;
					cin.ignore();
					cout << "Enter Year(yyyy): ";
					cin >> y;
					cin.ignore();
					cout << endl;
					flightlist[i].setstartdate(m, d, y);
					cout << endl;
					cout << "Departure date successfully updated." << endl;
					cout << endl;
					goto m3;
				}	
				if(b == 2)
				{
					cout << endl;
					cout << "Enter new departure time of flight(in GMT)." << endl;
					cout << "Hour(24-hour): ";
					cin >> h;
					cin.ignore();
					cout << "Minutes: ";
					cin >> min;
					cin.ignore();
					flightlist[i].setstarttime(h, min);
					cout << endl;
					cout << "Departure time successfully updated." << endl;
					cout << endl;
					goto m3;
				}
				if(b == 3)
				{
					cout << endl;
					cout << "Enter new landing date of flight." << endl;
					cout << "Enter Month(mm): ";
					cin >> m;
					cin.ignore();
					cout << "Enter Day(dd): ";
					cin >> d;
					cin.ignore();
					cout << "Enter Year(yyyy): ";
					cin >> y;
					cin.ignore();
					cout << endl;
					flightlist[i].setenddate(m, d, y);
					cout << endl;
					cout << "Landing date successfully updated." << endl;
					cout << endl;
					goto m3;
				}
				if(b == 4)
				{
					cout << endl;
					cout << "Enter new landing time of flight(in GMT)." << endl;
					cout << "Hour(24-hour): ";
					cin >> h;
					cin.ignore();
					cout << "Minutes: ";
					cin >> min;
					cin.ignore();
					flightlist[i].setendtime(h, min);
					cout << endl;
					cout << "Landing time successfully updated." << endl;
					cout << endl;
					goto m3;
				}
				if(b == 5)
				{
					cout << endl;
					cout << "Enter new tail number: ";
					getline(cin, tn);
					flightlist[i].settailnum(tn);
					cout << endl;
					cout << "Tail number successfully updated." << endl;
					cout << endl;
					goto m3;
				}
				if(b == 6)
				{
					cout << endl;
					cout << "Enter new pilot ID: ";
					cin >> p;
					cin.ignore();
					flightlist[i].setpid(p);
					cout << endl;
					cout << "Pilot ID successfully updated." << endl;
					cout << endl;
					goto m3;
				}
				if(b == 7)
				{
					cout << endl;
					cout << "Enter new co-pilot ID: ";
					cin >> copid;
					cin.ignore();
					flightlist[i].setcpid(copid);
					cout << endl;
					cout << "Co-pilot ID successfully updated." << endl;
					cout << endl;
					goto m3;
				}
				if(b == 8)
				{
					cout << endl;
					cout << "Enter new crew ID's";
					for(int j = 0; j < 3; ++j)
					{
						cout << "Crew member #" << j + 1 << ": ";
						cin >> c[j];
						cin.ignore();
					}
					flightlist[i].setcid(c);
					cout << endl;
					cout << "Crew ID's successfully updated." << endl;
					cout << endl;
					goto m3;
				}
				if(b == 9)
				{
					cout << endl;
					cout << "Enter new departure airport code: ";
					getline(cin, scode);
					flightlist[i].setsacode(scode);
					cout << endl;
					cout << "Departure airport code successfully updated." << endl;
					cout << endl;
					goto m3;
				}
				if(b == 10)
				{
					cout << endl;
					cout << "Enter new landing airport code: ";
					getline(cin, ecode);
					flightlist[i].seteacode(ecode);
					cout << endl;
					cout << "Landing airport code successfully updated." << endl;
					cout << endl;
					goto m3;
				}
				if(b == 11)
				{
					cout << endl;
					cout << "Enter new number of passengers: ";
					cin >> num;
					cin.ignore();
					flightlist[i].setnump(num);
					cout << endl;
					cout << "Number of passengers successfully updated." << endl;
					cout << endl;
					goto m3;
				}
				if(b == 12)
				{
					exit = false; //quit case
				}
				else
				{
					cout << "Invalid entry. Enter again." << endl;
					goto m3;
				}
			}
		}
		if(match == 0)
		{
			cout << endl;
			cout << "FLIGHT ID NUMBER " << a << " DOES NOT EXIST." << endl;
			cout << endl;
			exit = false;
		}
	}
}

void Flights::deleteanentry()
{
	int id; //flight ID variable
	int match = 0;
	
	updatestatus();
	cout << endl;
	if(flightlist.empty() == true)
	{
		cout << "THERE ARE NO FLIGHTS SCHEDULED." << endl;
		cout << endl;
		return;
	}
	
	printflights();
	
	bool exit = true;
	while(exit != false)
	{
		f5:
		cout << endl;
		cout << "Please enter the flight ID of the flight you would like to delete: ";
		cin >> id;
		cin.ignore();
		if(cin.fail())
		{
			cout << endl;
			cout << "Invalid entry. Enter again." << endl;
			cin.clear(); //clears error
			cin.ignore(10000, '\n'); //ignores everything in cin stream
			cout << endl;
			goto f5;
		}
	
		for(int i = 0; i < flightlist.size(); ++i)
		{
			if(flightlist[i].getfid() == id)
			{
				++match;
				flightlist.erase(flightlist.begin() + i);
				exit = false;
			}
		}
		if(match == 0)
		{
			cout << endl;
			cout << "FLIGHT ID NUMBER " << id << " DOES NOT EXIST." << endl;
			cout << endl;
			exit = false;
		}
	}
	if(match > 0)
	{
		cout << endl;
		cout << "FLIGHT WITH FLIGHT ID NUMBER " << id << " SUCCESSFULLY DELETED." << endl;
	}
}

void Flights::deleteallentries()
{
	updatestatus();
	if(flightlist.empty() == true)
	{
		cout << "THERE ARE NO FLIGHTS SCHEDULED." << endl;
		cout << endl;
		return;
	}
	
	flightlist.clear();
	cout << endl;
	cout << "All FLIGHTS HAVE BEEN SUCCESSFULLY DELETED." << endl;
	cout << endl;
}

void Flights::printplaneschedule()
{
	string tn; //variable for tail number
	int match = 0;
	
	updatestatus();
	if(flightlist.empty() == true)
	{
		cout << endl;
		cout << "THERE ARE NO FLIGHTS SCHEDULED." << endl;
		cout << endl;
		return;
	}
	
	bool exit = true;
	while(exit != false)
	{
		cout << endl;
		cout << "Please enter the tail number of a plane to print its active assignments: ";
		getline(cin, tn);
	
		sort(flightlist.begin(), flightlist.end(), sortbysacode); // calling sorting function, sorts by departure airport code
		cout << endl;
		for(int i = 0; i < flightlist.size(); ++i)
		{
			if(flightlist[i].gettailnum() == tn)
			{
				++match;
				flightlist[i].print(1);
				cout << endl;
				exit = false;
			}
		}
		if(match == 0)
		{
			cout << endl;
			cout << "PLANE " << tn << " DOES NOT EXIST." << endl;
			cout << endl;
			exit = false;
		}
	}
	if(match > 0)
	{
		cout << endl;
		cout << "ABOVE IS THE LIST OF ALL ACTIVE ASSIGNMENTS(IF ANY) FOR PLANE " << tn << ", SORTED BY DEPARTURE AIRPORT CODE." << endl;
		cout << endl;
	}
}

void Flights::printcrewschedule()
{
	int id; //variable for tail number
	int match = 0;
	int *a; //pointer for array of crew id's
	
	updatestatus();
	if(flightlist.empty() == true)
	{
		cout << endl;
		cout << "THERE ARE NO FLIGHTS SCHEDULED." << endl;
		cout << endl;
		return;
	}
	
	bool exit = true;
	while(exit != false)
	{
		f6:
		cout << endl;
		cout << "Please enter the ID number of a crew member to print their active assignments: ";
		cin >> id;
		cin.ignore();
		if(cin.fail())
		{
			cout << endl;
			cout << "INVALID ENTRY. ENTER AGAIN." << endl;
			cin.clear(); //clears error
			cin.ignore(10000, '\n'); //ignores everything in cin stream
			cout << endl;
			goto f6;
		}
		
		sort(flightlist.begin(), flightlist.end(), sortbysacode); // calling sorting function, sorts by departure airport code
		cout << endl;
		for(int i = 0; i < flightlist.size(); ++i)
		{
			if(flightlist[i].getpid() == id)
			{
				++match;
				flightlist[i].print(1);
				cout << endl;
				exit = false;
			}
			else if(flightlist[i].getcpid() == id)
			{
				++match;
				flightlist[i].print(1);
				cout << endl;
				exit = false;
			}
			a = flightlist[i].getcid();
			for(int j = 0; j < 3; ++j)
			{
				if(a[j] == id)
				{
					++match;
					flightlist[i].print(1);
					cout << endl;
					exit = false;
				}
			}
		}
		if(match == 0)
		{
			cout << "CREW MEMBER " << id << " DOES NOT EXIST." << endl;
			cout << endl;
			exit = false;
		}
	}
	if(match > 0)
	{
		cout << endl;
		cout << "ABOVE IS THE LIST OF ALL ACTIVE ASSIGNMENTS(IF ANY) FOR CREW MEMBER " << id << ", SORTED BY DEPARTURE AIRPORT CODE." << endl;
		cout << endl;
	}
}

void Flights::storeflights()
{
	ofstream fout;
	int *a;
	
	fout.open("flights.dat");
	fout << flightlist.size() << endl;
	for(int i = 0; i < flightlist.size(); ++i)
	{
		fout << flightlist[i].gettailnum() << "\t" << flightlist[i].getpid() << "\t" << flightlist[i].getcpid() << "\t";
		a = flightlist[i].getcid();
		for(int j = 0; j < 3; ++j)
		{
			fout << a[j] << "\t";
		}
		fout << flightlist[i].getstartmonth() << "\t" << flightlist[i].getstartday() << "\t" << flightlist[i].getstartyear() << "\t" << flightlist[i].getstarthour() << "\t" << flightlist[i].getstartmin() << "\t";
		fout << flightlist[i].getendmonth() << "\t" << flightlist[i].getendday() << "\t" << flightlist[i].getendyear() << "\t" << flightlist[i].getendhour() << "\t" << flightlist[i].getendmin() << "\t";
		fout << flightlist[i].getsacode() << "\t" << flightlist[i].geteacode() << "\t" << flightlist[i].getnump() << "\t" << flightlist[i].getstat() << "\t" << flightlist[i].getfid() << endl;
	}
	fout.close();
}

void Flights::loadflights()
{
	ifstream fin;
	string tn; //tail number
	int p; //pilot id
	int copid; //copilot id
	int c[3]; //array of 3 crew id
	int m, d, y; //month, day, year
	int h, min; //hour, min
	string scode; //3 letter starting airport code
	string ecode; //3 letter ending airport code
	int num; //number of passengers on the flight
	string stat; //status of flight
	int f; //variable to hold the flight id being read in from flights.dat file
	Flightdata temp; //**object to pass variables into vector list
	
	fin.open("flights.dat");
	fin >> flightcount;
	fin.ignore();
	
	if(flightcount == 0)
	{
		return;
	}
	
	for(int i = 0; i < flightcount; ++i)
	{
		getline(fin, tn, '\t');
		fin >> p >> copid;
		fin.ignore();
		
		for(int j = 0; j < 3; ++j)
		{
			fin >> c[j];
			fin.ignore();
		}
		
		fin >> m >> d >> y >> h >> min;
		fin.ignore();
		
		temp.setstartdate(m, d, y);
		temp.setstarttime(h, min);
		
		fin >> m >> d >> y >> h >> min;
		fin.ignore();
		
		temp.setenddate(m, d, y);
		temp.setendtime(h, min);
		
		getline(fin, scode, '\t');
		getline(fin, ecode, '\t');
		fin >> num;
		fin.ignore();
		getline(fin, stat, '\t');
		fin >> f;
		fin.ignore();
		
		temp.settailnum(tn);
		temp.setpid(p);
		temp.setcpid(copid);
		temp.setcid(c);
		temp.setsacode(scode);
		temp.seteacode(ecode);
		temp.setnump(num);
		temp.setstat(stat);
		temp.setfid(f); //sets the flight id read from file to use for search
		flightlist.push_back(temp);
	}
	fin.close();	
}

void Flights::cleanup()
{
	flightlist.clear();
}