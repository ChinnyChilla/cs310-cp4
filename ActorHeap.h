#include "Actor.h"

class ActorHeap {
	public:
		ActorHeap();
		~ActorHeap();
		void insert(Actor* actor);
		void remove(Actor* actor);
		void fixHeap(unsigned int index);
		Actor* extractMax();
		Actor** arr;
		unsigned int count;
		unsigned int maxSize;
	private:
		void grow();
		void swap(unsigned int left, unsigned int right);
		void mergeDown(unsigned int index);
		void mergeUp(unsigned int index);
		
};