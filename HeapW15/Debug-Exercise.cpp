/*
Q1.Debug the code.
void heapify(int arr[], int N, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < N && arr[l] > arr[largest])
        largest = l;
    if (r < N && arr[r] > arr[largest])
        largest = r;
    if (largest == i) {
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N) {
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
    for (int i = 0; i < N - 1; i++) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
Ans:-
void heapify(int arr[], int N, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < N && arr[l] > arr[largest])
        largest = l;
    if (r < N && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N) {
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
    for (int i = N - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Q2.Debug the code.
void firstKthElement(int arr[], int size, int k) {
    MinHeap* m = new MinHeap(0, arr);
    for (int i = 0; i < size; i++) {
        if (arr[0] > arr[i])
            continue;
        else {
            arr[0] = arr[i];
            m->heapify(0);
        }
    }
}
Ans:-
void firstKthElement(int arr[], int size, int k) {
    MinHeap* m = new MinHeap(k, arr);
    for (int i = k; i < size; i++) {
        if (arr[0] > arr[i])
            continue;
        else {
            arr[0] = arr[i];
            m->heapify(0);
        }
    }
}
// Q3.Debug the code. Merge K sorted arrays.
// For reference
// struct MinHeapNode {
//     // The element to be stored
//     int element;
//     // index of the array from which the element is taken
//     int i;
//     // index of the next element to be picked from the array
//     int j;
// };

int* mergeKArrays(int arr[][N], int K) {
    int* output = new int[N * K];
    MinHeapNode* harr = new MinHeapNode[K];
    for (int i = 0; i < K; i++) {
        harr[i].element = arr[i][0];
        harr[i].i = i;
        harr[i].j = 1;
    }
    MinHeap hp(harr, K);
    for (int count = 0; count < N * K; count++) {
        MinHeapNode root = hp.getMin();
        output[count] = root.element;
        if (root.i < N) {
            root.element = arr[root.i][root.j];
            root.j += 1;
        }
        else
            root.element = INT_MAX;
        hp.replaceMin(root);
    }
    return output;
}
Ans:-
int* mergeKArrays(int arr[][N], int K) {
    int* output = new int[N * K];
    MinHeapNode* harr = new MinHeapNode[K];
    for (int i = 0; i < K; i++) {
        harr[i].element = arr[i][0];
        harr[i].i = i;
        harr[i].j = 1;
    }
    MinHeap hp(harr, K);
    for (int count = 0; count < N * K; count++) {
        MinHeapNode root = hp.getMin();
        output[count] = root.element;
        if (root.j < N) {
            root.element = arr[root.i][root.j];
            root.j += 1;
        }
        else
            root.element = INT_MAX;
        hp.replaceMin(root);
    }
    return output;
}
// Q4.Debug the code. Median in a stream of integers (running integers).
void streamMedian(int A[], int n) {
    priority_queue<int> g, s;
    for (int i = 0; i < n; i++) {
        s.push(A[i]);
        int temp = s.top();
        s.pop();
        g.push(temp);
        if (g.size() > s.size()) {
            temp = g.top();
            g.pop();
            s.push(-1 * temp);
        }
        if (g.size() == s.size())
            cout << (double)s.top() << endl;
        else
            cout << (double)((s.top() * 1.0 - g.top() * 1.0)/ 2) << endl;
    }
}
Ans:-
void streamMedian(int A[], int n) {
    priority_queue<int> g, s;
    for (int i = 0; i < n; i++) {
        s.push(A[i]);
        int temp = s.top();
        s.pop();
        g.push(-1 * temp);
        if (g.size() > s.size()) {
            temp = g.top();
            g.pop();
            s.push(-1 * temp);
        }
        if (g.size() != s.size())
            cout << (double)s.top() << endl;
        else
            cout << (double)((s.top() * 1.0 - g.top() * 1.0)/ 2) << endl;
    }
}
*/