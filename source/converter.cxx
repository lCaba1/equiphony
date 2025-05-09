#include "../include/converter.hxx"

std::vector<uint> convert(char* str)
{
    std::vector <uint> res;
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