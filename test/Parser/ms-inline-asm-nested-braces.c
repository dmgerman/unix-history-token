begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple i386-apple-darwin10 -verify -fasm-blocks
end_comment

begin_function
name|int
name|t_fail
parameter_list|()
block|{
comment|// expected-note {{to match this}}
asm|__asm
block|{
comment|// expected-note {{to match this}}
block|{
comment|// expected-note {{to match this}}
block|{       }
end_function

begin_comment
comment|// expected-error 3 {{expected}}
end_comment

end_unit

