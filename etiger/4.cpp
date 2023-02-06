#include <iostream>
using namespace std;

bool nodup(bool cur_used[], int n2, int n3)
{
    bool used2[10];
    
    for (int i = 1; i <= 9; i++)
    {
        used2[i] = cur_used[i];
    }
    
    if (used2[n2 / 100])
    {
        return false;
    }
    used2[n2 / 100] = true;
    if (used2[(n2 % 100) / 10])
    {
        return false;
    }
    used2[(n2 % 100) / 10] = true;
    if (used2[n2 % 10])
    {
        return false;
    }
    used2[n2 % 10] = true;
    
    if (used2[n3 / 100])
    {
        return false;
    }
    used2[n3 / 100] = true;
    if (used2[(n3 % 100) / 10])
    {
        return false;
    }
    used2[(n3 % 100) / 10] = true;
    if (used2[n3 % 10])
    {
        return false;
    }
    
    return true;
}

bool used[10];
int num[3];

void search(int nnum)
{
    if (nnum == 3)
    {
        int n = num[0] * 100 + num[1] * 10 + num[2];
        int n2 = n * 2;
        int n3 = n * 3;
        
        if (n3 < 1000 && nodup(used, n2, n3))
        {
            cout << n << " " << n2 << " " << n3 << endl;
        }
    }
    else
    {
        for (int i = 1; i <= 9; i++)
        {
            if (!used[i])
            {
                used[i] = true;
                num[nnum] = i;
                search(nnum + 1);
                used[i] = false;
            }
        }
    }
}

int main()
{
    search(0);
    return 0;
}

