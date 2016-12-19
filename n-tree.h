#ifndef NTREE_H
#define NTREE_H

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>

template <class T> class Cluster {
	shared_ptr<T> Element;
	size_t Param;	
};


template <class T> class NTreeNode {
public:
	std::vector <std::shared_ptr<T>> Clusters; //Элементы на одной высоте дерева
	NTreeNode *Parent; //Ссылка на родителя
	NTreeNode *Child; //Ссылка на потомка
	size_t Level; //Текущая высота
	size_t ElementsCount;
};

template <class T> class NTree {
private:
	NTreeNode *Root; //Корень дерева
	size_t NConst; //Максимальное число потомков у одного листа
	size_t MaxLevelsCnt;

public:
	//Methods
	NTree(void); //Конструктор аллокатора
	~NTree(void); //Деструктор аллокатора

	bool Push(std::shared_ptr<T> element, size_t param);
	std::shared_ptr<T> Pop(size_t param);
};

#endif /* FIGURE_H */
