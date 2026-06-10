#pragma once

typedef struct Record {
    char date[12];
    char type[12];
    float amount;
    char note[100];
    struct Record* prev;
    struct Record* next;
} Record;

// 全局变量声明
extern Record* head;
extern Record* tail;

// 链表操作函数声明
Record* createNewNode(char date[], char type[], float amount, char note[]);
void addToTail(Record* node);
void addToHead(Record* node);
int getCount();
float getTotal();
float getIn();
int getInCount();
float getOut();
int getOutCount();