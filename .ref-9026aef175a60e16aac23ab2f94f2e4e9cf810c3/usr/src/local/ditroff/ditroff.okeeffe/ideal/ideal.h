begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	ideal.h	(CWI)	1.1	85/03/01	*/
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"stdas.h"
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_function_decl
specifier|extern
name|double
name|modf
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_typedef
typedef|typedef
name|int
name|boolean
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EPSILON
value|0.0001
end_define

begin_define
define|#
directive|define
name|PI
value|3.1415926535
end_define

begin_define
define|#
directive|define
name|INFINITY
value|1e30
end_define

begin_define
define|#
directive|define
name|INTERSIZE
value|20
end_define

begin_define
define|#
directive|define
name|POSSINTER
value|2
end_define

begin_define
define|#
directive|define
name|known
parameter_list|(
name|x
parameter_list|)
value|(!(((DEPPTR)x->left)->var || ((DEPPTR)x->right)->var))
end_define

begin_define
define|#
directive|define
name|fabs
parameter_list|(
name|z
parameter_list|)
value|((z>0)?z:-(z))
end_define

begin_define
define|#
directive|define
name|iabs
parameter_list|(
name|z
parameter_list|)
value|((z>0)?z:-(z))
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
value|(((x)>(y))?(x):(y))
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
value|(((x)<(y))?(x):(y))
end_define

begin_define
define|#
directive|define
name|Re
parameter_list|(
name|z
parameter_list|)
value|((DEPPTR)z->left)->coeff
end_define

begin_define
define|#
directive|define
name|Im
parameter_list|(
name|z
parameter_list|)
value|((DEPPTR)z->right)->coeff
end_define

begin_define
define|#
directive|define
name|ISREAL
parameter_list|(
name|z
parameter_list|)
value|(z->re_name> 0)
end_define

begin_define
define|#
directive|define
name|THENAME
parameter_list|(
name|z
parameter_list|)
value|(iabs(z->re_name))
end_define

begin_define
define|#
directive|define
name|arecollinear
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|)
value|(fabs((f-b)*(c-a)-(e-a)*(d-b))<EPSILON)
end_define

begin_define
define|#
directive|define
name|between
parameter_list|(
name|ax
parameter_list|,
name|ay
parameter_list|,
name|bx
parameter_list|,
name|by
parameter_list|,
name|cx
parameter_list|,
name|cy
parameter_list|)
value|((ax-bx)*(bx-cx)> 0 || (ay-by)*(by-cy)> 0)
end_define

begin_decl_stmt
specifier|extern
name|int
name|when_bug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|dbg
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|bug_on
value|dbg = TRUE
end_define

begin_define
define|#
directive|define
name|bug_off
value|dbg = FALSE
end_define

