#include <stdbool.h>
#include <stdio.h>  //use printf
#include <stdlib.h> //use random
#include <time.h>   //use time

#define MaxData 100 // Define Max Data
int Data[MaxData];
int Data1[MaxData], Data2[MaxData];
int OriginalData[MaxData];
int N;
int i;

void PrepareRawData(int N) {
  srand(time(NULL));
  for (int i = 0; i < N; i++) {
    Data[i] = 1 + rand() % 99;
    OriginalData[i] = Data[i];
  }
}

void RestoreData(int N) {
  for (int i = 0; i < N; i++) {
    Data[i] = OriginalData[i];
    Data1[i] = OriginalData[i];
    Data2[i] = OriginalData[i];
  }
}

void DispData0(int N) {
  for (int i = 0; i < N; i++)
  printf("%2d ", Data[i]);
printf("\n");
}

void DispData1(int Data[], int out) // Out is point of Outputted Number backward
{
  int i;
  for (i = 0; i <= N; i++) {
    if (i < out) {
      printf("%2d ", Data[i]); // Show 2 width of number
    } else
      printf("[%2d] ", Data[i]); // Show [ ] if it's Output
  }
  printf("\n");
}

void InsertionSort(int N) {
  int i, j, temp;
  printf("---------------------------------------------------------------------"
         "\n");
  printf(" i ");
  for (i = 1; i <= N; i++)
    printf(" (%2d)", i);
  printf("\n");
  printf("---------------------------------------------------------------------"
         "\n");

  printf("%2d. ", 0);
  DispData0(N);

  for (i = 1; i < N; i++) { // ปรับเงื่อนไขจาก i < N เป็น i < N-1
    temp = Data[i];
    j = i - 1;

    while (j >= 0 && Data[j] > temp) {
      Data[j + 1] = Data[j];
      j--;
    }
    Data[j + 1] = temp;

    printf("%2d. ", i);
    DispData0(N);
  }
}

void BubbleSort(int N) {
  int i, j, temp;
  printf("----------------------------------------------------------------\n");
  printf(" i ");
  for (i = 1; i <= N; i++)
    printf(" (%2d)", i);
  printf("\n");
  printf("----------------------------------------------------------------\n");

  for (i = 0; i < N - 1; i++) {
    for (j = 0; j < N - i - 1; j++) {
      if (Data[j] > Data[j + 1]) {
        temp = Data[j];
        Data[j] = Data[j + 1];
        Data[j + 1] = temp;
      }
    }
    printf("%2d. ", i + 1);
    DispData0(N);
  }
}

void swap0(int a, int b) {
  int temp;
  temp = Data[a];
  Data[a] = Data[b];
  Data[b] = temp;
}

void QuickSort(int f, int r) // Recursive Fn.
{
  int f1, r1;
  bool direction;
  f1 = f;
  r1 = r; // keep old Front & Rear values
  direction = true;
  while (f != r) {
    if (Data[f] > Data[r]) // Ascending case
    {
      printf("%2d %2d : ", f, r);
      DispData0(N);
      swap0(f, r);
      printf("%2d %2d : ", f, r);
      DispData0(N);
      direction = !direction; // change moving pointer direction
    }
    if (direction) // move r to left if TRUE
      r--;
    else
      f++; // move f right if FALSE
  }
  printf("k1=[%2d]--------------------------------------------------------\n",
         Data[f]); //
  // process in left hand
  if ((f > f1) && (f - 1 != f1))
    QuickSort(f1, f - 1); // recursive new position F&R
  // process in right hand
  if ((r < r1) && (r + 1 != r1))
    QuickSort(r + 1, r1); // recursive set new position F&R
}




void swap1(int a, int b) {
  int temp;
  temp = Data2[a];
  Data2[a] = Data2[b];
  Data2[b] = temp;
}


int Maximum(int a, int b) // Fine Maximum from 2 Data
{
  if (a > b)
    return (a);
  else
    return (b);
}
void AdjustTree(int LastNode) {
  int i, Max, lson, rson, son;
  bool result;
  i = 1;
  result = false; // False is NOT Finish Adjustment yet
  while (!result) {
    lson = (2 * i);     // Calculate LSon
    rson = (2 * i) + 1; // Calculate RSon
    son = 0;            // Set default Son
    if (lson == LastNode) {
      son = 1;
      if (Data2[i] < Data2[lson]) // Check Father Data < LSon data ?
      {
        swap1(i, lson);
        DispData1(Data2, LastNode + 1); // Show each step result
      }
      result = true; // Finish Adjustment
    }
    if (rson <= LastNode) {
      son = 2;
      Max = Maximum(Data2[lson], Data2[rson]); // Find Maximum Data
      if (Data2[i] < Max)                      // Check Father Data < Max ?
      {
        if (Max == Data2[lson]) // Max == Data Lson?
        {
          swap1(i, lson);
          DispData1(Data2, LastNode + 1); // Show each step result
          if (rson == LastNode)           // Check for Last Node
            result = true;                // Finish Adjustment
          else
            i = lson; // Let i follow to LSon
        } else        // if Data RSon is Maximum
        {
          swap1(i, rson);
          DispData1(Data2, LastNode + 1); // Show each step
          if (rson == LastNode)           // Check for Last Node
            result = true;                // Finish Adjustment
          else
            i = rson; // Let i follow to RSon
        }
      } else
        result = true; // Finish Adjustment
    }
    if (son == 0)
      result = true; // Finish Adjustment
  } // End While
  printf("---------------------------------------------------Adjust Tree Finished at N=%d \n",LastNode);
} // End Fn.

