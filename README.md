# rsa/crypto 
 > Cryptographic algorithm using public key cryptosystem :tada:
 

## Table of contents
* [General Info](#general-information)
* [Setup](#setup)
* [How to run](#how-to-run)
* [Acknowledgements](#acknowledgments)

## General Information
RSA is an asymmetric cryptographic algorithm where each user has two keys, one 
private and one public.

It uses data from the theory of numbers and in 
combination with the particularly large keys achieves encryption in 
a balance arithmetic that makes decryption by factorization impossible.


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
OpenSSL is installed in the '/usr/local/ssl' directory.


## How to run



## Acknowledgments
* Assignment for cryptography

[^1]: BIGNUM can represent every great number, see https://www.openssl.org/docs/man1.0.2/man3/bn.html
[^2]: https://www.openssl.org
[^3]: Make sure install version ubuntu x32 architecture compatible with SEEDUbuntu.
