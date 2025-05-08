#include "../include/levenshtein.hxx"
#include "../include/apophony.hxx"

using namespace std;

vector<vector<double>> levenshteinDist(u16string lword, u16string rword) {
    int lwsize = lword.size();
    int rwsize = rword.size();
    vector<vector<double>> result(lwsize + 1, vector<double>(rwsize + 1));
    for (int i = 1; i <= lwsize; ++i) result[i][0] = result[i - 1][0] + 1;
    for (int j = 1; j <= rwsize; ++j) result[0][j] = result[0][j - 1] + 1;
    for (int i = 1; i <= lwsize; ++i) {
        for (int j = 1; j <= rwsize; ++j) {
            result[i][j] = min(result[i - 1][j - 1], min(result[i - 1][j], result[i][j - 1])) 
            + defineCost(lword[i - 1], rword[j - 1], 0);


        }
    }
    return result;
}

