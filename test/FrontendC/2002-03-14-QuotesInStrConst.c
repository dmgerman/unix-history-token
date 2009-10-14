begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_comment
comment|/* GCC was not escaping quotes in string constants correctly, so this would  * get emitted:  *  %.LC1 = internal global [32 x sbyte] c"*** Word "%s" on line %d is not\00"  */
end_comment

begin_function
specifier|const
name|char
modifier|*
name|Foo
parameter_list|()
block|{
return|return
literal|"*** Word \"%s\" on line %d is not"
return|;
block|}
end_function

end_unit

