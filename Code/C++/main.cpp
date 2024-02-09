#include "interviewprep.cpp"
#include "linkedlist.cpp"
#include <iostream>
#include <array>
using namespace std;

void randomNumbers(int numberArray[], int size) {
    // Produces the same random array
    srand (time(NULL));
    for (int i = 0; i < size; i++) {
        numberArray[i] = rand() % 100;
    }
}

void printNumbers(int numberArray[], int size) {
    for(int i = 0; i < size; i++) {
        if (i % 20 == 0) {
            cout << endl;
        }
        cout << numberArray[i] << "  ";
    }
    cout << endl;
}

void swap (int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

//Sorting Algorithms
void bubbleSort(int numberArray[], int size) {
    // Parse in pairs (Bubbles) shifting larger values to the right, thus right side becomes the sorted portion
    // Time Complexity: Best: O(n), Avg/Worst: O(n^2) | Space Complexity: O(1)
    for (int i = 0; i < size-1; i++) {
        for (int n = 0; n < size-1; n++) {
            if (numberArray[n+1] < numberArray[n]) {
                swap (&numberArray[n], &numberArray[n+1]);
            }
        }
    }
    cout << endl << "Bubble Sort";
    printNumbers(numberArray, size);
}

void selectionSort(int numberArray[], int size) {
    // Moves smallest value to the left
    // Time Complexity: Best: O(n), Avg/Worst: O(n^2) | Space Complexity: O(1)
    int min;
    for (int i = 0; i < size-1; i++) {
        min = i;
        for (int n = i+1; n < size; n++) {
            if (numberArray[n] < numberArray[min]) {
                min = n;
            }
        }
        swap(&numberArray[i], &numberArray[min]);
    }
    cout << endl << "Selection Sort";
    printNumbers(numberArray, size);
}

void insertionSort(int numberArray[], int size) {
    // Moves smallest value to the left
    // Time Complexity: Best: O(n), Avg/Worst: O(n^2) | Space Complexity: O(1)
    for (int i = 1; i < size; i++) {
        int idx = i;
        while (numberArray[idx] < numberArray[idx-1] && idx > 0) {
            swap(&numberArray[idx-1], &numberArray[idx]);
            idx--;
        }
    }
    cout << endl << "Insertion Sort";
    printNumbers(numberArray, size);
}

int partition(int numberArray[], int low, int high) {
    // Separates into high/low relative to pivot = numberArray[high]
    // Low stops at the first value that is greater than the pivots
    for(int i = low; i < high; i++) {
        if(numberArray[i] < numberArray[high]) {
            swap(&numberArray[i], &numberArray[low]);
            // If numberArray[i] is less than pivot then swap with first non-swapped value (index=low)
            low++;
        }
    }
    swap(&numberArray[high], &numberArray[low]);
    // Since low is incremented after swaps, numberArray[low] is greater than pivot. Thus swap with pivot.
    return low;
    // Returns index that swaps have been made up until
}

void quickSort(int numberArray[], int low, int high) {
    // Repeatedly/Recursively partition relative to a pivot value creating high/low portions
    // Time Complexity: Best/Avg: O(nlog(n)), Worst: O(n^2) | Space Complexity: O(log(n))
    if (low < high) {
        // Once partition of size 3 recursive branch ends
        // Ie: [<Pivot] [Pivot] [>Pivot] -> [<Pivot] [Pivot] or [Pivot] [>Pivot]
        int pivot = partition(numberArray, low, high);
        quickSort(numberArray, low, pivot-1);
        // Checks all values less than the Pivot
        quickSort(numberArray, pivot+1, high);
        // Checks all values greater than or equal to the Pivots
    }
}

void merge(int numberArray[], int left, int mid, int right) {
    int leftRange = mid-left+1;
    int rightRange = right-mid;

    int leftArray [leftRange];
    int rightArray [rightRange];
    for (int i = 0; i < leftRange; i++) {
        leftArray[i] = numberArray[left+i];
    }
    for (int i = 0; i < rightRange; i++) {
        rightArray[i] = numberArray[mid+1+i];
    }

    int firstIdx = 0;
    int secondIdx = 0;
    int mergedIdx = left;

    // Combines Left and Right Array between left and right index parameters
    while (firstIdx < leftRange && secondIdx < rightRange) {
        if (leftArray[firstIdx] <= rightArray[secondIdx]) {
            numberArray[mergedIdx] = leftArray[firstIdx];
            firstIdx++;
        } else {
            numberArray[mergedIdx] = rightArray[secondIdx];
            secondIdx++;
        }
        mergedIdx++;
    }
    while (firstIdx < leftRange) { // Combines any remaining elements in leftArray
        numberArray[mergedIdx] = leftArray[firstIdx];
        firstIdx++;
        mergedIdx++;
    }
    while (secondIdx < rightRange) { // Combines any remaining elements in rightArray
        numberArray[mergedIdx] = rightArray[secondIdx];
        secondIdx++;
        mergedIdx++;
    }
}

void mergeSort(int numberArray[], int left, int right) {
    // Recursively breakdown into single elements and while loop combine in order
    // Time Complexity: Best/Avg/Worst: O(nlog(n)) | Space Complexity: O(n)
    if (left < right ) {
        //Ends once left = right, ie subarray is a single element
        int mid = (left + right)/ 2;
        mergeSort(numberArray, left, mid);
        // Repeatedly break-down left subarray until single elements
        mergeSort(numberArray, mid + 1, right);
        merge(numberArray, left, mid, right);
        // Recompile while sorting
    }
}

void heapify(int numberArray[], int size, int node) {
    // Finds largest value
    int largest = node;
    int left = 2*node+1;
    int right = 2*node+2;

    if (left < size && numberArray[largest] < numberArray[left]) {
        largest = left;
    }
    if (right < size && numberArray[largest] < numberArray[right]) {
        largest = right;
    }

    if (largest != node) { // Repeat while Root is not the Largest
        swap(&numberArray[node], &numberArray[largest]);
        heapify(numberArray, size, largest);
    }
}

void heapSort(int numberArray[], int size) {
    // Turn array into Max-Heap removing the root (Max) value each time
    // Time Complexity: Best/Avg/Worst: O(nlog(n)) | Space Complexity: O(1)
    for (int i = size/2-1; 0 <= i; i--) { // Create Max Heap
        heapify(numberArray, size, i);
    }
    for (int i = size-1; 0 < i; i--) {  // Repeatedly extracts max value and recreates max-heap with remaining elements
        swap(&numberArray[0], &numberArray[i]);
        heapify(numberArray, i, 0);
    }
    cout << endl << "Heap Sort";
    printNumbers(numberArray, size);
}

int linearSearch(int numberArray[], int size, int x) {
    for (int i = 0; i < size; i ++ ) {
        if (numberArray[i] == x) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int numberArray[], int left, int right, int x) {
    if (left <= right ) {
        int mid = (left + right - 1)/2;
        if (numberArray[mid] == x) {
            return mid;
        }
        if (x < numberArray[mid]) {
            return binarySearch(numberArray, left, mid-1, x);
        }
        return binarySearch(numberArray, mid+1, right, x);
    }
    return -1;
}

int main() {
    int size = 10;
    int unsortedNumbers[size];

    randomNumbers(unsortedNumbers, size);
    cout << endl << "Unsorted";
    printNumbers(unsortedNumbers, size);

    bubbleSort(unsortedNumbers, size);

    randomNumbers(unsortedNumbers, size);
    selectionSort(unsortedNumbers, size);

    randomNumbers(unsortedNumbers, size);
    insertionSort(unsortedNumbers, size);

    randomNumbers(unsortedNumbers, size);
    quickSort(unsortedNumbers, 0, size-1);
    cout << endl << "Quick Sort";
    printNumbers(unsortedNumbers, size);

    randomNumbers(unsortedNumbers, size);
    mergeSort(unsortedNumbers, 0, size-1);
    cout << endl << "Merge Sort";
    printNumbers(unsortedNumbers, size);

    randomNumbers(unsortedNumbers, size);
    heapSort(unsortedNumbers, size);

    cout << endl << "Linked List" << endl;
    list ll;
    ll.list_append(3);
    ll.list_append(2);
    ll.list_append(1);
    ll.list_prepend(4);
    ll.list_prepend(5);
    ll.list_print();



}


/*
 * ---NOTES---
 * C++ Program Structure -> https://www.cplusplus.com/doc/tutorial/program_structure/
 *  - # are directives read and interpreted by what is known as the preprocessor
 *      - Interpreted before the compilation of the program itself begins
 *      - Instructs the preprocessor to include a section of standard C++ code, known as header
 *  - Statement: An expression that can actually produce some effect
 *  - std: Abbreviation of Standard
 *      - 'Using namespace std': Uses the std namespace so that std:: doesn't need to prefix everything
 *          - Can create naming conflicts that may result in compilation errors or wrong function calls
 *              - Ex. Cout function is defined in a custom namespace in addition to std
 *      - Namespace: Declarative region that provides scope to identifiers (Name Types, Functions, Variables, etc...)
 *
 * Data Magnitudes -> https://wiki.ubuntu.com/UnitsPolicy
 *  - Bit(b): 0 or 1
 *  - Nibble: 4 bits
 *  - Byte(B): 8 bits
 *  - Decimal: Uses base-10 International System of Units (SI) standard
 *      - kilobyte(kB): 1000 bytes
 *      - megabyte(MB): 1000^2 bytes
 *      - gigabyte(GB): 1000^3 bytes
 *  - Binary: Uses base-2 International Electrotechnical Commission (IEC 600027) standard
 *      - kilobyte(KB)/kibibyte(KiB): 1024 bytes
 *      - megabyte(MB)/mebibyte(MiB): 1024^2 bytes
 *      - gigabyte(GB)/gibibyte(GiB): 1024^3 bytes
 *
 * Pointers -> https://www.cplusplus.com/doc/tutorial/pointers/
 *  - Pointer: Variable that stores the address of another variable
 *  - Address-of Operator(&): Obtains address of a variable
 *  - Dereference Operator(*): Obtains value of a pointer
 *      - Ex. variable = 7, pointer = &variable == 0xffffcbc0 (Memory Address), *pointer == 7
 *
 * Pass By Value vs Reference
 *  - Pass by Value: Caller and callee have two independent variables with the same value
 *      - Ex. Caller: passByVal(val), Callee: passByVal(type val) {...}
 *  - Pass by Reference: Caller and the callee use the same variable for the parameter
 *      - Ex. Caller: passByRef(&val), Callee: passByRef(type &val) {...}
 *          - Derivatives by Pass by Reference:
 *              - Ex. Caller: passPtr(ptrName), Callee: passPtr(type *ptrName) {...}
 *              - Ex. Caller: passRef(refName), Callee: passRef(type &refName) {...}
 *              - Ex. Caller: passPtrArg(&varName), Callee: passPtrArg(type *ptrName) {...}
 *      - Ex. Caller: passByPtr(*val), Callee: passByRef(type *val) {...}
 *
 * Deep vs Shallow Copy
 *  - Deep Copy:
 *
 * Trees
 *  - Tree: All nodes originate from a single Root Node and each Child Node has ONLY 1 Parent Node
 *      - General Tree (Tree): No limit of Children per Parent Node
 *      - Binary Tree: At most 2 Children per Parent Node
 *      - Binary Search Tree: Node Values are Left <= Parent <= Right
 *      - Full/Proper Binary Tree (2-Tree): Every Parent has 2 Children
 *      - Perfect Binary Tree: Every Parent has exactly 2 Children
 *      - Complete Binary Tree/Heap/Array: Only last level may be incompletely filled and then prioritized left to right
 *          - Min-Heap Order Property: Root = Min Value and Children Value <= Parent
 *          - Max-Heap Order Property: Root = Max Value and Children Value >= Parent
 *      - Balanced Binary Tree: Tree height is O(log(n)) for N = Number of Nodes
 *          - Height of left and right subtrees for each node varies at most +/- 1
 *      - AVL Tree: Self Balancing Binary Search Tree
 *          - Each node stores Balance Factor: -1 = Only Right Child, 0 = Either 2 or No Children, 1 = Only Left Child
 *
 * Logarithm: Power of B to equal A; Ie: logb(a) = c == b^c = a
 *      - Ex. Log 8 for base 2 is 3 since 2^3 = 8
 *
 * Big O Notation -> https://rob-bell.net/2009/06/a-beginners-guide-to-big-o-notation/
 *  - Big O Notation: Characterizes functions according to growth rates
 *      - Describes the performance or complexity of an algorithm
 *      https://www.freecodecamp.org/news/big-o-notation-why-it-matters-and-why-it-doesnt-1674cfa8a23c/
 *      - O (Big O): Upper Bound
 *      - Ω (Omega): Lower Bound
 *      - Θ (Theta): Exact Bound
 *      - o (Lil O): Upper Bound excluding Exact Bound
 *  - Time Complexity: Execution time for n inputs
 *  - Space Complexity: Amount of memory/space needed for n inputs
 *  - O(1) 'Constant': Same amount of executions regardless n number of inputs
 *      - Ex. First element of an Array
 *  - O(log(n)) 'Logarithmic': Execution increases linearly while n increases exponentially
 *      - Ex. Divide and conquer algorithms like Binary Search
 *  - O(n) 'Linear': Performance is directly proportional to the size of the input data set
 *      - Ex. For 0 to n
 *  - O(nlog(n)) = O(log(n!) 'Linearithmic'/'Loglinear': Doing log(n) n number of times
 *      - Ex. Ideal Quick Sort log(n) partitions at n visits per level log(n) * n = nlog(n)
 *  - O(n^2) 'Quadratic': Performance is directly proportional to the square size of the input data set
 *      - Ex. Nested For 0 to n
 *  - O(2^n) 'Exponential': Growth doubles with each additional element in an input data set
 *      - Ex. Recursively find the nth number in the fibonacci sequence
 *  - O(n!) 'Factorial':
 *      - Ex. Find all permutations (Order Matters)
 */

