begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-feature +altivec -triple powerpc-unknown-unknown -emit-llvm %s \
end_comment

begin_comment
comment|// RUN:            -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-feature +altivec -triple powerpc64-unknown-unknown -emit-llvm %s \
end_comment

begin_comment
comment|// RUN:            -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-feature +altivec -triple powerpc64le-unknown-unknown -emit-llvm %s \
end_comment

begin_comment
comment|// RUN:            -o - | FileCheck %s -check-prefix=CHECK-LE
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -triple powerpc64le-unknown-unknown -emit-llvm %s \
end_comment

begin_comment
comment|// RUN:            -ferror-limit 0 -DNO_ALTIVEC -o - 2>&1 \
end_comment

begin_comment
comment|// RUN:            | FileCheck %s -check-prefix=CHECK-NOALTIVEC
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_ALTIVEC
end_ifndef

begin_include
include|#
directive|include
file|<altivec.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|vector
name|bool
name|char
name|vbc
init|=
block|{
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|vector
name|bool
name|short
name|vbs
init|=
block|{
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|vector
name|pixel
name|vp
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

begin_decl_stmt
name|vector
name|bool
name|int
name|vbi
init|=
block|{
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|vector
name|bool
name|char
name|res_vbc
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|vector
name|bool
name|short
name|res_vbs
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|vector
name|pixel
name|res_vp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|bool
name|int
name|res_vbi
decl_stmt|;
end_decl_stmt

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

begin_comment
comment|// CHECK-NOALTIVEC: error: unknown type name 'vector'
end_comment

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
name|signed
name|long
name|long
name|param_sll
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|res_sc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|res_uc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|res_s
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|res_us
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|res_i
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|res_ui
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|res_f
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define void @test1
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
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
comment|// CHECK-LE: sub<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxsb
name|vs
operator|=
name|vec_abs
argument_list|(
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: sub<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vmaxsh
comment|// CHECK-LE: sub<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxsh
name|vi
operator|=
name|vec_abs
argument_list|(
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: sub<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vmaxsw
comment|// CHECK-LE: sub<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxsw
name|vf
operator|=
name|vec_abs
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: bitcast<4 x float> %{{.*}} to<4 x i32>
comment|// CHECK: and<4 x i32> {{.*}},<i32 2147483647, i32 2147483647, i32 2147483647, i32 2147483647>
comment|// CHECK: bitcast<4 x i32> %{{.*}} to<4 x float>
comment|// CHECK: store<4 x float> %{{.*}},<4 x float>* @vf
comment|// CHECK-LE: bitcast<4 x float> %{{.*}} to<4 x i32>
comment|// CHECK-LE: and<4 x i32> {{.*}},<i32 2147483647, i32 2147483647, i32 2147483647, i32 2147483647>
comment|// CHECK-LE: bitcast<4 x i32> %{{.*}} to<4 x float>
comment|// CHECK-LE: store<4 x float> %{{.*}},<4 x float>* @vf
comment|// CHECK-NOALTIVEC: error: use of undeclared identifier 'vf'
comment|// CHECK-NOALTIVEC: vf = vec_abs(vf)
name|vsc
operator|=
name|vec_nabs
argument_list|(
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: sub<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vminsb
comment|// CHECK-LE: sub<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vminsb
name|vs
operator|=
name|vec_nabs
argument_list|(
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: sub<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vminsh
comment|// CHECK-LE: sub<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vminsh
name|vi
operator|=
name|vec_nabs
argument_list|(
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: sub<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vminsw
comment|// CHECK-LE: sub<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vminsw
name|res_vi
operator|=
name|vec_neg
argument_list|(
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: sub<4 x i32> zeroinitializer, {{%[0-9]+}}
comment|// CHECK-LE: sub<4 x i32> zeroinitializer, {{%[0-9]+}}
comment|// CHECK-NOALTIVEC: error: use of undeclared identifier 'vi'
comment|// CHECK-NOALTIVEC: vi = vec_neg(vi);
name|res_vs
operator|=
name|vec_neg
argument_list|(
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: sub<8 x i16> zeroinitializer, {{%[0-9]+}}
comment|// CHECK-LE: sub<8 x i16> zeroinitializer, {{%[0-9]+}}
comment|// CHECK-NOALTIVEC: error: use of undeclared identifier 'vs'
comment|// CHECK-NOALTIVEC: res_vs = vec_neg(vs);
name|res_vsc
operator|=
name|vec_neg
argument_list|(
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: sub<16 x i8> zeroinitializer, {{%[0-9]+}}
comment|// CHECK-LE: sub<16 x i8> zeroinitializer, {{%[0-9]+}}
comment|// CHECK-NOALTIVEC: error: use of undeclared identifier 'vsc'
comment|// CHECK-NOALTIVEC: res_vsc = vec_neg(vsc);
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsubsbs
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxsb
name|vs
operator|=
name|vec_abss
argument_list|(
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubshs
comment|// CHECK: @llvm.ppc.altivec.vmaxsh
comment|// CHECK-LE: @llvm.ppc.altivec.vsubshs
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxsh
name|vi
operator|=
name|vec_abss
argument_list|(
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubsws
comment|// CHECK: @llvm.ppc.altivec.vmaxsw
comment|// CHECK-LE: @llvm.ppc.altivec.vsubsws
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxsw
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
comment|// CHECK: add<16 x i8>
comment|// CHECK-LE: add<16 x i8>
name|res_vsc
operator|=
name|vec_add
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: add<16 x i8>
comment|// CHECK-LE: add<16 x i8>
name|res_vsc
operator|=
name|vec_add
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: add<16 x i8>
comment|// CHECK-LE: add<16 x i8>
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
comment|// CHECK-LE: add<16 x i8>
name|res_vuc
operator|=
name|vec_add
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: add<16 x i8>
comment|// CHECK-LE: add<16 x i8>
name|res_vuc
operator|=
name|vec_add
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: add<16 x i8>
comment|// CHECK-LE: add<16 x i8>
name|res_vs
operator|=
name|vec_add
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: add<8 x i16>
comment|// CHECK-LE: add<8 x i16>
name|res_vs
operator|=
name|vec_add
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: add<8 x i16>
comment|// CHECK-LE: add<8 x i16>
name|res_vs
operator|=
name|vec_add
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: add<8 x i16>
comment|// CHECK-LE: add<8 x i16>
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
comment|// CHECK-LE: add<8 x i16>
name|res_vus
operator|=
name|vec_add
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: add<8 x i16>
comment|// CHECK-LE: add<8 x i16>
name|res_vus
operator|=
name|vec_add
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: add<8 x i16>
comment|// CHECK-LE: add<8 x i16>
name|res_vi
operator|=
name|vec_add
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: add<4 x i32>
comment|// CHECK-LE: add<4 x i32>
name|res_vi
operator|=
name|vec_add
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: add<4 x i32>
comment|// CHECK-LE: add<4 x i32>
name|res_vi
operator|=
name|vec_add
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: add<4 x i32>
comment|// CHECK-LE: add<4 x i32>
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
comment|// CHECK-LE: add<4 x i32>
name|res_vui
operator|=
name|vec_add
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: add<4 x i32>
comment|// CHECK-LE: add<4 x i32>
name|res_vui
operator|=
name|vec_add
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: add<4 x i32>
comment|// CHECK-LE: add<4 x i32>
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
comment|// CHECK-LE: fadd<4 x float>
name|res_vi
operator|=
name|vec_adde
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: and<4 x i32>
comment|// CHECK: add<4 x i32>
comment|// CHECK: add<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: add<4 x i32>
comment|// CHECK-LE: add<4 x i32>
name|res_vui
operator|=
name|vec_adde
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: and<4 x i32>
comment|// CHECK: add<4 x i32>
comment|// CHECK: add<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: add<4 x i32>
comment|// CHECK-LE: add<4 x i32>
name|res_vsc
operator|=
name|vec_vaddubm
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: add<16 x i8>
comment|// CHECK-LE: add<16 x i8>
name|res_vsc
operator|=
name|vec_vaddubm
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: add<16 x i8>
comment|// CHECK-LE: add<16 x i8>
name|res_vsc
operator|=
name|vec_vaddubm
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: add<16 x i8>
comment|// CHECK-LE: add<16 x i8>
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
comment|// CHECK-LE: add<16 x i8>
name|res_vuc
operator|=
name|vec_vaddubm
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: add<16 x i8>
comment|// CHECK-LE: add<16 x i8>
name|res_vuc
operator|=
name|vec_vaddubm
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: add<16 x i8>
comment|// CHECK-LE: add<16 x i8>
name|res_vs
operator|=
name|vec_vadduhm
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: add<8 x i16>
comment|// CHECK-LE: add<8 x i16>
name|res_vs
operator|=
name|vec_vadduhm
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: add<8 x i16>
comment|// CHECK-LE: add<8 x i16>
name|res_vs
operator|=
name|vec_vadduhm
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: add<8 x i16>
comment|// CHECK-LE: add<8 x i16>
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
comment|// CHECK-LE: add<8 x i16>
name|res_vus
operator|=
name|vec_vadduhm
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: add<8 x i16>
comment|// CHECK-LE: add<8 x i16>
name|res_vus
operator|=
name|vec_vadduhm
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: add<8 x i16>
comment|// CHECK-LE: add<8 x i16>
name|res_vi
operator|=
name|vec_vadduwm
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: add<4 x i32>
comment|// CHECK-LE: add<4 x i32>
name|res_vi
operator|=
name|vec_vadduwm
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: add<4 x i32>
comment|// CHECK-LE: add<4 x i32>
name|res_vi
operator|=
name|vec_vadduwm
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: add<4 x i32>
comment|// CHECK-LE: add<4 x i32>
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
comment|// CHECK-LE: add<4 x i32>
name|res_vui
operator|=
name|vec_vadduwm
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: add<4 x i32>
comment|// CHECK-LE: add<4 x i32>
name|res_vui
operator|=
name|vec_vadduwm
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: add<4 x i32>
comment|// CHECK-LE: add<4 x i32>
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
comment|// CHECK-LE: fadd<4 x float>
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
comment|// CHECK: @llvm.ppc.altivec.vaddcuw
comment|// CHECK-LE: @llvm.ppc.altivec.vaddcuw
name|res_vui
operator|=
name|vec_vaddcuw
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddcuw
comment|// CHECK-LE: @llvm.ppc.altivec.vaddcuw
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
comment|// CHECK-LE: @llvm.ppc.altivec.vaddsbs
name|res_vsc
operator|=
name|vec_adds
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddsbs
comment|// CHECK-LE: @llvm.ppc.altivec.vaddsbs
name|res_vsc
operator|=
name|vec_adds
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddsbs
comment|// CHECK-LE: @llvm.ppc.altivec.vaddsbs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vaddubs
name|res_vuc
operator|=
name|vec_adds
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddubs
comment|// CHECK-LE: @llvm.ppc.altivec.vaddubs
name|res_vuc
operator|=
name|vec_adds
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddubs
comment|// CHECK-LE: @llvm.ppc.altivec.vaddubs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vaddshs
name|res_vs
operator|=
name|vec_adds
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddshs
comment|// CHECK-LE: @llvm.ppc.altivec.vaddshs
name|res_vs
operator|=
name|vec_adds
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddshs
comment|// CHECK-LE: @llvm.ppc.altivec.vaddshs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vadduhs
name|res_vus
operator|=
name|vec_adds
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vadduhs
comment|// CHECK-LE: @llvm.ppc.altivec.vadduhs
name|res_vus
operator|=
name|vec_adds
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vadduhs
comment|// CHECK-LE: @llvm.ppc.altivec.vadduhs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vaddsws
name|res_vi
operator|=
name|vec_adds
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddsws
comment|// CHECK-LE: @llvm.ppc.altivec.vaddsws
name|res_vi
operator|=
name|vec_adds
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddsws
comment|// CHECK-LE: @llvm.ppc.altivec.vaddsws
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
comment|// CHECK-LE: @llvm.ppc.altivec.vadduws
name|res_vui
operator|=
name|vec_adds
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vadduws
comment|// CHECK-LE: @llvm.ppc.altivec.vadduws
name|res_vui
operator|=
name|vec_adds
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vadduws
comment|// CHECK-LE: @llvm.ppc.altivec.vadduws
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
comment|// CHECK-LE: @llvm.ppc.altivec.vaddsbs
name|res_vsc
operator|=
name|vec_vaddsbs
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddsbs
comment|// CHECK-LE: @llvm.ppc.altivec.vaddsbs
name|res_vsc
operator|=
name|vec_vaddsbs
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddsbs
comment|// CHECK-LE: @llvm.ppc.altivec.vaddsbs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vaddubs
name|res_vuc
operator|=
name|vec_vaddubs
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddubs
comment|// CHECK-LE: @llvm.ppc.altivec.vaddubs
name|res_vuc
operator|=
name|vec_vaddubs
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddubs
comment|// CHECK-LE: @llvm.ppc.altivec.vaddubs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vaddshs
name|res_vs
operator|=
name|vec_vaddshs
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddshs
comment|// CHECK-LE: @llvm.ppc.altivec.vaddshs
name|res_vs
operator|=
name|vec_vaddshs
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddshs
comment|// CHECK-LE: @llvm.ppc.altivec.vaddshs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vadduhs
name|res_vus
operator|=
name|vec_vadduhs
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vadduhs
comment|// CHECK-LE: @llvm.ppc.altivec.vadduhs
name|res_vus
operator|=
name|vec_vadduhs
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vadduhs
comment|// CHECK-LE: @llvm.ppc.altivec.vadduhs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vaddsws
name|res_vi
operator|=
name|vec_vaddsws
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddsws
comment|// CHECK-LE: @llvm.ppc.altivec.vaddsws
name|res_vi
operator|=
name|vec_vaddsws
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddsws
comment|// CHECK-LE: @llvm.ppc.altivec.vaddsws
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
comment|// CHECK-LE: @llvm.ppc.altivec.vadduws
name|res_vui
operator|=
name|vec_vadduws
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vadduws
comment|// CHECK-LE: @llvm.ppc.altivec.vadduws
name|res_vui
operator|=
name|vec_vadduws
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vadduws
comment|// CHECK-LE: @llvm.ppc.altivec.vadduws
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
comment|// CHECK-LE: and<16 x i8>
name|res_vsc
operator|=
name|vec_and
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: and<16 x i8>
comment|// CHECK-LE: and<16 x i8>
name|res_vsc
operator|=
name|vec_and
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: and<16 x i8>
comment|// CHECK-LE: and<16 x i8>
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
comment|// CHECK-LE: and<16 x i8>
name|res_vuc
operator|=
name|vec_and
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: and<16 x i8>
comment|// CHECK-LE: and<16 x i8>
name|res_vuc
operator|=
name|vec_and
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: and<16 x i8>
comment|// CHECK-LE: and<16 x i8>
name|res_vbc
operator|=
name|vec_and
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: and<16 x i8>
comment|// CHECK-LE: and<16 x i8>
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
comment|// CHECK-LE: and<8 x i16>
name|res_vs
operator|=
name|vec_and
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: and<8 x i16>
comment|// CHECK-LE: and<8 x i16>
name|res_vs
operator|=
name|vec_and
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: and<8 x i16>
comment|// CHECK-LE: and<8 x i16>
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
comment|// CHECK-LE: and<8 x i16>
name|res_vus
operator|=
name|vec_and
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: and<8 x i16>
comment|// CHECK-LE: and<8 x i16>
name|res_vus
operator|=
name|vec_and
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: and<8 x i16>
comment|// CHECK-LE: and<8 x i16>
name|res_vbs
operator|=
name|vec_and
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: and<8 x i16>
comment|// CHECK-LE: and<8 x i16>
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
comment|// CHECK-LE: and<4 x i32>
name|res_vi
operator|=
name|vec_and
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: and<4 x i32>
comment|// CHECK-le: and<4 x i32>
name|res_vi
operator|=
name|vec_and
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: and<4 x i32>
comment|// CHECK-LE: and<4 x i32>
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
comment|// CHECK-LE: and<4 x i32>
name|res_vui
operator|=
name|vec_and
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: and<4 x i32>
comment|// CHECK-LE: and<4 x i32>
name|res_vui
operator|=
name|vec_and
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: and<4 x i32>
comment|// CHECK-LE: and<4 x i32>
name|res_vbi
operator|=
name|vec_and
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: and<4 x i32>
comment|// CHECK-LE: and<4 x i32>
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
comment|// CHECK-LE: and<16 x i8>
name|res_vsc
operator|=
name|vec_vand
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: and<16 x i8>
comment|// CHECK-LE: and<16 x i8>
name|res_vsc
operator|=
name|vec_vand
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: and<16 x i8>
comment|// CHECK-LE: and<16 x i8>
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
comment|// CHECK-LE: and<16 x i8>
name|res_vuc
operator|=
name|vec_vand
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: and<16 x i8>
comment|// CHECK-LE: and<16 x i8>
name|res_vuc
operator|=
name|vec_vand
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: and<16 x i8>
comment|// CHECK-LE: and<16 x i8>
name|res_vbc
operator|=
name|vec_vand
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: and<16 x i8>
comment|// CHECK-LE: and<16 x i8>
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
comment|// CHECK-LE: and<8 x i16>
name|res_vs
operator|=
name|vec_vand
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: and<8 x i16>
comment|// CHECK-LE: and<8 x i16>
name|res_vs
operator|=
name|vec_vand
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: and<8 x i16>
comment|// CHECK-LE: and<8 x i16>
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
comment|// CHECK-LE: and<8 x i16>
name|res_vus
operator|=
name|vec_vand
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: and<8 x i16>
comment|// CHECK-LE: and<8 x i16>
name|res_vus
operator|=
name|vec_vand
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: and<8 x i16>
comment|// CHECK-LE: and<8 x i16>
name|res_vbs
operator|=
name|vec_vand
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: and<8 x i16>
comment|// CHECK-LE: and<8 x i16>
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
comment|// CHECK-LE: and<4 x i32>
name|res_vi
operator|=
name|vec_vand
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: and<4 x i32>
comment|// CHECK-LE: and<4 x i32>
name|res_vi
operator|=
name|vec_vand
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: and<4 x i32>
comment|// CHECK-LE: and<4 x i32>
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
comment|// CHECK-LE: and<4 x i32>
name|res_vui
operator|=
name|vec_vand
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: and<4 x i32>
comment|// CHECK-LE: and<4 x i32>
name|res_vui
operator|=
name|vec_vand
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: and<4 x i32>
comment|// CHECK-LE: and<4 x i32>
name|res_vbi
operator|=
name|vec_vand
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: and<4 x i32>
comment|// CHECK-LE: and<4 x i32>
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
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: and<16 x i8>
name|res_vsc
operator|=
name|vec_andc
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: and<16 x i8>
name|res_vsc
operator|=
name|vec_andc
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: and<16 x i8>
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
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: and<16 x i8>
name|res_vuc
operator|=
name|vec_andc
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: and<16 x i8>
name|res_vuc
operator|=
name|vec_andc
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: and<16 x i8>
name|res_vbc
operator|=
name|vec_andc
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: and<16 x i8>
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
comment|// CHECK-LE: xor<8 x i16>
comment|// CHECK-LE: and<8 x i16>
name|res_vs
operator|=
name|vec_andc
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
comment|// CHECK-LE: and<8 x i16>
name|res_vs
operator|=
name|vec_andc
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
comment|// CHECK-LE: and<8 x i16>
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
comment|// CHECK-LE: xor<8 x i16>
comment|// CHECK-LE: and<8 x i16>
name|res_vus
operator|=
name|vec_andc
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
comment|// CHECK-LE: and<8 x i16>
name|res_vus
operator|=
name|vec_andc
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
comment|// CHECK-LE: and<8 x i16>
name|res_vbs
operator|=
name|vec_andc
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
comment|// CHECK-LE: and<8 x i16>
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
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
name|res_vi
operator|=
name|vec_andc
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
name|res_vi
operator|=
name|vec_andc
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
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
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
name|res_vui
operator|=
name|vec_andc
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
name|res_vui
operator|=
name|vec_andc
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
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
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
name|res_vf
operator|=
name|vec_andc
argument_list|(
name|vbi
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
name|res_vf
operator|=
name|vec_andc
argument_list|(
name|vf
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
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
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: and<16 x i8>
name|res_vsc
operator|=
name|vec_vandc
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: and<16 x i8>
name|res_vsc
operator|=
name|vec_vandc
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: and<16 x i8>
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
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: and<16 x i8>
name|res_vuc
operator|=
name|vec_vandc
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: and<16 x i8>
name|res_vuc
operator|=
name|vec_vandc
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: and<16 x i8>
name|res_vbc
operator|=
name|vec_vandc
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: and<16 x i8>
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
comment|// CHECK-LE: xor<8 x i16>
comment|// CHECK-LE: and<8 x i16>
name|res_vs
operator|=
name|vec_vandc
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
comment|// CHECK-LE: and<8 x i16>
name|res_vs
operator|=
name|vec_vandc
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
comment|// CHECK-LE: and<8 x i16>
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
comment|// CHECK-LE: xor<8 x i16>
comment|// CHECK-LE: and<8 x i16>
name|res_vus
operator|=
name|vec_vandc
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
comment|// CHECK-LE: and<8 x i16>
name|res_vus
operator|=
name|vec_vandc
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
comment|// CHECK-LE: and<8 x i16>
name|res_vbs
operator|=
name|vec_vandc
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
comment|// CHECK-LE: and<8 x i16>
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
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
name|res_vi
operator|=
name|vec_vandc
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
name|res_vi
operator|=
name|vec_vandc
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
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
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
name|res_vui
operator|=
name|vec_vandc
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
name|res_vui
operator|=
name|vec_vandc
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
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
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
name|res_vf
operator|=
name|vec_vandc
argument_list|(
name|vbi
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
name|res_vf
operator|=
name|vec_vandc
argument_list|(
name|vf
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test2
end_comment

begin_function
name|void
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
comment|// CHECK: @llvm.ppc.altivec.vavgsb
comment|// CHECK-LE: @llvm.ppc.altivec.vavgsb
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
comment|// CHECK-LE: @llvm.ppc.altivec.vavgub
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
comment|// CHECK-LE: @llvm.ppc.altivec.vavgsh
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
comment|// CHECK-LE: @llvm.ppc.altivec.vavguh
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
comment|// CHECK-LE: @llvm.ppc.altivec.vavgsw
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
comment|// CHECK-LE: @llvm.ppc.altivec.vavguw
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
comment|// CHECK-LE: @llvm.ppc.altivec.vavgsb
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
comment|// CHECK-LE: @llvm.ppc.altivec.vavgub
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
comment|// CHECK-LE: @llvm.ppc.altivec.vavgsh
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
comment|// CHECK-LE: @llvm.ppc.altivec.vavguh
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
comment|// CHECK-LE: @llvm.ppc.altivec.vavgsw
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
comment|// CHECK-LE: @llvm.ppc.altivec.vavguw
comment|/* vec_ceil */
name|res_vf
operator|=
name|vec_ceil
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrfip
comment|// CHECK-LE: @llvm.ppc.altivec.vrfip
name|res_vf
operator|=
name|vec_vrfip
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrfip
comment|// CHECK-LE: @llvm.ppc.altivec.vrfip
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpbfp
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpbfp
comment|/* vec_cmpeq */
name|res_vbc
operator|=
name|vec_cmpeq
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb
name|res_vbc
operator|=
name|vec_cmpeq
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb
name|res_vbc
operator|=
name|vec_cmpeq
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb
name|res_vbc
operator|=
name|vec_cmpeq
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb
name|res_vbs
operator|=
name|vec_cmpeq
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh
name|res_vbs
operator|=
name|vec_cmpeq
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh
name|res_vbs
operator|=
name|vec_cmpeq
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh
name|res_vbs
operator|=
name|vec_cmpeq
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh
name|res_vbi
operator|=
name|vec_cmpeq
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw
name|res_vbi
operator|=
name|vec_cmpeq
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw
name|res_vbi
operator|=
name|vec_cmpeq
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw
name|res_vbi
operator|=
name|vec_cmpeq
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw
name|res_vbi
operator|=
name|vec_cmpeq
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpeqfp
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpeqfp
comment|/* vec_cmpge */
name|res_vbc
operator|=
name|vec_cmpge
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsb
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsb
name|res_vbc
operator|=
name|vec_cmpge
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub
name|res_vbs
operator|=
name|vec_cmpge
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsh
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsh
name|res_vbs
operator|=
name|vec_cmpge
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh
name|res_vbi
operator|=
name|vec_cmpge
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsw
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsw
name|res_vbi
operator|=
name|vec_cmpge
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw
name|res_vbi
operator|=
name|vec_cmpge
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgefp
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgefp
name|res_vbi
operator|=
name|vec_vcmpgefp
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgefp
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgefp
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test5
end_comment

begin_function
name|void
name|test5
parameter_list|()
block|{
comment|/* vec_cmpgt */
name|res_vbc
operator|=
name|vec_cmpgt
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsb
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsb
name|res_vbc
operator|=
name|vec_cmpgt
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub
name|res_vbs
operator|=
name|vec_cmpgt
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsh
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsh
name|res_vbs
operator|=
name|vec_cmpgt
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh
name|res_vbi
operator|=
name|vec_cmpgt
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsw
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsw
name|res_vbi
operator|=
name|vec_cmpgt
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw
name|res_vbi
operator|=
name|vec_cmpgt
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtfp
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtfp
name|res_vbc
operator|=
name|vec_vcmpgtsb
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsb
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsb
name|res_vbc
operator|=
name|vec_vcmpgtub
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub
name|res_vbs
operator|=
name|vec_vcmpgtsh
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsh
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsh
name|res_vbs
operator|=
name|vec_vcmpgtuh
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh
name|res_vbi
operator|=
name|vec_vcmpgtsw
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsw
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsw
name|res_vbi
operator|=
name|vec_vcmpgtuw
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw
name|res_vbi
operator|=
name|vec_vcmpgtfp
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtfp
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtfp
comment|/* vec_cmple */
name|res_vbc
operator|=
name|vec_cmple
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsb
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsb
name|res_vbc
operator|=
name|vec_cmple
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub
name|res_vbs
operator|=
name|vec_cmple
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsh
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsh
name|res_vbs
operator|=
name|vec_cmple
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh
name|res_vbi
operator|=
name|vec_cmple
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsw
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsw
name|res_vbi
operator|=
name|vec_cmple
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw
name|res_vbi
operator|=
name|vec_cmple
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgefp
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgefp
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test6
end_comment

begin_function
name|void
name|test6
parameter_list|()
block|{
comment|/* vec_cmplt */
name|res_vbc
operator|=
name|vec_cmplt
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsb
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsb
name|res_vbc
operator|=
name|vec_cmplt
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub
name|res_vbs
operator|=
name|vec_cmplt
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsh
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsh
name|res_vbs
operator|=
name|vec_cmplt
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh
name|res_vbi
operator|=
name|vec_cmplt
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsw
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsw
name|res_vbi
operator|=
name|vec_cmplt
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw
name|res_vbi
operator|=
name|vec_cmplt
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtfp
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtfp
comment|/* vec_ctf */
name|res_vf
operator|=
name|vec_ctf
argument_list|(
name|vi
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcfsx
comment|// CHECK-LE: @llvm.ppc.altivec.vcfsx
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcfux
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcfsx
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcfux
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
comment|// CHECK-LE: @llvm.ppc.altivec.vctsxs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vctsxs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vctuxs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vctuxs
name|res_vi
operator|=
name|vec_signed
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: fptosi<4 x float>
comment|// CHECK-LE: fptosi<4 x float>
name|res_vui
operator|=
name|vec_unsigned
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: fptoui<4 x float>
comment|// CHECK-LE: fptoui<4 x float>
name|res_vf
operator|=
name|vec_float
argument_list|(
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: sitofp<4 x i32>
comment|// CHECK-LE: sitofp<4 x i32>
name|res_vf
operator|=
name|vec_float
argument_list|(
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: uitofp<4 x i32>
comment|// CHECK-LE: uitofp<4 x i32>
comment|/* vec_div */
name|res_vsc
operator|=
name|vec_div
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: sdiv<16 x i8>
comment|// CHECK-LE: sdiv<16 x i8>
name|res_vuc
operator|=
name|vec_div
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: udiv<16 x i8>
comment|// CHECK-LE: udiv<16 x i8>
name|res_vs
operator|=
name|vec_div
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: sdiv<8 x i16>
comment|// CHECK-LE: sdiv<8 x i16>
name|res_vus
operator|=
name|vec_div
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: udiv<8 x i16>
comment|// CHECK-LE: udiv<8 x i16>
name|res_vi
operator|=
name|vec_div
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: sdiv<4 x i32>
comment|// CHECK-LE: sdiv<4 x i32>
name|res_vui
operator|=
name|vec_div
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: udiv<4 x i32>
comment|// CHECK-LE: udiv<4 x i32>
comment|/* vec_dss */
name|vec_dss
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.dss
comment|// CHECK-LE: @llvm.ppc.altivec.dss
comment|/* vec_dssall */
name|vec_dssall
argument_list|()
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.dssall
comment|// CHECK-LE: @llvm.ppc.altivec.dssall
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
comment|// CHECK-LE: @llvm.ppc.altivec.dst
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
comment|// CHECK-LE: @llvm.ppc.altivec.dstst
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
comment|// CHECK-LE: @llvm.ppc.altivec.dststt
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
comment|// CHECK-LE: @llvm.ppc.altivec.dstt
comment|/* vec_expte */
name|res_vf
operator|=
name|vec_expte
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vexptefp
comment|// CHECK-LE: @llvm.ppc.altivec.vexptefp
name|res_vf
operator|=
name|vec_vexptefp
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vexptefp
comment|// CHECK-LE: @llvm.ppc.altivec.vexptefp
comment|/* vec_floor */
name|res_vf
operator|=
name|vec_floor
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrfim
comment|// CHECK-LE: @llvm.ppc.altivec.vrfim
name|res_vf
operator|=
name|vec_vrfim
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrfim
comment|// CHECK-LE: @llvm.ppc.altivec.vrfim
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
name|res_vbc
operator|=
name|vec_ld
argument_list|(
literal|0
argument_list|,
operator|&
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
name|res_vbs
operator|=
name|vec_ld
argument_list|(
literal|0
argument_list|,
operator|&
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
name|res_vp
operator|=
name|vec_ld
argument_list|(
literal|0
argument_list|,
operator|&
name|vp
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
name|res_vbi
operator|=
name|vec_ld
argument_list|(
literal|0
argument_list|,
operator|&
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
name|res_vbc
operator|=
name|vec_lvx
argument_list|(
literal|0
argument_list|,
operator|&
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
name|res_vbs
operator|=
name|vec_lvx
argument_list|(
literal|0
argument_list|,
operator|&
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
name|res_vp
operator|=
name|vec_lvx
argument_list|(
literal|0
argument_list|,
operator|&
name|vp
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
name|res_vbi
operator|=
name|vec_lvx
argument_list|(
literal|0
argument_list|,
operator|&
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|/* vec_lde */
name|res_vsc
operator|=
name|vec_lde
argument_list|(
literal|0
argument_list|,
operator|&
name|param_sc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvebx
comment|// CHECK-LE: @llvm.ppc.altivec.lvebx
name|res_vuc
operator|=
name|vec_lde
argument_list|(
literal|0
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvebx
comment|// CHECK-LE: @llvm.ppc.altivec.lvebx
name|res_vs
operator|=
name|vec_lde
argument_list|(
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvehx
comment|// CHECK-LE: @llvm.ppc.altivec.lvehx
name|res_vus
operator|=
name|vec_lde
argument_list|(
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvehx
comment|// CHECK-LE: @llvm.ppc.altivec.lvehx
name|res_vi
operator|=
name|vec_lde
argument_list|(
literal|0
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvewx
comment|// CHECK-LE: @llvm.ppc.altivec.lvewx
name|res_vui
operator|=
name|vec_lde
argument_list|(
literal|0
argument_list|,
operator|&
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvewx
comment|// CHECK-LE: @llvm.ppc.altivec.lvewx
name|res_vf
operator|=
name|vec_lde
argument_list|(
literal|0
argument_list|,
operator|&
name|param_f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvewx
comment|// CHECK-LE: @llvm.ppc.altivec.lvewx
name|res_vsc
operator|=
name|vec_lvebx
argument_list|(
literal|0
argument_list|,
operator|&
name|param_sc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvebx
comment|// CHECK-LE: @llvm.ppc.altivec.lvebx
name|res_vuc
operator|=
name|vec_lvebx
argument_list|(
literal|0
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvebx
comment|// CHECK-LE: @llvm.ppc.altivec.lvebx
name|res_vs
operator|=
name|vec_lvehx
argument_list|(
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvehx
comment|// CHECK-LE: @llvm.ppc.altivec.lvehx
name|res_vus
operator|=
name|vec_lvehx
argument_list|(
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvehx
comment|// CHECK-LE: @llvm.ppc.altivec.lvehx
name|res_vi
operator|=
name|vec_lvewx
argument_list|(
literal|0
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvewx
comment|// CHECK-LE: @llvm.ppc.altivec.lvewx
name|res_vui
operator|=
name|vec_lvewx
argument_list|(
literal|0
argument_list|,
operator|&
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvewx
comment|// CHECK-LE: @llvm.ppc.altivec.lvewx
name|res_vf
operator|=
name|vec_lvewx
argument_list|(
literal|0
argument_list|,
operator|&
name|param_f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvewx
comment|// CHECK-LE: @llvm.ppc.altivec.lvewx
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
name|res_vbc
operator|=
name|vec_ldl
argument_list|(
literal|0
argument_list|,
operator|&
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
name|res_vbs
operator|=
name|vec_ldl
argument_list|(
literal|0
argument_list|,
operator|&
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
name|res_vp
operator|=
name|vec_ldl
argument_list|(
literal|0
argument_list|,
operator|&
name|vp
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
name|res_vbi
operator|=
name|vec_ldl
argument_list|(
literal|0
argument_list|,
operator|&
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
name|res_vbc
operator|=
name|vec_lvxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
name|res_vbs
operator|=
name|vec_lvxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
name|res_vp
operator|=
name|vec_lvxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vp
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
name|res_vbi
operator|=
name|vec_lvxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|/* vec_loge */
name|res_vf
operator|=
name|vec_loge
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vlogefp
comment|// CHECK-LE: @llvm.ppc.altivec.vlogefp
name|res_vf
operator|=
name|vec_vlogefp
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vlogefp
comment|// CHECK-LE: @llvm.ppc.altivec.vlogefp
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmaddfp
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmaddfp
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmhaddshs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmhaddshs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxsb
name|res_vsc
operator|=
name|vec_max
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxsb
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxsb
name|res_vsc
operator|=
name|vec_max
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxsb
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxsb
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxub
name|res_vuc
operator|=
name|vec_max
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxub
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxub
name|res_vuc
operator|=
name|vec_max
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxub
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxub
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxsh
name|res_vs
operator|=
name|vec_max
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxsh
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxsh
name|res_vs
operator|=
name|vec_max
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxsh
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxsh
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxuh
name|res_vus
operator|=
name|vec_max
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxuh
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxuh
name|res_vus
operator|=
name|vec_max
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxuh
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxuh
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxsw
name|res_vi
operator|=
name|vec_max
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxsw
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxsw
name|res_vi
operator|=
name|vec_max
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxsw
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxsw
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxuw
name|res_vui
operator|=
name|vec_max
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxuw
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxuw
name|res_vui
operator|=
name|vec_max
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxuw
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxuw
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxfp
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxsb
name|res_vsc
operator|=
name|vec_vmaxsb
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxsb
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxsb
name|res_vsc
operator|=
name|vec_vmaxsb
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxsb
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxsb
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxub
name|res_vuc
operator|=
name|vec_vmaxub
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxub
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxub
name|res_vuc
operator|=
name|vec_vmaxub
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxub
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxub
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxsh
name|res_vs
operator|=
name|vec_vmaxsh
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxsh
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxsh
name|res_vs
operator|=
name|vec_vmaxsh
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxsh
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxsh
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxuh
name|res_vus
operator|=
name|vec_vmaxuh
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxuh
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxuh
name|res_vus
operator|=
name|vec_vmaxuh
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxuh
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxuh
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxsw
name|res_vi
operator|=
name|vec_vmaxsw
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxsw
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxsw
name|res_vi
operator|=
name|vec_vmaxsw
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxsw
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxsw
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxuw
name|res_vui
operator|=
name|vec_vmaxuw
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxuw
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxuw
name|res_vui
operator|=
name|vec_vmaxuw
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxuw
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxuw
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxfp
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbc
operator|=
name|vec_mergeh
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vp
operator|=
name|vec_mergeh
argument_list|(
name|vp
argument_list|,
name|vp
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbs
operator|=
name|vec_mergeh
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbi
operator|=
name|vec_mergeh
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbc
operator|=
name|vec_vmrghb
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vp
operator|=
name|vec_vmrghh
argument_list|(
name|vp
argument_list|,
name|vp
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbs
operator|=
name|vec_vmrghh
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbi
operator|=
name|vec_vmrghw
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbc
operator|=
name|vec_mergel
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vp
operator|=
name|vec_mergeh
argument_list|(
name|vp
argument_list|,
name|vp
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbs
operator|=
name|vec_mergel
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbi
operator|=
name|vec_mergel
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbc
operator|=
name|vec_vmrglb
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vp
operator|=
name|vec_vmrglh
argument_list|(
name|vp
argument_list|,
name|vp
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbs
operator|=
name|vec_vmrglh
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbi
operator|=
name|vec_vmrglw
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|/* vec_mfvscr */
name|vus
operator|=
name|vec_mfvscr
argument_list|()
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.mfvscr
comment|// CHECK-LE: @llvm.ppc.altivec.mfvscr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vminsb
name|res_vsc
operator|=
name|vec_min
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminsb
comment|// CHECK-LE: @llvm.ppc.altivec.vminsb
name|res_vsc
operator|=
name|vec_min
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminsb
comment|// CHECK-LE: @llvm.ppc.altivec.vminsb
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
comment|// CHECK-LE: @llvm.ppc.altivec.vminub
name|res_vuc
operator|=
name|vec_min
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminub
comment|// CHECK-LE: @llvm.ppc.altivec.vminub
name|res_vuc
operator|=
name|vec_min
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminub
comment|// CHECK-LE: @llvm.ppc.altivec.vminub
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
comment|// CHECK-LE: @llvm.ppc.altivec.vminsh
name|res_vs
operator|=
name|vec_min
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminsh
comment|// CHECK-LE: @llvm.ppc.altivec.vminsh
name|res_vs
operator|=
name|vec_min
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminsh
comment|// CHECK-LE: @llvm.ppc.altivec.vminsh
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
comment|// CHECK-LE: @llvm.ppc.altivec.vminuh
name|res_vus
operator|=
name|vec_min
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminuh
comment|// CHECK-LE: @llvm.ppc.altivec.vminuh
name|res_vus
operator|=
name|vec_min
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminuh
comment|// CHECK-LE: @llvm.ppc.altivec.vminuh
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
comment|// CHECK-LE: @llvm.ppc.altivec.vminsw
name|res_vi
operator|=
name|vec_min
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminsw
comment|// CHECK-LE: @llvm.ppc.altivec.vminsw
name|res_vi
operator|=
name|vec_min
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminsw
comment|// CHECK-LE: @llvm.ppc.altivec.vminsw
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
comment|// CHECK-LE: @llvm.ppc.altivec.vminuw
name|res_vui
operator|=
name|vec_min
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminuw
comment|// CHECK-LE: @llvm.ppc.altivec.vminuw
name|res_vui
operator|=
name|vec_min
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminuw
comment|// CHECK-LE: @llvm.ppc.altivec.vminuw
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
comment|// CHECK-LE: @llvm.ppc.altivec.vminfp
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
comment|// CHECK-LE: @llvm.ppc.altivec.vminsb
name|res_vsc
operator|=
name|vec_vminsb
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminsb
comment|// CHECK-LE: @llvm.ppc.altivec.vminsb
name|res_vsc
operator|=
name|vec_vminsb
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminsb
comment|// CHECK-LE: @llvm.ppc.altivec.vminsb
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
comment|// CHECK-LE: @llvm.ppc.altivec.vminub
name|res_vuc
operator|=
name|vec_vminub
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminub
comment|// CHECK-LE: @llvm.ppc.altivec.vminub
name|res_vuc
operator|=
name|vec_vminub
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminub
comment|// CHECK-LE: @llvm.ppc.altivec.vminub
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
comment|// CHECK-LE: @llvm.ppc.altivec.vminsh
name|res_vs
operator|=
name|vec_vminsh
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminsh
comment|// CHECK-LE: @llvm.ppc.altivec.vminsh
name|res_vs
operator|=
name|vec_vminsh
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminsh
comment|// CHECK-LE: @llvm.ppc.altivec.vminsh
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
comment|// CHECK-LE: @llvm.ppc.altivec.vminuh
name|res_vus
operator|=
name|vec_vminuh
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminuh
comment|// CHECK-LE: @llvm.ppc.altivec.vminuh
name|res_vus
operator|=
name|vec_vminuh
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminuh
comment|// CHECK-LE: @llvm.ppc.altivec.vminuh
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
comment|// CHECK-LE: @llvm.ppc.altivec.vminsw
name|res_vi
operator|=
name|vec_vminsw
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminsw
comment|// CHECK-LE: @llvm.ppc.altivec.vminsw
name|res_vi
operator|=
name|vec_vminsw
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminsw
comment|// CHECK-LE: @llvm.ppc.altivec.vminsw
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
comment|// CHECK-LE: @llvm.ppc.altivec.vminuw
name|res_vui
operator|=
name|vec_vminuw
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminuw
comment|// CHECK-LE: @llvm.ppc.altivec.vminuw
name|res_vui
operator|=
name|vec_vminuw
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminuw
comment|// CHECK-LE: @llvm.ppc.altivec.vminuw
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
comment|// CHECK-LE: @llvm.ppc.altivec.vminfp
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
comment|// CHECK-LE: mul<8 x i16>
comment|// CHECK-LE: add<8 x i16>
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
comment|// CHECK: mul<8 x i16>
comment|// CHECK: add<8 x i16>
comment|// CHECK-LE: mul<8 x i16>
comment|// CHECK-LE: add<8 x i16>
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
comment|// CHECK: mul<8 x i16>
comment|// CHECK: add<8 x i16>
comment|// CHECK-LE: mul<8 x i16>
comment|// CHECK-LE: add<8 x i16>
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
comment|// CHECK: mul<8 x i16>
comment|// CHECK: add<8 x i16>
comment|// CHECK-LE: mul<8 x i16>
comment|// CHECK-LE: add<8 x i16>
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmhraddshs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmhraddshs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmsummbm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmsumubm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmsumshm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmsumuhm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmsummbm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmsumubm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmsumshm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmsumuhm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmsumshs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmsumuhs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmsumshs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmsumuhs
comment|/* vec_mtvscr */
name|vec_mtvscr
argument_list|(
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.mtvscr
comment|// CHECK-LE: @llvm.ppc.altivec.mtvscr
name|vec_mtvscr
argument_list|(
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.mtvscr
comment|// CHECK-LE: @llvm.ppc.altivec.mtvscr
name|vec_mtvscr
argument_list|(
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.mtvscr
comment|// CHECK-LE: @llvm.ppc.altivec.mtvscr
name|vec_mtvscr
argument_list|(
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.mtvscr
comment|// CHECK-LE: @llvm.ppc.altivec.mtvscr
name|vec_mtvscr
argument_list|(
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.mtvscr
comment|// CHECK-LE: @llvm.ppc.altivec.mtvscr
name|vec_mtvscr
argument_list|(
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.mtvscr
comment|// CHECK-LE: @llvm.ppc.altivec.mtvscr
name|vec_mtvscr
argument_list|(
name|vp
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.mtvscr
comment|// CHECK-LE: @llvm.ppc.altivec.mtvscr
name|vec_mtvscr
argument_list|(
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.mtvscr
comment|// CHECK-LE: @llvm.ppc.altivec.mtvscr
name|vec_mtvscr
argument_list|(
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.mtvscr
comment|// CHECK-LE: @llvm.ppc.altivec.mtvscr
name|vec_mtvscr
argument_list|(
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.mtvscr
comment|// CHECK-LE: @llvm.ppc.altivec.mtvscr
comment|/* vec_mul */
name|res_vsc
operator|=
name|vec_mul
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: mul<16 x i8>
comment|// CHECK-LE: mul<16 x i8>
name|res_vuc
operator|=
name|vec_mul
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: mul<16 x i8>
comment|// CHECK-LE: mul<16 x i8>
name|res_vs
operator|=
name|vec_mul
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: mul<8 x i16>
comment|// CHECK-LE: mul<8 x i16>
name|res_vus
operator|=
name|vec_mul
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: mul<8 x i16>
comment|// CHECK-LE: mul<8 x i16>
name|res_vi
operator|=
name|vec_mul
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: mul<4 x i32>
comment|// CHECK-LE: mul<4 x i32>
name|res_vui
operator|=
name|vec_mul
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: mul<4 x i32>
comment|// CHECK-LE: mul<4 x i32>
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmulosb
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmuloub
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmulosh
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmulouh
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmulosb
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmuloub
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmulosh
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmulouh
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmulesb
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmuleub
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmulesh
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmuleuh
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmulesb
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmuleub
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmulesh
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
comment|// CHECK-LE: @llvm.ppc.altivec.vmuleuh
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
comment|// CHECK-LE: @llvm.ppc.altivec.vnmsubfp
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
comment|// CHECK-LE: @llvm.ppc.altivec.vnmsubfp
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
comment|// CHECK-LE: or<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
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
comment|// CHECK-LE: or<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
name|res_vuc
operator|=
name|vec_nor
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: or<16 x i8>
comment|// CHECK: xor<16 x i8>
comment|// CHECK-LE: or<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
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
comment|// CHECK-LE: or<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
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
comment|// CHECK-LE: or<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
name|res_vus
operator|=
name|vec_nor
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: or<8 x i16>
comment|// CHECK: xor<8 x i16>
comment|// CHECK-LE: or<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
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
comment|// CHECK-LE: or<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
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
comment|// CHECK-LE: or<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
name|res_vui
operator|=
name|vec_nor
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: or<4 x i32>
comment|// CHECK: xor<4 x i32>
comment|// CHECK-LE: or<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
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
comment|// CHECK-LE: or<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
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
comment|// CHECK-LE: or<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
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
comment|// CHECK-LE: or<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
name|res_vuc
operator|=
name|vec_vnor
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: or<16 x i8>
comment|// CHECK: xor<16 x i8>
comment|// CHECK-LE: or<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
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
comment|// CHECK-LE: or<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
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
comment|// CHECK-LE: or<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
name|res_vus
operator|=
name|vec_vnor
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: or<8 x i16>
comment|// CHECK: xor<8 x i16>
comment|// CHECK-LE: or<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
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
comment|// CHECK-LE: or<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
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
comment|// CHECK-LE: or<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
name|res_vui
operator|=
name|vec_vnor
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: or<4 x i32>
comment|// CHECK: xor<4 x i32>
comment|// CHECK-LE: or<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
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
comment|// CHECK-LE: or<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
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
comment|// CHECK-LE: or<16 x i8>
name|res_vsc
operator|=
name|vec_or
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: or<16 x i8>
comment|// CHECK-LE: or<16 x i8>
name|res_vsc
operator|=
name|vec_or
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: or<16 x i8>
comment|// CHECK-LE: or<16 x i8>
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
comment|// CHECK-LE: or<16 x i8>
name|res_vuc
operator|=
name|vec_or
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: or<16 x i8>
comment|// CHECK-LE: or<16 x i8>
name|res_vuc
operator|=
name|vec_or
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: or<16 x i8>
comment|// CHECK-LE: or<16 x i8>
name|res_vbc
operator|=
name|vec_or
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: or<16 x i8>
comment|// CHECK-LE: or<16 x i8>
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
comment|// CHECK-LE: or<8 x i16>
name|res_vs
operator|=
name|vec_or
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: or<8 x i16>
comment|// CHECK-LE: or<8 x i16>
name|res_vs
operator|=
name|vec_or
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: or<8 x i16>
comment|// CHECK-LE: or<8 x i16>
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
comment|// CHECK-LE: or<8 x i16>
name|res_vus
operator|=
name|vec_or
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: or<8 x i16>
comment|// CHECK-LE: or<8 x i16>
name|res_vus
operator|=
name|vec_or
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: or<8 x i16>
comment|// CHECK-LE: or<8 x i16>
name|res_vbs
operator|=
name|vec_or
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: or<8 x i16>
comment|// CHECK-LE: or<8 x i16>
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
comment|// CHECK-LE: or<4 x i32>
name|res_vi
operator|=
name|vec_or
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: or<4 x i32>
comment|// CHECK-LE: or<4 x i32>
name|res_vi
operator|=
name|vec_or
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: or<4 x i32>
comment|// CHECK-LE: or<4 x i32>
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
comment|// CHECK-LE: or<4 x i32>
name|res_vui
operator|=
name|vec_or
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: or<4 x i32>
comment|// CHECK-LE: or<4 x i32>
name|res_vui
operator|=
name|vec_or
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: or<4 x i32>
comment|// CHECK-LE: or<4 x i32>
name|res_vbi
operator|=
name|vec_or
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: or<4 x i32>
comment|// CHECK-LE: or<4 x i32>
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
comment|// CHECK-LE: or<4 x i32>
name|res_vf
operator|=
name|vec_or
argument_list|(
name|vbi
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: or<4 x i32>
comment|// CHECK-LE: or<4 x i32>
name|res_vf
operator|=
name|vec_or
argument_list|(
name|vf
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: or<4 x i32>
comment|// CHECK-LE: or<4 x i32>
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
comment|// CHECK-LE: or<16 x i8>
name|res_vsc
operator|=
name|vec_vor
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: or<16 x i8>
comment|// CHECK-LE: or<16 x i8>
name|res_vsc
operator|=
name|vec_vor
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: or<16 x i8>
comment|// CHECK-LE: or<16 x i8>
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
comment|// CHECK-LE: or<16 x i8>
name|res_vuc
operator|=
name|vec_vor
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: or<16 x i8>
comment|// CHECK-LE: or<16 x i8>
name|res_vuc
operator|=
name|vec_vor
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: or<16 x i8>
comment|// CHECK-LE: or<16 x i8>
name|res_vbc
operator|=
name|vec_vor
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: or<16 x i8>
comment|// CHECK-LE: or<16 x i8>
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
comment|// CHECK-LE: or<8 x i16>
name|res_vs
operator|=
name|vec_vor
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: or<8 x i16>
comment|// CHECK-LE: or<8 x i16>
name|res_vs
operator|=
name|vec_vor
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: or<8 x i16>
comment|// CHECK-LE: or<8 x i16>
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
comment|// CHECK-LE: or<8 x i16>
name|res_vus
operator|=
name|vec_vor
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: or<8 x i16>
comment|// CHECK-LE: or<8 x i16>
name|res_vus
operator|=
name|vec_vor
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: or<8 x i16>
comment|// CHECK-LE: or<8 x i16>
name|res_vbs
operator|=
name|vec_vor
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: or<8 x i16>
comment|// CHECK-LE: or<8 x i16>
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
comment|// CHECK-LE: or<4 x i32>
name|res_vi
operator|=
name|vec_vor
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: or<4 x i32>
comment|// CHECK-LE: or<4 x i32>
name|res_vi
operator|=
name|vec_vor
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: or<4 x i32>
comment|// CHECK-LE: or<4 x i32>
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
comment|// CHECK-LE: or<4 x i32>
name|res_vui
operator|=
name|vec_vor
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: or<4 x i32>
comment|// CHECK-LE: or<4 x i32>
name|res_vui
operator|=
name|vec_vor
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: or<4 x i32>
comment|// CHECK-LE: or<4 x i32>
name|res_vbi
operator|=
name|vec_vor
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: or<4 x i32>
comment|// CHECK-LE: or<4 x i32>
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
comment|// CHECK-LE: or<4 x i32>
name|res_vf
operator|=
name|vec_vor
argument_list|(
name|vbi
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: or<4 x i32>
comment|// CHECK-LE: or<4 x i32>
name|res_vf
operator|=
name|vec_vor
argument_list|(
name|vf
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: or<4 x i32>
comment|// CHECK-LE: or<4 x i32>
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbc
operator|=
name|vec_pack
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbs
operator|=
name|vec_pack
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbc
operator|=
name|vec_vpkuhum
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbs
operator|=
name|vec_vpkuwum
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vpkpx
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
comment|// CHECK-LE: @llvm.ppc.altivec.vpkpx
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
comment|// CHECK-LE: @llvm.ppc.altivec.vpkshss
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
comment|// CHECK-LE: @llvm.ppc.altivec.vpkuhus
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
comment|// CHECK-LE: @llvm.ppc.altivec.vpkswss
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
comment|// CHECK-LE: @llvm.ppc.altivec.vpkuwus
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
comment|// CHECK-LE: @llvm.ppc.altivec.vpkshss
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
comment|// CHECK-LE: @llvm.ppc.altivec.vpkuhus
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
comment|// CHECK-LE: @llvm.ppc.altivec.vpkswss
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
comment|// CHECK-LE: @llvm.ppc.altivec.vpkuwus
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
comment|// CHECK-LE: @llvm.ppc.altivec.vpkshus
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
comment|// CHECK-LE: @llvm.ppc.altivec.vpkuhus
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
comment|// CHECK-LE: @llvm.ppc.altivec.vpkswus
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
comment|// CHECK-LE: @llvm.ppc.altivec.vpkuwus
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
comment|// CHECK-LE: @llvm.ppc.altivec.vpkshus
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
comment|// CHECK-LE: @llvm.ppc.altivec.vpkuhus
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
comment|// CHECK-LE: @llvm.ppc.altivec.vpkswus
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
comment|// CHECK-LE: @llvm.ppc.altivec.vpkuwus
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbc
operator|=
name|vec_perm
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbs
operator|=
name|vec_perm
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vp
operator|=
name|vec_perm
argument_list|(
name|vp
argument_list|,
name|vp
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbi
operator|=
name|vec_perm
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbc
operator|=
name|vec_vperm
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbs
operator|=
name|vec_vperm
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vp
operator|=
name|vec_vperm
argument_list|(
name|vp
argument_list|,
name|vp
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbi
operator|=
name|vec_vperm
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|/* vec_re */
name|res_vf
operator|=
name|vec_re
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrefp
comment|// CHECK-LE: @llvm.ppc.altivec.vrefp
name|res_vf
operator|=
name|vec_vrefp
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrefp
comment|// CHECK-LE: @llvm.ppc.altivec.vrefp
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
comment|// CHECK-LE: @llvm.ppc.altivec.vrlb
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
comment|// CHECK-LE: @llvm.ppc.altivec.vrlb
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
comment|// CHECK-LE: @llvm.ppc.altivec.vrlh
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
comment|// CHECK-LE: @llvm.ppc.altivec.vrlh
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
comment|// CHECK-LE: @llvm.ppc.altivec.vrlw
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
comment|// CHECK-LE: @llvm.ppc.altivec.vrlw
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
comment|// CHECK-LE: @llvm.ppc.altivec.vrlb
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
comment|// CHECK-LE: @llvm.ppc.altivec.vrlb
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
comment|// CHECK-LE: @llvm.ppc.altivec.vrlh
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
comment|// CHECK-LE: @llvm.ppc.altivec.vrlh
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
comment|// CHECK-LE: @llvm.ppc.altivec.vrlw
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
comment|// CHECK-LE: @llvm.ppc.altivec.vrlw
comment|/* vec_round */
name|res_vf
operator|=
name|vec_round
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrfin
comment|// CHECK-LE: @llvm.ppc.altivec.vrfin
name|res_vf
operator|=
name|vec_vrfin
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrfin
comment|// CHECK-LE: @llvm.ppc.altivec.vrfin
comment|/* vec_rsqrte */
name|res_vf
operator|=
name|vec_rsqrte
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrsqrtefp
comment|// CHECK-LE: @llvm.ppc.altivec.vrsqrtefp
name|res_vf
operator|=
name|vec_vrsqrtefp
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrsqrtefp
comment|// CHECK-LE: @llvm.ppc.altivec.vrsqrtefp
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
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: and<16 x i8>
comment|// CHECK-LE: and<16 x i8>
comment|// CHECK-LE: or<16 x i8>
name|res_vsc
operator|=
name|vec_sel
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK: or<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: and<16 x i8>
comment|// CHECK-LE: and<16 x i8>
comment|// CHECK-LE: or<16 x i8>
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
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: and<16 x i8>
comment|// CHECK-LE: and<16 x i8>
comment|// CHECK-LE: or<16 x i8>
name|res_vuc
operator|=
name|vec_sel
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK: or<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: and<16 x i8>
comment|// CHECK-LE: and<16 x i8>
comment|// CHECK-LE: or<16 x i8>
name|res_vbc
operator|=
name|vec_sel
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK: or<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: and<16 x i8>
comment|// CHECK-LE: and<16 x i8>
comment|// CHECK-LE: or<16 x i8>
name|res_vbc
operator|=
name|vec_sel
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK: or<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: and<16 x i8>
comment|// CHECK-LE: and<16 x i8>
comment|// CHECK-LE: or<16 x i8>
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
comment|// CHECK-LE: xor<8 x i16>
comment|// CHECK-LE: and<8 x i16>
comment|// CHECK-LE: and<8 x i16>
comment|// CHECK-LE: or<8 x i16>
name|res_vs
operator|=
name|vec_sel
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK: or<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
comment|// CHECK-LE: and<8 x i16>
comment|// CHECK-LE: and<8 x i16>
comment|// CHECK-LE: or<8 x i16>
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
comment|// CHECK-LE: xor<8 x i16>
comment|// CHECK-LE: and<8 x i16>
comment|// CHECK-LE: and<8 x i16>
comment|// CHECK-LE: or<8 x i16>
name|res_vus
operator|=
name|vec_sel
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK: or<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
comment|// CHECK-LE: and<8 x i16>
comment|// CHECK-LE: and<8 x i16>
comment|// CHECK-LE: or<8 x i16>
name|res_vbs
operator|=
name|vec_sel
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK: or<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
comment|// CHECK-LE: and<8 x i16>
comment|// CHECK-LE: and<8 x i16>
comment|// CHECK-LE: or<8 x i16>
name|res_vbs
operator|=
name|vec_sel
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK: or<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
comment|// CHECK-LE: and<8 x i16>
comment|// CHECK-LE: and<8 x i16>
comment|// CHECK-LE: or<8 x i16>
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
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: or<4 x i32>
name|res_vi
operator|=
name|vec_sel
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: or<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: or<4 x i32>
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
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: or<4 x i32>
name|res_vui
operator|=
name|vec_sel
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: or<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: or<4 x i32>
name|res_vbi
operator|=
name|vec_sel
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: or<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: or<4 x i32>
name|res_vbi
operator|=
name|vec_sel
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: or<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: or<4 x i32>
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
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: or<4 x i32>
name|res_vf
operator|=
name|vec_sel
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: or<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: or<4 x i32>
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
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: and<16 x i8>
comment|// CHECK-LE: and<16 x i8>
comment|// CHECK-LE: or<16 x i8>
name|res_vsc
operator|=
name|vec_vsel
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK: or<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: and<16 x i8>
comment|// CHECK-LE: and<16 x i8>
comment|// CHECK-LE: or<16 x i8>
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
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: and<16 x i8>
comment|// CHECK-LE: and<16 x i8>
comment|// CHECK-LE: or<16 x i8>
name|res_vuc
operator|=
name|vec_vsel
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK: or<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: and<16 x i8>
comment|// CHECK-LE: and<16 x i8>
comment|// CHECK-LE: or<16 x i8>
name|res_vbc
operator|=
name|vec_vsel
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK: or<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: and<16 x i8>
comment|// CHECK-LE: and<16 x i8>
comment|// CHECK-LE: or<16 x i8>
name|res_vbc
operator|=
name|vec_vsel
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK: and<16 x i8>
comment|// CHECK: or<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: and<16 x i8>
comment|// CHECK-LE: and<16 x i8>
comment|// CHECK-LE: or<16 x i8>
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
comment|// CHECK-LE: xor<8 x i16>
comment|// CHECK-LE: and<8 x i16>
comment|// CHECK-LE: and<8 x i16>
comment|// CHECK-LE: or<8 x i16>
name|res_vs
operator|=
name|vec_vsel
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK: or<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
comment|// CHECK-LE: and<8 x i16>
comment|// CHECK-LE: and<8 x i16>
comment|// CHECK-LE: or<8 x i16>
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
comment|// CHECK-LE: xor<8 x i16>
comment|// CHECK-LE: and<8 x i16>
comment|// CHECK-LE: and<8 x i16>
comment|// CHECK-LE: or<8 x i16>
name|res_vus
operator|=
name|vec_vsel
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK: or<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
comment|// CHECK-LE: and<8 x i16>
comment|// CHECK-LE: and<8 x i16>
comment|// CHECK-LE: or<8 x i16>
name|res_vbs
operator|=
name|vec_vsel
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK: or<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
comment|// CHECK-LE: and<8 x i16>
comment|// CHECK-LE: and<8 x i16>
comment|// CHECK-LE: or<8 x i16>
name|res_vbs
operator|=
name|vec_vsel
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK: and<8 x i16>
comment|// CHECK: or<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
comment|// CHECK-LE: and<8 x i16>
comment|// CHECK-LE: and<8 x i16>
comment|// CHECK-LE: or<8 x i16>
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
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: or<4 x i32>
name|res_vi
operator|=
name|vec_vsel
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: or<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: or<4 x i32>
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
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: or<4 x i32>
name|res_vui
operator|=
name|vec_vsel
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: or<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: or<4 x i32>
name|res_vbi
operator|=
name|vec_vsel
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: or<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: or<4 x i32>
name|res_vbi
operator|=
name|vec_vsel
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: or<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: or<4 x i32>
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
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: or<4 x i32>
name|res_vf
operator|=
name|vec_vsel
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: and<4 x i32>
comment|// CHECK: or<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: or<4 x i32>
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
comment|// CHECK: [[UREM:[0-9a-zA-Z%.]+]] = urem<16 x i8> {{[0-9a-zA-Z%.]+}},<i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8>
comment|// CHECK: shl<16 x i8> {{[0-9a-zA-Z%.]+}}, [[UREM]]
comment|// CHECK-LE: [[UREM:[0-9a-zA-Z%.]+]] = urem<16 x i8> {{[0-9a-zA-Z%.]+}},<i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8>
comment|// CHECK-LE: shl<16 x i8> {{[0-9a-zA-Z%.]+}}, [[UREM]]
name|res_vuc
operator|=
name|vec_sl
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: [[UREM:[0-9a-zA-Z%.]+]] = urem<16 x i8> {{[0-9a-zA-Z%.]+}},<i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8>
comment|// CHECK: shl<16 x i8> {{[0-9a-zA-Z%.]+}}, [[UREM]]
comment|// CHECK-LE: [[UREM:[0-9a-zA-Z%.]+]] = urem<16 x i8> {{[0-9a-zA-Z%.]+}},<i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8, i8 8>
comment|// CHECK-LE: shl<16 x i8> {{[0-9a-zA-Z%.]+}}, [[UREM]]
name|res_vs
operator|=
name|vec_sl
argument_list|(
name|vs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: [[UREM:[0-9a-zA-Z%.]+]] = urem<8 x i16> {{[0-9a-zA-Z%.]+}},<i16 16, i16 16, i16 16, i16 16, i16 16, i16 16, i16 16, i16 16>
comment|// CHECK: shl<8 x i16> {{[0-9a-zA-Z%.]+}}, [[UREM]]
comment|// CHECK-LE: [[UREM:[0-9a-zA-Z%.]+]] = urem<8 x i16> {{[0-9a-zA-Z%.]+}},<i16 16, i16 16, i16 16, i16 16, i16 16, i16 16, i16 16, i16 16>
comment|// CHECK-LE: shl<8 x i16> {{[0-9a-zA-Z%.]+}}, [[UREM]]
name|res_vus
operator|=
name|vec_sl
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: [[UREM:[0-9a-zA-Z%.]+]] = urem<8 x i16> {{[0-9a-zA-Z%.]+}},<i16 16, i16 16, i16 16, i16 16, i16 16, i16 16, i16 16, i16 16>
comment|// CHECK: shl<8 x i16> {{[0-9a-zA-Z%.]+}}, [[UREM]]
comment|// CHECK-LE: [[UREM:[0-9a-zA-Z%.]+]] = urem<8 x i16> {{[0-9a-zA-Z%.]+}},<i16 16, i16 16, i16 16, i16 16, i16 16, i16 16, i16 16, i16 16>
comment|// CHECK-LE: shl<8 x i16> {{[0-9a-zA-Z%.]+}}, [[UREM]]
name|res_vi
operator|=
name|vec_sl
argument_list|(
name|vi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: [[UREM:[0-9a-zA-Z%.]+]] = urem<4 x i32> {{[0-9a-zA-Z%.]+}},<i32 32, i32 32, i32 32, i32 32>
comment|// CHECK: shl<4 x i32> {{[0-9a-zA-Z%.]+}}, [[UREM]]
comment|// CHECK-LE: [[UREM:[0-9a-zA-Z%.]+]] = urem<4 x i32> {{[0-9a-zA-Z%.]+}},<i32 32, i32 32, i32 32, i32 32>
comment|// CHECK-LE: shl<4 x i32> {{[0-9a-zA-Z%.]+}}, [[UREM]]
name|res_vui
operator|=
name|vec_sl
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: [[UREM:[0-9a-zA-Z%.]+]] = urem<4 x i32> {{[0-9a-zA-Z%.]+}},<i32 32, i32 32, i32 32, i32 32>
comment|// CHECK: shl<4 x i32> {{[0-9a-zA-Z%.]+}}, [[UREM]]
comment|// CHECK-LE: [[UREM:[0-9a-zA-Z%.]+]] = urem<4 x i32> {{[0-9a-zA-Z%.]+}},<i32 32, i32 32, i32 32, i32 32>
comment|// CHECK-LE: shl<4 x i32> {{[0-9a-zA-Z%.]+}}, [[UREM]]
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
comment|// CHECK-LE: shl<16 x i8>
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
comment|// CHECK-LE: shl<16 x i8>
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
comment|// CHECK-LE: shl<8 x i16>
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
comment|// CHECK-LE: shl<8 x i16>
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
comment|// CHECK-LE: shl<4 x i32>
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
comment|// CHECK-LE: shl<4 x i32>
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
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 1
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 2
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 3
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 15
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: sub nsw i32 16
comment|// CHECK-LE: sub nsw i32 17
comment|// CHECK-LE: sub nsw i32 18
comment|// CHECK-LE: sub nsw i32 31
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 1
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 2
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 3
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 15
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: sub nsw i32 16
comment|// CHECK-LE: sub nsw i32 17
comment|// CHECK-LE: sub nsw i32 18
comment|// CHECK-LE: sub nsw i32 31
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 1
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 2
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 3
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 15
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: sub nsw i32 16
comment|// CHECK-LE: sub nsw i32 17
comment|// CHECK-LE: sub nsw i32 18
comment|// CHECK-LE: sub nsw i32 31
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 1
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 2
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 3
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 15
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: sub nsw i32 16
comment|// CHECK-LE: sub nsw i32 17
comment|// CHECK-LE: sub nsw i32 18
comment|// CHECK-LE: sub nsw i32 31
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbs
operator|=
name|vec_sld
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 1
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 2
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 3
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 15
comment|// CHECK: [[T1:%.+]] = bitcast<8 x i16> {{.+}} to<4 x i32>
comment|// CHECK: [[T2:%.+]] = bitcast<8 x i16> {{.+}} to<4 x i32>
comment|// CHECK: call<4 x i32> @llvm.ppc.altivec.vperm(<4 x i32> [[T1]],<4 x i32> [[T2]],<16 x i8>
comment|// CHECK-LE: sub nsw i32 16
comment|// CHECK-LE: sub nsw i32 17
comment|// CHECK-LE: sub nsw i32 18
comment|// CHECK-LE: sub nsw i32 31
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: [[T1:%.+]] = bitcast<8 x i16> {{.+}} to<4 x i32>
comment|// CHECK-LE: [[T2:%.+]] = bitcast<8 x i16> {{.+}} to<4 x i32>
comment|// CHECK-LE: call<4 x i32> @llvm.ppc.altivec.vperm(<4 x i32> [[T1]],<4 x i32> [[T2]],<16 x i8>
name|res_vp
operator|=
name|vec_sld
argument_list|(
name|vp
argument_list|,
name|vp
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 1
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 2
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 3
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 15
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: sub nsw i32 16
comment|// CHECK-LE: sub nsw i32 17
comment|// CHECK-LE: sub nsw i32 18
comment|// CHECK-LE: sub nsw i32 31
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 1
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 2
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 3
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 15
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: sub nsw i32 16
comment|// CHECK-LE: sub nsw i32 17
comment|// CHECK-LE: sub nsw i32 18
comment|// CHECK-LE: sub nsw i32 31
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 1
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 2
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 3
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 15
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: sub nsw i32 16
comment|// CHECK-LE: sub nsw i32 17
comment|// CHECK-LE: sub nsw i32 18
comment|// CHECK-LE: sub nsw i32 31
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbi
operator|=
name|vec_sld
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 1
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 2
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 3
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 15
comment|// CHECK: call<4 x i32> @llvm.ppc.altivec.vperm(<4 x i32> {{.+}},<4 x i32> {{.+}},<16 x i8>
comment|// CHECK-LE: sub nsw i32 16
comment|// CHECK-LE: sub nsw i32 17
comment|// CHECK-LE: sub nsw i32 18
comment|// CHECK-LE: sub nsw i32 31
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: call<4 x i32> @llvm.ppc.altivec.vperm(<4 x i32> {{.+}},<4 x i32> {{.+}},<16 x i8>
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
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 1
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 2
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 3
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 15
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: sub nsw i32 16
comment|// CHECK-LE: sub nsw i32 17
comment|// CHECK-LE: sub nsw i32 18
comment|// CHECK-LE: sub nsw i32 31
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|/* vec_sldw */
name|res_vsc
operator|=
name|vec_sldw
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 1
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 2
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 3
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 15
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: sub nsw i32 16
comment|// CHECK-LE: sub nsw i32 17
comment|// CHECK-LE: sub nsw i32 18
comment|// CHECK-LE: sub nsw i32 31
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vuc
operator|=
name|vec_sldw
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 1
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 2
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 3
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 15
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: sub nsw i32 16
comment|// CHECK-LE: sub nsw i32 17
comment|// CHECK-LE: sub nsw i32 18
comment|// CHECK-LE: sub nsw i32 31
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vi
operator|=
name|vec_sldw
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 1
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 2
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 3
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 15
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: sub nsw i32 16
comment|// CHECK-LE: sub nsw i32 17
comment|// CHECK-LE: sub nsw i32 18
comment|// CHECK-LE: sub nsw i32 31
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vui
operator|=
name|vec_sldw
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 1
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 2
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 3
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 15
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: sub nsw i32 16
comment|// CHECK-LE: sub nsw i32 17
comment|// CHECK-LE: sub nsw i32 18
comment|// CHECK-LE: sub nsw i32 31
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vs
operator|=
name|vec_sldw
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 1
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 2
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 3
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 15
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: sub nsw i32 16
comment|// CHECK-LE: sub nsw i32 17
comment|// CHECK-LE: sub nsw i32 18
comment|// CHECK-LE: sub nsw i32 31
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vus
operator|=
name|vec_sldw
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 1
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 2
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 3
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 15
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: sub nsw i32 16
comment|// CHECK-LE: sub nsw i32 17
comment|// CHECK-LE: sub nsw i32 18
comment|// CHECK-LE: sub nsw i32 31
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 1
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 2
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 3
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 15
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: sub nsw i32 16
comment|// CHECK-LE: sub nsw i32 17
comment|// CHECK-LE: sub nsw i32 18
comment|// CHECK-LE: sub nsw i32 31
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 1
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 2
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 3
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 15
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: sub nsw i32 16
comment|// CHECK-LE: sub nsw i32 17
comment|// CHECK-LE: sub nsw i32 18
comment|// CHECK-LE: sub nsw i32 31
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 1
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 2
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 3
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 15
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: sub nsw i32 16
comment|// CHECK-LE: sub nsw i32 17
comment|// CHECK-LE: sub nsw i32 18
comment|// CHECK-LE: sub nsw i32 31
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 1
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 2
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 3
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 15
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: sub nsw i32 16
comment|// CHECK-LE: sub nsw i32 17
comment|// CHECK-LE: sub nsw i32 18
comment|// CHECK-LE: sub nsw i32 31
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vp
operator|=
name|vec_vsldoi
argument_list|(
name|vp
argument_list|,
name|vp
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 1
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 2
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 3
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 15
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: sub nsw i32 16
comment|// CHECK-LE: sub nsw i32 17
comment|// CHECK-LE: sub nsw i32 18
comment|// CHECK-LE: sub nsw i32 31
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 1
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 2
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 3
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 15
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: sub nsw i32 16
comment|// CHECK-LE: sub nsw i32 17
comment|// CHECK-LE: sub nsw i32 18
comment|// CHECK-LE: sub nsw i32 31
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 1
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 2
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 3
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 15
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: sub nsw i32 16
comment|// CHECK-LE: sub nsw i32 17
comment|// CHECK-LE: sub nsw i32 18
comment|// CHECK-LE: sub nsw i32 31
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 1
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 2
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 3
comment|// CHECK: add nsw i32 {{[0-9a-zA-Z%.]+}}, 15
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: sub nsw i32 16
comment|// CHECK-LE: sub nsw i32 17
comment|// CHECK-LE: sub nsw i32 18
comment|// CHECK-LE: sub nsw i32 31
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
name|res_vbc
operator|=
name|vec_sll
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
name|res_vbc
operator|=
name|vec_sll
argument_list|(
name|vbc
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
name|res_vbc
operator|=
name|vec_sll
argument_list|(
name|vbc
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
name|res_vbs
operator|=
name|vec_sll
argument_list|(
name|vbs
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
name|res_vbs
operator|=
name|vec_sll
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
name|res_vbs
operator|=
name|vec_sll
argument_list|(
name|vbs
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
name|res_vp
operator|=
name|vec_sll
argument_list|(
name|vp
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
name|res_vp
operator|=
name|vec_sll
argument_list|(
name|vp
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
name|res_vp
operator|=
name|vec_sll
argument_list|(
name|vp
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
name|res_vbi
operator|=
name|vec_sll
argument_list|(
name|vbi
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
name|res_vbi
operator|=
name|vec_sll
argument_list|(
name|vbi
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
name|res_vbi
operator|=
name|vec_sll
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
name|res_vbc
operator|=
name|vec_vsl
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
name|res_vbc
operator|=
name|vec_vsl
argument_list|(
name|vbc
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
name|res_vbc
operator|=
name|vec_vsl
argument_list|(
name|vbc
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
name|res_vbs
operator|=
name|vec_vsl
argument_list|(
name|vbs
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
name|res_vbs
operator|=
name|vec_vsl
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
name|res_vbs
operator|=
name|vec_vsl
argument_list|(
name|vbs
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
name|res_vp
operator|=
name|vec_vsl
argument_list|(
name|vp
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
name|res_vp
operator|=
name|vec_vsl
argument_list|(
name|vp
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
name|res_vp
operator|=
name|vec_vsl
argument_list|(
name|vp
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
name|res_vbi
operator|=
name|vec_vsl
argument_list|(
name|vbi
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
name|res_vbi
operator|=
name|vec_vsl
argument_list|(
name|vbi
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
name|res_vbi
operator|=
name|vec_vsl
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsl
comment|// CHECK-LE: @llvm.ppc.altivec.vsl
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
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
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
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
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
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
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
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
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
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
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
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
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
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
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
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
name|res_vp
operator|=
name|vec_slo
argument_list|(
name|vp
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
name|res_vp
operator|=
name|vec_slo
argument_list|(
name|vp
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
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
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
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
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
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
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
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
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
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
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
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
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
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
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
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
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
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
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
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
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
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
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
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
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
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
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
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
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
name|res_vp
operator|=
name|vec_vslo
argument_list|(
name|vp
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
name|res_vp
operator|=
name|vec_vslo
argument_list|(
name|vp
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vslo
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
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
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
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
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
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
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
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
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
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
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
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
comment|// CHECK-LE: @llvm.ppc.altivec.vslo
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbc
operator|=
name|vec_splat
argument_list|(
name|vbc
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbs
operator|=
name|vec_splat
argument_list|(
name|vbs
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vp
operator|=
name|vec_splat
argument_list|(
name|vp
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbi
operator|=
name|vec_splat
argument_list|(
name|vbi
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbc
operator|=
name|vec_vspltb
argument_list|(
name|vbc
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbs
operator|=
name|vec_vsplth
argument_list|(
name|vbs
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vp
operator|=
name|vec_vsplth
argument_list|(
name|vp
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbi
operator|=
name|vec_vspltw
argument_list|(
name|vbi
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK: lshr<16 x i8>
comment|// CHECK-LE: lshr<16 x i8>
name|res_vuc
operator|=
name|vec_sr
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: lshr<16 x i8>
comment|// CHECK-LE: lshr<16 x i8>
name|res_vs
operator|=
name|vec_sr
argument_list|(
name|vs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: lshr<8 x i16>
comment|// CHECK-LE: lshr<8 x i16>
name|res_vus
operator|=
name|vec_sr
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: lshr<8 x i16>
comment|// CHECK-LE: lshr<8 x i16>
name|res_vi
operator|=
name|vec_sr
argument_list|(
name|vi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: lshr<4 x i32>
comment|// CHECK-LE: lshr<4 x i32>
name|res_vui
operator|=
name|vec_sr
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: lshr<4 x i32>
comment|// CHECK-LE: lshr<4 x i32>
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
comment|// CHECK-LE: shr<16 x i8>
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
comment|// CHECK-LE: shr<16 x i8>
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
comment|// CHECK-LE: shr<8 x i16>
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
comment|// CHECK-LE: shr<8 x i16>
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
comment|// CHECK-LE: shr<4 x i32>
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
comment|// CHECK-LE: shr<4 x i32>
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsrab
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsrab
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsrah
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsrah
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsraw
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsraw
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsrab
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsrab
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsrah
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsrah
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsraw
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsraw
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
name|res_vbc
operator|=
name|vec_srl
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
name|res_vbc
operator|=
name|vec_srl
argument_list|(
name|vbc
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
name|res_vbc
operator|=
name|vec_srl
argument_list|(
name|vbc
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
name|res_vbs
operator|=
name|vec_srl
argument_list|(
name|vbs
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
name|res_vbs
operator|=
name|vec_srl
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
name|res_vbs
operator|=
name|vec_srl
argument_list|(
name|vbs
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
name|res_vp
operator|=
name|vec_srl
argument_list|(
name|vp
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
name|res_vp
operator|=
name|vec_srl
argument_list|(
name|vp
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
name|res_vp
operator|=
name|vec_srl
argument_list|(
name|vp
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
name|res_vbi
operator|=
name|vec_srl
argument_list|(
name|vbi
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
name|res_vbi
operator|=
name|vec_srl
argument_list|(
name|vbi
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
name|res_vbi
operator|=
name|vec_srl
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
name|res_vbc
operator|=
name|vec_vsr
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
name|res_vbc
operator|=
name|vec_vsr
argument_list|(
name|vbc
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
name|res_vbc
operator|=
name|vec_vsr
argument_list|(
name|vbc
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
name|res_vbs
operator|=
name|vec_vsr
argument_list|(
name|vbs
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
name|res_vbs
operator|=
name|vec_vsr
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
name|res_vbs
operator|=
name|vec_vsr
argument_list|(
name|vbs
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
name|res_vp
operator|=
name|vec_vsr
argument_list|(
name|vp
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
name|res_vp
operator|=
name|vec_vsr
argument_list|(
name|vp
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
name|res_vp
operator|=
name|vec_vsr
argument_list|(
name|vp
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
name|res_vbi
operator|=
name|vec_vsr
argument_list|(
name|vbi
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
name|res_vbi
operator|=
name|vec_vsr
argument_list|(
name|vbi
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
name|res_vbi
operator|=
name|vec_vsr
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsr
comment|// CHECK-LE: @llvm.ppc.altivec.vsr
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
name|res_vp
operator|=
name|vec_sro
argument_list|(
name|vp
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
name|res_vp
operator|=
name|vec_sro
argument_list|(
name|vp
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
name|res_vp
operator|=
name|vec_vsro
argument_list|(
name|vp
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
name|res_vp
operator|=
name|vec_vsro
argument_list|(
name|vp
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsro
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsro
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_st
argument_list|(
name|vbc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_st
argument_list|(
name|vbc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_st
argument_list|(
name|vbc
argument_list|,
literal|0
argument_list|,
operator|&
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_st
argument_list|(
name|vbs
argument_list|,
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_st
argument_list|(
name|vbs
argument_list|,
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_st
argument_list|(
name|vbs
argument_list|,
literal|0
argument_list|,
operator|&
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_st
argument_list|(
name|vp
argument_list|,
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_st
argument_list|(
name|vp
argument_list|,
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_st
argument_list|(
name|vp
argument_list|,
literal|0
argument_list|,
operator|&
name|vp
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_st
argument_list|(
name|vbi
argument_list|,
literal|0
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_st
argument_list|(
name|vbi
argument_list|,
literal|0
argument_list|,
operator|&
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_st
argument_list|(
name|vbi
argument_list|,
literal|0
argument_list|,
operator|&
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvx
argument_list|(
name|vbc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvx
argument_list|(
name|vbc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvx
argument_list|(
name|vbc
argument_list|,
literal|0
argument_list|,
operator|&
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvx
argument_list|(
name|vbs
argument_list|,
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvx
argument_list|(
name|vbs
argument_list|,
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvx
argument_list|(
name|vbs
argument_list|,
literal|0
argument_list|,
operator|&
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvx
argument_list|(
name|vp
argument_list|,
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvx
argument_list|(
name|vp
argument_list|,
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvx
argument_list|(
name|vp
argument_list|,
literal|0
argument_list|,
operator|&
name|vp
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvx
argument_list|(
name|vbi
argument_list|,
literal|0
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvx
argument_list|(
name|vbi
argument_list|,
literal|0
argument_list|,
operator|&
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvx
argument_list|(
name|vbi
argument_list|,
literal|0
argument_list|,
operator|&
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvebx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvebx
name|vec_ste
argument_list|(
name|vbc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_sc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvebx
comment|// CHECK-LE: @llvm.ppc.altivec.stvebx
name|vec_ste
argument_list|(
name|vbc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvebx
comment|// CHECK-LE: @llvm.ppc.altivec.stvebx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvehx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvehx
name|vec_ste
argument_list|(
name|vbs
argument_list|,
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvehx
comment|// CHECK-LE: @llvm.ppc.altivec.stvehx
name|vec_ste
argument_list|(
name|vbs
argument_list|,
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvehx
comment|// CHECK-LE: @llvm.ppc.altivec.stvehx
name|vec_ste
argument_list|(
name|vp
argument_list|,
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvehx
comment|// CHECK-LE: @llvm.ppc.altivec.stvehx
name|vec_ste
argument_list|(
name|vp
argument_list|,
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvehx
comment|// CHECK-LE: @llvm.ppc.altivec.stvehx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvewx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvewx
name|vec_ste
argument_list|(
name|vbi
argument_list|,
literal|0
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvewx
comment|// CHECK-LE: @llvm.ppc.altivec.stvewx
name|vec_ste
argument_list|(
name|vbi
argument_list|,
literal|0
argument_list|,
operator|&
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvewx
comment|// CHECK-LE: @llvm.ppc.altivec.stvewx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvewx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvebx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvebx
name|vec_stvebx
argument_list|(
name|vbc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_sc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvebx
comment|// CHECK-LE: @llvm.ppc.altivec.stvebx
name|vec_stvebx
argument_list|(
name|vbc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvebx
comment|// CHECK-LE: @llvm.ppc.altivec.stvebx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvehx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvehx
name|vec_stvehx
argument_list|(
name|vbs
argument_list|,
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvehx
comment|// CHECK-LE: @llvm.ppc.altivec.stvehx
name|vec_stvehx
argument_list|(
name|vbs
argument_list|,
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvehx
comment|// CHECK-LE: @llvm.ppc.altivec.stvehx
name|vec_stvehx
argument_list|(
name|vp
argument_list|,
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvehx
comment|// CHECK-LE: @llvm.ppc.altivec.stvehx
name|vec_stvehx
argument_list|(
name|vp
argument_list|,
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvehx
comment|// CHECK-LE: @llvm.ppc.altivec.stvehx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvewx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvewx
name|vec_stvewx
argument_list|(
name|vbi
argument_list|,
literal|0
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvewx
comment|// CHECK-LE: @llvm.ppc.altivec.stvewx
name|vec_stvewx
argument_list|(
name|vbi
argument_list|,
literal|0
argument_list|,
operator|&
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvewx
comment|// CHECK-LE: @llvm.ppc.altivec.stvewx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvewx
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stl
argument_list|(
name|vbc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_sc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stl
argument_list|(
name|vbc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stl
argument_list|(
name|vbc
argument_list|,
literal|0
argument_list|,
operator|&
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stl
argument_list|(
name|vbs
argument_list|,
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stl
argument_list|(
name|vbs
argument_list|,
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stl
argument_list|(
name|vbs
argument_list|,
literal|0
argument_list|,
operator|&
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stl
argument_list|(
name|vp
argument_list|,
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stl
argument_list|(
name|vp
argument_list|,
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stl
argument_list|(
name|vp
argument_list|,
literal|0
argument_list|,
operator|&
name|vp
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stl
argument_list|(
name|vbi
argument_list|,
literal|0
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stl
argument_list|(
name|vbi
argument_list|,
literal|0
argument_list|,
operator|&
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stl
argument_list|(
name|vbi
argument_list|,
literal|0
argument_list|,
operator|&
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvxl
argument_list|(
name|vbc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_sc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvxl
argument_list|(
name|vbc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvxl
argument_list|(
name|vbc
argument_list|,
literal|0
argument_list|,
operator|&
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvxl
argument_list|(
name|vbs
argument_list|,
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvxl
argument_list|(
name|vbs
argument_list|,
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvxl
argument_list|(
name|vbs
argument_list|,
literal|0
argument_list|,
operator|&
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvxl
argument_list|(
name|vp
argument_list|,
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvxl
argument_list|(
name|vp
argument_list|,
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvxl
argument_list|(
name|vp
argument_list|,
literal|0
argument_list|,
operator|&
name|vp
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvxl
argument_list|(
name|vbi
argument_list|,
literal|0
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvxl
argument_list|(
name|vbi
argument_list|,
literal|0
argument_list|,
operator|&
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvxl
argument_list|(
name|vbi
argument_list|,
literal|0
argument_list|,
operator|&
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
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
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
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
comment|// CHECK: sub<16 x i8>
comment|// CHECK-LE: sub<16 x i8>
name|res_vsc
operator|=
name|vec_sub
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: sub<16 x i8>
comment|// CHECK-LE: sub<16 x i8>
name|res_vsc
operator|=
name|vec_sub
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: sub<16 x i8>
comment|// CHECK-LE: sub<16 x i8>
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
comment|// CHECK-LE: sub<16 x i8>
name|res_vuc
operator|=
name|vec_sub
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: sub<16 x i8>
comment|// CHECK-LE: sub<16 x i8>
name|res_vuc
operator|=
name|vec_sub
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: sub<16 x i8>
comment|// CHECK-LE: sub<16 x i8>
name|res_vs
operator|=
name|vec_sub
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: sub<8 x i16>
comment|// CHECK-LE: sub<8 x i16>
name|res_vs
operator|=
name|vec_sub
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: sub<8 x i16>
comment|// CHECK-LE: sub<8 x i16>
name|res_vs
operator|=
name|vec_sub
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: sub<8 x i16>
comment|// CHECK-LE: sub<8 x i16>
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
comment|// CHECK-LE: sub<8 x i16>
name|res_vus
operator|=
name|vec_sub
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: sub<8 x i16>
comment|// CHECK-LE: sub<8 x i16>
name|res_vus
operator|=
name|vec_sub
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: sub<8 x i16>
comment|// CHECK-LE: sub<8 x i16>
name|res_vi
operator|=
name|vec_sub
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: sub<4 x i32>
comment|// CHECK-LE: sub<4 x i32>
name|res_vi
operator|=
name|vec_sub
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: sub<4 x i32>
comment|// CHECK-LE: sub<4 x i32>
name|res_vi
operator|=
name|vec_sub
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: sub<4 x i32>
comment|// CHECK-LE: sub<4 x i32>
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
comment|// CHECK-LE: sub<4 x i32>
name|res_vui
operator|=
name|vec_sub
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: sub<4 x i32>
comment|// CHECK-LE: sub<4 x i32>
name|res_vui
operator|=
name|vec_sub
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: sub<4 x i32>
comment|// CHECK-LE: sub<4 x i32>
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
comment|// CHECK-LE: fsub<4 x float>
name|res_vsc
operator|=
name|vec_vsububm
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: sub<16 x i8>
comment|// CHECK-LE: sub<16 x i8>
name|res_vsc
operator|=
name|vec_vsububm
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: sub<16 x i8>
comment|// CHECK-LE: sub<16 x i8>
name|res_vsc
operator|=
name|vec_vsububm
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: sub<16 x i8>
comment|// CHECK-LE: sub<16 x i8>
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
comment|// CHECK-LE: sub<16 x i8>
name|res_vuc
operator|=
name|vec_vsububm
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: sub<16 x i8>
comment|// CHECK-LE: sub<16 x i8>
name|res_vuc
operator|=
name|vec_vsububm
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: sub<16 x i8>
comment|// CHECK-LE: sub<16 x i8>
name|res_vs
operator|=
name|vec_vsubuhm
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: sub<8 x i16>
comment|// CHECK-LE: sub<8 x i16>
name|res_vs
operator|=
name|vec_vsubuhm
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: sub<8 x i16>
comment|// CHECK-LE: sub<8 x i16>
name|res_vs
operator|=
name|vec_vsubuhm
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: sub<8 x i16>
comment|// CHECK-LE: sub<8 x i16>
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
comment|// CHECK-LE: sub<8 x i16>
name|res_vus
operator|=
name|vec_vsubuhm
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: sub<8 x i16>
comment|// CHECK-LE: sub<8 x i16>
name|res_vus
operator|=
name|vec_vsubuhm
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: sub<8 x i16>
comment|// CHECK-LE: sub<8 x i16>
name|res_vi
operator|=
name|vec_vsubuwm
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: sub<4 x i32>
comment|// CHECK-LE: sub<4 x i32>
name|res_vi
operator|=
name|vec_vsubuwm
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: sub<4 x i32>
comment|// CHECK-LE: sub<4 x i32>
name|res_vi
operator|=
name|vec_vsubuwm
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: sub<4 x i32>
comment|// CHECK-LE: sub<4 x i32>
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
comment|// CHECK-LE: sub<4 x i32>
name|res_vui
operator|=
name|vec_vsubuwm
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: sub<4 x i32>
comment|// CHECK-LE: sub<4 x i32>
name|res_vui
operator|=
name|vec_vsubuwm
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: sub<4 x i32>
comment|// CHECK-LE: sub<4 x i32>
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
comment|// CHECK-LE: fsub<4 x float>
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsubcuw
name|res_vi
operator|=
name|vec_subc
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubcuw
comment|// CHECK-LE: @llvm.ppc.altivec.vsubcuw
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsubcuw
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsubsbs
name|res_vsc
operator|=
name|vec_subs
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubsbs
comment|// CHECK-LE: @llvm.ppc.altivec.vsubsbs
name|res_vsc
operator|=
name|vec_subs
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubsbs
comment|// CHECK-LE: @llvm.ppc.altivec.vsubsbs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsububs
name|res_vuc
operator|=
name|vec_subs
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsububs
comment|// CHECK-LE: @llvm.ppc.altivec.vsububs
name|res_vuc
operator|=
name|vec_subs
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsububs
comment|// CHECK-LE: @llvm.ppc.altivec.vsububs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsubshs
name|res_vs
operator|=
name|vec_subs
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubshs
comment|// CHECK-LE: @llvm.ppc.altivec.vsubshs
name|res_vs
operator|=
name|vec_subs
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubshs
comment|// CHECK-LE: @llvm.ppc.altivec.vsubshs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsubuhs
name|res_vus
operator|=
name|vec_subs
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubuhs
comment|// CHECK-LE: @llvm.ppc.altivec.vsubuhs
name|res_vus
operator|=
name|vec_subs
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubuhs
comment|// CHECK-LE: @llvm.ppc.altivec.vsubuhs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsubsws
name|res_vi
operator|=
name|vec_subs
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubsws
comment|// CHECK-LE: @llvm.ppc.altivec.vsubsws
name|res_vi
operator|=
name|vec_subs
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubsws
comment|// CHECK-LE: @llvm.ppc.altivec.vsubsws
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsubuws
name|res_vui
operator|=
name|vec_subs
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubuws
comment|// CHECK-LE: @llvm.ppc.altivec.vsubuws
name|res_vui
operator|=
name|vec_subs
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubuws
comment|// CHECK-LE: @llvm.ppc.altivec.vsubuws
name|res_vi
operator|=
name|vec_sube
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: and<4 x i32>
comment|// CHECK: xor<4 x i32> {{%[0-9]+}},<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK: add<4 x i32>
comment|// CHECK: add<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: xor<4 x i32> {{%[0-9]+}},<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK-LE: add<4 x i32>
comment|// CHECK-LE: add<4 x i32>
name|res_vui
operator|=
name|vec_sube
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: and<4 x i32>
comment|// CHECK: xor<4 x i32> {{%[0-9]+}},<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK: add<4 x i32>
comment|// CHECK: add<4 x i32>
comment|// CHECK-LE: and<4 x i32>
comment|// CHECK-LE: xor<4 x i32> {{%[0-9]+}},<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK-LE: add<4 x i32>
comment|// CHECK-LE: add<4 x i32>
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsubsbs
name|res_vsc
operator|=
name|vec_vsubsbs
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubsbs
comment|// CHECK-LE: @llvm.ppc.altivec.vsubsbs
name|res_vsc
operator|=
name|vec_vsubsbs
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubsbs
comment|// CHECK-LE: @llvm.ppc.altivec.vsubsbs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsububs
name|res_vuc
operator|=
name|vec_vsububs
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsububs
comment|// CHECK-LE: @llvm.ppc.altivec.vsububs
name|res_vuc
operator|=
name|vec_vsububs
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsububs
comment|// CHECK-LE: @llvm.ppc.altivec.vsububs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsubshs
name|res_vs
operator|=
name|vec_vsubshs
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubshs
comment|// CHECK-LE: @llvm.ppc.altivec.vsubshs
name|res_vs
operator|=
name|vec_vsubshs
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubshs
comment|// CHECK-LE: @llvm.ppc.altivec.vsubshs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsubuhs
name|res_vus
operator|=
name|vec_vsubuhs
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubuhs
comment|// CHECK-LE: @llvm.ppc.altivec.vsubuhs
name|res_vus
operator|=
name|vec_vsubuhs
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubuhs
comment|// CHECK-LE: @llvm.ppc.altivec.vsubuhs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsubsws
name|res_vi
operator|=
name|vec_vsubsws
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubsws
comment|// CHECK-LE: @llvm.ppc.altivec.vsubsws
name|res_vi
operator|=
name|vec_vsubsws
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubsws
comment|// CHECK-LE: @llvm.ppc.altivec.vsubsws
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsubuws
name|res_vui
operator|=
name|vec_vsubuws
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubuws
comment|// CHECK-LE: @llvm.ppc.altivec.vsubuws
name|res_vui
operator|=
name|vec_vsubuws
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubuws
comment|// CHECK-LE: @llvm.ppc.altivec.vsubuws
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsum4sbs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsum4ubs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsum4shs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsum4sbs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsum4ubs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vsum4shs
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vsum2sws
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vsum2sws
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vsumsws
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
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vsumsws
comment|/* vec_trunc */
name|res_vf
operator|=
name|vec_trunc
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrfiz
comment|// CHECK-LE: @llvm.ppc.altivec.vrfiz
name|res_vf
operator|=
name|vec_vrfiz
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrfiz
comment|// CHECK-LE: @llvm.ppc.altivec.vrfiz
comment|/* vec_unpackh */
name|res_vs
operator|=
name|vec_unpackh
argument_list|(
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vupkhsb
comment|// CHECK-LE: @llvm.ppc.altivec.vupklsb
name|res_vbs
operator|=
name|vec_unpackh
argument_list|(
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vupkhsb
comment|// CHECK-LE: @llvm.ppc.altivec.vupklsb
name|res_vi
operator|=
name|vec_unpackh
argument_list|(
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vupkhsh
comment|// CHECK-LE: @llvm.ppc.altivec.vupklsh
name|res_vbi
operator|=
name|vec_unpackh
argument_list|(
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vupkhsh
comment|// CHECK-LE: @llvm.ppc.altivec.vupklsh
name|res_vui
operator|=
name|vec_unpackh
argument_list|(
name|vp
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vupkhpx
comment|// CHECK-LE: @llvm.ppc.altivec.vupklpx
name|res_vs
operator|=
name|vec_vupkhsb
argument_list|(
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vupkhsb
comment|// CHECK-LE: @llvm.ppc.altivec.vupklsb
name|res_vbs
operator|=
name|vec_vupkhsb
argument_list|(
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vupkhsb
comment|// CHECK-LE: @llvm.ppc.altivec.vupklsb
name|res_vi
operator|=
name|vec_vupkhsh
argument_list|(
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vupkhsh
comment|// CHECK-LE: @llvm.ppc.altivec.vupklsh
name|res_vbi
operator|=
name|vec_vupkhsh
argument_list|(
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vupkhsh
comment|// CHECK-LE: @llvm.ppc.altivec.vupklsh
name|res_vui
operator|=
name|vec_vupkhsh
argument_list|(
name|vp
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vupkhpx
comment|// CHECK-LE: @llvm.ppc.altivec.vupklpx
comment|/* vec_unpackl */
name|res_vs
operator|=
name|vec_unpackl
argument_list|(
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vupklsb
comment|// CHECK-LE: @llvm.ppc.altivec.vupkhsb
name|res_vbs
operator|=
name|vec_unpackl
argument_list|(
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vupklsb
comment|// CHECK-LE: @llvm.ppc.altivec.vupkhsb
name|res_vi
operator|=
name|vec_unpackl
argument_list|(
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vupklsh
comment|// CHECK-LE: @llvm.ppc.altivec.vupkhsh
name|res_vbi
operator|=
name|vec_unpackl
argument_list|(
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vupklsh
comment|// CHECK-LE: @llvm.ppc.altivec.vupkhsh
name|res_vui
operator|=
name|vec_unpackl
argument_list|(
name|vp
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vupklpx
comment|// CHECK-LE: @llvm.ppc.altivec.vupkhpx
name|res_vs
operator|=
name|vec_vupklsb
argument_list|(
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vupklsb
comment|// CHECK-LE: @llvm.ppc.altivec.vupkhsb
name|res_vbs
operator|=
name|vec_vupklsb
argument_list|(
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vupklsb
comment|// CHECK-LE: @llvm.ppc.altivec.vupkhsb
name|res_vi
operator|=
name|vec_vupklsh
argument_list|(
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vupklsh
comment|// CHECK-LE: @llvm.ppc.altivec.vupkhsh
name|res_vbi
operator|=
name|vec_vupklsh
argument_list|(
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vupklsh
comment|// CHECK-LE: @llvm.ppc.altivec.vupkhsh
name|res_vui
operator|=
name|vec_vupklsh
argument_list|(
name|vp
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vupklpx
comment|// CHECK-LE: @llvm.ppc.altivec.vupkhpx
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
comment|// CHECK-LE: xor<16 x i8>
name|res_vsc
operator|=
name|vec_xor
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
name|res_vsc
operator|=
name|vec_xor
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
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
comment|// CHECK-LE: xor<16 x i8>
name|res_vuc
operator|=
name|vec_xor
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
name|res_vuc
operator|=
name|vec_xor
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
name|res_vbc
operator|=
name|vec_xor
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
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
comment|// CHECK-LE: xor<8 x i16>
name|res_vs
operator|=
name|vec_xor
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
name|res_vs
operator|=
name|vec_xor
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
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
comment|// CHECK-LE: xor<8 x i16>
name|res_vus
operator|=
name|vec_xor
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
name|res_vus
operator|=
name|vec_xor
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
name|res_vbs
operator|=
name|vec_xor
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
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
comment|// CHECK-LE: xor<4 x i32>
name|res_vi
operator|=
name|vec_xor
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
name|res_vi
operator|=
name|vec_xor
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
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
comment|// CHECK-LE: xor<4 x i32>
name|res_vui
operator|=
name|vec_xor
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
name|res_vui
operator|=
name|vec_xor
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
name|res_vbi
operator|=
name|vec_xor
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
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
comment|// CHECK-LE: xor<4 x i32>
name|res_vf
operator|=
name|vec_xor
argument_list|(
name|vbi
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
name|res_vf
operator|=
name|vec_xor
argument_list|(
name|vf
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
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
comment|// CHECK-LE: xor<16 x i8>
name|res_vsc
operator|=
name|vec_vxor
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
name|res_vsc
operator|=
name|vec_vxor
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
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
comment|// CHECK-LE: xor<16 x i8>
name|res_vuc
operator|=
name|vec_vxor
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
name|res_vuc
operator|=
name|vec_vxor
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
name|res_vbc
operator|=
name|vec_vxor
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: xor<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
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
comment|// CHECK-LE: xor<8 x i16>
name|res_vs
operator|=
name|vec_vxor
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
name|res_vs
operator|=
name|vec_vxor
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
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
comment|// CHECK-LE: xor<8 x i16>
name|res_vus
operator|=
name|vec_vxor
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
name|res_vus
operator|=
name|vec_vxor
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
name|res_vbs
operator|=
name|vec_vxor
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: xor<8 x i16>
comment|// CHECK-LE: xor<8 x i16>
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
comment|// CHECK-LE: xor<4 x i32>
name|res_vi
operator|=
name|vec_vxor
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
name|res_vi
operator|=
name|vec_vxor
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
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
comment|// CHECK-LE: xor<4 x i32>
name|res_vui
operator|=
name|vec_vxor
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
name|res_vui
operator|=
name|vec_vxor
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
name|res_vbi
operator|=
name|vec_vxor
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
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
comment|// CHECK-LE: xor<4 x i32>
name|res_vf
operator|=
name|vec_vxor
argument_list|(
name|vbi
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
name|res_vf
operator|=
name|vec_vxor
argument_list|(
name|vf
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: xor<4 x i32>
comment|// CHECK-LE: xor<4 x i32>
comment|/* ------------------------------ extensions -------------------------------------- */
comment|/* vec_extract */
name|res_sc
operator|=
name|vec_extract
argument_list|(
name|vsc
argument_list|,
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: extractelement<16 x i8>
comment|// CHECK-LE: extractelement<16 x i8>
name|res_uc
operator|=
name|vec_extract
argument_list|(
name|vuc
argument_list|,
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: extractelement<16 x i8>
comment|// CHECK-LE: extractelement<16 x i8>
name|res_uc
operator|=
name|vec_extract
argument_list|(
name|vbc
argument_list|,
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: extractelement<16 x i8>
comment|// CHECK-LE: extractelement<16 x i8>
name|res_s
operator|=
name|vec_extract
argument_list|(
name|vs
argument_list|,
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: extractelement<8 x i16>
comment|// CHECK-LE: extractelement<8 x i16>
name|res_us
operator|=
name|vec_extract
argument_list|(
name|vus
argument_list|,
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: extractelement<8 x i16>
comment|// CHECK-LE: extractelement<8 x i16>
name|res_us
operator|=
name|vec_extract
argument_list|(
name|vbs
argument_list|,
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: extractelement<8 x i16>
comment|// CHECK-LE: extractelement<8 x i16>
name|res_i
operator|=
name|vec_extract
argument_list|(
name|vi
argument_list|,
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: extractelement<4 x i32>
comment|// CHECK-LE: extractelement<4 x i32>
name|res_ui
operator|=
name|vec_extract
argument_list|(
name|vui
argument_list|,
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: extractelement<4 x i32>
comment|// CHECK-LE: extractelement<4 x i32>
name|res_ui
operator|=
name|vec_extract
argument_list|(
name|vbi
argument_list|,
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: extractelement<4 x i32>
comment|// CHECK-LE: extractelement<4 x i32>
name|res_f
operator|=
name|vec_extract
argument_list|(
name|vf
argument_list|,
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: extractelement<4 x float>
comment|// CHECK-LE: extractelement<4 x float>
comment|/* vec_insert */
name|res_vsc
operator|=
name|vec_insert
argument_list|(
name|param_sc
argument_list|,
name|vsc
argument_list|,
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: insertelement<16 x i8>
comment|// CHECK-LE: insertelement<16 x i8>
name|res_vuc
operator|=
name|vec_insert
argument_list|(
name|param_uc
argument_list|,
name|vuc
argument_list|,
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: insertelement<16 x i8>
comment|// CHECK-LE: insertelement<16 x i8>
name|res_vbc
operator|=
name|vec_insert
argument_list|(
name|param_uc
argument_list|,
name|vbc
argument_list|,
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: insertelement<16 x i8>
comment|// CHECK-LE: insertelement<16 x i8>
name|res_vs
operator|=
name|vec_insert
argument_list|(
name|param_s
argument_list|,
name|vs
argument_list|,
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: insertelement<8 x i16>
comment|// CHECK-LE: insertelement<8 x i16>
name|res_vus
operator|=
name|vec_insert
argument_list|(
name|param_us
argument_list|,
name|vus
argument_list|,
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: insertelement<8 x i16>
comment|// CHECK-LE: insertelement<8 x i16>
name|res_vbs
operator|=
name|vec_insert
argument_list|(
name|param_us
argument_list|,
name|vbs
argument_list|,
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: insertelement<8 x i16>
comment|// CHECK-LE: insertelement<8 x i16>
name|res_vi
operator|=
name|vec_insert
argument_list|(
name|param_i
argument_list|,
name|vi
argument_list|,
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: insertelement<4 x i32>
comment|// CHECK-LE: insertelement<4 x i32>
name|res_vui
operator|=
name|vec_insert
argument_list|(
name|param_ui
argument_list|,
name|vui
argument_list|,
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: insertelement<4 x i32>
comment|// CHECK-LE: insertelement<4 x i32>
name|res_vbi
operator|=
name|vec_insert
argument_list|(
name|param_ui
argument_list|,
name|vbi
argument_list|,
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: insertelement<4 x i32>
comment|// CHECK-LE: insertelement<4 x i32>
name|res_vf
operator|=
name|vec_insert
argument_list|(
name|param_f
argument_list|,
name|vf
argument_list|,
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: insertelement<4 x float>
comment|// CHECK-LE: insertelement<4 x float>
comment|/* vec_lvlx */
name|res_vsc
operator|=
name|vec_lvlx
argument_list|(
literal|0
argument_list|,
operator|&
name|param_sc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vsc
operator|=
name|vec_lvlx
argument_list|(
literal|0
argument_list|,
operator|&
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vuc
operator|=
name|vec_lvlx
argument_list|(
literal|0
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vuc
operator|=
name|vec_lvlx
argument_list|(
literal|0
argument_list|,
operator|&
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbc
operator|=
name|vec_lvlx
argument_list|(
literal|0
argument_list|,
operator|&
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vs
operator|=
name|vec_lvlx
argument_list|(
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vs
operator|=
name|vec_lvlx
argument_list|(
literal|0
argument_list|,
operator|&
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vus
operator|=
name|vec_lvlx
argument_list|(
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vus
operator|=
name|vec_lvlx
argument_list|(
literal|0
argument_list|,
operator|&
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbs
operator|=
name|vec_lvlx
argument_list|(
literal|0
argument_list|,
operator|&
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vp
operator|=
name|vec_lvlx
argument_list|(
literal|0
argument_list|,
operator|&
name|vp
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vi
operator|=
name|vec_lvlx
argument_list|(
literal|0
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vi
operator|=
name|vec_lvlx
argument_list|(
literal|0
argument_list|,
operator|&
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vui
operator|=
name|vec_lvlx
argument_list|(
literal|0
argument_list|,
operator|&
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vui
operator|=
name|vec_lvlx
argument_list|(
literal|0
argument_list|,
operator|&
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbi
operator|=
name|vec_lvlx
argument_list|(
literal|0
argument_list|,
operator|&
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vf
operator|=
name|vec_lvlx
argument_list|(
literal|0
argument_list|,
operator|&
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x float> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x float> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|/* vec_lvlxl */
name|res_vsc
operator|=
name|vec_lvlxl
argument_list|(
literal|0
argument_list|,
operator|&
name|param_sc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vsc
operator|=
name|vec_lvlxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vuc
operator|=
name|vec_lvlxl
argument_list|(
literal|0
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vuc
operator|=
name|vec_lvlxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbc
operator|=
name|vec_lvlxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vs
operator|=
name|vec_lvlxl
argument_list|(
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vs
operator|=
name|vec_lvlxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vus
operator|=
name|vec_lvlxl
argument_list|(
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vus
operator|=
name|vec_lvlxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbs
operator|=
name|vec_lvlxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vp
operator|=
name|vec_lvlxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vp
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vi
operator|=
name|vec_lvlxl
argument_list|(
literal|0
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vi
operator|=
name|vec_lvlxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vui
operator|=
name|vec_lvlxl
argument_list|(
literal|0
argument_list|,
operator|&
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vui
operator|=
name|vec_lvlxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbi
operator|=
name|vec_lvlxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vf
operator|=
name|vec_lvlxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x float> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x float> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|/* vec_lvrx */
name|res_vsc
operator|=
name|vec_lvrx
argument_list|(
literal|0
argument_list|,
operator|&
name|param_sc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vsc
operator|=
name|vec_lvrx
argument_list|(
literal|0
argument_list|,
operator|&
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vuc
operator|=
name|vec_lvrx
argument_list|(
literal|0
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vuc
operator|=
name|vec_lvrx
argument_list|(
literal|0
argument_list|,
operator|&
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbc
operator|=
name|vec_lvrx
argument_list|(
literal|0
argument_list|,
operator|&
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vs
operator|=
name|vec_lvrx
argument_list|(
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vs
operator|=
name|vec_lvrx
argument_list|(
literal|0
argument_list|,
operator|&
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vus
operator|=
name|vec_lvrx
argument_list|(
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vus
operator|=
name|vec_lvrx
argument_list|(
literal|0
argument_list|,
operator|&
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbs
operator|=
name|vec_lvrx
argument_list|(
literal|0
argument_list|,
operator|&
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vp
operator|=
name|vec_lvrx
argument_list|(
literal|0
argument_list|,
operator|&
name|vp
argument_list|)
expr_stmt|;
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vi
operator|=
name|vec_lvrx
argument_list|(
literal|0
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vi
operator|=
name|vec_lvrx
argument_list|(
literal|0
argument_list|,
operator|&
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vui
operator|=
name|vec_lvrx
argument_list|(
literal|0
argument_list|,
operator|&
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vui
operator|=
name|vec_lvrx
argument_list|(
literal|0
argument_list|,
operator|&
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbi
operator|=
name|vec_lvrx
argument_list|(
literal|0
argument_list|,
operator|&
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vf
operator|=
name|vec_lvrx
argument_list|(
literal|0
argument_list|,
operator|&
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x float> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x float> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|/* vec_lvrxl */
name|res_vsc
operator|=
name|vec_lvrxl
argument_list|(
literal|0
argument_list|,
operator|&
name|param_sc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vsc
operator|=
name|vec_lvrxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vuc
operator|=
name|vec_lvrxl
argument_list|(
literal|0
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vuc
operator|=
name|vec_lvrxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbc
operator|=
name|vec_lvrxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vs
operator|=
name|vec_lvrxl
argument_list|(
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vs
operator|=
name|vec_lvrxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vus
operator|=
name|vec_lvrxl
argument_list|(
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vus
operator|=
name|vec_lvrxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbs
operator|=
name|vec_lvrxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vp
operator|=
name|vec_lvrxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vp
argument_list|)
expr_stmt|;
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vi
operator|=
name|vec_lvrxl
argument_list|(
literal|0
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vi
operator|=
name|vec_lvrxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vui
operator|=
name|vec_lvrxl
argument_list|(
literal|0
argument_list|,
operator|&
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vui
operator|=
name|vec_lvrxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbi
operator|=
name|vec_lvrxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vf
operator|=
name|vec_lvrxl
argument_list|(
literal|0
argument_list|,
operator|&
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvxl
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x float> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x float> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|/* vec_stvlx */
name|vec_stvlx
argument_list|(
name|vsc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_sc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvlx
argument_list|(
name|vsc
argument_list|,
literal|0
argument_list|,
operator|&
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvlx
argument_list|(
name|vuc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvlx
argument_list|(
name|vuc
argument_list|,
literal|0
argument_list|,
operator|&
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvlx
argument_list|(
name|vbc
argument_list|,
literal|0
argument_list|,
operator|&
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvlx
argument_list|(
name|vs
argument_list|,
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvlx
argument_list|(
name|vs
argument_list|,
literal|0
argument_list|,
operator|&
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvlx
argument_list|(
name|vus
argument_list|,
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvlx
argument_list|(
name|vus
argument_list|,
literal|0
argument_list|,
operator|&
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvlx
argument_list|(
name|vbs
argument_list|,
literal|0
argument_list|,
operator|&
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvlx
argument_list|(
name|vp
argument_list|,
literal|0
argument_list|,
operator|&
name|vp
argument_list|)
expr_stmt|;
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvlx
argument_list|(
name|vi
argument_list|,
literal|0
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvlx
argument_list|(
name|vi
argument_list|,
literal|0
argument_list|,
operator|&
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvlx
argument_list|(
name|vui
argument_list|,
literal|0
argument_list|,
operator|&
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvlx
argument_list|(
name|vui
argument_list|,
literal|0
argument_list|,
operator|&
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvlx
argument_list|(
name|vbi
argument_list|,
literal|0
argument_list|,
operator|&
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvlx
argument_list|(
name|vf
argument_list|,
literal|0
argument_list|,
operator|&
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x float> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x float> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
comment|/* vec_stvlxl */
name|vec_stvlxl
argument_list|(
name|vsc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_sc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvlxl
argument_list|(
name|vsc
argument_list|,
literal|0
argument_list|,
operator|&
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvlxl
argument_list|(
name|vuc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvlxl
argument_list|(
name|vuc
argument_list|,
literal|0
argument_list|,
operator|&
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvlxl
argument_list|(
name|vbc
argument_list|,
literal|0
argument_list|,
operator|&
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvlxl
argument_list|(
name|vs
argument_list|,
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvlxl
argument_list|(
name|vs
argument_list|,
literal|0
argument_list|,
operator|&
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvlxl
argument_list|(
name|vus
argument_list|,
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvlxl
argument_list|(
name|vus
argument_list|,
literal|0
argument_list|,
operator|&
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvlxl
argument_list|(
name|vbs
argument_list|,
literal|0
argument_list|,
operator|&
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvlxl
argument_list|(
name|vp
argument_list|,
literal|0
argument_list|,
operator|&
name|vp
argument_list|)
expr_stmt|;
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvlxl
argument_list|(
name|vi
argument_list|,
literal|0
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvlxl
argument_list|(
name|vi
argument_list|,
literal|0
argument_list|,
operator|&
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvlxl
argument_list|(
name|vui
argument_list|,
literal|0
argument_list|,
operator|&
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvlxl
argument_list|(
name|vui
argument_list|,
literal|0
argument_list|,
operator|&
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvlxl
argument_list|(
name|vbi
argument_list|,
literal|0
argument_list|,
operator|&
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvlxl
argument_list|(
name|vf
argument_list|,
literal|0
argument_list|,
operator|&
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x float> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x float> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
comment|/* vec_stvrx */
name|vec_stvrx
argument_list|(
name|vsc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_sc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvrx
argument_list|(
name|vsc
argument_list|,
literal|0
argument_list|,
operator|&
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvrx
argument_list|(
name|vuc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvrx
argument_list|(
name|vuc
argument_list|,
literal|0
argument_list|,
operator|&
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvrx
argument_list|(
name|vbc
argument_list|,
literal|0
argument_list|,
operator|&
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvrx
argument_list|(
name|vs
argument_list|,
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvrx
argument_list|(
name|vs
argument_list|,
literal|0
argument_list|,
operator|&
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvrx
argument_list|(
name|vus
argument_list|,
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvrx
argument_list|(
name|vus
argument_list|,
literal|0
argument_list|,
operator|&
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvrx
argument_list|(
name|vbs
argument_list|,
literal|0
argument_list|,
operator|&
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvrx
argument_list|(
name|vp
argument_list|,
literal|0
argument_list|,
operator|&
name|vp
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvrx
argument_list|(
name|vi
argument_list|,
literal|0
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvrx
argument_list|(
name|vi
argument_list|,
literal|0
argument_list|,
operator|&
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvrx
argument_list|(
name|vui
argument_list|,
literal|0
argument_list|,
operator|&
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvrx
argument_list|(
name|vui
argument_list|,
literal|0
argument_list|,
operator|&
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvrx
argument_list|(
name|vbi
argument_list|,
literal|0
argument_list|,
operator|&
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
name|vec_stvrx
argument_list|(
name|vf
argument_list|,
literal|0
argument_list|,
operator|&
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x float> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x float> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvx
comment|/* vec_stvrxl */
name|vec_stvrxl
argument_list|(
name|vsc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_sc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvrxl
argument_list|(
name|vsc
argument_list|,
literal|0
argument_list|,
operator|&
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvrxl
argument_list|(
name|vuc
argument_list|,
literal|0
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvrxl
argument_list|(
name|vuc
argument_list|,
literal|0
argument_list|,
operator|&
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvrxl
argument_list|(
name|vbc
argument_list|,
literal|0
argument_list|,
operator|&
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvrxl
argument_list|(
name|vs
argument_list|,
literal|0
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvrxl
argument_list|(
name|vs
argument_list|,
literal|0
argument_list|,
operator|&
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvrxl
argument_list|(
name|vus
argument_list|,
literal|0
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvrxl
argument_list|(
name|vus
argument_list|,
literal|0
argument_list|,
operator|&
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvrxl
argument_list|(
name|vbs
argument_list|,
literal|0
argument_list|,
operator|&
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvrxl
argument_list|(
name|vp
argument_list|,
literal|0
argument_list|,
operator|&
name|vp
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvrxl
argument_list|(
name|vi
argument_list|,
literal|0
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvrxl
argument_list|(
name|vi
argument_list|,
literal|0
argument_list|,
operator|&
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvrxl
argument_list|(
name|vui
argument_list|,
literal|0
argument_list|,
operator|&
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvrxl
argument_list|(
name|vui
argument_list|,
literal|0
argument_list|,
operator|&
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvrxl
argument_list|(
name|vbi
argument_list|,
literal|0
argument_list|,
operator|&
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
name|vec_stvrxl
argument_list|(
name|vf
argument_list|,
literal|0
argument_list|,
operator|&
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.lvx
comment|// CHECK: @llvm.ppc.altivec.lvsl
comment|// CHECK: store<4 x float> zeroinitializer
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.lvsr
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK: @llvm.ppc.altivec.stvxl
comment|// CHECK-LE: @llvm.ppc.altivec.lvx
comment|// CHECK-LE: @llvm.ppc.altivec.lvsl
comment|// CHECK-LE: store<4 x float> zeroinitializer
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.lvsr
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.stvxl
comment|/* vec_promote */
name|res_vsc
operator|=
name|vec_promote
argument_list|(
name|param_sc
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: insertelement<16 x i8>
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: insertelement<16 x i8>
name|res_vuc
operator|=
name|vec_promote
argument_list|(
name|param_uc
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: store<16 x i8> zeroinitializer
comment|// CHECK: insertelement<16 x i8>
comment|// CHECK-LE: store<16 x i8> zeroinitializer
comment|// CHECK-LE: insertelement<16 x i8>
name|res_vs
operator|=
name|vec_promote
argument_list|(
name|param_s
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: insertelement<8 x i16>
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: insertelement<8 x i16>
name|res_vus
operator|=
name|vec_promote
argument_list|(
name|param_us
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: store<8 x i16> zeroinitializer
comment|// CHECK: insertelement<8 x i16>
comment|// CHECK-LE: store<8 x i16> zeroinitializer
comment|// CHECK-LE: insertelement<8 x i16>
name|res_vi
operator|=
name|vec_promote
argument_list|(
name|param_i
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: insertelement<4 x i32>
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: insertelement<4 x i32>
name|res_vui
operator|=
name|vec_promote
argument_list|(
name|param_ui
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: store<4 x i32> zeroinitializer
comment|// CHECK: insertelement<4 x i32>
comment|// CHECK-LE: store<4 x i32> zeroinitializer
comment|// CHECK-LE: insertelement<4 x i32>
name|res_vf
operator|=
name|vec_promote
argument_list|(
name|param_f
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: store<4 x float> zeroinitializer
comment|// CHECK: insertelement<4 x float>
comment|// CHECK-LE: store<4 x float> zeroinitializer
comment|// CHECK-LE: insertelement<4 x float>
comment|/* vec_splats */
name|res_vsc
operator|=
name|vec_splats
argument_list|(
name|param_sc
argument_list|)
expr_stmt|;
comment|// CHECK: insertelement<16 x i8>
comment|// CHECK-LE: insertelement<16 x i8>
name|res_vuc
operator|=
name|vec_splats
argument_list|(
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: insertelement<16 x i8>
comment|// CHECK-LE: insertelement<16 x i8>
name|res_vs
operator|=
name|vec_splats
argument_list|(
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: insertelement<8 x i16>
comment|// CHECK-LE: insertelement<8 x i16>
name|res_vus
operator|=
name|vec_splats
argument_list|(
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: insertelement<8 x i16>
comment|// CHECK-LE: insertelement<8 x i16>
name|res_vi
operator|=
name|vec_splats
argument_list|(
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: insertelement<4 x i32>
comment|// CHECK-LE: insertelement<4 x i32>
name|res_vui
operator|=
name|vec_splats
argument_list|(
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: insertelement<4 x i32>
comment|// CHECK-LE: insertelement<4 x i32>
name|res_vf
operator|=
name|vec_splats
argument_list|(
name|param_f
argument_list|)
expr_stmt|;
comment|// CHECK: insertelement<4 x float>
comment|// CHECK-LE: insertelement<4 x float>
comment|/* ------------------------------ predicates -------------------------------------- */
comment|/* vec_all_eq */
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vp
argument_list|,
name|vp
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpeqfp.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsb.p
name|res_i
operator|=
name|vec_all_ge
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsb.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsb.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_all_ge
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_all_ge
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_all_ge
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_all_ge
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsh.p
name|res_i
operator|=
name|vec_all_ge
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsh.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_all_ge
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_all_ge
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_all_ge
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_all_ge
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsw.p
name|res_i
operator|=
name|vec_all_ge
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsw.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_all_ge
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_all_ge
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_all_ge
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_all_ge
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgefp.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsb.p
name|res_i
operator|=
name|vec_all_gt
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsb.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsb.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_all_gt
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_all_gt
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_all_gt
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_all_gt
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsh.p
name|res_i
operator|=
name|vec_all_gt
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsh.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_all_gt
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_all_gt
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_all_gt
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_all_gt
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsw.p
name|res_i
operator|=
name|vec_all_gt
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsw.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_all_gt
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_all_gt
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_all_gt
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_all_gt
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtfp.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpbfp.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsb.p
name|res_i
operator|=
name|vec_all_le
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsb.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsb.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_all_le
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_all_le
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_all_le
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_all_le
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsh.p
name|res_i
operator|=
name|vec_all_le
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsh.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_all_le
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_all_le
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_all_le
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_all_le
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsw.p
name|res_i
operator|=
name|vec_all_le
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsw.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_all_le
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_all_le
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_all_le
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_all_le
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgefp.p
comment|/* vec_all_lt */
name|res_i
operator|=
name|vec_all_lt
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsb.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsb.p
name|res_i
operator|=
name|vec_all_lt
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsb.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsb.p
name|res_i
operator|=
name|vec_all_lt
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_all_lt
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_all_lt
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_all_lt
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_all_lt
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_all_lt
argument_list|(
name|vs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsh.p
name|res_i
operator|=
name|vec_all_lt
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsh.p
name|res_i
operator|=
name|vec_all_lt
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_all_lt
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_all_lt
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_all_lt
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_all_lt
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_all_lt
argument_list|(
name|vi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsw.p
name|res_i
operator|=
name|vec_all_lt
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsw.p
name|res_i
operator|=
name|vec_all_lt
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_all_lt
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_all_lt
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_all_lt
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_all_lt
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_all_lt
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtfp.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtfp.p
comment|/* vec_all_nan */
name|res_i
operator|=
name|vec_all_nan
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpeqfp.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpeqfp.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vp
argument_list|,
name|vp
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpeqfp.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgefp.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtfp.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgefp.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtfp.p
comment|/* vec_all_numeric */
name|res_i
operator|=
name|vec_all_numeric
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpeqfp.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpeqfp.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vp
argument_list|,
name|vp
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpeqfp.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsb.p
name|res_i
operator|=
name|vec_any_ge
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsb.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsb.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_any_ge
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_any_ge
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_any_ge
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_any_ge
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsh.p
name|res_i
operator|=
name|vec_any_ge
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsh.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_any_ge
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_any_ge
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_any_ge
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_any_ge
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsw.p
name|res_i
operator|=
name|vec_any_ge
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsw.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_any_ge
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_any_ge
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_any_ge
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_any_ge
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgefp.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsb.p
name|res_i
operator|=
name|vec_any_gt
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsb.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsb.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_any_gt
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_any_gt
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_any_gt
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_any_gt
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsh.p
name|res_i
operator|=
name|vec_any_gt
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsh.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_any_gt
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_any_gt
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_any_gt
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_any_gt
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsw.p
name|res_i
operator|=
name|vec_any_gt
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsw.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_any_gt
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_any_gt
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_any_gt
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_any_gt
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtfp.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsb.p
name|res_i
operator|=
name|vec_any_le
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsb.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsb.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_any_le
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_any_le
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_any_le
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_any_le
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsh.p
name|res_i
operator|=
name|vec_any_le
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsh.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_any_le
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_any_le
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_any_le
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_any_le
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsw.p
name|res_i
operator|=
name|vec_any_le
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsw.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_any_le
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_any_le
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_any_le
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_any_le
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgefp.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsb.p
name|res_i
operator|=
name|vec_any_lt
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsb.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsb.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_any_lt
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_any_lt
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_any_lt
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
name|res_i
operator|=
name|vec_any_lt
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsh.p
name|res_i
operator|=
name|vec_any_lt
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsh.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_any_lt
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_any_lt
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_any_lt
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
name|res_i
operator|=
name|vec_any_lt
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsw.p
name|res_i
operator|=
name|vec_any_lt
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsw.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_any_lt
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_any_lt
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_any_lt
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
name|res_i
operator|=
name|vec_any_lt
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtfp.p
comment|/* vec_any_nan */
name|res_i
operator|=
name|vec_any_nan
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpeqfp.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpeqfp.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vbs
argument_list|,
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vp
argument_list|,
name|vp
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vbi
argument_list|,
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpeqfp.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgefp.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtfp.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgefp.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtfp.p
comment|/* vec_any_numeric */
name|res_i
operator|=
name|vec_any_numeric
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpeqfp.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpeqfp.p
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
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpbfp.p
block|}
end_function

begin_comment
comment|/* ------------------------------ Relational Operators ------------------------------ */
end_comment

begin_comment
comment|// CHECK-LABEL: define void @test7
end_comment

begin_function
name|void
name|test7
parameter_list|()
block|{
name|vector
name|signed
name|char
name|vsc1
init|=
call|(
name|vector
name|signed
name|char
call|)
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|;
name|vector
name|signed
name|char
name|vsc2
init|=
call|(
name|vector
name|signed
name|char
call|)
argument_list|(
operator|-
literal|2
argument_list|)
decl_stmt|;
name|res_i
operator|=
operator|(
name|vsc1
operator|==
name|vsc2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p(i32 2
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p(i32 2
name|res_i
operator|=
operator|(
name|vsc1
operator|!=
name|vsc2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p(i32 0
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p(i32 0
name|res_i
operator|=
operator|(
name|vsc1
operator|<
name|vsc2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsb.p(i32 2
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsb.p(i32 2
name|res_i
operator|=
operator|(
name|vsc1
operator|>
name|vsc2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsb.p(i32 2
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsb.p(i32 2
name|res_i
operator|=
operator|(
name|vsc1
operator|<=
name|vsc2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsb.p(i32 0
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsb.p(i32 0
name|res_i
operator|=
operator|(
name|vsc1
operator|>=
name|vsc2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsb.p(i32 0
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsb.p(i32 0
name|vector
name|unsigned
name|char
name|vuc1
init|=
call|(
name|vector
name|unsigned
name|char
call|)
argument_list|(
literal|1
argument_list|)
decl_stmt|;
name|vector
name|unsigned
name|char
name|vuc2
init|=
call|(
name|vector
name|unsigned
name|char
call|)
argument_list|(
literal|2
argument_list|)
decl_stmt|;
name|res_i
operator|=
operator|(
name|vuc1
operator|==
name|vuc2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p(i32 2
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p(i32 2
name|res_i
operator|=
operator|(
name|vuc1
operator|!=
name|vuc2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequb.p(i32 0
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequb.p(i32 0
name|res_i
operator|=
operator|(
name|vuc1
operator|<
name|vuc2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p(i32 2
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p(i32 2
name|res_i
operator|=
operator|(
name|vuc1
operator|>
name|vuc2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p(i32 2
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p(i32 2
name|res_i
operator|=
operator|(
name|vuc1
operator|<=
name|vuc2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p(i32 0
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p(i32 0
name|res_i
operator|=
operator|(
name|vuc1
operator|>=
name|vuc2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtub.p(i32 0
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtub.p(i32 0
name|vector
name|short
name|vs1
init|=
call|(
name|vector
name|short
call|)
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|;
name|vector
name|short
name|vs2
init|=
call|(
name|vector
name|short
call|)
argument_list|(
operator|-
literal|2
argument_list|)
decl_stmt|;
name|res_i
operator|=
operator|(
name|vs1
operator|==
name|vs2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p(i32 2
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p(i32 2
name|res_i
operator|=
operator|(
name|vs1
operator|!=
name|vs2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p(i32 0
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p(i32 0
name|res_i
operator|=
operator|(
name|vs1
operator|<
name|vs2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsh.p(i32 2
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsh.p(i32 2
name|res_i
operator|=
operator|(
name|vs1
operator|>
name|vs2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsh.p(i32 2
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsh.p(i32 2
name|res_i
operator|=
operator|(
name|vs1
operator|<=
name|vs2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsh.p(i32 0
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsh.p(i32 0
name|res_i
operator|=
operator|(
name|vs1
operator|>=
name|vs2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsh.p(i32 0
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsh.p(i32 0
name|vector
name|unsigned
name|short
name|vus1
init|=
call|(
name|vector
name|unsigned
name|short
call|)
argument_list|(
literal|1
argument_list|)
decl_stmt|;
name|vector
name|unsigned
name|short
name|vus2
init|=
call|(
name|vector
name|unsigned
name|short
call|)
argument_list|(
literal|2
argument_list|)
decl_stmt|;
name|res_i
operator|=
operator|(
name|vus1
operator|==
name|vus2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p(i32 2
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p(i32 2
name|res_i
operator|=
operator|(
name|vus1
operator|!=
name|vus2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequh.p(i32 0
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequh.p(i32 0
name|res_i
operator|=
operator|(
name|vus1
operator|<
name|vus2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p(i32 2
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p(i32 2
name|res_i
operator|=
operator|(
name|vus1
operator|>
name|vus2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p(i32 2
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p(i32 2
name|res_i
operator|=
operator|(
name|vus1
operator|<=
name|vus2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p(i32 0
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p(i32 0
name|res_i
operator|=
operator|(
name|vus1
operator|>=
name|vus2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuh.p(i32 0
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuh.p(i32 0
name|vector
name|int
name|vi1
init|=
call|(
name|vector
name|int
call|)
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|;
name|vector
name|int
name|vi2
init|=
call|(
name|vector
name|int
call|)
argument_list|(
operator|-
literal|2
argument_list|)
decl_stmt|;
name|res_i
operator|=
operator|(
name|vi1
operator|==
name|vi2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p(i32 2
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p(i32 2
name|res_i
operator|=
operator|(
name|vi1
operator|!=
name|vi2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p(i32 0
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p(i32 0
name|res_i
operator|=
operator|(
name|vi1
operator|<
name|vi2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsw.p(i32 2
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsw.p(i32 2
name|res_i
operator|=
operator|(
name|vi1
operator|>
name|vi2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsw.p(i32 2
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsw.p(i32 2
name|res_i
operator|=
operator|(
name|vi1
operator|<=
name|vi2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsw.p(i32 0
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsw.p(i32 0
name|res_i
operator|=
operator|(
name|vi1
operator|>=
name|vi2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsw.p(i32 0
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsw.p(i32 0
name|vector
name|unsigned
name|int
name|vui1
init|=
call|(
name|vector
name|unsigned
name|int
call|)
argument_list|(
literal|1
argument_list|)
decl_stmt|;
name|vector
name|unsigned
name|int
name|vui2
init|=
call|(
name|vector
name|unsigned
name|int
call|)
argument_list|(
literal|2
argument_list|)
decl_stmt|;
name|res_i
operator|=
operator|(
name|vui1
operator|==
name|vui2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p(i32 2
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p(i32 2
name|res_i
operator|=
operator|(
name|vui1
operator|!=
name|vui2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequw.p(i32 0
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequw.p(i32 0
name|res_i
operator|=
operator|(
name|vui1
operator|<
name|vui2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p(i32 2
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p(i32 2
name|res_i
operator|=
operator|(
name|vui1
operator|>
name|vui2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p(i32 2
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p(i32 2
name|res_i
operator|=
operator|(
name|vui1
operator|<=
name|vui2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p(i32 0
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p(i32 0
name|res_i
operator|=
operator|(
name|vui1
operator|>=
name|vui2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtuw.p(i32 0
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtuw.p(i32 0
name|vector
name|float
name|vf1
init|=
call|(
name|vector
name|float
call|)
argument_list|(
literal|1.0
argument_list|)
decl_stmt|;
name|vector
name|float
name|vf2
init|=
call|(
name|vector
name|float
call|)
argument_list|(
literal|2.0
argument_list|)
decl_stmt|;
name|res_i
operator|=
operator|(
name|vf1
operator|==
name|vf2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpeqfp.p(i32 2
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpeqfp.p(i32 2
name|res_i
operator|=
operator|(
name|vf1
operator|!=
name|vf2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpeqfp.p(i32 0
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpeqfp.p(i32 0
name|res_i
operator|=
operator|(
name|vf1
operator|<
name|vf2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtfp.p(i32 2
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtfp.p(i32 2
name|res_i
operator|=
operator|(
name|vf1
operator|>
name|vf2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtfp.p(i32 2
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtfp.p(i32 2
name|res_i
operator|=
operator|(
name|vf1
operator|<=
name|vf2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgefp.p(i32 2
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgefp.p(i32 2
name|res_i
operator|=
operator|(
name|vf1
operator|>=
name|vf2
operator|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgefp.p(i32 2
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgefp.p(i32 2
block|}
end_function

begin_comment
comment|/* ------------------------------ optional ---------------------------------- */
end_comment

begin_function
name|void
name|test8
parameter_list|()
block|{
comment|// CHECK-LABEL: define void @test8
comment|// CHECK-LE-LABEL: define void @test8
name|res_vbc
operator|=
name|vec_reve
argument_list|(
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector<16 x i8> %{{[0-9]+}},<16 x i8> %{{[0-9]+}},<16 x i32><i32 15, i32 14, i32 13, i32 12, i32 11, i32 10, i32 9, i32 8, i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0>
comment|// CHECK-LE: shufflevector<16 x i8> %{{[0-9]+}},<16 x i8> %{{[0-9]+}},<16 x i32><i32 15, i32 14, i32 13, i32 12, i32 11, i32 10, i32 9, i32 8, i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0>
name|res_vsc
operator|=
name|vec_reve
argument_list|(
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector<16 x i8> %{{[0-9]+}},<16 x i8> %{{[0-9]+}},<16 x i32><i32 15, i32 14, i32 13, i32 12, i32 11, i32 10, i32 9, i32 8, i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0>
comment|// CHECK-LE: shufflevector<16 x i8> %{{[0-9]+}},<16 x i8> %{{[0-9]+}},<16 x i32><i32 15, i32 14, i32 13, i32 12, i32 11, i32 10, i32 9, i32 8, i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0>
name|res_vuc
operator|=
name|vec_reve
argument_list|(
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector<16 x i8> %{{[0-9]+}},<16 x i8> %{{[0-9]+}},<16 x i32><i32 15, i32 14, i32 13, i32 12, i32 11, i32 10, i32 9, i32 8, i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0>
comment|// CHECK-LE: shufflevector<16 x i8> %{{[0-9]+}},<16 x i8> %{{[0-9]+}},<16 x i32><i32 15, i32 14, i32 13, i32 12, i32 11, i32 10, i32 9, i32 8, i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0>
name|res_vbi
operator|=
name|vec_reve
argument_list|(
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector<4 x i32> %{{[0-9]+}},<4 x i32> %{{[0-9]+}},<4 x i32><i32 3, i32 2, i32 1, i32 0>
comment|// CHECK-LE: shufflevector<4 x i32> %{{[0-9]+}},<4 x i32> %{{[0-9]+}},<4 x i32><i32 3, i32 2, i32 1, i32 0>
name|res_vi
operator|=
name|vec_reve
argument_list|(
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector<4 x i32> %{{[0-9]+}},<4 x i32> %{{[0-9]+}},<4 x i32><i32 3, i32 2, i32 1, i32 0>
comment|// CHECK-LE: shufflevector<4 x i32> %{{[0-9]+}},<4 x i32> %{{[0-9]+}},<4 x i32><i32 3, i32 2, i32 1, i32 0>
name|res_vui
operator|=
name|vec_reve
argument_list|(
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector<4 x i32> %{{[0-9]+}},<4 x i32> %{{[0-9]+}},<4 x i32><i32 3, i32 2, i32 1, i32 0>
comment|// CHECK-LE: shufflevector<4 x i32> %{{[0-9]+}},<4 x i32> %{{[0-9]+}},<4 x i32><i32 3, i32 2, i32 1, i32 0>
name|res_vbs
operator|=
name|vec_reve
argument_list|(
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector<8 x i16> %{{[0-9]+}},<8 x i16> %{{[0-9]+}},<8 x i32><i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0>
comment|// CHECK-LE: shufflevector<8 x i16> %{{[0-9]+}},<8 x i16> %{{[0-9]+}},<8 x i32><i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0>
name|res_vbs
operator|=
name|vec_reve
argument_list|(
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector<8 x i16> %{{[0-9]+}},<8 x i16> %{{[0-9]+}},<8 x i32><i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0>
comment|// CHECK-LE: shufflevector<8 x i16> %{{[0-9]+}},<8 x i16> %{{[0-9]+}},<8 x i32><i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0>
name|res_vbs
operator|=
name|vec_reve
argument_list|(
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector<8 x i16> %{{[0-9]+}},<8 x i16> %{{[0-9]+}},<8 x i32><i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0>
comment|// CHECK-LE: shufflevector<8 x i16> %{{[0-9]+}},<8 x i16> %{{[0-9]+}},<8 x i32><i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0>
name|res_vf
operator|=
name|vec_reve
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector<4 x float> %{{[0-9]+}},<4 x float> %{{[0-9]+}},<4 x i32><i32 3, i32 2, i32 1, i32 0>
comment|// CHECK-LE: shufflevector<4 x float> %{{[0-9]+}},<4 x float> %{{[0-9]+}},<4 x i32><i32 3, i32 2, i32 1, i32 0>
name|res_vbc
operator|=
name|vec_revb
argument_list|(
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = load<16 x i8>,<16 x i8>* @vbc, align 16
comment|// CHECK: store<16 x i8> [[T1]],<16 x i8>* [[T2:%.+]], align 16
comment|// CHECK: [[T3:%.+]] = load<16 x i8>,<16 x i8>* [[T2]], align 16
comment|// CHECK: store<16 x i8> [[T3]],<16 x i8>* @res_vbc, align 16
comment|// CHECK-LE: [[T1:%.+]] = load<16 x i8>,<16 x i8>* @vbc, align 16
comment|// CHECK-LE: store<16 x i8> [[T1]],<16 x i8>* [[T2:%.+]], align 16
comment|// CHECK-LE: [[T3:%.+]] = load<16 x i8>,<16 x i8>* [[T2]], align 16
comment|// CHECK-LE: store<16 x i8> [[T3]],<16 x i8>* @res_vbc, align 16
name|res_vsc
operator|=
name|vec_revb
argument_list|(
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = load<16 x i8>,<16 x i8>* @vsc, align 16
comment|// CHECK: store<16 x i8> [[T1]],<16 x i8>* [[T2:%.+]], align 16
comment|// CHECK: [[T3:%.+]] = load<16 x i8>,<16 x i8>* [[T2]], align 16
comment|// CHECK: store<16 x i8> [[T3]],<16 x i8>* @res_vsc, align 16
comment|// CHECK-LE: [[T1:%.+]] = load<16 x i8>,<16 x i8>* @vsc, align 16
comment|// CHECK-LE: store<16 x i8> [[T1]],<16 x i8>* [[T2:%.+]], align 16
comment|// CHECK-LE: [[T3:%.+]] = load<16 x i8>,<16 x i8>* [[T2]], align 16
comment|// CHECK-LE: store<16 x i8> [[T3]],<16 x i8>* @res_vsc, align 16
name|res_vuc
operator|=
name|vec_revb
argument_list|(
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = load<16 x i8>,<16 x i8>* @vuc, align 16
comment|// CHECK: store<16 x i8> [[T1]],<16 x i8>* [[T2:%.+]], align 16
comment|// CHECK: [[T3:%.+]] = load<16 x i8>,<16 x i8>* [[T2]], align 16
comment|// CHECK: store<16 x i8> [[T3]],<16 x i8>* @res_vuc, align 16
comment|// CHECK-LE: [[T1:%.+]] = load<16 x i8>,<16 x i8>* @vuc, align 16
comment|// CHECK-LE: store<16 x i8> [[T1]],<16 x i8>* [[T2:%.+]], align 16
comment|// CHECK-LE: [[T3:%.+]] = load<16 x i8>,<16 x i8>* [[T2]], align 16
comment|// CHECK-LE: store<16 x i8> [[T3]],<16 x i8>* @res_vuc, align 16
name|res_vbs
operator|=
name|vec_revb
argument_list|(
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: store<16 x i8><i8 1, i8 0, i8 3, i8 2, i8 5, i8 4, i8 7, i8 6, i8 9, i8 8, i8 11, i8 10, i8 13, i8 12, i8 15, i8 14>,<16 x i8>* {{%.+}}, align 16
comment|// CHECK: call<4 x i32> @llvm.ppc.altivec.vperm(<4 x i32> {{%.+}},<4 x i32> {{%.+}},<16 x i8> {{%.+}})
comment|// CHECK-LE: store<16 x i8><i8 1, i8 0, i8 3, i8 2, i8 5, i8 4, i8 7, i8 6, i8 9, i8 8, i8 11, i8 10, i8 13, i8 12, i8 15, i8 14>,<16 x i8>* {{%.+}}, align 16
comment|// CHECK-LE: store<16 x i8><i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>,<16 x i8>* {{%.+}}, align 16
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: call<4 x i32> @llvm.ppc.altivec.vperm(<4 x i32> {{%.+}},<4 x i32> {{%.+}},<16 x i8> {{%.+}})
name|res_vs
operator|=
name|vec_revb
argument_list|(
name|vs
argument_list|)
expr_stmt|;
comment|// CHECK: store<16 x i8><i8 1, i8 0, i8 3, i8 2, i8 5, i8 4, i8 7, i8 6, i8 9, i8 8, i8 11, i8 10, i8 13, i8 12, i8 15, i8 14>,<16 x i8>* {{%.+}}, align 16
comment|// CHECK: call<4 x i32> @llvm.ppc.altivec.vperm(<4 x i32> {{%.+}},<4 x i32> {{%.+}},<16 x i8> {{%.+}})
comment|// CHECK-LE: store<16 x i8><i8 1, i8 0, i8 3, i8 2, i8 5, i8 4, i8 7, i8 6, i8 9, i8 8, i8 11, i8 10, i8 13, i8 12, i8 15, i8 14>,<16 x i8>* {{%.+}}, align 16
comment|// CHECK-LE: store<16 x i8><i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>,<16 x i8>* {{%.+}}, align 16
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: call<4 x i32> @llvm.ppc.altivec.vperm(<4 x i32> {{%.+}},<4 x i32> {{%.+}},<16 x i8> {{%.+}})
name|res_vus
operator|=
name|vec_revb
argument_list|(
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: store<16 x i8><i8 1, i8 0, i8 3, i8 2, i8 5, i8 4, i8 7, i8 6, i8 9, i8 8, i8 11, i8 10, i8 13, i8 12, i8 15, i8 14>,<16 x i8>* {{%.+}}, align 16
comment|// CHECK: call<4 x i32> @llvm.ppc.altivec.vperm(<4 x i32> {{%.+}},<4 x i32> {{%.+}},<16 x i8> {{%.+}})
comment|// CHECK-LE: store<16 x i8><i8 1, i8 0, i8 3, i8 2, i8 5, i8 4, i8 7, i8 6, i8 9, i8 8, i8 11, i8 10, i8 13, i8 12, i8 15, i8 14>,<16 x i8>* {{%.+}}, align 16
comment|// CHECK-LE: store<16 x i8><i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>,<16 x i8>* {{%.+}}, align 16
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: call<4 x i32> @llvm.ppc.altivec.vperm(<4 x i32> {{%.+}},<4 x i32> {{%.+}},<16 x i8> {{%.+}})
name|res_vbi
operator|=
name|vec_revb
argument_list|(
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: store<16 x i8><i8 3, i8 2, i8 1, i8 0, i8 7, i8 6, i8 5, i8 4, i8 11, i8 10, i8 9, i8 8, i8 15, i8 14, i8 13, i8 12>,<16 x i8>* {{%.+}}, align 16
comment|// CHECK: call<4 x i32> @llvm.ppc.altivec.vperm(<4 x i32> {{%.+}},<4 x i32> {{%.+}},<16 x i8> {{%.+}})
comment|// CHECK-LE: store<16 x i8><i8 3, i8 2, i8 1, i8 0, i8 7, i8 6, i8 5, i8 4, i8 11, i8 10, i8 9, i8 8, i8 15, i8 14, i8 13, i8 12>,<16 x i8>* {{%.+}}, align 16
comment|// CHECK-LE: store<16 x i8><i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>,<16 x i8>* {{%.+}}, align 16
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: call<4 x i32> @llvm.ppc.altivec.vperm(<4 x i32> {{%.+}},<4 x i32> {{%.+}},<16 x i8> {{%.+}})
name|res_vi
operator|=
name|vec_revb
argument_list|(
name|vi
argument_list|)
expr_stmt|;
comment|// CHECK: store<16 x i8><i8 3, i8 2, i8 1, i8 0, i8 7, i8 6, i8 5, i8 4, i8 11, i8 10, i8 9, i8 8, i8 15, i8 14, i8 13, i8 12>,<16 x i8>* {{%.+}}, align 16
comment|// CHECK: call<4 x i32> @llvm.ppc.altivec.vperm(<4 x i32> {{%.+}},<4 x i32> {{%.+}},<16 x i8> {{%.+}})
comment|// CHECK-LE: store<16 x i8><i8 3, i8 2, i8 1, i8 0, i8 7, i8 6, i8 5, i8 4, i8 11, i8 10, i8 9, i8 8, i8 15, i8 14, i8 13, i8 12>,<16 x i8>* {{%.+}}, align 16
comment|// CHECK-LE: store<16 x i8><i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>,<16 x i8>* {{%.+}}, align 16
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: call<4 x i32> @llvm.ppc.altivec.vperm(<4 x i32> {{%.+}},<4 x i32> {{%.+}},<16 x i8> {{%.+}})
name|res_vui
operator|=
name|vec_revb
argument_list|(
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: store<16 x i8><i8 3, i8 2, i8 1, i8 0, i8 7, i8 6, i8 5, i8 4, i8 11, i8 10, i8 9, i8 8, i8 15, i8 14, i8 13, i8 12>,<16 x i8>* {{%.+}}, align 16
comment|// CHECK: call<4 x i32> @llvm.ppc.altivec.vperm(<4 x i32> {{%.+}},<4 x i32> {{%.+}},<16 x i8> {{%.+}})
comment|// CHECK-LE: store<16 x i8><i8 3, i8 2, i8 1, i8 0, i8 7, i8 6, i8 5, i8 4, i8 11, i8 10, i8 9, i8 8, i8 15, i8 14, i8 13, i8 12>,<16 x i8>* {{%.+}}, align 16
comment|// CHECK-LE: store<16 x i8><i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>,<16 x i8>* {{%.+}}, align 16
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: call<4 x i32> @llvm.ppc.altivec.vperm(<4 x i32> {{%.+}},<4 x i32> {{%.+}},<16 x i8> {{%.+}})
name|res_vf
operator|=
name|vec_revb
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: store<16 x i8><i8 3, i8 2, i8 1, i8 0, i8 7, i8 6, i8 5, i8 4, i8 11, i8 10, i8 9, i8 8, i8 15, i8 14, i8 13, i8 12>,<16 x i8>* {{%.+}}, align 16
comment|// CHECK: call<4 x i32> @llvm.ppc.altivec.vperm(<4 x i32> {{%.+}},<4 x i32> {{%.+}},<16 x i8> {{%.+}})
comment|// CHECK-LE: store<16 x i8><i8 3, i8 2, i8 1, i8 0, i8 7, i8 6, i8 5, i8 4, i8 11, i8 10, i8 9, i8 8, i8 15, i8 14, i8 13, i8 12>,<16 x i8>* {{%.+}}, align 16
comment|// CHECK-LE: store<16 x i8><i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>,<16 x i8>* {{%.+}}, align 16
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: call<4 x i32> @llvm.ppc.altivec.vperm(<4 x i32> {{%.+}},<4 x i32> {{%.+}},<16 x i8> {{%.+}})
block|}
end_function

begin_comment
comment|/* ------------------------------ vec_xl ------------------------------------ */
end_comment

begin_function
name|void
name|test9
parameter_list|()
block|{
comment|// CHECK-LABEL: define void @test9
comment|// CHECK-LE-LABEL: define void @test9
name|res_vsc
operator|=
name|vec_xl
argument_list|(
name|param_sll
argument_list|,
operator|&
name|param_sc
argument_list|)
expr_stmt|;
comment|// CHECK: load<16 x i8>,<16 x i8>* %{{[0-9]+}}, align 16
comment|// CHECK-LE: load<16 x i8>,<16 x i8>* %{{[0-9]+}}, align 16
name|res_vuc
operator|=
name|vec_xl
argument_list|(
name|param_sll
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: load<16 x i8>,<16 x i8>* %{{[0-9]+}}, align 16
comment|// CHECK-LE: load<16 x i8>,<16 x i8>* %{{[0-9]+}}, align 16
name|res_vs
operator|=
name|vec_xl
argument_list|(
name|param_sll
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: load<8 x i16>,<8 x i16>* %{{[0-9]+}}, align 16
comment|// CHECK-LE: load<8 x i16>,<8 x i16>* %{{[0-9]+}}, align 16
name|res_vus
operator|=
name|vec_xl
argument_list|(
name|param_sll
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: load<8 x i16>,<8 x i16>* %{{[0-9]+}}, align 16
comment|// CHECK-LE: load<8 x i16>,<8 x i16>* %{{[0-9]+}}, align 16
name|res_vi
operator|=
name|vec_xl
argument_list|(
name|param_sll
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: load<4 x i32>,<4 x i32>* %{{[0-9]+}}, align 16
comment|// CHECK-LE: load<4 x i32>,<4 x i32>* %{{[0-9]+}}, align 16
name|res_vui
operator|=
name|vec_xl
argument_list|(
name|param_sll
argument_list|,
operator|&
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: load<4 x i32>,<4 x i32>* %{{[0-9]+}}, align 16
comment|// CHECK-LE: load<4 x i32>,<4 x i32>* %{{[0-9]+}}, align 16
name|res_vf
operator|=
name|vec_xl
argument_list|(
name|param_sll
argument_list|,
operator|&
name|param_f
argument_list|)
expr_stmt|;
comment|// CHECK: load<4 x float>,<4 x float>* %{{[0-9]+}}, align 16
comment|// CHECK-LE: load<4 x float>,<4 x float>* %{{[0-9]+}}, align 16
block|}
end_function

begin_comment
comment|/* ------------------------------ vec_xst ----------------------------------- */
end_comment

begin_function
name|void
name|test10
parameter_list|()
block|{
comment|// CHECK-LABEL: define void @test10
comment|// CHECK-LE-LABEL: define void @test10
name|vec_xst
argument_list|(
name|vsc
argument_list|,
name|param_sll
argument_list|,
operator|&
name|param_sc
argument_list|)
expr_stmt|;
comment|// CHECK: store<16 x i8> %{{[0-9]+}},<16 x i8>* %{{[0-9]+}}, align 16
comment|// CHECK-LE: store<16 x i8> %{{[0-9]+}},<16 x i8>* %{{[0-9]+}}, align 16
name|vec_xst
argument_list|(
name|vuc
argument_list|,
name|param_sll
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: store<16 x i8> %{{[0-9]+}},<16 x i8>* %{{[0-9]+}}, align 16
comment|// CHECK-LE: store<16 x i8> %{{[0-9]+}},<16 x i8>* %{{[0-9]+}}, align 16
name|vec_xst
argument_list|(
name|vs
argument_list|,
name|param_sll
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: store<8 x i16> %{{[0-9]+}},<8 x i16>* %{{[0-9]+}}, align 16
comment|// CHECK-LE: store<8 x i16> %{{[0-9]+}},<8 x i16>* %{{[0-9]+}}, align 16
name|vec_xst
argument_list|(
name|vus
argument_list|,
name|param_sll
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: store<8 x i16> %{{[0-9]+}},<8 x i16>* %{{[0-9]+}}, align 16
comment|// CHECK-LE: store<8 x i16> %{{[0-9]+}},<8 x i16>* %{{[0-9]+}}, align 16
name|vec_xst
argument_list|(
name|vi
argument_list|,
name|param_sll
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: store<4 x i32> %{{[0-9]+}},<4 x i32>* %{{[0-9]+}}, align 16
comment|// CHECK-LE: store<4 x i32> %{{[0-9]+}},<4 x i32>* %{{[0-9]+}}, align 16
name|vec_xst
argument_list|(
name|vui
argument_list|,
name|param_sll
argument_list|,
operator|&
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: store<4 x i32> %{{[0-9]+}},<4 x i32>* %{{[0-9]+}}, align 16
comment|// CHECK-LE: store<4 x i32> %{{[0-9]+}},<4 x i32>* %{{[0-9]+}}, align 16
name|vec_xst
argument_list|(
name|vf
argument_list|,
name|param_sll
argument_list|,
operator|&
name|param_f
argument_list|)
expr_stmt|;
comment|// CHECK: store<4 x float> %{{[0-9]+}},<4 x float>* %{{[0-9]+}}, align 16
comment|// CHECK-LE: store<4 x float> %{{[0-9]+}},<4 x float>* %{{[0-9]+}}, align 16
block|}
end_function

begin_comment
comment|/* ----------------------------- vec_xl_be ---------------------------------- */
end_comment

begin_function
name|void
name|test11
parameter_list|()
block|{
comment|// CHECK-LABEL: define void @test11
comment|// CHECK-LE-LABEL: define void @test11
name|res_vsc
operator|=
name|vec_xl_be
argument_list|(
name|param_sll
argument_list|,
operator|&
name|param_sc
argument_list|)
expr_stmt|;
comment|// CHECK: load<16 x i8>,<16 x i8>* %{{[0-9]+}}, align 16
comment|// CHECK-LE: call<2 x double> @llvm.ppc.vsx.lxvd2x.be(i8* %{{[0-9]+}})
comment|// CHECK-LE: shufflevector<16 x i8> %{{[0-9]+}},<16 x i8> %{{[0-9]+}},<16 x i32><i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0, i32 15, i32 14, i32 13, i32 12, i32 11, i32 10, i32 9, i32 8>
name|res_vuc
operator|=
name|vec_xl_be
argument_list|(
name|param_sll
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: load<16 x i8>,<16 x i8>* %{{[0-9]+}}, align 16
comment|// CHECK-LE: call<2 x double> @llvm.ppc.vsx.lxvd2x.be(i8* %{{[0-9]+}})
comment|// CHECK-LE: shufflevector<16 x i8> %{{[0-9]+}},<16 x i8> %{{[0-9]+}},<16 x i32><i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0, i32 15, i32 14, i32 13, i32 12, i32 11, i32 10, i32 9, i32 8>
name|res_vs
operator|=
name|vec_xl_be
argument_list|(
name|param_sll
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: load<8 x i16>,<8 x i16>* %{{[0-9]+}}, align 16
comment|// CHECK-LE: call<2 x double> @llvm.ppc.vsx.lxvd2x.be(i8* %{{[0-9]+}})
comment|// CHECK-LE: shufflevector<8 x i16> %{{[0-9]+}},<8 x i16> %{{[0-9]+}},<8 x i32><i32 3, i32 2, i32 1, i32 0, i32 7, i32 6, i32 5, i32 4>
name|res_vus
operator|=
name|vec_xl_be
argument_list|(
name|param_sll
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: load<8 x i16>,<8 x i16>* %{{[0-9]+}}, align 16
comment|// CHECK-LE: call<2 x double> @llvm.ppc.vsx.lxvd2x.be(i8* %{{[0-9]+}})
comment|// CHECK-LE: shufflevector<8 x i16> %{{[0-9]+}},<8 x i16> %{{[0-9]+}},<8 x i32><i32 3, i32 2, i32 1, i32 0, i32 7, i32 6, i32 5, i32 4>
name|res_vi
operator|=
name|vec_xl_be
argument_list|(
name|param_sll
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: load<4 x i32>,<4 x i32>* %{{[0-9]+}}, align 16
comment|// CHECK-LE: call<4 x i32> @llvm.ppc.vsx.lxvw4x.be(i8* %{{[0-9]+}})
name|res_vui
operator|=
name|vec_xl_be
argument_list|(
name|param_sll
argument_list|,
operator|&
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: load<4 x i32>,<4 x i32>* %{{[0-9]+}}, align 16
comment|// CHECK-LE: call<4 x i32> @llvm.ppc.vsx.lxvw4x.be(i8* %{{[0-9]+}})
name|res_vf
operator|=
name|vec_xl_be
argument_list|(
name|param_sll
argument_list|,
operator|&
name|param_f
argument_list|)
expr_stmt|;
comment|// CHECK: load<4 x float>,<4 x float>* %{{[0-9]+}}, align 16
comment|// CHECK-LE: call<4 x i32> @llvm.ppc.vsx.lxvw4x.be(i8* %{{[0-9]+}})
block|}
end_function

begin_comment
comment|/* ----------------------------- vec_xst_be --------------------------------- */
end_comment

begin_function
name|void
name|test12
parameter_list|()
block|{
comment|// CHECK-LABEL: define void @test12
comment|// CHECK-LE-LABEL: define void @test12
name|vec_xst_be
argument_list|(
name|vsc
argument_list|,
name|param_sll
argument_list|,
operator|&
name|param_sc
argument_list|)
expr_stmt|;
comment|// CHECK: store<16 x i8> %{{[0-9]+}},<16 x i8>* %{{[0-9]+}}, align 16
comment|// CHECK-LE: shufflevector<16 x i8> %{{[0-9]+}},<16 x i8> %{{[0-9]+}},<16 x i32><i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0, i32 15, i32 14, i32 13, i32 12, i32 11, i32 10, i32 9, i32 8>
comment|// CHECK-LE: call void @llvm.ppc.vsx.stxvd2x.be(<2 x double> %{{[0-9]+}}, i8* %{{[0-9]+}})
name|vec_xst_be
argument_list|(
name|vuc
argument_list|,
name|param_sll
argument_list|,
operator|&
name|param_uc
argument_list|)
expr_stmt|;
comment|// CHECK: store<16 x i8> %{{[0-9]+}},<16 x i8>* %{{[0-9]+}}, align 16
comment|// CHECK-LE: shufflevector<16 x i8> %{{[0-9]+}},<16 x i8> %{{[0-9]+}},<16 x i32><i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0, i32 15, i32 14, i32 13, i32 12, i32 11, i32 10, i32 9, i32 8>
comment|// CHECK-LE: call void @llvm.ppc.vsx.stxvd2x.be(<2 x double> %{{[0-9]+}}, i8* %{{[0-9]+}})
name|vec_xst_be
argument_list|(
name|vs
argument_list|,
name|param_sll
argument_list|,
operator|&
name|param_s
argument_list|)
expr_stmt|;
comment|// CHECK: store<8 x i16> %{{[0-9]+}},<8 x i16>* %{{[0-9]+}}, align 16
comment|// CHECK-LE: shufflevector<8 x i16> %{{[0-9]+}},<8 x i16> %{{[0-9]+}},<8 x i32><i32 3, i32 2, i32 1, i32 0, i32 7, i32 6, i32 5, i32 4>
comment|// CHECK-LE: call void @llvm.ppc.vsx.stxvd2x.be(<2 x double> %{{[0-9]+}}, i8* %{{[0-9]+}})
name|vec_xst_be
argument_list|(
name|vus
argument_list|,
name|param_sll
argument_list|,
operator|&
name|param_us
argument_list|)
expr_stmt|;
comment|// CHECK: store<8 x i16> %{{[0-9]+}},<8 x i16>* %{{[0-9]+}}, align 16
comment|// CHECK-LE: shufflevector<8 x i16> %{{[0-9]+}},<8 x i16> %{{[0-9]+}},<8 x i32><i32 3, i32 2, i32 1, i32 0, i32 7, i32 6, i32 5, i32 4>
comment|// CHECK-LE: call void @llvm.ppc.vsx.stxvd2x.be(<2 x double> %{{[0-9]+}}, i8* %{{[0-9]+}})
name|vec_xst_be
argument_list|(
name|vi
argument_list|,
name|param_sll
argument_list|,
operator|&
name|param_i
argument_list|)
expr_stmt|;
comment|// CHECK: store<4 x i32> %{{[0-9]+}},<4 x i32>* %{{[0-9]+}}, align 16
comment|// CHECK-LE: call void @llvm.ppc.vsx.stxvw4x.be(<4 x i32> %{{[0-9]+}}, i8* %{{[0-9]+}})
name|vec_xst_be
argument_list|(
name|vui
argument_list|,
name|param_sll
argument_list|,
operator|&
name|param_ui
argument_list|)
expr_stmt|;
comment|// CHECK: store<4 x i32> %{{[0-9]+}},<4 x i32>* %{{[0-9]+}}, align 16
comment|// CHECK-LE: call void @llvm.ppc.vsx.stxvw4x.be(<4 x i32> %{{[0-9]+}}, i8* %{{[0-9]+}})
name|vec_xst_be
argument_list|(
name|vf
argument_list|,
name|param_sll
argument_list|,
operator|&
name|param_f
argument_list|)
expr_stmt|;
comment|// CHECK: store<4 x float> %{{[0-9]+}},<4 x float>* %{{[0-9]+}}, align 16
comment|// CHECK-LE: call void @llvm.ppc.vsx.stxvw4x.be(<4 x i32> %{{[0-9]+}}, i8* %{{[0-9]+}})
block|}
end_function

end_unit

