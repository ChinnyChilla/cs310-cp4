#ifndef __ACTOR_H_
#define __ACTOR_H_

#include <iostream>
using namespace std;

class Actor {
	public:
		Actor();
		Actor(unsigned int act_id, string last, string first); 
		// bool addMovie(const unsigned int movie_id);
		//void showCareer(const MovieDB &moviedb) const;

		string getName() const { 
			return first + " " + last;
		}
		unsigned int getID() const { return actor_id; }
		int praise_points;
		bool already_praised;
		int heap_position;
		unsigned int actor_id;
		string last;
		string first;
};

#endif
