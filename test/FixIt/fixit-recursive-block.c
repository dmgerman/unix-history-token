begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10  -Wuninitialized -fblocks -fdiagnostics-parseable-fixits %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10  -Wuninitialized -fblocks -verify %s
end_comment

begin_comment
comment|// rdar://10817031
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
name|void
function_decl|(
modifier|^
name|arc_fail
function_decl|)
parameter_list|()
init|=
lambda|^
parameter_list|()
block|{
comment|// expected-warning {{block pointer variable 'arc_fail' is uninitialized when captured by block}} \
comment|// expected-note {{maybe you meant to use __block 'arc_fail'}}
name|arc_fail
argument_list|()
function_decl|;
comment|// BOOM
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// CHECK: {7:12-7:12}:"__block "
end_comment

end_unit

