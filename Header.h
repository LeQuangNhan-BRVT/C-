#pragma once
#include <iostream>

using namespace std;
struct subject {
	char name[20];
	char code[20];
	int TC;
};
struct NODE {
	subject data;
	NODE* next;

};
typedef NODE* NODEPTR;
NODEPTR makeNode(subject sub);
void inSubject(subject& sub);
void outSubject(subject sub);
void addFront(NODEPTR& list, subject sub);
void addBack(NODEPTR& list, subject sub);
NODEPTR addAfterQ(NODEPTR& list, NODEPTR q, subject sub);
void print_List(NODEPTR list);
void findMinTC(NODEPTR list);
void findMaxTC(NODEPTR list);
NODEPTR findCode(NODEPTR list);
void insertNode(NODEPTR& list, int pos, subject sub);
int countNode(NODEPTR list);
void deleteFirst(NODEPTR& list);
void deleteLast(NODEPTR& list);
void deletePosition(NODEPTR& list, int pos);
void sortAscendingTC(NODEPTR &list);
void sortDescendingTC(NODEPTR& list);