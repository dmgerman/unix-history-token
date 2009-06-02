begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -fsyntax-only -verify -fmath-errno=0 %s
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
comment|// expected-warning {{expression result unused}}
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
block|}
end_function

end_unit

