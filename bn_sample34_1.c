/* bn_sample.c */
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
// Activity 3
BN_CTX * ctx= BN_CTX_new();
//Set variables
printf("\n\n\n--------Activity 3--------");
BIGNUM *n=BN_new();
BN_hex2bn(&n,"DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
BIGNUM *e=BN_new();
BN_hex2bn(&e,"010001");
BIGNUM*d=BN_new();
BN_hex2bn(&d,"74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");

BIGNUM*encr=BN_new();
BIGNUM*decr=BN_new();
BN_hex2bn(&encr,"B3AF0A70793BB53492B5311AED5EA843D94661924C97A446E9DD75846DF860DF");
printBN("\nEncrypted message:",encr);

BN_mod_exp(decr,encr,e,n,ctx);
printBN("Message in BN",decr);
char* message=BN_bn2hex(decr);
printf("Message in hex:%s",message);

//Sent message correct (We had to find a function to convert hex to ascii)

printf("\n\n\n--------Activity 4--------");
ctx= BN_CTX_new();
printf("\n4.1\n");
d=BN_new();
BN_hex2bn(&d,"74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");
e=BN_new();
BN_hex2bn(&e,"010001");
n=BN_new();
BN_hex2bn(&n,"DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
char *str = "Taz Bunny Duffy";
printf("Length:%d",strlen(str));
char* str3 = (char*)malloc(strlen(str)*sizeof(char));
printf("\nString is: %s\n",str);
int i=0;
int j=0;
//COnvert string to hex
for(i=0,j=0;i<strlen(str);i++,j+=2)
{
	sprintf((char*) str3+j,"%02X",str[i]);
}

str3[j]='\0';
printf("String in Hex form:%s\n",str3);

BIGNUM* strr = BN_new();
BN_hex2bn(&strr,str3);
//printBN("String in Hexadecimal bignum:", strr);
BIGNUM* S1 = BN_new();

BN_mod_exp(S1,strr,d,n,ctx);
printBN("S1:",S1);

//Digital signature for one string




}
