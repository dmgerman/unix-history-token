begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Code generation template numbers  */
end_comment

begin_define
define|#
directive|define
name|C_PUSH
value|1
end_define

begin_comment
comment|/* push anything onto stack */
end_comment

begin_define
define|#
directive|define
name|C_PUSHI
value|2
end_define

begin_comment
comment|/* push immediate quantity onto stack */
end_comment

begin_define
define|#
directive|define
name|C_PUSHN
value|3
end_define

begin_comment
comment|/* push a null descriptor on the stack */
end_comment

begin_define
define|#
directive|define
name|C_PUSHZ
value|4
end_define

begin_comment
comment|/* push a zero onto stack */
end_comment

begin_define
define|#
directive|define
name|C_PUSHA
value|5
end_define

begin_comment
comment|/* push address/offset onto stack */
end_comment

begin_define
define|#
directive|define
name|C_PUSHC
value|6
end_define

begin_comment
comment|/* push the address of a constant */
end_comment

begin_define
define|#
directive|define
name|C_PUSHL
value|7
end_define

begin_comment
comment|/* push a label onto stack */
end_comment

begin_define
define|#
directive|define
name|C_POP
value|8
end_define

begin_comment
comment|/* pop the stack into some location */
end_comment

begin_define
define|#
directive|define
name|C_MOV
value|9
end_define

begin_comment
comment|/* move one location to another */
end_comment

begin_define
define|#
directive|define
name|C_MOVI
value|10
end_define

begin_comment
comment|/* move an immediate somewhere */
end_comment

begin_define
define|#
directive|define
name|C_MOVA
value|11
end_define

begin_comment
comment|/* move an address to some location */
end_comment

begin_define
define|#
directive|define
name|C_MOVL
value|12
end_define

begin_comment
comment|/* move a label to some location */
end_comment

begin_define
define|#
directive|define
name|C_CLR
value|13
end_define

begin_comment
comment|/* clear a location */
end_comment

begin_define
define|#
directive|define
name|C_ADDTOP
value|14
end_define

begin_comment
comment|/* add immediate quantity to top of stack */
end_comment

begin_define
define|#
directive|define
name|C_INIT
value|15
end_define

begin_comment
comment|/* test initial flag of procedure */
end_comment

begin_define
define|#
directive|define
name|C_CALLJ
value|16
end_define

begin_comment
comment|/* jump to a subroutine */
end_comment

begin_define
define|#
directive|define
name|C_CALL
value|17
end_define

begin_comment
comment|/* call a subroutine */
end_comment

begin_define
define|#
directive|define
name|C_JUMP
value|18
end_define

begin_comment
comment|/* conditional jump to a local label */
end_comment

begin_define
define|#
directive|define
name|C_LABEL
value|19
end_define

begin_comment
comment|/* place a local label */
end_comment

begin_define
define|#
directive|define
name|C_MISC
value|20
end_define

begin_comment
comment|/* miscellaneous opcode and operand fields */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VAX
end_ifdef

begin_define
define|#
directive|define
name|BYTES
value|4
end_define

begin_decl_stmt
name|char
modifier|*
name|iformat
init|=
literal|"\t.long %d;"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|nameformat
init|=
literal|"\t.long %d,_ident+%d\t# %s\n"
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|r
parameter_list|(
name|i
parameter_list|)
value|(1<<(i))
end_define

begin_define
define|#
directive|define
name|C_MOVQ
value|26
end_define

begin_comment
comment|/* move a quadword */
end_comment

begin_define
define|#
directive|define
name|C_POPR
value|27
end_define

begin_comment
comment|/* pop registers */
end_comment

begin_define
define|#
directive|define
name|C_PUSHR
value|28
end_define

begin_comment
comment|/* push registers */
end_comment

begin_define
define|#
directive|define
name|C_PUSHIN
value|29
end_define

begin_comment
comment|/* push an indexed value */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PDP11
end_ifdef

begin_define
define|#
directive|define
name|BYTES
value|2
end_define

begin_decl_stmt
name|char
modifier|*
name|iformat
init|=
literal|"\t%06o;"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|nameformat
init|=
literal|"\t%06o;\t_ident+%o\t/ %s\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

