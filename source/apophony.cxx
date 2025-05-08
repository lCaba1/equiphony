#include "../include/apophony.hxx"
#include "../include/letters.hxx"
#include <algorithm>

using namespace std;

// Мена в рамках одного фонемотипа ( г↔к↔х, в↔ф, ж↔ч↔ш↔щ, д↔т, з↔с, п↔б ) = - 0,5
bool definePhonemotype(char16_t l, char16_t r)
{
    if (min(l, r) != l) swap(l, r);

    if (l == RU_LETTER_G && (r == RU_LETTER_K || r == RU_LETTER_KH) || 
        l == RU_LETTER_K && r == RU_LETTER_KH ||
        l == RU_LETTER_V && r == RU_LETTER_F ||
        l == RU_LETTER_ZH && (r == RU_LETTER_CH || r == RU_LETTER_SH || r == RU_LETTER_SHCH) ||
        l == RU_LETTER_CH && (r == RU_LETTER_SH || r == RU_LETTER_SHCH) ||
        l == RU_LETTER_SH && r == RU_LETTER_SHCH ||
        l == RU_LETTER_D && r == RU_LETTER_T ||
        l == RU_LETTER_Z && r == RU_LETTER_S ||
        l == RU_LETTER_B && r == RU_LETTER_P)
    {
        return true;
    }

    return false;
}

//Мена сонорных ( м↔н )/плавных ( р ↔ л )/губных ( б ↔ в, п↔ф ) = -1
bool defineSonorous(char16_t l, char16_t r)
{
    if (min(l, r) != l) swap(l, r);

    if (l == RU_LETTER_M && r == RU_LETTER_N || 
        l == RU_LETTER_L && r == RU_LETTER_R ||
        l == RU_LETTER_B && r == RU_LETTER_V ||
        l == RU_LETTER_P && r == RU_LETTER_F) 
    {
        return true;
    }

    return false;
}

// Мена по твердости/мягкости ( в↔в’, т↔т’, ш ↔ щ и т.п.) = -1,5
bool defineHardness(char16_t l, char16_t r, bool soft_change)
{
    if (soft_change) return true;

    return false;
}

// Мена смычных ( б/п↔д/т )/смычно-щелевых( ц↔ч ) = -2
bool defineOcclusive(char16_t l, char16_t r)
{
    if (min(l, r) != l) swap(l, r);

    if (l == RU_LETTER_B && (r == RU_LETTER_D || r == RU_LETTER_T) || 
        l == RU_LETTER_P && r == RU_LETTER_T ||
        l == RU_LETTER_D && r == RU_LETTER_P ||
        l == RU_LETTER_TS && r == RU_LETTER_CH) 
    {
        return true;
    }

    return false;
}

// Мена по глухости/звонкости (б↔т, п↔д) = -2,5
/*bool defineDeafness(char16_t l, char16_t r)
{
    return false;
}*/

// Произвольная мена между группами (сонорные ↔ плавные ↔ шумные и т.д.) = -3
bool defineGroup(char16_t a, char16_t b)
{
    return false;
}

// Мена мягкого на йоту = -2,5
bool defineSoftIota(char16_t a, char16_t b)
{
    return false;
}

//Мена твердого на йоту = -3,5
bool defineHardIota(char16_t a, char16_t b)
{
    return false;
}

//
double defineCost(char16_t l, char16_t r, bool soft_change)
{
    double cost = 0;

    if (l == r)
        cost = 0;
    else if (definePhonemotype(l, r))
        cost += 0.5;
    else if (defineSonorous(l, r))
        cost += 1;
    else if (defineHardness(l, r, soft_change))
        cost += 1.5;
    else if (defineOcclusive(l, r))
        cost += 2;
    /*else if (defineDeafness(l, r))
        cost += 2.5;*/
    /*else if (defineGroup(l, r))
        cost += 3;
    else if (defineSoftIota(l, r))
        cost += 2.5;
    else if (defineHardIota(l, r))
        cost += 3.5;*/
    else
        cost +=10;

    return cost;
}