class Crewdata
{
	private:
		string name; //name of crew member
		int ID; //crew member id
		string status; //available, on leave, sick
	public:
		void setname(string n){name = n;}
		string getname(){return name;}
		
		void setid(int id){ID = id;}
		int getid(){return ID;}
		
		void setstat(string s){status = s;}
		string getstat(){return status;}
		
		virtual void print(){};
};

class Pilot : public Crewdata
{
	private:
		string ratcode; //character rating code
		int flighthours; //flight hours
	public:
		void setratcode(string cr){ratcode = cr;}
		string getratcode(){return ratcode;}
		
		void setflighthours(int fl){flighthours = fl;}
		int getflighthours(){return flighthours;}
		
		void print();
};

class CoPilot : public Crewdata
{
	private:
		string ratcode; //character rating code
		int flighthours; //flight hours
	public:
		void setratcode(string cr){ratcode = cr;}
		string getratcode(){return ratcode;}
		
		void setflighthours(int fl){flighthours = fl;}
		int getflighthours(){return flighthours;}
		
		void print();
};

class CabinCrew : public Crewdata
{
	private:
		string position; //position of the cabin crew member
		string role; //variable that holds role of the crew member
	public:	
		void setposition(string p){position = p;}
		string getposition(){return position;}

		void print();
};