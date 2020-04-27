class Crews
{
	private:
		int crewcount;
		vector<Crewdata*> crewlist;
	public:
		Crews(){crewcount = 0;}
		
		void addcrew();
		void printcrew();
		void deletelastentry();
		void changespecificvalue();
		void deleteanentry();
		void deleteallentries();
		void loadcrew();
		void storecrew();
		void cleanup();
};