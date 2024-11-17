#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<int> Brute_Force(std::vector<int>& nums, int target)          //Time complexity:  O(n^2)                                                       
{                                                                         //Space complexity: O(1)
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (nums[i] + nums[j] == target)
			{
				return { i, j };
			}
		}
	}
	return {};
}

std::vector<int> Sorting(std::vector<int>& nums, int target)              //Time complexity:  O(nlogn)                                                       
{                                                                         //Space complexity: O(n)
	std::vector<std::pair<int, int>> p;
	for (int i = 0; i < nums.size(); i++) 
	{
		p.push_back({ nums[i], i });
	}

	sort(p.begin(), p.end());

	int i = 0, j = nums.size() - 1;
	while (i < j) 
	{
		int cur = p[i].first + p[j].first;
		if (cur == target)
		{
			return { std::min(p[i].second, p[j].second),
					std::max(p[i].second, p[j].second) };
		}
		else if (cur < target)
		{
			i++;
		}
		else {
			j--;
		}
	}
	return {};
}

std::vector<int> Hash_Map_Two_Pass(std::vector<int>& nums, int target)         //Time complexity:  O(n)                                                       
{                                                                              //Space complexity: O(n)
	std::unordered_map<int, int> indices;  // val -> index

	for (int i = 0; i < nums.size(); i++)
	{
		indices[nums[i]] = i;
	}

	for (int i = 0; i < nums.size(); i++)
	{
		int diff = target - nums[i];
		if (indices.count(diff) && indices[diff] != i)
		{
			return { i, indices[diff] };
		}
	}

	return {};
}

std::vector<int> Hash_Map_One_Pass(std::vector<int>& nums, int target)         //Time complexity:  O(n)                                                       
{                                                                              //Space complexity: O(n)
	std::unordered_map<int, int> num_map;

	for (int i = 0; i < nums.size(); ++i)
	{
		int complement = target - nums[i];
		if (num_map.find(complement) != num_map.end())
		{
			return { num_map[complement],i };
		}
		num_map.insert({ nums[i], i });
	}
	return {};
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

	int target;
	std::cout << std::setw(10) << std::left << "Input: ";
	std::cin >> target;


	std::cout << "\n" << std::setw(40) << std::left << "Outnput with use Brute Force: ";
	for (int i : Brute_Force(nums, target))
	{
		std::cout << i << " ";
	}

	std::cout << "\n" << std::setw(40) << std::left << "Outnput with use Sorting: ";
	for (int i : Sorting(nums, target))
	{
		std::cout << i << " ";
	}

	std::cout << "\n" << std::setw(40) << std::left << "Outnput with use Hash Map Two Pass: ";
	for (int i : Hash_Map_Two_Pass(nums, target))
	{
		std::cout << i << " ";
	}

	std::cout << "\n" << std::setw(40) << std::left << "Outnput with use Hash Map One Pass: ";
	for (int i : Hash_Map_One_Pass(nums, target))
	{
		std::cout << i << " ";
	}
}