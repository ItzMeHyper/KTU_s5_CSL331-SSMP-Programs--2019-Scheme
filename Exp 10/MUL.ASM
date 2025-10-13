CODE SEGMENT
ASSUME CS:CODE
START:
    MOV SI,3000H 
    MOV AL,[SI] 
    INC SI
    MOV BL,[SI]
    MUL BL  
    INC SI
    MOV [SI],AL 
    INC SI 
    MOV [SI],AH  
    INT 3
CODE ENDS
END START
