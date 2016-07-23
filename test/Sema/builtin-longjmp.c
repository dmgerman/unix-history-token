begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -emit-llvm< %s| FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm< %s| FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-windows -emit-llvm< %s| FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc-unknown-unknown -emit-llvm< %s| FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-unknown-unknown -emit-llvm< %s| FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple sparc-eabi-unknown -emit-llvm< %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple aarch64-unknown-unknown -emit-llvm-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips-unknown-unknown -emit-llvm-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips64-unknown-unknown -emit-llvm-only -verify %s
end_comment

begin_comment
comment|// Check that __builtin_longjmp and __builtin_setjmp are lowered into
end_comment

begin_comment
comment|// IR intrinsics on those architectures that can handle them.
end_comment

begin_comment
comment|// Check that an error is created otherwise.
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|jmp_buf
typedef|;
end_typedef

begin_decl_stmt
name|jmp_buf
name|buf
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK:   define{{.*}} void @do_jump()
end_comment

begin_comment
comment|// CHECK:   call{{.*}} void @llvm.eh.sjlj.longjmp
end_comment

begin_comment
comment|// CHECK:   define{{.*}} void @do_setjmp()
end_comment

begin_comment
comment|// CHECK:   call{{.*}} i32 @llvm.eh.sjlj.setjmp
end_comment

begin_function
name|void
name|do_jump
parameter_list|(
name|void
parameter_list|)
block|{
name|__builtin_longjmp
argument_list|(
name|buf
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{__builtin_longjmp is not supported for the current target}}
block|}
end_function

begin_function_decl
name|void
name|f
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|do_setjmp
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
operator|!
name|__builtin_setjmp
argument_list|(
name|buf
argument_list|)
condition|)
comment|// expected-error {{__builtin_setjmp is not supported for the current target}}
name|f
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

