#include <assert.h>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution1
{
  public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		const int n = nums.size();
		assert(n > 0);
		unordered_map<int, int> rec;
		for (auto i = 0; i < n; i++)
		{
			auto compensate = target - nums[i];
			if (rec.find(compensate) != rec.end())
			{
				return {rec[compensate], i};
			}
			rec[nums[i]] = i;
		}
		return {-1, -1};
	}
};