begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"itran.h"
end_include

begin_include
include|#
directive|include
file|"lex.h"
end_include

begin_include
include|#
directive|include
file|"token.h"
end_include

begin_comment
comment|/*  * Token table - contains an entry for each token type  * with printable name of token, token type, and flags  * for semicolon insertion.  */
end_comment

begin_decl_stmt
name|struct
name|toktab
name|toktab
index|[]
init|=
block|{
comment|/*  token		token type	flags */
comment|/* primitives */
literal|"identifier"
block|,
name|IDENT
block|,
name|BEGINNER
operator|+
name|ENDER
block|,
comment|/*   0 */
literal|"integer-literal"
block|,
name|INTLIT
block|,
name|BEGINNER
operator|+
name|ENDER
block|,
comment|/*   1 */
literal|"real-literal"
block|,
name|REALLIT
block|,
name|BEGINNER
operator|+
name|ENDER
block|,
comment|/*   2 */
literal|"string-literal"
block|,
name|STRINGLIT
block|,
name|BEGINNER
operator|+
name|ENDER
block|,
comment|/*   3 */
literal|"cset-literal"
block|,
name|CSETLIT
block|,
name|BEGINNER
operator|+
name|ENDER
block|,
comment|/*   4 */
literal|"end-of-file"
block|,
name|EOFX
block|,
literal|0
block|,
comment|/*   5 */
comment|/* reserved words */
literal|"break"
block|,
name|BREAK
block|,
name|BEGINNER
operator|+
name|ENDER
block|,
comment|/*   6 */
literal|"by"
block|,
name|BY
block|,
literal|0
block|,
comment|/*   7 */
literal|"case"
block|,
name|CASE
block|,
name|BEGINNER
block|,
comment|/*   8 */
literal|"create"
block|,
name|CREATE
block|,
name|BEGINNER
block|,
comment|/*   9 */
literal|"default"
block|,
name|DEFAULT
block|,
name|BEGINNER
block|,
comment|/*  10 */
literal|"do"
block|,
name|DO
block|,
literal|0
block|,
comment|/*  11 */
literal|"dynamic"
block|,
name|DYNAMIC
block|,
name|BEGINNER
block|,
comment|/*  12 */
literal|"else"
block|,
name|ELSE
block|,
literal|0
block|,
comment|/*  13 */
literal|"end"
block|,
name|END
block|,
name|BEGINNER
block|,
comment|/*  14 */
literal|"every"
block|,
name|EVERY
block|,
name|BEGINNER
block|,
comment|/*  15 */
literal|"fail"
block|,
name|FAIL
block|,
name|BEGINNER
operator|+
name|ENDER
block|,
comment|/*  16 */
literal|"global"
block|,
name|GLOBAL
block|,
literal|0
block|,
comment|/*  17 */
literal|"if"
block|,
name|IF
block|,
name|BEGINNER
block|,
comment|/*  18 */
literal|"initial"
block|,
name|INITIAL
block|,
name|BEGINNER
block|,
comment|/*  19 */
literal|"link"
block|,
name|LINK
block|,
literal|0
block|,
comment|/*  20 */
literal|"local"
block|,
name|LOCAL
block|,
name|BEGINNER
block|,
comment|/*  21 */
literal|"next"
block|,
name|NEXT
block|,
name|BEGINNER
operator|+
name|ENDER
block|,
comment|/*  22 */
literal|"not"
block|,
name|NOT
block|,
name|BEGINNER
block|,
comment|/*  23 */
literal|"of"
block|,
name|OF
block|,
literal|0
block|,
comment|/*  24 */
literal|"procedure"
block|,
name|PROCEDURE
block|,
literal|0
block|,
comment|/*  25 */
literal|"record"
block|,
name|RECORD
block|,
literal|0
block|,
comment|/*  26 */
literal|"repeat"
block|,
name|REPEAT
block|,
name|BEGINNER
block|,
comment|/*  27 */
literal|"return"
block|,
name|RETURN
block|,
name|BEGINNER
operator|+
name|ENDER
block|,
comment|/*  28 */
literal|"static"
block|,
name|STATIC
block|,
name|BEGINNER
block|,
comment|/*  29 */
literal|"suspend"
block|,
name|SUSPEND
block|,
name|BEGINNER
operator|+
name|ENDER
block|,
comment|/*  30 */
literal|"then"
block|,
name|THEN
block|,
literal|0
block|,
comment|/*  31 */
literal|"to"
block|,
name|TO
block|,
literal|0
block|,
comment|/*  32 */
literal|"until"
block|,
name|UNTIL
block|,
name|BEGINNER
block|,
comment|/*  33 */
literal|"while"
block|,
name|WHILE
block|,
name|BEGINNER
block|,
comment|/*  34 */
comment|/* operators */
literal|":="
block|,
name|ASSIGN
block|,
literal|0
block|,
comment|/*  35 */
literal|"@"
block|,
name|AT
block|,
name|BEGINNER
block|,
comment|/*  36 */
literal|"@:="
block|,
name|AUGACT
block|,
literal|0
block|,
comment|/*  37 */
literal|"&:="
block|,
name|AUGAND
block|,
literal|0
block|,
comment|/*  38 */
literal|"=:="
block|,
name|AUGEQ
block|,
literal|0
block|,
comment|/*  39 */
literal|"===:="
block|,
name|AUGEQV
block|,
literal|0
block|,
comment|/*  40 */
literal|">=:="
block|,
name|AUGGE
block|,
literal|0
block|,
comment|/*  41 */
literal|">:="
block|,
name|AUGGT
block|,
literal|0
block|,
comment|/*  42 */
literal|"<=:="
block|,
name|AUGLE
block|,
literal|0
block|,
comment|/*  43 */
literal|"<:="
block|,
name|AUGLT
block|,
literal|0
block|,
comment|/*  44 */
literal|"~=:="
block|,
name|AUGNE
block|,
literal|0
block|,
comment|/*  45 */
literal|"~===:="
block|,
name|AUGNEQV
block|,
literal|0
block|,
comment|/*  46 */
literal|"==:="
block|,
name|AUGSEQ
block|,
literal|0
block|,
comment|/*  47 */
literal|">>=:="
block|,
name|AUGSGE
block|,
literal|0
block|,
comment|/*  48 */
literal|">>:="
block|,
name|AUGSGT
block|,
literal|0
block|,
comment|/*  49 */
literal|"<<=:="
block|,
name|AUGSLE
block|,
literal|0
block|,
comment|/*  50 */
literal|"<<:="
block|,
name|AUGSLT
block|,
literal|0
block|,
comment|/*  51 */
literal|"~==:="
block|,
name|AUGSNE
block|,
literal|0
block|,
comment|/*  52 */
literal|"\\"
block|,
name|BACKSLASH
block|,
name|BEGINNER
block|,
comment|/*  53 */
literal|"!"
block|,
name|BANG
block|,
name|BEGINNER
block|,
comment|/*  54 */
literal|"|"
block|,
name|BAR
block|,
name|BEGINNER
block|,
comment|/*  55 */
literal|"^"
block|,
name|CARET
block|,
name|BEGINNER
block|,
comment|/*  56 */
literal|"^:="
block|,
name|CARETASGN
block|,
literal|0
block|,
comment|/*  57 */
literal|":"
block|,
name|COLON
block|,
literal|0
block|,
comment|/*  58 */
literal|","
block|,
name|COMMA
block|,
literal|0
block|,
comment|/*  59 */
literal|"||"
block|,
name|CONCAT
block|,
name|BEGINNER
block|,
comment|/*  60 */
literal|"||:="
block|,
name|CONCATASGN
block|,
literal|0
block|,
comment|/*  61 */
literal|"&"
block|,
name|CONJUNC
block|,
name|BEGINNER
block|,
comment|/*  62 */
literal|"."
block|,
name|DOT
block|,
name|BEGINNER
block|,
comment|/*  63 */
literal|"--"
block|,
name|DIFF
block|,
name|BEGINNER
block|,
comment|/*  64 */
literal|"--:="
block|,
name|DIFFASGN
block|,
literal|0
block|,
comment|/*  65 */
literal|"==="
block|,
name|EQUIV
block|,
name|BEGINNER
block|,
comment|/*  66 */
literal|"**"
block|,
name|INTER
block|,
name|BEGINNER
block|,
comment|/*  67 */
literal|"**:="
block|,
name|INTERASGN
block|,
literal|0
block|,
comment|/*  68 */
literal|"{"
block|,
name|LBRACE
block|,
name|BEGINNER
block|,
comment|/*  69 */
literal|"["
block|,
name|LBRACK
block|,
name|BEGINNER
block|,
comment|/*  70 */
literal|"|||"
block|,
name|LCONCAT
block|,
name|BEGINNER
block|,
comment|/*  71 */
literal|"|||:="
block|,
name|LCONCATASGN
block|,
name|BEGINNER
block|,
comment|/*  72 */
literal|"=="
block|,
name|LEXEQ
block|,
name|BEGINNER
block|,
comment|/*  73 */
literal|">>="
block|,
name|LEXGE
block|,
literal|0
block|,
comment|/*  74 */
literal|">>"
block|,
name|LEXGT
block|,
literal|0
block|,
comment|/*  75 */
literal|"<<="
block|,
name|LEXLE
block|,
literal|0
block|,
comment|/*  76 */
literal|"<<"
block|,
name|LEXLT
block|,
literal|0
block|,
comment|/*  77 */
literal|"~=="
block|,
name|LEXNE
block|,
name|BEGINNER
block|,
comment|/*  78 */
literal|"("
block|,
name|LPAREN
block|,
name|BEGINNER
block|,
comment|/*  79 */
literal|"-:"
block|,
name|MCOLON
block|,
literal|0
block|,
comment|/*  80 */
literal|"-"
block|,
name|MINUS
block|,
name|BEGINNER
block|,
comment|/*  81 */
literal|"-:="
block|,
name|MINUSASGN
block|,
literal|0
block|,
comment|/*  82 */
literal|"%"
block|,
name|MOD
block|,
literal|0
block|,
comment|/*  83 */
literal|"%:="
block|,
name|MODASGN
block|,
literal|0
block|,
comment|/*  84 */
literal|"~==="
block|,
name|NOTEQUIV
block|,
name|BEGINNER
block|,
comment|/*  85 */
literal|"="
block|,
name|NUMEQ
block|,
name|BEGINNER
block|,
comment|/*  86 */
literal|">="
block|,
name|NUMGE
block|,
literal|0
block|,
comment|/*  87 */
literal|">"
block|,
name|NUMGT
block|,
literal|0
block|,
comment|/*  88 */
literal|"<="
block|,
name|NUMLE
block|,
literal|0
block|,
comment|/*  89 */
literal|"<"
block|,
name|NUMLT
block|,
literal|0
block|,
comment|/*  90 */
literal|"~="
block|,
name|NUMNE
block|,
name|BEGINNER
block|,
comment|/*  91 */
literal|"+:"
block|,
name|PCOLON
block|,
literal|0
block|,
comment|/*  92 */
literal|"+"
block|,
name|PLUS
block|,
name|BEGINNER
block|,
comment|/*  93 */
literal|"+:="
block|,
name|PLUSASGN
block|,
literal|0
block|,
comment|/*  94 */
literal|"?"
block|,
name|QMARK
block|,
name|BEGINNER
block|,
comment|/*  95 */
literal|"<-"
block|,
name|REVASSIGN
block|,
literal|0
block|,
comment|/*  96 */
literal|"<->"
block|,
name|REVSWAP
block|,
literal|0
block|,
comment|/*  97 */
literal|"}"
block|,
name|RBRACE
block|,
name|ENDER
block|,
comment|/*  98 */
literal|"]"
block|,
name|RBRACK
block|,
name|ENDER
block|,
comment|/*  99 */
literal|")"
block|,
name|RPAREN
block|,
name|ENDER
block|,
comment|/* 100 */
literal|";"
block|,
name|SEMICOL
block|,
literal|0
block|,
comment|/* 101 */
literal|"?:="
block|,
name|SCANASGN
block|,
literal|0
block|,
comment|/* 102 */
literal|"/"
block|,
name|SLASH
block|,
name|BEGINNER
block|,
comment|/* 103 */
literal|"/:="
block|,
name|SLASHASGN
block|,
literal|0
block|,
comment|/* 104 */
literal|"*"
block|,
name|STAR
block|,
name|BEGINNER
block|,
comment|/* 105 */
literal|"*:="
block|,
name|STARASGN
block|,
literal|0
block|,
comment|/* 106 */
literal|":=:"
block|,
name|SWAP
block|,
literal|0
block|,
comment|/* 107 */
literal|"~"
block|,
name|TILDE
block|,
name|BEGINNER
block|,
comment|/* 108 */
literal|"++"
block|,
name|UNION
block|,
name|BEGINNER
block|,
comment|/* 109 */
literal|"++:="
block|,
name|UNIONASGN
block|,
literal|0
block|,
comment|/* 110 */
literal|"end-of-file"
block|,
literal|0
block|,
literal|0
block|,    }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * restab[c] points to the first keyword in toktab which  * begins with the letter c.  */
end_comment

