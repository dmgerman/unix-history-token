begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -std=c11 -fsyntax-only -verify -Wunused-value -Wunused-label %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -std=c11 -fsyntax-only -verify -Wunused %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -std=c11 -fsyntax-only -verify -Wall %s
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
comment|// expected-warning {{expression result unused}} expected-warning {{expression result unused}}
name|i
operator|,
name|foo
argument_list|()
operator|,
name|j
expr_stmt|;
comment|// expected-warning {{expression result unused}} expected-warning {{expression result unused}}
name|foo
argument_list|()
operator|,
name|i
operator|,
name|j
expr_stmt|;
comment|// expected-warning {{expression result unused}} expected-warning {{expression result unused}}
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
name|foo_label
label|:
comment|// expected-warning {{unused label}}
name|i
expr_stmt|;
comment|// expected-warning {{expression result unused}}
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
name|x
operator|||
name|test_logical_foo1
argument_list|()
expr_stmt|;
comment|// no-warning
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// PR8282
end_comment

begin_function
name|void
name|conditional_for_control_flow
parameter_list|(
name|int
name|cond
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
name|cond
condition|?
name|y
operator|++
else|:
name|x
expr_stmt|;
comment|// no-warning
name|cond
condition|?
name|y
else|:
operator|++
name|x
expr_stmt|;
comment|// no-warning
name|cond
condition|?
operator|(
name|x
operator||=
name|y
operator|)
else|:
operator|++
name|x
expr_stmt|;
comment|// no-warning
name|cond
condition|?
name|y
else|:
name|x
expr_stmt|;
comment|// expected-warning {{expression result unused}}
block|}
end_function

begin_struct
struct|struct
name|s0
block|{
name|int
name|f0
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|f0
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f1
parameter_list|(
name|struct
name|s0
modifier|*
name|a
parameter_list|)
block|{
comment|// rdar://8139785
name|f0
argument_list|(
call|(
name|int
call|)
argument_list|(
name|a
operator|->
name|f0
operator|+
literal|1
argument_list|,
literal|10
argument_list|)
argument_list|)
expr_stmt|;
comment|// expected-warning {{expression result unused}}
block|}
end_function

begin_function_decl
name|void
name|blah
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|GenTest
parameter_list|(
name|x
parameter_list|)
value|_Generic(x, default : blah)(x)
end_define

begin_function
name|void
name|unevaluated_operands
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|val
init|=
literal|0
decl_stmt|;
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
operator|++
name|val
argument_list|)
expr_stmt|;
comment|// expected-warning {{expression with side effects has no effect in an unevaluated context}}
operator|(
name|void
operator|)
generic_selection|_Generic(
name|val
operator|++
generic_selection|,
type|default
association|:
literal|0
generic_selection|)
expr_stmt|;
comment|// expected-warning {{expression with side effects has no effect in an unevaluated context}}
operator|(
name|void
operator|)
alignof|_Alignof
argument_list|(
name|val
operator|++
argument_list|)
expr_stmt|;
comment|// expected-warning {{expression with side effects has no effect in an unevaluated context}} expected-warning {{'_Alignof' applied to an expression is a GNU extension}}
comment|// VLAs can have side effects so long as it's part of the type and not
comment|// an expression.
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
name|int
index|[
operator|++
name|val
index|]
argument_list|)
expr_stmt|;
comment|// Ok
operator|(
name|void
operator|)
alignof|_Alignof
argument_list|(
name|int
index|[
operator|++
name|val
index|]
argument_list|)
expr_stmt|;
comment|// Ok
comment|// Side effects as part of macro expansion are ok.
name|GenTest
argument_list|(
name|val
operator|++
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

