begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 David I. Bell  * Permission is granted to use, distribute, or modify this source,  * provided that this copyright notice remains intact.  *  * Definitions for calculator program.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|"math.h"
end_include

begin_comment
comment|/*  * Configuration definitions  */
end_comment

begin_define
define|#
directive|define
name|CALCPATH
value|"CALCPATH"
end_define

begin_comment
comment|/* environment variable for files */
end_comment

begin_define
define|#
directive|define
name|CALCRC
value|"CALCRC"
end_define

begin_comment
comment|/* environment variable for startup */
end_comment

begin_define
define|#
directive|define
name|CALCBINDINGS
value|"CALCBINDINGS"
end_define

begin_comment
comment|/* environment variable for hist bindings */
end_comment

begin_define
define|#
directive|define
name|HOME
value|"HOME"
end_define

begin_comment
comment|/* environment variable for home dir */
end_comment

begin_define
define|#
directive|define
name|PAGER
value|"PAGER"
end_define

begin_comment
comment|/* environment variable for help */
end_comment

begin_define
define|#
directive|define
name|SHELL
value|"SHELL"
end_define

begin_comment
comment|/* environment variable for shell */
end_comment

begin_define
define|#
directive|define
name|DEFAULTCALCHELP
value|"help"
end_define

begin_comment
comment|/* help file that -h prints */
end_comment

begin_define
define|#
directive|define
name|DEFAULTSHELL
value|"sh"
end_define

begin_comment
comment|/* default shell to use */
end_comment

begin_define
define|#
directive|define
name|CALCEXT
value|".cal"
end_define

begin_comment
comment|/* extension for files read in */
end_comment

begin_define
define|#
directive|define
name|PATHSIZE
value|1024
end_define

begin_comment
comment|/* maximum length of path name */
end_comment

begin_define
define|#
directive|define
name|HOMECHAR
value|'~'
end_define

begin_comment
comment|/* char which indicates home directory */
end_comment

begin_define
define|#
directive|define
name|DOTCHAR
value|'.'
end_define

begin_comment
comment|/* char which indicates current directory */
end_comment

begin_define
define|#
directive|define
name|PATHCHAR
value|'/'
end_define

begin_comment
comment|/* char which separates path components */
end_comment

begin_define
define|#
directive|define
name|LISTCHAR
value|':'
end_define

begin_comment
comment|/* char which separates paths in a list */
end_comment

begin_define
define|#
directive|define
name|MAXCMD
value|1024
end_define

begin_comment
comment|/* maximum length of command invocation */
end_comment

begin_define
define|#
directive|define
name|MAXERROR
value|512
end_define

begin_comment
comment|/* maximum length of error message string */
end_comment

begin_define
define|#
directive|define
name|SYMBOLSIZE
value|256
end_define

begin_comment
comment|/* maximum symbol name size */
end_comment

begin_define
define|#
directive|define
name|MAXINDICES
value|20
end_define

begin_comment
comment|/* maximum number of indices for objects */
end_comment

begin_define
define|#
directive|define
name|MAXLABELS
value|100
end_define

begin_comment
comment|/* maximum number of user labels in function */
end_comment

begin_define
define|#
directive|define
name|MAXOBJECTS
value|10
end_define

begin_comment
comment|/* maximum number of object types */
end_comment

begin_define
define|#
directive|define
name|MAXDIM
value|4
end_define

begin_comment
comment|/* maximum number of dimensions in matrices */
end_comment

begin_define
define|#
directive|define
name|MAXSTRING
value|1024
end_define

begin_comment
comment|/* maximum size of string constant */
end_comment

begin_define
define|#
directive|define
name|MAXSTACK
value|1000
end_define

begin_comment
comment|/* maximum depth of evaluation stack */
end_comment

begin_define
define|#
directive|define
name|MAXFILES
value|20
end_define

begin_comment
comment|/* maximum number of opened files */
end_comment

begin_define
define|#
directive|define
name|PROMPT1
value|"> "
end_define

begin_comment
comment|/* normal prompt */
end_comment

begin_define
define|#
directive|define
name|PROMPT2
value|">> "
end_define

begin_comment
comment|/* prompt when inside multi-line input */
end_comment

begin_define
define|#
directive|define
name|TRACE_NORMAL
value|0x00
end_define

begin_comment
comment|/* normal trace flags */
end_comment

begin_define
define|#
directive|define
name|TRACE_OPCODES
value|0x01
end_define

