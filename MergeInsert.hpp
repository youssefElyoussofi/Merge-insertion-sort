#include <iostream>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

class MergeInsert
{
    private:
        vector<int> nums;
        list<pair<int, int> > pairs;
        bool isOdd;
        int single;

    public:
        MergeInsert(vector<int> &nums);
        void init_pairs();
        void algo();
        void display();
};