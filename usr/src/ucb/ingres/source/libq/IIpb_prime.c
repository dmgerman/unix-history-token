begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<pipes.h>
end_include

begin_include
include|#
directive|include
file|<symbol.h>
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)IIpb_prime.c
literal|7.2
literal|2
argument|/
literal|16
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  IIPB_PRIME -- prime a pipe for reading or writing ** **	This clears out any nasty stuff in the pipe block.  If **	we are reading, it reads the first block so that we can **	know what sort it is. ** **	Parameters: **		ppb -- a pointer to the pipe block. **		type -- if PB_NOTYPE, we are setting for reading. **			Otherwise, we are setting to write a **			message of the indicated type. ** **	Returns: **		none ** **	Side Effects: **		Changes *ppb. ** **	Trace Flags: **		12.0 */
end_comment

begin_expr_stmt
name|IIpb_prime
argument_list|(
name|ppb
argument_list|,
name|type
argument_list|)
specifier|register
name|pb_t
operator|*
name|ppb
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|type
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|type
operator|==
name|PB_NOTYPE
condition|)
block|{
comment|/* read pipe prime -- get the first block */
name|IIpb_read
argument_list|(
name|ppb
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* write pipe prime -- set up initial pointers */
name|ppb
operator|->
name|pb_from
operator|=
name|ppb
operator|->
name|pb_resp
operator|=
name|PB_FRONT
expr_stmt|;
name|ppb
operator|->
name|pb_type
operator|=
name|type
expr_stmt|;
name|ppb
operator|->
name|pb_stat
operator|=
literal|0
expr_stmt|;
name|ppb
operator|->
name|pb_nleft
operator|=
name|PB_DBSIZE
expr_stmt|;
name|ppb
operator|->
name|pb_nused
operator|=
literal|0
expr_stmt|;
name|ppb
operator|->
name|pb_st
operator|=
name|mdPARSER
expr_stmt|;
block|}
comment|/* do common initialization */
name|ppb
operator|->
name|pb_xptr
operator|=
name|ppb
operator|->
name|pb_data
expr_stmt|;
block|}
end_block

end_unit

