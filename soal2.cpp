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
