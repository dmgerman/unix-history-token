begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-feature +altivec -target-feature +power8-vector -triple powerpc64-unknown-unknown -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-feature +altivec -target-feature +power8-vector -triple powerpc64le-unknown-unknown -emit-llvm %s -o - | FileCheck %s -check-prefix=CHECK-LE
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -target-feature +altivec -target-feature +vsx -triple powerpc64-unknown-unknown -emit-llvm %s -o - 2>&1 | FileCheck %s -check-prefix=CHECK-PPC
end_comment

begin_comment
comment|// Added -target-feature +vsx above to avoid errors about "vector double" and to
end_comment

begin_comment
comment|// generate the correct errors for functions that are only overloaded with VSX
end_comment

begin_comment
comment|// (vec_cmpge, vec_cmple). Without this option, there is only one overload so
end_comment

begin_comment
comment|// it is selected.
end_comment

begin_include
include|#
directive|include
file|<altivec.h>
end_include

begin_function
name|void
name|dummy
parameter_list|()
block|{ }
end_function

begin_decl_stmt
name|signed
name|int
name|si
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|signed
name|long
name|long
name|sll
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|long
name|ull
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|signed
name|__int128
name|sx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|__int128
name|ux
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|d
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|signed
name|char
name|vsc
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
block|,
literal|8
block|,
literal|9
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
block|,
literal|8
block|,
literal|9
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
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|bool
name|char
name|vbc
init|=
block|{
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
literal|0
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|signed
name|short
name|vss
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
name|vector
name|unsigned
name|short
name|vus
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
name|vector
name|bool
name|short
name|vbs
init|=
block|{
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|,
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|signed
name|int
name|vsi
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
name|bool
name|int
name|vbi
init|=
block|{
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|signed
name|long
name|long
name|vsll
init|=
block|{
literal|1
block|,
literal|2
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|unsigned
name|long
name|long
name|vull
init|=
block|{
literal|1
block|,
literal|2
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|bool
name|long
name|long
name|vbll
init|=
block|{
literal|1
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|signed
name|__int128
name|vsx
init|=
block|{
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|unsigned
name|__int128
name|vux
init|=
block|{
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|float
name|vfa
init|=
block|{
literal|1.e-4f
block|,
operator|-
literal|132.23f
block|,
operator|-
literal|22.1
block|,
literal|32.00f
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|double
name|vda
init|=
block|{
literal|1.e-11
block|,
operator|-
literal|132.23e10
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|res_i
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|res_d
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|signed
name|long
name|long
name|res_sll
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|long
name|res_ull
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
name|char
name|res_vbc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|signed
name|short
name|res_vss
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
name|bool
name|short
name|res_vbs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|signed
name|int
name|res_vsi
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
name|bool
name|int
name|res_vbi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|signed
name|long
name|long
name|res_vsll
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|unsigned
name|long
name|long
name|res_vull
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|bool
name|long
name|long
name|res_vbll
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|signed
name|__int128
name|res_vsx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|unsigned
name|__int128
name|res_vux
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|float
name|res_vf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|double
name|res_vd
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
name|res_vsll
operator|=
name|vec_abs
argument_list|(
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x i64> @llvm.ppc.altivec.vmaxsd(<2 x i64> %{{[0-9]*}},<2 x i64>
comment|// CHECK-LE: call<2 x i64> @llvm.ppc.altivec.vmaxsd(<2 x i64> %{{[0-9]*}},<2 x i64>
comment|// CHECK-PPC: error: call to 'vec_abs' is ambiguous
comment|/* vec_add */
name|res_vsll
operator|=
name|vec_add
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: add<2 x i64>
comment|// CHECK-LE: add<2 x i64>
comment|// CHECK-PPC: error: call to 'vec_add' is ambiguous
name|res_vull
operator|=
name|vec_add
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: add<2 x i64>
comment|// CHECK-LE: add<2 x i64>
comment|// CHECK-PPC: error: call to 'vec_add' is ambiguous
comment|/* vec_addc */
name|res_vsi
operator|=
name|vec_addc
argument_list|(
name|vsi
argument_list|,
name|vsi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddcuw
comment|// CHECK-LE: @llvm.ppc.altivec.vaddcuw
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
name|res_vsx
operator|=
name|vec_addc
argument_list|(
name|vsx
argument_list|,
name|vsx
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddcuq
comment|// CHECK-LE: @llvm.ppc.altivec.vaddcuq
name|res_vux
operator|=
name|vec_addc
argument_list|(
name|vux
argument_list|,
name|vux
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddcuq
comment|// CHECK-LE: @llvm.ppc.altivec.vaddcuq
comment|/* vec_adde */
name|res_vsx
operator|=
name|vec_adde
argument_list|(
name|vsx
argument_list|,
name|vsx
argument_list|,
name|vsx
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddeuqm
comment|// CHECK-LE: @llvm.ppc.altivec.vaddeuqm
name|res_vux
operator|=
name|vec_adde
argument_list|(
name|vux
argument_list|,
name|vux
argument_list|,
name|vux
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddeuqm
comment|// CHECK-LE: @llvm.ppc.altivec.vaddeuqm
comment|/* vec_addec */
name|res_vsx
operator|=
name|vec_addec
argument_list|(
name|vsx
argument_list|,
name|vsx
argument_list|,
name|vsx
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddecuq
comment|// CHECK-LE: @llvm.ppc.altivec.vaddecuq
comment|/* vec_mergee */
name|res_vbi
operator|=
name|vec_mergee
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vsi
operator|=
name|vec_mergee
argument_list|(
name|vsi
argument_list|,
name|vsi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vui
operator|=
name|vec_mergee
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-PPC: warning: implicit declaration of function 'vec_mergee'
name|res_vbll
operator|=
name|vec_mergee
argument_list|(
name|vbll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vsll
operator|=
name|vec_mergee
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vull
operator|=
name|vec_mergee
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vf
operator|=
name|vec_mergee
argument_list|(
name|vfa
argument_list|,
name|vfa
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vd
operator|=
name|vec_mergee
argument_list|(
name|vda
argument_list|,
name|vda
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|/* vec_mergeo */
name|res_vbi
operator|=
name|vec_mergeo
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vsi
operator|=
name|vec_mergeo
argument_list|(
name|vsi
argument_list|,
name|vsi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vui
operator|=
name|vec_mergeo
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|// CHECK-PPC: warning: implicit declaration of function 'vec_mergeo'
comment|/* vec_cmpeq */
name|res_vbll
operator|=
name|vec_cmpeq
argument_list|(
name|vbll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd
comment|// CHECK-PPC: error: call to 'vec_cmpeq' is ambiguous
name|res_vbll
operator|=
name|vec_cmpeq
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd
comment|// CHECK-PPC: error: call to 'vec_cmpeq' is ambiguous
name|res_vbll
operator|=
name|vec_cmpeq
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd
comment|// CHECK-PPC: error: call to 'vec_cmpeq' is ambiguous
comment|/* vec_cmpge */
name|res_vbll
operator|=
name|vec_cmpge
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsd
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsd
comment|// CHECK-PPC: error: call to 'vec_cmpge' is ambiguous
name|res_vbll
operator|=
name|vec_cmpge
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud
comment|// CHECK-PPC: error: call to 'vec_cmpge' is ambiguous
comment|/* vec_cmple */
name|res_vbll
operator|=
name|vec_cmple
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsd
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsd
comment|// CHECK-PPC: error: call to 'vec_cmple' is ambiguous
name|res_vbll
operator|=
name|vec_cmple
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud
comment|// CHECK-PPC: error: call to 'vec_cmple' is ambiguous
comment|/* vec_cmpgt */
name|res_vbll
operator|=
name|vec_cmpgt
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsd
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsd
comment|// CHECK-PPC: error: call to 'vec_cmpgt' is ambiguous
name|res_vbll
operator|=
name|vec_cmpgt
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud
comment|// CHECK-PPC: error: call to 'vec_cmpgt' is ambiguous
comment|/* vec_cmplt */
name|res_vbll
operator|=
name|vec_cmplt
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x i64> @llvm.ppc.altivec.vcmpgtsd(<2 x i64> %{{[0-9]*}},<2 x i64> %{{[0-9]*}})
comment|// CHECK-LE: call<2 x i64> @llvm.ppc.altivec.vcmpgtsd(<2 x i64> %{{[0-9]*}},<2 x i64> %{{[0-9]*}})
comment|// CHECK-PPC: error: call to 'vec_cmplt' is ambiguous
name|res_vbll
operator|=
name|vec_cmplt
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x i64> @llvm.ppc.altivec.vcmpgtud(<2 x i64> %{{[0-9]*}},<2 x i64> %{{[0-9]*}})
comment|// CHECK-LE: call<2 x i64> @llvm.ppc.altivec.vcmpgtud(<2 x i64> %{{[0-9]*}},<2 x i64> %{{[0-9]*}})
comment|// CHECK-PPC: error: call to 'vec_cmplt' is ambiguous
comment|/* vec_eqv */
name|res_vsc
operator|=
name|vec_eqv
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = bitcast<16 x i8> {{.+}} to<4 x i32>
comment|// CHECK: [[T2:%.+]] = bitcast<16 x i8> {{.+}} to<4 x i32>
comment|// CHECK: [[T3:%.+]] = call<4 x i32> @llvm.ppc.vsx.xxleqv(<4 x i32> [[T1]],<4 x i32> [[T2]])
comment|// CHECK: bitcast<4 x i32> [[T3]] to<16 x i8>
comment|// CHECK-LE: [[T1:%.+]] = bitcast<16 x i8> {{.+}} to<4 x i32>
comment|// CHECK-LE: [[T2:%.+]] = bitcast<16 x i8> {{.+}} to<4 x i32>
comment|// CHECK-LE: [[T3:%.+]] = call<4 x i32> @llvm.ppc.vsx.xxleqv(<4 x i32> [[T1]],<4 x i32> [[T2]])
comment|// CHECK-LE: bitcast<4 x i32> [[T3]] to<16 x i8>
comment|// CHECK-PPC: error: assigning to
name|res_vsc
operator|=
name|vec_eqv
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = bitcast<16 x i8> {{.+}} to<4 x i32>
comment|// CHECK: [[T2:%.+]] = bitcast<16 x i8> {{.+}} to<4 x i32>
comment|// CHECK: [[T3:%.+]] = call<4 x i32> @llvm.ppc.vsx.xxleqv(<4 x i32> [[T1]],<4 x i32> [[T2]])
comment|// CHECK: bitcast<4 x i32> [[T3]] to<16 x i8>
comment|// CHECK-LE: [[T1:%.+]] = bitcast<16 x i8> {{.+}} to<4 x i32>
comment|// CHECK-LE: [[T2:%.+]] = bitcast<16 x i8> {{.+}} to<4 x i32>
comment|// CHECK-LE: [[T3:%.+]] = call<4 x i32> @llvm.ppc.vsx.xxleqv(<4 x i32> [[T1]],<4 x i32> [[T2]])
comment|// CHECK-LE: bitcast<4 x i32> [[T3]] to<16 x i8>
comment|// CHECK-PPC: error: assigning to
name|res_vuc
operator|=
name|vec_eqv
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = bitcast<16 x i8> {{.+}} to<4 x i32>
comment|// CHECK: [[T2:%.+]] = bitcast<16 x i8> {{.+}} to<4 x i32>
comment|// CHECK: [[T3:%.+]] = call<4 x i32> @llvm.ppc.vsx.xxleqv(<4 x i32> [[T1]],<4 x i32> [[T2]])
comment|// CHECK: bitcast<4 x i32> [[T3]] to<16 x i8>
comment|// CHECK-LE: [[T1:%.+]] = bitcast<16 x i8> {{.+}} to<4 x i32>
comment|// CHECK-LE: [[T2:%.+]] = bitcast<16 x i8> {{.+}} to<4 x i32>
comment|// CHECK-LE: [[T3:%.+]] = call<4 x i32> @llvm.ppc.vsx.xxleqv(<4 x i32> [[T1]],<4 x i32> [[T2]])
comment|// CHECK-LE: bitcast<4 x i32> [[T3]] to<16 x i8>
comment|// CHECK-PPC: error: assigning to
name|res_vss
operator|=
name|vec_eqv
argument_list|(
name|vss
argument_list|,
name|vss
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = bitcast<8 x i16> {{.+}} to<4 x i32>
comment|// CHECK: [[T2:%.+]] = bitcast<8 x i16> {{.+}} to<4 x i32>
comment|// CHECK: [[T3:%.+]] = call<4 x i32> @llvm.ppc.vsx.xxleqv(<4 x i32> [[T1]],<4 x i32> [[T2]])
comment|// CHECK: bitcast<4 x i32> [[T3]] to<8 x i16>
comment|// CHECK-LE: [[T1:%.+]] = bitcast<8 x i16> {{.+}} to<4 x i32>
comment|// CHECK-LE: [[T2:%.+]] = bitcast<8 x i16> {{.+}} to<4 x i32>
comment|// CHECK-LE: [[T3:%.+]] = call<4 x i32> @llvm.ppc.vsx.xxleqv(<4 x i32> [[T1]],<4 x i32> [[T2]])
comment|// CHECK-LE: bitcast<4 x i32> [[T3]] to<8 x i16>
comment|// CHECK-PPC: error: assigning to
name|res_vss
operator|=
name|vec_eqv
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = bitcast<8 x i16> {{.+}} to<4 x i32>
comment|// CHECK: [[T2:%.+]] = bitcast<8 x i16> {{.+}} to<4 x i32>
comment|// CHECK: [[T3:%.+]] = call<4 x i32> @llvm.ppc.vsx.xxleqv(<4 x i32> [[T1]],<4 x i32> [[T2]])
comment|// CHECK: bitcast<4 x i32> [[T3]] to<8 x i16>
comment|// CHECK-LE: [[T1:%.+]] = bitcast<8 x i16> {{.+}} to<4 x i32>
comment|// CHECK-LE: [[T2:%.+]] = bitcast<8 x i16> {{.+}} to<4 x i32>
comment|// CHECK-LE: [[T3:%.+]] = call<4 x i32> @llvm.ppc.vsx.xxleqv(<4 x i32> [[T1]],<4 x i32> [[T2]])
comment|// CHECK-LE: bitcast<4 x i32> [[T3]] to<8 x i16>
comment|// CHECK-PPC: error: assigning to
name|res_vus
operator|=
name|vec_eqv
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = bitcast<8 x i16> {{.+}} to<4 x i32>
comment|// CHECK: [[T2:%.+]] = bitcast<8 x i16> {{.+}} to<4 x i32>
comment|// CHECK: [[T3:%.+]] = call<4 x i32> @llvm.ppc.vsx.xxleqv(<4 x i32> [[T1]],<4 x i32> [[T2]])
comment|// CHECK: bitcast<4 x i32> [[T3]] to<8 x i16>
comment|// CHECK-LE: [[T1:%.+]] = bitcast<8 x i16> {{.+}} to<4 x i32>
comment|// CHECK-LE: [[T2:%.+]] = bitcast<8 x i16> {{.+}} to<4 x i32>
comment|// CHECK-LE: [[T3:%.+]] = call<4 x i32> @llvm.ppc.vsx.xxleqv(<4 x i32> [[T1]],<4 x i32> [[T2]])
comment|// CHECK-LE: bitcast<4 x i32> [[T3]] to<8 x i16>
comment|// CHECK-PPC: error: assigning to
name|res_vsi
operator|=
name|vec_eqv
argument_list|(
name|vsi
argument_list|,
name|vsi
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x i32> @llvm.ppc.vsx.xxleqv(<4 x i32> {{.*}},<4 x i32> {{.+}})
comment|// CHECK-LE: call<4 x i32> @llvm.ppc.vsx.xxleqv(<4 x i32> {{.*}},<4 x i32> {{.+}})
comment|// CHECK-PPC: error: assigning to
name|res_vsi
operator|=
name|vec_eqv
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x i32> @llvm.ppc.vsx.xxleqv(<4 x i32> {{.*}},<4 x i32> {{.+}})
comment|// CHECK-LE: call<4 x i32> @llvm.ppc.vsx.xxleqv(<4 x i32> {{.*}},<4 x i32> {{.+}})
comment|// CHECK-PPC: error: assigning to
name|res_vui
operator|=
name|vec_eqv
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x i32> @llvm.ppc.vsx.xxleqv(<4 x i32> {{.*}},<4 x i32> {{.+}})
comment|// CHECK-LE: call<4 x i32> @llvm.ppc.vsx.xxleqv(<4 x i32> {{.*}},<4 x i32> {{.+}})
comment|// CHECK-PPC: error: assigning to
name|res_vsll
operator|=
name|vec_eqv
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = bitcast<2 x i64> {{.+}} to<4 x i32>
comment|// CHECK: [[T2:%.+]] = bitcast<2 x i64> {{.+}} to<4 x i32>
comment|// CHECK: [[T3:%.+]] = call<4 x i32> @llvm.ppc.vsx.xxleqv(<4 x i32> [[T1]],<4 x i32> [[T2]])
comment|// CHECK: bitcast<4 x i32> [[T3]] to<2 x i64>
comment|// CHECK-LE: [[T1:%.+]] = bitcast<2 x i64> {{.+}} to<4 x i32>
comment|// CHECK-LE: [[T2:%.+]] = bitcast<2 x i64> {{.+}} to<4 x i32>
comment|// CHECK-LE: [[T3:%.+]] = call<4 x i32> @llvm.ppc.vsx.xxleqv(<4 x i32> [[T1]],<4 x i32> [[T2]])
comment|// CHECK-LE: bitcast<4 x i32> [[T3]] to<2 x i64>
comment|// CHECK-PPC: error: assigning to
name|res_vsll
operator|=
name|vec_eqv
argument_list|(
name|vbll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = bitcast<2 x i64> {{.+}} to<4 x i32>
comment|// CHECK: [[T2:%.+]] = bitcast<2 x i64> {{.+}} to<4 x i32>
comment|// CHECK: [[T3:%.+]] = call<4 x i32> @llvm.ppc.vsx.xxleqv(<4 x i32> [[T1]],<4 x i32> [[T2]])
comment|// CHECK: bitcast<4 x i32> [[T3]] to<2 x i64>
comment|// CHECK-LE: [[T1:%.+]] = bitcast<2 x i64> {{.+}} to<4 x i32>
comment|// CHECK-LE: [[T2:%.+]] = bitcast<2 x i64> {{.+}} to<4 x i32>
comment|// CHECK-LE: [[T3:%.+]] = call<4 x i32> @llvm.ppc.vsx.xxleqv(<4 x i32> [[T1]],<4 x i32> [[T2]])
comment|// CHECK-LE: bitcast<4 x i32> [[T3]] to<2 x i64>
comment|// CHECK-PPC: error: assigning to
name|res_vull
operator|=
name|vec_eqv
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = bitcast<2 x i64> {{.+}} to<4 x i32>
comment|// CHECK: [[T2:%.+]] = bitcast<2 x i64> {{.+}} to<4 x i32>
comment|// CHECK: [[T3:%.+]] = call<4 x i32> @llvm.ppc.vsx.xxleqv(<4 x i32> [[T1]],<4 x i32> [[T2]])
comment|// CHECK: bitcast<4 x i32> [[T3]] to<2 x i64>
comment|// CHECK-LE: [[T1:%.+]] = bitcast<2 x i64> {{.+}} to<4 x i32>
comment|// CHECK-LE: [[T2:%.+]] = bitcast<2 x i64> {{.+}} to<4 x i32>
comment|// CHECK-LE: [[T3:%.+]] = call<4 x i32> @llvm.ppc.vsx.xxleqv(<4 x i32> [[T1]],<4 x i32> [[T2]])
comment|// CHECK-LE: bitcast<4 x i32> [[T3]] to<2 x i64>
comment|// CHECK-PPC: error: assigning to
name|res_vf
operator|=
name|vec_eqv
argument_list|(
name|vfa
argument_list|,
name|vfa
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = bitcast<4 x float> {{.+}} to<4 x i32>
comment|// CHECK: [[T2:%.+]] = bitcast<4 x float> {{.+}} to<4 x i32>
comment|// CHECK: [[T3:%.+]] = call<4 x i32> @llvm.ppc.vsx.xxleqv(<4 x i32> [[T1]],<4 x i32> [[T2]])
comment|// CHECK: bitcast<4 x i32> [[T3]] to<4 x float>
comment|// CHECK-LE: [[T1:%.+]] = bitcast<4 x float> {{.+}} to<4 x i32>
comment|// CHECK-LE: [[T2:%.+]] = bitcast<4 x float> {{.+}} to<4 x i32>
comment|// CHECK-LE: [[T3:%.+]] = call<4 x i32> @llvm.ppc.vsx.xxleqv(<4 x i32> [[T1]],<4 x i32> [[T2]])
comment|// CHECK-LE: bitcast<4 x i32> [[T3]] to<4 x float>
comment|// CHECK-PPC: error: assigning to
name|res_vd
operator|=
name|vec_eqv
argument_list|(
name|vda
argument_list|,
name|vda
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = bitcast<2 x double> {{.+}} to<4 x i32>
comment|// CHECK: [[T2:%.+]] = bitcast<2 x double> {{.+}} to<4 x i32>
comment|// CHECK: [[T3:%.+]] = call<4 x i32> @llvm.ppc.vsx.xxleqv(<4 x i32> [[T1]],<4 x i32> [[T2]])
comment|// CHECK: bitcast<4 x i32> [[T3]] to<2 x double>
comment|// CHECK-LE: [[T1:%.+]] = bitcast<2 x double> {{.+}} to<4 x i32>
comment|// CHECK-LE: [[T2:%.+]] = bitcast<2 x double> {{.+}} to<4 x i32>
comment|// CHECK-LE: [[T3:%.+]] = call<4 x i32> @llvm.ppc.vsx.xxleqv(<4 x i32> [[T1]],<4 x i32> [[T2]])
comment|// CHECK-LE: bitcast<4 x i32> [[T3]] to<2 x double>
comment|// CHECK-PPC: error: assigning to
comment|/* vec_extract */
name|res_sll
operator|=
name|vec_extract
argument_list|(
name|vsll
argument_list|,
name|si
argument_list|)
expr_stmt|;
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK-LE: extractelement<2 x i64>
name|res_ull
operator|=
name|vec_extract
argument_list|(
name|vull
argument_list|,
name|si
argument_list|)
expr_stmt|;
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK-LE: extractelement<2 x i64>
name|res_ull
operator|=
name|vec_extract
argument_list|(
name|vbll
argument_list|,
name|si
argument_list|)
expr_stmt|;
comment|// CHECK: extractelement<2 x i64>
comment|// CHECK-LE: extractelement<2 x i64>
name|res_d
operator|=
name|vec_extract
argument_list|(
name|vda
argument_list|,
name|si
argument_list|)
expr_stmt|;
comment|// CHECK: extractelement<2 x double>
comment|// CHECK-LE: extractelement<2 x double>
comment|/* vec_insert */
name|res_vsll
operator|=
name|vec_insert
argument_list|(
name|sll
argument_list|,
name|vsll
argument_list|,
name|si
argument_list|)
expr_stmt|;
comment|// CHECK: insertelement<2 x i64>
comment|// CHECK-LE: insertelement<2 x i64>
name|res_vbll
operator|=
name|vec_insert
argument_list|(
name|ull
argument_list|,
name|vbll
argument_list|,
name|si
argument_list|)
expr_stmt|;
comment|// CHECK: insertelement<2 x i64>
comment|// CHECK-LE: insertelement<2 x i64>
name|res_vull
operator|=
name|vec_insert
argument_list|(
name|ull
argument_list|,
name|vull
argument_list|,
name|si
argument_list|)
expr_stmt|;
comment|// CHECK: insertelement<2 x i64>
comment|// CHECK-LE: insertelement<2 x i64>
name|res_vd
operator|=
name|vec_insert
argument_list|(
name|d
argument_list|,
name|vda
argument_list|,
name|si
argument_list|)
expr_stmt|;
comment|// CHECK: insertelement<2 x double>
comment|// CHECK-LE: insertelement<2 x double>
comment|/* vec_cntlz */
name|res_vsc
operator|=
name|vec_cntlz
argument_list|(
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: call<16 x i8> @llvm.ctlz.v16i8(<16 x i8> %{{.+}}, i1 false)
comment|// CHECK-LE: call<16 x i8> @llvm.ctlz.v16i8(<16 x i8> %{{.+}}, i1 false)
comment|// CHECK-PPC: warning: implicit declaration of function 'vec_cntlz' is invalid in C99
name|res_vuc
operator|=
name|vec_cntlz
argument_list|(
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: call<16 x i8> @llvm.ctlz.v16i8(<16 x i8> %{{.+}}, i1 false)
comment|// CHECK-LE: call<16 x i8> @llvm.ctlz.v16i8(<16 x i8> %{{.+}}, i1 false)
name|res_vss
operator|=
name|vec_cntlz
argument_list|(
name|vss
argument_list|)
expr_stmt|;
comment|// CHECK: call<8 x i16> @llvm.ctlz.v8i16(<8 x i16> %{{.+}}, i1 false)
comment|// CHECK-LE: call<8 x i16> @llvm.ctlz.v8i16(<8 x i16> %{{.+}}, i1 false)
name|res_vus
operator|=
name|vec_cntlz
argument_list|(
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: call<8 x i16> @llvm.ctlz.v8i16(<8 x i16> %{{.+}}, i1 false)
comment|// CHECK-LE: call<8 x i16> @llvm.ctlz.v8i16(<8 x i16> %{{.+}}, i1 false)
name|res_vsi
operator|=
name|vec_cntlz
argument_list|(
name|vsi
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x i32> @llvm.ctlz.v4i32(<4 x i32> %{{.+}}, i1 false)
comment|// CHECK-LE: call<4 x i32> @llvm.ctlz.v4i32(<4 x i32> %{{.+}}, i1 false)
name|res_vui
operator|=
name|vec_cntlz
argument_list|(
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x i32> @llvm.ctlz.v4i32(<4 x i32> %{{.+}}, i1 false)
comment|// CHECK-LE: call<4 x i32> @llvm.ctlz.v4i32(<4 x i32> %{{.+}}, i1 false)
name|res_vsll
operator|=
name|vec_cntlz
argument_list|(
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x i64> @llvm.ctlz.v2i64(<2 x i64> %{{.+}}, i1 false)
comment|// CHECK-LE: call<2 x i64> @llvm.ctlz.v2i64(<2 x i64> %{{.+}}, i1 false)
name|res_vull
operator|=
name|vec_cntlz
argument_list|(
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x i64> @llvm.ctlz.v2i64(<2 x i64> %{{.+}}, i1 false)
comment|// CHECK-LE: call<2 x i64> @llvm.ctlz.v2i64(<2 x i64> %{{.+}}, i1 false)
comment|/* ----------------------- predicates --------------------------- */
comment|/* vec_all_eq */
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-PPC: error: call to 'vec_all_eq' is ambiguous
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vsll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-PPC: error: call to 'vec_all_eq' is ambiguous
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-PPC: error: call to 'vec_all_eq' is ambiguous
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vull
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-PPC: error: call to 'vec_all_eq' is ambiguous
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vbll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-PPC: error: call to 'vec_all_eq' is ambiguous
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vbll
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-PPC: error: call to 'vec_all_eq' is ambiguous
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vbll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-PPC: error: call to 'vec_all_eq' is ambiguous
name|res_i
operator|=
name|vec_all_eq
argument_list|(
name|vda
argument_list|,
name|vda
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.xvcmpeqdp.p
comment|// CHECK-LE: @llvm.ppc.vsx.xvcmpeqdp.p
comment|/* vec_all_ne */
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-PPC: error: call to 'vec_all_ne' is ambiguous
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vsll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-PPC: error: call to 'vec_all_ne' is ambiguous
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-PPC: error: call to 'vec_all_ne' is ambiguous
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vull
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-PPC: error: call to 'vec_all_ne' is ambiguous
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vbll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-PPC: error: call to 'vec_all_ne' is ambiguous
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vbll
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-PPC: error: call to 'vec_all_ne' is ambiguous
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vbll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-PPC: error: call to 'vec_all_ne' is ambiguous
name|dummy
argument_list|()
expr_stmt|;
comment|// CHECK: @dummy
name|res_i
operator|=
name|vec_all_ne
argument_list|(
name|vda
argument_list|,
name|vda
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.xvcmpeqdp.p
comment|// CHECK-LE: @llvm.ppc.vsx.xvcmpeqdp.p
name|dummy
argument_list|()
expr_stmt|;
comment|// CHECK: @dummy
name|res_i
operator|=
name|vec_all_nge
argument_list|(
name|vda
argument_list|,
name|vda
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.xvcmpgedp.p
comment|// CHECK-LE: @llvm.ppc.vsx.xvcmpgedp.p
name|res_i
operator|=
name|vec_all_ngt
argument_list|(
name|vda
argument_list|,
name|vda
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.xvcmpgtdp.p
comment|// CHECK-LE: @llvm.ppc.vsx.xvcmpgtdp.p
comment|/* vec_any_eq */
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-PPC: error: call to 'vec_any_eq' is ambiguous
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vsll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-PPC: error: call to 'vec_any_eq' is ambiguous
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-PPC: error: call to 'vec_any_eq' is ambiguous
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vull
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-PPC: error: call to 'vec_any_eq' is ambiguous
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vbll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-PPC: error: call to 'vec_any_eq' is ambiguous
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vbll
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-PPC: error: call to 'vec_any_eq' is ambiguous
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vbll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-PPC: error: call to 'vec_any_eq' is ambiguous
name|res_i
operator|=
name|vec_any_eq
argument_list|(
name|vda
argument_list|,
name|vda
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.xvcmpeqdp.p
comment|// CHECK-LE: @llvm.ppc.vsx.xvcmpeqdp.p
comment|/* vec_any_ne */
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-PPC: error: call to 'vec_any_ne' is ambiguous
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vsll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-PPC: error: call to 'vec_any_ne' is ambiguous
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-PPC: error: call to 'vec_any_ne' is ambiguous
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vull
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-PPC: error: call to 'vec_any_ne' is ambiguous
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vbll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-PPC: error: call to 'vec_any_ne' is ambiguous
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vbll
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-PPC: error: call to 'vec_any_ne' is ambiguous
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vbll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpequd.p
comment|// CHECK-PPC: error: call to 'vec_any_ne' is ambiguous
name|res_i
operator|=
name|vec_any_ne
argument_list|(
name|vda
argument_list|,
name|vda
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.xvcmpeqdp.p
comment|// CHECK-LE: @llvm.ppc.vsx.xvcmpeqdp.p
comment|/* vec_all_ge */
name|res_i
operator|=
name|vec_all_ge
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-PPC: error: call to 'vec_all_ge' is ambiguous
name|res_i
operator|=
name|vec_all_ge
argument_list|(
name|vsll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-PPC: error: call to 'vec_all_ge' is ambiguous
name|res_i
operator|=
name|vec_all_ge
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_all_ge' is ambiguous
name|res_i
operator|=
name|vec_all_ge
argument_list|(
name|vull
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_all_ge' is ambiguous
name|res_i
operator|=
name|vec_all_ge
argument_list|(
name|vbll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_all_ge' is ambiguous
name|res_i
operator|=
name|vec_all_ge
argument_list|(
name|vbll
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_all_ge' is ambiguous
name|res_i
operator|=
name|vec_all_ge
argument_list|(
name|vbll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_all_ge' is ambiguous
name|res_i
operator|=
name|vec_all_ge
argument_list|(
name|vda
argument_list|,
name|vda
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.xvcmpgedp.p
comment|// CHECK-LE: @llvm.ppc.vsx.xvcmpgedp.p
comment|/* vec_all_gt */
name|res_i
operator|=
name|vec_all_gt
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-PPC: error: call to 'vec_all_gt' is ambiguous
name|res_i
operator|=
name|vec_all_gt
argument_list|(
name|vsll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-PPC: error: call to 'vec_all_gt' is ambiguous
name|res_i
operator|=
name|vec_all_gt
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_all_gt' is ambiguous
name|res_i
operator|=
name|vec_all_gt
argument_list|(
name|vull
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_all_gt' is ambiguous
name|res_i
operator|=
name|vec_all_gt
argument_list|(
name|vbll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_all_gt' is ambiguous
name|res_i
operator|=
name|vec_all_gt
argument_list|(
name|vbll
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_all_gt' is ambiguous
name|res_i
operator|=
name|vec_all_gt
argument_list|(
name|vbll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_all_gt' is ambiguous
name|res_i
operator|=
name|vec_all_gt
argument_list|(
name|vda
argument_list|,
name|vda
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.xvcmpgtdp.p
comment|// CHECK-LE: @llvm.ppc.vsx.xvcmpgtdp.p
comment|/* vec_all_le */
name|res_i
operator|=
name|vec_all_le
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-PPC: error: call to 'vec_all_le' is ambiguous
name|res_i
operator|=
name|vec_all_le
argument_list|(
name|vsll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-PPC: error: call to 'vec_all_le' is ambiguous
name|res_i
operator|=
name|vec_all_le
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_all_le' is ambiguous
name|res_i
operator|=
name|vec_all_le
argument_list|(
name|vull
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_all_le' is ambiguous
name|res_i
operator|=
name|vec_all_le
argument_list|(
name|vbll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_all_le' is ambiguous
name|res_i
operator|=
name|vec_all_le
argument_list|(
name|vbll
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_all_le' is ambiguous
name|res_i
operator|=
name|vec_all_le
argument_list|(
name|vbll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_all_le' is ambiguous
name|res_i
operator|=
name|vec_all_le
argument_list|(
name|vda
argument_list|,
name|vda
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.xvcmpgedp.p
comment|// CHECK-LE: @llvm.ppc.vsx.xvcmpgedp.p
comment|/* vec_all_lt */
name|res_i
operator|=
name|vec_all_lt
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-PPC: error: call to 'vec_all_lt' is ambiguous
name|res_i
operator|=
name|vec_all_lt
argument_list|(
name|vsll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-PPC: error: call to 'vec_all_lt' is ambiguous
name|res_i
operator|=
name|vec_all_lt
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_all_lt' is ambiguous
name|res_i
operator|=
name|vec_all_lt
argument_list|(
name|vull
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_all_lt' is ambiguous
name|res_i
operator|=
name|vec_all_lt
argument_list|(
name|vbll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_all_lt' is ambiguous
name|res_i
operator|=
name|vec_all_lt
argument_list|(
name|vbll
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_all_lt' is ambiguous
name|res_i
operator|=
name|vec_all_lt
argument_list|(
name|vbll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_all_lt' is ambiguous
name|res_i
operator|=
name|vec_all_lt
argument_list|(
name|vda
argument_list|,
name|vda
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.xvcmpgtdp.p
comment|// CHECK-LE: @llvm.ppc.vsx.xvcmpgtdp.p
name|res_i
operator|=
name|vec_all_nan
argument_list|(
name|vda
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.xvcmpeqdp.p
comment|// CHECK-LE: @llvm.ppc.vsx.xvcmpeqdp.p
comment|/* vec_any_ge */
name|res_i
operator|=
name|vec_any_ge
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-PPC: error: call to 'vec_any_ge' is ambiguous
name|res_i
operator|=
name|vec_any_ge
argument_list|(
name|vsll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-PPC: error: call to 'vec_any_ge' is ambiguous
name|res_i
operator|=
name|vec_any_ge
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_any_ge' is ambiguous
name|res_i
operator|=
name|vec_any_ge
argument_list|(
name|vull
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_any_ge' is ambiguous
name|res_i
operator|=
name|vec_any_ge
argument_list|(
name|vbll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_any_ge' is ambiguous
name|res_i
operator|=
name|vec_any_ge
argument_list|(
name|vbll
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_any_ge' is ambiguous
name|res_i
operator|=
name|vec_any_ge
argument_list|(
name|vbll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_any_ge' is ambiguous
name|res_i
operator|=
name|vec_any_ge
argument_list|(
name|vda
argument_list|,
name|vda
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.xvcmpgedp.p
comment|// CHECK-LE: @llvm.ppc.vsx.xvcmpgedp.p
comment|/* vec_any_gt */
name|res_i
operator|=
name|vec_any_gt
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-PPC: error: call to 'vec_any_gt' is ambiguous
name|res_i
operator|=
name|vec_any_gt
argument_list|(
name|vsll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-PPC: error: call to 'vec_any_gt' is ambiguous
name|res_i
operator|=
name|vec_any_gt
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_any_gt' is ambiguous
name|res_i
operator|=
name|vec_any_gt
argument_list|(
name|vull
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_any_gt' is ambiguous
name|res_i
operator|=
name|vec_any_gt
argument_list|(
name|vbll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_any_gt' is ambiguous
name|res_i
operator|=
name|vec_any_gt
argument_list|(
name|vbll
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_any_gt' is ambiguous
name|res_i
operator|=
name|vec_any_gt
argument_list|(
name|vbll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_any_gt' is ambiguous
name|res_i
operator|=
name|vec_any_gt
argument_list|(
name|vda
argument_list|,
name|vda
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.xvcmpgtdp.p
comment|// CHECK-LE: @llvm.ppc.vsx.xvcmpgtdp.p
comment|/* vec_any_le */
name|res_i
operator|=
name|vec_any_le
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-PPC: error: call to 'vec_any_le' is ambiguous
name|res_i
operator|=
name|vec_any_le
argument_list|(
name|vsll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-PPC: error: call to 'vec_any_le' is ambiguous
name|res_i
operator|=
name|vec_any_le
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_any_le' is ambiguous
name|res_i
operator|=
name|vec_any_le
argument_list|(
name|vull
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_any_le' is ambiguous
name|res_i
operator|=
name|vec_any_le
argument_list|(
name|vbll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_any_le' is ambiguous
name|res_i
operator|=
name|vec_any_le
argument_list|(
name|vbll
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_any_le' is ambiguous
name|res_i
operator|=
name|vec_any_le
argument_list|(
name|vbll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_any_le' is ambiguous
name|res_i
operator|=
name|vec_any_le
argument_list|(
name|vda
argument_list|,
name|vda
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.xvcmpgedp.p
comment|// CHECK-LE: @llvm.ppc.vsx.xvcmpgedp.p
comment|/* vec_any_lt */
name|res_i
operator|=
name|vec_any_lt
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-PPC: error: call to 'vec_any_lt' is ambiguous
name|res_i
operator|=
name|vec_any_lt
argument_list|(
name|vsll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtsd.p
comment|// CHECK-PPC: error: call to 'vec_any_lt' is ambiguous
name|res_i
operator|=
name|vec_any_lt
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_any_lt' is ambiguous
name|res_i
operator|=
name|vec_any_lt
argument_list|(
name|vull
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_any_lt' is ambiguous
name|res_i
operator|=
name|vec_any_lt
argument_list|(
name|vbll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_any_lt' is ambiguous
name|res_i
operator|=
name|vec_any_lt
argument_list|(
name|vbll
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_any_lt' is ambiguous
name|res_i
operator|=
name|vec_any_lt
argument_list|(
name|vbll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-LE: @llvm.ppc.altivec.vcmpgtud.p
comment|// CHECK-PPC: error: call to 'vec_any_lt' is ambiguous
name|res_i
operator|=
name|vec_any_lt
argument_list|(
name|vda
argument_list|,
name|vda
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.xvcmpgtdp.p
comment|// CHECK-LE: @llvm.ppc.vsx.xvcmpgtdp.p
comment|/* vec_max */
name|res_vsll
operator|=
name|vec_max
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxsd
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxsd
comment|// CHECK-PPC: error: call to 'vec_max' is ambiguous
name|res_vsll
operator|=
name|vec_max
argument_list|(
name|vbll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxsd
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxsd
comment|// CHECK-PPC: error: call to 'vec_max' is ambiguous
name|res_vsll
operator|=
name|vec_max
argument_list|(
name|vsll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxsd
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxsd
comment|// CHECK-PPC: error: call to 'vec_max' is ambiguous
name|res_vull
operator|=
name|vec_max
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxud
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxud
comment|// CHECK-PPC: error: call to 'vec_max' is ambiguous
name|res_vull
operator|=
name|vec_max
argument_list|(
name|vbll
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxud
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxud
comment|// CHECK-PPC: error: call to 'vec_max' is ambiguous
name|res_vull
operator|=
name|vec_max
argument_list|(
name|vull
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxud
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxud
comment|// CHECK-PPC: error: call to 'vec_max' is ambiguous
comment|/* vec_mergeh */
name|res_vbll
operator|=
name|vec_mergeh
argument_list|(
name|vbll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbll
operator|=
name|vec_mergel
argument_list|(
name|vbll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|/* vec_min */
name|res_vsll
operator|=
name|vec_min
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminsd
comment|// CHECK-LE: @llvm.ppc.altivec.vminsd
comment|// CHECK-PPC: error: call to 'vec_min' is ambiguous
name|res_vsll
operator|=
name|vec_min
argument_list|(
name|vbll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminsd
comment|// CHECK-LE: @llvm.ppc.altivec.vminsd
comment|// CHECK-PPC: error: call to 'vec_min' is ambiguous
name|res_vsll
operator|=
name|vec_min
argument_list|(
name|vsll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminsd
comment|// CHECK-LE: @llvm.ppc.altivec.vminsd
comment|// CHECK-PPC: error: call to 'vec_min' is ambiguous
name|res_vull
operator|=
name|vec_min
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminud
comment|// CHECK-LE: @llvm.ppc.altivec.vminud
comment|// CHECK-PPC: error: call to 'vec_min' is ambiguous
name|res_vull
operator|=
name|vec_min
argument_list|(
name|vbll
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminud
comment|// CHECK-LE: @llvm.ppc.altivec.vminud
comment|// CHECK-PPC: error: call to 'vec_min' is ambiguous
name|res_vull
operator|=
name|vec_min
argument_list|(
name|vull
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminud
comment|// CHECK-LE: @llvm.ppc.altivec.vminud
comment|// CHECK-PPC: error: call to 'vec_min' is ambiguous
comment|/* vec_mule */
name|res_vsll
operator|=
name|vec_mule
argument_list|(
name|vsi
argument_list|,
name|vsi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmulesw
comment|// CHECK-LE: @llvm.ppc.altivec.vmulosw
comment|// CHECK-PPC: error: call to 'vec_mule' is ambiguous
name|res_vull
operator|=
name|vec_mule
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmuleuw
comment|// CHECK-LE: @llvm.ppc.altivec.vmulouw
comment|// CHECK-PPC: error: call to 'vec_mule' is ambiguous
comment|/* vec_mulo */
name|res_vsll
operator|=
name|vec_mulo
argument_list|(
name|vsi
argument_list|,
name|vsi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmulosw
comment|// CHECK-LE: @llvm.ppc.altivec.vmulesw
comment|// CHECK-PPC: error: call to 'vec_mulo' is ambiguous
name|res_vull
operator|=
name|vec_mulo
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmulouw
comment|// CHECK-LE: @llvm.ppc.altivec.vmuleuw
comment|// CHECK-PPC: error: call to 'vec_mulo' is ambiguous
comment|/* vec_packs */
name|res_vsi
operator|=
name|vec_packs
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vpksdss
comment|// CHECK-LE: @llvm.ppc.altivec.vpksdss
comment|// CHECK-PPC: error: call to 'vec_packs' is ambiguous
name|res_vui
operator|=
name|vec_packs
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vpkudus
comment|// CHECK-LE: @llvm.ppc.altivec.vpkudus
comment|// CHECK-PPC: error: call to 'vec_packs' is ambiguous
comment|/* vec_packsu */
name|res_vui
operator|=
name|vec_packsu
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vpksdus
comment|// CHECK-LE: @llvm.ppc.altivec.vpksdus
comment|// CHECK-PPC: error: call to 'vec_packsu' is ambiguous
name|res_vui
operator|=
name|vec_packsu
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vpkudus
comment|// CHECK-LE: @llvm.ppc.altivec.vpkudus
comment|// CHECK-PPC: error: call to 'vec_packsu' is ambiguous
comment|/* vec_rl */
name|res_vsll
operator|=
name|vec_rl
argument_list|(
name|vsll
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrld
comment|// CHECK-LE: @llvm.ppc.altivec.vrld
comment|// CHECK-PPC: error: call to 'vec_rl' is ambiguous
name|res_vull
operator|=
name|vec_rl
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vrld
comment|// CHECK-LE: @llvm.ppc.altivec.vrld
comment|// CHECK-PPC: error: call to 'vec_rl' is ambiguous
comment|/* vec_sl */
name|res_vsll
operator|=
name|vec_sl
argument_list|(
name|vsll
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: shl<2 x i64>
comment|// CHECK-LE: shl<2 x i64>
comment|// CHECK-PPC: error: call to 'vec_sl' is ambiguous
name|res_vull
operator|=
name|vec_sl
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: shl<2 x i64>
comment|// CHECK-LE: shl<2 x i64>
comment|// CHECK-PPC: error: call to 'vec_sl' is ambiguous
comment|/* vec_sr */
name|res_vsll
operator|=
name|vec_sr
argument_list|(
name|vsll
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: lshr<2 x i64>
comment|// CHECK-LE: lshr<2 x i64>
comment|// CHECK-PPC: error: call to 'vec_sr' is ambiguous
name|res_vull
operator|=
name|vec_sr
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: lshr<2 x i64>
comment|// CHECK-LE: lshr<2 x i64>
comment|// CHECK-PPC: error: call to 'vec_sr' is ambiguous
comment|/* vec_sra */
name|res_vsll
operator|=
name|vec_sra
argument_list|(
name|vsll
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: ashr<2 x i64>
comment|// CHECK-LE: ashr<2 x i64>
comment|// CHECK-PPC: error: call to 'vec_sra' is ambiguous
name|res_vull
operator|=
name|vec_sra
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: ashr<2 x i64>
comment|// CHECK-LE: ashr<2 x i64>
comment|// CHECK-PPC: error: call to 'vec_sra' is ambiguous
comment|/* vec_splats */
name|res_vsll
operator|=
name|vec_splats
argument_list|(
name|sll
argument_list|)
expr_stmt|;
comment|// CHECK: insertelement<2 x i64>
comment|// CHECK-LE: insertelement<2 x i64>
name|res_vull
operator|=
name|vec_splats
argument_list|(
name|ull
argument_list|)
expr_stmt|;
comment|// CHECK: insertelement<2 x i64>
comment|// CHECK-LE: insertelement<2 x i64>
name|res_vsx
operator|=
name|vec_splats
argument_list|(
name|sx
argument_list|)
expr_stmt|;
comment|// CHECK: insertelement<1 x i128>
comment|// CHECK-LE: insertelement<1 x i128>
name|res_vux
operator|=
name|vec_splats
argument_list|(
name|ux
argument_list|)
expr_stmt|;
comment|// CHECK: insertelement<1 x i128>
comment|// CHECK-LE: insertelement<1 x i128>
name|res_vd
operator|=
name|vec_splats
argument_list|(
name|d
argument_list|)
expr_stmt|;
comment|// CHECK: insertelement<2 x double>
comment|// CHECK-LE: insertelement<2 x double>
comment|/* vec_unpackh */
name|res_vsll
operator|=
name|vec_unpackh
argument_list|(
name|vsi
argument_list|)
expr_stmt|;
comment|// CHECK: llvm.ppc.altivec.vupkhsw
comment|// CHECK-LE: llvm.ppc.altivec.vupklsw
comment|// CHECK-PPC: error: call to 'vec_unpackh' is ambiguous
name|res_vbll
operator|=
name|vec_unpackh
argument_list|(
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: llvm.ppc.altivec.vupkhsw
comment|// CHECK-LE: llvm.ppc.altivec.vupklsw
comment|// CHECK-PPC: error: call to 'vec_unpackh' is ambiguous
comment|/* vec_unpackl */
name|res_vsll
operator|=
name|vec_unpackl
argument_list|(
name|vsi
argument_list|)
expr_stmt|;
comment|// CHECK: llvm.ppc.altivec.vupklsw
comment|// CHECK-LE: llvm.ppc.altivec.vupkhsw
comment|// CHECK-PPC: error: call to 'vec_unpackl' is ambiguous
name|res_vbll
operator|=
name|vec_unpackl
argument_list|(
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: llvm.ppc.altivec.vupklsw
comment|// CHECK-LE: llvm.ppc.altivec.vupkhsw
comment|// CHECK-PPC: error: call to 'vec_unpackl' is ambiguous
comment|/* vec_vpksdss */
name|res_vsi
operator|=
name|vec_vpksdss
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: llvm.ppc.altivec.vpksdss
comment|// CHECK-LE: llvm.ppc.altivec.vpksdss
comment|// CHECK-PPC: warning: implicit declaration of function 'vec_vpksdss'
comment|/* vec_vpksdus */
name|res_vui
operator|=
name|vec_vpksdus
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: llvm.ppc.altivec.vpksdus
comment|// CHECK-LE: llvm.ppc.altivec.vpksdus
comment|// CHECK-PPC: warning: implicit declaration of function 'vec_vpksdus'
comment|/* vec_vpkudum */
name|res_vsi
operator|=
name|vec_vpkudum
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: vperm
comment|// CHECK-LE: vperm
comment|// CHECK-PPC: warning: implicit declaration of function 'vec_vpkudum'
name|res_vui
operator|=
name|vec_vpkudum
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: vperm
comment|// CHECK-LE: vperm
name|res_vui
operator|=
name|vec_vpkudus
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: llvm.ppc.altivec.vpkudus
comment|// CHECK-LE: llvm.ppc.altivec.vpkudus
comment|// CHECK-PPC: warning: implicit declaration of function 'vec_vpkudus'
comment|/* vec_vupkhsw */
name|res_vsll
operator|=
name|vec_vupkhsw
argument_list|(
name|vsi
argument_list|)
expr_stmt|;
comment|// CHECK: llvm.ppc.altivec.vupkhsw
comment|// CHECK-LE: llvm.ppc.altivec.vupklsw
comment|// CHECK-PPC: warning: implicit declaration of function 'vec_vupkhsw'
name|res_vbll
operator|=
name|vec_vupkhsw
argument_list|(
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: llvm.ppc.altivec.vupkhsw
comment|// CHECK-LE: llvm.ppc.altivec.vupklsw
comment|/* vec_vupklsw */
name|res_vsll
operator|=
name|vec_vupklsw
argument_list|(
name|vsi
argument_list|)
expr_stmt|;
comment|// CHECK: llvm.ppc.altivec.vupklsw
comment|// CHECK-LE: llvm.ppc.altivec.vupkhsw
comment|// CHECK-PPC: warning: implicit declaration of function 'vec_vupklsw'
name|res_vbll
operator|=
name|vec_vupklsw
argument_list|(
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: llvm.ppc.altivec.vupklsw
comment|// CHECK-LE: llvm.ppc.altivec.vupkhsw
comment|/* vec_max */
name|res_vsll
operator|=
name|vec_max
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxsd
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxsd
name|res_vsll
operator|=
name|vec_max
argument_list|(
name|vbll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxsd
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxsd
name|res_vsll
operator|=
name|vec_max
argument_list|(
name|vsll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxsd
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxsd
name|res_vull
operator|=
name|vec_max
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxud
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxud
name|res_vull
operator|=
name|vec_max
argument_list|(
name|vbll
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vmaxud
comment|// CHECK-LE: @llvm.ppc.altivec.vmaxud
comment|/* vec_min */
name|res_vsll
operator|=
name|vec_min
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminsd
comment|// CHECK-LE: @llvm.ppc.altivec.vminsd
name|res_vsll
operator|=
name|vec_min
argument_list|(
name|vbll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminsd
comment|// CHECK-LE: @llvm.ppc.altivec.vminsd
name|res_vsll
operator|=
name|vec_min
argument_list|(
name|vsll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminsd
comment|// CHECK-LE: @llvm.ppc.altivec.vminsd
name|res_vull
operator|=
name|vec_min
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminud
comment|// CHECK-LE: @llvm.ppc.altivec.vminud
name|res_vull
operator|=
name|vec_min
argument_list|(
name|vbll
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vminud
comment|// CHECK-LE: @llvm.ppc.altivec.vminud
comment|/* vec_nand */
name|res_vsc
operator|=
name|vec_nand
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = and<16 x i8>
comment|// CHECK: xor<16 x i8> [[T1]],<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
comment|// CHECK-LE: [[T1:%.+]] = and<16 x i8>
comment|// CHECK-LE: xor<16 x i8> [[T1]],<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
comment|// CHECK-PPC: warning: implicit declaration of function 'vec_nand' is invalid in C99
name|res_vsc
operator|=
name|vec_nand
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = and<16 x i8>
comment|// CHECK: xor<16 x i8> [[T1]],<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
comment|// CHECK-LE: [[T1:%.+]] = and<16 x i8>
comment|// CHECK-LE: xor<16 x i8> [[T1]],<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
name|res_vuc
operator|=
name|vec_nand
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = and<16 x i8>
comment|// CHECK: xor<16 x i8> [[T1]],<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
comment|// CHECK-LE: [[T1:%.+]] = and<16 x i8>
comment|// CHECK-LE: xor<16 x i8> [[T1]],<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
name|res_vss
operator|=
name|vec_nand
argument_list|(
name|vss
argument_list|,
name|vss
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = and<8 x i16>
comment|// CHECK: xor<8 x i16> [[T1]],<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
comment|// CHECK-LE: [[T1:%.+]] = and<8 x i16>
comment|// CHECK-LE: xor<8 x i16> [[T1]],<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
name|res_vss
operator|=
name|vec_nand
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = and<8 x i16>
comment|// CHECK: xor<8 x i16> [[T1]],<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
comment|// CHECK-LE: [[T1:%.+]] = and<8 x i16>
comment|// CHECK-LE: xor<8 x i16> [[T1]],<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
name|res_vus
operator|=
name|vec_nand
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = and<8 x i16>
comment|// CHECK: xor<8 x i16> [[T1]],<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
comment|// CHECK-LE: [[T1:%.+]] = and<8 x i16>
comment|// CHECK-LE: xor<8 x i16> [[T1]],<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
name|res_vsi
operator|=
name|vec_nand
argument_list|(
name|vsi
argument_list|,
name|vsi
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = and<4 x i32>
comment|// CHECK: xor<4 x i32> [[T1]],<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK-LE: [[T1:%.+]] = and<4 x i32>
comment|// CHECK-LE: xor<4 x i32> [[T1]],<i32 -1, i32 -1, i32 -1, i32 -1>
name|res_vsi
operator|=
name|vec_nand
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = and<4 x i32>
comment|// CHECK: xor<4 x i32> [[T1]],<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK-LE: [[T1:%.+]] = and<4 x i32>
comment|// CHECK-LE: xor<4 x i32> [[T1]],<i32 -1, i32 -1, i32 -1, i32 -1>
name|res_vui
operator|=
name|vec_nand
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = and<4 x i32>
comment|// CHECK: xor<4 x i32> [[T1]],<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK-LE: [[T1:%.+]] = and<4 x i32>
comment|// CHECK-LE: xor<4 x i32> [[T1]],<i32 -1, i32 -1, i32 -1, i32 -1>
name|res_vf
operator|=
name|vec_nand
argument_list|(
name|vfa
argument_list|,
name|vfa
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = and<4 x i32>
comment|// CHECK: xor<4 x i32> [[T1]],<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK-LE: [[T1:%.+]] = and<4 x i32>
comment|// CHECK-LE: xor<4 x i32> [[T1]],<i32 -1, i32 -1, i32 -1, i32 -1>
name|res_vsll
operator|=
name|vec_nand
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = and<2 x i64>
comment|// CHECK: xor<2 x i64> [[T1]],<i64 -1, i64 -1>
comment|// CHECK-LE: [[T1:%.+]] = and<2 x i64>
comment|// CHECK-LE: xor<2 x i64> [[T1]],<i64 -1, i64 -1>
name|res_vsll
operator|=
name|vec_nand
argument_list|(
name|vbll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = and<2 x i64>
comment|// CHECK: xor<2 x i64> [[T1]],<i64 -1, i64 -1>
comment|// CHECK-LE: [[T1:%.+]] = and<2 x i64>
comment|// CHECK-LE: xor<2 x i64> [[T1]],<i64 -1, i64 -1>
name|res_vull
operator|=
name|vec_nand
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = and<2 x i64>
comment|// CHECK: xor<2 x i64> [[T1]],<i64 -1, i64 -1>
comment|// CHECK-LE: [[T1:%.+]] = and<2 x i64>
comment|// CHECK-LE: xor<2 x i64> [[T1]],<i64 -1, i64 -1>
name|res_vd
operator|=
name|vec_nand
argument_list|(
name|vda
argument_list|,
name|vda
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = and<2 x i64>
comment|// CHECK: xor<2 x i64> [[T1]],<i64 -1, i64 -1>
comment|// CHECK-LE: [[T1:%.+]] = and<2 x i64>
comment|// CHECK-LE: xor<2 x i64> [[T1]],<i64 -1, i64 -1>
comment|/* vec_orc */
name|res_vsc
operator|=
name|vec_orc
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<16 x i8> {{%.+}},<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
comment|// CHECK: or<16 x i8> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<16 x i8> {{%.+}},<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
comment|// CHECK-LE: or<16 x i8> {{%.+}}, [[T1]]
comment|// CHECK-PPC: warning: implicit declaration of function 'vec_orc' is invalid in C99
name|res_vsc
operator|=
name|vec_orc
argument_list|(
name|vsc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<16 x i8> {{%.+}},<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
comment|// CHECK: or<16 x i8> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<16 x i8> {{%.+}},<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
comment|// CHECK-LE: or<16 x i8> {{%.+}}, [[T1]]
name|res_vsc
operator|=
name|vec_orc
argument_list|(
name|vbc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<16 x i8> {{%.+}},<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
comment|// CHECK: or<16 x i8> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<16 x i8> {{%.+}},<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
comment|// CHECK-LE: or<16 x i8> {{%.+}}, [[T1]]
name|res_vuc
operator|=
name|vec_orc
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<16 x i8> {{%.+}},<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
comment|// CHECK: or<16 x i8> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<16 x i8> {{%.+}},<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
comment|// CHECK-LE: or<16 x i8> {{%.+}}, [[T1]]
name|res_vuc
operator|=
name|vec_orc
argument_list|(
name|vuc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<16 x i8> {{%.+}},<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
comment|// CHECK: or<16 x i8> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<16 x i8> {{%.+}},<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
comment|// CHECK-LE: or<16 x i8> {{%.+}}, [[T1]]
name|res_vuc
operator|=
name|vec_orc
argument_list|(
name|vbc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<16 x i8> {{%.+}},<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
comment|// CHECK: or<16 x i8> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<16 x i8> {{%.+}},<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
comment|// CHECK-LE: or<16 x i8> {{%.+}}, [[T1]]
name|res_vbc
operator|=
name|vec_orc
argument_list|(
name|vbc
argument_list|,
name|vbc
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<16 x i8> {{%.+}},<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
comment|// CHECK: or<16 x i8> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<16 x i8> {{%.+}},<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
comment|// CHECK-LE: or<16 x i8> {{%.+}}, [[T1]]
name|res_vss
operator|=
name|vec_orc
argument_list|(
name|vss
argument_list|,
name|vss
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<8 x i16> {{%.+}},<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
comment|// CHECK: or<8 x i16> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<8 x i16> {{%.+}},<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
comment|// CHECK-LE: or<8 x i16> {{%.+}}, [[T1]]
name|res_vss
operator|=
name|vec_orc
argument_list|(
name|vss
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<8 x i16> {{%.+}},<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
comment|// CHECK: or<8 x i16> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<8 x i16> {{%.+}},<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
comment|// CHECK-LE: or<8 x i16> {{%.+}}, [[T1]]
name|res_vss
operator|=
name|vec_orc
argument_list|(
name|vbs
argument_list|,
name|vss
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<8 x i16> {{%.+}},<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
comment|// CHECK: or<8 x i16> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<8 x i16> {{%.+}},<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
comment|// CHECK-LE: or<8 x i16> {{%.+}}, [[T1]]
name|res_vus
operator|=
name|vec_orc
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<8 x i16> {{%.+}},<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
comment|// CHECK: or<8 x i16> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<8 x i16> {{%.+}},<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
comment|// CHECK-LE: or<8 x i16> {{%.+}}, [[T1]]
name|res_vus
operator|=
name|vec_orc
argument_list|(
name|vus
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<8 x i16> {{%.+}},<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
comment|// CHECK: or<8 x i16> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<8 x i16> {{%.+}},<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
comment|// CHECK-LE: or<8 x i16> {{%.+}}, [[T1]]
name|res_vus
operator|=
name|vec_orc
argument_list|(
name|vbs
argument_list|,
name|vus
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<8 x i16> {{%.+}},<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
comment|// CHECK: or<8 x i16> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<8 x i16> {{%.+}},<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
comment|// CHECK-LE: or<8 x i16> {{%.+}}, [[T1]]
name|res_vbs
operator|=
name|vec_orc
argument_list|(
name|vbs
argument_list|,
name|vbs
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<8 x i16> {{%.+}},<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
comment|// CHECK: or<8 x i16> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<8 x i16> {{%.+}},<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
comment|// CHECK-LE: or<8 x i16> {{%.+}}, [[T1]]
name|res_vsi
operator|=
name|vec_orc
argument_list|(
name|vsi
argument_list|,
name|vsi
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<4 x i32> {{%.+}},<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK: or<4 x i32> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<4 x i32> {{%.+}},<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK-LE: or<4 x i32> {{%.+}}, [[T1]]
name|res_vsi
operator|=
name|vec_orc
argument_list|(
name|vsi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<4 x i32> {{%.+}},<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK: or<4 x i32> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<4 x i32> {{%.+}},<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK-LE: or<4 x i32> {{%.+}}, [[T1]]
name|res_vsi
operator|=
name|vec_orc
argument_list|(
name|vbi
argument_list|,
name|vsi
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<4 x i32> {{%.+}},<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK: or<4 x i32> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<4 x i32> {{%.+}},<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK-LE: or<4 x i32> {{%.+}}, [[T1]]
name|res_vui
operator|=
name|vec_orc
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<4 x i32> {{%.+}},<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK: or<4 x i32> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<4 x i32> {{%.+}},<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK-LE: or<4 x i32> {{%.+}}, [[T1]]
name|res_vui
operator|=
name|vec_orc
argument_list|(
name|vui
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<4 x i32> {{%.+}},<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK: or<4 x i32> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<4 x i32> {{%.+}},<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK-LE: or<4 x i32> {{%.+}}, [[T1]]
name|res_vui
operator|=
name|vec_orc
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<4 x i32> {{%.+}},<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK: or<4 x i32> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<4 x i32> {{%.+}},<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK-LE: or<4 x i32> {{%.+}}, [[T1]]
name|res_vbi
operator|=
name|vec_orc
argument_list|(
name|vbi
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<4 x i32> {{%.+}},<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK: or<4 x i32> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<4 x i32> {{%.+}},<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK-LE: or<4 x i32> {{%.+}}, [[T1]]
name|res_vf
operator|=
name|vec_orc
argument_list|(
name|vbi
argument_list|,
name|vfa
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<4 x i32> {{%.+}},<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK: or<4 x i32> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<4 x i32> {{%.+}},<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK-LE: or<4 x i32> {{%.+}}, [[T1]]
name|res_vf
operator|=
name|vec_orc
argument_list|(
name|vfa
argument_list|,
name|vbi
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<4 x i32> {{%.+}},<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK: or<4 x i32> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<4 x i32> {{%.+}},<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK-LE: or<4 x i32> {{%.+}}, [[T1]]
name|res_vsll
operator|=
name|vec_orc
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<2 x i64> {{%.+}},<i64 -1, i64 -1>
comment|// CHECK: or<2 x i64> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<2 x i64> {{%.+}},<i64 -1, i64 -1>
comment|// CHECK-LE: or<2 x i64> {{%.+}}, [[T1]]
name|res_vsll
operator|=
name|vec_orc
argument_list|(
name|vsll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<2 x i64> {{%.+}},<i64 -1, i64 -1>
comment|// CHECK: or<2 x i64> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<2 x i64> {{%.+}},<i64 -1, i64 -1>
comment|// CHECK-LE: or<2 x i64> {{%.+}}, [[T1]]
name|res_vsll
operator|=
name|vec_orc
argument_list|(
name|vbll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<2 x i64> {{%.+}},<i64 -1, i64 -1>
comment|// CHECK: or<2 x i64> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<2 x i64> {{%.+}},<i64 -1, i64 -1>
comment|// CHECK-LE: or<2 x i64> {{%.+}}, [[T1]]
name|res_vull
operator|=
name|vec_orc
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<2 x i64> {{%.+}},<i64 -1, i64 -1>
comment|// CHECK: or<2 x i64> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<2 x i64> {{%.+}},<i64 -1, i64 -1>
comment|// CHECK-LE: or<2 x i64> {{%.+}}, [[T1]]
name|res_vull
operator|=
name|vec_orc
argument_list|(
name|vull
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<2 x i64> {{%.+}},<i64 -1, i64 -1>
comment|// CHECK: or<2 x i64> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<2 x i64> {{%.+}},<i64 -1, i64 -1>
comment|// CHECK-LE: or<2 x i64> {{%.+}}, [[T1]]
name|res_vull
operator|=
name|vec_orc
argument_list|(
name|vbll
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<2 x i64> {{%.+}},<i64 -1, i64 -1>
comment|// CHECK: or<2 x i64> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<2 x i64> {{%.+}},<i64 -1, i64 -1>
comment|// CHECK-LE: or<2 x i64> {{%.+}}, [[T1]]
name|res_vbll
operator|=
name|vec_orc
argument_list|(
name|vbll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<2 x i64> {{%.+}},<i64 -1, i64 -1>
comment|// CHECK: or<2 x i64> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<2 x i64> {{%.+}},<i64 -1, i64 -1>
comment|// CHECK-LE: or<2 x i64> {{%.+}}, [[T1]]
name|res_vd
operator|=
name|vec_orc
argument_list|(
name|vbll
argument_list|,
name|vda
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<2 x i64> {{%.+}},<i64 -1, i64 -1>
comment|// CHECK: or<2 x i64> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<2 x i64> {{%.+}},<i64 -1, i64 -1>
comment|// CHECK-LE: or<2 x i64> {{%.+}}, [[T1]]
name|res_vd
operator|=
name|vec_orc
argument_list|(
name|vda
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = xor<2 x i64> {{%.+}},<i64 -1, i64 -1>
comment|// CHECK: or<2 x i64> {{%.+}}, [[T1]]
comment|// CHECK-LE: [[T1:%.+]] = xor<2 x i64> {{%.+}},<i64 -1, i64 -1>
comment|// CHECK-LE: or<2 x i64> {{%.+}}, [[T1]]
comment|/* vec_sub */
name|res_vsll
operator|=
name|vec_sub
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: sub<2 x i64>
comment|// CHECK-LE: sub<2 x i64>
name|res_vull
operator|=
name|vec_sub
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: sub<2 x i64>
comment|// CHECK-LE: sub<2 x i64>
name|res_vd
operator|=
name|vec_sub
argument_list|(
name|vda
argument_list|,
name|vda
argument_list|)
expr_stmt|;
comment|// CHECK: fsub<2 x double>
comment|// CHECK-LE: fsub<2 x double>
name|res_vsx
operator|=
name|vec_sub
argument_list|(
name|vsx
argument_list|,
name|vsx
argument_list|)
expr_stmt|;
comment|// CHECK: sub<1 x i128>
comment|// CHECK-LE: sub<1 x i128>
name|res_vux
operator|=
name|vec_sub
argument_list|(
name|vux
argument_list|,
name|vux
argument_list|)
expr_stmt|;
comment|// CHECK: sub<1 x i128>
comment|// CHECK-LE: sub<1 x i128>
comment|/* vec_vbpermq */
name|res_vsll
operator|=
name|vec_vbpermq
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: llvm.ppc.altivec.vbpermq
comment|// CHECK-LE: llvm.ppc.altivec.vbpermq
name|res_vull
operator|=
name|vec_vbpermq
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: llvm.ppc.altivec.vbpermq
comment|// CHECK-LE: llvm.ppc.altivec.vbpermq
comment|// CHECK-PPC: warning: implicit declaration of function 'vec_vbpermq'
comment|/* vec_vgbbd */
name|res_vsc
operator|=
name|vec_vgbbd
argument_list|(
name|vsc
argument_list|)
expr_stmt|;
comment|// CHECK: llvm.ppc.altivec.vgbbd
comment|// CHECK-LE: llvm.ppc.altivec.vgbbd
name|res_vuc
operator|=
name|vec_vgbbd
argument_list|(
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: llvm.ppc.altivec.vgbbd
comment|// CHECK-LE: llvm.ppc.altivec.vgbbd
comment|// CHECK-PPC: warning: implicit declaration of function 'vec_vgbbd'
name|res_vuc
operator|=
name|vec_gb
argument_list|(
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: llvm.ppc.altivec.vgbbd
comment|// CHECK-LE: llvm.ppc.altivec.vgbbd
comment|// CHECK-PPC: warning: implicit declaration of function 'vec_gb'
name|res_vull
operator|=
name|vec_bperm
argument_list|(
name|vux
argument_list|,
name|vux
argument_list|)
expr_stmt|;
comment|// CHECK: llvm.ppc.altivec.vbpermq
comment|// CHECK-LE: llvm.ppc.altivec.vbpermq
comment|// CHECK-PPC: warning: implicit declaration of function 'vec_bperm'
name|res_vsll
operator|=
name|vec_neg
argument_list|(
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: sub<2 x i64> zeroinitializer, {{%[0-9]+}}
comment|// CHECK-LE: sub<2 x i64> zeroinitializer, {{%[0-9]+}}
comment|// CHECK_PPC: call to 'vec_neg' is ambiguous
block|}
end_function

begin_function
name|vector
name|signed
name|int
name|test_vec_addec_signed
parameter_list|(
name|vector
name|signed
name|int
name|a
parameter_list|,
name|vector
name|signed
name|int
name|b
parameter_list|,
name|vector
name|signed
name|int
name|c
parameter_list|)
block|{
return|return
name|vec_addec
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK-LABEL: @test_vec_addec_signed
comment|// CHECK: icmp slt i32 {{%[0-9]+}}, 4
comment|// CHECK: extractelement
comment|// CHECK: extractelement
comment|// CHECK: extractelement
comment|// CHECK: and i32 {{%[0-9]+}}, 1
comment|// CHECK: zext
comment|// CHECK: zext
comment|// CHECK: zext
comment|// CHECK: add i64
comment|// CHECK: add i64
comment|// CHECK: lshr i64
comment|// CHECK: and i64
comment|// CHECK: trunc i64 {{%[0-9]+}} to i32
comment|// CHECK: zext i32
comment|// CHECK: trunc i64 {{%[0-9]+}} to i32
comment|// CHECK: sext i32
comment|// CHECK: add nsw i32
comment|// CHECK: br label
comment|// CHECK: ret<4 x i32>
block|}
end_function

begin_function
name|vector
name|unsigned
name|int
name|test_vec_addec_unsigned
parameter_list|(
name|vector
name|unsigned
name|int
name|a
parameter_list|,
name|vector
name|unsigned
name|int
name|b
parameter_list|,
name|vector
name|unsigned
name|int
name|c
parameter_list|)
block|{
return|return
name|vec_addec
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK-LABEL: @test_vec_addec_unsigned
comment|// CHECK: icmp slt i32 {{%[0-9]+}}, 4
comment|// CHECK: extractelement
comment|// CHECK: and i32
comment|// CHECK: extractelement
comment|// CHECK: zext i32
comment|// CHECK: extractelement
comment|// CHECK: zext i32
comment|// CHECK: zext i32
comment|// CHECK: add i64
comment|// CHECK: lshr i64
comment|// CHECK: and i64
comment|// CHECK: trunc i64 {{%[0-9]+}} to i32
comment|// CHECK: zext i32
comment|// CHECK: trunc i64 {{%[0-9]+}} to i32
comment|// CHECK: sext i32
comment|// CHECK: add nsw i32
comment|// CHECK: br label
comment|// CHECK: ret<4 x i32>
block|}
end_function

begin_function
name|vector
name|signed
name|int
name|test_vec_subec_signed
parameter_list|(
name|vector
name|signed
name|int
name|a
parameter_list|,
name|vector
name|signed
name|int
name|b
parameter_list|,
name|vector
name|signed
name|int
name|c
parameter_list|)
block|{
return|return
name|vec_subec
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK-LABEL: @test_vec_subec_signed
comment|// CHECK: xor<4 x i32> {{%[0-9]+}},<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK: ret<4 x i32>
block|}
end_function

begin_function
name|vector
name|unsigned
name|int
name|test_vec_subec_unsigned
parameter_list|(
name|vector
name|unsigned
name|int
name|a
parameter_list|,
name|vector
name|unsigned
name|int
name|b
parameter_list|,
name|vector
name|unsigned
name|int
name|c
parameter_list|)
block|{
return|return
name|vec_subec
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK-LABEL: @test_vec_subec_unsigned
comment|// CHECK: xor<4 x i32> {{%[0-9]+}},<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK: ret<4 x i32>
block|}
end_function

end_unit

