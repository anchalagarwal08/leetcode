/*242. Valid Anagram:
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.*/

bool isAnagram(char* s, char* t) {
    int src[255]={0,};
    int dest[255]={0,};
    int p=0, q=0;
    if(s==NULL || t==NULL)
        return false;
    int src_len = strlen(s);
    int dest_len=strlen(t);
    if(src_len!=dest_len)
        return false;
    while(p<src_len && q<dest_len)
    {
        src[s[p]]++;
        dest[t[q]]++;
        p++;
        q++;
    }
    p=0;
    while(p<=255)
    {
       //printf("src=%d, dest=%d", src[p],dest[p]);
       if(src[p]!=dest[p])
         return false;
       p++;
    }
    return true;
    
}
