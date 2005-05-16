begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**************************************************************** Copyright (C) Lucent Technologies 1997 All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that the copyright notice and this permission notice and warranty disclaimer appear in supporting documentation, and that the name Lucent Technologies or any of its entities not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  LUCENT DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL LUCENT OR ANY OF ITS ENTITIES BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. ****************************************************************/
end_comment

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_typedef
typedef|typedef
name|double
name|Awkfloat
typedef|;
end_typedef

begin_comment
comment|/* unsigned char is more trouble than it's worth */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uschar
typedef|;
end_typedef

begin_define
define|#
directive|define
name|xfree
parameter_list|(
name|a
parameter_list|)
value|{ if ((a) != NULL) { free((char *) a); a = NULL; } }
end_define

begin_define
define|#
directive|define
name|NN
parameter_list|(
name|p
parameter_list|)
value|((p) ? (p) : "(null)")
end_define

begin_comment
comment|/* guaranteed non-null for dprintf  */
end_comment

begin_define
define|#
directive|define
name|DEBUG
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_comment
comment|/* uses have to be doubly parenthesized */
end_comment

begin_define
define|#
directive|define
name|dprintf
parameter_list|(
name|x
parameter_list|)
value|if (dbg) printf x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|dprintf
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|compile_time
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 if compiling, 0 if running */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|safe
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0 => unsafe, 1 => safe */
end_comment

begin_define
define|#
directive|define
name|RECSIZE
value|(8 * 1024)
end_define

