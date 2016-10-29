#pragma once
void bubbleSort(int*, int , int(*compare)(int, int));
int compareLittle(int, int);
int compareBig(int, int);
void quickSort(int*, int, int(*compare)(int, int));