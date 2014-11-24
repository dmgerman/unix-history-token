begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// Play around with backend reporting:
end_comment

begin_comment
comment|// _REGULAR_: Regular behavior, no warning switch enabled.
end_comment

begin_comment
comment|// _PROMOTE_: Promote warning to error.
end_comment

begin_comment
comment|// _IGNORE_: Drop backend warning.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: not %clang_cc1 %s -mllvm -warn-stack-size=0 -no-integrated-as -S -o - -triple=i386-apple-darwin 2> %t.err
end_comment

begin_comment
comment|// RUN: FileCheck< %t.err %s --check-prefix=REGULAR --check-prefix=ASM
end_comment

begin_comment
comment|// RUN: not %clang_cc1 %s -mllvm -warn-stack-size=0 -no-integrated-as -S -o - -triple=i386-apple-darwin -Werror=frame-larger-than= 2> %t.err
end_comment

begin_comment
comment|// RUN: FileCheck< %t.err %s --check-prefix=PROMOTE --check-prefix=ASM
end_comment

begin_comment
comment|// RUN: not %clang_cc1 %s -mllvm -warn-stack-size=0 -no-integrated-as -S -o - -triple=i386-apple-darwin -Wno-frame-larger-than= 2> %t.err
end_comment

begin_comment
comment|// RUN: FileCheck< %t.err %s --check-prefix=IGNORE --check-prefix=ASM
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -S -o - -triple=i386-apple-darwin -verify -no-integrated-as
end_comment

begin_function_decl
specifier|extern
name|void
name|doIt
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// REGULAR: warning: stack frame size of {{[0-9]+}} bytes in function 'stackSizeWarning'
end_comment

begin_comment
comment|// PROMOTE: error: stack frame size of {{[0-9]+}} bytes in function 'stackSizeWarning'
end_comment

begin_comment
comment|// IGNORE-NOT: stack frame size of {{[0-9]+}} bytes in function 'stackSizeWarning'
end_comment

begin_function
name|void
name|stackSizeWarning
parameter_list|()
block|{
name|char
name|buffer
index|[
literal|80
index|]
decl_stmt|;
name|doIt
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// ASM: inline assembly requires more registers than available
end_comment

begin_function
name|void
name|inlineAsmError
parameter_list|(
name|int
name|x0
parameter_list|,
name|int
name|x1
parameter_list|,
name|int
name|x2
parameter_list|,
name|int
name|x3
parameter_list|,
name|int
name|x4
parameter_list|,
name|int
name|x5
parameter_list|,
name|int
name|x6
parameter_list|,
name|int
name|x7
parameter_list|,
name|int
name|x8
parameter_list|,
name|int
name|x9
parameter_list|)
block|{
asm|__asm__("hello world": : "r" (x0),"r" (x1),"r" (x2),"r" (x3),
comment|// expected-error + {{inline assembly requires more registers than available}}
asm|"r" (x4),"r" (x5),"r" (x6),"r" (x7),"r" (x8),"r" (x9));
block|}
end_function

end_unit

