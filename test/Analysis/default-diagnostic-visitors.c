begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -triple x86_64-apple-darwin10 -analyzer-checker=core -analyzer-store=region -analyzer-output=text -verify %s
end_comment

begin_comment
comment|// This file is for testing enhanced diagnostics produced by the default BugReporterVisitors.
end_comment

begin_function
name|int
name|getPasswordAndItem
parameter_list|()
block|{
name|int
name|err
init|=
literal|0
decl_stmt|;
name|int
modifier|*
name|password
decl_stmt|;
comment|// expected-note {{'password' declared without an initial value}}
if|if
condition|(
name|password
operator|==
literal|0
condition|)
block|{
comment|// expected-warning {{The left operand of '==' is a garbage value}} // expected-note {{The left operand of '==' is a garbage value}}
name|err
operator|=
operator|*
name|password
expr_stmt|;
block|}
return|return
name|err
return|;
block|}
end_function

end_unit

