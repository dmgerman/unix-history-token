begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"../h/config.h"
end_include

begin_comment
comment|/*  * miscellaneous external declarations  */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|infile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current input file */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|outfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interpreter output file */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|dbgfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debug file */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|inname
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input file name */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|outname
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output file name */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|pname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* this program name (from command line) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|line
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* source program line number (from ucode) */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* source program file name (from ucode) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|statics
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total number of statics */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dynoff
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stack offset counter for locals */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|argoff
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stack offset counter for arguments */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|static1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* first static in procedure */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nlocal
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of locals in local table */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nconst
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of constants in constant table */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nrecords
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of records in program */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|trace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial setting of&trace */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Dflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debug flag */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|ixhdr
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Header line for direct execution */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|hdrloc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Location to place hdr block at */
end_comment

begin_comment
comment|/*  * interpreter code file header  */
end_comment

begin_struct
struct|struct
name|header
block|{
name|int
name|size
decl_stmt|;
comment|/* size of interpreter code */
name|int
name|trace
decl_stmt|;
comment|/* intial value of&trace */
name|int
name|records
decl_stmt|;
comment|/* location of record blocks */
name|int
name|ftab
decl_stmt|;
comment|/* location of record/field table */
name|int
name|globals
decl_stmt|;
comment|/* location of global variables */
name|int
name|gnames
decl_stmt|;
comment|/* location of names of globals */
name|int
name|statics
decl_stmt|;
comment|/* location of static variables */
name|int
name|ident
decl_stmt|;
comment|/* location of identifier table */
block|}
name|hdr
struct|;
end_struct

begin_comment
comment|/*  * structures for symbol table entries  */
end_comment

