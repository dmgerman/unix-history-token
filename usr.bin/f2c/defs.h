begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**************************************************************** Copyright 1990 - 1996 by AT&T, Lucent Technologies and Bellcore.  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that the copyright notice and this permission notice and warranty disclaimer appear in supporting documentation, and that the names of AT&T, Bell Laboratories, Lucent or Bellcore or any of their entities not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  AT&T, Lucent and Bellcore disclaim all warranties with regard to this software, including all implied warranties of merchantability and fitness.  In no event shall AT&T, Lucent or Bellcore be liable for any special, indirect or consequential damages or any damages whatsoever resulting from loss of use, data or profits, whether in an action of contract, negligence or other tortious action, arising out of or in connection with the use or performance of this software. ****************************************************************/
end_comment

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_include
include|#
directive|include
file|"ftypes.h"
end_include

begin_include
include|#
directive|include
file|"defines.h"
end_include

begin_include
include|#
directive|include
file|"machdefs.h"
end_include

begin_define
define|#
directive|define
name|MAXDIM
value|20
end_define

begin_define
define|#
directive|define
name|MAXINCLUDES
value|10
end_define

begin_define
define|#
directive|define
name|MAXLITERALS
value|200
end_define

begin_comment
comment|/* Max number of constants in the literal 				   pool */
end_comment

begin_define
define|#
directive|define
name|MAXCTL
value|20
end_define

begin_define
define|#
directive|define
name|MAXHASH
value|401
end_define

begin_define
define|#
directive|define
name|MAXSTNO
value|801
end_define

begin_define
define|#
directive|define
name|MAXEXT
value|200
end_define

begin_define
define|#
directive|define
name|MAXEQUIV
value|150
end_define

begin_define
define|#
directive|define
name|MAXLABLIST
value|258
end_define

begin_comment
comment|/* Max number of labels in an alternate 				   return CALL or computed GOTO */
end_comment

begin_define
define|#
directive|define
name|MAXCONTIN
value|99
end_define

begin_comment
comment|/* Max continuation lines */
end_comment

begin_comment
comment|/* These are the primary pointer types used in the compiler */
end_comment

begin_typedef
typedef|typedef
name|union
name|Expression
modifier|*
name|expptr
typedef|,
modifier|*
name|tagptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|Chain
modifier|*
name|chainp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|Addrblock
modifier|*
name|Addrp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|Constblock
modifier|*
name|Constp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|Exprblock
modifier|*
name|Exprp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|Nameblock
modifier|*
name|Namep
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|FILEP
name|infile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILEP
name|diagfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILEP
name|textfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILEP
name|asmfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILEP
name|c_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output file for all functions; extern 				   declarations will have to be prepended */
end_comment

begin_decl_stmt
specifier|extern
name|FILEP
name|pass1_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Temp file to hold the function bodies 				   read on pass 1 */
end_comment

begin_decl_stmt
specifier|extern
name|FILEP
name|expr_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Debugging file */
end_comment

begin_decl_stmt
specifier|extern
name|FILEP
name|initfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Intermediate data file pointer */
end_comment

begin_decl_stmt
specifier|extern
name|FILEP
name|blkdfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* BLOCK DATA file */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_ftn_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|maxcontin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|blkdfname
decl_stmt|,
modifier|*
name|initfname
decl_stmt|,
modifier|*
name|sortfname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|headoffset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Since the header block requires data we 				   don't know about until AFTER each 				   function has been processed, we keep a 				   pointer to the current (dummy) header 				   block (at the top of the assembly file) 				   here */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|main_alias
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name given to PROGRAM psuedo-op */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|token
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|maxtoklen
decl_stmt|,
name|toklen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|err_lineno
decl_stmt|,
name|lineno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|infname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|needkwd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|Labelblock
modifier|*
name|thislabel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Used to allow runtime expansion of internal tables.  In particular,    these values can exceed their associated constants */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|maxctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|maxequiv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|maxstno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|maxhash
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|maxext
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|flag
name|nowarnflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|flag
name|ftn66flag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generate warnings when weird f77 				   features are used (undeclared dummy 				   procedure, non-char initialized with 				   string, 1-dim subscript in EQUIV) */
end_comment

begin_decl_stmt
specifier|extern
name|flag
name|no66flag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generate an error when a generic 				   function (f77 feature) is used */
end_comment

begin_decl_stmt
specifier|extern
name|flag
name|noextflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generate an error when an extension to 				   Fortran 77 is used (hex/oct/bin 				   constants, automatic, static, double 				   complex types) */
end_comment

begin_decl_stmt
specifier|extern
name|flag
name|zflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* enable double complex intrinsics */
end_comment

begin_decl_stmt
specifier|extern
name|flag
name|shiftcase
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|flag
name|undeftype
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|flag
name|shortsubs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Use short subscripts on arrays? */
end_comment

begin_decl_stmt
specifier|extern
name|flag
name|onetripflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if true, always execute DO loop body */
end_comment

begin_decl_stmt
specifier|extern
name|flag
name|checksubs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|flag
name|debugflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nerr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nwarn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|parstate
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|flag
name|headerdone
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True iff the current procedure's header 				   data has been written */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|blklevel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|flag
name|saveall
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|flag
name|substars
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True iff some formal parameter is an 				   asterisk */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|impltype
index|[ ]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ftnint
name|implleng
index|[ ]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|implstg
index|[ ]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tycomplex
decl_stmt|,
name|tyint
decl_stmt|,
name|tyioint
decl_stmt|,
name|tyreal
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tylog
decl_stmt|,
name|tylogical
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TY____ of the implementation of   logical. 				   This will be LONG unless '-2' is given 				   on the command line */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|type_choice
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|typename
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|typesize
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size (in bytes) of an object of each 				   type.  Indexed by TY___ macros */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|typealign
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|proctype
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Type of return value in this procedure */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|procname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* External name of the procedure, or last ENTRY name */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rtvlabel
index|[ ]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return value labels, indexed by TY___ macros */
end_comment

begin_decl_stmt
specifier|extern
name|Addrp
name|retslot
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Addrp
name|xretslot
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cxslot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Complex return argument slot (frame pointer offset)*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|chslot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Character return argument slot (fp offset) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|chlgslot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Argument slot for length of character buffer */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|procclass
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Class of the current procedure:  either CLPROC, 			   CLMAIN, CLBLOCK or CLUNKNOWN */
end_comment

begin_decl_stmt
specifier|extern
name|ftnint
name|procleng
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Length of function return value (e.g. char 			   string length).  If this is -1, then the length is 			   not known at compile time */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nentry
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of entry points (other than the original 			   function call) into this procedure */
end_comment

