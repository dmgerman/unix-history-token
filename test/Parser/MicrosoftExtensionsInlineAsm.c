begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-mingw32 -fsyntax-only -verify -fms-extensions  %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_function
name|void
name|__forceinline
name|InterlockedBitTestAndSet
parameter_list|(
name|long
modifier|*
name|Base
parameter_list|,
name|long
name|Bit
parameter_list|)
block|{
asm|__asm {
asm|mov eax, Bit
asm|mov ecx, Base
asm|lock bts [ecx], eax
asm|setc al
asm|};
block|}
end_function

end_unit

