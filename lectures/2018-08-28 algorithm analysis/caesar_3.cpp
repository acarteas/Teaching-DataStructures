string caesarCipher(string s, int k) {

    string result = ""; //shifted string to be returned
    //traverse string 
    //for uppercase
    for (int i(0); i < s.length(); i++)
    {
        //uppercase
        if (isupper(s[i]))
            result += char(int(s[i]+k-65)%26 + 65);
        //lowercase
        else if (islower(s[i]))
            result += char(int(s[i]+k-97)%26 + 97);
        //must not be letter (symbol or other)
        else 
            result += s[i];
    }
return result;
}