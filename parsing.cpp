#include "MergeInsert.hpp"
#include <stdexcept>
#include <vector>
#include <cstring>
#include <climits>

void MergeInsert::parsing(int ac,char **argv)
{
    vector<int> nums;

    if (ac <= 2)
        throw logic_error("enter at least two argements without using quotes");
    nums.reserve(ac - 1);
    for (size_t i = 1; i < ac; i++)
    {
        char *rest;
        long nb = strtol(argv[i],&rest,10);
        if (rest == argv[i] || *rest != '\0')
            throw logic_error("input not valid");
        if (nb > INT_MAX || nb < INT_MIN)
            throw logic_error("invalid number out of rand INT_MAX INT_MIN");
        if (nums.size() > 0 && find(nums.begin(),nums.end(),nb) != nums.end())
            throw logic_error("invalid input do not enter Duplicate Number");
        nums.push_back(nb);
    }
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
            this->pairs.push_back(p);
        }
        else
        {
            this->isOdd = true;
            this->single = nums[i];
        }
        i += 2;
    }
 
}


void MergeInsert::display()
{
    for (list<pair<int,int> >::iterator it = this->pairs.begin(); it != this->pairs.end(); it++)
    {
        cout << '[' << it->first << ',' << it->second << "]\t";
    }
    if (this->isOdd)
        cout  << this->single;
    cout << endl;
}