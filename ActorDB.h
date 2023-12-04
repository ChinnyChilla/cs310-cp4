#ifndef __ACTORDB_H_
#define __ACTORDB_H_

#include <iostream>
using namespace std;

#include "Actor.h"
#include "Array.h"
#include "BST.h"

class ActorDB {
	private:
		GrowableArray<Actor> actors;
		BST Index;
	public:
		ActorDB();
		bool find(unsigned int actorid) const;
		string getName(unsigned int actorid) const;
		bool addActor(const Actor &actor);
		void registerActor(const Actor &actor);
		
};

#endif
