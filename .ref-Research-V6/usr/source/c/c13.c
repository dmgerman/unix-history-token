begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
comment|/* field selection */
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
literal|001000
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
literal|032101
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
comment|/* 109 */
literal|000000
comment|/* force r0 */
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
literal|0
operator|,
literal|0
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
literal|"=+"
operator|,
literal|"=-"
operator|,
literal|"=*"
operator|,
literal|"=/"
operator|,
literal|"=%"
operator|,
literal|"=>>"
operator|,
literal|"=<<"
operator|,
literal|"=&"
operator|,
literal|"=|"
operator|,
literal|"=^"
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
literal|"=& ~"
operator|,
literal|"=*"
operator|,
literal|"=/"
operator|,
literal|"=%"
operator|,
literal|0
operator|,
literal|"?"
operator|,
literal|"<<"
operator|,
literal|"=<<"
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
literal|0
operator|,
literal|"force register"
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

