#include "Actor.h"

class ActorNode {
public:
	ActorNode(Actor* actor) {
		this->actor = actor;
		this->left = nullptr;
		this->right = nullptr;
	};
	Actor* actor;
	ActorNode* left;
	ActorNode* right;
};