begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*static	char sccsid[] = "@(#)c2.h 4.4 %G%";*/
end_comment

begin_comment
comment|/* @(#)c2.h 1.19 80/08/26 13:39:07 */
end_comment

begin_comment
comment|/*  * Header for object code improver  */
end_comment

begin_define
define|#
directive|define
name|JBR
value|1
end_define

begin_define
define|#
directive|define
name|CBR
value|2
end_define

begin_define
define|#
directive|define
name|JMP
value|3
end_define

begin_define
define|#
directive|define
name|LABEL
value|4
end_define

begin_define
define|#
directive|define
name|DLABEL
value|5
end_define

begin_define
define|#
directive|define
name|EROU
value|7
end_define

begin_define
define|#
directive|define
name|JSW
value|9
end_define

begin_define
define|#
directive|define
name|MOV
value|10
end_define

begin_define
define|#
directive|define
name|CLR
value|11
end_define

begin_define
define|#
directive|define
name|INC
value|12
end_define

begin_define
define|#
directive|define
name|DEC
value|13
end_define

begin_define
define|#
directive|define
name|TST
value|14
end_define

begin_define
define|#
directive|define
name|PUSH
value|15
end_define

begin_define
define|#
directive|define
name|CVT
value|16
end_define

begin_define
define|#
directive|define
name|CMP
value|17
end_define

begin_define
define|#
directive|define
name|ADD
value|18
end_define

begin_define
define|#
directive|define
name|SUB
value|19
end_define

begin_define
define|#
directive|define
name|BIT
value|20
end_define

begin_define
define|#
directive|define
name|BIC
value|21
end_define

begin_define
define|#
directive|define
name|BIS
value|22
end_define

begin_define
define|#
directive|define
name|XOR
value|23
end_define

begin_define
define|#
directive|define
name|COM
value|24
end_define

begin_define
define|#
directive|define
name|NEG
value|25
end_define

begin_define
define|#
directive|define
name|MUL
value|26
end_define

begin_define
define|#
directive|define
name|DIV
value|27
end_define

begin_define
define|#
directive|define
name|ASH
value|28
end_define

begin_define
define|#
directive|define
name|EXTV
value|29
end_define

begin_define
define|#
directive|define
name|EXTZV
value|30
end_define

begin_define
define|#
directive|define
name|INSV
value|31
end_define

begin_define
define|#
directive|define
name|CALLS
value|32
end_define

begin_define
define|#
directive|define
name|RET
value|33
end_define

begin_define
define|#
directive|define
name|CASE
value|34
end_define

begin_define
define|#
directive|define
name|SOB
value|35
end_define

begin_define
define|#
directive|define
name|TEXT
value|36
end_define

begin_define
define|#
directive|define
name|DATA
value|37
end_define

begin_define
define|#
directive|define
name|BSS
value|38
end_define

begin_define
define|#
directive|define
name|ALIGN
value|39
end_define

begin_define
define|#
directive|define
name|END
value|40
end_define

begin_define
define|#
directive|define
name|MOVZ
value|41
end_define

begin_define
define|#
directive|define
name|WGEN
value|42
end_define

begin_define
define|#
directive|define
name|SOBGEQ
value|43
end_define

begin_define
define|#
directive|define
name|SOBGTR
value|44
end_define

begin_define
define|#
directive|define
name|AOBLEQ
value|45
end_define

begin_define
define|#
directive|define
name|AOBLSS
value|46
end_define

begin_define
define|#
directive|define
name|ACB
value|47
end_define

begin_define
define|#
directive|define
name|MOVA
value|48
end_define

begin_define
define|#
directive|define
name|PUSHA
value|49
end_define

begin_define
define|#
directive|define
name|LGEN
value|50
end_define

begin_define
define|#
directive|define
name|SET
value|51
end_define

begin_define
define|#
directive|define
name|MOVC3
value|52
end_define

begin_define
define|#
directive|define
name|RSB
value|53
end_define

begin_define
define|#
directive|define
name|JSB
value|54
end_define

begin_define
define|#
directive|define
name|MFPR
value|55
end_define

begin_define
define|#
directive|define
name|MTPR
value|56
end_define

begin_define
define|#
directive|define
name|PROBER
value|57
end_define

begin_define
define|#
directive|define
name|PROBEW
value|58
end_define

begin_define
define|#
directive|define
name|LCOMM
value|59
end_define

begin_define
define|#
directive|define
name|COMM
value|60
end_define

begin_define
define|#
directive|define
name|JEQ
value|0
end_define

