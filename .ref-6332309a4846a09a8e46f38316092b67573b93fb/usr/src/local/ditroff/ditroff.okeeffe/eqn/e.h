begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|dprintf
value|if (dbg) printf
end_define

begin_define
define|#
directive|define
name|max
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)>= (y)) ? (x) : (y))
end_define

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

begin_define
define|#
directive|define
name|DEFGAP
value|-999
end_define

begin_comment
comment|/* default gap in piles */
end_comment

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
name|dps_set
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 => -p option used */
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
name|ft
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default font */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|display
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 => inline, 0 => .EQ/.EN */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|synerr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 if syntax error in this eqn */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|typesetter
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* typesetter name for -T... */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|minsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* min size it can print */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ttype
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* actual type of typesetter: */
end_comment

begin_define
define|#
directive|define
name|DEVCAT
value|1
end_define

begin_define
define|#
directive|define
name|DEV202
value|2
end_define

begin_define
define|#
directive|define
name|DEVAPS
value|3
end_define

begin_define
define|#
directive|define
name|DEVHAR
value|4
end_define

begin_define
define|#
directive|define
name|DEVVER
value|5
end_define

begin_define
define|#
directive|define
name|DEVPSC
value|6
end_define

begin_decl_stmt
specifier|extern
name|float
name|eht
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|ebase
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|eps
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
name|yylval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|eqnreg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
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

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|spaceval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use in place of normal \x (for pic) */
end_comment

begin_define
define|#
directive|define
name|String
value|01
end_define

begin_define
define|#
directive|define
name|Macro
value|02
end_define

begin_define
define|#
directive|define
name|File
value|04
end_define

begin_define
define|#
directive|define
name|Char
value|010
end_define

begin_define
define|#
directive|define
name|Free
value|040
end_define

begin_typedef
typedef|typedef
struct|struct
name|infile
block|{
name|FILE
modifier|*
name|fin
decl_stmt|;
name|char
modifier|*
name|fname
decl_stmt|;
name|int
name|lineno
decl_stmt|;
block|}
name|Infile
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* input source */
name|int
name|type
decl_stmt|;
comment|/* Macro, String, File */
name|char
modifier|*
name|sp
decl_stmt|;
comment|/* if String or Macro */
block|}
name|Src
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|Src
name|src
index|[]
decl_stmt|,
modifier|*
name|srcp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input source stack */
end_comment

begin_define
define|#
directive|define
name|MAXARGS
value|20
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* argument stack */
name|char
modifier|*
name|argstk
index|[
name|MAXARGS
index|]
decl_stmt|;
comment|/* pointers to args */
name|char
modifier|*
name|argval
decl_stmt|;
comment|/* points to space containing args */
block|}
name|Arg
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* font number and name */
name|int
name|ft
decl_stmt|;
name|char
name|name
index|[
literal|10
index|]
decl_stmt|;
block|}
name|Font
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|Font
name|ftstack
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Font
modifier|*
name|ftp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|szstack
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nszstack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Infile
name|infile
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Infile
modifier|*
name|curfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|grow
argument_list|()
decl_stmt|,
modifier|*
name|malloc
argument_list|()
decl_stmt|,
modifier|*
name|realloc
argument_list|()
decl_stmt|,
modifier|*
name|strsave
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|DPS
argument_list|()
decl_stmt|,
modifier|*
name|ABSPS
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|EM
argument_list|()
decl_stmt|,
name|REL
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tbl
modifier|*
name|lookup
argument_list|()
decl_stmt|,
modifier|*
name|keytbl
index|[]
decl_stmt|,
modifier|*
name|deftbl
index|[]
decl_stmt|,
modifier|*
name|restbl
index|[]
decl_stmt|;
end_decl_stmt

end_unit

