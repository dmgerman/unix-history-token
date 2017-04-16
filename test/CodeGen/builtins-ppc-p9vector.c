begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-feature +altivec -target-feature +power9-vector \
end_comment

begin_comment
comment|// RUN:   -triple powerpc64-unknown-unknown -emit-llvm %s \
end_comment

begin_comment
comment|// RUN:   -o - | FileCheck %s -check-prefix=CHECK-BE
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-feature +altivec -target-feature +power9-vector \
end_comment

begin_comment
comment|// RUN:   -triple powerpc64le-unknown-unknown -emit-llvm %s \
end_comment

begin_comment
comment|// RUN:   -o - | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<altivec.h>
end_include

begin_decl_stmt
name|vector
name|signed
name|char
name|vsca
decl_stmt|,
name|vscb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|unsigned
name|char
name|vuca
decl_stmt|,
name|vucb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|bool
name|char
name|vbca
decl_stmt|,
name|vbcb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|signed
name|short
name|vssa
decl_stmt|,
name|vssb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|unsigned
name|short
name|vusa
decl_stmt|,
name|vusb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|bool
name|short
name|vbsa
decl_stmt|,
name|vbsb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|signed
name|int
name|vsia
decl_stmt|,
name|vsib
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|unsigned
name|int
name|vuia
decl_stmt|,
name|vuib
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|bool
name|int
name|vbia
decl_stmt|,
name|vbib
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|signed
name|long
name|long
name|vsla
decl_stmt|,
name|vslb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|unsigned
name|long
name|long
name|vula
decl_stmt|,
name|vulb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|bool
name|long
name|long
name|vbla
decl_stmt|,
name|vblb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|float
name|vfa
decl_stmt|,
name|vfb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|double
name|vda
decl_stmt|,
name|vdb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|unsigned
name|__int128
name|vui128a
decl_stmt|,
name|vui128b
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|signed
name|__int128
name|vsi128a
decl_stmt|,
name|vsi128b
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|f
index|[
literal|4
index|]
init|=
block|{
literal|23.4f
block|,
literal|56.7f
block|,
literal|89.0f
block|,
literal|12.3f
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|d
index|[
literal|2
index|]
init|=
block|{
literal|23.4
block|,
literal|56.7
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|signed
name|char
name|sc
index|[
literal|16
index|]
init|=
block|{
operator|-
literal|8
block|,
literal|9
block|,
operator|-
literal|10
block|,
literal|11
block|,
operator|-
literal|12
block|,
literal|13
block|,
operator|-
literal|14
block|,
literal|15
block|,
operator|-
literal|0
block|,
literal|1
block|,
operator|-
literal|2
block|,
literal|3
block|,
operator|-
literal|4
block|,
literal|5
block|,
operator|-
literal|6
block|,
literal|7
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|char
name|uc
index|[
literal|16
index|]
init|=
block|{
literal|8
block|,
literal|9
block|,
literal|10
block|,
literal|11
block|,
literal|12
block|,
literal|13
block|,
literal|14
block|,
literal|15
block|,
literal|0
block|,
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|5
block|,
literal|6
block|,
literal|7
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|signed
name|short
name|ss
index|[
literal|8
index|]
init|=
block|{
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|3
block|,
literal|4
block|,
operator|-
literal|5
block|,
literal|6
block|,
operator|-
literal|7
block|,
literal|8
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|short
name|us
index|[
literal|8
index|]
init|=
block|{
literal|0
block|,
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|5
block|,
literal|6
block|,
literal|7
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|signed
name|int
name|si
index|[
literal|4
index|]
init|=
block|{
operator|-
literal|1
block|,
literal|2
block|,
operator|-
literal|3
block|,
literal|4
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|int
name|ui
index|[
literal|4
index|]
init|=
block|{
literal|0
block|,
literal|1
block|,
literal|2
block|,
literal|3
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|signed
name|long
name|sl
index|[
literal|2
index|]
init|=
block|{
operator|-
literal|1L
block|,
literal|2L
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|ul
index|[
literal|2
index|]
init|=
block|{
literal|1L
block|,
literal|2L
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|signed
name|long
name|long
name|sll
index|[
literal|2
index|]
init|=
block|{
literal|1LL
block|,
literal|1LL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|long
name|ull
index|[
literal|2
index|]
init|=
block|{
operator|-
literal|1LL
block|,
literal|1LL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|signed
name|__int128
name|sint128
index|[
literal|1
index|]
init|=
block|{
operator|-
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|__int128
name|uint128
index|[
literal|1
index|]
init|=
block|{
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|unsigned
name|test1
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpequb(<16 x i8>
comment|// CHECK-BE: @llvm.ctlz.v2i64(<2 x i64>
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: icmp eq i64 {{.*}}, 64
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: add i64 {{.*}}, 64
comment|// CHECK-BE: lshr i64 {{.*}}, 3
comment|// CHECK: @llvm.ppc.altivec.vcmpequb(<16 x i8>
comment|// CHECK: @llvm.cttz.v2i64(<2 x i64>
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: icmp eq i64 {{.*}}, 64
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: add i64 {{.*}}, 64
comment|// CHECK: lshr i64 {{.*}}, 3
return|return
name|vec_first_match_index
argument_list|(
name|vsca
argument_list|,
name|vscb
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|test2
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpequb(<16 x i8>
comment|// CHECK-BE: @llvm.ctlz.v2i64(<2 x i64>
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: icmp eq i64 {{.*}}, 64
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: add i64 {{.*}}, 64
comment|// CHECK-BE: lshr i64 {{.*}}, 3
comment|// CHECK: @llvm.ppc.altivec.vcmpequb(<16 x i8>
comment|// CHECK: @llvm.cttz.v2i64(<2 x i64>
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: icmp eq i64 {{.*}}, 64
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: add i64 {{.*}}, 64
comment|// CHECK: lshr i64 {{.*}}, 3
return|return
name|vec_first_match_index
argument_list|(
name|vuca
argument_list|,
name|vucb
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|test3
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpequw(<4 x i32>
comment|// CHECK-BE: @llvm.ctlz.v2i64(<2 x i64>
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: icmp eq i64 {{.*}}, 64
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: add i64 {{.*}}, 64
comment|// CHECK-BE: lshr i64 {{.*}}, 5
comment|// CHECK: @llvm.ppc.altivec.vcmpequw(<4 x i32>
comment|// CHECK: @llvm.cttz.v2i64(<2 x i64>
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: icmp eq i64 {{.*}}, 64
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: add i64 {{.*}}, 64
comment|// CHECK: lshr i64 {{.*}}, 5
return|return
name|vec_first_match_index
argument_list|(
name|vsia
argument_list|,
name|vsib
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|test4
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpequw(<4 x i32>
comment|// CHECK-BE: @llvm.ctlz.v2i64(<2 x i64>
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: icmp eq i64 {{.*}}, 64
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: add i64 {{.*}}, 64
comment|// CHECK-BE: lshr i64 {{.*}}, 5
comment|// CHECK: @llvm.ppc.altivec.vcmpequw(<4 x i32>
comment|// CHECK: @llvm.cttz.v2i64(<2 x i64>
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: icmp eq i64 {{.*}}, 64
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: add i64 {{.*}}, 64
comment|// CHECK: lshr i64 {{.*}}, 5
return|return
name|vec_first_match_index
argument_list|(
name|vuia
argument_list|,
name|vuib
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|test5
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpequh(<8 x i16>
comment|// CHECK-BE: @llvm.ctlz.v2i64(<2 x i64>
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: icmp eq i64 {{.*}}, 64
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: add i64 {{.*}}, 64
comment|// CHECK-BE: lshr i64 {{.*}}, 4
comment|// CHECK: @llvm.ppc.altivec.vcmpequh(<8 x i16>
comment|// CHECK: @llvm.cttz.v2i64(<2 x i64>
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: icmp eq i64 {{.*}}, 64
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: add i64 {{.*}}, 64
comment|// CHECK: lshr i64 {{.*}}, 4
return|return
name|vec_first_match_index
argument_list|(
name|vssa
argument_list|,
name|vssb
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|test6
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpequh(<8 x i16>
comment|// CHECK-BE: @llvm.ctlz.v2i64(<2 x i64>
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: icmp eq i64 {{.*}}, 64
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: add i64 {{.*}}, 64
comment|// CHECK-BE: lshr i64 {{.*}}, 4
comment|// CHECK: @llvm.ppc.altivec.vcmpequh(<8 x i16>
comment|// CHECK: @llvm.cttz.v2i64(<2 x i64>
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: icmp eq i64 {{.*}}, 64
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: add i64 {{.*}}, 64
comment|// CHECK: lshr i64 {{.*}}, 4
return|return
name|vec_first_match_index
argument_list|(
name|vusa
argument_list|,
name|vusb
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|test7
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpequb(<16 x i8>
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpequb(<16 x i8>
comment|// CHECK-BE: or<16 x i8>
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpequb(<16 x i8>
comment|// CHECK-BE: or<16 x i8>
comment|// CHECK-BE: @llvm.ctlz.v2i64(<2 x i64>
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: icmp eq i64 {{.*}}, 64
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: add i64 {{.*}}, 64
comment|// CHECK-BE: lshr i64 {{.*}}, 3
comment|// CHECK: @llvm.ppc.altivec.vcmpequb(<16 x i8>
comment|// CHECK: @llvm.ppc.altivec.vcmpequb(<16 x i8>
comment|// CHECK: or<16 x i8>
comment|// CHECK: @llvm.ppc.altivec.vcmpequb(<16 x i8>
comment|// CHECK: or<16 x i8>
comment|// CHECK: @llvm.cttz.v2i64(<2 x i64>
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: icmp eq i64 {{.*}}, 64
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: add i64 {{.*}}, 64
comment|// CHECK: lshr i64 {{.*}}, 3
return|return
name|vec_first_match_or_eos_index
argument_list|(
name|vsca
argument_list|,
name|vscb
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|test8
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpequb(<16 x i8>
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpequb(<16 x i8>
comment|// CHECK-BE: or<16 x i8>
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpequb(<16 x i8>
comment|// CHECK-BE: or<16 x i8>
comment|// CHECK-BE: @llvm.ctlz.v2i64(<2 x i64>
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: icmp eq i64 {{.*}}, 64
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: add i64 {{.*}}, 64
comment|// CHECK-BE: lshr i64 {{.*}}, 3
comment|// CHECK: @llvm.ppc.altivec.vcmpequb(<16 x i8>
comment|// CHECK: @llvm.ppc.altivec.vcmpequb(<16 x i8>
comment|// CHECK: or<16 x i8>
comment|// CHECK: @llvm.ppc.altivec.vcmpequb(<16 x i8>
comment|// CHECK: or<16 x i8>
comment|// CHECK: @llvm.cttz.v2i64(<2 x i64>
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: icmp eq i64 {{.*}}, 64
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: add i64 {{.*}}, 64
comment|// CHECK: lshr i64 {{.*}}, 3
return|return
name|vec_first_match_or_eos_index
argument_list|(
name|vuca
argument_list|,
name|vucb
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|test9
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpequw(<4 x i32>
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpequw(<4 x i32>
comment|// CHECK-BE: or<4 x i32>
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpequw(<4 x i32>
comment|// CHECK-BE: or<4 x i32>
comment|// CHECK-BE: @llvm.ctlz.v2i64(<2 x i64>
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: icmp eq i64 {{.*}}, 64
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: add i64 {{.*}}, 64
comment|// CHECK-BE: lshr i64 {{.*}}, 5
comment|// CHECK: @llvm.ppc.altivec.vcmpequw(<4 x i32>
comment|// CHECK: @llvm.ppc.altivec.vcmpequw(<4 x i32>
comment|// CHECK: or<4 x i32>
comment|// CHECK: @llvm.ppc.altivec.vcmpequw(<4 x i32>
comment|// CHECK: or<4 x i32>
comment|// CHECK: @llvm.cttz.v2i64(<2 x i64>
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: icmp eq i64 {{.*}}, 64
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: add i64 {{.*}}, 64
comment|// CHECK: lshr i64 {{.*}}, 5
return|return
name|vec_first_match_or_eos_index
argument_list|(
name|vsia
argument_list|,
name|vsib
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|test10
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpequw(<4 x i32>
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpequw(<4 x i32>
comment|// CHECK-BE: or<4 x i32>
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpequw(<4 x i32>
comment|// CHECK-BE: or<4 x i32>
comment|// CHECK-BE: @llvm.ctlz.v2i64(<2 x i64>
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: icmp eq i64 {{.*}}, 64
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: add i64 {{.*}}, 64
comment|// CHECK-BE: lshr i64 {{.*}}, 5
comment|// CHECK: @llvm.ppc.altivec.vcmpequw(<4 x i32>
comment|// CHECK: @llvm.ppc.altivec.vcmpequw(<4 x i32>
comment|// CHECK: or<4 x i32>
comment|// CHECK: @llvm.ppc.altivec.vcmpequw(<4 x i32>
comment|// CHECK: or<4 x i32>
comment|// CHECK: @llvm.cttz.v2i64(<2 x i64>
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: icmp eq i64 {{.*}}, 64
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: add i64 {{.*}}, 64
comment|// CHECK: lshr i64 {{.*}}, 5
return|return
name|vec_first_match_or_eos_index
argument_list|(
name|vuia
argument_list|,
name|vuib
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|test11
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpequh(<8 x i16>
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpequh(<8 x i16>
comment|// CHECK-BE: or<8 x i16>
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpequh(<8 x i16>
comment|// CHECK-BE: or<8 x i16>
comment|// CHECK-BE: @llvm.ctlz.v2i64(<2 x i64>
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: icmp eq i64 {{.*}}, 64
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: add i64 {{.*}}, 64
comment|// CHECK-BE: lshr i64 {{.*}}, 4
comment|// CHECK: @llvm.ppc.altivec.vcmpequh(<8 x i16>
comment|// CHECK: @llvm.ppc.altivec.vcmpequh(<8 x i16>
comment|// CHECK: or<8 x i16>
comment|// CHECK: @llvm.ppc.altivec.vcmpequh(<8 x i16>
comment|// CHECK: or<8 x i16>
comment|// CHECK: @llvm.cttz.v2i64(<2 x i64>
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: icmp eq i64 {{.*}}, 64
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: add i64 {{.*}}, 64
comment|// CHECK: lshr i64 {{.*}}, 4
return|return
name|vec_first_match_or_eos_index
argument_list|(
name|vssa
argument_list|,
name|vssb
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|test12
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpequh(<8 x i16>
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpequh(<8 x i16>
comment|// CHECK-BE: or<8 x i16>
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpequh(<8 x i16>
comment|// CHECK-BE: or<8 x i16>
comment|// CHECK-BE: @llvm.ctlz.v2i64(<2 x i64>
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: icmp eq i64 {{.*}}, 64
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: add i64 {{.*}}, 64
comment|// CHECK-BE: lshr i64 {{.*}}, 4
comment|// CHECK: @llvm.ppc.altivec.vcmpequh(<8 x i16>
comment|// CHECK: @llvm.ppc.altivec.vcmpequh(<8 x i16>
comment|// CHECK: or<8 x i16>
comment|// CHECK: @llvm.ppc.altivec.vcmpequh(<8 x i16>
comment|// CHECK: or<8 x i16>
comment|// CHECK: @llvm.cttz.v2i64(<2 x i64>
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: icmp eq i64 {{.*}}, 64
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: add i64 {{.*}}, 64
comment|// CHECK: lshr i64 {{.*}}, 4
return|return
name|vec_first_match_or_eos_index
argument_list|(
name|vusa
argument_list|,
name|vusb
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|test13
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpneb(<16 x i8>
comment|// CHECK-BE: @llvm.ctlz.v2i64(<2 x i64>
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: icmp eq i64 {{.*}}, 64
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: add i64 {{.*}}, 64
comment|// CHECK-BE: lshr i64 {{.*}}, 3
comment|// CHECK: @llvm.ppc.altivec.vcmpneb(<16 x i8>
comment|// CHECK: @llvm.cttz.v2i64(<2 x i64>
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: icmp eq i64 {{.*}}, 64
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: add i64 {{.*}}, 64
comment|// CHECK: lshr i64 {{.*}}, 3
return|return
name|vec_first_mismatch_index
argument_list|(
name|vsca
argument_list|,
name|vscb
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|test14
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpneb(<16 x i8>
comment|// CHECK-BE: @llvm.ctlz.v2i64(<2 x i64>
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: icmp eq i64 {{.*}}, 64
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: add i64 {{.*}}, 64
comment|// CHECK-BE: lshr i64 {{.*}}, 3
comment|// CHECK: @llvm.ppc.altivec.vcmpneb(<16 x i8>
comment|// CHECK: @llvm.cttz.v2i64(<2 x i64>
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: icmp eq i64 {{.*}}, 64
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: add i64 {{.*}}, 64
comment|// CHECK: lshr i64 {{.*}}, 3
return|return
name|vec_first_mismatch_index
argument_list|(
name|vuca
argument_list|,
name|vucb
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|test15
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpnew(<4 x i32>
comment|// CHECK-BE: @llvm.ctlz.v2i64(<2 x i64>
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: icmp eq i64 {{.*}}, 64
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: add i64 {{.*}}, 64
comment|// CHECK-BE: lshr i64 {{.*}}, 5
comment|// CHECK: @llvm.ppc.altivec.vcmpnew(<4 x i32>
comment|// CHECK: @llvm.cttz.v2i64(<2 x i64>
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: icmp eq i64 {{.*}}, 64
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: add i64 {{.*}}, 64
comment|// CHECK: lshr i64 {{.*}}, 5
return|return
name|vec_first_mismatch_index
argument_list|(
name|vsia
argument_list|,
name|vsib
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|test16
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpnew(<4 x i32>
comment|// CHECK-BE: @llvm.ctlz.v2i64(<2 x i64>
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: icmp eq i64 {{.*}}, 64
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: add i64 {{.*}}, 64
comment|// CHECK-BE: lshr i64 {{.*}}, 5
comment|// CHECK: @llvm.ppc.altivec.vcmpnew(<4 x i32>
comment|// CHECK: @llvm.cttz.v2i64(<2 x i64>
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: icmp eq i64 {{.*}}, 64
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: add i64 {{.*}}, 64
comment|// CHECK: lshr i64 {{.*}}, 5
return|return
name|vec_first_mismatch_index
argument_list|(
name|vuia
argument_list|,
name|vuib
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|test17
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpneh(<8 x i16>
comment|// CHECK-BE: @llvm.ctlz.v2i64(<2 x i64>
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: icmp eq i64 {{.*}}, 64
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: add i64 {{.*}}, 64
comment|// CHECK-BE: lshr i64 {{.*}}, 4
comment|// CHECK: @llvm.ppc.altivec.vcmpneh(<8 x i16>
comment|// CHECK: @llvm.cttz.v2i64(<2 x i64>
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: icmp eq i64 {{.*}}, 64
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: add i64 {{.*}}, 64
comment|// CHECK: lshr i64 {{.*}}, 4
return|return
name|vec_first_mismatch_index
argument_list|(
name|vssa
argument_list|,
name|vssb
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|test18
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpneh(<8 x i16>
comment|// CHECK-BE: @llvm.ctlz.v2i64(<2 x i64>
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: icmp eq i64 {{.*}}, 64
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: add i64 {{.*}}, 64
comment|// CHECK-BE: lshr i64 {{.*}}, 4
comment|// CHECK: @llvm.ppc.altivec.vcmpneh(<8 x i16>
comment|// CHECK: @llvm.cttz.v2i64(<2 x i64>
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: icmp eq i64 {{.*}}, 64
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: add i64 {{.*}}, 64
comment|// CHECK: lshr i64 {{.*}}, 4
return|return
name|vec_first_mismatch_index
argument_list|(
name|vusa
argument_list|,
name|vusb
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|test19
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpnezb(<16 x i8>
comment|// CHECK-BE: @llvm.ctlz.v2i64(<2 x i64>
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: icmp eq i64 {{.*}}, 64
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: add i64 {{.*}}, 64
comment|// CHECK-BE: lshr i64 {{.*}}, 3
comment|// CHECK: @llvm.ppc.altivec.vcmpnezb(<16 x i8>
comment|// CHECK: @llvm.cttz.v2i64(<2 x i64>
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: icmp eq i64 {{.*}}, 64
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: add i64 {{.*}}, 64
comment|// CHECK: lshr i64 {{.*}}, 3
return|return
name|vec_first_mismatch_or_eos_index
argument_list|(
name|vsca
argument_list|,
name|vscb
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|test20
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpnezb(<16 x i8>
comment|// CHECK-BE: @llvm.ctlz.v2i64(<2 x i64>
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: icmp eq i64 {{.*}}, 64
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: add i64 {{.*}}, 64
comment|// CHECK-BE: lshr i64 {{.*}}, 3
comment|// CHECK: @llvm.ppc.altivec.vcmpnezb(<16 x i8>
comment|// CHECK: @llvm.cttz.v2i64(<2 x i64>
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: icmp eq i64 {{.*}}, 64
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: add i64 {{.*}}, 64
comment|// CHECK: lshr i64 {{.*}}, 3
return|return
name|vec_first_mismatch_or_eos_index
argument_list|(
name|vuca
argument_list|,
name|vucb
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|test21
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpnezw(<4 x i32>
comment|// CHECK-BE: @llvm.ctlz.v2i64(<2 x i64>
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: icmp eq i64 {{.*}}, 64
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: add i64 {{.*}}, 64
comment|// CHECK-BE: lshr i64 {{.*}}, 5
comment|// CHECK: @llvm.ppc.altivec.vcmpnezw(<4 x i32>
comment|// CHECK: @llvm.cttz.v2i64(<2 x i64>
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: icmp eq i64 {{.*}}, 64
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: add i64 {{.*}}, 64
comment|// CHECK: lshr i64 {{.*}}, 5
return|return
name|vec_first_mismatch_or_eos_index
argument_list|(
name|vsia
argument_list|,
name|vsib
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|test22
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpnezw(<4 x i32>
comment|// CHECK-BE: @llvm.ctlz.v2i64(<2 x i64>
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: icmp eq i64 {{.*}}, 64
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: add i64 {{.*}}, 64
comment|// CHECK-BE: lshr i64 {{.*}}, 5
comment|// CHECK: @llvm.ppc.altivec.vcmpnezw(<4 x i32>
comment|// CHECK: @llvm.cttz.v2i64(<2 x i64>
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: icmp eq i64 {{.*}}, 64
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: add i64 {{.*}}, 64
comment|// CHECK: lshr i64 {{.*}}, 5
return|return
name|vec_first_mismatch_or_eos_index
argument_list|(
name|vuia
argument_list|,
name|vuib
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|test23
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpnezh(<8 x i16>
comment|// CHECK-BE: @llvm.ctlz.v2i64(<2 x i64>
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: icmp eq i64 {{.*}}, 64
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: add i64 {{.*}}, 64
comment|// CHECK-BE: lshr i64 {{.*}}, 4
comment|// CHECK: @llvm.ppc.altivec.vcmpnezh(<8 x i16>
comment|// CHECK: @llvm.cttz.v2i64(<2 x i64>
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: icmp eq i64 {{.*}}, 64
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: add i64 {{.*}}, 64
comment|// CHECK: lshr i64 {{.*}}, 4
return|return
name|vec_first_mismatch_or_eos_index
argument_list|(
name|vssa
argument_list|,
name|vssb
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|test24
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpnezh(<8 x i16>
comment|// CHECK-BE: @llvm.ctlz.v2i64(<2 x i64>
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: icmp eq i64 {{.*}}, 64
comment|// CHECK-BE: extractelement<2 x i64>
comment|// CHECK-BE: add i64 {{.*}}, 64
comment|// CHECK-BE: lshr i64 {{.*}}, 4
comment|// CHECK: @llvm.ppc.altivec.vcmpnezh(<8 x i16>
comment|// CHECK: @llvm.cttz.v2i64(<2 x i64>
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: icmp eq i64 {{.*}}, 64
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK: add i64 {{.*}}, 64
comment|// CHECK: lshr i64 {{.*}}, 4
return|return
name|vec_first_mismatch_or_eos_index
argument_list|(
name|vusa
argument_list|,
name|vusb
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|bool
name|char
name|test25
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpneb(<16 x i8>
comment|// CHECK-BE-NEXT: ret<16 x i8>
comment|// CHECK: @llvm.ppc.altivec.vcmpneb(<16 x i8>
comment|// CHECK-NEXT: ret<16 x i8>
return|return
name|vec_cmpne
argument_list|(
name|vbca
argument_list|,
name|vbcb
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|bool
name|char
name|test26
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpneb(<16 x i8>
comment|// CHECK-BE-NEXT: ret<16 x i8>
comment|// CHECK: @llvm.ppc.altivec.vcmpneb(<16 x i8>
comment|// CHECK-NEXT: ret<16 x i8>
return|return
name|vec_cmpne
argument_list|(
name|vsca
argument_list|,
name|vscb
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|bool
name|char
name|test27
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpneb(<16 x i8>
comment|// CHECK-BE-NEXT: ret<16 x i8>
comment|// CHECK: @llvm.ppc.altivec.vcmpneb(<16 x i8>
comment|// CHECK-NEXT: ret<16 x i8>
return|return
name|vec_cmpne
argument_list|(
name|vuca
argument_list|,
name|vucb
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|bool
name|int
name|test28
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpnew(<4 x i32>
comment|// CHECK-BE-NEXT: ret<4 x i32>
comment|// CHECK: @llvm.ppc.altivec.vcmpnew(<4 x i32>
comment|// CHECK-NEXT: ret<4 x i32>
return|return
name|vec_cmpne
argument_list|(
name|vbia
argument_list|,
name|vbib
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|bool
name|int
name|test29
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpnew(<4 x i32>
comment|// CHECK-BE-NEXT: ret<4 x i32>
comment|// CHECK: @llvm.ppc.altivec.vcmpnew(<4 x i32>
comment|// CHECK-NEXT: ret<4 x i32>
return|return
name|vec_cmpne
argument_list|(
name|vsia
argument_list|,
name|vsib
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|bool
name|int
name|test30
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpnew(<4 x i32>
comment|// CHECK-BE-NEXT: ret<4 x i32>
comment|// CHECK: @llvm.ppc.altivec.vcmpnew(<4 x i32>
comment|// CHECK-NEXT: ret<4 x i32>
return|return
name|vec_cmpne
argument_list|(
name|vuia
argument_list|,
name|vuib
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|bool
name|long
name|long
name|test31
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpequd(<2 x i64>
comment|// CHECK-BE: xor<2 x i64>
comment|// CHECK-BE-NEXT: ret<2 x i64>
comment|// CHECK: @llvm.ppc.altivec.vcmpequd(<2 x i64>
comment|// CHECK: xor<2 x i64>
comment|// CHECK-NEXT: ret<2 x i64>
return|return
name|vec_cmpne
argument_list|(
name|vbla
argument_list|,
name|vblb
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|bool
name|long
name|long
name|test32
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpequd(<2 x i64>
comment|// CHECK-BE: xor<2 x i64>
comment|// CHECK-BE-NEXT: ret<2 x i64>
comment|// CHECK: @llvm.ppc.altivec.vcmpequd(<2 x i64>
comment|// CHECK: xor<2 x i64>
comment|// CHECK-NEXT: ret<2 x i64>
return|return
name|vec_cmpne
argument_list|(
name|vsla
argument_list|,
name|vslb
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|bool
name|long
name|long
name|test33
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpequd(<2 x i64>
comment|// CHECK-BE: xor<2 x i64>
comment|// CHECK-BE-NEXT: ret<2 x i64>
comment|// CHECK: @llvm.ppc.altivec.vcmpequd(<2 x i64>
comment|// CHECK: xor<2 x i64>
comment|// CHECK-NEXT: ret<2 x i64>
return|return
name|vec_cmpne
argument_list|(
name|vula
argument_list|,
name|vulb
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|bool
name|short
name|test34
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpneh(<8 x i16>
comment|// CHECK-BE-NEXT: ret<8 x i16>
comment|// CHECK: @llvm.ppc.altivec.vcmpneh(<8 x i16>
comment|// CHECK-NEXT: ret<8 x i16>
return|return
name|vec_cmpne
argument_list|(
name|vbsa
argument_list|,
name|vbsb
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|bool
name|short
name|test35
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpneh(<8 x i16>
comment|// CHECK-BE-NEXT: ret<8 x i16>
comment|// CHECK: @llvm.ppc.altivec.vcmpneh(<8 x i16>
comment|// CHECK-NEXT: ret<8 x i16>
return|return
name|vec_cmpne
argument_list|(
name|vssa
argument_list|,
name|vssb
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|bool
name|short
name|test36
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpneh(<8 x i16>
comment|// CHECK-BE-NEXT: ret<8 x i16>
comment|// CHECK: @llvm.ppc.altivec.vcmpneh(<8 x i16>
comment|// CHECK-NEXT: ret<8 x i16>
return|return
name|vec_cmpne
argument_list|(
name|vusa
argument_list|,
name|vusb
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|bool
name|long
name|long
name|test37
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpequd(<2 x i64>
comment|// CHECK-BE: xor<2 x i64>
comment|// CHECK-BE-NEXT: ret<2 x i64>
comment|// CHECK: @llvm.ppc.altivec.vcmpequd(<2 x i64>
comment|// CHECK: xor<2 x i64>
comment|// CHECK-NEXT: ret<2 x i64>
return|return
name|vec_cmpne
argument_list|(
name|vda
argument_list|,
name|vdb
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|bool
name|int
name|test38
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vcmpnew(<4 x i32>
comment|// CHECK-BE-NEXT: ret<4 x i32>
comment|// CHECK: @llvm.ppc.altivec.vcmpnew(<4 x i32>
comment|// CHECK-NEXT: ret<4 x i32>
return|return
name|vec_cmpne
argument_list|(
name|vfa
argument_list|,
name|vfb
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|signed
name|char
name|test39
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.cttz.v16i8(<16 x i8>
comment|// CHECK-BE-NEXT: ret<16 x i8>
comment|// CHECK: @llvm.cttz.v16i8(<16 x i8>
comment|// CHECK-NEXT: ret<16 x i8>
return|return
name|vec_cnttz
argument_list|(
name|vsca
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|char
name|test40
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.cttz.v16i8(<16 x i8>
comment|// CHECK-BE-NEXT: ret<16 x i8>
comment|// CHECK: @llvm.cttz.v16i8(<16 x i8>
comment|// CHECK-NEXT: ret<16 x i8>
return|return
name|vec_cnttz
argument_list|(
name|vuca
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|signed
name|int
name|test41
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.cttz.v4i32(<4 x i32>
comment|// CHECK-BE-NEXT: ret<4 x i32>
comment|// CHECK: @llvm.cttz.v4i32(<4 x i32>
comment|// CHECK-NEXT: ret<4 x i32>
return|return
name|vec_cnttz
argument_list|(
name|vsia
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|int
name|test42
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.cttz.v4i32(<4 x i32>
comment|// CHECK-BE-NEXT: ret<4 x i32>
comment|// CHECK: @llvm.cttz.v4i32(<4 x i32>
comment|// CHECK-NEXT: ret<4 x i32>
return|return
name|vec_cnttz
argument_list|(
name|vuia
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|signed
name|long
name|long
name|test43
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.cttz.v2i64(<2 x i64>
comment|// CHECK-BE-NEXT: ret<2 x i64>
comment|// CHECK: @llvm.cttz.v2i64(<2 x i64>
comment|// CHECK-NEXT: ret<2 x i64>
return|return
name|vec_cnttz
argument_list|(
name|vsla
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|long
name|long
name|test44
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.cttz.v2i64(<2 x i64>
comment|// CHECK-BE-NEXT: ret<2 x i64>
comment|// CHECK: @llvm.cttz.v2i64(<2 x i64>
comment|// CHECK-NEXT: ret<2 x i64>
return|return
name|vec_cnttz
argument_list|(
name|vula
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|signed
name|short
name|test45
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.cttz.v8i16(<8 x i16>
comment|// CHECK-BE-NEXT: ret<8 x i16>
comment|// CHECK: @llvm.cttz.v8i16(<8 x i16>
comment|// CHECK-NEXT: ret<8 x i16>
return|return
name|vec_cnttz
argument_list|(
name|vssa
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|short
name|test46
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.cttz.v8i16(<8 x i16>
comment|// CHECK-BE-NEXT: ret<8 x i16>
comment|// CHECK: @llvm.cttz.v8i16(<8 x i16>
comment|// CHECK-NEXT: ret<8 x i16>
return|return
name|vec_cnttz
argument_list|(
name|vusa
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|char
name|test47
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ctpop.v16i8(<16 x i8>
comment|// CHECK-BE-NEXT: ret<16 x i8>
comment|// CHECK: @llvm.ctpop.v16i8(<16 x i8>
comment|// CHECK-NEXT: ret<16 x i8>
return|return
name|vec_popcnt
argument_list|(
name|vsca
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|char
name|test48
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ctpop.v16i8(<16 x i8>
comment|// CHECK-BE-NEXT: ret<16 x i8>
comment|// CHECK: @llvm.ctpop.v16i8(<16 x i8>
comment|// CHECK-NEXT: ret<16 x i8>
return|return
name|vec_popcnt
argument_list|(
name|vuca
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|int
name|test49
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ctpop.v4i32(<4 x i32>
comment|// CHECK-BE-NEXT: ret<4 x i32>
comment|// CHECK: @llvm.ctpop.v4i32(<4 x i32>
comment|// CHECK-NEXT: ret<4 x i32>
return|return
name|vec_popcnt
argument_list|(
name|vsia
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|int
name|test50
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ctpop.v4i32(<4 x i32>
comment|// CHECK-BE-NEXT: ret<4 x i32>
comment|// CHECK: @llvm.ctpop.v4i32(<4 x i32>
comment|// CHECK-NEXT: ret<4 x i32>
return|return
name|vec_popcnt
argument_list|(
name|vuia
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|long
name|long
name|test51
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ctpop.v2i64(<2 x i64>
comment|// CHECK-BE-NEXT: ret<2 x i64>
comment|// CHECK: @llvm.ctpop.v2i64(<2 x i64>
comment|// CHECK-NEXT: ret<2 x i64>
return|return
name|vec_popcnt
argument_list|(
name|vsla
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|long
name|long
name|test52
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ctpop.v2i64(<2 x i64>
comment|// CHECK-BE-NEXT: ret<2 x i64>
comment|// CHECK: @llvm.ctpop.v2i64(<2 x i64>
comment|// CHECK-NEXT: ret<2 x i64>
return|return
name|vec_popcnt
argument_list|(
name|vula
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|short
name|test53
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ctpop.v8i16(<8 x i16>
comment|// CHECK-BE-NEXT: ret<8 x i16>
comment|// CHECK: @llvm.ctpop.v8i16(<8 x i16>
comment|// CHECK-NEXT: ret<8 x i16>
return|return
name|vec_popcnt
argument_list|(
name|vssa
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|short
name|test54
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ctpop.v8i16(<8 x i16>
comment|// CHECK-BE-NEXT: ret<8 x i16>
comment|// CHECK: @llvm.ctpop.v8i16(<8 x i16>
comment|// CHECK-NEXT: ret<8 x i16>
return|return
name|vec_popcnt
argument_list|(
name|vusa
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|double
name|test55
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.xviexpdp(<2 x i64> %{{.+}},<2 x i64>
comment|// CHECK-BE-NEXT: ret<2 x double>
comment|// CHECK: @llvm.ppc.vsx.xviexpdp(<2 x i64> %{{.+}},<2 x i64>
comment|// CHECK-NEXT: ret<2 x double>
return|return
name|vec_insert_exp
argument_list|(
name|vda
argument_list|,
name|vulb
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|double
name|test56
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.xviexpdp(<2 x i64> %{{.+}},<2 x i64>
comment|// CHECK-BE-NEXT: ret<2 x double>
comment|// CHECK: @llvm.ppc.vsx.xviexpdp(<2 x i64> %{{.+}},<2 x i64>
comment|// CHECK-NEXT: ret<2 x double>
return|return
name|vec_insert_exp
argument_list|(
name|vula
argument_list|,
name|vulb
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|float
name|test57
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.xviexpsp(<4 x i32> %{{.+}},<4 x i32>
comment|// CHECK-BE-NEXT: ret<4 x float>
comment|// CHECK: @llvm.ppc.vsx.xviexpsp(<4 x i32> %{{.+}},<4 x i32>
comment|// CHECK-NEXT: ret<4 x float>
return|return
name|vec_insert_exp
argument_list|(
name|vfa
argument_list|,
name|vuib
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|float
name|test58
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.xviexpsp(<4 x i32> %{{.+}},<4 x i32>
comment|// CHECK-BE-NEXT: ret<4 x float>
comment|// CHECK: @llvm.ppc.vsx.xviexpsp(<4 x i32> %{{.+}},<4 x i32>
comment|// CHECK-NEXT: ret<4 x float>
return|return
name|vec_insert_exp
argument_list|(
name|vuia
argument_list|,
name|vuib
argument_list|)
return|;
block|}
end_function

begin_function
name|signed
name|int
name|test59
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vclzlsbb(<16 x i8>
comment|// CHECK-BE-NEXT: ret i32
comment|// CHECK-LE: @llvm.ppc.altivec.vctzlsbb(<16 x i8>
comment|// CHECK-LE-NEXT: ret i32
return|return
name|vec_cntlz_lsbb
argument_list|(
name|vuca
argument_list|)
return|;
block|}
end_function

begin_function
name|signed
name|int
name|test60
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vclzlsbb(<16 x i8>
comment|// CHECK-BE-NEXT: ret i32
comment|// CHECK-LE: @llvm.ppc.altivec.vctzlsbb(<16 x i8>
comment|// CHECK-LE-NEXT: ret i32
return|return
name|vec_cntlz_lsbb
argument_list|(
name|vsca
argument_list|)
return|;
block|}
end_function

begin_function
name|signed
name|int
name|test61
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vctzlsbb(<16 x i8>
comment|// CHECK-BE-NEXT: ret i32
comment|// CHECK-LE: @llvm.ppc.altivec.vclzlsbb(<16 x i8>
comment|// CHECK-LE-NEXT: ret i32
return|return
name|vec_cnttz_lsbb
argument_list|(
name|vsca
argument_list|)
return|;
block|}
end_function

begin_function
name|signed
name|int
name|test62
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vctzlsbb(<16 x i8>
comment|// CHECK-BE-NEXT: ret i32
comment|// CHECK-LE: @llvm.ppc.altivec.vclzlsbb(<16 x i8>
comment|// CHECK-LE-NEXT: ret i32
return|return
name|vec_cnttz_lsbb
argument_list|(
name|vuca
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|int
name|test63
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vprtybw(<4 x i32>
comment|// CHECK-BE-NEXT: ret<4 x i32>
comment|// CHECK: @llvm.ppc.altivec.vprtybw(<4 x i32>
comment|// CHECK-NEXT: ret<4 x i32>
return|return
name|vec_parity_lsbb
argument_list|(
name|vuia
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|int
name|test64
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vprtybw(<4 x i32>
comment|// CHECK-BE-NEXT: ret<4 x i32>
comment|// CHECK: @llvm.ppc.altivec.vprtybw(<4 x i32>
comment|// CHECK-NEXT: ret<4 x i32>
return|return
name|vec_parity_lsbb
argument_list|(
name|vsia
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|long
name|long
name|test65
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vprtybd(<2 x i64>
comment|// CHECK-BE-NEXT: ret<2 x i64>
comment|// CHECK: @llvm.ppc.altivec.vprtybd(<2 x i64>
comment|// CHECK-NEXT: ret<2 x i64>
return|return
name|vec_parity_lsbb
argument_list|(
name|vula
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|long
name|long
name|test66
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vprtybd(<2 x i64>
comment|// CHECK-BE-NEXT: ret<2 x i64>
comment|// CHECK: @llvm.ppc.altivec.vprtybd(<2 x i64>
comment|// CHECK-NEXT: ret<2 x i64>
return|return
name|vec_parity_lsbb
argument_list|(
name|vsla
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|__int128
name|test67
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vprtybq(<1 x i128>
comment|// CHECK-BE-NEXT: ret<1 x i128>
comment|// CHECK: @llvm.ppc.altivec.vprtybq(<1 x i128>
comment|// CHECK-NEXT: ret<1 x i128>
return|return
name|vec_parity_lsbb
argument_list|(
name|vui128a
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|__int128
name|test68
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vprtybq(<1 x i128>
comment|// CHECK-BE-NEXT: ret<1 x i128>
comment|// CHECK: @llvm.ppc.altivec.vprtybq(<1 x i128>
comment|// CHECK-NEXT: ret<1 x i128>
return|return
name|vec_parity_lsbb
argument_list|(
name|vsi128a
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|char
name|test69
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: call<16 x i8> @llvm.ppc.altivec.vabsdub(<16 x i8> {{.+}},<16 x i8> {{.+}})
comment|// CHECK: call<16 x i8> @llvm.ppc.altivec.vabsdub(<16 x i8> {{.+}},<16 x i8> {{.+}})
return|return
name|vec_absd
argument_list|(
name|vuca
argument_list|,
name|vucb
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|short
name|test70
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: call<8 x i16> @llvm.ppc.altivec.vabsduh(<8 x i16> {{.+}},<8 x i16> {{.+}})
comment|// CHECK: call<8 x i16> @llvm.ppc.altivec.vabsduh(<8 x i16> {{.+}},<8 x i16> {{.+}})
return|return
name|vec_absd
argument_list|(
name|vusa
argument_list|,
name|vusb
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|int
name|test71
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: call<4 x i32> @llvm.ppc.altivec.vabsduw(<4 x i32> {{.+}},<4 x i32> {{.+}})
comment|// CHECK: call<4 x i32> @llvm.ppc.altivec.vabsduw(<4 x i32> {{.+}},<4 x i32> {{.+}})
return|return
name|vec_absd
argument_list|(
name|vuia
argument_list|,
name|vuib
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|char
name|test72
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vslv(<16 x i8>
comment|// CHECK-BE-NEXT: ret<16 x i8>
comment|// CHECK: @llvm.ppc.altivec.vslv(<16 x i8>
comment|// CHECK-NEXT: ret<16 x i8>
return|return
name|vec_slv
argument_list|(
name|vuca
argument_list|,
name|vucb
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|char
name|test73
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vsrv(<16 x i8>
comment|// CHECK-BE-NEXT: ret<16 x i8>
comment|// CHECK: @llvm.ppc.altivec.vsrv(<16 x i8>
comment|// CHECK-NEXT: ret<16 x i8>
return|return
name|vec_srv
argument_list|(
name|vuca
argument_list|,
name|vucb
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|short
name|test74
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.xvcvsphp(<4 x float>
comment|// CHECK-BE: @llvm.ppc.vsx.xvcvsphp(<4 x float>
comment|// CHECK-BE: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.vsx.xvcvsphp(<4 x float>
comment|// CHECK: @llvm.ppc.vsx.xvcvsphp(<4 x float>
comment|// CHECK: @llvm.ppc.altivec.vperm
return|return
name|vec_pack_to_short_fp32
argument_list|(
name|vfa
argument_list|,
name|vfb
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|int
name|test75
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vrlwmi(<4 x i32
comment|// CHECK-BE-NEXT: ret<4 x i32>
comment|// CHECK: @llvm.ppc.altivec.vrlwmi(<4 x i32
comment|// CHECK-NEXT: ret<4 x i32>
return|return
name|vec_rlmi
argument_list|(
name|vuia
argument_list|,
name|vuia
argument_list|,
name|vuia
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|long
name|long
name|test76
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.altivec.vrldmi(<2 x i64
comment|// CHECK-BE-NEXT: ret<2 x i64>
comment|// CHECK: @llvm.ppc.altivec.vrldmi(<2 x i64
comment|// CHECK-NEXT: ret<2 x i64>
return|return
name|vec_rlmi
argument_list|(
name|vula
argument_list|,
name|vula
argument_list|,
name|vula
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|int
name|test77
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: %[[RES1:.+]] = shl<4 x i32
comment|// CHECK-BE: %[[RES2:.+]] = or<4 x i32> %[[RES1]]
comment|// CHECK-BE: @llvm.ppc.altivec.vrlwnm(<4 x i32
comment|// CHECK-BE: ret<4 x i32>
comment|// CHECK: %[[RES1:.+]] = shl<4 x i32
comment|// CHECK: %[[RES2:.+]] = or<4 x i32> %[[RES1]]
comment|// CHECK: @llvm.ppc.altivec.vrlwnm(<4 x i32
comment|// CHECK: ret<4 x i32>
return|return
name|vec_rlnm
argument_list|(
name|vuia
argument_list|,
name|vuia
argument_list|,
name|vuia
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|long
name|long
name|test78
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: %[[RES1:.+]] = shl<2 x i64
comment|// CHECK-BE: %[[RES2:.+]] = or<2 x i64> %[[RES1]]
comment|// CHECK-BE: @llvm.ppc.altivec.vrldnm(<2 x i64
comment|// CHECK-BE-NEXT: ret<2 x i64>
comment|// CHECK: %[[RES1:.+]] = shl<2 x i64
comment|// CHECK: %[[RES2:.+]] = or<2 x i64> %[[RES1]]
comment|// CHECK: @llvm.ppc.altivec.vrldnm(<2 x i64
comment|// CHECK-NEXT: ret<2 x i64>
return|return
name|vec_rlnm
argument_list|(
name|vula
argument_list|,
name|vula
argument_list|,
name|vula
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|double
name|test79
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: extractelement<4 x float>
comment|// CHECK-BE: fpext float
comment|// CHECK-BE: insertelement<2 x double>
comment|// CHECK-BE: extractelement<4 x float>
comment|// CHECK-BE: fpext float
comment|// CHECK-BE: insertelement<2 x double>
comment|// CHECK: extractelement<4 x float>
comment|// CHECK: fpext float
comment|// CHECK: insertelement<2 x double>
comment|// CHECK: extractelement<4 x float>
comment|// CHECK: fpext float
comment|// CHECK: insertelement<2 x double>
return|return
name|vec_unpackh
argument_list|(
name|vfa
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|double
name|test80
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: extractelement<4 x float>
comment|// CHECK-BE: fpext float
comment|// CHECK-BE: insertelement<2 x double>
comment|// CHECK-BE: extractelement<4 x float>
comment|// CHECK-BE: fpext float
comment|// CHECK-BE: insertelement<2 x double>
comment|// CHECK: extractelement<4 x float>
comment|// CHECK: fpext float
comment|// CHECK: insertelement<2 x double>
comment|// CHECK: extractelement<4 x float>
comment|// CHECK: fpext float
comment|// CHECK: insertelement<2 x double>
return|return
name|vec_unpackl
argument_list|(
name|vfa
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|double
name|test81
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: extractelement<2 x double>
comment|// CHECK: fptrunc double
comment|// CHECK: insertelement<4 x float>
comment|// CHECK: extractelement<2 x double>
comment|// CHECK: fptrunc double
comment|// CHECK: insertelement<4 x float>
comment|// CHECK: extractelement<2 x double>
comment|// CHECK: fptrunc double
comment|// CHECK: insertelement<4 x float>
comment|// CHECK: extractelement<2 x double>
comment|// CHECK: fptrunc double
comment|// CHECK: insertelement<4 x float>
comment|// CHECK-LE: extractelement<2 x double>
comment|// CHECK-LE: fptrunc double
comment|// CHECK-LE: insertelement<4 x float>
comment|// CHECK-LE: extractelement<2 x double>
comment|// CHECK-LE: fptrunc double
comment|// CHECK-LE: insertelement<4 x float>
comment|// CHECK-LE: extractelement<2 x double>
comment|// CHECK-LE: fptrunc double
comment|// CHECK-LE: insertelement<4 x float>
comment|// CHECK-LE: extractelement<2 x double>
comment|// CHECK-LE: fptrunc double
comment|// CHECK-LE: insertelement<4 x float>
return|return
name|vec_pack
argument_list|(
name|vda
argument_list|,
name|vdb
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|int
name|test82
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.xvxexpsp(<4 x float> {{.+}})
comment|// CHECK-BE-NEXT: ret<4 x i32>
comment|// CHECK: @llvm.ppc.vsx.xvxexpsp(<4 x float> {{.+}})
comment|// CHECK-NEXT: ret<4 x i32>
return|return
name|vec_extract_exp
argument_list|(
name|vfa
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|long
name|long
name|test83
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.xvxexpdp(<2 x double> {{.+}})
comment|// CHECK-BE-NEXT: ret<2 x i64>
comment|// CHECK: @llvm.ppc.vsx.xvxexpdp(<2 x double> {{.+}})
comment|// CHECK-NEXT: ret<2 x i64>
return|return
name|vec_extract_exp
argument_list|(
name|vda
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|int
name|test84
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.xvxsigsp(<4 x float> {{.+}})
comment|// CHECK-BE-NEXT: ret<4 x i32>
comment|// CHECK: @llvm.ppc.vsx.xvxsigsp(<4 x float> {{.+}})
comment|// CHECK-NEXT: ret<4 x i32>
return|return
name|vec_extract_sig
argument_list|(
name|vfa
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|long
name|long
name|test85
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.xvxsigdp(<2 x double> {{.+}})
comment|// CHECK-BE-NEXT: ret<2 x i64>
comment|// CHECK: @llvm.ppc.vsx.xvxsigdp(<2 x double> {{.+}})
comment|// CHECK-NEXT: ret<2 x i64>
return|return
name|vec_extract_sig
argument_list|(
name|vda
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|bool
name|int
name|test86
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.xvtstdcsp(<4 x float> {{.+}}, i32 127)
comment|// CHECK-BE-NEXT: ret<4 x i32>
comment|// CHECK: @llvm.ppc.vsx.xvtstdcsp(<4 x float> {{.+}}, i32 127)
comment|// CHECK-NEXT: ret<4 x i32>
return|return
name|vec_test_data_class
argument_list|(
name|vfa
argument_list|,
name|__VEC_CLASS_FP_NOT_NORMAL
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|bool
name|long
name|long
name|test87
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.xvtstdcdp(<2 x double> {{.+}}, i32 127)
comment|// CHECK-BE_NEXT: ret<2 x i64
comment|// CHECK: @llvm.ppc.vsx.xvtstdcdp(<2 x double> {{.+}}, i32 127)
comment|// CHECK-NEXT: ret<2 x i64>
return|return
name|vec_test_data_class
argument_list|(
name|vda
argument_list|,
name|__VEC_CLASS_FP_NOT_NORMAL
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|char
name|test88
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.lxvl(i8* %{{.+}}, i64
comment|// CHECK-BE-NEXT-NEXT: ret<16 x i8>
comment|// CHECK: @llvm.ppc.vsx.lxvl(i8* %{{.+}}, i64
comment|// CHECK-NEXT-NEXT: ret<16 x i8>
return|return
name|vec_xl_len
argument_list|(
name|uc
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|signed
name|char
name|test89
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.lxvl(i8* %{{.+}}, i64
comment|// CHECK-BE-NEXT-NEXT: ret<16 x i8>
comment|// CHECK: @llvm.ppc.vsx.lxvl(i8* %{{.+}}, i64
comment|// CHECK-NEXT-NEXT: ret<16 x i8>
return|return
name|vec_xl_len
argument_list|(
name|sc
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|short
name|test90
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.lxvl(i8* %{{.+}}, i64
comment|// CHECK-BE-NEXT-NEXT: ret<8 x i16>
comment|// CHECK: @llvm.ppc.vsx.lxvl(i8* %{{.+}}, i64
comment|// CHECK-NEXT-NEXT: ret<8 x i16>
return|return
name|vec_xl_len
argument_list|(
name|us
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|signed
name|short
name|test91
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.lxvl(i8* %{{.+}}, i64
comment|// CHECK-BE-NEXT-NEXT: ret<8 x i16>
comment|// CHECK: @llvm.ppc.vsx.lxvl(i8* %{{.+}}, i64
comment|// CHECK-NEXT-NEXT: ret<8 x i16>
return|return
name|vec_xl_len
argument_list|(
name|ss
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|int
name|test92
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.lxvl(i8* %{{.+}}, i64
comment|// CHECK-BE-NEXT: ret<4 x i32>
comment|// CHECK: @llvm.ppc.vsx.lxvl(i8* %{{.+}}, i64
comment|// CHECK-NEXT: ret<4 x i32>
return|return
name|vec_xl_len
argument_list|(
name|ui
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|signed
name|int
name|test93
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.lxvl(i8* %{{.+}}, i64
comment|// CHECK-BE-NEXT: ret<4 x i32>
comment|// CHECK: @llvm.ppc.vsx.lxvl(i8* %{{.+}}, i64
comment|// CHECK-NEXT: ret<4 x i32>
return|return
name|vec_xl_len
argument_list|(
name|si
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|float
name|test94
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.lxvl(i8* %{{.+}}, i64
comment|// CHECK-BE-NEXT-NEXT: ret<4 x i32>
comment|// CHECK: @llvm.ppc.vsx.lxvl(i8* %{{.+}}, i64
comment|// CHECK-NEXT-NEXT: ret<4 x i32>
return|return
name|vec_xl_len
argument_list|(
name|f
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|long
name|long
name|test95
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.lxvl(i8* %{{.+}}, i64
comment|// CHECK-BE-NEXT-NEXT: ret<2 x i64>
comment|// CHECK: @llvm.ppc.vsx.lxvl(i8* %{{.+}}, i64
comment|// CHECK-NEXT-NEXT: ret<2 x i64>
return|return
name|vec_xl_len
argument_list|(
name|ull
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|signed
name|long
name|long
name|test96
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.lxvl(i8* %{{.+}}, i64
comment|// CHECK-BE-NEXT-NEXT: ret<2 x i64>
comment|// CHECK: @llvm.ppc.vsx.lxvl(i8* %{{.+}}, i64
comment|// CHECK-NEXT-NEXT: ret<2 x i64>
return|return
name|vec_xl_len
argument_list|(
name|sll
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|double
name|test97
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.lxvl(i8* %{{.+}}, i64
comment|// CHECK-BE-NEXT-NEXT: ret<2 x i64>
comment|// CHECK: @llvm.ppc.vsx.lxvl(i8* %{{.+}}, i64
comment|// CHECK-NEXT-NEXT: ret<2 x i64>
return|return
name|vec_xl_len
argument_list|(
name|d
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|__int128
name|test98
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.lxvl(i8* %{{.+}}, i64
comment|// CHECK-BE-NEXT-NEXT: ret<1 x i128>
comment|// CHECK: @llvm.ppc.vsx.lxvl(i8* %{{.+}}, i64
comment|// CHECK-NEXT-NEXT: ret<1 x i128>
return|return
name|vec_xl_len
argument_list|(
name|uint128
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|signed
name|__int128
name|test99
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.lxvl(i8* %{{.+}}, i64
comment|// CHECK-BE-NEXT-NEXT: ret<1 x i128>
comment|// CHECK: @llvm.ppc.vsx.lxvl(i8* %{{.+}}, i64
comment|// CHECK-NEXT-NEXT: ret<1 x i128>
return|return
name|vec_xl_len
argument_list|(
name|sint128
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test100
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.stxvl(<4 x i32> %{{.+}}, i8* %{{.+}}, i64
comment|// CHECK: @llvm.ppc.vsx.stxvl(<4 x i32> %{{.+}}, i8* %{{.+}}, i64
return|return
name|vec_xst_len
argument_list|(
name|vuca
argument_list|,
name|uc
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test101
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.stxvl(<4 x i32> %{{.+}}, i8* %{{.+}}, i64
comment|// CHECK: @llvm.ppc.vsx.stxvl(<4 x i32> %{{.+}}, i8* %{{.+}}, i64
return|return
name|vec_xst_len
argument_list|(
name|vsca
argument_list|,
name|sc
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test102
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.stxvl(<4 x i32> %{{.+}}, i8* %{{.+}}, i64
comment|// CHECK: @llvm.ppc.vsx.stxvl(<4 x i32> %{{.+}}, i8* %{{.+}}, i64
return|return
name|vec_xst_len
argument_list|(
name|vusa
argument_list|,
name|us
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test103
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.stxvl(<4 x i32> %{{.+}}, i8* %{{.+}}, i64
comment|// CHECK: @llvm.ppc.vsx.stxvl(<4 x i32> %{{.+}}, i8* %{{.+}}, i64
return|return
name|vec_xst_len
argument_list|(
name|vssa
argument_list|,
name|ss
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test104
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.stxvl(<4 x i32> %{{.+}}, i8* %{{.+}}, i64
comment|// CHECK: @llvm.ppc.vsx.stxvl(<4 x i32> %{{.+}}, i8* %{{.+}}, i64
return|return
name|vec_xst_len
argument_list|(
name|vuia
argument_list|,
name|ui
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test105
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.stxvl(<4 x i32> %{{.+}}, i8* %{{.+}}, i64
comment|// CHECK: @llvm.ppc.vsx.stxvl(<4 x i32> %{{.+}}, i8* %{{.+}}, i64
return|return
name|vec_xst_len
argument_list|(
name|vsia
argument_list|,
name|si
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test106
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.stxvl(<4 x i32> %{{.+}}, i8* %{{.+}}, i64
comment|// CHECK: @llvm.ppc.vsx.stxvl(<4 x i32> %{{.+}}, i8* %{{.+}}, i64
return|return
name|vec_xst_len
argument_list|(
name|vfa
argument_list|,
name|f
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test107
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.stxvl(<4 x i32> %{{.+}}, i8* %{{.+}}, i64
comment|// CHECK: @llvm.ppc.vsx.stxvl(<4 x i32> %{{.+}}, i8* %{{.+}}, i64
return|return
name|vec_xst_len
argument_list|(
name|vula
argument_list|,
name|ull
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test108
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.stxvl(<4 x i32> %{{.+}}, i8* %{{.+}}, i64
comment|// CHECK: @llvm.ppc.vsx.stxvl(<4 x i32> %{{.+}}, i8* %{{.+}}, i64
return|return
name|vec_xst_len
argument_list|(
name|vsla
argument_list|,
name|sll
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test109
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.stxvl(<4 x i32> %{{.+}}, i8* %{{.+}}, i64
comment|// CHECK: @llvm.ppc.vsx.stxvl(<4 x i32> %{{.+}}, i8* %{{.+}}, i64
return|return
name|vec_xst_len
argument_list|(
name|vda
argument_list|,
name|d
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test110
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.stxvl(<4 x i32> %{{.+}}, i8* %{{.+}}, i64
comment|// CHECK: @llvm.ppc.vsx.stxvl(<4 x i32> %{{.+}}, i8* %{{.+}}, i64
return|return
name|vec_xst_len
argument_list|(
name|vui128a
argument_list|,
name|uint128
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test111
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.stxvl(<4 x i32> %{{.+}}, i8* %{{.+}}, i64
comment|// CHECK: @llvm.ppc.vsx.stxvl(<4 x i32> %{{.+}}, i8* %{{.+}}, i64
return|return
name|vec_xst_len
argument_list|(
name|vsi128a
argument_list|,
name|sint128
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|char
name|test112
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.lxvll(i8* %{{.+}}, i64
comment|// CHECK: @llvm.ppc.vsx.lxvll(i8* %{{.+}}, i64
comment|// CHECK: @llvm.ppc.altivec.lvsr(i8* %{{.+}}
comment|// CHECK: @llvm.ppc.altivec.vperm
return|return
name|vec_xl_len_r
argument_list|(
name|uc
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test113
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: @llvm.ppc.vsx.stxvll(<4 x i32> %{{.+}}, i8* %{{.+}}, i64
comment|// CHECK: @llvm.ppc.altivec.lvsl(i8* %{{.+}}
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.vsx.stxvll(<4 x i32> %{{.+}}, i8* %{{.+}}, i64
return|return
name|vec_xst_len_r
argument_list|(
name|vuca
argument_list|,
name|uc
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|float
name|test114
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: shufflevector<8 x i16> {{.+}},<8 x i16> {{.+}},<8 x i32><i32 undef, i32 0, i32 undef, i32 1, i32 undef, i32 2, i32 undef, i32 3>
comment|// CHECK-BE: @llvm.ppc.vsx.xvcvhpsp(<8 x i16> {{.+}})
comment|// CHECK-BE-NEXT: ret<4 x float>
comment|// CHECK: shufflevector<8 x i16> {{.+}},<8 x i16> {{.+}},<8 x i32><i32 0, i32 undef, i32 1, i32 undef, i32 2, i32 undef, i32 3, i32 undef>
comment|// CHECK: @llvm.ppc.vsx.xvcvhpsp(<8 x i16> {{.+}})
comment|// CHECK-NEXT: ret<4 x float>
return|return
name|vec_extract_fp32_from_shorth
argument_list|(
name|vusa
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|float
name|test115
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: shufflevector<8 x i16> {{.+}},<8 x i16> {{.+}},<8 x i32><i32 undef, i32 4, i32 undef, i32 5, i32 undef, i32 6, i32 undef, i32 7>
comment|// CHECK-BE: @llvm.ppc.vsx.xvcvhpsp(<8 x i16> {{.+}})
comment|// CHECK-BE-NEXT: ret<4 x float>
comment|// CHECK: shufflevector<8 x i16> {{.+}},<8 x i16> {{.+}},<8 x i32><i32 4, i32 undef, i32 5, i32 undef, i32 6, i32 undef, i32 7, i32 undef>
comment|// CHECK: @llvm.ppc.vsx.xvcvhpsp(<8 x i16> {{.+}})
comment|// CHECK-NEXT: ret<4 x float>
return|return
name|vec_extract_fp32_from_shortl
argument_list|(
name|vusa
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|char
name|test116
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: [[T1:%.+]] = call<4 x i32> @llvm.ppc.vsx.xxinsertw(<4 x i32> {{.+}},<2 x i64> {{.+}}, i32 7)
comment|// CHECK-BE-NEXT: bitcast<4 x i32> [[T1]] to<16 x i8>
comment|// CHECK: [[T1:%.+]] = shufflevector<2 x i64> {{.+}},<2 x i64> {{.+}},<2 x i32><i32 1, i32 0>
comment|// CHECK-NEXT: [[T2:%.+]] =  bitcast<2 x i64> [[T1]] to<4 x i32>
comment|// CHECK-NEXT: [[T3:%.+]] = call<4 x i32> @llvm.ppc.vsx.xxinsertw(<4 x i32> [[T2]],<2 x i64> {{.+}}, i32 5)
comment|// CHECK-NEXT: bitcast<4 x i32> [[T3]] to<16 x i8>
return|return
name|vec_insert4b
argument_list|(
name|vuia
argument_list|,
name|vuca
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|char
name|test117
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: [[T1:%.+]] = call<4 x i32> @llvm.ppc.vsx.xxinsertw(<4 x i32> {{.+}},<2 x i64> {{.+}}, i32 12)
comment|// CHECK-BE-NEXT: bitcast<4 x i32> [[T1]] to<16 x i8>
comment|// CHECK: [[T1:%.+]] = shufflevector<2 x i64> {{.+}},<2 x i64> {{.+}},<2 x i32><i32 1, i32 0>
comment|// CHECK-NEXT: [[T2:%.+]] =  bitcast<2 x i64> [[T1]] to<4 x i32>
comment|// CHECK-NEXT: [[T3:%.+]] = call<4 x i32> @llvm.ppc.vsx.xxinsertw(<4 x i32> [[T2]],<2 x i64> {{.+}}, i32 0)
comment|// CHECK-NEXT: bitcast<4 x i32> [[T3]] to<16 x i8>
return|return
name|vec_insert4b
argument_list|(
name|vuia
argument_list|,
name|vuca
argument_list|,
literal|13
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|long
name|long
name|test118
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: call<2 x i64> @llvm.ppc.vsx.xxextractuw(<2 x i64> {{.+}}, i32 11)
comment|// CHECK-BE-NEXT: ret<2 x i64>
comment|// CHECK: [[T1:%.+]] = call<2 x i64> @llvm.ppc.vsx.xxextractuw(<2 x i64> {{.+}}, i32 1)
comment|// CHECK-NEXT: shufflevector<2 x i64> [[T1]],<2 x i64> [[T1]],<2 x i32><i32 1, i32 0>
comment|// CHECK-NEXT: ret<2 x i64>
return|return
name|vec_extract4b
argument_list|(
name|vuca
argument_list|,
literal|11
argument_list|)
return|;
block|}
end_function

begin_function
name|vector
name|unsigned
name|long
name|long
name|test119
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-BE: call<2 x i64> @llvm.ppc.vsx.xxextractuw(<2 x i64> {{.+}}, i32 0)
comment|// CHECK-BE-NEXT: ret<2 x i64>
comment|// CHECK: [[T1:%.+]] = call<2 x i64> @llvm.ppc.vsx.xxextractuw(<2 x i64> {{.+}}, i32 12)
comment|// CHECK-NEXT: shufflevector<2 x i64> [[T1]],<2 x i64> [[T1]],<2 x i32><i32 1, i32 0>
comment|// CHECK-NEXT: ret<2 x i64>
return|return
name|vec_extract4b
argument_list|(
name|vuca
argument_list|,
operator|-
literal|5
argument_list|)
return|;
block|}
end_function

end_unit

