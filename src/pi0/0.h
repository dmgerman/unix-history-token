begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_include
include|#
directive|include
file|"send.h"
end_include

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
comment|/*  * pi - Pascal interpreter code translator  *  * Charles Haley, Bill Joy  * University of California, Berkeley (UCB)  * Version 1.2 January 1979  */
end_comment

begin_comment
comment|/*  * Option flags  *  * The following options are recognized in the text of the program  * and also on the command line:  *  *	b	block buffer the file output  *  *	i	make a listing of the procedures and functions in  *		the following include files  *  *	l	make a listing of the program  *  *	n	place each include file on a new page with a header  *  *	p	disable post mortem and statement limit counting  *  *	t	disable run-time tests  *  *	u	card image mode; only first 72 chars of input count  *  *	w	suppress special diagnostic warnings  *  *	z	generate counters for an execution profile  */
end_comment

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
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/*  * Monflg is set when we are generating  * a profile  */
end_comment

begin_decl_stmt
name|char
name|monflg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * NOTES ON THE DYNAMIC NATURE OF THE DATA STRUCTURES  *  * Pi uses expandable tables for  * its namelist (symbol table), string table  * hash table, and parse tree space.  The following  * definitions specify the size of the increments  * for these items in fundamental units so that  * each uses approximately 1024 bytes.  */
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
value|512
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

begin_define
define|#
directive|define
name|NLINC
value|56
end_define

begin_comment
comment|/* namelist increment size in nl structs */
end_comment

begin_comment
comment|/*  * The initial sizes of the structures.  * These should be large enough to compile  * an "average" sized program so as to minimize  * storage requests.  * On a small system or and 11/34 or 11/40  * these numbers can be trimmed to make the  * compiler smaller.  */
end_comment

begin_define
define|#
directive|define
name|ITREE
value|512
end_define

begin_comment
comment|/* Must be the same as TRINC */
end_comment

begin_define
define|#
directive|define
name|INL
value|200
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

begin_define
define|#
directive|define
name|MAXHASH
value|4
end_define

begin_define
define|#
directive|define
name|MAXNL
value|12
end_define

begin_define
define|#
directive|define
name|MAXTREE
value|30
end_define

begin_define
define|#
directive|define
name|MAXDEPTH
value|150
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

begin_define
define|#
directive|define
name|eholdnl
parameter_list|()
value|Eholdnl = 1
end_define

begin_define
define|#
directive|define
name|nocascade
parameter_list|()
value|Enocascade = 1
end_define

begin_decl_stmt
name|char
name|Eholdnl
decl_stmt|,
name|Enocascade
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

begin_escape
end_escape

begin_comment
comment|/*  * The flag syneflg is used to suppress the diagnostics of the form  *	E 10 a, defined in someprocedure, is neither used nor set  * when there were syntax errors in "someprocedure".  * In this case, it is likely that these warinings would be spurious.  */
end_comment

begin_decl_stmt
name|char
name|syneflg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The compiler keeps its error messages in a file.  * The variable efil is the unit number on which  * this file is open for reading of error message text.  * Similarly, the file ofil is the unit of the file  * "obj" where we write the interpreter code.  */
end_comment

begin_decl_stmt
name|char
name|efil
decl_stmt|,
name|ofil
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* int	obuf[259]; */
end_comment

begin_define
define|#
directive|define
name|elineoff
parameter_list|()
value|Enoline++
end_define

begin_define
define|#
directive|define
name|elineon
parameter_list|()
value|Enoline = 0
end_define

begin_decl_stmt
name|char
name|Enoline
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/*  * SYMBOL TABLE STRUCTURE DEFINITIONS  *  * The symbol table is henceforth referred to as the "namelist".  * It consists of a number of structures of the form "nl" below.  * These are contained in a number of segments of the symbol  * table which are dynamically allocated as needed.  * The major namelist manipulation routines are contained in the  * file "nl.c".  *  * The major components of a namelist entry are the "symbol", giving  * a pointer into the string table for the string associated with this  * entry and the "class" which tells which of the (currently 19)  * possible types of structure this is.  *  * Many of the classes use the "type" field for a pointer to the type  * which the entry has.  *  * Other pieces of information in more than one class include the block  * in which the symbol is defined, flags indicating whether the symbol  * has been used and whether it has been assigned to, etc.  *  * A more complete discussion of the features of the namelist is impossible  * here as it would be too voluminous.  Refer to the "PI 1.0 Implementation  * Notes" for more details.  */
end_comment

