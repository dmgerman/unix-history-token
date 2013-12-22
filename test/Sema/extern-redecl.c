begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// rdar: // 8125274
end_comment

begin_decl_stmt
specifier|static
name|int
name|a16
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{tentative array definition assumed to have one element}}
end_comment

begin_function
name|void
name|f16
parameter_list|(
name|void
parameter_list|)
block|{
specifier|extern
name|int
name|a16
index|[]
decl_stmt|;
block|}
end_function

begin_comment
comment|// PR10013: Scope of extern declarations extend past enclosing block
end_comment

begin_decl_stmt
specifier|extern
name|int
name|PR10013_x
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|PR10013
parameter_list|(
name|void
parameter_list|)
block|{
name|int
modifier|*
name|PR10013_x
init|=
literal|0
decl_stmt|;
block|{
specifier|extern
name|int
name|PR10013_x
decl_stmt|;
specifier|extern
name|int
name|PR10013_x
decl_stmt|;
block|}
return|return
name|PR10013_x
return|;
comment|// expected-warning{{incompatible pointer to integer conversion}}
block|}
end_function

begin_decl_stmt
specifier|static
name|int
name|test1_a
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{tentative array definition assumed to have one element}}
end_comment

begin_decl_stmt
specifier|extern
name|int
name|test1_a
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// rdar://13535367
end_comment

begin_function
name|void
name|test2declarer
parameter_list|()
block|{
specifier|extern
name|int
name|test2_array
index|[
literal|100
index|]
decl_stmt|;
block|}
end_function

begin_decl_stmt
specifier|extern
name|int
name|test2_array
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|test2v
init|=
sizeof|sizeof
argument_list|(
name|test2_array
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{invalid application of 'sizeof' to an incomplete type 'int []'}}
end_comment

begin_function
name|void
name|test3declarer
parameter_list|()
block|{
block|{
specifier|extern
name|int
name|test3_array
index|[
literal|100
index|]
decl_stmt|;
block|}
specifier|extern
name|int
name|test3_array
index|[]
decl_stmt|;
name|int
name|x
init|=
sizeof|sizeof
argument_list|(
name|test3_array
argument_list|)
decl_stmt|;
comment|// expected-error {{invalid application of 'sizeof' to an incomplete type 'int []'}}
block|}
end_function

begin_function
name|void
name|test4
parameter_list|()
block|{
specifier|extern
name|int
name|test4_array
index|[]
decl_stmt|;
block|{
specifier|extern
name|int
name|test4_array
index|[
literal|100
index|]
decl_stmt|;
name|int
name|x
init|=
sizeof|sizeof
argument_list|(
name|test4_array
argument_list|)
decl_stmt|;
comment|// fine
block|}
name|int
name|x
init|=
sizeof|sizeof
argument_list|(
name|test4_array
argument_list|)
decl_stmt|;
comment|// expected-error {{invalid application of 'sizeof' to an incomplete type 'int []'}}
block|}
end_function

begin_comment
comment|// Test that invalid local extern declarations of library
end_comment

begin_comment
comment|// builtins behave reasonably.
end_comment

begin_function_decl
specifier|extern
name|void
name|abort
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note 2 {{previous declaration is here}}
end_comment

begin_function_decl
specifier|extern
name|float
modifier|*
name|calloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning {{incompatible redeclaration of library function}} expected-note {{is a builtin}} expected-note 2 {{previous declaration is here}}
end_comment

begin_function
name|void
name|test5a
parameter_list|()
block|{
name|int
name|abort
parameter_list|()
function_decl|;
comment|// expected-error {{conflicting types}}
name|float
modifier|*
name|malloc
parameter_list|()
function_decl|;
comment|// expected-warning {{incompatible redeclaration of library function}} expected-note 2 {{is a builtin}}
name|int
modifier|*
name|calloc
parameter_list|()
function_decl|;
comment|// expected-error {{conflicting types}}
block|}
end_function

begin_function
name|void
name|test5b
parameter_list|()
block|{
name|int
name|abort
parameter_list|()
function_decl|;
comment|// expected-error {{conflicting types}}
name|float
modifier|*
name|malloc
parameter_list|()
function_decl|;
comment|// expected-warning {{incompatible redeclaration of library function}}
name|int
modifier|*
name|calloc
parameter_list|()
function_decl|;
comment|// expected-error {{conflicting types}}
block|}
end_function

begin_function
name|void
name|test5c
parameter_list|()
block|{
name|void
function_decl|(
modifier|*
name|_abort
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
operator|&
name|abort
function_decl|;
name|void
modifier|*
function_decl|(
modifier|*
name|_malloc
function_decl|)
parameter_list|()
init|=
operator|&
name|malloc
function_decl|;
name|float
modifier|*
function_decl|(
modifier|*
name|_calloc
function_decl|)
parameter_list|()
init|=
operator|&
name|calloc
function_decl|;
block|}
end_function

begin_function
name|void
name|test6
parameter_list|()
block|{
specifier|extern
name|int
name|test6_array1
index|[
literal|100
index|]
decl_stmt|;
specifier|extern
name|int
name|test6_array2
index|[
literal|100
index|]
decl_stmt|;
name|void
name|test6_fn1
argument_list|(
name|int
operator|*
argument_list|)
decl_stmt|;
name|void
name|test6_fn2
argument_list|(
name|int
operator|*
argument_list|)
decl_stmt|;
block|{
comment|// Types are only merged from visible declarations.
name|char
name|test6_array2
decl_stmt|;
name|char
name|test6_fn2
decl_stmt|;
block|{
specifier|extern
name|int
name|test6_array1
index|[]
decl_stmt|;
specifier|extern
name|int
name|test6_array2
index|[]
decl_stmt|;
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
name|test6_array1
argument_list|)
expr_stmt|;
comment|// ok
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
name|test6_array2
argument_list|)
expr_stmt|;
comment|// expected-error {{incomplete type}}
name|void
name|test6_fn1
parameter_list|()
function_decl|;
name|void
name|test6_fn2
parameter_list|()
function_decl|;
name|test6_fn1
argument_list|(
literal|1.2
argument_list|)
expr_stmt|;
comment|// expected-error {{passing 'double' to parameter of incompatible type 'int *'}}
comment|// FIXME: This is valid, but we should warn on it.
name|test6_fn2
argument_list|(
literal|1.2
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

end_unit

