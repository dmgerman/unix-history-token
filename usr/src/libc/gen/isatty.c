begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Returns 1 iff file is a tty  */
end_comment

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_macro
name|isatty
argument_list|(
argument|f
argument_list|)
end_macro

begin_block
block|{
name|struct
name|sgttyb
name|ttyb
decl_stmt|;
if|if
condition|(
name|gtty
argument_list|(
name|f
argument_list|,
operator|&
name|ttyb
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

end_unit

