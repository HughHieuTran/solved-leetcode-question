class Solution
{
    public static void Main(string[] args)
    {
        int[] nums = { 0, 1, 2, 2, 4 };
        Console.WriteLine(ContainsDuplicate(nums));

    }
    public static bool ContainsDuplicate(int[] nums)
    {
        int[] storednums = new int[nums.Length];
        for (int i = 0; i < nums.Length; i++)
        {
            if (storednums.Contains(nums[i])) return false;
            else storednums[i] = nums[i];
        }
        return true;
    }
}