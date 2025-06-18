#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long power(long long a, long long b, long long m)
{
    long long f=1;
    a=a%m;
    while(b>0)
    {
        if(b%2==1)
            f = (f*a)%m;
        a=(a*a)%m;
        b=b/2;


    }
    return f;
}

//tim nghich dao cua a trong mod n
long long nghich_dao(long long a, long long n)
{
    for(long long nd=2;nd<n;nd++)
        if((a*nd)%n==1)
            return nd;
    return -1;
}
//ham ktra so nto
bool isPrime(int n)
{
    for(int i=2;i<=sqrt(n);i++)
        if(n%i==0)
            return false;
    return true;
}

//ham kiem tra phan tu sinh
bool check_pts(int g, int p)
{
    set <int > Set;
    for(int i=1;i<p;i++)
        Set.insert(power(g,i,p));
    return Set.size()==p-1;

}

int main()
{
    long long p,g,x,k,m;

    do {
        cout<<"nhap so nguyen to p>2:";
        cin>>p;
    }
    while(!isPrime(p)|| p<=2);

    do
    {
        cout<<"nhap phan tu sinh g trong Z_"<<p<<":";
        cin>>g;
    }
    while(g<=1 ||g>=p || !check_pts(g,p));

    //nhap khoa bi mat
    do
    {
        cout<<"Nhap khoa bi mat (1<x<p-1):";
        cin>>x;
    }
    while (x<=1 || x>=p-1);

    //tinh khoa cog khai
    long long y = power(g,x,p);
    cout<<"khoa cong khai y="<<y<<endl;

    //nhap ban ro m
   // do
   // {
    //    cout<<"nhap ban ro m(0<m<p):";
   //     cin>>m;
//
  //  }
   // while (m<=0 || m>=p);
    //nhap k ngau nhien



    do
    {
        cout<<"Nhap so ngau nhien k (1<k<p-1):";
        cin>>k;
    }
    while (k<=1 || k>=p-1);


   string s;
   cin.ignore();
   cout<<"nhap thong diep:";
   getline(cin,s);

   vector <int > day;
   for(char m:s)
        day.push_back(int(m));




    vector<pair<long long , long long>> banMo;
    vector<long long> banRo;

    for(int m:day)
    {
         //ma hoa
    long long c1 = power(g,k,p);
    long long c2 =(m*power(y,k,p))%p;

    banMo.push_back({c1,c2});

    //giai ma
    long long s = power(c1,x,p);
    long long s_1=nghich_dao(s,p);
    if(s_1==-1)
    {
        cout<<"Ko tim duoc nghich dao cua s. Giai ma that bai!"<<endl;
        return 1;
    }

    long long giaiMa = (c2*s_1)%p;
    banRo.push_back(giaiMa);
    }
    cout << "\nCac cap (c1, c2) sau khi ma hoa:\n";
    for (auto &c : banMo)
    cout << "(" << c.first << ", " << c.second << ") ";
    cout << endl;

    cout << "\nBan ro sau khi giai ma:\n";
    for (long long val : banRo)
    cout << char(val);
    cout << endl;


}
