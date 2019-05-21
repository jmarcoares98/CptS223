#include "VectorMyJosephus.h"

int main(void)
{
	VectorMyJosephus start;

	for (int i = 4; i <= 1024; i = i * 2)
	{
		start.init(i, 3);
		start.wrapper();
		cout << endl;
	}

	cout << endl;
	cout << endl;

    cout << "Experiment 2" << endl;
	for (int i = 2; i <= 1024; i = i * 2)
	{
		start.init(1024, i);
		start.wrapper();
		cout << endl;
	}

	cout << "Experiment Complete!" << endl;
	system("pause");
	return 0;
}