begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-linux-gnu -S -emit-llvm %s -o - | FileCheck %s --check-prefix=CHECK --check-prefix=CHECK-X86-64
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm64-linux-gnu -S -emit-llvm %s -o - | FileCheck %s --check-prefix=CHECK --check-prefix=CHECK-ARM
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7-linux-gnu -target-abi apcs-gnu -S -emit-llvm %s -o - | FileCheck %s --check-prefix=CHECK --check-prefix=CHECK-ARM
end_comment

begin_comment
comment|// CHECK-NOT: @sp = common global
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if

begin_decl_stmt
specifier|register
name|unsigned
name|long
name|current_stack_pointer
name|asm
argument_list|(
literal|"rsp"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|register
name|unsigned
name|long
name|current_stack_pointer
name|asm
argument_list|(
literal|"sp"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|p4_Thread
block|{
struct|struct
block|{
name|int
name|len
decl_stmt|;
block|}
name|word
struct|;
block|}
struct|;
end_struct

begin_comment
comment|// Testing pointer types as well
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if

begin_decl_stmt
specifier|register
name|struct
name|p4_Thread
modifier|*
name|p4TH
name|asm
argument_list|(
literal|"rsp"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|register
name|struct
name|p4_Thread
modifier|*
name|p4TH
name|asm
argument_list|(
literal|"sp"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK: define{{.*}} i[[bits:[0-9]+]] @get_stack_pointer_addr()
end_comment

begin_comment
comment|// CHECK: [[ret:%[0-9]+]] = call i[[bits]] @llvm.read_register.i[[bits]](metadata !0)
end_comment

begin_comment
comment|// CHECK: ret i[[bits]] [[ret]]
end_comment

begin_function
name|unsigned
name|long
name|get_stack_pointer_addr
parameter_list|()
block|{
return|return
name|current_stack_pointer
return|;
block|}
end_function

begin_comment
comment|// CHECK: declare{{.*}} i[[bits]] @llvm.read_register.i[[bits]](metadata)
end_comment

begin_comment
comment|// CHECK: define{{.*}} void @set_stack_pointer_addr(i[[bits]] %addr) #0 {
end_comment

begin_comment
comment|// CHECK: [[sto:%[0-9]+]] = load i[[bits]], i[[bits]]* %
end_comment

begin_comment
comment|// CHECK: call void @llvm.write_register.i[[bits]](metadata !0, i[[bits]] [[sto]])
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|void
name|set_stack_pointer_addr
parameter_list|(
name|unsigned
name|long
name|addr
parameter_list|)
block|{
name|current_stack_pointer
operator|=
name|addr
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: declare{{.*}} void @llvm.write_register.i[[bits]](metadata, i[[bits]])
end_comment

begin_comment
comment|// CHECK: define {{.*}}@fn1
end_comment

begin_function
name|int
name|fn1
parameter_list|()
block|{
return|return
operator|(
operator|*
name|p4TH
operator|)
operator|.
name|word
operator|.
name|len
return|;
block|}
end_function

begin_comment
comment|// CHECK: %[[regr:[0-9]+]] = call i[[bits]] @llvm.read_register.i[[bits]](metadata !0)
end_comment

begin_comment
comment|// CHECK: inttoptr i[[bits]] %[[regr]] to %struct.p4_Thread*
end_comment

begin_comment
comment|// CHECK: define {{.*}}@fn2
end_comment

begin_function
name|void
name|fn2
parameter_list|(
name|struct
name|p4_Thread
modifier|*
name|val
parameter_list|)
block|{
name|p4TH
operator|=
name|val
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: %[[regw:[0-9]+]] = ptrtoint %struct.p4_Thread* %{{.*}} to i[[bits]]
end_comment

begin_comment
comment|// CHECK: call void @llvm.write_register.i[[bits]](metadata !0, i[[bits]] %[[regw]])
end_comment

begin_comment
comment|// CHECK-X86-64: !llvm.named.register.rsp = !{!0}
end_comment

begin_comment
comment|// CHECK-X86-64: !0 = !{!"rsp"}
end_comment

begin_comment
comment|// CHECK-ARM: !llvm.named.register.sp = !{!0}
end_comment

begin_comment
comment|// CHECK-ARM: !0 = !{!"sp"}
end_comment

end_unit

