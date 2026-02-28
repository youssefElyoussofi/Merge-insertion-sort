#include "MergeInsert.hpp"

void merge_sort(list<pair<int,int> >& pairs)
{
    if(pairs.size() <= 1)
        return;
    
    list<pair<int,int> >::iterator mid = pairs.begin();
    advance(mid,pairs.size()/2);
    list<pair<int,int> > left , right;
    left.splice(left.begin(),pairs,pairs.begin(),mid);
    right.splice(right.begin(),pairs,pairs.begin(),pairs.end());

    merge_sort(left);
    merge_sort(right);

    list<pair<int,int> >::iterator it1 = left.begin();
    list<pair<int,int> >::iterator it2 = right.begin();

    while (it1 != left.end() && it2 != right.end())
    {
        if (it1->first < it2->first)
        {
            pairs.splice(pairs.end(),left,it1++);
        }
        else
        {
            pairs.splice(pairs.end(),right,it2++);
        }
    }
    pairs.splice(pairs.end(),left);
    pairs.splice(pairs.end(),right);
}

void merge_sort(vector<pair<int,int> >& pairs)
{
    
}