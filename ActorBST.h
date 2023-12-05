#include "ActorNode.h"

class ActorBST {
public:
	ActorNode* root;
	ActorBST();
	~ActorBST();
	void removeActor(Actor* actorToRemove);
    ActorNode* minValueNode(ActorNode* node);
	void destroyAllNodes(ActorNode* node) {
		if (node)
		{
			destroyAllNodes(node->left);
			destroyAllNodes(node->right);
		}
		delete node;
	};
	void insert(Actor* node);
	void print(ActorNode* node);
	Actor* search(string name);
	ActorNode* removeActorRec(ActorNode* node, Actor* actorToRemove);

};