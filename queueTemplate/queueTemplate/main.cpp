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

	cout << "��� ������ ������ ������� ������������ ������ �������: ";
	int queueSize;
	cin >> queueSize;

	//Queue<exampleClass>* q = new Queue<exampleClass>(queueSize);
	Queue<int>* q1 = new Queue<int>(queueSize);
	exampleClass* e = new exampleClass(queueSize*2);
	cout << "\n������� ���� ������� ����������������\n" << endl;

	int v;

	for (;;) {
		v = menu();

		switch (v) {

		case 1: //���������� �������� � ����� �������
			element;
			cout << "������� ����� �������: ";
			cin >> element;
			if (q1->addElement(e->newItem(element))) {
				cout << "\n������� �������� � ����� �������\n";
			}
			else
				cout << "\n������� �����������\n";
			break;

		case 2: //�������� �������� �� ������ �������
			if (q1->removeElement()) {
				cout << "\n������� ������� ��� ������� ������: " << endl;
			}
			else
				cout << "\n�� ���������� ������� ������� - ������� �����" << endl;
			break; 

		case 3:
			iTemp = q1->howMany();
			if (q1->isEmpty()) {
				cout << "\n������� �����\n";
				break;
			}
			else {

				cout << "\n����� � �������: " << iTemp << " ���������\n";
				cout << "�������� ����� �������� ��� ������: ";
				num;
				cin >> num;
				cout << "������� ��� ������� " << num << " : " << (q1->showElement(num));
				
			}
			break;
		case 4: //������ ���� �������
			tempArr = new int[queueSize];
			tempArr = q1->showQueue();
			if (q1->isEmpty())
			{
				cout << "\n������� �����";
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
				cout << "\n������� �����!\n";
				break;
			}
			if (q1->isFull())
			{
				cout << "\n������� �����������: ����� " << q1->howMany() << " ���������\n";
				break;
			}

			cout << "\n����� � ������� " << q1->howMany() << " ���������\n";
			break;

		case 0:
			exit(1);
			break;
		}
	}
}
