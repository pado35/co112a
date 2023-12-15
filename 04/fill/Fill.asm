// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.
(START)
@8192
D=A
@K
M=D
@N
M=0
(LOOP)
@N
D=M
@K
D=D-M
@END
D;JEQ
@KBD
D=M
@ELSE
D;JEQ
@SCREEN
D=A
@N
A=D+M
M=-1
@IFEND
0;JMP
(ELSE)
@SCREEN
D=A
@N
A=D+M
M=0
(IFEND)
@N
M=M+1
@LOOP
0;JMP
(END)
@START
0;JMP