#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int gen_rand()
{
    return rand();
    }

int main()
{
    srand(time(NULL));
    for(int i=0;i<10;i++)
        printf("%d\n",gen_rand());
    }
