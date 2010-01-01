begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -fblocks -fsyntax-only -Wunused-parameter %s -Xclang -verify
end_comment

begin_decl_stmt
name|int
name|f0
argument_list|(
name|int
name|x
argument_list|,
name|int
name|y
argument_list|,
comment|// expected-warning{{unused}}
name|int
name|z
name|__attribute__
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
argument_list|)
block|{
return|return
name|x
return|;
block|}
end_decl_stmt

begin_function
name|void
name|f1
parameter_list|()
block|{
operator|(
name|void
operator|)
lambda|^
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
comment|// expected-warning{{unused}}
name|int
name|z
name|__attribute__
lambda|(
parameter_list|(
name|unused
parameter_list|)
block|)
end_function

begin_block
unit|)
block|{
return|return
name|x
return|;
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

unit|}
end_unit

