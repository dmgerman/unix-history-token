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
argument|@(#)IIpb_wphys.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  PB_WPHYS -- physical write on pipe ** **	Parameters: **		ppb -- a pointer to the data area. **		fd -- the file descriptor. ** **	Returns: **		none ** **	Side Effects: **		none */
end_comment

begin_expr_stmt
name|IIpb_wphys
argument_list|(
name|ppb
argument_list|,
name|fd
argument_list|)
specifier|register
name|pb_t
operator|*
name|ppb
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|int
name|fd
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
name|i
operator|=
name|write
argument_list|(
name|fd
argument_list|,
name|ppb
argument_list|,
name|PB_IOSIZE
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|!=
name|PB_IOSIZE
condition|)
name|IIsyserr
argument_list|(
literal|"pb_wphys: write error"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

