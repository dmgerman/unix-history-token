begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|dprintf
value|if(dbg)printf
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|PI
end_ifndef

begin_define
define|#
directive|define
name|PI
value|3.141592654
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DEFAULT
value|0
end_define

begin_define
define|#
directive|define
name|HEAD1
value|1
end_define

begin_define
define|#
directive|define
name|HEAD2
value|2
end_define

begin_define
define|#
directive|define
name|HEAD12
value|(HEAD1+HEAD2)
end_define

begin_define
define|#
directive|define
name|INVIS
value|4
end_define

begin_define
define|#
directive|define
name|CW_ARC
value|8
end_define

begin_comment
comment|/* clockwise arc */
end_comment

begin_define
define|#
directive|define
name|DOTBIT
value|16
end_define

begin_define
define|#
directive|define
name|DASHBIT
value|32
end_define

begin_define
define|#
directive|define
name|CENTER
value|01
end_define

begin_comment
comment|/* text attributes */
end_comment

begin_define
define|#
directive|define
name|LJUST
value|02
end_define

begin_define
define|#
directive|define
name|RJUST
value|04
end_define

begin_define
define|#
directive|define
name|ABOVE
value|010
end_define

begin_define
define|#
directive|define
name|BELOW
value|020
end_define

begin_define
define|#
directive|define
name|SPREAD
value|040
end_define

begin_define
define|#
directive|define
name|FILL
value|0100
end_define

begin_define
define|#
directive|define
name|SCALE
value|1.0
end_define

begin_comment
comment|/* default scale: units/inch */
end_comment

begin_define
define|#
directive|define
name|WID
value|0.75
end_define

begin_comment
comment|/* default width for boxes and ellipses */
end_comment

begin_define
define|#
directive|define
name|WID2
value|0.375
end_define

begin_define
define|#
directive|define
name|HT
value|0.5
end_define

begin_comment
comment|/* default height and line length */
end_comment

begin_define
define|#
directive|define
name|HT2
value|0.25
end_define

begin_comment
comment|/* because no floating init exprs! */
end_comment

begin_define
define|#
directive|define
name|HT5
value|0.1
end_define

begin_define
define|#
directive|define
name|HT10
value|0.05
end_define

begin_comment
comment|/* these have to be like so, so that we can write */
end_comment

begin_comment
comment|/* things like R& V, etc. */
end_comment

begin_define
define|#
directive|define
name|H
value|0
end_define

begin_define
define|#
directive|define
name|V
value|1
end_define

begin_define
define|#
directive|define
name|R_DIR
value|0
end_define

begin_define
define|#
directive|define
name|U_DIR
value|1
end_define

begin_define
define|#
directive|define
name|L_DIR
value|2
end_define

begin_define
define|#
directive|define
name|D_DIR
value|3
end_define

begin_define
define|#
directive|define
name|ishor
parameter_list|(
name|n
parameter_list|)
value|(((n)& V) == 0)
end_define

begin_define
define|#
directive|define
name|isvert
parameter_list|(
name|n
parameter_list|)
value|(((n)& V) != 0)
end_define

begin_define
define|#
directive|define
name|isright
parameter_list|(
name|n
parameter_list|)
value|((n) == R_DIR)
end_define

begin_define
define|#
directive|define
name|isleft
parameter_list|(
name|n
parameter_list|)
value|((n) == L_DIR)
end_define

begin_define
define|#
directive|define
name|isdown
parameter_list|(
name|n
parameter_list|)
value|((n) == D_DIR)
end_define

begin_define
define|#
directive|define
name|isup
parameter_list|(
name|n
parameter_list|)
value|((n) == U_DIR)
end_define

begin_typedef
typedef|typedef
struct|struct
name|Point
block|{
name|float
name|x
decl_stmt|;
name|float
name|y
decl_stmt|;
block|}
empty_stmt|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|obj
block|{
comment|/* stores various things in variable length */
name|int
name|o_type
decl_stmt|;
name|int
name|o_count
decl_stmt|;
comment|/* number of things */
name|int
name|o_nobj
decl_stmt|;
comment|/* index in objlist */
name|int
name|o_mode
decl_stmt|;
comment|/* hor or vert */
name|float
name|o_x
decl_stmt|;
comment|/* coord of "center" */
name|float
name|o_y
decl_stmt|;
name|int
name|o_nt1
decl_stmt|;
comment|/* 1st index in text[] for this object */
name|int
name|o_nt2
decl_stmt|;
comment|/* 2nd; difference is #text strings */
name|int
name|o_attr
decl_stmt|;
comment|/* HEAD, CW, INVIS go here */
name|int
name|o_size
decl_stmt|;
comment|/* linesize */
name|int
name|o_nhead
decl_stmt|;
comment|/* arrowhead style */
name|struct
name|symtab
modifier|*
name|o_symtab
decl_stmt|;
comment|/* symtab for [...] */
name|float
name|o_ddval
decl_stmt|;
comment|/* value of dot/dash expression */
name|float
name|o_val
index|[
literal|1
index|]
decl_stmt|;
comment|/* actually this will be> 1 in general */
comment|/* type is not always FLOAT!!!! */
block|}
name|obj
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
name|obj
modifier|*
name|o
decl_stmt|;
name|float
name|f
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

