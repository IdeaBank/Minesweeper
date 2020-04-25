#include <stdio.h>
// 입출력을 위한 헤더파일
// Header file for input / output

#include <Windows.h>
// 화면 초기화 및 커서 위치 조절을 위한 헤더파일
// Header file for clearing screen and adjusting cursor location

#include <memory.h>
// 메모리 동적 할당을 위한 헤더파일
// Header file for memory allocation

#include <stdlib.h>
// 랜덤 수 출력을 위한 헤더파일
// Header file for getting pseudo random number

#include <time.h>
// 시드 값으로 전달할 현재 시간을 얻기 위한 헤더파일
// Header file for getting current time, which will be given for seed

#pragma warning(disable:4996)
// scanf 경고를 제거
// Preprocessor for removing scanf warning

void setPosition(int X, int Y)	// 커서 위치 조절을 위한 함수. 굳이 지금 해석할 필요까지는 없음. Function used to adjust cursor location. Don't necessarily need to understand.
{
	HANDLE Screen;
	Screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position = { X, Y };

	SetConsoleCursorPosition(Screen, Position);
}

void makeRandomArray(int* targetArray, int size, int amount)	// 지뢰가 숨겨진 위치를 정하기 위한 함수. Function used to set locations that mines are hidden.
{
	int count = 0;	// 현재까지 설치된 지뢰의 개수. Currently installed mines
	while (count < amount)	// 목표로 한 개수만큼 설치될 때까지 반복. Repeat until you fully install planned amount of mines
	{
		int x = rand() % size;
		int y = rand() % size;
		// 랜덤으로 좌표 값을 얻음. Get random location

		if (*(targetArray + x * size + y) == 0)	// 만약 그 위치에 지뢰가 설치되지 않았다면 설치함. If mine is not installed in the position, install it
		{
			*(targetArray + x * size + y) = 1;
			count += 1;
		}
	}
}

void printToScreen(int* mineArray, int* checkedLocation, int size)	// 현재까지 찾은 위치를 표현하기 위한 함수. Function used to print searched locations
{
	system("cls");	// 화면 초기화. Clear screen

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (*(checkedLocation + i * size + j) == 0)	// 만약 해당 좌표를 찾아보지 않았다면 X를 출력함. If the location hasn't been searched, print X
				printf("X");

			else
			{
				int checkCount = 0;	// 주위에 몇 개의 지뢰가 설치되어 있는지를 저장하기 위한 변수. Variable for saving how many mines are installed around the location

				if (i == 0 && j == 0)	// 왼쪽 맨 위에 위치할 경우. If it is on the leftmost top
				{
					if (*(mineArray + i * size + j + 1) == 1)
						checkCount += 1;

					if (*(mineArray + (i + 1) * size + j) == 1)
						checkCount += 1;

					if (*(mineArray + (i + 1) * size + j + 1) == 1)
						checkCount += 1;
				}

				else if (i == 0 && j == size - 1)	// 오른쪽 맨 위에 위치할 경우. If it is on the rightmost top
				{
					if (*(mineArray + i * size + j - 1) == 1)
						checkCount += 1;

					if (*(mineArray + (i + 1) * size + j) == 1)
						checkCount += 1;

					if (*(mineArray + (i + 1) * size + j - 1) == 1)
						checkCount += 1;
				}

				else if (i == size - 1 && j == 0)	// 왼쪽 맨 아래에 위치할 경우. If it is on the leftmost bottom
				{
					if (*(mineArray + i * size + j + 1) == 1)
						checkCount += 1;

					if (*(mineArray + (i - 1) * size + j) == 1)
						checkCount += 1;

					if (*(mineArray + (i - 1) * size + j + 1) == 1)
						checkCount += 1;
				}

				else if (i == size - 1 && j == size - 1)	// 오른쪽 맨 아래에 위치할 경우. If it is on the rightmost bottom
				{
					if (*(mineArray + i * size + j - 1) == 1)
						checkCount += 1;

					if (*(mineArray + (i - 1) * size + j) == 1)
						checkCount += 1;

					if (*(mineArray + (i - 1) * size + j - 1) == 1)
						checkCount += 1;
				}

				else if (i == 0) // 맨 위에 위치할 경우. If it is on the top
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

				else if (j == 0) // 맨 왼쪽에 위치할 경우. If it is on the leftmost
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

				else if (i == size - 1) // 맨 아래에 위치할 경우. If it is on the bottom
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

				else if (j == size - 1)	// 맨 오른쪽에 위치할 경우. If it is on the rightmost
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

				else // 나머지에 위치할 경우. If it is located elsewhere
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

				printf("%d", checkCount);	// 해당 위치에 주위 지뢰의 개수를 출력함. Print amount of mines installed around the location
			}
		}

		printf("\n");
	}
}

void printAll(int* mineArray, int size)	// 모든 지뢰의 위치를 출력하기 위한 함수. Function used to print locations of mines
{
	system("cls");	// 화면 초기화. Clear screen

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (*(mineArray + i * size + j) == 0)	// 현재 위치에 지뢰가 설치되어 있지 않을 경우, X를 출력함. If mine is not installed in the location, print X
				printf("X");

			else
				printf("M");	// 현재 위치에 지뢰가 설치되어 있을 경우, M을 출력함. If mine is installed in the location, print M
		}

		printf("\n");
	}
}

