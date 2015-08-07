begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -faltivec -target-feature +vsx -triple powerpc64-unknown-unknown -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -faltivec -target-feature +vsx -triple powerpc64le-unknown-unknown -emit-llvm %s -o - | FileCheck %s -check-prefix=CHECK-LE
end_comment

begin_decl_stmt
name|vector
name|unsigned
name|char
name|vuc
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
name|double
name|vd
init|=
block|{
literal|3.5
block|,
operator|-
literal|7.5
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
name|long
name|long
name|vsll
init|=
block|{
literal|255LL
block|,
operator|-
literal|937LL
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
literal|1447LL
block|,
literal|2894LL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|d
init|=
literal|23.4
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
name|bool
name|long
name|long
name|res_vbll
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
name|double
name|res_d
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|dummy
parameter_list|()
block|{ }
end_function

begin_function
name|void
name|test1
parameter_list|()
block|{
comment|// CHECK-LABEL: define void @test1
comment|// CHECK-LE-LABEL: define void @test1
name|res_vd
operator|=
name|vec_add
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: fadd<2 x double>
comment|// CHECK-LE: fadd<2 x double>
name|res_vd
operator|=
name|vec_and
argument_list|(
name|vbll
argument_list|,
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: and<2 x i64>
comment|// CHECK: bitcast<2 x i64> %{{[0-9]*}} to<2 x double>
comment|// CHECK-LE: and<2 x i64>
comment|// CHECK-LE: bitcast<2 x i64> %{{[0-9]*}} to<2 x double>
name|res_vd
operator|=
name|vec_and
argument_list|(
name|vd
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: and<2 x i64>
comment|// CHECK: bitcast<2 x i64> %{{[0-9]*}} to<2 x double>
comment|// CHECK-LE: and<2 x i64>
comment|// CHECK-LE: bitcast<2 x i64> %{{[0-9]*}} to<2 x double>
name|res_vd
operator|=
name|vec_and
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: and<2 x i64>
comment|// CHECK: bitcast<2 x i64> %{{[0-9]*}} to<2 x double>
comment|// CHECK-LE: and<2 x i64>
comment|// CHECK-LE: bitcast<2 x i64> %{{[0-9]*}} to<2 x double>
name|dummy
argument_list|()
expr_stmt|;
comment|// CHECK: call void @dummy()
comment|// CHECK-LE: call void @dummy()
name|res_vd
operator|=
name|vec_andc
argument_list|(
name|vbll
argument_list|,
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: bitcast<2 x double> %{{[0-9]*}} to<2 x i64>
comment|// CHECK: xor<2 x i64> %{{[0-9]*}},<i64 -1, i64 -1>
comment|// CHECK: and<2 x i64>
comment|// CHECK: bitcast<2 x i64> %{{[0-9]*}} to<2 x double>
comment|// CHECK-LE: bitcast<2 x double> %{{[0-9]*}} to<2 x i64>
comment|// CHECK-LE: xor<2 x i64> %{{[0-9]*}},<i64 -1, i64 -1>
comment|// CHECK-LE: and<2 x i64>
comment|// CHECK-LE: bitcast<2 x i64> %{{[0-9]*}} to<2 x double>
name|dummy
argument_list|()
expr_stmt|;
comment|// CHECK: call void @dummy()
comment|// CHECK-LE: call void @dummy()
name|res_vd
operator|=
name|vec_andc
argument_list|(
name|vd
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: bitcast<2 x double> %{{[0-9]*}} to<2 x i64>
comment|// CHECK: xor<2 x i64> %{{[0-9]*}},<i64 -1, i64 -1>
comment|// CHECK: and<2 x i64>
comment|// CHECK: bitcast<2 x i64> %{{[0-9]*}} to<2 x double>
comment|// CHECK-LE: bitcast<2 x double> %{{[0-9]*}} to<2 x i64>
comment|// CHECK-LE: xor<2 x i64> %{{[0-9]*}},<i64 -1, i64 -1>
comment|// CHECK-LE: and<2 x i64>
comment|// CHECK-LE: bitcast<2 x i64> %{{[0-9]*}} to<2 x double>
name|dummy
argument_list|()
expr_stmt|;
comment|// CHECK: call void @dummy()
name|res_vd
operator|=
name|vec_andc
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: bitcast<2 x double> %{{[0-9]*}} to<2 x i64>
comment|// CHECK: xor<2 x i64> %{{[0-9]*}},<i64 -1, i64 -1>
comment|// CHECK: and<2 x i64>
comment|// CHECK: bitcast<2 x i64> %{{[0-9]*}} to<2 x double>
name|dummy
argument_list|()
expr_stmt|;
comment|// CHECK: call void @dummy()
comment|// CHECK-LE: call void @dummy()
name|res_vd
operator|=
name|vec_ceil
argument_list|(
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x double> @llvm.ceil.v2f64(<2 x double> %{{[0-9]*}})
comment|// CHECK-LE: call<2 x double> @llvm.ceil.v2f64(<2 x double> %{{[0-9]*}})
name|res_vf
operator|=
name|vec_ceil
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x float> @llvm.ceil.v4f32(<4 x float> %{{[0-9]*}})
comment|// CHECK-LE: call<4 x float> @llvm.ceil.v4f32(<4 x float> %{{[0-9]*}})
name|res_vbll
operator|=
name|vec_cmpeq
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x i64> @llvm.ppc.vsx.xvcmpeqdp(<2 x double> %{{[0-9]*}},<2 x double> %{{[0-9]*}})
comment|// CHECK-LE: call<2 x i64> @llvm.ppc.vsx.xvcmpeqdp(<2 x double> %{{[0-9]*}},<2 x double> %{{[0-9]*}})
name|res_vbi
operator|=
name|vec_cmpeq
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x i32> @llvm.ppc.vsx.xvcmpeqsp(<4 x float> %{{[0-9]*}},<4 x float> %{{[0-9]*}})
comment|// CHECK-LE: call<4 x i32> @llvm.ppc.vsx.xvcmpeqsp(<4 x float> %{{[0-9]*}},<4 x float> %{{[0-9]*}})
name|res_vbll
operator|=
name|vec_cmpge
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x i64> @llvm.ppc.vsx.xvcmpgedp(<2 x double> %{{[0-9]*}},<2 x double> %{{[0-9]*}})
comment|// CHECK-LE: call<2 x i64> @llvm.ppc.vsx.xvcmpgedp(<2 x double> %{{[0-9]*}},<2 x double> %{{[0-9]*}})
name|res_vbi
operator|=
name|vec_cmpge
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x i32> @llvm.ppc.vsx.xvcmpgesp(<4 x float> %{{[0-9]*}},<4 x float> %{{[0-9]*}})
comment|// CHECK-LE: call<4 x i32> @llvm.ppc.vsx.xvcmpgesp(<4 x float> %{{[0-9]*}},<4 x float> %{{[0-9]*}})
name|res_vbll
operator|=
name|vec_cmpgt
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x i64> @llvm.ppc.vsx.xvcmpgtdp(<2 x double> %{{[0-9]*}},<2 x double> %{{[0-9]*}})
comment|// CHECK-LE: call<2 x i64> @llvm.ppc.vsx.xvcmpgtdp(<2 x double> %{{[0-9]*}},<2 x double> %{{[0-9]*}})
name|res_vbi
operator|=
name|vec_cmpgt
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x i32> @llvm.ppc.vsx.xvcmpgtsp(<4 x float> %{{[0-9]*}},<4 x float> %{{[0-9]*}})
comment|// CHECK-LE: call<4 x i32> @llvm.ppc.vsx.xvcmpgtsp(<4 x float> %{{[0-9]*}},<4 x float> %{{[0-9]*}})
name|res_vbll
operator|=
name|vec_cmple
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x i64> @llvm.ppc.vsx.xvcmpgedp(<2 x double> %{{[0-9]*}},<2 x double> %{{[0-9]*}})
comment|// CHECK-LE: call<2 x i64> @llvm.ppc.vsx.xvcmpgedp(<2 x double> %{{[0-9]*}},<2 x double> %{{[0-9]*}})
name|res_vbi
operator|=
name|vec_cmple
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x i32> @llvm.ppc.vsx.xvcmpgesp(<4 x float> %{{[0-9]*}},<4 x float> %{{[0-9]*}})
comment|// CHECK-LE: call<4 x i32> @llvm.ppc.vsx.xvcmpgesp(<4 x float> %{{[0-9]*}},<4 x float> %{{[0-9]*}})
name|res_vbll
operator|=
name|vec_cmplt
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x i64> @llvm.ppc.vsx.xvcmpgtdp(<2 x double> %{{[0-9]*}},<2 x double> %{{[0-9]*}})
comment|// CHECK-LE: call<2 x i64> @llvm.ppc.vsx.xvcmpgtdp(<2 x double> %{{[0-9]*}},<2 x double> %{{[0-9]*}})
name|res_vbi
operator|=
name|vec_cmplt
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x i32> @llvm.ppc.vsx.xvcmpgtsp(<4 x float> %{{[0-9]*}},<4 x float> %{{[0-9]*}})
comment|// CHECK-LE: call<4 x i32> @llvm.ppc.vsx.xvcmpgtsp(<4 x float> %{{[0-9]*}},<4 x float> %{{[0-9]*}})
comment|/* vec_cpsgn */
name|res_vf
operator|=
name|vec_cpsgn
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x float> @llvm.copysign.v4f32(<4 x float> %{{.+}},<4 x float> %{{.+}})
comment|// CHECK-LE: call<4 x float> @llvm.copysign.v4f32(<4 x float> %{{.+}},<4 x float> %{{.+}})
name|res_vd
operator|=
name|vec_cpsgn
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x double> @llvm.copysign.v2f64(<2 x double> %{{.+}},<2 x double> %{{.+}})
comment|// CHECK-LE: call<2 x double> @llvm.copysign.v2f64(<2 x double> %{{.+}},<2 x double> %{{.+}})
comment|/* vec_div */
name|res_vsll
operator|=
name|vec_div
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: sdiv<2 x i64>
comment|// CHECK-LE: sdiv<2 x i64>
name|res_vull
operator|=
name|vec_div
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: udiv<2 x i64>
comment|// CHECK-LE: udiv<2 x i64>
name|res_vf
operator|=
name|vec_div
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: fdiv<4 x float>
comment|// CHECK-LE: fdiv<4 x float>
name|res_vd
operator|=
name|vec_div
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: fdiv<2 x double>
comment|// CHECK-LE: fdiv<2 x double>
comment|/* vec_max */
name|res_vf
operator|=
name|vec_max
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.xvmaxsp
comment|// CHECK-LE: @llvm.ppc.vsx.xvmaxsp
name|res_vd
operator|=
name|vec_max
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.xvmaxdp
comment|// CHECK-LE: @llvm.ppc.vsx.xvmaxdp
name|res_vf
operator|=
name|vec_vmaxfp
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.xvmaxsp
comment|// CHECK-LE: @llvm.ppc.vsx.xvmaxsp
comment|/* vec_min */
name|res_vf
operator|=
name|vec_min
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.xvminsp
comment|// CHECK-LE: @llvm.ppc.vsx.xvminsp
name|res_vd
operator|=
name|vec_min
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.xvmindp
comment|// CHECK-LE: @llvm.ppc.vsx.xvmindp
name|res_vf
operator|=
name|vec_vminfp
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.xvminsp
comment|// CHECK-LE: @llvm.ppc.vsx.xvminsp
name|res_d
operator|=
name|__builtin_vsx_xsmaxdp
argument_list|(
name|d
argument_list|,
name|d
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.xsmaxdp
comment|// CHECK-LE: @llvm.ppc.vsx.xsmaxdp
name|res_d
operator|=
name|__builtin_vsx_xsmindp
argument_list|(
name|d
argument_list|,
name|d
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.xsmindp
comment|// CHECK-LE: @llvm.ppc.vsx.xsmindp
comment|/* vec_perm */
name|res_vsll
operator|=
name|vec_perm
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vull
operator|=
name|vec_perm
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbll
operator|=
name|vec_perm
argument_list|(
name|vbll
argument_list|,
name|vbll
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = bitcast<2 x i64> {{.+}} to<4 x i32>
comment|// CHECK: [[T2:%.+]] = bitcast<2 x i64> {{.+}} to<4 x i32>
comment|// CHECK: call<4 x i32> @llvm.ppc.altivec.vperm(<4 x i32> [[T1]],<4 x i32> [[T2]],<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: [[T1:%.+]] = bitcast<2 x i64> {{.+}} to<4 x i32>
comment|// CHECK-LE: [[T2:%.+]] = bitcast<2 x i64> {{.+}} to<4 x i32>
comment|// CHECK-LE: call<4 x i32> @llvm.ppc.altivec.vperm(<4 x i32> [[T1]],<4 x i32> [[T2]],<16 x i8>
name|res_vf
operator|=
name|vec_round
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x float> @llvm.round.v4f32(<4 x float>
comment|// CHECK-LE: call<4 x float> @llvm.round.v4f32(<4 x float>
name|res_vd
operator|=
name|vec_round
argument_list|(
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x double> @llvm.round.v2f64(<2 x double>
comment|// CHECK-LE: call<2 x double> @llvm.round.v2f64(<2 x double>
name|res_vd
operator|=
name|vec_perm
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vd
operator|=
name|vec_splat
argument_list|(
name|vd
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = bitcast<2 x double> {{.+}} to<4 x i32>
comment|// CHECK: [[T2:%.+]] = bitcast<2 x double> {{.+}} to<4 x i32>
comment|// CHECK: call<4 x i32> @llvm.ppc.altivec.vperm(<4 x i32> [[T1]],<4 x i32> [[T2]],<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: [[T1:%.+]] = bitcast<2 x double> {{.+}} to<4 x i32>
comment|// CHECK-LE: [[T2:%.+]] = bitcast<2 x double> {{.+}} to<4 x i32>
comment|// CHECK-LE: call<4 x i32> @llvm.ppc.altivec.vperm(<4 x i32> [[T1]],<4 x i32> [[T2]],<16 x i8>
name|res_vbll
operator|=
name|vec_splat
argument_list|(
name|vbll
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = bitcast<2 x i64> {{.+}} to<4 x i32>
comment|// CHECK: [[T2:%.+]] = bitcast<2 x i64> {{.+}} to<4 x i32>
comment|// CHECK: call<4 x i32> @llvm.ppc.altivec.vperm(<4 x i32> [[T1]],<4 x i32> [[T2]],<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: [[T1:%.+]] = bitcast<2 x i64> {{.+}} to<4 x i32>
comment|// CHECK-LE: [[T2:%.+]] = bitcast<2 x i64> {{.+}} to<4 x i32>
comment|// CHECK-LE: call<4 x i32> @llvm.ppc.altivec.vperm(<4 x i32> [[T1]],<4 x i32> [[T2]],<16 x i8>
name|res_vsll
operator|=
name|vec_splat
argument_list|(
name|vsll
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = bitcast<2 x i64> {{.+}} to<4 x i32>
comment|// CHECK: [[T2:%.+]] = bitcast<2 x i64> {{.+}} to<4 x i32>
comment|// CHECK: call<4 x i32> @llvm.ppc.altivec.vperm(<4 x i32> [[T1]],<4 x i32> [[T2]],<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: [[T1:%.+]] = bitcast<2 x i64> {{.+}} to<4 x i32>
comment|// CHECK-LE: [[T2:%.+]] = bitcast<2 x i64> {{.+}} to<4 x i32>
comment|// CHECK-LE: call<4 x i32> @llvm.ppc.altivec.vperm(<4 x i32> [[T1]],<4 x i32> [[T2]],<16 x i8>
name|res_vull
operator|=
name|vec_splat
argument_list|(
name|vull
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = bitcast<2 x i64> {{.+}} to<4 x i32>
comment|// CHECK: [[T2:%.+]] = bitcast<2 x i64> {{.+}} to<4 x i32>
comment|// CHECK: call<4 x i32> @llvm.ppc.altivec.vperm(<4 x i32> [[T1]],<4 x i32> [[T2]],<16 x i8>
comment|// CHECK-LE: xor<16 x i8>
comment|// CHECK-LE: [[T1:%.+]] = bitcast<2 x i64> {{.+}} to<4 x i32>
comment|// CHECK-LE: [[T2:%.+]] = bitcast<2 x i64> {{.+}} to<4 x i32>
comment|// CHECK-LE: call<4 x i32> @llvm.ppc.altivec.vperm(<4 x i32> [[T1]],<4 x i32> [[T2]],<16 x i8>
name|res_vsi
operator|=
name|vec_pack
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vui
operator|=
name|vec_pack
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vbi
operator|=
name|vec_pack
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
name|vec_vperm
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vull
operator|=
name|vec_vperm
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vd
operator|=
name|vec_vperm
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|/* vec_vsx_ld */
name|res_vsi
operator|=
name|vec_vsx_ld
argument_list|(
literal|0
argument_list|,
operator|&
name|vsi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.lxvw4x
comment|// CHECK-LE: @llvm.ppc.vsx.lxvw4x
name|res_vui
operator|=
name|vec_vsx_ld
argument_list|(
literal|0
argument_list|,
operator|&
name|vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.lxvw4x
comment|// CHECK-LE: @llvm.ppc.vsx.lxvw4x
name|res_vf
operator|=
name|vec_vsx_ld
argument_list|(
literal|0
argument_list|,
operator|&
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.lxvw4x
comment|// CHECK-LE: @llvm.ppc.vsx.lxvw4x
name|res_vsll
operator|=
name|vec_vsx_ld
argument_list|(
literal|0
argument_list|,
operator|&
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.lxvd2x
comment|// CHECK-LE: @llvm.ppc.vsx.lxvd2x
name|res_vull
operator|=
name|vec_vsx_ld
argument_list|(
literal|0
argument_list|,
operator|&
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.lxvd2x
comment|// CHECK-LE: @llvm.ppc.vsx.lxvd2x
name|res_vd
operator|=
name|vec_vsx_ld
argument_list|(
literal|0
argument_list|,
operator|&
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.lxvd2x
comment|// CHECK-LE: @llvm.ppc.vsx.lxvd2x
comment|/* vec_vsx_st */
name|vec_vsx_st
argument_list|(
name|vsi
argument_list|,
literal|0
argument_list|,
operator|&
name|res_vsi
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.stxvw4x
comment|// CHECK-LE: @llvm.ppc.vsx.stxvw4x
name|vec_vsx_st
argument_list|(
name|vui
argument_list|,
literal|0
argument_list|,
operator|&
name|res_vui
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.stxvw4x
comment|// CHECK-LE: @llvm.ppc.vsx.stxvw4x
name|vec_vsx_st
argument_list|(
name|vf
argument_list|,
literal|0
argument_list|,
operator|&
name|res_vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.stxvw4x
comment|// CHECK-LE: @llvm.ppc.vsx.stxvw4x
name|vec_vsx_st
argument_list|(
name|vsll
argument_list|,
literal|0
argument_list|,
operator|&
name|res_vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.stxvd2x
comment|// CHECK-LE: @llvm.ppc.vsx.stxvd2x
name|vec_vsx_st
argument_list|(
name|vull
argument_list|,
literal|0
argument_list|,
operator|&
name|res_vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.stxvd2x
comment|// CHECK-LE: @llvm.ppc.vsx.stxvd2x
name|vec_vsx_st
argument_list|(
name|vd
argument_list|,
literal|0
argument_list|,
operator|&
name|res_vd
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.stxvd2x
comment|// CHECK-LE: @llvm.ppc.vsx.stxvd2x
comment|/* vec_and */
name|res_vsll
operator|=
name|vec_and
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: and<2 x i64>
comment|// CHECK-LE: and<2 x i64>
name|res_vsll
operator|=
name|vec_and
argument_list|(
name|vbll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: and<2 x i64>
comment|// CHECK-LE: and<2 x i64>
name|res_vsll
operator|=
name|vec_and
argument_list|(
name|vsll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: and<2 x i64>
comment|// CHECK-LE: and<2 x i64>
name|res_vull
operator|=
name|vec_and
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: and<2 x i64>
comment|// CHECK-LE: and<2 x i64>
name|res_vull
operator|=
name|vec_and
argument_list|(
name|vbll
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: and<2 x i64>
comment|// CHECK-LE: and<2 x i64>
name|res_vull
operator|=
name|vec_and
argument_list|(
name|vull
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: and<2 x i64>
comment|// CHECK-LE: and<2 x i64>
name|res_vbll
operator|=
name|vec_and
argument_list|(
name|vbll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: and<2 x i64>
comment|// CHECK-LE: and<2 x i64>
comment|/* vec_vand */
name|res_vsll
operator|=
name|vec_vand
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: and<2 x i64>
comment|// CHECK-LE: and<2 x i64>
name|res_vsll
operator|=
name|vec_vand
argument_list|(
name|vbll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: and<2 x i64>
comment|// CHECK-LE: and<2 x i64>
name|res_vsll
operator|=
name|vec_vand
argument_list|(
name|vsll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: and<2 x i64>
comment|// CHECK-LE: and<2 x i64>
name|res_vull
operator|=
name|vec_vand
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: and<2 x i64>
comment|// CHECK-LE: and<2 x i64>
name|res_vull
operator|=
name|vec_vand
argument_list|(
name|vbll
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: and<2 x i64>
comment|// CHECK-LE: and<2 x i64>
name|res_vull
operator|=
name|vec_vand
argument_list|(
name|vull
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: and<2 x i64>
comment|// CHECK-LE: and<2 x i64>
name|res_vbll
operator|=
name|vec_vand
argument_list|(
name|vbll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: and<2 x i64>
comment|// CHECK-LE: and<2 x i64>
comment|/* vec_andc */
name|res_vsll
operator|=
name|vec_andc
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: xor<2 x i64>
comment|// CHECK: and<2 x i64>
comment|// CHECK-LE: xor<2 x i64>
comment|// CHECK-LE: and<2 x i64>
name|res_vsll
operator|=
name|vec_andc
argument_list|(
name|vbll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: xor<2 x i64>
comment|// CHECK: and<2 x i64>
comment|// CHECK-LE: xor<2 x i64>
comment|// CHECK-LE: and<2 x i64>
name|res_vsll
operator|=
name|vec_andc
argument_list|(
name|vsll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: xor<2 x i64>
comment|// CHECK: and<2 x i64>
comment|// CHECK-LE: xor<2 x i64>
comment|// CHECK-LE: and<2 x i64>
name|res_vull
operator|=
name|vec_andc
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: xor<2 x i64>
comment|// CHECK: and<2 x i64>
comment|// CHECK-LE: xor<2 x i64>
comment|// CHECK-LE: and<2 x i64>
name|res_vull
operator|=
name|vec_andc
argument_list|(
name|vbll
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: xor<2 x i64>
comment|// CHECK: and<2 x i64>
comment|// CHECK-LE: xor<2 x i64>
comment|// CHECK-LE: and<2 x i64>
name|res_vull
operator|=
name|vec_andc
argument_list|(
name|vull
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: xor<2 x i64>
comment|// CHECK: and<2 x i64>
comment|// CHECK-LE: xor<2 x i64>
comment|// CHECK-LE: and<2 x i64>
name|res_vbll
operator|=
name|vec_andc
argument_list|(
name|vbll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: xor<2 x i64>
comment|// CHECK: and<2 x i64>
comment|// CHECK-LE: xor<2 x i64>
comment|// CHECK-LE: and<2 x i64>
name|res_vf
operator|=
name|vec_floor
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x float> @llvm.floor.v4f32(<4 x float> %{{[0-9]+}})
comment|// CHECK-LE: call<4 x float> @llvm.floor.v4f32(<4 x float> %{{[0-9]+}})
name|res_vd
operator|=
name|vec_floor
argument_list|(
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x double> @llvm.floor.v2f64(<2 x double> %{{[0-9]+}})
comment|// CHECK-LE: call<2 x double> @llvm.floor.v2f64(<2 x double> %{{[0-9]+}})
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
comment|// CHECK: call<4 x float> @llvm.fma.v4f32(<4 x float> %{{[0-9]+}},<4 x float> %{{[0-9]+}},<4 x float> %{{[0-9]+}})
comment|// CHECK-LE: call<4 x float> @llvm.fma.v4f32(<4 x float> %{{[0-9]+}},<4 x float> %{{[0-9]+}},<4 x float> %{{[0-9]+}})
name|res_vd
operator|=
name|vec_madd
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|,
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x double> @llvm.fma.v2f64(<2 x double> %{{[0-9]+}},<2 x double> %{{[0-9]+}},<2 x double> %{{[0-9]+}})
comment|// CHECK-LE: call<2 x double> @llvm.fma.v2f64(<2 x double> %{{[0-9]+}},<2 x double> %{{[0-9]+}},<2 x double> %{{[0-9]+}})
comment|/* vec_mergeh */
name|res_vsll
operator|=
name|vec_mergeh
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vsll
operator|=
name|vec_mergeh
argument_list|(
name|vsll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vsll
operator|=
name|vec_mergeh
argument_list|(
name|vbll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vull
operator|=
name|vec_mergeh
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vull
operator|=
name|vec_mergeh
argument_list|(
name|vull
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vull
operator|=
name|vec_mergeh
argument_list|(
name|vbll
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|/* vec_mergel */
name|res_vsll
operator|=
name|vec_mergel
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vsll
operator|=
name|vec_mergel
argument_list|(
name|vsll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vsll
operator|=
name|vec_mergel
argument_list|(
name|vbll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vull
operator|=
name|vec_mergel
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vull
operator|=
name|vec_mergel
argument_list|(
name|vull
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
name|res_vull
operator|=
name|vec_mergel
argument_list|(
name|vbll
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vperm
comment|// CHECK-LE: @llvm.ppc.altivec.vperm
comment|/* vec_msub */
name|res_vf
operator|=
name|vec_msub
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: fsub<4 x float><float -0.000000e+00, float -0.000000e+00, float -0.000000e+00, float -0.000000e+00>, %{{[0-9]+}}
comment|// CHECK-NEXT: call<4 x float> @llvm.fma.v4f32(<4 x float> %{{[0-9]+}},<4 x float> %{{[0-9]+}},<4 x float>
comment|// CHECK-LE: fsub<4 x float><float -0.000000e+00, float -0.000000e+00, float -0.000000e+00, float -0.000000e+00>, %{{[0-9]+}}
comment|// CHECK-LE-NEXT: call<4 x float> @llvm.fma.v4f32(<4 x float> %{{[0-9]+}},<4 x float> %{{[0-9]+}},<4 x float>
name|res_vd
operator|=
name|vec_msub
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|,
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: fsub<2 x double><double -0.000000e+00, double -0.000000e+00>, %{{[0-9]+}}
comment|// CHECK-NEXT: call<2 x double> @llvm.fma.v2f64(<2 x double> %{{[0-9]+}},<2 x double> %{{[0-9]+}},<2 x double>
comment|// CHECK-LE: fsub<2 x double><double -0.000000e+00, double -0.000000e+00>, %{{[0-9]+}}
comment|// CHECK-LE-NEXT: call<2 x double> @llvm.fma.v2f64(<2 x double> %{{[0-9]+}},<2 x double> %{{[0-9]+}},<2 x double>
name|res_vsll
operator|=
name|vec_mul
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: mul<2 x i64>
comment|// CHECK-LE: mul<2 x i64>
name|res_vull
operator|=
name|vec_mul
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: mul<2 x i64>
comment|// CHECK-LE: mul<2 x i64>
name|res_vf
operator|=
name|vec_mul
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: fmul<4 x float> %{{[0-9]+}}, %{{[0-9]+}}
comment|// CHECK-LE: fmul<4 x float> %{{[0-9]+}}, %{{[0-9]+}}
name|res_vd
operator|=
name|vec_mul
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: fmul<2 x double> %{{[0-9]+}}, %{{[0-9]+}}
comment|// CHECK-LE: fmul<2 x double> %{{[0-9]+}}, %{{[0-9]+}}
name|res_vf
operator|=
name|vec_nearbyint
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x float> @llvm.round.v4f32(<4 x float> %{{[0-9]+}})
comment|// CHECK-LE: call<4 x float> @llvm.round.v4f32(<4 x float> %{{[0-9]+}})
name|res_vd
operator|=
name|vec_nearbyint
argument_list|(
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x double> @llvm.round.v2f64(<2 x double> %{{[0-9]+}})
comment|// CHECK-LE: call<2 x double> @llvm.round.v2f64(<2 x double> %{{[0-9]+}})
name|res_vf
operator|=
name|vec_nmadd
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: [[FM:[0-9]+]] = call<4 x float> @llvm.fma.v4f32(<4 x float> %{{[0-9]+}},<4 x float> %{{[0-9]+}},<4 x float> %{{[0-9]+}})
comment|// CHECK-NEXT: fsub<4 x float><float -0.000000e+00, float -0.000000e+00, float -0.000000e+00, float -0.000000e+00>, %[[FM]]
comment|// CHECK-LE: [[FM:[0-9]+]] = call<4 x float> @llvm.fma.v4f32(<4 x float> %{{[0-9]+}},<4 x float> %{{[0-9]+}},<4 x float> %{{[0-9]+}})
comment|// CHECK-LE-NEXT: fsub<4 x float><float -0.000000e+00, float -0.000000e+00, float -0.000000e+00, float -0.000000e+00>, %[[FM]]
name|res_vd
operator|=
name|vec_nmadd
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|,
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: [[FM:[0-9]+]] = call<2 x double> @llvm.fma.v2f64(<2 x double> %{{[0-9]+}},<2 x double> %{{[0-9]+}},<2 x double> %{{[0-9]+}})
comment|// CHECK-NEXT: fsub<2 x double><double -0.000000e+00, double -0.000000e+00>, %[[FM]]
comment|// CHECK-LE: [[FM:[0-9]+]] = call<2 x double> @llvm.fma.v2f64(<2 x double> %{{[0-9]+}},<2 x double> %{{[0-9]+}},<2 x double> %{{[0-9]+}})
comment|// CHECK-LE-NEXT: fsub<2 x double><double -0.000000e+00, double -0.000000e+00>, %[[FM]]
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
comment|// CHECK: fsub<4 x float><float -0.000000e+00, float -0.000000e+00, float -0.000000e+00, float -0.000000e+00>, %{{[0-9]+}}
comment|// CHECK-NEXT: call<4 x float> @llvm.fma.v4f32(<4 x float> %{{[0-9]+}},<4 x float> %{{[0-9]+}},<4 x float>
comment|// CHECK: fsub<4 x float><float -0.000000e+00, float -0.000000e+00, float -0.000000e+00, float -0.000000e+00>, %{{[0-9]+}}
comment|// CHECK-LE: fsub<4 x float><float -0.000000e+00, float -0.000000e+00, float -0.000000e+00, float -0.000000e+00>, %{{[0-9]+}}
comment|// CHECK-LE-NEXT: call<4 x float> @llvm.fma.v4f32(<4 x float> %{{[0-9]+}},<4 x float> %{{[0-9]+}},<4 x float>
comment|// CHECK-LE: fsub<4 x float><float -0.000000e+00, float -0.000000e+00, float -0.000000e+00, float -0.000000e+00>, %{{[0-9]+}}
name|res_vd
operator|=
name|vec_nmsub
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|,
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: fsub<2 x double><double -0.000000e+00, double -0.000000e+00>, %{{[0-9]+}}
comment|// CHECK-NEXT: [[FM:[0-9]+]] = call<2 x double> @llvm.fma.v2f64(<2 x double> %{{[0-9]+}},<2 x double> %{{[0-9]+}},<2 x double>
comment|// CHECK-NEXT: fsub<2 x double><double -0.000000e+00, double -0.000000e+00>, %[[FM]]
comment|// CHECK-LE: fsub<2 x double><double -0.000000e+00, double -0.000000e+00>, %{{[0-9]+}}
comment|// CHECK-LE-NEXT: [[FM:[0-9]+]] = call<2 x double> @llvm.fma.v2f64(<2 x double> %{{[0-9]+}},<2 x double> %{{[0-9]+}},<2 x double>
comment|// CHECK-LE-NEXT: fsub<2 x double><double -0.000000e+00, double -0.000000e+00>, %[[FM]]
comment|/* vec_nor */
name|res_vsll
operator|=
name|vec_nor
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: or<2 x i64>
comment|// CHECK: xor<2 x i64>
comment|// CHECK-LE: or<2 x i64>
comment|// CHECK-LE: xor<2 x i64>
name|res_vull
operator|=
name|vec_nor
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: or<2 x i64>
comment|// CHECK: xor<2 x i64>
comment|// CHECK-LE: or<2 x i64>
comment|// CHECK-LE: xor<2 x i64>
name|res_vull
operator|=
name|vec_nor
argument_list|(
name|vbll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: or<2 x i64>
comment|// CHECK: xor<2 x i64>
comment|// CHECK-LE: or<2 x i64>
comment|// CHECK-LE: xor<2 x i64>
name|res_vd
operator|=
name|vec_nor
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: bitcast<2 x double> %{{[0-9]+}} to<2 x i64>
comment|// CHECK: [[OR:%.+]] = or<2 x i64> %{{[0-9]+}}, %{{[0-9]+}}
comment|// CHECK-NEXT: xor<2 x i64> [[OR]],<i64 -1, i64 -1>
comment|// CHECK-LE: bitcast<2 x double> %{{[0-9]+}} to<2 x i64>
comment|// CHECK-LE: [[OR:%.+]] = or<2 x i64> %{{[0-9]+}}, %{{[0-9]+}}
comment|// CHECK-LE-NEXT: xor<2 x i64> [[OR]],<i64 -1, i64 -1>
comment|/* vec_or */
name|res_vsll
operator|=
name|vec_or
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: or<2 x i64>
comment|// CHECK-LE: or<2 x i64>
name|res_vsll
operator|=
name|vec_or
argument_list|(
name|vbll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: or<2 x i64>
comment|// CHECK-LE: or<2 x i64>
name|res_vsll
operator|=
name|vec_or
argument_list|(
name|vsll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: or<2 x i64>
comment|// CHECK-LE: or<2 x i64>
name|res_vull
operator|=
name|vec_or
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: or<2 x i64>
comment|// CHECK-LE: or<2 x i64>
name|res_vull
operator|=
name|vec_or
argument_list|(
name|vbll
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: or<2 x i64>
comment|// CHECK-LE: or<2 x i64>
name|res_vull
operator|=
name|vec_or
argument_list|(
name|vull
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: or<2 x i64>
comment|// CHECK-LE: or<2 x i64>
name|res_vbll
operator|=
name|vec_or
argument_list|(
name|vbll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: or<2 x i64>
comment|// CHECK-LE: or<2 x i64>
name|res_vd
operator|=
name|vec_or
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: bitcast<2 x double> %{{[0-9]+}} to<2 x i64>
comment|// CHECK: or<2 x i64> %{{[0-9]+}}, %{{[0-9]+}}
comment|// CHECK-LE: bitcast<2 x double> %{{[0-9]+}} to<2 x i64>
comment|// CHECK-LE: or<2 x i64> %{{[0-9]+}}, %{{[0-9]+}}
name|res_vd
operator|=
name|vec_or
argument_list|(
name|vbll
argument_list|,
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = bitcast<2 x double> %{{[0-9]+}} to<2 x i64>
comment|// CHECK: [[T2:%.+]] = or<2 x i64> %{{[0-9]+}}, [[T1]]
comment|// CHECK: bitcast<2 x i64> [[T2]] to<2 x double>
comment|// CHECK-LE: [[T1:%.+]] = bitcast<2 x double> %{{[0-9]+}} to<2 x i64>
comment|// CHECK-LE: [[T2:%.+]] = or<2 x i64> %{{[0-9]+}}, [[T1]]
comment|// CHECK-LE: bitcast<2 x i64> [[T2]] to<2 x double>
name|res_vd
operator|=
name|vec_or
argument_list|(
name|vd
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.+]] = bitcast<2 x double> %{{[0-9]+}} to<2 x i64>
comment|// CHECK: [[T2:%.+]] = or<2 x i64> [[T1]], %{{[0-9]+}}
comment|// CHECK: bitcast<2 x i64> [[T2]] to<2 x double>
comment|// CHECK-LE: [[T1:%.+]] = bitcast<2 x double> %{{[0-9]+}} to<2 x i64>
comment|// CHECK-LE: [[T2:%.+]] = or<2 x i64> [[T1]], %{{[0-9]+}}
comment|// CHECK-LE: bitcast<2 x i64> [[T2]] to<2 x double>
name|res_vf
operator|=
name|vec_re
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x float> @llvm.ppc.vsx.xvresp(<4 x float>
comment|// CHECK-LE: call<4 x float> @llvm.ppc.vsx.xvresp(<4 x float>
name|res_vd
operator|=
name|vec_re
argument_list|(
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x double> @llvm.ppc.vsx.xvredp(<2 x double>
comment|// CHECK-LE: call<2 x double> @llvm.ppc.vsx.xvredp(<2 x double>
name|res_vf
operator|=
name|vec_rint
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x float> @llvm.nearbyint.v4f32(<4 x float> %{{[0-9]+}})
comment|// CHECK-LE: call<4 x float> @llvm.nearbyint.v4f32(<4 x float> %{{[0-9]+}})
name|res_vd
operator|=
name|vec_rint
argument_list|(
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x double> @llvm.nearbyint.v2f64(<2 x double> %{{[0-9]+}})
comment|// CHECK-LE: call<2 x double> @llvm.nearbyint.v2f64(<2 x double> %{{[0-9]+}})
name|res_vf
operator|=
name|vec_rsqrte
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x float> @llvm.ppc.vsx.xvrsqrtesp(<4 x float> %{{[0-9]+}})
comment|// CHECK-LE: call<4 x float> @llvm.ppc.vsx.xvrsqrtesp(<4 x float> %{{[0-9]+}})
name|res_vd
operator|=
name|vec_rsqrte
argument_list|(
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x double> @llvm.ppc.vsx.xvrsqrtedp(<2 x double> %{{[0-9]+}})
comment|// CHECK-LE: call<2 x double> @llvm.ppc.vsx.xvrsqrtedp(<2 x double> %{{[0-9]+}})
name|dummy
argument_list|()
expr_stmt|;
comment|// CHECK: call void @dummy()
comment|// CHECK-LE: call void @dummy()
name|res_vf
operator|=
name|vec_sel
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: xor<2 x i64> %{{[0-9]+}},<i64 -1, i64 -1>
comment|// CHECK: and<2 x i64> %{{[0-9]+}},
comment|// CHECK: and<2 x i64> %{{[0-9]+}}, %{{[0-9]+}}
comment|// CHECK: or<2 x i64>
comment|// CHECK: bitcast<2 x i64> %{{[0-9]+}} to<2 x double>
comment|// CHECK-LE: xor<2 x i64> %{{[0-9]+}},<i64 -1, i64 -1>
comment|// CHECK-LE: and<2 x i64> %{{[0-9]+}},
comment|// CHECK-LE: and<2 x i64> %{{[0-9]+}}, %{{[0-9]+}}
comment|// CHECK-LE: or<2 x i64>
comment|// CHECK-LE: bitcast<2 x i64> %{{[0-9]+}} to<2 x double>
name|dummy
argument_list|()
expr_stmt|;
comment|// CHECK: call void @dummy()
comment|// CHECK-LE: call void @dummy()
name|res_vd
operator|=
name|vec_sel
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: xor<2 x i64> %{{[0-9]+}},<i64 -1, i64 -1>
comment|// CHECK: and<2 x i64> %{{[0-9]+}},
comment|// CHECK: and<2 x i64> %{{[0-9]+}}, %{{[0-9]+}}
comment|// CHECK: or<2 x i64>
comment|// CHECK: bitcast<2 x i64> %{{[0-9]+}} to<2 x double>
comment|// CHECK-LE: xor<2 x i64> %{{[0-9]+}},<i64 -1, i64 -1>
comment|// CHECK-LE: and<2 x i64> %{{[0-9]+}},
comment|// CHECK-LE: and<2 x i64> %{{[0-9]+}}, %{{[0-9]+}}
comment|// CHECK-LE: or<2 x i64>
comment|// CHECK-LE: bitcast<2 x i64> %{{[0-9]+}} to<2 x double>
name|res_vf
operator|=
name|vec_sqrt
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x float> @llvm.sqrt.v4f32(<4 x float> %{{[0-9]+}})
comment|// CHECK-LE: call<4 x float> @llvm.sqrt.v4f32(<4 x float> %{{[0-9]+}})
name|res_vd
operator|=
name|vec_sqrt
argument_list|(
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x double> @llvm.sqrt.v2f64(<2 x double> %{{[0-9]+}})
comment|// CHECK-LE: call<2 x double> @llvm.sqrt.v2f64(<2 x double> %{{[0-9]+}})
name|res_vd
operator|=
name|vec_sub
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: fsub<2 x double> %{{[0-9]+}}, %{{[0-9]+}}
comment|// CHECK-LE: fsub<2 x double> %{{[0-9]+}}, %{{[0-9]+}}
name|res_vf
operator|=
name|vec_trunc
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x float> @llvm.trunc.v4f32(<4 x float> %{{[0-9]+}})
comment|// CHECK-LE: call<4 x float> @llvm.trunc.v4f32(<4 x float> %{{[0-9]+}})
name|res_vd
operator|=
name|vec_trunc
argument_list|(
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x double> @llvm.trunc.v2f64(<2 x double> %{{[0-9]+}})
comment|// CHECK-LE: call<2 x double> @llvm.trunc.v2f64(<2 x double> %{{[0-9]+}})
comment|/* vec_vor */
name|res_vsll
operator|=
name|vec_vor
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: or<2 x i64>
comment|// CHECK-LE: or<2 x i64>
name|res_vsll
operator|=
name|vec_vor
argument_list|(
name|vbll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: or<2 x i64>
comment|// CHECK-LE: or<2 x i64>
name|res_vsll
operator|=
name|vec_vor
argument_list|(
name|vsll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: or<2 x i64>
comment|// CHECK-LE: or<2 x i64>
name|res_vull
operator|=
name|vec_vor
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: or<2 x i64>
comment|// CHECK-LE: or<2 x i64>
name|res_vull
operator|=
name|vec_vor
argument_list|(
name|vbll
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: or<2 x i64>
comment|// CHECK-LE: or<2 x i64>
name|res_vull
operator|=
name|vec_vor
argument_list|(
name|vull
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: or<2 x i64>
comment|// CHECK-LE: or<2 x i64>
name|res_vbll
operator|=
name|vec_vor
argument_list|(
name|vbll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: or<2 x i64>
comment|// CHECK-LE: or<2 x i64>
comment|/* vec_xor */
name|res_vsll
operator|=
name|vec_xor
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: xor<2 x i64>
comment|// CHECK-LE: xor<2 x i64>
name|res_vsll
operator|=
name|vec_xor
argument_list|(
name|vbll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: xor<2 x i64>
comment|// CHECK-LE: xor<2 x i64>
name|res_vsll
operator|=
name|vec_xor
argument_list|(
name|vsll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: xor<2 x i64>
comment|// CHECK-LE: xor<2 x i64>
name|res_vull
operator|=
name|vec_xor
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: xor<2 x i64>
comment|// CHECK-LE: xor<2 x i64>
name|res_vull
operator|=
name|vec_xor
argument_list|(
name|vbll
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: xor<2 x i64>
comment|// CHECK-LE: xor<2 x i64>
name|res_vull
operator|=
name|vec_xor
argument_list|(
name|vull
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: xor<2 x i64>
comment|// CHECK-LE: xor<2 x i64>
name|res_vbll
operator|=
name|vec_xor
argument_list|(
name|vbll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: xor<2 x i64>
comment|// CHECK-LE: xor<2 x i64>
name|dummy
argument_list|()
expr_stmt|;
comment|// CHECK: call void @dummy()
comment|// CHECK-LE: call void @dummy()
name|res_vd
operator|=
name|vec_xor
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: [[X1:%.+]] = xor<2 x i64> %{{[0-9]+}}, %{{[0-9]+}}
comment|// CHECK: bitcast<2 x i64> [[X1]] to<2 x double>
comment|// CHECK-LE: [[X1:%.+]] = xor<2 x i64> %{{[0-9]+}}, %{{[0-9]+}}
comment|// CHECK-LE: bitcast<2 x i64> [[X1]] to<2 x double>
name|dummy
argument_list|()
expr_stmt|;
comment|// CHECK: call void @dummy()
comment|// CHECK-LE: call void @dummy()
name|res_vd
operator|=
name|vec_xor
argument_list|(
name|vd
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: [[X1:%.+]] = xor<2 x i64> %{{[0-9]+}}, %{{[0-9]+}}
comment|// CHECK: bitcast<2 x i64> [[X1]] to<2 x double>
comment|// CHECK-LE: [[X1:%.+]] = xor<2 x i64> %{{[0-9]+}}, %{{[0-9]+}}
comment|// CHECK-LE: bitcast<2 x i64> [[X1]] to<2 x double>
name|dummy
argument_list|()
expr_stmt|;
comment|// CHECK: call void @dummy()
comment|// CHECK-LE: call void @dummy()
name|res_vd
operator|=
name|vec_xor
argument_list|(
name|vbll
argument_list|,
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: [[X1:%.+]] = xor<2 x i64> %{{[0-9]+}}, %{{[0-9]+}}
comment|// CHECK: bitcast<2 x i64> [[X1]] to<2 x double>
comment|// CHECK-LE: [[X1:%.+]] = xor<2 x i64> %{{[0-9]+}}, %{{[0-9]+}}
comment|// CHECK-LE: bitcast<2 x i64> [[X1]] to<2 x double>
comment|/* vec_vxor */
name|res_vsll
operator|=
name|vec_vxor
argument_list|(
name|vsll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: xor<2 x i64>
comment|// CHECK-LE: xor<2 x i64>
name|res_vsll
operator|=
name|vec_vxor
argument_list|(
name|vbll
argument_list|,
name|vsll
argument_list|)
expr_stmt|;
comment|// CHECK: xor<2 x i64>
comment|// CHECK-LE: xor<2 x i64>
name|res_vsll
operator|=
name|vec_vxor
argument_list|(
name|vsll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: xor<2 x i64>
comment|// CHECK-LE: xor<2 x i64>
name|res_vull
operator|=
name|vec_vxor
argument_list|(
name|vull
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: xor<2 x i64>
comment|// CHECK-LE: xor<2 x i64>
name|res_vull
operator|=
name|vec_vxor
argument_list|(
name|vbll
argument_list|,
name|vull
argument_list|)
expr_stmt|;
comment|// CHECK: xor<2 x i64>
comment|// CHECK-LE: xor<2 x i64>
name|res_vull
operator|=
name|vec_vxor
argument_list|(
name|vull
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: xor<2 x i64>
comment|// CHECK-LE: xor<2 x i64>
name|res_vbll
operator|=
name|vec_vxor
argument_list|(
name|vbll
argument_list|,
name|vbll
argument_list|)
expr_stmt|;
comment|// CHECK: xor<2 x i64>
comment|// CHECK-LE: xor<2 x i64>
block|}
end_function

end_unit

