begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_include
include|#
directive|include
file|"c0h.c"
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
comment|/* EOF */
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
comment|/* 10 */
literal|000000
operator|,
comment|/* 11 */
literal|000000
operator|,
comment|/* 12 */
literal|000000
operator|,
comment|/* 13 */
literal|000000
operator|,
comment|/* 14 */
literal|000000
operator|,
comment|/* 15 */
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
literal|000000
operator|,
comment|/* 25 */
literal|000000
operator|,
comment|/* 26 */
literal|000000
operator|,
comment|/* 27 */
literal|000000
operator|,
comment|/* 28 */
literal|034200
operator|,
comment|/* sizeof */
literal|034202
operator|,
comment|/* ++pre */
literal|034202
operator|,
comment|/* --pre */
literal|034202
operator|,
comment|/* ++post */
literal|034202
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
literal|000000
operator|,
comment|/* 55 */
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
literal|000000
operator|,
comment|/* 91 */
literal|000000
operator|,
comment|/* 92 */
literal|000000
operator|,
comment|/* 93 */
literal|000000
operator|,
comment|/* 94 */
literal|000000
operator|,
comment|/* 95 */
literal|000000
operator|,
comment|/* 96 */
literal|000000
operator|,
comment|/* 97 */
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
comment|/* 109 */
literal|000000
comment|/* force r0 */
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * conversion table:  * 0100-- convert left operand  * 0*0XX-- XX is conversion number, to wit:  *  000: none  *  001: int -> ptr  *  002: ptr -> int  *  003: int -> double  *  004: double -> int  *  077: generally illegal  */
end_comment

