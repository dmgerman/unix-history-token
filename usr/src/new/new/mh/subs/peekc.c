begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_macro
name|peekc
argument_list|(
argument|ib
argument_list|)
end_macro

begin_decl_stmt
name|FILE
modifier|*
name|ib
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|c
expr_stmt|;
name|c
operator|=
name|getc
argument_list|(
name|ib
argument_list|)
expr_stmt|;
name|ungetc
argument_list|(
name|c
argument_list|,
name|ib
argument_list|)
expr_stmt|;
return|return
operator|(
name|c
operator|)
return|;
block|}
end_block

end_unit

