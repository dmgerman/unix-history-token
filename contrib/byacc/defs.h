begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: defs.h,v 1.57 2017/04/30 23:29:11 tom Exp $ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_comment
comment|/* __cplusplus, etc. */
end_comment

begin_define
define|#
directive|define
name|class
value|myClass
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|YYMAJOR
value|1
end_define

begin_define
define|#
directive|define
name|YYMINOR
value|9
end_define

begin_define
define|#
directive|define
name|CONCAT
parameter_list|(
name|first
parameter_list|,
name|second
parameter_list|)
value|first #second
end_define

begin_define
define|#
directive|define
name|CONCAT1
parameter_list|(
name|string
parameter_list|,
name|number
parameter_list|)
value|CONCAT(string, number)
end_define

begin_define
define|#
directive|define
name|CONCAT2
parameter_list|(
name|first
parameter_list|,
name|second
parameter_list|)
value|#first "." #second
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|YYPATCH
end_ifdef

begin_define
define|#
directive|define
name|VSTRING
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CONCAT2(a,b) CONCAT1(" ",YYPATCH)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VSTRING
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CONCAT2(a,b)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VERSION
value|VSTRING(YYMAJOR, YYMINOR)
end_define

begin_comment
comment|/*  machine-dependent definitions:			*/
end_comment

begin_comment
comment|/*  MAXCHAR is the largest unsigned character value	*/
end_comment

begin_comment
comment|/*  MAXTABLE is the maximum table size			*/
end_comment

begin_comment
comment|/*  YYINT is the smallest C integer type that can be	*/
end_comment

begin_comment
comment|/*	used to address a table of size MAXTABLE	*/
end_comment

begin_comment
comment|/*  MAXYYINT is the largest value of a YYINT		*/
end_comment

begin_comment
comment|/*  MINYYINT is the most negative value of a YYINT	*/
end_comment

begin_comment
comment|/*  BITS_PER_WORD is the number of bits in a C unsigned	*/
end_comment

begin_comment
comment|/*  WORDSIZE computes the number of words needed to	*/
end_comment

begin_comment
comment|/*	store n bits					*/
end_comment

begin_comment
comment|/*  BIT returns the value of the n-th bit starting	*/
end_comment

begin_comment
comment|/*	from r (0-indexed)				*/
end_comment

begin_comment
comment|/*  SETBIT sets the n-th bit starting from r		*/
end_comment

begin_define
define|#
directive|define
name|MAXCHAR
value|UCHAR_MAX
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MAXTABLE
end_ifndef

begin_define
define|#
directive|define
name|MAXTABLE
value|32500
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|MAXTABLE
operator|<=
name|SHRT_MAX
end_if

begin_define
define|#
directive|define
name|YYINT
value|short
end_define

begin_define
define|#
directive|define
name|MAXYYINT
value|SHRT_MAX
end_define

begin_define
define|#
directive|define
name|MINYYINT
value|SHRT_MIN
end_define

begin_elif
elif|#
directive|elif
name|MAXTABLE
operator|<=
name|INT_MAX
end_elif

begin_define
define|#
directive|define
name|YYINT
value|int
end_define

begin_define
define|#
directive|define
name|MAXYYINT
value|INT_MAX
end_define

begin_define
define|#
directive|define
name|MINYYINT
value|INT_MIN
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"MAXTABLE is too large for this machine architecture!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BITS_PER_WORD
value|((int) sizeof (unsigned) * CHAR_BIT)
end_define

begin_define
define|#
directive|define
name|WORDSIZE
parameter_list|(
name|n
parameter_list|)
value|(((n)+(BITS_PER_WORD-1))/BITS_PER_WORD)
end_define

begin_define
define|#
directive|define
name|BIT
parameter_list|(
name|r
parameter_list|,
name|n
parameter_list|)
value|((((r)[(n)/BITS_PER_WORD])>>((n)&(BITS_PER_WORD-1)))&1)
end_define

