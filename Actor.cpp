#include "Actor.h"

Actor::Actor() {
	first = "";
	last = "";
	actor_id = 0;
}

Actor::Actor(unsigned int act_id, string lname, string fname) {
	first = fname;
	last = lname;
	actor_id = act_id;
}

bool Actor::operator==(const Actor& other) {
        return actor_id == other.actor_id; 
    }

bool Actor::operator!=(const Actor& other){
        return !(*this == other);
    }

