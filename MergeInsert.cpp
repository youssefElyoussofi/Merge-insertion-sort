#include "MergeInsert.hpp"

MergeInsert::MergeInsert(vector<int>& nums):nums(nums),isOdd(false)
{

}

void MergeInsert::init_pairs()
{
    for (size_t i = 0; i < nums.size();)
    {
        if (i + 1 < nums.size())
        {
            pair<int,int> p;
            if (nums[i] > nums[i + 1])
            {
                p.first = nums[i];
                p.second = nums[i + 1];
            }
            else
            {
                p.first = nums[i + 1];
                p.second = nums[i];
            }
            pairs.push_back(p);
        }
        else
        {
            isOdd = true;
            single = nums[i];
        }
        i += 2;
    }
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
    this->init_pairs();
    merge_sort(this->pairs);
    list<pair<int,int> > losers = this->pairs;
    vector<int> jacob = jacobstalNums();
    list<pair<int,int> >::iterator oldIterat , currIterat , target, insert_pos,index;
    size_t jacobIndex = 2,pos,total = 0;
    pair<int,int> tmp;
    for (size_t total = 0;total < losers.size();)
    {
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
            pos = jacob[jacobIndex] - 1;
            oldIterat = currIterat;
            if (pos < losers.size())
            {
                currIterat = losers.begin();
                advance(currIterat,pos);
            }
            else
                currIterat = --losers.end();
            index = currIterat;
            while (index != oldIterat)
            {
                tmp.first = index->second;
                tmp.second = index->first;
                target = find(pairs.begin(),pairs.end(),*index);
                insert_pos = lower_bound(pairs.begin(),target,tmp,compare);
                pairs.insert(insert_pos,tmp);
                --index;
                total++;
            }
        }
        jacobIndex++;
    }
    if (this->isOdd)
    {
        tmp.first = this->single;
        insert_pos = lower_bound(pairs.begin(),pairs.end(),tmp,compare);
        pairs.insert(insert_pos,tmp);
    }
    
}

void MergeInsert::display()
{
    for (list<pair<int,int> >::iterator it = this->pairs.begin(); it != this->pairs.end(); it++)
    {
        cout << it->first << ' ';
    }
    cout << endl;
}