begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Header for object code improver  *  Copyright 1974 Bell Telephone Laboratories, Incorporated  */
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
name|COM
value|12
end_define

begin_define
define|#
directive|define
name|INC
value|13
end_define

begin_define
define|#
directive|define
name|DEC
value|14
end_define

begin_define
define|#
directive|define
name|NEG
value|15
end_define

begin_define
define|#
directive|define
name|TST
value|16
end_define

begin_define
define|#
directive|define
name|ASR
value|17
end_define

begin_define
define|#
directive|define
name|ASL
value|18
end_define

begin_define
define|#
directive|define
name|SXT
value|19
end_define

begin_define
define|#
directive|define
name|CMP
value|20
end_define

begin_define
define|#
directive|define
name|ADD
value|21
end_define

begin_define
define|#
directive|define
name|SUB
value|22
end_define

begin_define
define|#
directive|define
name|BIT
value|23
end_define

begin_define
define|#
directive|define
name|BIC
value|24
end_define

begin_define
define|#
directive|define
name|BIS
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
name|XOR
value|29
end_define

begin_define
define|#
directive|define
name|TEXT
value|30
end_define

begin_define
define|#
directive|define
name|DATA
value|31
end_define

begin_define
define|#
directive|define
name|BSS
value|32
end_define

begin_define
define|#
directive|define
name|EVEN
value|33
end_define

begin_define
define|#
directive|define
name|MOVF
value|34
end_define

begin_define
define|#
directive|define
name|MOVOF
value|35
end_define

begin_define
define|#
directive|define
name|MOVFO
value|36
end_define

begin_define
define|#
directive|define
name|ADDF
value|37
end_define

begin_define
define|#
directive|define
name|SUBF
value|38
end_define

begin_define
define|#
directive|define
name|DIVF
value|39
end_define

begin_define
define|#
directive|define
name|MULF
value|40
end_define

begin_define
define|#
directive|define
name|CLRF
value|41
end_define

begin_define
define|#
directive|define
name|CMPF
value|42
end_define

begin_define
define|#
directive|define
name|NEGF
value|43
end_define

begin_define
define|#
directive|define
name|TSTF
value|44
end_define

begin_define
define|#
directive|define
name|CFCC
value|45
end_define

begin_define
define|#
directive|define
name|SOB
value|46
end_define

begin_define
define|#
directive|define
name|JSR
value|47
end_define

begin_define
define|#
directive|define
name|END
value|48
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

begin_define
define|#
directive|define
name|JLO
value|6
end_define

begin_define
define|#
directive|define
name|JHI
value|7
end_define

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
name|BYTE
value|100
end_define

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
name|int
name|labno
decl_stmt|;
name|char
modifier|*
name|code
decl_stmt|;
name|int
name|refc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
block|{
name|int
name|combop
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|optab
block|{
name|char
modifier|*
name|opstring
decl_stmt|;
name|int
name|opcode
decl_stmt|;
block|}
name|optab
index|[]
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

begin_decl_stmt
name|char
name|regs
index|[
literal|12
index|]
index|[
literal|20
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|conloc
index|[
literal|20
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|conval
index|[
literal|20
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|ccloc
index|[
literal|20
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|RT1
value|10
end_define

begin_define
define|#
directive|define
name|RT2
value|11
end_define

begin_define
define|#
directive|define
name|FREG
value|5
end_define

begin_define
define|#
directive|define
name|NREG
value|5
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
name|OPHS
value|57
end_define

begin_decl_stmt
name|struct
name|optab
modifier|*
name|ophash
index|[
name|OPHS
index|]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
block|{
name|int
name|int
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
block|{
name|char
name|lbyte
decl_stmt|;
block|}
struct|;
end_struct

end_unit

