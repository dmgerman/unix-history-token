begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	SC	A Table Calculator  *		Common definitions  *  *		original by James Gosling, September 1982  *		modified by Mark Weiser and Bruce Israel,  *			University of Maryland  *		R. Bond  12/86  *		More mods by Alan Silverstein, 3-4/88, see list of changes.  *		$Revision: 6.8 $  *  */
end_comment

begin_define
define|#
directive|define
name|ATBL
parameter_list|(
name|tbl
parameter_list|,
name|row
parameter_list|,
name|col
parameter_list|)
value|(*(tbl + row) + (col))
end_define

begin_define
define|#
directive|define
name|MINROWS
value|40
end_define

begin_comment
comment|/* minimum size at startup */
end_comment

begin_define
define|#
directive|define
name|MINCOLS
value|20
end_define

begin_define
define|#
directive|define
name|ABSMAXCOLS
value|702
end_define

begin_comment
comment|/* absolute cols: ZZ (base 26) */
end_comment

begin_define
define|#
directive|define
name|RESCOL
value|4
end_define

begin_comment
comment|/* columns reserved for row numbers */
end_comment

begin_define
define|#
directive|define
name|RESROW
value|3
end_define

begin_comment
comment|/* rows reserved for prompt, error, and column numbers */
end_comment

begin_define
define|#
directive|define
name|DEFWIDTH
value|10
end_define

begin_comment
comment|/* Default column width and precision */
end_comment

begin_define
define|#
directive|define
name|DEFPREC
value|2
end_define

begin_define
define|#
directive|define
name|HISTLEN
value|10
end_define

begin_comment
comment|/* Number of history entries for vi emulation */
end_comment

begin_define
define|#
directive|define
name|error
value|(void)move(1,0), (void)clrtoeol(), (void) printw
end_define

begin_define
define|#
directive|define
name|FBUFLEN
value|1024
end_define

begin_comment
comment|/* buffer size for a single field */
end_comment

begin_define
define|#
directive|define
name|PATHLEN
value|1024
end_define

begin_comment
comment|/* maximum path length */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|A_CHARTEXT
end_ifndef

begin_comment
comment|/* Should be defined in curses.h */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INTERNATIONAL
end_ifdef

begin_define
define|#
directive|define
name|A_CHARTEXT
value|0xff
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|A_CHARTEXT
value|0x7f
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|BSD42
argument_list|)
operator|||
name|defined
argument_list|(
name|BSD43
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|strrchr
argument_list|)
end_if

