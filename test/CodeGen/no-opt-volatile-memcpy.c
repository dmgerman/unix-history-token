begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple=x86_64-apple-darwin  -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// rdar://11861085
end_comment

begin_struct
struct|struct
name|s
block|{
name|char
name|filler
index|[
literal|128
index|]
decl_stmt|;
specifier|volatile
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|s
name|gs
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|s
name|ls
decl_stmt|;
name|ls
operator|=
name|ls
expr_stmt|;
name|gs
operator|=
name|gs
expr_stmt|;
name|ls
operator|=
name|gs
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @foo()
end_comment

begin_comment
comment|// CHECK: %[[LS:.*]] = alloca %struct.s, align 4
end_comment

begin_comment
comment|// CHECK-NEXT: %[[ZERO:.*]] = bitcast %struct.s* %[[LS]] to i8*
end_comment

begin_comment
comment|// CHECK-NEXT: %[[ONE:.*]] = bitcast %struct.s* %[[LS]] to i8*
end_comment

begin_comment
comment|// CHECK-NEXT: call void @llvm.memcpy.{{.*}}(i8* %[[ZERO]], i8* %[[ONE]], i64 132, i32 4, i1 true)
end_comment

begin_comment
comment|// CHECK-NEXT: call void @llvm.memcpy.{{.*}}(i8* getelementptr inbounds (%struct.s* @gs, i32 0, i32 0, i32 0), i8* getelementptr inbounds (%struct.s* @gs, i32 0, i32 0, i32 0), i64 132, i32 4, i1 true)
end_comment

begin_comment
comment|// CHECK-NEXT: %[[TWO:.*]] = bitcast %struct.s* %[[LS]] to i8*
end_comment

begin_comment
comment|// CHECK-NEXT: call void @llvm.memcpy.{{.*}}(i8* %[[TWO]], i8* getelementptr inbounds (%struct.s* @gs, i32 0, i32 0, i32 0), i64 132, i32 4, i1 true)
end_comment

begin_struct
struct|struct
name|s1
block|{
name|struct
name|s
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|s1
name|s
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|fee
parameter_list|(
name|void
parameter_list|)
block|{
name|s
operator|=
name|s
expr_stmt|;
name|s
operator|.
name|y
operator|=
name|gs
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @fee()
end_comment

begin_comment
comment|// CHECK: call void @llvm.memcpy.{{.*}}(i8* getelementptr inbounds (%struct.s1* @s, i32 0, i32 0, i32 0, i32 0), i8* getelementptr inbounds (%struct.s1* @s, i32 0, i32 0, i32 0, i32 0), i64 132, i32 4, i1 true)
end_comment

begin_comment
comment|// CHECK-NEXT: call void @llvm.memcpy.{{.*}}(i8* getelementptr inbounds (%struct.s1* @s, i32 0, i32 0, i32 0, i32 0), i8* getelementptr inbounds (%struct.s* @gs, i32 0, i32 0, i32 0), i64 132, i32 4, i1 true)
end_comment

end_unit

