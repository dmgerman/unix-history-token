begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pic.h	(Berkeley)	1.2	83/08/09	*/
end_comment

begin_define
define|#
directive|define
name|dprintf
value|if(dbg)printf
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
name|PI
value|3.141592654
end_define

begin_define
define|#
directive|define
name|PI2
value|PI/2
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

begin_define
define|#
directive|define
name|MAXOBJ
value|1200
end_define

begin_define
define|#
directive|define
name|MAXTEXT
value|1200
end_define

begin_define
define|#
directive|define
name|SYMTAB
value|200
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
name|struct
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
name|attr
block|{
comment|/* attribute of an object */
name|int
name|a_type
decl_stmt|;
name|YYSTYPE
name|a_val
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
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
comment|/* various attributes of interest */
name|int
name|o_dotdash
decl_stmt|;
comment|/* kludge in a dot/dash mode */
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
struct|;
end_struct

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

begin_struct
struct|struct
name|text
block|{
name|int
name|t_type
decl_stmt|;
name|char
modifier|*
name|t_val
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|dbg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|obj
modifier|*
name|objlist
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nobj
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|attr
name|attr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nattr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|text
name|text
index|[]
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
name|tostring
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
name|int
name|crop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|res
decl_stmt|,
name|DX
decl_stmt|,
name|DY
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|sxmin
decl_stmt|,
name|sxmax
decl_stmt|,
name|symin
decl_stmt|,
name|symax
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
name|struct
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
name|struct
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
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
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
name|struct
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
name|makebetween
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
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
name|float
name|atof
parameter_list|()
function_decl|;
end_function_decl

end_unit

