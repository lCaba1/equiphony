#include "../include/main.hxx"
#include <cstdio>
#include <cstdlib>

using namespace std;

vector<uint> convert(char* str);

int main() {
    //cout << fixed << setprecision(1);
    //wstring_convert<codecvt_utf8_utf16<char16_t>, char16_t> utf16conv;
    //u16string lword = u"ш\u0301";
    //u16string rword = utf16conv.from_bytes("щ");

    // u16string lword = u"тест";
    // u16string rword = u"тест";

    // vector<vector<double>> dist = levenshteinDist(lword, rword);
    // for (int i = 0; i <= lword.size(); ++i) {
    //     for (int j = 0; j <= rword.size(); ++j) {
    //         cout << dist[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    //printf("%sq", lword.c_str()) ;
    //cout << '\n';

    // system("chcp 65000");
    char tmp[80] = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяáa҄";
    // cin.getline(tmp, 80);
    auto a = convert(tmp);

    for (auto b : a){
        cout << b << " ";
    }
    return 0;
}

// u'\u0484' - мягкость
// u'\u0301' - ударение
#define UNI_ACCENT = 52353;
#define UNI_OVER = 53892;
#define LET_A = 53424;
#define LET_B = 53425;
#define LET_V = 53426;
#define LET_G = 53427;
#define LET_D = 53428;
#define LET_YE = 53429;
#define LET_YO = 53649;
#define LET_ZH = 53430;
#define LET_Z = 53431;
#define LET_I = 53432;
#define LET_J = 53433;
#define LET_K = 53434;
#define LET_L = 53435;
#define LET_M = 53436;
#define LET_N = 53437;
#define LET_O = 53438;
#define LET_P = 53439;
#define LET_R = 53632;
#define LET_S = 53633;
#define LET_T = 53634;
#define LET_U = 53635;
#define LET_F = 53636;
#define LET_H = 53637;
#define LET_TS = 53638;
#define LET_CH = 53639;
#define LET_SH = 53640;
#define LET_SHA = 53641;
#define LET_TVERD = 53642;
#define LET_II = 53643;
#define LET_MYAGKIY = 53644;
#define LET_E = 53645;
#define LET_YU = 53646;
#define LET_YA = 53647;

vector<uint> convert(char* str)
{
    vector <uint> res;
    char * ch = str;
    char * tmp = new char[4];
    uint * data = (uint*) tmp;

    while( *ch != 0 ){
        int i = -1;
        while (*ch & (0x80 >> ++i));
        if (i == 0){
            res.push_back(*ch);
            i += 1;
        }
        else if ( i <= 4) {
            *data = 0;
            for (int j = 0; j < i; ++j){
                tmp[i - j - 1] = *(ch + j);
            }
            res.push_back(*data);
        }
        ch += i;
    }

    delete[] tmp;

    return res;
}