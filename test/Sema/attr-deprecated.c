begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -verify -fsyntax-only
end_comment

begin_function_decl
name|int
name|f
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(deprecated
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|g
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(deprecated
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|g
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|z
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(bogusattr
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning {{'bogusattr' attribute ignored}}
end_comment

begin_decl_stmt
specifier|extern
name|int
name|var
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|a
parameter_list|()
block|{
name|int
function_decl|(
modifier|*
name|ptr
function_decl|)
parameter_list|()
init|=
name|f
function_decl|;
comment|// expected-warning {{'f' is deprecated}}
name|f
argument_list|()
expr_stmt|;
comment|// expected-warning {{'f' is deprecated}}
comment|// test if attributes propagate to functions
name|g
argument_list|()
expr_stmt|;
comment|// expected-warning {{'g' is deprecated}}
return|return
name|var
return|;
comment|// expected-warning {{'var' is deprecated}}
block|}
end_function

begin_comment
comment|// test if attributes propagate to variables
end_comment

begin_decl_stmt
specifier|extern
name|int
name|var
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|w
parameter_list|()
block|{
return|return
name|var
return|;
comment|// expected-warning {{'var' is deprecated}}
block|}
end_function

begin_function_decl
name|int
name|old_fn
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(deprecated
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|old_fn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
function_decl|(
modifier|*
name|fn_ptr
function_decl|)
parameter_list|()
init|=
name|old_fn
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning {{'old_fn' is deprecated}}
end_comment

begin_function
name|int
name|old_fn
parameter_list|()
block|{
return|return
name|old_fn
argument_list|()
operator|+
literal|1
return|;
comment|// no warning, deprecated functions can use deprecated symbols.
block|}
end_function

begin_struct
struct|struct
name|foo
block|{
name|int
name|x
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|test1
parameter_list|(
name|struct
name|foo
modifier|*
name|F
parameter_list|)
block|{
operator|++
name|F
operator|->
name|x
expr_stmt|;
comment|// expected-warning {{'x' is deprecated}}
block|}
end_function

begin_typedef
typedef|typedef
name|struct
name|foo
name|foo_dep
name|__attribute__
typedef|((
name|deprecated
typedef|));
end_typedef

begin_decl_stmt
name|foo_dep
modifier|*
name|test2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'foo_dep' is deprecated}}
end_comment

begin_decl_stmt
name|struct
name|bar_dep
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|,
name|invalid_attribute
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'invalid_attribute' attribute ignored}}
end_comment

begin_decl_stmt
name|struct
name|bar_dep
modifier|*
name|test3
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'bar_dep' is deprecated}}
end_comment

begin_comment
comment|// These should not warn because the actually declaration itself is deprecated.
end_comment

begin_comment
comment|// rdar://6756623
end_comment

begin_decl_stmt
name|foo_dep
modifier|*
name|test4
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|bar_dep
modifier|*
name|test5
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|foo_dep
name|test6
parameter_list|(
name|struct
name|bar_dep
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// expected-warning {{'foo_dep' is deprecated}} \
end_comment

begin_comment
comment|// expected-warning {{'bar_dep' is deprecated}}
end_comment

begin_typedef
typedef|typedef
name|foo_dep
name|test7
parameter_list|(
name|struct
name|bar_dep
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(deprecated
typedef|));
end_typedef

begin_function
name|int
name|test8
parameter_list|(
name|char
modifier|*
name|p
parameter_list|)
block|{
name|p
operator|+=
sizeof|sizeof
argument_list|(
name|foo_dep
argument_list|)
expr_stmt|;
comment|// expected-warning {{'foo_dep' is deprecated}}
name|foo_dep
modifier|*
name|ptr
decl_stmt|;
comment|// expected-warning {{'foo_dep' is deprecated}}
name|ptr
operator|=
operator|(
name|foo_dep
operator|*
operator|)
name|p
expr_stmt|;
comment|// expected-warning {{'foo_dep' is deprecated}}
name|int
name|func
argument_list|(
name|foo_dep
operator|*
name|foo
argument_list|)
decl_stmt|;
comment|// expected-warning {{'foo_dep' is deprecated}}
return|return
name|func
argument_list|(
name|ptr
argument_list|)
return|;
block|}
end_function

begin_function_decl
name|foo_dep
modifier|*
name|test9
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(deprecated
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|foo_dep
modifier|*
name|test9
parameter_list|(
name|void
parameter_list|)
block|{
name|void
modifier|*
name|myalloc
argument_list|(
name|unsigned
name|long
argument_list|)
decl_stmt|;
name|foo_dep
modifier|*
name|ptr
init|=
operator|(
name|foo_dep
operator|*
operator|)
name|myalloc
argument_list|(
sizeof|sizeof
argument_list|(
name|foo_dep
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|ptr
return|;
block|}
end_function

begin_function_decl
name|void
name|test10
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(deprecated
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|test10
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
sizeof|sizeof
argument_list|(
name|foo_dep
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
condition|)
block|{   }
name|foo_dep
modifier|*
name|localfunc
argument_list|(
name|void
argument_list|)
decl_stmt|;
name|foo_dep
name|localvar
decl_stmt|;
block|}
end_function

begin_decl_stmt
name|char
name|test11
index|[
sizeof|sizeof
argument_list|(
name|foo_dep
argument_list|)
index|]
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|test12
index|[
sizeof|sizeof
argument_list|(
name|foo_dep
argument_list|)
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'foo_dep' is deprecated}}
end_comment

begin_function_decl
name|int
name|test13
parameter_list|(
name|foo_dep
modifier|*
name|foo
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(deprecated
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|test14
parameter_list|(
name|foo_dep
modifier|*
name|foo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning {{'foo_dep' is deprecated}}
end_comment

begin_decl_stmt
name|unsigned
name|long
name|test15
init|=
sizeof|sizeof
argument_list|(
name|foo_dep
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'foo_dep' is deprecated}}
end_comment

begin_decl_stmt
name|unsigned
name|long
name|test16
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
init|=
sizeof|sizeof
argument_list|(
name|foo_dep
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|foo_dep
name|test17
decl_stmt|,
comment|// expected-warning {{'foo_dep' is deprecated}}
name|test18
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
decl_stmt|,
name|test19
decl_stmt|;
end_decl_stmt

end_unit

