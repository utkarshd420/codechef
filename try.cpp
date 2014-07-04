#include <cstdio>
#include <string>
using namespace std;
int ncr(int n,int r)
{
        long int num_res =1;long int denum_res =1;
            if(r > (n-r))
                    {
                                for(int i=n;i>r;i--)
                                                num_res = num_res*i;
                                                        for(int i=1;i<=n-r;i++)
                                                                        denum_res = denum_res*i;
                                                                            }
                                                                                else
                                                                                        {
                                                                                                    for(int i=n;i>n-r;i--)
                                                                                                                    num_res = num_res*i;
                                                                                                                            for(int i=1;i<=r;i++)
                                                                                                                                            denum_res = denum_res*i;
                                                                                                                                                }   
                                                                                                                                                    return num_res/denum_res;
}

int main()
{
    int n,r;
    scanf("%d",&n);
    scanf("%d",&r);
   printf("%d\n", ncr(n,r));
}
