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

// (Bagian #include dan fungsi dfs() sama kayak di atas)

int main() {
    int V, E;
    // Baca jumlah vertex (orang) dan edge (hubungan)
    cout << "Jumlah vertex dan edge: ";
    cin >> V >> E;

    // Resize adjacency list & infection_day array
    adj.resize(V);
    infection_day.assign(V, -1); // Inisialisasi semua -1 (belum kena)

    // --- INI BAGIAN YANG DIUBAH ---
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
    // --- SAMPAI SINI ---

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
