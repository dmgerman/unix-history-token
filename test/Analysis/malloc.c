begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -analyze -analyzer-experimental-internal-checks -checker-cfref -analyzer-experimental-checks -analyzer-store=region -verify %s
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
modifier|*
name|malloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f1
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
name|malloc
argument_list|(
literal|10
argument_list|)
decl_stmt|;
return|return;
comment|// expected-warning{{Allocated memory never released. Potential memory leak.}}
block|}
end_function

begin_function
name|void
name|f1_b
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
name|malloc
argument_list|(
literal|10
argument_list|)
decl_stmt|;
comment|// expected-warning{{Allocated memory never released. Potential memory leak.}}
block|}
end_function

begin_function
name|void
name|f2
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
name|malloc
argument_list|(
literal|10
argument_list|)
decl_stmt|;
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning{{Try to free a memory block that has been released}}
block|}
end_function

begin_comment
comment|// This case tests that storing malloc'ed memory to a static variable which is
end_comment

begin_comment
comment|// then returned is not leaked.  In the absence of known contracts for functions
end_comment

begin_comment
comment|// or inter-procedural analysis, this is a conservative answer.
end_comment

begin_function
name|int
modifier|*
name|f3
parameter_list|()
block|{
specifier|static
name|int
modifier|*
name|p
init|=
literal|0
decl_stmt|;
name|p
operator|=
name|malloc
argument_list|(
literal|10
argument_list|)
expr_stmt|;
return|return
name|p
return|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// This case tests that storing malloc'ed memory to a static global variable
end_comment

begin_comment
comment|// which is then returned is not leaked.  In the absence of known contracts for
end_comment

begin_comment
comment|// functions or inter-procedural analysis, this is a conservative answer.
end_comment

begin_decl_stmt
specifier|static
name|int
modifier|*
name|p_f4
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|int
modifier|*
name|f4
parameter_list|()
block|{
name|p_f4
operator|=
name|malloc
argument_list|(
literal|10
argument_list|)
expr_stmt|;
return|return
name|p_f4
return|;
comment|// no-warning
block|}
end_function

end_unit

