#include "wrapper.h"

Wrapper::Wrapper(int numMin,
	int numMax,
	int numMed)
{

}

Wrapper::~Wrapper()
{

}

void Wrapper::runApp()
{
	string select = "";
	bool exit = false;

	while (exit == false)
	{
		select = displayMenu();
		if (select == "input1.txt")
		{
			cout << "REPORT" << endl;

			auto start = high_resolution_clock::now();
			readFile1();
			auto stop = high_resolution_clock::now();
			auto durationTimeInsert = duration_cast<microseconds>(stop - start);
			cout << "Time Insert: " << durationTimeInsert.count() << " microseconds" << endl;

			cout << "Minimum Num: " << numMin << endl;
			cout << "Maximum Num: " << numMax << endl;
			cout << "Median Num: " << numMed << endl;

			system("pause");
			system("cls");

			exit = true;
		}

		else if (select == "input2.txt")
		{
			cout << "REPORT" << endl;

			auto start2 = high_resolution_clock::now();
			readFile2();
			auto stop2 = high_resolution_clock::now();
			auto durationTimeInsert = duration_cast<microseconds>(stop2 - start2);
			cout << "Time Insert: " << durationTimeInsert.count() << " microseconds" << endl;

			cout << "Minimum Num: " << numMin << endl;
			cout << "Maximum Num: " << numMax << endl;
			cout << "Median Num: " << numMed << endl;

			system("pause");
			system("cls");
			exit = true;
		}

		else
		{
			cout << "INPUT INVALID !" << endl;
		}
	}

}

string Wrapper::displayMenu()
{
	string select = "";

	cout << "Enter File Name:" << endl;
	cout << "";
	cin >> select;
	system("cls");

	return select;
}

//reads the file for input1.txt
bool Wrapper::readFile1()
{
	bool success = false;

	int i = 0;

	List *pList = nullptr;
	Node * pMem = nullptr;
	Node *mNext = nullptr;

	int iNum = 0;

	fstream thousandList("input1.txt");

	while (!thousandList.eof())
	{
		pMem = new Node;
		thousandList >> *pMem;
		pMem->setNext(mpHead);
		mpHead = pMem;
		i++;
	}

	auto start3 = high_resolution_clock::now();
	findMin();
	auto stop3 = high_resolution_clock::now();
	auto durationTimeMin = duration_cast<microseconds>(stop3 - start3);
	cout << "Time To Find Minimum: " << durationTimeMin.count() << " microseconds" << endl;

	auto start4 = high_resolution_clock::now();
	findMax();
	auto stop4 = high_resolution_clock::now();
	auto durationTimeMax = duration_cast<microseconds>(stop4 - start4);
	cout << "Time To Find Maximum: " << durationTimeMax.count() << " microseconds" << endl;

	auto start5 = high_resolution_clock::now();
	findMed(i);
	auto stop5 = high_resolution_clock::now();
	auto durationTimeMed = duration_cast<microseconds>(stop5 - start5);
	cout << "Time To Find Median: " << durationTimeMed.count() << " microseconds" << endl;

	success = true;
	return success;
}

//reads the file for input2.txt
bool Wrapper::readFile2()
{
	bool success = false;

	int i = 0;

	List *pList = nullptr;
	Node * pMem = nullptr;
	Node *mNext = nullptr;

	int iNum = 0;

	fstream millionList("input2.txt");

	while (!millionList.eof())
	{
		pMem = new Node;
		millionList >> *pMem;
		pMem->setNext(mpHead);
		mpHead = pMem;
		i++;
	}

	auto start7 = high_resolution_clock::now();
	findMin();
	auto stop7 = high_resolution_clock::now();
	auto durationTimeMin = duration_cast<microseconds>(stop7 - start7);
	cout << "Time To Find Minimum: " << durationTimeMin.count() << "microseconds" << endl;

	auto start8 = high_resolution_clock::now();
	findMax();
	auto stop8 = high_resolution_clock::now();
	auto durationTimeMax = duration_cast<microseconds>(stop8 - start8);
	cout << "Time To Find Maximum: " << durationTimeMax.count() << "microseconds" << endl;

	auto start9 = high_resolution_clock::now();
	findMed(i);
	auto stop9 = high_resolution_clock::now();
	auto durationTimeMed = duration_cast<microseconds>(stop9 - start9);
	cout << "Time To Find Median: " << durationTimeMed.count() << "microseconds" << endl;

	success = true;
	return success;
}

//sorting out to find the min
bool Wrapper::findMin()
{
	bool success = false;
	Node *pPrev = mpHead, *pCur = nullptr, *pTemp = new Node;

	for (pPrev = mpHead; pPrev != nullptr; pPrev = pPrev->getNext())
	{
		for (pCur = pPrev->getNext(); pCur != nullptr; pCur = pCur->getNext())
		{
			if (pPrev->getNumbers() < pCur->getNumbers())
			{
				success = true;
				pTemp->setNumbers(pPrev->getNumbers());
				pPrev->setNumbers(pCur->getNumbers());
				pCur->setNumbers(pTemp->getNumbers());
			}
		}
	}

	numMin = pTemp->getNumbers();

	return success;
}

//sorting out to find the max
bool Wrapper::findMax()
{
	bool success = false;
	Node *pPrev = mpHead, *pCur = nullptr, *pTemp = new Node;

	for (pPrev = mpHead; pPrev != nullptr; pPrev = pPrev->getNext())
	{
		for (pCur = pPrev->getNext(); pCur != nullptr; pCur = pCur->getNext())
		{
			if (pPrev->getNumbers() > pCur->getNumbers())
			{
				success = true;
				pTemp->setNumbers(pPrev->getNumbers());
				pPrev->setNumbers(pCur->getNumbers());
				pCur->setNumbers(pTemp->getNumbers());
			}
		}
	}

	numMax = pTemp->getNumbers();

	return success;
}

//finding the median
bool Wrapper::findMed(int middle)
{
	bool success = false;

	Node *pCur = mpHead, *pNext = nullptr;

	for (int i = 0; i != (middle / 2) + 1; i++) //stops in the middle
	{

		if (pCur != nullptr)
		{
			numMed = pCur->getNumbers();
			pCur = pCur->getNext();
			success = true;
		}

		else
		{
			break;
		}
	}
	
	return success;
}