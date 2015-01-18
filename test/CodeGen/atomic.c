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
name|int
modifier|*
name|ptrval
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
comment|// CHECK: atomicrmw add i32* %val, i32 1 seq_cst
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
comment|// CHECK: atomicrmw sub i8* %valc, i8 2 seq_cst
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
comment|// CHECK: atomicrmw min i32* %val, i32 3 seq_cst
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
comment|// CHECK: atomicrmw max i32* %val, i32 4 seq_cst
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
comment|// CHECK: atomicrmw umin i32* %uval, i32 5 seq_cst
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
comment|// CHECK: atomicrmw umax i32* %uval, i32 6 seq_cst
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
comment|// CHECK: atomicrmw xchg i32* %val, i32 7 seq_cst
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
comment|// CHECK: atomicrmw xchg i32* %val, i32 8 seq_cst
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
comment|// CHECK: [[PAIR:%[a-z0-9_.]+]] = cmpxchg i32* %val, i32 4, i32 1976 seq_cst
comment|// CHECK: extractvalue { i32, i1 } [[PAIR]], 0
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
comment|// CHECK: [[PAIR:%[a-z0-9_.]+]] = cmpxchg i32* %val, i32 4, i32 1976 seq_cst
comment|// CHECK: extractvalue { i32, i1 } [[PAIR]], 1
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
comment|// CHECK: atomicrmw and i32* %val, i32 9 seq_cst
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
comment|// CHECK: atomicrmw or i32* %val, i32 10 seq_cst
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
comment|// CHECK: atomicrmw xor i32* %val, i32 11 seq_cst
name|old
operator|=
name|__sync_fetch_and_nand
argument_list|(
operator|&
name|val
argument_list|,
literal|0xc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw nand i32* %val, i32 12 seq_cst
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
comment|// CHECK: atomicrmw add i32* %val, i32 1 seq_cst
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
comment|// CHECK: atomicrmw sub i32* %val, i32 2 seq_cst
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
comment|// CHECK: atomicrmw and i8* %valc, i8 3 seq_cst
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
comment|// CHECK: atomicrmw or i8* %valc, i8 4 seq_cst
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
comment|// CHECK: atomicrmw xor i8* %valc, i8 5 seq_cst
name|old
operator|=
name|__sync_nand_and_fetch
argument_list|(
operator|&
name|valc
argument_list|,
literal|6
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw nand i8* %valc, i8 6 seq_cst
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
comment|// CHECK: [[PAIR:%[a-z0-9_.]+]] = cmpxchg i32* null, i32 0, i32 0 seq_cst
comment|// CHECK: extractvalue { i32, i1 } [[PAIR]], 0
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
comment|// CHECK: [[PAIR:%[a-z0-9_.]+]] = cmpxchg i8* %valb, i8 0, i8 1 seq_cst
comment|// CHECK: [[VAL:%[a-z0-9_.]+]] = extractvalue { i8, i1 } [[PAIR]], 0
comment|// CHECK: trunc i8 [[VAL]] to i1
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
comment|// CHECK: cmpxchg i32* null, i32 0, i32 0 seq_cst
name|__sync_lock_release
argument_list|(
operator|&
name|val
argument_list|)
expr_stmt|;
comment|// CHECK: store atomic i32 0, {{.*}} release, align 4
name|__sync_lock_release
argument_list|(
operator|&
name|ptrval
argument_list|)
expr_stmt|;
comment|// CHECK: store atomic i32 0, {{.*}} release, align 4
name|__sync_synchronize
argument_list|()
expr_stmt|;
comment|// CHECK: fence seq_cst
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
comment|// CHECK: store atomic {{.*}} release, align 4
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
comment|// CHECK: cmpxchg i32 addrspace(256)*{{.*}}, i32 0, i32 1 seq_cst
name|__sync_val_compare_and_swap
argument_list|(
name|P
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: cmpxchg i32 addrspace(256)*{{.*}}, i32 0, i32 1 seq_cst
name|__sync_xor_and_fetch
argument_list|(
name|P
argument_list|,
literal|123
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xor i32 addrspace(256)*{{.*}}, i32 123 seq_cst
block|}
end_decl_stmt

end_unit

