begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<ingres.h>
end_include

begin_include
include|#
directive|include
file|"IIglobals.h"
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)IIpb_read.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  IIPB_READ -- read a pipe block ** **	This routine reads a pipe block into *ppb.  It also handles **	all the low level protocol: RESET blocks, SYNC blocks, META **	blocks, blocks intended for another process, etc. ** **	When this routine returns, it returns with a block intended **	for this process, which must be a REGULAR block, a RESPONSE **	block, or an ERROR block. ** **	Parameters: **		ppb -- a pointer to the area which wants the block. ** **	Returns: **		none ** **	Side Effects: **		ppb is set to the named block. **		Virtually any amount of stuff can happen, depending **			on what is coming through the pipe. ** **	Trace Flags: **		12.4 - 12.9 */
end_comment

begin_expr_stmt
name|IIpb_read
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
specifier|register
name|int
name|type
decl_stmt|;
specifier|register
name|int
name|from
decl_stmt|;
comment|/* 	**  Top Loop. 	**	Hang waiting for a normal block.  Other blocks are 	**		handled inside the loop. 	**	We multiplex 'from' in here temporarily. 	*/
for|for
control|(
init|;
condition|;
control|)
block|{
name|from
operator|=
name|IIpb_rphys
argument_list|(
name|ppb
argument_list|,
name|IIinput
argument_list|)
expr_stmt|;
if|if
condition|(
name|from
operator|!=
name|PB_IOSIZE
condition|)
name|IIsyserr
argument_list|(
literal|"pb_read: read error (%d)"
argument_list|,
name|from
argument_list|)
expr_stmt|;
comment|/* set up buffer pointers, etc. */
name|ppb
operator|->
name|pb_xptr
operator|=
name|ppb
operator|->
name|pb_data
expr_stmt|;
name|ppb
operator|->
name|pb_nleft
operator|=
name|ppb
operator|->
name|pb_nused
expr_stmt|;
name|type
operator|=
name|ppb
operator|->
name|pb_type
expr_stmt|;
name|from
operator|=
name|ppb
operator|->
name|pb_from
expr_stmt|;
comment|/* do sync block processing */
if|if
condition|(
name|type
operator|==
name|PB_SYNC
condition|)
block|{
name|IISyncs
index|[
name|from
index|]
operator|--
expr_stmt|;
continue|continue;
block|}
comment|/* see if we are ignoring from this process */
if|if
condition|(
name|IISyncs
index|[
name|from
index|]
operator|>
literal|0
condition|)
continue|continue;
comment|/* 		**  Block type dispatching. 		**	Regular, response, and error blocks return. 		**	Meta blocks are handled by calling other 		**		routines. 		*/
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|PB_REG
case|:
case|case
name|PB_RESP
case|:
case|case
name|PB_ERR
case|:
comment|/* handled by readinput() */
return|return;
comment|/* insert more meta handling before this line */
default|default:
name|IIsyserr
argument_list|(
literal|"pb_read: type %d"
argument_list|,
name|type
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_block

end_unit

