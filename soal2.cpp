#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    queue<string> AntrianNormal;  
    queue<string> AntrianDarurat;

    for (int i = 0; i < N; i++) {
        string command, name;
        cin >> command;

        if (command == "DATANG") {
            cin >> name;
            AntrianNormal.push(name);
        } 
        else if (command == "DARURAT") {
            cin >> name;
            AntrianDarurat.push(name);
        } 
        else if (command == "LAYANI") {
            if (!AntrianDarurat.empty()) {
                cout << AntrianDarurat.front() << endl;
                AntrianDarurat.pop();
            } 
            else if (!AntrianNormal.empty()) {
                cout << AntrianNormal.front() << endl;
                AntrianNormal.pop();
            } 
            else {
                cout << "(TIDAK ADA PASIEN)" << endl;
            }
        }
    }
    return 0;
}


/* 
Penjelasan algoritma/logika penyelesaian soal 2:

1. Programnya dimulai dengan membuat dua antrian (queue), yaitu antrian normal untuk pasien biasa 
   dan antrian darurat untuk pasien prioritas.

2. Program membaca setiap perintah dari input menggunakan perulangan while 
   hingga tidak ada lagi perintah yang dimasukkan.

3. Jika perintah “DATANG <nama>”, maka nama pasien dimasukkan ke antrian normal.

4. Jika perintah “DARURAT <nama>”, maka nama pasien dimasukkan ke antrian darurat.

5. Jika perintah “LAYANI”, maka program memeriksa antrian darurat terlebih dahulu. 
   Jika tidak kosong, pasien darurat dilayani dan dihapus dari antrian. 
   Jika kosong, pasien pertama di antrian normal yang dilayani.

6. Jika kedua antrian kosong saat perintah “LAYANI” diberikan, maka ditampilkan pesan 
   “(TIDAK ADA PASIEN)”.

7. Program menggunakan konsep FIFO (First In First Out) agar urutan pelayanan sesuai 
   dengan waktu kedatangan pasien.
*/
