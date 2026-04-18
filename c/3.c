#include <stdio.h>
#include <stdbool.h>

int main(){

    char a = 'c';//%c
    char b[] = "bro";//%s

    float c = 3.1415926;//%f 6-7
    double d = 3.14159265358979323846;//%lf 15-16
    bool e =true;//%d false is 0, true is 1

    char f = 100;//%d or %c (-128 to 127)
    unsigned char g = 255;//%d or %c (0 to 255)

    short int h =32767;   //%d  (-32768 to 32767)
    unsigned short int i = 65535;   //%d  (0 to +65535)

    int j = 2147483647; //%d  (-2147483648 to 2147483647)
    unsigned int k = 4294967295; //%u (0 to +4294967295)

    long long int l = 9223372036854775807; //%lld (-9223372036854775808 to 9223372036854775807)
    unsigned long long int m = 18446744073709551615U; //%llu (0 to +18446744073709551615)




    printf("%c\n",a);
    printf("%s\n",b);
    printf("%0.15f\n",c);
    printf("%0.1f\n",d);
    printf("%d\n",e);
    printf("%d\n",f);
    printf("%d\n",g);
    printf("%d\n",h);
    printf("%d\n",i);
    printf("%d\n",j);
    printf("%u\n",k);
    printf("%lld\n",l);
    printf("%llu\n",m);


   //%c = character
   //%s = string
   //%f = float
   //%lf = double
   //%d = signed integer
   //%u = unsigned integer
   //%lld = long long int
   //%llu = unsigned long long int

   //%.1 = 1 digit after decimal point
   //%.15 = 15 digits after decimal point
   float item1 =5.75;
   float item2 =10.00;
   float item3 = 100.99;

   printf("Item 1: $%0.2f\n",item1);
   printf("Item 2: $%0.2f\n",item2); 
   printf("Item 3: $%0.2f\n",item3);


  return 0;
}