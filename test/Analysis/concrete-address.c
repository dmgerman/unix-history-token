begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core,alpha.core -analyzer-store=region -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
operator|(
name|int
operator|*
operator|)
literal|0x10000
decl_stmt|;
comment|// Should not crash here.
operator|*
name|p
operator|=
literal|3
expr_stmt|;
block|}
end_function

end_unit