begin_define
define|#
directive|define
name|dprintf
value|if (dbg) fprintf(stderr,
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|filename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lineno
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|LIBFIL
value|1
end_define

begin_define
define|#
directive|define
name|SILENT
value|2
end_define

begin_define
define|#
directive|define
name|CHATTY
value|3
end_define

begin_decl_stmt
specifier|extern
name|boolean
name|radflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|wantout
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|dtor
parameter_list|(
name|x
parameter_list|)
value|x *= PI/180
end_define

begin_define
define|#
directive|define
name|rtod
parameter_list|(
name|x
parameter_list|)
value|x *= 180/PI
end_define

begin_comment
comment|/* these are codes for classification of intersection points */
end_comment

begin_define
define|#
directive|define
name|UNUSED
value|0
end_define

begin_define
define|#
directive|define
name|SIMPLE
value|1
end_define

begin_define
define|#
directive|define
name|AT0
value|2
end_define

begin_define
define|#
directive|define
name|AT1
value|3
end_define

begin_define
define|#
directive|define
name|COLLINEAR
value|4
end_define

begin_define
define|#
directive|define
name|ON0
value|5
end_define

begin_define
define|#
directive|define
name|ON1
value|6
end_define

begin_define
define|#
directive|define
name|TANGENT
value|7
end_define

begin_comment
comment|/* these are codes for setting up the list of intersections */
end_comment

begin_define
define|#
directive|define
name|INHERIT
value|0
end_define

begin_comment
comment|/* #define	SIMPLE		1 */
end_comment

begin_define
define|#
directive|define
name|EXTREMUM
value|2
end_define

begin_define
define|#
directive|define
name|INFLECTION
value|3
end_define

begin_define
define|#
directive|define
name|EXT0
value|4
end_define

begin_define
define|#
directive|define
name|EXT1
value|5
end_define

begin_define
define|#
directive|define
name|INFL0
value|6
end_define

begin_define
define|#
directive|define
name|INFL1
value|7
end_define

begin_define
define|#
directive|define
name|IGNORE
value|8
end_define

begin_define
define|#
directive|define
name|INBEGIN
value|0
end_define

begin_define
define|#
directive|define
name|OUTBEGIN
value|1
end_define

begin_define
define|#
directive|define
name|ONBEGIN
value|2
end_define

begin_comment
comment|/* structure definitions for data structures */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|EXPR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|tryfree
parameter_list|(
name|doomed
parameter_list|)
value|free((char *)doomed)
end_define

begin_typedef
typedef|typedef
struct|struct
name|stmtnode
block|{
comment|/* hooks together stmts in bodies */
name|struct
name|stmtnode
modifier|*
name|next
decl_stmt|;
name|EXPR
name|stmt
decl_stmt|;
name|int
name|kind
decl_stmt|;
block|}
name|STMTNODE
operator|,
typedef|*
name|STMTPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|boxnode
block|{
comment|/* hooks together box definitions */
name|struct
name|boxnode
modifier|*
name|next
decl_stmt|;
name|int
name|name
decl_stmt|;
name|STMTPTR
name|stmtlist
decl_stmt|;
block|}
name|BOXNODE
operator|,
typedef|*
name|BOXPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|namenode
block|{
comment|/* holds var lists and path names */
name|struct
name|namenode
modifier|*
name|next
decl_stmt|;
name|int
name|name
decl_stmt|;
block|}
name|NAMENODE
operator|,
typedef|*
name|NAMEPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|exprnode
block|{
comment|/* points to equations and bdlists */
name|struct
name|exprnode
modifier|*
name|next
decl_stmt|;
name|EXPR
name|expr
decl_stmt|;
block|}
name|EXPRNODE
operator|,
typedef|*
name|EXPRPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|putnode
block|{
comment|/* put statements */
name|int
name|name
decl_stmt|;
name|BOXPTR
name|parm
decl_stmt|;
name|int
name|p_or_c
decl_stmt|;
block|}
name|PUTNODE
operator|,
typedef|*
name|PUTPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|pen_node
block|{
comment|/* conn ... using statements */
name|EXPR
name|from
decl_stmt|,
name|to
decl_stmt|,
name|copies
decl_stmt|,
name|start
decl_stmt|,
name|end
decl_stmt|;
name|BOXPTR
name|pen
decl_stmt|;
block|}
name|PEN_NODE
operator|,
typedef|*
name|PENPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|miscnode
block|{
comment|/* opaque, draw handling */
name|int
name|info
decl_stmt|;
block|}
name|MISCNODE
operator|,
typedef|*
name|MISCPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|strnode
block|{
comment|/* strings */
name|int
name|command
decl_stmt|;
name|char
modifier|*
name|string
decl_stmt|;
name|EXPR
name|at
decl_stmt|;
block|}
name|STRNODE
operator|,
typedef|*
name|STRPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|exprintl
block|{
comment|/* internal node of expr tree */
name|boolean
name|leaf
decl_stmt|;
comment|/* always FALSE */
name|int
name|oper
decl_stmt|;
name|EXPR
name|left
decl_stmt|;
name|EXPR
name|right
decl_stmt|;
block|}
name|EXPRINTL
operator|,
typedef|*
name|INTLPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|exprextl
block|{
comment|/* external node of expr tree */
name|boolean
name|leaf
decl_stmt|;
comment|/* always TRUE */
union|union
name|u
block|{
name|struct
name|namenode
modifier|*
name|path
decl_stmt|;
name|float
specifier|const
expr_stmt|;
block|}
name|info
union|;
name|int
name|kind
decl_stmt|;
comment|/* should be one of PATH, CONST */
block|}
name|EXPREXTL
operator|,
typedef|*
name|EXTLPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|noad
block|{
comment|/* linked structures in which variables reside */
name|PUTPTR
name|defnode
decl_stmt|;
name|struct
name|varnode
modifier|*
name|edgevarlist
decl_stmt|;
name|struct
name|varnode
modifier|*
name|boxvarlist
decl_stmt|;
name|struct
name|linenode
modifier|*
name|linelist
decl_stmt|;
name|struct
name|noad
modifier|*
name|father
decl_stmt|;
name|struct
name|noad
modifier|*
name|brother
decl_stmt|;
name|struct
name|noad
modifier|*
name|son
decl_stmt|;
block|}
name|NOAD
operator|,
typedef|*
name|NOADPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|varnode
block|{
comment|/* where ONE variable--the real or imag part of a var--lives */
name|struct
name|varnode
modifier|*
name|next
decl_stmt|;
name|int
name|re_name
decl_stmt|;
comment|/* positive for real part, negative for imag part */
name|struct
name|depnode
modifier|*
name|deplist
decl_stmt|;
block|}
name|VARNODE
operator|,
typedef|*
name|VARPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|depnode
block|{
comment|/* a term in the dependency list representation of a variable */
name|struct
name|depnode
modifier|*
name|next
decl_stmt|;
name|VARPTR
name|var
decl_stmt|;
name|float
name|coeff
decl_stmt|;
block|}
name|DEPNODE
operator|,
typedef|*
name|DEPPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|linenode
block|{
comment|/* a line segment on linelist */
name|struct
name|linenode
modifier|*
name|next
decl_stmt|;
name|int
name|kind
decl_stmt|;
comment|/* always LINE */
name|float
name|x0
decl_stmt|,
name|y0
decl_stmt|,
name|x1
decl_stmt|,
name|y1
decl_stmt|;
block|}
name|LINENODE
operator|,
typedef|*
name|LINEPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|edgenode
block|{
comment|/* an edge of an opaque polygon */
name|struct
name|edgenode
modifier|*
name|next
decl_stmt|,
modifier|*
name|prev
decl_stmt|;
name|struct
name|arcnode
modifier|*
name|fax
decl_stmt|;
name|boolean
name|flipped
decl_stmt|;
name|float
name|sx
decl_stmt|,
name|sy
decl_stmt|,
comment|/* start point */
name|ex
decl_stmt|,
name|ey
decl_stmt|,
comment|/* end point */
name|stx
decl_stmt|,
name|sty
decl_stmt|,
comment|/* coords of endpt of a tan vector at start */
name|etx
decl_stmt|,
name|ety
decl_stmt|;
comment|/* coords of endpt of a tan vector at end */
name|int
name|code
index|[
name|POSSINTER
index|]
decl_stmt|;
name|float
name|alpha
index|[
name|POSSINTER
index|]
decl_stmt|;
block|}
name|EDGENODE
operator|,
typedef|*
name|EDGEPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|circnode
block|{
comment|/* a circle on linelist */
name|struct
name|linenode
modifier|*
name|next
decl_stmt|;
name|int
name|kind
decl_stmt|;
comment|/* always CIRCLE */
name|float
name|x0
decl_stmt|,
name|y0
decl_stmt|,
name|r
decl_stmt|;
block|}
name|CIRCNODE
operator|,
typedef|*
name|CIRCPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|arcnode
block|{
comment|/* an arc on linelist */
name|struct
name|linenode
modifier|*
name|next
decl_stmt|;
name|int
name|kind
decl_stmt|;
comment|/* always ARC */
name|float
name|x0
decl_stmt|,
name|y0
decl_stmt|,
name|x1
decl_stmt|,
name|y1
decl_stmt|,
name|x2
decl_stmt|,
name|y2
decl_stmt|,
name|theta1
decl_stmt|,
name|theta2
decl_stmt|,
name|radius
decl_stmt|;
comment|/* TROFF figures out the center depending on sign of radius */
block|}
name|ARCNODE
operator|,
typedef|*
name|ARCPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|textnode
block|{
comment|/* a string on linelist */
name|struct
name|linenode
modifier|*
name|next
decl_stmt|;
name|int
name|kind
decl_stmt|,
comment|/* always STRING */
name|command
decl_stmt|;
name|char
modifier|*
name|string
decl_stmt|;
name|float
name|x0
decl_stmt|,
name|y0
decl_stmt|;
block|}
name|TEXTNODE
operator|,
typedef|*
name|TEXTPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|splnode
block|{
comment|/* a spline on linelist */
name|struct
name|linenode
modifier|*
name|next
decl_stmt|;
name|int
name|kind
decl_stmt|;
comment|/* always SPLINE */
name|EXPRPTR
name|knotlist
decl_stmt|;
block|}
name|SPLNODE
operator|,
typedef|*
name|SPLPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|eqnnode
block|{
comment|/* a non-linear equation residing on list */
name|struct
name|eqnnode
modifier|*
name|next
decl_stmt|;
name|EXPR
name|eqn
decl_stmt|;
name|NOADPTR
name|noad
decl_stmt|;
block|}
name|EQNNODE
operator|,
typedef|*
name|EQNPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|opqnode
block|{
comment|/* an alpha or theta of intersection */
name|struct
name|opqnode
modifier|*
name|next
decl_stmt|;
name|int
name|code
decl_stmt|;
name|float
name|alpha
decl_stmt|;
block|}
name|OPQNODE
operator|,
typedef|*
name|OPQPTR
typedef|;
end_typedef

begin_comment
comment|/* routines in memut.c */
end_comment

begin_function_decl
specifier|extern
name|STMTPTR
name|stmtgen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOXPTR
name|boxgen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|NAMEPTR
name|namegen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|EXPRPTR
name|exprgen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|PUTPTR
name|putgen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|PENPTR
name|pengen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|MISCPTR
name|miscgen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|INTLPTR
name|intlgen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|INTLPTR
name|commagen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|EXTLPTR
name|extlgen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|EXTLPTR
name|fextlgen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|NOADPTR
name|noadgen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VARPTR
name|vargen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DEPPTR
name|depgen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|LINEPTR
name|linegen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|EDGEPTR
name|edgeline
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|LINEPTR
name|circgen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|LINEPTR
name|arcgen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|LINEPTR
name|angularc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|LINEPTR
name|pointarc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|EDGEPTR
name|edgearc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|LINEPTR
name|textgen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|LINEPTR
name|splgen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|STRPTR
name|strgen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|EQNPTR
name|eqngen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|OPQPTR
name|opqgen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nextfree
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|depfree
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|namefree
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|exprlsfree
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|linefree
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|intlfree
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|noadfree
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|varfree
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|exprfree
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|boxfree
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|emergency
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* routines in util.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|lookup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|idprint
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOXPTR
name|findbox
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|INTLPTR
name|varfind
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|INTLPTR
name|pathfind
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOXPTR
name|tail
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|forget
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|exprprint
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|STMTPTR
name|nextstmt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|EXPR
name|bracket
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|depprint
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dexch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fexch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|float
name|rprin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|float
name|dprin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|angorder
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|STMTPTR
name|reverse
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|impossible
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* routines in bldds.c */
end_comment

begin_function_decl
specifier|extern
name|NOADPTR
name|buildnoadtree
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VARPTR
name|buildvarlist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|NOADPTR
name|walkputlist
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* routines in simul.c */
end_comment

begin_function_decl
specifier|extern
name|DEPPTR
name|depadd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DEPPTR
name|depsubst
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* routines in exprn.c */
end_comment

begin_function_decl
specifier|extern
name|INTLPTR
name|expreval
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|eqndo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|depvarclean
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|depvarkill
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|eqneval
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nl_eval
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* routines in action.c */
end_comment

begin_function_decl
specifier|extern
name|LINEPTR
name|build
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|LINEPTR
name|connact
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|LINEPTR
name|penact
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|LINEPTR
name|drawact
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|LINEPTR
name|stract
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|LINEPTR
name|circact
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|LINEPTR
name|arcact
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|LINEPTR
name|splact
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* routines in piece.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|linecall
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|circcall
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|arccall
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|textcall
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|splcall
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|boundscall
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* routines in opaque.c */
end_comment

begin_function_decl
specifier|extern
name|LINEPTR
name|opqact
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|opqinsert
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|LINEPTR
name|lineclean
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|halfplane
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|triangle
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* routines in inter.c */
end_comment

begin_function_decl
specifier|extern
name|boolean
name|llinter
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|boolean
name|lcinter
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|boolean
name|ccinter
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* routines in opqpoly.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|opqpoly
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|polyline
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|polyarc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|linetest
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|arctest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* routines in opqcirc.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|opqcirc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|circline
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|circarc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* routines in opqsect.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|opqsect
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* routines in opqseg.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|opqseg
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* lexical analyzer routines */
end_comment

begin_function_decl
specifier|extern
name|void
name|filepush
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|filepop
parameter_list|()
function_decl|;
end_function_decl

end_unit

