begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<useful.h>
end_include

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
argument|@(#)IIpb_put.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  IIPB_PUT -- buffered put on pipe ** **	This routine puts the named data out onto the pipe **	determined by ppb->pb_proc. ** **	Parameters: **		dp -- a pointer to the data to write. **		len -- the length of the data to write. **		ppb -- a pointer to the pipe block. ** **	Returns: **		none ** **	Side Effects: **		none ** **	Trace Flags: **		18.8 - 18.15 */
end_comment

begin_expr_stmt
name|IIpb_put
argument_list|(
name|dp
argument_list|,
name|len
argument_list|,
name|ppb
argument_list|)
specifier|register
name|char
operator|*
name|dp
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|int
name|len
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|pb_t
modifier|*
name|ppb
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
comment|/* 	**  Top loop. 	**	Loop until we have run out of things to write. 	*/
while|while
condition|(
name|len
operator|>
literal|0
condition|)
block|{
comment|/* compute the length to move */
name|i
operator|=
name|min
argument_list|(
name|ppb
operator|->
name|pb_nleft
argument_list|,
name|len
argument_list|)
expr_stmt|;
comment|/* move data into buffer and adjust ptrs& counts */
name|IIbmove
argument_list|(
name|dp
argument_list|,
name|ppb
operator|->
name|pb_xptr
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|dp
operator|+=
name|i
expr_stmt|;
name|len
operator|-=
name|i
expr_stmt|;
name|ppb
operator|->
name|pb_xptr
operator|+=
name|i
expr_stmt|;
name|ppb
operator|->
name|pb_nleft
operator|-=
name|i
expr_stmt|;
name|ppb
operator|->
name|pb_nused
operator|+=
name|i
expr_stmt|;
comment|/* flush block if full */
if|if
condition|(
name|ppb
operator|->
name|pb_nleft
operator|<=
literal|0
condition|)
name|IIpb_write
argument_list|(
name|ppb
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

