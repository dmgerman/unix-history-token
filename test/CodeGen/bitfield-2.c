begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -triple x86_64 -O3 -o %t.opt.ll %s \
end_comment

begin_comment
comment|// RUN:   -fdump-record-layouts> %t.dump.txt
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-RECORD< %t.dump.txt %s
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-OPT< %t.opt.ll %s
end_comment

begin_comment
comment|/****/
end_comment

begin_comment
comment|// Check that we don't read off the end a packed 24-bit structure.
end_comment

begin_comment
comment|// PR6176
end_comment

begin_comment
comment|// CHECK-RECORD: *** Dumping IRgen Record Layout
end_comment

begin_comment
comment|// CHECK-RECORD: Record: RecordDecl{{.*}}s0
end_comment

begin_comment
comment|// CHECK-RECORD: Layout:<CGRecordLayout
end_comment

begin_comment
comment|// CHECK-RECORD:   LLVMType:%struct.s0 = type { [3 x i8] }
end_comment

begin_comment
comment|// CHECK-RECORD:   IsZeroInitializable:1
end_comment

begin_comment
comment|// CHECK-RECORD:   BitFields:[
end_comment

begin_comment
comment|// CHECK-RECORD:<CGBitFieldInfo Offset:0 Size:24 IsSigned:1 StorageSize:24 StorageAlignment:1>
end_comment

