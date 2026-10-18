#ifndef BURBUJA_PE_H
#define BURBUJA_PE_H

#include <iostream>
using namespace std;

// Burbuja para enteros
inline void burbujaInt(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool hubo = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                hubo = true;
            }
        }
        if (!hubo) break;
    }
}

// Burbuja para caracteres
inline void burbujaChar(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool hubo = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                hubo = true;
            }
        }
        if (!hubo) break;
    }
}

#endif
