begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: addrspace(2)
end_comment

begin_comment
comment|// CHECK: addrspace(3)
end_comment

begin_comment
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(3)
end_comment

begin_comment
comment|// CHECK: addrspace(3)
end_comment

begin_comment
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(3)
end_comment

begin_comment
comment|// CHECK: addrspace(3)
end_comment

begin_comment
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(2)
end_comment

begin_comment
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(2)
end_comment

begin_comment
comment|// CHECK: addrspace(2)
end_comment

begin_comment
comment|// CHECK: addrspace(2)
end_comment

begin_comment
comment|// Check the load and store are using the correct address space to access
end_comment

begin_comment
comment|// the variables.
end_comment

begin_define
define|#
directive|define
name|__addr1
value|__attribute__((address_space(1)))
end_define

begin_define
define|#
directive|define
name|__addr2
value|__attribute__((address_space(2)))
end_define

begin_define
define|#
directive|define
name|__addr3
value|__attribute__((address_space(3)))
end_define

begin_typedef
typedef|typedef
struct|struct
name|Pair
block|{
name|__addr2
name|int
modifier|*
name|a
decl_stmt|;
name|__addr3
name|int
modifier|*
name|b
decl_stmt|;
block|}
name|Pair
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|S
block|{
name|Pair
name|arr
index|[
literal|3
index|]
decl_stmt|;
block|}
name|S
typedef|;
end_typedef

begin_function
name|void
name|test_addrspace
parameter_list|(
name|__addr1
name|S
modifier|*
name|p1
parameter_list|,
name|__addr1
name|S
modifier|*
name|p2
parameter_list|)
block|{
operator|*
name|p1
operator|->
name|arr
index|[
literal|0
index|]
operator|.
name|a
operator|=
operator|*
name|p2
operator|->
name|arr
index|[
literal|1
index|]
operator|.
name|b
expr_stmt|;
block|}
end_function

end_unit

