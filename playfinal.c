#include<stdio.h>
#include <stdlib.h>
#include <string.h>
char matrix[5][5];
void toLowerCase(char *plain, int ps) 
{ 
    int i; 
    for (i = 0; i < ps; i++) { 
        if (plain[i] > 64 && plain[i] < 91) 
            plain[i] += 32; 
    } 
} 
  
// Function to remove all spaces in a string 
void removeSpaces(char* plain, int ps) 
{ 
    int i, count = 0; 
    for (i = 0; i < ps; i++) 
        if (plain[i] != ' ') 
            plain[count++] = plain[i]; 
    plain[count] = '\0'; 
} 

void createMatrix(char k[]) {

    int i=0,j=0,len,x=-1;
    int last_i,last_j,temp,xy,yz;
    len=strlen(k);
    int arr[26]={0}; //used as hash map
    arr[9]=1;
    while(len--) {
        x++;
        if(j<=4) { //filling all columns of each row first
            if(arr[k[x]-97]==0) { //if 0 then hasnt been used in matrix
                matrix[i][j]=k[x]; 
                last_i=i; //used to check if i anf j have crossed 5 rows and columns
                last_j=j;
                j++;
                arr[k[x]-97]++;
            }
        }
        else {
            j=0;
            i++;
            if(arr[k[x]-97]==0) {
                matrix[i][j]=k[x];
                last_i=i;
                last_j=j;
                j++;
                arr[k[x]-97]++;
            }
        }
    }
    if(last_j>=4) {
        last_i++;
        last_j=0;
    }
    else {
        last_j++;
    }
    for(temp=0;temp<26;temp++) { //iterating through rest of alphabets
        if(arr[temp]==0) {
            if(last_j<=4) {
                matrix[last_i][last_j]=temp+97;
                last_j++;
            }
            else  {
                last_j=0;
                last_i++;
                matrix[last_i][last_j]=temp+97;
                last_j++;
            }
        }
    }
}
void decrypt(char matrix[5][5], char*plaintext)
{
    int first=strlen(plaintext);
  char final[strlen(plaintext)];
  int len_new=0;
  int ct=0;
  int r1,r2,c1,c2;
  while(ct<strlen(plaintext)-1)
  {

//printf("%c %c becomes ", plaintext[ct], plaintext[ct+1]);
       if (plaintext[ct] == 'j') 
        plaintext[ct] = 'i'; 
    else if (plaintext[ct+1] == 'j') 
        plaintext[ct+1] = 'i'; 
  
    for (int i = 0; i < 5; i++) { 
  
        for (int j = 0; j < 5; j++) { 
  
            if (matrix[i][j] == plaintext[ct]) { 
                r1 = i; 
                c1 = j; 
            } 
            else if (matrix[i][j] == plaintext[ct+1]) { 
                r2 = i; 
                c2 = j; 
            } 
        } 
    } 
    //printf("%d, %d, %d, %d\n", r1,c1,r2,c2); //prints all the coordinates
    if(r1!=r2 && c1!=c2) {
            int col_diff=abs(c1-c2);
            if(c1<c2) {
                c1+=col_diff;
                c2-=col_diff;
            }
            else {
                c1-=col_diff;
                c2+=col_diff;
            }
            //printf("%c %c\n",matrix[r1][c1],matrix[r2][c2]);
            final[len_new++]=matrix[r1][c1];
            final[len_new++]=matrix[r2][c2];
            //printf("%c %c\n",matrix[r1][c2],matrix[r2][c1]);
        }
        else if(r1==r2) {
            c1--;
            c1%=5;
            c2--;
            c2%=5;
            //printf("%c %c \n",matrix[r1][c1],matrix[r2][c2]);
            final[len_new++]=matrix[r1][c1];
            final[len_new++]=matrix[r2][c2];
        }
        else {
            r1--;
            r1%=5;
            r2--;
            r2%=5;
            //printf("%c %c \n",matrix[r1][c1],matrix[r2][c2]);
            final[len_new++]=matrix[r1][c1];
            final[len_new++]=matrix[r2][c2];
        }
      
  ct+=2;
  }
  for(int i=0; i<first;i++)
  {
      printf("%c", final[i]);
  }
  printf("\n");
    
    //printf("Decrypted %s\n", final);

}
void  encrypt(char matrix[5][5],char *plaintext)
{
    int len=strlen(plaintext);
    char final[len];
    int len_new=0;
  //printf("%s\n", plaintext);
      for(int i=0; i<5; i++)
    {
      for (int j=0; j<5; j++)
      {
        printf("%c ", matrix[i][j]);
      }
      printf("\n");
    }
    
    if (len % 2 != 0) { 
        plaintext[len++] = 'z'; 
        plaintext[len] = '\0'; 
    } 
  
  int ct=0;
  int r1,r2,c1,c2;
  while(ct<strlen(plaintext)-1)
  {

printf("%c %c becomes ", plaintext[ct], plaintext[ct+1]);
       if (plaintext[ct] == 'j') 
        plaintext[ct] = 'i'; 
    else if (plaintext[ct+1] == 'j') 
        plaintext[ct+1] = 'i'; 
  
    for (int i = 0; i < 5; i++) { 
  
        for (int j = 0; j < 5; j++) { 
  
            if (matrix[i][j] == plaintext[ct]) { 
                r1 = i; 
                c1 = j; 
            } 
            else if (matrix[i][j] == plaintext[ct+1]) { 
                r2 = i; 
                c2 = j; 
            } 
        } 
    } 
    //printf("%d, %d, %d, %d\n", r1,c1,r2,c2); //prints all the coordinates
    if(r1!=r2 && c1!=c2) {
            int col_diff=abs(c1-c2);
            if(c1<c2) {
                c1+=col_diff;
                c2-=col_diff;
            }
            else {
                c1-=col_diff;
                c2+=col_diff;
            }
            printf("%c %c\n",matrix[r1][c1],matrix[r2][c2]);
            final[len_new++]=matrix[r1][c1];
            final[len_new++]=matrix[r2][c2];
            //printf("%c %c\n",matrix[r1][c2],matrix[r2][c1]);
        }
        else if(r1==r2) {
            c1++;
            c1%=5;
            c2++;
            c2%=5;
            printf("%c %c \n",matrix[r1][c1],matrix[r2][c2]);
            final[len_new++]=matrix[r1][c1];
            final[len_new++]=matrix[r2][c2];
        }
        else {
            r1++;
            r1%=5;
            r2++;
            r2%=5;
            printf("%c %c \n",matrix[r1][c1],matrix[r2][c2]);
            final[len_new++]=matrix[r1][c1];
            final[len_new++]=matrix[r2][c2];
        }
      
  ct+=2;
  }
  char new[len];
  for(int i=0; i<len; i++)
  {
     new[i]=final[i];
  }
  printf("Encrypted Text is: %s\n", new);
  printf("\n");
  decrypt(matrix,new);

}

int main()
{

  char key[100];
  strcpy(key,"attack");
  printf("The key is: %s\n", key);
  createMatrix(key); //enter any key
  char plaintext[100000];
  // strcpy(plaintext,"This is the plaintext");
  scanf("%[^\n]s", plaintext);
  printf("%s\n", plaintext);
  removeSpaces(plaintext, strlen(plaintext));
  toLowerCase(plaintext, strlen(plaintext));
  encrypt(matrix, plaintext);
  return 0;
}



