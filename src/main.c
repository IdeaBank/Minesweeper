#include <stdio.h>
#include <Windows.h>
#include <memory.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

void setPosition(int X, int Y)
{
	HANDLE Screen;
	Screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position = { Y, X };

	SetConsoleCursorPosition(Screen, Position);
}

void makeRandomArray(int* targetArray, int size, int amount)
{
	int count = 0;
	while (count < amount)
	{
		int x = rand() % size;
		int y = rand() % size;

		if (*(targetArray + x * size + y) == 0)
		{
			*(targetArray + x * size + y) = 1;
			count += 1;
		}
	}
}

void printToScreen(int* mineArray, int* checkedLocation, int size)
{
	system("cls");

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (*(mineArray + i * size + j) == 1 && *(checkedLocation + i * size + j) == 1)
			{
				printf("M");
				break;
			}

			if (*(checkedLocation + i * size + j) == 0)
				printf("X");

			else
			{
				int checkCount = 0;
				if (i == 0 && j == 0)	// 왼쪽 맨 위
				{
					if (*(mineArray + i * size + j + 1) == 1)
						checkCount += 1;

					if (*(mineArray + (i + 1) * size + j) == 1)
						checkCount += 1;

					if (*(mineArray + (i + 1) * size + j + 1) == 1)
						checkCount += 1;
				}

				else if (i == 0 && j == size - 1)	// 오른쪽 맨 위
				{
					if (*(mineArray + i * size + j - 1) == 1)
						checkCount += 1;

					if (*(mineArray + (i + 1) * size + j) == 1)
						checkCount += 1;

					if (*(mineArray + (i + 1) * size + j - 1) == 1)
						checkCount += 1;
				}

				else if (i == size - 1 && j == 0)	// 왼쪽 맨 아래
				{
					if (*(mineArray + i * size + j + 1) == 1)
						checkCount += 1;

					if (*(mineArray + (i - 1) * size + j) == 1)
						checkCount += 1;

					if (*(mineArray + (i - 1) * size + j + 1) == 1)
						checkCount += 1;
				}

				else if (i == size - 1 && j == size - 1)	// 오른쪽 맨 위
				{
					if (*(mineArray + i * size + j - 1) == 1)
						checkCount += 1;

					if (*(mineArray + (i - 1) * size + j) == 1)
						checkCount += 1;

					if (*(mineArray + (i - 1) * size + j - 1) == 1)
						checkCount += 1;
				}

				else if (i == 0) // 맨 위
				{
					if (*(mineArray + i * size + j - 1) == 1)
						checkCount += 1;

					if (*(mineArray + i * size + j + 1) == 1)
						checkCount += 1;

					if (*(mineArray + (i + 1) * size + j - 1) == 1)
						checkCount += 1;

					if (*(mineArray + (i + 1) * size + j) == 1)
						checkCount += 1;

					if (*(mineArray + (i + 1) * size + j + 1) == 1)
						checkCount += 1;
				}

				else if (j == 0) // 맨 왼쪽
				{
					if (*(mineArray + (i - 1) * size + j) == 1)
						checkCount += 1;

					if (*(mineArray + (i + 1) * size + j) == 1)
						checkCount += 1;

					if (*(mineArray + (i - 1) * size + j + 1) == 1)
						checkCount += 1;

					if (*(mineArray + i * size + j + 1) == 1)
						checkCount += 1;

					if (*(mineArray + (i + 1) * size + j + 1) == 1)
						checkCount += 1;
				}

				else if (i == size - 1) // 맨 아래
				{
					if (*(mineArray + i * size + j - 1) == 1)
						checkCount += 1;

					if (*(mineArray + i * size + j + 1) == 1)
						checkCount += 1;

					if (*(mineArray + (i - 1) * size + j - 1) == 1)
						checkCount += 1;

					if (*(mineArray + (i - 1) * size + j) == 1)
						checkCount += 1;

					if (*(mineArray + (i - 1) * size + j + 1) == 1)
						checkCount += 1;
				}

				else if (j == size - 1)	// 맨 오른쪽
				{
					if (*(mineArray + (i - 1) * size + j) == 1)
						checkCount += 1;

					if (*(mineArray + (i + 1) * size + j) == 1)
						checkCount += 1;

					if (*(mineArray + (i - 1) * size + j - 1) == 1)
						checkCount += 1;

					if (*(mineArray + i * size + j - 1) == 1)
						checkCount += 1;

					if (*(mineArray + (i + 1) * size + j - 1) == 1)
						checkCount += 1;
				}

				else // 나머지
				{
					if (*(mineArray + (i - 1) * size + j - 1) == 1)
						checkCount += 1;

					if (*(mineArray + (i - 1) * size + j) == 1)
						checkCount += 1;

					if (*(mineArray + (i - 1) * size + j + 1) == 1)
						checkCount += 1;

					if (*(mineArray + (i + 1) * size + j - 1) == 1)
						checkCount += 1;

					if (*(mineArray + (i + 1) * size + j) == 1)
						checkCount += 1;

					if (*(mineArray + (i + 1) * size + j + 1) == 1)
						checkCount += 1;

					if (*(mineArray + i * size + j - 1) == 1)
						checkCount += 1;

					if (*(mineArray + i * size + j + 1) == 1)
						checkCount += 1;
				}

				printf("%d", checkCount);
			}
		}
		printf("\n");
	}
}

