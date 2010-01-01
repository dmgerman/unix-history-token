begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm< %s -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK:%struct.S = type { i32, i32 }
end_comment

begin_comment
comment|// CHECK:define void @test_addrspace(%struct.S addrspace(1)* %p1, %struct.S addrspace(2)* %p2) nounwind
end_comment

begin_comment
comment|// CHECK:  [[p1addr:%.*]] = alloca %struct.S addrspace(1)*       ;<%struct.S addrspace(1)**> [#uses=3]
end_comment

begin_comment
comment|// CHECK:  [[p2addr:%.*]] = alloca %struct.S addrspace(2)*       ;<%struct.S addrspace(2)**> [#uses=3]
end_comment

begin_comment
comment|// CHECK:  store %struct.S addrspace(1)* %p1, %struct.S addrspace(1)** [[p1addr]]
end_comment

begin_comment
comment|// CHECK:  store %struct.S addrspace(2)* %p2, %struct.S addrspace(2)** [[p2addr]]
end_comment

begin_comment
comment|// CHECK:  [[t0:%.*]] = load %struct.S addrspace(2)** [[p2addr]]   ;<%struct.S addrspace(2)*> [#uses=1]
end_comment

begin_comment
comment|// CHECK:  [[t1:%.*]] = getelementptr inbounds %struct.S addrspace(2)* [[t0]], i32 0, i32 1 ;<i32 addrspace(2)*> [#uses=1]
end_comment

begin_comment
comment|// CHECK:  [[t2:%.*]] = load i32 addrspace(2)* [[t1]]            ;<i32> [#uses=1]
end_comment

begin_comment
comment|// CHECK:  [[t3:%.*]] = load %struct.S addrspace(1)** [[p1addr]]  ;<%struct.S addrspace(1)*> [#uses=1]
end_comment

begin_comment
comment|// CHECK:  [[t4:%.*]] = getelementptr inbounds %struct.S addrspace(1)* [[t3]], i32 0, i32 0 ;<i32 addrspace(1)*> [#uses=1]
end_comment

begin_comment
comment|// CHECK:  store i32 [[t2]], i32 addrspace(1)* [[t4]]
end_comment

begin_comment
comment|// CHECK:  [[t5:%.*]] = load %struct.S addrspace(2)** [[p2addr]]  ;<%struct.S addrspace(2)*> [#uses=1]
end_comment

begin_comment
comment|// CHECK:  [[t6:%.*]] = getelementptr inbounds %struct.S addrspace(2)* [[t5]], i32 0, i32 0 ;<i32 addrspace(2)*> [#uses=1]
end_comment

begin_comment
comment|// CHECK:  [[t7:%.*]] = load i32 addrspace(2)* [[t6]]            ;<i32> [#uses=1]
end_comment

begin_comment
comment|// CHECK:  [[t8:%.*]] = load %struct.S addrspace(1)** [[p1addr]]  ;<%struct.S addrspace(1)*> [#uses=1]
end_comment

begin_comment
comment|// CHECK:  [[t9:%.*]] = getelementptr inbounds %struct.S addrspace(1)* [[t8]], i32 0, i32 1 ;<i32 addrspace(1)*> [#uses=1]
end_comment

begin_comment
comment|// CHECK:  store i32 [[t7]], i32 addrspace(1)* [[t9]]
end_comment

begin_comment
comment|// CHECK:  ret void
end_comment

begin_comment
comment|// CHECK:}
end_comment

begin_comment
comment|// Check that we don't lose the address space when accessing a member
end_comment

begin_comment
comment|// of a structure.
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
name|a
decl_stmt|;
name|int
name|b
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
parameter_list|)
block|{
comment|// swap
name|p1
operator|->
name|a
operator|=
name|p2
operator|->
name|b
expr_stmt|;
name|p1
operator|->
name|b
operator|=
name|p2
operator|->
name|a
expr_stmt|;
block|}
end_function

end_unit

