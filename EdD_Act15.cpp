#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;  // Array-based heap

    // Helper: swap parent & child upward
    void reHeapUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (heap[index] > heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

public:

    // Insert into heap
    void insert(int item) {
        heap.push_back(item);      // Insert at end
        reHeapUp(heap.size() - 1); // Fix upward
        showHeap();
    }

    // Pushes down to restore heap after removal
    void reHeapDown(int i) {
        int size = heap.size();

        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < size && heap[left] > heap[largest])
                largest = left;
            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest == i) break;

            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

    // Remove max element (root)
    int removeMax() {
        if (heap.empty()) {
            cout << "Heap is empty\n";
            return -1;
        }

        int maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            reHeapDown(0);

        showHeap();
        return maxValue;
    }

    // Print the heap array
    void showHeap() {
        cout << "Heap: ";
        for (int x : heap) cout << x << " ";
        cout << "\n";
    }

    // Print each node with its children (index view)
    void printTree() {
        cout << "\nTree structure:\n";
        for (int i = 0; i < heap.size(); i++) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            cout << "Node[" << i << "]=" << heap[i];

            if (left < heap.size())
                cout << "  Left[" << left << "]=" << heap[left];
            else
                cout << "  Left: NULL";

            if (right < heap.size())
                cout << "  Right[" << right << "]=" << heap[right];
            else
                cout << "  Right: NULL";

            cout << "\n";
        }
        cout << "\n";
    }
};

// ------------------ MAIN ------------------

int main() {
    MaxHeap H;

    // Insert some numbers
    int arr[] = {40, 20, 60, 10, 50, 70};
    for (int v : arr) {
        cout << "\nInsert: " << v << "\n";
        H.insert(v);
    }

    cout << "\n==== Remove max 3 times ====\n";
    for (int i = 0; i < 3; i++) {
        cout << "\nRemove max:\n";
        H.removeMax();
    }

    cout << "\nFinal Tree Structure:\n";
    H.printTree();

    return 0;
}
