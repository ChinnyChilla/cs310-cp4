#include "ActorBST.h"

ActorBST::ActorBST() {
	root = nullptr;
};

ActorBST::~ActorBST() {};
// insert a node into the BST sorted by last name
void ActorBST::insert(Actor* actor) {
	ActorNode* newNode = new ActorNode(actor);
	if (root == nullptr) {
		root = newNode;
		return;
	}
	ActorNode* curr = root;
	while (curr != nullptr) {
		if (curr->actor->last < newNode->actor->last) {
			if (curr->left == nullptr) {
				curr->left = newNode;
				return;
			}
			curr = curr->left;
		} else {
			if (curr->right == nullptr) {
				curr->right = newNode;
				return;
			}
			curr = curr->right;
		}
	}
}
Actor* ActorBST::search(string name) {
	ActorNode* curr = root;
	while (curr != nullptr) {
		if (curr->actor->last == name) {
			return curr->actor;
		} else if (curr->actor->last < name) {
			curr = curr->left;
		} else {
			curr = curr->right;
		}
	}
	return nullptr;
}
// print all the nodes in the BST in order
void ActorBST::print(ActorNode* curr) {
	if (curr->left != nullptr) {
		print(curr->left);
	};
	cout << curr->actor->actor_id << " " << curr->actor->first << " " << curr->actor->last << " has " << curr->actor->praise_points << " praise points" << endl;
	if (curr->right != nullptr) {
		print(curr->right);
	};
	return;
}