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

	cout << "��� ������ ������ ������� ������������ ������ �������: ";
	int queueSize;
	cin >> queueSize;

	Queue<exampleClass>* q = new Queue<exampleClass>(queueSize);
	cout << "\n������� ���� ������� ����������������\n" << endl;

	int v;

	for (;;) {
		v = menu();

		switch (v) {

		case 1: //���������� �������� � ����� �������
			element;
			cout << "������� ����� �������: ";
			cin >> element;
			if (q->addElement(element)) {
				cout << "\n������� �������� � ����� �������\n";
			}
			else
				cout << "\n������� �����������\n";
			break;

		case 2: //�������� �������� �� ������ �������
			if (q->removeElement()) {
				cout << "\n������� ������� ��� ������� ������: " << endl;
			}
			else
				cout << "\n�� ���������� ������� ������� - ������� �����" << endl;
			break; 

		case 3:
			iTemp = q->howMany();
			if (q->isEmpty()) {
				cout << "\n������� �����\n";
				break;
			}
			else {

				cout << "\n����� � �������: " << iTemp << " ���������\n";
				cout << "�������� ����� �������� ��� ������: ";
				num;
				cin >> num;
				cout << "������� ��� ������� " << num << " : " << (q->showElement(num)).item;
				
			}
			break;
		case 4: //������ ���� �������
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
				cout << "\n������� �����!\n";
				break;
			}
			if (q->isFull())
			{
				cout << "\n������� �����������: ����� " << q->howMany() << " ���������\n";
				break;
			}

			cout << "\n����� � ������� " << q->howMany() << " ���������\n";
			break;

		case 0:
			exit(1);
			break;
		}
	}
}
