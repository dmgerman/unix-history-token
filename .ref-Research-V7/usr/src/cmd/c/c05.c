begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_include
include|#
directive|include
file|"c0.h"
end_include

begin_comment
comment|/*  *  info on operators:  *   01-- is binary operator  *   02-- left (or only) operand must be lvalue  *   04-- is relational operator  *  010-- is assignment-type operator  *  020-- non-float req. on left  *  040-- non-float req. on right  * 0100-- is commutative  * 0200-- is right, not left-associative  * 0400-- is leaf of tree  * *0XX000-- XX is priority of operator  */
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
literal|037000
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
literal|000001
operator|,
comment|/* field selection */
literal|034201
operator|,
comment|/* CAST */
literal|000000
operator|,
comment|/* ETYPE */
literal|000001
operator|,
comment|/* integer->ptr */
literal|000001
operator|,
comment|/* ptr->integer */
literal|000001
operator|,
comment|/* long->ptr */
literal|000000
operator|,
comment|/* 16 */
literal|000000
operator|,
comment|/* 17 */
literal|000000
operator|,
comment|/* 18 */
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
literal|000400
operator|,
comment|/* long constant */
literal|000400
operator|,
comment|/* long constant<= 16 bits */
literal|000000
operator|,
comment|/* 27 */
literal|000000
operator|,
comment|/* 28 */
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
literal|034200
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
literal|017161
operator|,
comment|/* | */
literal|017161
operator|,
comment|/* ^ */
literal|036001
operator|,
comment|/* -> */
literal|000000
operator|,
comment|/* int -> double */
literal|000000
operator|,
comment|/* double -> int */
literal|016001
operator|,
comment|/*&& */
literal|015001
operator|,
comment|/* || */
literal|030001
operator|,
comment|/*&~ */
literal|000000
operator|,
comment|/* 56 */
literal|000000
operator|,
comment|/* 57 */
literal|000000
operator|,
comment|/* 58 */
literal|000000
operator|,
comment|/* 59 */
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
literal|000000
operator|,
comment|/* 81 */
literal|000000
operator|,
comment|/* 82 */
literal|000000
operator|,
comment|/* 83 */
literal|000000
operator|,
comment|/* 84 */
literal|000000
operator|,
comment|/* 85 */
literal|000000
operator|,
comment|/* 86 */
literal|000000
operator|,
comment|/* 87 */
literal|000000
operator|,
comment|/* 88 */
literal|000000
operator|,
comment|/* 89 */
literal|014201
operator|,
comment|/* ? */
literal|034200
operator|,
comment|/* sizeof */
literal|000000
operator|,
comment|/* 92 */
literal|021101
operator|,
comment|/* min */
literal|021101
operator|,
comment|/* minp */
literal|021101
operator|,
comment|/* max */
literal|021101
operator|,
comment|/* maxp */
literal|007001
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
literal|036001
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
literal|000000
operator|,
comment|/* 105 */
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
comment|/* char->int */
literal|000000
comment|/* force r0 */
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * conversion table:  * FTI: float (or double) to integer  * ITF: integer to float  * ITP: integer to pointer  * ITL: integer to long  * LTI: long to integer  * LTF: long to float  * FTL: float to long  * PTI: pointer to integer  * LTP: long to ptr (ptr[long])  * XX: usually illegal  * When FTI, LTI, FTL are added in they specify  * that it is the left operand that should be converted.  * For + this is done and the conversion is turned back into  * ITF, ITL, LTF.  * For = however the left operand can't be converted  * and the specified conversion is applied to the rhs.  */
end_comment

begin_decl_stmt
name|char
name|cvtab
index|[
literal|4
index|]
index|[
literal|4
index|]
block|{
comment|/*		int	double		long		ptr */
comment|/* int */
literal|0
operator|,
operator|(
name|FTI
operator|<<
literal|4
operator|)
operator|+
name|ITF
operator|,
operator|(
name|LTI
operator|<<
literal|4
operator|)
operator|+
name|ITL
operator|,
operator|(
name|ITP
operator|<<
literal|4
operator|)
operator|+
name|ITP
operator|,
comment|/* double */
name|ITF
operator|,
literal|0
operator|,
name|LTF
operator|,
name|XX
operator|,
comment|/* long */
name|ITL
operator|,
operator|(
name|FTL
operator|<<
literal|4
operator|)
operator|+
name|LTF
operator|,
literal|0
operator|,
operator|(
name|LTP
operator|<<
literal|4
operator|)
operator|+
name|LTP
operator|,
comment|/* ptr */
name|ITP
operator|,
name|XX
operator|,
name|LTP
operator|,
name|PTI
operator|,
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * relate conversion numbers to operators  */
end_comment

begin_decl_stmt
name|char
name|cvntab
index|[]
block|{
literal|0
operator|,
name|ITOF
operator|,
name|ITOL
operator|,
name|LTOF
operator|,
name|ITOP
operator|,
name|PTOI
operator|,
name|FTOI
operator|,
name|LTOI
operator|,
name|FTOL
operator|,
name|LTOP
operator|,
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * character type table  */
end_comment

begin_decl_stmt
name|char
name|ctab
index|[]
block|{
name|EOFC
operator|,
name|INSERT
operator|,
name|UNKN
operator|,
name|UNKN
operator|,
name|UNKN
operator|,
name|UNKN
operator|,
name|UNKN
operator|,
name|UNKN
operator|,
name|UNKN
operator|,
name|SPACE
operator|,
name|NEWLN
operator|,
name|SPACE
operator|,
name|SPACE
operator|,
name|UNKN
operator|,
name|UNKN
operator|,
name|UNKN
operator|,
name|UNKN
operator|,
name|UNKN
operator|,
name|UNKN
operator|,
name|UNKN
operator|,
name|UNKN
operator|,
name|UNKN
operator|,
name|UNKN
operator|,
name|UNKN
operator|,
name|UNKN
operator|,
name|UNKN
operator|,
name|UNKN
operator|,
name|UNKN
operator|,
name|UNKN
operator|,
name|UNKN
operator|,
name|UNKN
operator|,
name|UNKN
operator|,
name|SPACE
operator|,
name|EXCLA
operator|,
name|DQUOTE
operator|,
name|SHARP
operator|,
name|UNKN
operator|,
name|MOD
operator|,
name|AND
operator|,
name|SQUOTE
operator|,
name|LPARN
operator|,
name|RPARN
operator|,
name|TIMES
operator|,
name|PLUS
operator|,
name|COMMA
operator|,
name|MINUS
operator|,
name|PERIOD
operator|,
name|DIVIDE
operator|,
name|DIGIT
operator|,
name|DIGIT
operator|,
name|DIGIT
operator|,
name|DIGIT
operator|,
name|DIGIT
operator|,
name|DIGIT
operator|,
name|DIGIT
operator|,
name|DIGIT
operator|,
name|DIGIT
operator|,
name|DIGIT
operator|,
name|COLON
operator|,
name|SEMI
operator|,
name|LESS
operator|,
name|ASSIGN
operator|,
name|GREAT
operator|,
name|QUEST
operator|,
name|UNKN
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LBRACK
operator|,
name|BSLASH
operator|,
name|RBRACK
operator|,
name|EXOR
operator|,
name|LETTER
operator|,
name|UNKN
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LETTER
operator|,
name|LBRACE
operator|,
name|OR
operator|,
name|RBRACE
operator|,
name|COMPL
operator|,
name|UNKN
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

