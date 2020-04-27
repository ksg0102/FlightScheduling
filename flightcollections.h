class Flights
{
	private:
		int flightcount;
		vector<Flightdata> flightlist;
	public:
		Flights(){flightcount = 0;}
		
		void addflight();
		void printflights();
		void updatestatus();
		void cancelflight();
		void printflightsbystatus(int ch);
		void deletecanceledflights();
		void deletecompletedflights();
		void deletelastentry();
		void changespecificvalue();
		void deleteanentry();
		void deleteallentries();
		void printplaneschedule();
		void printcrewschedule();
		void loadflights();
		void storeflights();
		void cleanup();
};