#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int V, E;
    cout << "Jumlah vertex dan edge: ";
    cin >> V >> E;

    vector<vector<int>> graph(V);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // graf tidak berarah
    }

    int S, K;
    cout << "Node Awal dan Hari Terinfeksi: ";
    cin >> S >> K;

    vector<bool> visited(V, false);
    queue<pair<int, int>> q;
    visited[S] = true;
    q.push(make_pair(S, 0));

    vector<int> terinfeksiPadaHariK;

    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();

        int node = front.first;
        int day = front.second;

        if (day == K) {
            terinfeksiPadaHariK.push_back(node);
            continue;
        }

        for (int i = 0; i < graph[node].size(); i++) {
            int tetangga = graph[node][i];
            if (!visited[tetangga]) {
                visited[tetangga] = true;
                q.push(make_pair(tetangga, day + 1));
            }
        }
    }

    cout << "Node terinfeksi: ";
    if (terinfeksiPadaHariK.empty()) {
        cout << "(TIDAK ADA)" << endl;
    } else {
        sort(terinfeksiPadaHariK.begin(), terinfeksiPadaHariK.end());
        for (int i = 0; i < terinfeksiPadaHariK.size(); i++) {
            if (i > 0) cout << " ";
            cout << terinfeksiPadaHariK[i];
        }
        cout << endl;
    }

    return 0;
}


/*
Penjelasan Algoritma/Logika Penyelesaian:

1. Struktur Data yang Digunakan:
   - Vector<vector<int>> graph: Representasi graf menggunakan adjacency list
   - Vector<bool> visited: Menandai node yang sudah terinfeksi
   - Queue<pair<int,int>>: Menyimpan (node, hari) untuk BFS
   - Vector<int> infectedAtK: Menyimpan node yang terinfeksi tepat di hari ke-K

2. Algoritma Utama: BFS (Breadth-First Search) dengan modifikasi
   - BFS dipilih karena virus menyebar ke semua tetangga dalam waktu yang sama
   - Setiap level BFS merepresentasikan 1 hari penyebaran
   - Queue menyimpan pasangan (node, hari) untuk melacak kapan setiap node terinfeksi

3. Langkah-langkah Detail:
   a) Input dan Inisialisasi:
      - Baca jumlah vertex (V) dan edge (E)
      - Buat graf tidak berarah dengan adjacency list
      - Baca node awal (S) dan target hari (K)
   
   b) Proses BFS:
      - Mulai dari node S dengan hari = 0
      - Untuk setiap node yang diproses:
        * Jika hari == K: tambahkan ke infectedAtK
        * Jika hari < K: infeksi semua tetangga yang belum terinfeksi
        * Tetangga yang baru terinfeksi masuk queue dengan hari + 1
   
   c) Output:
      - Sort infectedAtK untuk output terurut
      - Jika kosong, print "(TIDAK ADA)"
      - Jika ada, print semua node terpisah spasi

4. Kompleksitas:
   - Waktu: O(V + E) untuk BFS + O(K) untuk level + O(V log V) untuk sorting
   - Ruang: O(V) untuk visited & queue + O(V) untuk adjacency list

5. Kebenaran:
   - BFS menjamin menemukan semua node dengan jarak K dari S
   - Setiap level BFS = 1 hari penyebaran
   - Visited array mencegah node terinfeksi lebih dari sekali
*/