begin_define
define|#
directive|define
name|strrchr
value|rindex
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|ent_ptr
block|{
name|int
name|vf
decl_stmt|;
name|struct
name|ent
modifier|*
name|vp
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|range_s
block|{
name|struct
name|ent_ptr
name|left
decl_stmt|,
name|right
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Some not too obvious things about the flags:  *    is_valid means there is a valid number in v.  *    label set means it points to a valid constant string.  *    is_strexpr set means expr yields a string expression.  *    If is_strexpr is not set, and expr points to an expression tree, the  *        expression yields a numeric expression.  *    So, either v or label can be set to a constant.   *        Either (but not both at the same time) can be set from an expression.  */
end_comment

begin_define
define|#
directive|define
name|VALID_CELL
parameter_list|(
name|p
parameter_list|,
name|r
parameter_list|,
name|c
parameter_list|)
value|((p = *ATBL(tbl, r, c))&& \ 			     ((p->flags& is_valid) || p->label))
end_define

begin_struct
struct|struct
name|ent
block|{
name|double
name|v
decl_stmt|;
name|char
modifier|*
name|label
decl_stmt|;
name|struct
name|enode
modifier|*
name|expr
decl_stmt|;
name|short
name|flags
decl_stmt|;
name|short
name|row
decl_stmt|,
name|col
decl_stmt|;
name|struct
name|ent
modifier|*
name|next
decl_stmt|;
comment|/* next deleted ent */
name|struct
name|ent
modifier|*
name|evnext
decl_stmt|;
comment|/* next ent w/ a object to eval */
name|struct
name|ent
modifier|*
name|evprev
decl_stmt|;
comment|/* prev ent w/ a object to eval */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|range
block|{
name|struct
name|ent_ptr
name|r_left
decl_stmt|,
name|r_right
decl_stmt|;
name|char
modifier|*
name|r_name
decl_stmt|;
name|struct
name|range
modifier|*
name|r_next
decl_stmt|,
modifier|*
name|r_prev
decl_stmt|;
name|int
name|r_is_range
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FIX_ROW
value|1
end_define

begin_define
define|#
directive|define
name|FIX_COL
value|2
end_define

begin_struct
struct|struct
name|enode
block|{
name|int
name|op
decl_stmt|;
union|union
block|{
name|double
name|k
decl_stmt|;
name|struct
name|ent_ptr
name|v
decl_stmt|;
name|struct
name|range_s
name|r
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
struct|struct
block|{
name|struct
name|enode
modifier|*
name|left
decl_stmt|,
modifier|*
name|right
decl_stmt|;
block|}
name|o
struct|;
block|}
name|e
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* op values */
end_comment

begin_define
define|#
directive|define
name|O_VAR
value|'v'
end_define

begin_define
define|#
directive|define
name|O_CONST
value|'k'
end_define

begin_define
define|#
directive|define
name|O_SCONST
value|'$'
end_define

begin_define
define|#
directive|define
name|REDUCE
value|0200
end_define

begin_comment
comment|/* Or'ed into OP if operand is a range */
end_comment

begin_define
define|#
directive|define
name|OP_BASE
value|256
end_define

begin_define
define|#
directive|define
name|ACOS
value|OP_BASE + 0
end_define

begin_define
define|#
directive|define
name|ASIN
value|OP_BASE + 1
end_define

begin_define
define|#
directive|define
name|ATAN
value|OP_BASE + 2
end_define

begin_define
define|#
directive|define
name|CEIL
value|OP_BASE + 3
end_define

begin_define
define|#
directive|define
name|COS
value|OP_BASE + 4
end_define

begin_define
define|#
directive|define
name|EXP
value|OP_BASE + 5
end_define

begin_define
define|#
directive|define
name|FABS
value|OP_BASE + 6
end_define

begin_define
define|#
directive|define
name|FLOOR
value|OP_BASE + 7
end_define

begin_define
define|#
directive|define
name|HYPOT
value|OP_BASE + 8
end_define

begin_define
define|#
directive|define
name|LOG
value|OP_BASE + 9
end_define

begin_define
define|#
directive|define
name|LOG10
value|OP_BASE + 10
end_define

begin_define
define|#
directive|define
name|POW
value|OP_BASE + 11
end_define

begin_define
define|#
directive|define
name|SIN
value|OP_BASE + 12
end_define

begin_define
define|#
directive|define
name|SQRT
value|OP_BASE + 13
end_define

begin_define
define|#
directive|define
name|TAN
value|OP_BASE + 14
end_define

begin_define
define|#
directive|define
name|DTR
value|OP_BASE + 15
end_define

begin_define
define|#
directive|define
name|RTD
value|OP_BASE + 16
end_define

begin_define
define|#
directive|define
name|MIN
value|OP_BASE + 17
end_define

begin_define
define|#
directive|define
name|MAX
value|OP_BASE + 18
end_define

begin_define
define|#
directive|define
name|RND
value|OP_BASE + 19
end_define

begin_define
define|#
directive|define
name|HOUR
value|OP_BASE + 20
end_define

begin_define
define|#
directive|define
name|MINUTE
value|OP_BASE + 21
end_define

begin_define
define|#
directive|define
name|SECOND
value|OP_BASE + 22
end_define

begin_define
define|#
directive|define
name|MONTH
value|OP_BASE + 23
end_define

begin_define
define|#
directive|define
name|DAY
value|OP_BASE + 24
end_define

begin_define
define|#
directive|define
name|YEAR
value|OP_BASE + 25
end_define

begin_define
define|#
directive|define
name|NOW
value|OP_BASE + 26
end_define

begin_define
define|#
directive|define
name|DATE
value|OP_BASE + 27
end_define

begin_define
define|#
directive|define
name|FMT
value|OP_BASE + 28
end_define

begin_define
define|#
directive|define
name|SUBSTR
value|OP_BASE + 29
end_define

begin_define
define|#
directive|define
name|STON
value|OP_BASE + 30
end_define

begin_define
define|#
directive|define
name|EQS
value|OP_BASE + 31
end_define

begin_define
define|#
directive|define
name|EXT
value|OP_BASE + 32
end_define

begin_define
define|#
directive|define
name|ELIST
value|OP_BASE + 33
end_define

begin_comment
comment|/* List of expressions */
end_comment

begin_define
define|#
directive|define
name|LMAX
value|OP_BASE + 34
end_define

begin_define
define|#
directive|define
name|LMIN
value|OP_BASE + 35
end_define

begin_define
define|#
directive|define
name|NVAL
value|OP_BASE + 36
end_define

begin_define
define|#
directive|define
name|SVAL
value|OP_BASE + 37
end_define

begin_define
define|#
directive|define
name|PV
value|OP_BASE + 38
end_define

begin_define
define|#
directive|define
name|FV
value|OP_BASE + 39
end_define

begin_define
define|#
directive|define
name|PMT
value|OP_BASE + 40
end_define

begin_define
define|#
directive|define
name|STINDEX
value|OP_BASE + 41
end_define

begin_define
define|#
directive|define
name|LOOKUP
value|OP_BASE + 42
end_define

begin_define
define|#
directive|define
name|ATAN2
value|OP_BASE + 43
end_define

begin_define
define|#
directive|define
name|INDEX
value|OP_BASE + 44
end_define

begin_define
define|#
directive|define
name|DTS
value|OP_BASE + 45
end_define

begin_define
define|#
directive|define
name|TTS
value|OP_BASE + 46
end_define

begin_define
define|#
directive|define
name|ABS
value|OP_BASE + 47
end_define

begin_define
define|#
directive|define
name|HLOOKUP
value|OP_BASE + 48
end_define

begin_define
define|#
directive|define
name|VLOOKUP
value|OP_BASE + 49
end_define

begin_define
define|#
directive|define
name|ROUND
value|OP_BASE + 50
end_define

begin_define
define|#
directive|define
name|IF
value|OP_BASE + 51
end_define

begin_comment
comment|/* flag values */
end_comment

begin_define
define|#
directive|define
name|is_valid
value|0001
end_define

begin_define
define|#
directive|define
name|is_changed
value|0002
end_define

begin_define
define|#
directive|define
name|is_strexpr
value|0004
end_define

begin_define
define|#
directive|define
name|is_leftflush
value|0010
end_define

begin_define
define|#
directive|define
name|is_deleted
value|0020
end_define

begin_define
define|#
directive|define
name|ctl
parameter_list|(
name|c
parameter_list|)
value|((c)&037)
end_define

begin_define
define|#
directive|define
name|ESC
value|033
end_define

begin_define
define|#
directive|define
name|DEL
value|0177
end_define

begin_define
define|#
directive|define
name|BYCOLS
value|1
end_define

begin_define
define|#
directive|define
name|BYROWS
value|2
end_define

begin_define
define|#
directive|define
name|BYGRAPH
value|4
end_define

begin_comment
comment|/* Future */
end_comment

begin_define
define|#
directive|define
name|TBL
value|1
end_define

begin_comment
comment|/* tblprint style output for 'tbl' */
end_comment

begin_define
define|#
directive|define
name|LATEX
value|2
end_define

begin_comment
comment|/* tblprint style output for 'LaTeX' */
end_comment

begin_define
define|#
directive|define
name|TEX
value|3
end_define

begin_comment
comment|/* tblprint style output for 'TeX' */
end_comment

begin_comment
comment|/* Types for etype() */
end_comment

begin_define
define|#
directive|define
name|NUM
value|1
end_define

begin_define
define|#
directive|define
name|STR
value|2
end_define

begin_define
define|#
directive|define
name|GROWAMT
value|10
end_define

begin_comment
comment|/* default minimum amount to grow */
end_comment

begin_define
define|#
directive|define
name|GROWNEW
value|1
end_define

begin_comment
comment|/* first time table */
end_comment

begin_define
define|#
directive|define
name|GROWROW
value|2
end_define

begin_comment
comment|/* add rows */
end_comment

begin_define
define|#
directive|define
name|GROWCOL
value|3
end_define

begin_define
define|#
directive|define
name|GROWBOTH
value|4
end_define

begin_decl_stmt
specifier|extern
name|struct
name|ent
modifier|*
modifier|*
modifier|*
name|tbl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|curfile
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|strow
decl_stmt|,
name|stcol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|currow
decl_stmt|,
name|curcol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|savedrow
decl_stmt|,
name|savedcol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|FullUpdate
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|maxrow
decl_stmt|,
name|maxcol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|maxrows
decl_stmt|,
name|maxcols
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # cells currently allocated */
end_comment

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|fwidth
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|precision
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|col_hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|row_hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|line
index|[
name|FBUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|linelim
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|changed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ent
modifier|*
name|to_fix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|showsc
decl_stmt|,
name|showsr
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|openout
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|coltoa
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|findhome
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|r_name
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|seval
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strrchr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|v_name
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|xmalloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
name|dolookup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
name|eval
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|RealEvalAll
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|are_ranges
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|atocol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|constant
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|etype
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fork
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|get_rcqual
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|growtbl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nmgetch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|writefile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfree
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|yn_ask
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|enode
modifier|*
name|copye
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|enode
modifier|*
name|new
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|enode
modifier|*
name|new_const
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|enode
modifier|*
name|new_range
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|enode
modifier|*
name|new_str
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|enode
modifier|*
name|new_var
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|ent
modifier|*
name|lookat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|range
modifier|*
name|find_range
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|EvalAll
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|Evalall
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|RealEvalOne
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|backcol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|backrow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|checkbounds
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|clearent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|closecol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|closeout
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|closerow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|colshow_op
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|colvalueize
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|colvalueize
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|copy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|copyent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|copyrtv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|decompile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|deletecol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|deleterow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|deraw
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doend
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doformat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dupcol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|duprow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|editexp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|edits
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|editv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|efree
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|erase_area
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|erasedb
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|eraser
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fill
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|flush_saved
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|forwcol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|forwrow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_ent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|go_last
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|goraw
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|help
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|hide_col
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|hide_row
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|hidecol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|hiderow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|index_arg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ins_string
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|insert_mode
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|insertcol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|insertrow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|kbd_again
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|label
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|let
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|list_arg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|list_range
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|moveto
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|num_search
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|one_arg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|opencol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|openrow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|printfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pullcells
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|range_arg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|readfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|repaint
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|resetkbd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rowshow_op
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rowvalueize
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|setauto
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|setiterations
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|setorder
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|showcol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|showdr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|showrow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|showstring
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|signals
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|slet
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|startshow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|str_search
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sync_refs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|syncref
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tblprintfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|three_arg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|two_arg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|two_arg_index
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|update
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|valueize_area
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_fd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|yyerror
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DOBACKUPS
end_ifdef

begin_function_decl
specifier|extern
name|int
name|backup_file
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|modflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Crypt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mdir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|prescale
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|extfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|propagation
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|calc_order
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|autocalc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|numeric
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|showcell
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|showtop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|loading
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|getrcqual
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tbl_style
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|progname
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|BSD42
operator|||
name|SYSIII
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|cbreak
end_ifndef

begin_define
define|#
directive|define
name|cbreak
value|crmode
end_define

begin_define
define|#
directive|define
name|nocbreak
value|nocrmode
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

