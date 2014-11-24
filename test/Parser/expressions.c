begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
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
block|{}
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
block|{}
end_if

begin_comment
comment|// sizeof type
end_comment

begin_expr_stmt
call|(
name|void
call|)
argument_list|(
name|int
argument_list|)
literal|4
expr_stmt|;
end_expr_stmt

begin_comment
comment|// cast.
end_comment

begin_expr_stmt
operator|(
name|void
operator|)
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

begin_decl_stmt
name|int
name|A
init|=
operator|(
expr|struct
block|{
name|int
name|a
block|;}
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
operator|(
name|void
operator|)
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
return|return
literal|0
return|;
block|}
end_function

begin_struct
struct|struct
name|X0
block|{
struct|struct
block|{
struct|struct
block|{
name|int
name|c
index|[
literal|10
index|]
index|[
literal|9
index|]
decl_stmt|;
block|}
name|b
struct|;
block|}
name|a
struct|;
block|}
struct|;
end_struct

begin_function
name|int
name|test_offsetof
parameter_list|()
block|{
operator|(
name|void
operator|)
name|__builtin_offsetof
argument_list|(
expr|struct
name|X0
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
return|return
literal|0
return|;
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
operator|(
name|void
operator|)
sizeof|sizeof
name|arr
index|[
literal|0
index|]
expr_stmt|;
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
name|arr
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
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
comment|// expected-warning {{indirection of non-volatile null pointer}} \
comment|// expected-note {{consider using __builtin_trap}}
return|return
literal|0
return|;
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
comment|// PR8394
argument|void test7() {     ({}
comment|// expected-note {{to match}}
argument|;
comment|// expected-error {{expected ')'}}
argument|}
comment|// PR16992
argument|struct pr16992 { int x; };  void func_16992 () {   int x1 = sizeof int;
comment|// expected-error {{expected parentheses around type name in sizeof expression}}
argument|int x2 = sizeof struct pr16992;
comment|// expected-error {{expected parentheses around type name in sizeof expression}}
argument|int x3 = __alignof int;
comment|// expected-error {{expected parentheses around type name in __alignof expression}}
argument|int x4 = _Alignof int;
comment|// expected-error {{expected parentheses around type name in _Alignof expression}}
argument|}  void callee(double, double); void test8() {   callee(foobar,
comment|// expected-error {{use of undeclared identifier 'foobar'}}
argument|fizbin);
comment|// expected-error {{use of undeclared identifier 'fizbin'}}
argument|}
end_function

end_unit

