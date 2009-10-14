begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_function
name|int
name|foo
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|__ppc__
specifier|register
name|int
name|X
name|__asm__
argument_list|(
literal|"r1"
argument_list|)
decl_stmt|;
else|#
directive|else
specifier|register
name|int
name|X
name|__asm__
argument_list|(
literal|"ebx"
argument_list|)
decl_stmt|;
endif|#
directive|endif
return|return
name|X
return|;
block|}
end_function

end_unit

