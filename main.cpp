#include"Header.h"
#include<string>
int main() {
	subject sub;
	NODEPTR list = NULL, tail= NULL;
era:
	while (1) {
		cout << "\n---------------------------------\n";
		cout << "\n1.Them dau .";
		cout << "\n2.Them cuoi .";
		cout << "\n3.Xuat danh sach ";
		cout << "\n4.Tim Min Tin Chi ";
		cout << "\n5.Tim Max Tin Chi ";
		cout << "\n6.Tim Ma mon hoc ";
		cout << "\n7.Them sau node Q ";
		cout << "\n8.Xoa node dau tien";
		cout << "\n9.Xoa node cuoi cung";
		cout << "\n10.Xoa node bat ky";
		cout << "\n0.Exit!";
		cout << "\nLua chon : ";
		int option;
		cin >> option;
		cout << "\n---------------------------------\n";
		if (option == 1) {
			inSubject(sub);
			addFront(list, sub);
		}
		else if (option == 2) {
			inSubject(sub);
			addBack(list, sub);
		}
		else if (option == 3) {
			print_List(list);
		}
		else if(option == 4)
		{
			findMinTC(list);
			
		}
		else if(option == 5)
		{
			findMaxTC(list);
		
		}
		else if (option == 6)
		{	
			findCode(list);
		}
		else if(option == 7)
		{
			subject less;
			int position;
			cout << "\nNhap vi tri can chen";
			cin >> position;
			if (position < 1|| position > countNode(list)) {
				cout << "\nVi tri khong hop le!";
				goto era;
			}
			inSubject(less);
			insertNode(list, position, less);
			
		}
		else if (option == 8) {
			deleteFirst(list);
		}
		else if (option == 9) {
			deleteLast(list);
		}
		else if (option == 10) {
			int posy;
			cout << "\nNhap vi tri can xoa:  ";
			cin >> posy;
			if (posy<1 || posy>countNode(list)) {
				cout << "\nVi tri khong hop le";
				goto era;
			}
			deletePosition(list, posy);
		}
		else
		{
			break;
		}
	}
	return 0;
}