begin_comment
comment|/* sets limit on records, fields, etc., etc. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|recsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of current record, orig RECSIZE */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|FS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|RS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|ORS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|OFS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|OFMT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Awkfloat
modifier|*
name|NR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Awkfloat
modifier|*
name|FNR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Awkfloat
modifier|*
name|NF
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|FILENAME
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|SUBSEP
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Awkfloat
modifier|*
name|RSTART
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Awkfloat
modifier|*
name|RLENGTH
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|record
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* points to $0 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lineno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line number in awk program */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errorflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 if error has occurred */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|donefld
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 if record broken into fields */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|donerec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 if record is valid (no fld has changed */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|inputFS
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* FS at time of input, for field splitting */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dbg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|patbeg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* beginning of pattern matched */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|patlen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* length of pattern matched.  set in b.c */
end_comment

begin_comment
comment|/* Cell:  all information about a variable or constant */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Cell
block|{
name|uschar
name|ctype
decl_stmt|;
comment|/* OCELL, OBOOL, OJUMP, etc. */
name|uschar
name|csub
decl_stmt|;
comment|/* CCON, CTEMP, CFLD, etc. */
name|char
modifier|*
name|nval
decl_stmt|;
comment|/* name, for variables only */
name|char
modifier|*
name|sval
decl_stmt|;
comment|/* string value */
name|Awkfloat
name|fval
decl_stmt|;
comment|/* value as number */
name|int
name|tval
decl_stmt|;
comment|/* type info: STR|NUM|ARR|FCN|FLD|CON|DONTFREE */
name|struct
name|Cell
modifier|*
name|cnext
decl_stmt|;
comment|/* ptr to next if chained */
block|}
name|Cell
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|Array
block|{
comment|/* symbol table array */
name|int
name|nelem
decl_stmt|;
comment|/* elements in table right now */
name|int
name|size
decl_stmt|;
comment|/* size of tab */
name|Cell
modifier|*
modifier|*
name|tab
decl_stmt|;
comment|/* hash table pointers */
block|}
name|Array
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NSYMTAB
value|50
end_define

begin_comment
comment|/* initial size of a symbol table */
end_comment

begin_decl_stmt
specifier|extern
name|Array
modifier|*
name|symtab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Cell
modifier|*
name|nrloc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NR */
end_comment

begin_decl_stmt
specifier|extern
name|Cell
modifier|*
name|fnrloc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* FNR */
end_comment

begin_decl_stmt
specifier|extern
name|Cell
modifier|*
name|nfloc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NF */
end_comment

begin_decl_stmt
specifier|extern
name|Cell
modifier|*
name|rstartloc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* RSTART */
end_comment

begin_decl_stmt
specifier|extern
name|Cell
modifier|*
name|rlengthloc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* RLENGTH */
end_comment

begin_comment
comment|/* Cell.tval values: */
end_comment

begin_define
define|#
directive|define
name|NUM
value|01
end_define

begin_comment
comment|/* number value is valid */
end_comment

begin_define
define|#
directive|define
name|STR
value|02
end_define

begin_comment
comment|/* string value is valid */
end_comment

begin_define
define|#
directive|define
name|DONTFREE
value|04
end_define

begin_comment
comment|/* string space is not freeable */
end_comment

begin_define
define|#
directive|define
name|CON
value|010
end_define

begin_comment
comment|/* this is a constant */
end_comment

begin_define
define|#
directive|define
name|ARR
value|020
end_define

begin_comment
comment|/* this is an array */
end_comment

begin_define
define|#
directive|define
name|FCN
value|040
end_define

begin_comment
comment|/* this is a function name */
end_comment

begin_define
define|#
directive|define
name|FLD
value|0100
end_define

begin_comment
comment|/* this is a field $1, $2, ... */
end_comment

begin_define
define|#
directive|define
name|REC
value|0200
end_define

begin_comment
comment|/* this is $0 */
end_comment

begin_comment
comment|/* function types */
end_comment

begin_define
define|#
directive|define
name|FLENGTH
value|1
end_define

begin_define
define|#
directive|define
name|FSQRT
value|2
end_define

begin_define
define|#
directive|define
name|FEXP
value|3
end_define

begin_define
define|#
directive|define
name|FLOG
value|4
end_define

begin_define
define|#
directive|define
name|FINT
value|5
end_define

begin_define
define|#
directive|define
name|FSYSTEM
value|6
end_define

begin_define
define|#
directive|define
name|FRAND
value|7
end_define

begin_define
define|#
directive|define
name|FSRAND
value|8
end_define

begin_define
define|#
directive|define
name|FSIN
value|9
end_define

begin_define
define|#
directive|define
name|FCOS
value|10
end_define

begin_define
define|#
directive|define
name|FATAN
value|11
end_define

begin_define
define|#
directive|define
name|FTOUPPER
value|12
end_define

begin_define
define|#
directive|define
name|FTOLOWER
value|13
end_define

begin_define
define|#
directive|define
name|FFLUSH
value|14
end_define

begin_comment
comment|/* Node:  parse tree is made of nodes, with Cell's at bottom */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Node
block|{
name|int
name|ntype
decl_stmt|;
name|struct
name|Node
modifier|*
name|nnext
decl_stmt|;
name|int
name|lineno
decl_stmt|;
name|int
name|nobj
decl_stmt|;
name|struct
name|Node
modifier|*
name|narg
index|[
literal|1
index|]
decl_stmt|;
comment|/* variable: actual size set by calling malloc */
block|}
name|Node
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NIL
value|((Node *) 0)
end_define

begin_decl_stmt
specifier|extern
name|Node
modifier|*
name|winner
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Node
modifier|*
name|nullstat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Node
modifier|*
name|nullnode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ctypes */
end_comment

begin_define
define|#
directive|define
name|OCELL
value|1
end_define

begin_define
define|#
directive|define
name|OBOOL
value|2
end_define

begin_define
define|#
directive|define
name|OJUMP
value|3
end_define

begin_comment
comment|/* Cell subtypes: csub */
end_comment

begin_define
define|#
directive|define
name|CFREE
value|7
end_define

begin_define
define|#
directive|define
name|CCOPY
value|6
end_define

begin_define
define|#
directive|define
name|CCON
value|5
end_define

begin_define
define|#
directive|define
name|CTEMP
value|4
end_define

begin_define
define|#
directive|define
name|CNAME
value|3
end_define

begin_define
define|#
directive|define
name|CVAR
value|2
end_define

begin_define
define|#
directive|define
name|CFLD
value|1
end_define

begin_define
define|#
directive|define
name|CUNK
value|0
end_define

begin_comment
comment|/* bool subtypes */
end_comment

begin_define
define|#
directive|define
name|BTRUE
value|11
end_define

begin_define
define|#
directive|define
name|BFALSE
value|12
end_define

begin_comment
comment|/* jump subtypes */
end_comment

begin_define
define|#
directive|define
name|JEXIT
value|21
end_define

begin_define
define|#
directive|define
name|JNEXT
value|22
end_define

begin_define
define|#
directive|define
name|JBREAK
value|23
end_define

begin_define
define|#
directive|define
name|JCONT
value|24
end_define

begin_define
define|#
directive|define
name|JRET
value|25
end_define

begin_define
define|#
directive|define
name|JNEXTFILE
value|26
end_define

begin_comment
comment|/* node types */
end_comment

begin_define
define|#
directive|define
name|NVALUE
value|1
end_define

begin_define
define|#
directive|define
name|NSTAT
value|2
end_define

begin_define
define|#
directive|define
name|NEXPR
value|3
end_define

begin_decl_stmt
specifier|extern
name|int
name|pairstack
index|[]
decl_stmt|,
name|paircnt
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|notlegal
parameter_list|(
name|n
parameter_list|)
value|(n<= FIRSTTOKEN || n>= LASTTOKEN || proctab[n-FIRSTTOKEN] == nullproc)
end_define

begin_define
define|#
directive|define
name|isvalue
parameter_list|(
name|n
parameter_list|)
value|((n)->ntype == NVALUE)
end_define

begin_define
define|#
directive|define
name|isexpr
parameter_list|(
name|n
parameter_list|)
value|((n)->ntype == NEXPR)
end_define

begin_define
define|#
directive|define
name|isjump
parameter_list|(
name|n
parameter_list|)
value|((n)->ctype == OJUMP)
end_define

begin_define
define|#
directive|define
name|isexit
parameter_list|(
name|n
parameter_list|)
value|((n)->csub == JEXIT)
end_define

begin_define
define|#
directive|define
name|isbreak
parameter_list|(
name|n
parameter_list|)
value|((n)->csub == JBREAK)
end_define

begin_define
define|#
directive|define
name|iscont
parameter_list|(
name|n
parameter_list|)
value|((n)->csub == JCONT)
end_define

begin_define
define|#
directive|define
name|isnext
parameter_list|(
name|n
parameter_list|)
value|((n)->csub == JNEXT || (n)->csub == JNEXTFILE)
end_define

begin_define
define|#
directive|define
name|isret
parameter_list|(
name|n
parameter_list|)
value|((n)->csub == JRET)
end_define

begin_define
define|#
directive|define
name|isrec
parameter_list|(
name|n
parameter_list|)
value|((n)->tval& REC)
end_define

begin_define
define|#
directive|define
name|isfld
parameter_list|(
name|n
parameter_list|)
value|((n)->tval& FLD)
end_define

begin_define
define|#
directive|define
name|isstr
parameter_list|(
name|n
parameter_list|)
value|((n)->tval& STR)
end_define

begin_define
define|#
directive|define
name|isnum
parameter_list|(
name|n
parameter_list|)
value|((n)->tval& NUM)
end_define

begin_define
define|#
directive|define
name|isarr
parameter_list|(
name|n
parameter_list|)
value|((n)->tval& ARR)
end_define

begin_define
define|#
directive|define
name|isfcn
parameter_list|(
name|n
parameter_list|)
value|((n)->tval& FCN)
end_define

begin_define
define|#
directive|define
name|istrue
parameter_list|(
name|n
parameter_list|)
value|((n)->csub == BTRUE)
end_define

begin_define
define|#
directive|define
name|istemp
parameter_list|(
name|n
parameter_list|)
value|((n)->csub == CTEMP)
end_define

begin_define
define|#
directive|define
name|isargument
parameter_list|(
name|n
parameter_list|)
value|((n)->nobj == ARG)
end_define

begin_comment
comment|/* #define freeable(p)	(!((p)->tval& DONTFREE)) */
end_comment

begin_define
define|#
directive|define
name|freeable
parameter_list|(
name|p
parameter_list|)
value|( ((p)->tval& (STR|DONTFREE)) == STR )
end_define

begin_comment
comment|/* structures used by regular expression matching machinery, mostly b.c: */
end_comment

begin_define
define|#
directive|define
name|NCHARS
value|(256+3)
end_define

begin_comment
comment|/* 256 handles 8-bit chars; 128 does 7-bit */
end_comment

begin_comment
comment|/* watch out in match(), etc. */
end_comment

begin_define
define|#
directive|define
name|NSTATES
value|32
end_define

begin_typedef
typedef|typedef
struct|struct
name|rrow
block|{
name|long
name|ltype
decl_stmt|;
comment|/* long avoids pointer warnings on 64-bit */
union|union
block|{
name|int
name|i
decl_stmt|;
name|Node
modifier|*
name|np
decl_stmt|;
name|uschar
modifier|*
name|up
decl_stmt|;
block|}
name|lval
union|;
comment|/* because Al stores a pointer in it! */
name|int
modifier|*
name|lfollow
decl_stmt|;
block|}
name|rrow
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|fa
block|{
name|uschar
name|gototab
index|[
name|NSTATES
index|]
index|[
name|NCHARS
index|]
decl_stmt|;
name|uschar
name|out
index|[
name|NSTATES
index|]
decl_stmt|;
name|uschar
modifier|*
name|restr
decl_stmt|;
name|int
modifier|*
name|posns
index|[
name|NSTATES
index|]
decl_stmt|;
name|int
name|anchor
decl_stmt|;
name|int
name|use
decl_stmt|;
name|int
name|initstat
decl_stmt|;
name|int
name|curstat
decl_stmt|;
name|int
name|accept
decl_stmt|;
name|int
name|reset
decl_stmt|;
name|struct
name|rrow
name|re
index|[
literal|1
index|]
decl_stmt|;
comment|/* variable: actual size set by calling malloc */
block|}
name|fa
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"proto.h"
end_include

end_unit