begin_decl_stmt
specifier|extern
name|flag
name|multitype
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* YES iff there is more than one return value 			   possible */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|blklevel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|lastiolabno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|lastlabno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lastvarno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lastargslot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* integer offset pointing to the next free 			   location for an argument to the current routine */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|argloc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|autonum
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for numbering 				   automatic variables, e.g. temporaries */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|retlabel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ret0label
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dorange
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of the label which terminates 				   the innermost DO loop */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|regnum
index|[ ]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Numbers of DO indicies named in 				   regnamep   (below) */
end_comment

begin_decl_stmt
specifier|extern
name|Namep
name|regnamep
index|[ ]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of DO indicies in registers */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|maxregvar
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of elts in   regnamep   */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|highregvar
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* keeps track of the highest register 				   number used by DO index allocator */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nregvar
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* count of DO indicies in registers */
end_comment

begin_decl_stmt
specifier|extern
name|chainp
name|templist
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|maxdim
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|chainp
name|earlylabs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|chainp
name|holdtemps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|Entrypoint
modifier|*
name|entries
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|Rplblock
modifier|*
name|rpllist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|Chain
modifier|*
name|curdtp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ftnint
name|curdtelt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|chainp
name|allargs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* union of args in entries */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nallargs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total number of args */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nallchargs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total number of character args */
end_comment

begin_decl_stmt
specifier|extern
name|flag
name|toomanyinit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True iff too many initializers in a 				   DATA statement */
end_comment

begin_decl_stmt
specifier|extern
name|flag
name|inioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iostmt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Addrp
name|ioblkp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nequiv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|eqvstart
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* offset to eqv number to guarantee uniqueness 			   and prevent<something> from going negative */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nintnames
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chain of tagged blocks */
end_comment

begin_struct
struct|struct
name|Chain
block|{
name|chainp
name|nextp
decl_stmt|;
name|char
modifier|*
name|datap
decl_stmt|;
comment|/* Tagged block */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|chainp
name|chains
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Recall that   field   is intended to hold four-bit characters */
end_comment

begin_comment
comment|/* This structure exists only to defeat the type checking */
end_comment

begin_struct
struct|struct
name|Headblock
block|{
name|field
name|tag
decl_stmt|;
name|field
name|vtype
decl_stmt|;
name|field
name|vclass
decl_stmt|;
name|field
name|vstg
decl_stmt|;
name|expptr
name|vleng
decl_stmt|;
comment|/* Expression for length of char string - 				   this may be a constant, or an argument 				   generated by mkarg() */
block|}
struct|;
end_struct

begin_comment
comment|/* Control construct info (for do loops, else, etc) */
end_comment

begin_struct
struct|struct
name|Ctlframe
block|{
name|unsigned
name|ctltype
range|:
literal|8
decl_stmt|;
name|unsigned
name|dostepsign
range|:
literal|8
decl_stmt|;
comment|/* 0 - variable, 1 - pos, 2 - neg */
name|unsigned
name|dowhile
range|:
literal|1
decl_stmt|;
name|int
name|ctlabels
index|[
literal|4
index|]
decl_stmt|;
comment|/* Control labels, defined below */
name|int
name|dolabel
decl_stmt|;
comment|/* label marking end of this DO loop */
name|Namep
name|donamep
decl_stmt|;
comment|/* DO index variable */
name|expptr
name|doinit
decl_stmt|;
comment|/* for use with -onetrip */
name|expptr
name|domax
decl_stmt|;
comment|/* constant or temp variable holding MAX 				   loop value; or expr of while(expr) */
name|expptr
name|dostep
decl_stmt|;
comment|/* expression */
name|Namep
name|loopname
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|endlabel
value|ctlabels[0]
end_define

begin_define
define|#
directive|define
name|elselabel
value|ctlabels[1]
end_define

begin_define
define|#
directive|define
name|dobodylabel
value|ctlabels[1]
end_define

begin_define
define|#
directive|define
name|doposlabel
value|ctlabels[2]
end_define

begin_define
define|#
directive|define
name|doneglabel
value|ctlabels[3]
end_define

begin_decl_stmt
specifier|extern
name|struct
name|Ctlframe
modifier|*
name|ctls
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Keeps info on DO and BLOCK IF 					   structures - this is the stack 					   bottom */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|Ctlframe
modifier|*
name|ctlstack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to current nesting 					   level */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|Ctlframe
modifier|*
name|lastctl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Point to end of 					   dynamically-allocated array */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|chainp
name|cp
decl_stmt|;
block|}
name|Atype
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|defined
decl_stmt|,
name|dnargs
decl_stmt|,
name|nargs
decl_stmt|,
name|changes
decl_stmt|;
name|Atype
name|atypes
index|[
literal|1
index|]
decl_stmt|;
block|}
name|Argtypes
typedef|;
end_typedef

begin_comment
comment|/* External Symbols */
end_comment

