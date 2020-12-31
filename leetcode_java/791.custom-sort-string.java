import java.util.Comparator;
import java.util.Arrays;

/*
 * @lc app=leetcode id=791 lang=java
 *
 * [791] Custom Sort String
 *
 * https://leetcode.com/problems/custom-sort-string/description/
 *
 * algorithms
 * Medium (65.84%)
 * Total Accepted:    80.4K
 * Total Submissions: 122.2K
 * Testcase Example:  '"cba"\n"abcd"'
 *
 * S and T are strings composed of lowercase letters. In S, no letter occurs
 * more than once.
 *
 * S was sorted in some custom order previously. We want to permute the
 * characters of T so that they match the order that S was sorted. More
 * specifically, if x occurs before y in S, then x should occur before y in the
 * returned string.
 *
 * Return any permutation of T (as a string) that satisfies this property.
 *
 *
 * Example :
 * Input:
 * S = "cba"
 * T = "abcd"
 * Output: "cbad"
 * Explanation:
 * "a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b",
 * and "a".
 * Since "d" does not appear in S, it can be at any position in T. "dcba",
 * "cdba", "cbda" are also valid outputs.
 *
 *
 *
 *
 * Note:
 *
 *
 * S has length at most 26, and no character is repeated in S.
 * T has length at most 200.
 * S and T consist of lowercase letters only.
 *
 *
 */
class Solution791 {
    class SortByS implements Comparator<Character> {
        int[] weights = new int[26];

        SortByS(String S) {
            for (int i = 0; i < S.length(); i++) {
                weights[getIndex(S.charAt(i))] = i;
            }
        }

        @Override
        public int compare(Character c1, Character c2) {
            return weights[getIndex(c1)] - weights[getIndex(c2)];
        }

        private int getIndex(char a) {
            return a - 'a';
        }
    }


    public String customSortString(String S, String T) {
        // step 1: construct an array of 26 items. Each store the order in S. O(S) <= O(26) = constant
        // step 2: sort T based on the comparator returned in step 1. O(TlogT)
        Character[] chars = new Character[T.length()];
        for (int i = 0; i < T.length(); i++) {
            chars[i] = T.charAt(i);
        }
        Arrays.sort(chars, new SortByS(S));
        StringBuilder sb = new StringBuilder();
        for (char c: chars) {
            sb.append(c);
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        Solution791 s = new Solution791();
        System.out.println(s.customSortString("cba", "abcd"));
    }
}
