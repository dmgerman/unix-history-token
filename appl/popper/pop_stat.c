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
comment|/*  *  stat:   Display the status of a POP maildrop to its client  */
end_comment

begin_function
name|int
name|pop_stat
parameter_list|(
name|POP
modifier|*
name|p
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|p
operator|->
name|debug
condition|)
name|pop_log
argument_list|(
name|p
argument_list|,
name|POP_DEBUG
argument_list|,
literal|"%d message(s) (%ld octets)."
argument_list|,
name|p
operator|->
name|msg_count
operator|-
name|p
operator|->
name|msgs_deleted
argument_list|,
name|p
operator|->
name|drop_size
operator|-
name|p
operator|->
name|bytes_deleted
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DEBUG */
return|return
operator|(
name|pop_msg
argument_list|(
name|p
argument_list|,
name|POP_SUCCESS
argument_list|,
literal|"%d %ld"
argument_list|,
name|p
operator|->
name|msg_count
operator|-
name|p
operator|->
name|msgs_deleted
argument_list|,
name|p
operator|->
name|drop_size
operator|-
name|p
operator|->
name|bytes_deleted
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