begin_define
define|#
directive|define
name|SETBIT
parameter_list|(
name|r
parameter_list|,
name|n
parameter_list|)
value|((r)[(n)/BITS_PER_WORD]|=((unsigned)1<<((n)&(BITS_PER_WORD-1))))
end_define

begin_comment
comment|/*  character names  */
end_comment

begin_define
define|#
directive|define
name|NUL
value|'\0'
end_define

begin_comment
comment|/*  the null character  */
end_comment

begin_define
define|#
directive|define
name|NEWLINE
value|'\n'
end_define

begin_comment
comment|/*  line feed  */
end_comment

begin_define
define|#
directive|define
name|SP
value|' '
end_define

begin_comment
comment|/*  space  */
end_comment

begin_define
define|#
directive|define
name|BS
value|'\b'
end_define

begin_comment
comment|/*  backspace  */
end_comment

begin_define
define|#
directive|define
name|HT
value|'\t'
end_define

begin_comment
comment|/*  horizontal tab  */
end_comment

begin_define
define|#
directive|define
name|VT
value|'\013'
end_define

begin_comment
comment|/*  vertical tab  */
end_comment

begin_define
define|#
directive|define
name|CR
value|'\r'
end_define

begin_comment
comment|/*  carriage return  */
end_comment

begin_define
define|#
directive|define
name|FF
value|'\f'
end_define

begin_comment
comment|/*  form feed  */
end_comment

begin_define
define|#
directive|define
name|QUOTE
value|'\''
end_define

begin_comment
comment|/*  single quote  */
end_comment

begin_define
define|#
directive|define
name|DOUBLE_QUOTE
value|'\"'
end_define

begin_comment
comment|/*  double quote  */
end_comment

begin_define
define|#
directive|define
name|BACKSLASH
value|'\\'
end_define

begin_comment
comment|/*  backslash  */
end_comment

begin_define
define|#
directive|define
name|UCH
parameter_list|(
name|c
parameter_list|)
value|(unsigned char)(c)
end_define

begin_comment
comment|/* defines for constructing filenames */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VMS
argument_list|)
end_if

begin_define
define|#
directive|define
name|CODE_SUFFIX
value|"_code.c"
end_define

begin_define
define|#
directive|define
name|DEFINES_SUFFIX
value|"_tab.h"
end_define

begin_define
define|#
directive|define
name|EXTERNS_SUFFIX
value|"_tab.i"
end_define

begin_define
define|#
directive|define
name|OUTPUT_SUFFIX
value|"_tab.c"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CODE_SUFFIX
value|".code.c"
end_define

begin_define
define|#
directive|define
name|DEFINES_SUFFIX
value|".tab.h"
end_define

begin_define
define|#
directive|define
name|EXTERNS_SUFFIX
value|".tab.i"
end_define

begin_define
define|#
directive|define
name|OUTPUT_SUFFIX
value|".tab.c"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VERBOSE_SUFFIX
value|".output"
end_define

begin_define
define|#
directive|define
name|GRAPH_SUFFIX
value|".dot"
end_define

begin_comment
comment|/* keyword codes */
end_comment

begin_define
define|#
directive|define
name|TOKEN
value|0
end_define

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
name|NONASSOC
value|3
end_define

begin_define
define|#
directive|define
name|MARK
value|4
end_define

begin_define
define|#
directive|define
name|TEXT
value|5
end_define

begin_define
define|#
directive|define
name|TYPE
value|6
end_define

begin_define
define|#
directive|define
name|START
value|7
end_define

begin_define
define|#
directive|define
name|UNION
value|8
end_define

begin_define
define|#
directive|define
name|IDENT
value|9
end_define

begin_define
define|#
directive|define
name|EXPECT
value|10
end_define

begin_define
define|#
directive|define
name|EXPECT_RR
value|11
end_define

begin_define
define|#
directive|define
name|PURE_PARSER
value|12
end_define

begin_define
define|#
directive|define
name|PARSE_PARAM
value|13
end_define

