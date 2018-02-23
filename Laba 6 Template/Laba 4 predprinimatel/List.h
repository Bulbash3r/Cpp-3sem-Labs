#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

template<typename T>
struct Node
{
		T data;
		Node<T> *next;
		Node<T> *prev;
};

template<typename T>
class List
{
protected:
		Node<T> *head;
		Node<T> *tail;
		long amount;
public:
		List()
		{
				head = nullptr;
				tail = nullptr;
				amount = 0;
		}
		~List()
		{
				while (head)
				{
						this->pop_head();
				}
		}

		//Длина списка
		long size()
		{
				return this->amount;
		}

		//Добавление с головы
		void push_head(T input_object)
		{
				if (head == nullptr)
				{
						head = new Node<T>;
						head->data = input_object;
						head->next = nullptr;
						head->prev = nullptr;
						tail = head;
						amount++;
						return;
				}
				Node<T> *node = new Node<T>;
				node->data = input_object;
				node->next = head;
				node->prev = nullptr;
				head->prev = node;
				head = node;
				amount++;
				return;
		}

		//Добавление в хвост
		void push_tail(T input_object)
		{
				if (head == nullptr)
				{
						head = new Node<T>;
						head->data = input_object;
						head->next = nullptr;
						head->prev = nullptr;
						tail = head;
						amount++;
						return;
				}
				Node<T> *node = new Node<T>;
				node->data = input_object;
				node->next = nullptr;
				node->prev = tail;
				tail->next = node;
				tail = node;
				amount++;
				return;
		}

		//Удаление от головы
		T pop_head()
		{
				if (!(head)) return T();
				T data = head->data;
				Node<T> *node = head;
				head = head->next;
				if (head)
						head->prev = nullptr;
				delete node;
				amount--;
				return data;
		}

		//Удаление из хвоста
		T pop_tail()
		{
				if (!(head)) return T();
				T data = tail->data;
				Node<T> *node = tail;
				tail = tail->prev;
				if (tail)
						tail->next = nullptr;
				delete node;
				amount--;
				return data;
		}

		// произвольный доступ к объектам
		T &operator[](long num)
		{
				Node<T> *curr = head;
				if (num < 0 || num >= amount) return curr->data;
				for (long i = 0; i < num; i++)
						curr = curr->next;
				return curr->data;
		}

		// удаление элемента из списка
		void delete_element(Node<T> *node)
		{
				if (head == node) head = head->next;
				if (tail == node) tail = tail->prev;
				if (node->next != nullptr) node->next->prev = node->prev;
				if (node->prev != nullptr) node->prev->next = node->next;
				delete node;
				node = nullptr;
				this->amount--;
		}

		// вывод на экран содержимого списка
		void List<T>::output()
		{
				int i = 0;
				if (!head) cout << "Список пуст!";
				else for (Node<T> *node = head; node != nullptr; node = node->next)
						 {
								cout << node->data;
								i++;
						 }
		}

		void sort()
		{
				Node<T> *cur = head;
				while (cur->next)
				{
						if ((cur->data.getAge()) > (cur->next->data.getAge()))
						{
								cTourist temp = cur->next->data;
								cur->next->data = cur->data;
								cur->data = temp;

								cur = cur->next;
								sort();
						}
						else { cur = cur->next; }
				}
		}
};