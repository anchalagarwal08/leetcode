/*345. Reverse Vowels of a String   */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* reverseVowels(char* s) {
    if(!s)
        return NULL;
    int len = strlen(s);
    if(len==1)
        return s;
    int i=0, j=len-1;
    while(i<j)
    {
        if((s[i]=='a' || s[i]=='e' ||s[i]=='i' || s[i]=='o'|| s[i]=='u'||s[i]=='A' || s[i]=='E' ||s[i]=='I' || s[i]=='O'|| s[i]=='U') && (s[j]=='a' || s[j]=='e' ||s[j]=='i' || s[j]=='o'|| s[j]=='u'|| s[j]=='A' || s[j]=='E' ||s[j]=='I' || s[j]=='O'|| s[j]=='U'))
        {
            char tmp = s[i];
            s[i] = s[j];
            s[j]=tmp;
            i++;
            j--;
        }
        else if((s[i]=='a' || s[i]=='e' ||s[i]=='i' || s[i]=='o'|| s[i]=='u'||s[i]=='A' || s[i]=='E' ||s[i]=='I' || s[i]=='O'|| s[i]=='U'))
            j--;
        else
            i++;
    }
    return s;
}
