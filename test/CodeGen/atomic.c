begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -triple=i686-apple-darwin9> %t1
end_comment

begin_comment
comment|// RUN: grep @llvm.memory.barrier %t1 | count 38
end_comment

begin_comment
comment|// RUN: grep @llvm.atomic.load.add.i32 %t1 | count 3
end_comment

begin_comment
comment|// RUN: grep @llvm.atomic.load.sub.i8 %t1 | count 2
end_comment

begin_comment
comment|// RUN: grep @llvm.atomic.load.min.i32 %t1
end_comment

begin_comment
comment|// RUN: grep @llvm.atomic.load.max.i32 %t1
end_comment

begin_comment
comment|// RUN: grep @llvm.atomic.load.umin.i32 %t1
end_comment

begin_comment
comment|// RUN: grep @llvm.atomic.load.umax.i32 %t1
end_comment

begin_comment
comment|// RUN: grep @llvm.atomic.swap.i32 %t1
end_comment

begin_comment
comment|// RUN: grep @llvm.atomic.cmp.swap.i32 %t1 | count 4
end_comment

begin_comment
comment|// RUN: grep @llvm.atomic.load.and.i32 %t1
end_comment

begin_comment
comment|// RUN: grep @llvm.atomic.load.or.i8 %t1
end_comment

begin_comment
comment|// RUN: grep @llvm.atomic.load.xor.i8 %t1
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
name|__sync_lock_release
argument_list|(
operator|&
name|val
argument_list|)
expr_stmt|;
name|__sync_synchronize
argument_list|()
expr_stmt|;
return|return
name|old
return|;
block|}
end_function

end_unit

