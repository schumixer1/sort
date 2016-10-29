#include<iostream>
#include<cstdlib>//for srand() and rand()
#include<fstream>//for text files
#include<ctime>?//for clock
#include"Header.h"
using namespace std;
const int MAX = 4;
int main()
  {
  int N;
  clock_t start, stop;
  ofstream file;
  cout << "Enter number of elements\n";
  cin >> N;
  int* mas[MAX];
  for (int i{ 0 };i < MAX;i++)
    mas[i]= new int[N];
  srand(time(NULL));
  for (int i{ 0 };i < N;i++)
    mas[1][i] = mas[2][i] = mas[3][i] = mas[0][i] = rand() % 999;

  //BigBubbleSort
  start = clock();
  bubbleSort(mas[0], N, compareBig);
  stop = clock();
  file.open("BigBubbleSort.txt");//object of ofstream
  for (int i{ 0 };i < N;i++)
    file << mas[0][i] << "\n";
  file.close();
  cout << "BigBubbleSort: "<<(float)(stop - start) / CLOCKS_PER_SEC<<endl;

  //LittleBubbleSort
  start = clock();
  bubbleSort(mas[1], N, compareLittle);
  stop = clock();
  file.open("LittleBubbleSort.txt");//object of ofstream
  for (int i{ 0 };i < N;i++)
    file << mas[1][i] << "\n";
  file.close();
  cout << "LittleBubbleSort: "<<(float)(stop - start) / CLOCKS_PER_SEC << endl;

  //BigQuickSort
  start = clock();
  quickSort(mas[2], N, compareLittle);
  stop = clock();
  file.open("BigQuickSort.txt");//object of ofstream
  for (int i{ 0 };i < N;i++)
    file << mas[2][i] << "\n";
  file.close();
  cout << "BigQuickSort: " << (float)(stop - start) / CLOCKS_PER_SEC << endl;

  //LittleQuickSort
  start = clock();
  quickSort(mas[3], N, compareBig);
  stop = clock();
  file.open("LittleQuickSort.txt");//object of ofstream
  for (int i{ 0 };i < N;i++)
    file << mas[3][i] << "\n";
  file.close();
  cout << "LittleQuickSort: " << (float)(stop - start) / CLOCKS_PER_SEC << endl;
  cout << "mom";
  cout << "mom";

  system("pause");
  }