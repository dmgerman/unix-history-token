begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"ctlmod.h"
end_include

begin_include
include|#
directive|include
file|"pipes.h"
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)readmon.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  READMON -- Read bytes from tty monitor ** **	This routine is a cludge.  It will exist only in version **	6.3 with split monitor/parser.  The purpose is to get **	around the problem caused by the monitor not outputting **	text in one of the basic internal data types.  What it **	can do is to output no parameters& terminate with a **	PV_EOF.  This doesn't flush the pipe, so it can continue **	with plain text.  This routine retrieves that text. **	The name "readmon" is somewhat of a misnomer -- it is **	not restricted to the monitor,& does not necessarily **	read from the monitor; but this routine should only **	be called from the parser on the monitor pipe. ** **	Parameters: **		buf -- a buffer to read into. **		nbytes -- the max number of bytes to read. ** **	Returns: **		The actual number of bytes read. **		zero on eof. ** **	Side Effects: **		none. ** **	NOTE: **		When this routine is eliminated, so should the **		'cm_monppb' field of the Cm struct and the code **		in proc_err to flush the monitor input pipe. ** **	Trace Flags: **		none. */
end_comment

begin_decl_stmt
name|pb_t
modifier|*
name|MonPpb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to ppb for monitor */
end_comment

begin_macro
name|readmon
argument_list|(
argument|buf
argument_list|,
argument|nbytes
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|buf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nbytes
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|Cm
operator|.
name|cm_input
operator|=
name|Cm
operator|.
name|cm_rinput
expr_stmt|;
return|return
operator|(
name|pb_get
argument_list|(
name|MonPpb
argument_list|,
name|buf
argument_list|,
name|nbytes
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

