begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core,alpha.core -std=gnu99 -analyzer-store=region -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|// The store for 'a[1]' should not be removed mistakenly. SymbolicRegions may
end_comment

begin_comment
comment|// also be live roots.
end_comment

begin_function
name|void
name|f14
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|a
index|[
literal|1
index|]
operator|=
literal|1
expr_stmt|;
name|i
operator|=
name|a
index|[
literal|1
index|]
expr_stmt|;
if|if
condition|(
name|i
operator|!=
literal|1
condition|)
block|{
name|int
modifier|*
name|p
init|=
literal|0
decl_stmt|;
name|i
operator|=
operator|*
name|p
expr_stmt|;
comment|// no-warning
block|}
block|}
end_function

end_unit

