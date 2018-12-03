#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    int n, i, j, k;
    int t[20];

    cin >> i;
    cin >> j;

    k = 0;
    n = 20;

    do {
        t[k] = k;
        k = k + 1;
        if (k % 2 == 0) {
            continue;
        }
        cout << "asdf" << endl;
        cout << t[k - 1] << endl;
    } while(k < n);

    if (i < j && j < n && i >= 0) {
        t[i] = i * 2;
        t[j] = j * 2;
        k = t[i];
        t[i] = t[j];
        t[j] = k;
    } else {
        while (i >= j || false) {
            k = (1 + i -j) % 3;
            i = i - 1;
            if (k > 1) {
                continue;
            }
            cout << k << endl;
        }
    }

    cout << i << endl;
    cout << j << endl;
    cout << k << endl;
    
    if (i < n && i >= 0) cout << t[i] << endl;

    if (j < n && j >= 0) cout << t[j] << endl;

    return 0;
}