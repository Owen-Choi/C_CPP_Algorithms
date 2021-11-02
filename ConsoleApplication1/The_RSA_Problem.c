#include<stdio.h>

// return GCD value ::
int Euclid(int a, int b);
// find d value to calculate M ::
int find_D();
// calculate M value with e,d,n ::
int squaring(int d);

// public key ::
int n, e;
// Cipher value ::
int C;
// Euler's totient ::
int ET;
int main() {
	printf("Please enter the public key values :: \n");
	printf("Please enter n : ");
	scanf("%d", &n);
	printf("Please enter e : ");
	scanf("%d", &e);
	printf("Please enter the Cipher value :: \n");
	printf("Please enter C : ");
	scanf("%d", &C);

	printf("M value is %d", squaring(find_D()));
	return 0;
}
// we can get the GCD value with recursively defined function ::
int Euclid(int a, int b) {
	if (b == 0)
		return a;
	else
		return Euclid(b, a % b);
}
// :: for calculating d value with following steps 
// calculate Euler's totient by using Euclid 
// find d value by brute-force algoritm, with pi(n) ::
int find_D() {
	int count = 0;
	int d = -1;
	for (int i = 1; i < n; i++) {
		if (Euclid(i, n) == 1)
			count++;
	}
	ET = count;
	for (int i = 0; i < ET; i++) {
		if ((e * i) % ET == 1) {
			d = i;
			break;
		}
	}
	return d;
}
// :: we can use repeated squaring algorithm to get M value
// which can be calculated by C^e mod n ::
int squaring(int d) {
	int iter = d;
	int base = C;
	int result = 1;
	while (d > 0) {
		while (d % 2 == 0) {
			d /= 2;
			base = (base * base) % n;
		}
		d--;
		result = (result * base) % n;
	}
	return result;
}