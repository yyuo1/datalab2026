/* WARNING: Do not include any other libraries here,
 * otherwise you will get an error while running test.py
 * You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 *
 * Using printf will interfere with our script capturing the execution results.
 * At this point, you can only test correctness with ./btest.
 * After confirming everything is correct in ./btest, remove the printf
 * and run the complete tests with test.py.
 */

 /*
 * bitAnd - x & y using only ~ and |
 * Example: bitAnd(4, 5) = 4
 * Legal ops: ~ |
 * Max ops: 7
 * Difficulty: 1
 */
int bitAnd(int x, int y) 
{
    return ~(~x|~y);
}

/*
 * bitXor - x ^ y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 7
 *   Difficulty: 1
 */
int bitXor(int x, int y) 
{
    return ~(x&y)&~(~x&~y);
}

/*
 * samesign - Determines if two integers have the same sign.
 *   0 is not positive, nor negative
 *   Example: samesign(0, 1) = 0, samesign(0, 0) = 1
 *            samesign(-4, -5) = 1, samesign(-4, 5) = 0
 *   Legal ops: >> << ! ^ && if else &
 *   Max ops: 12
 *   Difficulty: 2
 *
 * Parameters:
 *   x - The first integer.
 *   y - The second integer.
 *
 * Returns:
 *   1 if x and y have the same sign , 0 otherwise.
 */
int samesign(int x, int y) 
{
    if(!x&&!y)
        return 1;
    if(!x)
        return 0;
    if(!y)
        return 0;
    return !(x>>31^y>>31);
}

/*
 * logtwo - Calculate the base-2 logarithm of a positive integer using bit
 *   shifting. (Think about bitCount)
 *   Note: You may assume that v > 0
 *   Example: logtwo(32) = 5
 *   Legal ops: > < >> << |
 *   Max ops: 25
 *   Difficulty: 4
 */
int logtwo(int v) 
{
    int res=0;
    int temp;
    temp=((v>>16)>0)<<4;
    res=res|temp;
    v=v>>temp;
    temp=((v>>8)>0)<<3;
    res=res|temp;
    v=v>>temp;
    temp=((v>>4)>0)<<2;
    res=res|temp;
    v=v>>temp;
    temp=((v>>2)>0)<<1;
    res=res|temp;
    v=v>>temp;
    temp=(v>>1)>0;
    res=res|temp;
    return res;
}

/*
 *  byteSwap - swaps the nth byte and the mth byte
 *    Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *              byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *    Note: You may assume that 0 <= n <= 3, 0 <= m <= 3
 *    Legal ops: ! ~ & ^ | + << >>
 *    Max ops: 17
 *    Difficulty: 2
 */
int byteSwap(int x, int n, int m) 
{
    int n1=n<<3;
    int m1=m<<3;
    int a=0xFF<<n1;
    int b=0xFF<<m1;
    int temp1=(((x&a)>>n1)&0xFF)<<m1;
    int temp2=(((x&b))>>m1&0xFF)<<n1;
    int x1=temp1|temp2;
    int move=~(a|b);
    int x2=x&move;
    return x1|x2;
}

/*
 * reverse - Reverse the bit order of a 32-bit unsigned integer.
 *   Example: reverse(0xFFFF0000) = 0x0000FFFF reverse(0x80000000)=0x1 reverse(0xA0000000)=0x5
 *   Note: You may assume that an unsigned integer is 32 bits long.
 *   Legal ops: << | & - + >> for while ! ~ (You can define unsigned in this function)
 *   Max ops: 30
 *   Difficulty: 3
 */
