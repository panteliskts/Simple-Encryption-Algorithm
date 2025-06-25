# 🔐 [The Rivest–Shamir–Adleman Algorithm](https://en.wikipedia.org/wiki/RSA_(cryptosystem))

The RSA Algorithm's main purpose is to encrypt or decrypt a message while implementing different mathematical calculations. Basically, we use two keys, a **public key**, which is the product of two prime numbers: **p** and **q**, and a **private key** which we have assigned the letter d. While encrypting, we use the **e** as an exponent and **m**, which is the message, as a base for that exponent. When we decrypt, we use **d** instead of **e** to perform the calculations. In the [**Implementation**](#implementation) section I will cover the most vital parts of the implemented code and in [Executing](#executing) section how to compile and run the program.

## 🛠️ Implementation

* Firstly, we create 5 functions outside of the **main function**:
  * **Gcd** to find the greatest common denominator of **p** and **q**;
  * **Prime** to check if p and q are prime numbers;
  * **Coprime** to determine if p and q are coprime(if the gcd of p and q = 1);
  * **Totient** to calculate the **phi function** also known as **[Euler's Totient Function](https://en.wikipedia.org/wiki/Euler%27s_totient_function)** for p and q;
  * **[Mod_Exp](https://en.wikipedia.org/wiki/Modular_exponentiation)** to efficiently compute the modular exponentiation using an iterative method that reduces the 
   problem size by squaring the base and halving the exponent in each iteration.

* Inside the **main function**, apart from the recursively calling the functions, I have included tests to check the correctness of the program:

1. **Argument Validation**:
   - Ensures the correct number of arguments are provided.
   - Checks if the first argument is either "enc" (for encryption) or "dec" (for decryption).

2. **Conversion and Validation**:
   - Converts command-line arguments to `long long` integers for `e`, `d`, `p`, `q`, and `m`.
   - Validates that `e`, `d`, `p`, and `q` are positive and that `p` and `q` are prime.

3. **RSA Setup**:
   - Calculates the totient (`phi`) of `p` and `q`.
   - Ensures `e` and `phi` are coprime.
   - Computes the modulus `N` as the product of `p` and `q`.
   - Verifies that `e * d % phi` equals 1.

4. **Message Handling**:
   - Reads the message `m` from the terminal.
   - Ensures the message is positive and smaller than `N`.

5. **Encryption/Decryption**:
   - Performs encryption or decryption based on the first argument using modular exponentiation (`mod_exp`).
   - Prints the encrypted or decrypted message.

The program returns 0 if all operations are successful, indicating that everything went well.


## </>Executing

1. Compile the program:
```bash
    gcc -o rsa rsa.c
```

2. Run the program and insert 5 numbers:

```bash
echo <message>| ./rsa enc|dec <exp_exp> <priv_exp> <prime1> <prime2> 
```

3. Check if the program has executed succesfully:
```bash
   echo $?
```

 
   
