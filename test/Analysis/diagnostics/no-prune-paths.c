begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core -analyzer-output=text -verify %s
end_comment

begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core -analyzer-output=text -analyzer-config prune-paths=false -DNPRUNE=1 -verify %s
end_comment

begin_comment
comment|// "prune-paths" is a debug option only; this is just a simple test to see that
end_comment

begin_comment
comment|// it's being honored.
end_comment

begin_function
name|void
name|helper
parameter_list|()
block|{
specifier|extern
name|void
name|foo
parameter_list|()
function_decl|;
name|foo
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test
parameter_list|()
block|{
name|helper
argument_list|()
expr_stmt|;
if|#
directive|if
name|NPRUNE
comment|// expected-note@-2 {{Calling 'helper'}}
comment|// expected-note@-3 {{Returning from 'helper'}}
endif|#
directive|endif
operator|*
operator|(
specifier|volatile
name|int
operator|*
operator|)
literal|0
operator|=
literal|1
expr_stmt|;
comment|// expected-warning {{Dereference of null pointer}}
comment|// expected-note@-1 {{Dereference of null pointer}}
block|}
end_function

end_unit

