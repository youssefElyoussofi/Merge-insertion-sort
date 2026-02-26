#include "MergeInsert.hpp"
#include <vector>

int main(int ac,char **av)
{
    MergeInsert merge;

    try
    {
        merge.parsing(ac,av);
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
}