//Masukkan jawaban disini
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // Dipake buat swap di bubble sort

using namespace std;

// Adjacency list buat simpen graf
vector<vector<int>> adj;
// Array visited buat nandain node
vector<bool> visited;

/**
 * Fungsi Bubble Sort[cite: 34].
 * Mengurutkan vector secara menaik.
 * * @param arr Vector yang mau di-sort.
 */
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        // Loop j cuma sampe n - 1 - i
        // karena elemen terakhir (i) udah di posisi yg bener
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // Kalo dalem satu iterasi gak ada yg di-swap,
        // berarti udah urut. Langsung break.
        if (!swapped) {
            break;
        }
    }
}

/**
 * Fungsi BFS (Breadth-First Search)[cite: 33].
 * Mencari semua node yang terjangkau dari startNode.
 * * @param startNode Node awal.
 * @return Vector berisi ID teman-teman yg terjangkau (TIDAK termasuk startNode).
 */
vector<int> bfs(int startNode) {
    vector<int> results;      // Buat nampung hasil [cite: 34]
    queue<int> q;             // Queue buat BFS

    // Mulai BFS
    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Cek semua tetangga v dari u
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;  // Tandain visited
                q.push(v);          // Masukin ke queue
                results.push_back(v); // Masukin ke hasil
            }
        }
    }
    return results;
}

int main() {
    int V, E;
    // Baca jumlah vertex (teman) dan edge [cite: 35]
    cout << "Masukkan jumlah teman dan edge: ";
    cin >> V >> E;

    // Resize adj list & visited array
    adj.resize(V);
    visited.assign(V, false);

    // Baca semua edge [cite: 38]
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        // Graf tak berarah
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    // Baca titik start [cite: 39]
    cout << "Masukkan titik start: ";
    cin >> start;

    // 1. Lakukan BFS
    vector<int> teman = bfs(start);

    // 2. Urutkan hasilnya pake Bubble Sort [cite: 34]
    bubbleSort(teman);

    // 3. Cetak hasil [cite: 35]
    for (int i = 0; i < teman.size(); ++i) {
        cout << teman[i] << (i == teman.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}


/*
   --- PENJELASAN ALGORITMA (SOAL 5) ---
  
   1.  Tujuan: Menemukan semua teman (node yang terjangkau) dari start,
   lalu diurut daftarnya menggunakan Bubble Sort  dan dicetak .
  
   2.  Struktur Data:
   - adj (vector<vector<int>>): Adjacency list untuk representasi graf pertemanan.
   - visited (vector<bool>): Array boolean untuk menandai node yang sudah
   dikunjungi selama BFS, agar tidak terjadi loop tak terbatas.
   - q (queue<int>): Queue standar untuk implementasi BFS.
   - results (vector<int>): Vector untuk menyimpan hasil penelusuran (ID teman).
  
   3.  Logika BFS bfs(int startNode):
   - Fungsi ini menerima ID pengguna awal (startNode).
   - Masukkan startNode ke q dan tandai visited[startNode] = true.
   - Lakukan loop while (!q.empty()):
   - Ambil (dequeue) node u dari q.
   - Cek semua tetangga v dari u.
   - Jika v belum di-visit (!visited[v]):
   - Tandai visited[v] = true.
   - Masukkan v ke q (enqueue) untuk dikunjungi nanti.
   - Masukkan v ke vector results. (Sesuai test case, startNode
   sendiri tidak masuk ke daftar output).
   - Setelah loop selesai, kembalikan results.
  
   4.  Logika bubbleSort(vector<int>& arr):
   - Ini adalah implementasi standar Bubble Sort.
   - Menggunakan dua loop for bersarang.
   - Loop luar i berjalan dari 0 sampai n-2.
   - Loop dalam j berjalan dari 0 sampai n-i-2.
   - Di dalam loop j, bandingkan arr[j] dan arr[j+1]. Jika arr[j] > arr[j+1],
   maka tukar (swap) posisi keduanya.
   - Terdapat optimasi swapped flag. Jika dalam satu iterasi loop i
   penuh tidak ada satupun swap yang terjadi, artinya array sudah
   terurut dan algoritma bisa berhenti lebih awal.
 
   5.  Fungsi Main:
   - Baca input V, E, dan start[cite: 35, 38, 39].
   - Bangun adjacency list.
   - Panggil bfs(start) dan simpan hasilnya di vector<int> teman.
   - Panggil bubbleSort(teman) untuk mengurutkan vector tersebut.
   - Cetak isi vector teman yang sudah terurut.
 */
