
#include <iostream>

int main()
{
    char a, b, x;
    long long k;
    std::cin >> a >> b >> x >> k;

    int N = b - a +1;  // 1) Length of the interval
    // 2) Normalize k so it always fits in [0, N-1]
    //    This makes the program handle huge or negative k values correctly.
    //    (k % N) reduces it to the correct size,
    //    +N removes negativity,
    k = (k % N) + N;

    // 3) offset  position of x within the interval [a, b]
    //    Example: if a='a', b='d', x='b' -> offset = 1
    char offset = (x-a);

    // 4) newOffset new position after moving k steps cyclically
    char new_offset = (offset + k) % N; 
    // 5) Convert back from index to actual ASCII code
    char result= (char)(a + new_offset); 
    
    std::cout << result;


}
