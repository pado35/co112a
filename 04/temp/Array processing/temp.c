#include <stdio.h>
int main(){
    int RAM[201];
    RAM[0]=100;  //start address
    RAM[1]=5;    //address quantity
    RAM[2]=0;    //sum
    RAM[3]=0;    //count

    RAM[100]=1;
    RAM[101]=2;
    RAM[102]=4;
    RAM[103]=8;
    RAM[104]=16;

    while(RAM[1]!=RAM[3]){
        RAM[2]+=RAM[RAM[0]+RAM[3]];
        RAM[3]+=1;
    }
    printf("%d", RAM[2]);
}


loop:   //(LOOP)
    if(RAM[1]==RAM[3]) goto end;    //@1 D=M @3 D=D-M @END D;JEQ
    RAM[2]+=RAM[RAM[0]+RAM[3]]; //@0 D=M @3 A=M+D D=M @2 M=M+D
    RAM[3]+=1;  //@3 M=M+1
    goto loop;  //@LOOP 0;JMP
end:    //(END) @END 0;JMP
