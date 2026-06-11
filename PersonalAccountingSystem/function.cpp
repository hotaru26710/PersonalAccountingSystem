#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
#include "record.h"



void saveToFile() {
	FILE* fp = fopen("record.txt", "w");
	if (fp == NULL) {
		printf("保存失败\n");
		return;
	}
	Record* current = head;
	while (current != NULL) {
		fprintf(fp, "%s %s %f %s\n", current->date, current->type, current->amount, current->note);
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
	return;
}

void addRecord() {
	system("cls");
	char date[12], type[10], note[100];
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
	printf("记录添加成功!当前共有%d条记录\n", getCount());

	return;
}

void viewRecord() {
	system("cls");
	if (head == NULL) {
		printf("\n===================暂无记录========================\n");
		getchar();
		getchar();
		return;
	}
	printf("\n=============请选择排序方式==============\n");
	printf("1.正序\n");
	printf("2.倒序\n");
	printf("3.仅看收入（正序）\n");
	printf("4.仅看收入（倒序）\n");
	printf("5.仅看支出（正序）\n");
	printf("6.仅看支出（倒序）\n");
	printf("7.返回\n");
	int input;
	Record* current;
	scanf("%d", &input);
	switch (input)
	{
	case 1:
		system("cls");
		printf("\n====================账单记录=====================\n");
		printf("%-12s %-10s %-10s %-20s\n", "日期", "类型", "金额", "备注");
		printf("===================================================================================\n");

		current = head;
		while (current != NULL) {
			printf("%-12s %-10s %-10.2f %-20s\n", current->date, current->type, current->amount, current->note);
			current = current->next;
		}
		printf("已成功加载%d条记录\n", getCount());
		printf("按回车键返回\n");
		getchar();
		getchar();
		return;

	case 2:
		system("cls");
		printf("\n====================账单记录=====================\n");
		printf("%-12s %-10s %-10s %-20s\n", "日期", "类型", "金额", "备注");
		printf("===================================================================================\n");

		current = tail;
		while (current != NULL) {
			printf("%-12s %-10s %-10.2f %-20s\n", current->date, current->type, current->amount, current->note);
			current = current->prev;
		}
		printf("已成功加载%d条记录\n", getCount());
		printf("按回车键返回\n");
		getchar();
		getchar();
		return;

	case 3:
		system("cls");
		printf("\n====================账单记录=====================\n");
		printf("%-12s %-10s %-10s %-20s\n", "日期", "类型", "金额", "备注");
		printf("===================================================================================\n");

		current = head;
		while (current != NULL) {
			if (current->amount >= 0) {
				printf("%-12s %-10s %-10.2f %-20s\n", current->date, current->type, current->amount, current->note);
				current = current->next;
			}
			else {
				current = current->next;
			}
		}
		printf("已成功加载%d条记录\n", getInCount());
		printf("当前净收入:%.2f\n", getIn());
		printf("按回车键返回\n");
		getchar();
		getchar();
		return;

	case 4:
		system("cls");
		printf("\n====================账单记录=====================\n");
		printf("%-12s %-10s %-10s %-20s\n", "日期", "类型", "金额", "备注");
		printf("===================================================================================\n");

		current = tail;
		while (current != NULL) {
			if (current->amount >= 0) {
				printf("%-12s %-10s %-10.2f %-20s\n", current->date, current->type, current->amount, current->note);
				current = current->prev;
			}
			else {
				current = current->prev;
			}
		}
		printf("已成功加载%d条记录\n", getInCount());
		printf("当前净收入:%.2f\n", getIn());
		printf("按回车键返回\n");
		getchar();
		getchar();
		return;

	case 5:
		system("cls");
		printf("\n====================账单记录=====================\n");
		printf("%-12s %-10s %-10s %-20s\n", "日期", "类型", "金额", "备注");
		printf("===================================================================================\n");

		current = head;
		while (current != NULL) {
			if (current->amount < 0) {
				printf("%-12s %-10s %-10.2f %-20s\n", current->date, current->type, current->amount, current->note);
				current = current->next;
			}
			else {
				current = current->next;
			}
		}
		printf("已成功加载%d条记录\n", getOutCount());
		printf("当前净支出:%.2f\n", getOut());
		printf("按回车键返回\n");
		getchar();
		getchar();
		return;

	case 6:
		system("cls");
		printf("\n====================账单记录=====================\n");
		printf("%-12s %-10s %-10s %-20s\n", "日期", "类型", "金额", "备注");
		printf("===================================================================================\n");

		current = tail;
		while (current != NULL) {
			if (current->amount < 0) {
				printf("%-12s %-10s %-10.2f %-20s\n", current->date, current->type, current->amount, current->note);
				current = current->prev;
			}
			else {
				current = current->prev;
			}
		}
		printf("已成功加载%d条记录\n", getOutCount());
		printf("当前净支出:%.2f\n", getOut());
		printf("按回车键返回\n");
		getchar();
		getchar();
		return;

	case 7:
		return;

	default:
		printf("无效选择\n");
		break;
	}
}

void modifyRecord() {
	system("cls");
	printf("\n====================账单记录=====================\n");
	printf("%-12s %-10s %-10s %-20s\n", "日期", "类型", "金额", "备注");
	printf("===================================================================================\n");

	Record* current = head;
	while (current != NULL) {
		printf("%-12s %-10s %-10.2f %-20s\n", current->date, current->type, current->amount, current->note);
		current = current->next;
	}
	printf("\n==========================选择修改方式=========================\n");
	printf("1.通过索引修改\n");
	printf("2.返回\n");

	int input;
	while (true) {
		scanf("%d", &input);
		switch (input) {
			case 1:
				indexModify();
				return;
				break;
			case 2:
				return;
			default:
				printf("无效选择\n");
				break;
		}
	}
	
}

void indexModify() {
	Record* current = head;
	printf("请选择你想修改账目的索引(1-%d)\n", getCount());
	int index;
	scanf("%d", &index);
	for (int i = 1; i < index; i++) {
		current = current->next;
	}
	printf("当前条目信息:\n%-12s %-10s %-10.2f %-20s\n", current->date, current->type, current->amount, current->note);
	char input[100];
	printf("请输入更新的数据(直接回车数据不做改变)：\n");

	printf("日期(%s):\n", current->date);
	getchar();
	if (fgets(input, sizeof(input), stdin) && input[0] != '\n') {
		input[strcspn(input, "\n")] = 0;
		strcpy(current->date, input);
		printf("日期已更新为: %s\n", current->date);
	}
	else {
		printf("日期未作出改变\n");
	}

	printf("类型(%s):\n", current->type);
	if (fgets(input, sizeof(input), stdin) && input[0] != '\n') {
		input[strcspn(input, "\n")] = 0;
		strcpy(current->type, input);
		printf("类型已更新为: %s\n", current->type);
	}
	else {
		printf("类型未作出改变\n");
	}

	printf("金额(%f):\n", current->amount);
	if (fgets(input, sizeof(input), stdin) && input[0] != '\n') {
		current->amount = atof(input);
		printf("金额已更新为: %f\n", current->amount);
	}
	else {
		printf("金额未作出改变\n");
	}

	printf("备注(%s):\n", current->note);
	if (fgets(input, sizeof(input), stdin) && input[0] != '\n') {
		input[strcspn(input, "\n")] = 0;
		strcpy(current->note, input);
		printf("备注已更新为: %s\n", current->note);
	}
	else {
		printf("备注未作出改变\n");
	}

	saveToFile();
	printf("该条目数据已修改完成！\n");
	printf("回车键返回\n");
	getchar();
	return;
}

void billInformation() {
	system("cls");
	printf("\n=======================账单统计信息============================\n");
	printf("当前账单条目数: %d\n", getCount());
	printf("当前记录余额: %.2f\n", getTotal());
	if (getTotal() <= 0) {
		printf("当前余额已透支，请注意消费！\n");
	} 
	printf("当前净收入: %.2f\n", getIn());
	printf("当前净收入笔数: %d\n", getInCount());
	printf("当前净支出: %.2f\n", getOut());
	printf("当前净支出笔数: %d\n", getOutCount());
	

	printf("按回车键返回\n");
	getchar();
	getchar();
	return;

}