begin_struct
struct|struct
name|Extsym
block|{
name|char
modifier|*
name|fextname
decl_stmt|;
comment|/* Fortran version of external name */
name|char
modifier|*
name|cextname
decl_stmt|;
comment|/* C version of external name */
name|field
name|extstg
decl_stmt|;
comment|/* STG -- should be COMMON, UNKNOWN or EXT 				   */
name|unsigned
name|extype
range|:
literal|4
decl_stmt|;
comment|/* for transmitting type to output routines */
name|unsigned
name|used_here
range|:
literal|1
decl_stmt|;
comment|/* Boolean - true on the second pass 				   through a function if the block has 				   been referenced */
name|unsigned
name|exused
range|:
literal|1
decl_stmt|;
comment|/* Has been used (for help with error msgs 				   about externals typed differently in 				   different modules) */
name|unsigned
name|exproto
range|:
literal|1
decl_stmt|;
comment|/* type specified in a .P file */
name|unsigned
name|extinit
range|:
literal|1
decl_stmt|;
comment|/* Procedure has been defined, 				   or COMMON has DATA */
name|unsigned
name|extseen
range|:
literal|1
decl_stmt|;
comment|/* True if previously referenced */
name|chainp
name|extp
decl_stmt|;
comment|/* List of identifiers in the common 				   block for this function, stored as 				   Namep (hash table pointers) */
name|chainp
name|allextp
decl_stmt|;
comment|/* List of lists of identifiers; we keep one 				   list for each layout of this common block */
name|int
name|curno
decl_stmt|;
comment|/* current number for this common block, 				   used for constructing appending _nnn 				   to the common block name */
name|int
name|maxno
decl_stmt|;
comment|/* highest curno value for this common block */
name|ftnint
name|extleng
decl_stmt|;
name|ftnint
name|maxleng
decl_stmt|;
name|Argtypes
modifier|*
name|arginfo
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|Extsym
name|Extsym
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|Extsym
modifier|*
name|extsymtab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* External symbol table */
end_comment

begin_decl_stmt
specifier|extern
name|Extsym
modifier|*
name|nextext
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Extsym
modifier|*
name|lastext
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|complex_seen
decl_stmt|,
name|dcomplex_seen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Statement labels */
end_comment

begin_struct
struct|struct
name|Labelblock
block|{
name|int
name|labelno
decl_stmt|;
comment|/* Internal label */
name|unsigned
name|blklevel
range|:
literal|8
decl_stmt|;
comment|/* level of nesting, for branch-in-loop 				   checking */
name|unsigned
name|labused
range|:
literal|1
decl_stmt|;
name|unsigned
name|fmtlabused
range|:
literal|1
decl_stmt|;
name|unsigned
name|labinacc
range|:
literal|1
decl_stmt|;
comment|/* inaccessible? (i.e. has its scope 				   vanished) */
name|unsigned
name|labdefined
range|:
literal|1
decl_stmt|;
comment|/* YES or NO */
name|unsigned
name|labtype
range|:
literal|2
decl_stmt|;
comment|/* LAB{FORMAT,EXEC,etc} */
name|ftnint
name|stateno
decl_stmt|;
comment|/* Original label */
name|char
modifier|*
name|fmtstring
decl_stmt|;
comment|/* format string */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|Labelblock
modifier|*
name|labeltab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Label table - keeps track of 					   all labels, including undefined */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|Labelblock
modifier|*
name|labtabend
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|Labelblock
modifier|*
name|highlabtab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Entry point list */
end_comment

begin_struct
struct|struct
name|Entrypoint
block|{
name|struct
name|Entrypoint
modifier|*
name|entnextp
decl_stmt|;
name|Extsym
modifier|*
name|entryname
decl_stmt|;
comment|/* Name of this ENTRY */
name|chainp
name|arglist
decl_stmt|;
name|int
name|typelabel
decl_stmt|;
comment|/* Label for function exit; this 					   will return the proper type of 					   object */
name|Namep
name|enamep
decl_stmt|;
comment|/* External name */
block|}
struct|;
end_struct

begin_comment
comment|/* Primitive block, or Primary block.  This is a general template returned    by the parser, which will be interpreted in context.  It is a template    for an identifier (variable name, function name), parenthesized    arguments (array subscripts, function parameters) and substring    specifications. */
end_comment

begin_struct
struct|struct
name|Primblock
block|{
name|field
name|tag
decl_stmt|;
name|field
name|vtype
decl_stmt|;
name|unsigned
name|parenused
range|:
literal|1
decl_stmt|;
comment|/* distinguish (a) from a */
name|Namep
name|namep
decl_stmt|;
comment|/* Pointer to structure Nameblock */
name|struct
name|Listblock
modifier|*
name|argsp
decl_stmt|;
name|expptr
name|fcharp
decl_stmt|;
comment|/* first-char-index-pointer (in 					   substring) */
name|expptr
name|lcharp
decl_stmt|;
comment|/* last-char-index-pointer (in 					   substring) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Hashentry
block|{
name|int
name|hashval
decl_stmt|;
name|Namep
name|varp
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|Hashentry
modifier|*
name|hashtab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hash table */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|Hashentry
modifier|*
name|lasthash
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|Intrpacked
comment|/* bits for intrinsic function description */
block|{
name|unsigned
name|f1
range|:
literal|4
decl_stmt|;
name|unsigned
name|f2
range|:
literal|4
decl_stmt|;
name|unsigned
name|f3
range|:
literal|7
decl_stmt|;
name|unsigned
name|f4
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Nameblock
block|{
name|field
name|tag
decl_stmt|;
name|field
name|vtype
decl_stmt|;
name|field
name|vclass
decl_stmt|;
name|field
name|vstg
decl_stmt|;
name|expptr
name|vleng
decl_stmt|;
comment|/* length of character string, if applicable */
name|char
modifier|*
name|fvarname
decl_stmt|;
comment|/* name in the Fortran source */
name|char
modifier|*
name|cvarname
decl_stmt|;
comment|/* name in the resulting C */
name|chainp
name|vlastdim
decl_stmt|;
comment|/* datap points to new_vars entry for the */
comment|/* system variable, if any, storing the final */
comment|/* dimension; we zero the datap if this */
comment|/* variable is needed */
name|unsigned
name|vprocclass
range|:
literal|3
decl_stmt|;
comment|/* P____ macros - selects the   varxptr 				   field below */
name|unsigned
name|vdovar
range|:
literal|1
decl_stmt|;
comment|/* "is it a DO variable?" for register 				   and multi-level loop	checking */
name|unsigned
name|vdcldone
range|:
literal|1
decl_stmt|;
comment|/* "do I think I'm done?" - set when the 				   context is sufficient to determine its 				   status */
name|unsigned
name|vadjdim
range|:
literal|1
decl_stmt|;
comment|/* "adjustable dimension?" - needed for 				   information about copies */
name|unsigned
name|vsave
range|:
literal|1
decl_stmt|;
name|unsigned
name|vimpldovar
range|:
literal|1
decl_stmt|;
comment|/* used to prevent erroneous error messages 				   for variables used only in DATA stmt 				   implicit DOs */
name|unsigned
name|vis_assigned
range|:
literal|1
decl_stmt|;
comment|/* True if this variable has had some 				   label ASSIGNED to it; hence 				   varxptr.assigned_values is valid */
name|unsigned
name|vimplstg
range|:
literal|1
decl_stmt|;
comment|/* True if storage type is assigned implicitly; 				   this allows a COMMON variable to participate 				   in a DIMENSION before the COMMON declaration. 				   */
name|unsigned
name|vcommequiv
range|:
literal|1
decl_stmt|;
comment|/* True if EQUIVALENCEd onto STGCOMMON */
name|unsigned
name|vfmt_asg
range|:
literal|1
decl_stmt|;
comment|/* True if char *var_fmt needed */
name|unsigned
name|vpassed
range|:
literal|1
decl_stmt|;
comment|/* True if passed as a character-variable arg */
name|unsigned
name|vknownarg
range|:
literal|1
decl_stmt|;
comment|/* True if seen in a previous entry point */
name|unsigned
name|visused
range|:
literal|1
decl_stmt|;
comment|/* True if variable is referenced -- so we */
comment|/* can omit variables that only appear in DATA */
name|unsigned
name|vnamelist
range|:
literal|1
decl_stmt|;
comment|/* Appears in a NAMELIST */
name|unsigned
name|vimpltype
range|:
literal|1
decl_stmt|;
comment|/* True if implicitly typed and not 				   invoked as a function or subroutine 				   (so we can consistently type procedures 				   declared external and passed as args 				   but never invoked). 				   */
name|unsigned
name|vtypewarned
range|:
literal|1
decl_stmt|;
comment|/* so we complain just once about 				   changed types of external procedures */
name|unsigned
name|vinftype
range|:
literal|1
decl_stmt|;
comment|/* so we can restore implicit type to a 				   procedure if it is invoked as a function 				   after being given a different type by -it */
name|unsigned
name|vinfproc
range|:
literal|1
decl_stmt|;
comment|/* True if -it infers this to be a procedure */
name|unsigned
name|vcalled
range|:
literal|1
decl_stmt|;
comment|/* has been invoked */
name|unsigned
name|vdimfinish
range|:
literal|1
decl_stmt|;
comment|/* need to invoke dim_finish() */
name|unsigned
name|vrefused
range|:
literal|1
decl_stmt|;
comment|/* Need to #define name_ref (for -s) */
name|unsigned
name|vsubscrused
range|:
literal|1
decl_stmt|;
comment|/* Need to #define name_subscr (for -2) */
name|unsigned
name|veqvadjust
range|:
literal|1
decl_stmt|;
comment|/* voffset has been adjusted for equivalence */
comment|/* The   vardesc   union below is used to store the number of an intrinsic    function (when vstg == STGINTR and vprocclass == PINTRINSIC), or to    store the index of this external symbol in   extsymtab   (when vstg ==    STGEXT and vprocclass == PEXTERNAL) */
union|union
block|{
name|int
name|varno
decl_stmt|;
comment|/* Return variable for a function. 					   This is used when a function is 					   assigned a return value.  Also 					   used to point to the COMMON 					   block, when this is a field of 					   that block.  Also points to 					   EQUIV block when STGEQUIV */
name|struct
name|Intrpacked
name|intrdesc
decl_stmt|;
comment|/* bits for intrinsic function*/
block|}
name|vardesc
union|;
name|struct
name|Dimblock
modifier|*
name|vdim
decl_stmt|;
comment|/* points to the dimensions if they exist */
name|ftnint
name|voffset
decl_stmt|;
comment|/* offset in a storage block (the variable 				   name will be "v.%d", voffset in a 				   common blck on the vax).  Also holds 				   pointers for automatic variables.  When 				   STGEQUIV, this is -(offset from array 				   base) */
union|union
block|{
name|chainp
name|namelist
decl_stmt|;
comment|/* points to names in the NAMELIST, 					   if this is a NAMELIST name */
name|chainp
name|vstfdesc
decl_stmt|;
comment|/* points to (formals, expr) pair */
name|chainp
name|assigned_values
decl_stmt|;
comment|/* list of integers, each being a 					   statement label assigned to 					   this variable in the current function */
block|}
name|varxptr
union|;
name|int
name|argno
decl_stmt|;
comment|/* for multiple entries */
name|Argtypes
modifier|*
name|arginfo
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* PARAMETER statements */
end_comment

begin_struct
struct|struct
name|Paramblock
block|{
name|field
name|tag
decl_stmt|;
name|field
name|vtype
decl_stmt|;
name|field
name|vclass
decl_stmt|;
name|field
name|vstg
decl_stmt|;
name|expptr
name|vleng
decl_stmt|;
name|char
modifier|*
name|fvarname
decl_stmt|;
name|char
modifier|*
name|cvarname
decl_stmt|;
name|expptr
name|paramval
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Expression block */
end_comment

begin_struct
struct|struct
name|Exprblock
block|{
name|field
name|tag
decl_stmt|;
name|field
name|vtype
decl_stmt|;
name|field
name|vclass
decl_stmt|;
name|field
name|vstg
decl_stmt|;
name|expptr
name|vleng
decl_stmt|;
comment|/* in the case of a character expression, this 				   value is inherited from the children */
name|unsigned
name|opcode
decl_stmt|;
name|expptr
name|leftp
decl_stmt|;
name|expptr
name|rightp
decl_stmt|;
name|int
name|typefixed
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|Constant
block|{
struct|struct
block|{
name|char
modifier|*
name|ccp0
decl_stmt|;
name|ftnint
name|blanks
decl_stmt|;
block|}
name|ccp1
struct|;
name|ftnint
name|ci
decl_stmt|;
comment|/* Constant longeger */
name|double
name|cd
index|[
literal|2
index|]
decl_stmt|;
name|char
modifier|*
name|cds
index|[
literal|2
index|]
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|ccp
value|ccp1.ccp0
end_define

begin_struct
struct|struct
name|Constblock
block|{
name|field
name|tag
decl_stmt|;
name|field
name|vtype
decl_stmt|;
name|field
name|vclass
decl_stmt|;
name|field
name|vstg
decl_stmt|;
comment|/* vstg = 1 when using Const.cds */
name|expptr
name|vleng
decl_stmt|;
name|union
name|Constant
name|Const
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Listblock
block|{
name|field
name|tag
decl_stmt|;
name|field
name|vtype
decl_stmt|;
name|chainp
name|listp
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Address block - this is the FINAL form of identifiers before being    sent to pass 2.  We'll want to add the original identifier here so that it can    be preserved in the translation.     An example identifier is q.7.  The "q" refers to the storage class    (field vstg), the 7 to the variable number (int memno). */
end_comment

begin_struct
struct|struct
name|Addrblock
block|{
name|field
name|tag
decl_stmt|;
name|field
name|vtype
decl_stmt|;
name|field
name|vclass
decl_stmt|;
name|field
name|vstg
decl_stmt|;
name|expptr
name|vleng
decl_stmt|;
comment|/* put union...user here so the beginning of an Addrblock 	 * is the same as a Constblock. 	 */
union|union
block|{
name|Namep
name|name
decl_stmt|;
comment|/* contains a pointer into the hash table */
name|char
name|ident
index|[
name|IDENT_LEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* C string form of identifier */
name|char
modifier|*
name|Charp
decl_stmt|;
name|union
name|Constant
name|Const
decl_stmt|;
comment|/* Constant value */
struct|struct
block|{
name|double
name|dfill
index|[
literal|2
index|]
decl_stmt|;
name|field
name|vstg1
decl_stmt|;
block|}
name|kludge
struct|;
comment|/* so we can distinguish string vs binary 				 * floating-point constants */
block|}
name|user
union|;
name|long
name|memno
decl_stmt|;
comment|/* when vstg == STGCONST, this is the 				   numeric part of the assembler label 				   where the constant value is stored */
name|expptr
name|memoffset
decl_stmt|;
comment|/* used in subscript computations, usually */
name|unsigned
name|istemp
range|:
literal|1
decl_stmt|;
comment|/* used in stack management of temporary 				   variables */
name|unsigned
name|isarray
range|:
literal|1
decl_stmt|;
comment|/* used to show that memoffset is 				   meaningful, even if zero */
name|unsigned
name|ntempelt
range|:
literal|10
decl_stmt|;
comment|/* for representing temporary arrays, as 				   in concatenation */
name|unsigned
name|dbl_builtin
range|:
literal|1
decl_stmt|;
comment|/* builtin to be declared double */
name|unsigned
name|charleng
range|:
literal|1
decl_stmt|;
comment|/* so saveargtypes can get i/o calls right */
name|unsigned
name|cmplx_sub
range|:
literal|1
decl_stmt|;
comment|/* used in complex arithmetic under -s */
name|unsigned
name|skip_offset
range|:
literal|1
decl_stmt|;
comment|/* used in complex arithmetic under -s */
name|unsigned
name|parenused
range|:
literal|1
decl_stmt|;
comment|/* distinguish (a) from a */
name|ftnint
name|varleng
decl_stmt|;
comment|/* holds a copy of a constant length which 				   is stored in the   vleng   field (e.g. 				   a double is 8 bytes) */
name|int
name|uname_tag
decl_stmt|;
comment|/* Tag describing which of the unions() 				   below to use */
name|char
modifier|*
name|Field
decl_stmt|;
comment|/* field name when dereferencing a struct */
block|}
struct|;
end_struct

begin_comment
comment|/* struct Addrblock */
end_comment

begin_comment
comment|/* Errorbock - placeholder for errors, to allow the compilation to    continue */
end_comment

begin_struct
struct|struct
name|Errorblock
block|{
name|field
name|tag
decl_stmt|;
name|field
name|vtype
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Implicit DO block, especially related to DATA statements.  This block    keeps track of the compiler's location in the implicit DO while it's    running.  In particular, the   isactive and isbusy   flags tell where    it is */
end_comment

begin_struct
struct|struct
name|Impldoblock
block|{
name|field
name|tag
decl_stmt|;
name|unsigned
name|isactive
range|:
literal|1
decl_stmt|;
name|unsigned
name|isbusy
range|:
literal|1
decl_stmt|;
name|Namep
name|varnp
decl_stmt|;
name|Constp
name|varvp
decl_stmt|;
name|chainp
name|impdospec
decl_stmt|;
name|expptr
name|implb
decl_stmt|;
name|expptr
name|impub
decl_stmt|;
name|expptr
name|impstep
decl_stmt|;
name|ftnint
name|impdiff
decl_stmt|;
name|ftnint
name|implim
decl_stmt|;
name|struct
name|Chain
modifier|*
name|datalist
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Each of these components has a first field called   tag.   This union    exists just for allocation simplicity */
end_comment

begin_union
union|union
name|Expression
block|{
name|field
name|tag
decl_stmt|;
name|struct
name|Addrblock
name|addrblock
decl_stmt|;
name|struct
name|Constblock
name|constblock
decl_stmt|;
name|struct
name|Errorblock
name|errorblock
decl_stmt|;
name|struct
name|Exprblock
name|exprblock
decl_stmt|;
name|struct
name|Headblock
name|headblock
decl_stmt|;
name|struct
name|Impldoblock
name|impldoblock
decl_stmt|;
name|struct
name|Listblock
name|listblock
decl_stmt|;
name|struct
name|Nameblock
name|nameblock
decl_stmt|;
name|struct
name|Paramblock
name|paramblock
decl_stmt|;
name|struct
name|Primblock
name|primblock
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|Dimblock
block|{
name|int
name|ndim
decl_stmt|;
name|expptr
name|nelt
decl_stmt|;
comment|/* This is NULL if the array is unbounded */
name|expptr
name|baseoffset
decl_stmt|;
comment|/* a constant or local variable holding 				   the offset in this procedure */
name|expptr
name|basexpr
decl_stmt|;
comment|/* expression for comuting the offset, if 				   it's not constant.  If this is 				   non-null, the register named in 				   baseoffset will get initialized to this 				   value in the procedure's prolog */
struct|struct
block|{
name|expptr
name|dimsize
decl_stmt|;
comment|/* constant or register holding the size 				   of this dimension */
name|expptr
name|dimexpr
decl_stmt|;
comment|/* as above in basexpr, this is an 				   expression for computing a variable 				   dimension */
block|}
name|dims
index|[
literal|1
index|]
struct|;
comment|/* Dimblocks are allocated with enough 				   space for this to become dims[ndim] */
block|}
struct|;
end_struct

begin_comment
comment|/* Statement function identifier stack - this holds the name and value of    the parameters in a statement function invocation.  For example,  	f(x,y,z)=x+y+z 		. 		. 	y = f(1,2,3)     generates a stack of depth 3, with<x 1>,<y 2>,<z 3> AT THE INVOCATION, NOT    at the definition */
end_comment

begin_struct
struct|struct
name|Rplblock
comment|/* name replacement block */
block|{
name|struct
name|Rplblock
modifier|*
name|rplnextp
decl_stmt|;
name|Namep
name|rplnp
decl_stmt|;
comment|/* Name of the formal parameter */
name|expptr
name|rplvp
decl_stmt|;
comment|/* Value of the actual parameter */
name|expptr
name|rplxp
decl_stmt|;
comment|/* Initialization of temporary variable, 				   if required; else null */
name|int
name|rpltag
decl_stmt|;
comment|/* Tag on the value of the actual param */
block|}
struct|;
end_struct

begin_comment
comment|/* Equivalence block */
end_comment

begin_struct
struct|struct
name|Equivblock
block|{
name|struct
name|Eqvchain
modifier|*
name|equivs
decl_stmt|;
comment|/* List (Eqvchain) of primblocks 					   holding variable identifiers */
name|flag
name|eqvinit
decl_stmt|;
name|long
name|eqvtop
decl_stmt|;
name|long
name|eqvbottom
decl_stmt|;
name|int
name|eqvtype
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|eqvleng
value|eqvtop
end_define

begin_decl_stmt
specifier|extern
name|struct
name|Equivblock
modifier|*
name|eqvclass
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|Eqvchain
block|{
name|struct
name|Eqvchain
modifier|*
name|eqvnextp
decl_stmt|;
union|union
block|{
name|struct
name|Primblock
modifier|*
name|eqvlhs
decl_stmt|;
name|Namep
name|eqvname
decl_stmt|;
block|}
name|eqvitem
union|;
name|long
name|eqvoffset
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* For allocation purposes only, and to keep lint quiet.  In particular,    don't count on the tag being able to tell you which structure is used */
end_comment

begin_comment
comment|/* There is a tradition in Fortran that the compiler not generate the same    bit pattern more than is necessary.  This structure is used to do just    that; if two integer constants have the same bit pattern, just generate    it once.  This could be expanded to optimize without regard to type, by    removing the type check in   putconst()   */
end_comment

begin_struct
struct|struct
name|Literal
block|{
name|short
name|littype
decl_stmt|;
name|short
name|lituse
decl_stmt|;
comment|/* usage count */
name|long
name|litnum
decl_stmt|;
comment|/* numeric part of the assembler 					   label for this constant value */
union|union
block|{
name|ftnint
name|litival
decl_stmt|;
name|double
name|litdval
index|[
literal|2
index|]
decl_stmt|;
name|ftnint
name|litival2
index|[
literal|2
index|]
decl_stmt|;
comment|/* length, nblanks for strings */
block|}
name|litval
union|;
name|char
modifier|*
name|cds
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|Literal
modifier|*
name|litpool
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|maxliterals
decl_stmt|,
name|nliterals
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|Letters
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|letter
parameter_list|(
name|x
parameter_list|)
value|Letters[x]
end_define

begin_struct
struct|struct
name|Dims
block|{
name|expptr
name|lb
decl_stmt|,
name|ub
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|forcedouble
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* force real functions to double */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|doin_setbound
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* special handling for array bounds */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Ansi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|hextoi_tab
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|hextoi
parameter_list|(
name|x
parameter_list|)
value|hextoi_tab[(x)& 0xff]
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|casttypes
index|[]
decl_stmt|,
modifier|*
name|ftn_types
index|[]
decl_stmt|,
modifier|*
name|protorettypes
index|[]
decl_stmt|,
modifier|*
name|usedcasts
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Castargs
decl_stmt|,
name|infertypes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|protofile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|binread
index|[]
decl_stmt|,
name|binwrite
index|[]
decl_stmt|,
name|textread
index|[]
decl_stmt|,
name|textwrite
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ei_first
decl_stmt|,
modifier|*
name|ei_last
decl_stmt|,
modifier|*
name|ei_next
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|wh_first
decl_stmt|,
modifier|*
name|wh_last
decl_stmt|,
modifier|*
name|wh_next
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|halign
decl_stmt|,
modifier|*
name|outbuf
decl_stmt|,
modifier|*
name|outbtail
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|flag
name|keepsubs
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|TYQUAD
end_ifdef

begin_decl_stmt
specifier|extern
name|flag
name|use_tyquad
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|n_keywords
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|c_keywords
index|[]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_define
define|#
directive|define
name|Argdcl
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_define
define|#
directive|define
name|Void
end_define

begin_comment
comment|/* void */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Argdcl
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|Void
value|void
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
modifier|*
name|Alloc
name|Argdcl
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Argtype
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Fatal
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|Impldoblock
modifier|*
name|mkiodo
name|Argdcl
argument_list|(
operator|(
name|chainp
operator|,
name|chainp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|Inline
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|chainp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|Labelblock
modifier|*
name|execlab
name|Argdcl
argument_list|(
operator|(
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|Labelblock
modifier|*
name|mklabel
name|Argdcl
argument_list|(
operator|(
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|Listblock
modifier|*
name|mklist
name|Argdcl
argument_list|(
operator|(
name|chainp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Un_link_all
name|Argdcl
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|add_extern_to_list
name|Argdcl
argument_list|(
operator|(
name|Addrp
operator|,
name|chainp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|addressable
name|Argdcl
argument_list|(
operator|(
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|addrof
name|Argdcl
argument_list|(
operator|(
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|addunder
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Addrp
name|autovar
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|tagptr
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|backup
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bad_atypes
name|Argdcl
argument_list|(
operator|(
name|Argtypes
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|badchleng
name|Argdcl
argument_list|(
operator|(
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|badop
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|badstg
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|badtag
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|badthing
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|badtype
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Addrp
name|builtin
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|c_name
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|call0
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|call1
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|call2
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|tagptr
operator|,
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|call3
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|tagptr
operator|,
name|tagptr
operator|,
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|call4
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|tagptr
operator|,
name|tagptr
operator|,
name|tagptr
operator|,
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|callk
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|chainp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cast_args
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|chainp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|cds
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|changedtype
name|Argdcl
argument_list|(
operator|(
name|Namep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ptr
name|ckalloc
name|Argdcl
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cktype
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|clf
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cmpstr
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|long
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|c_type_decl
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Extsym
modifier|*
name|comblock
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|comm_union_name
name|Argdcl
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|consconv
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|Constp
operator|,
name|Constp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|consnegop
name|Argdcl
argument_list|(
operator|(
name|Constp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|conssgn
name|Argdcl
argument_list|(
operator|(
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|convic
name|Argdcl
argument_list|(
operator|(
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|copy_data
name|Argdcl
argument_list|(
operator|(
name|chainp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|copyn
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|copys
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|cpblock
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|cpexpr
name|Argdcl
argument_list|(
operator|(
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cpn
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|cpstring
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|dataline
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|dataname
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|dataval
name|Argdcl
argument_list|(
operator|(
name|tagptr
operator|,
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|dclerr
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|Namep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|def_commons
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|def_start
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|deregister
name|Argdcl
argument_list|(
operator|(
name|Namep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|do_uninit_equivs
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
name|ptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|doequiv
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dofork
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|doinclude
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|doio
name|Argdcl
argument_list|(
operator|(
name|chainp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|done
name|Argdcl
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|donmlist
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|dsort
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|dtos
name|Argdcl
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|elif_out
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|end_else_out
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|enddcl
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|enddo
name|Argdcl
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|endio
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|endioctl
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|endproc
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|entrypt
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|long
operator|,
name|Extsym
operator|*
operator|,
name|chainp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|eqn
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|equiv_name
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|err
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|err66
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|errext
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|erri
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|errl
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|tagptr
name|errnode
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|errstr
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|exarif
name|Argdcl
argument_list|(
operator|(
name|tagptr
operator|,
expr|struct
name|Labelblock
operator|*
operator|,
expr|struct
name|Labelblock
operator|*
operator|,
expr|struct
name|Labelblock
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|exasgoto
name|Argdcl
argument_list|(
operator|(
name|Namep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|exassign
name|Argdcl
argument_list|(
operator|(
name|Namep
operator|,
expr|struct
name|Labelblock
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|excall
name|Argdcl
argument_list|(
operator|(
name|Namep
operator|,
expr|struct
name|Listblock
operator|*
operator|,
name|int
operator|,
expr|struct
name|Labelblock
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|exdo
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|Namep
operator|,
name|chainp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|execerr
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|exelif
name|Argdcl
argument_list|(
operator|(
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|exelse
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|exenddo
name|Argdcl
argument_list|(
operator|(
name|Namep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|exendif
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|exequals
name|Argdcl
argument_list|(
operator|(
expr|struct
name|Primblock
operator|*
operator|,
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|exgoto
name|Argdcl
argument_list|(
operator|(
expr|struct
name|Labelblock
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|exif
name|Argdcl
argument_list|(
operator|(
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|exreturn
name|Argdcl
argument_list|(
operator|(
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|exstop
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|extern_out
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
name|Extsym
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fatali
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fatalstr
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ffilecopy
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
name|FILEP
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|fileinit
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|fixargs
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|Listblock
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|fixexpr
name|Argdcl
argument_list|(
operator|(
name|Exprp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|fixtype
name|Argdcl
argument_list|(
operator|(
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|flconst
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|flline
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fmt_init
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|fmtname
name|Argdcl
argument_list|(
operator|(
name|Namep
operator|,
name|Addrp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fmtstmt
name|Argdcl
argument_list|(
operator|(
expr|struct
name|Labelblock
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|fold
name|Argdcl
argument_list|(
operator|(
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|frchain
name|Argdcl
argument_list|(
operator|(
name|chainp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|frdata
name|Argdcl
argument_list|(
operator|(
name|chainp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|freetemps
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|freqchain
name|Argdcl
argument_list|(
operator|(
expr|struct
name|Equivblock
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|frexchain
name|Argdcl
argument_list|(
operator|(
name|chainp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|frexpr
name|Argdcl
argument_list|(
operator|(
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|frrpl
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|frtemp
name|Argdcl
argument_list|(
operator|(
name|Addrp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|gmem
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|hashclear
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|chainp
name|hookup
name|Argdcl
argument_list|(
operator|(
name|chainp
operator|,
name|chainp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|expptr
name|imagpart
name|Argdcl
argument_list|(
operator|(
name|Addrp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|impldcl
name|Argdcl
argument_list|(
operator|(
name|Namep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|in_vector
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|incomm
name|Argdcl
argument_list|(
operator|(
name|Extsym
operator|*
operator|,
name|Namep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|inferdcl
name|Argdcl
argument_list|(
operator|(
name|Namep
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|inilex
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|initkey
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|inregister
name|Argdcl
argument_list|(
operator|(
name|Namep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|int
name|commlen
name|Argdcl
argument_list|(
operator|(
name|chainp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|int
name|convci
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|int
name|iarrlen
name|Argdcl
argument_list|(
operator|(
name|Namep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|int
name|lencat
name|Argdcl
argument_list|(
operator|(
name|expptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|int
name|lmax
name|Argdcl
argument_list|(
operator|(
name|long
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|int
name|lmin
name|Argdcl
argument_list|(
operator|(
name|long
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|int
name|wr_char_len
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
expr|struct
name|Dimblock
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Addrp
name|intraddr
name|Argdcl
argument_list|(
operator|(
name|Namep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|intrcall
name|Argdcl
argument_list|(
operator|(
name|Namep
operator|,
expr|struct
name|Listblock
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|intrfunct
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ioclause
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|expptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|iocname
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|is_negatable
name|Argdcl
argument_list|(
operator|(
name|Constp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isaddr
name|Argdcl
argument_list|(
operator|(
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isnegative_const
name|Argdcl
argument_list|(
operator|(
name|Constp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isstatic
name|Argdcl
argument_list|(
operator|(
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|chainp
name|length_comp
name|Argdcl
argument_list|(
operator|(
expr|struct
name|Entrypoint
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lengtype
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|lexline
name|Argdcl
argument_list|(
operator|(
name|ptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|list_arg_types
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
expr|struct
name|Entrypoint
operator|*
operator|,
name|chainp
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|list_decls
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|list_init_data
name|Argdcl
argument_list|(
operator|(
name|FILE
operator|*
operator|*
operator|,
name|char
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|listargs
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
expr|struct
name|Entrypoint
operator|*
operator|,
name|int
operator|,
name|chainp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|lit_name
name|Argdcl
argument_list|(
operator|(
expr|struct
name|Literal
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|log_2
name|Argdcl
argument_list|(
operator|(
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|lower_string
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
decl|main
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|expptr
name|make_int_expr
name|Argdcl
argument_list|(
operator|(
name|expptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|make_param
name|Argdcl
argument_list|(
operator|(
expr|struct
name|Paramblock
operator|*
operator|,
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|many
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|margin_printf
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|maxtype
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|mem
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|mem_init
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|char
modifier|*
name|memname
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Addrp
name|memversion
name|Argdcl
argument_list|(
operator|(
name|Namep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|mkaddcon
name|Argdcl
argument_list|(
operator|(
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Addrp
name|mkaddr
name|Argdcl
argument_list|(
operator|(
name|Namep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Addrp
name|mkarg
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|mkbitcon
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|chainp
name|mkchain
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|chainp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Constp
name|mkconst
name|Argdcl
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|mkconv
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|mkcxcon
name|Argdcl
argument_list|(
operator|(
name|tagptr
operator|,
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|mkexpr
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|tagptr
operator|,
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Extsym
modifier|*
name|mkext
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Extsym
modifier|*
name|mkext1
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Addrp
name|mkfield
name|Argdcl
argument_list|(
operator|(
name|Addrp
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|mkfunct
name|Argdcl
argument_list|(
operator|(
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|mkintcon
name|Argdcl
argument_list|(
operator|(
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|mklhs
name|Argdcl
argument_list|(
operator|(
expr|struct
name|Primblock
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|mklogcon
name|Argdcl
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Namep
name|mkname
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Addrp
name|mkplace
name|Argdcl
argument_list|(
operator|(
name|Namep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|mkprim
name|Argdcl
argument_list|(
operator|(
name|Namep
operator|,
expr|struct
name|Listblock
operator|*
operator|,
name|chainp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|mkrealcon
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Addrp
name|mkscalar
name|Argdcl
argument_list|(
operator|(
name|Namep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|mkstfunct
name|Argdcl
argument_list|(
operator|(
expr|struct
name|Primblock
operator|*
operator|,
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|mkstrcon
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Addrp
name|mktmp
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Addrp
name|mktmp0
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Addrp
name|mktmpn
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|namelist
name|Argdcl
argument_list|(
operator|(
name|Namep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ncat
name|Argdcl
argument_list|(
operator|(
name|expptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|negate_const
name|Argdcl
argument_list|(
operator|(
name|Constp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|new_endif
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|Extsym
modifier|*
name|newentry
name|Argdcl
argument_list|(
operator|(
name|Namep
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|long
name|newlabel
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|newproc
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|Addrp
name|nextdata
name|Argdcl
argument_list|(
operator|(
name|long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nice_printf
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|not_both
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|np_init
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|oneof_stg
name|Argdcl
argument_list|(
operator|(
name|Namep
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|op_assign
name|Argdcl
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|opconv
name|Argdcl
argument_list|(
operator|(
name|tagptr
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILEP
name|opf
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|out_addr
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
name|Addrp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|out_asgoto
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|out_call
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
name|int
operator|,
name|int
operator|,
name|tagptr
operator|,
name|tagptr
operator|,
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|out_const
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
name|Constp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|out_else
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|out_for
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
name|tagptr
operator|,
name|tagptr
operator|,
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|out_init
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|outbuf_adjust
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|p1_label
name|Argdcl
argument_list|(
operator|(
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|prcona
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|prconi
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|prconr
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
name|Constp
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|procinit
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|procode
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|prolog
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
name|chainp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|protowrite
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
name|int
operator|,
name|char
operator|*
operator|,
expr|struct
name|Entrypoint
operator|*
operator|,
name|chainp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|expptr
name|prune_left_conv
name|Argdcl
argument_list|(
operator|(
name|expptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|put_one_arg
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|expptr
name|putassign
name|Argdcl
argument_list|(
operator|(
name|expptr
operator|,
name|expptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Addrp
name|putchop
name|Argdcl
argument_list|(
operator|(
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|putcmgo
name|Argdcl
argument_list|(
operator|(
name|tagptr
operator|,
name|int
operator|,
expr|struct
name|Labelblock
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Addrp
name|putconst
name|Argdcl
argument_list|(
operator|(
name|Constp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|putcxop
name|Argdcl
argument_list|(
operator|(
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|puteq
name|Argdcl
argument_list|(
operator|(
name|expptr
operator|,
name|expptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|putexpr
name|Argdcl
argument_list|(
operator|(
name|expptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|puthead
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|putif
name|Argdcl
argument_list|(
operator|(
name|tagptr
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|putout
name|Argdcl
argument_list|(
operator|(
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|expptr
name|putsteq
name|Argdcl
argument_list|(
operator|(
name|Addrp
operator|,
name|Addrp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|putwhile
name|Argdcl
argument_list|(
operator|(
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|putx
name|Argdcl
argument_list|(
operator|(
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|r8fix
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|rdlong
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
name|long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rdname
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
name|ptr
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|read_Pfiles
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Addrp
name|realpart
name|Argdcl
argument_list|(
operator|(
name|Addrp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|chainp
name|revchain
name|Argdcl
argument_list|(
operator|(
name|chainp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|same_expr
name|Argdcl
argument_list|(
operator|(
name|tagptr
operator|,
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|same_ident
name|Argdcl
argument_list|(
operator|(
name|tagptr
operator|,
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|save_argtypes
name|Argdcl
argument_list|(
operator|(
name|chainp
operator|,
name|Argtypes
operator|*
operator|*
operator|,
name|Argtypes
operator|*
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|saveargtypes
name|Argdcl
argument_list|(
operator|(
name|Exprp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|set_externs
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_tmp_names
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|setbound
name|Argdcl
argument_list|(
operator|(
name|Namep
operator|,
name|int
operator|,
expr|struct
name|Dims
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setdata
name|Argdcl
argument_list|(
operator|(
name|Addrp
operator|,
name|Constp
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setext
name|Argdcl
argument_list|(
operator|(
name|Namep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setfmt
name|Argdcl
argument_list|(
operator|(
expr|struct
name|Labelblock
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setimpl
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|long
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setintr
name|Argdcl
argument_list|(
operator|(
name|Namep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|settype
name|Argdcl
argument_list|(
operator|(
name|Namep
operator|,
name|int
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sigcatch
name|Argdcl
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sserr
name|Argdcl
argument_list|(
operator|(
name|Namep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|start_formatting
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|startioctl
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|startproc
name|Argdcl
argument_list|(
operator|(
name|Extsym
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|startrw
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|char
modifier|*
name|string_num
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|struct_eq
name|Argdcl
argument_list|(
operator|(
name|chainp
operator|,
name|chainp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|subcheck
name|Argdcl
argument_list|(
operator|(
name|Namep
operator|,
name|tagptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tagptr
name|suboffset
name|Argdcl
argument_list|(
operator|(
expr|struct
name|Primblock
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|type_fixup
name|Argdcl
argument_list|(
operator|(
name|Argtypes
operator|*
operator|,
name|Atype
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|unamstring
name|Argdcl
argument_list|(
operator|(
name|Addrp
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|unclassifiable
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|vardcl
name|Argdcl
argument_list|(
operator|(
name|Namep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|warn
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|warn1
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|warni
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|wr_abbrevs
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
name|int
operator|,
name|chainp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|wr_ardecls
name|Argdcl
argument_list|(
operator|(
name|FILE
operator|*
operator|,
expr|struct
name|Dimblock
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|wr_array_init
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
name|int
operator|,
name|chainp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|wr_common_decls
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|wr_equiv_init
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
name|int
operator|,
name|chainp
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|wr_globals
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|wr_nv_ident_help
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
name|Addrp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|wr_struct
name|Argdcl
argument_list|(
operator|(
name|FILEP
operator|,
name|chainp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|wronginf
name|Argdcl
argument_list|(
operator|(
name|Namep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|yyerror
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|yylex
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|yyparse
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|USE_DTOA
end_ifdef

begin_define
define|#
directive|define
name|atof
parameter_list|(
name|x
parameter_list|)
value|strtod(x,0)
end_define

begin_decl_stmt
name|void
name|g_fmt
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

