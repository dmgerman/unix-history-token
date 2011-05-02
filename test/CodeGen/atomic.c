begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -triple=i686-apple-darwin9 | FileCheck %s
end_comment

begin_function
name|int
name|atomic
parameter_list|(
name|void
parameter_list|)
block|{
comment|// non-sensical test for sync functions
name|int
name|old
decl_stmt|;
name|int
name|val
init|=
literal|1
decl_stmt|;
name|char
name|valc
init|=
literal|1
decl_stmt|;
name|_Bool
name|valb
init|=
literal|0
decl_stmt|;
name|unsigned
name|int
name|uval
init|=
literal|1
decl_stmt|;
name|int
name|cmp
init|=
literal|0
decl_stmt|;
name|old
operator|=
name|__sync_fetch_and_add
argument_list|(
operator|&
name|val
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
comment|// CHECK: call i32 @llvm.atomic.load.add.i32.p0i32(i32* %val, i32 1)
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
name|old
operator|=
name|__sync_fetch_and_sub
argument_list|(
operator|&
name|valc
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
comment|// CHECK: call i8 @llvm.atomic.load.sub.i8.p0i8(i8* %valc, i8 2)
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
name|old
operator|=
name|__sync_fetch_and_min
argument_list|(
operator|&
name|val
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
comment|// CHECK: call i32 @llvm.atomic.load.min.i32.p0i32(i32* %val, i32 3)
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
name|old
operator|=
name|__sync_fetch_and_max
argument_list|(
operator|&
name|val
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
comment|// CHECK: call i32 @llvm.atomic.load.max.i32.p0i32(i32* %val, i32 4)
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
name|old
operator|=
name|__sync_fetch_and_umin
argument_list|(
operator|&
name|uval
argument_list|,
literal|5u
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
comment|// CHECK: call i32 @llvm.atomic.load.umin.i32.p0i32(i32* %uval, i32 5)
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
name|old
operator|=
name|__sync_fetch_and_umax
argument_list|(
operator|&
name|uval
argument_list|,
literal|6u
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
comment|// CHECK: call i32 @llvm.atomic.load.umax.i32.p0i32(i32* %uval, i32 6)
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
name|old
operator|=
name|__sync_lock_test_and_set
argument_list|(
operator|&
name|val
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
comment|// CHECK: call i32 @llvm.atomic.swap.i32.p0i32(i32* %val, i32 7)
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
name|old
operator|=
name|__sync_swap
argument_list|(
operator|&
name|val
argument_list|,
literal|8
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
comment|// CHECK: call i32 @llvm.atomic.swap.i32.p0i32(i32* %val, i32 8)
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
name|old
operator|=
name|__sync_val_compare_and_swap
argument_list|(
operator|&
name|val
argument_list|,
literal|4
argument_list|,
literal|1976
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
comment|// CHECK: call i32 @llvm.atomic.cmp.swap.i32.p0i32(i32* %val, i32 4, i32 1976)
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
name|old
operator|=
name|__sync_bool_compare_and_swap
argument_list|(
operator|&
name|val
argument_list|,
literal|4
argument_list|,
literal|1976
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
comment|// CHECK: call i32 @llvm.atomic.cmp.swap.i32.p0i32(i32* %val, i32 4, i32 1976)
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
name|old
operator|=
name|__sync_fetch_and_and
argument_list|(
operator|&
name|val
argument_list|,
literal|0x9
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
comment|// CHECK: call i32 @llvm.atomic.load.and.i32.p0i32(i32* %val, i32 9)
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
name|old
operator|=
name|__sync_fetch_and_or
argument_list|(
operator|&
name|val
argument_list|,
literal|0xa
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
comment|// CHECK: call i32 @llvm.atomic.load.or.i32.p0i32(i32* %val, i32 10)
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
name|old
operator|=
name|__sync_fetch_and_xor
argument_list|(
operator|&
name|val
argument_list|,
literal|0xb
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
comment|// CHECK: call i32 @llvm.atomic.load.xor.i32.p0i32(i32* %val, i32 11)
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
name|old
operator|=
name|__sync_add_and_fetch
argument_list|(
operator|&
name|val
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
comment|// CHECK: call i32 @llvm.atomic.load.add.i32.p0i32(i32* %val, i32 1)
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
name|old
operator|=
name|__sync_sub_and_fetch
argument_list|(
operator|&
name|val
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
comment|// CHECK: call i32 @llvm.atomic.load.sub.i32.p0i32(i32* %val, i32 2)
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
name|old
operator|=
name|__sync_and_and_fetch
argument_list|(
operator|&
name|valc
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
comment|// CHECK: call i8 @llvm.atomic.load.and.i8.p0i8(i8* %valc, i8 3)
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
name|old
operator|=
name|__sync_or_and_fetch
argument_list|(
operator|&
name|valc
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
comment|// CHECK: call i8 @llvm.atomic.load.or.i8.p0i8(i8* %valc, i8 4)
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
name|old
operator|=
name|__sync_xor_and_fetch
argument_list|(
operator|&
name|valc
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
comment|// CHECK: call i8 @llvm.atomic.load.xor.i8.p0i8(i8* %valc, i8 5)
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
name|__sync_val_compare_and_swap
argument_list|(
operator|(
name|void
operator|*
operator|*
operator|)
literal|0
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
comment|// CHECK: call i32 @llvm.atomic.cmp.swap.i32.p0i32(i32* null, i32 0, i32 0)
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
if|if
condition|(
name|__sync_val_compare_and_swap
argument_list|(
operator|&
name|valb
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
condition|)
block|{
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
comment|// CHECK: call i8 @llvm.atomic.cmp.swap.i8.p0i8(i8* %valb, i8 0, i8 1)
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
name|old
operator|=
literal|42
expr_stmt|;
block|}
name|__sync_bool_compare_and_swap
argument_list|(
operator|(
name|void
operator|*
operator|*
operator|)
literal|0
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
comment|// CHECK: call i32 @llvm.atomic.cmp.swap.i32.p0i32(i32* null, i32 0, i32 0)
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
name|__sync_lock_release
argument_list|(
operator|&
name|val
argument_list|)
expr_stmt|;
comment|// CHECK: volatile store i32 0, i32*
name|__sync_synchronize
argument_list|()
expr_stmt|;
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 false)
return|return
name|old
return|;
block|}
end_function

begin_comment
comment|// CHECK: @release_return
end_comment

begin_function
name|void
name|release_return
parameter_list|(
name|int
modifier|*
name|lock
parameter_list|)
block|{
comment|// Ensure this is actually returning void all the way through.
return|return
name|__sync_lock_release
argument_list|(
name|lock
argument_list|)
return|;
comment|// CHECK: volatile store i32 0, i32*
block|}
end_function

begin_comment
comment|// rdar://8461279 - Atomics with address spaces.
end_comment

begin_comment
comment|// CHECK: @addrspace
end_comment

begin_decl_stmt
name|void
name|addrspace
argument_list|(
name|int
name|__attribute__
argument_list|(
operator|(
name|address_space
argument_list|(
literal|256
argument_list|)
operator|)
argument_list|)
operator|*
name|P
argument_list|)
block|{
name|__sync_bool_compare_and_swap
argument_list|(
name|P
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
comment|// CHECK: call i32 @llvm.atomic.cmp.swap.i32.p256i32(i32 addrspace(256)*{{.*}}, i32 0, i32 1)
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
name|__sync_val_compare_and_swap
argument_list|(
name|P
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
comment|// CHECK: call i32 @llvm.atomic.cmp.swap.i32.p256i32(i32 addrspace(256)*{{.*}}, i32 0, i32 1)
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
name|__sync_xor_and_fetch
argument_list|(
name|P
argument_list|,
literal|123
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
comment|// CHECK: call i32 @llvm.atomic.load.xor.i32.p256i32(i32 addrspace(256)* {{.*}}, i32 123)
comment|// CHECK: call void @llvm.memory.barrier(i1 true, i1 true, i1 true, i1 true, i1 true)
block|}
end_decl_stmt

end_unit

