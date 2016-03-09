#include <stdio.h>

typedef struct{
	int num;
	int den;
} Fraction;

static int gcd(int a, int b) {
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

Fraction MakeFraction(int n, int d){
	Fraction f = {0, 1};
	if(n == 0){
		return f;
	}
	if(d < 0){
		n = -n;
		d = -d;
	}
	int g = gcd(n,d);
	if(g != 1){
		n /= g;
		d /= g;
	}

	f.num = n;
	f.den = d;
	return f;
}

void comparefrac(Fraction f1, Fraction f2){
	if((f1.num == f2.num) && (f1.den == f2.den)){
		printf("%d/%d = %d/%d\n", f1.num, f1.den, f2.num, f2.den);
	}
	float num1 = f1.num + 0.0;
	float den1 = f1.den + 0.0;
	float num2 = f2.num + 0.0;
	float den2 = f2.den + 0.0;
	float val1 = num1/den1;
	float val2 = num2/den2;
	if(val1 > val2){
		printf("%d/%d > %d/%d\n", f1.num, f1.den, f2.num, f2.den);
	}else{
		printf("%d/%d < %d/%d\n", f1.num, f1.den, f2.num, f2.den);
	}
}

int main(){
	Fraction f1;
	f1 = MakeFraction(6, 9);
	Fraction f2;
	f2 = MakeFraction(4, 8);
	comparefrac(f1, f2);
}
	









