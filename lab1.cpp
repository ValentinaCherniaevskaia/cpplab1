#include <iostream>

void swap (int *a, int *b){ //функция обменивает значения двух переменных, которые содержат одинаковые типы данных
    int t = *a;
    *a = *b;
    *b = t;
}


void bubblesort (int n, int a[]){ //повторение проходов по массиву с помощью вложенных циклов. При каждом проходе по массиву сравниваются между собой пары “соседних” элементов. Если числа какой-то из сравниваемых пар расположены в неправильном порядке, происходит перезапись значений ячеек массива

    for (int i =0;i < n;i++){
        for (int j = 0; j < n-1;j++){
            if (a[j] > a[j+1]){
               swap (&a[j], &a[j+1]);
            }
        }
    }
    
    std::cout << std::endl;
    for (int i = 0; i < n; i++){
        std::cout << a[i] << " ";
    }
}


void selectsort (int n, int a[]){ //поиск минимального значения элемента в массиве, и перемещение этого значения в начало массива

    for (int i=0; i<n-1; i++){ 
            int min =i;
            for (int j=i+1; j<n; j++){
                if (a[j] < a[min])
                    min = j;
            }
            swap (&a[min], &a[i]);
    }

    std::cout << std::endl;
    for (int i = 0; i < n; i++){
        std::cout << a[i] << " ";
    }
}


void insertsort (int n, int a[]) { //на каждом шаге алгоритма мы берем один из элементов массива, находим позицию для вставки и вставляем, при этом массив из 1-го элемента считается отсортированным
    
    for (int i=1; i<n; i++){
        int k = a[i];
        int j = i-1;
        while (k<a[j] && j>=0 ){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = k;
    }

    std::cout << std::endl;
    for (int i = 0; i < n; i++){
        std::cout << a[i] << " ";
    }
}


int main() {
    int a[100]; //создается массив
    int n; //количество чисел в массиве
    std::cout << "An amount of numbers in the array: "; //вводится значение, обозначающее количество чисел в массиве
    std::cin >> n; //значение присваивается n
    std::cout << "Array: ";  //вводится массив
    for (int i=0; i<n; i++){
        std::cin >> a[i];
    }

    std::cout << "Select a sort: 1. Bubble; 2. Select; 3.Insert: ";
    int k;
    std::cin >> k;
    switch (k) { //проверяет одну переменную в своих условия
        case 1: //в случае, если выбран 1. bubble sort
            bubblesort (n,a);
            break;
        case 2: //в случае, если выбран 2. select sort
            selectsort (n,a);
            break;
        case 3: //в случае, если выбран 3. insert sort
            insertsort (n,a);
    }

}
