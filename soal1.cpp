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

/* Penjelasan algoritma/logika penyelesaian soal 1:
1.  Mendapatkan Ukuran Array (n) dan Jumlah Rotasi (d)
    Langkah pertama adalah mendapatkan jumlah elemen dalam array, yang disimpan dalam variabel ndan jumlah rotasi, yang disimpan dalam variabel d.

2.  Optimasi Jumlah Rotasi
    Langkah ini bertujuan untuk mendapatkan jumlah rotasi yang terbaik dengan memakai rumus rotasi_efektif = d % n.

    Contoh: Jika n=5 dan d=7, 7 % 5 = 2. Jadi, 7 rotasi sama dengan 2 rotasi.

3.  Membuat Array Hasil
    Kita membuat sebuah vector baru bernama hasil untuk menyimpan elemen-elemen yang sudah dirotasi.

4.  Menyalin Bagian Belakang
    Rotasi kiri sebanyak d berarti memindahkan elemen-elemen dari indeks d hingga n-1 ke bagian depan array baru.Kita menggunakan for loop untuk menyalin elemen-elemen arr[d] sampai arr[n-1] ke dalam hasil_rotasi.

5.  Menyalin Bagian Depan
    Selanjutnya, elemen-elemen dari indeks 0 hingga d - 1 harus dipindahkan ke bagian belakang array baru. Kita menggunakan for loop kedua untuk menyalin elemen-elemen arr[0] sampai arr[d-1] ke akhir hasil_rotasi.

6.  Mengembalikan Hasil
    Fungsi mengembalikan hasil_rotasi yang kini berisi semua elemen dari arr dalam urutan yang sudah dirotasi.
*/
