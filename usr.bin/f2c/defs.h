begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**************************************************************** Copyright 1990, 1991, 1992, 1993 by AT&T Bell Laboratories, Bellcore.  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that the copyright notice and this permission notice and warranty disclaimer appear in supporting documentation, and that the names of AT&T Bell Laboratories or Bellcore or any of their entities not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  AT&T and Bellcore disclaim all warranties with regard to this software, including all implied warranties of merchantability and fitness.  In no event shall AT&T or Bellcore be liable for any special, indirect or consequential damages or any damages whatsoever resulting from loss of use, data or profits, whether in an action of contract, negligence or other tortious action, arising out of or in connection with the use or performance of this software. ****************************************************************/
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
name|MAXTOKENLEN
value|502
end_define

begin_comment
comment|/* length of longest token */
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

begin_function_decl
specifier|extern
name|FILEP
name|opf
parameter_list|()
function_decl|;
end_function_decl

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
name|int
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
name|token
index|[ ]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|toklen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
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
name|int
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
comment|/* level of nesting , for branch-in-loop 				   checking */
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
literal|3
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
comment|/* Constant long integer */
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
name|int
name|eqvtop
decl_stmt|;
name|long
name|int
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
name|int
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
name|litnum
decl_stmt|;
comment|/* numeric part of the assembler 					   label for this constant value */
name|int
name|lituse
decl_stmt|;
comment|/* usage count */
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

begin_comment
comment|/* popular functions with non integer return values */
end_comment

begin_function_decl
name|int
modifier|*
name|ckalloc
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|char
modifier|*
name|varstr
argument_list|()
decl_stmt|,
modifier|*
name|nounder
argument_list|()
decl_stmt|,
modifier|*
name|addunder
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|copyn
argument_list|()
decl_stmt|,
modifier|*
name|copys
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|chainp
name|hookup
argument_list|()
decl_stmt|,
name|mkchain
argument_list|()
decl_stmt|,
name|revchain
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|ftnint
name|convci
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|convic
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|setdoto
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|double
name|convcd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Namep
name|mkname
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|Labelblock
modifier|*
name|mklabel
argument_list|()
decl_stmt|,
modifier|*
name|execlab
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Extsym
modifier|*
name|mkext
argument_list|()
decl_stmt|,
modifier|*
name|newentry
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|expptr
name|addrof
argument_list|()
decl_stmt|,
name|call1
argument_list|()
decl_stmt|,
name|call2
argument_list|()
decl_stmt|,
name|call3
argument_list|()
decl_stmt|,
name|call4
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Addrp
name|builtin
argument_list|()
decl_stmt|,
name|mktmp
argument_list|()
decl_stmt|,
name|mktmp0
argument_list|()
decl_stmt|,
name|mktmpn
argument_list|()
decl_stmt|,
name|autovar
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Addrp
name|mkplace
argument_list|()
decl_stmt|,
name|mkaddr
argument_list|()
decl_stmt|,
name|putconst
argument_list|()
decl_stmt|,
name|memversion
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|expptr
name|mkprim
argument_list|()
decl_stmt|,
name|mklhs
argument_list|()
decl_stmt|,
name|mkexpr
argument_list|()
decl_stmt|,
name|mkconv
argument_list|()
decl_stmt|,
name|mkfunct
argument_list|()
decl_stmt|,
name|fixexpr
argument_list|()
decl_stmt|,
name|fixtype
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|expptr
name|errnode
argument_list|()
decl_stmt|,
name|mkaddcon
argument_list|()
decl_stmt|,
name|mkintcon
argument_list|()
decl_stmt|,
name|putcxop
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|tagptr
name|cpexpr
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|ftnint
name|lmin
argument_list|()
decl_stmt|,
name|lmax
argument_list|()
decl_stmt|,
name|iarrlen
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|dbconst
argument_list|()
decl_stmt|,
modifier|*
name|flconst
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|puteq
argument_list|()
decl_stmt|,
name|putex1
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|expptr
name|putx
argument_list|()
decl_stmt|,
name|putsteq
argument_list|()
decl_stmt|,
name|putassign
argument_list|()
decl_stmt|;
end_decl_stmt

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
modifier|*
name|cds
argument_list|()
decl_stmt|,
modifier|*
name|cpstring
argument_list|()
decl_stmt|,
modifier|*
name|dtos
argument_list|()
decl_stmt|,
modifier|*
name|string_num
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|c_type_decl
parameter_list|()
function_decl|;
end_function_decl

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
name|void
name|exit
argument_list|()
decl_stmt|,
name|inferdcl
argument_list|()
decl_stmt|,
name|protowrite
argument_list|()
decl_stmt|,
name|save_argtypes
argument_list|()
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

begin_function_decl
specifier|extern
name|void
name|putwhile
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|halign
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
decl_stmt|,
name|n_st_fields
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|c_keywords
index|[]
decl_stmt|,
modifier|*
name|st_fields
index|[]
decl_stmt|;
end_decl_stmt

end_unit