begin_struct
struct|struct
name|lentry
block|{
comment|/* local table entry */
name|char
modifier|*
name|l_name
decl_stmt|;
comment|/*   name of variable */
name|int
name|l_flag
decl_stmt|;
comment|/*   variable flags */
union|union
block|{
comment|/*   value field */
name|int
name|staticid
decl_stmt|;
comment|/*     unique id for static variables */
name|int
name|offset
decl_stmt|;
comment|/*     stack offset for args and locals */
name|struct
name|gentry
modifier|*
name|global
decl_stmt|;
comment|/*     global table entry */
block|}
name|l_val
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|gentry
block|{
comment|/* global table entry */
name|struct
name|gentry
modifier|*
name|g_blink
decl_stmt|;
comment|/*   link for bucket chain */
name|char
modifier|*
name|g_name
decl_stmt|;
comment|/*   name of variable */
name|int
name|g_flag
decl_stmt|;
comment|/*   variable flags */
name|int
name|g_nargs
decl_stmt|;
comment|/*   number of args or fields */
name|int
name|g_procid
decl_stmt|;
comment|/*   procedure or record id */
name|int
name|g_pc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|centry
block|{
comment|/* constant table entry */
name|int
name|c_flag
decl_stmt|;
comment|/*   type of literal flag */
union|union
block|{
comment|/*   value field */
name|long
name|ival
decl_stmt|;
comment|/*     integer */
name|double
name|rval
decl_stmt|;
comment|/*     real */
name|char
modifier|*
name|sval
decl_stmt|;
comment|/*     string */
block|}
name|c_val
union|;
name|int
name|c_length
decl_stmt|;
comment|/*   length of literal string */
name|int
name|c_pc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ientry
block|{
comment|/* identifier table entry */
name|struct
name|ientry
modifier|*
name|i_blink
decl_stmt|;
comment|/*   link for bucket chain */
name|char
modifier|*
name|i_name
decl_stmt|;
comment|/*   pointer to string */
name|int
name|i_length
decl_stmt|;
comment|/*   length of string */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fentry
block|{
comment|/* field table header entry */
name|struct
name|fentry
modifier|*
name|f_blink
decl_stmt|;
comment|/*   link for bucket chain */
name|char
modifier|*
name|f_name
decl_stmt|;
comment|/*   name of field */
name|int
name|f_fid
decl_stmt|;
comment|/*   field id */
name|struct
name|rentry
modifier|*
name|f_rlist
decl_stmt|;
comment|/*   head of list of records */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rentry
block|{
comment|/* field table record list entry */
name|struct
name|rentry
modifier|*
name|r_link
decl_stmt|;
comment|/*   link for list of records */
name|int
name|r_recid
decl_stmt|;
comment|/*   record id */
name|int
name|r_fnum
decl_stmt|;
comment|/*   offset of field within record */
block|}
struct|;
end_struct

begin_comment
comment|/*  * flag values in symbol tables  */
end_comment

begin_define
define|#
directive|define
name|F_GLOBAL
value|01
end_define

begin_comment
comment|/* variable declared global externally */
end_comment

begin_define
define|#
directive|define
name|F_PROC
value|05
end_define

begin_comment
comment|/* procedure (includes GLOBAL) */
end_comment

begin_define
define|#
directive|define
name|F_RECORD
value|011
end_define

begin_comment
comment|/* record (includes GLOBAL) */
end_comment

begin_define
define|#
directive|define
name|F_DYNAMIC
value|020
end_define

begin_comment
comment|/* variable declared local dynamic */
end_comment

begin_define
define|#
directive|define
name|F_STATIC
value|040
end_define

begin_comment
comment|/* variable declared local static */
end_comment

begin_define
define|#
directive|define
name|F_BUILTIN
value|0101
end_define

begin_comment
comment|/* identifier refers to built-in procedure */
end_comment

begin_define
define|#
directive|define
name|F_IMPERROR
value|0400
end_define

begin_comment
comment|/* procedure has default error */
end_comment

begin_define
define|#
directive|define
name|F_ARGUMENT
value|01000
end_define

begin_comment
comment|/* variable is a formal parameter */
end_comment

begin_define
define|#
directive|define
name|F_INTLIT
value|02000
end_define

begin_comment
comment|/* literal is an integer */
end_comment

begin_define
define|#
directive|define
name|F_REALLIT
value|04000
end_define

begin_comment
comment|/* literal is a real */
end_comment

begin_define
define|#
directive|define
name|F_STRLIT
value|010000
end_define

begin_comment
comment|/* literal is a string */
end_comment

begin_define
define|#
directive|define
name|F_CSETLIT
value|020000
end_define

begin_comment
comment|/* literal is a cset */
end_comment

begin_define
define|#
directive|define
name|F_LONGLIT
value|040000
end_define

begin_comment
comment|/* literal is a long integer */
end_comment

begin_comment
comment|/*  * symbol table region pointers  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|gentry
modifier|*
modifier|*
name|ghash
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hash area for global table */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|ientry
modifier|*
modifier|*
name|ihash
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hash area for identifier table */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|fentry
modifier|*
modifier|*
name|fhash
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hash area for field table */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|lentry
modifier|*
name|ltable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* local table */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|gentry
modifier|*
name|gtable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* global table */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|centry
modifier|*
name|ctable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* constant table */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|ientry
modifier|*
name|itable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* identifier table */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|fentry
modifier|*
name|ftable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* field table headers */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|rentry
modifier|*
name|rtable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* field table record lists */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strings
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string space */
end_comment

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|labels
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* label table */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|code
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* generated code space */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|gentry
modifier|*
name|gfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* free pointer for global table */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|ientry
modifier|*
name|ifree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* free pointer for identifier table */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|fentry
modifier|*
name|ffree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* free pointer for field table headers */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|rentry
modifier|*
name|rfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* free pointer for field table	record lists */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* free pointer for string space */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|codep
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* free pointer for code space */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of local table */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of global table */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|csize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of constant table */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|isize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of identifier table */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|fsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of field table headers */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of field table record lists */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ssize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of string space */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ihsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of identifier table hash area */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ghsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of global table hash area */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|fhsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of field table hash area */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|maxlabels
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum number of labels per procedure */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|maxcode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum amount of code per procedure */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gmask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mask for global table hash */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|imask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mask for identifier table hash */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|fmask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mask for field table hash */
end_comment

begin_comment
comment|/*  * symbol table parameters  */
end_comment

begin_define
define|#
directive|define
name|LSIZE
value|100
end_define

begin_comment
comment|/* default size of local table */
end_comment

begin_define
define|#
directive|define
name|GSIZE
value|200
end_define

begin_comment
comment|/* default size of global table */
end_comment

begin_define
define|#
directive|define
name|CSIZE
value|100
end_define

begin_comment
comment|/* default size of constant table */
end_comment

begin_define
define|#
directive|define
name|ISIZE
value|500
end_define

begin_comment
comment|/* default size of identifier table */
end_comment

begin_define
define|#
directive|define
name|FSIZE
value|100
end_define

begin_comment
comment|/* default size of field table headers */
end_comment

begin_define
define|#
directive|define
name|RSIZE
value|100
end_define

begin_comment
comment|/* default size of field table record lists */
end_comment

begin_define
define|#
directive|define
name|SSIZE
value|5000
end_define

begin_comment
comment|/* default size of string space */
end_comment

begin_define
define|#
directive|define
name|GHSIZE
value|64
end_define

begin_comment
comment|/* default size of global table hash area */
end_comment

begin_define
define|#
directive|define
name|IHSIZE
value|128
end_define

begin_comment
comment|/* default size of identifier table hash area */
end_comment

begin_define
define|#
directive|define
name|FHSIZE
value|32
end_define

begin_comment
comment|/* default size of field table hash area */
end_comment

begin_define
define|#
directive|define
name|MAXLABELS
value|500
end_define

begin_comment
comment|/* default maximum number of labels/proc */
end_comment

begin_comment
comment|/*  * hash computation macros  */
end_comment

begin_define
define|#
directive|define
name|ghasher
parameter_list|(
name|x
parameter_list|)
value|(((int)x)&gmask)
end_define

begin_comment
comment|/* for global table */
end_comment

begin_define
define|#
directive|define
name|fhasher
parameter_list|(
name|x
parameter_list|)
value|(((int)x)&fmask)
end_define

begin_comment
comment|/* for field table */
end_comment

begin_comment
comment|/*  * machine-dependent constants  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VAX
end_ifdef

begin_define
define|#
directive|define
name|BIT32
end_define

begin_comment
comment|/* integers have 32 bits */
end_comment

begin_define
define|#
directive|define
name|MINSHORT
value|0100000
end_define

begin_comment
comment|/* smallest short integer */
end_comment

begin_define
define|#
directive|define
name|MAXSHORT
value|077777
end_define

begin_comment
comment|/* largest short integer */
end_comment

begin_define
define|#
directive|define
name|LOGINTSIZE
value|5
end_define

begin_comment
comment|/* log of INTSIZE */
end_comment

begin_define
define|#
directive|define
name|BITOFFMASK
value|037
end_define

begin_comment
comment|/* mask for bit offset into word */
end_comment

begin_define
define|#
directive|define
name|CSETSIZE
value|8
end_define

begin_comment
comment|/* # of words to contain cset bits */
end_comment

begin_define
define|#
directive|define
name|ADDRSIZE
value|4
end_define

begin_comment
comment|/* # of bytes in a pointer */
end_comment

begin_define
define|#
directive|define
name|MAXCODE
value|10000
end_define

begin_comment
comment|/* default maximum amount of code/proc */
end_comment

begin_endif
endif|#
directive|endif
endif|VAX
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PDP11
end_ifdef

begin_define
define|#
directive|define
name|BIT16
end_define

begin_comment
comment|/* integers have 16 bits */
end_comment

begin_define
define|#
directive|define
name|MINSHORT
value|0100000
end_define

begin_comment
comment|/* smallest short integer */
end_comment

begin_define
define|#
directive|define
name|MAXSHORT
value|077777
end_define

begin_comment
comment|/* largest short integer */
end_comment

begin_define
define|#
directive|define
name|LOGINTSIZE
value|4
end_define

begin_comment
comment|/* log of INTSIZE */
end_comment

begin_define
define|#
directive|define
name|BITOFFMASK
value|017
end_define

begin_comment
comment|/* mask for bit offset into word */
end_comment

begin_define
define|#
directive|define
name|CSETSIZE
value|16
end_define

begin_comment
comment|/* # of words to contain cset bits */
end_comment

begin_define
define|#
directive|define
name|ADDRSIZE
value|2
end_define

begin_comment
comment|/* # of bytes in a pointer */
end_comment

begin_define
define|#
directive|define
name|MAXCODE
value|2000
end_define

begin_comment
comment|/* default maximum amount of code/proc */
end_comment

begin_endif
endif|#
directive|endif
endif|PDP11
end_endif

begin_comment
comment|/*  * cset accessing macros  */
end_comment

begin_define
define|#
directive|define
name|CSOFF
parameter_list|(
name|b
parameter_list|)
value|((b)& BITOFFMASK)
end_define

begin_comment
comment|/* offset in word of cs bit */
end_comment

begin_define
define|#
directive|define
name|CSPTR
parameter_list|(
name|b
parameter_list|,
name|c
parameter_list|)
value|((c) + (((b)&0377)>> LOGINTSIZE))
end_define

begin_comment
comment|/* address of word of cs bit */
end_comment

begin_define
define|#
directive|define
name|setb
parameter_list|(
name|b
parameter_list|,
name|c
parameter_list|)
value|(*CSPTR(b,c) |= (01<< CSOFF(b)))
end_define

begin_comment
comment|/* set bit b in cset c */
end_comment

begin_define
define|#
directive|define
name|MAXHDR
value|1024
end_define

begin_comment
comment|/* size of autoloading header */
end_comment

begin_define
define|#
directive|define
name|HDRFILE
value|"/usr/new/lib/icon/icont/iconx.hdr"
end_define

end_unit

