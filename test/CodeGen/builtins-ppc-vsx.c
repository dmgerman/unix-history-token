begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -faltivec -target-feature +vsx -triple powerpc64-unknown-unknown -emit-llvm %s -o - | FileCheck %s
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
name|test1
parameter_list|()
block|{
comment|// CHECK-LABEL: define void @test1
comment|/* vec_div */
name|res_vf
operator|=
name|vec_div
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.xvdivsp
name|res_vd
operator|=
name|vec_div
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.vsx.xvdivdp
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
block|}
end_function

end_unit

