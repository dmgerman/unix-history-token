begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-store=region -analyzer-constraints=range -fblocks -analyzer-opt-analyze-nested-blocks -analyzer-check-objc-mem -analyzer-checker=core.experimental.IdempotentOps -verify %s
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

begin_function_decl
specifier|extern
name|void
name|test_f
parameter_list|(
name|float
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|unsigned
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
comment|// expected-warning {{Assigned value is always the same as the existing value}}
name|test
argument_list|(
name|x
operator|-
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{Both operands to '-' always have the same value}}
name|x
operator|-=
name|x
expr_stmt|;
comment|// expected-warning {{Both operands to '-=' always have the same value}}
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
comment|// expected-warning {{Both operands to '/' always have the same value}}
name|x
operator|/=
name|x
expr_stmt|;
comment|// expected-warning {{Both operands to '/=' always have the same value}}
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
comment|// expected-warning {{Both operands to '&' always have the same value}}
name|x
operator|&=
name|x
expr_stmt|;
comment|// expected-warning {{Both operands to '&=' always have the same value}}
name|test
argument_list|(
name|x
operator||
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{Both operands to '|' always have the same value}}
name|x
operator||=
name|x
expr_stmt|;
comment|// expected-warning {{Both operands to '|=' always have the same value}}
comment|// x op 1
name|test
argument_list|(
name|x
operator|*
name|one
argument_list|)
expr_stmt|;
comment|// expected-warning {{The right operand to '*' is always 1}}
name|x
operator|*=
name|one
expr_stmt|;
comment|// expected-warning {{The right operand to '*=' is always 1}}
name|test
argument_list|(
name|x
operator|/
name|one
argument_list|)
expr_stmt|;
comment|// expected-warning {{The right operand to '/' is always 1}}
name|x
operator|/=
name|one
expr_stmt|;
comment|// expected-warning {{The right operand to '/=' is always 1}}
comment|// 1 op x
name|test
argument_list|(
name|one
operator|*
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{The left operand to '*' is always 1}}
comment|// x op 0
name|test
argument_list|(
name|x
operator|+
name|zero
argument_list|)
expr_stmt|;
comment|// expected-warning {{The right operand to '+' is always 0}}
name|test
argument_list|(
name|x
operator|-
name|zero
argument_list|)
expr_stmt|;
comment|// expected-warning {{The right operand to '-' is always 0}}
name|test
argument_list|(
name|x
operator|*
name|zero
argument_list|)
expr_stmt|;
comment|// expected-warning {{The right operand to '*' is always 0}}
name|test
argument_list|(
name|x
operator|&
name|zero
argument_list|)
expr_stmt|;
comment|// expected-warning {{The right operand to '&' is always 0}}
name|test
argument_list|(
name|x
operator||
name|zero
argument_list|)
expr_stmt|;
comment|// expected-warning {{The right operand to '|' is always 0}}
name|test
argument_list|(
name|x
operator|^
name|zero
argument_list|)
expr_stmt|;
comment|// expected-warning {{The right operand to '^' is always 0}}
name|test
argument_list|(
name|x
operator|<<
name|zero
argument_list|)
expr_stmt|;
comment|// expected-warning {{The right operand to '<<' is always 0}}
name|test
argument_list|(
name|x
operator|>>
name|zero
argument_list|)
expr_stmt|;
comment|// expected-warning {{The right operand to '>>' is always 0}}
comment|// 0 op x
name|test
argument_list|(
name|zero
operator|+
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{The left operand to '+' is always 0}}
name|test
argument_list|(
name|zero
operator|-
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{The left operand to '-' is always 0}}
name|test
argument_list|(
name|zero
operator|/
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{The left operand to '/' is always 0}}
name|test
argument_list|(
name|zero
operator|*
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{The left operand to '*' is always 0}}
name|test
argument_list|(
name|zero
operator|&
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{The left operand to '&' is always 0}}
name|test
argument_list|(
name|zero
operator||
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{The left operand to '|' is always 0}}
name|test
argument_list|(
name|zero
operator|^
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{The left operand to '^' is always 0}}
name|test
argument_list|(
name|zero
operator|<<
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{The left operand to '<<' is always 0}}
name|test
argument_list|(
name|zero
operator|>>
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{The left operand to '>>' is always 0}}
comment|// Overwrite the values so these aren't marked as Pseudoconstants
name|x
operator|=
literal|1
expr_stmt|;
name|zero
operator|=
literal|2
expr_stmt|;
name|one
operator|=
literal|3
expr_stmt|;
return|return
name|x
operator|+
name|zero
operator|+
name|one
return|;
block|}
end_function