int main()
{
	int size = 0;	// 판의 크기를 저장하기 위한 변수. Variable for saving size of board

	int* mineArray;	// 지뢰의 설치 여부를 저장하기 위한 배열. Array for saving whether mine is installed or not
	int* checkedLocation;	// 찾아본 위치를 저장하기 위한 배열. Array for saving checked location

	int currentLocation[2] = { 0, 0 };	// 현재 커서 위치를 저장하기 위한 배열. Array for saving current cursor location

	int mineAmount = 0;	// 설치된 지뢰 개수를 저장하기 위한 변수. Variable for saving amount of installed mines
	int mineFound = 0;	// 찾은 지뢰 개수를 저장하기 위한 변수 (0 초과일 시 게임 종료). Variable for saving amount of found mines(Game will be over if it is more than 0)
	int checkedCount = 0; // 찾아본 위치의 개수를 저장하기 위한 변수. Variable for saving amount of checked locations

	char pressedKey = 0;	// 누른 키를 저장하기 위한 변수. Variable for saving pressed key

	srand(time(NULL));	// 현재 시간을 시드 값으로 전달. Give current time to seed

	printf("Enter size : ");
	scanf("%d", &size);

	while (!(1 <= size && size <= 10))	// 크기가 0 미만이거나 10 초과일 시 다시 입력받음. If size is less than 0 or more than 10, get input again
	{
		printf("The size should be between 1 and 10!\nPlease Enter the size again : ");
		scanf("%d", &size);
	}

	printf("Enter amount of mines : ");
	scanf("%d", &mineAmount);

	while (!(mineAmount < size * size && 0 < mineAmount))	// 지뢰가 최대 개수보다 많을 시 다시 입력받음. If amount of mines are more than the limit or less than 0, get input again
	{
		printf("Amount of mines are greater than or equal to the limit and more than 0!\nPlease Enter amount of mines again : ");
		scanf("%d", &mineAmount);
	}

	mineArray = (int*)malloc(sizeof(int) * size * size);	// 판의 크기 만큼의 메모리를 할당받음. Allocate memory whose size is size of the board
	checkedLocation = (int*)malloc(sizeof(int) * size * size);	// 위와 같음. As above

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			*(mineArray + i * size + j) = 0;
			*(checkedLocation + i * size + j) = 0;
		}
	}

	// 배열의 원소를 0으로 초기화 함. Set all elements of array to 0

	makeRandomArray(mineArray, size, mineAmount);	// 지뢰를 랜덤 위치에 설치함. Install mines in random locations
	printToScreen(mineArray, checkedLocation, size);	// 현재 확인한 위치를 화면에 표시함. Print currently checked location to the screen

	while (checkedCount != size * size - mineAmount && mineFound == 0)	// 지뢰를 제외한 모든 위치를 확인하거나 지뢰를 찾을때까지 반복함. Repeat until you find all places except where mine is installed or you find a mine
	{
		printToScreen(mineArray, checkedLocation, size);	// 현재 확인한 위치를 화면에 표시함. Print currently checked location to the screen 
		setPosition(currentLocation[0], currentLocation[1]);	// 커서의 위치를 설정함. Set cursor position

		pressedKey = getch();	// 키를 하나 입력받음. Get key input

		switch (pressedKey)
		{
		case 'w':	// w를 누르면. If w is pressed
			if (currentLocation[1] == 0)	// 만약 현재 위치가 맨 위면 취소함. If current location is top, cancel
				break;

			else
				currentLocation[1] -= 1;	// 아니면 위로 옮김. If else, move up
			break;

		case 'a':	// a를 누르면. If a is pressed
			if (currentLocation[0] == 0)	// 만약 현재 위치가 맨 왼쪽이면 취소함. If current location is leftmost, cancel
				break;

			else
				currentLocation[0] -= 1;	// 아니면 왼쪽으로 옮김. If else, move left

			break;

		case 's':	// s를 누르면. If s is pressed
			if (currentLocation[1] == size - 1)	// 만약 현재 위치가 맨 아래면 취소함. If current location is bottom, cancel
				break;

			else
				currentLocation[1] += 1;	// 아니면 아래로 옮김. If else, move down

			break;

		case 'd':	// d를 누르면. If d is pressed
			if (currentLocation[0] == size - 1)	// 만약 현재 위치가 맨 오른쪽면 취소함. If current location is rightmost, cancel
				break;

			else
				currentLocation[0] += 1;	// 아니면 오른쪽으로 옮김. If else, move right

			break;

		case '\r':	// 엔터 키를 누르면. If enter key is pressed
			if (*(checkedLocation + currentLocation[1] * size + currentLocation[0]) == 1)	// 만약 현재 위치를 이미 확인 했으면 취소함. If you already checked the location, cancel
				break;

			if (*(mineArray + currentLocation[1] * size + currentLocation[0]) == 1)	// 만약 그 위치에 지뢰가 설치되어 있을 경우 찾은 지뢰의 개수를 1 증가시킴. If mine is installed in the location, increase the amount of found mines 
			{
				mineFound += 1;
				break;
			}

			else	// 둘 다 아닐 경우, 현재 위치를 확인해보고 확인한 위치의 개수를 1 증가시킴. If neither of the conditions are satisfied, check the location and increase the amount of checked locations 
			{
				*(checkedLocation + currentLocation[1] * size + currentLocation[0]) = 1;
				checkedCount += 1;
			}

			break;

		default:
			break;
		}
	}

	printAll(mineArray, size);	// 모든 지뢰의 위치를 표시함. Print locations of installed mines

	setPosition(0, 10);	// 커서 위치를 아래로 이동시킴. Move cursor to the bottom

	if (mineFound != 0)	// 한번도 지뢰를 안 발견했을 시. If you didn't find any mine
		printf("YOU FOUND A MINE! YOU ARE DEAD\n");

	else	// 지뢰를 찾았을 시. If you found a mine
		printf("YOU FOUND NO MINE! YOU ARE NOW FREE TO GO\n");

	free(mineArray);	
	free(checkedLocation);
	// 메모리를 할당 해제함. Free used memories

	return 0;
}
