begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_function_decl
name|void
modifier|*
name|dlclose
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|ap_os_dso_unload
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|)
block|{
name|dlclose
argument_list|(
name|handle
argument_list|)
expr_stmt|;
return|return;
comment|/* This return triggers the bug: Weird */
block|}
end_function

end_unit

