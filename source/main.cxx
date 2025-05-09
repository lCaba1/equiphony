#include "../include/main.hxx"

using namespace std;

int main() {
    char str1[] = "тест";
    char str2[] = "тсет";

    for (auto i : convert(str1)) cout << i << ' ';
    cout << '\n';
    for (auto i : convert(str2)) cout << i << ' ';
    cout << '\n';

    vector<vector<int>> dist = levenshteinDist(convert(str1), convert(str2));
    
    for (int i = 0; i < dist.size(); ++i) {
        for (int j = 0; j < dist[i].size(); ++j) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    
    // "áa҄";

    return 0;
}
