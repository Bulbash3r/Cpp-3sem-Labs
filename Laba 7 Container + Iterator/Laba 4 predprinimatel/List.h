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
		void pop_head()
		{
				Iterator<T> it = this->begin();
				this->delete_element(it.get_node());
		}
		//�������� �� ������
		void pop_tail()
		{
				Iterator<T> it = this->end();
				this->delete_element(it.get_node());
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
		// ����� �� ����� ����������� ������
		void List<T>::output()
		{
				Iterator<T> i = this->begin();
				Iterator<T> j = this->end();
				j++;
				do
				{
						cout << (*i);
						i++;
				} while (i != j);
		}
		// ������� ��� ������ � ����������
		Node<T> *begin()
		{
				return head;
		}
		Node<T> *end()
		{
				if (tail == nullptr) return tail->prev;
				return tail;
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
		bool operator+=(int j)
		{
				if (current == nullptr) return false;
				for (int i = 0; i < j; i++)
				{
						current = current->next;
				}
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






