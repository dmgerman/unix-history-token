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
literal|"@(#)t0.c	4.2 8/11/83"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
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
file|"t..c"
end_include

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

begin_decl_stmt
name|int
name|pr1403
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|delim1
decl_stmt|,
name|delim2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evenup
index|[
name|MAXCOL
index|]
decl_stmt|,
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

begin_decl_stmt
name|int
name|F2
init|=
literal|0
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|int
name|rightl
init|=
literal|0
decl_stmt|;
end_decl_stmt

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
comment|/*char *rpt[MAXHEAD][MAXCOL];*/
end_comment

begin_comment
comment|/*char rpttx[MAXRPT];*/
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
decl_stmt|,
name|nclin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sep
index|[
name|MAXCOL
index|]
decl_stmt|;
end_decl_stmt

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
decl_stmt|,
name|ncol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|iline
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ifile
init|=
literal|"Input"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
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
name|FILE
modifier|*
name|tabout
comment|/* = stdout */
decl_stmt|;
end_decl_stmt

end_unit

