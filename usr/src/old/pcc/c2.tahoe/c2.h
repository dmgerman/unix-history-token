begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	c2.h	1.2	86/07/27	*/
end_comment

begin_comment
comment|/*  * Header for object code improver  */
end_comment

begin_comment
comment|/* tokens */
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
value|6
end_define

begin_define
define|#
directive|define
name|JSW
value|7
end_define

begin_define
define|#
directive|define
name|MOV
value|8
end_define

begin_define
define|#
directive|define
name|CLR
value|9
end_define

begin_define
define|#
directive|define
name|INC
value|10
end_define

begin_define
define|#
directive|define
name|DEC
value|11
end_define

begin_define
define|#
directive|define
name|TST
value|12
end_define

begin_define
define|#
directive|define
name|PUSH
value|13
end_define

begin_define
define|#
directive|define
name|CVT
value|14
end_define

begin_define
define|#
directive|define
name|MOVZ
value|15
end_define

begin_define
define|#
directive|define
name|CMP
value|16
end_define

begin_define
define|#
directive|define
name|ADD
value|17
end_define

begin_define
define|#
directive|define
name|SUB
value|18
end_define

begin_define
define|#
directive|define
name|BIT
value|19
end_define

begin_define
define|#
directive|define
name|AND
value|20
end_define

begin_define
define|#
directive|define
name|OR
value|21
end_define

begin_define
define|#
directive|define
name|XOR
value|22
end_define

begin_define
define|#
directive|define
name|COM
value|23
end_define

begin_define
define|#
directive|define
name|NEG
value|24
end_define

begin_define
define|#
directive|define
name|EMUL
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
name|EDIV
value|28
end_define

begin_define
define|#
directive|define
name|SHAL
value|29
end_define

begin_define
define|#
directive|define
name|SHAR
value|30
end_define

begin_define
define|#
directive|define
name|SHL
value|31
end_define

begin_define
define|#
directive|define
name|SHR
value|32
end_define

begin_define
define|#
directive|define
name|CALLF
value|33
end_define

begin_define
define|#
directive|define
name|CALLS
value|34
end_define

begin_define
define|#
directive|define
name|CASE
value|35
end_define

begin_define
define|#
directive|define
name|ADDA
value|36
end_define

begin_define
define|#
directive|define
name|SUBA
value|37
end_define

begin_define
define|#
directive|define
name|AOBLEQ
value|38
end_define

begin_define
define|#
directive|define
name|AOBLSS
value|39
end_define

begin_define
define|#
directive|define
name|MOVA
value|40
end_define

begin_define
define|#
directive|define
name|PUSHA
value|41
end_define

begin_define
define|#
directive|define
name|LDF
value|42
end_define

begin_define
define|#
directive|define
name|LNF
value|43
end_define

begin_define
define|#
directive|define
name|STF
value|44
end_define

begin_define
define|#
directive|define
name|CMPF
value|45
end_define

begin_define
define|#
directive|define
name|CMPF2
value|46
end_define

begin_define
define|#
directive|define
name|TSTF
value|47
end_define

begin_define
define|#
directive|define
name|PUSHD
value|48
end_define

begin_define
define|#
directive|define
name|CVLF
value|49
end_define

begin_define
define|#
directive|define
name|CVFL
value|50
end_define

begin_define
define|#
directive|define
name|LDFD
value|51
end_define

begin_define
define|#
directive|define
name|CVDF
value|52
end_define

begin_define
define|#
directive|define
name|NEGF
value|53
end_define

begin_define
define|#
directive|define
name|ADDF
value|54
end_define

begin_define
define|#
directive|define
name|SUBF
value|55
end_define

begin_define
define|#
directive|define
name|MULF
value|56
end_define

begin_define
define|#
directive|define
name|DIVF
value|57
end_define

begin_define
define|#
directive|define
name|SINF
value|58
end_define

begin_define
define|#
directive|define
name|COSF
value|59
end_define