begin_comment
comment|/* trace every opcode */
end_comment

begin_define
define|#
directive|define
name|TRACE_NODEBUG
value|0x02
end_define

begin_comment
comment|/* suppress debugging opcodes */
end_comment

begin_define
define|#
directive|define
name|TRACE_MAX
value|0x03
end_define

begin_comment
comment|/* maximum value for trace flag */
end_comment

begin_define
define|#
directive|define
name|DISPLAY_DEFAULT
value|20
end_define

begin_comment
comment|/* default digits for float display */
end_comment

begin_define
define|#
directive|define
name|EPSILON_DEFAULT
value|"1e-20"
end_define

begin_comment
comment|/* allowed error for float calculations */
end_comment

begin_define
define|#
directive|define
name|MAXPRINT_DEFAULT
value|16
end_define

begin_comment
comment|/* default number of elements printed */
end_comment

begin_define
define|#
directive|define
name|USUAL_ELEMENTS
value|4
end_define

begin_comment
comment|/* usual number of elements for object */
end_comment

begin_define
define|#
directive|define
name|ABORT_NONE
value|0
end_define

begin_comment
comment|/* abort not needed yet */
end_comment

begin_define
define|#
directive|define
name|ABORT_STATEMENT
value|1
end_define

begin_comment
comment|/* abort on statement boundary */
end_comment

begin_define
define|#
directive|define
name|ABORT_OPCODE
value|2
end_define

begin_comment
comment|/* abort on any opcode boundary */
end_comment

begin_define
define|#
directive|define
name|ABORT_MATH
value|3
end_define

begin_comment
comment|/* abort on any math operation */
end_comment

begin_define
define|#
directive|define
name|ABORT_NOW
value|4
end_define

begin_comment
comment|/* abort right away */
end_comment

begin_define
define|#
directive|define
name|CONFIG_MODE
value|1
end_define

begin_comment
comment|/* types of configuration parameters */
end_comment

begin_define
define|#
directive|define
name|CONFIG_DISPLAY
value|2
end_define

begin_define
define|#
directive|define
name|CONFIG_EPSILON
value|3
end_define

begin_define
define|#
directive|define
name|CONFIG_TRACE
value|4
end_define

begin_define
define|#
directive|define
name|CONFIG_MAXPRINT
value|5
end_define

begin_define
define|#
directive|define
name|CONFIG_MUL2
value|6
end_define

begin_define
define|#
directive|define
name|CONFIG_SQ2
value|7
end_define

begin_define
define|#
directive|define
name|CONFIG_POW2
value|8
end_define

begin_define
define|#
directive|define
name|CONFIG_REDC2
value|9
end_define

begin_comment
comment|/*  * Flags to modify results from the printvalue routine.  * These flags are OR'd together.  */
end_comment

begin_define
define|#
directive|define
name|PRINT_NORMAL
value|0x00
end_define

begin_comment
comment|/* print in normal manner */
end_comment

begin_define
define|#
directive|define
name|PRINT_SHORT
value|0x01
end_define

begin_comment
comment|/* print in short format (no elements) */
end_comment

begin_define
define|#
directive|define
name|PRINT_UNAMBIG
value|0x02
end_define

begin_comment
comment|/* print in non-ambiguous manner */
end_comment

begin_comment
comment|/*  * Definition of values of various types.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|value
name|VALUE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|object
name|OBJECT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|matrix
name|MATRIX
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|list
name|LIST
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|FILEID
typedef|;
end_typedef

begin_struct
struct|struct
name|value
block|{
name|short
name|v_type
decl_stmt|;
comment|/* type of value */
name|short
name|v_subtype
decl_stmt|;
comment|/* other data related to some types */
union|union
block|{
name|long
name|vv_int
decl_stmt|;
comment|/* small integer value */
name|FILEID
name|vv_file
decl_stmt|;
comment|/* id of opened file */
name|NUMBER
modifier|*
name|vv_num
decl_stmt|;
comment|/* arbitrary sized numeric value */
name|COMPLEX
modifier|*
name|vv_com
decl_stmt|;
comment|/* complex number */
name|VALUE
modifier|*
name|vv_addr
decl_stmt|;
comment|/* address of variable value */
name|MATRIX
modifier|*
name|vv_mat
decl_stmt|;
comment|/* address of matrix */
name|LIST
modifier|*
name|vv_list
decl_stmt|;
comment|/* address of list */
name|OBJECT
modifier|*
name|vv_obj
decl_stmt|;
comment|/* address of object */
name|char
modifier|*
name|vv_str
decl_stmt|;
comment|/* string value */
block|}
name|v_union
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * For ease in referencing  */
end_comment

