#pragma once
#include<locale.h>
#include <iostream>
using namespace std;

int menu();

//пользовательский класс

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
	int front, rear; //"указатели" на начало и конец очереди
	int size;
	int numEl = 0;

public:

	
	//конструктор, оба "указателя" устанавливаются на -1
	Queue(int size = 1) {
		front = -1;
		rear = -1;
		this->size = size;
		queueArray = new T[size];
	}

	//проверка на переполненность очереди
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
	
	//проверка на пустую очередь
	bool isEmpty() {
		if (front == -1) 
			return true;
		else 
			return false;
	}


	//добавление элемента в конец очереди
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

	//удаление элемента из начала очереди
	bool removeElement() {
		
		if (isEmpty()) {
			return false;
		}
		else {

			if (front == rear) { // то есть в очереди только один элемент
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

	//функция для печати очереди: элементы копируются в нужном порядке в возвращаемый вспомогательный массив
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
	
	//функция выводит на экран элемент под указанным номером
	T showElement(int num) {
		return queueArray[(front+num-1)%size];
	}
	//вспомогательная функция: возвращает количество элементов в очереди
	int howMany() {
		return this->numEl;
	}

};
