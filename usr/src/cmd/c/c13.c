begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * C second pass -- tables  */
end_comment

begin_include
include|#
directive|include
file|"c1.h"
end_include

begin_comment
comment|/*  * Operator dope table-- see description in c0.  */
end_comment

begin_decl_stmt
name|int
name|opdope
index|[]
block|{
literal|000000
operator|,
comment|/* EOFC */
literal|000000
operator|,
comment|/* ; */
literal|000000
operator|,
comment|/* { */
literal|000000
operator|,
comment|/* } */
literal|036000
operator|,
comment|/* [ */
literal|002000
operator|,
comment|/* ] */
literal|036000
operator|,
comment|/* ( */
literal|002000
operator|,
comment|/* ) */
literal|014201
operator|,
comment|/* : */
literal|007001
operator|,
comment|/* , */
literal|000000
operator|,
comment|/* field selection */
literal|000000
operator|,
comment|/* reverse field selection */
literal|000001
operator|,
comment|/* temporary field selection */
literal|000001
operator|,
comment|/* int->ptr */
literal|000001
operator|,
comment|/* ptr->int */
literal|000001
operator|,
comment|/* long->ptr */
literal|000001
operator|,
comment|/* field assignment */
literal|000001
operator|,
comment|/*>> unsigned */
literal|000001
operator|,
comment|/*>> unsigned */
literal|000000
operator|,
comment|/* 19 */
literal|000400
operator|,
comment|/* name */
literal|000400
operator|,
comment|/* short constant */
literal|000400
operator|,
comment|/* string */
literal|000400
operator|,
comment|/* float */
literal|000400
operator|,
comment|/* double */
literal|0000400
operator|,
comment|/* long const */
literal|000400
operator|,
comment|/* long const<= 16 bits */
literal|000400
operator|,
comment|/* autoi, *r++ */
literal|000400
operator|,
comment|/* autod, *--r */
literal|000000
operator|,
comment|/* 29 */
literal|034203
operator|,
comment|/* ++pre */
literal|034203
operator|,
comment|/* --pre */
literal|034203
operator|,
comment|/* ++post */
literal|034203
operator|,
comment|/* --post */
literal|034220
operator|,
comment|/* !un */
literal|034202
operator|,
comment|/*&un */
literal|034220
operator|,
comment|/* *un */
literal|034200
operator|,
comment|/* -un */
literal|034220
operator|,
comment|/* ~un */
literal|036001
operator|,
comment|/* . (structure reference) */
literal|030101
operator|,
comment|/* + */
literal|030001
operator|,
comment|/* - */
literal|032101
operator|,
comment|/* * */
literal|032001
operator|,
comment|/* / */
literal|032001
operator|,
comment|/* % */
literal|026061
operator|,
comment|/*>> */
literal|026061
operator|,
comment|/*<< */
literal|020161
operator|,
comment|/*& */
literal|016161
operator|,
comment|/* | */
literal|016161
operator|,
comment|/* ^ */
literal|036001
operator|,
comment|/* -> */
literal|001000
operator|,
comment|/* int -> double */
literal|001000
operator|,
comment|/* double -> int */
literal|000001
operator|,
comment|/*&& */
literal|000001
operator|,
comment|/* || */
literal|030001
operator|,
comment|/*&~ */
literal|001000
operator|,
comment|/* double -> long */
literal|001000
operator|,
comment|/* long -> double */
literal|001000
operator|,
comment|/* integer -> long */
literal|000000
operator|,
comment|/* long -> integer */
literal|022005
operator|,
comment|/* == */
literal|022005
operator|,
comment|/* != */
literal|024005
operator|,
comment|/*<= */
literal|024005
operator|,
comment|/*< */
literal|024005
operator|,
comment|/*>= */
literal|024005
operator|,
comment|/*> */
literal|024005
operator|,
comment|/*<p */
literal|024005
operator|,
comment|/*<=p */
literal|024005
operator|,
comment|/*>p */
literal|024005
operator|,
comment|/*>=p */
literal|012213
operator|,
comment|/* =+ */
literal|012213
operator|,
comment|/* =- */
literal|012213
operator|,
comment|/* =* */
literal|012213
operator|,
comment|/* =/ */
literal|012213
operator|,
comment|/* =% */
literal|012253
operator|,
comment|/* =>> */
literal|012253
operator|,
comment|/* =<< */
literal|012253
operator|,
comment|/* =& */
literal|012253
operator|,
comment|/* =| */
literal|012253
operator|,
comment|/* =^ */
literal|012213
operator|,
comment|/* = */
literal|030001
operator|,
comment|/*& for tests */
literal|032001
operator|,
comment|/*  * (long) */
literal|032001
operator|,
comment|/*  / (long) */
literal|032001
operator|,
comment|/* % (long) */
literal|012253
operator|,
comment|/* =& ~ */
literal|012213
operator|,
comment|/* =* (long) */
literal|012213
operator|,
comment|/* / (long) */
literal|012213
operator|,
comment|/* % (long) */
literal|000000
operator|,
comment|/* 89 */
literal|014201
operator|,
comment|/* ? */
literal|026061
operator|,
comment|/* long<< */
literal|012253
operator|,
comment|/* long =<< */
literal|000101
operator|,
comment|/* max */
literal|000101
operator|,
comment|/* maxp */
literal|000101
operator|,
comment|/* min */
literal|000101
operator|,
comment|/* minp */
literal|000001
operator|,
comment|/* , */
literal|000000
operator|,
comment|/* 98 */
literal|000000
operator|,
comment|/* 99 */
literal|036001
operator|,
comment|/* call */
literal|036000
operator|,
comment|/* mcall */
literal|000000
operator|,
comment|/* goto */
literal|000000
operator|,
comment|/* jump cond */
literal|000000
operator|,
comment|/* branch cond */
literal|000400
operator|,
comment|/* set nregs */
literal|000000
operator|,
comment|/* 106 */
literal|000000
operator|,
comment|/* 107 */
literal|000000
operator|,
comment|/* 108 */
literal|000000
operator|,
comment|/* int->char */
literal|000000
operator|,
comment|/* force r0 */
literal|000000
operator|,
comment|/* 111 */
literal|000000
operator|,
comment|/* 112 */
literal|000000
operator|,
comment|/* 113 */
literal|000000
operator|,
comment|/* 114 */
literal|000000
operator|,
comment|/* structure assign */
literal|000001
operator|,
comment|/* struct assignment setup */
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|char
modifier|*
name|opntab
index|[]
block|{
literal|0
operator|,
literal|0
operator|,
literal|0
operator|,
literal|0
operator|,
literal|0
operator|,
literal|0
operator|,
literal|0
operator|,
literal|0
operator|,
literal|":"
operator|,
literal|","
operator|,
literal|"field select"
operator|,
literal|0
operator|,
literal|0
operator|,
literal|"int->ptr"
operator|,
literal|"ptr->int"
operator|,
literal|"long->ptr"
operator|,
literal|"field assign"
operator|,
literal|">>"
operator|,
literal|">>"
operator|,
literal|0
operator|,
literal|"name"
operator|,
literal|"short constant"
operator|,
literal|"string"
operator|,
literal|"float"
operator|,
literal|"double"
operator|,
literal|"long constant"
operator|,
literal|"long constant"
operator|,
literal|"*r++"
operator|,
literal|"*--r"
operator|,
literal|0
operator|,
literal|"++pre"
operator|,
literal|"--pre"
operator|,
literal|"++post"
operator|,
literal|"--post"
operator|,
literal|"!un"
operator|,
literal|"&"
operator|,
literal|"*"
operator|,
literal|"-"
operator|,
literal|"~"
operator|,
literal|"."
operator|,
literal|"+"
operator|,
literal|"-"
operator|,
literal|"*"
operator|,
literal|"/"
operator|,
literal|"%"
operator|,
literal|">>"
operator|,
literal|"<<"
operator|,
literal|"&"
operator|,
literal|"|"
operator|,
literal|"^"
operator|,
literal|"->"
operator|,
literal|"int->double"
operator|,
literal|"double->int"
operator|,
literal|"&&"
operator|,
literal|"||"
operator|,
literal|"&~"
operator|,
literal|"double->long"
operator|,
literal|"long->double"
operator|,
literal|"integer->long"
operator|,
literal|"long->integer"
operator|,
literal|"=="
operator|,
literal|"!="
operator|,
literal|"<="
operator|,
literal|"<"
operator|,
literal|">="
operator|,
literal|">"
operator|,
literal|"<p"
operator|,
literal|"<=p"
operator|,
literal|">p"
operator|,
literal|">=p"
operator|,
literal|"+="
operator|,
literal|"-="
operator|,
literal|"*="
operator|,
literal|"/="
operator|,
literal|"%="
operator|,
literal|">>="
operator|,
literal|"<<="
operator|,
literal|"&="
operator|,
literal|"|="
operator|,
literal|"^="
operator|,
literal|"="
operator|,
literal|"& for tests"
operator|,
literal|"*"
operator|,
literal|"/"
operator|,
literal|"%"
operator|,
literal|"&= ~"
operator|,
literal|"*="
operator|,
literal|"/="
operator|,
literal|"%="
operator|,
literal|0
operator|,
literal|"?"
operator|,
literal|"<<"
operator|,
literal|"<<="
operator|,
literal|"\\/"
operator|,
literal|"\\/"
operator|,
literal|"/\\"
operator|,
literal|"/\\"
operator|,
literal|0
operator|,
literal|"call"
operator|,
literal|"call"
operator|,
literal|"call"
operator|,
literal|0
operator|,
literal|"goto"
operator|,
literal|"jump cond"
operator|,
literal|"branch cond"
operator|,
literal|"set nregs"
operator|,
literal|"load value"
operator|,
literal|0
operator|,
literal|0
operator|,
literal|"int->char"
operator|,
literal|"force register"
operator|,
literal|""
operator|,
literal|""
operator|,
literal|""
operator|,
literal|""
operator|,
literal|"=structure"
operator|,
literal|"= (struct setup)"
operator|,
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * Strings for instruction tables.  */
end_comment

begin_expr_stmt
name|char
name|mov
index|[]
literal|"mov"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|clr
index|[]
literal|"clr"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|cmp
index|[]
literal|"cmp"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|tst
index|[]
literal|"tst"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|add
index|[]
literal|"add"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|sub
index|[]
literal|"sub"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|inc
index|[]
literal|"inc"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|dec
index|[]
literal|"dec"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|mul
index|[]
literal|"mul"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|div
index|[]
literal|"div"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|asr
index|[]
literal|"asr"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|ash
index|[]
literal|"ash"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|asl
index|[]
literal|"asl"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|bic
index|[]
literal|"bic"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|bic1
index|[]
literal|"bic $1,"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|bit
index|[]
literal|"bit"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|bit1
index|[]
literal|"bit $1,"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|bis
index|[]
literal|"bis"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|bis1
index|[]
literal|"bis $1,"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|xor
index|[]
literal|"xor"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|neg
index|[]
literal|"neg"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|com
index|[]
literal|"com"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|stdol
index|[]
literal|"*$"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|ashc
index|[]
literal|"ashc"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|slmul
index|[]
literal|"lmul"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|sldiv
index|[]
literal|"ldiv"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|slrem
index|[]
literal|"lrem"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|almul
index|[]
literal|"almul"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|aldiv
index|[]
literal|"aldiv"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|alrem
index|[]
literal|"alrem"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|jeq
index|[]
literal|"jeq"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|jne
index|[]
literal|"jne"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|jle
index|[]
literal|"jle"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|jgt
index|[]
literal|"jgt"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|jlt
index|[]
literal|"jlt"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|jge
index|[]
literal|"jge"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|jlos
index|[]
literal|"jlos"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|jhi
index|[]
literal|"jhi"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|jlo
index|[]
literal|"jlo"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|jhis
index|[]
literal|"jhis"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|nop
index|[]
literal|"/nop"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
name|jbr
index|[]
literal|"jbr"
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Instruction tables, accessed by  * I (first operand) or I' (second) macros.  */
end_comment

begin_struct
struct|struct
name|instab
name|instab
index|[]
block|{
name|LOAD
operator|,
name|mov
operator|,
name|tst
operator|,
name|ASSIGN
operator|,
name|mov
operator|,
name|clr
operator|,
name|EQUAL
operator|,
name|cmp
operator|,
name|tst
operator|,
name|NEQUAL
operator|,
name|cmp
operator|,
name|tst
operator|,
name|LESSEQ
operator|,
name|cmp
operator|,
name|tst
operator|,
name|LESS
operator|,
name|cmp
operator|,
name|tst
operator|,
name|GREATEQ
operator|,
name|cmp
operator|,
name|tst
operator|,
name|GREAT
operator|,
name|cmp
operator|,
name|tst
operator|,
name|LESSEQP
operator|,
name|cmp
operator|,
name|tst
operator|,
name|LESSP
operator|,
name|cmp
operator|,
name|tst
operator|,
name|GREATQP
operator|,
name|cmp
operator|,
name|tst
operator|,
name|GREATP
operator|,
name|cmp
operator|,
name|tst
operator|,
name|PLUS
operator|,
name|add
operator|,
name|inc
operator|,
name|ASPLUS
operator|,
name|add
operator|,
name|inc
operator|,
name|MINUS
operator|,
name|sub
operator|,
name|dec
operator|,
name|ASMINUS
operator|,
name|sub
operator|,
name|dec
operator|,
name|INCBEF
operator|,
name|add
operator|,
name|inc
operator|,
name|DECBEF
operator|,
name|sub
operator|,
name|dec
operator|,
name|INCAFT
operator|,
name|add
operator|,
name|inc
operator|,
name|DECAFT
operator|,
name|sub
operator|,
name|dec
operator|,
name|TIMES
operator|,
name|mul
operator|,
name|mul
operator|,
name|ASTIMES
operator|,
name|mul
operator|,
name|mul
operator|,
name|DIVIDE
operator|,
name|div
operator|,
name|div
operator|,
name|ASDIV
operator|,
name|div
operator|,
name|div
operator|,
name|MOD
operator|,
name|div
operator|,
name|div
operator|,
name|ASMOD
operator|,
name|div
operator|,
name|div
operator|,
name|PTOI
operator|,
name|div
operator|,
name|div
operator|,
name|RSHIFT
operator|,
name|ash
operator|,
name|asr
operator|,
name|ASRSH
operator|,
name|ash
operator|,
name|asr
operator|,
name|LSHIFT
operator|,
name|ash
operator|,
name|asl
operator|,
name|ASLSH
operator|,
name|ash
operator|,
name|asl
operator|,
name|AND
operator|,
name|bic
operator|,
name|bic1
operator|,
name|ANDN
operator|,
name|bic
operator|,
name|bic1
operator|,
name|ASANDN
operator|,
name|bic
operator|,
name|bic1
operator|,
name|TAND
operator|,
name|bit
operator|,
name|bit1
operator|,
name|OR
operator|,
name|bis
operator|,
name|bis1
operator|,
name|ASOR
operator|,
name|bis
operator|,
name|bis1
operator|,
name|EXOR
operator|,
name|xor
operator|,
name|xor
operator|,
name|ASXOR
operator|,
name|xor
operator|,
name|xor
operator|,
name|NEG
operator|,
name|neg
operator|,
name|neg
operator|,
name|COMPL
operator|,
name|com
operator|,
name|com
operator|,
name|CALL1
operator|,
name|stdol
operator|,
name|stdol
operator|,
name|CALL2
operator|,
literal|""
operator|,
literal|""
operator|,
name|LLSHIFT
operator|,
name|ashc
operator|,
name|ashc
operator|,
name|ASLSHL
operator|,
name|ashc
operator|,
name|ashc
operator|,
name|LTIMES
operator|,
name|slmul
operator|,
name|slmul
operator|,
name|LDIV
operator|,
name|sldiv
operator|,
name|sldiv
operator|,
name|LMOD
operator|,
name|slrem
operator|,
name|slrem
operator|,
name|LASTIMES
operator|,
name|almul
operator|,
name|almul
operator|,
name|LASDIV
operator|,
name|aldiv
operator|,
name|aldiv
operator|,
name|LASMOD
operator|,
name|alrem
operator|,
name|alrem
operator|,
name|ULSH
operator|,
name|ashc
operator|,
name|ashc
operator|,
name|ASULSH
operator|,
name|ashc
operator|,
name|ashc
operator|,
literal|0
operator|,
literal|0
operator|,
literal|0
block|}
struct|;
end_struct

begin_comment
comment|/*  * Similar table for relationals.  * The first string is for the positive  * test, the second for the inverted one.  * The '200+' entries are   * used in tests against 0 where a 'tst'  * instruction is used; it clears the c-bit  * the c-bit so ptr tests are funny.  */
end_comment

begin_struct
struct|struct
name|instab
name|branchtab
index|[]
block|{
name|EQUAL
operator|,
name|jeq
operator|,
name|jne
operator|,
name|NEQUAL
operator|,
name|jne
operator|,
name|jeq
operator|,
name|LESSEQ
operator|,
name|jle
operator|,
name|jgt
operator|,
name|LESS
operator|,
name|jlt
operator|,
name|jge
operator|,
name|GREATEQ
operator|,
name|jge
operator|,
name|jlt
operator|,
name|GREAT
operator|,
name|jgt
operator|,
name|jle
operator|,
name|LESSEQP
operator|,
name|jlos
operator|,
name|jhi
operator|,
name|LESSP
operator|,
name|jlo
operator|,
name|jhis
operator|,
name|GREATQP
operator|,
name|jhis
operator|,
name|jlo
operator|,
name|GREATP
operator|,
name|jhi
operator|,
name|jlos
operator|,
literal|200
operator|+
name|EQUAL
operator|,
name|jeq
operator|,
name|jne
operator|,
literal|200
operator|+
name|NEQUAL
operator|,
name|jne
operator|,
name|jeq
operator|,
literal|200
operator|+
name|LESSEQ
operator|,
name|jle
operator|,
name|jgt
operator|,
literal|200
operator|+
name|LESS
operator|,
name|jlt
operator|,
name|jge
operator|,
literal|200
operator|+
name|GREATEQ
operator|,
name|jge
operator|,
name|jlt
operator|,
literal|200
operator|+
name|GREAT
operator|,
name|jgt
operator|,
name|jle
operator|,
literal|200
operator|+
name|LESSEQP
operator|,
name|jeq
operator|,
name|jne
operator|,
literal|200
operator|+
name|LESSP
operator|,
name|nop
operator|,
name|jbr
operator|,
literal|200
operator|+
name|GREATQP
operator|,
name|jbr
operator|,
name|nop
operator|,
literal|200
operator|+
name|GREATP
operator|,
name|jne
operator|,
name|jeq
operator|,
literal|0
operator|,
literal|0
operator|,
literal|0
block|}
struct|;
end_struct

end_unit

