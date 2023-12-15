#include <stdio.h>
int main(){
    int R0=300;
    int R1=5;
    int R2=0;
    int RAM[500]=0;

    while(R1!=R2){
        RAM[R0+R2]=-1;
        R2+=1;
    }
}


R0=300; //@300 D=A @0 M=D
R1=5;   //@5 D=A @1 M=D
R2=0;   //@2 M=0
loop:   //(LOOP)
    if(R1==R2) goto end;    //@R1 D=M @R2 D=D-M @END D;JEQ
    RAM[R0+R2]=-1;  //@R0 D=M @R2 A=D+M M=-1
    R2=R2+1;    //@R2 M=M+1
    goto loop;  //@LOOP 0;JMP
end:    //(END) @END 0;JMP
    