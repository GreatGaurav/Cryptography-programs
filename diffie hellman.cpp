#include<stdio.h>

long long int power(int a, int b, int c){
	long long int t;
	if (b==1){
		return a;
	}
	t = power(a, b/2, c);
	if(b%2 == 0){
		return (t*t)%c;
	}
	else{
		return ((t*t)%c)*a%c;
	}
}
int main(void){
	int A, B, Ak, Bk;
	int a, b, p, q, n;
	printf("Enter the value of p, q, a, b: ");
	scanf("%d%d%d%d",&p,&q,&a,&b);
	A = power(q, a, p);
	B = power(q, b, p);
	Ak = power(B, a, p);
	Bk = power(A, b, p);
	printf("\n\nAK = %d\nBK = %d",Ak,Bk);
}
