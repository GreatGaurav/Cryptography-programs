#include<stdio.h>
#include<string.h>
int main(){
	char text[] = "abcdefghijklmnopqrstuvwxyz";
	char cipr[] = "zyxwvutsrqponmlkjihgfedcba";
	char pt[] = "hello";
	int i ,j;
	for (i=0;i<strlen(pt);i++){
		for (j=0;j<26;j++){
			if (pt[i]==text[j]){
				printf("%c",cipr[j]);
			}
		}
		
	}
}
