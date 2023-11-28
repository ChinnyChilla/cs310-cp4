#include "ActorHeap.h"

ActorHeap::ActorHeap()
{
	arr = new Actor[2];
	maxSize = 2;
	count = 0;
}

ActorHeap::~ActorHeap() {
	delete[] arr;
}
void ActorHeap::grow()
{
	Actor* newArray = new Actor[maxSize * 2];
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
	mergeUp(count);
	count++;
	return;
}

Actor* ActorHeap::extractMax() {
	Actor* toReturn = arr[0];
	arr[0] = arr[count-1];
	mergeDown(0);
	// Potentially add already_priased logic here?
	return toReturn;
}
void ActorHeap::swap(unsigned int left, unsigned int right) {
	Actor* temp = arr[left];
	arr[left] = arr[right];
	arr[right] = arr[left];
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
		if (arr[index]->priase_points > arr[parentIndex]->priase_points) {
				swap(index, parentIndex);
				index = parentIndex;
		} else {break;}
	}
	return;
}

void ActorHeap::mergeDown(unsigned int index) {
	int largestIndex;
	int leftChildIndex;
	int rightChildIndex;
	while (index < count) {
		largestIndex = index;
		leftChildIndex = (index * 2) + 1;
		rightChildIndex = (index * 2) + 2;

		if (arr[leftChildIndex] > arr[largestIndex]) {
			largestIndex = leftChildIndex;
		}
		if (arr[rightChildIndex] > arr[largestIndex]) {
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