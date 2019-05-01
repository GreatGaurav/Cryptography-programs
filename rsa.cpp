#include<stdio.h>
long long int power(int a, int b, int c){
	long long t;
	if(b==1){
		return a;
	}
	t = power(a, b/2, c);
	if (b%2 == 0){
		return (t*t)%c;
	}
	else{
		return ((t*t)%c)*a%c;
	}
}
int main(void){
	int n , p , q, phin, d, e, x;
	long ct, pt;
	printf("Enter the value of p, q, e, pt");
	scanf("%d%d%d%d",&p,&q,&e,&pt);
	n = p*q;
	phin = (p-1)*(q-1);
	ct = power(pt, e, n);
	printf("\nEncrypted text is : %d",ct);
	printf("\n\n***DECRYPTING***");
	for (int i=1; i<phin; i++){
		if((phin*i + 1)%e ==0){
			x = i;
			break;
		}
	}
	d = (phin*x+1)/e;
	pt = power(ct, d, n);
	printf("\nthe decrypted text is : %d",pt);
	
}
