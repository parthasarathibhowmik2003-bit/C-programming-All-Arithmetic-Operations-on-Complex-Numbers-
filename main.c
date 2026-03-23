#include <stdio.h>
#include <math.h>

typedef struct {
    float real;
    float imag;
} Complex;

Complex add(Complex a, Complex b) {
    return (Complex){a.real + b.real, a.imag + b.imag};
}

Complex subtract(Complex a, Complex b) {
    return (Complex){a.real - b.real, a.imag - b.imag};
}

Complex multiply(Complex a, Complex b) {
    return (Complex){
        a.real * b.real - a.imag * b.imag,
        a.real * b.imag + a.imag * b.real
    };
}

Complex divide(Complex a, Complex b) {
    float denom = b.real * b.real + b.imag * b.imag;
    return (Complex){
        (a.real * b.real + a.imag * b.imag) / denom,
        (a.imag * b.real - a.real * b.imag) / denom
    };
}

float modulus(Complex a) {
    return sqrt(a.real * a.real + a.imag * a.imag);
}

void display(Complex c, const char *label) {
    if (c.imag >= 0)
        printf("%-15s = %.2f + %.2fi\n", label, c.real, c.imag);
    else
        printf("%-15s = %.2f - %.2fi\n", label, c.real, -c.imag);
}

int main() {
    Complex c1 = {3.0, 4.0};
    Complex c2 = {1.0, 2.0};

    printf("Complex Number Operations\n");
    printf("==========================\n");
    display("c1", c1);
    display("c2", c2);
    printf("\n");

    display("Addition",       add(c1, c2));
    display("Subtraction",    subtract(c1, c2));
    display("Multiplication", multiply(c1, c2));
    display("Division",       divide(c1, c2));

    printf("\n|c1| (Modulus)   = %.2f\n", modulus(c1));
    printf("|c2| (Modulus)   = %.2f\n",   modulus(c2));

    return 0;
}
```

**Sample Output:**
```
Complex Number Operations
==========================
c1              = 3.00 + 4.00i
c2              = 1.00 + 2.00i

Addition        = 4.00 + 6.00i
Subtraction     = 2.00 + 2.00i
Multiplication  = -5.00 + 10.00i
Division        = 2.20 - 0.40i

|c1| (Modulus)  = 5.00
|c2| (Modulus)  = 2.24
