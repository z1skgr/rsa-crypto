/*
            ======================================================
            + Name        : bn_sample4_2.c                       +
            + Author      : Christos Z, 		        		 +
            + Description : RSA crypto			                 +
            ======================================================
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/bn.h>
#define NBITS 128

// Function to print a BIGNUM in hexadecimal format
void printBN(char *msg, BIGNUM * a)
{
/* Use BN_bn2hex(a) for hex string
* Use BN_bn2dec(a) for decimal string */
char * number_str = BN_bn2hex(a);
printf("%s %s\n", msg, number_str);
OPENSSL_free(number_str);
}





int main ()
{

// Activity 4
BN_CTX * ctx= BN_CTX_new();

// Create a new BIGNUM for 'n'
BIGNUM *n=BN_new();
// Convert hexadecimal string to BIGNUM
BN_hex2bn(&n,"DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
// Create a new BIGNUM for 'e'
BIGNUM *e=BN_new();
 // Convert hexadecimal string to BIGNUM
BN_hex2bn(&e,"010001");
// Create a new BIGNUM for 'd'
BIGNUM*d=BN_new();
// Convert hexadecimal string to BIGNUM
BN_hex2bn(&d,"74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");



// Create a new BN_CTX structure for holding temporary variables
ctx= BN_CTX_new();
printf("\n4.2\n");
d=BN_new();
BN_hex2bn(&d,"74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");
e=BN_new();
BN_hex2bn(&e,"010001");
n=BN_new();
BN_hex2bn(&n,"DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
char *str = "Taz Buny Dufy";
printf("Length:%d",strlen(str));
// Allocate memory for the hexadecimal representation of the string
char* str3 = (char*)malloc(strlen(str)*sizeof(char));
printf("\nString is: %s\n",str);
int i=0;
int j=0;
for(i=0,j=0;i<strlen(str);i++,j+=2)
{
	// Format the character as a two-digit hexadecimal number
	sprintf((char*) str3+j,"%02X",str[i]);
}
// Null-terminate the hexadecimal string
str3[j]='\0';
printf("String in Hex form:%s\n",str3);

BIGNUM* strr = BN_new();

BN_hex2bn(&strr,str3);
//printBN("String in Hexadecimal bignum:", strr);

// Create a new BIGNUM for the signature
BIGNUM* S1 = BN_new();
// Perform modular exponentiation
BN_mod_exp(S1,strr,d,n,ctx);
// Print the result of the modular exponentiation
printBN("S2:",S1);


//Digital Signatures are different because of the small changes in strings

printf("\n\n\n--------Activity 5--------");
char * M = "Launch a missile";
printf("\nMessage:%s",M);
printf("\n5.1");

// Create a new BIGNUM for the signature
BIGNUM *S= BN_new();
BN_hex2bn(&S,"643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6802F");
e=BN_new();
BN_hex2bn(&e,"010001");
n=BN_new();
BN_hex2bn(&n,"AE1CD4DC432798D933779FBD46C6E1247F0CF1233595113AA51B450F18116115");

BIGNUM* Mn=BN_new();
BN_mod_exp(Mn,S,e,n,ctx);

int cmpr=BN_cmp(S,Mn);
printf("\ncmpr:%d",cmpr);
//cmpr=1 means that the two signatures are equal. Else they are different

printf("\n\n\n5.2");
S= BN_new();
BN_hex2bn(&S,"643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6803F");
BIGNUM* Mp=BN_new();
BN_mod_exp(Mp,S,e,n,ctx);
cmpr=BN_cmp(S,Mp);
printf("\ncmpr:%d",cmpr);
//Different because of the changes on the signature
}
