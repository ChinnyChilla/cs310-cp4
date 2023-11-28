#include "Actor.h"


class ActorHeap {
	public:
		ActorHeap();
		~ActorHeap();
		bool insert(Actor* actor);
		bool remove(Actor* actor);
		Actor* extractMax();
	private:
		void grow();
		void swap(unsigned int left, unsigned int right);
		void mergeDown(unsigned int index);
		void mergeUp(unsigned int index);
		Array<Actor*>* arr;
		int count;
		int maxSize;
}