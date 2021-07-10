#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000

typedef struct _element {
	int x;
}element;

void swap(int arr[], int arr2[]) {
	int temp = arr[0];
	arr[0] = arr2[0];
	arr2[0] = temp;
}

void quick_sort(element arr[], int left, int right) {//left = 0. right = n - 1
	int pivot, i, j;
	
	if (left < right) {
		i = left;
		j = right+1;// right + 1인 이유..?
		pivot = arr[left].x;
		do {
			do i++;
			while (arr[i].x < pivot);
			do j--;
			while (arr[j].x > pivot);
			if (i < j) {
				swap(&arr[i].x, &arr[j].x);
			}
		} while (i < j); 

		swap(&arr[left].x, &arr[j].x);
		quick_sort(arr, left, j - 1);
		quick_sort(arr, j + 1, right);
	}
}

void print_array(element arr[], int size){
	int i;
	for (i = 0; i < size; i++) {
		printf("%-4d ", arr[i].x);
	}
	printf("\n");
}

void r_swap(int x, int y, element array[]) {
	element temp = array[x];
	array[x] = array[y];
	array[y] = temp;
}

int main() {
	//오름차순
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
	quick_sort(array, 0, MAX - 1);
	end = clock();
	print_array(array, size);

	result = 1000*(end - start);
	printf("us = %f", result);
	*/

	//내림차순
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
	quick_sort(array, 0, MAX-1);
	end = clock();
	printf("\n=============[sorted]=============\n\n");
	print_array(array, size);

	result = 1000*(end - start);
	printf("\nus = %f", result);
	*/

	//랜덤
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
		y = rand() % MAX;//0~9까지 사잇값 중에 하나 나옴
		r_swap(x,y,array);//결론적으로 swap이 안 됨. >> 왜 안 됐을까 >> x,y는 배열을 모름(해결).
	}
	printf("======[random]======\n\n");
	print_array(array, MAX);
	start = clock();
	quick_sort(array, 0, MAX - 1);
	end = clock();
	printf("\n=============[sorted]=============\n\n");
	print_array(array, MAX);

	result = 1000*(end - start);
	printf("%f", result);
	*/
}