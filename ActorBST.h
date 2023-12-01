#include "ActorNode.h"

class ActorBST {
public:
	ActorNode* root;
	ActorBST();
	~ActorBST();
	void insert(Actor* node);
	void print(ActorNode* node);
	Actor* search(string name);
};