/* from Listing 5.5 Using a recursive function to calculate factorials; page 113  */
//For number entered = 6, basically calculates
// 6 * (6-1) * (6-2) *(6-3) * (6-4) * (6-3) * (6-2) * (6-1)
// Since this is a recursive function (it can also be set up as and if-then-else without recursion),
// the program will "hold" this in a stack and THEN do the math to multiple them. Because of recursion,
// it's like the function calls never fully complete and have to be held in a temp area (stack)
// before the math takes place.  Recursion can be "expensive" for large numbers. Sometimes it's better to go with
// using a loop (see examples following this recursion pgm)
// Here with recursion, the program "holds" the following in a stack and THEN does the math backwards:
// 6  --> 120 (prev ans.)*6=720  *** step 6
// 5  --> 24  (prev ans.)*5=120  *** step 5
// 4  --> 6   (prev ans.)*4=24   *** step 4
// 3  --> 2   (prev ans.)*3=6    *** step 3
// 2  --> 1   (prev nbr.)*2=2    *** step 2
// 1  --> starting point         *** step 1


// ************ Example with recursive function
#include <stdio.h>

unsigned int f,x;
unsigned int factorial(unsigned int a);

int main(void)
{
    puts("Enter an integer value between 1 and 8: \n");
    scanf("%d",&x);

    if(x>8 || x<1)
    {
        printf("Only values from 1 to 8 are acceptable!");
    }
    else
    {
        printf("'x' is %u\n",x);
        f = factorial(x);
        printf("%u factorial equals %u\n", x,f);
    }
    return 0;
}
unsigned int factorial(unsigned int a)
{
    if (a==1)
        return 1;
    else
    {
        //a *= factorial(a-1);
        // same as below
        a= a * factorial(a-1);

        return a;
    }
}

//********* Example using a loop without recursion
/*#include <stdio.h>

int main()
{
  int c, n, fact = 1;

  printf("Enter a number to calculate it's factorial\n");
  scanf("%d", &n);

  for (c = 1; c <= n; c++)
    fact = fact * c;

  printf("Factorial of %d = %d\n", n, fact);

  return 0;
}

*/
//************ Example using a function without recursion
/*#include <stdio.h>

long factorial(int);

int main()
{
  int number;
  long fact = 1;

  printf("Enter a number to calculate it's factorial\n");
  scanf("%d", &number);

  printf("%d! = %ld\n", number, factorial(number));

  return 0;
}

long factorial(int n)
{
  int c;
  long result = 1;

  for (c = 1; c <= n; c++)
    result = result * c;

  return result;
}

*/

//Exercises for Lesson 6 #11. - Recursion example to take value of 3 to the power of another number

/*#include <stdio.h>
int three_powered(int power);

int main(void)
{
    int a = 4;
    int b = 9;

    printf("\n3 to the power of %d is %d\n",a,three_powered(a));

    printf("\n3 to the power of %d is %d\n\n",b,three_powered(b));

    return 0;
}

int three_powered(int power)
{
    if (power <1)
        return(1);
    else
        return(3*three_powered(power-1));

}
*/