begin_define
define|#
directive|define
name|LEX_PARAM
value|14
end_define

begin_define
define|#
directive|define
name|POSIX_YACC
value|15
end_define

begin_define
define|#
directive|define
name|TOKEN_TABLE
value|16
end_define

begin_define
define|#
directive|define
name|ERROR_VERBOSE
value|17
end_define

begin_define
define|#
directive|define
name|XXXDEBUG
value|18
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
end_if

begin_define
define|#
directive|define
name|LOCATIONS
value|19
end_define

begin_define
define|#
directive|define
name|DESTRUCTOR
value|20
end_define

begin_define
define|#
directive|define
name|INITIAL_ACTION
value|21
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  symbol classes  */
end_comment

begin_define
define|#
directive|define
name|UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|TERM
value|1
end_define

begin_define
define|#
directive|define
name|NONTERM
value|2
end_define

begin_define
define|#
directive|define
name|ACTION
value|3
end_define

begin_define
define|#
directive|define
name|ARGUMENT
value|4
end_define

begin_comment
comment|/*  the undefined value  */
end_comment

begin_define
define|#
directive|define
name|UNDEFINED
value|(-1)
end_define

begin_comment
comment|/*  action codes  */
end_comment

begin_define
define|#
directive|define
name|SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|REDUCE
value|2
end_define

begin_comment
comment|/*  character macros  */
end_comment

begin_define
define|#
directive|define
name|IS_IDENT
parameter_list|(
name|c
parameter_list|)
value|(isalnum(c) || (c) == '_' || (c) == '.' || (c) == '$')
end_define

begin_define
define|#
directive|define
name|IS_OCTAL
parameter_list|(
name|c
parameter_list|)
value|((c)>= '0'&& (c)<= '7')
end_define

begin_define
define|#
directive|define
name|NUMERIC_VALUE
parameter_list|(
name|c
parameter_list|)
value|((c) - '0')
end_define

begin_comment
comment|/*  symbol macros  */
end_comment

begin_define
define|#
directive|define
name|ISTOKEN
parameter_list|(
name|s
parameter_list|)
value|((s)< start_symbol)
end_define

begin_define
define|#
directive|define
name|ISVAR
parameter_list|(
name|s
parameter_list|)
value|((s)>= start_symbol)
end_define

begin_comment
comment|/*  storage allocation macros  */
end_comment

begin_define
define|#
directive|define
name|CALLOC
parameter_list|(
name|k
parameter_list|,
name|n
parameter_list|)
value|(calloc((size_t)(k),(size_t)(n)))
end_define

begin_define
define|#
directive|define
name|FREE
parameter_list|(
name|x
parameter_list|)
value|(free((char*)(x)))
end_define

begin_define
define|#
directive|define
name|MALLOC
parameter_list|(
name|n
parameter_list|)
value|(malloc((size_t)(n)))
end_define

begin_define
define|#
directive|define
name|TCMALLOC
parameter_list|(
name|t
parameter_list|,
name|n
parameter_list|)
value|((t*) calloc((size_t)(n), sizeof(t)))
end_define

begin_define
define|#
directive|define
name|TMALLOC
parameter_list|(
name|t
parameter_list|,
name|n
parameter_list|)
value|((t*) malloc((size_t)(n) * sizeof(t)))
end_define

begin_define
define|#
directive|define
name|NEW
parameter_list|(
name|t
parameter_list|)
value|((t*)allocate(sizeof(t)))
end_define

begin_define
define|#
directive|define
name|NEW2
parameter_list|(
name|n
parameter_list|,
name|t
parameter_list|)
value|((t*)allocate(((size_t)(n)*sizeof(t))))
end_define

begin_define
define|#
directive|define
name|REALLOC
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|(realloc((char*)(p),(size_t)(n)))
end_define

