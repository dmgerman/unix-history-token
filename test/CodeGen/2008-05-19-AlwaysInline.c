begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - | not grep sabrina
end_comment

begin_function_decl
specifier|static
specifier|inline
name|int
name|sabrina
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(always_inline
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
specifier|static
specifier|inline
name|int
name|sabrina
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|13
return|;
block|}
end_function

begin_function
name|int
name|bar
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|sabrina
argument_list|()
operator|+
literal|68
return|;
block|}
end_function

end_unit

