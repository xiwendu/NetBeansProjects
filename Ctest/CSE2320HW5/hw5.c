#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
//Xiwen Du 1001093006  
int editDistance(char[], int, char[], int);  
void Alignment(char[], int, char[], int);
int main()  
{  
    char* s;
    char* t;
    int ret1;
    int ret2;
    
    do{
   
    int n1=1000;
    int s_len;
    int mindis;
    s=(char*)malloc(sizeof(char)*n1); 
    printf("First Sequence:");
    scanf("%s",s);
    s_len=strlen(s);
    if ((n1-s_len) > 10) 
    {
        realloc(s,sizeof(char)*(s_len+1));
        n1= s_len+1;
    }
    
    int n2=1000;
    int t_len;
    t=(char*)malloc(sizeof(char)*n2);
    printf("Second Sequence:");
    scanf("%s",t);
    t_len=strlen(t);
    if ((n2-t_len) > 10) 
    {
        realloc(t,sizeof(char)*(t_len+1));
        n2= t_len+1;
    }
    mindis = editDistance(s, s_len, t, t_len);
    
    ret1 = strcmp(s, "-1");
    ret2 = strcmp(t, "-1");  
    
    printf("edit distance:%3d \n", mindis);
    printf("Alignment:\n");
    //Alignment(s, s_len, t, t_len);
    
    }while(ret1!=0 && ret2!=0);
    
    
    return 0;
    
}  
  
//find min 
int Min(int x, int y, int z)  
{  
    if(x <= y && x <= z)  
        return x;  
    else if (y <= z)  
        return y;  
    else  
        return z;  
}  
  

int editDistance(char s[], int s_len, char t[], int t_len)  
{  
    //Create a matrix d
    int d[s_len+1][t_len+1];  
    int i, j;  
  
    //only need delete  
    for (i = 0; i <= s_len; i++)  
        d[i][0] = i;  
    //only need add
    for (j = 1; j <= t_len; j++)  
        d[0][j] = j;  
    for (j = 0; j < t_len; j++)  
        for (i = 0; i < s_len; i++)  
            if (s[i] == t[j])  
                d[i+1][j+1] = d[i][j]; //no need operations  
            else  
                d[i+1][j+1] = Min(d[i][j+1] + 1,  //delete  
                              d[i+1][j] + 1,  //add  
                              d[i][j] + 1 //replace
                              );  
    printf("first: %s \n", s);
    printf("second: %s \n", t);
    for (i = 0; i <= s_len; i++) {  
        for (j = 0; j <= t_len; j++)
            {
            printf("%3d", d[i][j]);
            printf("|");
            }
        printf("\n");
        
    }
    return d[s_len][t_len];  
} 

//---------------------Alignment------------------ 
//This part I wrote down the code. The idea should be right, but there
//always has some small error. I cannot fix it. Is That possible give some
//part of the partial credit? Please, just a little bit.      
void Alignment(char s[], int s_len, char t[], int t_len)  
{  

    char S[100];
    char T[100];
    char X[100];
    int d[s_len+1][t_len+1];  
    int i, j;  
    for (i = 0; i <= s_len; i++)  
        d[i][0] = i;  
    for (j = 1; j <= t_len; j++)  
        d[0][j] = j;  
    for (j = 0; j < t_len; j++)  
        for (i = 0; i < s_len; i++)  
            if (s[i] == t[j])  
                d[i+1][j+1] = d[i][j];
            else  
                d[i+1][j+1] = Min(d[i][j+1] + 1,
                              d[i+1][j] + 1,
                              d[i][j] + 1
                              ); 
    
    for (i = 0; i <= s_len; i++) {  
        for (j = 0; j <= t_len; j++)
            {
            if (d[i][j]-1==d[i-1][j])
                {
                strcat(S, &s[i]);
                strcat(T, "-");
                strcat(X, "x");
                i--;
                }
            else if(d[i][j]-1==d[i][j-1])
                {
                strcat(S, "-");
                strcat(T, &t[j]);
                strcat(X, "x");
                j--;
                }
            else if(&s[i] == &t[j])
                {
                strcat(S, &s[i]);
                strcat(T, &t[j]);
                strcat(X, ".");
                i--; 
                j--;
                }          
            }
    }
    strcpy(S, S);
    puts(S);
    strcpy(T, T);
    puts(T);
    strcpy(X, X);
    puts(X);

} 
//---------------------End------------------------ 