begin_struct
struct|struct
name|__attribute
argument_list|(
argument|(packed)
argument_list|)
name|s0
block|{
name|int
name|f0
range|:
literal|24
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|s0
name|g0
init|=
block|{
literal|0xdeadbeef
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|f0_load
parameter_list|(
name|struct
name|s0
modifier|*
name|a0
parameter_list|)
block|{
name|int
name|size_check
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|s0
argument_list|)
operator|==
literal|3
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
return|return
name|a0
operator|->
name|f0
return|;
block|}
end_function

begin_function
name|int
name|f0_store
parameter_list|(
name|struct
name|s0
modifier|*
name|a0
parameter_list|)
block|{
return|return
operator|(
name|a0
operator|->
name|f0
operator|=
literal|1
operator|)
return|;
block|}
end_function

begin_function
name|int
name|f0_reload
parameter_list|(
name|struct
name|s0
modifier|*
name|a0
parameter_list|)
block|{
return|return
operator|(
name|a0
operator|->
name|f0
operator|+=
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-OPT-LABEL: define i64 @test_0()
end_comment

begin_comment
comment|// CHECK-OPT:  ret i64 1
end_comment

begin_comment
comment|// CHECK-OPT: }
end_comment

begin_function
name|unsigned
name|long
name|long
name|test_0
parameter_list|()
block|{
name|struct
name|s0
name|g0
init|=
block|{
literal|0xdeadbeef
block|}
decl_stmt|;
name|unsigned
name|long
name|long
name|res
init|=
literal|0
decl_stmt|;
name|res
operator|^=
name|g0
operator|.
name|f0
expr_stmt|;
name|res
operator|^=
name|f0_load
argument_list|(
operator|&
name|g0
argument_list|)
operator|^
name|f0_store
argument_list|(
operator|&
name|g0
argument_list|)
operator|^
name|f0_reload
argument_list|(
operator|&
name|g0
argument_list|)
expr_stmt|;
name|res
operator|^=
name|g0
operator|.
name|f0
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/****/
end_comment

begin_comment
comment|// PR5591
end_comment

begin_comment
comment|// CHECK-RECORD: *** Dumping IRgen Record Layout
end_comment

begin_comment
comment|// CHECK-RECORD: Record: RecordDecl{{.*}}s1
end_comment

begin_comment
comment|// CHECK-RECORD: Layout:<CGRecordLayout
end_comment

begin_comment
comment|// CHECK-RECORD:   LLVMType:%struct.s1 = type { [3 x i8] }
end_comment

begin_comment
comment|// CHECK-RECORD:   IsZeroInitializable:1
end_comment

begin_comment
comment|// CHECK-RECORD:   BitFields:[
end_comment

begin_comment
comment|// CHECK-RECORD:<CGBitFieldInfo Offset:0 Size:10 IsSigned:1 StorageSize:24 StorageAlignment:1>
end_comment

begin_comment
comment|// CHECK-RECORD:<CGBitFieldInfo Offset:10 Size:10 IsSigned:1 StorageSize:24 StorageAlignment:1>
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_struct
struct|struct
name|__attribute
argument_list|(
argument|(packed)
argument_list|)
name|s1
block|{
name|signed
name|f0
range|:
literal|10
decl_stmt|;
name|signed
name|f1
range|:
literal|10
decl_stmt|;
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_decl_stmt
name|struct
name|s1
name|g1
init|=
block|{
literal|0xdeadbeef
block|,
literal|0xdeadbeef
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|f1_load
parameter_list|(
name|struct
name|s1
modifier|*
name|a0
parameter_list|)
block|{
name|int
name|size_check
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|s1
argument_list|)
operator|==
literal|3
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
return|return
name|a0
operator|->
name|f1
return|;
block|}
end_function

begin_function
name|int
name|f1_store
parameter_list|(
name|struct
name|s1
modifier|*
name|a0
parameter_list|)
block|{
return|return
operator|(
name|a0
operator|->
name|f1
operator|=
literal|1234
operator|)
return|;
block|}
end_function

begin_function
name|int
name|f1_reload
parameter_list|(
name|struct
name|s1
modifier|*
name|a0
parameter_list|)
block|{
return|return
operator|(
name|a0
operator|->
name|f1
operator|+=
literal|1234
operator|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-OPT-LABEL: define i64 @test_1()
end_comment

begin_comment
comment|// CHECK-OPT:  ret i64 210
end_comment

begin_comment
comment|// CHECK-OPT: }
end_comment

begin_function
name|unsigned
name|long
name|long
name|test_1
parameter_list|()
block|{
name|struct
name|s1
name|g1
init|=
block|{
literal|0xdeadbeef
block|,
literal|0xdeadbeef
block|}
decl_stmt|;
name|unsigned
name|long
name|long
name|res
init|=
literal|0
decl_stmt|;
name|res
operator|^=
name|g1
operator|.
name|f0
operator|^
name|g1
operator|.
name|f1
expr_stmt|;
name|res
operator|^=
name|f1_load
argument_list|(
operator|&
name|g1
argument_list|)
operator|^
name|f1_store
argument_list|(
operator|&
name|g1
argument_list|)
operator|^
name|f1_reload
argument_list|(
operator|&
name|g1
argument_list|)
expr_stmt|;
name|res
operator|^=
name|g1
operator|.
name|f0
operator|^
name|g1
operator|.
name|f1
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/****/
end_comment

begin_comment
comment|// Check that we don't access beyond the bounds of a union.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PR5567
end_comment

begin_comment
comment|// CHECK-RECORD: *** Dumping IRgen Record Layout
end_comment

begin_comment
comment|// CHECK-RECORD: Record: RecordDecl{{.*}}u2
end_comment

begin_comment
comment|// CHECK-RECORD: Layout:<CGRecordLayout
end_comment

begin_comment
comment|// CHECK-RECORD:   LLVMType:%union.u2 = type { i8 }
end_comment

begin_comment
comment|// CHECK-RECORD:   IsZeroInitializable:1
end_comment

begin_comment
comment|// CHECK-RECORD:   BitFields:[
end_comment

begin_comment
comment|// CHECK-RECORD:<CGBitFieldInfo Offset:0 Size:3 IsSigned:0 StorageSize:8 StorageAlignment:1>
end_comment

begin_union
union|union
name|__attribute__
argument_list|(
argument|(packed)
argument_list|)
name|u2
block|{
name|unsigned
name|long
name|long
name|f0
range|:
literal|3
decl_stmt|;
block|}
union|;
end_union

begin_decl_stmt
name|union
name|u2
name|g2
init|=
block|{
literal|0xdeadbeef
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|f2_load
parameter_list|(
name|union
name|u2
modifier|*
name|a0
parameter_list|)
block|{
return|return
name|a0
operator|->
name|f0
return|;
block|}
end_function

begin_function
name|int
name|f2_store
parameter_list|(
name|union
name|u2
modifier|*
name|a0
parameter_list|)
block|{
return|return
operator|(
name|a0
operator|->
name|f0
operator|=
literal|1234
operator|)
return|;
block|}
end_function

begin_function
name|int
name|f2_reload
parameter_list|(
name|union
name|u2
modifier|*
name|a0
parameter_list|)
block|{
return|return
operator|(
name|a0
operator|->
name|f0
operator|+=
literal|1234
operator|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-OPT-LABEL: define i64 @test_2()
end_comment

begin_comment
comment|// CHECK-OPT:  ret i64 2
end_comment

begin_comment
comment|// CHECK-OPT: }
end_comment

begin_function
name|unsigned
name|long
name|long
name|test_2
parameter_list|()
block|{
name|union
name|u2
name|g2
init|=
block|{
literal|0xdeadbeef
block|}
decl_stmt|;
name|unsigned
name|long
name|long
name|res
init|=
literal|0
decl_stmt|;
name|res
operator|^=
name|g2
operator|.
name|f0
expr_stmt|;
name|res
operator|^=
name|f2_load
argument_list|(
operator|&
name|g2
argument_list|)
operator|^
name|f2_store
argument_list|(
operator|&
name|g2
argument_list|)
operator|^
name|f2_reload
argument_list|(
operator|&
name|g2
argument_list|)
expr_stmt|;
name|res
operator|^=
name|g2
operator|.
name|f0
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/***/
end_comment

begin_comment
comment|// PR5039
end_comment

begin_struct
struct|struct
name|s3
block|{
name|long
name|long
name|f0
range|:
literal|32
decl_stmt|;
name|long
name|long
name|f1
range|:
literal|32
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|s3
name|g3
init|=
block|{
literal|0xdeadbeef
block|,
literal|0xdeadbeef
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|f3_load
parameter_list|(
name|struct
name|s3
modifier|*
name|a0
parameter_list|)
block|{
name|a0
operator|->
name|f0
operator|=
literal|1
expr_stmt|;
return|return
name|a0
operator|->
name|f0
return|;
block|}
end_function

begin_function
name|int
name|f3_store
parameter_list|(
name|struct
name|s3
modifier|*
name|a0
parameter_list|)
block|{
name|a0
operator|->
name|f0
operator|=
literal|1
expr_stmt|;
return|return
operator|(
name|a0
operator|->
name|f0
operator|=
literal|1234
operator|)
return|;
block|}
end_function

begin_function
name|int
name|f3_reload
parameter_list|(
name|struct
name|s3
modifier|*
name|a0
parameter_list|)
block|{
name|a0
operator|->
name|f0
operator|=
literal|1
expr_stmt|;
return|return
operator|(
name|a0
operator|->
name|f0
operator|+=
literal|1234
operator|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-OPT-LABEL: define i64 @test_3()
end_comment

begin_comment
comment|// CHECK-OPT:  ret i64 -559039940
end_comment

begin_comment
comment|// CHECK-OPT: }
end_comment

begin_function
name|unsigned
name|long
name|long
name|test_3
parameter_list|()
block|{
name|struct
name|s3
name|g3
init|=
block|{
literal|0xdeadbeef
block|,
literal|0xdeadbeef
block|}
decl_stmt|;
name|unsigned
name|long
name|long
name|res
init|=
literal|0
decl_stmt|;
name|res
operator|^=
name|g3
operator|.
name|f0
operator|^
name|g3
operator|.
name|f1
expr_stmt|;
name|res
operator|^=
name|f3_load
argument_list|(
operator|&
name|g3
argument_list|)
operator|^
name|f3_store
argument_list|(
operator|&
name|g3
argument_list|)
operator|^
name|f3_reload
argument_list|(
operator|&
name|g3
argument_list|)
expr_stmt|;
name|res
operator|^=
name|g3
operator|.
name|f0
operator|^
name|g3
operator|.
name|f1
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/***/
end_comment

begin_comment
comment|// This is a case where the bitfield access will straddle an alignment boundary
end_comment

begin_comment
comment|// of its underlying type.
end_comment

begin_struct
struct|struct
name|s4
block|{
name|unsigned
name|f0
range|:
literal|16
decl_stmt|;
name|unsigned
name|f1
range|:
literal|28
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|s4
name|g4
init|=
block|{
literal|0xdeadbeef
block|,
literal|0xdeadbeef
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|f4_load
parameter_list|(
name|struct
name|s4
modifier|*
name|a0
parameter_list|)
block|{
return|return
name|a0
operator|->
name|f0
operator|^
name|a0
operator|->
name|f1
return|;
block|}
end_function

begin_function
name|int
name|f4_store
parameter_list|(
name|struct
name|s4
modifier|*
name|a0
parameter_list|)
block|{
return|return
operator|(
name|a0
operator|->
name|f0
operator|=
literal|1234
operator|)
operator|^
operator|(
name|a0
operator|->
name|f1
operator|=
literal|5678
operator|)
return|;
block|}
end_function

begin_function
name|int
name|f4_reload
parameter_list|(
name|struct
name|s4
modifier|*
name|a0
parameter_list|)
block|{
return|return
operator|(
name|a0
operator|->
name|f0
operator|+=
literal|1234
operator|)
operator|^
operator|(
name|a0
operator|->
name|f1
operator|+=
literal|5678
operator|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-OPT-LABEL: define i64 @test_4()
end_comment

begin_comment
comment|// CHECK-OPT:  ret i64 4860
end_comment

begin_comment
comment|// CHECK-OPT: }
end_comment

begin_function
name|unsigned
name|long
name|long
name|test_4
parameter_list|()
block|{
name|struct
name|s4
name|g4
init|=
block|{
literal|0xdeadbeef
block|,
literal|0xdeadbeef
block|}
decl_stmt|;
name|unsigned
name|long
name|long
name|res
init|=
literal|0
decl_stmt|;
name|res
operator|^=
name|g4
operator|.
name|f0
operator|^
name|g4
operator|.
name|f1
expr_stmt|;
name|res
operator|^=
name|f4_load
argument_list|(
operator|&
name|g4
argument_list|)
operator|^
name|f4_store
argument_list|(
operator|&
name|g4
argument_list|)
operator|^
name|f4_reload
argument_list|(
operator|&
name|g4
argument_list|)
expr_stmt|;
name|res
operator|^=
name|g4
operator|.
name|f0
operator|^
name|g4
operator|.
name|f1
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/***/
end_comment

begin_struct
struct|struct
name|s5
block|{
name|unsigned
name|f0
range|:
literal|2
decl_stmt|;
name|_Bool
name|f1
range|:
literal|1
decl_stmt|;
name|_Bool
name|f2
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|s5
name|g5
init|=
block|{
literal|0xdeadbeef
block|,
literal|0xdeadbeef
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|f5_load
parameter_list|(
name|struct
name|s5
modifier|*
name|a0
parameter_list|)
block|{
return|return
name|a0
operator|->
name|f0
operator|^
name|a0
operator|->
name|f1
return|;
block|}
end_function

begin_function
name|int
name|f5_store
parameter_list|(
name|struct
name|s5
modifier|*
name|a0
parameter_list|)
block|{
return|return
operator|(
name|a0
operator|->
name|f0
operator|=
literal|0xF
operator|)
operator|^
operator|(
name|a0
operator|->
name|f1
operator|=
literal|0xF
operator|)
operator|^
operator|(
name|a0
operator|->
name|f2
operator|=
literal|0xF
operator|)
return|;
block|}
end_function

begin_function
name|int
name|f5_reload
parameter_list|(
name|struct
name|s5
modifier|*
name|a0
parameter_list|)
block|{
return|return
operator|(
name|a0
operator|->
name|f0
operator|+=
literal|0xF
operator|)
operator|^
operator|(
name|a0
operator|->
name|f1
operator|+=
literal|0xF
operator|)
operator|^
operator|(
name|a0
operator|->
name|f2
operator|+=
literal|0xF
operator|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-OPT-LABEL: define i64 @test_5()
end_comment

begin_comment
comment|// CHECK-OPT:  ret i64 2
end_comment

begin_comment
comment|// CHECK-OPT: }
end_comment

begin_function
name|unsigned
name|long
name|long
name|test_5
parameter_list|()
block|{
name|struct
name|s5
name|g5
init|=
block|{
literal|0xdeadbeef
block|,
literal|0xdeadbeef
block|,
literal|0xdeadbeef
block|}
decl_stmt|;
name|unsigned
name|long
name|long
name|res
init|=
literal|0
decl_stmt|;
name|res
operator|^=
name|g5
operator|.
name|f0
operator|^
name|g5
operator|.
name|f1
operator|^
name|g5
operator|.
name|f2
expr_stmt|;
name|res
operator|^=
name|f5_load
argument_list|(
operator|&
name|g5
argument_list|)
operator|^
name|f5_store
argument_list|(
operator|&
name|g5
argument_list|)
operator|^
name|f5_reload
argument_list|(
operator|&
name|g5
argument_list|)
expr_stmt|;
name|res
operator|^=
name|g5
operator|.
name|f0
operator|^
name|g5
operator|.
name|f1
operator|^
name|g5
operator|.
name|f2
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/***/
end_comment

begin_struct
struct|struct
name|s6
block|{
name|_Bool
name|f0
range|:
literal|2
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|s6
name|g6
init|=
block|{
literal|0xF
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|f6_load
parameter_list|(
name|struct
name|s6
modifier|*
name|a0
parameter_list|)
block|{
return|return
name|a0
operator|->
name|f0
return|;
block|}
end_function

begin_function
name|int
name|f6_store
parameter_list|(
name|struct
name|s6
modifier|*
name|a0
parameter_list|)
block|{
return|return
name|a0
operator|->
name|f0
operator|=
literal|0x0
return|;
block|}
end_function

begin_function
name|int
name|f6_reload
parameter_list|(
name|struct
name|s6
modifier|*
name|a0
parameter_list|)
block|{
return|return
operator|(
name|a0
operator|->
name|f0
operator|+=
literal|0xF
operator|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-OPT-LABEL: define zeroext i1 @test_6()
end_comment

begin_comment
comment|// CHECK-OPT:  ret i1 true
end_comment

begin_comment
comment|// CHECK-OPT: }
end_comment

begin_function
name|_Bool
name|test_6
parameter_list|()
block|{
name|struct
name|s6
name|g6
init|=
block|{
literal|0xF
block|}
decl_stmt|;
name|unsigned
name|long
name|long
name|res
init|=
literal|0
decl_stmt|;
name|res
operator|^=
name|g6
operator|.
name|f0
expr_stmt|;
name|res
operator|^=
name|f6_load
argument_list|(
operator|&
name|g6
argument_list|)
expr_stmt|;
name|res
operator|^=
name|g6
operator|.
name|f0
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/***/
end_comment

begin_comment
comment|// Check that we compute the best alignment possible for each access.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-RECORD: *** Dumping IRgen Record Layout
end_comment

begin_comment
comment|// CHECK-RECORD: Record: RecordDecl{{.*}}s7
end_comment

begin_comment
comment|// CHECK-RECORD: Layout:<CGRecordLayout
end_comment

begin_comment
comment|// CHECK-RECORD:   LLVMType:%struct.s7 = type { i32, i32, i32, i8, i32, [12 x i8] }
end_comment

begin_comment
comment|// CHECK-RECORD:   IsZeroInitializable:1
end_comment

begin_comment
comment|// CHECK-RECORD:   BitFields:[
end_comment

begin_comment
comment|// CHECK-RECORD:<CGBitFieldInfo Offset:0 Size:5 IsSigned:1 StorageSize:8 StorageAlignment:4>
end_comment

begin_comment
comment|// CHECK-RECORD:<CGBitFieldInfo Offset:0 Size:29 IsSigned:1 StorageSize:32 StorageAlignment:16>
end_comment

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(aligned(
literal|16
argument|))
argument_list|)
name|s7
block|{
name|int
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|;
name|int
name|f0
range|:
literal|5
decl_stmt|;
name|int
name|f1
range|:
literal|29
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|int
name|f7_load
parameter_list|(
name|struct
name|s7
modifier|*
name|a0
parameter_list|)
block|{
return|return
name|a0
operator|->
name|f0
return|;
block|}
end_function

begin_comment
comment|/***/
end_comment

begin_comment
comment|// This is a case where we narrow the access width immediately.
end_comment

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(packed)
argument_list|)
name|s8
block|{
name|char
name|f0
range|:
literal|4
decl_stmt|;
name|char
name|f1
decl_stmt|;
name|int
name|f2
range|:
literal|4
decl_stmt|;
name|char
name|f3
range|:
literal|4
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|s8
name|g8
init|=
block|{
literal|0xF
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|f8_load
parameter_list|(
name|struct
name|s8
modifier|*
name|a0
parameter_list|)
block|{
return|return
name|a0
operator|->
name|f0
operator|^
name|a0
operator|->
name|f2
operator|^
name|a0
operator|->
name|f3
return|;
block|}
end_function

begin_function
name|int
name|f8_store
parameter_list|(
name|struct
name|s8
modifier|*
name|a0
parameter_list|)
block|{
return|return
operator|(
name|a0
operator|->
name|f0
operator|=
literal|0xFD
operator|)
operator|^
operator|(
name|a0
operator|->
name|f2
operator|=
literal|0xFD
operator|)
operator|^
operator|(
name|a0
operator|->
name|f3
operator|=
literal|0xFD
operator|)
return|;
block|}
end_function

begin_function
name|int
name|f8_reload
parameter_list|(
name|struct
name|s8
modifier|*
name|a0
parameter_list|)
block|{
return|return
operator|(
name|a0
operator|->
name|f0
operator|+=
literal|0xFD
operator|)
operator|^
operator|(
name|a0
operator|->
name|f2
operator|+=
literal|0xFD
operator|)
operator|^
operator|(
name|a0
operator|->
name|f3
operator|+=
literal|0xFD
operator|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-OPT-LABEL: define i32 @test_8()
end_comment

begin_comment
comment|// CHECK-OPT:  ret i32 -3
end_comment

begin_comment
comment|// CHECK-OPT: }
end_comment

begin_function
name|unsigned
name|test_8
parameter_list|()
block|{
name|struct
name|s8
name|g8
init|=
block|{
literal|0xdeadbeef
block|,
literal|0xdeadbeef
block|,
literal|0xdeadbeef
block|,
literal|0xdeadbeef
block|}
decl_stmt|;
name|unsigned
name|long
name|long
name|res
init|=
literal|0
decl_stmt|;
name|res
operator|^=
name|g8
operator|.
name|f0
operator|^
name|g8
operator|.
name|f2
operator|^
name|g8
operator|.
name|f3
expr_stmt|;
name|res
operator|^=
name|f8_load
argument_list|(
operator|&
name|g8
argument_list|)
operator|^
name|f8_store
argument_list|(
operator|&
name|g8
argument_list|)
operator|^
name|f8_reload
argument_list|(
operator|&
name|g8
argument_list|)
expr_stmt|;
name|res
operator|^=
name|g8
operator|.
name|f0
operator|^
name|g8
operator|.
name|f2
operator|^
name|g8
operator|.
name|f3
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/***/
end_comment

begin_comment
comment|// This is another case where we narrow the access width immediately.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//<rdar://problem/7893760>
end_comment

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(packed)
argument_list|)
name|s9
block|{
name|unsigned
name|f0
range|:
literal|7
decl_stmt|;
name|unsigned
name|f1
range|:
literal|7
decl_stmt|;
name|unsigned
name|f2
range|:
literal|7
decl_stmt|;
name|unsigned
name|f3
range|:
literal|7
decl_stmt|;
name|unsigned
name|f4
range|:
literal|7
decl_stmt|;
name|unsigned
name|f5
range|:
literal|7
decl_stmt|;
name|unsigned
name|f6
range|:
literal|7
decl_stmt|;
name|unsigned
name|f7
range|:
literal|7
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|int
name|f9_load
parameter_list|(
name|struct
name|s9
modifier|*
name|a0
parameter_list|)
block|{
return|return
name|a0
operator|->
name|f7
return|;
block|}
end_function

end_unit

