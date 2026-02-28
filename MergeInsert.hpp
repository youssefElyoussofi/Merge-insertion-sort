#include <iostream>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

enum Type {LIST,VECTOR}; 

class MergeInsert
{
    private:
        vector<int> nums;
        list<pair<int, int> > pairsLst;
        vector<pair<int, int> > pairsVec;
        bool isOdd;
        int single;

    public:
        MergeInsert(vector<int> &nums);
        void init_pairs(Type type);
        void algo(Type type);
        void display(Type type);
};

void merge_sort(list<pair<int,int> >& pairs);
void merge_sort(vector<pair<int,int> >& pairs);
