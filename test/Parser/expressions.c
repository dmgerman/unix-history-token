begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -parse-noop -verify %s
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
if|if
condition|(
expr|sizeof
operator|(
name|int
operator|)
block|{
literal|1
block|}
block|)
function|;
end_function

begin_comment
comment|// sizeof compound literal
end_comment

begin_if
if|if
condition|(
sizeof|sizeof
argument_list|(
name|int
argument_list|)
condition|)
empty_stmt|;
end_if

begin_comment
comment|// sizeof type
end_comment

begin_expr_stmt
operator|(
name|int
operator|)
literal|4
expr_stmt|;
end_expr_stmt

begin_comment
comment|// cast.
end_comment

begin_expr_stmt
operator|(
name|int
operator|)
block|{
literal|4
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|// compound literal.
end_comment

begin_comment
comment|// FIXME: change this to the struct version when we can.
end_comment

begin_comment
comment|//int A = (struct{ int a;}){ 1}.a;
end_comment

begin_decl_stmt
name|int
name|A
init|=
operator|(
name|int
operator|)
block|{
literal|1
block|}
operator|.
name|a
decl_stmt|;
end_decl_stmt

begin_macro
unit|}  int
name|test2
argument_list|(
argument|int a
argument_list|,
argument|int b
argument_list|)
end_macro

begin_block
block|{
return|return
name|a
condition|?
name|a
operator|,
name|b
operator|:
name|a
return|;
block|}
end_block

begin_function
name|int
name|test3
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|,
name|int
name|c
parameter_list|)
block|{
return|return
name|a
operator|=
name|b
operator|=
name|c
return|;
block|}
end_function

begin_function
name|int
name|test4
parameter_list|()
block|{
name|test4
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|int
name|test_offsetof
parameter_list|()
block|{
comment|// FIXME: change into something that is semantically correct.
name|__builtin_offsetof
argument_list|(
name|int
argument_list|,
name|a
operator|.
name|b
operator|.
name|c
index|[
literal|4
index|]
index|[
literal|5
index|]
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_sizeof
parameter_list|()
block|{
name|int
name|arr
index|[
literal|10
index|]
decl_stmt|;
sizeof|sizeof
name|arr
index|[
literal|0
index|]
expr_stmt|;
sizeof|sizeof
argument_list|(
name|arr
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
sizeof|sizeof
argument_list|(
name|arr
argument_list|)
index|[
literal|0
index|]
expr_stmt|;
block|}
end_function

begin_comment
comment|// PR3418
end_comment

begin_function
name|int
name|test_leading_extension
parameter_list|()
block|{
name|__extension__
argument_list|(
operator|*
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|)
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_comment
comment|// PR3972
end_comment

begin_function_decl
name|int
name|test5
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|test6
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|test5
argument_list|(
comment|// expected-note {{to match}}
argument|test5(
literal|1
argument|)                  ;
comment|// expected-error {{expected ')'}}
argument|}
end_function

end_unit

