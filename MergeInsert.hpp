#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class MergeInsert
{
    private:
        list<pair<int,int> > pairs;
        bool isOdd;
        int single;
    public:
        MergeInsert();
        void parsing(int ac,char **av);
        void algo();
        void display();
        
};