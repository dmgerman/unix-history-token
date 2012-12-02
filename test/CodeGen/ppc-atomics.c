begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple powerpc-linux-gnu -emit-llvm %s -o - | FileCheck %s -check-prefix=32
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-linux-gnu -emit-llvm %s -o - | FileCheck %s -check-prefix=64
end_comment

begin_decl_stmt
name|unsigned
name|char
name|c1
decl_stmt|,
name|c2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|short
name|s1
decl_stmt|,
name|s2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|int
name|i1
decl_stmt|,
name|i2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|long
name|ll1
decl_stmt|,
name|ll2
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|memory_order
block|{
name|memory_order_relaxed
block|,
name|memory_order_consume
block|,
name|memory_order_acquire
block|,
name|memory_order_release
block|,
name|memory_order_acq_rel
block|,
name|memory_order_seq_cst
block|}
enum|;
end_enum

begin_function
name|void
name|test1
parameter_list|(
name|void
parameter_list|)
block|{
operator|(
name|void
operator|)
name|__atomic_load
argument_list|(
operator|&
name|c1
argument_list|,
operator|&
name|c2
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|__atomic_load
argument_list|(
operator|&
name|s1
argument_list|,
operator|&
name|s2
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|__atomic_load
argument_list|(
operator|&
name|i1
argument_list|,
operator|&
name|i2
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|__atomic_load
argument_list|(
operator|&
name|ll1
argument_list|,
operator|&
name|ll2
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
comment|// 32: define void @test1
comment|// 32: load atomic i8* @c1 seq_cst
comment|// 32: load atomic i16* @s1 seq_cst
comment|// 32: load atomic i32* @i1 seq_cst
comment|// 32: call void @__atomic_load(i32 8, i8* bitcast (i64* @ll1 to i8*)
comment|// 64: define void @test1
comment|// 64: load atomic i8* @c1 seq_cst
comment|// 64: load atomic i16* @s1 seq_cst
comment|// 64: load atomic i32* @i1 seq_cst
comment|// 64: load atomic i64* @ll1 seq_cst
block|}
end_function

end_unit

