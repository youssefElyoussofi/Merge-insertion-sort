#include "MergeInsert.hpp"

static void jacobstalNums(vector<int>& jacobstal)
{
    jacobstal.reserve(20);
    jacobstal[0] = 0;
    jacobstal[1] = 1;
    for (size_t i = 2; i < 20; i++)
    {
        jacobstal[i] = jacobstal[i - 1] + (jacobstal[i - 2] * 2);
    }
}

bool compare(const pair<int, int> &elem, const pair<int, int> &tmp_elem)
{
    return elem.first < tmp_elem.first;
}

void insertion(list<pair<int,int> >& pairs,bool isOdd,int num)
{
    list<pair<int, int> > losers = pairs;
    vector<int> jacob;
    jacobstalNums(jacob);
    list<pair<int, int> >::iterator oldIterat, currIterat, target, insert_pos, index;
    size_t jacobIndex = 2, pos, total = 0;
    pair<int, int> tmp;
    for (size_t total = 0; total < losers.size();)
    {
        if (jacobIndex == 2)
        {
            currIterat = losers.begin();
            tmp.first = currIterat->second;
            tmp.second = currIterat->first;
            pairs.push_front(tmp);
            total++;
        }
        else
        {
            pos = jacob[jacobIndex] - 1;
            oldIterat = currIterat;
            if (pos < losers.size())
            {
                currIterat = losers.begin();
                advance(currIterat, pos);
            }
            else
                currIterat = --losers.end();
            index = currIterat;
            while (index != oldIterat)
            {
                tmp.first = index->second;
                tmp.second = index->first;
                target = find(pairs.begin(), pairs.end(), *index);
                insert_pos = lower_bound(pairs.begin(), target, tmp, compare);
                pairs.insert(insert_pos, tmp);
                --index;
                ++total;
            }
        }
        ++jacobIndex;
    }
    if (isOdd)
    {
        tmp.first = num;
        insert_pos = lower_bound(pairs.begin(), pairs.end(), tmp, compare);
        pairs.insert(insert_pos, tmp);
    }
}

void insertion(vector<pair<int,int> >& pairs,bool isOdd,int num)
{
    vector<pair<int, int> > losers;
    pair<int, int> tmp;

    losers = pairs;
    vector<int> jacob;
    jacobstalNums(jacob);
    size_t jIndex = 2, currIndex = 0, oldIndex = 0;
    vector<pair<int, int> >::iterator target, insert_pos;
    while (oldIndex != losers.size() - 1)
    {
        currIndex = (jacob[jIndex] - 1 > losers.size() )? (losers.size() - 1) : (jacob[jIndex] - 1);
        if (jacob[jIndex] == 1)
        {
            tmp.first = losers[0].second;
            tmp.second = losers[0].first;
            pairs.insert(pairs.begin(),tmp);
        }
        else
        {
            for (size_t i = currIndex; i > oldIndex; --i)
            {
                tmp.first = losers[i].second;
                tmp.second = losers[i].first;
                target = find(pairs.begin(),pairs.end(),losers[i]);
                insert_pos = lower_bound(pairs.begin(),target,tmp,compare);
                pairs.insert(insert_pos,tmp);
            }
        }
        oldIndex = currIndex;
        jIndex++;
    }
    if (isOdd)
    {
        tmp.first = num;
        insert_pos = lower_bound(pairs.begin(), pairs.end(), tmp, compare);
        pairs.insert(insert_pos, tmp);
    }
}