#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <cstdio>
#include <math.h>
using namespace std;
int main() {
int i,n,j,k;
 //считываем размерность
    freopen("a.txt", "r", stdin);
    cin>>n;
    fclose(stdin);
    cout<<n<<endl;
float **a=new float *[n];
    for (i=0; i<n; i++)
        a[i] = new float [n];
float *b=new float [n];
float *x=new  float [n];
    //считываем столбец а и b
    freopen("a.txt", "r", stdin);
    cin>>n;
    for (i=0; i<n; i++) {
        for (j = 0; j < n; j++)
            cin >> a[i][j];
        cin>>b[i];
    }

    fclose(stdin);
    //выводим массив а b
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++)
        {cout<<a[i][j]<< "  "; }cout<<b[i];
        cout<<endl;
    }
    int ind1,ind2,m;
 float d,sum,max;
    for (k = 0; k < n; k++)
    {   max=fabsf(a[k][k]);
        for ( m=k; m<n; m++)
            if (fabs(a[m][m])>max)
            { max =fabs(a[m][m]);
              ind1=m ;
            }

        for (ind2=0; ind2<n; ind2++)
            swap(a[ind1,ind2], a[k,ind2]);
        swap(b[ind1],b[k]);
        for (j = k + 1; j < n; j++)
        {
            d = a[j][k] / a[k][k]; cout<<endl<<"d="<<d<<endl;
            for (i = k; i <= n; i++)
            {
                a[j][i] = a[j][i] - d * a[k][i];
            }
            b[j] = b[j] - d * b[k];
        }
    }

    for (k = n-1; k >= 0; k--)
    {
        d = 0;
        for (j = k + 1; j <= n; j++)
        {
            sum = a[k][j] * x[j];
            d = d + sum;
        }
        x[k] = (b[k] - d) / a[k][k];
    }
   // cout<<"that";
    freopen("x.txt", "w", stdout);
    for (i=0; i<n; i++)
            cout<<x[i]<<endl;
           // cout<<"rgfd";
    fclose(stdout);
/*cout<<"dfdf";
    for (i=0; i<n; i++)
        cout<<x[i]<<"  "<<endl;
    cout << "Hello, World!" << endl;*/
    return 0;
}