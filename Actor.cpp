#include "Actor.h"

Actor::Actor() {
	first = "";
	last = "";
	actor_id = 0;
	praise_points = 0;
	already_praised = false;
	heap_position = -1;
}

Actor::Actor(unsigned int act_id, string lname, string fname) {
	first = fname;
	last = lname;
	actor_id = act_id;
	praise_points = 0;
	already_praised = false;
	heap_position = -1;
}

// bool Actor::addMovie(const unsigned int movieid) {
// 	for (unsigned int i = 0; i < movies.size(); i++) {
// 		if (movies[i] == movieid)
// 			return false;
// 	}
// 	movies.push_back(movieid);
// 	return true;
// }

