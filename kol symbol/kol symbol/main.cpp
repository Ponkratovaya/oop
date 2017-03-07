#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()

{  setlocale(LC_ALL, "rus");
   ifstream fin;
   fin.open("in.txt");
   ofstream fout;
   fout.open("out.txt");
   if (!fin) {cout<<"no open file"<<endl;}
   if (!fout) {cout<<"no open file"<<endl;}
    string str,buf;
    char a;
 /* while (!fin.eof()) {
    getline ( fin, buf, '\0' );
    str+=buf;
    }*/
    int siz,i,index;
    int mas[33];
    for (i=0; i<33; i++)
        mas[i]=0;
    siz = str.length();
   // cout<<"Длина строки ="<<siz<<endl;
//cout<<str;
    for (i=0; i<siz; i++)
     cout<<" код буквы а="<<(int)(a)<<endl;
// cout<<"ghdfjh"<<endl;
  // fin>>a; cout<<a<<"="<<(int)a<<endl;
    while (!fin.eof())
    {
        fin>>a;
        {
            if (((int)(a)>=-64) &&((int)(a)<=-1))
               {
                index =(((int)(a))+64)%32;
                mas[index]= mas[index]+1;
               }
            if (((int)(a)==-72) || ((int)(a)==-88))
                mas[32]=mas[32]+1;
        }

    }
    int kol=0;
   for (i=0; i<32; i++) {kol=kol+mas[i];}
   for (i=0; i<32; i++)
      if (i==6) { fout<<(char)168<<"  = "<< (float) mas[i]/kol<<endl; fout<<(char)(i+192)<<"  = "<<(float) mas[i]/kol<<endl;}
    else {
            fout<<((char)(i+192))<<"  = "<<(float) mas[i]/kol<<endl;
            //cout<<mas[i]<<endl;
         }
      // cout<<5656<<endl;
    fin.close();
    fout.close();
    cout << "Hello world!" << endl;
    return 0;
}
