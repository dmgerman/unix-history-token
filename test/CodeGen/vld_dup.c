begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: arm-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7a-linux-gnueabi \
end_comment

begin_comment
comment|// RUN:   -target-cpu cortex-a8 \
end_comment

begin_comment
comment|// RUN:   -emit-llvm -o - %s | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|int
name|main
parameter_list|()
block|{
name|int32_t
name|v0
index|[
literal|3
index|]
decl_stmt|;
name|int32x2x3_t
name|v1
decl_stmt|;
name|int32_t
name|v2
index|[
literal|4
index|]
decl_stmt|;
name|int32x2x4_t
name|v3
decl_stmt|;
name|int64x1x3_t
name|v4
decl_stmt|;
name|int64x1x4_t
name|v5
decl_stmt|;
name|int64_t
name|v6
index|[
literal|3
index|]
decl_stmt|;
name|int64_t
name|v7
index|[
literal|4
index|]
decl_stmt|;
name|v1
operator|=
name|vld3_dup_s32
argument_list|(
name|v0
argument_list|)
expr_stmt|;
comment|// CHECK: [[T168:%.*]] = call {<2 x i32>,<2 x i32>,<2 x i32> } @llvm.arm.neon.vld3lane.v2i32(i8* {{.*}},<2 x i32> undef,<2 x i32> undef,<2 x i32> undef, i32 {{[0-9]+}}, i32 {{[0-9]+}})
comment|// CHECK-NEXT: [[T169:%.*]] = extractvalue {<2 x i32>,<2 x i32>,<2 x i32> } [[T168]], 0
comment|// CHECK-NEXT: [[T170:%.*]] = shufflevector<2 x i32> [[T169]],<2 x i32> [[T169]],<2 x i32> zeroinitializer
comment|// CHECK-NEXT: [[T171:%.*]] = insertvalue {<2 x i32>,<2 x i32>,<2 x i32> } [[T168]],<2 x i32> [[T170]], 0
comment|// CHECK-NEXT: [[T172:%.*]] = extractvalue {<2 x i32>,<2 x i32>,<2 x i32> } [[T171]], 1
comment|// CHECK-NEXT: [[T173:%.*]] = shufflevector<2 x i32> [[T172]],<2 x i32> [[T172]],<2 x i32> zeroinitializer
comment|// CHECK-NEXT: [[T174:%.*]] = insertvalue {<2 x i32>,<2 x i32>,<2 x i32> } [[T171]],<2 x i32> [[T173]], 1
comment|// CHECK-NEXT: [[T175:%.*]] = extractvalue {<2 x i32>,<2 x i32>,<2 x i32> } [[T174]], 2
comment|// CHECK-NEXT: [[T176:%.*]] = shufflevector<2 x i32> [[T175]],<2 x i32> [[T175]],<2 x i32> zeroinitializer
comment|// CHECK-NEXT: [[T177:%.*]] = insertvalue {<2 x i32>,<2 x i32>,<2 x i32> } [[T174]],<2 x i32> [[T176]], 2
name|v3
operator|=
name|vld4_dup_s32
argument_list|(
name|v2
argument_list|)
expr_stmt|;
comment|// CHECK: [[T178:%.*]] = call {<2 x i32>,<2 x i32>,<2 x i32>,<2 x i32> } @llvm.arm.neon.vld4lane.v2i32(i8* {{.*}},<2 x i32> undef,<2 x i32> undef,<2 x i32> undef,<2 x i32> undef, i32 {{[0-9]+}}, i32 {{[0-9]+}})
comment|// CHECK-NEXT: [[T179:%.*]] = extractvalue {<2 x i32>,<2 x i32>,<2 x i32>,<2 x i32> } [[T178]], 0
comment|// CHECK-NEXT: [[T180:%.*]] = shufflevector<2 x i32> [[T179]],<2 x i32> [[T179]],<2 x i32> zeroinitializer
comment|// CHECK-NEXT: [[T181:%.*]] = insertvalue {<2 x i32>,<2 x i32>,<2 x i32>,<2 x i32> } [[T178]],<2 x i32> [[T180]], 0
comment|// CHECK-NEXT: [[T182:%.*]] = extractvalue {<2 x i32>,<2 x i32>,<2 x i32>,<2 x i32> } [[T181]], 1
comment|// CHECK-NEXT: [[T183:%.*]] = shufflevector<2 x i32> [[T182]],<2 x i32> [[T182]],<2 x i32> zeroinitializer
comment|// CHECK-NEXT: [[T184:%.*]] = insertvalue {<2 x i32>,<2 x i32>,<2 x i32>,<2 x i32> } [[T181]],<2 x i32> [[T183]], 1
comment|// CHECK-NEXT: [[T185:%.*]] = extractvalue {<2 x i32>,<2 x i32>,<2 x i32>,<2 x i32> } [[T184]], 2
comment|// CHECK-NEXT: [[T186:%.*]] = shufflevector<2 x i32> [[T185]],<2 x i32> [[T185]],<2 x i32> zeroinitializer
comment|// CHECK-NEXT: [[T187:%.*]] = insertvalue {<2 x i32>,<2 x i32>,<2 x i32>,<2 x i32> } [[T184]],<2 x i32> [[T186]], 2
comment|// CHECK-NEXT: [[T188:%.*]] = extractvalue {<2 x i32>,<2 x i32>,<2 x i32>,<2 x i32> } [[T187]], 3
comment|// CHECK-NEXT: [[T189:%.*]] = shufflevector<2 x i32> [[T188]],<2 x i32> [[T188]],<2 x i32> zeroinitializer
comment|// CHECK-NEXT: [[T190:%.*]] = insertvalue {<2 x i32>,<2 x i32>,<2 x i32>,<2 x i32> } [[T187]],<2 x i32> [[T189]], 3
name|v4
operator|=
name|vld3_dup_s64
argument_list|(
name|v6
argument_list|)
expr_stmt|;
comment|// CHECK: {{%.*}} = call {<1 x i64>,<1 x i64>,<1 x i64> } @llvm.arm.neon.vld3.v1i64(i8* {{.*}}, i32 {{[0-9]+}})
name|v5
operator|=
name|vld4_dup_s64
argument_list|(
name|v7
argument_list|)
expr_stmt|;
comment|// CHECK: {{%.*}} = call {<1 x i64>,<1 x i64>,<1 x i64>,<1 x i64> } @llvm.arm.neon.vld4.v1i64(i8* {{.*}}, i32 {{[0-9]+}})
return|return
literal|0
return|;
block|}
end_function

end_unit

