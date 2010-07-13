begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-idempotent-operation -analyzer-store=region -analyzer-constraints=range -fblocks -verify -analyzer-opt-analyze-nested-blocks -analyzer-check-objc-mem -verify %s
end_comment

begin_comment
comment|// Basic tests
end_comment

begin_function_decl
specifier|extern
name|void
name|test
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|basic
parameter_list|()
block|{
name|int
name|x
init|=
literal|10
decl_stmt|,
name|zero
init|=
literal|0
decl_stmt|,
name|one
init|=
literal|1
decl_stmt|;
comment|// x op x
name|x
operator|=
name|x
expr_stmt|;
comment|// expected-warning {{idempotent operation; both operands are always equal in value}}
name|test
argument_list|(
name|x
operator|-
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{idempotent operation; both operands are always equal in value}}
name|x
operator|-=
name|x
expr_stmt|;
comment|// expected-warning {{idempotent operation; both operands are always equal in value}}
name|x
operator|=
literal|10
expr_stmt|;
comment|// no-warning
name|test
argument_list|(
name|x
operator|/
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{idempotent operation; both operands are always equal in value}}
name|x
operator|/=
name|x
expr_stmt|;
comment|// expected-warning {{idempotent operation; both operands are always equal in value}}
name|x
operator|=
literal|10
expr_stmt|;
comment|// no-warning
name|test
argument_list|(
name|x
operator|&
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{idempotent operation; both operands are always equal in value}}
name|x
operator|&=
name|x
expr_stmt|;
comment|// expected-warning {{idempotent operation; both operands are always equal in value}}
name|test
argument_list|(
name|x
operator||
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{idempotent operation; both operands are always equal in value}}
name|x
operator||=
name|x
expr_stmt|;
comment|// expected-warning {{idempotent operation; both operands are always equal in value}}
comment|// x op 1
name|test
argument_list|(
name|x
operator|*
name|one
argument_list|)
expr_stmt|;
comment|// expected-warning {{idempotent operation; the right operand is always 1}}
name|x
operator|*=
name|one
expr_stmt|;
comment|// expected-warning {{idempotent operation; the right operand is always 1}}
name|test
argument_list|(
name|x
operator|/
name|one
argument_list|)
expr_stmt|;
comment|// expected-warning {{idempotent operation; the right operand is always 1}}
name|x
operator|/=
name|one
expr_stmt|;
comment|// expected-warning {{idempotent operation; the right operand is always 1}}
comment|// 1 op x
name|test
argument_list|(
name|one
operator|*
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{idempotent operation; the left operand is always 1}}
comment|// x op 0
name|test
argument_list|(
name|x
operator|+
name|zero
argument_list|)
expr_stmt|;
comment|// expected-warning {{idempotent operation; the right operand is always 0}}
name|test
argument_list|(
name|x
operator|-
name|zero
argument_list|)
expr_stmt|;
comment|// expected-warning {{idempotent operation; the right operand is always 0}}
name|test
argument_list|(
name|x
operator|*
name|zero
argument_list|)
expr_stmt|;
comment|// expected-warning {{idempotent operation; the right operand is always 0}}
name|test
argument_list|(
name|x
operator|&
name|zero
argument_list|)
expr_stmt|;
comment|// expected-warning {{idempotent operation; the right operand is always 0}}
name|test
argument_list|(
name|x
operator||
name|zero
argument_list|)
expr_stmt|;
comment|// expected-warning {{idempotent operation; the right operand is always 0}}
name|test
argument_list|(
name|x
operator|^
name|zero
argument_list|)
expr_stmt|;
comment|// expected-warning {{idempotent operation; the right operand is always 0}}
name|test
argument_list|(
name|x
operator|<<
name|zero
argument_list|)
expr_stmt|;
comment|// expected-warning {{idempotent operation; the right operand is always 0}}
name|test
argument_list|(
name|x
operator|>>
name|zero
argument_list|)
expr_stmt|;
comment|// expected-warning {{idempotent operation; the right operand is always 0}}
comment|// 0 op x
name|test
argument_list|(
name|zero
operator|+
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{idempotent operation; the left operand is always 0}}
name|test
argument_list|(
name|zero
operator|-
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{idempotent operation; the left operand is always 0}}
name|test
argument_list|(
name|zero
operator|/
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{idempotent operation; the left operand is always 0}}
name|test
argument_list|(
name|zero
operator|*
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{idempotent operation; the left operand is always 0}}
name|test
argument_list|(
name|zero
operator|&
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{idempotent operation; the left operand is always 0}}
name|test
argument_list|(
name|zero
operator||
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{idempotent operation; the left operand is always 0}}
name|test
argument_list|(
name|zero
operator|^
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{idempotent operation; the left operand is always 0}}
name|test
argument_list|(
name|zero
operator|<<
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{idempotent operation; the left operand is always 0}}
name|test
argument_list|(
name|zero
operator|>>
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{idempotent operation; the left operand is always 0}}
block|}
end_function

end_unit

