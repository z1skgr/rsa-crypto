# rsa/crypto
 > Cryptographic algorithm using public key cryptosystem
 

## Table of contents
* [General Info](#general-information)
* [Setup](#setup)
* [Acknowledgements](#acknowledgements)

## General Information
RSA is an asymmetric cryptographic algorithm where each user has two keys, one 
private and one public.

It uses data from the theory of numbers and in 
combination with the particularly large keys achieves encryption in 
a balance arithmetic that makes decryption by factorization impossible.


## Setup
we use   large numbers **bn[^1]** (multiprecision integer arithmetics) library provided by the **openssl [^2]**

## Acknowledgments


[^1]: BIGNUM can represent every great number, see https://www.openssl.org/docs/man1.0.2/man3/bn.html
[^2]: https://www.openssl.org
