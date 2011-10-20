begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -std=gnu99 %s -emit-llvm -o - | grep ".*alloca.*align 16"
end_comment

begin_function_decl
specifier|extern
name|void
name|bar
parameter_list|(
name|int
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|foo
parameter_list|(
name|int
name|a
parameter_list|)
block|{
name|int
name|var
index|[
name|a
index|]
name|__attribute__
argument_list|(
operator|(
name|__aligned__
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
decl_stmt|;
name|bar
argument_list|(
name|var
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

end_unit

