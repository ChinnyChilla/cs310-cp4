#include "ActorDB.h"
// #include "Array.h"
// #include "ActorBST.h"
// #include "ActorHeap.h"

ActorDB::ActorDB() {
	actors = new Array<Actor*>();
	actorBST = new ActorBST();
	actorHeap = new ActorHeap();

}
ActorDB::~ActorDB() {
	delete actorHeap;
	delete actors;
	delete actorBST;
}
int ActorDB::binarySearchActor(int target, int left, int right)
{
	if (right == -1)
		return -1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		int middle_id = actors->at(middle)->getID();
		if (middle_id == target)
			return middle;

		if (middle_id < target)
		{
			left = middle + 1;
			continue;
		}
		right = middle - 1;
	};
	return -1;
};

int ActorDB::findInsertLocationActor(int target, int left, int right)
{
	if (right == -1)
		return 0;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		int middle_id = actors->at(middle)->getID();
		if (middle_id == target)
			return middle;
		if (middle_id < target)
		{
			left = middle + 1;
			continue;
		}
		right = middle - 1;
	};
	return right + 1;
};

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

bool ActorDB::addActor(unsigned int actorid, string last, string first) {
		
	Actor* actor = new Actor(actorid, last, first);
	
	int location = binarySearchActor(actorid, 0, actors->count - 1);
	if (location != -1) {
		cout << "register_actor: Error actor id " << actorid << " already in use" << endl;
		return false;
	}
	int insertLocation = findInsertLocationActor(actorid, 0 , actors->count - 1);
	cout << "register_actor: Registered actor " << actor->getName() << endl;
	actors->insert(insertLocation, actor);
	
	actorBST->insert(actor);
	actorHeap->insert(actor);
	return true;
}

void ActorDB::praise_actor(string last, unsigned int points) {
	Actor* actor = actorBST->search(last);
	if (actor == nullptr) {
		cout << "Actor " << last << " not found" << endl;
		return;
	}
	if (actor->already_praised) {
		cout << "That's nice but " << actor->first << " " << actor->last << " has already recieved the award" << endl;
		return;
	}
	actor->praise_points += points;
	cout << "Awarding actor " << actor->first << " " << actor->last << " " << points << " praise points" << endl;
	actorHeap->fixHeap(actor->heap_position);
	return;
};

void ActorDB::award_actor() {
	Actor* actor = actorHeap->extractMax();
	if (actor == nullptr) {
		cout << "No actors to award" << endl;
		return;
	}
	cout << "Actor " << actor->first << " " << actor->last << " presnted with the Lifetime Achievement Award (" << actor->praise_points << " praise points)" << endl;
	actor->already_praised = true;

	
	return;
}

void ActorDB::show_praise() {
	cout << "actor cout is " << actors->count << endl;
	for (unsigned int i=0; i<actors->count; i++) {
		cout << actors->at(i)->getID() << " " << actors->at(i)->getName() << " has " << actors->at(i)->praise_points << " praise points" << endl;
	}
	return;
}

void ActorDB::remove_actor(unsigned int actorid) {
	int actorLocation = binarySearchActor(actorid, 0, actors->count-1);
	if (actorLocation == -1) {
		cout << "remove_actor: Actor not found" << endl;
		return;
	}
	Actor* actorToRemove = actors->at(actorLocation);
	cout << "Actor with name " << actorToRemove->first << " " << actorToRemove->last << " has been removed" << endl;
	actors->remove(actorLocation);
	if (!actorToRemove->already_praised) {
		actorHeap->remove(actorToRemove);
	}
	actorBST->removeActor(actorToRemove);
	return;

}

void ActorDB::remove_actor(string last) {

	Actor* actorToRemove = actorBST->search(last);
	if (actorToRemove == nullptr) {
		cout << "remove_actor: Actor not found" << endl;
		return;
	}
	cout << "remove_actor: Actor with name " << actorToRemove->first << " " << actorToRemove->last << " has been removed" << endl;
	int actorLocation = binarySearchActor(actorToRemove->getID(), 0, actors->count-1);
	actors->remove(actorLocation);
	if (!actorToRemove->already_praised) {
		actorHeap->remove(actorToRemove);
	}
	actorBST->removeActor(actorToRemove);
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
