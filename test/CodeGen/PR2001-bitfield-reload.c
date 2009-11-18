begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -triple i386-unknown-unknown --emit-llvm-bc -o - %s | opt --std-compile-opts | llvm-dis> %t
end_comment

begin_comment
comment|// RUN: grep "ret i32" %t | count 1
end_comment

begin_comment
comment|// RUN: grep "ret i32 1" %t | count 1
end_comment

begin_comment
comment|// PR2001
end_comment

begin_comment
comment|/* Test that the result of the assignment properly uses the value *in    the bitfield* as opposed to the RHS. */
end_comment

begin_function
specifier|static
name|int
name|foo
parameter_list|(
name|int
name|i
parameter_list|)
block|{
struct|struct
block|{
name|int
name|f0
range|:
literal|2
decl_stmt|;
block|}
name|x
struct|;
return|return
operator|(
name|x
operator|.
name|f0
operator|=
name|i
operator|)
return|;
block|}
end_function

begin_function
name|int
name|bar
parameter_list|()
block|{
return|return
name|foo
argument_list|(
operator|-
literal|5
argument_list|)
operator|==
operator|-
literal|1
return|;
block|}
end_function

end_unit

