begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sccs id  @(#)global.h	35.3  7/2/81  */
end_comment

begin_comment
comment|/**********************************************************************/
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*   file: global.h						      */
end_comment

begin_comment
comment|/*   contents:							      */
end_comment

begin_comment
comment|/* GLOBAL STUFF *******************************************************/
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<pagsiz.h>
end_include

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|UNIXTS
end_ifdef

begin_include
include|#
directive|include
file|"tsfix.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AD
value|0
end_define

begin_define
define|#
directive|define
name|peekc
parameter_list|(
name|p
parameter_list|)
value|(p->_cnt>0? *(p)->_ptr&0377:_filbuf(p)==-1?-1:((p)->_cnt++,*--(p)->_ptr&0377))
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|EVER
value|;;
end_define

begin_define
define|#
directive|define
name|CNIL
value|((lispval) -4)
end_define

begin_define
define|#
directive|define
name|nil
value|((lispval) 0)
end_define

begin_define
define|#
directive|define
name|eofa
value|((lispval) 20)
end_define

begin_define
define|#
directive|define
name|NOTNIL
parameter_list|(
name|a
parameter_list|)
value|((int)a)
end_define

begin_define
define|#
directive|define
name|ISNIL
parameter_list|(
name|a
parameter_list|)
value|(!(int)a)
end_define

begin_define
define|#
directive|define
name|STRBLEN
value|512
end_define

begin_define
define|#
directive|define
name|NULL_CHAR
value|0
end_define

begin_define
define|#
directive|define
name|LF
value|'\n'
end_define

begin_define
define|#
directive|define
name|WILDCHR
value|'\0177'
end_define

begin_comment
comment|/* type flags and the macros to get them ********************************/
end_comment

begin_define
define|#
directive|define
name|UNBO
value|-1
end_define

begin_define
define|#
directive|define
name|STRNG
value|0
end_define

begin_define
define|#
directive|define
name|ATOM
value|1
end_define

begin_define
define|#
directive|define
name|INT
value|2
end_define

begin_define
define|#
directive|define
name|DTPR
value|3
end_define

begin_define
define|#
directive|define
name|DOUB
value|4
end_define

begin_define
define|#
directive|define
name|BCD
value|5
end_define

begin_define
define|#
directive|define
name|PORT
value|6
end_define

begin_define
define|#
directive|define
name|ARRAY
value|7
end_define

begin_define
define|#
directive|define
name|SDOT
value|9
end_define

begin_define
define|#
directive|define
name|VALUE
value|10
end_define

begin_define
define|#
directive|define
name|HUNK2
value|11
end_define

begin_comment
comment|/* The hunks */
end_comment

begin_define
define|#
directive|define
name|HUNK4
value|12
end_define

begin_define
define|#
directive|define
name|HUNK8
value|13
end_define

begin_define
define|#
directive|define
name|HUNK16
value|14
end_define

begin_define
define|#
directive|define
name|HUNK32
value|15
end_define

begin_define
define|#
directive|define
name|HUNK64
value|16
end_define

begin_define
define|#
directive|define
name|HUNK128
value|17
end_define

begin_comment
comment|/* the numbers per page of the different data objects *******************/
end_comment

begin_define
define|#
directive|define
name|NUMSPACES
value|16
end_define

begin_define
define|#
directive|define
name|ATOMSPP
value|25
end_define

begin_define
define|#
directive|define
name|STRSPP
value|NBPG
end_define

begin_define
define|#
directive|define
name|INTSPP
value|128
end_define

begin_define
define|#
directive|define
name|DTPRSPP
value|64
end_define

begin_define
define|#
directive|define
name|DOUBSPP
value|64
end_define

begin_define
define|#
directive|define
name|ARRAYSPP
value|25
end_define

begin_define
define|#
directive|define
name|SDOTSPP
value|64
end_define

begin_define
define|#
directive|define
name|VALSPP
value|128
end_define

begin_define
define|#
directive|define
name|BCDSPP
value|64
end_define

begin_define
define|#
directive|define
name|HUNK2SPP
value|64
end_define

begin_comment
comment|/* hunk page sizes */
end_comment

begin_define
define|#
directive|define
name|HUNK4SPP
value|32
end_define

begin_define
define|#
directive|define
name|HUNK8SPP
value|16
end_define

begin_define
define|#
directive|define
name|HUNK16SPP
value|8
end_define

begin_define
define|#
directive|define
name|HUNK32SPP
value|4
end_define

begin_define
define|#
directive|define
name|HUNK64SPP
value|2
end_define

begin_define
define|#
directive|define
name|HUNK128SPP
value|1
end_define

begin_decl_stmt
specifier|extern
name|char
name|typetable
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  the table with types for each page  */
end_comment

begin_define
define|#
directive|define
name|TYPL
parameter_list|(
name|a1
parameter_list|)
value|((typetable+1)[(int)(a1)>> 9])
end_define

begin_define
define|#
directive|define
name|SETTYPE
parameter_list|(
name|a1
parameter_list|,
name|b
parameter_list|)
value|{if((itemp = ((int)a1)>> 9)>= fakettsize) \ 			 { if(fakettsize>= TTSIZE) \ 			   {\ 			      printf(" all space exausted, goodbye\n");\ 			      exit(1);\ 			   }\ 			   fakettsize++;  badmem();\ 			 }\ 			(typetable + 1)[itemp] = (b); }
end_define

begin_define
define|#
directive|define
name|TYPE
parameter_list|(
name|a1
parameter_list|)
value|((typetable+1)[(int)(a1)>> 9])
end_define

begin_define
define|#
directive|define
name|HUNKP
parameter_list|(
name|a1
parameter_list|)
value|((TYPE(a1)+5)& 16)
end_define

begin_define
define|#
directive|define
name|HUNKSIZE
parameter_list|(
name|a1
parameter_list|)
value|((TYPE(a1)+5)& 15)
end_define

begin_define
define|#
directive|define
name|VALID
parameter_list|(
name|a
parameter_list|)
value|(a>= CNIL&& a< datalim)
end_define

begin_comment
comment|/*   * macros for saving state and restoring state  *  * Savestack and Restorestack are required at the beginning and end of  * functions which modify the stack pointers np and lbot.  * The Savestack(n) should appear at the end of the variable declarations  * The n refers to the number of register variables declared in this routine.  * The information is required for the Vax version only.  */
end_comment

begin_if
if|#
directive|if
name|vax
end_if

begin_define
define|#
directive|define
name|Savestack
parameter_list|(
name|n
parameter_list|)
value|snpand(n)
end_define

begin_define
define|#
directive|define
name|Restorestack
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|vax
end_if

begin_define
define|#
directive|define
name|Popframe
parameter_list|()
value|(errp->olderrp)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* some types ***********************************************************/
end_comment

begin_define
define|#
directive|define
name|lispint
value|long
end_define

begin_define
define|#
directive|define
name|MAX10LNG
value|200000000
end_define

begin_comment
comment|/* max long divided by 10	*/
end_comment

begin_typedef
typedef|typedef
name|union
name|lispobj
modifier|*
name|lispval
typedef|;
end_typedef

begin_struct
struct|struct
name|dtpr
block|{
name|lispval
name|cdr
decl_stmt|,
name|car
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sdot
block|{
name|int
name|I
decl_stmt|;
name|lispval
name|CDR
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|atom
block|{
name|lispval
name|clb
decl_stmt|;
comment|/* current level binding*/
name|lispval
name|plist
decl_stmt|;
comment|/* pointer to prop list	*/
ifndef|#
directive|ifndef
name|WILD
name|lispval
name|fnbnd
decl_stmt|;
comment|/* function binding	*/
endif|#
directive|endif
name|struct
name|atom
modifier|*
name|hshlnk
decl_stmt|;
comment|/* hash link to next	*/
name|char
modifier|*
name|pname
decl_stmt|;
comment|/* print name	*/
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|WILD
end_ifdef

begin_define
define|#
directive|define
name|fnbnd
value|clb
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|array
block|{
name|lispval
name|accfun
decl_stmt|,
comment|/*  access function--may be anything  */
name|aux
decl_stmt|;
comment|/*  slot for dimensions or auxilliary data  */
name|char
modifier|*
name|data
decl_stmt|;
comment|/*  pointer to first byte of array    */
name|lispval
name|length
decl_stmt|,
name|delta
decl_stmt|;
comment|/* length in items and length of one item */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bfun
block|{
name|lispval
function_decl|(
modifier|*
name|entry
function_decl|)
parameter_list|()
function_decl|;
comment|/*  entry point to routine  */
name|lispval
name|discipline
decl_stmt|,
comment|/*  argument-passing discipline  */
name|language
decl_stmt|,
comment|/*  language coded in	*/
name|params
decl_stmt|,
comment|/*  parameter list if relevant  */
name|loctab
decl_stmt|;
comment|/*  local table  */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Hunk
block|{
name|lispval
name|hunk
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|lispobj
block|{
name|struct
name|atom
name|a
decl_stmt|;
name|FILE
modifier|*
name|p
decl_stmt|;
name|struct
name|dtpr
name|d
decl_stmt|;
name|long
name|int
name|i
decl_stmt|;
name|long
name|int
modifier|*
name|j
decl_stmt|;
name|double
name|r
decl_stmt|;
name|lispval
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|()
function_decl|;
name|struct
name|array
name|ar
decl_stmt|;
name|struct
name|sdot
name|s
decl_stmt|;
name|char
name|c
decl_stmt|;
name|lispval
name|l
decl_stmt|;
name|struct
name|bfun
name|bcd
decl_stmt|;
name|struct
name|Hunk
name|h
decl_stmt|;
block|}
union|;
end_union

begin_include
include|#
directive|include
file|"sigtab.h"
end_include

begin_comment
comment|/* table of all pointers to lisp data */
end_comment

begin_comment
comment|/* Port definitions *****************************************************/
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|piport
decl_stmt|,
comment|/* standard input port		*/
modifier|*
name|poport
decl_stmt|,
comment|/* standard output port		*/
modifier|*
name|errport
decl_stmt|,
comment|/* port for error messages	*/
modifier|*
name|rdrport
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* temporary port for readr	*/
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|xports
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* page of file *'s for lisp	*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lineleng
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line length desired		*/
end_comment

begin_decl_stmt
specifier|extern
name|char
name|rbktf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* logical flag: ] mode		*/
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
modifier|*
name|ctable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Character table in current use */
end_comment

begin_define
define|#
directive|define
name|Xdqc
value|ctable[131]
end_define

begin_define
define|#
directive|define
name|Xesc
value|ctable[130]
end_define

begin_define
define|#
directive|define
name|Xsdc
value|ctable[129]
end_define

begin_comment
comment|/* name stack ***********************************************************/
end_comment

begin_define
define|#
directive|define
name|NAMESIZE
value|3072
end_define

begin_comment
comment|/* the name stack limit is raised by NAMINC every namestack overflow to allow    a user function to handle the error */
end_comment

begin_define
define|#
directive|define
name|NAMINC
value|25
end_define

begin_struct
specifier|extern
struct|struct
name|nament
block|{
name|lispval
name|val
decl_stmt|,
name|atm
decl_stmt|;
block|}
modifier|*
name|bnp
struct|,
comment|/* first free bind entry*/
modifier|*
name|bnplim
struct|;
end_struct

begin_comment
comment|/* limit of bindstack   */
end_comment

begin_struct
struct|struct
name|argent
block|{
name|lispval
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|argent
modifier|*
name|lbot
decl_stmt|,
modifier|*
name|np
decl_stmt|,
modifier|*
name|namptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|nament
modifier|*
name|bnp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* first free bind entry*/
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|argent
modifier|*
name|nplim
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* don't have this = np	*/
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|argent
modifier|*
name|orgnp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used by top level to reset to start  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|nament
modifier|*
name|orgbnp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used by top level to reset to start  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|nament
modifier|*
name|bnplim
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* limit of bindstack   */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|argent
modifier|*
name|np
decl_stmt|,
comment|/* top entry on stack	*/
modifier|*
name|lbot
decl_stmt|,
comment|/* bottom of cur frame	*/
modifier|*
name|namptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* temporary pointer	*/
end_comment

begin_decl_stmt
specifier|extern
name|lispval
name|sigacts
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|lispval
name|hunk_pages
index|[
literal|7
index|]
decl_stmt|,
name|hunk_items
index|[
literal|7
index|]
decl_stmt|,
name|hunk_name
index|[
literal|7
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TNP
value|if(np>= nplim) namerr();
end_define

begin_define
define|#
directive|define
name|TNP
value|if(np>= nplim) namerr();
end_define

begin_define
define|#
directive|define
name|INRNP
value|if (np++>= nplim) namerr();
end_define

begin_define
define|#
directive|define
name|protect
parameter_list|(
name|p
parameter_list|)
value|(np++->val = (p))
end_define

begin_define
define|#
directive|define
name|chkarg
parameter_list|(
name|p
parameter_list|,
name|x
parameter_list|)
value|; if((p)!=np-lbot) argerr(x);
end_define

begin_comment
comment|/** status codes **********************************************/
end_comment

begin_comment
comment|/*							      */
end_comment

begin_comment
comment|/* these define how status and sstatus should service probes  */
end_comment

begin_comment
comment|/* into the lisp data base				      */
end_comment

begin_comment
comment|/* common status codes */
end_comment

begin_define
define|#
directive|define
name|ST_NO
value|0
end_define

begin_comment
comment|/* status codes */
end_comment

begin_define
define|#
directive|define
name|ST_READ
value|1
end_define

begin_define
define|#
directive|define
name|ST_FEATR
value|2
end_define

begin_define
define|#
directive|define
name|ST_SYNT
value|3
end_define

begin_define
define|#
directive|define
name|ST_RINTB
value|4
end_define

begin_define
define|#
directive|define
name|ST_NFETR
value|5
end_define

begin_define
define|#
directive|define
name|ST_DMPR
value|6
end_define

begin_define
define|#
directive|define
name|ST_CTIM
value|7
end_define

begin_define
define|#
directive|define
name|ST_LOCT
value|8
end_define

begin_define
define|#
directive|define
name|ST_ISTTY
value|9
end_define

begin_define
define|#
directive|define
name|ST_UNDEF
value|10
end_define

begin_comment
comment|/* sstatus codes */
end_comment

begin_define
define|#
directive|define
name|ST_SET
value|1
end_define

begin_define
define|#
directive|define
name|ST_FEATW
value|2
end_define

begin_define
define|#
directive|define
name|ST_TOLC
value|3
end_define

begin_define
define|#
directive|define
name|ST_CORE
value|4
end_define

begin_define
define|#
directive|define
name|ST_INTB
value|5
end_define

begin_define
define|#
directive|define
name|ST_NFETW
value|6
end_define

begin_define
define|#
directive|define
name|ST_DMPW
value|7
end_define

begin_define
define|#
directive|define
name|ST_AUTR
value|8
end_define

begin_define
define|#
directive|define
name|ST_TRAN
value|9
end_define

begin_define
define|#
directive|define
name|ST_BCDTR
value|10
end_define

begin_comment
comment|/* number of counters for fasl to use in a profiling lisp  */
end_comment

begin_define
define|#
directive|define
name|NMCOUNT
value|5000
end_define

begin_comment
comment|/* hashing things *******************************************************/
end_comment

begin_define
define|#
directive|define
name|HASHTOP
value|1024
end_define

begin_comment
comment|/*  we handle 8-bit characters by dropping top bit  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|atom
modifier|*
name|hasht
index|[
name|HASHTOP
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hash
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set by ratom		*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|atmlen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* length of atom including final null	*/
end_comment

begin_comment
comment|/** exception handling ***********************************************/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|exception
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if TRUE then an exception is pending, one of */
end_comment

begin_comment
comment|/* the below 				        */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sigintcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if> 0 then there is a SIGINT pending	*/
end_comment

begin_comment
comment|/* big string buffer for whomever needs it ******************************/
end_comment

begin_decl_stmt
specifier|extern
name|char
name|strbuf
index|[
name|STRBLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|endstrb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* break and error declarations *****************************************/
end_comment

begin_define
define|#
directive|define
name|SAVSIZE
value|44
end_define

begin_comment
comment|/* number of bytes saved by setexit	*/
end_comment

begin_define
define|#
directive|define
name|BRRETB
value|1
end_define

begin_define
define|#
directive|define
name|BRCONT
value|2
end_define

begin_define
define|#
directive|define
name|BRGOTO
value|3
end_define

begin_define
define|#
directive|define
name|BRRETN
value|4
end_define

begin_define
define|#
directive|define
name|INTERRUPT
value|5
end_define

begin_define
define|#
directive|define
name|THROW
value|6
end_define

begin_decl_stmt
specifier|extern
name|int
name|depth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* depth of nested breaks		*/
end_comment

begin_decl_stmt
specifier|extern
name|lispval
name|contval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the value being returned up		*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|retval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used by each error/prog call		*/
end_comment

begin_decl_stmt
specifier|extern
name|lispval
name|lispretval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used by non-local go			*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rsetsw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used by *rset mode			*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|evalhcallsw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used by evalhook			*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|funhcallsw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used by evalhook			*/
end_comment

begin_decl_stmt
specifier|extern
name|lispval
name|Vevalframe
decl_stmt|;
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* used by evalframe			*/
end_comment

begin_comment
comment|/* other stuff **********************************************************/
end_comment

begin_decl_stmt
specifier|extern
name|lispval
name|ftemp
decl_stmt|,
name|vtemp
decl_stmt|,
name|argptr
decl_stmt|,
name|ttemp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* temporaries: use briefly  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|itemp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for pointer type conversion  */
end_comment

begin_include
include|#
directive|include
file|"dfuncs.h"
end_include

begin_define
define|#
directive|define
name|NUMBERP
value|2
end_define

begin_define
define|#
directive|define
name|BCDP
value|5
end_define

begin_define
define|#
directive|define
name|PORTP
value|6
end_define

begin_define
define|#
directive|define
name|ARRAYP
value|7
end_define

begin_define
define|#
directive|define
name|ABSVAL
value|0
end_define

begin_define
define|#
directive|define
name|MINUS
value|1
end_define

begin_define
define|#
directive|define
name|ADD1
value|2
end_define

begin_define
define|#
directive|define
name|SUB1
value|3
end_define

begin_define
define|#
directive|define
name|NOT
value|4
end_define

begin_define
define|#
directive|define
name|LNILL
value|5
end_define

begin_define
define|#
directive|define
name|ZEROP
value|6
end_define

begin_define
define|#
directive|define
name|ONEP
value|7
end_define

begin_define
define|#
directive|define
name|PLUS
value|8
end_define

begin_define
define|#
directive|define
name|TIMES
value|9
end_define

begin_define
define|#
directive|define
name|DIFFERENCE
value|10
end_define

begin_define
define|#
directive|define
name|QUOTIENT
value|11
end_define

begin_define
define|#
directive|define
name|MOD
value|12
end_define

begin_define
define|#
directive|define
name|LESSP
value|13
end_define

begin_define
define|#
directive|define
name|GREATERP
value|14
end_define

begin_define
define|#
directive|define
name|SUM
value|15
end_define

begin_define
define|#
directive|define
name|PRODUCT
value|16
end_define

begin_define
define|#
directive|define
name|AND
value|17
end_define

begin_define
define|#
directive|define
name|OR
value|18
end_define

begin_define
define|#
directive|define
name|XOR
value|19
end_define

begin_expr_stmt
name|interpt
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|handler
argument_list|()
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern sigdelay
operator|,
extern|sigstruck;
end_extern

begin_comment
comment|/* limit of valid data area **************************************/
end_comment

begin_decl_stmt
specifier|extern
name|lispval
name|datalim
decl_stmt|;
end_decl_stmt

begin_comment
comment|/** macros to push and pop the value of an atom on the stack ******/
end_comment

begin_define
define|#
directive|define
name|PUSHDOWN
parameter_list|(
name|atom
parameter_list|,
name|value
parameter_list|)
define|\
value|{bnp->atm=(atom);bnp++->val=(atom)->a.clb;(atom)->a.clb=value;\ 	if(bnp>bnplim) binderr();}
end_define

begin_define
define|#
directive|define
name|POP
define|\
value|{--bnp;bnp->atm->a.clb=bnp->val;}
end_define

begin_comment
comment|/** macro for evaluating atoms in eval and interpreter  ***********/
end_comment

begin_define
define|#
directive|define
name|EVALATOM
parameter_list|(
name|x
parameter_list|)
value|vtemp = x->a.clb;\ 			if( vtemp == CNIL ) {\ 				printf("%s: ",(x)->a.pname);\ 				vtemp = error("UNBOUND VARIABLE",TRUE);}
end_define

begin_comment
comment|/*  having to do with small integers					*/
end_comment

begin_define
define|#
directive|define
name|SMALL
parameter_list|(
name|i
parameter_list|)
value|((lispval)(1024 + (i<<2)))
end_define

begin_define
define|#
directive|define
name|P
parameter_list|(
name|p
parameter_list|)
value|((lispval) (xports +((p)-_iob)))
end_define

begin_define
define|#
directive|define
name|PN
parameter_list|(
name|p
parameter_list|)
value|((int) ((p)-_iob))
end_define

begin_define
define|#
directive|define
name|okport
parameter_list|(
name|arg
parameter_list|,
define|default) (vtemp = arg,((TYPE((vtemp))!=PORT)?default:(vtemp)->p))
end_define

begin_decl_stmt
specifier|extern
name|lispval
name|ioname
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* names of open files */
end_comment

begin_comment
comment|/*  interpreter globals   */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lctrace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* register lisp macros for registers */
end_comment

begin_define
define|#
directive|define
name|saveonly
parameter_list|(
name|n
parameter_list|)
value|asm("#save	n")
end_define

begin_define
define|#
directive|define
name|snpand
parameter_list|(
name|n
parameter_list|)
value|asm("#protect	n")
end_define

end_unit

