begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* t..c : external declarations */
end_comment

begin_include
include|#
directive|include
file|"stdio.h"
end_include

begin_include
include|#
directive|include
file|"ctype.h"
end_include

begin_define
define|#
directive|define
name|MAXLIN
value|200
end_define

begin_define
define|#
directive|define
name|MAXHEAD
value|30
end_define

begin_define
define|#
directive|define
name|MAXCOL
value|20
end_define

begin_define
define|#
directive|define
name|MAXCHS
value|2000
end_define

begin_define
define|#
directive|define
name|MAXRPT
value|100
end_define

begin_define
define|#
directive|define
name|CLLEN
value|10
end_define

begin_define
define|#
directive|define
name|SHORTLINE
value|4
end_define

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

begin_struct
struct|struct
name|colstr
block|{
name|char
modifier|*
name|col
decl_stmt|,
modifier|*
name|rcol
decl_stmt|;
block|}
struct|;
end_struct

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
name|int
name|texname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|texct
decl_stmt|,
name|texmax
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
decl_stmt|,
modifier|*
name|tabout
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CRIGHT
value|80
end_define

begin_define
define|#
directive|define
name|CLEFT
value|40
end_define

begin_define
define|#
directive|define
name|CMID
value|60
end_define

begin_define
define|#
directive|define
name|S1
value|31
end_define

begin_define
define|#
directive|define
name|S2
value|32
end_define

begin_define
define|#
directive|define
name|TMP
value|38
end_define

begin_define
define|#
directive|define
name|SF
value|35
end_define

begin_define
define|#
directive|define
name|SL
value|34
end_define

begin_define
define|#
directive|define
name|LSIZE
value|33
end_define

begin_define
define|#
directive|define
name|SIND
value|37
end_define

begin_define
define|#
directive|define
name|SVS
value|36
end_define

begin_comment
comment|/* this refers to the relative position of lines */
end_comment

begin_define
define|#
directive|define
name|LEFT
value|1
end_define

begin_define
define|#
directive|define
name|RIGHT
value|2
end_define

begin_define
define|#
directive|define
name|THRU
value|3
end_define

begin_define
define|#
directive|define
name|TOP
value|1
end_define

begin_define
define|#
directive|define
name|BOT
value|2
end_define

end_unit

