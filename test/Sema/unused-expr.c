begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -fno-math-errno %s
end_comment

begin_function_decl
name|int
name|foo
parameter_list|(
name|int
name|X
parameter_list|,
name|int
name|Y
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|sqrt
parameter_list|(
name|double
name|X
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// implicitly const because of -fno-math-errno!
end_comment

begin_function
name|void
name|bar
parameter_list|(
specifier|volatile
name|int
modifier|*
name|VP
parameter_list|,
name|int
modifier|*
name|P
parameter_list|,
name|int
name|A
parameter_list|,
specifier|_Complex
name|double
name|C
parameter_list|,
specifier|volatile
specifier|_Complex
name|double
name|VC
parameter_list|)
block|{
name|VP
operator|==
name|P
expr_stmt|;
comment|// expected-warning {{expression result unused}}
operator|(
name|void
operator|)
name|A
expr_stmt|;
operator|(
name|void
operator|)
name|foo
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// no warning.
name|A
operator|==
name|foo
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// expected-warning {{expression result unused}}
name|foo
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
operator|+
name|foo
argument_list|(
literal|4
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// expected-warning {{expression result unused}}
operator|*
name|P
expr_stmt|;
comment|// expected-warning {{expression result unused}}
operator|*
name|VP
expr_stmt|;
comment|// no warning.
name|P
index|[
literal|4
index|]
expr_stmt|;
comment|// expected-warning {{expression result unused}}
name|VP
index|[
literal|4
index|]
expr_stmt|;
comment|// no warning.
name|__real__
name|C
decl_stmt|;
comment|// expected-warning {{expression result unused}}
name|__real__
name|VC
decl_stmt|;
comment|// We know this can't change errno because of -fno-math-errno.
name|sqrt
argument_list|(
name|A
argument_list|)
expr_stmt|;
comment|// expected-warning {{ignoring return value of function declared with const attribute}}
block|}
end_function

begin_function_decl
specifier|extern
name|void
name|t1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|t2
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|t3
parameter_list|(
name|int
name|c
parameter_list|)
block|{
name|c
condition|?
name|t1
argument_list|()
else|:
name|t2
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// This shouldn't warn: the expr at the end of the stmtexpr really is used.
end_comment

begin_function
name|int
name|stmt_expr
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
return|return
operator|(
block|{
name|int
name|_a
operator|=
name|x
block|,
name|_b
operator|=
name|y
block|;
name|_a
operator|>
name|_b
condition|?
name|_a
else|:
name|_b
block|; }
operator|)
return|;
block|}
end_function

begin_function
name|void
name|nowarn
parameter_list|(
name|unsigned
name|char
modifier|*
name|a
parameter_list|,
name|unsigned
name|char
modifier|*
name|b
parameter_list|)
block|{
name|unsigned
name|char
name|c
init|=
literal|1
decl_stmt|;
operator|*
name|a
operator||=
name|c
operator|,
operator|*
name|b
operator|+=
name|c
expr_stmt|;
comment|// PR4633
name|int
name|y
decl_stmt|,
name|x
decl_stmt|;
operator|(
operator|(
name|void
operator|)
literal|0
operator|)
operator|,
name|y
operator|=
name|x
expr_stmt|;
block|}
end_function

begin_function
name|void
name|t4
parameter_list|(
name|int
name|a
parameter_list|)
block|{
name|int
name|b
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|a
condition|)
name|b
operator|==
literal|1
expr_stmt|;
comment|// expected-warning{{expression result unused}}
else|else
name|b
operator|==
literal|2
expr_stmt|;
comment|// expected-warning{{expression result unused}}
while|while
condition|(
literal|1
condition|)
name|b
operator|==
literal|3
expr_stmt|;
comment|// expected-warning{{expression result unused}}
do|do
name|b
operator|==
literal|4
expr_stmt|;
comment|// expected-warning{{expression result unused}}
do|while
condition|(
literal|1
condition|)
do|;
for|for
control|(
init|;
condition|;
control|)
name|b
operator|==
literal|5
expr_stmt|;
comment|// expected-warning{{expression result unused}}
for|for
control|(
name|b
operator|==
literal|1
init|;
condition|;
control|)
block|{}
comment|// expected-warning{{expression result unused}}
for|for
control|(
init|;
name|b
operator|==
literal|1
condition|;
control|)
block|{}
for|for
control|(
init|;
condition|;
name|b
operator|==
literal|1
control|)
block|{}
comment|// expected-warning{{expression result unused}}
block|}
end_function

begin_comment
comment|// rdar://7186119
end_comment

begin_function_decl
name|int
name|t5f
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(warn_unused_result
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|t5
parameter_list|()
block|{
name|t5f
argument_list|()
expr_stmt|;
comment|// expected-warning {{ignoring return value of function declared with warn_unused_result}}
block|}
end_function

begin_function_decl
name|int
name|fn1
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(warn_unused_result
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|fn2
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(pure
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|fn3
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(const
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// rdar://6587766
end_comment

begin_function
name|int
name|t6
parameter_list|()
block|{
if|if
condition|(
name|fn1
argument_list|()
operator|<
literal|0
operator|||
name|fn2
argument_list|(
literal|2
argument_list|,
literal|1
argument_list|)
operator|<
literal|0
operator|||
name|fn3
argument_list|(
literal|2
argument_list|)
operator|<
literal|0
condition|)
comment|// no warnings
return|return
operator|-
literal|1
return|;
name|fn1
argument_list|()
expr_stmt|;
comment|// expected-warning {{ignoring return value of function declared with warn_unused_result attribute}}
name|fn2
argument_list|(
literal|92
argument_list|,
literal|21
argument_list|)
expr_stmt|;
comment|// expected-warning {{ignoring return value of function declared with pure attribute}}
name|fn3
argument_list|(
literal|42
argument_list|)
expr_stmt|;
comment|// expected-warning {{ignoring return value of function declared with const attribute}}
name|__builtin_fabsf
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning {{ignoring return value of function declared with const attribute}}
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
name|int
name|t7
name|__attribute__
argument_list|(
operator|(
name|warn_unused_result
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'warn_unused_result' attribute only applies to function types}}
end_comment

begin_comment
comment|// PR4010
end_comment

begin_function_decl
name|int
function_decl|(
modifier|*
name|fn4
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(warn_unused_result
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|t8
parameter_list|()
block|{
name|fn4
argument_list|()
expr_stmt|;
comment|// expected-warning {{ignoring return value of function declared with warn_unused_result attribute}}
block|}
end_function

begin_function_decl
name|void
name|t9
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(warn_unused_result
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning {{attribute 'warn_unused_result' cannot be applied to functions without return value}}
end_comment

end_unit

