begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -W -Wall -Werror -verify %s
end_comment

begin_decl_stmt
name|int
name|f
argument_list|(
name|int
name|i
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
argument_list|)
block|{
return|return
literal|0
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|int
name|g
argument_list|(
name|i
argument_list|)
name|int
name|i
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
literal|0
return|;
block|}
end_block

end_unit

