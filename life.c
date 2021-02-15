#include <stdio.h>

#ifdef _WIN32
#include <Windows.h>
void clear() {
	system("cls");
} 
#else
#include <unistd.h>
void clear() {
	system("clear");
} 
#endif

#define size 64

static int generation = 0;

static int universe[size][size] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,1,1,1,0,0,0,0,0,0,0,1,1,0},
	{0,0,0,0,0,0,1,0,0,0,0,0,1,0,0},
	{0,0,0,0,0,1,0,0,0,0,0,1,1,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
	{0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,1,0,0,1,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
	{0,1,0,0,0,0,0,0,0,0,0,0,1,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,1,1,0,0},
};

void show() {
	clear();
	printf("%i\n", generation);
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
  			if (universe[i][j]) {
  				printf("# ");
  			} else {
  				printf("  ");
  			}
		}
		printf("\n");
	}
	printf("\n");
}

void generate() {
	int next[size][size] = {0};
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			int neighbors = 0;
			for (int k = i-1; k < i+2; ++k) {
				for (int l = j-1; l < j+2; ++l) {
					if (k == i && j == l) {
					} else if (universe[k % size][l % size]) {
						neighbors += 1;
					}
				}
			}
			if (neighbors == 3 || (neighbors == 2 && universe[i][j])) {
				next[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			universe[i][j] = next[i][j];
		}
	}
	generation += 1;
}

int main(void) {
	show();
	for (;;) {
		generate();
		show();
		sleep(1);
	}
}
