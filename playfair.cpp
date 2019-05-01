#include<stdio.h> 
#include<conio.h> 
#include<string.h> 
#include<ctype.h> 
#define MX 5  

void playfair(char ch1, char ch2, char key[MX][MX]) 
{  
    int i, j, w, x, y, z;  
    
    for(i = 0; i < MX; i++) 
    {  
        for(j = 0; j < MX; j++) 
        {  
            if(ch1 == key[i][j]) 
            {  
                w = i;  
                x = j;  
            }
            else if(ch2 == key[i][j]) 
            {  
                y = i;  
                z = j;  
            }  
        }  
    }  
    if(w == y) 
    {  
        x = (x + 1) % 5;  
        z = (z + 1) % 5;  
        printf("%c%c", key[w][x], key[y][z]);     
    } 
    else if(x == z)
    {  
        w = (w + 1) % 5;  
        y = (y + 1) % 5;  
        printf("%c%c", key[w][x], key[y][z]);      
    } 
    else 
        printf("%c%c", key[w][z], key[y][x]);        
}  
int main(void) 
{  
    int i, j, k = 0, l, m = 0, n;  
    char key[MX][MX], keyminus[25], keystr[10], str[25], temp1, temp2, temp3;  
    char alpa[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};  
    printf("Enter key:\t");  
    scanf("%s", keystr);  
    printf("Enter the plain text:\t");  
    scanf("%s", str);  
    n = strlen(keystr);  
    //convert the characters to uppertext  
    for (i = 0; i < n; i++) 
    {  
        keystr[i] = toupper(keystr[i]);
        if(keystr[i] == 'J') 
            keystr[i] = 'I';  
    }  
    for(i = 0; i < n; i++)
    {
        temp1 = keystr[i];
        for(j = i + 1; j < n; j++)
            if(keystr[j] == temp1)
                for(k = j; k < n; k++)
                    keystr[k] = keystr[k+1];
    }
    n = strlen(keystr);
    //convert all the characters of plaintext to uppertext  
    for (i = 0; i < strlen(str); i++) 
    {  
        str[i] = toupper(str[i]);
        if(str[i] == 'J') 
            str[i] = 'I';            
    }  
    // store all characters except key  
    j = 0;  
    for(i = 0; i < 26; i++) 
    {  
        for(k = 0; k < n; k++) 
            if((keystr[k] == alpa[i]) || (alpa[i] == 'J')) 
                break;  
        if(k == n) 
            keyminus[j++] = alpa[i];  
    }  
    //construct key keymatrix  
    k = 0;  
    for(i = 0; i < MX; i++) 
    {  
        for(j = 0; j < MX; j++) 
        {  
            if(k < n) 
                key[i][j] = keystr[k++];  
            else 
                key[i][j] = keyminus[m++];  
            printf("%c ", key[i][j]);  
        }  
        printf("\n");  
    }  
    // construct diagram and convert to cipher text  
    printf("\n\nEntered text :%s\nCipher Text :", str);  
    for (i = 0; i < strlen(str); i++) 
    {  
        if (str[i + 1] == '\0') 
            playfair(str[i], 'X', key);  
        else 
        {  
            if (str[i] == str[i + 1]) 
                playfair(str[i], 'X', key);  
            else 
            {  
                playfair(str[i], str[i + 1], key);  
                i++;  
            }  
        }  
    }  
}
