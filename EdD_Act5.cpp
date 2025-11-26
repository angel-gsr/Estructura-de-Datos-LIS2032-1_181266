#include <iostream>
#include <vector>
using namespace std;

// ---------------- BUBBLE SORT TRACE ----------------
void bubbleTrace(vector<int> a) {
    int n = a.size();
    for (int pass = 0; pass < n - 1; pass++) {
        cout << "Pass " << pass + 1 << ": ";
        for (int i = 0; i < n - pass - 1; i++) {
            if (a[i] > a[i+1]) {
                swap(a[i], a[i+1]);
                cout << "swap ";
            }
        }
        for (int x : a) cout << x << " ";
        cout << "\n";
    }
}

// ---------------- MERGE SORT (trace only) ----------
void mergeTrace(vector<int> &a, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeTrace(a, l, m);
    mergeTrace(a, m+1, r);

    vector<int> temp;
    int i = l, j = m+1;
    while (i <= m && j <= r) {
        if (a[i] < a[j]) temp.push_back(a[i++]);
        else temp.push_back(a[j++]);
    }
    while (i <= m) temp.push_back(a[i++]);
    while (j <= r) temp.push_back(a[j++]);

    for (int k = 0; k < temp.size(); k++)
        a[l + k] = temp[k];

    cout << "Merged: ";
    for (int x : temp) cout << x << " ";
    cout << "\n";
}

// ---------------- QUICKSORT PARTITION TRACE --------
int partitionTrace(vector<int>& a, int low, int high) {
    int pivot = a[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[high]);

    cout << "After partition around " << pivot << ": ";
    for (int x : a) cout << x << " ";
    cout << "\n";

    return i;
}

int main() {
    bubbleTrace({2,6,5,1,4});
    cout << "\n";

    vector<int> m = {8,3,7,2,9};
    mergeTrace(m, 0, m.size()-1);
    cout << "\n";

    vector<int> q = {10,4,6,2,9,5};
    partitionTrace(q, 0, q.size()-1);

    return 0;
}
