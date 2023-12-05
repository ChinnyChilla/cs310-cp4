#include <iostream>
using namespace std;

// #include "Actor.h"
#include "Array.cpp"
#include "ActorBST.h"
#include "ActorHeap.h"

class ActorDB {
	private:
		Array<Actor*>* actors;
		ActorBST* actorBST;
		ActorHeap* actorHeap; 	
	public:
		ActorDB();
		~ActorDB();
		// bool find(unsigned int actorid) const;
		// string getName(unsigned int actorid) const;
		bool addActor(unsigned int actorid, string last, string first);
		void praise_actor(string last, unsigned int points);
		void award_actor();
		void show_praise();
		int findInsertLocationActor(int target, int left, int right);
		int binarySearchActor(int target, int left, int right);
		void remove_actor(unsigned int actorid);
		void remove_actor(string last);
		// void remove_actor(string last);˜
		//void showCareer(unsigned int actorid) const;
};
