begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm-linux-gnueabi -emit-llvm %s -o - | FileCheck %s -check-prefix=ARM
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc-linux-gnu -emit-llvm %s -o - | FileCheck %s -check-prefix=PPC32
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-linux-gnu -emit-llvm %s -o - | FileCheck %s -check-prefix=PPC64
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mipsel-linux-gnu -emit-llvm %s -o - | FileCheck %s -check-prefix=MIPS32
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips64el-linux-gnu -emit-llvm %s -o - | FileCheck %s -check-prefix=MIPS64
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

begin_decl_stmt
name|unsigned
name|char
name|a1
index|[
literal|100
index|]
decl_stmt|,
name|a2
index|[
literal|100
index|]
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
name|__atomic_store
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
name|__atomic_store
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
name|__atomic_store
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
operator|(
name|void
operator|)
name|__atomic_store
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
operator|(
name|void
operator|)
name|__atomic_load
argument_list|(
operator|&
name|a1
argument_list|,
operator|&
name|a2
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|__atomic_store
argument_list|(
operator|&
name|a1
argument_list|,
operator|&
name|a2
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
comment|// ARM-LABEL: define{{.*}} void @test1
comment|// ARM: = call{{.*}} zeroext i8 @__atomic_load_1(i8* @c1
comment|// ARM: call{{.*}} void @__atomic_store_1(i8* @c1, i8 zeroext
comment|// ARM: = call{{.*}} zeroext i16 @__atomic_load_2(i8* bitcast (i16* @s1 to i8*)
comment|// ARM: call{{.*}} void @__atomic_store_2(i8* bitcast (i16* @s1 to i8*), i16 zeroext
comment|// ARM: = call{{.*}} i32 @__atomic_load_4(i8* bitcast (i32* @i1 to i8*)
comment|// ARM: call{{.*}} void @__atomic_store_4(i8* bitcast (i32* @i1 to i8*), i32
comment|// ARM: = call{{.*}} i64 @__atomic_load_8(i8* bitcast (i64* @ll1 to i8*)
comment|// ARM: call{{.*}} void @__atomic_store_8(i8* bitcast (i64* @ll1 to i8*), i64
comment|// ARM: call{{.*}} void @__atomic_load(i32 100, i8* getelementptr inbounds ([100 x i8]* @a1, i32 0, i32 0), i8* getelementptr inbounds ([100 x i8]* @a2, i32 0, i32 0)
comment|// ARM: call{{.*}} void @__atomic_store(i32 100, i8* getelementptr inbounds ([100 x i8]* @a1, i32 0, i32 0), i8* getelementptr inbounds ([100 x i8]* @a2, i32 0, i32 0)
comment|// PPC32-LABEL: define void @test1
comment|// PPC32: = load atomic i8* @c1 seq_cst
comment|// PPC32: store atomic i8 {{.*}}, i8* @c1 seq_cst
comment|// PPC32: = load atomic i16* @s1 seq_cst
comment|// PPC32: store atomic i16 {{.*}}, i16* @s1 seq_cst
comment|// PPC32: = load atomic i32* @i1 seq_cst
comment|// PPC32: store atomic i32 {{.*}}, i32* @i1 seq_cst
comment|// PPC32: = call i64 @__atomic_load_8(i8* bitcast (i64* @ll1 to i8*)
comment|// PPC32: call void @__atomic_store_8(i8* bitcast (i64* @ll1 to i8*), i64
comment|// PPC32: call void @__atomic_load(i32 100, i8* getelementptr inbounds ([100 x i8]* @a1, i32 0, i32 0), i8* getelementptr inbounds ([100 x i8]* @a2, i32 0, i32 0)
comment|// PPC32: call void @__atomic_store(i32 100, i8* getelementptr inbounds ([100 x i8]* @a1, i32 0, i32 0), i8* getelementptr inbounds ([100 x i8]* @a2, i32 0, i32 0)
comment|// PPC64-LABEL: define void @test1
comment|// PPC64: = load atomic i8* @c1 seq_cst
comment|// PPC64: store atomic i8 {{.*}}, i8* @c1 seq_cst
comment|// PPC64: = load atomic i16* @s1 seq_cst
comment|// PPC64: store atomic i16 {{.*}}, i16* @s1 seq_cst
comment|// PPC64: = load atomic i32* @i1 seq_cst
comment|// PPC64: store atomic i32 {{.*}}, i32* @i1 seq_cst
comment|// PPC64: = load atomic i64* @ll1 seq_cst
comment|// PPC64: store atomic i64 {{.*}}, i64* @ll1 seq_cst
comment|// PPC64: call void @__atomic_load(i64 100, i8* getelementptr inbounds ([100 x i8]* @a1, i32 0, i32 0), i8* getelementptr inbounds ([100 x i8]* @a2, i32 0, i32 0)
comment|// PPC64: call void @__atomic_store(i64 100, i8* getelementptr inbounds ([100 x i8]* @a1, i32 0, i32 0), i8* getelementptr inbounds ([100 x i8]* @a2, i32 0, i32 0)
comment|// MIPS32-LABEL: define void @test1
comment|// MIPS32: = load atomic i8* @c1 seq_cst
comment|// MIPS32: store atomic i8 {{.*}}, i8* @c1 seq_cst
comment|// MIPS32: = load atomic i16* @s1 seq_cst
comment|// MIPS32: store atomic i16 {{.*}}, i16* @s1 seq_cst
comment|// MIPS32: = load atomic i32* @i1 seq_cst
comment|// MIPS32: store atomic i32 {{.*}}, i32* @i1 seq_cst
comment|// MIPS32: call i64 @__atomic_load_8(i8* bitcast (i64* @ll1 to i8*)
comment|// MIPS32: call void @__atomic_store_8(i8* bitcast (i64* @ll1 to i8*), i64
comment|// MIPS32: call void @__atomic_load(i32 zeroext 100, i8* getelementptr inbounds ([100 x i8]* @a1, i32 0, i32 0), i8* getelementptr inbounds ([100 x i8]* @a2, i32 0, i32 0)
comment|// MIPS32: call void @__atomic_store(i32 zeroext 100, i8* getelementptr inbounds ([100 x i8]* @a1, i32 0, i32 0), i8* getelementptr inbounds ([100 x i8]* @a2, i32 0, i32 0)
comment|// MIPS64-LABEL: define void @test1
comment|// MIPS64: = load atomic i8* @c1 seq_cst
comment|// MIPS64: store atomic i8 {{.*}}, i8* @c1 seq_cst
comment|// MIPS64: = load atomic i16* @s1 seq_cst
comment|// MIPS64: store atomic i16 {{.*}}, i16* @s1 seq_cst
comment|// MIPS64: = load atomic i32* @i1 seq_cst
comment|// MIPS64: store atomic i32 {{.*}}, i32* @i1 seq_cst
comment|// MIPS64: = load atomic i64* @ll1 seq_cst
comment|// MIPS64: store atomic i64 {{.*}}, i64* @ll1 seq_cst
comment|// MIPS64: call void @__atomic_load(i64 zeroext 100, i8* getelementptr inbounds ([100 x i8]* @a1, i32 0, i32 0)
comment|// MIPS64: call void @__atomic_store(i64 zeroext 100, i8* getelementptr inbounds ([100 x i8]* @a1, i32 0, i32 0), i8* getelementptr inbounds ([100 x i8]* @a2, i32 0, i32 0)
block|}
end_function

end_unit

