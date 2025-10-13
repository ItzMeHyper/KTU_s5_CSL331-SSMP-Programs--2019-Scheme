CODE SEGMENT
ASSUME CS:CODE
START:
     MOV CL,00H
     MOV SI,3000H
     MOV AL,[SI]
     INC SI
     MOV AH,[SI]
     INC SI
     MOV BL,[SI]
     INC SI
     MOV BH,[SI]
     ADD AX,BX
     INC SI
     MOV [SI],AL
     INC SI
     MOV [SI],AH
     JC L1
     INC SI
     MOV [SI],CL
     INT 3
L1:
     INC CL
     INC SI
     MOV [SI],CL
     INT 3
  CODE ENDS
  END START

