begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple amdgcn -emit-llvm< %s | FileCheck -check-prefixes=PIZ,COM %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple amdgcn---amdgiz -emit-llvm< %s | FileCheck -check-prefixes=CHECK,COM %s
end_comment

begin_comment
comment|// PIZ-DAG: @foo = common addrspace(1) global i32 0
end_comment

begin_comment
comment|// CHECK-DAG: @foo = common addrspace(1) global i32 0
end_comment

begin_decl_stmt
name|int
name|foo
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PIZ-DAG: @ban = common addrspace(1) global [10 x i32] zeroinitializer
end_comment

begin_comment
comment|// CHECK-DAG: @ban = common addrspace(1) global [10 x i32] zeroinitializer
end_comment

begin_decl_stmt
name|int
name|ban
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PIZ-DAG: @A = common addrspace(1) global i32 addrspace(4)* null
end_comment

begin_comment
comment|// PIZ-DAG: @B = common addrspace(1) global i32 addrspace(4)* null
end_comment

begin_comment
comment|// CHECK-DAG: @A = common addrspace(1) global i32* null
end_comment

begin_comment
comment|// CHECK-DAG: @B = common addrspace(1) global i32* null
end_comment

begin_decl_stmt
name|int
modifier|*
name|A
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|B
decl_stmt|;
end_decl_stmt

begin_comment
comment|// COM-LABEL: define i32 @test1()
end_comment

begin_comment
comment|// PIZ: load i32, i32 addrspace(4)* addrspacecast{{[^@]+}} @foo
end_comment

begin_comment
comment|// CHECK: load i32, i32* addrspacecast{{[^@]+}} @foo
end_comment

begin_function
name|int
name|test1
parameter_list|()
block|{
return|return
name|foo
return|;
block|}
end_function

begin_comment
comment|// COM-LABEL: define i32 @test2(i32 %i)
end_comment

begin_comment
comment|// COM: %[[addr:.*]] = getelementptr
end_comment

begin_comment
comment|// PIZ: load i32, i32 addrspace(4)* %[[addr]]
end_comment

begin_comment
comment|// PIZ-NEXT: ret i32
end_comment

begin_comment
comment|// CHECK: load i32, i32* %[[addr]]
end_comment

begin_comment
comment|// CHECK-NEXT: ret i32
end_comment

begin_function
name|int
name|test2
parameter_list|(
name|int
name|i
parameter_list|)
block|{
return|return
name|ban
index|[
name|i
index|]
return|;
block|}
end_function

begin_comment
comment|// COM-LABEL: define void @test3()
end_comment

begin_comment
comment|// PIZ: load i32 addrspace(4)*, i32 addrspace(4)* addrspace(4)* addrspacecast{{[^@]+}} @B
end_comment

begin_comment
comment|// PIZ: load i32, i32 addrspace(4)*
end_comment

begin_comment
comment|// PIZ: load i32 addrspace(4)*, i32 addrspace(4)* addrspace(4)* addrspacecast{{[^@]+}} @A
end_comment

begin_comment
comment|// PIZ: store i32 {{.*}}, i32 addrspace(4)*
end_comment

begin_comment
comment|// CHECK: load i32*, i32** addrspacecast{{.*}} @B
end_comment

begin_comment
comment|// CHECK: load i32, i32*
end_comment

begin_comment
comment|// CHECK: load i32*, i32** addrspacecast{{.*}} @A
end_comment

begin_comment
comment|// CHECK: store i32 {{.*}}, i32*
end_comment

begin_function
name|void
name|test3
parameter_list|()
block|{
operator|*
name|A
operator|=
operator|*
name|B
expr_stmt|;
block|}
end_function

begin_comment
comment|// PIZ-LABEL: define void @test4(i32 addrspace(4)* %a)
end_comment

begin_comment
comment|// PIZ: %[[alloca:.*]] = alloca i32 addrspace(4)*
end_comment

begin_comment
comment|// PIZ: %[[a_addr:.*]] = addrspacecast{{.*}} %[[alloca]] to i32 addrspace(4)* addrspace(4)*
end_comment

begin_comment
comment|// PIZ: store i32 addrspace(4)* %a, i32 addrspace(4)* addrspace(4)* %[[a_addr]]
end_comment

begin_comment
comment|// PIZ: %[[r0:.*]] = load i32 addrspace(4)*, i32 addrspace(4)* addrspace(4)* %[[a_addr]]
end_comment

begin_comment
comment|// PIZ: %[[arrayidx:.*]] = getelementptr inbounds i32, i32 addrspace(4)* %[[r0]]
end_comment

begin_comment
comment|// PIZ: store i32 0, i32 addrspace(4)* %[[arrayidx]]
end_comment

begin_comment
comment|// CHECK-LABEL: define void @test4(i32* %a)
end_comment

begin_comment
comment|// CHECK: %[[alloca:.*]] = alloca i32*, align 8, addrspace(5)
end_comment

begin_comment
comment|// CHECK: %[[a_addr:.*]] = addrspacecast{{.*}} %[[alloca]] to i32**
end_comment

begin_comment
comment|// CHECK: store i32* %a, i32** %[[a_addr]]
end_comment

begin_comment
comment|// CHECK: %[[r0:.*]] = load i32*, i32** %[[a_addr]]
end_comment

begin_comment
comment|// CHECK: %[[arrayidx:.*]] = getelementptr inbounds i32, i32* %[[r0]]
end_comment

begin_comment
comment|// CHECK: store i32 0, i32* %[[arrayidx]]
end_comment

begin_function
name|void
name|test4
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{
name|a
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
block|}
end_function

end_unit

