#include "ActorDB.h"
#include "Array.h"

ActorDB::ActorDB() {
}

bool ActorDB::find(unsigned int actorid) const {
	for (unsigned int i = 0; i < actors.getSize(); i++) {
		if (actors[i].getID() == actorid)
			return true;
	}
	return false;
}

string ActorDB::getName(unsigned int actorid) const {
	for (unsigned int i = 0; i < actors.getSize(); i++) {
		if (actors[i].getID() == actorid)
			return actors[i].getName();
	}
	return "EMPTY";
}

bool ActorDB::addActor(const Actor &actor) {
	for (unsigned int i = 0; i < actors.getSize(); i++) {
		if (actors[i].getID() == actor.getID())
			return false;
	}
	actors.push_back(actor);
	return true;
}

void ActorDB::registerActor(const Actor& actor) {
    actors.add(actor); 
    int index = actor.getID(); 
    Index.insert(actor.getLastName(), index);
}

