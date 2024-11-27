/*
            ======================================================
            + Name        : bn_sample12.c                        +
            + Author      : Christos Z, 		        		 +
            + Description : RSA crypto			                 +
            ======================================================
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/bn.h>
#define NBITS 128

void printBN(char *msg, BIGNUM * a)
{
/* Use BN_bn2hex(a) for hex string
* Use BN_bn2dec(a) for decimal string */
char * number_str = BN_bn2hex(a);
printf("%s %s\n", msg, number_str);
OPENSSL_free(number_str);
}

void printBNN(char *msg,const BIGNUM *a){
/* Use BN_bn2hex(a) for hex string
* Use BN_bn2dec(a) for decimal string */
char * number_str = BN_bn2hex(a);
printf("%s %s\n", msg, number_str);
OPENSSL_free(number_str);
}



int main ()
{
BN_CTX *ctx ;
ctx= BN_CTX_new();

// Activity 1
printf("\n\n\n--------Activity 1--------");
BIGNUM *p = BN_new(); /*Assign values to p,q*/
BN_hex2bn(&p,"953AAB9B3F23ED593FBDC690CA10E703");
BIGNUM *q = BN_new();
BN_hex2bn(&q,"C34EFC7C4C2369164E953553CDF94945");
BIGNUM *e = BN_new();
BN_hex2bn(&e,"0D88C3");

const BIGNUM *one = BN_value_one();
BIGNUM *m = BN_new();
BIGNUM *n = BN_new();

/*Calculations for variables for the key*/
BN_mul(n, p, q, ctx);


BIGNUM *phi = BN_new();
BIGNUM *d = BN_new();

/*Temporary variables
temp1=p-1
temp2=q-1	*/

BIGNUM *temp1 = BN_new();
BN_sub(temp1,p,one);
BIGNUM *temp2 = BN_new();
BN_sub(temp2,q,one);

printBN("\np:",p);
printBN("temp1:",temp1);
printBN("q:",q);
printBN("temp2:",temp2);

/*phi=(p-1)*(q-1)*/
BN_mul(phi,temp1,temp2,ctx);
printBN("phi",phi);
/*mod inverse for calculating private key*/
BN_mod_inverse(d,e,phi,ctx);

printBNN("d = ", d);

OPENSSL_free(temp1);
OPENSSL_free(temp2);



printf("\n\n\n--------Activity 2--------");
char* str = "Make it possible";
char* str2 = (char*)malloc(strlen(str)*sizeof(char));
printf("\nString is: %s\n",str);
int i=0;
int j=0;
/*Convert string to hex*/
for(i=0,j=0;i<strlen(str);i++,j+=2)
{
	sprintf((char*) str2+j,"%02X",str[i]);
}

str2[j]='\0';

printf("String in Hex form:%s\n",str2);
BIGNUM *strr = BN_new();
BIGNUM* decr=BN_new();
BIGNUM* encr=BN_new();
BN_hex2bn(&strr,str2);
printBN("String in Hexadecimal bignum:", strr);

//encryption with public key

BN_mod_exp(encr,strr,e,n,ctx);
printBN("Encryption message:",encr);
//decryption with private key
BN_mod_exp(decr,encr,d,n,ctx);
printBN("Decryption message:",decr);

//RESULTS ARE CORRECT. Decrypted message is like string in hexadecimal bignum
OPENSSL_free(encr);
OPENSSL_free(decr);

return 0;
}
