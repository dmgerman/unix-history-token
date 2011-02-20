begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | grep llvm.gcroot
end_comment

begin_comment
comment|// RUN: %llvmgcc -S %s -o - | grep llvm.gcroot | count 6
end_comment

begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as
end_comment

begin_typedef
typedef|typedef
struct|struct
name|foo_s
block|{
name|int
name|a
decl_stmt|;
block|}
name|foo
operator|,
name|__attribute__
typedef|((
name|gcroot
typedef|)) *
name|foo_p
typedef|;
end_typedef

begin_decl_stmt
name|foo
name|my_foo
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|alpha
parameter_list|()
block|{
name|foo
name|my_foo2
init|=
name|my_foo
decl_stmt|;
return|return
name|my_foo2
operator|.
name|a
return|;
block|}
end_function

begin_function
name|int
name|bar
parameter_list|(
name|foo
name|a
parameter_list|)
block|{
name|foo_p
name|b
decl_stmt|;
return|return
name|b
operator|->
name|a
return|;
block|}
end_function

begin_function
name|foo_p
name|baz
parameter_list|(
name|foo_p
name|a
parameter_list|,
name|foo_p
name|b
parameter_list|,
name|foo_p
modifier|*
name|c
parameter_list|)
block|{
name|a
operator|=
name|b
operator|=
operator|*
name|c
expr_stmt|;
return|return
name|a
return|;
block|}
end_function

end_unit

