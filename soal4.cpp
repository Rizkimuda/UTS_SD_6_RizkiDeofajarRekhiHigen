//Masukkan jawaban disini
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Adjacency list buat simpen graf
vector<vector<int>> adj;
// Array buat nyimpen hari infeksi
// -1 artinya belum terinfeksi
vector<int> infection_day;
// K global buat diakses di DFS
int K_global;

/**
 * Fungsi DFS (Depth-First Search) buat simulasi virus.
 * * @param u Node (orang) saat ini.
 * @param day Hari ke-berapa node ini di-visit.
 */
void dfs(int u, int day) {
    // 1. Optimasi: Kalo hari udah ngelewatin K, stop aja.
    if (day > K_global) {
        return;
    }

    // 2. Cek apakah node ini udah pernah di-visit di hari yang
    //    lebih cepet atau sama. Kalo iya, stop path ini.
    //    Ini penting biar kita dapet "hari" terpendek, mirip sifat BFS.
    if (infection_day[u] != -1 && infection_day[u] <= day) {
        return;
    }

    // 3. Catat hari infeksi node ini
    infection_day[u] = day;

    // 4. Kalo udah pas hari-K, kita gak perlu nyebarin ke tetangganya lagi,
    //    karena tetangganya baru kena di K+1. Stop di sini.
    if (day == K_global) {
        return;
    }

    // 5. Langkah rekursif: kunjungi semua tetangga
    for (int v : adj[u]) {
        dfs(v, day + 1);
    }
}


int main() {
    int V, E;
    // Baca jumlah vertex (orang) dan edge (hubungan)
    cout << "Jumlah vertex dan edge: ";
    cin >> V >> E;

    // Resize adjacency list & infection_day array
    adj.resize(V);
    infection_day.assign(V, -1); // Inisialisasi semua -1 (belum kena)

    
    cout << "Masukkan " << E << " edge (format: u v):" << endl;
    // Baca semua edge
    for (int i = 0; i < E; ++i) {
        int u, v;
        cout << "Edge " << i + 1 << ": "; // Ditambahin prompt di sini
        cin >> u >> v;
        // Graf tak berarah
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int S, K;
    // Baca node awal (S) dan hari ke-K
    cout << "Node Awal dan Hari Terinfeksi: ";
    cin >> S >> K;
    K_global = K;

    // Mulai simulasi DFS dari node S di hari 0
    dfs(S, 0);

    vector<int> results;
    // Kumpulin semua node yang terinfeksi TEPAT di hari ke-K
    for (int i = 0; i < V; ++i) {
        if (infection_day[i] == K) {
            results.push_back(i);
        }
    }

    cout << "Node terinfeksi: ";
    if (results.empty()) {
        // Cetak (TIDAK ADA) kalo gak ada
        cout << "(TIDAK ADA)" << endl;
    } else {
        // Soal 3 (induk soal ini) minta diurutkan menaik
        sort(results.begin(), results.end());
        for (int i = 0; i < results.size(); ++i) {
            cout << results[i] << (i == results.size() - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}


/*
   --- PENJELASAN ALGORITMA (SOAL 4) ---
 
   1.  Tujuan: Menemukan semua node yang terinfeksi TEPAT pada hari ke-K menggunakan DFS.
 
   2.  Struktur Data:
   - adj (vector<vector<int>>): Menggunakan adjacency list untuk representasi graf,
   karena efisien untuk traversal.
   - infection_day (vector<int>): Array ini krusial. Fungsinya mirip array visited
   tapi lebih canggih. infection_day[i] menyimpan HARI (level/jarak)
   terpendek dari node Awal (S) ke node i. Diinisialisasi -1.
  
   3.  Logika DFS dfs(int u, int day):
   - Fungsi ini melacak day (level) saat ini.
   - Cek Pruning 1: if (day > K) -> Jika hari sudah lewat K, tidak perlu
   dicari lebih dalam. Stop.
   - Cek Pruning 2: if (infection_day[u] != -1 && infection_day[u] <= day) ->
   Ini adalah kunci agar DFS bisa meniru sifat BFS (mencari level). Jika kita
   sampai di node u pada day ke-5, tapi sebelumnya sudah pernah sampai
   di node u pada day ke-3, maka path ini tidak optimal dan di-stop.
   - Pencatatan: infection_day[u] = day; -> Catat hari terinfeksi terpendek
   untuk node u yang ditemukan sejauh ini.
   - Cek Target: if (day == K) -> Jika sudah pas di hari K, kita return.
   Kita tidak lanjut ke tetangganya, karena tetangganya akan terinfeksi
   pada hari K+1, bukan K.
   - Rekursif: Jika day < K, panggil dfs untuk semua tetangga v dari u
   dengan day + 1.
  
   4.  Fungsi Main:
   - Baca input V, E, S, dan K[cite: 25, 26, 27].
   - Panggil dfs(S, 0) untuk memulai simulasi.
   - Setelah DFS selesai, infection_day akan berisi hari infeksi tercepat
   untuk semua node yang terjangkau.
   - Loop dari i = 0 sampai V-1. Jika infection_day[i] == K, masukkan i
   ke vector results.
   - Cetak results (setelah di-sort menaik [cite: 23]) atau "(TIDAK ADA)"[cite: 24].
 */
