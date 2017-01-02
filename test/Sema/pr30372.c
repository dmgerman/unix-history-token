begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple i386-pc-windows-msvc18.0.0 -disable-free -fms-volatile -fms-extensions -fms-compatibility -fms-compatibility-version=18 -std=c++11 -x c++
end_comment

begin_comment
comment|// Check that the parser catching an 'error' from forward declaration of "location" does not lexer out it's subsequent declation.
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
asm|__asm {
asm|jl         location
asm|location:
asm|ret
asm|}
block|}
end_function

end_unit

