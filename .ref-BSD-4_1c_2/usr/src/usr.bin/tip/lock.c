begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	lock.c	4.3	81/11/29	*/
end_comment

begin_include
include|#
directive|include
file|"tip.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ACULOG
end_ifdef

begin_comment
comment|/*  * Locking mechanism for files  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|fd
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_macro
name|lock
argument_list|(
argument|f
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|f
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|timeout
init|=
literal|0
decl_stmt|;
while|while
condition|(
operator|(
name|fd
operator|=
name|creat
argument_list|(
name|f
argument_list|,
literal|0444
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
if|if
condition|(
operator|++
name|timeout
operator|==
literal|6
condition|)
break|break;
name|sleep
argument_list|(
literal|5
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|timeout
operator|==
literal|6
operator|&&
name|fd
operator|>=
literal|0
condition|)
name|unlock
argument_list|()
expr_stmt|;
else|else
name|unlink
argument_list|(
name|f
argument_list|)
expr_stmt|;
return|return
operator|(
name|fd
operator|>=
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|unlock
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|fd
operator|!=
operator|-
literal|1
condition|)
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|fd
operator|=
operator|-
literal|1
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

