// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm> 

using namespace std;
int main()
{
	const int size = 25;
	int arr[25][25];
	int arr1[25][25];
	int rand1=0;
	int x, y;
	int total = 0;
	for (x=0; x < size; x++) {
		for (y=0; y < size; y++) {
			rand1 = (rand() % 10);
			if (rand1 < 5) {
				arr[x][y] = 1;
			}
			else {
				arr[x][y] = 0;
			}
			cout << arr[x][y];
		}
		 cout<< '\n';
	}

	int check = 0;
	while (check < 1000) {

		for (x = 0; x < size; x++) {
			for (y = 0; y < size; y++) {
				if (x == 0) {
					if (y == 0) {
						total = arr[x + 1][y] + arr[x + 1][y + 1] + arr[x][y + 1];
					}
					else if (y == size-1) {
						total = arr[x][y - 1] + arr[x + 1][y] + arr[x + 1][y - 1];
					}
					else {
						total = arr[x][y - 1] + arr[x][y + 1] + arr[x + 1][y] + arr[x + 1][y - 1] + arr[x + 1][y + 1];
					}
				}
				else if (x == size-1) {
					if (y == 0) {
						total = arr[x - 1][y] + arr[x - 1][y + 1] + arr[x][y + 1];
					}
					else if (y == size-1) {
						total = arr[x][y - 1] + arr[x - 1][y] + arr[x - 1][y - 1];
					}
					else {
						total = arr[x][y - 1] + arr[x][y + 1] + arr[x - 1][y - 1] + arr[x - 1][y] + arr[x - 1][y + 1];
					}
				}
				else if (y == 0) {
					total = arr[x - 1][y] + arr[x + 1][y] + arr[x - 1][y + 1] + arr[x][y + 1] + arr[x + 1][y + 1];
				}
				else if (y == size-1) {
					total = arr[x - 1][y] + arr[x + 1][y] + arr[x - 1][y - 1] + arr[x + 1][y - 1] + arr[x][y - 1];
				}
				else {
					total = arr[x - 1][y - 1] + arr[x - 1][y] + arr[x - 1][y + 1] + arr[x][y - 1] + arr[x][y + 1] + arr[x + 1][y - 1] + arr[x + 1][y] + arr[x + 1][y + 1];
				}

				if (total < 2 || total>3) {
					arr1[x][y] = 0;
				}
				else if (total == 3) {
					arr1[x][y] = 1;
				}
				else {
					arr1[x][y] = arr[x][y];
				}
				cout << arr1[x][y];
				total = 0;
			}
			cout << '\n';

		}
		system("pause");
		cout << "\x1B[2J\x1B[H";
		check++;
		std::copy(&arr1[0][0], &arr1[0][0] + size * size, &arr[0][0]);

	}
	

}

