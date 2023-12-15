#include <stdio.h>
int main(){
    int R0=5;
    int R1=7;
    int R2=0;

    while(R0>0){
        R2+=R1;
        R0-=1;
    }
    printf("%d", sum);
}


R2=0;  //@2 M=0
loop:
    if(R0<=0) goto end;  //@0 D=M @END D;JLE
    R2=R2+R1;  //@1 D=M @2 M=M+D
    R0=R0-1;  //@0 M=M-1
    goto loop;  //@LOOP 0;JMP
end:
