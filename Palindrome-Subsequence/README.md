给定字符串，求它的回文子序列个数。

回文子序列反转字符顺序后仍然与原序列相同。例如字符串aba中，回文子序列为"a", "a", "aa", "b", "aba"，共5个。
内容相同位置不同的子序列算不同的子序列。

Figure out the amount of palindrome sub-sequences of a given string. In the case of string "aba", its palindrome sub-sequences are "a","a","aa","b" and "aba".
If two sub-sequences have the same content but are at different positions, they are regarded as different sub-sequences.



输入

第一行一个整数T，表示数据组数。之后是T组数据，每组数据为一行字符串。


输出

对于每组数据输出一行，格式为"Case #X: Y"，X代表数据编号（从1开始），Y为答案。答案对100007取模。
