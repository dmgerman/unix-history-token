begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)glob.c	4.2 8/11/83"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"e.h"
end_include

begin_decl_stmt
name|int
name|dbg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debugging print if non-zero */
end_comment

begin_decl_stmt
name|int
name|lp
index|[
literal|80
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stack for things like piles and matrices */
end_comment

begin_decl_stmt
name|int
name|ct
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to lp */
end_comment

begin_decl_stmt
name|int
name|used
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* available registers */
end_comment

begin_decl_stmt
name|int
name|ps
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default init point size */
end_comment

begin_decl_stmt
name|int
name|deltaps
init|=
literal|3
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default change in ps */
end_comment

begin_decl_stmt
name|int
name|gsize
init|=
literal|10
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default initial point size */
end_comment

begin_decl_stmt
name|int
name|gfont
init|=
name|ITAL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* italic */
end_comment

begin_decl_stmt
name|int
name|ft
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default font */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|curfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current input file */
end_comment

begin_decl_stmt
name|int
name|ifile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|linect
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line number in file */
end_comment

begin_decl_stmt
name|int
name|eqline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line where eqn started */
end_comment

begin_decl_stmt
name|int
name|svargc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|svargv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|eht
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ebase
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lfont
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rfont
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|eqnreg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* register where final string appears */
end_comment

begin_decl_stmt
name|int
name|eqnht
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* inal height of equation */
end_comment

begin_decl_stmt
name|int
name|lefteq
init|=
literal|'\0'
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* left in-line delimiter */
end_comment

begin_decl_stmt
name|int
name|righteq
init|=
literal|'\0'
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* right in-line delimiter */
end_comment

begin_decl_stmt
name|int
name|lastchar
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last character read by lex */
end_comment

begin_decl_stmt
name|int
name|markline
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 if this EQ/EN contains mark or lineup */
end_comment

end_unit