begin_struct
struct|struct
name|symtab
block|{
name|char
modifier|*
name|s_name
decl_stmt|;
name|int
name|s_type
decl_stmt|;
name|YYSTYPE
name|s_val
decl_stmt|;
name|struct
name|symtab
modifier|*
name|s_next
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* attribute of an object */
name|int
name|a_type
decl_stmt|;
name|int
name|a_sub
decl_stmt|;
name|YYSTYPE
name|a_val
decl_stmt|;
block|}
name|Attr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|t_type
decl_stmt|;
comment|/* CENTER, LJUST, etc. */
name|char
name|t_op
decl_stmt|;
comment|/* optional sign for size changes */
name|char
name|t_size
decl_stmt|;
comment|/* size, abs or rel */
name|char
modifier|*
name|t_val
decl_stmt|;
block|}
name|Text
typedef|;
end_typedef

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

begin_typedef
typedef|typedef
struct|struct
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

begin_decl_stmt
specifier|extern
name|Infile
name|infile
index|[]
decl_stmt|,
modifier|*
name|curfile
decl_stmt|;
end_decl_stmt

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
name|int
name|dbg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|obj
modifier|*
modifier|*
name|objlist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nobj
decl_stmt|,
name|nobjlist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Attr
modifier|*
name|attr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nattr
decl_stmt|,
name|nattrlist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Text
modifier|*
name|text
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ntextlist
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
name|int
name|ntext1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|curx
decl_stmt|,
name|cury
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hvmode
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
name|float
name|getfval
argument_list|()
decl_stmt|,
name|getcomp
argument_list|()
decl_stmt|,
name|getblkvar
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|YYSTYPE
name|getvar
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|symtab
modifier|*
name|lookup
argument_list|()
decl_stmt|,
modifier|*
name|makevar
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ifstat
argument_list|()
decl_stmt|,
modifier|*
name|delimstr
argument_list|()
decl_stmt|,
modifier|*
name|sprintgen
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|deltx
decl_stmt|,
name|delty
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
name|float
name|xmin
decl_stmt|,
name|ymin
decl_stmt|,
name|xmax
decl_stmt|,
name|ymax
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|obj
modifier|*
name|leftthing
argument_list|()
decl_stmt|,
modifier|*
name|boxgen
argument_list|()
decl_stmt|,
modifier|*
name|circgen
argument_list|()
decl_stmt|,
modifier|*
name|arcgen
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|obj
modifier|*
name|linegen
argument_list|()
decl_stmt|,
modifier|*
name|splinegen
argument_list|()
decl_stmt|,
modifier|*
name|movegen
argument_list|()
decl_stmt|,
modifier|*
name|textgen
argument_list|()
decl_stmt|,
modifier|*
name|plotgen
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|obj
modifier|*
name|troffgen
argument_list|()
decl_stmt|,
modifier|*
name|rightthing
argument_list|()
decl_stmt|,
modifier|*
name|blockgen
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|obj
modifier|*
name|makenode
argument_list|()
decl_stmt|,
modifier|*
name|makepos
argument_list|()
decl_stmt|,
modifier|*
name|fixpos
argument_list|()
decl_stmt|,
modifier|*
name|addpos
argument_list|()
decl_stmt|,
modifier|*
name|subpos
argument_list|()
decl_stmt|,
modifier|*
name|makebetween
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|obj
modifier|*
name|getpos
argument_list|()
decl_stmt|,
modifier|*
name|gethere
argument_list|()
decl_stmt|,
modifier|*
name|getfirst
argument_list|()
decl_stmt|,
modifier|*
name|getlast
argument_list|()
decl_stmt|,
modifier|*
name|getblock
argument_list|()
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|pushstack
block|{
name|float
name|p_x
decl_stmt|;
name|float
name|p_y
decl_stmt|;
name|int
name|p_hvmode
decl_stmt|;
name|float
name|p_xmin
decl_stmt|;
name|float
name|p_ymin
decl_stmt|;
name|float
name|p_xmax
decl_stmt|;
name|float
name|p_ymax
decl_stmt|;
name|struct
name|symtab
modifier|*
name|p_symtab
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|pushstack
name|stack
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nstack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cw
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|double
name|errcheck
parameter_list|()
function_decl|;
end_function_decl

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

end_unit

