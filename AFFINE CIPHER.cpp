#include<stdio.h>
#include<string.h>
int main()
{
	int ch,a1,b1,a,b,c,d,d1[15],h,n,i=0;
	char str1[80],ek[80];
	printf("Enter the text \n");
	gets(str1);
  	do
	{
	printf("Enter the key \na:");
	scanf("%d",&a);
	printf("\nb:");
	scanf("%d",&b);
	a1=a;
	b1=b;
	b=26;
	d=1;
	while(d!=0)
	{
		
		
			c=a/b;
			
			d=a%b;
			d1[i]=d;
			a=b;
			b=d;
		i=i++;
		
		

	}
	
	n=i-1;

	
	
	

			if(d1[n-1]==1)
			{
				printf("\nOi ariumoi einai prvtoi metaji tous\n\n");
				ch=1;

			}
			else 
			{
				printf("\nOi ariumoi den einai prvtoi metaji tous\n\n");
				ch=0;
			}
	}
	while(ch==0);
			a=a1;
			b=b1;
			printf("\nTo kleidi einai (%d,%d):\n",a,b);

			printf("\nTo keimeno einai %s  to mikos toy %d	\n",str1,strlen(str1));
			n=strlen(str1);
		
			ek[n]='\0';
			h=strlen(ek);
			for (i=0; i<h; i++)
			{
				str1[i]=str1[i]-97;
				ek[i]=((a*str1[i]+b)%26)+97;
				printf("%c -> %d to \n",str1[i]+97,str1[i]);
			}
			
			printf("\n\nTo kriptografhmeno keimeno einai:%s \n",ek);
			for (i=0; i<h; i++)
			{
				printf("%c -> %d \n",ek[i],ek[i]-97);
			}
			printf("To kriptografhmeno keimeno einai:%s \n\n",ek);
			
}
