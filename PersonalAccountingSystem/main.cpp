#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include "record.h"

int main() {
	loadFromFile();
	while (true) {
		system("cls");
		printf("\n=====================个人记账系统========================\n");
		printf("请选择你要进行的操作\n");
		printf("1.添加记录\n");
		printf("2.查看当前账单\n");
		printf("3.修改账目\n");
		printf("4.删除账目\n");
		printf("5.查看账目统计信息\n");
		printf("6.退出系统\n");

		int input;
		scanf("%d", &input);
		switch (input){
		
			case 1:
				addRecord();
				break;
			case 2:
				viewRecord();
				break;
			case 3:
				modifyRecord();
				break;
			case 4:
				deleteRecord();
				break;
			case 5:
				billInformation();
				break;
			case 6:
				return 0;
			default:
				printf("无效选择\n");
				break;
		}
	}
	return 0;
}