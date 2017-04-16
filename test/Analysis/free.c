begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-store=region -analyzer-checker=core,unix.Malloc -fblocks -verify %s
end_comment

begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-store=region -analyzer-checker=core,unix.Malloc -fblocks -verify -analyzer-config unix.Malloc:Optimistic=true %s
end_comment

begin_typedef
typedef|typedef
name|__typeof
argument_list|(
argument|sizeof(int)
argument_list|)
name|size_t
expr_stmt|;
end_typedef

begin_function_decl
name|void
name|free
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|alloca
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|t1
parameter_list|()
block|{
name|int
name|a
index|[]
init|=
block|{
literal|1
block|}
decl_stmt|;
name|free
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|// expected-warning {{Argument to free() is the address of the local variable 'a', which is not memory allocated by malloc()}}
block|}
end_function

begin_function
name|void
name|t2
parameter_list|()
block|{
name|int
name|a
init|=
literal|1
decl_stmt|;
name|free
argument_list|(
operator|&
name|a
argument_list|)
expr_stmt|;
comment|// expected-warning {{Argument to free() is the address of the local variable 'a', which is not memory allocated by malloc()}}
block|}
end_function

begin_function
name|void
name|t3
parameter_list|()
block|{
specifier|static
name|int
name|a
index|[]
init|=
block|{
literal|1
block|}
decl_stmt|;
name|free
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|// expected-warning {{Argument to free() is the address of the static variable 'a', which is not memory allocated by malloc()}}
block|}
end_function

begin_function
name|void
name|t4
parameter_list|(
name|char
modifier|*
name|x
parameter_list|)
block|{
name|free
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|t5
parameter_list|()
block|{
specifier|extern
name|char
modifier|*
name|ptr
parameter_list|()
function_decl|;
name|free
argument_list|(
name|ptr
argument_list|()
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|t6
parameter_list|()
block|{
name|free
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|1000
argument_list|)
expr_stmt|;
comment|// expected-warning {{Argument to free() is a constant address (1000), which is not memory allocated by malloc()}}
block|}
end_function

begin_function
name|void
name|t7
parameter_list|(
name|char
modifier|*
modifier|*
name|x
parameter_list|)
block|{
name|free
argument_list|(
operator|*
name|x
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|t8
parameter_list|(
name|char
modifier|*
modifier|*
name|x
parameter_list|)
block|{
comment|// ugh
name|free
argument_list|(
operator|(
operator|*
name|x
operator|)
operator|+
literal|8
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|t9
parameter_list|()
block|{
name|label
label|:
name|free
argument_list|(
operator|&&
name|label
argument_list|)
expr_stmt|;
comment|// expected-warning {{Argument to free() is the address of the label 'label', which is not memory allocated by malloc()}}
block|}
end_function

begin_function
name|void
name|t10
parameter_list|()
block|{
name|free
argument_list|(
operator|(
name|void
operator|*
operator|)
operator|&
name|t10
argument_list|)
expr_stmt|;
comment|// expected-warning {{Argument to free() is the address of the function 't10', which is not memory allocated by malloc()}}
block|}
end_function

begin_function
name|void
name|t11
parameter_list|()
block|{
name|char
modifier|*
name|p
init|=
operator|(
name|char
operator|*
operator|)
name|alloca
argument_list|(
literal|2
argument_list|)
decl_stmt|;
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning {{Memory allocated by alloca() should not be deallocated}}
block|}
end_function

begin_function
name|void
name|t12
parameter_list|()
block|{
name|char
modifier|*
name|p
init|=
operator|(
name|char
operator|*
operator|)
name|__builtin_alloca
argument_list|(
literal|2
argument_list|)
decl_stmt|;
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning {{Memory allocated by alloca() should not be deallocated}}
block|}
end_function

begin_function
name|void
name|t13
parameter_list|()
block|{
name|free
argument_list|(
lambda|^
block|{
return|return;
block|}
argument_list|)
expr_stmt|;
comment|// expected-warning {{Argument to free() is a block, which is not memory allocated by malloc()}}
block|}
end_function

begin_function
name|void
name|t14
parameter_list|(
name|char
name|a
parameter_list|)
block|{
name|free
argument_list|(
operator|&
name|a
argument_list|)
expr_stmt|;
comment|// expected-warning {{Argument to free() is the address of the parameter 'a', which is not memory allocated by malloc()}}
block|}
end_function

begin_decl_stmt
specifier|static
name|int
name|someGlobal
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|t15
parameter_list|()
block|{
name|free
argument_list|(
name|someGlobal
argument_list|)
expr_stmt|;
comment|// expected-warning {{Argument to free() is the address of the global variable 'someGlobal', which is not memory allocated by malloc()}}
block|}
end_function

begin_function
name|void
name|t16
parameter_list|(
name|char
modifier|*
modifier|*
name|x
parameter_list|,
name|int
name|offset
parameter_list|)
block|{
comment|// Unknown value
name|free
argument_list|(
name|x
index|[
name|offset
index|]
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

end_unit