unsigned reverse(unsigned v) 
{
    int temp1=(v&0x55555555)<<1;
    int temp2=(v>>1)&0x55555555;
    v=temp1|temp2;
    temp1=(v&0x33333333)<<2;
    temp2=(v>>2)&0x33333333;
    v=temp1|temp2;
    temp1=(v&0x0F0F0F0F)<<4;
    temp2=(v>>4)&0x0F0F0F0F;
    v=temp1|temp2;
    temp1=(v&0x00FF00FF)<<8;
    temp2=(v>>8)&0x00FF00FF;
    v=temp1|temp2;
    v=(v>>16)|(v<<16);
    return v;
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Note: You can assume that 0 <= n <= 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Difficulty: 3
 */
int logicalShift(int x, int n) 
{
    x=x>>n;
    int move=~(((1<<31)>>n)<<1);
    x=x&move;
    return x;
}

/*
 * leftBitCount - returns count of number of consective 1's in left-hand (most) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12,
 *             leftBitCount(0xFE00FF0F) = 7
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Difficulty: 4
 */
int leftBitCount(int x) 
{
    int y=~x;
    int res=0;
    int n;
    n=(!(y>>16))<<4;
    res=res+n;
    y=y<<n;
    n=(!(y>>24))<<3;
    res=res+n;
    y=y<<n;
    n=(!(y>>28))<<2;
    res=res+n;
    y=y<<n;
    n=(!(y>>30))<<1;
    res=res+n;
    y=y<<n;
    n=!(y>>31);
    res=res+n;
    return res+!y;
}

/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but it is to be interpreted as
 *   the bit-level representation of a single-precision floating point values.
 *   Legal ops: if else while for & | ~ + - >> << < > ! ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned float_i2f(int x) 
{
    unsigned sign;
    unsigned exp;
    unsigned frac;
    if(x==0)
        return 0;
    unsigned ux=x;
    sign=ux&0x80000000;
    if(sign)
        ux=~ux+1;
    unsigned e=31;
    while(!(ux>>e))
        e=e-1;
    exp=e+0x7f;
    ux=ux<<(31-e);
    frac=(ux>>8)&0x7fffff;
    unsigned extra=ux&0xff;
    if(extra>0x80)
        frac=frac+1;
    else if(extra==0x80)
    {
        if(frac&1)
            frac=frac+1;
    }
    if(frac>>23)
    {
        exp=exp+1;
        frac=0;
    }
    return sign|(exp<<23)|frac;
}

/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: & >> << | if > < >= <= ! ~ else + ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatScale2(unsigned uf) 
{
    unsigned sign=uf&0x80000000;
    unsigned exp=(uf>>23)&0xff;
    unsigned frac=uf&0x7fffff;
    if(exp==0xff)
        return uf;
    else if(exp==0x00)
        return sign|(frac<<1);
    else
        exp=exp+1;
    if(exp==0xff)
        frac=0;
    return sign|(exp<<23)|frac;
}

/*
 * float64_f2i - Convert a 64-bit IEEE 754 floating-point number to a 32-bit signed integer.
 *   The conversion rounds towards zero.
 *   Note: Assumes IEEE 754 representation and standard two's complement integer format.
 *   Parameters:
 *     uf1 - The lower 32 bits of the 64-bit floating-point number.
 *     uf2 - The higher 32 bits of the 64-bit floating-point number.
 *   Returns:
 *     The converted integer value, or 0x80000000 on overflow, or 0 on underflow.
 *   Legal ops: >> << | & ~ ! + - > < >= <= if else
 *   Max ops: 60
 *   Difficulty: 3
 */
int float64_f2i(unsigned uf1, unsigned uf2) 
{
    unsigned sign=uf2>>31;
    unsigned exp=(uf2>>20)&0x7ff;
    if(exp<1023)
        return 0;
    unsigned e=exp-1023;
    if(e>30)
        return 0x80000000;
    unsigned part1=(uf2&0x000fffff)|0x00100000;
    unsigned m;
    if(e<=20)
        m=part1>>(20-e);
    else
    {
        unsigned part2=uf1>>(52-e);
        m=part2|part1<<(e-20);
    }
    if(sign)
        return -m;
    return m;
}

/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: < > <= >= << >> + - & | ~ ! if else &&
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatPower2(int x) 
{
    if(x>127)
        return 0x7f800000;
    if(x>=-126)
        return (x+127)<<23;
    if(x>=-149)
        return 1<<(x+149);
    return 0;
}
