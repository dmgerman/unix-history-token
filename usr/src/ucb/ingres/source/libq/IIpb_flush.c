begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<pipes.h>
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)IIpb_flush.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  IIPB_FLUSH -- flush a pipe buffer ** **	This routine insures that all the data in a pipe buffer **	is flushed out to the pipe. ** **	We also handle input switching in this routine.  If the **	message we are writing is not merely informational (such **	as an error message, or some sort of meta message), we **	change the input to be whatever pipe the named process **	will write back on. ** **	Parameters: **		ppb -- a ptr to the pipe buffer to flush. ** **	Returns: **		none ** **	Side Effects: **		none ** **	Trace Flags: **		none */
end_comment

begin_expr_stmt
name|IIpb_flush
argument_list|(
name|ppb
argument_list|)
specifier|register
name|pb_t
operator|*
name|ppb
expr_stmt|;
end_expr_stmt

begin_block
block|{
comment|/* mark this as an EOF block and flush the buffer */
name|ppb
operator|->
name|pb_stat
operator||=
name|PB_EOF
expr_stmt|;
name|IIpb_write
argument_list|(
name|ppb
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

