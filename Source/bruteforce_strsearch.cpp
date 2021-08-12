# include <string>
# include <conio>
# include <stdio>

int xstrsearch(char *,char *);

void main()
{
	char s1[] = "Pussycat dolls";
   char s2[] = "dolls";
   int pos;

   printf("\n%s",s1);
   printf("\n%s",s2);

   pos = xstrsearch(s1,s2);

   printf("\nfound at %d",pos);
   printf("\nasd\n");
   for(int m=pos;m<(pos+5);m++)
   	printf("%c",s1[m]);
   getch();
}

int xstrsearch(char *s1,char *s2)
{
  int i,j,k;
  int l1 =  strlen(s1);
  int l2 =  strlen(s2);

  for(i=0;i<=l1-l2;i++)
  {
  	j = 0;
   k = i;
   while((s1[k] == s2[j])&&(j<l2))
   	{	k++; j++;}
   if(j==l2) return i;
  }
  return -1;
}
