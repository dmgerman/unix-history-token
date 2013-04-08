begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s -verify
end_comment

begin_comment
comment|// rdar://13081751
end_comment

begin_typedef
typedef|typedef
name|__SIZE_TYPE__
name|size_t
typedef|;
end_typedef

begin_function_decl
name|void
modifier|*
name|memset
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|struct
name|__incomplete
modifier|*
name|incomplete
typedef|;
end_typedef

begin_function
name|void
name|mt_query_for_domain
parameter_list|(
specifier|const
name|char
modifier|*
name|domain
parameter_list|)
block|{
name|incomplete
name|query
init|=
literal|0
decl_stmt|;
name|memset
argument_list|(
name|query
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|query
argument_list|)
argument_list|)
expr_stmt|;
comment|// expected-warning {{'memset' call operates on objects of type 'struct __incomplete' while the size is based on a different type 'incomplete'}} \
comment|// expected-note {{did you mean to dereference the argument to 'sizeof' (and multiply it by the number of elements)?}}
block|}
end_function

end_unit

