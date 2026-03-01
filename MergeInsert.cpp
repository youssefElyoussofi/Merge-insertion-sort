#include "MergeInsert.hpp"
#include <sys/time.h>

MergeInsert::MergeInsert(vector<int> &nums) : nums(nums), isOdd(false)
{
}

void MergeInsert::init_pairs(Type type)
{
    if (type == VECTOR)
        pairsVec.reserve((nums.size() / 2) + 1);
    for (size_t i = 0; i < nums.size();)
    {
        if (i + 1 < nums.size())
        {
            pair<int, int> p;
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
            if (type == VECTOR)
                pairsVec.push_back(p);
            else
                pairsLst.push_back(p);
        }
        else
        {
            isOdd = true;
            single = nums[i];
        }
        i += 2;
    }
}

double MergeInsert::algo(Type type)
{
    // start timer to get exactly time that can algo take
    timeval t1, t2;
    gettimeofday(&t1, NULL);
    // 1 Group the elements into ⌊ n / 2 ⌋ pairs of elements
    // leaving one element unpaired if there is an odd number of elements.

    // 2 -Perform ⌊ n / 2 ⌋ {\displaystyle \lfloor n/2\rfloor } comparisons,
    // one per pair, to determine the larger of the two elements in each pair.

    // (this function include both steps 1 - 2)
    this->init_pairs(type);

    // 3 - Recursively sort the ⌊ n / 2 ⌋ by larger elements from each pair,
    // in ascending order, using the merge-insertion sort.
    if (type == LIST)
        merge_sort(this->pairsLst);
    else
        merge_sort(this->pairsVec);

    // 4 - Insert at the start element that was paired with the first and smallest element of our sequence.
    // 5 - Insert the remaining ⌈ n / 2 ⌉ − 1 elements, with a specially chosen insertion ordering.
    // Use binary search in subsequences to determine the position at which each element should be inserted.
    if (type == LIST)
        insertion(this->pairsLst, this->isOdd, this->single);
    else
        insertion(this->pairsVec, this->isOdd, this->single);
    // take time to know exactly when it's done
    gettimeofday(&t2, NULL);
    // calculate time by miscosecond
    double time = ((t2.tv_sec - t1.tv_sec) * 1000000.0) + (t2.tv_usec - t1.tv_usec);
    return time;
}

void MergeInsert::display()
{
    cout << "sorted numbers : \n";
    for (vector<pair<int, int> >::iterator it = this->pairsVec.begin(); it != this->pairsVec.end(); it++)
    {
        cout << it->first << ' ';
    }
    cout << '\n';
}