#ifndef NTREE_H
#define NTREE_H

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <memory>

template <class T> class Cluster {
public:
	std::shared_ptr<T> Element;
	size_t Param;
	bool IsEmpty;
	bool IsOverload;

	Cluster(void);
	~Cluster(void);

	//Cluster<T>& operator=(Cluster<T> &arrInt2);
};


template <class T> class NTreeNode {
public:
	std::vector <Cluster <T>> Clusters; //Элементы на одной высоте дерева
	NTreeNode<T> *Parent; //Ссылка на родителя
	NTreeNode<T> *Child; //Ссылка на потомка
	size_t Level; //Текущая высота
	size_t ClustersCnt;
};

template <class T> class NTree {
private:
	NTreeNode<T> *Root; //Корень дерева
	size_t NConst; //Максимальное число потомков у одного листа
	size_t MaxLevelsCnt;

public:
	//Methods
	NTree(void); //Конструктор аллокатора
	~NTree(void); //Деструктор аллокатора

	Cluster<T> Push(std::shared_ptr<T> element, size_t param);
	std::shared_ptr<T> Pop(size_t param);

	bool IsEmpty(void);

	template <class A> friend std::ostream& operator<<(std::ostream& os,const NTree<A>& ntree);
};

#endif /* FIGURE_H */
