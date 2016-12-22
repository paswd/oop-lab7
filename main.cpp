#include <iostream>
#include "square.h"
#include "trapeze.h"
#include "rectangle.h"
#include "repo.h"

using namespace std;

int main(void)
{
	//Trepo *repo = new Trepo;
	Repo repo;
	cout << "-------------------------------------------\n";
	cout << "Commands:\n";
	cout << "s <value> - push Square to repo\n";
	cout << "t <value> - push Trapeze to repo\n";
	cout << "r <value> - push Rectangle to repo\n";
	cout << "d <square> - pop from repo and print popped item\n";
	cout << "p - print repo\n";
	cout << "q - exit\n";
	cout << "-------------------------------------------\n";
	//int cnt = 0;
	while (true) {
		//cout << "%d\n", cnt;
		//cnt++;
		char cmd;
		size_t param;
		std::shared_ptr<Figure> value;
		bool is_finished = false;
		scanf("%c", &cmd);
		switch (cmd) {
			case 'q':
				is_finished = true;
				break;
			case 's':
				//value = (Item) FSquare(std::cin);
				//value 
				//cin >> value;
				repo.Push(std::make_shared <FSquare> (cin));
				break;
			case 't':
				//value = (Item) FSquare(std::cin);
				//cin >> value;
				repo.Push(std::make_shared <Trapeze> (cin));
				break;
			case 'r':
				//value = (Item) FSquare(std::cin);
				//cin >> r_value;
				repo.Push(std::make_shared <Rectangle> (cin));
				break;
			case 'd':

				cin >> param;
				value = repo.Pop(param);
				if (value != NULL)
					cout << *value << endl;
				break;
			case 'p':
				//repo.Print();
				cout << repo << endl;
				break;
			case '\n':
				break;
			default:
				cout << "Invalid command " << cmd << "\n";
				break;
		}
		if (is_finished) break;
	}
	cout << "Goodbye!\n";

	//delete repo;

	return 0;
}