begin_define
define|#
directive|define
name|TREALLOC
parameter_list|(
name|t
parameter_list|,
name|p
parameter_list|,
name|n
parameter_list|)
value|((t*)realloc((char*)(p), (size_t)(n) * sizeof(t)))
end_define

begin_define
define|#
directive|define
name|DO_FREE
parameter_list|(
name|x
parameter_list|)
value|if (x) { FREE(x); x = 0; }
end_define

begin_define
define|#
directive|define
name|NO_SPACE
parameter_list|(
name|p
parameter_list|)
value|if (p == 0) no_space(); assert(p != 0)
end_define

begin_comment
comment|/* messages */
end_comment

begin_define
define|#
directive|define
name|PLURAL
parameter_list|(
name|n
parameter_list|)
value|((n)> 1 ? "s" : "")
end_define

begin_comment
comment|/*  * Features which depend indirectly on the btyacc configuration, but are not  * essential.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_HEADER_GUARDS
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|USE_HEADER_GUARDS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|char
name|Assoc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|Class_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|YYINT
name|Index_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|YYINT
name|Value_t
typedef|;
end_typedef

begin_comment
comment|/*  the structure of a symbol table entry  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|bucket
name|bucket
typedef|;
end_typedef

begin_struct
struct|struct
name|bucket
block|{
name|struct
name|bucket
modifier|*
name|link
decl_stmt|;
name|struct
name|bucket
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|tag
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
name|char
modifier|*
modifier|*
name|argnames
decl_stmt|;
name|char
modifier|*
modifier|*
name|argtags
decl_stmt|;
name|int
name|args
decl_stmt|;
name|char
modifier|*
name|destructor
decl_stmt|;
endif|#
directive|endif
name|Value_t
name|value
decl_stmt|;
name|Index_t
name|index
decl_stmt|;
name|Value_t
name|prec
decl_stmt|;
name|Class_t
name|class
decl_stmt|;
name|Assoc_t
name|assoc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  the structure of the LR(0) state machine  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|core
name|core
typedef|;
end_typedef

begin_struct
struct|struct
name|core
block|{
name|struct
name|core
modifier|*
name|next
decl_stmt|;
name|struct
name|core
modifier|*
name|link
decl_stmt|;
name|Value_t
name|number
decl_stmt|;
name|Value_t
name|accessing_symbol
decl_stmt|;
name|Value_t
name|nitems
decl_stmt|;
name|Value_t
name|items
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  the structure used to record shifts  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|shifts
name|shifts
typedef|;
end_typedef

begin_struct
struct|struct
name|shifts
block|{
name|struct
name|shifts
modifier|*
name|next
decl_stmt|;
name|Value_t
name|number
decl_stmt|;
name|Value_t
name|nshifts
decl_stmt|;
name|Value_t
name|shift
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  the structure used to store reductions  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|reductions
name|reductions
typedef|;
end_typedef

begin_struct
struct|struct
name|reductions
block|{
name|struct
name|reductions
modifier|*
name|next
decl_stmt|;
name|Value_t
name|number
decl_stmt|;
name|Value_t
name|nreds
decl_stmt|;
name|Value_t
name|rules
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  the structure used to represent parser actions  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|action
name|action
typedef|;
end_typedef

begin_struct
struct|struct
name|action
block|{
name|struct
name|action
modifier|*
name|next
decl_stmt|;
name|Value_t
name|symbol
decl_stmt|;
name|Value_t
name|number
decl_stmt|;
name|Value_t
name|prec
decl_stmt|;
name|char
name|action_code
decl_stmt|;
name|Assoc_t
name|assoc
decl_stmt|;
name|char
name|suppressed
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  the structure used to store parse/lex parameters  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|param
name|param
typedef|;
end_typedef

begin_struct
struct|struct
name|param
block|{
name|struct
name|param
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
comment|/* parameter name */
name|char
modifier|*
name|type
decl_stmt|;
comment|/* everything before parameter name */
name|char
modifier|*
name|type2
decl_stmt|;
comment|/* everything after parameter name */
block|}
struct|;
end_struct