begin_decl_stmt
name|struct
name|toktab
modifier|*
name|restab
index|[]
init|=
block|{
name|NULL
block|,
name|NULL
block|,
comment|/*   _` */
name|NULL
block|,
operator|&
name|toktab
index|[
literal|6
index|]
block|,
operator|&
name|toktab
index|[
literal|8
index|]
block|,
operator|&
name|toktab
index|[
literal|10
index|]
block|,
comment|/* abcd */
operator|&
name|toktab
index|[
literal|13
index|]
block|,
operator|&
name|toktab
index|[
literal|16
index|]
block|,
operator|&
name|toktab
index|[
literal|17
index|]
block|,
name|NULL
block|,
comment|/* efgh */
operator|&
name|toktab
index|[
literal|18
index|]
block|,
name|NULL
block|,
name|NULL
block|,
operator|&
name|toktab
index|[
literal|20
index|]
block|,
comment|/* ijkl */
name|NULL
block|,
operator|&
name|toktab
index|[
literal|22
index|]
block|,
operator|&
name|toktab
index|[
literal|24
index|]
block|,
operator|&
name|toktab
index|[
literal|25
index|]
block|,
comment|/* mnop */
name|NULL
block|,
operator|&
name|toktab
index|[
literal|26
index|]
block|,
operator|&
name|toktab
index|[
literal|29
index|]
block|,
operator|&
name|toktab
index|[
literal|31
index|]
block|,
comment|/* qrst */
operator|&
name|toktab
index|[
literal|33
index|]
block|,
name|NULL
block|,
operator|&
name|toktab
index|[
literal|34
index|]
block|,
name|NULL
block|,
comment|/* uvwx */
name|NULL
block|,
name|NULL
block|,
comment|/* yz */
block|}
decl_stmt|;
end_decl_stmt

end_unit

