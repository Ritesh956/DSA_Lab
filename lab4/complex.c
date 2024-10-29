#include<stdio.h>

typedef struct{
	double real;
	double imag;
}complex;

complex add(complex c1,complex c2){
	complex c3;
	c3.real=c1.real+c2.real;
	c3.imag=c1.imag+c2.imag;
	return c3;
}

complex subtract(complex c1,complex c2){
	complex c3;
	if(c1.real>c2.real){
		c3.real=c1.real-c2.real;
		c3.imag=c1.imag-c2.imag;
	}
	else{
		c3.real=c2.real-c1.real;
		c3.imag=c2.imag-c1.imag;
	}
	return c3;
}

complex mult(complex c1,complex c2){
	complex c3;
	c3.real=(c1.real*c2.real)-(c1.imag*c2.imag);
	c3.imag=(c2.real*c1.imag)+(c2.imag*c1.real);
	return c3;
}

int main(){
	complex c1;
	complex c2;
	complex c3;

	printf("Enter real part of complex 1: ");
	scanf("%lf",&c1.real);
	printf("Enter the imaginary part of complex 1: ");
	scanf("%lf",&c1.imag);
	printf("Enter the real part of complex 2: ");
	scanf("%lf",&c2.real);
	printf("Enter the imaginary part of complex 2: ");
	scanf("%lf",&c2.imag);

	c3=add(c1,c2);
	printf("The addition results in : %lf + %lfi",c3.real,c3.imag);

	c3=subtract(c1,c2);
	printf("\nThe subtraction results in : %lf - %lfi",c3.real,c3.imag);

	c3=mult(c1,c2);
	printf("\nThe multiplication results in : %lf * %lfi",c3.real,c3.imag);

	return 0;
}

