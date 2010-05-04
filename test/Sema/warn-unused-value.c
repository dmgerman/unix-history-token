begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -Wunused-value %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -Wunused %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -Wall %s
end_comment

begin_decl_stmt
name|int
name|i
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|j
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// PR4806
end_comment

begin_function
name|void
name|pr4806
parameter_list|()
block|{
literal|1
operator|,
name|foo
argument_list|()
expr_stmt|;
comment|// expected-warning {{expression result unused}}
comment|// other
name|foo
argument_list|()
expr_stmt|;
name|i
expr_stmt|;
comment|// expected-warning {{expression result unused}}
name|i
operator|,
name|foo
argument_list|()
expr_stmt|;
comment|// expected-warning {{expression result unused}}
name|foo
argument_list|()
operator|,
name|i
expr_stmt|;
comment|// expected-warning {{expression result unused}}
name|i
operator|,
name|j
operator|,
name|foo
argument_list|()
expr_stmt|;
comment|// expected-warning {{expression result unused}}
name|i
operator|,
name|foo
argument_list|()
operator|,
name|j
expr_stmt|;
comment|// expected-warning {{expression result unused}}
name|foo
argument_list|()
operator|,
name|i
operator|,
name|j
expr_stmt|;
comment|// expected-warning {{expression result unused}}
name|i
operator|++
expr_stmt|;
name|i
operator|++
operator|,
name|foo
argument_list|()
expr_stmt|;
name|foo
argument_list|()
operator|,
name|i
operator|++
expr_stmt|;
name|i
operator|++
operator|,
name|j
operator|,
name|foo
argument_list|()
expr_stmt|;
comment|// expected-warning {{expression result unused}}
name|i
operator|++
operator|,
name|foo
argument_list|()
operator|,
name|j
expr_stmt|;
comment|// expected-warning {{expression result unused}}
name|foo
argument_list|()
operator|,
name|i
operator|++
operator|,
name|j
expr_stmt|;
comment|// expected-warning {{expression result unused}}
name|i
operator|,
name|j
operator|++
operator|,
name|foo
argument_list|()
expr_stmt|;
comment|// expected-warning {{expression result unused}}
name|i
operator|,
name|foo
argument_list|()
operator|,
name|j
operator|++
expr_stmt|;
comment|// expected-warning {{expression result unused}}
name|foo
argument_list|()
operator|,
name|i
operator|,
name|j
operator|++
expr_stmt|;
comment|// expected-warning {{expression result unused}}
name|i
operator|++
operator|,
name|j
operator|++
operator|,
name|foo
argument_list|()
expr_stmt|;
name|i
operator|++
operator|,
name|foo
argument_list|()
operator|,
name|j
operator|++
expr_stmt|;
name|foo
argument_list|()
operator|,
name|i
operator|++
operator|,
name|j
operator|++
expr_stmt|;
block|{}
empty_stmt|;
operator|(
block|{}
operator|)
expr_stmt|;
operator|(
block|{}
operator|)
operator|,
name|foo
argument_list|()
expr_stmt|;
name|foo
argument_list|()
operator|,
operator|(
block|{}
operator|)
expr_stmt|;
operator|(
name|int
operator|)
literal|1U
expr_stmt|;
comment|// expected-warning {{expression result unused}}
operator|(
name|void
operator|)
literal|1U
expr_stmt|;
comment|// pointer to volatile has side effect (thus no warning)
name|int
modifier|*
name|pi
init|=
operator|&
name|i
decl_stmt|;
specifier|volatile
name|int
modifier|*
name|pj
init|=
operator|&
name|j
decl_stmt|;
operator|*
name|pi
expr_stmt|;
comment|// expected-warning {{expression result unused}}
operator|*
name|pj
expr_stmt|;
block|}
end_function

begin_comment
comment|// Don't warn about unused '||', '&&' expressions that contain assignments.
end_comment

begin_function_decl
name|int
name|test_logical_foo1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|test_logical_foo2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|test_logical_foo3
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|test_logical_bar
parameter_list|()
block|{
name|int
name|x
init|=
literal|0
decl_stmt|;
operator|(
name|x
operator|=
name|test_logical_foo1
argument_list|()
operator|)
operator|||
comment|// no-warning
operator|(
name|x
operator|=
name|test_logical_foo2
argument_list|()
operator|)
operator|||
comment|// no-warning
operator|(
name|x
operator|=
name|test_logical_foo3
argument_list|()
operator|)
expr_stmt|;
comment|// no-warning
return|return
name|x
return|;
block|}
end_function

end_unit

