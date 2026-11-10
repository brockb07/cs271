// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.

// Runs an infinite loop that listens to the keyboard input. 
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel. When no key is pressed, 
// the screen should be cleared.

(INF_LOOP)
@8192
D=A
@i
M=D

@SCREEN
D=A
@LOC
M=D

@KBD
D=M

@FILL_LOOP
D;JGT
@UNFILL_LOOP
0;JMP

(FILL_LOOP)
@LOC
A=M
M=-1

@LOC
M=M+1

@i
M=M-1
D=M

@FILL_LOOP
D;JGT
@INF_LOOP
0;JMP

(UNFILL_LOOP)
@LOC
A=M
M=0

@LOC
M=M+1

@i
M=M-1
D=M

@UNFILL_LOOP
D;JGT
@INF_LOOP
0;JMP
