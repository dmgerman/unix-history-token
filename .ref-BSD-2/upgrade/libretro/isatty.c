begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_comment
comment|/* is unit c a tty? */
end_comment

begin_macro
name|isatty
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|int
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|sgttyb
name|tty
decl_stmt|;
return|return
operator|(
name|gtty
argument_list|(
name|c
argument_list|,
operator|&
name|tty
argument_list|)
operator|==
literal|0
operator|)
return|;
block|}
end_block

end_unit

