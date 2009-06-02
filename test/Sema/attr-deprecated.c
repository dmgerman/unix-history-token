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

end_unit

