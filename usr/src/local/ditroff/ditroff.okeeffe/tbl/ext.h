begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)ext.h	1.3 (CWI) 86/11/13	*/
end_comment

begin_comment
comment|/*	t..c	4.2	83/10/13	*/
end_comment

begin_comment
comment|/* t..c : external declarations */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|nlin
decl_stmt|,
name|ncol
decl_stmt|,
name|iline
decl_stmt|,
name|nclin
decl_stmt|,
name|nslin
decl_stmt|,
name|qcol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|oldname
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
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
specifier|extern
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
specifier|extern
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
specifier|extern
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
specifier|extern
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
specifier|extern
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

begin_decl_stmt
specifier|extern
name|int
name|stynum
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|F1
decl_stmt|,
name|F2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
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
specifier|extern
name|int
name|fullbot
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|instead
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|expflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ctrflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|evenflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|evenup
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|boxflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dboxflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|linsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pr1403
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|linsize
decl_stmt|,
name|delim1
decl_stmt|,
name|delim2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|allflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|textflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|left1flg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rightl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|colstr
modifier|*
name|table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|cspace
decl_stmt|,
modifier|*
name|cstore
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|exstore
decl_stmt|,
modifier|*
name|exlim
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sep
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|used
index|[]
decl_stmt|,
name|lused
index|[]
decl_stmt|,
name|rused
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|linestop
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|leftover
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|last
decl_stmt|,
modifier|*
name|ifile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|texname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|texct
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|texstr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|linstart
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|tabin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pr1403
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dbg
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|reg
parameter_list|()
function_decl|;
end_function_decl

begin_extern
extern|extern device;
end_extern

end_unit

