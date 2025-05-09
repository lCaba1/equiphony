#include "../include/apophony.hxx"
#include "../include/letters.hxx"
#include <algorithm>

using namespace std;

// Мена в рамках одного фонемотипа ( г↔к↔х, в↔ф, ж↔ч↔ш↔щ, д↔т, з↔с, п↔б ) = - 0,5
bool definePhonemotype(uint l, uint r)
{
    if (min(l, r) != l) swap(l, r);

    if (l == LET_G && (r == LET_K || r == LET_H) || 
        l == LET_K && r == LET_H ||
        l == LET_V && r == LET_F ||
        l == LET_ZH && (r == LET_CH || r == LET_SH || r == LET_SHA) ||
        l == LET_CH && (r == LET_SH || r == LET_SHA) ||
        l == LET_SH && r == LET_SHA ||
        l == LET_D && r == LET_T ||
        l == LET_Z && r == LET_S ||
        l == LET_B && r == LET_P)
    {
        return true;
    }

    return false;
}

//Мена сонорных ( м↔н )/плавных ( р ↔ л )/губных ( б ↔ в, п↔ф ) = -1
bool defineSonorous(uint l, uint r)
{
    if (min(l, r) != l) swap(l, r);

    if (l == LET_M && r == LET_N || 
        l == LET_L && r == LET_R ||
        l == LET_B && r == LET_V ||
        l == LET_P && r == LET_F) 
    {
        return true;
    }

    return false;
}

// Мена по твердости/мягкости ( в↔в’, т↔т’, ш ↔ щ и т.п.) = -1,5
/*bool defineHardness(char16_t l, char16_t r, bool soft_change)
{
    if (soft_change) return true;

    return false;
}*/

// Мена смычных ( б/п↔д/т )/смычно-щелевых( ц↔ч ) = -2
bool defineOcclusive(uint l, uint r)
{
    if (min(l, r) != l) swap(l, r);

    if (l == LET_B && (r == LET_D || r == LET_T) || 
        l == LET_P && r == LET_T ||
        l == LET_D && r == LET_P ||
        l == LET_TS && r == LET_CH) 
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
bool defineGroup(uint a, uint b)
{
    return false;
}

// Мена мягкого на йоту = -2,5
bool defineSoftIota(uint a, uint b)
{
    return false;
}

//Мена твердого на йоту = -3,5
bool defineHardIota(uint a, uint b)
{
    return false;
}

//
double defineCost(uint l, uint r)
{
    double cost = 0;

    if (l == r)
        cost = 0;
    else if (definePhonemotype(l, r))
        cost += 0.5;
    else if (defineSonorous(l, r))
        cost += 1;
    /*else if (defineHardness(l, r, soft_change))
        cost += 1.5;*/
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