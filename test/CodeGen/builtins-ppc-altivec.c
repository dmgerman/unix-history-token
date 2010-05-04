begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -faltivec -triple powerpc-unknown-unknown -emit-llvm %s -o - | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|"altivec.h"
end_include

begin_function
name|int
name|main
parameter_list|()
block|{
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
name|vector
name|signed
name|char
name|res_vsc
decl_stmt|;
name|vector
name|unsigned
name|char
name|res_vuc
decl_stmt|;
name|vector
name|short
name|res_vs
decl_stmt|;
name|vector
name|unsigned
name|short
name|res_vus
decl_stmt|;
name|vector
name|int
name|res_vi
decl_stmt|;
name|vector
name|unsigned
name|int
name|res_vui
decl_stmt|;
name|vector
name|float
name|res_vf
decl_stmt|;
name|int
name|param_i
decl_stmt|;
name|int
name|res_i
decl_stmt|;
comment|/* vec_abs */
name|vsc
operator|=
name|vec_abs
argument_list|(
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: sub<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vmaxsb
name|vs
operator|=
name|__builtin_vec_abs
argument_list|(
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: sub<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vmaxsh
name|vi
operator|=
name|vec_abs
argument_list|(
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: sub<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vmaxsw
name|vf
operator|=
name|vec_abs
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: store<4 x i32><i32 2147483647, i32 2147483647, i32 2147483647, i32 2147483647>
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
name|__builtin_vec_abss
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
name|__builtin_altivec_vadduhm
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
name|__builtin_vec_vadduwm
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
name|__builtin_vec_vaddfp
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
name|__builtin_vec_vaddshs
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
name|__builtin_vec_vaddsws
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
name|__builtin_altivec_vsubuhm
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
name|__builtin_vec_vsubuwm
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
name|__builtin_vec_vsubfp
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: fsub<4 x float>
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
name|__builtin_vec_vsubshs
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
name|__builtin_vec_vsubsws
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
comment|// CHECK: @llvm.ppc.altivec.vavgsb
name|res_vuc
operator|=
name|__builtin_vec_vavgub
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
name|__builtin_vec_vavguh
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
name|__builtin_vec_vavguw
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vavguw
comment|/* vec_st */
name|param_i
operator|=
literal|5
expr_stmt|;
name|vec_st
argument_list|(
name|vsc
argument_list|,
literal|0
argument_list|,
operator|&
name|res_vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
name|__builtin_vec_st
argument_list|(
name|vuc
argument_list|,
name|param_i
argument_list|,
operator|&
name|res_vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
name|vec_stvx
argument_list|(
name|vs
argument_list|,
literal|1
argument_list|,
operator|&
name|res_vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
name|vec_st
argument_list|(
name|vus
argument_list|,
literal|1000
argument_list|,
operator|&
name|res_vus
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
name|res_vi
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
name|res_vui
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
name|res_vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|/* vec_stl */
name|param_i
operator|=
literal|10000
expr_stmt|;
name|vec_stl
argument_list|(
name|vsc
argument_list|,
name|param_i
argument_list|,
operator|&
name|res_vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
name|__builtin_vec_stl
argument_list|(
name|vuc
argument_list|,
literal|1
argument_list|,
operator|&
name|res_vuc
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
name|res_vs
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
name|res_vus
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
name|res_vi
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
name|res_vui
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
name|res_vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|/* vec_ste */
name|param_i
operator|=
literal|10000
expr_stmt|;
name|vec_ste
argument_list|(
name|vsc
argument_list|,
name|param_i
argument_list|,
operator|&
name|res_vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvebx
name|vec_stvebx
argument_list|(
name|vuc
argument_list|,
literal|1
argument_list|,
operator|&
name|res_vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvebx
name|__builtin_vec_stvehx
argument_list|(
name|vs
argument_list|,
literal|0
argument_list|,
operator|&
name|res_vs
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
name|res_vus
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
name|res_vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvewx
name|__builtin_vec_stvewx
argument_list|(
name|vui
argument_list|,
literal|0
argument_list|,
operator|&
name|res_vui
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
name|res_vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvewx
comment|/* vec_cmpb */
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
name|res_vi
operator|=
name|vec_cmpeq
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb
name|res_vi
operator|=
name|__builtin_vec_cmpeq
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb
name|res_vi
operator|=
name|vec_cmpeq
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh
name|res_vi
operator|=
name|vec_cmpeq
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh
name|res_vi
operator|=
name|vec_cmpeq
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw
name|res_vi
operator|=
name|vec_cmpeq
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw
name|res_vi
operator|=
name|vec_cmpeq
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpeqfp
comment|/* vec_cmpge */
name|res_vi
operator|=
name|__builtin_vec_cmpge
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgefp
comment|/* vec_cmpgt */
name|res_vi
operator|=
name|vec_cmpgt
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsb
name|res_vi
operator|=
name|vec_vcmpgtub
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub
name|res_vi
operator|=
name|__builtin_vec_vcmpgtsh
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsh
name|res_vi
operator|=
name|vec_cmpgt
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh
name|res_vi
operator|=
name|vec_cmpgt
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsw
name|res_vi
operator|=
name|vec_cmpgt
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw
name|res_vi
operator|=
name|vec_cmpgt
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtfp
comment|/* vec_cmple */
name|res_vi
operator|=
name|__builtin_vec_cmple
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgefp
comment|/* vec_cmplt */
name|res_vi
operator|=
name|vec_cmplt
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsb
name|res_vi
operator|=
name|__builtin_vec_cmplt
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub
name|res_vi
operator|=
name|vec_cmplt
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsh
name|res_vi
operator|=
name|vec_cmplt
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh
name|res_vi
operator|=
name|vec_cmplt
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsw
name|res_vi
operator|=
name|vec_cmplt
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw
name|res_vi
operator|=
name|vec_cmplt
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtfp
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
name|__builtin_vec_vmaxub
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
name|__builtin_vec_vmaxsw
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
name|__builtin_vec_max
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxfp
comment|/* vec_mfvscr */
name|vf
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
name|__builtin_vec_vminub
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
name|__builtin_vec_vminsw
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
name|__builtin_vec_min
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminfp
comment|/* vec_mtvscr */
name|vec_mtvscr
argument_list|(
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.mtvscr
comment|/* ------------------------------ predicates -------------------------------------- */
name|res_i
operator|=
name|__builtin_vec_vcmpeq_p
argument_list|(
name|__CR6_EQ
argument_list|,
name|vsc
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpeqfp.p
name|res_i
operator|=
name|__builtin_vec_vcmpge_p
argument_list|(
name|__CR6_EQ
argument_list|,
name|vs
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgefp.p
name|res_i
operator|=
name|__builtin_vec_vcmpgt_p
argument_list|(
name|__CR6_EQ
argument_list|,
name|vuc
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtfp.p
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
comment|// CHECK: @llvm.ppc.altivec.vcmpgtfp.p
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
comment|// CHECK: @llvm.ppc.altivec.vcmpgtfp.p
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
comment|// CHECK: @llvm.ppc.altivec.vcmpgtfp.p
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
comment|// CHECK: @llvm.ppc.altivec.vcmpgtfp.p
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

