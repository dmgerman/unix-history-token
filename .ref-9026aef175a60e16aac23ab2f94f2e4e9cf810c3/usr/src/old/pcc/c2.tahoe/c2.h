begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	c2.h	1.3	86/08/14	*/
end_comment

begin_comment
comment|/*  * Header for object code improver  */
end_comment

begin_comment
comment|/* tokens */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|NIL
block|,
name|JBR
block|,
name|CBR
block|,
name|JMP
block|,
name|LABEL
block|,
name|DLABEL
block|,
name|EROU
block|,
name|JSW
block|,
name|MOV
block|,
name|CLR
block|,
name|INC
block|,
name|DEC
block|,
name|TST
block|,
name|PUSH
block|,
name|CVT
block|,
name|MOVZ
block|,
name|CMP
block|,
name|ADD
block|,
name|SUB
block|,
name|BIT
block|,
name|AND
block|,
name|OR
block|,
name|XOR
block|,
name|COM
block|,
name|NEG
block|,
name|EMUL
block|,
name|MUL
block|,
name|DIV
block|,
name|EDIV
block|,
name|SHAL
block|,
name|SHAR
block|,
name|SHL
block|,
name|SHR
block|,
name|CALLF
block|,
name|CALLS
block|,
name|CASE
block|,
name|ADDA
block|,
name|SUBA
block|,
name|AOBLEQ
block|,
name|AOBLSS
block|,
name|MOVA
block|,
name|PUSHA
block|,
name|LDF
block|,
name|LNF
block|,
name|STF
block|,
name|CMPF
block|,
name|CMPF2
block|,
name|TSTF
block|,
name|PUSHD
block|,
name|CVLF
block|,
name|CVFL
block|,
name|LDFD
block|,
name|CVDF
block|,
name|NEGF
block|,
name|ADDF
block|,
name|SUBF
block|,
name|MULF
block|,
name|DIVF
block|,
name|SINF
block|,
name|COSF
block|,
name|ATANF
block|,
name|LOGF
block|,
name|SQRTF
block|,
name|EXPF
block|,
name|MOVBLK
block|,
name|MFPR
block|,
name|MTPR
block|,
name|PROBE
block|,
name|MOVO
block|,
name|TEXT
block|,
name|DATA
block|,
name|BSS
block|,
name|ALIGN
block|,
name|END
block|,
name|LGEN
block|,
name|WGEN
block|,
name|SET
block|,
name|LCOMM
block|,
name|COMM
block|}
name|OpCode
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ord
parameter_list|(
name|e
parameter_list|)
value|((int)(e))
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

begin_define
define|#
directive|define
name|has2ops
parameter_list|(
name|p
parameter_list|)
value|(((p)->subop>>4) == OP2)
end_define

begin_define
define|#
directive|define
name|has3ops
parameter_list|(
name|p
parameter_list|)
value|(((p)->subop>>4) == OP3)
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
name|OpCode
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
name|OpCode
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
name|OpCode
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

begin_define
define|#
directive|define
name|tempreg
parameter_list|(
name|s
parameter_list|,
name|r
parameter_list|)
value|((unsigned)((r)=isreg(s))< NUSE)
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

