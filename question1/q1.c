#include <stdio.h>
#include <ctype.h>

float getfloat(float *);

int main(){
    int c, dec, sign, a;
    float *fpr; 
    getfloat(fpr);
    float x = *fpr;
    printf("%f", x);

return 0;
}


float getfloat(float *fpr){
    int sign, c, a, dec;
        while (isspace(c = getchar()));
        if(!isdigit(c) && c != EOF && c !='+' && c != '-'){
            getchar();
            return 0;
        }
        sign = (c == '-') ? -1 : 1;
      
        if (c == '+' || c == '-'){
            c = getchar();
                }
                
        for (*fpr = 0, dec = 1; c != EOF; c = getchar()){
                    int a;
                    *fpr = 10 * *fpr + (c - '0');
                    if (isdigit(c)){
                        dec++;
                    }
                    else if(c = '.'){
                        dec++;
                        a == 10 ^dec;
                        
                    }
                
        }
        *fpr = (*fpr * sign)/a;
        return *fpr;
}