begin_define
define|#
directive|define
name|ATANF
value|60
end_define

begin_define
define|#
directive|define
name|LOGF
value|61
end_define

begin_define
define|#
directive|define
name|SQRTF
value|62
end_define

begin_define
define|#
directive|define
name|EXPF
value|63
end_define

begin_define
define|#
directive|define
name|MOVBLK
value|64
end_define

begin_define
define|#
directive|define
name|MFPR
value|65
end_define

begin_define
define|#
directive|define
name|MTPR
value|66
end_define

begin_define
define|#
directive|define
name|PROBE
value|67
end_define

begin_define
define|#
directive|define
name|MOVO
value|68
end_define

begin_define
define|#
directive|define
name|TEXT
value|69
end_define

begin_define
define|#
directive|define
name|DATA
value|70
end_define

begin_define
define|#
directive|define
name|BSS
value|71
end_define

begin_define
define|#
directive|define
name|ALIGN
value|72
end_define

begin_define
define|#
directive|define
name|END
value|73
end_define

begin_define
define|#
directive|define
name|LGEN
value|74
end_define

begin_define
define|#
directive|define
name|WGEN
value|75
end_define

begin_define
define|#
directive|define
name|SET
value|76
end_define

begin_define
define|#
directive|define
name|LCOMM
value|77
end_define

begin_define
define|#
directive|define
name|COMM
value|78
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
name|RET
value|14
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
name|QUAD
value|4
end_define

begin_define
define|#
directive|define
name|FLOAT
value|5
end_define

begin_define
define|#
directive|define
name|DOUBLE
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

begin_comment
comment|/* #define T(a,b) (a|((b)<<8)) NUXI problems */
end_comment

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
name|char
name|opcod
decl_stmt|;
name|unsigned
name|char
name|subopcod
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
name|unsigned
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
name|intleavetab
block|{
name|char
name|op
decl_stmt|;
name|unsigned
name|char
name|subop
decl_stmt|;
name|int
name|intleavect
decl_stmt|;
block|}
name|intltab
index|[]
struct|;
end_struct

begin_comment
comment|/* struct { NUXI problems 	short	combop; }; */
end_comment

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
name|naob
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
name|nst
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nld
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
name|int
name|fortflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|aobflag
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
value|13
end_define

begin_comment
comment|/* 0-12, f.p. accumulator, 4 for operands, 1 for running off end */
end_comment

begin_decl_stmt
name|char
modifier|*
name|regs
index|[
name|NREG
operator|+
literal|6
index|]
decl_stmt|;
end_decl_stmt

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
name|ACC
value|NREG
end_define

begin_define
define|#
directive|define
name|RT1
value|NREG+1
end_define

begin_define
define|#
directive|define
name|RT2
value|NREG+2
end_define

begin_define
define|#
directive|define
name|RT3
value|NREG+3
end_define

begin_define
define|#
directive|define
name|RT4
value|NREG+4
end_define

begin_define
define|#
directive|define
name|LABHS
value|127
end_define

begin_define
define|#
directive|define
name|MAXAOBDISP
value|5000
end_define

begin_define
define|#
directive|define
name|NUSE
value|6
end_define

begin_decl_stmt
name|struct
name|node
modifier|*
name|uses
index|[
name|NUSE
operator|+
literal|7
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for backwards flow analysis */
end_comment

begin_decl_stmt
name|struct
name|node
modifier|*
name|useacc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* same for acc */
end_comment

begin_decl_stmt
name|char
modifier|*
name|lastrand
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last operand of instruction */
end_comment

begin_function_decl
name|struct
name|node
modifier|*
name|bflow
parameter_list|()
function_decl|;
end_function_decl

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

begin_function_decl
name|struct
name|node
modifier|*
name|alloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|findcon
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|byondrd
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|equstr
value|!strcmp
end_define

begin_define
define|#
directive|define
name|COPYCODE
end_define

end_unit

