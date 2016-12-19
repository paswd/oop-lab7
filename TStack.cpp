#include "TStack.h"

template <class T> TStack<T>::TStack() : head(NULL) {
}
template <class T> std::ostream& operator<<(std::ostream& os, const TStack<T>& stack) {
	std::shared_ptr<TStackItem<T>> item = stack.head;

	while(item != NULL) {
		os << *item;
		item = item->GetNext();
	}

	return os;
}
template <class T> void TStack<T>::push(std::shared_ptr<T> &&item) {
	std::shared_ptr<TStackItem<T>> other(new TStackItem<T>(item));
	other->SetNext(head);
	head = other;
}
template <class T> bool TStack<T>::empty() {
	return head == NULL;
}
template <class T> std::shared_ptr<T> TStack<T>::pop() {
	std::shared_ptr<T> result;
	if (head != NULL) {
		result = head->GetItem();
		head = head->GetNext();
	}
	return result;
}

template <class T> TIterator<TStackItem<T>,T> TStack<T>::begin()
{
	return TIterator<TStackItem<T>,T>(head);
}
template <class T> TIterator<TStackItem<T>,T> TStack<T>::end()
{
	return TIterator<TStackItem<T>,T>(NULL);
}

template <class T> TStack<T>::~TStack() {

}


extern "C" Vector* new_vector() {
    return new Vector;
}
extern "C" void delete_vector(Vector *tmp) {
    delete tmp;
}


template class TStack<Figure>;
template std::ostream& operator<<(std::ostream& os, const TStack<Figure>&
stack);
