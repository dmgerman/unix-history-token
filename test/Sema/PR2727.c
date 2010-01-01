begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -fsyntax-only -std=c90 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -verify -fsyntax-only -std=c99 %s
end_comment

begin_function
name|int
name|f
parameter_list|(
name|int
name|x
parameter_list|)
block|{
comment|// sizeof applied to a type should not delete the type.
return|return
sizeof|sizeof
argument_list|(
name|int
index|[
name|x
index|]
argument_list|)
return|;
block|}
end_function

end_unit

