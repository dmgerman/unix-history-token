begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Definitions and declarations used throughout the run-time system.  */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|VAX
end_ifdef

begin_comment
comment|/*  * Memory sizes.  */
end_comment

begin_define
define|#
directive|define
name|MAXHEAPSIZE
value|51200
end_define

begin_comment
comment|/* size of the heap in bytes */
end_comment

begin_define
define|#
directive|define
name|MAXSTRSPACE
value|51200
end_define

begin_comment
comment|/* size of the string space in bytes */
end_comment

begin_define
define|#
directive|define
name|STACKSIZE
value|2000
end_define

begin_comment
comment|/* size of co-expression stack in words */
end_comment

begin_define
define|#
directive|define
name|MAXSTACKS
value|4
end_define

begin_comment
comment|/* number of coexpression stacks */
end_comment

begin_define
define|#
directive|define
name|NUMBUF
value|10
end_define

begin_comment
comment|/* number of i/o buffers available */
end_comment

begin_define
define|#
directive|define
name|NBUCKETS
value|37
end_define

begin_comment
comment|/* number of hash buckets */
end_comment

begin_comment
comment|/*  * Implementation specific constants.  */
end_comment

begin_define
define|#
directive|define
name|INTSIZE
value|32
end_define

begin_comment
comment|/* bits per integer */
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
name|MINLONG
value|020000000000L
end_define

begin_comment
comment|/* smallest long integer */
end_comment

begin_define
define|#
directive|define
name|MAXLONG
value|017777777777L
end_define

begin_comment
comment|/* largest long integer */
end_comment

begin_define
define|#
directive|define
name|LGHUGE
value|39
end_define

begin_comment
comment|/* maximum base-10 exp+1 of real */
end_comment

begin_define
define|#
directive|define
name|FRAMELIMIT
value|2
end_define

begin_comment
comment|/* maxmum negative offset in proc frame */
end_comment

begin_define
define|#
directive|define
name|WORDSIZE
value|sizeof(int *)
end_define

begin_comment
comment|/* size in bytes of a pointer */
end_comment

begin_define
define|#
directive|define
name|STKBASE
value|0x7fffffff
end_define

begin_comment
comment|/* highest possible address for sp */
end_comment

begin_define
define|#
directive|define
name|GRANSIZE
value|1024
end_define

begin_comment
comment|/* storage allocation granule size */
end_comment

begin_comment
comment|/*  * Some macros for source code tailoring.  */
end_comment

begin_define
define|#
directive|define
name|SetBound
value|setbound()
end_define

begin_define
define|#
directive|define
name|ClearBound
value|clrbound()
end_define

begin_define
define|#
directive|define
name|DclSave
value|register int saveefp,savegfp;
end_define

begin_define
define|#
directive|define
name|EntryPoint
parameter_list|(
name|x
parameter_list|)
value|(char *)x + 2
end_define

begin_define
define|#
directive|define
name|Global
parameter_list|(
name|x
parameter_list|)
value|.globl x
end_define

begin_define
define|#
directive|define
name|DummyFcn
parameter_list|(
name|x
parameter_list|)
value|.globl x; x: halt
end_define

begin_define
define|#
directive|define
name|DummyData
parameter_list|(
name|x
parameter_list|)
value|.globl x; x: .long 0
end_define

begin_define
define|#
directive|define
name|DummyRef
parameter_list|(
name|x
parameter_list|)
value|.long x
end_define

begin_define
define|#
directive|define
name|gfp
value|r10
end_define

begin_define
define|#
directive|define
name|efp
value|r11
end_define

begin_define
define|#
directive|define
name|ipc
value|r9
end_define

begin_comment
comment|/*  * Cset initialization macros.  */
end_comment

begin_define
define|#
directive|define
name|twd
parameter_list|(
name|w0
parameter_list|,
name|w1
parameter_list|)
value|((w0)&0xffff | (w1)<<16)
end_define

begin_define
define|#
directive|define
name|cset_display
parameter_list|(
name|w0
parameter_list|,
name|w1
parameter_list|,
name|w2
parameter_list|,
name|w3
parameter_list|,
name|w4
parameter_list|,
name|w5
parameter_list|,
name|w6
parameter_list|,
name|w7
parameter_list|,
name|w8
parameter_list|,
name|w9
parameter_list|,
name|wa
parameter_list|,
name|wb
parameter_list|,
name|wc
parameter_list|,
name|wd
parameter_list|,
name|we
parameter_list|,
name|wf
parameter_list|)
define|\
value|{twd(w0,w1),twd(w2,w3),twd(w4,w5),twd(w6,w7), \          twd(w8,w9),twd(wa,wb),twd(wc,wd),twd(we,wf)}
end_define

begin_endif
endif|#
directive|endif
endif|VAX
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PORT
end_ifdef

begin_comment
comment|/*  * Memory sizes.  */
end_comment

begin_define
define|#
directive|define
name|MAXHEAPSIZE
value|x
end_define

begin_comment
comment|/* size of the heap in bytes */
end_comment

begin_define
define|#
directive|define
name|MAXSTRSPACE
value|x
end_define

begin_comment
comment|/* size of the string space in bytes */
end_comment

begin_define
define|#
directive|define
name|STACKSIZE
value|x
end_define

begin_comment
comment|/* size of coexpression stack in WORDSIZE 				    words */
end_comment

begin_define
define|#
directive|define
name|MAXSTACKS
value|x
end_define

begin_comment
comment|/* number of coexpression stacks */
end_comment

