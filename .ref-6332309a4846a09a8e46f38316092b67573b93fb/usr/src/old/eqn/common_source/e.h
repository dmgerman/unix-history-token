begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	e.h	4.2	83/02/12	*/
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|FATAL
value|1
end_define

begin_define
define|#
directive|define
name|ROM
value|'1'
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NEQN
end_ifndef

begin_define
define|#
directive|define
name|ITAL
value|'2'
end_define

begin_define
define|#
directive|define
name|BLD
value|'3'
end_define

begin_else
else|#
directive|else
else|NEQN
end_else

begin_define
define|#
directive|define
name|ITAL
value|'1'
end_define

begin_define
define|#
directive|define
name|BLD
value|'1'
end_define

begin_endif
endif|#
directive|endif
endif|NEQN
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NEQN
end_ifndef

begin_define
define|#
directive|define
name|VERT
parameter_list|(
name|n
parameter_list|)
value|((((n)+1)/3)*3)
end_define

begin_else
else|#
directive|else
else|NEQN
end_else

begin_define
define|#
directive|define
name|VERT
parameter_list|(
name|n
parameter_list|)
value|(20 * (n))
end_define

begin_endif
endif|#
directive|endif
endif|NEQN
end_endif

begin_define
define|#
directive|define
name|EFFPS
parameter_list|(
name|p
parameter_list|)
value|((p)>= 6 ? (p) : 6)
end_define

begin_decl_stmt
specifier|extern
name|int
name|dbg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ct
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lp
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|used
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* available registers */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ps
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dflt init pt size */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|deltaps
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default change in ps */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* global size */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gfont
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* global font */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ft
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dflt font */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|curfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current input file */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ifile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input file number */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|linect
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line number in current file */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|eqline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line where eqn started */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|svargc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|svargv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|eht
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ebase
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lfont
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rfont
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|yyval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|yypv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|yylval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|eqnreg
decl_stmt|,
name|eqnht
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lefteq
decl_stmt|,
name|righteq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lastchar
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last character read by lex */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|markline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 if this EQ/EN contains mark or lineup */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|s_tbl
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|defn
decl_stmt|;
name|struct
name|s_tbl
modifier|*
name|next
decl_stmt|;
block|}
name|tbl
typedef|;
end_typedef

end_unit

