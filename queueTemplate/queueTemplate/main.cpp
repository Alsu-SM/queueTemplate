#include<iostream>
#include<locale.h>
#include<Windows.h>
#include "queueTemplate.h"

int iTemp, element, num;
int* tempArr;
using namespace std;
exampleClass* arr;
int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Для начала работы укажите максимальный размер очереди: ";
	int queueSize;
	cin >> queueSize;

	//Queue<exampleClass>* q = new Queue<exampleClass>(queueSize);
	Queue<int>* q1 = new Queue<int>(queueSize);
	exampleClass* e = new exampleClass(queueSize*2);
	cout << "\nОчередь была успешно инициализирована\n" << endl;

	int v;

	for (;;) {
		v = menu();

		switch (v) {

		case 1: //добавление элемента в конец очереди
			element;
			cout << "Введите новый элемент: ";
			cin >> element;
			if (q1->addElement(e->newItem(element))) {
				cout << "\nЭлемент добавлен в конец очереди\n";
			}
			else
				cout << "\nОчередь переполнена\n";
			break;

		case 2: //удаление элемента из начала очереди
			if (q1->removeElement()) {
				cout << "\nТекущий элемент был успешно удален: " << endl;
			}
			else
				cout << "\nНе получилось удалить элемент - очередь пуста" << endl;
			break; 

		case 3:
			iTemp = q1->howMany();
			if (q1->isEmpty()) {
				cout << "\nОчередь пуста\n";
				break;
			}
			else {

				cout << "\nВсего в очереди: " << iTemp << " элементов\n";
				cout << "Выберите номер элемента для печати: ";
				num;
				cin >> num;
				cout << "Элемент под номером " << num << " : " << (q1->showElement(num));
				
			}
			break;
		case 4: //печать всей очереди
			tempArr = new int[queueSize];
			tempArr = q1->showQueue();
			if (q1->isEmpty())
			{
				cout << "\nОчередь пуста";
				break;
			}
			for (int i = 0; i < q1->howMany(); i++) {
				cout << i+1 <<": "<<  (tempArr[i]) << endl;
			}
			cout << "\n";

			break; 

		case 5:
			if (q1->isEmpty())
			{
				cout << "\nОчередь пуста!\n";
				break;
			}
			if (q1->isFull())
			{
				cout << "\nОчередь переполнена: всего " << q1->howMany() << " элементов\n";
				break;
			}

			cout << "\nВсего в очереди " << q1->howMany() << " элементов\n";
			break;

		case 0:
			exit(1);
			break;
		}
	}
}
