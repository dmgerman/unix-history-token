begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple i386-pc-windows-msvc -fms-extensions -S -o - | FileCheck %s
end_comment

begin_comment
comment|// Yes, this is an assembly test from Clang, because we need to make it all the
end_comment

begin_comment
comment|// way through code generation to know if our call became a direct, pc-relative
end_comment

begin_comment
comment|// call or an indirect call through memory.
end_comment

begin_function_decl
name|int
name|k
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_function_decl
name|int
name|kimport
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
function_decl|(
modifier|*
name|kptr
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|int
argument_list|(
operator|*
name|gptr
argument_list|()
argument_list|)
argument_list|(
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|foo
parameter_list|()
block|{
comment|// CHECK-LABEL: _foo:
name|int
function_decl|(
modifier|*
name|r
function_decl|)
parameter_list|(
name|int
parameter_list|)
init|=
name|gptr
argument_list|()
function_decl|;
comment|// Simple case: direct call.
asm|__asm call k;
comment|// CHECK:     calll   _k
comment|// Marginally harder: indirect calls, via dllimport or function pointer.
asm|__asm call r;
comment|// CHECK:     calll   *({{.*}})
asm|__asm call kimport;
comment|// CHECK:     calll   *({{.*}})
comment|// Broken case: Call through a global function pointer.
asm|__asm call kptr;
comment|// CHECK:     calll   _kptr
comment|// CHECK-FIXME: calll   *_kptr
block|}
end_function

begin_function
name|int
name|bar
parameter_list|()
block|{
comment|// CHECK-LABEL: _bar:
asm|__asm jmp k;
comment|// CHECK:     jmp     _k
block|}
end_function

begin_function
name|int
name|baz
parameter_list|()
block|{
comment|// CHECK-LABEL: _baz:
asm|__asm mov eax, k;
comment|// CHECK: movl    _k, %eax
asm|__asm mov eax, kptr;
comment|// CHECK: movl    _kptr, %eax
block|}
end_function

begin_comment
comment|// Test that this asm blob doesn't require more registers than available.  This
end_comment

begin_comment
comment|// has to be an LLVM code generation test.
end_comment

begin_function
name|void
name|__declspec
parameter_list|(
name|naked
parameter_list|)
function|naked
parameter_list|()
block|{
asm|__asm pusha
asm|__asm call k
asm|__asm popa
asm|__asm ret
comment|// CHECK-LABEL: _naked:
comment|// CHECK: pushal
comment|// CHECK-NEXT: calll _k
comment|// CHECK-NEXT: popal
comment|// CHECK-NEXT: retl
block|}
end_function

end_unit