begin_define
define|#
directive|define
name|NUMBUF
value|x
end_define

begin_comment
comment|/* number of i/o buffers available */
end_comment

begin_define
define|#
directive|define
name|NBUCKETS
value|x
end_define

begin_comment
comment|/* number of hash buckets */
end_comment

begin_comment
comment|/*  * Implementation specific constants.  */
end_comment

begin_define
define|#
directive|define
name|INTSIZE
value|x
end_define

begin_comment
comment|/* bits per integer */
end_comment

begin_define
define|#
directive|define
name|LOGINTSIZE
value|x
end_define

begin_comment
comment|/* log of INTSIZE */
end_comment

begin_define
define|#
directive|define
name|MINSHORT
value|x
end_define

begin_comment
comment|/* smallest short integer */
end_comment

begin_define
define|#
directive|define
name|MAXSHORT
value|x
end_define

begin_comment
comment|/* largest short integer */
end_comment

begin_define
define|#
directive|define
name|MINLONG
value|x
end_define

begin_comment
comment|/* smallest long integer */
end_comment

begin_define
define|#
directive|define
name|MAXLONG
value|x
end_define

begin_comment
comment|/* largest long integer */
end_comment

begin_define
define|#
directive|define
name|LGHUGE
value|x
end_define

begin_comment
comment|/* maximum base-10 exp + 1 of float number */
end_comment

begin_define
define|#
directive|define
name|FRAMELIMIT
value|x
end_define

begin_comment
comment|/* maximum negative offset in proc frame (int) */
end_comment

begin_define
define|#
directive|define
name|WORDSIZE
value|sizeof(int *)
end_define

begin_comment
comment|/* size in bytes of a pointer */
end_comment

begin_define
define|#
directive|define
name|STKBASE
value|x
end_define

begin_comment
comment|/* highest possible address for sp */
end_comment

begin_define
define|#
directive|define
name|GRANSIZE
value|x
end_define

begin_comment
comment|/* storage allocation granule size */
end_comment

begin_comment
comment|/*  * Some macros to allow customization.  */
end_comment

begin_comment
comment|/*#define SetBound*/
end_comment

begin_comment
comment|/*#define ClearBound*/
end_comment

begin_comment
comment|/*#define DclSave*/
end_comment

begin_comment
comment|/*#define EntryPoint(name) (char *)name + x*/
end_comment

begin_comment
comment|/*#define Global(x)*/
end_comment

begin_comment
comment|/*#define DummyFcn(x)*/
end_comment

begin_comment
comment|/*#define DummyData(x)*/
end_comment

begin_comment
comment|/*#define DummyRef(x)*/
end_comment

begin_comment
comment|/*#define gfp x*/
end_comment

begin_comment
comment|/*#define efp x*/
end_comment

begin_comment
comment|/*#define ipc x*/
end_comment

begin_comment
comment|/*  * Cset initialization macros.  */
end_comment

begin_comment
comment|/*  For ints with 32 bits use these:          #define twd(w0, w1)     ((w0)&0xffff | (w1)<<16)     #define cset_display(w0,w1,w2,w3,w4,w5,w6,w7,w8,w9,wa,wb,wc,wd,we,wf) \         {twd(w0,w1),twd(w2,w3),twd(w4,w5),twd(w6,w7), \          twd(w8,w9),twd(wa,wb),twd(wc,wd),twd(we,wf)}   For ints with 16 bits use these:      #define cset_display(w0,w1,w2,w3,w4,w5,w6,w7,w8,w9,wa,wb,wc,wd,we,wf) \         {w0,w1,w2,w3,w4,w5,w6,w7,w8,w9,wa,wb,wc,wd,we,wf} */
end_comment

begin_endif
endif|#
directive|endif
endif|PORT
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PDP11
end_ifdef

begin_define
define|#
directive|define
name|MAXHEAPSIZE
value|10240
end_define

begin_comment
comment|/* size of the heap in bytes */
end_comment

begin_define
define|#
directive|define
name|MAXSTRSPACE
value|10240
end_define

begin_comment
comment|/* size of the string space in bytes */
end_comment

begin_define
define|#
directive|define
name|STACKSIZE
value|1000
end_define

begin_comment
comment|/* size a coexpression stack in WORDSIZE 				    words */
end_comment

begin_define
define|#
directive|define
name|MAXSTACKS
value|2
end_define

begin_comment
comment|/* number of coexpression stacks */
end_comment

begin_define
define|#
directive|define
name|NUMBUF
value|5
end_define

begin_comment
comment|/* number of i/o buffers available */
end_comment

begin_define
define|#
directive|define
name|NBUCKETS
value|13
end_define

begin_comment
comment|/* number of hash buckets */
end_comment

begin_define
define|#
directive|define
name|MAXLISTSIZE
value|4090
end_define

begin_comment
comment|/* Defined if lists are limited in size  				    due to addressing limitations of a 				    particular architecture.  Specified 				    value is the largest list element 				    block that can be made. */
end_comment

begin_comment
comment|/*  * Implementation specific constants.  */
end_comment

begin_define
define|#
directive|define
name|INTSIZE
value|16
end_define

begin_comment
comment|/* bits per integer */
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
name|LONGS
end_define

begin_comment
comment|/* longs are not same as ints */
end_comment

begin_define
define|#
directive|define
name|MINLONG
value|020000000000L
end_define

begin_comment
comment|/* smallest long integer */
end_comment

begin_define
define|#
directive|define
name|MAXLONG
value|017777777777L
end_define

