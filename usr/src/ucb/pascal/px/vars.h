begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)vars.h	5.2 (Berkeley) 11/5/86  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/*  * px - Berkeley Pascal interpreter  *  * Version 4.0, January 1981  *  * Original version by Ken Thompson  *  * Substantial revisions by Bill Joy and Chuck Haley  * November-December 1976  *  * Rewritten for VAX 11/780 by Kirk McKusick  * Fall 1978  *  * Rewritten in ``C'' using libpc by Kirk McKusick  * Winter 1981  *  * Px is described in detail in the "PX 4.0 Implementation Notes"  * The source code for px is in several major pieces:  *  *	int.c		C main program which reads in interpreter code  *	interp.c	Driver including main interpreter loop and  *			the interpreter instructions grouped by their  *			positions in the interpreter table.  *	utilities.c	Interpreter exit, backtrace, and runtime statistics.  *  * In addition there are several headers defining mappings for panic  * names into codes, and a definition of the interpreter transfer  * table. These are made by the script make.ed1 in this directory and   * the routine opc.c from ${PASCALDIR}. (see the makefile for details)  */
end_comment

begin_define
define|#
directive|define
name|PXPFILE
value|"pmon.out"
end_define

begin_define
define|#
directive|define
name|BITSPERBYTE
value|8
end_define

begin_define
define|#
directive|define
name|BITSPERLONG
value|(BITSPERBYTE * sizeof(long))
end_define

begin_define
define|#
directive|define
name|HZ
value|100
end_define

begin_define
define|#
directive|define
name|NAMSIZ
value|76
end_define

begin_define
define|#
directive|define
name|MAXFILES
value|32
end_define

begin_define
define|#
directive|define
name|PREDEF
value|2
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ADDR32
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|tahoe
end_ifndef

begin_define
define|#
directive|define
name|STDLVL
value|((struct iorec *)(0x7ffffff1))
end_define

begin_define
define|#
directive|define
name|GLVL
value|((struct iorec *)(0x7ffffff0))
end_define

begin_else
else|#
directive|else
else|tahoe
end_else

begin_define
define|#
directive|define
name|STDLVL
value|((struct iorec *)(0xbffffff1))
end_define

begin_define
define|#
directive|define
name|GLVL
value|((struct iorec *)(0xbffffff0))
end_define

begin_endif
endif|#
directive|endif
endif|tahoe
end_endif

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
name|STDLVL
value|((struct iorec *)(0xfff1))
end_define

begin_define
define|#
directive|define
name|GLVL
value|((struct iorec *)(0xfff0))
end_define

begin_endif
endif|#
directive|endif
endif|ADDR16
end_endif

begin_define
define|#
directive|define
name|FILNIL
value|((struct iorec *)(0))
end_define

begin_define
define|#
directive|define
name|INPUT
value|((struct iorec *)(&input))
end_define

begin_define
define|#
directive|define
name|OUTPUT
value|((struct iorec *)(&output))
end_define

begin_define
define|#
directive|define
name|ERR
value|((struct iorec *)(&_err))
end_define

begin_define
define|#
directive|define
name|PX
value|0
end_define

begin_comment
comment|/* normal run of px */
end_comment

begin_define
define|#
directive|define
name|PIX
value|1
end_define

begin_comment
comment|/* load and go */
end_comment

begin_define
define|#
directive|define
name|PIPE
value|2
end_define

begin_comment
comment|/* bootstrap via a pipe */
end_comment

begin_define
define|#
directive|define
name|PDX
value|3
end_define

begin_comment
comment|/* invoked by the debugger "pdx" */
end_comment

begin_define
define|#
directive|define
name|releq
value|0
end_define

begin_define
define|#
directive|define
name|relne
value|2
end_define

begin_define
define|#
directive|define
name|rellt
value|4
end_define

begin_define
define|#
directive|define
name|relgt
value|6
end_define

begin_define
define|#
directive|define
name|relle
value|8
end_define

