begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin -emit-llvm< %s | FileCheck -check-prefixes=CHECK,X86,GIZ %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple amdgcn -emit-llvm< %s | FileCheck -check-prefixes=CHECK,PIZ %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple amdgcn---amdgiz -emit-llvm< %s | FileCheck -check-prefixes=CHECK,AMDGIZ,GIZ %s
end_comment

begin_comment
comment|// CHECK: @foo = common addrspace(1) global
end_comment

begin_decl_stmt
name|int
name|foo
name|__attribute__
argument_list|(
operator|(
name|address_space
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @ban = common addrspace(1) global
end_comment

begin_decl_stmt
name|int
name|ban
index|[
literal|10
index|]
name|__attribute__
argument_list|(
operator|(
name|address_space
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @a = common global
end_comment

begin_decl_stmt
name|int
name|a
name|__attribute__
argument_list|(
operator|(
name|address_space
argument_list|(
literal|0
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define i32 @test1()
end_comment

begin_comment
comment|// CHECK: load i32, i32 addrspace(1)* @foo
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
comment|// CHECK-LABEL: define i32 @test2(i32 %i)
end_comment

begin_comment
comment|// CHECK: load i32, i32 addrspace(1)*
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
comment|// Both A and B point into addrspace(2).
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(address_space(
literal|2
argument|))
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|A
decl_stmt|,
modifier|*
name|B
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define void @test3()
end_comment

begin_comment
comment|// GIZ: load i32 addrspace(2)*, i32 addrspace(2)** @B
end_comment

begin_comment
comment|// PIZ: load i32 addrspace(2)*, i32 addrspace(2)* addrspace(4)* @B
end_comment

begin_comment
comment|// CHECK: load i32, i32 addrspace(2)*
end_comment

begin_comment
comment|// GIZ: load i32 addrspace(2)*, i32 addrspace(2)** @A
end_comment

begin_comment
comment|// PIZ: load i32 addrspace(2)*, i32 addrspace(2)* addrspace(4)* @A
end_comment

begin_comment
comment|// CHECK: store i32 {{.*}}, i32 addrspace(2)*
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
comment|// PR7437
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|float
name|aData
index|[
literal|1
index|]
decl_stmt|;
block|}
name|MyStruct
typedef|;
end_typedef

begin_comment
comment|// CHECK-LABEL: define void @test4(
end_comment

begin_comment
comment|// GIZ: call void @llvm.memcpy.p0i8.p2i8
end_comment

begin_comment
comment|// GIZ: call void @llvm.memcpy.p2i8.p0i8
end_comment

begin_comment
comment|// PIZ: call void @llvm.memcpy.p4i8.p2i8
end_comment

begin_comment
comment|// PIZ: call void @llvm.memcpy.p2i8.p4i8
end_comment

begin_decl_stmt
name|void
name|test4
argument_list|(
name|MyStruct
name|__attribute__
argument_list|(
operator|(
name|address_space
argument_list|(
literal|2
argument_list|)
operator|)
argument_list|)
operator|*
name|pPtr
argument_list|)
block|{
name|MyStruct
name|s
init|=
name|pPtr
index|[
literal|0
index|]
decl_stmt|;
name|pPtr
index|[
literal|0
index|]
operator|=
name|s
expr_stmt|;
block|}
end_decl_stmt

end_unit

