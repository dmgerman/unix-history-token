begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)0.h	5.2 (Berkeley) 6/20/85  */
end_comment

begin_define
define|#
directive|define
name|DEBUG
end_define

begin_define
define|#
directive|define
name|CONSETS
end_define

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

begin_define
define|#
directive|define
name|hp21mx
value|0
end_define

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

begin_undef
undef|#
directive|undef
name|roundup
end_undef

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

begin_comment
comment|/*  * Option flags  *  * The following options are recognized in the text of the program  * and also on the command line:  *  *	b	block buffer the file output  *  *	i	make a listing of the procedures and functions in  *		the following include files  *  *	l	make a listing of the program  *  *	n	place each include file on a new page with a header  *  *	p	disable post mortem and statement limit counting  *  *	t	disable run-time tests  *  *	u	card image mode; only first 72 chars of input count  *  *	w	suppress special diagnostic warnings  *  *	z	generate counters for an execution profile  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
name|bool
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
endif|DEBUG
end_endif

begin_comment
comment|/*  * Each option has a stack of 17 option values, with opts giving  * the current, top value, and optstk the value beneath it.  * One refers to option `l' as, e.g., opt('l') in the text for clarity.  */
end_comment

begin_decl_stmt
name|char
name|opts
index|[
literal|'z'
operator|-
literal|'A'
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|optstk
index|[
literal|'z'
operator|-
literal|'A'
operator|+
literal|1
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
value|opts[c-'A']
end_define

begin_comment
comment|/*  * Monflg is set when we are generating  * a pxp profile.  this is set by the -z command line option.  */
end_comment

begin_decl_stmt
name|bool
name|monflg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*      *	profflag is set when we are generating a prof profile.      *	this is set by the -p command line option.      */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PC
end_ifdef

begin_decl_stmt
name|bool
name|profflag
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

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
value|2000
end_define

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
name|MAXNL
value|(12 * TABLE_MULTIPLIER)
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
name|bool
name|Recovery
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|eholdnl
parameter_list|()
value|Eholdnl = TRUE
end_define

begin_define
define|#
directive|define
name|nocascade
parameter_list|()
value|Enocascade = TRUE
end_define

begin_decl_stmt
name|bool
name|Eholdnl
decl_stmt|,
name|Enocascade
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The flag eflg is set whenever we have a hard error.  * The character in errpfx will precede the next error message.  * When cgenflg is set code generation is suppressed.  * This happens whenver we have an error (i.e. if eflg is set)  * and when we are walking the tree to determine types only.  */
end_comment

begin_decl_stmt
name|bool
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
name|continuation
parameter_list|()
value|setpfx(' ')
end_define

begin_decl_stmt
name|int
name|cgenflg
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/*  * The flag syneflg is used to suppress the diagnostics of the form  *	E 10 a, defined in someprocedure, is neither used nor set  * when there were syntax errors in "someprocedure".  * In this case, it is likely that these warinings would be spurious.  */
end_comment

begin_decl_stmt
name|bool
name|syneflg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The compiler keeps its error messages in a file.  * The variable efil is the unit number on which  * this file is open for reading of error message text.  * Similarly, the file ofil is the unit of the file  * "obj" where we write the interpreter code.  */
end_comment

begin_decl_stmt
name|short
name|efil
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ
end_ifdef

begin_decl_stmt
name|short
name|ofil
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|obuf
index|[
literal|518
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|bool
name|Enoline
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|elineoff
parameter_list|()
value|Enoline = TRUE
end_define

begin_define
define|#
directive|define
name|elineon
parameter_list|()
value|Enoline = FALSE
end_define

begin_escape
end_escape

begin_comment
comment|/*  * SYMBOL TABLE STRUCTURE DEFINITIONS  *  * The symbol table is henceforth referred to as the "namelist".  * It consists of a number of structures of the form "nl" below.  * These are contained in a number of segments of the symbol  * table which are dynamically allocated as needed.  * The major namelist manipulation routines are contained in the  * file "nl.c".  *  * The major components of a namelist entry are the "symbol", giving  * a pointer into the string table for the string associated with this  * entry and the "class" which tells which of the (currently 19)  * possible types of structure this is.  *  * Many of the classes use the "type" field for a pointer to the type  * which the entry has.  *  * Other pieces of information in more than one class include the block  * in which the symbol is defined, flags indicating whether the symbol  * has been used and whether it has been assigned to, etc.  *  * A more complete discussion of the features of the namelist is impossible  * here as it would be too voluminous.  Refer to the "PI 1.0 Implementation  * Notes" for more details.  */
end_comment

begin_comment
comment|/*  * The basic namelist structure.  * There is a union of data types defining the stored information  * as pointers, integers, longs, or a double.  *  * The array disptab defines the hash header for the symbol table.  * Symbols are hashed based on the low 6 bits of their pointer into  * the string table; see the routines in the file "lookup.c" and also "fdec.c"  * especially "funcend".  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pnumcnt
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|nl
block|{
name|char
modifier|*
name|symbol
decl_stmt|;
name|char
name|info
index|[
literal|4
index|]
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
union|union
block|{
name|struct
name|nl
modifier|*
name|un_ptr
index|[
literal|5
index|]
decl_stmt|;
name|int
name|un_value
index|[
literal|5
index|]
decl_stmt|;
name|long
name|un_range
index|[
literal|2
index|]
decl_stmt|;
name|double
name|un_real
decl_stmt|;
name|struct
name|nl
modifier|*
name|un_nptr
index|[
literal|5
index|]
decl_stmt|;
comment|/* Points to conformant array bounds */
block|}
name|nl_un
union|;
ifdef|#
directive|ifdef
name|PTREE
name|pPointer
name|inTree
decl_stmt|;
endif|#
directive|endif
endif|PTREE
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|class
value|info[0]
end_define

begin_define
define|#
directive|define
name|nl_flags
value|info[1]
end_define

begin_define
define|#
directive|define
name|nl_block
value|info[1]
end_define

begin_define
define|#
directive|define
name|extra_flags
value|info[2]
end_define

begin_define
define|#
directive|define
name|align_info
value|info[3]
end_define

begin_define
define|#
directive|define
name|range
value|nl_un.un_range
end_define

begin_define
define|#
directive|define
name|value
value|nl_un.un_value
end_define

begin_define
define|#
directive|define
name|ptr
value|nl_un.un_ptr
end_define

begin_define
define|#
directive|define
name|real
value|nl_un.un_real
end_define

begin_define
define|#
directive|define
name|nptr
value|nl_un.un_nptr
end_define

begin_decl_stmt
specifier|extern
name|struct
name|nl
modifier|*
name|nlp
decl_stmt|,
modifier|*
name|disptab
index|[
literal|077
operator|+
literal|1
index|]
decl_stmt|,
modifier|*
name|Fp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|nl
name|nl
index|[
name|INL
index|]
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/*  * NL FLAGS BITS  *  * Definitions of the usage of the bits in  * the nl_flags byte. Note that the low 5 bits of the  * byte are the "nl_block" and that some classes make use  * of this byte as a "width".  *  * The only non-obvious bit definition here is "NFILES"  * which records whether a structure contains any files.  * Such structures are not allowed to be dynamically allocated.  */
end_comment

begin_define
define|#
directive|define
name|BLOCKNO
parameter_list|(
name|flag
parameter_list|)
value|( flag& 037 )
end_define

begin_define
define|#
directive|define
name|NLFLAGS
parameter_list|(
name|flag
parameter_list|)
value|( flag&~ 037 )
end_define

begin_define
define|#
directive|define
name|NUSED
value|0100
end_define

begin_define
define|#
directive|define
name|NMOD
value|0040
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

begin_ifdef
ifdef|#
directive|ifdef
name|PC
end_ifdef

begin_define
define|#
directive|define
name|NEXTERN
value|0001
end_define

begin_comment
comment|/* flag used to mark external funcs and procs */
end_comment

begin_define
define|#
directive|define
name|NLOCAL
value|0002
end_define

begin_comment
comment|/* variable is a local */
end_comment

begin_define
define|#
directive|define
name|NPARAM
value|0004
end_define

begin_comment
comment|/* variable is a parameter */
end_comment

begin_define
define|#
directive|define
name|NGLOBAL
value|0010
end_define

begin_comment
comment|/* variable is a global */
end_comment

begin_define
define|#
directive|define
name|NREGVAR
value|0020
end_define

begin_comment
comment|/* or'ed in if variable is in a register */
end_comment

begin_define
define|#
directive|define
name|NNLOCAL
value|0040
end_define

begin_comment
comment|/* named local variable, not used in symbol table */
end_comment

begin_endif
endif|#
directive|endif
endif|PC
end_endif

begin_comment
comment|/*  * used to mark value[ NL_FORV ] for loop variables  */
end_comment

begin_define
define|#
directive|define
name|FORVAR
value|1
end_define

begin_escape
end_escape

begin_comment
comment|/*  * Definition of the commonly used "value" fields.  * The most important one is NL_OFFS which gives  * the offset of a variable in its stack mark.  */
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
name|NL_CNTR
value|1
end_define

begin_define
define|#
directive|define
name|NL_NLSTRT
value|2
end_define

begin_define
define|#
directive|define
name|NL_LINENO
value|3
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
name|NL_ENTLOC
value|4
end_define

begin_comment
comment|/* FUNC, PROC - entry point */
end_comment

begin_define
define|#
directive|define
name|NL_FCHAIN
value|4
end_define

begin_comment
comment|/* FFUNC, FPROC - ptr to formals */
end_comment

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

begin_comment
comment|/*      *	nlp -> nl_un.un_ptr[] subscripts for records      *	NL_FIELDLIST	the chain of fixed fields of a record, in order.      *			the fields are also chained through ptr[NL_FIELDLIST].      *			this does not include the tag, or fields of variants.      *	NL_VARNT	pointer to the variants of a record,      *			these are then chained through the .chain field.      *	NL_VTOREC	pointer from a VARNT to the RECORD that is the variant.      *	NL_TAG		pointer from a RECORD to the tagfield      *			if there are any variants.      *	align_info	the alignment of a RECORD is in info[3].      */
end_comment

begin_define
define|#
directive|define
name|NL_FIELDLIST
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
comment|/* and align_info is info[3].  #defined above */
end_comment

begin_define
define|#
directive|define
name|NL_ELABEL
value|4
end_define

begin_comment
comment|/* SCAL - ptr to definition of enums */
end_comment

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

begin_comment
comment|/*      *	variables come in three flavors: globals, parameters, locals;      *	they can also hide in registers, but that's a different flag      */
end_comment

begin_define
define|#
directive|define
name|PARAMVAR
value|1
end_define

begin_define
define|#
directive|define
name|LOCALVAR
value|2
end_define

begin_define
define|#
directive|define
name|GLOBALVAR
value|3
end_define

begin_define
define|#
directive|define
name|NAMEDLOCALVAR
value|4
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
name|FILET
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

begin_define
define|#
directive|define
name|FPROC
value|23
end_define

begin_define
define|#
directive|define
name|FFUNC
value|24
end_define

begin_define
define|#
directive|define
name|CRANGE
value|25
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
comment|/*  * NOCON and SAWCON are flags in the tree telling whether  * a constant set is part of an expression.  *	these are no longer used,  *	since we now do constant sets at compile time.  */
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
name|short
name|bn
decl_stmt|,
name|cbn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The variable line is the current semantic  * line and is set in stat.c from the numbers  * embedded in statement type tree nodes.  */
end_comment

begin_decl_stmt
name|short
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
comment|/*      *	the following structure records whether a level declares      *	any variables which are (or contain) files.      *	this so that the runtime routines for file cleanup can be invoked.      */
end_comment

begin_decl_stmt
name|bool
name|dfiles
index|[
name|DSPLYSZ
index|]
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/*  * Structure recording information about a constant  * declaration.  It is actually the return value from  * the routine "gconst", but since C doesn't support  * record valued functions, this is more convenient.  */
end_comment

begin_struct
struct|struct
block|{
name|struct
name|nl
modifier|*
name|ctype
decl_stmt|;
name|short
name|cival
decl_stmt|;
name|double
name|crval
decl_stmt|;
name|char
modifier|*
name|cpval
decl_stmt|;
comment|/* note used to be int * */
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
name|short
name|lwrb
decl_stmt|,
name|uprbp
decl_stmt|;
block|}
name|set
struct|;
end_struct

begin_comment
comment|/*      *	structures of this kind are filled in by precset and used by postcset      *	to indicate things about constant sets.      */
end_comment

begin_struct
struct|struct
name|csetstr
block|{
name|struct
name|nl
modifier|*
name|csettype
decl_stmt|;
name|long
name|paircnt
decl_stmt|;
name|long
name|singcnt
decl_stmt|;
name|bool
name|comptime
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following flags are passed on calls to lvalue  * to indicate how the reference is to affect the usage  * information for the variable being referenced.  * MOD is used to set the NMOD flag in the namelist  * entry for the variable, ASGN permits diagnostics  * to be formed when a for variable is assigned to in  * the range of the loop.  */
end_comment

begin_define
define|#
directive|define
name|NOFLAGS
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

begin_comment
comment|/*      *	the following flags are passed to lvalue and rvalue      *	to tell them whether an lvalue or rvalue is required.      *	the semantics checking is done according to the function called,      *	but for pc, lvalue may put out an rvalue by indirecting afterwards,      *	and rvalue may stop short of putting out the indirection.      */
end_comment

begin_define
define|#
directive|define
name|LREQ
value|01
end_define

begin_define
define|#
directive|define
name|RREQ
value|02
end_define

begin_decl_stmt
name|double
name|MAXINT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|MININT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Variables for generation of profile information.  * Monflg is set when we want to generate a profile.  * Gocnt record the total number of goto's and  * cnts records the current counter for generating  * COUNT operators.  */
end_comment

begin_decl_stmt
name|short
name|gocnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
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
comment|/*  * Parts records which declaration parts have been seen.  * The grammar allows the "label" "const" "type" "var" and routine  * parts to be repeated and to be in any order, so that  * they can be detected semantically to give better  * error diagnostics.  *  * The flag NONLOCALVAR indicates that a non-local var has actually  * been used hence the display must be saved; NONLOCALGOTO indicates  * that a non-local goto has been done hence that a setjmp must be done.  */
end_comment

begin_decl_stmt
name|int
name|parts
index|[
name|DSPLYSZ
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|LPRT
value|0x0001
end_define

begin_define
define|#
directive|define
name|CPRT
value|0x0002
end_define

begin_define
define|#
directive|define
name|TPRT
value|0x0004
end_define

begin_define
define|#
directive|define
name|VPRT
value|0x0008
end_define

begin_define
define|#
directive|define
name|RPRT
value|0x0010
end_define

begin_define
define|#
directive|define
name|NONLOCALVAR
value|0x0020
end_define

begin_define
define|#
directive|define
name|NONLOCALGOTO
value|0x0040
end_define

begin_comment
comment|/*  * Flags for the "you used / instead of div" diagnostic  */
end_comment

begin_decl_stmt
name|bool
name|divchk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|divflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
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

begin_decl_stmt
name|struct
name|nl
modifier|*
name|withlist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|nl
modifier|*
name|intset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|nl
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

begin_comment
comment|/* progseen flag used by PC to determine if  * a routine segment is being compiled (and  * therefore no program statement seen)  */
end_comment

begin_decl_stmt
name|bool
name|progseen
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/*  * STRUCTURED STATEMENT GOTO CHECKING  *  * The variable level keeps track of the current  * "structured statement level" when processing the statement  * body of blocks.  This is used in the detection of goto's into  * structured statements in a block.  *  * Each label's namelist entry contains two pieces of information  * related to this check. The first `NL_GOLEV' either contains  * the level at which the label was declared, `NOTYET' if the label  * has not yet been declared, or `DEAD' if the label is dead, i.e.  * if we have exited the level in which the label was defined.  *  * When we discover a "goto" statement, if the label has not  * been defined yet, then we record the current level and the current line  * for a later error check.  If the label has been already become "DEAD"  * then a reference to it is an error.  Now the compiler maintains,  * for each block, a linked list of the labels headed by "gotos[bn]".  * When we exit a structured level, we perform the routine  * ungoto in stat.c. It notices labels whose definition levels have been  * exited and makes them be dead. For labels which have not yet been  * defined, ungoto will maintain NL_GOLEV as the minimum structured level  * since the first usage of the label. It is not hard to see that the label  * must eventually be declared at this level or an outer level to this  * one or a goto into a structured statement will exist.  */
end_comment

begin_decl_stmt
name|short
name|level
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|nl
modifier|*
name|gotos
index|[
name|DSPLYSZ
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NOTYET
value|10000
end_define

begin_define
define|#
directive|define
name|DEAD
value|10000
end_define

begin_comment
comment|/*  * Noreach is true when the next statement will  * be unreachable unless something happens along  * (like exiting a looping construct) to save  * the day.  */
end_comment

begin_decl_stmt
name|bool
name|noreach
decl_stmt|;
end_decl_stmt

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
comment|/*  * CODE GENERATION DEFINITIONS  */
end_comment

begin_comment
comment|/*  * NSTAND is or'ed onto the abstract machine opcode  * for non-standard built-in procedures and functions.  */
end_comment

begin_define
define|#
directive|define
name|NSTAND
value|0400
end_define

begin_define
define|#
directive|define
name|codeon
parameter_list|()
value|cgenflg++
end_define

begin_define
define|#
directive|define
name|codeoff
parameter_list|()
value|--cgenflg
end_define

begin_define
define|#
directive|define
name|CGENNING
value|( cgenflg>= 0 )
end_define

begin_comment
comment|/*  * Codeline is the last lino output in the code generator.  * It used to be used to suppress LINO operators but no  * more since we now count statements.  * Lc is the intepreter code location counter.  * short	codeline;  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|lc
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/*  * Routines which need types  * other than "integer" to be  * assumed by the compiler.  */
end_comment

begin_function_decl
name|double
name|atof
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|lwidth
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|leven
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|aryconst
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|a8tol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|roundup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|tmpalloc
parameter_list|()
function_decl|;
end_function_decl

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
name|int
modifier|*
name|pcalloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|savestr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|esavestr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|parnam
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getlab
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getnext
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
name|char
modifier|*
name|nameof
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|pstrcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|myctime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|putlab
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|fcompat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|constval
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|precset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|nilfnil
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|funccod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|pcfunccod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|lookup1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|hdefnl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|defnl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|flvalue
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|plist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|enter
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|nlcopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|tyrec
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|tyary
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|tyrang
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|tyscal
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|deffld
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|stklval
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|scalar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|gen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|stkrval
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|funcext
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|funchdr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|funcbody
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|yybaduse
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|stackRV
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|defvnt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|tyrec1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|reclook
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|asgnop1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|pcasgconf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|gtype
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|call
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|lvalue
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|pclvalue
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|rvalue
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|cset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|tycrang
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tnode
modifier|*
name|newlist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tnode
modifier|*
name|addlist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tnode
modifier|*
name|fixlist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tnode
modifier|*
name|setupvar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tnode
modifier|*
name|setuptyrec
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tnode
modifier|*
name|setupfield
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tnode
modifier|*
name|tree
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tnode
modifier|*
name|tree1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tnode
modifier|*
name|tree2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tnode
modifier|*
name|tree3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tnode
modifier|*
name|tree4
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tnode
modifier|*
name|tree5
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * type cast NIL to keep lint happy (which is not so bad)  */
end_comment

begin_define
define|#
directive|define
name|NLNIL
value|( (struct nl *) NIL )
end_define

begin_define
define|#
directive|define
name|TR_NIL
value|( (struct tnode *) NIL)
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
name|short
name|pint
decl_stmt|;
name|short
name|pint2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lstruct
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
name|short
name|pflstc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
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
name|long
name|tvec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|snark
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SNARK */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|classes
index|[ ]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maps namelist classes to string names */
end_comment

begin_define
define|#
directive|define
name|derror
value|error
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PC
end_ifdef

begin_comment
comment|/*      *	the current function number, for [ lines      */
end_comment

begin_decl_stmt
name|int
name|ftnno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*      *	the pc output stream      */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|pcstream
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|PC
end_endif

end_unit

