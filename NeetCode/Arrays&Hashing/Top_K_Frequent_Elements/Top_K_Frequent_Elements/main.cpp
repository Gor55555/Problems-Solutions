#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

std::vector<int> Sorting(std::vector<int>& nums, int k)       //Time complexity:  O(nlogn)
{                                                             //Space complexity: O(n)
    std::unordered_map<int, int> count;
    for (int num : nums)
    {
        count[num]++;
    }

    std::vector<std::pair<int, int>> arr;
    for (const auto& p : count) {
        arr.push_back({ p.second, p.first });
    }

    std::sort(arr.rbegin(), arr.rend());

    std::vector<int> res;
    for (int i = 0; i < k; ++i)
    {
        res.push_back(arr[i].second);
    }
    return res;
}

std::vector<int> Heap(std::vector<int>& nums, int k)        //Time complexity:  O(nlogk) 
{                                                           //Space complexity: O(n+k)
    std::unordered_map<int, int> count;
    for (int num : nums)
    {
        count[num]++;
    }

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> heap;
    for (auto& entry : count)
    {
        heap.push({ entry.second, entry.first });

        if (heap.size() > k)
        {
            heap.pop();
        }
    }

    std::vector<int> res;
    for (int i = 0; i < k; i++)
    {
        res.push_back(heap.top().second);
        heap.pop();
    }
    return res;
}

std::vector<int> Bucket_Sort(std::vector<int>& nums, int k)           //Time complexity:  O(n)
{                                                                     //Space complexity: O(n) 
    std::unordered_map<int, int> count;
    std::vector<std::vector<int>> freq(nums.size() + 1);

    for (int n : nums)
    {
        count[n] = 1 + count[n];
    }
    for (const auto& entry : count)
    {
        freq[entry.second].push_back(entry.first);
    }

    std::vector<int> res;
    for (int i = freq.size() - 1; i > 0; --i)
    {
        for (int n : freq[i])
        {
            res.push_back(n);
            if (res.size() == k)
            {
                return res;
            }
        }
    }
    return res;
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

    int k;
    std::cout << std::setw(10) << std::left << "Input: ";
    std::cin >> k;

    std::cout << "\n" << std::setw(35) << std::left << "Outnput with use Sorting: ";
    for (int num : Sorting(nums, k))
    {
        std::cout << num << " ";
    }

    std::cout << "\n" << std::setw(35) << std::left << "Outnput with use Heap: ";
    for (int num : Heap(nums, k))
    {
        std::cout << num << " ";
    }

    std::cout << "\n" << std::setw(35) << std::left << "Outnput with use Bucket Sort: ";
    for (int num : Bucket_Sort(nums, k))
    {
        std::cout << num << " ";
    }
}