begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_comment
comment|/* Testcase for a problem where GCC allocated xqic to a register,  * and did not have a VAR_DECL that explained the stack slot to LLVM.  * Now the LLVM code synthesizes a stack slot if one is presented that  * has not been previously recognized.  This is where alloca's named   * 'local' come from now.   */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|x
decl_stmt|;
block|}
name|foostruct
typedef|;
end_typedef

begin_function_decl
name|int
name|foo
parameter_list|(
name|foostruct
name|ic
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test
parameter_list|()
block|{
name|foostruct
name|xqic
decl_stmt|;
name|foo
argument_list|(
name|xqic
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

