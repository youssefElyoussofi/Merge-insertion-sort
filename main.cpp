#include "MergeInsert.hpp"
#include <stdexcept>
#include <cstring>
#include <climits>
#include <sys/time.h>

void parsing(int ac,char **argv,vector<int>& nums)
{
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
}

int main(int ac,char **av)
{
    vector<int> nums;
    timeval tm1, tm2;
    try
    {
        parsing(ac,av,nums);
        MergeInsert merge(nums);
        gettimeofday(&tm1,NULL);
        merge.algo();
        gettimeofday(&tm2,NULL);
        double time = ((tm2.tv_sec - tm1.tv_sec) * 1000000.0) + (tm2.tv_usec - tm1.tv_usec);
        merge.display();
        cout << "time : " << time << " us\n";
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
}