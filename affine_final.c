#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<string.h>
#define MAX_LIMIT_TEXT 100000

char *affine_encrypt(char *text,int a, int b)
{
    int i,n;
    n = strlen(text);
    char *affine_encrypt; char ch[2]; ch[1] = '\0';
    affine_encrypt = malloc(n*sizeof(char));

    for(i = 0 ; i<n; i++)
    {
        if(text[i] != ' ')
        {
        int res = (a * (((int)(text[i])) - 65) + b) % 26;
        ch[0] = (char)res+65;
        strcat(affine_encrypt,ch);
        }
        else
        {
            ch[0] = ' ';
            strcat(affine_encrypt,ch);
        }
    }
    return affine_encrypt;
}
void toLowerCase(char *plain, int ps) 
{ 
    int i; 
    for (i = 0; i < ps; i++) { 
        if (plain[i] > 64 && plain[i] < 91) 
            plain[i] += 32; 
    } 
} 
int modInverse(int a, int m) 
{ 
    a = a%m; 
    for (int x=1; x<m; x++) 
    {
       if ((a*x) % m == 1) 
          return x; 
    }
    return -1;
} 

char *affine_decrypt(char *text,int a, int b)
{
    int i,n;
    n = strlen(text);
    char *affine_decrypt; char ch[2]; ch[1] = '\0';
    affine_decrypt = malloc(n*sizeof(char));

    for(i = 0 ; i<n; i++)
    {
        if(text[i] != ' ')
        {
        int res = (modInverse(a,26) * (((int)(text[i]))) - b) % 26;
        ch[0] = (char)res+66;
        strcat(affine_decrypt,ch);
        }
        else
        {
            ch[0] = ' ';
            strcat(affine_decrypt,ch);
        }
    }
    return affine_decrypt;
}
int main(void)
{
    char *text,*key;
    struct timespec start, finish;
    int i = 0;
    while(i!=1)
    {
        // int i,j;
        int a = 17;
        int b = 20;
        text = (char*)malloc(MAX_LIMIT_TEXT*sizeof(char));
        fgets(text,MAX_LIMIT_TEXT,stdin);
        text[strcspn(text, "\n")] = 0;
		clock_gettime(CLOCK_REALTIME, &start);
        // strcpy(text,"this is the text to be encrypted");
        printf("%s\n",text); 
        char *res=affine_encrypt(text,a,b);
        printf("Encryption: %s\n",res);
        // toLowerCase(res, strlen(res));
        // printf("res %s\n", res);
        // printf("Decrypt: %s\n", affine_decrypt(res,a,b));
        clock_gettime(CLOCK_REALTIME, &finish); 
     	long seconds = finish.tv_sec - start.tv_sec; 
    	long ns = finish.tv_nsec - start.tv_nsec; 
    	//printf("total nanoseconds: %e\n", (double)ns); 

        i++;
    }

}
