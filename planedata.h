class Planedata
{
	private:
		string make; //make of the plane
		string model; //model of the plane
		string tailnum; //tail number of plane
		int seats; // # of seats on a plane
		int range; //range a plane can fly
		string status; //out, in, repair
	public:
		void setmake(string m){make = m;}
		string getmake(){return make;}
		
		void setmodel(string mod){model = mod;}
		string getmodel(){return model;}
		
		void settailnum(string t){tailnum = t;}
		string gettailnum(){return tailnum;}
		
		void setseats(int s){seats = s;}
		int getseats(){return seats;}
		
		void setrange(int r){range = r;}
		int getrange(){return range;}
		
		void setstatus(string stat){status = stat;}
		string getstatus(){return status;}
};