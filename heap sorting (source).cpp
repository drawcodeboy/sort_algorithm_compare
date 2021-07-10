#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

typedef struct _element {
	int key;
}element;

void adjust(element list[], int root, int n) {
	int child, rootkey;
	element temp;
	temp = list[root];
	rootkey = list[root].key;

	child = 2 * root;
	while (child <= n) {//n이 최대치
		if ((child < n) && (list[child].key < list[child + 1].key)) {
			child++;//왼쪽 child가 오른쪽 child보다 작으면 오른쪽 child로 옮김
		}
		if (rootkey > list[child].key) {
			break;//rootkey가 child보다 크면 가만히 둔다.
		}
		else {
			list[child / 2] = list[child];//root에 child값을 넣어준다.root가 더 작기 때문
			child *= 2;//child의 child로 넘어감
		}
	}
	list[child / 2] = temp;
	//(1) else문을 통과하지 않았을 때는 원래 root의 값을 넣어준다.
	//(2) else문을 통과하였을 때는 child = 2 * root에 *= 2를 해주어서 [child/2]는 child값이며 바뀐 root를 넣어준다.
}

void swap(int a, int b, element arr[]) {
	//printf("\n[SWAP CHECK] %d %d", arr[a].key, arr[b].key);
	int temp = arr[a].key;
	arr[a].key = arr[b].key;
	arr[b].key = temp;
	//printf(">> %d %d\n", arr[a].key, arr[b].key);
}

void heap_sort(element list[], int n) {//n = 마지막 heap 값
	int i, j;
	//element temp;
	//temp.key = 0;
	for (i = n / 2; i > 0; i--) {
		adjust(list, i, n);
	}//MAX HEAP을 구하는 과정
	/*
	printf("[MAX HEAP]\n");
	for (int x = 1; x < MAX + 1; x++) {
		printf("%-4d", list[x].key);
	}
	printf("\n\n[ADJUST PROCESS]\n");
	*/
	for (j = n - 1; j > 0; j--) {// 실제로는 n-1부터 1까지만 adjust
		swap(1, j+1, list );
		adjust(list, 1, j);//n-1부터 n은 맨 밑으로 바꾸고, 다시 adjust 
		/*
		for (int y = 1; y < MAX + 1; y++) {
			printf("%-4d", list[y].key);
		}
		printf("\n");
		*/
	}
	/*
	printf("\n[SORTED]\n");
	for (int x = 1; x < MAX + 1; x++) {
		printf("%-4d", list[x].key);
	}
	printf("\n\n");
	*/
}

void r_swap(int a, int b, element array[]) {
	element temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

int main() {
	//오름차순
	/*
	clock_t start, end;
	double result;
	
	element array[MAX + 1];//0을 비워두기 위해
	for (int i = 1; i < MAX + 1; i++) {
		array[i].key = i;
	}
	printf("[BEFORE]\n");
	for (int j = 1; j < MAX + 1; j++) {
		printf("%-6d", array[j].key);
	}
	printf("\n\n");
	start = clock();
	heap_sort(array, MAX);
	end = clock();
	printf("[AFTER]\n");
	for (int j = 1; j < MAX + 1; j++) {
		printf("%-6d", array[j].key);
	}
	
	result = 1000 * (end - start);
	printf("\nus = %f", result);
	*/


	//내림차순
	/*
	clock_t start, end;
	double result;

	element array[MAX + 1];//0을 비워두기 위해

	int n = MAX;
	for (int i = 1; i < MAX + 1; i++) {
		array[i].key = n--;
	}
	printf("[BEFORE]\n");
	for (int j = 1; j < MAX + 1; j++) {
		printf("%-6d", array[j].key);
	}
	printf("\n\n");
	start = clock();
	heap_sort(array, MAX);
	end = clock();
	printf("[AFTER]\n");
	for (int j = 1; j < MAX + 1; j++) {
		printf("%-6d", array[j].key);
	}
	
	result = 1000 * (end - start);
	printf("\nus = %f", result);
	*/


	//랜덤
	/*
	clock_t start, end;
	double result;

	srand(time(0));

	int i, x, y, shuffle;
	element array[MAX + 1];

	for (int i = 1; i < MAX + 1; i++) {
		array[i].key = i;
	}
	for (shuffle = 0; shuffle < 5000; shuffle++) {
		x = rand() % MAX + 1;
		y = rand() % MAX + 1;
		r_swap(x, y, array);
	}
	printf("[BEFORE]\n");
	for (int j = 1; j < MAX + 1; j++) {
		printf("%-6d", array[j].key);
	}
	printf("\n\n");
	start = clock();
	heap_sort(array, MAX);
	end = clock();
	printf("[AFTER]\n");
	for (int j = 1; j < MAX + 1; j++) {
		printf("%-6d", array[j].key);
	}

	result = 1000*(end - start);
	printf("\n\nus = %f", result);
	*/
}