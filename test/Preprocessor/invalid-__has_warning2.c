begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify %s
end_comment

begin_comment
comment|// These must be the last lines in this test.
end_comment

begin_comment
comment|// expected-error@+1{{expected string literal}} expected-error@+1{{expected}}
end_comment

begin_decl_stmt
name|int
name|i
init|=
name|__has_warning
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

