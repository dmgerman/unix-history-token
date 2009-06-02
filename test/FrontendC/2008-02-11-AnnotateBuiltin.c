begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -o - | llvm-as | llvm-dis | grep llvm.annotation
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
name|x
init|=
literal|0
decl_stmt|;
return|return
name|__builtin_annotation
argument_list|(
name|x
argument_list|,
literal|"annotate"
argument_list|)
return|;
block|}
end_function

end_unit

