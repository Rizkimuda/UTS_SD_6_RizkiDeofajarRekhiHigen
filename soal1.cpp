#include <iostream>
#include <vector>
using namespace std;

vector<int> rotasiKiri(int d, vector<int> arr) {
    int n = arr.size();
    d = d % n;
    
    vector<int> hasil(n);

    for (int i = 0; i < n; i++) {
        int posisiBaru = (i + n - d) % n;
        hasil[posisiBaru] = arr[i];
    }

    return hasil;
}

int main() {
    int n, d;

    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Masukkan elemen array: ";
    for (int i = 0; i < n; i++){ 
        cin >> arr[i]; 
    }

    cout << "Masukkan jumlah rotasi: ";
    cin >> d;

    vector<int> hasil = rotasiKiri(d, arr);

    cout << "Hasil rotasi: ";
    for (int x : hasil) cout << x << " ";

    return 0;
}