begin_decl_stmt
name|char
name|cvtab
index|[]
block|{
literal|0000
operator|,
comment|/* i : i */
literal|0000
operator|,
comment|/* i : c */
literal|0103
operator|,
comment|/* i : f */
literal|0103
operator|,
comment|/* i : d */
literal|0077
operator|,
comment|/* i : s */
literal|0101
operator|,
comment|/* i : *i */
literal|0000
operator|,
comment|/* i : *c */
literal|0101
operator|,
comment|/* i : *f */
literal|0101
operator|,
comment|/* i : *d */
literal|0101
operator|,
comment|/* i : *s */
literal|0101
operator|,
comment|/* i : ** */
literal|0000
operator|,
comment|/* c : i */
literal|0000
operator|,
comment|/* c : c */
literal|0103
operator|,
comment|/* c : f */
literal|0103
operator|,
comment|/* c : d */
literal|0077
operator|,
comment|/* c : s */
literal|0101
operator|,
comment|/* c : *i */
literal|0000
operator|,
comment|/* c : *c */
literal|0101
operator|,
comment|/* c : *f */
literal|0101
operator|,
comment|/* c : *d */
literal|0101
operator|,
comment|/* c : *s */
literal|0101
operator|,
comment|/* c : ** */
literal|0003
operator|,
comment|/* f : i */
literal|0003
operator|,
comment|/* f : c */
literal|0000
operator|,
comment|/* f : f */
literal|0000
operator|,
comment|/* f : d */
literal|0077
operator|,
comment|/* f : s */
literal|0077
operator|,
comment|/* f : *i */
literal|0077
operator|,
comment|/* f : *c */
literal|0077
operator|,
comment|/* f : *f */
literal|0077
operator|,
comment|/* f : *d */
literal|0077
operator|,
comment|/* f : *s */
literal|0077
operator|,
comment|/* f : ** */
literal|0003
operator|,
comment|/* d : i */
literal|0003
operator|,
comment|/* d : c */
literal|0000
operator|,
comment|/* d : f */
literal|0000
operator|,
comment|/* d : d */
literal|0077
operator|,
comment|/* d : s */
literal|0077
operator|,
comment|/* d : *i */
literal|0077
operator|,
comment|/* d : *c */
literal|0077
operator|,
comment|/* d : *f */
literal|0077
operator|,
comment|/* d : *d */
literal|0077
operator|,
comment|/* d : *s */
literal|0077
operator|,
comment|/* d : ** */
literal|0077
operator|,
comment|/* s : i */
literal|0077
operator|,
comment|/* s : c */
literal|0077
operator|,
comment|/* s : f */
literal|0077
operator|,
comment|/* s : d */
literal|0077
operator|,
comment|/* s : s */
literal|0077
operator|,
comment|/* s : *i */
literal|0077
operator|,
comment|/* s : *c */
literal|0077
operator|,
comment|/* s : *f */
literal|0077
operator|,
comment|/* s : *d */
literal|0077
operator|,
comment|/* s : *s */
literal|0077
operator|,
comment|/* s : ** */
literal|0001
operator|,
comment|/* *i : i */
literal|0001
operator|,
comment|/* *i : c */
literal|0077
operator|,
comment|/* *i : f */
literal|0077
operator|,
comment|/* *i : d */
literal|0077
operator|,
comment|/* *i : s */
literal|0002
operator|,
comment|/* *i : *i */
literal|0077
operator|,
comment|/* *i : *c */
literal|0077
operator|,
comment|/* *i : *f */
literal|0077
operator|,
comment|/* *i : *d */
literal|0077
operator|,
comment|/* *i : *s */
literal|0002
operator|,
comment|/* *i : ** */
literal|0000
operator|,
comment|/* *c : i */
literal|0000
operator|,
comment|/* *c : c */
literal|0077
operator|,
comment|/* *c : f */
literal|0077
operator|,
comment|/* *c : d */
literal|0077
operator|,
comment|/* *c : s */
literal|0077
operator|,
comment|/* *c : *i */
literal|0000
operator|,
comment|/* *c : *c */
literal|0077
operator|,
comment|/* *c : *f */
literal|0077
operator|,
comment|/* *c : *d */
literal|0077
operator|,
comment|/* *c : *s */
literal|0077
operator|,
comment|/* *c : ** */
literal|0001
operator|,
comment|/* *f : i */
literal|0001
operator|,
comment|/* *f : c */
literal|0077
operator|,
comment|/* *f : f */
literal|0077
operator|,
comment|/* *f : d */
literal|0077
operator|,
comment|/* *f : s */
literal|0077
operator|,
comment|/* *f : *i */
literal|0077
operator|,
comment|/* *f : *c */
literal|0002
operator|,
comment|/* *f : *f */
literal|0077
operator|,
comment|/* *f : *d */
literal|0077
operator|,
comment|/* *f : *s */
literal|0077
operator|,
comment|/* *f : ** */
literal|0001
operator|,
comment|/* *d : i */
literal|0001
operator|,
comment|/* *d : c */
literal|0077
operator|,
comment|/* *d : f */
literal|0077
operator|,
comment|/* *d : d */
literal|0077
operator|,
comment|/* *d : s */
literal|0077
operator|,
comment|/* *d : *i */
literal|0077
operator|,
comment|/* *d : *c */
literal|0077
operator|,
comment|/* *d : *f */
literal|0002
operator|,
comment|/* *d : *d */
literal|0077
operator|,
comment|/* *d : *s */
literal|0077
operator|,
comment|/* *d : ** */
literal|0001
operator|,
comment|/* *s : i */
literal|0001
operator|,
comment|/* *s : c */
literal|0077
operator|,
comment|/* *s : f */
literal|0077
operator|,
comment|/* *s : d */
literal|0077
operator|,
comment|/* *s : s */
literal|0077
operator|,
comment|/* *s : *i */
literal|0077
operator|,
comment|/* *s : *c */
literal|0077
operator|,
comment|/* *s : *f */
literal|0077
operator|,
comment|/* *s : *d */
literal|0002
operator|,
comment|/* *s : *s */
literal|0077
operator|,
comment|/* *s : ** */
literal|0001
operator|,
comment|/* ** : i */
literal|0001
operator|,
comment|/* ** : c */
literal|0077
operator|,
comment|/* ** : f */
literal|0077
operator|,
comment|/* ** : d */
literal|0077
operator|,
comment|/* ** : s */
literal|0002
operator|,
comment|/* ** : *i */
literal|0077
operator|,
comment|/* ** : *c */
literal|0077
operator|,
comment|/* ** : *f */
literal|0077
operator|,
comment|/* ** : *d */
literal|0077
operator|,
comment|/* ** : *s */
literal|0002
comment|/* ** : ** */
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
name|EOF
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
name|UNKN
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
name|UNKN
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

