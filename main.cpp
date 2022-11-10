/*Jimmy Lieu
COSC 1336 001
10/26/2021
Purpose: To build a fraction calculator (Lab5L2)*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//function prototypes 
int getNumerator();
int getDenominator();
void calculateProduct(int num1, int den1, int num2, int den2);
int multiply(int n1, int n2);
void printDecimal(int dividend, int divisor);
void calculateQuoatient(int num1, int den1, int num2, int den2);
void calculateSum(int num1, int den1, int num2, int den2);
void calculateDifference(int num1, int den1, int num2, int den2);
void exitMessage();
int add(int addend, int addend2);

int main() {
	int response;
	printf("Please enter 1 for mutiply, 2 for divide, 3 for add, 4 for subtract, or 5 for exit: ");
	scanf("%d", &response);
	while (response != 5) {
		int num1 = getNumerator();
		int den1 = getDenominator();
		int num2 = getNumerator();
		int den2 = getDenominator();

		switch (response) {
		case 1:
			calculateProduct(num1, den1, num2, den2);
			break;
		case 2:
			calculateQuoatient(num1, den1, num2, den2);
			break;
		case 3: 
			calculateSum(num1, den1, num2, den2);
			break;
		case 4: 
			calculateDifference(num1, den1, num2, den2);
			break;
		case 5:
			break;
		default: printf("Please enter 1, 2, 3, 4, or 5!!!!!!!!!");
			break;
		} //end switch
		printf("Please enter 1 for mutiply, 2 for divide, 3 for add, 4 for subtract, or 5 for exit: ");
		scanf("%d", &response);
	}//end while
	exitMessage();
}//end main

int getNumerator() {
	int returnMe;
	printf("Please enter the numerator(any integer): ");
	scanf("%d", &returnMe);
	return returnMe;
}
int getDenominator() {
	int returnMe;
	do {
		printf("Please enter the denominator(positive integer only): ");
		scanf("%d", &returnMe);
	} while (returnMe <= 0);
	return returnMe;
}
void calculateProduct(int n1, int d1, int n2, int d2) {
	int numProduct = multiply(n1, n2);
	int denProduct = multiply(d1, d2);
	printf("%d/%d * %d/%d. The resulting fraction is %d/%d.\n", n1, d1, n2, d2, numProduct, denProduct);
	printDecimal(numProduct, denProduct);
}
int multiply(int n1, int n2) {
	int returnMe;
	returnMe = n1 * n2;
	return returnMe;
}
void printDecimal(int dividend, int divisor) {
	double decimalValue = (double) dividend / divisor;
	printf("The decimal version of %d/%d is %.2f.\n", dividend, divisor, decimalValue);
}
void calculateQuoatient(int n1, int d1, int n2, int d2) {
	int numQuotient = multiply(n1, d2);
	int denQuotient = multiply(d1, n2);
	printf("%d/%d / %d/%d. The resulting fraction is %d/%d.\n", n1, d1, n2, d2, numQuotient, denQuotient);
	printDecimal(numQuotient, denQuotient);
}
void calculateSum(int num1, int den1, int num2, int den2) {
	int numerator = add(multiply(num1, den2), multiply(num2, den1));
	int denominator = multiply(den1, den2);
	printf("%d/%d + %d/%d. The resulting fraction is %d/%d.\n", num1, den1, num2, den2, numerator, denominator);
	printDecimal(numerator, denominator);
}
void calculateDifference(int num1, int den1, int num2, int den2) {
	int numerator = add(multiply(num1, den2), -multiply(num2, den1));
	int denominator = multiply(den1, den2);
	printf("%d/%d - %d/%d. The resulting fraction is %d/%d.\n", num1, den1, num2, den2, numerator, denominator);
	printDecimal(numerator, denominator);
}
void exitMessage() {
	printf("Goodbye. ");
}
int add(int addend, int addend2) {
	int returnMe = 0;
	returnMe = addend + addend2;
	return returnMe;
}
