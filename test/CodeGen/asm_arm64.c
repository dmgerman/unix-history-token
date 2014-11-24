begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-ios -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// rdar://9167275
end_comment

begin_function
name|int
name|t1
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
asm|__asm__("mov %0, 7" : "=r" (x));
return|return
name|x
return|;
block|}
end_function

begin_function
name|long
name|t2
parameter_list|()
block|{
name|long
name|x
decl_stmt|;
asm|__asm__("mov %0, 7" : "=r" (x));
return|return
name|x
return|;
block|}
end_function

begin_function
name|long
name|t3
parameter_list|()
block|{
name|long
name|x
decl_stmt|;
asm|__asm__("mov %w0, 7" : "=r" (x));
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// rdar://9281206
end_comment

begin_function
name|void
name|t4
parameter_list|(
name|long
name|op
parameter_list|)
block|{
name|long
name|x1
decl_stmt|;
asm|asm ("mov x0, %1; svc #0;" : "=r"(x1) :"r"(op),"r"(x1) :"x0" );
block|}
end_function

begin_comment
comment|// rdar://9394290
end_comment

begin_function
name|float
name|t5
parameter_list|(
name|float
name|x
parameter_list|)
block|{
asm|__asm__("fadd %0, %0, %0" : "+w" (x));
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// rdar://9865712
end_comment

begin_function
name|void
name|t6
parameter_list|(
name|void
modifier|*
name|f
parameter_list|,
name|int
name|g
parameter_list|)
block|{
comment|// CHECK: t6
comment|// CHECK: call void asm "str $1, $0", "=*Q,r"
asm|asm("str %1, %0" : "=Q"(f) : "r"(g));
block|}
end_function

end_unit

