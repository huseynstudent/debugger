#include <iostream>
using namespace std;
template <typename T>
void fillarr(T* arr, int size);
template <typename T>
void showarr(const T* arr, int size);
template<typename T>
T* removeNegative(T* arr, int& size);
template<typename T>
T* commonElements(const T* A, int M, const T* B, int N, int& size);
template<typename T>
T* uniqueInA(const T* A, int M, const T* B, int N, int& size);
template<typename T>
T* uniqueInBoth(const T* A, int M, const T* B, int N, int& size);
template<typename T>
bool isPrime(T num);
template<typename T>
T* removePrimes(T* arr, int& size);
int main() {
    srand(time(NULL));
    int M, N;
    cout << "Enter size of array A: ";
    cin >> M;
    cout << "Enter size of array B: ";
    cin >> N;
    int* A = new int[M];
    int* B = new int[N];
    fillarr(A, M);
    showarr(A, M);
    cout << endl;
    fillarr(B, N);
    showarr(B, N);
    cout << "\n\ttask1\n";
    int newSizeA = M;
    int* filteredA = removeNegative(A, newSizeA);
    cout << "Array A without negative numbers: ";
    showarr(filteredA, newSizeA);
    cout << "\n\ttask3\n";
    int sizeCommon;
    int* common = commonElements(A, M, B, N, sizeCommon);
    cout << "Common elements: ";
    showarr(common, sizeCommon);
    cout << "\n\ttask4\n";
    int sizeUniqueInA;
    int* uniqueA = uniqueInA(A, M, B, N, sizeUniqueInA);
    cout << "Unique elements in A: ";
    showarr(uniqueA, sizeUniqueInA);
    cout << "\n\ttask5\n";
    int sizeUniqueInBoth;
    int* uniqueBoth = uniqueInBoth(A, M, B, N, sizeUniqueInBoth);
    cout << "Unique elements in both A and B: ";
    showarr(uniqueBoth, sizeUniqueInBoth);
    cout << endl;
    int newSizeFilteredA = M;
    int* nonprimes = removePrimes(A, newSizeFilteredA);
    cout << "Array A without prime numbers: ";
    showarr(nonprimes, newSizeFilteredA);
    cout << endl;
    {
    delete[] A;
    delete[] B;
    delete[] filteredA;
    delete[] common;
    delete[] uniqueA;
    delete[] uniqueBoth;
    delete[] nonprimes;
    }
}
template<typename T>
T* removeNegative(T* arr, int& size) {
    T* newArr = new T[size];
    int newSize = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] >= 0) {
            newArr[newSize++] = arr[i];
        }
    }
    size = newSize;
    T* result = new T[size];
    for (int i = 0; i < size; i++) {
        result[i] = newArr[i];
    }
    delete[] newArr;
    return result;
}
template<typename T>
T* commonElements(const T* A, int M, const T* B, int N, int& size) {
    T* common = new T[min(M, N)];
    size = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                bool found = false;
                for (int k = 0; k < size; k++) {
                    if (common[k] == A[i]) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    common[size++] = A[i];
                }
            }
        }
    }
    T* result = new T[size];
    for (int i = 0; i < size; i++) {
        result[i] = common[i];
    }
    delete[] common;
    return result;
}
template<typename T>
T* uniqueInA(const T* A, int M, const T* B, int N, int& size) {
    T* unique = new T[M];
    size = 0;

    for (int i = 0; i < M; i++) {
        bool foundInB = false;
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                foundInB = true;
                break;
            }
        }
        if (!foundInB) {
            bool foundInUnique = false;
            for (int k = 0; k < size; k++) {
                if (unique[k] == A[i]) {
                    foundInUnique = true;
                    break;
                }
            }
            if (!foundInUnique) {
                unique[size++] = A[i];
            }
        }
    }
    T* result = new T[size];
    for (int i = 0; i < size; i++) {
        result[i] = unique[i];
    }
    delete[] unique;
    return result;
}
template<typename T>
T* uniqueInBoth(const T* A, int M, const T* B, int N, int& size) {
    T* unique = new T[M + N];
    size = 0;

    for (int i = 0; i < M; i++) {
        bool foundInB = false;
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                foundInB = true;
                break;
            }
        }
        if (!foundInB) {
            bool foundInUnique = false;
            for (int k = 0; k < size; k++) {
                if (unique[k] == A[i]) {
                    foundInUnique = true;
                    break;
                }
            }
            if (!foundInUnique) {
                unique[size++] = A[i];
            }
        }
    }

    for (int j = 0; j < N; j++) {
        bool foundInA = false;
        for (int i = 0; i < M; i++) {
            if (B[j] == A[i]) {
                foundInA = true;
                break;
            }
        }
        if (!foundInA) {
            bool foundInUnique = false;
            for (int k = 0; k < size; k++) {
                if (unique[k] == B[j]) {
                    foundInUnique = true;
                    break;
                }
            }
            if (!foundInUnique) {
                unique[size++] = B[j];
            }
        }
    }

    T* result = new T[size];
    for (int i = 0; i < size; i++) {
        result[i] = unique[i];
    }
    delete[] unique;
    return result;
}
template<typename T>
T* removePrimes(T* arr, int& size) {
    T* newArr = new T[size];
    int newSize = 0;

    for (int i = 0; i < size; i++) {
        if (!isPrime(arr[i])) {
            newArr[newSize++] = arr[i];
        }
    }
    size = newSize;
    T* result = new T[size];
    for (int i = 0; i < size; i++) {
        result[i] = newArr[i];
    }
    delete[] newArr;
    return result;
}
template<typename T>
bool isPrime(T n) {
    if (n <= 1) return false;
    for (T i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
template <typename T>
void fillarr(T* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = 25 - rand() % 50;
    }
}
template <typename T>
void showarr(const T* arr, int size) {
    if (arr != nullptr) {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
}
