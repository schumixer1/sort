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
  int i, j; // указатели, участвующие в разделении
  int lb, ub; // границы сортируемого в цикле фрагмента

  int lbstack[MAXSTACK], ubstack[MAXSTACK]; // стек запросов
                                             // каждый запрос задаетс€ парой значений,
                                             // а именно: левой(lbstack) и правой(ubstack)
                                             // границами промежутка
  int stackpos = 1; // текуща€ позици€ стека
  int ppos; // середина массива
  int pivot; // опорный элемент
  int temp;

  lbstack[1] = 0;
  ubstack[1] = size - 1;

  do
    {
    // ¬з€ть границы lb и ub текущего массива из стека.
    lb = lbstack[stackpos];
    ub = ubstack[stackpos];
    stackpos--;

    do
      {
      // Ўаг 1. –азделение по элементу pivot
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

        // —ейчас указатель i указывает на начало правого подмассива,
        // j - на конец левого (см. иллюстрацию выше), lb ? j ? i ? ub.
        // ¬озможен случай, когда указатель i или j выходит за границу массива

        // Ўаги 2, 3. ќтправл€ем большую часть в стек и двигаем lb,ub
        if (i < ppos)
          { // права€ часть больше
          if (i < ub)
            { // если в ней больше 1 элемента - нужно
            stackpos++; // сортировать, запрос в стек
            lbstack[stackpos] = i;
            ubstack[stackpos] = ub;
            }
          ub = j; // следующа€ итераци€ разделени€
                  // будет работать с левой частью
          }
        else
          { // лева€ часть больше
          if (j > lb)
            {
            stackpos++;
            lbstack[stackpos] = lb;
            ubstack[stackpos] = j;
            }
          lb = i;
          }
      }
    while (lb < ub); // пока в меньшей части более 1 элемента
    }
  while (stackpos != 0); // пока есть запросы в стеке
  }
  
int compareLittle(int val1, int val2)
  {
  return (val1 > val2) ? 1 : 0;
  }
int compareBig(int val1, int val2)
  {
  return (val1 < val2) ? 1 : 0;
  }
