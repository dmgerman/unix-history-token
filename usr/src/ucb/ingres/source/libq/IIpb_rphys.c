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
argument|@(#)IIpb_rphys.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  IIPB_RPHYS -- physical read on pipe ** **	Parameters: **		ppb -- a pointer to the data area. **		fd -- the file descriptor. ** **	Returns: **		none ** **	Side Effects: **		none ** **	Trace Flags: **		none */
end_comment

begin_expr_stmt
name|IIpb_rphys
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
return|return
operator|(
name|read
argument_list|(
name|fd
argument_list|,
name|ppb
argument_list|,
name|PB_IOSIZE
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

