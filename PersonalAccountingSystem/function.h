#pragma once

//主要函数功能声明
void saveToFile();
void loadFromFile();
void addRecord();
void viewRecord();
void modifyRecord();
void billInformation();
void deleteRecord();


//次要功能函数声明
void indexModify();
void indexDelete();
bool isDateValid(const char* date);