begin_define
define|#
directive|define
name|relge
value|10
end_define

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
comment|/*  * interrupt and allocation routines  */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|createtime
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|PALLOC
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|time
parameter_list|()
function_decl|;
end_function_decl

begin_extern
extern|extern intr(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern memsize(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern syserr(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern liberr(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * stack routines and structures  */
end_comment

begin_struct
struct|struct
name|sze8
block|{
name|char
name|element
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|short
name|pop2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|pop4
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
name|pop8
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|sze8
name|popsze8
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|pushsp
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * emulated pc types  */
end_comment

begin_union
union|union
name|progcntr
block|{
name|char
modifier|*
name|cp
decl_stmt|;
name|unsigned
name|char
modifier|*
name|ucp
decl_stmt|;
name|short
modifier|*
name|sp
decl_stmt|;
name|unsigned
name|short
modifier|*
name|usp
decl_stmt|;
name|long
modifier|*
name|lp
decl_stmt|;
name|double
modifier|*
name|dbp
decl_stmt|;
name|struct
name|hdr
modifier|*
name|hdrp
decl_stmt|;
block|}
union|;
end_union

begin_escape
end_escape

begin_comment
comment|/*  * THE RUNTIME DISPLAY  *  * The entries in the display point to the active static block marks.  * The first entry in the display is for the global variables,  * then the procedure or function at level one, etc.  * Each display entry points to a stack frame as shown:  *  *		base of stack frame  *		  ---------------  *		  |		|  *		  | block mark  |  *		  |		|  *		  ---------------<-- display entry "stp" points here  *		  |             |<-- display entry "locvars" points here  *		  |   local	|  *		  |  variables  |  *		  |		|  *		  ---------------  *		  |		|  *		  |  expression |  *		  |  temporary  |  *		  |  storage	|  *		  |		|  *		  - - - - - - - -  *  * The information in the block mark is thus at positive offsets from  * the display.stp pointer entries while the local variables are at negative  * offsets from display.locvars. The block mark actually consists of  * two parts. The first part is created at CALL and the second at entry,  * i.e. BEGIN. Thus:  *  *		-------------------------  *		|			|  *		|  Saved lino		|  *		|  Saved lc		|  *		|  Saved dp		|  *		|			|  *		-------------------------  *		|			|  *		|  Saved (dp)		|  *		|			|  *		|  Pointer to current 	|  *		|   routine header info	|  *		|			|  *		|  Saved value of	|  *		|   "curfile"		|  *		|			|  *		|  Empty tos value	|  *		|			|  *		-------------------------  */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  * program variables  */
end_comment

begin_decl_stmt
specifier|extern
name|union
name|display
name|_display
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* runtime display */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|dispsave
modifier|*
name|_dp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to active frame */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|_lino
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current line number */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_argc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of passed args */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|_argv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* values of passed args */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|_nodump
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE => no post mortum dump */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|_runtst
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE => runtime tests */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|_mode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* execl by PX, PIPE, or PIX */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|_stlim
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* statement limit */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|_stcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* statement count */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|_seed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* random number seed */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_maxptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum valid pointer */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_minptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* minimum valid pointer */
end_comment

begin_decl_stmt
specifier|extern
name|long
modifier|*
name|_pcpcount
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to pxp buffer */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|_cntrs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of counters */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|_rtns
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of routine cntrs */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  * The file i/o routines maintain a notion of a "current file".  * A pointer to this file structure is kept in "curfile".  *  * file structures  */
end_comment

begin_struct
struct|struct
name|iorechd
block|{
name|char
modifier|*
name|fileptr
decl_stmt|;
comment|/* ptr to file window */
name|long
name|lcount
decl_stmt|;
comment|/* number of lines printed */
name|long
name|llimit
decl_stmt|;
comment|/* maximum number of text lines */
name|FILE
modifier|*
name|fbuf
decl_stmt|;
comment|/* FILE ptr */
name|struct
name|iorec
modifier|*
name|fchain
decl_stmt|;
comment|/* chain to next file */
name|struct
name|iorec
modifier|*
name|flev
decl_stmt|;
comment|/* ptr to associated file variable */
name|char
modifier|*
name|pfname
decl_stmt|;
comment|/* ptr to name of file */
name|short
name|funit
decl_stmt|;
comment|/* file status flags */
name|short
name|fblk
decl_stmt|;
comment|/* index into active file table */
name|long
name|fsize
decl_stmt|;
comment|/* size of elements in the file */
name|char
name|fname
index|[
name|NAMSIZ
index|]
decl_stmt|;
comment|/* name of associated UNIX file */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iorec
block|{
name|char
modifier|*
name|fileptr
decl_stmt|;
comment|/* ptr to file window */
name|long
name|lcount
decl_stmt|;
comment|/* number of lines printed */
name|long
name|llimit
decl_stmt|;
comment|/* maximum number of text lines */
name|FILE
modifier|*
name|fbuf
decl_stmt|;
comment|/* FILE ptr */
name|struct
name|iorec
modifier|*
name|fchain
decl_stmt|;
comment|/* chain to next file */
name|struct
name|iorec
modifier|*
name|flev
decl_stmt|;
comment|/* ptr to associated file variable */
name|char
modifier|*
name|pfname
decl_stmt|;
comment|/* ptr to name of file */
name|short
name|funit
decl_stmt|;
comment|/* file status flags */
name|short
name|fblk
decl_stmt|;
comment|/* index into active file table */
name|long
name|fsize
decl_stmt|;
comment|/* size of elements in the file */
name|char
name|fname
index|[
name|NAMSIZ
index|]
decl_stmt|;
comment|/* name of associated UNIX file */
name|char
name|buf
index|[
name|BUFSIZ
index|]
decl_stmt|;
comment|/* I/O buffer */
name|char
name|window
index|[
literal|1
index|]
decl_stmt|;
comment|/* file window element */
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/*  * unit flags  */
end_comment

begin_define
define|#
directive|define
name|FDEF
value|0x80
end_define

begin_comment
comment|/* 1 => reserved file name */
end_comment

begin_define
define|#
directive|define
name|FTEXT
value|0x40
end_define

begin_comment
comment|/* 1 => text file, process EOLN */
end_comment

begin_define
define|#
directive|define
name|FWRITE
value|0x20
end_define

begin_comment
comment|/* 1 => open for writing */
end_comment

begin_define
define|#
directive|define
name|FREAD
value|0x10
end_define

begin_comment
comment|/* 1 => open for reading */
end_comment

begin_define
define|#
directive|define
name|TEMP
value|0x08
end_define

begin_comment
comment|/* 1 => temporary file */
end_comment

begin_define
define|#
directive|define
name|SYNC
value|0x04
end_define

begin_comment
comment|/* 1 => window is out of sync */
end_comment

begin_define
define|#
directive|define
name|EOLN
value|0x02
end_define

begin_comment
comment|/* 1 => at end of line */
end_comment

begin_define
define|#
directive|define
name|EOFF
value|0x01
end_define

begin_comment
comment|/* 1 => at end of file */
end_comment

begin_comment
comment|/*  * file routines  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|iorec
modifier|*
name|GETNAME
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|MKTEMP
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * file record variables  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|iorechd
name|_fchain
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of active file chain */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|iorec
modifier|*
name|_actfile
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* table of active files */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|_filefre
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last used entry in _actfile */
end_comment

begin_comment
comment|/*  * standard files  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|iorechd
name|input
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|iorechd
name|output
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|iorechd
name|_err
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Px execution profile array  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PROFILE
end_ifdef

begin_define
define|#
directive|define
name|NUMOPS
value|256
end_define

begin_decl_stmt
specifier|extern
name|long
name|_profcnts
index|[
name|NUMOPS
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|PROFILE
end_endif

end_unit

