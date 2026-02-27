#include "MergeInsert.hpp"
#include <vector>

MergeInsert::MergeInsert():isOdd(false)
{

}

static vector<int> jacobstalNums()
{
    vector<int> jacobstal;

    jacobstal.reserve(20);
    jacobstal[0] = 0;
    jacobstal[1] = 1;
    for (size_t i = 2; i < 20; i++)
    {
        jacobstal[i] = jacobstal[i - 1] + (jacobstal[i - 2] * 2);
    }
    return jacobstal;
}

static void merge_sort(list<pair<int,int> >& pairs)
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

bool compare(pair<int,int>& elem,const pair<int,int>& tmp_elem)
{
    return elem.first < tmp_elem.first;
}

void MergeInsert::algo()
{
    merge_sort(this->pairs);

    list<pair<int,int> > losers = this->pairs;
    vector<int> jacob = jacobstalNums();
    list<pair<int,int> >::iterator oldIterat , currIterat , target, insert_pos;
    size_t jacobIndex = 2,pos,total = 0;

    for (size_t total = 0;total < losers.size();)
    {
        pair<int,int> tmp;
        if(jacobIndex == 2)
        {
            currIterat = losers.begin();
            tmp.first = currIterat->second;
            tmp.second = currIterat->first;
            pairs.push_front(tmp);
            total++;
        }
        else
        {
            oldIterat = currIterat;
            pos = jacob[jacobIndex] - 1;
            if (pos < losers.size())
            {
                currIterat = losers.begin();
                advance(currIterat,pos);
            }
            else
                currIterat = --losers.end();
            while (currIterat != oldIterat)
            {
                tmp.first = currIterat->second;
                tmp.second = currIterat->first;
                target = find(pairs.begin(),pairs.end(),*currIterat);
                insert_pos = lower_bound(pairs.begin(),target,tmp,compare);
                pairs.insert(insert_pos,tmp);
                --currIterat;
                total++;
            }
        }
        jacobIndex++;
    }
    
}