begin_comment
comment|/* largest long integer */
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
name|LGHUGE
value|39
end_define

begin_comment
comment|/* maximum base-10 exp +1 of float number */
end_comment

begin_define
define|#
directive|define
name|FRAMELIMIT
value|5
end_define

begin_comment
comment|/* maxmum negative offset in proc frame (int) */
end_comment

begin_define
define|#
directive|define
name|WORDSIZE
value|sizeof(int *)
end_define

begin_comment
comment|/* size in bytes of a pointer */
end_comment

begin_define
define|#
directive|define
name|STKBASE
value|0177776
end_define

begin_comment
comment|/* highest possible address for sp */
end_comment

begin_define
define|#
directive|define
name|GRANSIZE
value|64
end_define

begin_comment
comment|/* storage allocation granule size */
end_comment

begin_comment
comment|/*  * Some macros to allow customization.  */
end_comment

begin_define
define|#
directive|define
name|SetBound
end_define

begin_define
define|#
directive|define
name|ClearBound
end_define

begin_define
define|#
directive|define
name|DclSave
end_define

begin_define
define|#
directive|define
name|EntryPoint
parameter_list|(
name|x
parameter_list|)
value|(char *)x + 4
end_define

begin_define
define|#
directive|define
name|Global
parameter_list|(
name|x
parameter_list|)
value|.globl x
end_define

begin_define
define|#
directive|define
name|DummyFcn
parameter_list|(
name|x
parameter_list|)
value|.globl x; x: 0
end_define

begin_define
define|#
directive|define
name|DummyData
parameter_list|(
name|x
parameter_list|)
value|.globl x; x: 0
end_define

begin_define
define|#
directive|define
name|DummyRef
parameter_list|(
name|x
parameter_list|)
value|.globl x; x
end_define

begin_comment
comment|/*  * Cset initialization macros.  */
end_comment

begin_define
define|#
directive|define
name|cset_display
parameter_list|(
name|w0
parameter_list|,
name|w1
parameter_list|,
name|w2
parameter_list|,
name|w3
parameter_list|,
name|w4
parameter_list|,
name|w5
parameter_list|,
name|w6
parameter_list|,
name|w7
parameter_list|,
name|w8
parameter_list|,
name|w9
parameter_list|,
name|wa
parameter_list|,
name|wb
parameter_list|,
name|wc
parameter_list|,
name|wd
parameter_list|,
name|we
parameter_list|,
name|wf
parameter_list|)
define|\
value|{w0,w1,w2,w3,w4,w5,w6,w7,w8,w9,wa,wb,wc,wd,we,wf}
end_define

begin_endif
endif|#
directive|endif
endif|PDP11
end_endif

begin_comment
comment|/*  * Constants that are not likely to vary between implementations.  */
end_comment

begin_define
define|#
directive|define
name|BITOFFMASK
value|(INTSIZE-1)
end_define

begin_define
define|#
directive|define
name|CSETSIZE
value|(256/INTSIZE)
end_define

begin_comment
comment|/* number of ints to hold 256 cset 				     bits.  Use (256/INTSIZE)+1 if 				     256 % INTSIZE != 0 */
end_comment

begin_define
define|#
directive|define
name|LISTBLKSIZE
value|8
end_define

begin_comment
comment|/* number of elements in an expansion 				 *  list element block  */
end_comment

begin_define
define|#
directive|define
name|MAXSTRING
value|257
end_define

begin_comment
comment|/* largest string in conversions */
end_comment

begin_define
define|#
directive|define
name|MAXREADSTRING
value|2049
end_define

begin_comment
comment|/* largest string to read() in one piece */
end_comment

begin_define
define|#
directive|define
name|RANDA
value|1103515245
end_define

begin_comment
comment|/* random seed multiplier */
end_comment

begin_define
define|#
directive|define
name|RANDC
value|453816694
end_define

begin_comment
comment|/* random seed additive constant */
end_comment

begin_define
define|#
directive|define
name|RSCALE
value|4.65661286e-10
end_define

begin_comment
comment|/* random scale factor = 1/(2^31-1)) */
end_comment

begin_comment
comment|/*  * Offset in word of cset bit.  */
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
comment|/*  * Address of word of cset bit.  */
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
comment|/*  * Set bit b in cset c.  */
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
comment|/*  * Test bit b in cset c.  */
end_comment

begin_define
define|#
directive|define
name|tstb
parameter_list|(
name|b
parameter_list|,
name|c
parameter_list|)
value|((*CSPTR(b,c)>> CSOFF(b))& 01)
end_define

begin_comment
comment|/*  * Runtime data structures.  */
end_comment

