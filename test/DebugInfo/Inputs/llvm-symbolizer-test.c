begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function
name|int
name|f
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
return|return
name|a
operator|+
name|b
return|;
block|}
end_function

begin_function
name|int
name|g
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
name|a
operator|+
literal|1
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
return|return
name|f
argument_list|(
literal|2
argument_list|,
name|g
argument_list|(
literal|2
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Built with Clang 3.3:
end_comment

begin_comment
comment|// $ mkdir -p /tmp/dbginfo
end_comment

begin_comment
comment|// $ cp llvm-symbolizer-test.c /tmp/dbginfo
end_comment

begin_comment
comment|// $ cd /tmp/dbginfo
end_comment

begin_comment
comment|// $ clang -g llvm-symbolizer-test.c -o<output>
end_comment

end_unit

