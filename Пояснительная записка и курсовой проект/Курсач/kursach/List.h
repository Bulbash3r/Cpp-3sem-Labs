#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "Income.h"
#include "Consum.h"
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
		template<typename T> friend class Iterator;
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

		//����� ������
		long size()
		{
				return this->amount;
		}

		//���������� � ������
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
		//��������� � �����
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

		//�������� �� ������
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
		//�������� �� ������
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

		// ������������ ������ � ��������
		T &operator[](long num)
		{
				Node<T> *curr = head;
				if (num < 0 || num >= amount) return curr->data;
				for (long i = 0; i < num; i++)
						curr = curr->next;
				return curr->data;
		}

		// �������� �������� �� ������
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

		double getBalance(List<Income> &income, List<Consum> &consum)
		{
				double tempBalance=0;
				if (income.size()>0)
				for (Iterator<Income> i = income.begin(); i != Iterator <Income>(income.end()); i++)
				{
						tempBalance += (*i).getSum();
				}
				if(consum.size()>0)
				for (Iterator<Consum> j = consum.begin(); j != Iterator<Consum>(consum.end()); j++)
				{
						tempBalance -= (*j).getSum();
				}
				return tempBalance;
		}

		// ������� ��� ������ � ����������
		Node<T> *begin()
		{
				return head;
		}
		Node<T> *end()
		{
				if (tail != nullptr) return tail->next;
				return tail;
		}

		// ����� �� ����� ����������� ������
		void List<T>::output() 
		{
				int i = 0;
				if (!head) cout << "������ ����!";
				else
						for (Node<T> *node = head; node != nullptr; node = node->next)
						{
								cout << setw(3) << i+1 << node->data;
								cout << endl;
								i++;
						}
		}
		//����� �� ����
		void List<T>::output_for_type(int _type)
		{
				int i = 0;
				if (!head) cout << "������ ����!";
				else
						for (Node<T> *node = head; node != nullptr; node = node->next)
						{
								if (node->data.getType() == _type)
								{
										cout << setw(3) << i + 1 << node->data;
										cout << endl;
										i++;
								}
						}
		}
};

template <typename T>
class Iterator
{
		Node<T> *current;
public:
		Iterator()
		{
				current = nullptr;
		}
		Iterator(List<T> &container)
		{
				current = container.head;
		}
		Iterator(Iterator<T> &iter)
		{
				current = iter.current;
		}
		Iterator(Node<T> *node)
		{
				current = node;
		}
		~Iterator() {}

		// ��������� ���� �� ���������
		Node<T> *get_node()
		{
				return current;
		}

		// ����� ���������
		bool operator++(int i)
		{
				if (current == nullptr) return false;
				current = current->next;
				return true;
		}
		bool operator--(int i)
		{
				if (current->prev == nullptr) return false;
				current = current->prev;
				return true;
		}
		// ��������� �������� �� ���������
		T &operator*()
		{
				return current->data;
		}

		bool operator==(Iterator &iter)
		{
				if (current == nullptr && iter.current == nullptr)
						return true;
				if (current == nullptr || iter.current == nullptr)
						return false;
				if (current->data == iter.current->data && current->next == iter.current->next && current->prev == iter.current->prev)
						return true;
				return false;
		}
		bool operator!=(Iterator &iter)
		{
				if (current == nullptr && iter.current == nullptr)
						return false;
				if ((current == nullptr && iter.current != nullptr) || (current != nullptr && iter.current == nullptr))
						return true;
				if (current->data == iter.current->data && current->next == iter.current->next && current->prev == iter.current->prev)
						return false;
				return true;
		}
};