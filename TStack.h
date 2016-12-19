#ifndef TSTACK_H
#define TSTACK_H
#include "TStackItem.h"
#include "TIterator.h"
#include <iostream>
#include <memory>

template <class T> class TStack {
public:
	//Конструктор
	TStack();

	//Добавление в стек
	void push(std::shared_ptr<T> &&item);
	//Проверка на пустоту
	bool empty();
	//Удаление из стека
	std::shared_ptr<T> pop();

	//Итератор: начало
	TIterator<TStackItem<T>, T> begin();
	//Итератор: конец
	TIterator<TStackItem<T>, T> end();

	//Переопределение вывода
	template <class A> friend std::ostream& operator<<(std::ostream& os,const TStack<A>& stack);
	//Деструктор
	virtual ~TStack();
private:

	std::shared_ptr<TStackItem<T>> head;
};
#endif /* TSTACK_H */
