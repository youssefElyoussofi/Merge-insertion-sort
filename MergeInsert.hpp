#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class MergeInsert
{
    private:
        list<pair<int,int>> pairs;
        bool isOdd = false;
        int single;
    public:
        MergeInsert();
        void parsing(int ac,char **av);
        
};