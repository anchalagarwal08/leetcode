/*URL shortner. Idea is to encode the a unique id to the base 64 (26 upper case+26 lower case+10 numbers+2 special char (- .)*/
//Shorturl can be of the form uid->some string as encoded below or uid->domainname/somestring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//This API will encode unique id to short url. Each long url will have this unique UID attached to it
char *idToURL(long int id)
{
    char map[] = "abcdefghijklmnopqrstuvwxyzABCDEF"
                       "GHIJKLMNOPQRSTUVWXYZ0123456789-.";

    char url[100];
    int i=0;
    while(id>0)
    {
      url[i++]=map[id%62];
      id=id/62;
    }
    char *str = (char*)malloc(sizeof(char)*i);
      printf("\n url=%s\n",url);
    strncpy(str, url,i);
    str[i]='\0';
    return str;
}

//This API converts back the shorturl to UID.
long int urlToID(char *shorturl)
{
  if(shorturl==NULL)
    return 0;
  int i=0, len=strlen(shorturl);
  long int id=0;
  for(i=0;i<len;i++)
  {
    if(shorturl[i] >='a' && shorturl[i] <='z')
      id= id*64 - 'a';
    if(shorturl[i] >='A' && shorturl[i] <='Z')
            id= id*64 - 'A' + 26;
    if(shorturl[i] >='0' && shorturl[i] <='9')
            id= id*64 - '0'+ 52;
    if(shorturl[i] == '.' || shorturl[i] =='-')
            id= id*64 - 'a'+ 62;
  }
  return id;
}
int main()
{
  long int n = 12345;
  char *shorturl = idToURL(n);
  printf("Generated short url is:%s\n",shorturl);
  printf("Id from url is %ld\n",urlToID(shorturl));
  return 0;
}
