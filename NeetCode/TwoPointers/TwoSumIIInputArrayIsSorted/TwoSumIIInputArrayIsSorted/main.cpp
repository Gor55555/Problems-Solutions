#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_map>

std::vector<int> Brute_Force(std::vector<int>& numbers, int target)      //Time complexity:  O(n^2)
{                                                                        //Space complexity: O(1)
    for (int i = 0; i < numbers.size(); i++) 
    {
        for (int j = i + 1; j < numbers.size(); j++) 
        {
            if (numbers[i] + numbers[j] == target)
            {
                return { i + 1, j + 1 };
            }
        }
    }
    return {};
}
std::vector<int> Binary_Search(std::vector<int>& numbers, int target)    //Time complexity:  O(nlogn)
{                                                                        //Space complexity: O(1)
    for (int i = 0; i < numbers.size(); i++) 
    {
        int l = i + 1, r = numbers.size() - 1;
        int tmp = target - numbers[i];
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (numbers[mid] == tmp) 
            {
                return { i + 1, mid + 1 };
            }
            else if (numbers[mid] < tmp) 
            {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
    }
    return {};
}
std::vector<int> Hash_Map(std::vector<int>& numbers, int target)       //Time complexity:  O(n)
{                                                                      //Space complexity: O(n)
    std::unordered_map<int, int> mp;
    for (int i = 0; i < numbers.size(); i++)
    {
        int tmp = target - numbers[i];
        if (mp.count(tmp))
        {
            return { mp[tmp], i + 1 };
        }
        mp[numbers[i]] = i + 1;
    }
    return {};
}
std::vector<int> Two_Pointers(std::vector<int>& numbers, int target)   //Time complexity:  O(n)
{                                                                      //Space complexity: O(1)
    int l = 0, r = numbers.size() - 1;

    while (l < r)
    {
        int curSum = numbers[l] + numbers[r];

        if (curSum > target)
        {
            r--;
        }
        else if (curSum < target) 
        {
            l++;
        }
        else
        {
            return { l + 1, r + 1 };
        }
    }
    return {};
}
int main()
{
    int size;
    std::cout << std::setw(10) << std::left << "Input: ";
    std::cin >> size;
    std::vector<int> numbers(size);
    std::cout << std::setw(10) << std::left << "Input: ";
    for (int i = 0; i < numbers.size(); ++i)
    {
        std::cin >> numbers[i];
    }
    int target;
    std::cout << std::setw(10) << std::left << "Input: ";
    std::cin >> target;


    std::cout << "\n" << std::setw(35) << std::left << "Output with use Brute Force: ";
    for (int i : Brute_Force(numbers, target))
    {
        std::cout << i << " ";
    }
    std::cout << "\n" << std::setw(35) << std::left << "Output with use Binary Search: ";
    for (int i : Binary_Search(numbers, target))
    {
        std::cout << i << " ";
    }
    std::cout << "\n" << std::setw(35) << std::left << "Output with use Hash Map: ";
    for (int i : Hash_Map(numbers, target))
    {
        std::cout << i << " ";
    }
    std::cout << "\n" << std::setw(35) << std::left << "Output with use Two Pointers: ";
    for (int i : Two_Pointers(numbers, target))
    {
        std::cout << i << " ";
    }
}