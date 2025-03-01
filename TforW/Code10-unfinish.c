#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DATA 100

int Data[MAX_DATA];
int N;

void PrepareRawData(int N) {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        Data[i] = 1 + rand() % 99;
    }
}

void DispData(int N) {
    for (int i = 0; i < N; i++) {
        printf("%2d   ", Data[i]);
    }
    printf("\n");
}

void InsertionSort(int N) {
    for (int i = 1; i < N; i++) {
        int temp = Data[i];
        int j = i - 1;
        while (j >= 0 && Data[j] > temp) {
            Data[j + 1] = Data[j];
            j--;
        }
        Data[j + 1] = temp;
    }
}

void BubbleSort(int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (Data[j] > Data[j + 1]) {
                int temp = Data[j];
                Data[j] = Data[j + 1];
                Data[j + 1] = temp;
            }
        }
    }
}

void ShowMenu() {
    printf("====================================\n");
    printf(" รหัส นศ.: 67543210008-8 ชื่อ-สกุล: ณัฐพงศ์ จินะปัญญา \n");
    printf("====================================\n");
    printf("1. เรียงลำดับแบบ Insertion Sort\n");
    printf("2. เรียงลำดับแบบ Bubble Sort\n");
    printf("3. สุ่มข้อมูลใหม่\n");
    printf("0. ออกจากโปรแกรม\n");
    printf("====================================\n");
}

int main() {
    int choice;
    printf("กรุณาป้อนจำนวนข้อมูลที่ต้องการสุ่ม: ");
    scanf("%d", &N);

    do {
        PrepareRawData(N);
        printf("ข้อมูลที่สุ่มได้: ");
        DispData(N);
        printf("ต้องการใช้ข้อมูลนี้สำหรับการจัดเรียงหรือไม่? (1=ใช่, 0=ไม่): ");
        scanf("%d", &choice);
    } while (choice == 0);

    while (1) {
        ShowMenu();
        printf("เลือกเมนู: ");
        scanf("%d", &choice);

        if (choice == 1) {
            InsertionSort(N);
            printf("ข้อมูลหลังจากเรียงลำดับแบบ Insertion Sort: ");
            DispData(N);
        } else if (choice == 2) {
            BubbleSort(N);
            printf("ข้อมูลหลังจากเรียงลำดับแบบ Bubble Sort: ");
            DispData(N);
        } else if (choice == 3) {
            PrepareRawData(N);
            printf("ข้อมูลใหม่ที่สุ่มได้: ");
            DispData(N);
        } else if (choice == 0) {
            printf("ออกจากโปรแกรม\n");
            break;
        } else {
            printf("ตัวเลือกไม่ถูกต้อง! กรุณาเลือกใหม่\n");
        }
    }
    return 0;
}