begin_define
define|#
directive|define
name|JNE
value|1
end_define

begin_define
define|#
directive|define
name|JLE
value|2
end_define

begin_define
define|#
directive|define
name|JGE
value|3
end_define

begin_define
define|#
directive|define
name|JLT
value|4
end_define

begin_define
define|#
directive|define
name|JGT
value|5
end_define

begin_comment
comment|/* rearranged for unsigned branches so that jxxu = jxx + 6 */
end_comment

begin_define
define|#
directive|define
name|JLOS
value|8
end_define

begin_define
define|#
directive|define
name|JHIS
value|9
end_define

begin_define
define|#
directive|define
name|JLO
value|10
end_define

begin_define
define|#
directive|define
name|JHI
value|11
end_define

begin_define
define|#
directive|define
name|JBC
value|12
end_define

begin_define
define|#
directive|define
name|JBS
value|13
end_define

begin_define
define|#
directive|define
name|JLBC
value|14
end_define

begin_define
define|#
directive|define
name|JLBS
value|15
end_define

begin_define
define|#
directive|define
name|JBCC
value|16
end_define

begin_define
define|#
directive|define
name|JBSC
value|17
end_define

begin_define
define|#
directive|define
name|JBCS
value|18
end_define

begin_define
define|#
directive|define
name|JBSS
value|19
end_define

begin_define
define|#
directive|define
name|BYTE
value|1
end_define

begin_define
define|#
directive|define
name|WORD
value|2
end_define

begin_define
define|#
directive|define
name|LONG
value|3
end_define

begin_define
define|#
directive|define
name|FLOAT
value|4
end_define

begin_define
define|#
directive|define
name|DOUBLE
value|5
end_define

begin_define
define|#
directive|define
name|QUAD
value|6
end_define

begin_define
define|#
directive|define
name|OP2
value|7
end_define

begin_define
define|#
directive|define
name|OP3
value|8
end_define

begin_define
define|#
directive|define
name|OPB
value|9
end_define

begin_define
define|#
directive|define
name|OPX
value|10
end_define

begin_define
define|#
directive|define
name|T
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a|((b)<<8))
end_define

begin_define
define|#
directive|define
name|U
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a|((b)<<4))
end_define

begin_define
define|#
directive|define
name|C2_ASIZE
value|128
end_define

begin_struct
struct|struct
name|optab
block|{
name|char
name|opstring
index|[
literal|7
index|]
decl_stmt|;
name|short
name|opcode
decl_stmt|;
block|}
name|optab
index|[]
struct|;
end_struct

begin_struct
struct|struct
name|node
block|{
name|char
name|op
decl_stmt|;
name|char
name|subop
decl_stmt|;
name|short
name|refc
decl_stmt|;
name|struct
name|node
modifier|*
name|forw
decl_stmt|;
name|struct
name|node
modifier|*
name|back
decl_stmt|;
name|struct
name|node
modifier|*
name|ref
decl_stmt|;
name|char
modifier|*
name|code
decl_stmt|;
name|struct
name|optab
modifier|*
name|pop
decl_stmt|;
name|long
name|labno
decl_stmt|;
name|short
name|seq
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
block|{
name|short
name|combop
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|char
name|line
index|[
literal|512
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|node
name|first
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|curlp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nbrbr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nsaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|redunm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|iaftbr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|njp1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nrlab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nxjump
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ncmot
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nrevbr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|loopiv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nredunj
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nskip
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ncomj
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nsob
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nrtst
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nbj
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfield
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nchange
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|lasta
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|lastr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|firstr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|revbr
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NREG
value|12
end_define

begin_decl_stmt
name|char
modifier|*
name|regs
index|[
name|NREG
operator|+
literal|5
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0-11, 4 for operands, 1 for running off end */
end_comment

begin_decl_stmt
name|char
name|conloc
index|[
name|C2_ASIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|conval
index|[
name|C2_ASIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|ccloc
index|[
name|C2_ASIZE
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|RT1
value|12
end_define

begin_define
define|#
directive|define
name|RT2
value|13
end_define

begin_define
define|#
directive|define
name|RT3
value|14
end_define

begin_define
define|#
directive|define
name|RT4
value|15
end_define

begin_define
define|#
directive|define
name|LABHS
value|127
end_define

begin_struct
struct|struct
block|{
name|char
name|lbyte
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|char
modifier|*
name|copy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|getnum
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|node
modifier|*
name|codemove
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|node
modifier|*
name|insertl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|node
modifier|*
name|nonlab
parameter_list|()
function_decl|;
end_function_decl

end_unit

