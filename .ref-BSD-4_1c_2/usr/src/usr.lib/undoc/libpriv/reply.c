begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)reply.c	4.1	(Melbourne)	82/01/04	*/
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/mu_msg.h>
end_include

begin_macro
name|reply
argument_list|(
argument|mp
argument_list|,
argument|opt
argument_list|)
end_macro

begin_block
block|{
return|return
operator|(
name|mu_msg
argument_list|(
name|MSG_RPLY
argument_list|,
name|opt
argument_list|,
name|mp
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

