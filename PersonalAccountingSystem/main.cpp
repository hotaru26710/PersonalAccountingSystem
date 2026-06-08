#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int getCount();


typedef struct Record{
	char date[12];
	char type[12];
	float amount;
	char note[100];
	struct Record* prev;
	struct Record* next;
}Record;

Record* head = NULL;
Record* tail = NULL;

//创建新节点
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

//将节点数据存入文件
void saveToFile() {
	FILE* fp = fopen("record.txt", "w");
	if (fp == NULL) {
		printf("保存失败\n");
		return;
	}
	Record* current = head;
	while (current != NULL) {
		fprintf(fp, "%s %s %f %s", current->date, current->type, current->amount, current->note);
		current = current->next;
	}
	printf("文件保存成功\n");
	fclose(fp);
	return;
}

//从文件中读取节点
void loadFromFile() {
	FILE* fp = fopen("record.txt", "r");
	if (fp == NULL) {
		printf("加载失败\n");
		return;
	}
	char date[12], type[10], note[100];
	float amount;
	while (fscanf(fp, "%s %s %f %[^\n]", date, type, &amount, note) != EOF) {
		addToTail(createNewNode(date, type, amount, note));
	}
	printf("加载成功，本次加载了%d个节点\n", getCount());
	fclose(fp);
	

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


void addRecord() {
	system("cls");
	char date[12], type[10],note[100];
	float amount;

	printf("请输入日期(YYYY-MM-DD):\n");
	scanf("%s", date);
	printf("请输入类型(购物/租金/收入等):\n");
	scanf("%s", type);
	printf("请输入金额:\n");
	scanf("%f", &amount);
	printf("请输入备注:\n");
	scanf("%s", note);

	addToTail(createNewNode(date, type, amount, note));
	saveToFile();
	printf("记录添加成功!当前共有%d条记录\n",getCount());

	return;

}

void viewRecord() {
	system("cls");
	if (head == NULL) {
		printf("\n======暂无记录=====\n");
		return;
	}
	printf("\n====================账单记录=====================\n");
	printf("%s %s %s %s\n", "日期", "类型", "金额", "备注");
	printf("===================================================================================\n");

	Record* current = head;
	while (current != NULL) {
		printf("%s %s %.2f %s\n", current->date, current->type, current->amount, current->note);
		current = current->next;
	}
	printf("已成功加载%d条记录\n", getCount());
	printf("按回车键返回\n");
	getchar();
	getchar();
	return;
}

int main() {
	loadFromFile();
	while (true) {
		system("cls");
		printf("\n=====================个人记账系统========================\n");
		printf("请选择你要进行的操作\n");
		printf("1.添加记录\n");
		printf("2.查看当前账单\n");
		printf("3.退出系统\n");

		int input;
		scanf("%d", &input);
		switch (input){
		
			case 1: {
				addRecord();
				break;
			}
			case 2: {
				viewRecord();
				break;
			}
			case 3: {
				return 0;
			}
			default: {
				printf("无效选择\n");
				break;
			}
		}
	}








	return 0;
}