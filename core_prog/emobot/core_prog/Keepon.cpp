#include <iostream>
#include <time.h>

class Keepon
{
	protected:
		//level is a value between 1 and 100 that will indicate the behaviour that keepon will show.
		double* level;
		time_t* lastSeen;
		char* twitterUN;

	public:
		//default constructor
		Keepon();
		//allows level to be updated from main.
		void updateLevel (bool  input);
		void getLevel ();
		//allows lastSeen to be updated from main body.
		void setLastSeen (time_t seen);
		void getLastSeen ();
};