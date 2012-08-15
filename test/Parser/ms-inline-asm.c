begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fms-extensions
end_comment

begin_define
define|#
directive|define
name|M
value|__asm int 0x2c
end_define

begin_define
define|#
directive|define
name|M2
value|int
end_define

begin_function
name|void
name|t1
parameter_list|(
name|void
parameter_list|)
block|{
name|M
block|}
end_function

begin_comment
comment|// expected-warning {{MS-style inline assembly is not supported}}
end_comment

begin_function
name|void
name|t2
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm int 0x2c
block|}
end_function

begin_comment
comment|// expected-warning {{MS-style inline assembly is not supported}}
end_comment

begin_function
name|void
name|t3
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm M2 0x2c
block|}
end_function

begin_comment
comment|// expected-warning {{MS-style inline assembly is not supported}}
end_comment

begin_function
name|void
modifier|*
name|t4
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm mov eax, fs:[0x10]
block|}
end_function

begin_comment
comment|// expected-warning {{MS-style inline assembly is not supported}}
end_comment

begin_function
name|void
name|t5
parameter_list|()
block|{
asm|__asm {
comment|//
asm|expected-warning {{MS-style inline assembly is not supported}}
asm|int 0x2c ;
asm|}
name|asm
name|comments
name|are
name|fun
operator|!
block|}
end_function

begin_block
block|{   }
end_block

begin_asm
asm|__asm {}
end_asm

begin_comment
comment|// no warning as this gets merged with the previous inline asm
end_comment

begin_macro
unit|} int
name|t6
argument_list|()
end_macro

begin_block
block|{
asm|__asm int 3 ;
block|}
end_block

begin_macro
name|comments
end_macro

begin_for
for|for single-line asm
comment|// expected-warning {{MS-style inline assembly is not supported}}
asm|__asm {}
comment|// no warning as this gets merged with the previous inline asm
asm|__asm int 4
comment|//
asm|no warning as this gets merged with the previous inline asm
for|return 10
empty_stmt|;
end_for

begin_macro
unit|} int
name|t7
argument_list|()
end_macro

begin_block
block|{
asm|__asm {
comment|//
asm|expected-warning {{MS-style inline assembly is not supported}}
asm|push ebx
asm|mov ebx, 0x07
asm|pop ebx
asm|}
block|}
end_block

begin_function
name|void
name|t8
parameter_list|()
block|{
asm|__asm nop
asm|__asm nop
asm|__asm nop
comment|//
asm|expected-warning {{MS-style inline assembly is not supported}}
block|}
end_function

begin_function
name|void
name|t9
parameter_list|()
block|{
asm|__asm nop
asm|__asm nop ;
asm|__asm nop
comment|//
asm|expected-warning {{MS-style inline assembly is not supported}}
block|}
end_function

begin_function
name|int
name|t_fail
parameter_list|()
block|{
end_function

begin_comment
comment|// expected-note {{to match this}}
end_comment

begin_asm
asm|__asm
end_asm

begin_asm
asm|__asm {
comment|//
asm|expected-error 3 {{expected}} expected-note {{to match this}}
end_asm

end_unit

