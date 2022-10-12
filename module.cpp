#include"Header.h"
NODEPTR makeNode(subject sub) {
	NODEPTR p = new NODE;
	p->data = sub;
	p->next = NULL;
	return p;
}
void inSubject(subject& sub) {
	cin.ignore();
	cout << "\nNhap ten sach : ";
	cin.getline(sub.name, 20);

	cout << "\nNhap ma : ";
	cin.getline(sub.code,20);
	cout << "\nNhap so tin chi : ";
	cin >> sub.TC;
}
void outSubject(subject sub) {
	cout << "\nMon hoc :" << sub.name;
	cout << "\tMa : " << sub.code;
	cout << "\t\tSo tin chi : " << sub.TC;
}
void addFront(NODEPTR& list, subject sub) {
	NODEPTR p = makeNode(sub);
	if (list == NULL)
	{
		list = p;
		return;
	}
	p->next = list;
	list = p;
}
void addBack(NODEPTR& list, subject sub) {
	NODEPTR p = makeNode(sub);
	if (list == NULL)
	{
		addFront(list, sub);
		return;
	}
	NODEPTR temp = list;
	//duyet tu dau den cuoi danh sach, neu next tro toi null thi gan temp->next = p
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = p;
}
void print_List(NODEPTR list) {
	while (list != NULL) {
		outSubject(list->data);
		list = list->next;
	}
}
void findMinTC(NODEPTR list) {
	NODEPTR  min;
	min = list;
	//if list only have a node, cout it
	if (list->next == NULL) {
		outSubject(min->data);
		return;
	}
	while (list != NULL)
	{
		if (min->data.TC > list->data.TC) {
			min = list;
		
		}
		list = list->next;
		
	}
	outSubject(min->data);
}
void findMaxTC(NODEPTR list) {
	NODEPTR  max;
	max = list;
	//if list only have a node, cout it
	if (list->next == NULL) {
		outSubject(max->data);
		return;
	}
	while (list != NULL)
	{
		if (max->data.TC < list->data.TC) {
			max = list;
			
		}
		list = list->next;
		
	}
	outSubject(max->data);
}
NODEPTR findCode(NODEPTR list) {
	NODEPTR p = list;
	char maMon[20];
	cout << "Nhap ma so can tim: ";
	cin.ignore();
	cin.getline(maMon,20);
	while (p!=NULL)
	{
		if (_strcmpi(p->data.code, maMon)==0) {
			outSubject(p->data);
		}
		p = p->next;
	}
	return NULL;
}
NODEPTR addAfterQ(NODEPTR& list, NODEPTR q, subject sub) {
	NODEPTR p;
	p = makeNode(sub);
	if (q == NULL) {
		addFront(list, sub);
	}
	else 
	{
		p->next = q->next;
		q->next = p;
	}
	return p;
}
int countNode(NODEPTR list) {
	NODEPTR q = list;
	int countOfNode = 0;
	for (NODEPTR k = q; k != NULL; k = k->next) {
		countOfNode++;
	}
	return countOfNode;
}
void insertNode(NODEPTR& list, int pos, subject sub) {
	NODEPTR p = makeNode(sub);
	NODEPTR q = list;
	int i = 1;
	while (q!=NULL)
	{
		if (i == pos) {
			p->next = q->next;
			q->next = p;
			}
		i++;
		q = q->next;
	}
}
void deleteFirst(NODEPTR& list) {
	NODEPTR p=list;//con tro p tro den dau danh sach
	if (list!=NULL)
	{
		list = list->next;//doi dau danh sach sang thang thu 2
		delete p;//xoa thang dau
	}
}
void deleteLast(NODEPTR& list)
{
	NODEPTR last = list;
	if (list == NULL) {
		return;
	}
	if (last->next== NULL) {
		list = NULL;
		delete last;
		return;
	}
	//tim thang gan cuoi
	while (last->next->next!=NULL)
	{
		last = last->next;
	}
	//xoa thang cuoi danh sach
	delete last->next;
	//cap nhat lai gan cuoi thanh cuoi danh sach
	last->next = NULL;
}
void deletePosition(NODEPTR& list, int pos) {
	NODEPTR temp = list;
	
	if (list == NULL) {
		return;
	}
	else if (pos == 1) {
		deleteFirst(list);
	}
	else
	{
		for (int i = 1; i <= pos - 2; i++) {
			temp = temp->next;
		}
		//temp: pos -1
		NODEPTR	eraser = temp->next;//node can xoa
		//cho thang truoc eraser tro den thang sau eraser
		temp->next = eraser->next;
		delete eraser;
	}
}
void sortAscendingTC(NODEPTR& list) {
	NODEPTR p = list;
	NODEPTR q = p->next;
	while (p->next!=NULL)
	{
		q = p->next;
		while (q!=NULL)
		{
			if (p->data.TC > q->data.TC)
				swap(p->data, q->data);
			q = q->next;
		}
		p = p->next;
	}
}
void sortDescendingTC(NODEPTR& list) {
	NODEPTR p = list;
	NODEPTR q = p->next;
	while (p->next != NULL)
	{
		q = p->next;
		while (q != NULL)
		{
			if (p->data.TC < q->data.TC)
				swap(p->data, q->data);
			q = q->next;
		}
		p = p->next;
	}
}