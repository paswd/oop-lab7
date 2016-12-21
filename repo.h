#ifndef REPO_H
#define REPO_H

#include "TStack.h"
#include "n-tree.h"
#include "square.h"
#include "trapeze.h"
#include "rectangle.h"

class Repo {
private:
	TStack <NTree <Figure>> stack;

public:
	Repo(void);
	~Repo(void);

	//Добавление
	void Push(std::shared_ptr<Figure> &&item);
	//Проверка на пустоту
	bool empty();
	//Удаление
	std::shared_ptr<Figure> Pop(size_t param);

	friend std::ostream& operator<<(std::ostream& os,const Repo& repo);
};

#endif
