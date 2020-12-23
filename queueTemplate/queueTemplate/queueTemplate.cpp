#include<iostream>
#include<locale.h>
#include<Windows.h>
#include "queueTemplate.h"

using namespace std;

int v;

int menu() {

	cout << "\nЧто вы хотите сделать?\n" << endl;
	cout << "\n1 - добавить элемент в конец очереди";
	cout << "\n2 - удалить элемент из начала очереди";
	cout << "\n3 - показать текущий элемент";
	cout << "\n4 - показать всю очередь";
	cout << "\n5 - проверить заполненность очереди";
	cout << "\n\n0 - выход\n";

	for (;;) {
		cout << "\nВаш выбор: ";
		cin >> v;
		cout << "\n";

		if (v < 0 || v > 5) {
			cout << "\nПожалуйста, введите числа от 0 до 5.\n" << endl;
			continue;
		}

		return v;
	}

}