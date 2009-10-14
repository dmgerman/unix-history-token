begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-llvm %s -o - | FileCheck %s
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
comment|// CHECK: addrspace(1)
end_comment

begin_comment
comment|// CHECK: addrspace(2)
end_comment

begin_comment
comment|// CHECK: addrspace(2)
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
comment|// CHECK: addrspace(2)
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
comment|// CHECK: addrspace(2)
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
comment|// CHECK: addrspace(2)
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
comment|// CHECK: addrspace(2)
end_comment

begin_comment
comment|// CHECK: addrspace(2)
end_comment

begin_comment
comment|// Check that we don't lose the address space when accessing an array element
end_comment

begin_comment
comment|// inside a structure.
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

begin_typedef
typedef|typedef
struct|struct
name|S
block|{
name|int
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
name|__addr2
name|S
modifier|*
name|p2
parameter_list|,
name|int
modifier|*
name|val
parameter_list|,
name|int
name|n
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|3
condition|;
operator|++
name|i
control|)
block|{
name|int
name|t
init|=
name|val
index|[
name|i
index|]
decl_stmt|;
name|p1
operator|->
name|arr
index|[
name|i
index|]
operator|=
name|t
expr_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|n
condition|;
operator|++
name|j
control|)
name|p2
index|[
name|j
index|]
operator|.
name|arr
index|[
name|i
index|]
operator|=
name|t
expr_stmt|;
block|}
block|}
end_function

end_unit

