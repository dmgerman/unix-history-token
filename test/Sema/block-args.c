begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify -fblocks
end_comment

begin_function_decl
name|void
name|take
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test
parameter_list|()
block|{
name|take
argument_list|(
lambda|^
parameter_list|(
name|int
name|x
parameter_list|)
block|{}
argument_list|)
expr_stmt|;
name|take
argument_list|(
lambda|^
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{}
argument_list|)
expr_stmt|;
name|take
argument_list|(
lambda|^
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{}
argument_list|)
expr_stmt|;
name|take
argument_list|(
lambda|^
parameter_list|(
name|int
name|x
parameter_list|,
comment|// expected-note {{previous declaration is here}}
name|int
name|x
parameter_list|)
block|{}
argument_list|)
expr_stmt|;
comment|// expected-error {{redefinition of parameter 'x'}}
name|take
argument_list|(
lambda|^
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
operator|+
literal|1
return|;
block|}
argument_list|)
expr_stmt|;
name|int
function_decl|(
modifier|^
name|CP
function_decl|)
parameter_list|(
name|int
parameter_list|)
init|=
lambda|^
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
operator|*
name|x
return|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|take
argument_list|(
name|CP
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|arg
decl_stmt|;
end_decl_stmt

begin_expr_stmt
lambda|^
block|{
return|return
literal|1
return|;
block|}
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
lambda|^
block|{
return|return
literal|2
return|;
block|}
argument_list|(
name|arg
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{too many arguments to block call}}
end_comment

begin_expr_stmt
lambda|^
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|3
return|;
block|}
argument_list|(
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{too many arguments to block call}}
end_comment

begin_expr_stmt
lambda|^
parameter_list|()
block|{
return|return
literal|4
return|;
block|}
argument_list|(
name|arg
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{too many arguments to block call}}
end_comment

begin_expr_stmt
lambda|^
parameter_list|(
name|int
name|x
parameter_list|,
modifier|...
parameter_list|)
block|{
return|return
literal|5
return|;
block|}
argument_list|(
name|arg
argument_list|,
name|arg
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Explicit varargs, ok.
end_comment

begin_function
unit|}  int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
lambda|^
parameter_list|(
name|int
name|argCount
parameter_list|)
block|{
name|argCount
operator|=
literal|3
expr_stmt|;
block|}
argument_list|(
name|argc
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// radar 7528255
end_comment

begin_function
name|void
name|f0
parameter_list|()
block|{
lambda|^
parameter_list|(
name|int
parameter_list|,
name|double
name|d
parameter_list|,
name|char
parameter_list|)
block|{}
argument_list|(
literal|1
argument_list|,
literal|1.34
argument_list|,
literal|'a'
argument_list|)
expr_stmt|;
comment|// expected-error {{parameter name omitted}} \
comment|// expected-error {{parameter name omitted}}
block|}
end_function

begin_comment
comment|// rdar://problem/8962770
end_comment

begin_function
name|void
name|test4
parameter_list|()
block|{
name|int
function_decl|(
modifier|^
name|f
function_decl|)
parameter_list|()
init|=
lambda|^
parameter_list|(
init|(
name|x
init|)
block|)
block|{ }
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning {{type specifier missing}} expected-error {{type-id cannot have a name}}
end_comment

begin_comment
unit|}
comment|// rdar://problem/9170609
end_comment

begin_expr_stmt
unit|void
name|test5_helper
argument_list|(
name|void
argument_list|(
operator|^
argument_list|)
argument_list|(
name|int
argument_list|,
name|int
index|[
operator|*
index|]
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|test5
parameter_list|(
name|void
parameter_list|)
block|{
name|test5_helper
argument_list|(
lambda|^
parameter_list|(
name|int
name|n
parameter_list|,
name|int
name|array
index|[
name|n
index|]
parameter_list|)
block|{}
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Reduced from a problem on platforms where va_list is an array.
end_comment

begin_struct
struct|struct
name|tag
block|{
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|tag
name|array_ty
index|[
literal|1
index|]
typedef|;
end_typedef

begin_function
name|void
name|test6
parameter_list|(
name|void
parameter_list|)
block|{
name|void
function_decl|(
modifier|^
name|block
function_decl|)
parameter_list|(
name|array_ty
parameter_list|)
init|=
lambda|^
parameter_list|(
name|array_ty
name|arr
parameter_list|)
block|{ }
function_decl|;
name|array_ty
name|arr
decl_stmt|;
name|block
argument_list|(
name|arr
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

