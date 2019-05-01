#include<stdio.h>
#include<string.h>
void rail(char pt[20], int key){
	int l = strlen(pt);
	char mat[key][l];
	int i, j , k=-1, col, row;
	
	for(i=0;i<key;i++)
		for(j=0;j<l;j++)
			mat[i][j] = '\n';
			
	row = 0;
	col = 0;
	
	for(i=0;i<l;i++){
		mat[row][col++] = pt[i];
		if(row==0 || row==key-1){
			k = k*(-1);
		}
		row = row + k;
	}
	
	printf("\n\n****printging*****\n\n");
	for(i=0;i<key;i++){
		for(j=0;j<l;j++){
			if(mat[i][j] != '\n')
				printf("%c",mat[i][j]);
		}
	}
	
}
int main(void){
	int key;
	char pt[20];
	printf("Enter plain txt: ");
	gets(pt);
	printf("Enter key: ");
	scanf("%d",&key);
	
	rail(pt, key);
}
