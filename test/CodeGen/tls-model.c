begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple x86_64-pc-linux-gnu -emit-llvm -o - | FileCheck %s -check-prefix=CHECK-GD
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple x86_64-pc-linux-gnu -ftls-model=global-dynamic -emit-llvm -o - | FileCheck %s -check-prefix=CHECK-GD
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple x86_64-pc-linux-gnu -ftls-model=local-dynamic -emit-llvm -o - | FileCheck %s -check-prefix=CHECK-LD
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple x86_64-pc-linux-gnu -ftls-model=initial-exec -emit-llvm -o - | FileCheck %s -check-prefix=CHECK-IE
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple x86_64-pc-linux-gnu -ftls-model=local-exec -emit-llvm -o - | FileCheck %s -check-prefix=CHECK-LE
end_comment

begin_decl_stmt
name|int
name|__thread
name|x
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|f
parameter_list|()
block|{
specifier|static
name|int
name|__thread
name|y
decl_stmt|;
return|return
name|y
operator|++
return|;
block|}
end_function

begin_decl_stmt
name|int
name|__thread
name|__attribute__
argument_list|(
operator|(
name|tls_model
argument_list|(
literal|"initial-exec"
argument_list|)
operator|)
argument_list|)
name|z
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-GD: @f.y = internal thread_local global i32 0
end_comment

begin_comment
comment|// CHECK-GD: @x = thread_local global i32 0
end_comment

begin_comment
comment|// CHECK-GD: @z = thread_local(initialexec) global i32 0
end_comment

begin_comment
comment|// CHECK-LD: @f.y = internal thread_local(localdynamic) global i32 0
end_comment

begin_comment
comment|// CHECK-LD: @x = thread_local(localdynamic) global i32 0
end_comment

begin_comment
comment|// CHECK-LD: @z = thread_local(initialexec) global i32 0
end_comment

begin_comment
comment|// CHECK-IE: @f.y = internal thread_local(initialexec) global i32 0
end_comment

begin_comment
comment|// CHECK-IE: @x = thread_local(initialexec) global i32 0
end_comment

begin_comment
comment|// CHECK-IE: @z = thread_local(initialexec) global i32 0
end_comment

begin_comment
comment|// CHECK-LE: @f.y = internal thread_local(localexec) global i32 0
end_comment

begin_comment
comment|// CHECK-LE: @x = thread_local(localexec) global i32 0
end_comment

begin_comment
comment|// CHECK-LE: @z = thread_local(initialexec) global i32 0
end_comment

end_unit

