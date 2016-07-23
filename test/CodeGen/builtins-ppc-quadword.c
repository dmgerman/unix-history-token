begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -faltivec -target-feature +power8-vector \
end_comment

begin_comment
comment|// RUN: -triple powerpc64-unknown-unknown -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -faltivec -target-feature +power8-vector \
end_comment

begin_comment
comment|// RUN: -triple powerpc64le-unknown-unknown -emit-llvm %s -o - \
end_comment

begin_comment
comment|// RUN: | FileCheck %s -check-prefix=CHECK-LE
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -faltivec -triple powerpc-unknown-unknown \
end_comment

begin_comment
comment|// RUN: -emit-llvm %s -o - 2>&1 | FileCheck %s -check-prefix=CHECK-PPC
end_comment

begin_include
include|#
directive|include
file|<altivec.h>
end_include

begin_comment
comment|// CHECK-PPC: error: __int128 is not supported on this target
end_comment

begin_decl_stmt
name|vector
name|signed
name|__int128
name|vlll
init|=
block|{
operator|-
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-PPC: error: __int128 is not supported on this target
end_comment

begin_decl_stmt
name|vector
name|unsigned
name|__int128
name|vulll
init|=
block|{
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-PPC: error: __int128 is not supported on this target
end_comment

begin_decl_stmt
name|vector
name|signed
name|__int128
name|res_vlll
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-PPC: error: __int128 is not supported on this target
end_comment

begin_decl_stmt
name|vector
name|unsigned
name|__int128
name|res_vulll
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
comment|/* vec_add */
name|res_vlll
operator|=
name|vec_add
argument_list|(
name|vlll
argument_list|,
name|vlll
argument_list|)
expr_stmt|;
comment|// CHECK: add<1 x i128>
comment|// CHECK-LE: add<1 x i128>
comment|// CHECK-PPC: error: call to 'vec_add' is ambiguous
name|res_vulll
operator|=
name|vec_add
argument_list|(
name|vulll
argument_list|,
name|vulll
argument_list|)
expr_stmt|;
comment|// CHECK: add<1 x i128>
comment|// CHECK-LE: add<1 x i128>
comment|// CHECK-PPC: error: call to 'vec_add' is ambiguous
comment|/* vec_vadduqm */
name|res_vlll
operator|=
name|vec_vadduqm
argument_list|(
name|vlll
argument_list|,
name|vlll
argument_list|)
expr_stmt|;
comment|// CHECK: add<1 x i128>
comment|// CHECK-LE: add<1 x i128>
comment|// CHECK-PPC: error: assigning to '__vector __int128' (vector of 1 '__int128' value) from incompatible type 'int'
name|res_vulll
operator|=
name|vec_vadduqm
argument_list|(
name|vulll
argument_list|,
name|vulll
argument_list|)
expr_stmt|;
comment|// CHECK: add<1 x i128>
comment|// CHECK-LE: add<1 x i128>
comment|// CHECK-PPC: error: assigning to '__vector unsigned __int128' (vector of 1 'unsigned __int128' value) from incompatible type 'int'
comment|/* vec_vaddeuqm */
name|res_vlll
operator|=
name|vec_vaddeuqm
argument_list|(
name|vlll
argument_list|,
name|vlll
argument_list|,
name|vlll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddeuqm
comment|// CHECK-LE: @llvm.ppc.altivec.vaddeuqm
comment|// CHECK-PPC: error: assigning to '__vector __int128' (vector of 1 '__int128' value) from incompatible type 'int'
name|res_vulll
operator|=
name|vec_vaddeuqm
argument_list|(
name|vulll
argument_list|,
name|vulll
argument_list|,
name|vulll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddeuqm
comment|// CHECK-LE: @llvm.ppc.altivec.vaddeuqm
comment|// CHECK-PPC: error: assigning to '__vector unsigned __int128' (vector of 1 'unsigned __int128' value) from incompatible type 'int'
comment|/* vec_addc */
name|res_vlll
operator|=
name|vec_addc
argument_list|(
name|vlll
argument_list|,
name|vlll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddcuq
comment|// CHECK-LE: @llvm.ppc.altivec.vaddcuq
comment|// KCHECK-PPC: error: call to 'vec_addc' is ambiguous
name|res_vulll
operator|=
name|vec_addc
argument_list|(
name|vulll
argument_list|,
name|vulll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddcuq
comment|// CHECK-LE: @llvm.ppc.altivec.vaddcuq
comment|// KCHECK-PPC: error: call to 'vec_addc' is ambiguous
comment|/* vec_vaddcuq */
name|res_vlll
operator|=
name|vec_vaddcuq
argument_list|(
name|vlll
argument_list|,
name|vlll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddcuq
comment|// CHECK-LE: @llvm.ppc.altivec.vaddcuq
comment|// CHECK-PPC: error: assigning to '__vector __int128' (vector of 1 '__int128' value) from incompatible type 'int'
name|res_vulll
operator|=
name|vec_vaddcuq
argument_list|(
name|vulll
argument_list|,
name|vulll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddcuq
comment|// CHECK-LE: @llvm.ppc.altivec.vaddcuq
comment|// CHECK-PPC: error: assigning to '__vector unsigned __int128' (vector of 1 'unsigned __int128' value) from incompatible type 'int'
comment|/* vec_vaddecuq */
name|res_vlll
operator|=
name|vec_vaddecuq
argument_list|(
name|vlll
argument_list|,
name|vlll
argument_list|,
name|vlll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddecuq
comment|// CHECK-LE: @llvm.ppc.altivec.vaddecuq
comment|// CHECK-PPC: error: assigning to '__vector __int128' (vector of 1 '__int128' value) from incompatible type 'int'
name|res_vulll
operator|=
name|vec_vaddecuq
argument_list|(
name|vulll
argument_list|,
name|vulll
argument_list|,
name|vulll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vaddecuq
comment|// CHECK-LE: @llvm.ppc.altivec.vaddecuq
comment|// CHECK-PPC: error: assigning to '__vector unsigned __int128' (vector of 1 'unsigned __int128' value) from incompatible type 'int'
comment|/* vec_sub */
name|res_vlll
operator|=
name|vec_sub
argument_list|(
name|vlll
argument_list|,
name|vlll
argument_list|)
expr_stmt|;
comment|// CHECK: sub<1 x i128>
comment|// CHECK-LE: sub<1 x i128>
comment|// CHECK-PPC: error: call to 'vec_sub' is ambiguous
name|res_vulll
operator|=
name|vec_sub
argument_list|(
name|vulll
argument_list|,
name|vulll
argument_list|)
expr_stmt|;
comment|// CHECK: sub<1 x i128>
comment|// CHECK-LE: sub<1 x i128>
comment|// CHECK-PPC: error: call to 'vec_sub' is ambiguous
comment|/* vec_vsubuqm */
name|res_vlll
operator|=
name|vec_vsubuqm
argument_list|(
name|vlll
argument_list|,
name|vlll
argument_list|)
expr_stmt|;
comment|// CHECK: sub<1 x i128>
comment|// CHECK-LE: sub<1 x i128>
comment|// CHECK-PPC: error: assigning to '__vector __int128' (vector of 1 '__int128' value) from incompatible type 'int'
name|res_vulll
operator|=
name|vec_vsubuqm
argument_list|(
name|vulll
argument_list|,
name|vulll
argument_list|)
expr_stmt|;
comment|// CHECK: sub<1 x i128>
comment|// CHECK-LE: sub<1 x i128>
comment|// CHECK-PPC: error: assigning to '__vector unsigned __int128' (vector of 1 'unsigned __int128' value) from incompatible type 'int'
comment|/* vec_vsubeuqm */
name|res_vlll
operator|=
name|vec_vsubeuqm
argument_list|(
name|vlll
argument_list|,
name|vlll
argument_list|,
name|vlll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubeuqm
comment|// CHECK-LE: @llvm.ppc.altivec.vsubeuqm
comment|// CHECK-PPC: error: assigning to '__vector __int128' (vector of 1 '__int128' value) from incompatible type 'int'
name|res_vulll
operator|=
name|vec_vsubeuqm
argument_list|(
name|vulll
argument_list|,
name|vulll
argument_list|,
name|vulll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubeuqm
comment|// CHECK-LE: @llvm.ppc.altivec.vsubeuqm
comment|// CHECK-PPC: error: assigning to '__vector unsigned __int128' (vector of 1 'unsigned __int128' value) from incompatible type 'int'
comment|/* vec_subc */
name|res_vlll
operator|=
name|vec_subc
argument_list|(
name|vlll
argument_list|,
name|vlll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubcuq
comment|// CHECK-LE: @llvm.ppc.altivec.vsubcuq
comment|// KCHECK-PPC: error: call to 'vec_subc' is ambiguous
name|res_vulll
operator|=
name|vec_subc
argument_list|(
name|vulll
argument_list|,
name|vulll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubcuq
comment|// CHECK-LE: @llvm.ppc.altivec.vsubcuq
comment|// KCHECK-PPC: error: call to 'vec_subc' is ambiguous
comment|/* vec_vsubcuq */
name|res_vlll
operator|=
name|vec_vsubcuq
argument_list|(
name|vlll
argument_list|,
name|vlll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubcuq
comment|// CHECK-LE: @llvm.ppc.altivec.vsubcuq
comment|// CHECK-PPC: error: assigning to '__vector __int128' (vector of 1 '__int128' value) from incompatible type 'int'
name|res_vulll
operator|=
name|vec_vsubcuq
argument_list|(
name|vulll
argument_list|,
name|vulll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubcuq
comment|// CHECK-LE: @llvm.ppc.altivec.vsubcuq
comment|// CHECK-PPC: error: assigning to '__vector unsigned __int128' (vector of 1 'unsigned __int128' value) from incompatible type 'int'
comment|/* vec_vsubecuq */
name|res_vlll
operator|=
name|vec_vsubecuq
argument_list|(
name|vlll
argument_list|,
name|vlll
argument_list|,
name|vlll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubecuq
comment|// CHECK-LE: @llvm.ppc.altivec.vsubecuq
comment|// CHECK-PPC: error: assigning to '__vector __int128' (vector of 1 '__int128' value) from incompatible type 'int'
name|res_vulll
operator|=
name|vec_vsubecuq
argument_list|(
name|vulll
argument_list|,
name|vulll
argument_list|,
name|vulll
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.altivec.vsubecuq
comment|// CHECK-LE: @llvm.ppc.altivec.vsubecuq
comment|// CHECK-PPC: error: assigning to '__vector unsigned __int128' (vector of 1 'unsigned __int128' value) from incompatible type 'int'
block|}
end_function

end_unit

