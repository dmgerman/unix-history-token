begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_comment
comment|/* static	char sccsid[] = "@(#)pc.h 1.2 10/14/80"; */
end_comment

begin_comment
comment|/*      *		random constants for pc      */
end_comment

begin_comment
comment|/*      *	the name of the display.      *	the display is made up of saved AP's and FP's.      *	FP's are used to find locals, and AP's are used to find parameters.      *	FP and AP are untyped pointers, but are used throughout as (char *).      *	the display is used by adding AP_OFFSET or FP_OFFSET to the       *	address of the approriate display entry.      */
end_comment

begin_define
define|#
directive|define
name|DISPLAYNAME
value|"__disply"
end_define

begin_struct
struct|struct
name|dispsave
block|{
name|char
modifier|*
name|savedAP
decl_stmt|;
name|char
modifier|*
name|savedFP
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AP_OFFSET
value|( 0 )
end_define

begin_define
define|#
directive|define
name|FP_OFFSET
value|( sizeof(char *) )
end_define

begin_comment
comment|/*      *	the structure below describes the locals used by the run time system.      *	at function entry, at least this much space is allocated,      *	and the following information is filled in:      *	the address of a routine to close the current frame for unwinding,      *	a pointer to the display entry for the current static level and      *	the previous contents of the display for this static level.      *	the curfile location is used to point to the currently active file,      *	and is filled in as io is initiated.      *	one of these structures is allocated on the (negatively growing) stack.      *	at function entry, fp is set to point to the last field of the struct,      *	thus the offsets of the fields are as indicated below.      */
end_comment

begin_struct
struct|struct
name|rtlocals
block|{
name|struct
name|iorec
modifier|*
name|curfile
decl_stmt|;
name|struct
name|dispsave
name|dsave
decl_stmt|;
name|struct
name|dispsave
modifier|*
name|dptr
decl_stmt|;
name|int
function_decl|(
modifier|*
name|unwind
function_decl|)
parameter_list|()
function_decl|;
block|}
name|rtlocs
struct|;
end_struct

begin_define
define|#
directive|define
name|CURFILEOFFSET
value|( ( -sizeof rtlocs ) + sizeof rtlocs.unwind )
end_define

begin_define
define|#
directive|define
name|DSAVEOFFSET
value|( CURFILEOFFSET + sizeof rtlocs.curfile )
end_define

begin_define
define|#
directive|define
name|DPTROFFSET
value|( DSAVEOFFSET + sizeof rtlocs.dsave )
end_define

begin_define
define|#
directive|define
name|UNWINDOFFSET
value|( DPTROFFSET + sizeof rtlocs.dptr )
end_define

begin_define
define|#
directive|define
name|UNWINDNAME
value|"_UNWIND"
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
comment|/*      *	formats for various names      *	    NAMEFORMAT		arbitrary length strings.      *	    EXTFORMAT		for externals, a preceding underscore.      *	    PREFIXFORMAT	used to print made up names with prefixes.      *	    LABELPREFIX		with getlab() makes up label names.      *	    LLABELPREFIX	with getlab() makes up sdb labels.      *	a typical use might be to print out a name with a preceeding underscore      *	with putprintf( EXTFORMAT , 0 , name );      */
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

begin_comment
comment|/*      *	and of course ...      */
end_comment

begin_define
define|#
directive|define
name|BITSPERBYTE
value|8
end_define

begin_comment
comment|/*      *	error number for case label not found (ECASE)      *	stolen from ~mckusick/px/lib/h01errs.h      */
end_comment

begin_define
define|#
directive|define
name|ECASE
value|5
end_define

end_unit

