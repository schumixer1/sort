#include "Header.h"
void bubbleSort(int* array, int size, int(*compare)(int, int))
  {
  for (int i{0};i < size;i++)
    {
    for (int j{0};j < size - i-1;j++)
      {
      if (compare(array[j], array[j + 1]))
        {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
        }
      }
    }
  }

void quickSort(int* array, int size, int(*compare)(int, int))
  {
  const int MAXSTACK = 2048;
  int i, j; // ���������, ����������� � ����������
  int lb, ub; // ������� ������������ � ����� ���������

  int lbstack[MAXSTACK], ubstack[MAXSTACK]; // ���� ��������
                                             // ������ ������ �������� ����� ��������,
                                             // � ������: �����(lbstack) � ������(ubstack)
                                             // ��������� ����������
  int stackpos = 1; // ������� ������� �����
  int ppos; // �������� �������
  int pivot; // ������� �������
  int temp;

  lbstack[1] = 0;
  ubstack[1] = size - 1;

  do
    {
    // ����� ������� lb � ub �������� ������� �� �����.
    lb = lbstack[stackpos];
    ub = ubstack[stackpos];
    stackpos--;

    do
      {
      // ��� 1. ���������� �� �������� pivot
      ppos = (lb + ub) >> 1;
      i = lb; j = ub; pivot = array[ppos];
      do
        {
        while (compare(array[i],pivot)) i++;
        while (compare(pivot, array[j] )) j--;
        if (i <= j)
          {
          temp = array[i]; array[i] = array[j]; array[j] = temp;
          i++; j--;
          }
        }
      while (i <= j);

        // ������ ��������� i ��������� �� ������ ������� ����������,
        // j - �� ����� ������ (��. ����������� ����), lb ? j ? i ? ub.
        // �������� ������, ����� ��������� i ��� j ������� �� ������� �������

        // ���� 2, 3. ���������� ������� ����� � ���� � ������� lb,ub
        if (i < ppos)
          { // ������ ����� ������
          if (i < ub)
            { // ���� � ��� ������ 1 �������� - �����
            stackpos++; // �����������, ������ � ����
            lbstack[stackpos] = i;
            ubstack[stackpos] = ub;
            }
          ub = j; // ��������� �������� ����������
                  // ����� �������� � ����� ������
          }
        else
          { // ����� ����� ������
          if (j > lb)
            {
            stackpos++;
            lbstack[stackpos] = lb;
            ubstack[stackpos] = j;
            }
          lb = i;
          }
      }
    while (lb < ub); // ���� � ������� ����� ����� 1 ��������
    }
  while (stackpos != 0); // ���� ���� ������� � �����
  }
  
int compareLittle(int val1, int val2)
  {
  return (val1 > val2) ? 1 : 0;
  }
int compareBig(int val1, int val2)
  {
  return (val1 < val2) ? 1 : 0;
  }
