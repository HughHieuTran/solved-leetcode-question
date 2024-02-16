using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AppCS {
    internal static class ArrayAndHashing {

        public static void Run() {
            string[] test = { "bdddddddddd", "bbbbbbbbbbc", "tan", "ate", "nat", "bat" };
            Console.WriteLine(GroupAnagrams(test));
        }

        public static IList<IList<string>> GroupAnagrams(string[] strs) {
            var groups = new Dictionary<string, IList<string>>();

            foreach (string s in strs) {
                char[] hash = new char[26];
                foreach (char c in s) {
                    
                }

                string key = new string(hash);
                if (!groups.ContainsKey(key)) {
                    groups[key] = new List<string>();
                }
                groups[key].Add(s);
            }
            return groups.Values.ToList();
        }

        public static int[] TwoSum(int[] nums, int target) {
            Dictionary<int, int> dic = new Dictionary<int, int>();
            for (int i = 0; i < nums.Length; i++) {
                if (dic.ContainsKey(target - nums[i])) return new int[] { dic[target - nums[i]], i };
                dic[nums[i]] = i;
            }
            return new int[] { -1, -1 };
        }
        public static bool IsAnagram2(string s, string t) {
            if (s.Length != t.Length) return false;

            int[] store = new int[26];

            for (int i = 0; i < s.Length; i++) {
                store[s[i] - 'a']++;
                store[t[i] - 'a']--;
            }

            foreach (int i in store) {
                if (i != 0) return false;
            }
            return true;
        }
        public static bool IsAnagram(string s, string t) {
            if (s.Length != t.Length) return false;
            Dictionary<char, int> checkDict = new Dictionary<char, int>();

            for (int i = 0; i < s.Length; i++) {
                if (checkDict.ContainsKey(s[i])) checkDict[s[i]]++;
                else checkDict[s[i]] = 1;

                if (checkDict.ContainsKey(t[i])) checkDict[t[i]]--;
                else checkDict[t[i]] = -1;
            }

            foreach (char c in checkDict.Keys) {
                if (checkDict[c] != 0) return false;
            }
            return true;
        }


        public static bool ContainsDuplicate(int[] nums) {
            int[] checkArr = new int[nums.Length];
            for (int i = 0; i < nums.Length; i++) {
                if (checkArr.Contains(nums[i])) return true;
                checkArr[i] = nums[i];
            }
            return false;

            //int[] nums = { 1, 2, 3, 4, 5, 5 };
            //Console.WriteLine(ArrayAndHashing.ContainsDuplicate(nums));
        }

    }
}
