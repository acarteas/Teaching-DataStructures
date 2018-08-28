string hackerrankInString(string s)
{
	string target = "hackerrank";
	int j = 0; // number of matching characters between target and s
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == target[j])
			j++;
	}
	if (j == target.length()) // if all characters in target appear in s
		return "YES";
	else
		return "NO";
}