/*
There will be two arrays of integers. Determine all integers that satisfy the following two conditions:

The elements of the first array are all factors of the integer being considered
The integer being considered is a factor of all elements of the second array
These numbers are referred to as being between the two arrays. Determine how many such numbers exist.
*/
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int getTotalX(vector<int> a, vector<int> b) {
    int l = a[0];
    for (int i = 1; i < a.size(); i++) {
        l = lcm(l, a[i]);
    }

    int g = b[0];
    for (int i = 1; i < b.size(); i++) {
        g = gcd(g, b[i]);
    }

    int count = 0;
    for (int x = l; x <= g; x += l) {
        if (g % x == 0) {
            count++;
        }
    }

    return count;
}
/*
Why LCM of a?
You’re looking for numbers x such that:
Every element in a is a factor of x That means: x % a[i] == 0 for all i
So, the smallest such x that satisfies all these conditions is the Least Common Multiple (LCM) of the array a. Any valid x must be a multiple of LCM(a)—otherwise, it won’t be divisible by all elements of a.

Why GCD of b?
You also want:
x is a factor of every element in b That means: b[i] % x == 0 for all i
So, the largest such x that satisfies all these conditions is the Greatest Common Divisor (GCD) of the array b. Any valid x must be a factor of GCD(b)—otherwise, it won’t divide all elements of b.

Why Count Multiples of LCM That Divide GCD?
Now you’re looking for numbers that:
Are multiples of LCM(a) (so they satisfy array a)
And divide GCD(b) (so they satisfy array b)
So you loop through all multiples of LCM(a) up to GCD(b) and check:

Example
Let’s say:
a = [2, 4] → LCM = 4
b = [16, 32, 96] → GCD = 16
Now check multiples of 4 up to 16:

4 → 16 % 4 == 0 ✅
8 → 16 % 8 == 0 ✅
12 → 16 % 12 != 0 ❌
16 → 16 % 16 == 0 ✅
Answer: 3 valid numbers → [4, 8, 16]
*/
