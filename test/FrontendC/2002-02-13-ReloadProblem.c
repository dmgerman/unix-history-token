begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_comment
comment|/* This triggered a problem in reload, fixed by disabling most of the   * steps of compilation in GCC.  Before this change, the code went through  * the entire backend of GCC, even though it was unnecessary for LLVM output  * now it is skipped entirely, and since reload doesn't run, it can't cause  * a problem.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|tolower
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|const
name|char
modifier|*
name|rangematch
parameter_list|(
specifier|const
name|char
modifier|*
name|pattern
parameter_list|,
name|int
name|test
parameter_list|,
name|int
name|c
parameter_list|)
block|{
if|if
condition|(
operator|(
name|c
operator|<=
name|test
operator|)
operator||
operator|(
name|tolower
argument_list|(
name|c
argument_list|)
operator|<=
name|tolower
argument_list|(
operator|(
name|unsigned
name|char
operator|)
name|test
argument_list|)
operator|)
condition|)
return|return
literal|0
return|;
return|return
name|pattern
return|;
block|}
end_function

end_unit

