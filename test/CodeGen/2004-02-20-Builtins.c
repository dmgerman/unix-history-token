begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1  %s -emit-llvm -o - | not grep builtin
end_comment

begin_function_decl
name|double
name|sqrt
parameter_list|(
name|double
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|zsqrtxxx
parameter_list|(
name|float
name|num
parameter_list|)
block|{
name|num
operator|=
name|sqrt
argument_list|(
name|num
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

