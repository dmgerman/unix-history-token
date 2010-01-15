begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -fblocks
end_comment

begin_function_decl
name|void
name|donotwarn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
function_decl|(
modifier|^
name|IFP
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
function_decl|(
modifier|^
name|II
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|test1
parameter_list|()
block|{
name|int
function_decl|(
modifier|^
name|PFR
function_decl|)
parameter_list|(
name|int
parameter_list|)
init|=
literal|0
function_decl|;
comment|// OK
name|PFR
operator|=
name|II
expr_stmt|;
comment|// OK
if|if
condition|(
name|PFR
operator|==
name|II
condition|)
comment|// OK
name|donotwarn
argument_list|()
expr_stmt|;
if|if
condition|(
name|PFR
operator|==
name|IFP
condition|)
comment|// OK
name|donotwarn
argument_list|()
expr_stmt|;
if|if
condition|(
name|PFR
operator|==
operator|(
name|int
argument_list|(
operator|^
argument_list|)
argument_list|(
name|int
argument_list|)
operator|)
name|IFP
condition|)
comment|// OK
name|donotwarn
argument_list|()
expr_stmt|;
if|if
condition|(
name|PFR
operator|==
literal|0
condition|)
comment|// OK
name|donotwarn
argument_list|()
expr_stmt|;
if|if
condition|(
name|PFR
condition|)
comment|// OK
name|donotwarn
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|PFR
condition|)
comment|// OK
name|donotwarn
argument_list|()
expr_stmt|;
return|return
name|PFR
operator|!=
name|IFP
return|;
comment|// OK
block|}
end_function

begin_function
name|int
name|test2
parameter_list|(
name|double
function_decl|(
modifier|^
name|S
function_decl|)
parameter_list|()
parameter_list|)
block|{
name|double
function_decl|(
modifier|^
name|I
function_decl|)
parameter_list|(
name|int
parameter_list|)
init|=
operator|(
name|void
operator|*
operator|)
name|S
function_decl|;
operator|(
name|void
operator|*
operator|)
name|I
operator|=
operator|(
name|void
operator|*
operator|)
name|S
expr_stmt|;
comment|// expected-error {{assignment to cast is illegal, lvalue casts are not supported}}
name|void
modifier|*
name|pv
init|=
name|I
decl_stmt|;
name|pv
operator|=
name|S
expr_stmt|;
name|I
argument_list|(
literal|1
argument_list|)
expr_stmt|;
return|return
operator|(
name|void
operator|*
operator|)
name|I
operator|==
operator|(
name|void
operator|*
operator|)
name|S
return|;
block|}
end_function

begin_decl_stmt
name|int
modifier|^
name|x
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{block pointer to non-function type is invalid}}
end_comment

begin_decl_stmt
name|int
modifier|^
modifier|^
name|x1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{block pointer to non-function type is invalid}} expected-error {{block pointer to non-function type is invalid}}
end_comment

begin_function
name|void
name|test3
parameter_list|()
block|{
name|char
modifier|*
modifier|^
name|y
decl_stmt|;
comment|// expected-error {{block pointer to non-function type is invalid}}
block|}
end_function

begin_enum
enum|enum
block|{
name|NSBIRLazilyAllocated
init|=
literal|0
block|}
enum|;
end_enum

