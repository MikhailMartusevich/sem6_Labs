#ifndef LIST_H
#define LIST_H
#include <iostream>

template <typename T>
class List {
public:
	List() = default; // default constructor
	void push_back(T data); 
	void push_front(T data);
	void pop_front();
	
	T& operator[](const int index);
	friend std::ostream& operator<< (std::ostream& msg, const List<T> lst) {
			if (lst.head == nullptr)
				throw ("list is empty");

			Element* temp = lst.head;
			msg << "{ ";
			while (temp->nextptr != nullptr) {
				msg << temp->data << ", ";
				temp = temp->nextptr;
			}
			msg << temp->data << " }";
			return msg;
	}

	bool operator==(const List<T>& b);
	void operator+(T data);
	void operator--();


private:
	class Element { // node of list class
	public:
		Element* nextptr{ nullptr };
		T data;
		Element(T data = T(), Element* nextptr = nullptr) {
			this->data = data;
			this->nextptr = nextptr;
		}
	};
	size_t size{ 0 }; // size of list
	Element* head{ nullptr }; // head pointer;
};

template <typename T>
void List<T>::push_back(T data) {
	if (head == nullptr)
		head = new Element(data);
	else {
		Element* temp = this->head;

		while (temp->nextptr != nullptr)
			temp = temp->nextptr;

		temp->nextptr = new Element(data);
	}

	size++;
}
template <typename T>
void List<T>::push_front(T data) {
	if (head == nullptr) 
		head = new Element(data);
	else {
		Element* temp = this->head;
		head = new Element(data, temp);
	}

	size++;
}

template <typename T>
void List<T>::pop_front() {
	if (size > 0) {
		Element* temp = this->head;
		head = head->nextptr;
		delete temp;
		size--;
	}
	else
		throw ("Out of range pop_front");
}

template<typename T>
T& List<T>::operator[](const int index) {
	size_t tempcount = { 0 };
	Element* temp = this->head;
	while (temp != nullptr)
	{
		if (tempcount == index)
		{
			return temp->data;
		}
		temp = temp->nextptr;
		tempcount++;
	}
}

template<typename T>
bool List<T>::operator==(const List<T>& b) {
		if (size == 0 && b.size == 0)
			throw ("Lists are empty");

		if (size == b.size)
		{
			Element* tempa = head;
			Element* tempb = b.head;
			while ((tempa->nextptr != nullptr) && (tempb->nextptr != nullptr))
			{
				if (tempa->data != tempb->data) return false;
				tempa = tempa->nextptr;
				tempb = tempb->nextptr;
			}
			if (tempa->data != tempb->data) return false;
			return true;
		}
		else return false;
}

template<typename T>
void List<T>::operator+(T data) {
	this->push_front(data);
}

template<typename T>
void List<T>::operator--() {
	this->pop_front();
}

#endif // !LIST_H
