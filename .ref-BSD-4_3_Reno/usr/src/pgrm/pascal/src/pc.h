begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)pc.h	5.2 (Berkeley) 11/12/86  */
end_comment

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_comment
comment|/*      *	random constants for pc      */
end_comment

begin_comment
comment|/*      *	the name of the display.      */
end_comment

begin_define
define|#
directive|define
name|DISPLAYNAME
value|"__disply"
end_define

begin_comment
comment|/*      *	the structure below describes the locals used by the run time system.      *	at function entry, at least this much space is allocated,      *	and the following information is filled in:      *	the address of a routine to close the current frame for unwinding,      *	a pointer to the display entry for the current static level and      *	the previous contents of the display for this static level.      *	the curfile location is used to point to the currently active file,      *	and is filled in as io is initiated.      *	one of these structures is allocated on the (negatively growing) stack.      *	at function entry, fp is set to point to the last field of the struct,      *	thus the offsets of the fields are as indicated below.      */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_struct
struct|struct
name|rtlocals
block|{
name|jmp_buf
name|gotoenv
decl_stmt|;
name|struct
name|iorec
modifier|*
name|curfile
decl_stmt|;
name|struct
name|dispsave
name|dsave
decl_stmt|;
block|}
name|rtlocs
struct|;
end_struct

begin_endif
endif|#
directive|endif
endif|vax
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|tahoe
end_ifdef

begin_struct
struct|struct
name|rtlocals
block|{
name|jmp_buf
name|gotoenv
decl_stmt|;
name|struct
name|iorec
modifier|*
name|curfile
decl_stmt|;
name|struct
name|dispsave
name|dsave
decl_stmt|;
name|long
name|savedregs
index|[
literal|9
index|]
decl_stmt|;
block|}
name|rtlocs
struct|;
end_struct

begin_endif
endif|#
directive|endif
endif|tahoe
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mc68000
end_ifdef

begin_struct
struct|struct
name|rtlocals
block|{
name|jmp_buf
name|gotoenv
decl_stmt|;
name|struct
name|iorec
modifier|*
name|curfile
decl_stmt|;
name|struct
name|dispsave
name|dsave
decl_stmt|;
block|}
name|rtlocs
struct|;
end_struct

begin_endif
endif|#
directive|endif
endif|mc68000
end_endif

begin_define
define|#
directive|define
name|GOTOENVOFFSET
value|( -sizeof rtlocs )
end_define

begin_define
define|#
directive|define
name|CURFILEOFFSET
value|( GOTOENVOFFSET + sizeof rtlocs.gotoenv )
end_define

begin_define
define|#
directive|define
name|DSAVEOFFSET
value|( CURFILEOFFSET + sizeof rtlocs.curfile )
end_define