begin_function
name|int
name|test4
parameter_list|(
name|int
name|argc
parameter_list|)
block|{
comment|// rdar://6251437
lambda|^
block|{
switch|switch
condition|(
name|argc
condition|)
block|{
case|case
name|NSBIRLazilyAllocated
case|:
comment|// is an integer constant expression.
default|default:
break|break;
block|}
block|}
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function_decl
name|void
name|bar
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// rdar://6257721 - reference to static/global is byref by default.
end_comment

begin_decl_stmt
specifier|static
name|int
name|test5g
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test5
parameter_list|()
block|{
name|bar
argument_list|(
lambda|^
block|{
name|test5g
operator|=
literal|1
expr_stmt|;
block|}
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// rdar://6405429 - __func__ in a block refers to the containing function name.
end_comment

begin_function
specifier|const
name|char
modifier|*
name|test6
parameter_list|()
block|{
return|return
lambda|^
block|{
return|return
name|__func__
return|;
block|}
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// radr://6732116 - block comparisons
end_comment

begin_function_decl
name|void
function_decl|(
modifier|^
name|test7a
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|test7
parameter_list|(
name|void
function_decl|(
modifier|^
name|p
function_decl|)
parameter_list|()
parameter_list|)
block|{
return|return
name|test7a
operator|==
name|p
return|;
block|}
end_function

begin_function
name|void
name|test8
parameter_list|()
block|{
name|somelabel
label|:
comment|// FIXME: This should say "jump out of block not legal" when gotos are allowed.
lambda|^
block|{
goto|goto
name|somelabel
goto|;
block|}
argument_list|()
expr_stmt|;
comment|// expected-error {{goto not allowed in block literal}}
block|}
end_function

begin_function
name|void
name|test9
parameter_list|()
block|{
goto|goto
name|somelabel
goto|;
comment|// expected-error {{use of undeclared label 'somelabel'}}
lambda|^
block|{
name|somelabel
label|:
empty_stmt|;
block|}
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test10
parameter_list|(
name|int
name|i
parameter_list|)
block|{
switch|switch
condition|(
name|i
condition|)
block|{
case|case
literal|41
case|:
empty_stmt|;
lambda|^
block|{
case|case
literal|42
case|:
empty_stmt|;
block|}
argument_list|()
expr_stmt|;
comment|// expected-error {{'case' statement not in switch statement}}
block|}
block|}
end_function

begin_function
name|void
name|test11
parameter_list|(
name|int
name|i
parameter_list|)
block|{
switch|switch
condition|(
name|i
condition|)
block|{
case|case
literal|41
case|:
empty_stmt|;
lambda|^
block|{
break|break;
block|}
argument_list|()
expr_stmt|;
comment|// expected-error {{'break' statement not in loop or switch statement}}
block|}
for|for
control|(
init|;
name|i
operator|<
literal|100
condition|;
operator|++
name|i
control|)
lambda|^
block|{
break|break;
block|}
argument_list|()
expr_stmt|;
comment|// expected-error {{'break' statement not in loop or switch statement}}
block|}
end_function

begin_function_decl
name|void
function_decl|(
modifier|^
name|test12f
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test12
parameter_list|()
block|{
name|test12f
operator|=
operator|^
name|test12f
expr_stmt|;
comment|// expected-error {{type name requires a specifier or qualifier}} expected-error {{expected expression}}
block|}
end_function

begin_comment
comment|// rdar://6808730
end_comment

begin_decl_stmt
name|void
modifier|*
name|test13
init|=
lambda|^
block|{
name|int
name|X
init|=
literal|32
decl_stmt|;
name|void
modifier|*
name|P
init|=
lambda|^
block|{
return|return
name|X
operator|+
literal|4
return|;
comment|// References outer block's "X", so outer block is constant.
block|}
decl_stmt|;
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test14
parameter_list|()
block|{
name|int
name|X
init|=
literal|32
decl_stmt|;
specifier|static
name|void
modifier|*
name|P
init|=
lambda|^
block|{
comment|// expected-error {{initializer element is not a compile-time constant}}
name|void
modifier|*
name|Q
init|=
lambda|^
block|{
comment|// References test14's "X": outer block is non constant.
return|return
name|X
operator|+
literal|4
return|;
block|}
decl_stmt|;
block|}
decl_stmt|;
block|}
end_function

begin_enum
enum|enum
block|{
name|LESS
block|}
enum|;
end_enum

begin_function
name|void
name|foo
parameter_list|(
name|long
function_decl|(
modifier|^
name|comp
function_decl|)
parameter_list|()
parameter_list|)
block|{ }
end_function

begin_function_decl
name|void
function_decl|(
modifier|^
name|test15f
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test15
parameter_list|()
block|{
name|foo
argument_list|(
lambda|^
block|{
return|return
name|LESS
return|;
block|}
argument_list|)
expr_stmt|;
comment|// expected-error {{incompatible block pointer types passing 'int (^)(void)', expected 'long (^)()'}}
block|}
end_function

begin_decl_stmt
specifier|__block
name|int
name|test16i
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{__block attribute not allowed, only allowed on local variables}}
end_comment

begin_function
name|void
name|test16
parameter_list|(
specifier|__block
name|int
name|i
parameter_list|)
block|{
comment|// expected-error {{__block attribute not allowed, only allowed on local variables}}
name|int
name|size
init|=
literal|5
decl_stmt|;
specifier|extern
specifier|__block
name|double
name|extern_var
decl_stmt|;
comment|// expected-error {{__block attribute not allowed, only allowed on local variables}}
specifier|static
specifier|__block
name|char
modifier|*
name|pch
decl_stmt|;
comment|// expected-error {{__block attribute not allowed, only allowed on local variables}}
specifier|__block
name|int
name|a
index|[
name|size
index|]
decl_stmt|;
comment|// expected-error {{__block attribute not allowed on declaration with a variably modified type}}
specifier|__block
name|int
argument_list|(
operator|*
name|ap
argument_list|)
index|[
name|size
index|]
expr_stmt|;
comment|// expected-error {{__block attribute not allowed on declaration with a variably modified type}}
block|}
end_function

begin_function_decl
name|void
name|f
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|test17
parameter_list|()
block|{
name|void
function_decl|(
modifier|^
name|bp
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|rp
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|^
name|bp1
function_decl|)
parameter_list|()
function_decl|;
name|void
modifier|*
name|vp
init|=
name|bp
decl_stmt|;
name|f
argument_list|(
literal|1
condition|?
name|bp
else|:
name|vp
argument_list|)
expr_stmt|;
name|f
argument_list|(
literal|1
condition|?
name|vp
else|:
name|bp
argument_list|)
expr_stmt|;
name|f
argument_list|(
literal|1
condition|?
name|bp
else|:
name|bp1
argument_list|)
expr_stmt|;
call|(
name|void
call|)
argument_list|(
name|bp
operator|>
name|rp
argument_list|)
expr_stmt|;
comment|// expected-error {{invalid operands}}
call|(
name|void
call|)
argument_list|(
name|bp
operator|>
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error {{invalid operands}}
call|(
name|void
call|)
argument_list|(
name|bp
operator|>
name|bp
argument_list|)
expr_stmt|;
comment|// expected-error {{invalid operands}}
call|(
name|void
call|)
argument_list|(
name|bp
operator|>
name|vp
argument_list|)
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|f
argument_list|(
literal|1
condition|?
name|bp
else|:
name|rp
argument_list|)
expr_stmt|;
comment|// expected-error {{incompatible operand types ('void (^)(int)' and 'void (*)(int)')}}
call|(
name|void
call|)
argument_list|(
name|bp
operator|==
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{invalid operands to binary expression}}
call|(
name|void
call|)
argument_list|(
name|bp
operator|==
literal|0
argument_list|)
expr_stmt|;
call|(
name|void
call|)
argument_list|(
literal|1
operator|==
name|bp
argument_list|)
expr_stmt|;
comment|// expected-error {{invalid operands to binary expression}}
call|(
name|void
call|)
argument_list|(
literal|0
operator|==
name|bp
argument_list|)
expr_stmt|;
call|(
name|void
call|)
argument_list|(
name|bp
operator|<
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{invalid operands to binary expression}}
call|(
name|void
call|)
argument_list|(
name|bp
operator|<
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error {{invalid operands to binary expression}}
call|(
name|void
call|)
argument_list|(
literal|1
operator|<
name|bp
argument_list|)
expr_stmt|;
comment|// expected-error {{invalid operands to binary expression}}
call|(
name|void
call|)
argument_list|(
literal|0
operator|<
name|bp
argument_list|)
expr_stmt|;
comment|// expected-error {{invalid operands to binary expression}}
block|}
end_function

begin_function
name|void
name|test18
parameter_list|()
block|{
name|void
argument_list|(
operator|^
specifier|const
name|blockA
argument_list|)
argument_list|(
name|void
argument_list|)
operator|=
lambda|^
block|{ }
expr_stmt|;
name|blockA
operator|=
lambda|^
block|{ }
expr_stmt|;
comment|// expected-error {{read-only variable is not assignable}}
block|}
end_function

begin_comment
comment|// rdar://7072507
end_comment

begin_function
name|int
name|test19
parameter_list|()
block|{
goto|goto
name|L0
goto|;
comment|// expected-error {{illegal goto into protected scope}}
specifier|__block
name|int
name|x
decl_stmt|;
comment|// expected-note {{jump bypasses setup of __block variable}}
name|L0
label|:
name|x
operator|=
literal|0
expr_stmt|;
lambda|^
parameter_list|()
block|{
operator|++
name|x
expr_stmt|;
block|}
argument_list|()
expr_stmt|;
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// radr://7438948
end_comment

begin_function
name|void
name|test20
parameter_list|()
block|{
name|int
name|n
init|=
literal|7
decl_stmt|;
name|int
name|vla
index|[
name|n
index|]
decl_stmt|;
comment|// expected-note {{declared at}}
name|int
argument_list|(
operator|*
name|vm
argument_list|)
index|[
name|n
index|]
operator|=
literal|0
expr_stmt|;
comment|// expected-note {{declared at}}
name|vla
index|[
literal|1
index|]
operator|=
literal|4341
expr_stmt|;
lambda|^
block|{
operator|(
name|void
operator|)
name|vla
index|[
literal|1
index|]
expr_stmt|;
comment|// expected-error {{cannot refer to declaration with a variably modified type inside block}}
call|(
name|void
call|)
argument_list|(
name|vm
operator|+
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{cannot refer to declaration with a variably modified type inside block}}
block|}
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// radr://7438948
end_comment

begin_function
name|void
name|test21
parameter_list|()
block|{
name|int
name|a
index|[
literal|7
index|]
decl_stmt|;
comment|// expected-note {{declared at}}
name|a
index|[
literal|1
index|]
operator|=
literal|1
expr_stmt|;
lambda|^
block|{
operator|(
name|void
operator|)
name|a
index|[
literal|1
index|]
expr_stmt|;
comment|// expected-error {{cannot refer to declaration with an array type inside block}}
block|}
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

