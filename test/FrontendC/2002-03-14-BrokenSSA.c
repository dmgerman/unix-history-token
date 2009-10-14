begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_comment
comment|/* This code used to break GCC's SSA computation code.  It would create    uses of B& C that are not dominated by their definitions.  See:    http://gcc.gnu.org/ml/gcc/2002-03/msg00697.html  */
end_comment

begin_function_decl
name|int
name|bar
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|foo
parameter_list|()
block|{
name|int
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|;
name|a
operator|=
name|b
operator|+
name|c
expr_stmt|;
name|b
operator|=
name|bar
argument_list|()
expr_stmt|;
name|c
operator|=
name|bar
argument_list|()
expr_stmt|;
return|return
name|a
operator|+
name|b
operator|+
name|c
return|;
block|}
end_function

end_unit

