begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -faltivec -target-feature +power8-vector -triple powerpc64-unknown-unknown -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -faltivec -target-feature +power8-vector -triple powerpc64le-unknown-unknown -emit-llvm %s -o - | FileCheck %s -check-prefix=CHECK-LE
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -faltivec -triple powerpc64-unknown-unknown -emit-llvm %s -o - 2>&1 | FileCheck %s -check-prefix=CHECK-PPC
end_comment

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
name|int
name|res_i
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

begin_comment
comment|// CHECK-LABEL: define void @test1
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
comment|/* vec_cmpeq */
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
name|vi
argument_list|,
name|vi
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
name|vi
argument_list|,
name|vi
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
name|res_vi
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
comment|// CHECK: ashr<2 x i64>
comment|// CHECK-LE: ashr<2 x i64>
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
comment|/* vec_unpackh */
name|res_vsll
operator|=
name|vec_unpackh
argument_list|(
name|vi
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
name|vi
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
name|res_vi
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
name|res_vi
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
name|vi
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
name|vi
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
block|}
end_function

end_unit

