# Data structures and Algorithms

## Complexity (Big O)

Complexity of an algorithm measures time and memory. How long does one algorithm takes to finish? How much memory does it use?

We measure these values in terms of the input size (Usually for the input size we use the letter $n$)

We can analyze algorithms in the Best case, Average case and Worst case.

Best case measures the quickest way for an algorithm to finish.

Average case measures what time does the algorithm need to finish on average.

Worst case measures the slowest time for an algorithm to finish.

### General idea

1. Big O: $\mathcal{O}(n^2)$ - the algorithm takes **at most** $n^2$ steps to finish in the **WORST CASE**.
2. Little o: $\mathcal{o}(n^2)$ - the algorithm takes **less than** $n^2$ steps to finish in the **WORST CASE**.
3. Big Omega: $\Omega(n^2)$ - the algorithm takes **at least** $n^2$ steps to finish in the **BEST CASE**.
4. Little Omega: $\omega(n^2)$ - the algorithm takes **more than** $n^2$ steps to finish in the **BEST CASE**.
5. Big Theta: $\Theta(n^2)$ - the combination of $\mathcal{O}(n^2)$ and $\Omega(n^2)$. Meaning the algorithm takes at least $n^2$ steps to finish and takes at most $n^2$ steps to finish, i.e. it always takes $n^2$ steps.

### Comparison of orders of common functions

$$
\mathcal{O}(1) < \mathcal{O}(loglog(n)) < \mathcal{O}(log(n)) < \mathcal{O}(log^2(n)) < \mathcal{O}(\sqrt{n}) < \mathcal{O}(n) < \mathcal{O}(nlog(n)) < \mathcal{O}(n^2) <
\\
< \mathcal{O}(n^3) < \mathcal{O}(2^n) < \mathcal{O}(3^n) < \mathcal{O}(n!) < \mathcal{O}(n^n) < \mathcal{O}(3^{n^2}) < \mathcal{O}(2^{n^3})
$$

### Big O cheat sheet

https://www.bigocheatsheet.com/

### Formal definitions

$$
\mathcal{O}(f(n))=\{g(n): \exist c > 0, \exists n_0 > 0 \mid 0 \le g(n) \le cf(n) \space \forall n \ge n_0 \}
$$

$$
\Theta(f(n))=\{g(n): \exist c_1 > 0, \exist c_2 > 0, \exists n_0 > 0 \mid 0 \le c_1f(n) \le g(n) \le c_2 f(n) \space \forall n \ge n_0 \}
$$

$$
\Omega(f(n))=\{g(n): \exist c > 0, \exists n_0 > 0 \mid 0 \le cf(n) \le g(n) \space \forall n \ge n_0 \}
$$

$$
\mathcal{o}(f(n))=\{g(n): \forall c > 0 \space \exists n_0 > 0 \mid 0 \le g(n) < cf(n) \space \forall n \ge n_0 \}
$$

$$
\omega(f(n))=\{g(n): \forall c > 0 \space \exists n_0 > 0 \mid 0 \le cf(n) < g(n) \space \forall n \ge n_0 \}
$$

### Examples

$\mathcal{O}(34n^4+5) = n^4$

$\mathcal{O}(2^n+n^{1024}+log(n)) = 2^n$

$\mathcal{O}(5N + \frac{1}{2} M) = N + M$

$\mathcal{O}(n^2)$ means that if our algorithm takes input of 10 elements it will need 100 steps to finish in the worst case. If the input is of 100 elements it will need 10000 steps to finish in the worst case.

### Constants and Big O

Usually we discard constants when using Big O, but in some cases the constant can be meaningful for small input sizes. In the following example $\mathcal{O}(n^2)$ is faster than $\mathcal{O}(n)$ because our complexities are $n^2$ and $9n$ so for $n < 9$ the $n^2$ algorithm is faster than the $9n$ one.

