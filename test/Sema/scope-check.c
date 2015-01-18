begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -fblocks -std=gnu99 %s -Wno-unreachable-code
end_comment

begin_function
name|int
name|test1
parameter_list|(
name|int
name|x
parameter_list|)
block|{
goto|goto
name|L
goto|;
comment|// expected-error{{cannot jump from this goto statement to its label}}
name|int
name|a
index|[
name|x
index|]
decl_stmt|;
comment|// expected-note {{jump bypasses initialization of variable length array}}
name|int
name|b
index|[
name|x
index|]
decl_stmt|;
comment|// expected-note {{jump bypasses initialization of variable length array}}
name|L
label|:
return|return
sizeof|sizeof
name|a
return|;
block|}
end_function

begin_function
name|int
name|test2
parameter_list|(
name|int
name|x
parameter_list|)
block|{
goto|goto
name|L
goto|;
comment|// expected-error{{cannot jump from this goto statement to its label}}
typedef|typedef
name|int
name|a
index|[
name|x
index|]
typedef|;
comment|// expected-note {{jump bypasses initialization of VLA typedef}}
name|L
label|:
return|return
sizeof|sizeof
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function_decl
name|void
name|test3clean
parameter_list|(
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|test3
parameter_list|()
block|{
goto|goto
name|L
goto|;
comment|// expected-error{{cannot jump from this goto statement to its label}}
name|int
name|a
name|__attribute
argument_list|(
operator|(
name|cleanup
argument_list|(
name|test3clean
argument_list|)
operator|)
argument_list|)
decl_stmt|;
comment|// expected-note {{jump bypasses initialization of variable with __attribute__((cleanup))}}
name|L
label|:
return|return
name|a
return|;
block|}
end_function

begin_function
name|int
name|test4
parameter_list|(
name|int
name|x
parameter_list|)
block|{
goto|goto
name|L
goto|;
comment|// expected-error{{cannot jump from this goto statement to its label}}
name|int
name|a
index|[
name|x
index|]
decl_stmt|;
comment|// expected-note {{jump bypasses initialization of variable length array}}
name|test4
argument_list|(
name|x
argument_list|)
expr_stmt|;
name|L
label|:
return|return
sizeof|sizeof
name|a
return|;
block|}
end_function

begin_function
name|int
name|test5
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|a
index|[
name|x
index|]
decl_stmt|;
name|test5
argument_list|(
name|x
argument_list|)
expr_stmt|;
goto|goto
name|L
goto|;
comment|// Ok.
name|L
label|:
goto|goto
name|L
goto|;
comment|// Ok.
return|return
sizeof|sizeof
name|a
return|;
block|}
end_function

begin_function
name|int
name|test6
parameter_list|()
block|{
comment|// just plain invalid.
goto|goto
name|x
goto|;
comment|// expected-error {{use of undeclared label 'x'}}
block|}
end_function

begin_function
name|void
name|test7
parameter_list|(
name|int
name|x
parameter_list|)
block|{
switch|switch
condition|(
name|x
condition|)
block|{
case|case
literal|1
case|:
empty_stmt|;
name|int
name|a
index|[
name|x
index|]
decl_stmt|;
comment|// expected-note {{jump bypasses initialization of variable length array}}
case|case
literal|2
case|:
comment|// expected-error {{cannot jump from switch statement to this case label}}
name|a
index|[
literal|1
index|]
operator|=
literal|2
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_function
name|int
name|test8
parameter_list|(
name|int
name|x
parameter_list|)
block|{
comment|// For statement.
goto|goto
name|L2
goto|;
comment|// expected-error {{cannot jump from this goto statement to its label}}
for|for
control|(
name|int
name|arr
index|[
name|x
index|]
init|;
comment|// expected-note {{jump bypasses initialization of variable length array}}
condition|;
operator|++
name|x
control|)
name|L2
label|:
empty_stmt|;
comment|// Statement expressions.
goto|goto
name|L3
goto|;
comment|// expected-error {{cannot jump from this goto statement to its label}}
name|int
name|Y
init|=
operator|(
block|{
name|int
name|a
index|[
name|x
index|]
block|;
comment|// expected-note {{jump bypasses initialization of variable length array}}
name|L3
operator|:
literal|4
block|; }
operator|)
decl_stmt|;
goto|goto
name|L4
goto|;
comment|// expected-error {{cannot jump from this goto statement to its label}}
block|{
name|int
name|A
index|[
name|x
index|]
decl_stmt|,
comment|// expected-note {{jump bypasses initialization of variable length array}}
name|B
index|[
name|x
index|]
decl_stmt|;
comment|// expected-note {{jump bypasses initialization of variable length array}}
name|L4
label|:
empty_stmt|;
block|}
block|{
name|L5
label|:
empty_stmt|;
comment|// ok
name|int
name|A
index|[
name|x
index|]
decl_stmt|,
name|B
init|=
operator|(
block|{
if|if
condition|(
name|x
condition|)
goto|goto
name|L5
goto|;
else|else
goto|goto
name|L6
goto|;
literal|4
expr|;
block|}
block|)
function|;
end_function

begin_label
name|L6
label|:
end_label

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// ok.
end_comment

begin_if
if|if
condition|(
name|x
condition|)
goto|goto
name|L6
goto|;
end_if

begin_comment
comment|// ok
end_comment

begin_label
unit|}      {
name|L7
label|:
end_label

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// ok
end_comment

begin_decl_stmt
name|int
name|A
index|[
name|x
index|]
decl_stmt|,
name|B
init|=
operator|(
block|{
if|if
condition|(
name|x
condition|)
goto|goto
name|L7
goto|;
else|else
goto|goto
name|L8
goto|;
comment|// expected-error {{cannot jump from this goto statement to its label}}
literal|4
expr|;
end_decl_stmt

begin_operator
unit|})
operator|,
end_operator

begin_expr_stmt
name|C
index|[
name|x
index|]
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-note {{jump bypasses initialization of variable length array}}
end_comment

begin_label
name|L8
label|:
end_label

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// bad
end_comment

begin_label
unit|}     {
name|L9
label|:
end_label

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// ok
end_comment

begin_expr_stmt
name|int
name|A
index|[
operator|(
block|{
expr|if
operator|(
name|x
operator|)
end_expr_stmt

begin_goto
goto|goto
name|L9
goto|;
end_goto

begin_else
else|else
comment|// FIXME:
goto|goto
name|L10
goto|;
end_else

begin_comment
comment|// fixme-error {{cannot jump from this goto statement to its label}}
end_comment

begin_expr_stmt
literal|4
expr_stmt|;
end_expr_stmt

begin_empty_stmt
unit|})]
empty_stmt|;
end_empty_stmt

begin_label
name|L10
label|:
end_label

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// bad
end_comment

begin_comment
unit|}      {
comment|// FIXME: Crashes goto checker.
end_comment

begin_comment
comment|//goto L11;// ok
end_comment

begin_comment
comment|//int A[({   L11: 4; })];
end_comment

begin_goto
unit|}      {
goto|goto
name|L12
goto|;
end_goto

begin_decl_stmt
name|int
name|y
init|=
literal|4
decl_stmt|;
end_decl_stmt

begin_comment
comment|// fixme-warn: skips initializer.
end_comment

begin_label
name|L12
label|:
end_label

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// Statement expressions 2.
end_comment

begin_expr_stmt
unit|goto
name|L1
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{cannot jump from this goto statement to its label}}
end_comment

begin_return
return|return
name|x
operator|==
operator|(
block|{
name|int
name|a
index|[
name|x
index|]
block|;
comment|// expected-note {{jump bypasses initialization of variable length array}}
name|L1
operator|:
literal|42
block|; }
operator|)
return|;
end_return

begin_macro
unit|}  void
name|test9
argument_list|(
argument|int n
argument_list|,
argument|void *P
argument_list|)
end_macro

begin_block
block|{
name|int
name|Y
decl_stmt|;
name|int
name|Z
init|=
literal|4
decl_stmt|;
goto|goto *
name|P
goto|;
comment|// expected-error {{cannot jump from this indirect goto statement to one of its possible targets}}
name|L2
label|:
empty_stmt|;
name|int
name|a
index|[
name|n
index|]
decl_stmt|;
comment|// expected-note {{jump bypasses initialization of variable length array}}
name|L3
label|:
comment|// expected-note {{possible target of indirect goto}}
name|L4
label|:
goto|goto *
name|P
goto|;
goto|goto
name|L3
goto|;
comment|// ok
goto|goto
name|L4
goto|;
comment|// ok
name|void
modifier|*
name|Ptrs
index|[]
init|=
block|{
operator|&&
name|L2
block|,
operator|&&
name|L3
block|}
decl_stmt|;
block|}
end_block

begin_function
name|void
name|test10
parameter_list|(
name|int
name|n
parameter_list|,
name|void
modifier|*
name|P
parameter_list|)
block|{
goto|goto
name|L0
goto|;
comment|// expected-error {{cannot jump from this goto statement to its label}}
typedef|typedef
name|int
name|A
index|[
name|n
index|]
typedef|;
comment|// expected-note {{jump bypasses initialization of VLA typedef}}
name|L0
label|:
goto|goto
name|L1
goto|;
comment|// expected-error {{cannot jump from this goto statement to its label}}
name|A
name|b
decl_stmt|,
name|c
index|[
literal|10
index|]
decl_stmt|;
comment|// expected-note 2 {{jump bypasses initialization of variable length array}}
name|L1
label|:
goto|goto
name|L2
goto|;
comment|// expected-error {{cannot jump from this goto statement to its label}}
name|A
name|d
index|[
name|n
index|]
decl_stmt|;
comment|// expected-note {{jump bypasses initialization of variable length array}}
name|L2
label|:
return|return;
block|}
end_function

begin_function
name|void
name|test11
parameter_list|(
name|int
name|n
parameter_list|)
block|{
name|void
modifier|*
name|P
init|=
lambda|^
block|{
switch|switch
condition|(
name|n
condition|)
block|{
case|case
literal|1
case|:
empty_stmt|;
case|case
literal|2
case|:
case|case
literal|3
case|:
empty_stmt|;
name|int
name|Arr
index|[
name|n
index|]
decl_stmt|;
comment|// expected-note {{jump bypasses initialization of variable length array}}
case|case
literal|4
case|:
comment|// expected-error {{cannot jump from switch statement to this case label}}
return|return;
block|}
block|}
decl_stmt|;
block|}
end_function

begin_comment
comment|// TODO: When and if gotos are allowed in blocks, this should work.
end_comment

begin_function
name|void
name|test12
parameter_list|(
name|int
name|n
parameter_list|)
block|{
name|void
modifier|*
name|P
init|=
lambda|^
block|{
goto|goto
name|L1
goto|;
name|L1
label|:
goto|goto
name|L2
goto|;
name|L2
label|:
goto|goto
name|L3
goto|;
comment|// expected-error {{cannot jump from this goto statement to its label}}
name|int
name|Arr
index|[
name|n
index|]
decl_stmt|;
comment|// expected-note {{jump bypasses initialization of variable length array}}
name|L3
label|:
goto|goto
name|L4
goto|;
name|L4
label|:
return|return;
block|}
decl_stmt|;
block|}
end_function

begin_function
name|void
name|test13
parameter_list|(
name|int
name|n
parameter_list|,
name|void
modifier|*
name|p
parameter_list|)
block|{
name|int
name|vla
index|[
name|n
index|]
decl_stmt|;
goto|goto *
name|p
goto|;
name|a0
label|:
empty_stmt|;
specifier|static
name|void
modifier|*
name|ps
index|[]
init|=
block|{
operator|&&
name|a0
block|}
decl_stmt|;
block|}
end_function

begin_function
name|int
name|test14
parameter_list|(
name|int
name|n
parameter_list|)
block|{
specifier|static
name|void
modifier|*
name|ps
index|[]
init|=
block|{
operator|&&
name|a0
block|,
operator|&&
name|a1
block|}
decl_stmt|;
if|if
condition|(
name|n
operator|<
literal|0
condition|)
goto|goto *&&
name|a0
goto|;
if|if
condition|(
name|n
operator|>
literal|0
condition|)
block|{
name|int
name|vla
index|[
name|n
index|]
decl_stmt|;
name|a1
label|:
name|vla
index|[
name|n
operator|-
literal|1
index|]
operator|=
literal|0
expr_stmt|;
block|}
name|a0
label|:
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// PR8473: IR gen can't deal with indirect gotos past VLA
end_comment

begin_comment
comment|// initialization, so that really needs to be a hard error.
end_comment

begin_function
name|void
name|test15
parameter_list|(
name|int
name|n
parameter_list|,
name|void
modifier|*
name|pc
parameter_list|)
block|{
specifier|static
specifier|const
name|void
modifier|*
name|addrs
index|[]
init|=
block|{
operator|&&
name|L1
block|,
operator|&&
name|L2
block|}
decl_stmt|;
goto|goto *
name|pc
goto|;
comment|// expected-error {{cannot jump from this indirect goto statement to one of its possible targets}}
name|L1
label|:
block|{
name|char
name|vla
index|[
name|n
index|]
decl_stmt|;
comment|// expected-note {{jump bypasses initialization}}
name|L2
label|:
comment|// expected-note {{possible target}}
name|vla
index|[
literal|0
index|]
operator|=
literal|'a'
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|// rdar://9024687
end_comment

begin_decl_stmt
name|int
name|test16
argument_list|(
name|int
index|[
sizeof|sizeof
expr|&&
name|z
expr|]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{use of address-of-label extension outside of a function body}}
end_comment

end_unit