begin_function
name|void
name|floats
parameter_list|(
name|float
name|x
parameter_list|)
block|{
name|test_f
argument_list|(
name|x
operator|*
literal|1.0
argument_list|)
expr_stmt|;
comment|// no-warning
name|test_f
argument_list|(
name|x
operator|*
literal|1.0F
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// Ensure that we don't report false poitives in complex loops
end_comment

begin_function
name|void
name|bailout
parameter_list|()
block|{
name|int
name|unused
init|=
literal|0
decl_stmt|,
name|result
init|=
literal|4
decl_stmt|;
name|result
operator|=
name|result
expr_stmt|;
comment|// expected-warning {{Assigned value is always the same as the existing value}}
for|for
control|(
name|unsigned
name|bg
init|=
literal|0
init|;
name|bg
operator|<
literal|1024
condition|;
name|bg
operator|++
control|)
block|{
name|result
operator|=
name|bg
operator|*
name|result
expr_stmt|;
comment|// no-warning
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|256
condition|;
name|i
operator|++
control|)
block|{
name|unused
operator|*=
name|i
expr_stmt|;
comment|// no-warning
block|}
block|}
block|}
end_function

begin_comment
comment|// Relaxed liveness - check that we don't kill liveness at assignments
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|uintptr_t
typedef|;
end_typedef

begin_function
name|void
name|kill_at_assign
parameter_list|()
block|{
name|short
name|array
index|[
literal|2
index|]
decl_stmt|;
name|uintptr_t
name|x
init|=
name|array
decl_stmt|;
comment|// expected-warning{{incompatible pointer to integer conversion}}
name|short
modifier|*
name|p
init|=
name|x
decl_stmt|;
comment|// expected-warning{{incompatible integer to pointer conversion}}
comment|// The following branch should be infeasible.
if|if
condition|(
operator|!
operator|(
name|p
operator|=
operator|&
name|array
index|[
literal|0
index|]
operator|)
condition|)
block|{
comment|// expected-warning{{Assigned value is always the same as the existing value}}
name|p
operator|=
literal|0
expr_stmt|;
operator|*
name|p
operator|=
literal|1
expr_stmt|;
comment|// no-warning
block|}
block|}
end_function

begin_comment
comment|// False positive tests
end_comment

begin_function
name|unsigned
name|false1
parameter_list|()
block|{
name|int
name|a
init|=
literal|10
decl_stmt|;
return|return
name|a
operator|*
operator|(
literal|5
operator|-
literal|2
operator|-
literal|3
operator|)
return|;
comment|// no-warning
block|}
end_function

begin_enum
enum|enum
name|testenum
block|{
name|enum1
init|=
literal|0
block|,
name|enum2
block|}
enum|;
end_enum

begin_function
name|unsigned
name|false2
parameter_list|()
block|{
name|int
name|a
init|=
literal|1234
decl_stmt|;
return|return
name|enum1
operator|+
name|a
return|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// Self assignments of unused variables are common false positives
end_comment

begin_function
name|unsigned
name|false3
parameter_list|(
name|int
name|param
parameter_list|,
name|int
name|param2
parameter_list|)
block|{
name|param
operator|=
name|param
expr_stmt|;
comment|// no-warning
comment|// if a self assigned variable is used later, then it should be reported still
name|param2
operator|=
name|param2
expr_stmt|;
comment|// expected-warning{{Assigned value is always the same as the existing value}}
name|unsigned
name|nonparam
init|=
literal|5
decl_stmt|;
name|nonparam
operator|=
name|nonparam
expr_stmt|;
comment|// expected-warning{{Assigned value is always the same as the existing value}}
return|return
name|param2
operator|+
name|nonparam
return|;
block|}
end_function

begin_comment
comment|// Pseudo-constants (vars only read) and constants should not be reported
end_comment

begin_function
name|unsigned
name|false4
parameter_list|()
block|{
comment|// Trivial constant
specifier|const
name|int
name|height
init|=
literal|1
decl_stmt|;
name|int
name|c
init|=
literal|42
decl_stmt|;
name|test
argument_list|(
name|height
operator|*
name|c
argument_list|)
expr_stmt|;
comment|// no-warning
comment|// Pseudo-constant (never changes after decl)
name|int
name|width
init|=
name|height
decl_stmt|;
return|return
name|width
operator|*
literal|10
return|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// Block pseudoconstants
end_comment

begin_function
name|void
name|false4a
parameter_list|()
block|{
comment|// Pseudo-constant
specifier|__block
name|int
name|a
init|=
literal|1
decl_stmt|;
name|int
name|b
init|=
literal|10
decl_stmt|;
specifier|__block
name|int
name|c
init|=
literal|0
decl_stmt|;
name|b
operator|*=
name|a
expr_stmt|;
comment|// no-warning
lambda|^
block|{
comment|// Psuedoconstant block var
name|test
argument_list|(
name|b
operator|*
name|c
argument_list|)
expr_stmt|;
comment|// no-warning
comment|// Non-pseudoconstant block var
name|int
name|d
init|=
literal|0
decl_stmt|;
name|test
argument_list|(
name|b
operator|*
name|d
argument_list|)
expr_stmt|;
comment|// expected-warning{{The right operand to '*' is always 0}}
name|d
operator|=
literal|5
expr_stmt|;
name|test
argument_list|(
name|d
argument_list|)
expr_stmt|;
block|}
argument_list|()
expr_stmt|;
name|test
argument_list|(
name|a
operator|+
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Static vars are common false positives
end_comment

begin_function
name|int
name|false5
parameter_list|()
block|{
specifier|static
name|int
name|test
init|=
literal|0
decl_stmt|;
name|int
name|a
init|=
literal|56
decl_stmt|;
name|a
operator|*=
name|test
expr_stmt|;
comment|// no-warning
name|test
operator|++
expr_stmt|;
return|return
name|a
return|;
block|}
end_function

begin_comment
comment|// Non-local storage vars are considered false positives
end_comment

begin_decl_stmt
name|int
name|globalInt
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|false6
parameter_list|()
block|{
name|int
name|localInt
init|=
literal|23
decl_stmt|;
name|localInt
operator|/=
name|globalInt
expr_stmt|;
return|return
name|localInt
return|;
block|}
end_function

begin_comment
comment|// Check that assignments filter out false positives correctly
end_comment

begin_function
name|int
name|false7
parameter_list|()
block|{
name|int
name|zero
init|=
literal|0
decl_stmt|;
comment|// psuedo-constant
name|int
name|one
init|=
literal|1
decl_stmt|;
name|int
name|a
init|=
literal|55
decl_stmt|;
name|a
operator|=
name|a
expr_stmt|;
comment|// expected-warning{{Assigned value is always the same as the existing value}}
name|a
operator|=
name|enum1
operator|*
name|a
expr_stmt|;
comment|// no-warning
name|int
name|b
init|=
literal|123
decl_stmt|;
name|b
operator|=
name|b
expr_stmt|;
comment|// no-warning
return|return
name|a
return|;
block|}
end_function

begin_comment
comment|// Check truncations do not flag as self-assignments
end_comment

begin_function
name|void
name|false8
parameter_list|()
block|{
name|int
name|a
init|=
literal|10000000
decl_stmt|;
name|a
operator|=
operator|(
name|short
operator|)
name|a
expr_stmt|;
comment|// no-warning
name|test
argument_list|(
name|a
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// This test case previously flagged a warning at 'b == c' because the
end_comment

begin_comment
comment|// analyzer previously allowed 'UnknownVal' as the index for ElementRegions.
end_comment

begin_typedef
typedef|typedef
struct|struct
name|RDar8431728_F
block|{
name|int
name|RDar8431728_A
decl_stmt|;
name|unsigned
name|char
modifier|*
name|RDar8431728_B
decl_stmt|;
name|int
name|RDar8431728_E
index|[
literal|6
index|]
decl_stmt|;
block|}
name|RDar8431728_D
typedef|;
end_typedef

begin_function
specifier|static
specifier|inline
name|int
name|RDar8431728_C
parameter_list|(
name|RDar8431728_D
modifier|*
name|s
parameter_list|,
name|int
name|n
parameter_list|,
name|unsigned
name|char
modifier|*
modifier|*
name|RDar8431728_B_ptr
parameter_list|)
block|{
name|int
name|xy
decl_stmt|,
name|wrap
decl_stmt|,
name|pred
decl_stmt|,
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|;
name|xy
operator|=
name|s
operator|->
name|RDar8431728_E
index|[
name|n
index|]
expr_stmt|;
name|wrap
operator|=
name|s
operator|->
name|RDar8431728_A
expr_stmt|;
name|a
operator|=
name|s
operator|->
name|RDar8431728_B
index|[
name|xy
operator|-
literal|1
index|]
expr_stmt|;
name|b
operator|=
name|s
operator|->
name|RDar8431728_B
index|[
name|xy
operator|-
literal|1
operator|-
name|wrap
index|]
expr_stmt|;
name|c
operator|=
name|s
operator|->
name|RDar8431728_B
index|[
name|xy
operator|-
name|wrap
index|]
expr_stmt|;
if|if
condition|(
name|b
operator|==
name|c
condition|)
block|{
comment|// no-warning
name|pred
operator|=
name|a
expr_stmt|;
block|}
else|else
block|{
name|pred
operator|=
name|c
expr_stmt|;
block|}
operator|*
name|RDar8431728_B_ptr
operator|=
operator|&
name|s
operator|->
name|RDar8431728_B
index|[
name|xy
index|]
expr_stmt|;
return|return
name|pred
return|;
block|}
end_function

begin_comment
comment|//<rdar://problem/8601243> - Don't warn on pointer arithmetic.  This
end_comment

begin_comment
comment|// is often idiomatic.
end_comment

begin_function_decl
name|unsigned
name|rdar8601243_aux
parameter_list|(
name|unsigned
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|rdar8601243
parameter_list|()
block|{
name|char
name|arr
index|[
literal|100
index|]
decl_stmt|;
name|char
modifier|*
name|start
init|=
name|arr
decl_stmt|;
name|start
operator|=
name|start
operator|+
name|rdar8601243_aux
argument_list|(
sizeof|sizeof
argument_list|(
name|arr
argument_list|)
operator|-
operator|(
name|arr
operator|-
name|start
operator|)
argument_list|)
expr_stmt|;
comment|// no-warning
operator|(
name|void
operator|)
name|start
expr_stmt|;
block|}
end_function

end_unit

