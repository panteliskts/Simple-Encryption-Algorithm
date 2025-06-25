#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Function to calculate the greatest common divisor
long long gcd(long long p, long long q) {
    if (q == 0) {
        return p;
    } else if (p == 0) {
        return q;
    }
    return gcd(q, p % q);
}
// Function to check if a number is prime
int prime(long long n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}
// Function to check if two numbers are coprime
long long coprime(long long p, long long q) {
    if (gcd(p, q) == 1) {
        return 0;
    } else {
        return 1;
    }
}

// Euler's totient function
long long totient(long long p, long long q) {
    return (p - 1) * (q - 1);
}

// Function to perform modular exponentiation
long long mod_exp(long long base, long long exp, long long mod) {

    long long result = 1; //Holds the  result of the modular exponentiation
    while (exp > 0) {   // Loop until the exponent becomes 0
        if (exp % 2 == 1) {
            result = (result * base) % mod;//If the exponent is odd, multiply the result by the base and take the remainder
        }
        base = (base * base) % mod; //Square the base and take the remainder
        exp /= 2; //Divide the exponent by 2
    }
    return result;
}
int main(int argc, char *argv[]) {

    // Check if the number of arguments is correct
    if (argc != 6) {
        printf("Usage: ./rsa enc|dec <exp_exp> <priv_exp> <prime1> <prime2>\n");
        return 1;
    }

    // Check if the first argument is "enc" or "dec"
    if (strcmp(argv[1], "enc") != 0 && strcmp(argv[1], "dec") != 0) {
        printf("First argument must be 'enc' or 'dec'\n");
        return 1;
    }


    //Convert the command-line arguments from strings to long long
    long long e = atoll(argv[2]);
    long long d = atoll(argv[3]);
    long long p = atoll(argv[4]);
    long long q = atoll(argv[5]);
    long long m;
  


    /// Check if the numbers are positive
    if ( e < 0 || d < 0 || p < 0 || q < 0) {
        printf("Negative numbers are not allowed.\n");
        return 1;
    }
    // Check if p and q are prime
    if (!prime(p) || !prime(q)) {
             printf("p and q must be prime\n");
        return 1;
    }

 

    //Calculate the totient of p and q
    long long phi = totient(p, q);
    // Check if e and phi are coprime
        if (coprime(e, phi) != 0) {
        printf("e is not coprime with phi(N)\n");
        return 1;
    }
    // Calculate N
    long long N = p * q;
    


    // Check if the message is smaller than N
        if ((e * d) % phi != 1) {
        printf("e * d mod phi(N) is not 1\n");
        return 1;
    }

    //Use scanf to read the message from the terminal
        if (scanf("%lld", &m) != 1 ) {
        return 1;
    }

    // Check if the message is positive
    if (m < 0) {
        printf("Negative numbers are not allowed.\n");
        return 1;
    }
 
    // Check if the message is smaller than N
    if (m >= N) {
        printf("Message is larger than N\n");
        return 1;
    }
    // Perform encryption based on the first argument
    if (strcmp(argv[1], "enc") == 0) {
        long long encrypted = mod_exp(m, e, N);
        printf(" %lld\n", encrypted);
    } 
    // Perform decryption
    else if (strcmp(argv[1], "dec") == 0) {
        long long decrypted = mod_exp(m, d, N);
        printf(" %lld\n", decrypted);
    }

    return 0; //return 0 if everything went well
    }
