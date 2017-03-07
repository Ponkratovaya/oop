#include <iostream>
using namespace std;

class Tree {
public:
    int key;
    Tree *left;
    Tree *right;
public:
    Tree *First(int k) {
        Tree *u = new Tree;
        u->key = k;
        u->left = NULL;
        u->right = NULL;
        return u;
    }


//Ищем вершину, если ее нет, то добавляем
    Tree *Add(Tree *Cur, int k) {
        Tree *p = Cur, *prev;
        bool found = false;
        while (p && !found) {
            prev = p;
            if (k == p->key) { found = true; }
            else if (k < p->key) {
                p = p->left;
            }
            else p = p->right;
        }
        if (found)  { Tree *u = new Tree;
            u->key = k;
            u->left = NULL;
            u->right = p;  return p; }

        Tree *u = new Tree;
        u->key = k;
        u->left = NULL;
        u->right = NULL;
        if (k < prev->key) prev->left = u;
        else prev->right = u;
        return u;
    }


    Tree *Find(Tree *Cur, int k)
    {
        Tree *p = Cur, *prev;
        bool found = false;
        while (p && !found) {
            prev = p;
            if (k == p->key) { found = true; }
            else if (k < p->key) {
                p = p->left;
            } else p = p->right;
        }
        if (found) {
            cout << "есть  вершина с ключом  =" << k << endl;
            return p;
                 }
        else { cout << "Нет вершины с ключом = " << k  << endl; }
    }

    Tree *Delete(Tree *Cur, int k)
     {
         Tree *p = Cur, *prev;
         bool found = false;
         while (p && !found) {
             prev = p;
             if (k == p->key) { found = true; }
             else if (k < p->key) {
                 p = p->left;
             }
             else p = p->right;
         }
         if (found) {
             cout << "есть  вершина с ключом  =" << k << endl;
             if ((p->left == NULL) && (p->right == NULL))
               {
                 cout << "list" << endl;
                   delete  p;
               }
             else if (p->left == NULL) { p = p->right;  }
                  else {  p = p->left;  }
             return p; }

         else {cout<<"Нет вершины с ключом = "<<k<<endl;}
     }

    void Print(Tree *p, int k ){
        if (p) {
            Print(p->right, k + 1);
            for (int i = 0; i < k; i++) cout << "    ";
            cout << p->key << endl;
            Print(p->left, k + 1);
        }
    }
};
int main()

{   int n,i;
    cout<<"Введите количество элементов в дереве"<<endl;
    cin>>n;
    int a[n];

    cout<<"Введите элементы дерева"<<endl;
    cin>>a[0];
    Tree M;
    //создаем дерево
    Tree *Cur= M.First(a[0]);
    for (i=1; i<n; i++)
       {cin>>a[i];
        M.Add(Cur, a[i]);}
    M.Print(Cur, 0);
    int t;
    cout<<"Какой элемент хотите добавить?"<<endl;
    cin>>t;
    M.Add(Cur, t);
   // cout<<"Какой элемент хотите удалить?"<<endl;
   // cin>>t;
  //  M.Delete(Cur, t);
    cout<<"Выводим получившееся дерево"<<endl;
    M.Print(Cur, 0);
    return 0;
}