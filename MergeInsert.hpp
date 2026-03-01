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
        double time;

    public:
        MergeInsert(vector<int> &nums);
        void init_pairs(Type type);
        double algo(Type type);
        void display();
};

void merge_sort(list<pair<int,int> >& pairs);
void merge_sort(vector<pair<int,int> >& pairs);

void insertion(vector<pair<int,int> >& pairs,bool isOdd,int num);
void insertion(list<pair<int,int> >& pairs,bool isOdd,int num);