begin_define
define|#
directive|define
name|v_int
value|v_union.vv_int
end_define

begin_define
define|#
directive|define
name|v_file
value|v_union.vv_file
end_define

begin_define
define|#
directive|define
name|v_num
value|v_union.vv_num
end_define

begin_define
define|#
directive|define
name|v_com
value|v_union.vv_com
end_define

begin_define
define|#
directive|define
name|v_addr
value|v_union.vv_addr
end_define

begin_define
define|#
directive|define
name|v_str
value|v_union.vv_str
end_define

begin_define
define|#
directive|define
name|v_mat
value|v_union.vv_mat
end_define

begin_define
define|#
directive|define
name|v_list
value|v_union.vv_list
end_define

begin_define
define|#
directive|define
name|v_obj
value|v_union.vv_obj
end_define

begin_define
define|#
directive|define
name|v_valid
value|v_union.vv_int
end_define

begin_comment
comment|/*  * Value types.  */
end_comment

begin_define
define|#
directive|define
name|V_NULL
value|0
end_define

begin_comment
comment|/* null value */
end_comment

begin_define
define|#
directive|define
name|V_INT
value|1
end_define

begin_comment
comment|/* normal integer */
end_comment

begin_define
define|#
directive|define
name|V_NUM
value|2
end_define

begin_comment
comment|/* number */
end_comment

begin_define
define|#
directive|define
name|V_COM
value|3
end_define

begin_comment
comment|/* complex number */
end_comment

begin_define
define|#
directive|define
name|V_ADDR
value|4
end_define

begin_comment
comment|/* address of variable value */
end_comment

begin_define
define|#
directive|define
name|V_STR
value|5
end_define

begin_comment
comment|/* address of string */
end_comment

begin_define
define|#
directive|define
name|V_MAT
value|6
end_define

begin_comment
comment|/* address of matrix structure */
end_comment

begin_define
define|#
directive|define
name|V_LIST
value|7
end_define

begin_comment
comment|/* address of list structure */
end_comment

begin_define
define|#
directive|define
name|V_OBJ
value|8
end_define

begin_comment
comment|/* address of object structure */
end_comment

begin_define
define|#
directive|define
name|V_FILE
value|9
end_define

begin_comment
comment|/* opened file id */
end_comment

begin_define
define|#
directive|define
name|V_MAX
value|9
end_define

begin_comment
comment|/* highest legal value */
end_comment

begin_define
define|#
directive|define
name|V_STRLITERAL
value|0
end_define

begin_comment
comment|/* string subtype for literal str */
end_comment

begin_define
define|#
directive|define
name|V_STRALLOC
value|1
end_define

begin_comment
comment|/* string subtype for allocated str */
end_comment

begin_define
define|#
directive|define
name|TWOVAL
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a) * (V_MAX+1) + (b))
end_define

begin_comment
comment|/* for switch of two values */
end_comment

begin_comment
comment|/*  * Structure of a matrix.  */
end_comment

