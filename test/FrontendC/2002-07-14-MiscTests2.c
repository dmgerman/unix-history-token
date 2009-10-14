begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_comment
comment|// Test ?: in function calls
end_comment

begin_extern
extern|extern fp(int
operator|,
extern|char*
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|char
modifier|*
name|Ext
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|__bb_exit_func
parameter_list|(
name|void
parameter_list|)
block|{
name|fp
argument_list|(
literal|12
argument_list|,
name|Ext
condition|?
name|Ext
else|:
literal|"<none>"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