begin_comment
comment|/*  * The basic namelist structure.  * There are also two other variants, defining the real  * field as longs or integers given below.  *  * The array disptab defines the hash header for the symbol table.  * Symbols are hashed based on the low 6 bits of their pointer into  * the string table; see the routines in the file "lookup.c" and also "fdec.c"  * especially "funcend".  */
end_comment

begin_struct
struct|struct
name|nl
block|{
name|char
modifier|*
name|symbol
decl_stmt|;
name|char
name|class
decl_stmt|,
name|nl_flags
decl_stmt|;
name|struct
name|nl
modifier|*
name|type
decl_stmt|;
name|struct
name|nl
modifier|*
name|chain
decl_stmt|,
modifier|*
name|nl_next
decl_stmt|;
name|double
name|real
decl_stmt|;
block|}
name|nl
index|[]
struct|,
modifier|*
name|nlp
struct|,
modifier|*
name|disptab
index|[
literal|077
operator|+
literal|1
index|]
struct|;
end_struct

begin_struct
struct|struct
block|{
name|char
modifier|*
name|symbol
decl_stmt|;
name|char
name|class
decl_stmt|,
name|nl_block
decl_stmt|;
name|struct
name|nl
modifier|*
name|type
decl_stmt|;
name|struct
name|nl
modifier|*
name|chain
decl_stmt|,
modifier|*
name|nl_next
decl_stmt|;
name|long
name|range
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
block|{
name|char
modifier|*
name|symbol
decl_stmt|;
name|char
name|class
decl_stmt|,
name|nl_flags
decl_stmt|;
name|struct
name|nl
modifier|*
name|type
decl_stmt|;
name|struct
name|nl
modifier|*
name|chain
decl_stmt|,
modifier|*
name|nl_next
decl_stmt|;
name|int
name|value
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * NL FLAGS BITS  *  * Definitions of the usage of the bits in  * the nl_flags byte. Note that the low 5 bits of the  * byte are the "nl_block" and that some classes make use  * of this byte as a "width".  *  * The only non-obvious bit definition here is "NFILES"  * which records whether a structure contains any files.  * Such structures are not allowed to be dynamically allocated.  */
end_comment

begin_define
define|#
directive|define
name|NPACKED
value|0200
end_define

begin_define
define|#
directive|define
name|NFORWD
value|0200
end_define

begin_define
define|#
directive|define
name|NFILES
value|0200
end_define

begin_escape
end_escape

begin_comment
comment|/*  * Definition of the commonly used "value" fields.  * The most important ones are NL_LOC which gives the location  * in the code of a label or procedure, and NL_OFFS which gives  * the offset of a variable in its stack mark.  */
end_comment

begin_define
define|#
directive|define
name|NL_OFFS
value|0
end_define

begin_define
define|#
directive|define
name|NL_LOC
value|1
end_define

begin_define
define|#
directive|define
name|NL_FVAR
value|3
end_define

begin_define
define|#
directive|define
name|NL_GOLEV
value|2
end_define

begin_define
define|#
directive|define
name|NL_GOLINE
value|3
end_define

begin_define
define|#
directive|define
name|NL_FORV
value|1
end_define

begin_define
define|#
directive|define
name|NL_FLDSZ
value|1
end_define

begin_define
define|#
directive|define
name|NL_VARNT
value|2
end_define

begin_define
define|#
directive|define
name|NL_VTOREC
value|2
end_define

begin_define
define|#
directive|define
name|NL_TAG
value|3
end_define

begin_comment
comment|/*  * For BADUSE nl structures, NL_KINDS is a bit vector  * indicating the kinds of illegal usages complained about  * so far.  For kind of bad use "kind", "1<< kind" is set.  * The low bit is reserved as ISUNDEF to indicate whether  * this identifier is totally undefined.  */
end_comment

begin_define
define|#
directive|define
name|NL_KINDS
value|0
end_define

begin_define
define|#
directive|define
name|ISUNDEF
value|1
end_define

begin_escape
end_escape

begin_comment
comment|/*  * NAMELIST CLASSES  *  * The following are the namelist classes.  * Different classes make use of the value fields  * of the namelist in different ways.  *  * The namelist should be redesigned by providing  * a number of structure definitions with one corresponding  * to each namelist class, ala a variant record in Pascal.  */
end_comment

begin_define
define|#
directive|define
name|BADUSE
value|0
end_define

begin_define
define|#
directive|define
name|CONST
value|1
end_define

begin_define
define|#
directive|define
name|TYPE
value|2
end_define

begin_define
define|#
directive|define
name|VAR
value|3
end_define

begin_define
define|#
directive|define
name|ARRAY
value|4
end_define

begin_define
define|#
directive|define
name|PTRFILE
value|5
end_define

begin_define
define|#
directive|define
name|RECORD
value|6
end_define

begin_define
define|#
directive|define
name|FIELD
value|7
end_define

begin_define
define|#
directive|define
name|PROC
value|8
end_define

begin_define
define|#
directive|define
name|FUNC
value|9
end_define

begin_define
define|#
directive|define
name|FVAR
value|10
end_define

begin_define
define|#
directive|define
name|REF
value|11
end_define

begin_define
define|#
directive|define
name|PTR
value|12
end_define

begin_define
define|#
directive|define
name|FILE
value|13
end_define

begin_define
define|#
directive|define
name|SET
value|14
end_define

begin_define
define|#
directive|define
name|RANGE
value|15
end_define

begin_define
define|#
directive|define
name|LABEL
value|16
end_define

begin_define
define|#
directive|define
name|WITHPTR
value|17
end_define

begin_define
define|#
directive|define
name|SCAL
value|18
end_define

begin_define
define|#
directive|define
name|STR
value|19
end_define

begin_define
define|#
directive|define
name|PROG
value|20
end_define

begin_define
define|#
directive|define
name|IMPROPER
value|21
end_define

begin_define
define|#
directive|define
name|VARNT
value|22
end_define

begin_comment
comment|/*  * Clnames points to an array of names for the  * namelist classes.  */
end_comment

begin_decl_stmt
name|char
modifier|*
modifier|*
name|clnames
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/*  * PRE-DEFINED NAMELIST OFFSETS  *  * The following are the namelist offsets for the  * primitive types. The ones which are negative  * don't actually exist, but are generated and tested  * internally. These definitions are sensitive to the  * initializations in nl.c.  */
end_comment

begin_define
define|#
directive|define
name|TFIRST
value|-7
end_define

begin_define
define|#
directive|define
name|TFILE
value|-7
end_define

begin_define
define|#
directive|define
name|TREC
value|-6
end_define

begin_define
define|#
directive|define
name|TARY
value|-5
end_define

begin_define
define|#
directive|define
name|TSCAL
value|-4
end_define

begin_define
define|#
directive|define
name|TPTR
value|-3
end_define

begin_define
define|#
directive|define
name|TSET
value|-2
end_define

begin_define
define|#
directive|define
name|TSTR
value|-1
end_define

begin_define
define|#
directive|define
name|NIL
value|0
end_define

begin_define
define|#
directive|define
name|TBOOL
value|1
end_define

begin_define
define|#
directive|define
name|TCHAR
value|2
end_define

begin_define
define|#
directive|define
name|TINT
value|3
end_define

begin_define
define|#
directive|define
name|TDOUBLE
value|4
end_define

begin_define
define|#
directive|define
name|TNIL
value|5
end_define

begin_define
define|#
directive|define
name|T1INT
value|6
end_define

begin_define
define|#
directive|define
name|T2INT
value|7
end_define

begin_define
define|#
directive|define
name|T4INT
value|8
end_define

begin_define
define|#
directive|define
name|T1CHAR
value|9
end_define

begin_define
define|#
directive|define
name|T1BOOL
value|10
end_define

begin_define
define|#
directive|define
name|T8REAL
value|11
end_define

begin_define
define|#
directive|define
name|TLAST
value|11
end_define

begin_escape
end_escape

begin_comment
comment|/*  * SEMANTIC DEFINITIONS  */
end_comment

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
comment|/*  * The variable cbn gives the current block number,  * the variable bn is set as a side effect of a call to  * lookup, and is the block number of the variable which  * was found.  */
end_comment

begin_decl_stmt
name|int
name|bn
decl_stmt|,
name|cbn
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
comment|/*  * The size of the display  * which defines the maximum nesting  * of procedures and functions allowed.  * Because of the flags in the current namelist  * this must be no greater than 32.  */
end_comment

begin_define
define|#
directive|define
name|DSPLYSZ
value|20
end_define

begin_comment
comment|/*  * The following structure is used  * to keep track of the amount of variable  * storage required by each block.  * "Max" is the high water mark, "off"  * the current need. Temporaries for "for"  * loops and "with" statements are allocated  * in the local variable area and these  * numbers are thereby changed if necessary.  */
end_comment

begin_comment
comment|/* struct om { */
end_comment

begin_comment
comment|/* 	long	om_off; */
end_comment

begin_comment
comment|/* 	long	om_max; */
end_comment

begin_comment
comment|/* } sizes[DSPLYSZ]; */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  * Structure recording information about a constant  * declaration.  It is actually the return value from  * the routine "gconst", but since C doesn't support  * record valued functions, this is more convenient.  */
end_comment

begin_struct
struct|struct
block|{
name|int
name|ctype
decl_stmt|;
name|int
name|cival
decl_stmt|;
name|double
name|crval
decl_stmt|;
block|}
name|con
struct|;
end_struct

begin_comment
comment|/*  * The set structure records the lower bound  * and upper bound with the lower bound normalized  * to zero when working with a set. It is set by  * the routine setran in var.c.  */
end_comment

begin_struct
struct|struct
block|{
name|int
name|lwrb
decl_stmt|,
name|uprbp
decl_stmt|;
block|}
name|set
struct|;
end_struct

begin_comment
comment|/*  * The following flags are passed on calls to lvalue  * to indicate how the reference is to affect the usage  * information for the variable being referenced.  * MOD is used to set the NMOD flag in the namelist  * entry for the variable, ASGN permits diagnostics  * to be formed when a for variable is assigned to in  * the range of the loop.  */
end_comment

begin_define
define|#
directive|define
name|NOMOD
value|0
end_define

begin_define
define|#
directive|define
name|MOD
value|01
end_define

begin_define
define|#
directive|define
name|ASGN
value|02
end_define

begin_define
define|#
directive|define
name|NOUSE
value|04
end_define

begin_decl_stmt
name|double
name|MAXINT
decl_stmt|,
name|MININT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Variables for generation of profile information.  * Monflg is set when we want to generate a profile.  * Gocnt record the total number of goto's and  * cnts records the current counter for generating  * COUNT operators.  */
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

begin_escape
end_escape

begin_comment
comment|/*  * Most routines call "incompat" rather than asking "!compat"  * for historical reasons.  */
end_comment

begin_define
define|#
directive|define
name|incompat
value|!compat
end_define

begin_comment
comment|/*  * Parts records which declaration parts have been seen.  * The grammar allows the "const" "type" and "var"  * parts to be repeated and to be in any order, so that  * they can be detected semantically to give better  * error diagnostics.  */
end_comment

begin_decl_stmt
name|int
name|parts
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|LPRT
value|01
end_define

begin_define
define|#
directive|define
name|CPRT
value|02
end_define

begin_define
define|#
directive|define
name|TPRT
value|04
end_define

begin_define
define|#
directive|define
name|VPRT
value|08
end_define

begin_comment
comment|/*  * Flags for the "you used / instead of div" diagnostic  */
end_comment

begin_comment
comment|/* char	divchk; */
end_comment

begin_comment
comment|/* char	divflg; */
end_comment

begin_decl_stmt
name|int
name|errcnt
index|[
name|DSPLYSZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Forechain links those types which are  *	^ sometype  * so that they can be evaluated later, permitting  * circular, recursive list structures to be defined.  */
end_comment

begin_decl_stmt
name|struct
name|nl
modifier|*
name|forechain
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Withlist links all the records which are currently  * opened scopes because of with statements.  */
end_comment

begin_comment
comment|/* struct  nl *withlist; */
end_comment

begin_decl_stmt
name|char
modifier|*
name|intset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|input
decl_stmt|,
modifier|*
name|output
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|nl
modifier|*
name|program
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/*  * UNDEFINED VARIABLE REFERENCE STRUCTURES  */
end_comment

begin_struct
struct|struct
name|udinfo
block|{
name|int
name|ud_line
decl_stmt|;
name|struct
name|udinfo
modifier|*
name|ud_next
decl_stmt|;
name|char
name|nullch
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/*  * Routines which need types  * other than "integer" to be  * assumed by the compiler.  */
end_comment

begin_comment
comment|/* double  atof(); */
end_comment

begin_function_decl
name|long
name|lwidth
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|aryconst
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* long    a8tol(); */
end_comment

begin_function_decl
name|struct
name|nl
modifier|*
name|lookup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|double
name|atof
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
modifier|*
name|tree
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

begin_comment
comment|/*  * Funny structures to use  * pointers in wild and wooly ways  */
end_comment

begin_struct
struct|struct
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
comment|/*  * MAIN PROGRAM VARIABLES, MISCELLANY  */
end_comment

begin_comment
comment|/*  * Variables forming a data base referencing  * the command line arguments with the "i" option, e.g.  * in "pi -i scanner.i compiler.p".  */
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
name|int
name|tvec
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mod time of the source file */
end_comment

begin_decl_stmt
name|char
name|snark
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SNARK */
end_comment

begin_decl_stmt
name|char
modifier|*
name|classes
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maps namelist classes to string names */
end_comment

begin_decl_stmt
name|char
modifier|*
name|errfile
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|derror
value|error
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
name|char
name|hp21mx
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

