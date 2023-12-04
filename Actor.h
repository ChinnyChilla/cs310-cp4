#ifndef __ACTOR_H_
#define __ACTOR_H_

#include <iostream>
#include "Array.h"
using namespace std;




class Actor {
	private:
		unsigned int actor_id;
		string last;
		string first;
	public:
		Actor();
		Actor(unsigned int act_id, string last, string first); 
     bool operator==(const Actor& other);
     bool operator!=(const Actor& other);
		string getName() const { 
			return first + " " + last;
		}
		unsigned int getID() const { return actor_id; }
	      string getLastName() const{
	                 return last;
                }

};

#endif
