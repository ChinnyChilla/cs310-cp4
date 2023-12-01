#include <iostream>
using namespace std;

// #include "Actor.h"
#include "Array.h"
#include "ActorBST.h"
#include "ActorHeap.h"

class ActorDB {
	private:
		Array<Actor*>* actors;
		ActorBST actorBST;
		ActorHeap actorHeap; 	
	public:
		ActorDB();
		// bool find(unsigned int actorid) const;
		// string getName(unsigned int actorid) const;
		bool addActor(Actor* actor);
		void praise_actor(string last, unsigned int points);
		// void award_actor();
		// void remove_actor(string last);
		//void showCareer(unsigned int actorid) const;
};
