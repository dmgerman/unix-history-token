begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_comment
comment|// Don't crash on a common-linkage constant global.
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|kABSourceTypeProperty
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|kABSourceTypeProperty
return|;
block|}
end_function

begin_decl_stmt
specifier|const
name|int
name|kABSourceTypeProperty
decl_stmt|;
end_decl_stmt

end_unit

