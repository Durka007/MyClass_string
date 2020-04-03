

#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

const int  d = 20;			 
const  int  n = 10;

class Mycls {
    char tmp;
	string ar[d];
	string *text[n];
public:
    bool open() //open file
    {
        ifstream file("Text.txt");
        if (!file)
        {
            cout << "File not found\n";
            return 1;
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < d; j++)
            {
                file.get(tmp);
                ar[i] += tmp;
                text[i] = &ar[i];
            }
        return 0;
    }
    void print(){
        for (int i = 0; i < n; i++)
            cout << *text[i]<<endl;
        cout << endl;
    }
    void delspace(int t) {
        int k = 0;
        int max = d;
        int begin = 0;
        for (int i = 0; i < max; i++) {
            if (text[t]->at(i) == ' ')
            {
                if(k==0)
                    begin = i;
                k++;
                
            }
            else
            {
                if (k >= 2)
                {
                    text[t]->erase(begin, k-1);
                    max = max - (k-1);
                }
                k = 0;
            }
        }
    }
};
int main()
{

    Mycls T1;
    if (T1.open() == 1)
    {
        return 1;
    }
    T1.print();
    T1.delspace(0);
    T1.print();
    return 0;
}


