#include <iostream>
using namespace std;

void mediumLevel()
{
	string line = "";

	cout << "Enter some symbols" << endl;
	cin >> line;
	cout << endl;

	for (size_t i = 0; i < line.length(); i++)
	{
		if (line[i] == '!')
			line.insert(i, 1, ','), i++;
	}

	cout << line;
}

void highLevelTask()
{
	string line = "";

	bool displayed = false;
	unsigned short counter = 0;

	cout << "Enter some symbols:" << endl;
	cin >> line;
	cout << endl;

	for (size_t i = 0; i < line.length(); i++) // Подсчет количества символов
	{
		displayed = false;
		counter = 0;

		for (size_t j = 0; j < i; j++) // Проверка, не был ли символ выведен ранее
		{
			if (line[i] == line[j])
				displayed = true;
		}

		if (!displayed) // Если символ не был выведен, то считаем сколько таких же
		{
			for (size_t j = i; j < line.length(); j++)
			{
				if (line[i] == line[j])
					counter++;
			}

			cout << "Amount of '" << line[i] << "' is " << counter << endl;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Choose task: 1)medium level 2)high level" << endl;
	unsigned short choose = 0;

tryAgain:
	cin >> choose;

	switch (choose)
	{
	case 1:
		mediumLevel();
		break;
	case 2:
		highLevelTask();
		break;
	default:
		cout << "Try again" << endl;
		goto tryAgain;
		break;
	}
}