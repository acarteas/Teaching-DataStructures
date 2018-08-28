string caesarCipher(string s, int k) 
{
    if(k > 26)
    {
        k = k % 26;
    }
    string new_string;
    
    for(int i = 0 ; i < s.size();i++)
    {
        char ch = s[i];
        int new_addition = 0;
        
        if((ch >= 65 && ch <= 122)&&(ch >= 97 || ch <= 90))
        {
            if(ch >= 97 && ch <= 122)
            {
                ch = ch + k;
                if(ch > 122)
                {
                    new_addition = (ch - 97) % 26;
                    ch = 97 + new_addition;
                    new_string.push_back(ch);
                }
                else
                {
                    new_string.push_back(ch);
                }
            }
           if(ch >= 65 && ch <= 90)
            {
                ch = ch + k;
                if(ch > 90)
                {
                    new_addition = (ch - 65) % 26;
                    ch = 64 + new_addition;
                    new_string.push_back(ch);
                }
                else
                {
                    new_string.push_back(ch);
                }
           }
        }
    else{
        new_string.push_back(ch);
        }
    }
    
    return new_string;
}
