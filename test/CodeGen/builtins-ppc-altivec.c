begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -faltivec -triple powerpc-unknown-unknown -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// TODO: uncomment
end_comment

begin_comment
comment|/*  vector bool char vbc = { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 }; */
end_comment

begin_decl_stmt
name|vector
name|signed
name|char
name|vsc
init|=
block|{
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
block|,
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
literal|16
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|unsigned
name|char
name|vuc
init|=
block|{
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
block|,
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
literal|16
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// TODO: uncomment
end_comment

begin_comment
comment|/*  vector bool short vbs = { 1, 0, 1, 0, 1, 0, 1, 0 }; */
end_comment

begin_decl_stmt
name|vector
name|short
name|vs
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
name|vector
name|unsigned
name|short
name|vus
init|=
block|{
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
block|,
literal|8
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// TODO: uncomment
end_comment

begin_comment
comment|/*  vector bool int vbi = { 1, 0, 1, 0 }; */
end_comment

begin_decl_stmt
name|vector
name|int
name|vi
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
name|vector
name|unsigned
name|int
name|vui
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|float
name|vf
init|=
block|{
operator|-
literal|1.5
block|,
literal|2.5
block|,
operator|-
literal|3.5
block|,
literal|4.5
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// TODO: uncomment
end_comment

begin_comment
comment|/*  vector bool char res_vbc; */
end_comment

begin_decl_stmt
name|vector
name|signed
name|char
name|res_vsc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|unsigned
name|char
name|res_vuc
decl_stmt|;
end_decl_stmt

begin_comment
comment|// TODO: uncomment
end_comment

begin_comment
comment|/*  vector bool short res_vbs; */
end_comment

begin_decl_stmt
name|vector
name|short
name|res_vs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|unsigned
name|short
name|res_vus
decl_stmt|;
end_decl_stmt

begin_comment
comment|// TODO: uncomment
end_comment

begin_decl_stmt
name|vector
name|pixel
name|res_vp
decl_stmt|;
end_decl_stmt

begin_comment
comment|// TODO: uncomment
end_comment

begin_comment
comment|/*  vector bool int res_vbi; */
end_comment

begin_decl_stmt
name|vector
name|int
name|res_vi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|unsigned
name|int
name|res_vui
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|float
name|res_vf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|signed
name|char
name|param_sc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|char
name|param_uc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|param_s
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|short
name|param_us
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|param_i
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|int
name|param_ui
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|param_f
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|res_i
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|test1
parameter_list|()
block|{
comment|// CHECK: define i32 @test1
comment|/* vec_abs */
name|vsc
operator|=
name|vec_abs
argument_list|(
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: sub nsw<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vmaxsb
name|vs
operator|=
name|vec_abs
argument_list|(
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: sub nsw<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vmaxsh
name|vi
operator|=
name|vec_abs
argument_list|(
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: sub nsw<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vmaxsw
name|vf
operator|=
name|vec_abs
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: and<4 x i32>
comment|/* vec_abs */
name|vsc
operator|=
name|vec_abss
argument_list|(
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubsbs
comment|// CHECK: @llvm.ppc.altivec.vmaxsb
name|vs
operator|=
name|vec_abss
argument_list|(
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubshs
comment|// CHECK: @llvm.ppc.altivec.vmaxsh
name|vi
operator|=
name|vec_abss
argument_list|(
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubsws
comment|// CHECK: @llvm.ppc.altivec.vmaxsw
comment|/*  vec_add */
name|res_vsc
operator|=
name|vec_add
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: add nsw<16 x i8>
name|res_vuc
operator|=
name|vec_add
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: add<16 x i8>
name|res_vs
operator|=
name|vec_add
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: add nsw<8 x i16>
name|res_vus
operator|=
name|vec_add
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: add<8 x i16>
name|res_vi
operator|=
name|vec_add
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: add nsw<4 x i32>
name|res_vui
operator|=
name|vec_add
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: add<4 x i32>
name|res_vf
operator|=
name|vec_add
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: fadd<4 x float>
name|res_vsc
operator|=
name|vec_vaddubm
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: add nsw<16 x i8>
name|res_vuc
operator|=
name|vec_vaddubm
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: add<16 x i8>
name|res_vs
operator|=
name|vec_vadduhm
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: add nsw<8 x i16>
name|res_vus
operator|=
name|vec_vadduhm
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: add<8 x i16>
name|res_vi
operator|=
name|vec_vadduwm
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: add nsw<4 x i32>
name|res_vui
operator|=
name|vec_vadduwm
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: add<4 x i32>
name|res_vf
operator|=
name|vec_vaddfp
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: fadd<4 x float>
comment|/* vec_addc */
name|res_vui
operator|=
name|vec_addc
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// HECK: @llvm.ppc.altivec.vaddcuw
name|res_vui
operator|=
name|vec_vaddcuw
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// HECK: @llvm.ppc.altivec.vaddcuw
comment|/* vec_adds */
name|res_vsc
operator|=
name|vec_adds
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddsbs
name|res_vuc
operator|=
name|vec_adds
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddubs
name|res_vs
operator|=
name|vec_adds
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddshs
name|res_vus
operator|=
name|vec_adds
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vadduhs
name|res_vi
operator|=
name|vec_adds
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddsws
name|res_vui
operator|=
name|vec_adds
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vadduws
name|res_vsc
operator|=
name|vec_vaddsbs
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddsbs
name|res_vuc
operator|=
name|vec_vaddubs
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddubs
name|res_vs
operator|=
name|vec_vaddshs
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddshs
name|res_vus
operator|=
name|vec_vadduhs
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vadduhs
name|res_vi
operator|=
name|vec_vaddsws
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddsws
name|res_vui
operator|=
name|vec_vadduws
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vadduws
comment|/* vec_and */
name|res_vsc
operator|=
name|vec_and
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: and<16 x i8>
name|res_vuc
operator|=
name|vec_and
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: and<16 x i8>
name|res_vs
operator|=
name|vec_and
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: and<8 x i16>
name|res_vus
operator|=
name|vec_and
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: and<8 x i16>
name|res_vi
operator|=
name|vec_and
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: and<4 x i32>
name|res_vui
operator|=
name|vec_and
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: and<4 x i32>
name|res_vsc
operator|=
name|vec_vand
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: and<16 x i8>
name|res_vuc
operator|=
name|vec_vand
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: and<16 x i8>
name|res_vs
operator|=
name|vec_vand
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: and<8 x i16>
name|res_vus
operator|=
name|vec_vand
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: and<8 x i16>
name|res_vi
operator|=
name|vec_vand
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: and<4 x i32>
name|res_vui
operator|=
name|vec_vand
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: and<4 x i32>
comment|/* vec_andc */
name|res_vsc
operator|=
name|vec_andc
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK: and<16 x i8>
name|res_vuc
operator|=
name|vec_andc
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK: and<16 x i8>
name|res_vs
operator|=
name|vec_andc
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK: and<8 x i16>
name|res_vus
operator|=
name|vec_andc
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK: and<8 x i16>
name|res_vi
operator|=
name|vec_andc
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
name|res_vui
operator|=
name|vec_andc
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
name|res_vf
operator|=
name|vec_andc
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
name|res_vsc
operator|=
name|vec_vandc
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK: and<16 x i8>
name|res_vuc
operator|=
name|vec_vandc
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK: and<16 x i8>
name|res_vs
operator|=
name|vec_vandc
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK: and<8 x i16>
name|res_vus
operator|=
name|vec_vandc
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK: and<8 x i16>
name|res_vi
operator|=
name|vec_vandc
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
name|res_vui
operator|=
name|vec_vandc
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
name|res_vf
operator|=
name|vec_vandc
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
block|}
end_function

begin_comment
comment|// CHECK: i32 @test2
end_comment

begin_function
name|int
name|test2
parameter_list|()
block|{
comment|/* vec_avg */
name|res_vsc
operator|=
name|vec_avg
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: call {{.*}}@llvm.ppc.altivec.vavgsb
name|res_vuc
operator|=
name|vec_avg
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vavgub
name|res_vs
operator|=
name|vec_avg
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vavgsh
name|res_vus
operator|=
name|vec_avg
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vavguh
name|res_vi
operator|=
name|vec_avg
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vavgsw
name|res_vui
operator|=
name|vec_avg
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vavguw
name|res_vsc
operator|=
name|vec_vavgsb
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vavgsb
name|res_vuc
operator|=
name|vec_vavgub
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vavgub
name|res_vs
operator|=
name|vec_vavgsh
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vavgsh
name|res_vus
operator|=
name|vec_vavguh
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vavguh
name|res_vi
operator|=
name|vec_vavgsw
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vavgsw
name|res_vui
operator|=
name|vec_vavguw
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vavguw
comment|/* vec_ceil */
name|res_vf
operator|=
name|vec_ceil
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrfip
name|res_vf
operator|=
name|vec_vrfip
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrfip
comment|/* vec_cmpb */
name|res_vi
operator|=
name|vec_cmpb
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpbfp
name|res_vi
operator|=
name|vec_vcmpbfp
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpbfp
comment|/* vec_cmpeq */
name|vsc
operator|=
name|vec_cmpeq
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHCK: call {{.*}}@llvm.ppc.altivec.vcmpequb
name|vuc
operator|=
name|vec_cmpeq
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHCK: @llvm.ppc.altivec.vcmpequb
name|vs
operator|=
name|vec_cmpeq
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHCK: @llvm.ppc.altivec.vcmpequh
name|vs
operator|=
name|vec_cmpeq
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHCK: @llvm.ppc.altivec.vcmpequh
name|vi
operator|=
name|vec_cmpeq
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHCK: @llvm.ppc.altivec.vcmpequw
name|vui
operator|=
name|vec_cmpeq
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHCK: @llvm.ppc.altivec.vcmpequw
name|vf
operator|=
name|vec_cmpeq
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHCK: @llvm.ppc.altivec.vcmpeqfp
comment|/* vec_cmpge */
name|vf
operator|=
name|vec_cmpge
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHCK: @llvm.ppc.altivec.vcmpgefp
name|vf
operator|=
name|vec_vcmpgefp
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHCK: call {{.*}}@llvm.ppc.altivec.vcmpgefp
block|}
end_function

begin_comment
comment|// CHECK: define i32 @test5
end_comment

begin_function
name|int
name|test5
parameter_list|()
block|{
comment|/* vec_cmpgt */
name|vsc
operator|=
name|vec_cmpgt
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: call {{.*}}@llvm.ppc.altivec.vcmpgtsb
name|vuc
operator|=
name|vec_cmpgt
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: call {{.*}}@llvm.ppc.altivec.vcmpgtub
name|vs
operator|=
name|vec_cmpgt
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: call {{.*}}@llvm.ppc.altivec.vcmpgtsh
name|vus
operator|=
name|vec_cmpgt
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh
name|vi
operator|=
name|vec_cmpgt
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsw
name|vui
operator|=
name|vec_cmpgt
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw
name|vf
operator|=
name|vec_cmpgt
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtfp
name|vsc
operator|=
name|vec_vcmpgtsb
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsb
name|vuc
operator|=
name|vec_vcmpgtub
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub
name|vs
operator|=
name|vec_vcmpgtsh
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsh
name|vus
operator|=
name|vec_vcmpgtuh
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh
name|vi
operator|=
name|vec_vcmpgtsw
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsw
name|vui
operator|=
name|vec_vcmpgtuw
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw
name|vf
operator|=
name|vec_vcmpgtfp
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtfp
comment|/* vec_cmple */
name|vf
operator|=
name|vec_cmple
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: call {{.*}}@llvm.ppc.altivec.vcmpgefp
block|}
end_function

begin_comment
comment|// CHECK: define i32 @test6
end_comment

begin_function
name|int
name|test6
parameter_list|()
block|{
comment|/* vec_cmplt */
name|vsc
operator|=
name|vec_cmplt
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: call {{.*}}@llvm.ppc.altivec.vcmpgtsb
name|vsc
operator|=
name|vec_cmplt
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: call {{.*}}@llvm.ppc.altivec.vcmpgtub
name|vs
operator|=
name|vec_cmplt
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: call {{.*}}@llvm.ppc.altivec.vcmpgtsh
name|vs
operator|=
name|vec_cmplt
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh
name|vi
operator|=
name|vec_cmplt
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsw
name|vui
operator|=
name|vec_cmplt
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw
name|vf
operator|=
name|vec_cmplt
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtfp
comment|/* vec_ctf */
name|res_vf
operator|=
name|vec_ctf
argument_list|(
name|vi
argument_list|,
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcfsx
name|res_vf
operator|=
name|vec_ctf
argument_list|(
name|vui
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcfux
name|res_vf
operator|=
name|vec_vcfsx
argument_list|(
name|vi
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcfsx
name|res_vf
operator|=
name|vec_vcfux
argument_list|(
name|vui
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcfux
comment|/* vec_cts */
name|res_vi
operator|=
name|vec_cts
argument_list|(
name|vf
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vctsxs
name|res_vi
operator|=
name|vec_vctsxs
argument_list|(
name|vf
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vctsxs
comment|/* vec_ctu */
name|res_vui
operator|=
name|vec_ctu
argument_list|(
name|vf
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vctuxs
name|res_vui
operator|=
name|vec_vctuxs
argument_list|(
name|vf
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vctuxs
comment|/* vec_dss */
name|vec_dss
argument_list|(
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.dss
comment|/* vec_dssall */
name|vec_dssall
argument_list|()
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.dssall
comment|/* vec_dst */
name|vec_dst
argument_list|(
operator|&
name|vsc
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.dst
comment|/* vec_dstst */
name|vec_dstst
argument_list|(
operator|&
name|vs
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.dstst
comment|/* vec_dststt */
name|vec_dststt
argument_list|(
operator|&
name|param_i
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.dststt
comment|/* vec_dstt */
name|vec_dstt
argument_list|(
operator|&
name|vf
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.dstt
comment|/* vec_expte */
name|res_vf
operator|=
name|vec_expte
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vexptefp
name|res_vf
operator|=
name|vec_vexptefp
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vexptefp
comment|/* vec_floor */
name|res_vf
operator|=
name|vec_floor
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrfim
name|res_vf
operator|=
name|vec_vrfim
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrfim
comment|/* vec_ld */
name|res_vsc
operator|=
name|vec_ld
argument_list|(
literal|0
argument_list|,
operator|&
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
name|res_vsc
operator|=
name|vec_ld
argument_list|(
literal|0
argument_list|,
operator|&
name|param_sc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
name|res_vuc
operator|=
name|vec_ld
argument_list|(
literal|0
argument_list|,
operator|&
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
name|res_vuc
operator|=
name|vec_ld
argument_list|(
literal|0
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
name|res_vs
operator|=
name|vec_ld
argument_list|(
literal|0
argument_list|,
operator|&
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
name|res_vs
operator|=
name|vec_ld
argument_list|(
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
name|res_vus
operator|=
name|vec_ld
argument_list|(
literal|0
argument_list|,
operator|&
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
name|res_vus
operator|=
name|vec_ld
argument_list|(
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
name|res_vi
operator|=
name|vec_ld
argument_list|(
literal|0
argument_list|,
operator|&
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
name|res_vi
operator|=
name|vec_ld
argument_list|(
literal|0
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
name|res_vui
operator|=
name|vec_ld
argument_list|(
literal|0
argument_list|,
operator|&
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
name|res_vui
operator|=
name|vec_ld
argument_list|(
literal|0
argument_list|,
operator|&
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
name|res_vf
operator|=
name|vec_ld
argument_list|(
literal|0
argument_list|,
operator|&
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
name|res_vf
operator|=
name|vec_ld
argument_list|(
literal|0
argument_list|,
operator|&
name|param_f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
name|res_vsc
operator|=
name|vec_lvx
argument_list|(
literal|0
argument_list|,
operator|&
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
name|res_vsc
operator|=
name|vec_lvx
argument_list|(
literal|0
argument_list|,
operator|&
name|param_sc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
name|res_vuc
operator|=
name|vec_lvx
argument_list|(
literal|0
argument_list|,
operator|&
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
name|res_vuc
operator|=
name|vec_lvx
argument_list|(
literal|0
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
name|res_vs
operator|=
name|vec_lvx
argument_list|(
literal|0
argument_list|,
operator|&
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
name|res_vs
operator|=
name|vec_lvx
argument_list|(
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
name|res_vus
operator|=
name|vec_lvx
argument_list|(
literal|0
argument_list|,
operator|&
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
name|res_vus
operator|=
name|vec_lvx
argument_list|(
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
name|res_vi
operator|=
name|vec_lvx
argument_list|(
literal|0
argument_list|,
operator|&
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
name|res_vi
operator|=
name|vec_lvx
argument_list|(
literal|0
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
name|res_vui
operator|=
name|vec_lvx
argument_list|(
literal|0
argument_list|,
operator|&
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
name|res_vui
operator|=
name|vec_lvx
argument_list|(
literal|0
argument_list|,
operator|&
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
name|res_vf
operator|=
name|vec_lvx
argument_list|(
literal|0
argument_list|,
operator|&
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
name|res_vf
operator|=
name|vec_lvx
argument_list|(
literal|0
argument_list|,
operator|&
name|param_f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|/* vec_lde */
name|res_vsc
operator|=
name|vec_lde
argument_list|(
literal|0
argument_list|,
operator|&
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvebx
name|res_vuc
operator|=
name|vec_lde
argument_list|(
literal|0
argument_list|,
operator|&
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvebx
name|res_vs
operator|=
name|vec_lde
argument_list|(
literal|0
argument_list|,
operator|&
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvehx
name|res_vus
operator|=
name|vec_lde
argument_list|(
literal|0
argument_list|,
operator|&
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvehx
name|res_vi
operator|=
name|vec_lde
argument_list|(
literal|0
argument_list|,
operator|&
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvewx
name|res_vui
operator|=
name|vec_lde
argument_list|(
literal|0
argument_list|,
operator|&
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvewx
name|res_vf
operator|=
name|vec_lde
argument_list|(
literal|0
argument_list|,
operator|&
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvewx
name|res_vsc
operator|=
name|vec_lvebx
argument_list|(
literal|0
argument_list|,
operator|&
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvebx
name|res_vuc
operator|=
name|vec_lvebx
argument_list|(
literal|0
argument_list|,
operator|&
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvebx
name|res_vs
operator|=
name|vec_lvehx
argument_list|(
literal|0
argument_list|,
operator|&
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvehx
name|res_vus
operator|=
name|vec_lvehx
argument_list|(
literal|0
argument_list|,
operator|&
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvehx
name|res_vi
operator|=
name|vec_lvewx
argument_list|(
literal|0
argument_list|,
operator|&
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvewx
name|res_vui
operator|=
name|vec_lvewx
argument_list|(
literal|0
argument_list|,
operator|&
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvewx
name|res_vf
operator|=
name|vec_lvewx
argument_list|(
literal|0
argument_list|,
operator|&
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvewx
comment|/* vec_ldl */
name|res_vsc
operator|=
name|vec_ldl
argument_list|(
literal|0
argument_list|,
operator|&
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
name|res_vsc
operator|=
name|vec_ldl
argument_list|(
literal|0
argument_list|,
operator|&
name|param_sc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
name|res_vuc
operator|=
name|vec_ldl
argument_list|(
literal|0
argument_list|,
operator|&
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
name|res_vuc
operator|=
name|vec_ldl
argument_list|(
literal|0
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
name|res_vs
operator|=
name|vec_ldl
argument_list|(
literal|0
argument_list|,
operator|&
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
name|res_vs
operator|=
name|vec_ldl
argument_list|(
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
name|res_vus
operator|=
name|vec_ldl
argument_list|(
literal|0
argument_list|,
operator|&
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
name|res_vus
operator|=
name|vec_ldl
argument_list|(
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
name|res_vi
operator|=
name|vec_ldl
argument_list|(
literal|0
argument_list|,
operator|&
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
name|res_vi
operator|=
name|vec_ldl
argument_list|(
literal|0
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
name|res_vui
operator|=
name|vec_ldl
argument_list|(
literal|0
argument_list|,
operator|&
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
name|res_vui
operator|=
name|vec_ldl
argument_list|(
literal|0
argument_list|,
operator|&
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
name|res_vf
operator|=
name|vec_ldl
argument_list|(
literal|0
argument_list|,
operator|&
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
name|res_vf
operator|=
name|vec_ldl
argument_list|(
literal|0
argument_list|,
operator|&
name|param_f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
name|res_vsc
operator|=
name|vec_lvxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
name|res_vsc
operator|=
name|vec_lvxl
argument_list|(
literal|0
argument_list|,
operator|&
name|param_sc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
name|res_vuc
operator|=
name|vec_lvxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
name|res_vuc
operator|=
name|vec_lvxl
argument_list|(
literal|0
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
name|res_vs
operator|=
name|vec_lvxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
name|res_vs
operator|=
name|vec_lvxl
argument_list|(
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
name|res_vus
operator|=
name|vec_lvxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
name|res_vus
operator|=
name|vec_lvxl
argument_list|(
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
name|res_vi
operator|=
name|vec_lvxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
name|res_vi
operator|=
name|vec_lvxl
argument_list|(
literal|0
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
name|res_vui
operator|=
name|vec_lvxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
name|res_vui
operator|=
name|vec_lvxl
argument_list|(
literal|0
argument_list|,
operator|&
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
name|res_vf
operator|=
name|vec_lvxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
name|res_vf
operator|=
name|vec_lvxl
argument_list|(
literal|0
argument_list|,
operator|&
name|param_f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|/* vec_loge */
name|res_vf
operator|=
name|vec_loge
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vlogefp
name|res_vf
operator|=
name|vec_vlogefp
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vlogefp
comment|/* vec_lvsl */
name|res_vuc
operator|=
name|vec_lvsl
argument_list|(
literal|0
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|/* vec_lvsr */
name|res_vuc
operator|=
name|vec_lvsr
argument_list|(
literal|0
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|/* vec_madd */
name|res_vf
operator|=
name|vec_madd
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaddfp
name|res_vf
operator|=
name|vec_vmaddfp
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaddfp
comment|/* vec_madds */
name|res_vs
operator|=
name|vec_madds
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmhaddshs
name|res_vs
operator|=
name|vec_vmhaddshs
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmhaddshs
comment|/* vec_max */
name|res_vsc
operator|=
name|vec_max
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxsb
name|res_vuc
operator|=
name|vec_max
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxub
name|res_vs
operator|=
name|vec_max
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxsh
name|res_vus
operator|=
name|vec_max
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxuh
name|res_vi
operator|=
name|vec_max
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxsw
name|res_vui
operator|=
name|vec_max
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxuw
name|res_vf
operator|=
name|vec_max
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxfp
name|res_vsc
operator|=
name|vec_vmaxsb
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxsb
name|res_vuc
operator|=
name|vec_vmaxub
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxub
name|res_vs
operator|=
name|vec_vmaxsh
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxsh
name|res_vus
operator|=
name|vec_vmaxuh
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxuh
name|res_vi
operator|=
name|vec_vmaxsw
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxsw
name|res_vui
operator|=
name|vec_vmaxuw
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxuw
name|res_vf
operator|=
name|vec_vmaxfp
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxfp
comment|/* vec_mergeh */
name|res_vsc
operator|=
name|vec_mergeh
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vuc
operator|=
name|vec_mergeh
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vs
operator|=
name|vec_mergeh
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vus
operator|=
name|vec_mergeh
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vi
operator|=
name|vec_mergeh
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vui
operator|=
name|vec_mergeh
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vf
operator|=
name|vec_mergeh
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vsc
operator|=
name|vec_vmrghb
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vuc
operator|=
name|vec_vmrghb
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vs
operator|=
name|vec_vmrghh
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vus
operator|=
name|vec_vmrghh
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vi
operator|=
name|vec_vmrghw
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vui
operator|=
name|vec_vmrghw
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vf
operator|=
name|vec_vmrghw
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|/* vec_mergel */
name|res_vsc
operator|=
name|vec_mergel
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vuc
operator|=
name|vec_mergel
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vs
operator|=
name|vec_mergel
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vus
operator|=
name|vec_mergel
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vi
operator|=
name|vec_mergel
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vui
operator|=
name|vec_mergel
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vf
operator|=
name|vec_mergel
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vsc
operator|=
name|vec_vmrglb
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vuc
operator|=
name|vec_vmrglb
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vs
operator|=
name|vec_vmrglh
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vus
operator|=
name|vec_vmrglh
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vi
operator|=
name|vec_vmrglw
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vui
operator|=
name|vec_vmrglw
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vf
operator|=
name|vec_vmrglw
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|/* vec_mfvscr */
name|vus
operator|=
name|vec_mfvscr
argument_list|()
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.mfvscr
comment|/* vec_min */
name|res_vsc
operator|=
name|vec_min
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminsb
name|res_vuc
operator|=
name|vec_min
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminub
name|res_vs
operator|=
name|vec_min
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminsh
name|res_vus
operator|=
name|vec_min
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminuh
name|res_vi
operator|=
name|vec_min
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminsw
name|res_vui
operator|=
name|vec_min
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminuw
name|res_vf
operator|=
name|vec_min
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminfp
name|res_vsc
operator|=
name|vec_vminsb
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminsb
name|res_vuc
operator|=
name|vec_vminub
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminub
name|res_vs
operator|=
name|vec_vminsh
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminsh
name|res_vus
operator|=
name|vec_vminuh
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminuh
name|res_vi
operator|=
name|vec_vminsw
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminsw
name|res_vui
operator|=
name|vec_vminuw
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminuw
name|res_vf
operator|=
name|vec_vminfp
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminfp
comment|/* vec_mladd */
name|res_vus
operator|=
name|vec_mladd
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: mul<8 x i16>
comment|// CHECK: add<8 x i16>
name|res_vs
operator|=
name|vec_mladd
argument_list|(
name|vus
argument_list|,
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: mul nsw<8 x i16>
comment|// CHECK: add nsw<8 x i16>
name|res_vs
operator|=
name|vec_mladd
argument_list|(
name|vs
argument_list|,
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: mul nsw<8 x i16>
comment|// CHECK: add nsw<8 x i16>
name|res_vs
operator|=
name|vec_mladd
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: mul nsw<8 x i16>
comment|// CHECK: add nsw<8 x i16>
comment|/* vec_mradds */
name|res_vs
operator|=
name|vec_mradds
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmhraddshs
name|res_vs
operator|=
name|vec_vmhraddshs
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmhraddshs
comment|/* vec_msum */
name|res_vi
operator|=
name|vec_msum
argument_list|(
name|vsc
argument_list|,
name|vuc
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmsummbm
name|res_vui
operator|=
name|vec_msum
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmsumubm
name|res_vi
operator|=
name|vec_msum
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmsumshm
name|res_vui
operator|=
name|vec_msum
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmsumuhm
name|res_vi
operator|=
name|vec_vmsummbm
argument_list|(
name|vsc
argument_list|,
name|vuc
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmsummbm
name|res_vui
operator|=
name|vec_vmsumubm
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmsumubm
name|res_vi
operator|=
name|vec_vmsumshm
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmsumshm
name|res_vui
operator|=
name|vec_vmsumuhm
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmsumuhm
comment|/* vec_msums */
name|res_vi
operator|=
name|vec_msums
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmsumshs
name|res_vui
operator|=
name|vec_msums
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmsumuhs
name|res_vi
operator|=
name|vec_vmsumshs
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmsumshs
name|res_vui
operator|=
name|vec_vmsumuhs
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmsumuhs
comment|/* vec_mtvscr */
name|vec_mtvscr
argument_list|(
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.mtvscr
comment|/* vec_mule */
name|res_vs
operator|=
name|vec_mule
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmulesb
name|res_vus
operator|=
name|vec_mule
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmuleub
name|res_vi
operator|=
name|vec_mule
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmulesh
name|res_vui
operator|=
name|vec_mule
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmuleuh
name|res_vs
operator|=
name|vec_vmulesb
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmulesb
name|res_vus
operator|=
name|vec_vmuleub
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmuleub
name|res_vi
operator|=
name|vec_vmulesh
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmulesh
name|res_vui
operator|=
name|vec_vmuleuh
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmuleuh
comment|/* vec_mulo */
name|res_vs
operator|=
name|vec_mulo
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmulosb
name|res_vus
operator|=
name|vec_mulo
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmuloub
name|res_vi
operator|=
name|vec_mulo
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmulosh
name|res_vui
operator|=
name|vec_mulo
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmulouh
name|res_vs
operator|=
name|vec_vmulosb
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmulosb
name|res_vus
operator|=
name|vec_vmuloub
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmuloub
name|res_vi
operator|=
name|vec_vmulosh
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmulosh
name|res_vui
operator|=
name|vec_vmulouh
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmulouh
comment|/* vec_nmsub */
name|res_vf
operator|=
name|vec_nmsub
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vnmsubfp
name|res_vf
operator|=
name|vec_vnmsubfp
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vnmsubfp
comment|/* vec_nor */
name|res_vsc
operator|=
name|vec_nor
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: or<16 x i8>
comment|// CHECK: xor<16 x i8>
name|res_vuc
operator|=
name|vec_nor
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: or<16 x i8>
comment|// CHECK: xor<16 x i8>
name|res_vs
operator|=
name|vec_nor
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: or<8 x i16>
comment|// CHECK: xor<8 x i16>
name|res_vus
operator|=
name|vec_nor
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: or<8 x i16>
comment|// CHECK: xor<8 x i16>
name|res_vi
operator|=
name|vec_nor
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: or<4 x i32>
comment|// CHECK: xor<4 x i32>
name|res_vui
operator|=
name|vec_nor
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: or<4 x i32>
comment|// CHECK: xor<4 x i32>
name|res_vf
operator|=
name|vec_nor
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: or<4 x i32>
comment|// CHECK: xor<4 x i32>
name|res_vsc
operator|=
name|vec_vnor
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: or<16 x i8>
comment|// CHECK: xor<16 x i8>
name|res_vuc
operator|=
name|vec_vnor
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: or<16 x i8>
comment|// CHECK: xor<16 x i8>
name|res_vs
operator|=
name|vec_vnor
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: or<8 x i16>
comment|// CHECK: xor<8 x i16>
name|res_vus
operator|=
name|vec_vnor
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: or<8 x i16>
comment|// CHECK: xor<8 x i16>
name|res_vi
operator|=
name|vec_vnor
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: or<4 x i32>
comment|// CHECK: xor<4 x i32>
name|res_vui
operator|=
name|vec_vnor
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: or<4 x i32>
comment|// CHECK: xor<4 x i32>
name|res_vf
operator|=
name|vec_vnor
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: or<4 x i32>
comment|// CHECK: xor<4 x i32>
comment|/* vec_or */
name|res_vsc
operator|=
name|vec_or
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: or<16 x i8>
name|res_vuc
operator|=
name|vec_or
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: or<16 x i8>
name|res_vs
operator|=
name|vec_or
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: or<8 x i16>
name|res_vus
operator|=
name|vec_or
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: or<8 x i16>
name|res_vi
operator|=
name|vec_or
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: or<4 x i32>
name|res_vui
operator|=
name|vec_or
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: or<4 x i32>
name|res_vf
operator|=
name|vec_or
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: or<4 x i32>
name|res_vsc
operator|=
name|vec_vor
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: or<16 x i8>
name|res_vuc
operator|=
name|vec_vor
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: or<16 x i8>
name|res_vs
operator|=
name|vec_vor
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: or<8 x i16>
name|res_vus
operator|=
name|vec_vor
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: or<8 x i16>
name|res_vi
operator|=
name|vec_vor
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: or<4 x i32>
name|res_vui
operator|=
name|vec_vor
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: or<4 x i32>
name|res_vf
operator|=
name|vec_vor
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: or<4 x i32>
comment|/* vec_pack */
name|res_vsc
operator|=
name|vec_pack
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vuc
operator|=
name|vec_pack
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vs
operator|=
name|vec_pack
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vus
operator|=
name|vec_pack
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vsc
operator|=
name|vec_vpkuhum
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vuc
operator|=
name|vec_vpkuhum
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vs
operator|=
name|vec_vpkuwum
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vus
operator|=
name|vec_vpkuwum
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|/* vec_packpx */
name|res_vp
operator|=
name|vec_packpx
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vpkpx
name|res_vp
operator|=
name|vec_vpkpx
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vpkpx
comment|/* vec_packs */
name|res_vsc
operator|=
name|vec_packs
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vpkshss
name|res_vuc
operator|=
name|vec_packs
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vpkuhus
name|res_vs
operator|=
name|vec_packs
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vpkswss
name|res_vus
operator|=
name|vec_packs
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vpkuwus
name|res_vsc
operator|=
name|vec_vpkshss
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vpkshss
name|res_vuc
operator|=
name|vec_vpkuhus
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vpkuhus
name|res_vs
operator|=
name|vec_vpkswss
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vpkswss
name|res_vus
operator|=
name|vec_vpkuwus
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vpkuwus
comment|/* vec_packsu */
name|res_vuc
operator|=
name|vec_packsu
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vpkshus
name|res_vuc
operator|=
name|vec_packsu
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vpkuhus
name|res_vus
operator|=
name|vec_packsu
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vpkswus
name|res_vus
operator|=
name|vec_packsu
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vpkuwus
name|res_vuc
operator|=
name|vec_vpkshus
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vpkshus
name|res_vuc
operator|=
name|vec_vpkshus
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vpkuhus
name|res_vus
operator|=
name|vec_vpkswus
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vpkswus
name|res_vus
operator|=
name|vec_vpkswus
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vpkuwus
comment|/* vec_perm */
name|res_vsc
operator|=
name|vec_perm
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vuc
operator|=
name|vec_perm
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vs
operator|=
name|vec_perm
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vus
operator|=
name|vec_perm
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vi
operator|=
name|vec_perm
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vui
operator|=
name|vec_perm
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vf
operator|=
name|vec_perm
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vsc
operator|=
name|vec_vperm
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vuc
operator|=
name|vec_vperm
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vs
operator|=
name|vec_vperm
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vus
operator|=
name|vec_vperm
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vi
operator|=
name|vec_vperm
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vui
operator|=
name|vec_vperm
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vf
operator|=
name|vec_vperm
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|/* vec_re */
name|res_vf
operator|=
name|vec_re
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrefp
name|res_vf
operator|=
name|vec_vrefp
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrefp
comment|/* vec_rl */
name|res_vsc
operator|=
name|vec_rl
argument_list|(
name|vsc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrlb
name|res_vuc
operator|=
name|vec_rl
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrlb
name|res_vs
operator|=
name|vec_rl
argument_list|(
name|vs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrlh
name|res_vus
operator|=
name|vec_rl
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrlh
name|res_vi
operator|=
name|vec_rl
argument_list|(
name|vi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrlw
name|res_vui
operator|=
name|vec_rl
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrlw
name|res_vsc
operator|=
name|vec_vrlb
argument_list|(
name|vsc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrlb
name|res_vuc
operator|=
name|vec_vrlb
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrlb
name|res_vs
operator|=
name|vec_vrlh
argument_list|(
name|vs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrlh
name|res_vus
operator|=
name|vec_vrlh
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrlh
name|res_vi
operator|=
name|vec_vrlw
argument_list|(
name|vi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrlw
name|res_vui
operator|=
name|vec_vrlw
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrlw
comment|/* vec_round */
name|res_vf
operator|=
name|vec_round
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrfin
name|res_vf
operator|=
name|vec_vrfin
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrfin
comment|/* vec_rsqrte */
name|res_vf
operator|=
name|vec_rsqrte
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrsqrtefp
name|res_vf
operator|=
name|vec_vrsqrtefp
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrsqrtefp
comment|/* vec_sel */
name|res_vsc
operator|=
name|vec_sel
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK: or<16 x i8>
name|res_vuc
operator|=
name|vec_sel
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK: or<16 x i8>
name|res_vs
operator|=
name|vec_sel
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK: or<8 x i16>
name|res_vus
operator|=
name|vec_sel
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK: or<8 x i16>
name|res_vi
operator|=
name|vec_sel
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: or<4 x i32>
name|res_vui
operator|=
name|vec_sel
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: or<4 x i32>
name|res_vf
operator|=
name|vec_sel
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: or<4 x i32>
name|res_vsc
operator|=
name|vec_vsel
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK: or<16 x i8>
name|res_vuc
operator|=
name|vec_vsel
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK: or<16 x i8>
name|res_vs
operator|=
name|vec_vsel
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK: or<8 x i16>
name|res_vus
operator|=
name|vec_vsel
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK: or<8 x i16>
name|res_vi
operator|=
name|vec_vsel
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: or<4 x i32>
name|res_vui
operator|=
name|vec_vsel
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: or<4 x i32>
name|res_vf
operator|=
name|vec_vsel
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: or<4 x i32>
comment|/* vec_sl */
name|res_vsc
operator|=
name|vec_sl
argument_list|(
name|vsc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: shl<16 x i8>
name|res_vuc
operator|=
name|vec_sl
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: shl<16 x i8>
name|res_vs
operator|=
name|vec_sl
argument_list|(
name|vs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: shl<8 x i16>
name|res_vus
operator|=
name|vec_sl
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: shl<8 x i16>
name|res_vi
operator|=
name|vec_sl
argument_list|(
name|vi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: shl<4 x i32>
name|res_vui
operator|=
name|vec_sl
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: shl<4 x i32>
name|res_vsc
operator|=
name|vec_vslb
argument_list|(
name|vsc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: shl<16 x i8>
name|res_vuc
operator|=
name|vec_vslb
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: shl<16 x i8>
name|res_vs
operator|=
name|vec_vslh
argument_list|(
name|vs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: shl<8 x i16>
name|res_vus
operator|=
name|vec_vslh
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: shl<8 x i16>
name|res_vi
operator|=
name|vec_vslw
argument_list|(
name|vi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: shl<4 x i32>
name|res_vui
operator|=
name|vec_vslw
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: shl<4 x i32>
comment|/* vec_sld */
name|res_vsc
operator|=
name|vec_sld
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vuc
operator|=
name|vec_sld
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vs
operator|=
name|vec_sld
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vus
operator|=
name|vec_sld
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vi
operator|=
name|vec_sld
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vui
operator|=
name|vec_sld
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vf
operator|=
name|vec_sld
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vsc
operator|=
name|vec_vsldoi
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vuc
operator|=
name|vec_vsldoi
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vs
operator|=
name|vec_vsldoi
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vus
operator|=
name|vec_vsldoi
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vi
operator|=
name|vec_vsldoi
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vui
operator|=
name|vec_vsldoi
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vf
operator|=
name|vec_vsldoi
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|/* vec_sll */
name|res_vsc
operator|=
name|vec_sll
argument_list|(
name|vsc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vsc
operator|=
name|vec_sll
argument_list|(
name|vsc
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vsc
operator|=
name|vec_sll
argument_list|(
name|vsc
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vuc
operator|=
name|vec_sll
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vuc
operator|=
name|vec_sll
argument_list|(
name|vuc
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vuc
operator|=
name|vec_sll
argument_list|(
name|vuc
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vs
operator|=
name|vec_sll
argument_list|(
name|vs
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vs
operator|=
name|vec_sll
argument_list|(
name|vs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vs
operator|=
name|vec_sll
argument_list|(
name|vs
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vus
operator|=
name|vec_sll
argument_list|(
name|vus
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vus
operator|=
name|vec_sll
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vus
operator|=
name|vec_sll
argument_list|(
name|vus
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vi
operator|=
name|vec_sll
argument_list|(
name|vi
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vi
operator|=
name|vec_sll
argument_list|(
name|vi
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vi
operator|=
name|vec_sll
argument_list|(
name|vi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vui
operator|=
name|vec_sll
argument_list|(
name|vui
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vui
operator|=
name|vec_sll
argument_list|(
name|vui
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vui
operator|=
name|vec_sll
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vsc
operator|=
name|vec_vsl
argument_list|(
name|vsc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vsc
operator|=
name|vec_vsl
argument_list|(
name|vsc
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vsc
operator|=
name|vec_vsl
argument_list|(
name|vsc
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vuc
operator|=
name|vec_vsl
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vuc
operator|=
name|vec_vsl
argument_list|(
name|vuc
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vuc
operator|=
name|vec_vsl
argument_list|(
name|vuc
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vs
operator|=
name|vec_vsl
argument_list|(
name|vs
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vs
operator|=
name|vec_vsl
argument_list|(
name|vs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vs
operator|=
name|vec_vsl
argument_list|(
name|vs
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vus
operator|=
name|vec_vsl
argument_list|(
name|vus
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vus
operator|=
name|vec_vsl
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vus
operator|=
name|vec_vsl
argument_list|(
name|vus
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vi
operator|=
name|vec_vsl
argument_list|(
name|vi
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vi
operator|=
name|vec_vsl
argument_list|(
name|vi
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vi
operator|=
name|vec_vsl
argument_list|(
name|vi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vui
operator|=
name|vec_vsl
argument_list|(
name|vui
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vui
operator|=
name|vec_vsl
argument_list|(
name|vui
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
name|res_vui
operator|=
name|vec_vsl
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
comment|/* vec_slo */
name|res_vsc
operator|=
name|vec_slo
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
name|res_vsc
operator|=
name|vec_slo
argument_list|(
name|vsc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
name|res_vuc
operator|=
name|vec_slo
argument_list|(
name|vuc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
name|res_vuc
operator|=
name|vec_slo
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
name|res_vs
operator|=
name|vec_slo
argument_list|(
name|vs
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
name|res_vs
operator|=
name|vec_slo
argument_list|(
name|vs
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
name|res_vus
operator|=
name|vec_slo
argument_list|(
name|vus
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
name|res_vus
operator|=
name|vec_slo
argument_list|(
name|vus
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
name|res_vi
operator|=
name|vec_slo
argument_list|(
name|vi
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
name|res_vi
operator|=
name|vec_slo
argument_list|(
name|vi
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
name|res_vui
operator|=
name|vec_slo
argument_list|(
name|vui
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
name|res_vui
operator|=
name|vec_slo
argument_list|(
name|vui
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
name|res_vf
operator|=
name|vec_slo
argument_list|(
name|vf
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
name|res_vf
operator|=
name|vec_slo
argument_list|(
name|vf
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
name|res_vsc
operator|=
name|vec_vslo
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
name|res_vsc
operator|=
name|vec_vslo
argument_list|(
name|vsc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
name|res_vuc
operator|=
name|vec_vslo
argument_list|(
name|vuc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
name|res_vuc
operator|=
name|vec_vslo
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
name|res_vs
operator|=
name|vec_vslo
argument_list|(
name|vs
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
name|res_vs
operator|=
name|vec_vslo
argument_list|(
name|vs
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
name|res_vus
operator|=
name|vec_vslo
argument_list|(
name|vus
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
name|res_vus
operator|=
name|vec_vslo
argument_list|(
name|vus
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
name|res_vi
operator|=
name|vec_vslo
argument_list|(
name|vi
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
name|res_vi
operator|=
name|vec_vslo
argument_list|(
name|vi
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
name|res_vui
operator|=
name|vec_vslo
argument_list|(
name|vui
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
name|res_vui
operator|=
name|vec_vslo
argument_list|(
name|vui
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
name|res_vf
operator|=
name|vec_vslo
argument_list|(
name|vf
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
name|res_vf
operator|=
name|vec_vslo
argument_list|(
name|vf
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
comment|/* vec_splat */
name|res_vsc
operator|=
name|vec_splat
argument_list|(
name|vsc
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vuc
operator|=
name|vec_splat
argument_list|(
name|vuc
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vs
operator|=
name|vec_splat
argument_list|(
name|vs
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vus
operator|=
name|vec_splat
argument_list|(
name|vus
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vi
operator|=
name|vec_splat
argument_list|(
name|vi
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vui
operator|=
name|vec_splat
argument_list|(
name|vui
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vf
operator|=
name|vec_splat
argument_list|(
name|vf
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vsc
operator|=
name|vec_vspltb
argument_list|(
name|vsc
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vuc
operator|=
name|vec_vspltb
argument_list|(
name|vuc
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vs
operator|=
name|vec_vsplth
argument_list|(
name|vs
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vus
operator|=
name|vec_vsplth
argument_list|(
name|vus
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vi
operator|=
name|vec_vspltw
argument_list|(
name|vi
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vui
operator|=
name|vec_vspltw
argument_list|(
name|vui
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
name|res_vf
operator|=
name|vec_vspltw
argument_list|(
name|vf
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|/* vec_splat_s8 */
name|res_vsc
operator|=
name|vec_splat_s8
argument_list|(
literal|0x09
argument_list|)
expr_stmt|;
comment|// TODO: add check
name|res_vsc
operator|=
name|vec_vspltisb
argument_list|(
literal|0x09
argument_list|)
expr_stmt|;
comment|// TODO: add check
comment|/* vec_splat_s16 */
name|res_vs
operator|=
name|vec_splat_s16
argument_list|(
literal|0x09
argument_list|)
expr_stmt|;
comment|// TODO: add check
name|res_vs
operator|=
name|vec_vspltish
argument_list|(
literal|0x09
argument_list|)
expr_stmt|;
comment|// TODO: add check
comment|/* vec_splat_s32 */
name|res_vi
operator|=
name|vec_splat_s32
argument_list|(
literal|0x09
argument_list|)
expr_stmt|;
comment|// TODO: add check
name|res_vi
operator|=
name|vec_vspltisw
argument_list|(
literal|0x09
argument_list|)
expr_stmt|;
comment|// TODO: add check
comment|/* vec_splat_u8 */
name|res_vuc
operator|=
name|vec_splat_u8
argument_list|(
literal|0x09
argument_list|)
expr_stmt|;
comment|// TODO: add check
comment|/* vec_splat_u16 */
name|res_vus
operator|=
name|vec_splat_u16
argument_list|(
literal|0x09
argument_list|)
expr_stmt|;
comment|// TODO: add check
comment|/* vec_splat_u32 */
name|res_vui
operator|=
name|vec_splat_u32
argument_list|(
literal|0x09
argument_list|)
expr_stmt|;
comment|// TODO: add check
comment|/* vec_sr */
name|res_vsc
operator|=
name|vec_sr
argument_list|(
name|vsc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: shr<16 x i8>
name|res_vuc
operator|=
name|vec_sr
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: shr<16 x i8>
name|res_vs
operator|=
name|vec_sr
argument_list|(
name|vs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: shr<8 x i16>
name|res_vus
operator|=
name|vec_sr
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: shr<8 x i16>
name|res_vi
operator|=
name|vec_sr
argument_list|(
name|vi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: shr<4 x i32>
name|res_vui
operator|=
name|vec_sr
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: shr<4 x i32>
name|res_vsc
operator|=
name|vec_vsrb
argument_list|(
name|vsc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: shr<16 x i8>
name|res_vuc
operator|=
name|vec_vsrb
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: shr<16 x i8>
name|res_vs
operator|=
name|vec_vsrh
argument_list|(
name|vs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: shr<8 x i16>
name|res_vus
operator|=
name|vec_vsrh
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: shr<8 x i16>
name|res_vi
operator|=
name|vec_vsrw
argument_list|(
name|vi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: shr<4 x i32>
name|res_vui
operator|=
name|vec_vsrw
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: shr<4 x i32>
comment|/* vec_sra */
name|res_vsc
operator|=
name|vec_sra
argument_list|(
name|vsc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsrab
name|res_vuc
operator|=
name|vec_sra
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsrab
name|res_vs
operator|=
name|vec_sra
argument_list|(
name|vs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsrah
name|res_vus
operator|=
name|vec_sra
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsrah
name|res_vi
operator|=
name|vec_sra
argument_list|(
name|vi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsraw
name|res_vui
operator|=
name|vec_sra
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsraw
name|res_vsc
operator|=
name|vec_vsrab
argument_list|(
name|vsc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsrab
name|res_vuc
operator|=
name|vec_vsrab
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsrab
name|res_vs
operator|=
name|vec_vsrah
argument_list|(
name|vs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsrah
name|res_vus
operator|=
name|vec_vsrah
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsrah
name|res_vi
operator|=
name|vec_vsraw
argument_list|(
name|vi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsraw
name|res_vui
operator|=
name|vec_vsraw
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsraw
comment|/* vec_srl */
name|res_vsc
operator|=
name|vec_srl
argument_list|(
name|vsc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vsc
operator|=
name|vec_srl
argument_list|(
name|vsc
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vsc
operator|=
name|vec_srl
argument_list|(
name|vsc
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vuc
operator|=
name|vec_srl
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vuc
operator|=
name|vec_srl
argument_list|(
name|vuc
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vuc
operator|=
name|vec_srl
argument_list|(
name|vuc
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vs
operator|=
name|vec_srl
argument_list|(
name|vs
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vs
operator|=
name|vec_srl
argument_list|(
name|vs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vs
operator|=
name|vec_srl
argument_list|(
name|vs
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vus
operator|=
name|vec_srl
argument_list|(
name|vus
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vus
operator|=
name|vec_srl
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vus
operator|=
name|vec_srl
argument_list|(
name|vus
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vi
operator|=
name|vec_srl
argument_list|(
name|vi
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vi
operator|=
name|vec_srl
argument_list|(
name|vi
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vi
operator|=
name|vec_srl
argument_list|(
name|vi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vui
operator|=
name|vec_srl
argument_list|(
name|vui
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vui
operator|=
name|vec_srl
argument_list|(
name|vui
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vui
operator|=
name|vec_srl
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vsc
operator|=
name|vec_vsr
argument_list|(
name|vsc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vsc
operator|=
name|vec_vsr
argument_list|(
name|vsc
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vsc
operator|=
name|vec_vsr
argument_list|(
name|vsc
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vuc
operator|=
name|vec_vsr
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vuc
operator|=
name|vec_vsr
argument_list|(
name|vuc
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vuc
operator|=
name|vec_vsr
argument_list|(
name|vuc
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vs
operator|=
name|vec_vsr
argument_list|(
name|vs
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vs
operator|=
name|vec_vsr
argument_list|(
name|vs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vs
operator|=
name|vec_vsr
argument_list|(
name|vs
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vus
operator|=
name|vec_vsr
argument_list|(
name|vus
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vus
operator|=
name|vec_vsr
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vus
operator|=
name|vec_vsr
argument_list|(
name|vus
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vi
operator|=
name|vec_vsr
argument_list|(
name|vi
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vi
operator|=
name|vec_vsr
argument_list|(
name|vi
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vi
operator|=
name|vec_vsr
argument_list|(
name|vi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vui
operator|=
name|vec_vsr
argument_list|(
name|vui
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vui
operator|=
name|vec_vsr
argument_list|(
name|vui
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
name|res_vui
operator|=
name|vec_vsr
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
comment|/* vec_sro */
name|res_vsc
operator|=
name|vec_sro
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
name|res_vsc
operator|=
name|vec_sro
argument_list|(
name|vsc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
name|res_vuc
operator|=
name|vec_sro
argument_list|(
name|vuc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
name|res_vuc
operator|=
name|vec_sro
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
name|res_vs
operator|=
name|vec_sro
argument_list|(
name|vs
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
name|res_vs
operator|=
name|vec_sro
argument_list|(
name|vs
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
name|res_vus
operator|=
name|vec_sro
argument_list|(
name|vus
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
name|res_vus
operator|=
name|vec_sro
argument_list|(
name|vus
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
name|res_vi
operator|=
name|vec_sro
argument_list|(
name|vi
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
name|res_vi
operator|=
name|vec_sro
argument_list|(
name|vi
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
name|res_vui
operator|=
name|vec_sro
argument_list|(
name|vui
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
name|res_vui
operator|=
name|vec_sro
argument_list|(
name|vui
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
name|res_vf
operator|=
name|vec_sro
argument_list|(
name|vf
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
name|res_vf
operator|=
name|vec_sro
argument_list|(
name|vf
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
name|res_vsc
operator|=
name|vec_vsro
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
name|res_vsc
operator|=
name|vec_vsro
argument_list|(
name|vsc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
name|res_vuc
operator|=
name|vec_vsro
argument_list|(
name|vuc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
name|res_vuc
operator|=
name|vec_vsro
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
name|res_vs
operator|=
name|vec_vsro
argument_list|(
name|vs
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
name|res_vs
operator|=
name|vec_vsro
argument_list|(
name|vs
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
name|res_vus
operator|=
name|vec_vsro
argument_list|(
name|vus
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
name|res_vus
operator|=
name|vec_vsro
argument_list|(
name|vus
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
name|res_vi
operator|=
name|vec_vsro
argument_list|(
name|vi
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
name|res_vi
operator|=
name|vec_vsro
argument_list|(
name|vi
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
name|res_vui
operator|=
name|vec_vsro
argument_list|(
name|vui
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
name|res_vui
operator|=
name|vec_vsro
argument_list|(
name|vui
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
name|res_vf
operator|=
name|vec_vsro
argument_list|(
name|vf
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
name|res_vf
operator|=
name|vec_vsro
argument_list|(
name|vf
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
comment|/* vec_st */
name|vec_st
argument_list|(
name|vsc
argument_list|,
literal|0
argument_list|,
operator|&
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
name|vec_st
argument_list|(
name|vsc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_sc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
name|vec_st
argument_list|(
name|vuc
argument_list|,
literal|0
argument_list|,
operator|&
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
name|vec_st
argument_list|(
name|vuc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
name|vec_st
argument_list|(
name|vs
argument_list|,
literal|0
argument_list|,
operator|&
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
name|vec_st
argument_list|(
name|vs
argument_list|,
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
name|vec_st
argument_list|(
name|vus
argument_list|,
literal|0
argument_list|,
operator|&
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
name|vec_st
argument_list|(
name|vus
argument_list|,
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
name|vec_st
argument_list|(
name|vi
argument_list|,
literal|0
argument_list|,
operator|&
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
name|vec_st
argument_list|(
name|vi
argument_list|,
literal|0
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
name|vec_st
argument_list|(
name|vui
argument_list|,
literal|0
argument_list|,
operator|&
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
name|vec_st
argument_list|(
name|vui
argument_list|,
literal|0
argument_list|,
operator|&
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
name|vec_st
argument_list|(
name|vf
argument_list|,
literal|0
argument_list|,
operator|&
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
name|vec_st
argument_list|(
name|vf
argument_list|,
literal|0
argument_list|,
operator|&
name|param_f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
name|vec_stvx
argument_list|(
name|vsc
argument_list|,
literal|0
argument_list|,
operator|&
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
name|vec_stvx
argument_list|(
name|vsc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_sc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
name|vec_stvx
argument_list|(
name|vuc
argument_list|,
literal|0
argument_list|,
operator|&
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
name|vec_stvx
argument_list|(
name|vuc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
name|vec_stvx
argument_list|(
name|vs
argument_list|,
literal|0
argument_list|,
operator|&
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
name|vec_stvx
argument_list|(
name|vs
argument_list|,
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
name|vec_stvx
argument_list|(
name|vus
argument_list|,
literal|0
argument_list|,
operator|&
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
name|vec_stvx
argument_list|(
name|vus
argument_list|,
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
name|vec_stvx
argument_list|(
name|vi
argument_list|,
literal|0
argument_list|,
operator|&
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
name|vec_stvx
argument_list|(
name|vi
argument_list|,
literal|0
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
name|vec_stvx
argument_list|(
name|vui
argument_list|,
literal|0
argument_list|,
operator|&
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
name|vec_stvx
argument_list|(
name|vui
argument_list|,
literal|0
argument_list|,
operator|&
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
name|vec_stvx
argument_list|(
name|vf
argument_list|,
literal|0
argument_list|,
operator|&
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
name|vec_stvx
argument_list|(
name|vf
argument_list|,
literal|0
argument_list|,
operator|&
name|param_f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|/* vec_ste */
name|vec_ste
argument_list|(
name|vsc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_sc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvebx
name|vec_ste
argument_list|(
name|vuc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvebx
name|vec_ste
argument_list|(
name|vs
argument_list|,
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvehx
name|vec_ste
argument_list|(
name|vus
argument_list|,
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvehx
name|vec_ste
argument_list|(
name|vi
argument_list|,
literal|0
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvewx
name|vec_ste
argument_list|(
name|vui
argument_list|,
literal|0
argument_list|,
operator|&
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvewx
name|vec_ste
argument_list|(
name|vf
argument_list|,
literal|0
argument_list|,
operator|&
name|param_f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvewx
name|vec_stvebx
argument_list|(
name|vsc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_sc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvebx
name|vec_stvebx
argument_list|(
name|vuc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvebx
name|vec_stvehx
argument_list|(
name|vs
argument_list|,
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvehx
name|vec_stvehx
argument_list|(
name|vus
argument_list|,
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvehx
name|vec_stvewx
argument_list|(
name|vi
argument_list|,
literal|0
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvewx
name|vec_stvewx
argument_list|(
name|vui
argument_list|,
literal|0
argument_list|,
operator|&
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvewx
name|vec_stvewx
argument_list|(
name|vf
argument_list|,
literal|0
argument_list|,
operator|&
name|param_f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvewx
comment|/* vec_stl */
name|vec_stl
argument_list|(
name|vsc
argument_list|,
literal|0
argument_list|,
operator|&
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
name|vec_stl
argument_list|(
name|vsc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_sc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
name|vec_stl
argument_list|(
name|vuc
argument_list|,
literal|0
argument_list|,
operator|&
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
name|vec_stl
argument_list|(
name|vuc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
name|vec_stl
argument_list|(
name|vs
argument_list|,
literal|0
argument_list|,
operator|&
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
name|vec_stl
argument_list|(
name|vs
argument_list|,
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
name|vec_stl
argument_list|(
name|vus
argument_list|,
literal|0
argument_list|,
operator|&
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
name|vec_stl
argument_list|(
name|vus
argument_list|,
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
name|vec_stl
argument_list|(
name|vi
argument_list|,
literal|0
argument_list|,
operator|&
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
name|vec_stl
argument_list|(
name|vi
argument_list|,
literal|0
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
name|vec_stl
argument_list|(
name|vui
argument_list|,
literal|0
argument_list|,
operator|&
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
name|vec_stl
argument_list|(
name|vui
argument_list|,
literal|0
argument_list|,
operator|&
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
name|vec_stl
argument_list|(
name|vf
argument_list|,
literal|0
argument_list|,
operator|&
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
name|vec_stl
argument_list|(
name|vf
argument_list|,
literal|0
argument_list|,
operator|&
name|param_f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
name|vec_stvxl
argument_list|(
name|vsc
argument_list|,
literal|0
argument_list|,
operator|&
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
name|vec_stvxl
argument_list|(
name|vsc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_sc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
name|vec_stvxl
argument_list|(
name|vuc
argument_list|,
literal|0
argument_list|,
operator|&
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
name|vec_stvxl
argument_list|(
name|vuc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
name|vec_stvxl
argument_list|(
name|vs
argument_list|,
literal|0
argument_list|,
operator|&
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
name|vec_stvxl
argument_list|(
name|vs
argument_list|,
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
name|vec_stvxl
argument_list|(
name|vus
argument_list|,
literal|0
argument_list|,
operator|&
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
name|vec_stvxl
argument_list|(
name|vus
argument_list|,
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
name|vec_stvxl
argument_list|(
name|vi
argument_list|,
literal|0
argument_list|,
operator|&
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
name|vec_stvxl
argument_list|(
name|vi
argument_list|,
literal|0
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
name|vec_stvxl
argument_list|(
name|vui
argument_list|,
literal|0
argument_list|,
operator|&
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
name|vec_stvxl
argument_list|(
name|vui
argument_list|,
literal|0
argument_list|,
operator|&
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
name|vec_stvxl
argument_list|(
name|vf
argument_list|,
literal|0
argument_list|,
operator|&
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
name|vec_stvxl
argument_list|(
name|vf
argument_list|,
literal|0
argument_list|,
operator|&
name|param_f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|/* vec_sub */
name|res_vsc
operator|=
name|vec_sub
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: sub nsw<16 x i8>
name|res_vuc
operator|=
name|vec_sub
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: sub<16 x i8>
name|res_vs
operator|=
name|vec_sub
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: sub nsw<8 x i16>
name|res_vus
operator|=
name|vec_sub
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: sub<8 x i16>
name|res_vi
operator|=
name|vec_sub
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: sub nsw<4 x i32>
name|res_vui
operator|=
name|vec_sub
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: sub<4 x i32>
name|res_vf
operator|=
name|vec_sub
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: fsub<4 x float>
name|res_vsc
operator|=
name|vec_vsububm
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: sub nsw<16 x i8>
name|res_vuc
operator|=
name|vec_vsububm
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: sub<16 x i8>
name|res_vs
operator|=
name|vec_vsubuhm
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: sub nsw<8 x i16>
name|res_vus
operator|=
name|vec_vsubuhm
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: sub<8 x i16>
name|res_vi
operator|=
name|vec_vsubuwm
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: sub nsw<4 x i32>
name|res_vui
operator|=
name|vec_vsubuwm
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: sub<4 x i32>
name|res_vf
operator|=
name|vec_vsubfp
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: fsub<4 x float>
comment|/* vec_subc */
name|res_vui
operator|=
name|vec_subc
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubcuw
name|res_vui
operator|=
name|vec_vsubcuw
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubcuw
comment|/* vec_subs */
name|res_vsc
operator|=
name|vec_subs
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubsbs
name|res_vuc
operator|=
name|vec_subs
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsububs
name|res_vs
operator|=
name|vec_subs
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubshs
name|res_vus
operator|=
name|vec_subs
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubuhs
name|res_vi
operator|=
name|vec_subs
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubsws
name|res_vui
operator|=
name|vec_subs
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubuws
name|res_vsc
operator|=
name|vec_vsubsbs
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubsbs
name|res_vuc
operator|=
name|vec_vsububs
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsububs
name|res_vs
operator|=
name|vec_vsubshs
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubshs
name|res_vus
operator|=
name|vec_vsubuhs
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubuhs
name|res_vi
operator|=
name|vec_vsubsws
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubsws
name|res_vui
operator|=
name|vec_vsubuws
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubuws
comment|/* vec_sum4s */
name|res_vi
operator|=
name|vec_sum4s
argument_list|(
name|vsc
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsum4sbs
name|res_vui
operator|=
name|vec_sum4s
argument_list|(
name|vuc
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsum4ubs
name|res_vi
operator|=
name|vec_sum4s
argument_list|(
name|vs
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsum4shs
name|res_vi
operator|=
name|vec_vsum4sbs
argument_list|(
name|vsc
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsum4sbs
name|res_vui
operator|=
name|vec_vsum4ubs
argument_list|(
name|vuc
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsum4ubs
name|res_vi
operator|=
name|vec_vsum4shs
argument_list|(
name|vs
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsum4shs
comment|/* vec_sum2s */
name|res_vi
operator|=
name|vec_sum2s
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsum2sws
name|res_vi
operator|=
name|vec_vsum2sws
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsum2sws
comment|/* vec_sums */
name|res_vi
operator|=
name|vec_sums
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsumsws
name|res_vi
operator|=
name|vec_vsumsws
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsumsws
comment|/* vec_trunc */
name|res_vf
operator|=
name|vec_trunc
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrfiz
name|res_vf
operator|=
name|vec_vrfiz
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrfiz
comment|/* vec_unpackh */
name|res_vs
operator|=
name|vec_unpackh
argument_list|(
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vupkhsb
name|res_vi
operator|=
name|vec_unpackh
argument_list|(
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vupkhsh
name|res_vs
operator|=
name|vec_vupkhsb
argument_list|(
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vupkhsb
name|res_vi
operator|=
name|vec_vupkhsh
argument_list|(
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vupkhsh
comment|/* vec_unpackl */
name|res_vs
operator|=
name|vec_unpackl
argument_list|(
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vupklsb
name|res_vi
operator|=
name|vec_vupklsh
argument_list|(
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vupklsh
name|res_vs
operator|=
name|vec_vupklsb
argument_list|(
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vupklsb
name|res_vi
operator|=
name|vec_vupklsh
argument_list|(
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vupklsh
comment|/* vec_xor */
name|res_vsc
operator|=
name|vec_xor
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
name|res_vuc
operator|=
name|vec_xor
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
name|res_vs
operator|=
name|vec_xor
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
name|res_vus
operator|=
name|vec_xor
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
name|res_vi
operator|=
name|vec_xor
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
name|res_vui
operator|=
name|vec_xor
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
name|res_vf
operator|=
name|vec_xor
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
name|res_vsc
operator|=
name|vec_vxor
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
name|res_vuc
operator|=
name|vec_vxor
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
name|res_vs
operator|=
name|vec_vxor
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
name|res_vus
operator|=
name|vec_vxor
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
name|res_vi
operator|=
name|vec_vxor
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
name|res_vui
operator|=
name|vec_vxor
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
name|res_vf
operator|=
name|vec_vxor
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|/* ------------------------------ predicates -------------------------------------- */
comment|/*  vec_all_eq */
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpeqfp.p
comment|/* vec_all_ge */
name|res_i
operator|=
name|vec_all_ge
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsb.p
name|res_i
operator|=
name|vec_all_ge
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_all_ge
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsh.p
name|res_i
operator|=
name|vec_all_ge
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_all_ge
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsw.p
name|res_i
operator|=
name|vec_all_ge
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_all_ge
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgefp.p
comment|/* vec_all_gt */
name|res_i
operator|=
name|vec_all_gt
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsb.p
name|res_i
operator|=
name|vec_all_gt
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_all_gt
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsh.p
name|res_i
operator|=
name|vec_all_gt
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_all_gt
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsw.p
name|res_i
operator|=
name|vec_all_gt
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_all_gt
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtfp.p
comment|/* vec_all_in */
name|res_i
operator|=
name|vec_all_in
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpbfp.p
comment|/* vec_all_le */
name|res_i
operator|=
name|vec_all_le
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsb.p
name|res_i
operator|=
name|vec_all_le
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_all_le
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsh.p
name|res_i
operator|=
name|vec_all_le
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_all_le
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsw.p
name|res_i
operator|=
name|vec_all_le
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_all_le
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgefp.p
comment|/* vec_all_nan */
name|res_i
operator|=
name|vec_all_nan
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpeqfp.p
comment|/*  vec_all_ne */
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpeqfp.p
comment|/* vec_all_nge */
name|res_i
operator|=
name|vec_all_nge
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgefp.p
comment|/* vec_all_ngt */
name|res_i
operator|=
name|vec_all_ngt
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtfp.p
comment|/* vec_all_nle */
name|res_i
operator|=
name|vec_all_nle
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgefp.p
comment|/* vec_all_nlt */
name|res_i
operator|=
name|vec_all_nlt
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtfp.p
comment|/* vec_all_numeric */
name|res_i
operator|=
name|vec_all_numeric
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpeqfp.p
comment|/*  vec_any_eq */
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpeqfp.p
comment|/* vec_any_ge */
name|res_i
operator|=
name|vec_any_ge
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsb.p
name|res_i
operator|=
name|vec_any_ge
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_any_ge
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsh.p
name|res_i
operator|=
name|vec_any_ge
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_any_ge
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsw.p
name|res_i
operator|=
name|vec_any_ge
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_any_ge
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgefp.p
comment|/* vec_any_gt */
name|res_i
operator|=
name|vec_any_gt
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsb.p
name|res_i
operator|=
name|vec_any_gt
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_any_gt
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsh.p
name|res_i
operator|=
name|vec_any_gt
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_any_gt
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsw.p
name|res_i
operator|=
name|vec_any_gt
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_any_gt
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtfp.p
comment|/* vec_any_le */
name|res_i
operator|=
name|vec_any_le
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsb.p
name|res_i
operator|=
name|vec_any_le
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_any_le
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsh.p
name|res_i
operator|=
name|vec_any_le
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_any_le
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsw.p
name|res_i
operator|=
name|vec_any_le
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_any_le
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgefp.p
comment|/* vec_any_lt */
name|res_i
operator|=
name|vec_any_lt
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsb.p
name|res_i
operator|=
name|vec_any_lt
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_any_lt
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsh.p
name|res_i
operator|=
name|vec_any_lt
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_any_lt
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsw.p
name|res_i
operator|=
name|vec_any_lt
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_any_lt
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtfp.p
comment|/* vec_any_nan */
name|res_i
operator|=
name|vec_any_nan
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpeqfp.p
comment|/* vec_any_ne */
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpeqfp.p
comment|/* vec_any_nge */
name|res_i
operator|=
name|vec_any_nge
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgefp.p
comment|/* vec_any_ngt */
name|res_i
operator|=
name|vec_any_ngt
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtfp.p
comment|/* vec_any_nle */
name|res_i
operator|=
name|vec_any_nle
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgefp.p
comment|/* vec_any_nlt */
name|res_i
operator|=
name|vec_any_nlt
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtfp.p
comment|/* vec_any_numeric */
name|res_i
operator|=
name|vec_any_numeric
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpeqfp.p
comment|/* vec_any_out */
name|res_i
operator|=
name|vec_any_out
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpbfp.p
return|return
literal|0
return|;
block|}
end_function

end_unit

