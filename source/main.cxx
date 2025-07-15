#include "../include/main.hxx"
#include <cstring>
#include <sys/types.h>
#include <vector>

using namespace std;

int main() {
    vector<char*> lines;
    string temp;

    //cout << "\nОжидается ввод строк... (для завершения Ctrl+D)\n\n";

    while (getline(cin, temp)) {
        char* line = new char[temp.length() + 1];
        strcpy(line, temp.c_str());
        lines.push_back(line);
    }

    //cout << "\n\n";

    vector<vector<uint>> codes;
    for (int i = 0; i < lines.size(); ++i) codes.push_back(convert(lines[i]));

    
    //cout << "Преобразование строк:\n\n";
    for (int i = 0; i < codes.size() - 1; ++i) {
        for (int j = i + 1; j < codes.size(); ++j) {
            vector<vector<double>> dist = levenshteinDistWeighted(codes[i], codes[j]);
            cout << i + 1 << "=>" << j + 1<< " cost ";
            /*for (int k = 0; k < dist.size(); ++k) {
                for (int l = 0; l < dist[k].size(); ++l) {
                    cout << dist[k][l] << ' ';
                }
                cout << '\n';
            }*/
            cout << dist[dist.size() - 1][dist[0].size() - 1];
            cout << '\n';
        }
    }

    cout << '\n';

    return 0;
}

// "áa҄";

/*

Афанасий Фет

шепот робкое дыханье
трели соловья
серебро и колыханье
сонного ручья

1-2 86
1-3 86
0-2 92.5
2-3 105.5
0-1 109
0-3 116

*/

/*

Владимир Маяковский

я достаю из широких штанин
дубликатом бесценного груза
читайте завидуйте я гражданин
советского союза

1-3 93
0-3 141
0-2 161
2-3 163
0-1 206.5
1-2 223

*/