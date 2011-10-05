begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_include
include|#
directive|include
file|<popper.h>
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  *  rset:   Unflag all messages flagged for deletion in a POP maildrop  */
end_comment

begin_function
name|int
name|pop_rset
parameter_list|(
name|POP
modifier|*
name|p
parameter_list|)
block|{
name|MsgInfoList
modifier|*
name|mp
decl_stmt|;
comment|/*  Pointer to the message info list */
name|int
name|i
decl_stmt|;
comment|/*  Unmark all the messages */
for|for
control|(
name|i
operator|=
name|p
operator|->
name|msg_count
operator|,
name|mp
operator|=
name|p
operator|->
name|mlp
init|;
name|i
operator|>
literal|0
condition|;
name|i
operator|--
operator|,
name|mp
operator|++
control|)
name|mp
operator|->
name|flags
operator|&=
operator|~
name|DEL_FLAG
expr_stmt|;
comment|/*  Reset the messages-deleted and bytes-deleted counters */
name|p
operator|->
name|msgs_deleted
operator|=
literal|0
expr_stmt|;
name|p
operator|->
name|bytes_deleted
operator|=
literal|0
expr_stmt|;
comment|/*  Reset the last-message-access flag */
name|p
operator|->
name|last_msg
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|pop_msg
argument_list|(
name|p
argument_list|,
name|POP_SUCCESS
argument_list|,
literal|"Maildrop has %u messages (%ld octets)"
argument_list|,
name|p
operator|->
name|msg_count
argument_list|,
name|p
operator|->
name|drop_size
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

