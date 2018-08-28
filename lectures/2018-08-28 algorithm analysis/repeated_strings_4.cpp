int main()
{
   string s;
   cin >> s;
   long n;
   cin >> n;

   long count_final = 0, int_temp, unused;
   long length = s.length();
   for (int w = 0; w < length; w++)

   {
      if (s[w] == 'a')

      {
         count_final++;
      }
   }

   int_temp = n / length;
   unused = n % length;
   count_final = int_temp * count_final;

   for (int w = 0; w < unused; w++)

   {
      if (s[w] = 'a')
      {
         count_final++;
      }
   }
   cout << count_final;
   return 0;
}