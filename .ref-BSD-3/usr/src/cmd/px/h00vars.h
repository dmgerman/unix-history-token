begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/*  * px - Berkeley Pascal interpreter  *  * Version 2.0, January 1979  *  * Original version by Ken Thompson  *  * Substantial revisions by Bill Joy and Chuck Haley  * November-December 1976  *  * Rewritten for VAX 11/780 by Kirk McKusick  * Fall 1978  *  * Px is described in detail in the "PX 1.0 Implementation Notes"  * The source code for px is in several major pieces:  *  *	int.c		C main program which reads in interpreter code  *	00case.s	Driver including main interpreter loop  *	dd*.s		Where dd are digits, interpreter instructions  *			grouped by their positions in the interpreter table.  *	p*.c		Various C language routines supporting the system.  *  * In addition there are several headers defining mappings for error  * messages names into codes, and a definition of the interpreter transfer  * table. These are made by the script Emake in this directory and the scripts  * in the directory '../opcodes'.  */
end_comment

begin_decl_stmt
name|long
name|argc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Pascal runtime errors transfer to the routine  * 'error' in the file perror.c to decode them.  */
end_comment

begin_decl_stmt
name|int
name|perrno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of error which occurred */
end_comment

begin_comment
comment|/*  * Definitions for memory allocation  * Memory allocation is done by palloc in utilities.c  */
end_comment

begin_comment
comment|/*  * The file i/o routines maintain a notion of a "current file".  * The printing name of this file is kept in the variable  * "file" for use in error messages.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to active file name */
end_comment

begin_decl_stmt
name|long
name|fchain
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of active file chain */
end_comment

begin_decl_stmt
name|int
name|bufopt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* controls flushing of std output as follows: 			 * 0 => flush on every write 			 * 1 => flush before std read or at end of line 			 * 2 => normal buffering 			 */
end_comment

begin_comment
comment|/*  * THE RUNTIME DISPLAY  *  * The entries in the display point to the active static block marks.  * The first entry in the display is for the global variables,  * then the procedure or function at level one, etc.  * Each display entry points to a stack frame as shown:  *  *		base of stack frame  *		  ---------------  *		  |		|  *		  | block mark  |  *		  |		|  *		  ---------------<-- display entry points here  *		  |             |  *		  |   local	|  *		  |  variables  |  *		  |		|  *		  ---------------  *		  |		|  *		  |  expression |  *		  |  temporary  |  *		  |  storage	|  *		  |		|  *		  - - - - - - - -  *  * The information in the block mark is thus at positive offsets from  * the display pointer entries while the local variables are at negative  * offsets. The block mark actually consists of two parts. The first  * part is created at CALL and the second at entry, i.e. BEGIN. Thus:  *  *		-------------------------  *		|			|  *		|  Saved lino		|  *		|  Saved lc		|  *		|  Saved dp		|  *		|			|  *		-------------------------  *		|			|  *		|  Saved (dp)		|  *		|			|  *		|  Current section name	|  *		|   and entry line ptr	|  *		|			|  *		|  Saved file name and	|  *		|   file buffer ptr	|  *		|			|  *		|  Empty tos value	|  *		|			|  *		-------------------------  */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  * Structure for accessing things in the block mark  */
end_comment

begin_struct
struct|struct
name|stack
block|{
name|long
modifier|*
name|tos
decl_stmt|;
comment|/* pointer to top of stack frame */
name|char
modifier|*
name|file
decl_stmt|;
comment|/* pointer to active file name */
name|long
name|buf
decl_stmt|;
comment|/* pointer to active file record */
struct|struct
block|{
name|char
name|name
index|[
literal|8
index|]
decl_stmt|;
comment|/* name of active procedure */
name|short
name|offset
decl_stmt|;
comment|/* offset of procedure in source file */
block|}
modifier|*
name|entry
struct|;
name|struct
name|stack
modifier|*
name|disp
decl_stmt|;
comment|/* previous display value for this level */
name|struct
name|stack
modifier|*
modifier|*
name|dp
decl_stmt|;
comment|/* pointer to active display entry */
name|long
name|lc
decl_stmt|;
comment|/* previous location counter */
name|long
name|lino
decl_stmt|;
comment|/* previous line number */
block|}
modifier|*
name|display
index|[
literal|40
index|]
struct|;
end_struct

begin_decl_stmt
name|long
name|addrsze
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of display addresses */
end_comment

begin_comment
comment|/*  * Program option variables  */
end_comment

begin_decl_stmt
name|long
name|stcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of statements executed */
end_comment

begin_decl_stmt
name|long
name|stlim
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max number of statements to execute */
end_comment

begin_decl_stmt
name|long
name|llimit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max number of lines per text file */
end_comment

begin_decl_stmt
name|short
name|nodump
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 => no post mortum dump */
end_comment

begin_decl_stmt
name|short
name|mode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mode of input to interpreter */
end_comment

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

begin_escape
end_escape

begin_comment
comment|/*  * Pxp variables  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|pxpbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to pxp buffer */
end_comment

begin_decl_stmt
name|long
name|pxpsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of pxp buffer */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|profile
end_ifdef

begin_comment
comment|/*  * Px execution profile data  */
end_comment

begin_define
define|#
directive|define
name|numops
value|256
end_define

begin_struct
struct|struct
name|cntrec
block|{
name|double
name|counts
index|[
name|numops
index|]
decl_stmt|;
comment|/* instruction counts */
name|long
name|runs
decl_stmt|;
comment|/* number of interpreter runs */
name|long
name|startdate
decl_stmt|;
comment|/* date profile started */
name|long
name|usrtime
decl_stmt|;
comment|/* total user time consumed */
name|long
name|systime
decl_stmt|;
comment|/* total system time consumed */
name|double
name|stmts
decl_stmt|;
comment|/* number of pascal statements executed */
block|}
name|profdata
struct|;
end_struct

begin_decl_stmt
name|long
name|profcnts
index|[
name|numops
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|proffile
value|"/usr/ucb/pascal/px/pcnt.out"
end_define

begin_decl_stmt
name|FILE
modifier|*
name|datafile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input datafiles */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|profcnts
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dummy just to keep the linker happy */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

