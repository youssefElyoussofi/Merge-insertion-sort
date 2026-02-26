#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class MergeInsert
{
    private:
        list<pair<int,int>> pairs;
    public:
        MergeInsert();
        void parsing(int ac,char **av);
        
};