#include <iostream>
using namespace std;
 
bool check_set(int num,int k)
{
    int n = (num >> (k-1)) & 1;

    if(n == 1)  return true;
    else        return false;
}

int set_bit(int num,int k)
{
    int n = 1;
    n = n << (k-1);

    return (num | n);
}

int clear_bit(int num,int k)
{
    int n = 1;
    n = ~( n << (k-1) );

    return (num & n);
}

int cnt_set(int num)
{
    int cnt = 0;

    while(num > 0)
    {
        num = num & (num - 1);
        cnt++;
    }

    return cnt;
}


int main()
{
    int n,k;
    cout<<"Enter the number and kth bit : "<<endl;
    cin>>n>>k;

    cout<<"Checking kth set bit : "<<check_set(n,k)<<endl;
    cout<<"Clear kth set bit : "<<clear_bit(n,k)<<endl;
    cout<<"Set kth set bit : "<<set_bit(n,k)<<endl;
    cout<<"Count set bit : "<<cnt_set(n)<<endl;

    return 0;
}