begin_struct
struct|struct
name|matrix
block|{
name|long
name|m_dim
decl_stmt|;
comment|/* dimension of matrix */
name|long
name|m_size
decl_stmt|;
comment|/* total number of elements */
name|long
name|m_min
index|[
name|MAXDIM
index|]
decl_stmt|;
comment|/* minimum bound for indices */
name|long
name|m_max
index|[
name|MAXDIM
index|]
decl_stmt|;
comment|/* maximum bound for indices */
name|VALUE
name|m_table
index|[
literal|1
index|]
decl_stmt|;
comment|/* actually varying length table */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|matsize
parameter_list|(
name|n
parameter_list|)
value|(sizeof(MATRIX) - sizeof(VALUE) + ((n) * sizeof(VALUE)))
end_define

begin_comment
comment|/*  * List definitions.  * An individual list element.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|listelem
name|LISTELEM
typedef|;
end_typedef

begin_struct
struct|struct
name|listelem
block|{
name|LISTELEM
modifier|*
name|e_next
decl_stmt|;
comment|/* next element in list (or NULL) */
name|LISTELEM
modifier|*
name|e_prev
decl_stmt|;
comment|/* previous element in list (or NULL) */
name|VALUE
name|e_value
decl_stmt|;
comment|/* value of this element */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure for a list of elements.  */
end_comment

begin_struct
struct|struct
name|list
block|{
name|LISTELEM
modifier|*
name|l_first
decl_stmt|;
comment|/* first list element (or NULL) */
name|LISTELEM
modifier|*
name|l_last
decl_stmt|;
comment|/* last list element (or NULL) */
name|LISTELEM
modifier|*
name|l_cache
decl_stmt|;
comment|/* cached list element (or NULL) */
name|long
name|l_cacheindex
decl_stmt|;
comment|/* index of cached element (or undefined) */
name|long
name|l_count
decl_stmt|;
comment|/* total number of elements in the list */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|void
name|insertlistfirst
argument_list|()
decl_stmt|,
name|insertlistlast
argument_list|()
decl_stmt|,
name|insertlistmiddle
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|removelistfirst
argument_list|()
decl_stmt|,
name|removelistlast
argument_list|()
decl_stmt|,
name|removelistmiddle
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|listfree
argument_list|()
decl_stmt|,
name|listprint
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|listsearch
argument_list|()
decl_stmt|,
name|listrsearch
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|BOOL
name|listcmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VALUE
modifier|*
name|listindex
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|LIST
modifier|*
name|listalloc
argument_list|()
decl_stmt|,
modifier|*
name|listcopy
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Object actions.  */
end_comment

begin_define
define|#
directive|define
name|OBJ_PRINT
value|0
end_define

begin_comment
comment|/* print the value */
end_comment

begin_define
define|#
directive|define
name|OBJ_ONE
value|1
end_define

begin_comment
comment|/* create the multiplicative identity */
end_comment

begin_define
define|#
directive|define
name|OBJ_TEST
value|2
end_define

begin_comment
comment|/* test a value for "zero" */
end_comment

begin_define
define|#
directive|define
name|OBJ_ADD
value|3
end_define

begin_comment
comment|/* add two values */
end_comment

begin_define
define|#
directive|define
name|OBJ_SUB
value|4
end_define

begin_comment
comment|/* subtrace one value from another */
end_comment

begin_define
define|#
directive|define
name|OBJ_NEG
value|5
end_define

begin_comment
comment|/* negate a value */
end_comment

begin_define
define|#
directive|define
name|OBJ_MUL
value|6
end_define

begin_comment
comment|/* multiply two values */
end_comment

begin_define
define|#
directive|define
name|OBJ_DIV
value|7
end_define

begin_comment
comment|/* divide one value by another */
end_comment

begin_define
define|#
directive|define
name|OBJ_INV
value|8
end_define

begin_comment
comment|/* invert a value */
end_comment

begin_define
define|#
directive|define
name|OBJ_ABS
value|9
end_define

begin_comment
comment|/* take absolute value of value */
end_comment

begin_define
define|#
directive|define
name|OBJ_NORM
value|10
end_define

begin_comment
comment|/* take the norm of a value */
end_comment

begin_define
define|#
directive|define
name|OBJ_CONJ
value|11
end_define

begin_comment
comment|/* take the conjugate of a value */
end_comment

begin_define
define|#
directive|define
name|OBJ_POW
value|12
end_define

begin_comment
comment|/* take the power function */
end_comment

begin_define
define|#
directive|define
name|OBJ_SGN
value|13
end_define

begin_comment
comment|/* return the sign of a value */
end_comment

begin_define
define|#
directive|define
name|OBJ_CMP
value|14
end_define

begin_comment
comment|/* compare two values for equality */
end_comment

begin_define
define|#
directive|define
name|OBJ_REL
value|15
end_define

begin_comment
comment|/* compare two values for inequality */
end_comment

begin_define
define|#
directive|define
name|OBJ_QUO
value|16
end_define

begin_comment
comment|/* integer quotient of values */
end_comment

begin_define
define|#
directive|define
name|OBJ_MOD
value|17
end_define

begin_comment
comment|/* remainder of division of values */
end_comment

begin_define
define|#
directive|define
name|OBJ_INT
value|18
end_define

begin_comment
comment|/* integer part of */
end_comment

begin_define
define|#
directive|define
name|OBJ_FRAC
value|19
end_define

begin_comment
comment|/* fractional part of */
end_comment

begin_define
define|#
directive|define
name|OBJ_INC
value|20
end_define

begin_comment
comment|/* increment by one */
end_comment

begin_define
define|#
directive|define
name|OBJ_DEC
value|21
end_define

begin_comment
comment|/* decrement by one */
end_comment

begin_define
define|#
directive|define
name|OBJ_SQUARE
value|22
end_define

begin_comment
comment|/* square value */
end_comment

begin_define
define|#
directive|define
name|OBJ_SCALE
value|23
end_define

begin_comment
comment|/* scale by power of two */
end_comment

begin_define
define|#
directive|define
name|OBJ_SHIFT
value|24
end_define

begin_comment
comment|/* shift left (or right) by number of bits */
end_comment

begin_define
define|#
directive|define
name|OBJ_ROUND
value|25
end_define

begin_comment
comment|/* round to specified decimal places */
end_comment

begin_define
define|#
directive|define
name|OBJ_BROUND
value|26
end_define

begin_comment
comment|/* round to specified binary places */
end_comment

begin_define
define|#
directive|define
name|OBJ_ROOT
value|27
end_define

begin_comment
comment|/* take nth root of value */
end_comment

begin_define
define|#
directive|define
name|OBJ_SQRT
value|28
end_define

begin_comment
comment|/* take square root of value */
end_comment

begin_define
define|#
directive|define
name|OBJ_MAXFUNC
value|28
end_define

begin_comment
comment|/* highest function */
end_comment

begin_comment
comment|/*  * Definition of an object type.  * This is actually a varying sized structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name of object */
name|int
name|count
decl_stmt|;
comment|/* number of elements defined */
name|int
name|actions
index|[
name|OBJ_MAXFUNC
operator|+
literal|1
index|]
decl_stmt|;
comment|/* function indices for actions */
name|int
name|elements
index|[
literal|1
index|]
decl_stmt|;
comment|/* element indexes (MUST BE LAST) */
block|}
name|OBJECTACTIONS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|objectactionsize
parameter_list|(
name|elements
parameter_list|)
define|\
value|(sizeof(OBJECTACTIONS) + ((elements) - 1) * sizeof(int))
end_define

begin_comment
comment|/*  * Structure of an object.  * This is actually a varying sized structure.  * However, there are always at least USUAL_ELEMENTS values in the object.  */
end_comment

begin_struct
struct|struct
name|object
block|{
name|OBJECTACTIONS
modifier|*
name|o_actions
decl_stmt|;
comment|/* action table for this object */
name|VALUE
name|o_table
index|[
name|USUAL_ELEMENTS
index|]
decl_stmt|;
comment|/* object values (MUST BE LAST) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|objectsize
parameter_list|(
name|elements
parameter_list|)
define|\
value|(sizeof(OBJECT) + ((elements) - USUAL_ELEMENTS) * sizeof(VALUE))
end_define

begin_comment
comment|/*  * File ids corresponding to standard in, out, error, and when not in use.  */
end_comment

begin_define
define|#
directive|define
name|FILEID_STDIN
value|((FILEID)0)
end_define

begin_define
define|#
directive|define
name|FILEID_STDOUT
value|((FILEID)1)
end_define

begin_define
define|#
directive|define
name|FILEID_STDERR
value|((FILEID)2)
end_define

begin_define
define|#
directive|define
name|FILEID_NONE
value|((FILEID)-1)
end_define

begin_comment
comment|/*  * Common definitions  */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|maxprint
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of elements to print */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|abortlevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current level of aborts */
end_comment

begin_decl_stmt
specifier|extern
name|BOOL
name|inputwait
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if in a terminal input wait */
end_comment

begin_decl_stmt
specifier|extern
name|FLAG
name|traceflags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tracing flags */
end_comment

begin_decl_stmt
specifier|extern
name|VALUE
modifier|*
name|stack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* execution stack */
end_comment

begin_decl_stmt
specifier|extern
name|jmp_buf
name|jmpbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for errors */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|calcpath
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $CALCPATH or default */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|calcrc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $CALCRC or default */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|calcbindings
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $CALCBINDINGS or default */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|home
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $HOME or default */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|shell
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $SHELL or default */
end_comment

begin_comment
comment|/*  * Functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|MATRIX
modifier|*
name|matadd
argument_list|()
decl_stmt|,
modifier|*
name|matsub
argument_list|()
decl_stmt|,
modifier|*
name|matmul
argument_list|()
decl_stmt|,
modifier|*
name|matneg
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MATRIX
modifier|*
name|matalloc
argument_list|()
decl_stmt|,
modifier|*
name|matcopy
argument_list|()
decl_stmt|,
modifier|*
name|matsquare
argument_list|()
decl_stmt|,
modifier|*
name|matinv
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MATRIX
modifier|*
name|matscale
argument_list|()
decl_stmt|,
modifier|*
name|matmulval
argument_list|()
decl_stmt|,
modifier|*
name|matpowi
argument_list|()
decl_stmt|,
modifier|*
name|matconj
argument_list|()
decl_stmt|,
modifier|*
name|matquoval
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MATRIX
modifier|*
name|matmodval
argument_list|()
decl_stmt|,
modifier|*
name|matint
argument_list|()
decl_stmt|,
modifier|*
name|matfrac
argument_list|()
decl_stmt|,
modifier|*
name|matround
argument_list|()
decl_stmt|,
modifier|*
name|matbround
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MATRIX
modifier|*
name|mattrans
argument_list|()
decl_stmt|,
modifier|*
name|matcross
argument_list|()
decl_stmt|,
modifier|*
name|matshift
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|mattest
argument_list|()
decl_stmt|,
name|matcmp
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|matsearch
argument_list|()
decl_stmt|,
name|matrsearch
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|VALUE
name|matdet
argument_list|()
decl_stmt|,
name|matdot
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|matfill
argument_list|()
decl_stmt|,
name|matfree
argument_list|()
decl_stmt|,
name|matprint
argument_list|()
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|extern BOOL matisident();
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|OBJECT
modifier|*
name|objcopy
argument_list|()
decl_stmt|,
modifier|*
name|objalloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|VALUE
name|objcall
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|objfree
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|objuncache
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|addelement
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|defineobject
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|checkobject
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|showobjfuncs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|findelement
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|objoffset
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|freevalue
argument_list|()
decl_stmt|,
name|copyvalue
argument_list|()
decl_stmt|,
name|negvalue
argument_list|()
decl_stmt|,
name|addvalue
argument_list|()
decl_stmt|,
name|subvalue
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mulvalue
argument_list|()
decl_stmt|,
name|squarevalue
argument_list|()
decl_stmt|,
name|invertvalue
argument_list|()
decl_stmt|,
name|roundvalue
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|broundvalue
argument_list|()
decl_stmt|,
name|intvalue
argument_list|()
decl_stmt|,
name|fracvalue
argument_list|()
decl_stmt|,
name|incvalue
argument_list|()
decl_stmt|,
name|decvalue
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|conjvalue
argument_list|()
decl_stmt|,
name|sqrtvalue
argument_list|()
decl_stmt|,
name|rootvalue
argument_list|()
decl_stmt|,
name|absvalue
argument_list|()
decl_stmt|,
name|normvalue
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|shiftvalue
argument_list|()
decl_stmt|,
name|scalevalue
argument_list|()
decl_stmt|,
name|powivalue
argument_list|()
decl_stmt|,
name|powervalue
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|divvalue
argument_list|()
decl_stmt|,
name|quovalue
argument_list|()
decl_stmt|,
name|modvalue
argument_list|()
decl_stmt|,
name|printvalue
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|testvalue
argument_list|()
decl_stmt|,
name|comparevalue
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|FLAG
name|relvalue
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|FILEID
name|openid
argument_list|()
decl_stmt|,
name|indexid
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|validid
argument_list|()
decl_stmt|,
name|errorid
argument_list|()
decl_stmt|,
name|eofid
argument_list|()
decl_stmt|,
name|closeid
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|getcharid
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|idprintf
argument_list|()
decl_stmt|,
name|printid
argument_list|()
decl_stmt|,
name|flushid
argument_list|()
decl_stmt|,
name|readid
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|f_open
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|openstring
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|openterminal
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|opensearchfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nextchar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reread
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VALUE
name|builtinfunc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|NUMBER
modifier|*
name|constvalue
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|long
name|addnumber
argument_list|()
decl_stmt|,
name|addqconstant
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|long
name|linenumber
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|builtinname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|inputname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOL
name|inputisterminal
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|resetinput
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|nextline
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|calculate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|initstack
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dumpop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|version
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* print version string */
end_comment

begin_function_decl
specifier|extern
name|void
name|runrcfiles
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|getcommands
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|givehelp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|setprompt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|getconfig
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|setconfig
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|configtype
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|VARARGS
end_ifdef

begin_function_decl
name|void
name|error
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
name|void
name|error
parameter_list|(
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|error
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* END CODE */
end_comment

end_unit