void CreateHeapTree() {
  int i, j, k, father;
  bool result;

  Data2[1] = Data1[0]; // เปลี่ยนจาก Data1[1] เป็น Data1[0]
  DispData1(Data2, N + 1);

  for (i = 1; i < N; i++) {
    Data2[i + 1] = Data1[i];
    DispData1(Data2, N + 1);
    result = true;
    j = i + 1;

    while (result) {
      father = j / 2;
      if (Data2[j] > Data2[father] && j > 1) {
        swap1(j, father);
        DispData1(Data2, N + 1);
        j = father;
      } else {
        result = false;
      }
    }
  }

  printf("---------------------------------------------------Create Heap Tree Finished \n");
  for (k = 1; k <= N; k++)
    printf("(%d) ", k);
  printf("\n");

  for (i = N; i > 1; i--) {
    swap1(1, i);
    DispData1(Data2, i);
    AdjustTree(i - 1);
  }
}

void ShowMenu() {
  printf("====================================\n");
  printf("0. สุ่มตัวเลขใหม่\n");
  printf("1. เรียงลำดับแบบ Insertion Sort\n");
  printf("2. เรียงลำดับแบบ Bubble Sort\n");
  printf("3. เรียงลำดับแบบ Quick sort\n");
  printf("4. เรียงลำดับแบบ Heap sort\n");
  printf("X. ออก\n");
  printf("====================================\n");
}

int in() {
  printf("\n");
  printf("ASCENDING INSERTION SORT\n");
  printf("==============================\n");
  RestoreData(N);
  printf("Raw Data : ");
  DispData0(N);
  printf("Processing Data...\n");
  InsertionSort(N);
  printf("----------------------------------------------------------------\n");
  printf("Sorted Data : ");
  DispData0(N); // Sorted Data
  getchar();
  return (0);
} // End Main
int bub() {
  printf("\n");
  printf("ASCENDING BUBBLE SORT\n");
  printf("================================================================\n");
  RestoreData(N);
  printf("Raw Data : ");
  DispData0(N);
  printf("----------------------------------------------------------------\n");
  printf("Processing Data...\n");
  BubbleSort(N);
  printf("----------------------------------------------------------------\n");
  printf("Sorted Data : ");
  DispData0(N); // Sorted Data
  getchar();
  return (0);
} // End Main
int quick() {
  printf("\n");
  printf("ASCENDING QUICK SORT\n");
  printf("==============================\n");
  RestoreData(N);
  printf("Raw Data : ");
  DispData0(N);
  printf("Processing Data...\n");
  printf(" F R ");
  for (i = 0; i < N; i++)
    printf(" (%2d)", i);
  printf("\n");
  QuickSort(0, N - 1); // เปลี่ยนจาก QuickSort(1, N - 1) เป็น QuickSort(0, N - 1)
  printf("----------------------------------------------------------------\n");
  printf("Sorted Data : ");
  DispData0(N);
  getchar();
  return (0);
}
int heap() {
  printf("\n");
  printf("ASCENDING HEAP SORT\n");
  printf("===================================================\n");
  RestoreData(N);
  printf("Raw Data : ");
  DispData1(Data1, N + 1);
  printf(
      "---------------------------------------------------Raw Data Finished\n");
  printf("Create Heap Tree...\n");
  CreateHeapTree();
  printf("Sorted Data is: ");
  DispData1(Data2, 0); // Sorted Data
  printf("---------------------------------------------------Sort Finished \n");
  getchar();
  return (0);
} // End Main

void chose() {
  ShowMenu();
  char ch;
  while (true) {
    printf("เลือกตัวเลือก: ");
    scanf(" %c", &ch);
    if (ch == '0') {
      PrepareRawData(N);
      printf("Raw Data   : ");
      DispData0(N);
    } else if (ch == '1') {
      in();
    } else if (ch == '2') {
      bub();
    } else if (ch == '3') {
      quick();
    } else if (ch == '4') {
      heap();
    } else if (ch == 'x' || ch == 'X') {
      printf("Good bye");
      break;
    } else {
      printf("ตัวเลือกไม่ถูกต้อง! กรุณาเลือกใหม่\n");
    }
  }
}

int main() {
  printf("====================================\n");
  printf(" รหัส นศ.: 67543210008-8 ชื่อ: ณัฐพงศ์ จินะปัญญา \n");
  printf("====================================\n");
  printf("ระบุจำนวนตัวเลขที่จะจัดเรียง : ");
  scanf("%d", &N);
  printf("\n");
  PrepareRawData(N);
  printf("Raw Data : ");
  DispData0(N);
  chose();
  return 0;
}