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
