#include "ActorHeap.h"

ActorHeap::ActorHeap()
{
	arr = new Actor*[2];
	maxSize = 2;
	count = 0;
}

ActorHeap::~ActorHeap() {
	delete[] arr;
}
void ActorHeap::grow()
{
	Actor** newArray = new Actor*[maxSize * 2];
	for (unsigned int i=0; i < maxSize; i++) {
		newArray[i] = arr[i];
	}
	maxSize = maxSize*2;
	delete[] arr;
	arr = newArray;
	return;
}
void ActorHeap::insert(Actor* actor)
{
	if (count == maxSize) grow();
	arr[count] = actor;
	actor->heap_position = count;
	mergeUp(count);
	count++;
	return;
}

Actor* ActorHeap::extractMax() {
	if (count == 0) {return nullptr;}
	Actor* toReturn = arr[0];
	arr[0] = arr[count-1];
	arr[0]->heap_position = 0;
	count--;
	if (count == 1) {
		return toReturn;
	} else {
		mergeDown(0);
		return toReturn;
	};
}
void ActorHeap::swap(unsigned int left, unsigned int right) {
	Actor* temp = arr[left];
	arr[left] = arr[right];
	arr[right] = temp;

	// update index positions
	arr[left]->heap_position = left;
	arr[right]->heap_position = right;
	return;
}

void ActorHeap::mergeUp(unsigned int index) {
	int parentIndex = -1;
	while (index > 0) {
		if (index % 2  == 0) {
			parentIndex = (index - 2) / 2;
		} else {
			parentIndex = (index - 1) / 2;
		}
		if (arr[index]->praise_points > arr[parentIndex]->praise_points) {
				swap(index, parentIndex);
				index = parentIndex;
		} else {break;}
	}
	return;
}

void ActorHeap::mergeDown(unsigned int index) {
	unsigned int largestIndex;
	unsigned int leftChildIndex;
	unsigned int rightChildIndex;
	while (index < count) {
		largestIndex = index;
		leftChildIndex = (index * 2) + 1;
		rightChildIndex = (index * 2) + 2;

		if (leftChildIndex<count && arr[leftChildIndex]->praise_points> arr[largestIndex]->praise_points)
		{
			largestIndex = leftChildIndex;
		}
		if (rightChildIndex<count && arr[rightChildIndex]->praise_points> arr[largestIndex]->praise_points)
		{
			largestIndex = rightChildIndex;
		}
		if (largestIndex != index) {
			swap(index, largestIndex);
			index = largestIndex;
		} else {
			break;
		}
	}
	return;
}
void ActorHeap::fixHeap(unsigned int index) {
	mergeUp(index);
	return;
}