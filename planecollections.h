class Planes
{
	private:
		int planecount; //count for creating size of vector when loading data
		vector<Planedata> planelist;
	public:
		Planes(){planecount = 0;}
		
		void addplane();
		void printplanes();
		void deletelastentry();
		void changespecificvalue();
		void deleteanentry();
		void deleteallentries();
		void loadplanes();
		void storeplanes();
		void cleanup();
};