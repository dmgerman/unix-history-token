begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|dprintf
value|if(dbg)printf
end_define

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
name|Thru
value|020
end_define

begin_define
define|#
directive|define
name|Free
value|040
end_define

begin_define
define|#
directive|define
name|MARGIN
value|0.07
end_define

begin_comment
comment|/* default margin around data */
end_comment

begin_define
define|#
directive|define
name|SLOP
value|1.001
end_define

begin_comment
comment|/* slop for limits of for loops */
end_comment

begin_define
define|#
directive|define
name|FRAMEWID
value|3
end_define

begin_comment
comment|/* default width for boxes and ellipses */
end_comment

begin_define
define|#
directive|define
name|FRAMEHT
value|2
end_define

begin_comment
comment|/* default height and line length */
end_comment

begin_define
define|#
directive|define
name|TICKLEN
value|0.1
end_define

begin_define
define|#
directive|define
name|MAXNUM
value|200
end_define

begin_define
define|#
directive|define
name|XFLAG
value|01
end_define

begin_define
define|#
directive|define
name|YFLAG
value|02
end_define

begin_define
define|#
directive|define
name|INTICK
value|01
end_define

begin_define
define|#
directive|define
name|OUTICK
value|02
end_define

begin_define
define|#
directive|define
name|BOT
value|01
end_define

begin_define
define|#
directive|define
name|TOP
value|02
end_define

begin_define
define|#
directive|define
name|RIGHT
value|04
end_define

begin_define
define|#
directive|define
name|LEFT
value|010
end_define

begin_define
define|#
directive|define
name|RJUST
value|01
end_define

begin_define
define|#
directive|define
name|LJUST
value|02
end_define

begin_define
define|#
directive|define
name|ABOVE
value|04
end_define

begin_define
define|#
directive|define
name|BELOW
value|010
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

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|obj
modifier|*
name|obj
decl_stmt|;
name|double
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
name|Point
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|attr
block|{
comment|/* e.g., DASH 1.1 or "..." rjust size *.5 */
name|short
name|type
decl_stmt|;
name|double
name|fval
decl_stmt|;
name|char
modifier|*
name|sval
decl_stmt|;
name|short
name|just
decl_stmt|;
comment|/* justification, for STRING type */
name|short
name|op
decl_stmt|;
comment|/* optional operator, ditto */
name|struct
name|attr
modifier|*
name|next
decl_stmt|;
block|}
name|Attr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|obj
block|{
comment|/* a name and its properties */
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|val
decl_stmt|;
comment|/* body of define, etc. */
name|double
name|fval
decl_stmt|;
comment|/* if a numeric variable */
name|Point
name|pt
decl_stmt|;
comment|/* usually for max and min */
name|Point
name|pt1
decl_stmt|;
name|short
name|type
decl_stmt|;
comment|/* NAME, DEFNAME, ... */
name|short
name|first
decl_stmt|;
comment|/* 1 after 1st item seen */
name|short
name|coord
decl_stmt|;
comment|/* 1 if coord system specified for this name */
name|short
name|log
decl_stmt|;
comment|/* x, y, or z (= x+y) */
name|Attr
modifier|*
name|attr
decl_stmt|;
comment|/* DASH, etc., for now */
name|struct
name|obj
modifier|*
name|next
decl_stmt|;
block|}
name|Obj
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
comment|/* the yacc stack type */
name|int
name|i
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|;
name|double
name|f
decl_stmt|;
name|Point
name|pt
decl_stmt|;
name|Obj
modifier|*
name|op
decl_stmt|;
name|Attr
modifier|*
name|ap
decl_stmt|;
block|}
name|YYSTYPE
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|YYSTYPE
name|yylval
decl_stmt|,
name|yyval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dbg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ntext
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|num
index|[
name|MAXNUM
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nnum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ntick
decl_stmt|,
name|tside
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|calloc
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
name|tostring
argument_list|()
decl_stmt|,
modifier|*
name|grow
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|desc_str
argument_list|()
decl_stmt|,
modifier|*
name|ifstat
argument_list|()
decl_stmt|,
modifier|*
name|delimstr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|xyname
argument_list|()
decl_stmt|,
modifier|*
name|slprint
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|Obj
modifier|*
name|lookup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Obj
modifier|*
name|copythru
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|Obj
modifier|*
name|objlist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Attr
modifier|*
name|makeattr
argument_list|()
decl_stmt|,
modifier|*
name|makefattr
argument_list|()
decl_stmt|,
modifier|*
name|makesattr
argument_list|()
decl_stmt|,
modifier|*
name|addattr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|Point
name|makepoint
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|double
name|setvar
argument_list|()
decl_stmt|,
name|getvar
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lineno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|synerr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|codegen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tempfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|tfd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Point
name|ptmin
decl_stmt|,
name|ptmax
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|dflt_coord
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|curr_coord
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ncoord
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|auto_x
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|margin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|autoticks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pointsize
decl_stmt|,
name|ps_set
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sizeit
argument_list|()
decl_stmt|,
modifier|*
name|juststr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|log10
argument_list|()
decl_stmt|,
name|log
argument_list|()
decl_stmt|,
name|exp
argument_list|()
decl_stmt|,
name|sin
argument_list|()
decl_stmt|,
name|cos
argument_list|()
decl_stmt|,
name|sqrt
argument_list|()
decl_stmt|,
name|atof
argument_list|()
decl_stmt|,
name|errcheck
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|fabs
argument_list|()
decl_stmt|,
name|floor
argument_list|()
decl_stmt|,
name|ceil
argument_list|()
decl_stmt|,
name|moddouble
argument_list|()
decl_stmt|,
name|modceil
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|logit
parameter_list|(
name|x
parameter_list|)
value|(x) = log10(x)
end_define

begin_define
define|#
directive|define
name|Log10
parameter_list|(
name|x
parameter_list|)
value|errcheck(log10(x), "log")
end_define

begin_define
define|#
directive|define
name|Exp
parameter_list|(
name|x
parameter_list|)
value|errcheck(exp(x), "exp")
end_define

begin_define
define|#
directive|define
name|Sqrt
parameter_list|(
name|x
parameter_list|)
value|errcheck(sqrt(x), "sqrt")
end_define

begin_define
define|#
directive|define
name|min
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)<= (y)) ? (x) : (y))
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

end_unit