begin_union
union|union
name|numeric
block|{
comment|/* long integers or real numbers */
name|long
name|integer
decl_stmt|;
name|double
name|real
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|descrip
block|{
comment|/* descriptor */
name|int
name|type
decl_stmt|;
comment|/* type field */
union|union
block|{
name|int
name|integr
decl_stmt|;
comment|/* integer value */
name|char
modifier|*
name|cptr
decl_stmt|;
comment|/* pointer to character string */
name|union
name|block
modifier|*
name|bptr
decl_stmt|;
comment|/* pointer to a block */
name|struct
name|descrip
modifier|*
name|dptr
decl_stmt|;
comment|/* pointer to a descriptor */
block|}
name|value
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sdescrip
block|{
name|int
name|length
decl_stmt|;
comment|/* length of string */
name|char
modifier|*
name|string
decl_stmt|;
comment|/* pointer to string */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|b_int
block|{
comment|/* long integer block */
name|int
name|type
decl_stmt|;
comment|/*   T_LONGINT */
name|long
name|intval
decl_stmt|;
comment|/*   value */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|b_real
block|{
comment|/* real block */
name|int
name|type
decl_stmt|;
comment|/*   T_REAL */
name|double
name|realval
decl_stmt|;
comment|/*   value */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|b_cset
block|{
comment|/* cset block */
name|int
name|type
decl_stmt|;
comment|/*   T_CSET */
name|int
name|bits
index|[
name|CSETSIZE
index|]
decl_stmt|;
comment|/*   array of bits, one per ascii character */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|b_file
block|{
comment|/* file block */
name|int
name|type
decl_stmt|;
comment|/*   T_FILE */
name|FILE
modifier|*
name|fd
decl_stmt|;
comment|/*   Unix file descriptor */
name|int
name|status
decl_stmt|;
comment|/*   file status */
name|struct
name|descrip
name|fname
decl_stmt|;
comment|/*   file name (string qualifier) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|b_proc
block|{
comment|/* procedure block */
name|int
name|type
decl_stmt|;
comment|/*   T_PROC */
name|int
name|size
decl_stmt|;
comment|/*   size of block */
name|char
modifier|*
name|entryp
decl_stmt|;
comment|/*   entry point (code) */
name|int
name|nparam
decl_stmt|;
comment|/*   number of parameters */
name|int
name|ndynam
decl_stmt|;
comment|/*   number of dynamic locals */
name|int
name|nstatic
decl_stmt|;
comment|/*   number of static locals */
name|int
name|fstatic
decl_stmt|;
comment|/*   index (in global table) of first static */
name|struct
name|descrip
name|pname
decl_stmt|;
comment|/*   procedure name (string qualifier) */
name|struct
name|descrip
name|lnames
index|[
literal|1
index|]
decl_stmt|;
comment|/*   list of local names (qualifiers) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * b_iproc blocks are used to statically initialize information about  *  functions.  They are identical to b_proc blocks except for  *  the pname field which is a sdecrip (simple/string descriptor) instead  *  of a descrip.  This is done because unions can't be initialized.  */
end_comment

begin_struct
struct|struct
name|b_iproc
block|{
comment|/* procedure block */
name|int
name|ip_type
decl_stmt|;
comment|/*   T_PROC */
name|int
name|ip_size
decl_stmt|;
comment|/*   size  of block */
name|char
modifier|*
name|ip_entryp
decl_stmt|;
comment|/*   entry point (code) */
name|int
name|ip_nparam
decl_stmt|;
comment|/*   number of parameters */
name|int
name|ip_ndynam
decl_stmt|;
comment|/*   number of dynamic locals */
name|int
name|ip_nstatic
decl_stmt|;
comment|/*   number of static locals */
name|int
name|ip_fstatic
decl_stmt|;
comment|/*   index (in global table) of first static */
name|struct
name|sdescrip
name|ip_pname
decl_stmt|;
comment|/*   procedure name (string qualifier) */
name|struct
name|descrip
name|ip_lnames
index|[
literal|1
index|]
decl_stmt|;
comment|/*   list of local names (qualifiers) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|b_list
block|{
comment|/* list header block */
name|int
name|type
decl_stmt|;
comment|/*   T_LIST */
name|int
name|cursize
decl_stmt|;
comment|/*   current list size */
name|struct
name|descrip
name|listhead
decl_stmt|;
comment|/*   pointer to first list element block */
name|struct
name|descrip
name|listtail
decl_stmt|;
comment|/*   pointer to last list element block */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|b_lelem
block|{
comment|/* list element block */
name|int
name|type
decl_stmt|;
comment|/*   T_LELEM */
name|int
name|size
decl_stmt|;
comment|/*   size of block */
name|int
name|nelem
decl_stmt|;
comment|/*   total number of elements */
name|int
name|first
decl_stmt|;
comment|/*   index of first element */
name|int
name|nused
decl_stmt|;
comment|/*   number of used elements */
name|struct
name|descrip
name|listprev
decl_stmt|;
comment|/*   pointer to previous list element block */
name|struct
name|descrip
name|listnext
decl_stmt|;
comment|/*   pointer to next list element block */
name|struct
name|descrip
name|lslots
index|[
literal|1
index|]
decl_stmt|;
comment|/*   array of elements */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|b_table
block|{
comment|/* table header block */
name|int
name|type
decl_stmt|;
comment|/*   T_TABLE */
name|int
name|cursize
decl_stmt|;
comment|/*   current table size */
name|struct
name|descrip
name|defvalue
decl_stmt|;
comment|/*   default table element value */
name|struct
name|descrip
name|buckets
index|[
name|NBUCKETS
index|]
decl_stmt|;
comment|/* hash buckets */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|b_telem
block|{
comment|/* table element block */
name|int
name|type
decl_stmt|;
comment|/*   T_TELEM */
name|int
name|hashnum
decl_stmt|;
comment|/*   for ordering chain */
name|struct
name|descrip
name|blink
decl_stmt|;
comment|/*   hash bucket link */
name|struct
name|descrip
name|tref
decl_stmt|;
comment|/*   reference field */
name|struct
name|descrip
name|tval
decl_stmt|;
comment|/*   value field */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|SETS
end_ifdef

begin_struct
struct|struct
name|b_set
block|{
comment|/* set header block */
name|int
name|type
decl_stmt|;
comment|/*   T_SET */
name|int
name|setsize
decl_stmt|;
comment|/*   cardinality of the set */
name|struct
name|descrip
name|sbucks
index|[
name|NBUCKETS
index|]
decl_stmt|;
comment|/* hash buckets */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|b_selem
block|{
comment|/* set element block */
name|int
name|type
decl_stmt|;
comment|/*   T_SELEM */
name|int
name|hnum
decl_stmt|;
comment|/*   hash number */
name|struct
name|descrip
name|setmem
decl_stmt|;
comment|/*   the element */
name|struct
name|descrip
name|sblink
decl_stmt|;
comment|/*   hash chain link */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
endif|SETS
end_endif

begin_struct
struct|struct
name|b_record
block|{
comment|/* record block */
name|int
name|type
decl_stmt|;
comment|/*   T_RECORD */
name|int
name|size
decl_stmt|;
comment|/*   size of block */
name|struct
name|b_proc
modifier|*
name|recptr
decl_stmt|;
comment|/*   pointer to record constructor proc */
name|struct
name|descrip
name|fields
index|[
literal|1
index|]
decl_stmt|;
comment|/*   fields */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|b_tvsubs
block|{
comment|/* substring trapped variable block */
name|int
name|type
decl_stmt|;
comment|/*   T_TVSUBS */
name|int
name|sslen
decl_stmt|;
comment|/*   length of substring */
name|int
name|sspos
decl_stmt|;
comment|/*   position of substring */
name|struct
name|descrip
name|ssvar
decl_stmt|;
comment|/*   variable that substring is from */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|b_tvtbl
block|{
comment|/* table element trapped variable block */
name|int
name|type
decl_stmt|;
comment|/*   T_TVTBL */
name|int
name|hashnum
decl_stmt|;
comment|/* for ordering */
name|struct
name|descrip
name|tvtable
decl_stmt|;
comment|/* pointer to table header block */
name|struct
name|descrip
name|tvtref
decl_stmt|;
comment|/*   reference field */
name|struct
name|descrip
name|tvtval
decl_stmt|;
comment|/* used when block is converted to telem */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|b_estack
block|{
comment|/* co-expression stack block */
name|int
name|type
decl_stmt|;
comment|/*   T_ESTACK */
name|struct
name|descrip
name|activator
decl_stmt|;
comment|/*   most recent activator */
name|int
modifier|*
name|sbase
decl_stmt|;
comment|/*   stack base */
name|int
modifier|*
name|sp
decl_stmt|;
comment|/*   stack pointer */
name|int
modifier|*
name|ap
decl_stmt|;
comment|/*   address pointer, only on Vax */
name|int
modifier|*
name|boundary
decl_stmt|;
comment|/*   Icon/C boundary */
name|int
name|nresults
decl_stmt|;
comment|/*   number of results produced */
name|struct
name|descrip
name|freshblk
decl_stmt|;
comment|/*   refresh block pointer */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|b_eblock
block|{
comment|/* co-expression heap block */
name|int
name|type
decl_stmt|;
comment|/*   T_EBLOCK */
name|int
name|size
decl_stmt|;
comment|/*   size of block */
name|int
modifier|*
name|ep
decl_stmt|;
comment|/*   entry point */
name|int
name|numargs
decl_stmt|;
comment|/*   number of arguments */
name|int
name|numlocals
decl_stmt|;
comment|/*   number of locals */
name|struct
name|descrip
name|elems
index|[
literal|1
index|]
decl_stmt|;
comment|/*   arguments and locals, including arg0 */
block|}
struct|;
end_struct

begin_union
union|union
name|block
block|{
comment|/* general heap block */
name|struct
name|b_int
name|longint
decl_stmt|;
name|struct
name|b_real
name|realblk
decl_stmt|;
name|struct
name|b_cset
name|cset
decl_stmt|;
name|struct
name|b_file
name|file
decl_stmt|;
name|struct
name|b_proc
name|proc
decl_stmt|;
name|struct
name|b_list
name|list
decl_stmt|;
name|struct
name|b_lelem
name|lelem
decl_stmt|;
name|struct
name|b_table
name|table
decl_stmt|;
name|struct
name|b_telem
name|telem
decl_stmt|;
ifdef|#
directive|ifdef
name|SETS
name|struct
name|b_set
name|set
decl_stmt|;
name|struct
name|b_selem
name|selem
decl_stmt|;
endif|#
directive|endif
endif|SETS
name|struct
name|b_record
name|record
decl_stmt|;
name|struct
name|b_tvsubs
name|tvsubs
decl_stmt|;
name|struct
name|b_tvtbl
name|tvtbl
decl_stmt|;
name|struct
name|b_estack
name|estack
decl_stmt|;
name|struct
name|b_eblock
name|eblock
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * External declarations.  */
end_comment

begin_extern
extern|extern char (*bufs
end_extern

begin_expr_stmt
unit|)
index|[
name|BUFSIZ
index|]
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* i/o buffers */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
modifier|*
name|bufused
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* i/o buffer use markers */
end_comment

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|stacks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start of expression stack space */
end_comment

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|estacks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of expression stack space */
end_comment

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|esfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* expression stack space free list header */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ssize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of string space (bytes) */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strings
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start of string space */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|estrings
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of string space */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string space free pointer */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|hpsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of heap (words) */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|hpbase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* base of heap */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|maxheap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum address in heap */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|hpfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* first free location in heap */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|bsizes
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sizes of heap blocks */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|firstd
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* offset (words) of first descrip. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|blkname
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print names for block types. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|numbufs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of buffers */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|stksize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of coexpression stacks in words */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|b_cset
name|k_ascii
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* value of&ascii */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|b_cset
name|k_cset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* value of&cset */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|b_file
name|k_errout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* value of&errout */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|b_file
name|k_input
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* value of&input */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|b_cset
name|k_lcase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* value of&lcase */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|k_level
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* value of&level */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|k_pos
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* value of&pos */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|descrip
name|k_main
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* value of&main */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|b_file
name|k_output
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* value of&output */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|k_random
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* value of&random */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|descrip
name|k_subject
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* value of&subject */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|k_trace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* value of&trace */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|b_cset
name|k_ucase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* value of&ucase */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|starttime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start time in milliseconds */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|descrip
name|nulldesc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* universal&null */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|descrip
name|zerodesc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* universal 0 */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|descrip
name|onedesc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* universal 1 */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|descrip
name|nullstr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* universal null string */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|descrip
name|blank
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* universal blank */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|descrip
name|letr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* universal letter 'r' */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|descrip
name|maps2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* save space for 2nd arg to map() */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|descrip
name|maps3
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* save space for 3rd arg to map() */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|descrip
name|current
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current expression stack pointer */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|descrip
name|input
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* universal input file */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|descrip
name|errout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* universal error file */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|descrip
name|lcase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* universal lower case string */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|descrip
name|ucase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* universal upper case string */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|line
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current source program line number */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current source program file name */
end_comment

begin_comment
comment|/*  * Descriptor flags.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VAX
end_ifdef

begin_define
define|#
directive|define
name|F_NQUAL
value|0x80000000
end_define

begin_comment
comment|/* set if NOT string qualifier */
end_comment

begin_define
define|#
directive|define
name|F_VAR
value|0x40000000
end_define

begin_comment
comment|/* set if variable */
end_comment

begin_define
define|#
directive|define
name|F_TVAR
value|0x20000000
end_define

begin_comment
comment|/* set if trapped variable */
end_comment

begin_define
define|#
directive|define
name|F_PTR
value|0x10000000
end_define

begin_comment
comment|/* set if value field is pointer */
end_comment

begin_endif
endif|#
directive|endif
endif|VAX
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PORT
end_ifdef

begin_define
define|#
directive|define
name|F_NQUAL
value|x
end_define

begin_comment
comment|/* set if NOT string qualifier */
end_comment

begin_define
define|#
directive|define
name|F_VAR
value|x
end_define

begin_comment
comment|/* set if variable */
end_comment

begin_define
define|#
directive|define
name|F_TVAR
value|x
end_define

begin_comment
comment|/* set if trapped variable */
end_comment

begin_define
define|#
directive|define
name|F_PTR
value|x
end_define

begin_comment
comment|/* set if value field is pointer */
end_comment

begin_endif
endif|#
directive|endif
endif|PORT
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PDP11
end_ifdef

begin_define
define|#
directive|define
name|F_NQUAL
value|0100000
end_define

begin_comment
comment|/* set if NOT string qualifier */
end_comment

begin_define
define|#
directive|define
name|F_VAR
value|0040000
end_define

begin_comment
comment|/* set if variable */
end_comment

begin_define
define|#
directive|define
name|F_TVAR
value|0020000
end_define

begin_comment
comment|/* set if trapped variable */
end_comment

begin_define
define|#
directive|define
name|F_PTR
value|0010000
end_define

begin_comment
comment|/* set if value field is pointer */
end_comment

begin_endif
endif|#
directive|endif
endif|PDP11
end_endif

begin_define
define|#
directive|define
name|TYPEMASK
value|63
end_define

begin_comment
comment|/* type mask */
end_comment

begin_define
define|#
directive|define
name|OFFSETMASK
value|(~(F_NQUAL|F_VAR|F_TVAR))
end_define

begin_comment
comment|/* offset mask for variables */
end_comment

begin_comment
comment|/*  * Type codes (descriptors and blocks).  */
end_comment

begin_define
define|#
directive|define
name|T_INTEGER
value|1
end_define

begin_comment
comment|/* short integer */
end_comment

begin_comment
comment|/*  * For 32 bit machines, e.g. the Vax, we make LONGINT's and INTEGER's  *  the same.  It would be better to have a generic integer type, and  *  also have LONGINT's and SHORTINT's, but at the current time,  *  LONGINT is used both to refer to integers not representable by  *  a short, and as a generic integer type.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LONGS
end_ifdef

begin_define
define|#
directive|define
name|T_LONGINT
value|2
end_define

begin_comment
comment|/* long integer */
end_comment

begin_else
else|#
directive|else
else|LONGS
end_else

begin_define
define|#
directive|define
name|T_LONGINT
value|1
end_define

begin_comment
comment|/* long integer */
end_comment

begin_endif
endif|#
directive|endif
endif|LONGS
end_endif

begin_define
define|#
directive|define
name|T_REAL
value|3
end_define

begin_comment
comment|/* real number */
end_comment

begin_define
define|#
directive|define
name|T_CSET
value|4
end_define

begin_comment
comment|/* cset */
end_comment

begin_define
define|#
directive|define
name|T_FILE
value|5
end_define

begin_comment
comment|/* file block */
end_comment

begin_define
define|#
directive|define
name|T_PROC
value|6
end_define

begin_comment
comment|/* procedure block */
end_comment

begin_define
define|#
directive|define
name|T_LIST
value|7
end_define

begin_comment
comment|/* list header block */
end_comment

begin_define
define|#
directive|define
name|T_TABLE
value|8
end_define

begin_comment
comment|/* table header */
end_comment

begin_define
define|#
directive|define
name|T_RECORD
value|9
end_define

begin_comment
comment|/* record block */
end_comment

begin_define
define|#
directive|define
name|T_TELEM
value|10
end_define

begin_comment
comment|/* table element block */
end_comment

begin_define
define|#
directive|define
name|T_LELEM
value|11
end_define

begin_comment
comment|/* list element block */
end_comment

begin_define
define|#
directive|define
name|T_TVSUBS
value|12
end_define

begin_comment
comment|/* substring trapped variable */
end_comment

begin_define
define|#
directive|define
name|JUNK_13
value|13
end_define

begin_comment
comment|/* (no longer used) */
end_comment

begin_define
define|#
directive|define
name|T_TVTBL
value|14
end_define

begin_comment
comment|/* table element trapped variable block */
end_comment

begin_define
define|#
directive|define
name|T_TVPOS
value|15
end_define

begin_comment
comment|/*&pos trapped variable */
end_comment

begin_define
define|#
directive|define
name|T_TVRAND
value|16
end_define

begin_comment
comment|/*&random trapped variable */
end_comment

begin_define
define|#
directive|define
name|T_TVTRACE
value|17
end_define

begin_comment
comment|/*&trace trapped variable */
end_comment

begin_define
define|#
directive|define
name|T_ESTACK
value|18
end_define

begin_comment
comment|/* expression stack block */
end_comment

begin_define
define|#
directive|define
name|T_EBLOCK
value|19
end_define

begin_comment
comment|/* expression heap block */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SETS
end_ifdef

begin_define
define|#
directive|define
name|T_SET
value|20
end_define

begin_comment
comment|/* set header block */
end_comment

begin_define
define|#
directive|define
name|T_SELEM
value|21
end_define

begin_comment
comment|/* set element block */
end_comment

begin_define
define|#
directive|define
name|MAXTYPE
value|21
end_define

begin_comment
comment|/* maximum type number */
end_comment

begin_else
else|#
directive|else
else|SETS
end_else

begin_define
define|#
directive|define
name|MAXTYPE
value|19
end_define

begin_comment
comment|/* maximum type number w/o sets */
end_comment

begin_endif
endif|#
directive|endif
endif|SETS
end_endif

begin_comment
comment|/*  * Descriptor types and flags.  */
end_comment

begin_define
define|#
directive|define
name|D_VAR
value|(F_VAR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_TVAR
value|(F_VAR | F_TVAR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_NULL
value|0
end_define

begin_define
define|#
directive|define
name|D_INTEGER
value|(T_INTEGER | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_LONGINT
value|(T_LONGINT | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_REAL
value|(T_REAL | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_CSET
value|(T_CSET | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_FILE
value|(T_FILE | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_PROC
value|(T_PROC | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_LIST
value|(T_LIST | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_TABLE
value|(T_TABLE | F_PTR | F_NQUAL)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SETS
end_ifdef

begin_define
define|#
directive|define
name|D_SET
value|(T_SET | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_SELEM
value|(T_SELEM | F_PTR | F_NQUAL)
end_define

begin_endif
endif|#
directive|endif
endif|SETS
end_endif

begin_define
define|#
directive|define
name|D_RECORD
value|(T_RECORD | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_TELEM
value|(T_TELEM | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_LELEM
value|(T_LELEM | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_TVSUBS
value|(T_TVSUBS | D_TVAR)
end_define

begin_define
define|#
directive|define
name|D_TVTBL
value|(T_TVTBL | D_TVAR)
end_define

begin_define
define|#
directive|define
name|D_TVPOS
value|(T_TVPOS | D_TVAR)
end_define

begin_define
define|#
directive|define
name|D_TVRAND
value|(T_TVRAND | D_TVAR)
end_define

begin_define
define|#
directive|define
name|D_TVTRACE
value|(T_TVTRACE | D_TVAR)
end_define

begin_define
define|#
directive|define
name|D_ESTACK
value|(T_ESTACK | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_EBLOCK
value|(T_EBLOCK | F_PTR | F_NQUAL)
end_define

begin_comment
comment|/*  * File status flags in status field of file blocks.  */
end_comment

begin_define
define|#
directive|define
name|FS_READ
value|01
end_define

begin_comment
comment|/* read access */
end_comment

begin_define
define|#
directive|define
name|FS_WRITE
value|02
end_define

begin_comment
comment|/* write access */
end_comment

begin_define
define|#
directive|define
name|FS_CREATE
value|04
end_define

begin_comment
comment|/* file created on open */
end_comment

begin_define
define|#
directive|define
name|FS_APPEND
value|010
end_define

begin_comment
comment|/* append mode */
end_comment

begin_define
define|#
directive|define
name|FS_PIPE
value|020
end_define

begin_comment
comment|/* reading/writing on a pipe */
end_comment

begin_comment
comment|/*  * Macros for testing descriptors.  d must be of type struct descrip.  */
end_comment

begin_define
define|#
directive|define
name|NULLDESC
parameter_list|(
name|d
parameter_list|)
value|(((d).type|(d).value.integr)==0)
end_define

begin_comment
comment|/* check for&null */
end_comment

begin_comment
comment|/*  * String qualifiers.  */
end_comment

begin_define
define|#
directive|define
name|QUAL
parameter_list|(
name|d
parameter_list|)
value|(!((d).type& F_NQUAL))
end_define

begin_comment
comment|/* check for qualifier */
end_comment

begin_define
define|#
directive|define
name|STRLEN
parameter_list|(
name|d
parameter_list|)
value|((d).type)
end_define

begin_comment
comment|/* get length of string */
end_comment

begin_define
define|#
directive|define
name|STRLOC
parameter_list|(
name|d
parameter_list|)
value|((d).value.cptr)
end_define

begin_comment
comment|/* get address of string */
end_comment

begin_comment
comment|/*  * Values, d must not be qualifier or variable.  */
end_comment

begin_define
define|#
directive|define
name|TYPE
parameter_list|(
name|d
parameter_list|)
value|((d).type& TYPEMASK)
end_define

begin_comment
comment|/* get type code */
end_comment

begin_define
define|#
directive|define
name|POINTER
parameter_list|(
name|d
parameter_list|)
value|((d).type& F_PTR)
end_define

begin_comment
comment|/* check for pointer */
end_comment

begin_define
define|#
directive|define
name|INTVAL
parameter_list|(
name|d
parameter_list|)
value|((d).value.integr)
end_define

begin_comment
comment|/* get short integer value */
end_comment

begin_define
define|#
directive|define
name|BLKLOC
parameter_list|(
name|d
parameter_list|)
value|((d).value.bptr)
end_define

begin_comment
comment|/* get pointer to block */
end_comment

begin_comment
comment|/*  * Variables, d must not be qualifier.  */
end_comment

begin_define
define|#
directive|define
name|VAR
parameter_list|(
name|d
parameter_list|)
value|((d).type& F_VAR)
end_define

begin_comment
comment|/* check for variable */
end_comment

begin_define
define|#
directive|define
name|TVAR
parameter_list|(
name|d
parameter_list|)
value|((d).type& F_TVAR)
end_define

begin_comment
comment|/* check for trapped var */
end_comment

begin_define
define|#
directive|define
name|OFFSET
parameter_list|(
name|d
parameter_list|)
value|((d).type& OFFSETMASK)
end_define

begin_comment
comment|/* get offset field */
end_comment

begin_define
define|#
directive|define
name|VARLOC
parameter_list|(
name|d
parameter_list|)
value|((d).value.dptr)
end_define

begin_comment
comment|/* get pointer to descriptor */
end_comment

begin_define
define|#
directive|define
name|TVARLOC
parameter_list|(
name|d
parameter_list|)
value|((d).value.bptr)
end_define

begin_comment
comment|/* get ptr to t.v. block */
end_comment

begin_comment
comment|/*  * Macros to define procedure blocks.  */
end_comment

begin_define
define|#
directive|define
name|IDENT
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|CAT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|IDENT(x)y
end_define

begin_define
define|#
directive|define
name|Procblock
parameter_list|(
name|f
parameter_list|,
name|nargs
parameter_list|)
define|\
value|struct b_iproc CAT(B,f) = {\ 	T_PROC,\ 	vsizeof(struct b_proc),\ 	EntryPoint(CAT(X,f)),\ 	nargs,\ 	-1,\ 	0, 0,\ 	{sizeof("f")-1,"f"}};
end_define

begin_define
define|#
directive|define
name|Opblock
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|Opblock1(a,b,c,0)
end_define

begin_define
define|#
directive|define
name|Opblockx
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|Opblock1(a,b,c,-d)
end_define

begin_define
define|#
directive|define
name|Opblock1
parameter_list|(
name|f
parameter_list|,
name|nargs
parameter_list|,
name|sname
parameter_list|,
name|realargs
parameter_list|)
define|\
value|struct b_iproc CAT(B,f) = {\ 	T_PROC,\ 	vsizeof(struct b_proc),\ 	EntryPoint(f),\ 	nargs,\ 	-1,\ 	realargs,\ 	0,\ 	{sizeof(sname)-1,sname}};
end_define

begin_comment
comment|/*  * Macros to access Icon arguments from C-language library procedures.  *  Library procedures must have exactly one argument, named nargs.  */
end_comment

begin_comment
comment|/*  * n-th argument.  */
end_comment

begin_define
define|#
directive|define
name|ARG
parameter_list|(
name|n
parameter_list|)
value|(*((struct descrip *)(&nargs+1)+(nargs-n)))
end_define

begin_comment
comment|/*  * Type field of n-th argument.  */
end_comment

begin_define
define|#
directive|define
name|ARGTYPE
parameter_list|(
name|n
parameter_list|)
value|(*(&nargs+1+2*(nargs-n)))
end_define

begin_comment
comment|/*  * Value field of n-th argument.  */
end_comment

begin_define
define|#
directive|define
name|ARGVAL
parameter_list|(
name|n
parameter_list|)
value|(*(&nargs+2+2*(nargs-n)))
end_define

begin_comment
comment|/*  * Minimum of x and y.  */
end_comment

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)<(y)?(x):(y))
end_define

begin_comment
comment|/*  * Maximum of x and y.  */
end_comment

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)>(y)?(x):(y))
end_define

begin_comment
comment|/*  * Derefence d.  */
end_comment

begin_define
define|#
directive|define
name|DeRef
parameter_list|(
name|d
parameter_list|)
value|if(!QUAL(d)&&VAR(d))deref(&d);
end_define

begin_comment
comment|/*  *  vsizeof is for use with variable-sized (i.e., indefinite)  *  structures containing an array declared of size 1  *  to avoid compiler warnings associated with 0-sized arrays.  */
end_comment

begin_define
define|#
directive|define
name|vsizeof
parameter_list|(
name|s
parameter_list|)
value|(sizeof(s) - sizeof(struct descrip))
end_define

end_unit

