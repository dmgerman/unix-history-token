begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * A subroutine version of the macro getchar.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_undef
undef|#
directive|undef
name|getchar
end_undef

begin_macro
name|getchar
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
name|getc
argument_list|(
name|stdin
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

