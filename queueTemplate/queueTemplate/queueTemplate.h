#pragma once
#include<locale.h>
#include <iostream>
using namespace std;

int menu();

//���������������� �����

class exampleClass {
public:
	int item;
	int front = 0;
	int* itemArr;
	exampleClass(int size, int number=0) {
		item = number;
		itemArr = new int[size];
	}

	int& newItem(int item) {
		itemArr[front] = item;
		front++;

		return itemArr[front-1];
	}
};


template<class T> class Queue
{

private:
	T* queueArray;
	int front, rear; //"���������" �� ������ � ����� �������
	int size;
	int numEl = 0;

public:

	
	//�����������, ��� "���������" ��������������� �� -1
	Queue(int size = 1) {
		front = -1;
		rear = -1;
		this->size = size;
		queueArray = new T[size];
	}

	//�������� �� ��������������� �������
	bool isFull() {
		if (front == 0 && rear == size - 1)
		{
			return true;
		}

		if (front == rear + 1) {
			return true;
		}

		return false;
	}
	
	//�������� �� ������ �������
	bool isEmpty() {
		if (front == -1) 
			return true;
		else 
			return false;
	}


	//���������� �������� � ����� �������
	bool addElement(T newElement) {
		if (isFull()) {
			return false;
		}
		else {
			if (front == -1) front = 0;
			rear = (rear + 1) % size;
			queueArray[rear] = newElement;
			numEl++;
			return true;
			
			
		}
	}

	//�������� �������� �� ������ �������
	bool removeElement() {
		
		if (isEmpty()) {
			return false;
		}
		else {

			if (front == rear) { // �� ���� � ������� ������ ���� �������
				front = -1;
				rear = -1;
			} 
			else {
				front = (front + 1) % size;
			}
			numEl--;
			return true;
		}

	}

	//������� ��� ������ �������: �������� ���������� � ������ ������� � ������������ ��������������� ������
	T* showQueue() {
		T* arr = new T[numEl];
		int i, j = 0;
		for (i = front; i != rear; i = (i + 1) % size)
		{
			arr[j] = queueArray[i];
			j++;
		}
		arr[j] = queueArray[i];
		return arr;
	}
	
	//������� ������� �� ����� ������� ��� ��������� �������
	T showElement(int num) {
		return queueArray[(front+num-1)%size];
	}
	//��������������� �������: ���������� ���������� ��������� � �������
	int howMany() {
		return this->numEl;
	}

};
