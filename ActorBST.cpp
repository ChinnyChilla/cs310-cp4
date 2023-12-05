#include "ActorBST.h"

ActorBST::ActorBST() {
	root = nullptr;
};

ActorBST::~ActorBST() {
	destroyAllNodes(root);
};
// insert a node into the BST sorted by last name
void ActorBST::insert(Actor* actor) {
	ActorNode* newNode = new ActorNode(actor);
	if (root == nullptr) {
		root = newNode;
		return;
	}
	ActorNode* curr = root;
	while (curr != nullptr) {
		if (curr->actor->last > newNode->actor->last) {
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

void ActorBST::removeActor(Actor* actorToRemove) {
    root = removeActorRec(root, actorToRemove);
}

//tranverse thge node and find node to remove
ActorNode* ActorBST::removeActorRec(ActorNode* node, Actor* actorToRemove) {
    if (node == nullptr) return nullptr;
    if (actorToRemove->last < node->actor->last) {
        node->left = removeActorRec(node->left, actorToRemove);
    } else if (actorToRemove->last > node->actor->last) {
        node->right = removeActorRec(node->right, actorToRemove);
    } else {
        if (node->left == nullptr) {
            ActorNode* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            ActorNode* temp = node->left;
            delete node;
            return temp;
        }

        ActorNode* temp = minValueNode(node->right);
        node->actor = temp->actor; // Swap actor; assuming shallow copy is acceptable
        node->right = removeActorRec(node->right, temp->actor);
    }
    return node;
}

// in case the node to be removed has two children, make the right min value node successor
ActorNode* ActorBST::minValueNode(ActorNode* node) {
    ActorNode* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}
