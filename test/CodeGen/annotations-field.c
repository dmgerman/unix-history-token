begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// END.
end_comment

begin_comment
comment|// CHECK: private unnamed_addr constant [8 x i8] c"v_ann_{{.}}\00", section "llvm.metadata"
end_comment

begin_comment
comment|// CHECK: private unnamed_addr constant [8 x i8] c"v_ann_{{.}}\00", section "llvm.metadata"
end_comment

begin_struct
struct|struct
name|foo
block|{
name|int
name|v
name|__attribute__
argument_list|(
operator|(
name|annotate
argument_list|(
literal|"v_ann_0"
argument_list|)
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|annotate
argument_list|(
literal|"v_ann_1"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|foo
name|gf
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|struct
name|foo
name|f
decl_stmt|;
name|f
operator|.
name|v
operator|=
name|argc
expr_stmt|;
comment|// CHECK: getelementptr inbounds %struct.foo* %f, i32 0, i32 0
comment|// CHECK-NEXT: bitcast i32* {{.*}} to i8*
comment|// CHECK-NEXT: call i8* @llvm.ptr.annotation.p0i8({{.*}}str{{.*}}str{{.*}}i32 8)
comment|// CHECK-NEXT: bitcast i8* {{.*}} to i32*
comment|// CHECK-NEXT: bitcast i32* {{.*}} to i8*
comment|// CHECK-NEXT: call i8* @llvm.ptr.annotation.p0i8({{.*}}str{{.*}}str{{.*}}i32 8)
comment|// CHECK-NEXT: bitcast i8* {{.*}} to i32*
name|gf
operator|.
name|v
operator|=
name|argc
expr_stmt|;
comment|// CHECK: bitcast i32* getelementptr inbounds (%struct.foo* @gf, i32 0, i32 0) to i8*
comment|// CHECK-NEXT: call i8* @llvm.ptr.annotation.p0i8({{.*}}str{{.*}}str{{.*}}i32 8)
return|return
literal|0
return|;
block|}
end_function

end_unit

