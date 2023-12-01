#include "ActorDB.h"


ActorDB::ActorDB() {
	actors = new Array<Actor*>();
	actorBST = ActorBST();
	actorHeap = ActorHeap();

}

// bool ActorDB::find(unsigned int actorid) const {
// 	for (unsigned int i = 0; i < actors->count; i++) {
// 		if (actors->at(i)->getID() == actorid)
// 			return true;
// 	}
// 	return false;
// }

// string ActorDB::getName(unsigned int actorid) const {
// 	for (unsigned int i = 0; i < actors->count; i++) {
// 		if (actors->at(i)->getID() == actorid)
// 			return actors->at(i)->getName();
// 	}
// 	return "EMPTY";
// }

bool ActorDB::addActor(Actor* actor) {
	for (unsigned int i = 0; i < actors->count; i++) {
		if (actors->at(i)->getID() == actor->getID())
			return false;
	}
	for (unsigned int i=0; i<actors->count; i++) {
		if (actors->at(i)->getID() > actor->getID()) {
			actors->insert(i, actor);
			break;
		}
	}
	actorBST.insert(actor);
	actorHeap.insert(actor);
	return true;
}

void ActorDB::praise_actor(string last, unsigned int points) {
	Actor* actor = actorBST.search(last);
	if (actor == nullptr) {
		cout << "Actor " << last << " not found" << endl;
		return;
	}
	if (actor->already_praised) {
		cout << "Actor " << last << " already praised" << endl;
		return;
	}
	actor->praise_points += points;
	cout << "Awarding actor " << actor->first << " " << actor->last << " " << points << " praise points" << endl;
	actorHeap.fixHeap(actor->heap_position);
	return;
}
/*
void ActorDB::showCareer(unsigned int actorid) const {
	for (unsigned int i = 0; i < actors.size(); i++) {
		if (actors[i].getID() == actorid) {
			cout << actors[i].getName << " has acted in:" << 
				endl;
			break;
	}
	if (i < actors.size())
		actors[i].showCareer();
	else 
		cout << "actor id " << actorid << " not found" << endl;
}
*/
