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

//删除节点


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

//获取链表节点个数
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

//获取账单所有金额总值
float getTotal() {
	Record* current = head;
	float total = 0;
	while (current != NULL) {
		total += current->amount;
		current = current->next;
	}
	return total;
}

float getIn() {
	Record* current = head;
	float total = 0;
	while (current != NULL) {
		if (current->amount > 0) {
			total += current->amount;
			current = current->next;
		}
		else
		{
			current = current->next;
		}
	}
	return total;
}

int getInCount() {
	Record* current = head;
	int count = 0;
	while (current != NULL) {
		if (current->amount > 0) {
			count += 1;
			current = current->next;
		}
		else
		{
			current = current->next;
		}
	}
	return count;
}

float getOut() {
	Record* current = head;
	float total = 0;
	while (current != NULL) {
		if (current->amount < 0) {
			total += current->amount;
			current = current->next;
		}
		else
		{
			current = current->next;
		}
	}
	return total;
}

int getOutCount() {
	Record* current = head;
	int count = 0;
	while (current != NULL) {
		if (current->amount < 0) {
			count += 1;
			current = current->next;
		}
		else
		{
			current = current->next;
		}
	}
	return count;
}

void deleteNode(Record* current) {
	if (current->prev != NULL) {
		current->prev->next = current->next;
	}
	if (current->next != NULL) {
		current->next->prev = current->prev;
	}
	free(current);
}