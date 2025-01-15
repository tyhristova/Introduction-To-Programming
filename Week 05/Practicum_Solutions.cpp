#include <iostream>

int reverse(int n)
{
    int reversedN = 0;

     while(n != 0){
        int digit = n % 10;
        reversedN = reversedN * 10 + digit;
        n /= 10;
     }

     return reversedN;
}

int digitsCounter(int n)
{
    int counter = 0;

    while(n > 0)
    {
        n /= 10;
        counter++;
    }

    return counter;
}

// 1
void swap(int& a, int& b) 
{
    int temp = a;
    a = b;
    b = temp;
}

void swap(double& a, double& b) 
{
    double temp = a;
    a = b;
    b = temp;
}

// 7
int gcd(int first, int second)
{
    if (!(first > second)) {
        swap(first, second);
    }
  
    for (int i = second; i >= 1; --i) {
        if (first % i == 0 && second % i == 0) {
             return i;
         }      
    }
    return 1;
}

int gcdEucledianAlgorithm(int a, int b)
{
    int r = 0;

    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

// 2
void fraction(int& nominator, int& denominator) 
{
    int gcdInput = gcd(nominator, denominator);

    nominator /= gcdInput;
    denominator /= gcdInput;
}

// 3
int removeDigitAtIndex(int n, int k)
{
    int counter = digitsCounter(n);

    if(k > 0 && k <= counter)
    {
        int divider1 = 1;
        int divider2 = 1;
        
        for(int i = 1; i < k; i++)
        {
            divider1 *= 10;
        }

        for(int i = 1; i <= k; i++)
        {
            divider2 *= 10;
        }

        int remainder = n % divider1;
        n /= divider2;

        return n * divider1 + remainder;
    }
    
    return 0;
}

// 4
void splitEvenOddPositions(int n)
{
    int oddPosition = 0;
    int evenPosition = 0;
    int counter = digitsCounter(n);

    int divider1 = 1;
    int divider2 = 1;

    while(n != 0)
    {
        if(counter % 2 == 1)
        {
            int remainderOdd = n % 10;
            n /= 10;
            oddPosition += remainderOdd * divider1;
            divider1 *= 10;
            counter--;
        }
        else if(counter % 2 == 0)
        {
            int remainderEven = n % 10;
            n /= 10;
            evenPosition += remainderEven * divider2;
            divider2 *= 10;
            counter--;
        }
    }

    std::cout << oddPosition << " " << evenPosition << std::endl;
    
}

// 5
int getPartialNumber(int n, int i, int j)
{
    int counter = digitsCounter(n);

    int divider1 = 1;

    if(i > 0 && i < counter && j > 0 && j < counter && i <= j)
    {
        for(int p = 0; p < counter; p++)
        {
        divider1 *= 10;
        }

        int s = 0;
        while(s < i)
        {
            n %= divider1;
            divider1 /= 10;
            s++;
        }

        int t = j;
        while(t < counter)
        {
            n /= 10;
            t++;
        }

    }

    return n;
}

// 6

int powerOfTen(int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= 10;
    }
    return result;
}

void changeDigits(int n, int m, int k)
{
    int nOriginal = n;
    int mOriginal = m;
    int counter = digitsCounter(n);

    for(int i = k; i < counter; i++)
    {
        n /= 10;
    }
    
    int nIndex = n % 10;


    for(int j = k; j < counter; j++)
    {
        m /= 10;
    }

    int mIndex = m % 10;

    int nNew = 0;
    int mNew = 0;
    int power = counter - k;

    nNew = (n / 10) * powerOfTen(power + 1) + mIndex * powerOfTen(power) + nOriginal % powerOfTen(power);
    mNew = (m / 10) * powerOfTen(power + 1) + nIndex * powerOfTen(power) + mOriginal % powerOfTen(power);

    std::cout << nNew << " " << mNew;
}



// 8
int lcm(int first, int second)
{
    int result = first;

    for(int i = 1; result % second != 0; i++)
    {
        result = first * i;
    }

    return result;
}

// 9
int concat(unsigned int first, unsigned int second)
{
    int counterSecond = digitsCounter(second);
    int result = first * powerOfTen(counterSecond) + second;

    return result;
}

int main()
{   
    // int i = 0;
    // while(++i, ++i < 15){
    //     do
    //     {
    //         std::cout << i * 2;
    //     }
    //     while(i++ < 6);
    // }

    int a, b;
    std::cin >> a >> b;
    std::cout << gcdEucledianAlgorithm(a, b);

    return 0;
}
