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
literal|"@(#)globals.c	1.3 (CWI) 86/11/13"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_comment
comment|/* t0.c: storage allocation */
end_comment

begin_empty
empty|#
end_empty

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
name|char
name|oldname
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for .lf kludge */
end_comment

begin_decl_stmt
name|int
name|expflg
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ctrflg
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|boxflg
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dboxflg
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tab
init|=
literal|'\t'
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|linsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointsize of lines to draw */
end_comment

begin_decl_stmt
name|int
name|delim1
decl_stmt|,
name|delim2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* eqn delimiters (for n specification) */
end_comment

begin_decl_stmt
name|int
name|evenup
index|[
name|MAXCOL
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Equal width column */
end_comment

begin_decl_stmt
name|int
name|evenflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|F1
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* First ``funny'' field delimiter */
end_comment

begin_decl_stmt
name|int
name|F2
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Second ``funny'' spanning indicator */
end_comment

begin_decl_stmt
name|int
name|allflg
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|leftover
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|textflg
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|left1flg
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Line left of first (output) column */
end_comment

begin_decl_stmt
name|int
name|rightl
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Line right of last (output) column */
end_comment

begin_decl_stmt
name|char
modifier|*
name|cstore
decl_stmt|,
modifier|*
name|cspace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|last
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|colstr
modifier|*
name|table
index|[
name|MAXLIN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Next arrays describe the real table. Could be put in a structure in  * future  */
end_comment

begin_decl_stmt
name|int
name|style
index|[
name|MAXHEAD
index|]
index|[
name|MAXCOL
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Style of column (l, a, etc.) */
end_comment

begin_decl_stmt
name|int
name|ctop
index|[
name|MAXHEAD
index|]
index|[
name|MAXCOL
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|font
index|[
name|MAXHEAD
index|]
index|[
name|MAXCOL
index|]
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fontstyle of column */
end_comment

begin_decl_stmt
name|char
name|csize
index|[
name|MAXHEAD
index|]
index|[
name|MAXCOL
index|]
index|[
literal|4
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointsize of column */
end_comment

begin_decl_stmt
name|char
name|vsize
index|[
name|MAXHEAD
index|]
index|[
name|MAXCOL
index|]
index|[
literal|4
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Vertical spacing (text blocks only */
end_comment

begin_decl_stmt
name|int
name|lefline
index|[
name|MAXHEAD
index|]
index|[
name|MAXCOL
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line left of specified columns */
end_comment

begin_decl_stmt
name|char
name|cll
index|[
name|MAXCOL
index|]
index|[
name|CLLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* minimum colwumn width wanted */
end_comment

begin_decl_stmt
name|int
name|sep
index|[
name|MAXCOL
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Separation between columns in n's */
end_comment

begin_decl_stmt
name|int
name|stynum
index|[
name|MAXLIN
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nslin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nclin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of columns in specification part */
end_comment

begin_decl_stmt
name|int
name|fullbot
index|[
name|MAXLIN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|instead
index|[
name|MAXLIN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|used
index|[
name|MAXCOL
index|]
decl_stmt|,
name|lused
index|[
name|MAXCOL
index|]
decl_stmt|,
name|rused
index|[
name|MAXCOL
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|linestop
index|[
name|MAXLIN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nlin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ncol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|qcol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* quantity of output columns (bwk) */
end_comment

begin_decl_stmt
name|int
name|iline
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input line counter */
end_comment

begin_decl_stmt
name|char
modifier|*
name|ifile
init|=
literal|"Input"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input file name */
end_comment

begin_comment
comment|/*  * current name of the diversion for textblocks  */
end_comment

begin_decl_stmt
name|char
name|texname
init|=
literal|'a'
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|texct
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* index in texstr */
end_comment

begin_comment
comment|/*  * possible names of diversions  */
end_comment

begin_decl_stmt
name|char
name|texstr
index|[]
init|=
literal|"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWYXZ0123456789"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|linstart
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|exstore
decl_stmt|,
modifier|*
name|exlim
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|tabin
comment|/*= stdin */
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pr1403
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dbg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debug flag */
end_comment

begin_comment
comment|/* Device dependencies */
end_comment

begin_decl_stmt
name|int
name|device
init|=
name|HARRIS
decl_stmt|;
end_decl_stmt

end_unit

