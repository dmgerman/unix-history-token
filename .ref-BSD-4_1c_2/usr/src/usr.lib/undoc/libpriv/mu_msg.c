begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)mu_msg.c	4.1	(Melbourne)	82/01/04	*/
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
name|mu_msg
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|,
argument|c
argument_list|)
end_macro

begin_block
block|{
return|return
operator|(
name|syscall
argument_list|(
literal|64
operator|+
literal|62
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

