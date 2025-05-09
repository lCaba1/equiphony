#include "../include/main.hxx"

using namespace std;

int main() {
    char str1[100], str2[100];
    cin >> str1 >> str2;

    cout << "\nСтрока 1: " << str1 << "\n\n"; 
    for (auto i : convert(str1)) cout << i << ' ';
    cout << "\n\n";
    cout << "Строка 2: " << str2 << "\n\n"; 
    for (auto i : convert(str2)) cout << i << ' ';
    cout << "\n\n";

    vector<vector<int>> dist1 = levenshteinDist(convert(str1), convert(str2));
    for (int i = 0; i < dist1.size(); ++i) {
        for (int j = 0; j < dist1[i].size(); ++j) {
            cout << dist1[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << '\n';
    
    vector<vector<double>> dist2 = levenshteinDistWeighted(convert(str1), convert(str2));
    for (int i = 0; i < dist2.size(); ++i) {
        for (int j = 0; j < dist2[i].size(); ++j) {
            cout << dist2[i][j] << ' ';
        }
        cout << '\n';
    }    

    return 0;
}

// "áa҄";
