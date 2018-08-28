// Complete the caesarCipher function below.
string caesarCipher(string s, int k) {

    for(int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 65 && s[i] <= 90) 
        {
            s[i] = s[i] + k;
            if (s[i] > 90)
            {
                s[i] = s[i] - 26;
            }
        }
        else if (s[i] >= 97 && s[i] <= 122)
        {
            s[i] = s[i] + k;
            if (s[i] > 122)
            {
                s[i] = s[i] - 26;
            }
        }
    }
    return s;

}