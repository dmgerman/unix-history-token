begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	gtty.c	4.1	83/07/04	*/
end_comment

begin_comment
comment|/*  * Writearound to old gtty system call.  */
end_comment

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_macro
name|gtty
argument_list|(
argument|fd
argument_list|,
argument|ap
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|sgtty
modifier|*
name|ap
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|TIOCGETP
argument_list|,
name|ap
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

