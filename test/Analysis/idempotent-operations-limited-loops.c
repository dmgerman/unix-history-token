begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-store=region -analyzer-constraints=range -fblocks -analyzer-opt-analyze-nested-blocks -analyzer-check-objc-mem -analyzer-checker=core.experimental.IdempotentOps -analyzer-max-loop 3 -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-store=region -analyzer-constraints=range -fblocks -analyzer-opt-analyze-nested-blocks -analyzer-check-objc-mem -analyzer-checker=core.experimental.IdempotentOps -analyzer-max-loop 4 -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-store=region -analyzer-constraints=range -fblocks -analyzer-opt-analyze-nested-blocks -analyzer-check-objc-mem -analyzer-checker=core.experimental.IdempotentOps %s -verify
end_comment

begin_function
name|void
name|always_warning
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
literal|0
decl_stmt|;
operator|*
name|p
operator|=
literal|0xDEADBEEF
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-warning{{Dereference of null pointer (loaded from variable 'p')}}
end_comment

begin_comment
comment|// This test case previously caused a bogus idempotent operation warning
end_comment

begin_comment
comment|// due to us not properly culling warnings due to incomplete analysis of loops.
end_comment

begin_function
name|int
name|pr8403
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
name|i
operator|++
control|)
block|{
name|int
name|j
decl_stmt|;
for|for
control|(
name|j
operator|=
literal|0
init|;
name|j
operator|+
literal|1
operator|<
name|i
condition|;
name|j
operator|++
control|)
block|{                 }
block|}
return|return
literal|0
return|;
block|}
end_function

end_unit

