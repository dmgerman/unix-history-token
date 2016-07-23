begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-elfiamcu -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: target datalayout = "e-m:e-p:32:32-i64:32-f64:32-f128:32-n8:16:32-a:0:32-S32"
end_comment

begin_comment
comment|// CHECK: target triple = "i386-pc-elfiamcu"
end_comment

begin_function_decl
name|void
name|food
parameter_list|(
name|double
modifier|*
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fooll
parameter_list|(
name|long
name|long
modifier|*
name|ll
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fooull
parameter_list|(
name|unsigned
name|long
name|long
modifier|*
name|ull
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|foold
parameter_list|(
name|long
name|double
modifier|*
name|ld
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK-LABEL: define void @testdouble()
end_comment

begin_comment
comment|// CHECK: alloca double, align 4
end_comment

begin_function
name|void
name|testdouble
parameter_list|()
block|{
name|double
name|d
init|=
literal|2.0
decl_stmt|;
name|food
argument_list|(
operator|&
name|d
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @testlonglong()
end_comment

begin_comment
comment|// CHECK: alloca i64, align 4
end_comment

begin_function
name|void
name|testlonglong
parameter_list|()
block|{
name|long
name|long
name|ll
init|=
literal|2
decl_stmt|;
name|fooll
argument_list|(
operator|&
name|ll
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @testunsignedlonglong()
end_comment

begin_comment
comment|// CHECK: alloca i64, align 4
end_comment

begin_function
name|void
name|testunsignedlonglong
parameter_list|()
block|{
name|unsigned
name|long
name|long
name|ull
init|=
literal|2
decl_stmt|;
name|fooull
argument_list|(
operator|&
name|ull
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @testlongdouble()
end_comment

begin_comment
comment|// CHECK: alloca double, align 4
end_comment

begin_function
name|void
name|testlongdouble
parameter_list|()
block|{
name|long
name|double
name|ld
init|=
literal|2.0
decl_stmt|;
name|foold
argument_list|(
operator|&
name|ld
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

