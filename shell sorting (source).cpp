#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000

typedef struct _element {
	int x;
}element;

void print_array(element array[], int size);

void shell_sort(element array[], int size) {
	for (int i = size / 2; i > 0; i /= 2) {// i = h, h�� ����� ��� �ٿ���
		for (int j = 0; j < i; j++) {// j�� sublist�� �����̴�, 
			for (int k = i + j; k < size; k += i) {//insertion sort
				element l = array[k];//l�� ����
				int m = k;//���� �� ����
				while (m > i - 1 && array[m - i].x > l.x) { //m>i-1�� �ؼ�
					array[m] = array[m - i];
					m -= i;
				}
				array[m].x = l.x;
			}
		}
		//printf("i=%d || ",i);
		//print_array(array,size);
	}
}

void print_array(element array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%-5d", array[i].x);
	}  
	printf("\n");
}

void swap(int n,int m,element array[MAX]) {
	//printf("%d,%d\n", n, m);
	element temp = array[n];
	array[n] = array[m];
	array[m] = temp;
	//printf("%d,%d\n", n, m);
}

int main() {
	//��������
	/*
	clock_t start, end;
	double result;

	element array[MAX];
	int i;
	int size = sizeof(array) / sizeof(array[0]);
	for (i = 1; i <= size; i++) {
		array[i - 1].x = i;
	}
	print_array(array, size);
	start = clock();
	shell_sort(array, size);
	end = clock();
	print_array(array, size);
	
	result = 1000*(end - start);
	printf("\nus = %f", result);
	*/
	 
	//��������
	/*
	clock_t start, end;
	double result;
	element array[MAX];
	int i;
	int size = sizeof(array) / sizeof(array[0].x);
	int n = size;
	for (i = 0; i <= size-1; i++) {
		array[i].x = n--;
	}
	printf("======[Before]======\n\n");
	print_array(array, size);
	start = clock();
	shell_sort(array, size);
	end = clock();
	printf("\n=============[sorted]=============\n\n");
	print_array(array, size);

	result = 1000*(end - start);
	printf("\nus = %f", result);
	*/

	//����
	/*
	clock_t start, end;
	double result;

	int shuffle;
	int i, x, y;
	element array[MAX];
	srand(time(0));

	for (i = 0; i < MAX; i++) {
		array[i].x = i + 1;
	}
	for (shuffle = 0; shuffle < 5000; shuffle++) {
		x = rand() % MAX;
		y = rand() % MAX;//0~9���� ���հ� �߿� �ϳ� ����
		swap(x,y,array);//��������� swap�� �� ��. >> �� �� ������ >> x,y�� �迭�� ��(�ذ�).
	}
	printf("======[random]======\n\n");
	print_array(array, MAX);
	start = clock();
	shell_sort(array, MAX);
	end = clock();
	printf("\n=============[sorted]=============\n\n");
	print_array(array, MAX);

	result = 1000*(end - start);
	printf("\nus = %f", result);
	*/
}