begin_comment
comment|/* global variables */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|dflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|gflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|iflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|lflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|rflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|sflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|tflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|vflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|symbol_prefix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|myname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|cptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|line
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
name|outline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|exit_code
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pure_parser
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|token_table
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|error_verbose
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|locations
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|backtrack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|destructor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|initial_action
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|banner
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|xdecls
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|tables
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|global_vars
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|impure_vars
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|hdr_defs
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|hdr_vars
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|body_1
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|body_vars
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|init_vars
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|body_2
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|body_3
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|trailer
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|code_file_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|input_file_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|input_file_name_len
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|defines_file_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|externs_file_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|action_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|code_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|defines_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|externs_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|input_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|output_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|text_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|union_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|verbose_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|graph_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Value_t
name|nitems
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Value_t
name|nrules
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Value_t
name|nsyms
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Value_t
name|ntokens
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Value_t
name|nvars
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ntags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|unionized
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|line_format
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Value_t
name|start_symbol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|symbol_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|symbol_pname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Value_t
modifier|*
name|symbol_value
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Value_t
modifier|*
name|symbol_prec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|symbol_assoc
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|Value_t
modifier|*
name|symbol_pval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|symbol_destructor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|symbol_type_tag
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|Value_t
modifier|*
name|ritem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Value_t
modifier|*
name|rlhs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Value_t
modifier|*
name|rrhs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Value_t
modifier|*
name|rprec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Assoc_t
modifier|*
name|rassoc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Value_t
modifier|*
modifier|*
name|derives
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|nullable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bucket
modifier|*
name|first_symbol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bucket
modifier|*
name|last_symbol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nstates
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|core
modifier|*
name|first_state
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|shifts
modifier|*
name|first_shift
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|reductions
modifier|*
name|first_reduction
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Value_t
modifier|*
name|accessing_symbol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|core
modifier|*
modifier|*
name|state_table
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|shifts
modifier|*
modifier|*
name|shift_table
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|reductions
modifier|*
modifier|*
name|reduction_table
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
modifier|*
name|LA
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Value_t
modifier|*
name|LAruleno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Value_t
modifier|*
name|lookaheads
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Value_t
modifier|*
name|goto_base
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Value_t
modifier|*
name|goto_map
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Value_t
modifier|*
name|from_state
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Value_t
modifier|*
name|to_state
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|action
modifier|*
modifier|*
name|parser
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|SRexpect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|RRexpect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|SRtotal
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|RRtotal
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Value_t
modifier|*
name|SRconflicts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Value_t
modifier|*
name|RRconflicts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Value_t
modifier|*
name|defred
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Value_t
modifier|*
name|rules_used
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Value_t
name|nunused
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Value_t
name|final_state
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Value_t
modifier|*
name|itemset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Value_t
modifier|*
name|itemsetend
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
modifier|*
name|ruleset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|param
modifier|*
name|lex_param
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|param
modifier|*
name|parse_param
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* global functions */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_NORETURN
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__dead2
argument_list|)
end_if

begin_define
define|#
directive|define
name|GCC_NORETURN
value|__dead2
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__dead
argument_list|)
end_elif

begin_define
define|#
directive|define
name|GCC_NORETURN
value|__dead
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GCC_NORETURN
end_define

begin_comment
comment|/* nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_UNUSED
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__unused
argument_list|)
end_if

begin_define
define|#
directive|define
name|GCC_UNUSED
value|__unused
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GCC_UNUSED
end_define

begin_comment
comment|/* nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_PRINTFLIKE
end_ifndef

begin_define
define|#
directive|define
name|GCC_PRINTFLIKE
parameter_list|(
name|fmt
parameter_list|,
name|var
parameter_list|)
end_define

begin_comment
comment|/*nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* closure.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|closure
parameter_list|(
name|Value_t
modifier|*
name|nucleus
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finalize_closure
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_first_derives
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* error.c */
end_comment

