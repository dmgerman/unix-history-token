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
argument|@(#)IIpb_write.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  IIPB_WRITE -- Write pipe block ** **	Writes the block specified by ppb down to the PARSER ** **	Parameters: **		ppb -- a ptr to the pipe block to write. ** **	Returns: **		none ** **	Side Effects: **		none */
end_comment

begin_expr_stmt
name|IIpb_write
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
name|i
decl_stmt|;
specifier|register
name|int
name|ofd
decl_stmt|;
comment|/* mark the block as coming from this process */
name|ppb
operator|->
name|pb_from
operator|=
name|PB_FRONT
expr_stmt|;
comment|/* normal message */
name|i
operator|=
name|ppb
operator|->
name|pb_proc
expr_stmt|;
name|IIpb_wphys
argument_list|(
name|ppb
argument_list|,
name|IIw_down
argument_list|)
expr_stmt|;
comment|/* reset some exciting pointers */
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
name|PB_DBSIZE
expr_stmt|;
name|ppb
operator|->
name|pb_nused
operator|=
literal|0
expr_stmt|;
block|}
end_block

end_unit