void printAll(int* mineArray, int size)
{
	system("cls");

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (*(mineArray + i * size + j) == 0)
				printf("X");

			else
				printf("M");
		}

		printf("\n");
	}
}

int main()
{
	int size = 0;

	int* mineArray;
	int* checkedLocation;

	int currentLocation[2] = { 0, 0 };

	int mineAmount = 0;
	int mineFound = 0;
	int checkedCount = 0;

	char pressedKey = 0;

	srand(time(NULL));

	printf("Enter Size : ");
	scanf("%d", &size);

	while (!(1 <= size && size <= 10))
	{
		printf("The size should be between 1 and 10!\nPlease Enter size again : ");
		scanf("%d", &size);
	}

	printf("Enter mine amount : ");
	scanf("%d", &mineAmount);

	while (mineAmount >= size * size)
	{
		printf("Mine amount is greater than or equal to the limit!\nPlease Enter mine amount again : ");
		scanf("%d", &mineAmount);
	}

	mineArray = (int*)malloc(sizeof(int) * size * size);
	checkedLocation = (int*)malloc(sizeof(int) * size * size);

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			*(mineArray + i * size + j) = 0;
			*(checkedLocation + i * size + j) = 0;
		}
	}

	makeRandomArray(mineArray, size, mineAmount);
	printToScreen(mineArray, checkedLocation, size);

	while (checkedCount != size * size - mineAmount && mineFound == 0)
	{
		printToScreen(mineArray, checkedLocation, size);
		setPosition(currentLocation[0], currentLocation[1]);

		pressedKey = getch();

		switch (pressedKey)
		{
		case 'w':
			if (currentLocation[0] == 0)
				break;

			else
				currentLocation[0] -= 1;
			break;

		case 'a':
			if (currentLocation[1] == 0)
				break;

			else
				currentLocation[1] -= 1;

			break;

		case 's':
			if (currentLocation[0] == size - 1)
				break;

			else
				currentLocation[0] += 1;

			break;

		case 'd':
			if (currentLocation[1] == size - 1)
				break;

			else
				currentLocation[1] += 1;

			break;

		case '\r':	// Enter Key Pressed
			if (*(checkedLocation + currentLocation[0] * size + currentLocation[1]) == 1)
				break;

			if (*(mineArray + currentLocation[0] * size + currentLocation[1]) == 1)
			{
				mineFound += 1;
				break;
			}

			else
			{
				*(checkedLocation + currentLocation[0] * size + currentLocation[1]) = 1;
				checkedCount += 1;
			}

			break;

		default:
			break;

		}
	}

	printAll(mineArray, size);

	setPosition(10, 0);

	if (mineFound != 0)
		printf("YOU FOUND A MINE! YOU ARE DEAD\n");

	else
		printf("YOU FOUND NO MINE! YOU ARE NOW FREE TO GO\n");

	free(mineArray);
	free(checkedLocation);

	return 0;
}
