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

1. Inisialisasi Antrian
   Program memulai dengan membuat dua buah antrian (queue) yaitu antrian normal dan antrian darurat. 
   Antrian normal digunakan untuk menampung pasien biasa, sedangkan antrian darurat digunakan untuk menampung pasien prioritas darurat.

2. Pembacaan Perintah
   Program membaca perintah dari pengguna menggunakan perulangan while, yang akan terus berjalan 
   selama masih ada input. Setiap perintah bisa berupa “DATANG”, “DARURAT”, atau “LAYANI”.

3. Menambahkan Pasien Normal
   Jika perintah yang dibaca adalah “DATANG <nama_pasien>”, maka nama pasien tersebut 
   dimasukkan ke dalam antrian normal dengan perintah push() pada queue normal.

4. Menambahkan Pasien Darurat
   Jika perintah yang dibaca adalah “DARURAT <nama_pasien>”, maka nama pasien tersebut 
   dimasukkan ke dalam antrian darurat dengan perintah push() pada queue darurat.

5. Melayani Pasien
   Jika perintah yang dibaca adalah “LAYANI”, maka program akan memeriksa antrian darurat terlebih dahulu.
   Apabila antrian darurat tidak kosong, maka pasien yang berada di depan antrian darurat akan dilayani 
   dan dikeluarkan dari antrian menggunakan perintah pop(). Jika antrian darurat kosong, maka pasien 
   pertama dari antrian normal yang akan dilayani.

6. Kondisi Antrian Kosong
   Jika perintah “LAYANI” diberikan tetapi kedua antrian kosong, maka program akan menampilkan pesan 
   “(TIDAK ADA PASIEN)” sebagai tanda bahwa tidak ada pasien yang menunggu di sistem.

7. Prinsip FIFO
   Struktur data queue digunakan karena memiliki prinsip FIFO (First In First Out), di mana pasien yang 
   datang lebih dahulu akan dilayani lebih dahulu sesuai urutan kedatangannya.

8. Penghentian Program
   Program akan terus berjalan sampai tidak ada lagi perintah yang dimasukkan oleh pengguna 
   atau input berakhir (EOF). Setelah itu, program selesai dijalankan.

*/
