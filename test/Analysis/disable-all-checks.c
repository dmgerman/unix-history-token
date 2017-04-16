begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core -analyzer-store=region -analyzer-disable-all-checks -verify %s
end_comment

begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-disable-all-checks -analyzer-checker=core -analyzer-store=region -verify %s
end_comment

begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-disable-all-checks -verify %s
end_comment

begin_comment
comment|// RUN: not %clang_analyze_cc1 -analyzer-checker=core -analyzer-store=region -analyzer-disable-checker -verify %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|// CHECK: use -analyzer-disable-all-checks to disable all static analyzer checkers
end_comment

begin_function
name|int
name|buggy
parameter_list|()
block|{
name|int
name|x
init|=
literal|0
decl_stmt|;
return|return
literal|5
operator|/
name|x
return|;
comment|// no warning
block|}
end_function

end_unit

