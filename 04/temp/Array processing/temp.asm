(LOOP)
@1
D=M
@3
D=D-M
@END
D;JEQ
@0
D=M
@3
A=M+D
D=M
@2
M=M+D
@3
M=M+1
@LOOP
0;JMP
(END)
@END
0;JMP