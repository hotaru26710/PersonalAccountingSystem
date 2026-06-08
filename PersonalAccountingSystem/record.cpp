#define _CRT_SECURE_NO_WARNINGS
#include "record.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

Record* head = NULL;
Record* tail = NULL;

Record* createNewNode(char date[], char type[], float amount, char note[]) {
	Record* NewNode = (Record*)malloc(sizeof(Record));
	strcpy(NewNode->date, date);
	strcpy(NewNode->type, type);
	NewNode->amount = amount;
	strcpy(NewNode->note, note);
	NewNode->prev = NULL;
	NewNode->next = NULL;
	return NewNode;
}

//尾差节点
void addToTail(Record* node) {
	if (head == NULL) {
		head = tail = node;
	}
	else {
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
	return;
}

//头插节点
void addToHead(Record* node) {
	if (head == NULL) {
		head = tail = node;
	}
	else {
		head->prev = node;
		node->next = head;
		head = node;
	}
	return;
}

int getCount() {
	int count = 0;
	if (head == NULL) {
		return count;
	}
	Record* current = head;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}