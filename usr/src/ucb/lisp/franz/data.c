begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Header: /na/franz/franz/RCS/data.c,v 1.2 83/01/29 12:31:39 jkf Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*					-[Sat Jan 29 12:21:50 1983 by jkf]-  * 	data.c				$Locker:  $  * static storage declarations  *  * (c) copyright 1982, Regents of the University of California  */
end_comment

begin_include
include|#
directive|include
file|"global.h"
end_include

begin_include
include|#
directive|include
file|"gtabs.h"
end_include

begin_include
include|#
directive|include
file|"structs.h"
end_include

begin_include
include|#
directive|include
file|"frame.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/*char firstalloc[NBPG] = { 'x' };	/* first thing allocated in file */
end_comment

begin_decl_stmt
name|lispval
name|lispsys
index|[
name|SIGNIF
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lisp data used by system */
end_comment

begin_decl_stmt
name|lispval
name|gftab
index|[
name|GFTABLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* global function table for interpreter */
end_comment

begin_decl_stmt
name|lispval
name|gctab
index|[
name|GCTABLEN
index|]
init|=
comment|/* global constant table for interpreter */
block|{
name|nil
block|,
literal|0
block|,
name|SMALL
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|SMALL
argument_list|(
literal|0
argument_list|)
block|,
name|SMALL
argument_list|(
literal|1
argument_list|)
block|,
name|SMALL
argument_list|(
literal|2
argument_list|)
block|,
name|SMALL
argument_list|(
literal|3
argument_list|)
block|,
name|SMALL
argument_list|(
literal|4
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Port definitions *****************************************************/
end_comment

begin_decl_stmt
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
decl_stmt|,
comment|/* temporary port for readr	*/
modifier|*
name|proport
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* port for protocal		*/
end_comment

begin_decl_stmt
name|int
name|lineleng
init|=
literal|80
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line length desired		*/
end_comment

begin_decl_stmt
name|int
name|rlevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used to indicate depth of recursion 				   in reader.  No longer really necessary */
end_comment

begin_decl_stmt
name|char
name|keybin
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* logical flag: using keyboard	*/
end_comment

begin_decl_stmt
name|char
name|protflag
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* logical flag: want protocall */
end_comment

begin_decl_stmt
name|char
name|rbktf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* logical flag: ] mode		*/
end_comment

begin_decl_stmt
name|lispval
name|ioname
index|[
name|_NFILE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* strings of names of files currently open	*/
end_comment

begin_comment
comment|/* name stack ***********************************************************/
end_comment

begin_decl_stmt
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
name|struct
name|argent
modifier|*
name|namptr
decl_stmt|,
comment|/* temporary pointer	*/
ifdef|#
directive|ifdef
name|PORTABLE
modifier|*
name|lbot
decl_stmt|,
comment|/* beginning of frame	*/
modifier|*
name|np
decl_stmt|,
comment|/* first free entry   	*/
endif|#
directive|endif
modifier|*
name|nplim
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* don't have this = np	*/
end_comment

begin_decl_stmt
name|struct
name|nament
modifier|*
name|bnp
decl_stmt|,
comment|/* top of bind stack    */
modifier|*
name|orgbnp
decl_stmt|,
comment|/* absolute bottom of ""*/
modifier|*
name|bnplim
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* absolute top of ""   */
end_comment

begin_comment
comment|/* hashing things *******************************************************/
end_comment

begin_decl_stmt
name|int
name|hash
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set by ratom		*/
end_comment

begin_decl_stmt
name|int
name|atmlen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* length of atom including final null	*/
end_comment

begin_comment
comment|/* big string buffer for whomever needs it ******************************/
end_comment

begin_decl_stmt
name|char
name|strbuf
index|[
name|STRBLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|endstrb
init|=
name|strbuf
operator|+
name|STRBLEN
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* strings needed by the two hand crafted atoms, nil and eof */
end_comment

begin_decl_stmt
name|char
name|nilpname
index|[]
init|=
literal|"nil"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|eofpname
index|[]
init|=
literal|"eof"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set by sstatus commands */
end_comment

begin_decl_stmt
name|int
name|uctolc
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* when set, uc chars in atoms go to lc */
end_comment

begin_decl_stmt
name|int
name|dmpmode
init|=
literal|413
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default mode for dumplisp  			   (note this is decimal not octal) */
end_comment

begin_comment
comment|/* break and error declarations *****************************************/
end_comment

begin_decl_stmt
name|int
name|depth
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* depth of nested breaks		*/
end_comment

begin_decl_stmt
name|lispval
name|contval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the value being returned up		*/
end_comment

begin_decl_stmt
name|int
name|retval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used by each error/prog call		*/
end_comment

begin_decl_stmt
name|lispval
name|lispretval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used by non-local goto's		*/
end_comment

begin_decl_stmt
name|int
name|rsetsw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* when set, trace frames built		*/
end_comment

begin_decl_stmt
name|int
name|bcdtrsw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* when set with rsetsw, trace bcd too	*/
end_comment

begin_decl_stmt
name|int
name|evalhcallsw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* when set will not evalhook next eval */
end_comment

begin_decl_stmt
name|int
name|funhcallsw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* when set will not funcallhook next eval */
end_comment

begin_comment
comment|/* exception handling stuff *********************************************/
end_comment

begin_decl_stmt
name|int
name|exception
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if an exception is pending */
end_comment

begin_decl_stmt
name|int
name|sigintcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of SIGINT's pending	   */
end_comment

begin_comment
comment|/* current state of the hole (for fasling into) *************************/
end_comment

begin_decl_stmt
name|char
modifier|*
name|curhbeg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next location to fasl into */
end_comment

begin_decl_stmt
name|int
name|usehole
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if TRUE, fasl tries to use hole */
end_comment

begin_comment
comment|/* other stuff **********************************************************/
end_comment

begin_decl_stmt
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
comment|/* temporaries: use briefly	*/
end_comment

begin_decl_stmt
name|int
name|itemp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|lispval
name|sigacts
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for catching interrupts	*/
end_comment

begin_decl_stmt
name|int
name|sigstruck
decl_stmt|,
name|sigdelay
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for catching interrupts	*/
end_comment

begin_decl_stmt
name|lispval
name|stattab
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* miscelleneous options	*/
end_comment

begin_comment
comment|/*  interpreter globals    */
end_comment

begin_decl_stmt
name|int
name|lctrace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fvirgin
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to 1 initially 			*/
end_comment

begin_decl_stmt
name|int
name|gctime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|frame
modifier|*
name|errp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stack of error frames 		*/
end_comment

begin_comment
comment|/* global pointers to the transfer tables */
end_comment

begin_decl_stmt
name|struct
name|trtab
modifier|*
name|trhead
init|=
comment|/* first in list of transfer tables 	   */
operator|(
expr|struct
name|trtab
operator|*
operator|)
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|trent
modifier|*
name|trcur
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next entry to allocate	    	   */
end_comment

begin_decl_stmt
name|int
name|trleft
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of entries left in current table */
end_comment

begin_comment
comment|/* globals from sysat.c  */
end_comment

begin_decl_stmt
name|int
modifier|*
name|beginsweep
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* place for sweeper to begin 		*/
end_comment

begin_decl_stmt
name|int
name|initflag
init|=
name|TRUE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* inhibit gcing initially		*/
end_comment

begin_decl_stmt
name|int
name|tgcthresh
init|=
literal|15
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|page_limit
init|=
operator|(
literal|5
operator|*
name|TTSIZE
operator|)
operator|/
literal|6
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* globals from rlc  */
end_comment

begin_decl_stmt
name|int
name|usehole
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if allocator should consider the  				   hole for allocation		*/
end_comment

begin_comment
comment|/* global used in io.c */
end_comment

begin_decl_stmt
name|lispval
name|lastrtab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* globals from [VT]alloc.c  */
end_comment

begin_decl_stmt
name|char
name|purepage
index|[
name|TTSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fakettsize
init|=
name|TTSIZE
operator|-
literal|8
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gcstrings
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  Do we mark and sweep strings? */
end_comment

begin_decl_stmt
name|int
modifier|*
name|bind_lists
init|=
operator|(
name|int
operator|*
operator|)
name|CNIL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  lisp data for compiled code */
end_comment

begin_decl_stmt
name|struct
name|str_x
name|str_current
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  next free string spaces */
end_comment

begin_decl_stmt
name|struct
name|types
name|atom_str
init|=
block|{
operator|(
name|char
operator|*
operator|)
name|CNIL
block|,
literal|0
block|,
name|ATOMSPP
block|,
name|ATOM
block|,
literal|5
block|,
operator|&
name|atom_items
block|,
operator|&
name|atom_pages
block|,
operator|&
name|atom_name
block|,
operator|(
expr|struct
name|heads
operator|*
operator|)
name|CNIL
block|,
operator|(
name|char
operator|*
operator|)
name|CNIL
block|}
decl_stmt|,
name|strng_str
init|=
block|{
operator|(
name|char
operator|*
operator|)
name|CNIL
block|,
literal|0
block|,
name|STRSPP
block|,
name|STRNG
block|,
literal|128
block|,
operator|&
name|str_items
block|,
operator|&
name|str_pages
block|,
operator|&
name|str_name
block|,
operator|(
expr|struct
name|heads
operator|*
operator|)
name|CNIL
block|,
operator|(
name|char
operator|*
operator|)
name|CNIL
block|}
decl_stmt|,
name|int_str
init|=
block|{
operator|(
name|char
operator|*
operator|)
name|CNIL
block|,
literal|0
block|,
name|INTSPP
block|,
name|INT
block|,
literal|1
block|,
operator|&
name|int_items
block|,
operator|&
name|int_pages
block|,
operator|&
name|int_name
block|,
operator|(
expr|struct
name|heads
operator|*
operator|)
name|CNIL
block|,
operator|(
name|char
operator|*
operator|)
name|CNIL
block|}
decl_stmt|,
name|dtpr_str
init|=
block|{
operator|(
name|char
operator|*
operator|)
name|CNIL
block|,
literal|0
block|,
name|DTPRSPP
block|,
name|DTPR
block|,
literal|2
block|,
operator|&
name|dtpr_items
block|,
operator|&
name|dtpr_pages
block|,
operator|&
name|dtpr_name
block|,
operator|(
expr|struct
name|heads
operator|*
operator|)
name|CNIL
block|,
operator|(
name|char
operator|*
operator|)
name|CNIL
block|}
decl_stmt|,
name|doub_str
init|=
block|{
operator|(
name|char
operator|*
operator|)
name|CNIL
block|,
literal|0
block|,
name|DOUBSPP
block|,
name|DOUB
block|,
literal|2
block|,
operator|&
name|doub_items
block|,
operator|&
name|doub_pages
block|,
operator|&
name|doub_name
block|,
operator|(
expr|struct
name|heads
operator|*
operator|)
name|CNIL
block|,
operator|(
name|char
operator|*
operator|)
name|CNIL
block|}
decl_stmt|,
name|array_str
init|=
block|{
operator|(
name|char
operator|*
operator|)
name|CNIL
block|,
literal|0
block|,
name|ARRAYSPP
block|,
name|ARRAY
block|,
literal|5
block|,
operator|&
name|array_items
block|,
operator|&
name|array_pages
block|,
operator|&
name|array_name
block|,
operator|(
expr|struct
name|heads
operator|*
operator|)
name|CNIL
block|,
operator|(
name|char
operator|*
operator|)
name|CNIL
block|}
decl_stmt|,
name|other_str
init|=
block|{
operator|(
name|char
operator|*
operator|)
name|CNIL
block|,
literal|0
block|,
name|STRSPP
block|,
name|OTHER
block|,
literal|128
block|,
operator|&
name|other_items
block|,
operator|&
name|other_pages
block|,
operator|&
name|other_name
block|,
operator|(
expr|struct
name|heads
operator|*
operator|)
name|CNIL
block|,
operator|(
name|char
operator|*
operator|)
name|CNIL
block|}
decl_stmt|,
name|sdot_str
init|=
block|{
operator|(
name|char
operator|*
operator|)
name|CNIL
block|,
literal|0
block|,
name|SDOTSPP
block|,
name|SDOT
block|,
literal|2
block|,
operator|&
name|sdot_items
block|,
operator|&
name|sdot_pages
block|,
operator|&
name|sdot_name
block|,
operator|(
expr|struct
name|heads
operator|*
operator|)
name|CNIL
block|,
operator|(
name|char
operator|*
operator|)
name|CNIL
block|}
decl_stmt|,
name|val_str
init|=
block|{
operator|(
name|char
operator|*
operator|)
name|CNIL
block|,
literal|0
block|,
name|VALSPP
block|,
name|VALUE
block|,
literal|1
block|,
operator|&
name|val_items
block|,
operator|&
name|val_pages
block|,
operator|&
name|val_name
block|,
operator|(
expr|struct
name|heads
operator|*
operator|)
name|CNIL
block|,
operator|(
name|char
operator|*
operator|)
name|CNIL
block|}
decl_stmt|,
name|funct_str
init|=
block|{
operator|(
name|char
operator|*
operator|)
name|CNIL
block|,
literal|0
block|,
name|BCDSPP
block|,
name|BCD
block|,
literal|2
block|,
operator|&
name|funct_items
block|,
operator|&
name|funct_pages
block|,
operator|&
name|funct_name
block|,
operator|(
expr|struct
name|heads
operator|*
operator|)
name|CNIL
block|,
operator|(
name|char
operator|*
operator|)
name|CNIL
block|}
decl_stmt|,
name|vect_str
init|=
block|{
operator|(
name|char
operator|*
operator|)
name|CNIL
block|,
literal|0
block|,
name|VECTORSPP
block|,
name|VECTOR
block|,
literal|1
block|,
operator|&
name|vect_items
block|,
operator|&
name|vect_pages
block|,
operator|&
name|vect_name
block|,
operator|(
expr|struct
name|heads
operator|*
operator|)
name|CNIL
block|,
operator|(
name|char
operator|*
operator|)
name|CNIL
block|}
decl_stmt|,
name|vecti_str
init|=
block|{
operator|(
name|char
operator|*
operator|)
name|CNIL
block|,
literal|0
block|,
name|VECTORSPP
block|,
name|VECTORI
block|,
literal|1
block|,
operator|&
name|vect_items
block|,
operator|&
name|vecti_pages
block|,
operator|&
name|vecti_name
block|,
operator|(
expr|struct
name|heads
operator|*
operator|)
name|CNIL
block|,
operator|(
name|char
operator|*
operator|)
name|CNIL
block|}
decl_stmt|,
name|hunk_str
index|[
literal|7
index|]
init|=
block|{
block|{
operator|(
name|char
operator|*
operator|)
name|CNIL
block|,
literal|0
block|,
name|HUNK2SPP
block|,
name|HUNK2
block|,
literal|2
block|,
operator|&
name|hunk_items
index|[
literal|0
index|]
block|,
operator|&
name|hunk_pages
index|[
literal|0
index|]
block|,
operator|&
name|hunk_name
index|[
literal|0
index|]
block|,
operator|(
expr|struct
name|heads
operator|*
operator|)
name|CNIL
block|,
operator|(
name|char
operator|*
operator|)
name|CNIL
block|}
block|,
block|{
operator|(
name|char
operator|*
operator|)
name|CNIL
block|,
literal|0
block|,
name|HUNK4SPP
block|,
name|HUNK4
block|,
literal|4
block|,
operator|&
name|hunk_items
index|[
literal|1
index|]
block|,
operator|&
name|hunk_pages
index|[
literal|1
index|]
block|,
operator|&
name|hunk_name
index|[
literal|1
index|]
block|,
operator|(
expr|struct
name|heads
operator|*
operator|)
name|CNIL
block|,
operator|(
name|char
operator|*
operator|)
name|CNIL
block|}
block|,
block|{
operator|(
name|char
operator|*
operator|)
name|CNIL
block|,
literal|0
block|,
name|HUNK8SPP
block|,
name|HUNK8
block|,
literal|8
block|,
operator|&
name|hunk_items
index|[
literal|2
index|]
block|,
operator|&
name|hunk_pages
index|[
literal|2
index|]
block|,
operator|&
name|hunk_name
index|[
literal|2
index|]
block|,
operator|(
expr|struct
name|heads
operator|*
operator|)
name|CNIL
block|,
operator|(
name|char
operator|*
operator|)
name|CNIL
block|}
block|,
block|{
operator|(
name|char
operator|*
operator|)
name|CNIL
block|,
literal|0
block|,
name|HUNK16SPP
block|,
name|HUNK16
block|,
literal|16
block|,
operator|&
name|hunk_items
index|[
literal|3
index|]
block|,
operator|&
name|hunk_pages
index|[
literal|3
index|]
block|,
operator|&
name|hunk_name
index|[
literal|3
index|]
block|,
operator|(
expr|struct
name|heads
operator|*
operator|)
name|CNIL
block|,
operator|(
name|char
operator|*
operator|)
name|CNIL
block|}
block|,
block|{
operator|(
name|char
operator|*
operator|)
name|CNIL
block|,
literal|0
block|,
name|HUNK32SPP
block|,
name|HUNK32
block|,
literal|32
block|,
operator|&
name|hunk_items
index|[
literal|4
index|]
block|,
operator|&
name|hunk_pages
index|[
literal|4
index|]
block|,
operator|&
name|hunk_name
index|[
literal|4
index|]
block|,
operator|(
expr|struct
name|heads
operator|*
operator|)
name|CNIL
block|,
operator|(
name|char
operator|*
operator|)
name|CNIL
block|}
block|,
block|{
operator|(
name|char
operator|*
operator|)
name|CNIL
block|,
literal|0
block|,
name|HUNK64SPP
block|,
name|HUNK64
block|,
literal|64
block|,
operator|&
name|hunk_items
index|[
literal|5
index|]
block|,
operator|&
name|hunk_pages
index|[
literal|5
index|]
block|,
operator|&
name|hunk_name
index|[
literal|5
index|]
block|,
operator|(
expr|struct
name|heads
operator|*
operator|)
name|CNIL
block|,
operator|(
name|char
operator|*
operator|)
name|CNIL
block|}
block|,
block|{
operator|(
name|char
operator|*
operator|)
name|CNIL
block|,
literal|0
block|,
name|HUNK128SPP
block|,
name|HUNK128
block|,
literal|128
block|,
operator|&
name|hunk_items
index|[
literal|6
index|]
block|,
operator|&
name|hunk_pages
index|[
literal|6
index|]
block|,
operator|&
name|hunk_name
index|[
literal|6
index|]
block|,
operator|(
expr|struct
name|heads
operator|*
operator|)
name|CNIL
block|,
operator|(
name|char
operator|*
operator|)
name|CNIL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_struct
specifier|extern
struct|struct
name|readtable
block|{
name|unsigned
name|char
name|ctable
index|[
literal|132
index|]
decl_stmt|;
block|}
name|initread
struct|;
end_struct

begin_decl_stmt
name|unsigned
name|char
modifier|*
name|ctable
init|=
name|initread
operator|.
name|ctable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gensymcounter
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|hashtop
init|=
name|HASHTOP
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|xcycle
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used by xsbrk   */
end_comment

begin_decl_stmt
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
name|lispval
name|datalim
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to next location to allocate */
end_comment

begin_decl_stmt
name|char
name|typetable
index|[
name|TTSIZE
operator|+
literal|1
index|]
init|=
block|{
name|UNBO
block|,
name|ATOM
block|,
name|PORT
block|,
name|INT
block|,
name|INT
block|,
name|INT
block|,
name|INT
block|,
name|INT
block|,
name|INT
block|,
name|INT
block|,
name|INT
block|,
name|INT
block|,
name|INT
block|,
name|INT
block|,
name|INT
block|,
name|INT
block|,
name|INT
block|,
name|INT
block|,
name|INT
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* this must be the last thing allocated in this file	*/
end_comment

begin_decl_stmt
name|char
name|lsbrkpnt
decl_stmt|,
name|zfreespace
decl_stmt|;
end_decl_stmt

end_unit

