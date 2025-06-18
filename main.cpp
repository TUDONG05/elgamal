#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long power(long long a, long long b, long long p)
{
    long long f =1;
    a =a%p;
    while (b>0)
    {
        if(b&1)
            f=(f*a)%p;
        a = (a*a)%p;
        b=b/2;
    }
    return f;
}

long long nghich(long long a, long long n)
{
    for(int i=2;i<n;i++)
        if((a*i)%n==1)
            return i;
    return -1;
}

bool check_snt(long long a)
{
    if(a<2)
        return false;
    else
    {
        for(int i=2;i<=sqrt(a);i++)
            if(a%i==0)
                return false;
        return true;
    }

}
bool check_pts(long long g, long long p)
{
    set <long long> Set;
    for(int i=1;i<p;i++)
        Set.insert(power(g,i,p));
    return(Set.size()==p-1);
}


int main()
{
    long long p;

    do
    {
        cout<<"Nhap so nguyen to lon p:";
        cin>>p;
    }
    while(!check_snt(p));

    long long g;
    do
    {
        cout<<"Nhap ptu sinh g trong z_p:";
        cin>>g;
    }
    while(g<= 1 || g>=p || !check_pts(g,p));
    long long x;
    do
    {
        cout<<"nhap khoa rieng x( 1<x<"<<p<<"):";
        cin>>x;
    }
    while(x<=1 || x>=p);
    long long y = power(g,x,p);

    long long k;
    do
    {
        cout<<"nahp so ngau nhien k:";
        cin>>k;

    }
    while(k<=1 || k>=p);

    string s ;
    cin.ignore();
    cout<<"Nhap thong diep muon ma hoa:";
    getline(cin,s);

    //chuyen kitu -> so
    vector <long long> m;
    for(char si: s )
        m.push_back(int(si));

    vector <pair<long long, long long>> banMo;
    vector <long long> giaiMa;

    //ma hoa va giai ma
    for(long long mi :m)
    {
        long long c1 = power(g,k,p);
        long long c2 = (mi*power(y,k,p))%p;

        banMo.push_back({c1,c2});

        //giai ma
        long long s = power(c1,x,p);
        long long s_1 =nghich(s,p);

        if(s_1 ==-1)
        {
            cout<<"ko tim dc nghich dao s_1, ko the giai ma!"<<endl;

        }
        else
        {
            long long mess = (c2*s_1)%p;
            giaiMa.push_back(mess);


        }

    }
            cout<<"cac cap khoa (c1,c2):"<<endl;
            for(auto &c :banMo)
                cout<<"("<<c.first<<","<<c.second<<")";
                cout<<endl;

            cout<<"giai ma thong diep ta duoc:"<<endl;
            for(long long i:giaiMa)
                cout<<(char)i;
            cout<<endl;


}