begin_struct
struct|struct
name|ainfo
block|{
name|int
name|a_lineno
decl_stmt|;
name|char
modifier|*
name|a_line
decl_stmt|;
name|char
modifier|*
name|a_cptr
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
name|arg_number_disagree_warning
parameter_list|(
name|int
name|a_lineno
parameter_list|,
name|char
modifier|*
name|a_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|arg_type_disagree_warning
parameter_list|(
name|int
name|a_lineno
parameter_list|,
name|int
name|i
parameter_list|,
name|char
modifier|*
name|a_name
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|at_error
argument_list|(
name|int
name|a_lineno
argument_list|,
name|char
operator|*
name|a_line
argument_list|,
name|char
operator|*
name|a_cptr
argument_list|)
name|GCC_NORETURN
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|at_warning
parameter_list|(
name|int
name|a_lineno
parameter_list|,
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|bad_formals
argument_list|(
name|void
argument_list|)
name|GCC_NORETURN
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|default_action_warning
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|destructor_redeclared_warning
parameter_list|(
specifier|const
name|struct
name|ainfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|dollar_error
argument_list|(
name|int
name|a_lineno
argument_list|,
name|char
operator|*
name|a_line
argument_list|,
name|char
operator|*
name|a_cptr
argument_list|)
name|GCC_NORETURN
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|dollar_warning
parameter_list|(
name|int
name|a_lineno
parameter_list|,
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|fatal
argument_list|(
specifier|const
name|char
operator|*
name|msg
argument_list|)
name|GCC_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|illegal_character
argument_list|(
name|char
operator|*
name|c_cptr
argument_list|)
name|GCC_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|illegal_tag
argument_list|(
name|int
name|t_lineno
argument_list|,
name|char
operator|*
name|t_line
argument_list|,
name|char
operator|*
name|t_cptr
argument_list|)
name|GCC_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|missing_brace
argument_list|(
name|void
argument_list|)
name|GCC_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|no_grammar
argument_list|(
name|void
argument_list|)
name|GCC_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|no_space
argument_list|(
name|void
argument_list|)
name|GCC_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|open_error
argument_list|(
specifier|const
name|char
operator|*
name|filename
argument_list|)
name|GCC_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|over_unionized
argument_list|(
name|char
operator|*
name|u_cptr
argument_list|)
name|GCC_NORETURN
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|prec_redeclared
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reprec_warning
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|restarted_warning
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|retyped_warning
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|revalued_warning
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|start_requires_args
parameter_list|(
name|char
modifier|*
name|a_name
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|syntax_error
argument_list|(
name|int
name|st_lineno
argument_list|,
name|char
operator|*
name|st_line
argument_list|,
name|char
operator|*
name|st_cptr
argument_list|)
name|GCC_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|terminal_lhs
argument_list|(
name|int
name|s_lineno
argument_list|)
name|GCC_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|terminal_start
argument_list|(
name|char
operator|*
name|s
argument_list|)
name|GCC_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tokenized_start
argument_list|(
name|char
operator|*
name|s
argument_list|)
name|GCC_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|undefined_goal
argument_list|(
name|char
operator|*
name|s
argument_list|)
name|GCC_NORETURN
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|undefined_symbol_warning
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|unexpected_EOF
argument_list|(
name|void
argument_list|)
name|GCC_NORETURN
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|unknown_arg_warning
parameter_list|(
name|int
name|d_lineno
parameter_list|,
specifier|const
name|char
modifier|*
name|dlr_opt
parameter_list|,
specifier|const
name|char
modifier|*
name|d_arg
parameter_list|,
specifier|const
name|char
modifier|*
name|d_line
parameter_list|,
specifier|const
name|char
modifier|*
name|d_cptr
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|unknown_rhs
argument_list|(
name|int
name|i
argument_list|)
name|GCC_NORETURN
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|unsupported_flag_warning
parameter_list|(
specifier|const
name|char
modifier|*
name|flag
parameter_list|,
specifier|const
name|char
modifier|*
name|details
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|unterminated_action
argument_list|(
specifier|const
expr|struct
name|ainfo
operator|*
argument_list|)
name|GCC_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|unterminated_comment
argument_list|(
specifier|const
expr|struct
name|ainfo
operator|*
argument_list|)
name|GCC_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|unterminated_string
argument_list|(
specifier|const
expr|struct
name|ainfo
operator|*
argument_list|)
name|GCC_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|unterminated_text
argument_list|(
specifier|const
expr|struct
name|ainfo
operator|*
argument_list|)
name|GCC_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|unterminated_union
argument_list|(
specifier|const
expr|struct
name|ainfo
operator|*
argument_list|)
name|GCC_NORETURN
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|untyped_arg_warning
parameter_list|(
name|int
name|a_lineno
parameter_list|,
specifier|const
name|char
modifier|*
name|dlr_opt
parameter_list|,
specifier|const
name|char
modifier|*
name|a_name
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|untyped_lhs
argument_list|(
name|void
argument_list|)
name|GCC_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|untyped_rhs
argument_list|(
name|int
name|i
argument_list|,
name|char
operator|*
name|s
argument_list|)
name|GCC_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|used_reserved
argument_list|(
name|char
operator|*
name|s
argument_list|)
name|GCC_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|unterminated_arglist
argument_list|(
specifier|const
expr|struct
name|ainfo
operator|*
argument_list|)
name|GCC_NORETURN
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|wrong_number_args_warning
parameter_list|(
specifier|const
name|char
modifier|*
name|which
parameter_list|,
specifier|const
name|char
modifier|*
name|a_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|wrong_type_for_arg_warning
parameter_list|(
name|int
name|i
parameter_list|,
name|char
modifier|*
name|a_name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* graph.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|graph
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* lalr.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|lalr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* lr0.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|lr0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|show_cores
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|show_ritems
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|show_rrhs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|show_shifts
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* main.c */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|allocate
parameter_list|(
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|done
argument_list|(
name|int
name|k
argument_list|)
name|GCC_NORETURN
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mkpar.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|free_parser
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|make_parser
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* mstring.c */
end_comment

begin_struct
struct|struct
name|mstring
block|{
name|char
modifier|*
name|base
decl_stmt|,
modifier|*
name|ptr
decl_stmt|,
modifier|*
name|end
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
name|msprintf
parameter_list|(
name|struct
name|mstring
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|GCC_PRINTFLIKE
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|int
name|mputchar
parameter_list|(
name|struct
name|mstring
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|mstring
modifier|*
name|msnew
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|msdone
parameter_list|(
name|struct
name|mstring
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|strnscmp
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|strnshash
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|mputc
parameter_list|(
name|m
parameter_list|,
name|ch
parameter_list|)
value|(((m)->ptr == (m)->end) \ 			 ? mputchar(m,ch) \ 			 : (*(m)->ptr++ = (char) (ch)))
end_define

begin_comment
comment|/* output.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|output
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* reader.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|reader
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* skeleton.c (generated by skel2c) */
end_comment

begin_function_decl
specifier|extern
name|void
name|write_section
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
specifier|const
name|char
modifier|*
specifier|const
name|section
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* symtab.c */
end_comment

begin_function_decl
specifier|extern
name|bucket
modifier|*
name|make_bucket
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bucket
modifier|*
name|lookup
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|create_symbol_table
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_symbol_table
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_symbols
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* verbose.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|verbose
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* warshall.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|reflexive_transitive_closure
parameter_list|(
name|unsigned
modifier|*
name|R
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_comment
comment|/* closure.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|print_closure
parameter_list|(
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_EFF
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_first_derives
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* lr0.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|print_derives
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NO_LEAKS
end_ifdef

begin_function_decl
specifier|extern
name|void
name|lr0_leaks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lalr_leaks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mkpar_leaks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|output_leaks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mstring_leaks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reader_leaks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