![](https://i.imgur.com/qv7rO70.png)

## Sorting

Sorting means ordering a set of elements in a sequence.

We can sort a set of elements whose elements are in partial order. Partial order is a relation with the following properties:

1. Antisymmetry - For every 2 elements in the set (A, B), if $A \le B$ and $B \le A$ then $A=B$.
2. Transitivity - For every 3 elements in the set (A, B, C), if $A \le B$ and $B \le C$ then $A \le C$.
3. Reflexivity - For every element in the set A, $A \le A$.

### Sorting properties

#### Stable sort

A sorting algorithm is stable if two equal objects appear in the same order in the ordered output as they appeared in the unsorted input.

> Example input: $1, 2, 3_a, 8, 5, 3_b$. Here $3_a$ and $3_b$ are simply a 3 but we have marked them to follow what happens with them after the sorting.
>
> Example output: $1,2,3_a,3_b,5,8$
>
> Unstable sort output: $1,2,3_b,3_a,5,8$

#### In place sort

Uses only a small constant amount of extra memory. In place sort means the elements are swapped around. Out of place means we use another extra array to swap items around.

#### Number of comparisons

How many times do we need to compare 2 elements. For most sorts this represents the time complexity.

#### Adaptive sort

Determines whether the sorting algorithm runs faster for inputs that are partially or fully sorted. If an algorithm is unadaptive it runs for the same time on sorted and unsorted input. If an algorithm is adaptive it runs faster on sorted input than on unsorted input.

#### Online sort

Determines if an algorithm needs all the items from the input to start sorting. If an algorithm is online it can start sorting input that is given in parts. If an algorithm is offline it can start sorting only after it has the whole input.

#### External sort

Allows sorting data which cannot fit into memory. Such algorithms are designed to sort massive amounts of data (Gigabytes, Terabytes, etc.)

#### Parallel sort

An algorithm which can be ran on multiple threads at the same time, speeding the running time.

#### Locality

An algorithm which heavily uses the processor cache to speed up its execution. The data processed needs to be sequentially located.

### Helper code

```c++
// swap the values of two variables
void swap(int & a, int & b) {
    int tmp = a;
    a = b;
    b = tmp;
}
```

### Bubble sort

| Bubble sort           | n = input size     |
| --------------------- | ------------------ |
| Time complexity       | $\mathcal{O}(n^2)$ |
| Space complexity      | $\mathcal{O}(1)$   |
| Adaptive              | Yes                |
| Stable                | Yes                |
| Number of comparisons | $\mathcal{O}(n^2)$ |
| Number of swaps       | $\mathcal{O}(n^2)$ |
| Online                | No                 |
| In place              | Yes                |

Honorable mention - Cocktail shaker sort, similar to bubble and selection sort. It’s like the Online version of bubble sort.

#### Clean code

```c++
void bubbleSort(int * array, int length) {
    for (int bubbleStartIndex = 0; bubbleStartIndex < length; bubbleStartIndex++) {
        for (int bubbleMovedIndex = 0; bubbleMovedIndex < length - 1; bubbleMovedIndex++) {
            if (array[bubbleMovedIndex] > array[bubbleMovedIndex+1]) {
                swap(array[bubbleMovedIndex], array[bubbleMovedIndex+1]);
            }
        }
    }
}
```

#### Short code

```c++
void bubbleSort(int * array, int length) {
    for (int i = 0; i < length; i++) {
        for (int k = 0; k < length - 1; k++) {
            if (array[k] > array[k+1]) {
                swap(array[k], array[k+1]);
            }
        }
    }
}
```

#### Optimization 1 - make it faster

```c++
void bubbleSort(int * array, int length) {
    for (int i = 0; i < length; i++) {
        for (int k = 0; k < length - 1 - i; k++) { // length - 1 - i = 2x less iterations
            if (array[k] > array[k+1]) {
                swap(array[k], array[k+1]);
            }
        }
    }
}
```

#### Optimization 2 - make it adaptive

```c++
void bubbleSort(int * array, int length) {
    for (int i = 0; i < length; i++) {
        bool swappedAtLeastOnce = false; // add a flag to check if a swap has occurred

        for (int k = 0; k < length - 1 - i; k++) {
            if (array[k] > array[k+1]) {
                swap(array[k], array[k+1]);
                swappedAtLeastOnce = true;
            }
        }
        
        if (!swappedAtLeastOnce) { // if there were no swaps, it's ordered
            break;
        }
    }
}
```

### Selection sort

| Selection sort        | n = input size     |
| --------------------- | ------------------ |
| Time complexity       | $\mathcal{O}(n^2)$ |
| Space complexity      | $\mathcal{O}(1)$   |
| Adaptive              | No                 |
| Stable                | No                 |
| Number of comparisons | $\mathcal{O}(n^2)$ |
| Number of swaps       | $\mathcal{O}(n)$   |
| Online                | No                 |
| In place              | Yes                |

#### Key points

1. It’s better than bubble sort in cases we need to sort items which are very large in size because it has $\mathcal{O}(n)$ swaps.

#### Clean code

```c++
void selectionSort(int * array, int length) {
    for (int currentIndex = 0; currentIndex < length; currentIndex++) {
        int smallestNumberIndex = currentIndex;

        for (int potentialSmallerNumberIndex = currentIndex + 1; 
             	potentialSmallerNumberIndex < length;
             	potentialSmallerNumberIndex++) {
            if (array[potentialSmallerNumberIndex] < array[smallestNumberIndex]) {
                smallestNumberIndex = potentialSmallerNumberIndex;
            }
        }
        
        swap(array[currentIndex], array[smallestNumberIndex]);
    }
}
```

#### Short code

```c++
void selectionSort(int * array, int length) {
    for (int i = 0; i < length; i++) {
        int index = i;

        for (int k = i + 1; k < length; k++) {
            if (array[k] < array[index]) {
                index = k;
            }
        }
        
        swap(array[i], array[index]);
    }
}
```

### Insertion sort

| Insertion sort        | n = input size     |
| --------------------- | ------------------ |
| Time complexity       | $\mathcal{O}(n^2)$ |
| Space complexity      | $\mathcal{O}(1)$   |
| Adaptive              | Yes                |
| Stable                | Yes                |
| Number of comparisons | $\mathcal{O}(n^2)$ |
| Number of swaps       | $\mathcal{O}(n^2)$ |
| Online                | Yes                |
| In place              | Yes                |

#### Key points

1. The best algorithm for sorting small arrays.
2. Often combined with other algorithms for optimal runtime.

#### Clean code

```c++
void insertionSort(int * array, int length) {
    for (int nextItemToSortIndex = 1; nextItemToSortIndex < length; nextItemToSortIndex++) {
        for (int potentiallyBiggerItemIndex = nextItemToSortIndex; 
             	potentiallyBiggerItemIndex > 0 && 
             	array[potentiallyBiggerItemIndex] < array[potentiallyBiggerItemIndex - 1];
             	potentiallyBiggerItemIndex--) {
            swap(array[potentiallyBiggerItemIndex], array[potentiallyBiggerItemIndex-1]);
        }
    }
}
```

#### Short code

```c++
void insertionSort(int * array, int length) {
    for (int i = 1; i < length; i++) {
        for (int k = i; k > 0 && array[k] < array[k - 1]; k--) {
            swap(array[k], array[k-1]);
        }
    }
}
```

### Merge sort

| Merge sort            | n = input size          |
| --------------------- | ----------------------- |
| Time complexity       | $\mathcal{O}(n*log(n))$ |
| Space complexity      | $\mathcal{O}(n)$        |
| Adaptive              | No                      |
| Stable                | Yes                     |
| Number of comparisons | $\mathcal{O}(n*log(n))$ |
| External              | Yes                     |
| Parallel              | Yes                     |
| Online                | No                      |
| In place              | No                      |

#### Key points

1. Every array of 0 or 1 elements is sorted.
2. Merging requires additional memory.
3. Splitting the array in 2 every time gives us $log(n)$ levels.
4. On each level we have $\mathcal{O}(n)$ for the merging operation.

Honorable mention - Ford–Johnson aka Merge-insertion sort. Cool idea, but not practical enough.

Important algorithm: Timsort - Absolute beast.

#### Clean code

```c++
void merge(int * originalArray, int * mergeArray, int start, int mid, int end) {
    int leftIndex = start;
    int rightIndex = mid + 1;
    int sortedIndex = start;

    while (leftIndex <= mid && rightIndex <= end) {
        if (originalArray[leftIndex] <= originalArray[rightIndex]) {
            mergeArray[sortedIndex] = originalArray[leftIndex];
            leftIndex++;
        } else {
            mergeArray[sortedIndex] = originalArray[rightIndex];
            rightIndex++;
        }

        sortedIndex++;
    }

    while (leftIndex <= mid) {
        mergeArray[sortedIndex] = originalArray[leftIndex];
        leftIndex++;
    }
    while (rightIndex <= end) {
        mergeArray[sortedIndex] = originalArray[rightIndex];
        rightIndex++;
    }

    for (int i = start; i <= end; i++) {
        originalArray[i] = mergeArray[i];
    }
}

void mergeSortRecursive(int * original, int * mergeArray, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;

        mergeSortRecursive(original, mergeArray, start, mid);
        mergeSortRecursive(original, mergeArray, mid + 1, end);

        merge(original, mergeArray, start, mid, end);
    }
}

void mergeSort(int * array, int length) {
    int * mergeArray = new int[length];
    mergeSortRecursive(array, mergeArray, 0, length - 1);
    delete[] mergeArray;
}
```

#### Short code

```c++
void merge(int * originalArray, int * mergeArray, int start, int mid, int end) {
    int left = start;
    int right = mid + 1;

    for (int i = start; i <= end; i++) {
        if (left <= mid && (right > end || originalArray[left] <= originalArray[right])) {
            mergeArray[i] = originalArray[left];
            left++;
        } else {
            mergeArray[i] = originalArray[right];
            right++;
        }
    }

    for (int i = start; i <= end; i++) {
        originalArray[i] = mergeArray[i];
    }
}

void mergeSortRecursive(int * originalArray, int * mergeArray, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;

        mergeSortRecursive(originalArray, mergeArray, start, mid);
        mergeSortRecursive(originalArray, mergeArray, mid + 1, end);

        merge(originalArray, mergeArray, start, mid, end);
    }
}

void mergeSort(int * array, int length) {
    int * mergeArray = new int[length];
    mergeSortRecursive(array, mergeArray, 0, length - 1);
    delete[] mergeArray;
}
```

### Quick sort

| Quick sort                     | n = input size                        |
| ------------------------------ | ------------------------------------- |
| Time complexity (Worst case)   | $\mathcal{O}(n^2)$                    |
| Time complexity (Average case) | $\mathcal{O}(n*log(n))$               |
| Space complexity               | $\mathcal{O}(log(n))$                 |
| Adaptive                       | No                                    |
| Anti-Adaptive                  | Yes (the more randomness, the better) |
| Stable                         | No                                    |
| Number of comparisons          | $\mathcal{O}(n*log(n))$               |
| Parallel                       | Yes                                   |
| Online                         | No                                    |
| In place                       | Yes                                   |
| Locality                       | Yes                                   |

#### Key points

1. Quick sort adores chaos. That’s why a common strategy is to shuffle the array before sorting it.

C++ STL sorting algorithm is Introsort, which is a hybrid between quicksort and heapsort.

Quick sort optimization for arrays with many equal numbers - three-way partitioning, aka Dutch national flag.

Quick sort can also be optimized with picking 2 pivots instead of 1 - multi-pivot quicksort.

#### Clean code using Lomuto partitioning

```c++
int partition(int * array, int startIndex, int endIndex) {
    int pivot = array[endIndex];
    int pivotIndex = startIndex;

    for (int i = startIndex; i <= endIndex; i++) {
        if (array[i] < pivot) {
            swap(array[i], array[pivotIndex]);
            pivotIndex++;
        }
    }

    swap(array[endIndex], array[pivotIndex]);
    return pivotIndex;
}

void _quickSort(int * array, int startIndex, int endIndex) {
    if (startIndex < endIndex) {
        int pivot = partition(array, startIndex, endIndex);
        _quickSort(array, startIndex, pivot - 1);
        _quickSort(array, pivot + 1, endIndex);
    }
}

void quickSort(int * array, int length) {
    _quickSort(array, 0, length - 1);
}
```

#### Short code using Lomuto partitioning

```c++
int partition(int * array, int start, int end) {
    int pivot = array[end];
    int pivotIndex = start;
    for (int i = start; i <= end; i++) {
        if (array[i] < pivot) {
            swap(array[i], array[pivotIndex]);
            pivotIndex++;
        }
    }
    swap(array[end], array[pivotIndex]);
    return pivotIndex;
}

void _quickSort(int * array, int start, int end) {
    if (start < end) {
        int pivot = partition(array, start, end);
        _quickSort(array, start, pivot - 1);
        _quickSort(array, pivot + 1, end);
    }
}

void quickSort(int * array, int length) {
    _quickSort(array, 0, length - 1);
}
```

#### Optimization 1 - pivot is random number

```c++
#include <random>
int generateRandomNumber(int from, int to) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(from,to);

    return dist6(rng);
}

int partition(int * array, int start, int end) {
    int randomIndex = generateRandomNumber(start, end);
    swap(array[end], array[randomIndex]);
    
    int pivot = array[end];
    int pivotIndex = start;
    for (int i = start; i <= end; i++) {
        if (array[i] < pivot) {
            swap(array[i], array[pivotIndex]);
            pivotIndex++;
        }
    }
    swap(array[end], array[pivotIndex]);
    return pivotIndex;
}

void _quickSort(int * array, int start, int end) {
    if (start < end) {
        int pivot = partition(array, start, end);
        _quickSort(array, start, pivot - 1);
        _quickSort(array, pivot + 1, end);
    }
}

void quickSort(int * array, int length) {
    _quickSort(array, 0, length - 1);
}
```

#### Optimization 2 - shuffle before picking pivot

```c++
#include <random>
int generateRandomNumber(int from, int to) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(from,to);

    return dist6(rng);
}

void shuffle(int * arr, int length) {
    for (int i = 0; i < length - 1; i++) {
        int swapCurrentWith = generateRandomNumber(i, length - 1);
        swap(arr[i], arr[swapCurrentWith]);
    }
}

int partition(int * array, int start, int end) {
    shuffle(array + start, end - start);

    int pivot = array[end];
    int pivotIndex = start;
    for (int i = start; i <= end; i++) {
        if (array[i] < pivot) {
            swap(array[i], array[pivotIndex]);
            pivotIndex++;
        }
    }
    swap(array[end], array[pivotIndex]);
    return pivotIndex;
}

void _quickSort(int * array, int start, int end) {
    if (start < end) {
        int pivot = partition(array, start, end);
        _quickSort(array, start, pivot - 1);
        _quickSort(array, pivot + 1, end);
    }
}

void quickSort(int * array, int length) {
    _quickSort(array, 0, length - 1);
}
```

#### Short code using Hoare partitioning

```c++
int partition(int * array, int start, int end) {
    int pivot = array[(start + end) / 2];
    int left = start;
    int right = end;
    
    while (true) {
        while (array[left] < pivot) {
            left++;
        }
        while (array[right] > pivot) {
            right--;
        }
        
        if (left >= right) {
            return right;
        }

        swap(array[left], array[right]);
    }
}

void _quickSort(int * array, int start, int end) {
    if (start < end) {
        int pivot = partition(array, start, end);
        _quickSort(array, start, pivot - 1);
        _quickSort(array, pivot + 1, end);
    }
}

void quickSort(int * array, int length) {
    _quickSort(array, 0, length - 1);
}
```

### Counting sort

| Counting sort                | n = input size, k = max number |
| ---------------------------- | ------------------------------ |
| Time complexity (Worst case) | $\mathcal{O}(n + k)$           |
| Time complexity (Best case)  | $\mathcal{O}(n)$               |
| Space complexity             | $\mathcal{O}(k)$               |

#### Key points

1. Not a comparison sort.
2. Very efficient for an array of integers with many repeating integers with small difference between the biggest and smallest integer.

#### Counting sort for positive numbers

```c++
void countingSort(int * array, int length) {
    int maxNumber = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] > maxNumber) {
            maxNumber = array[i];
        }
    }

    int * countingArray = new int[maxNumber + 1];
    for (int i = 0; i < maxNumber + 1; i++) {
        countingArray[i] = 0;
    }

    for (int i = 0; i < length; i++) {
        countingArray[array[i]]++;
    }

    int sortedIndex = 0;
    for (int i = 0; i < length; i++) {
        while (countingArray[sortedIndex] == 0) {
            sortedIndex++;
        }

        array[i] = sortedIndex;
        countingArray[sortedIndex]--;
    }

    delete[] countingArray;
}
```

### Bucket sort

| Bucket sort                    | n = input size, k = number of buckets |
| ------------------------------ | ------------------------------------- |
| Time complexity (Worst case)   | $\mathcal{O}(n^2)$                    |
| Time complexity (Average case) | $\mathcal{O}(n+\frac{n^2}{k}+k)$      |
| Space complexity               | $\mathcal{O}(nk)$                     |

#### Key points

1. It’s a distribution sort, not a comparison sort.
2. Very situational sort.
3. The bellow code is a sample implementation for floats between 0 and 1.

```c++
#include <iostream>
#include <vector>
#include <algorithm>
void bucketSort(double *array, int length) {
    std::vector<double> buckets[length];

    for(int i = 0; i < length; i++) {
        buckets[int(length * array[i])].push_back(array[i]);
    }

    for(int i = 0; i < length; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;
    for(int i = 0; i < length; i++) {
        while(!buckets[i].empty()) {
            array[index] = buckets[i][0];
            index++;
            buckets[i].erase(buckets[i].begin());
        }
    }
}
```

### Radix sort

| Radix sort                     | n = input size                   |
| ------------------------------ | -------------------------------- |
| Time complexity (Worst case)   | $\mathcal{O}(n^2)$               |
| Time complexity (Average case) | $\mathcal{O}(n+\frac{n^2}{k}+k)$ |
| Space complexity               | $\mathcal{O}(nk)$                |

#### Key points

1. Good on multi-threaded machines.

```c++
#include <iostream>
#include <cmath>
#include <list>

int abs(int a) {
    return a >= 0 ? a : -a;
}

void radixSort(int * array, int length) {
    int maxNumber = 0;
    for (int i = 0; i < length; i++) {
        if (abs(array[i]) > maxNumber) {
            maxNumber = abs(array[i]);
        }
    }

    int maxDigits = log10(maxNumber) + 1;

    std::list<int> pocket[10];

    for(int i = 0; i < maxDigits; i++) {
        int m = pow(10, i + 1);
        int p = pow(10, i);

        for(int j = 0; j < length; j++) {
            int temp = array[j] % m;
            int index = temp / p;
            pocket[index].push_back(array[j]);
        }

        int count = 0;
        for(int j = 0; j<10; j++) {
            while(!pocket[j].empty()) {
                array[count] = *(pocket[j].begin());
                pocket[j].erase(pocket[j].begin());
                count++;
            }
        }
    }
}
```

## Linked list

