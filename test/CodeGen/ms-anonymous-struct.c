begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fms-extensions -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: %struct.nested1 = type { i32, i32 }
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nested1
block|{
name|int
name|a1
decl_stmt|;
name|int
name|b1
decl_stmt|;
block|}
name|NESTED1
typedef|;
end_typedef

begin_comment
comment|// CHECK: %struct.nested2 = type { i32, %struct.nested1, i32 }
end_comment

begin_struct
struct|struct
name|nested2
block|{
name|int
name|a
decl_stmt|;
name|NESTED1
expr_stmt|;
name|int
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: %struct.test = type { i32, %struct.nested2, i32 }
end_comment

begin_struct
struct|struct
name|test
block|{
name|int
name|x
decl_stmt|;
struct_decl|struct
name|nested2
struct_decl|;
name|int
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|foo
parameter_list|()
block|{
comment|// CHECK: %var = alloca %struct.test, align 4
name|struct
name|test
name|var
decl_stmt|;
comment|// CHECK: getelementptr inbounds %struct.test* %var, i32 0, i32 1
comment|// CHECK-NEXT: getelementptr inbounds %struct.nested2* %{{.*}}, i32 0, i32 0
comment|// CHECK-NEXT: load i32* %{{.*}}, align 4
name|var
operator|.
name|a
expr_stmt|;
comment|// CHECK-NEXT: getelementptr inbounds %struct.test* %var, i32 0, i32 1
comment|// CHECK-NEXT: getelementptr inbounds %struct.nested2* %{{.*}}, i32 0, i32 2
comment|// CHECK-NEXT: load i32* %{{.*}}, align 4
name|var
operator|.
name|b
expr_stmt|;
comment|// CHECK-NEXT: getelementptr inbounds %struct.test* %var, i32 0, i32 1
comment|// CHECK-NEXT: getelementptr inbounds %struct.nested2* %{{.*}}, i32 0, i32 1
comment|// CHECK-NEXT: getelementptr inbounds %struct.nested1* %{{.*}}, i32 0, i32 0
comment|// CHECK-NEXT: load i32* %{{.*}}, align 4
name|var
operator|.
name|a1
expr_stmt|;
comment|// CHECK-NEXT: getelementptr inbounds %struct.test* %{{.*}}var, i32 0, i32 1
comment|// CHECK-NEXT: getelementptr inbounds %struct.nested2* %{{.*}}, i32 0, i32 1
comment|// CHECK-NEXT: getelementptr inbounds %struct.nested1* %{{.*}}, i32 0, i32 1
comment|// CHECK-NEXT: load i32* %{{.*}}, align 4
name|var
operator|.
name|b1
expr_stmt|;
comment|// CHECK-NEXT: getelementptr inbounds %struct.test* %var, i32 0, i32 0
comment|// CHECK-NEXT: load i32* %{{.*}}, align 4
name|var
operator|.
name|x
expr_stmt|;
comment|// CHECK-NEXT: getelementptr inbounds %struct.test* %var, i32 0, i32 2
comment|// CHECK-NEXT: load i32* %{{.*}}, align 4
name|var
operator|.
name|y
expr_stmt|;
block|}
end_function

begin_function
name|void
name|foo2
parameter_list|(
name|struct
name|test
modifier|*
name|var
parameter_list|)
block|{
comment|// CHECK: alloca %struct.test*, align
comment|// CHECK-NEXT: store %struct.test* %var, %struct.test** %{{.*}}, align
comment|// CHECK-NEXT: load %struct.test** %{{.*}}, align
comment|// CHECK-NEXT: getelementptr inbounds %struct.test* %{{.*}}, i32 0, i32 1
comment|// CHECK-NEXT: getelementptr inbounds %struct.nested2* %{{.*}}, i32 0, i32 0
comment|// CHECK-NEXT: load i32* %{{.*}}, align 4
name|var
operator|->
name|a
expr_stmt|;
comment|// CHECK-NEXT: load %struct.test** %{{.*}}, align
comment|// CHECK-NEXT: getelementptr inbounds %struct.test* %{{.*}}, i32 0, i32 1
comment|// CHECK-NEXT: getelementptr inbounds %struct.nested2* %{{.*}}, i32 0, i32 2
comment|// CHECK-NEXT: load i32* %{{.*}}, align 4
name|var
operator|->
name|b
expr_stmt|;
comment|// CHECK-NEXT: load %struct.test** %{{.*}}, align
comment|// CHECK-NEXT: getelementptr inbounds %struct.test* %{{.*}}, i32 0, i32 1
comment|// CHECK-NEXT: getelementptr inbounds %struct.nested2* %{{.*}}, i32 0, i32 1
comment|// CHECK-NEXT: getelementptr inbounds %struct.nested1* %{{.*}}, i32 0, i32 0
comment|// CHECK-NEXT: load i32* %{{.*}}, align 4
name|var
operator|->
name|a1
expr_stmt|;
comment|// CHECK-NEXT: load %struct.test** %{{.*}}, align
comment|// CHECK-NEXT: getelementptr inbounds %struct.test* %{{.*}}, i32 0, i32 1
comment|// CHECK-NEXT: getelementptr inbounds %struct.nested2* %{{.*}}, i32 0, i32 1
comment|// CHECK-NEXT: getelementptr inbounds %struct.nested1* %{{.*}}, i32 0, i32 1
comment|// CHECK-NEXT: load i32* %{{.*}}, align 4
name|var
operator|->
name|b1
expr_stmt|;
comment|// CHECK-NEXT: load %struct.test** %{{.*}}, align
comment|// CHECK-NEXT: getelementptr inbounds %struct.test* %{{.*}}, i32 0, i32 0
comment|// CHECK-NEXT: load i32* %{{.*}}, align 4
name|var
operator|->
name|x
expr_stmt|;
comment|// CHECK-NEXT: load %struct.test** %{{.*}}, align
comment|// CHECK-NEXT: getelementptr inbounds %struct.test* %{{.*}}, i32 0, i32 2
comment|// CHECK-NEXT: load i32* %{{.*}}, align 4
name|var
operator|->
name|y
expr_stmt|;
block|}
end_function

end_unit

