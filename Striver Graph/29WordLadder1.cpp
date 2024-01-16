/*Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest transformation sequence from startWord to targetWord.
Keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList
The second part of this problem can be found here.

Note: If no possible way to transform sequence from startWord to targetWord return 0


Example 1:

Input:
wordList = {"des","der","dfr","dgt","dfs"}
startWord = "der", targetWord= "dfs",
Output:
3
Explanation:
The length of the smallest transformation
sequence from "der" to "dfs" is 3
i,e "der" -> "dfr" -> "dfs".
Example 2:

Input:
wordList = {"geek", "gefk"}
startWord = "gedk", targetWord= "geek",
Output:
2
Explanation:
gedk -> geek
Example 3:

Input:
wordList = {"poon", "plee", "same", "poie","plea","plie","poin"}
startWord = "toon", targetWord= "plea",
Output: 7
Explanation:
toon -> poon -> poin -> poie -> plie -> plee -> plea


Your Task:
You don't need to read or print anything, Your task is to complete the function wordLadderLength() which takes startWord, targetWord and wordList as input parameter and returns the length of the shortest transformation sequence from startWord to targetWord. If not possible return 0.


Expected Time Compelxity: O(N2 * M)
Expected Auxiliary Space: O(N * M) where N = length of wordList and M = |wordListi|


Constraints:
1 ≤ N ≤ 100
1 ≤ M ≤ 10
*/

#include <bits/stdc++.h>
using namespace std;

int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
{
  // Code here
  queue<pair<string, int>> q;
  set<string> st(wordList.begin(), wordList.end());
  q.push({startWord, 1});
  st.erase(startWord);
  while (!q.empty())
  {
    string s = q.front().first;
    int val = q.front().second;
    q.pop();
    if (s == targetWord)
    {
      return val;
    }

    for (int i = 0; i < s.length(); i++)
    {
      char originalWord = s[i];
      for (char ch = 'a'; ch <= 'z'; ch++)
      {
        s[i] = ch;
        if (st.find(s) != st.end())
        {
          q.push({s, val + 1});
          st.erase(s);
        }
      }
      s[i] = originalWord;
    }
  }

  return 0;
}

//{ Driver Code Starts.
int main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {
    int n;
    cin >> n;
    vector<string> wordList(n);
    for (int i = 0; i < n; i++)
      cin >> wordList[i];
    string startWord, targetWord;
    cin >> startWord >> targetWord;

    int ans = wordLadderLength(startWord, targetWord, wordList);
    cout << ans << "\n";
  }
  return 0;
}