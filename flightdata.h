class Flightdata
{
	private:
		string tailnum; //tail number of plane
		int pid; //pilot id
		int cpid; //co-pilot id
		int cid[3]; //int array of size 3 for crew id
		int smonth, sday, syear, shour, smin; //start date/time entered as GMT
		int emonth, eday, eyear, ehour, emin; //end date/time entered as GMT
		string sacode; //3 letter starting airport code
		string eacode; //3 letter ending airport code
		int nump; //number of passengers on the flight
		string status; //**set automatically to active,completed -- cancel manually
		int fid; //**set automatically, flight id(use for locating flight)
	public:
		void settailnum(string tn){tailnum = tn;}
		string gettailnum(){return tailnum;}
		
		void setpid(int p){pid = p;}
		int getpid(){return pid;}
		
		void setcpid(int copid){cpid = copid;}
		int getcpid(){return cpid;}
		
		void setcid(int c[3])
		{
			for(int i = 0; i < 3; ++i)
			{
				cid[i] = c[i];
			}
		}
		int* getcid(){return cid;}
		
		void setstartdate(int m, int d, int y)
		{
			smonth = m;
			sday = d;
			syear = y;
		}
		int getstartmonth(){return smonth;}
		int getstartday(){return sday;}
		int getstartyear(){return syear;}
		
		void setstarttime(int h, int min)
		{
			shour = h;
			smin = min;
		}
		int getstarthour(){return shour;}
		int getstartmin(){return smin;}
		
		void setenddate(int m, int d, int y)
		{
			emonth = m;
			eday = d;
			eyear = y;
		}
		int getendmonth(){return emonth;}
		int getendday(){return eday;}
		int getendyear(){return eyear;}
		
		void setendtime(int h, int min)
		{
			ehour = h;
			emin = min;
		}
		int getendhour(){return ehour;}
		int getendmin(){return emin;}
		
		void setsacode(string scode){sacode = scode;}
		string getsacode(){return sacode;}
		
		void seteacode(string ecode){eacode = ecode;}
		string geteacode(){return eacode;}
		
		void setnump(int num){nump = num;}
		int getnump(){return nump;}
		
		void setstat(string stat){status = stat;}
		string getstat(){return status;}
		
		void setfid()
		{
			srand(time(0));
			fid = (rand()%899999)+100000;
		}
		void setfid(int f){fid = f;} //this is only used for when reading the flights.dat file with an existing flight ID
		int getfid(){return fid;}
		
		int print(int ch);
};