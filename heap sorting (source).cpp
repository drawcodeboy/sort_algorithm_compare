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
	while (child <= n) {//n�� �ִ�ġ
		if ((child < n) && (list[child].key < list[child + 1].key)) {
			child++;//���� child�� ������ child���� ������ ������ child�� �ű�
		}
		if (rootkey > list[child].key) {
			break;//rootkey�� child���� ũ�� ������ �д�.
		}
		else {
			list[child / 2] = list[child];//root�� child���� �־��ش�.root�� �� �۱� ����
			child *= 2;//child�� child�� �Ѿ
		}
	}
	list[child / 2] = temp;
	//(1) else���� ������� �ʾ��� ���� ���� root�� ���� �־��ش�.
	//(2) else���� ����Ͽ��� ���� child = 2 * root�� *= 2�� ���־ [child/2]�� child���̸� �ٲ� root�� �־��ش�.
}

void swap(int a, int b, element arr[]) {
	//printf("\n[SWAP CHECK] %d %d", arr[a].key, arr[b].key);
	int temp = arr[a].key;
	arr[a].key = arr[b].key;
	arr[b].key = temp;
	//printf(">> %d %d\n", arr[a].key, arr[b].key);
}

void heap_sort(element list[], int n) {//n = ������ heap ��
	int i, j;
	//element temp;
	//temp.key = 0;
	for (i = n / 2; i > 0; i--) {
		adjust(list, i, n);
	}//MAX HEAP�� ���ϴ� ����
	/*
	printf("[MAX HEAP]\n");
	for (int x = 1; x < MAX + 1; x++) {
		printf("%-4d", list[x].key);
	}
	printf("\n\n[ADJUST PROCESS]\n");
	*/
	for (j = n - 1; j > 0; j--) {// �����δ� n-1���� 1������ adjust
		swap(1, j+1, list );
		adjust(list, 1, j);//n-1���� n�� �� ������ �ٲٰ�, �ٽ� adjust 
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
	//��������
	/*
	clock_t start, end;
	double result;
	
	element array[MAX + 1];//0�� ����α� ����
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


	//��������
	/*
	clock_t start, end;
	double result;

	element array[MAX + 1];//0�� ����α� ����

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


	//����
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