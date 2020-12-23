#include<iostream>
#include<locale.h>
#include<Windows.h>
#include "queueTemplate.h"

int iTemp, element, num;
exampleClass* tempArr;
using namespace std;
exampleClass* arr;
int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Для начала работы укажите максимальный размер очереди: ";
	int queueSize;
	cin >> queueSize;

	Queue<exampleClass>* q = new Queue<exampleClass>(queueSize);
	cout << "\nОчередь была успешно инициализирована\n" << endl;

	int v;

	for (;;) {
		v = menu();

		switch (v) {

		case 1: //добавление элемента в конец очереди
			element;
			cout << "Введите новый элемент: ";
			cin >> element;
			if (q->addElement(element)) {
				cout << "\nЭлемент добавлен в конец очереди\n";
			}
			else
				cout << "\nОчередь переполнена\n";
			break;

		case 2: //удаление элемента из начала очереди
			if (q->removeElement()) {
				cout << "\nТекущий элемент был успешно удален: " << endl;
			}
			else
				cout << "\nНе получилось удалить элемент - очередь пуста" << endl;
			break; 

		case 3:
			iTemp = q->howMany();
			if (q->isEmpty()) {
				cout << "\nОчередь пуста\n";
				break;
			}
			else {

				cout << "\nВсего в очереди: " << iTemp << " элементов\n";
				cout << "Выберите номер элемента для печати: ";
				num;
				cin >> num;
				cout << "Элемент под номером " << num << " : " << (q->showElement(num)).item;
				
			}
			break;
		case 4: //печать всей очереди
			tempArr = new exampleClass[queueSize];
			tempArr = q->showQueue();
			
			for (int i = 0; i < q->howMany(); i++) {
				cout << i+1 <<": "<<  (tempArr[i]).item << endl;
			}
			cout << "\n";

			break; 

		case 5:
			if (q->isEmpty())
			{
				cout << "\nОчередь пуста!\n";
				break;
			}
			if (q->isFull())
			{
				cout << "\nОчередь переполнена: всего " << q->howMany() << " элементов\n";
				break;
			}

			cout << "\nВсего в очереди " << q->howMany() << " элементов\n";
			break;

		case 0:
			exit(1);
			break;
		}
	}
}
