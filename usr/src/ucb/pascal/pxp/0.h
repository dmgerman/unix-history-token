begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)0.h	5.1 (Berkeley) 6/5/85  */
end_comment

begin_comment
comment|/* #define DEBUG */
end_comment

begin_define
define|#
directive|define
name|CHAR
end_define

begin_define
define|#
directive|define
name|STATIC
end_define

begin_comment
comment|/*  * pxp - Pascal execution profiler  *  * Bill Joy  * University of California, Berkeley (UCB)  * Version 1.1 February 1978  */
end_comment

begin_comment
comment|/*  * Option flags  *  * The following options are recognized on the command line by pxp.  * Only the u, w, and z options here have effect in comments in the  * program; the others are command line only, and unrelated  * to the options with the same designations in comments.  *  *	a	Print all routines in a profile; normally, routines  *		which have never been executed have their bodies suppressed.  *  *	c	Extract profile data from the file core, or the file  *		named after the last argument rather than the file 'pmon.out'.  *		Must be used with z to have an effect.  *  *	d	Suppress declarations  *  *	f	Fully parenthesize expressions.  *  *	j	Left justify all procedures and functions rather than  *		indenting them.  *  *	n	Eject a new page in the listing as each 'include' file  *		is incorporated into the profile.  *  *	o	Put output prettyprint in first argument file  *  *	p	Pretty print a main program without processing  *		the include statements.  *  *	t	Print a table summarizing procedure and function call counts.  *  *	u	Card image mode; only the first 72 chars on a line count.  *  *	w	Suppress certain warning diagnostics.  *  *	z	Generate an execution profile of the program.  *		May also be followed by a list of procedure and function  *		names mixed, if desired, with include file names.  *		Only these procedures and functions, and the contents  *		of the specified include files will then be profiled.  *  *  [23456789]	Use the specified number of spaces for the basic  *		indenting unit in the program.  *  *	_	Underline keywords in the output.  *  *	O	remove `others'.  if an `others' label is found in a  *		case statement the case statement (minus the others case)  *		is printed as a guarded case statement, and the others case  *		is the else branch of the guard.  this transformation  *		causes the case selector to be evaluated twice, a lose  *		if the selector has side-effects.  this option is only  *		available if pxp is compiled with RMOTHERS defined.  */
end_comment

begin_decl_stmt
name|char
name|all
decl_stmt|,
name|core
decl_stmt|,
name|nodecl
decl_stmt|,
name|full
decl_stmt|,
name|justify
decl_stmt|,
name|pmain
decl_stmt|,
name|stripcomm
decl_stmt|,
name|table
decl_stmt|,
name|underline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|profile
decl_stmt|,
name|onefile
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|RMOTHERS
end_ifdef

begin_decl_stmt
name|char
name|rmothers
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RMOTHERS
end_endif

begin_decl_stmt
name|char
modifier|*
name|firstname
decl_stmt|,
modifier|*
name|stdoutn
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
name|char
name|fulltrace
decl_stmt|,
name|errtrace
decl_stmt|,
name|testtrace
decl_stmt|,
name|yyunique
decl_stmt|,
name|typetest
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|unit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The flag nojunk means that header lines  * of procedures and functions are to be suppressed  * when the z option is off.  * It is the default when command line z option  * control is specified.  *  * The flag noinclude indicates that include statements are not  * to be processed since we are pretty-printing the contents  * of a single file.  *  * The flag bracket indicates that the source code should be  * bracketed with lines of the form  *	program x(output);  * and  *	begin end.  * so that an include will pretty print without syntax errors.  */
end_comment

begin_decl_stmt
name|char
name|nojunk
decl_stmt|,
name|noinclude
decl_stmt|,
name|bracket
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * IMPORTANT NOTE  *  * Many of the following globals are shared by pi and pxp.  * For more discussion of these see the available documentation  * on the structure of pi.  */
end_comment

begin_comment
comment|/*  * Each option has a stack of 17 option values, with opts giving  * the current, top value, and optstk the value beneath it.  * One refers to option `l' as, e.g., opt('l') in the text for clarity.  */
end_comment

