#include "npc.h"
#define dis 25
int Npc::ifnpcclose(int _x,int _y)
{
    if(((_x-760)*(_x-760)+(_y-450)*(_y-450))<=dis)//商人
    return 1;
    if(((_x-30)*(_x-30)+(_y-450)*(_y-450))<=dis)//智慧长老
    return 2;
    if(((_x-760)*(_x-760)+(_y-530)*(_y-530))<=dis)//幸运长老
    return 3;
    if(((_x-30)*(_x-30)+(_y-530)*(_y-530))<=dis)//武力长老
    return 4;
    if(((_x-770)*(_x-770)+(_y-500)*(_y-500))<=dis)//tunnel
    return 5;
    if(((_x-50)*(_x-50)+(_y-200)*(_y-200))<=dis)//tunnel
    return 6;
    if(((_x-770)*(_x-770)+(_y-200)*(_y-200))<=dis)//tunnel
    return 7;
    if(((_x-900)*(_x-900)+(_y-200)*(_y-200))<=dis)//tunnel
    return 8;
    if(((_x-200)*(_x-200)+(_y-200)*(_y-200))<=dis)//tunnel
    return 9;
}
