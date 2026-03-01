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

// void merge_sort(vector<pair<int,int> >& pairs)
// {
//     if (pairs.size() <= 1)
//         return;
//     size_t mid = pairs.size() / 2;
//     vector<pair<int,int> > left(pairs.begin(),pairs.begin() + mid);
//     vector<pair<int,int> > right(pairs.begin() + mid,pairs.end());
//     merge_sort(left);
//     merge_sort(right);
//     size_t left_len = left.size();
//     size_t right_len = right.size();
//     size_t l = 0,r = 0,index = 0;
//     while (l < left_len && r < right_len)
//     {
//         if (left[l].first < right[r].first)
//         {
//             pairs[index++] = left[l++];
//         }
//         else
//         {
//             pairs[index++] = right[r++];
//         }
//     }
//     while (l < left_len)
//     {
//         pairs[index++] = left[l++];
//     }
//     while (r < right_len)
//     {
//         pairs[index++] = right[r++];
//     }
// }


// void merge_sort(vector<pair<int,int> >& pairs)
// {
//     if (pairs.size() <= 1)
//         return;
//     size_t mid = pairs.size() / 2;
//     vector<pair<int,int> > left(pairs.begin(),pairs.begin() + mid);
//     vector<pair<int,int> > right(pairs.begin() + mid,pairs.end());
//     merge_sort(left);
//     merge_sort(right);
//     vector<pair<int,int> >::iterator  it1, it2;
//     it1 = left.begin();
//     it2 = right.begin();
//     pairs.clear();

//     while (it1 != left.end() && it2 != right.end())
//     {
//         if (it1->first < it2->first)
//             pairs.push_back(*(it1++));
//         else
//             pairs.push_back(*(it2++));
//     }
//     pairs.insert(pairs.end(),it1,left.end());
//     pairs.insert(pairs.end(),it2,right.end());
// }

// void merge_sort(vector<pair<int,int> >& pairs)
// {
//     if (pairs.size() <= 1)
//         return;
//     size_t mid = pairs.size() / 2;
//     vector<pair<int,int> > left(pairs.begin(),pairs.begin() + mid);
//     vector<pair<int,int> > right(pairs.begin() + mid,pairs.end());
//     merge_sort(left);
//     merge_sort(right);
//     vector<pair<int,int> >::iterator it, it1, it2;
//     vector<pair<int,int> > vec;
//     it = vec.begin();
//     it1 = left.begin();
//     it2 = right.begin();

//     while (it1 != left.end() && it2 != right.end())
//     {
//         if (it1->first < it2->first)
//             vec.push_back(*(it1++));
//         else
//             vec.push_back(*(it2++));
//     }
//     vec.insert(vec.end(),it1,left.end());
//     vec.insert(vec.end(),it2,right.end());
//     pairs = vec;
// }



void merge_sort(vector<pair<int,int> >& pairs)
{
    if (pairs.size() <= 1)
        return;
        
    size_t mid = pairs.size() / 2;
    vector<pair<int,int> > left(pairs.begin(), pairs.begin() + mid);
    vector<pair<int,int> > right(pairs.begin() + mid, pairs.end());
    
    merge_sort(left);
    merge_sort(right);
    
    vector<pair<int,int> > vec(pairs.size()); 
    
    vector<pair<int,int> >::iterator it = vec.begin();
    vector<pair<int,int> >::iterator it1 = left.begin();
    vector<pair<int,int> >::iterator it2 = right.begin();

    while (it1 != left.end() && it2 != right.end())
    {
        if (it1->first < it2->first)
            *(it++) = *(it1++);
        else
            *(it++) = *(it2++);
    }
    while (it1 != left.end())
    {
        *(it++) = *(it1++);
    }
    while (it2 != right.end())
    {
        *(it++) = *(it2++);
    }
    pairs = vec;
}