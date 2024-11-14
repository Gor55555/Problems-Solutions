#include <iostream> 
#include <iomanip> 
#include <vector> 
#include <unordered_set> 
#include <algorithm>

bool Brute_Force(std::vector<int>& nums)                  //Time complexity O(n^2)
{                                                         //Space complexity O(1)
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
            {
                return true;
            }
        }
    }
    return false;
}

bool Sorting(std::vector<int>& nums)                    //Time complexity O(nlogn)
{                                                       //Space complexity O(1)
    std::sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1])
        {
            return true;
        }
    }
    return false;
}

bool  Hash_Set(std::vector<int>& nums)                 //Time complexity O(n)
{                                                      //Space complexity O(n)
    std::unordered_set<int> s;

    for (int i = 0; i < nums.size(); ++i)
    {
        if (s.find(nums[i]) != s.end())
        {
            return true;
        }
        s.insert(nums[i]);

    }
    return false;
}

bool Hash_Set_Length(std::vector<int>& nums)          //Time complexity O(n)
{                                                     //Space complexity O(n)
    return std::unordered_set<int>(nums.begin(), 
        nums.end()).size() < nums.size();
}

int main()
{
    int size;
    std::cout << std::setw(10) << std::left << "Input: ";
    std::cin >> size;

    std::vector<int> nums(size);

    std::cout << std::setw(10) << std::left << "Input: ";
    for (int i = 0; i < nums.size(); ++i)
    {
        std::cin >> nums[i];
    }

    std::cout << "\n" << std::setw(35) << std::left << "Output with use Brute Force: " << (Brute_Force(nums) ? "True" : "False");
    std::cout << "\n" << std::setw(35) << std::left << "Output with use Sorting: " << (Sorting(nums) ? "True" : "False");
    std::cout << "\n" << std::setw(35) << std::left << "Output with use Hash Set: " << (Hash_Set(nums) ? "True" : "False");
    std::cout << "\n" << std::setw(35) << std::left << "Output with use Hash Set Lenght: " << (Hash_Set_Length(nums) ? "True" : "False");
}
