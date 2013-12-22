begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -w -fblocks -triple i386-apple-darwin9 -emit-llvm -o %t %s
end_comment

begin_comment
comment|// RUN: FileCheck< %t %s
end_comment

begin_comment
comment|// CHECK-LABEL: define void @f0(%struct.s0* byval align 4)
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i32(i8* %{{.*}}, i8* %{{.*}}, i32 16, i32 4, i1 false)
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_struct
struct|struct
name|s0
block|{
name|long
name|double
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f0
parameter_list|(
name|struct
name|s0
name|a0
parameter_list|)
block|{
specifier|extern
name|long
name|double
name|f0_g0
decl_stmt|;
name|f0_g0
operator|=
name|a0
operator|.
name|a
expr_stmt|;
block|}
end_function

end_unit

