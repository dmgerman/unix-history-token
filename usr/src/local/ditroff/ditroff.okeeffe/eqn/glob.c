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
literal|"@(#)glob.c	2.1 (CWI) 85/07/18"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
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
literal|200
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
name|ft
init|=
literal|'2'
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Font
name|ftstack
index|[
literal|10
index|]
init|=
block|{
literal|'2'
block|,
literal|"2"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bottom is global font */
end_comment

begin_decl_stmt
name|Font
modifier|*
name|ftp
init|=
name|ftstack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|szstack
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* non-zero if absolute size set at this level */
end_comment

begin_decl_stmt
name|int
name|nszstack
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|display
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=>display, 0=>.EQ/.EN */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|APS
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|typesetter
init|=
literal|"aps"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name for -T */
end_comment

begin_decl_stmt
name|int
name|ttype
init|=
name|DEVAPS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* type of typesetter today */
end_comment

begin_decl_stmt
name|int
name|res
init|=
literal|723
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* resolution of typesetter; dflt = 202 */
end_comment

begin_decl_stmt
name|int
name|minsize
init|=
literal|5
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* min size it can handle; ditto */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|typesetter
init|=
literal|"har"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttype
init|=
name|DEVHAR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* type of typesetter today */
end_comment

begin_decl_stmt
name|int
name|res
init|=
literal|1445
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* resolution of typesetter; dflt = har */
end_comment

begin_decl_stmt
name|int
name|minsize
init|=
literal|4
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* min size it can handle; ditto */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	char	*typesetter = "202";  *	int	ttype	= DEV202;	/* type of typesetter today  *	int	res	= 972;		/* resolution of typesetter; dflt = 202  *	int	minsize	= 5;		/* min size it can handle; ditto */
end_comment

begin_decl_stmt
name|int
name|synerr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 if syntax err in this eqn */
end_comment

begin_decl_stmt
name|float
name|eht
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|ebase
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|eps
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
name|float
name|eqnht
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* final height of equation */
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
name|markline
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 if this EQ/EN contains mark; 2 if lineup */
end_comment

end_unit