begin_decl_stmt
name|char
name|opts
index|[
literal|26
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|optstk
index|[
literal|26
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|opt
parameter_list|(
name|c
parameter_list|)
value|opts[c-'a']
end_define

begin_escape
end_escape

begin_comment
comment|/*  * NOTES ON THE DYNAMIC NATURE OF THE DATA STRUCTURES  *  * Pxp uses expandable tables for its string table  * hash table, and parse tree space.  The following  * definitions specify the size of the increments  * for these items in fundamental units so that  * each uses approximately 1024 bytes.  */
end_comment

begin_define
define|#
directive|define
name|STRINC
value|1024
end_define

begin_comment
comment|/* string space increment */
end_comment

begin_define
define|#
directive|define
name|TRINC
value|1024
end_define

begin_comment
comment|/* tree space increment */
end_comment

begin_define
define|#
directive|define
name|HASHINC
value|509
end_define

begin_comment
comment|/* hash table size in words, each increment */
end_comment

begin_comment
comment|/*  * The initial sizes of the structures.  * These should be large enough to profile  * an "average" sized program so as to minimize  * storage requests.  * On a small system or and 11/34 or 11/40  * these numbers can be trimmed to make the  * profiler smaller.  */
end_comment

begin_define
define|#
directive|define
name|ITREE
value|2000
end_define

begin_define
define|#
directive|define
name|IHASH
value|509
end_define

begin_comment
comment|/*  * The following limits on hash and tree tables currently  * allow approximately 1200 symbols and 20k words of tree  * space.  The fundamental limit of 64k total data space  * should be exceeded well before these are full.  */
end_comment

begin_comment
comment|/*  * TABLE_MULTIPLIER is for uniformly increasing the sizes of the tables  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ADDR32
end_ifdef

begin_define
define|#
directive|define
name|TABLE_MULTIPLIER
value|8
end_define

begin_endif
endif|#
directive|endif
endif|ADDR32
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ADDR16
end_ifdef

begin_define
define|#
directive|define
name|TABLE_MULTIPLIER
value|1
end_define

begin_endif
endif|#
directive|endif
endif|ADDR16
end_endif

begin_define
define|#
directive|define
name|MAXHASH
value|(4 * TABLE_MULTIPLIER)
end_define

begin_define
define|#
directive|define
name|MAXTREE
value|(40 * TABLE_MULTIPLIER)
end_define

begin_comment
comment|/*  * MAXDEPTH is the depth of the parse stack.  * STACK_MULTIPLIER is for increasing its size.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ADDR32
end_ifdef

begin_define
define|#
directive|define
name|STACK_MULTIPLIER
value|8
end_define

begin_endif
endif|#
directive|endif
endif|ADDR32
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ADDR16
end_ifdef

begin_define
define|#
directive|define
name|STACK_MULTIPLIER
value|1
end_define

begin_endif
endif|#
directive|endif
endif|ADDR16
end_endif

begin_define
define|#
directive|define
name|MAXDEPTH
value|( 150 * STACK_MULTIPLIER )
end_define

begin_escape
end_escape

begin_comment
comment|/*  * ERROR RELATED DEFINITIONS  */
end_comment

begin_comment
comment|/*  * Exit statuses to pexit  *  * AOK  * ERRS		Compilation errors inhibit obj productin  * NOSTART	Errors before we ever got started  * DIED		We ran out of memory or some such  */
end_comment

begin_define
define|#
directive|define
name|AOK
value|0
end_define

begin_define
define|#
directive|define
name|ERRS
value|1
end_define

begin_define
define|#
directive|define
name|NOSTART
value|2
end_define

begin_define
define|#
directive|define
name|DIED
value|3
end_define

begin_decl_stmt
name|char
name|Recovery
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The flag eflg is set whenever we have a hard error.  * The character in errpfx will precede the next error message.  */
end_comment

begin_decl_stmt
name|int
name|eflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|errpfx
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|setpfx
parameter_list|(
name|x
parameter_list|)
value|errpfx = x
end_define

begin_define
define|#
directive|define
name|standard
parameter_list|()
value|setpfx('s')
end_define

begin_define
define|#
directive|define
name|warning
parameter_list|()
value|setpfx('w')
end_define

begin_define
define|#
directive|define
name|recovered
parameter_list|()
value|setpfx('e')
end_define

begin_define
define|#
directive|define
name|quit
parameter_list|()
value|setpfx('Q')
end_define

begin_define
define|#
directive|define
name|continuation
parameter_list|()
value|setpfx(' ')
end_define

begin_escape
end_escape

begin_comment
comment|/*  * SEMANTIC DEFINITIONS  */
end_comment

begin_define
define|#
directive|define
name|NIL
value|0
end_define

begin_comment
comment|/*  * NOCON and SAWCON are flags in the tree telling whether  * a constant set is part of an expression.  */
end_comment

begin_define
define|#
directive|define
name|NOCON
value|0
end_define

begin_define
define|#
directive|define
name|SAWCON
value|1
end_define

begin_comment
comment|/*  * The variable cbn gives the current block number.  * The variable lastbn gives the block number before  * it last changed and is used to know that we were  * in a nested procedure so that we can print  *	begin { solve }  * when solve has nested procedures or functions in it.  */
end_comment

begin_decl_stmt
name|int
name|cbn
decl_stmt|,
name|lastbn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The variable line is the current semantic  * line and is set in stat.c from the numbers  * embedded in statement type tree nodes.  */
end_comment

begin_decl_stmt
name|int
name|line
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The size of the display  * which defines the maximum nesting  * of procedures and functions allowed.  */
end_comment

begin_define
define|#
directive|define
name|DSPLYSZ
value|20
end_define

begin_escape
end_escape

begin_comment
comment|/*  * Routines which need types  * other than "integer" to be  * assumed by the compiler.  */
end_comment

begin_function_decl
name|struct
name|tnode
modifier|*
name|tree
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|skipbl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
modifier|*
name|hash
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|alloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|cntof
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|nowcnt
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  *	type cast nils to keep lint happy.  */
end_comment

begin_define
define|#
directive|define
name|TR_NIL
value|((struct tnode *) NIL)
end_define

begin_comment
comment|/*  * Funny structures to use  * pointers in wild and wooly ways  */
end_comment

begin_struct
struct|struct
name|cstruct
block|{
name|char
name|pchar
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
block|{
name|int
name|pint
decl_stmt|;
name|int
name|pint2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
block|{
name|long
name|plong
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
block|{
name|double
name|pdouble
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OCT
value|1
end_define

begin_define
define|#
directive|define
name|HEX
value|2
end_define

begin_escape
end_escape

begin_comment
comment|/*  * MAIN PROGRAM GLOBALS, MISCELLANY  */
end_comment

begin_comment
comment|/*  * Variables forming a data base referencing  * the command line arguments with the "z" option.  */
end_comment

begin_decl_stmt
name|char
modifier|*
modifier|*
name|pflist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pflstc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pfcnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|filename
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current source file name */
end_comment

begin_decl_stmt
name|char
modifier|*
name|lastname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last file name printed */
end_comment

begin_decl_stmt
name|long
name|tvec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mod time of the source file */
end_comment

begin_decl_stmt
name|long
name|ptvec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time profiled */
end_comment

begin_decl_stmt
name|char
name|printed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current file has been printed */
end_comment

begin_decl_stmt
name|char
name|hadsome
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* had some output */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  * PROFILING AND FORMATTING DEFINITIONS  */
end_comment

begin_comment
comment|/*  * The basic counter information recording structure.  * This is global only because people outside  * the cluster in pmon.c need to know its size.  */
end_comment

begin_struct
struct|struct
name|pxcnt
block|{
name|long
name|ntimes
decl_stmt|;
comment|/* the count this structure is all about */
name|int
name|counter
decl_stmt|;
comment|/* a unique counter number for us */
name|int
name|gos
decl_stmt|;
comment|/* global goto count when we hatched */
name|int
name|printed
decl_stmt|;
comment|/* are we considered to have been printed? */
block|}
name|pfcnts
index|[
name|DSPLYSZ
index|]
struct|;
end_struct

begin_comment
comment|/*  * The pieces we divide the output line indents into:  *	line#  PRFN  label:   STAT  999.---|  DECL   text  */
end_comment

begin_define
define|#
directive|define
name|STAT
value|0
end_define

begin_define
define|#
directive|define
name|DECL
value|1
end_define

begin_define
define|#
directive|define
name|PRFN
value|2
end_define

begin_comment
comment|/*  * Gocnt records the total number of goto's and  * cnts records the current counter for generating  * COUNT operators.  */
end_comment

begin_decl_stmt
name|int
name|gocnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cnts
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_typedef
typedef|typedef
enum|enum
block|{
name|FALSE
block|,
name|TRUE
block|}
name|bool
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|putchar
end_undef

end_unit

