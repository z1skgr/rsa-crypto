# rsa/crypto 
 > Cryptographic algorithm using public key cryptosystem :tada:
 

## Table of contents
* [General Info](#general-information)
* [Setup](#setup)
* [How to run](#how-to-run)
* [Acknowledgements](#acknowledgments)

## General Information
__RSA__ is an asymmetric cryptographic algorithm where each user has two keys
* private 
* public

It uses data from the theory of numbers and in combination with the particularly large keys achieves encryption in 
a balance arithmetic that makes decryption by factorization impossible.

### bn_act_1 & 2.c
1. Create a private key[^4]
2. Message encryption

|   | Description |
| ------------- | ------------- |
| p  | Prime  |
| q  | Prime  |
| e  | number |
| n  |  p * q |
| e,n  |  Public key |
| d |  Private key |
    
Calculations

$public_{key} = (e,n)$

$p = 953AAB9B3F23ED593FBDC690CA10E703$

$q = C34EFC7C4C2369164E953553CDF94945$

$e = 0D88C3$

$n = p * q$

$M = "message"$

#### Act 
* Calculate private key d
* Name surname encryption



### bn_act_3 & 4_1.c
1. Message decryption
2. Message signing

Calculations

$d = 74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D$

$e = 010001 (this hex value equals to decimal 65537) $

$n = DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5$

$M = "message"$

$M` = "messag"$

#### Act 
* Decrypt message using private and public key
* Message signing to two different texts

### bn_act_4-2.c
1. Signature Verification

Calculations

$public_{key} (e,n)$

$S = 643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6802F$

$e = 010001 (this hex value equals to decimal 65537) $

$n = AE1CD4DC432798D933779FBD46C6E1247F0CF1233595113AA51B450F18116115$

$M = "Launch a missile"$

#### Act 
* Signing verification
* Signing verification with modified S (last bit 2F->3F)


## Setup
Large numbers **bn[^1]** (multiprecision integer arithmetics) library provided by the **openssl [^2]**
For more information, you can check [bn](https://www.openssl.org/docs/man1.0.2/man3/bn.html).

<br><br>
Check the virtual Ubuntu SEED machine 16.04.


1. Download SEEDUbuntu-v 16.04 from site
```
https://seedsecuritylabs.org/lab_env.html
```
2. Download and install VM engine from site
```
https://www.virtualbox.org/wiki/Downloads
```
3. Build a new VM os importing SEEDUbuntu 
   * Select OS Type Linux [^3] version Ubuntu

4. PRE-build VM hard disk from SEED file
  * From the unzipped folder, select ```xxxx.vmdk``` where xxx is the SEED_name_version

5. Setting->General->Advanced 
   - [x] Shared Clipboard : Bidirectional
   - [x] Drag'n'Drop : Bidirectional
   - [x] Controller : VBoxVGA
   - [x] Processor : 1+ 

6. Open terminal
```
$ sudo apt update
$ sudo apt install build-essential checkinstall zlib1g-dev -y
$ cd /usr/local/src/
$ wget https://www.openssl.org/source/openssl-1.0.2o.tar.gz
$ tar -xf openssl-1.0.2o.tar.gz
$ cd openssl-1.0.2o
$ ./config --prefix=/usr/local/ssl --openssldir=/usr/local/ssl shared zlib
$ make
$ make test
$ make install
```

7. Configure libraries
```
$ cd /etc/ld.so.conf.d/
$ vim openssl-1.0.2o.conf
```
8. Paste
```
$ /usr/local/ssl/lib
```
9. Reload link
```
$ sudo ldconfig -v
```
You can edit with atom or any other editor
OpenSSL is installed in the `'/usr/local/ssl'` directory.



## How to run
Any `.c` file can be executed as
```
gcc XXXXX -o XXXXXX.c -lcrypto
```

where `XXXXX` filename




## Acknowledgments
* Assignment for cryptography

[^1]: BIGNUM can represent every great number, see https://www.openssl.org/docs/man1.0.2/man3/bn.html
[^2]: https://www.openssl.org
[^3]: Make sure install version ubuntu x32 architecture compatible with SEEDUbuntu.
[^4]: For simplicity, we use numbers 128 bits. Must be 512.