begin_comment
comment|/*      *	this is a cookie used to communicate between the      *	routine entry code and the routine exit code.      *	mostly it's for labels shared between the two.      */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_struct
struct|struct
name|entry_exit_cookie
block|{
name|struct
name|nl
modifier|*
name|nlp
decl_stmt|;
name|char
name|extname
index|[
name|BUFSIZ
index|]
decl_stmt|;
name|int
name|toplabel
decl_stmt|;
name|int
name|savlabel
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FRAME_SIZE_LABEL
value|"LF"
end_define

begin_define
define|#
directive|define
name|SAVE_MASK_LABEL
value|"L"
end_define

begin_endif
endif|#
directive|endif
endif|vax
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|tahoe
end_ifdef

begin_struct
struct|struct
name|entry_exit_cookie
block|{
name|struct
name|nl
modifier|*
name|nlp
decl_stmt|;
name|char
name|extname
index|[
name|BUFSIZ
index|]
decl_stmt|;
name|int
name|toplabel
decl_stmt|;
name|int
name|savlabel
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FRAME_SIZE_LABEL
value|"LF"
end_define

begin_define
define|#
directive|define
name|SAVE_MASK_LABEL
value|"L"
end_define

begin_endif
endif|#
directive|endif
endif|tahoe
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mc68000
end_ifdef

begin_struct
struct|struct
name|entry_exit_cookie
block|{
name|struct
name|nl
modifier|*
name|nlp
decl_stmt|;
name|char
name|extname
index|[
name|BUFSIZ
index|]
decl_stmt|;
name|int
name|toplabel
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FRAME_SIZE_LABEL
value|"LF"
end_define

begin_define
define|#
directive|define
name|PAGE_BREAK_LABEL
value|"LP"
end_define

begin_define
define|#
directive|define
name|SAVE_MASK_LABEL
value|"LS"
end_define

begin_endif
endif|#
directive|endif
endif|mc68000
end_endif

begin_comment
comment|/*      *	formats for various names      *	    NAMEFORMAT		arbitrary length strings.      *	    EXTFORMAT		for externals, a preceding underscore.      *	    LABELFORMAT		for label names, a preceding dollar-sign.      *	    PREFIXFORMAT	used to print made up names with prefixes.      *	    LABELPREFIX		with getlab() makes up label names.      *	    LLABELPREFIX	with getlab() makes up sdb labels.      *	    FORMALPREFIX	prefix for EXTFORMAT for formal entry points.      *	a typical use might be to print out a name with a preceeding underscore      *	with putprintf( EXTFORMAT , 0 , name );      */
end_comment

begin_define
define|#
directive|define
name|NAMEFORMAT
value|"%s"
end_define

begin_define
define|#
directive|define
name|EXTFORMAT
value|"_%s"
end_define

begin_define
define|#
directive|define
name|LABELFORMAT
value|"$%s"
end_define

begin_define
define|#
directive|define
name|PREFIXFORMAT
value|"%s%d"
end_define

begin_define
define|#
directive|define
name|LABELPREFIX
value|"L"
end_define

begin_define
define|#
directive|define
name|LLABELPREFIX
value|"LL"
end_define

begin_define
define|#
directive|define
name|FORMALPREFIX
value|"__"
end_define

begin_comment
comment|/*      *	the name of the statement counter      */
end_comment

begin_define
define|#
directive|define
name|STMTCOUNT
value|"__stcnt"
end_define

begin_comment
comment|/*      *	the name of the pcp counters      */
end_comment

begin_define
define|#
directive|define
name|PCPCOUNT
value|"__pcpcount"
end_define

begin_comment
comment|/*      *	a vector of pointer to enclosing functions for fully qualified names.      */
end_comment

begin_decl_stmt
name|char
modifier|*
name|enclosing
index|[
name|DSPLYSZ
index|]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_comment
comment|/*      *	the runtime framepointer and argumentpointer registers      */
end_comment

begin_define
define|#
directive|define
name|P2FP
value|13
end_define

begin_define
define|#
directive|define
name|P2FPNAME
value|"fp"
end_define

begin_define
define|#
directive|define
name|P2AP
value|12
end_define

begin_define
define|#
directive|define
name|P2APNAME
value|"ap"
end_define

begin_comment
comment|/*      *	the register save mask for saving no registers      */
end_comment

begin_define
define|#
directive|define
name|RSAVEMASK
value|( 0 )
end_define

begin_comment
comment|/*      *	runtime check mask for divide check and integer overflow      */
end_comment

begin_define
define|#
directive|define
name|RUNCHECK
value|( ( 1<< 15 ) | ( 1<< 14 ) )
end_define

begin_comment
comment|/*      *	and of course ...      */
end_comment

begin_define
define|#
directive|define
name|BITSPERBYTE
value|8
end_define

begin_endif
endif|#
directive|endif
endif|vax
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|tahoe
end_ifdef

begin_comment
comment|/*      *	the runtime framepointer and argumentpointer registers      */
end_comment

begin_define
define|#
directive|define
name|P2FP
value|13
end_define

begin_define
define|#
directive|define
name|P2FPNAME
value|"fp"
end_define

begin_define
define|#
directive|define
name|P2AP
value|13
end_define

begin_define
define|#
directive|define
name|P2APNAME
value|"fp"
end_define

begin_comment
comment|/*      *	the register save mask for saving no registers      */
end_comment

begin_define
define|#
directive|define
name|RSAVEMASK
value|( 0 )
end_define

begin_comment
comment|/*      *	divide check and integer overflow don't exist in the save mask      */
end_comment

begin_define
define|#
directive|define
name|RUNCHECK
value|( 0 )
end_define

begin_comment
comment|/*      *	and of course ...      */
end_comment

begin_define
define|#
directive|define
name|BITSPERBYTE
value|8
end_define

begin_endif
endif|#
directive|endif
endif|tahoe
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mc68000
end_ifdef

begin_comment
comment|/*      *	these magic numbers lifted from pcc/mac2defs      *	the offsets are for mapping data and address register numbers      *	to linear register numbers.  e.g. d2 ==> r2, and a2 ==> r10.      */
end_comment

begin_define
define|#
directive|define
name|DATA_REG_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|ADDR_REG_OFFSET
value|8
end_define

begin_define
define|#
directive|define
name|P2FPNAME
value|"a6"
end_define

begin_define
define|#
directive|define
name|P2FP
value|(ADDR_REG_OFFSET + 6)
end_define

begin_define
define|#
directive|define
name|P2APNAME
value|"a6"
end_define

begin_define
define|#
directive|define
name|P2AP
value|(ADDR_REG_OFFSET + 6)
end_define

begin_comment
comment|/*      *	and still ...      */
end_comment

begin_define
define|#
directive|define
name|BITSPERBYTE
value|8
end_define

begin_endif
endif|#
directive|endif
endif|mc68000
end_endif

end_unit

