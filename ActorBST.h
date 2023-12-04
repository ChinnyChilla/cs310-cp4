#include "ActorNode.h"

class ActorBST {
public:
	ActorNode* root;
	ActorBST();
	~ActorBST();
	void destoryAllNodes(ActorNode* node) {
		if (node)
		{
			destoryAllNodes(node->left);
			destoryAllNodes(node->right);
		}
		delete node;
	};
	void insert(Actor* node);
	void print(ActorNode* node);
	Actor* search(string name);
};