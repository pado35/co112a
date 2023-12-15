 screen=16384;
 k=8192;
 n=0;

while(n<=k){
    if(kbd!=0)
        RAM[screen+n]=-1;
    else
        RAM[screen+n]=0;
    n+=1;
}


start:  //(START)
    st=16384;   //@SCREEN D=A @st M=D
    k=8192; //@8192 D=A @K M=D
    n=0;    //@N M=0
    loop:   //(LOOP)
        if(n==k) goto end;   //@N D=M @K D=D-M @END D;JEQ
        if(kbd!=0)  //@KBD D=M @ELSE D;JEQ
            RAM[screen+n]=-1;   //@st D=M @N A=D+M M=-1 @IFEND 0;JMP
        else    //(ELSE)
            RAM[screen+n]=0;    //@st D=M @N A=D+M M=0
            //(IFEND)
        n+=1;   //@N M=M+1
        goto loop;  //@LOOP 0;JMP
    end:    //(END)
        goto start; //@START 0;JMP




start:  //(START)
    k=8192; //@8192 D=A @K M=D
    n=0;    //@N M=0
    loop:   //(LOOP)
        if(n==k) goto end;   //@N D=M @K D=D-M @END D;JEQ
        if(kbd!=0)  //@KBD D=M @ELSE D;JEQ
            RAM[screen+n]=-1;   //@SCREEN D=A @N A=D+M M=-1 @IFEND 0;JMP
        else    //(ELSE)
            RAM[screen+n]=0;    //@SCREEN D=A @N A=D+M M=0
            //(IFEND)
        n+=1;   //@N M=M+1
        goto loop;  //@LOOP 0;JMP
    end:    //(END)
        goto start; //@START 0;JMP

