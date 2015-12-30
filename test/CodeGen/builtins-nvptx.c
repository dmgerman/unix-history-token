begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: nvptx-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple nvptx-unknown-unknown -fcuda-is-device -S -emit-llvm -o - -x cuda %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple nvptx64-unknown-unknown -fcuda-is-device -S -emit-llvm -o - -x cuda %s | FileCheck %s
end_comment

begin_define
define|#
directive|define
name|__device__
value|__attribute__((device))
end_define

begin_define
define|#
directive|define
name|__global__
value|__attribute__((global))
end_define

begin_define
define|#
directive|define
name|__shared__
value|__attribute__((shared))
end_define

begin_define
define|#
directive|define
name|__constant__
value|__attribute__((constant))
end_define

begin_function
name|__device__
name|int
name|read_tid
parameter_list|()
block|{
comment|// CHECK: call i32 @llvm.ptx.read.tid.x()
comment|// CHECK: call i32 @llvm.ptx.read.tid.y()
comment|// CHECK: call i32 @llvm.ptx.read.tid.z()
comment|// CHECK: call i32 @llvm.ptx.read.tid.w()
name|int
name|x
init|=
name|__builtin_ptx_read_tid_x
argument_list|()
decl_stmt|;
name|int
name|y
init|=
name|__builtin_ptx_read_tid_y
argument_list|()
decl_stmt|;
name|int
name|z
init|=
name|__builtin_ptx_read_tid_z
argument_list|()
decl_stmt|;
name|int
name|w
init|=
name|__builtin_ptx_read_tid_w
argument_list|()
decl_stmt|;
return|return
name|x
operator|+
name|y
operator|+
name|z
operator|+
name|w
return|;
block|}
end_function

begin_function
name|__device__
name|int
name|read_ntid
parameter_list|()
block|{
comment|// CHECK: call i32 @llvm.ptx.read.ntid.x()
comment|// CHECK: call i32 @llvm.ptx.read.ntid.y()
comment|// CHECK: call i32 @llvm.ptx.read.ntid.z()
comment|// CHECK: call i32 @llvm.ptx.read.ntid.w()
name|int
name|x
init|=
name|__builtin_ptx_read_ntid_x
argument_list|()
decl_stmt|;
name|int
name|y
init|=
name|__builtin_ptx_read_ntid_y
argument_list|()
decl_stmt|;
name|int
name|z
init|=
name|__builtin_ptx_read_ntid_z
argument_list|()
decl_stmt|;
name|int
name|w
init|=
name|__builtin_ptx_read_ntid_w
argument_list|()
decl_stmt|;
return|return
name|x
operator|+
name|y
operator|+
name|z
operator|+
name|w
return|;
block|}
end_function

begin_function
name|__device__
name|int
name|read_ctaid
parameter_list|()
block|{
comment|// CHECK: call i32 @llvm.ptx.read.ctaid.x()
comment|// CHECK: call i32 @llvm.ptx.read.ctaid.y()
comment|// CHECK: call i32 @llvm.ptx.read.ctaid.z()
comment|// CHECK: call i32 @llvm.ptx.read.ctaid.w()
name|int
name|x
init|=
name|__builtin_ptx_read_ctaid_x
argument_list|()
decl_stmt|;
name|int
name|y
init|=
name|__builtin_ptx_read_ctaid_y
argument_list|()
decl_stmt|;
name|int
name|z
init|=
name|__builtin_ptx_read_ctaid_z
argument_list|()
decl_stmt|;
name|int
name|w
init|=
name|__builtin_ptx_read_ctaid_w
argument_list|()
decl_stmt|;
return|return
name|x
operator|+
name|y
operator|+
name|z
operator|+
name|w
return|;
block|}
end_function

begin_function
name|__device__
name|int
name|read_nctaid
parameter_list|()
block|{
comment|// CHECK: call i32 @llvm.ptx.read.nctaid.x()
comment|// CHECK: call i32 @llvm.ptx.read.nctaid.y()
comment|// CHECK: call i32 @llvm.ptx.read.nctaid.z()
comment|// CHECK: call i32 @llvm.ptx.read.nctaid.w()
name|int
name|x
init|=
name|__builtin_ptx_read_nctaid_x
argument_list|()
decl_stmt|;
name|int
name|y
init|=
name|__builtin_ptx_read_nctaid_y
argument_list|()
decl_stmt|;
name|int
name|z
init|=
name|__builtin_ptx_read_nctaid_z
argument_list|()
decl_stmt|;
name|int
name|w
init|=
name|__builtin_ptx_read_nctaid_w
argument_list|()
decl_stmt|;
return|return
name|x
operator|+
name|y
operator|+
name|z
operator|+
name|w
return|;
block|}
end_function

begin_function
name|__device__
name|int
name|read_ids
parameter_list|()
block|{
comment|// CHECK: call i32 @llvm.ptx.read.laneid()
comment|// CHECK: call i32 @llvm.ptx.read.warpid()
comment|// CHECK: call i32 @llvm.ptx.read.nwarpid()
comment|// CHECK: call i32 @llvm.ptx.read.smid()
comment|// CHECK: call i32 @llvm.ptx.read.nsmid()
comment|// CHECK: call i32 @llvm.ptx.read.gridid()
name|int
name|a
init|=
name|__builtin_ptx_read_laneid
argument_list|()
decl_stmt|;
name|int
name|b
init|=
name|__builtin_ptx_read_warpid
argument_list|()
decl_stmt|;
name|int
name|c
init|=
name|__builtin_ptx_read_nwarpid
argument_list|()
decl_stmt|;
name|int
name|d
init|=
name|__builtin_ptx_read_smid
argument_list|()
decl_stmt|;
name|int
name|e
init|=
name|__builtin_ptx_read_nsmid
argument_list|()
decl_stmt|;
name|int
name|f
init|=
name|__builtin_ptx_read_gridid
argument_list|()
decl_stmt|;
return|return
name|a
operator|+
name|b
operator|+
name|c
operator|+
name|d
operator|+
name|e
operator|+
name|f
return|;
block|}
end_function

begin_function
name|__device__
name|int
name|read_lanemasks
parameter_list|()
block|{
comment|// CHECK: call i32 @llvm.ptx.read.lanemask.eq()
comment|// CHECK: call i32 @llvm.ptx.read.lanemask.le()
comment|// CHECK: call i32 @llvm.ptx.read.lanemask.lt()
comment|// CHECK: call i32 @llvm.ptx.read.lanemask.ge()
comment|// CHECK: call i32 @llvm.ptx.read.lanemask.gt()
name|int
name|a
init|=
name|__builtin_ptx_read_lanemask_eq
argument_list|()
decl_stmt|;
name|int
name|b
init|=
name|__builtin_ptx_read_lanemask_le
argument_list|()
decl_stmt|;
name|int
name|c
init|=
name|__builtin_ptx_read_lanemask_lt
argument_list|()
decl_stmt|;
name|int
name|d
init|=
name|__builtin_ptx_read_lanemask_ge
argument_list|()
decl_stmt|;
name|int
name|e
init|=
name|__builtin_ptx_read_lanemask_gt
argument_list|()
decl_stmt|;
return|return
name|a
operator|+
name|b
operator|+
name|c
operator|+
name|d
operator|+
name|e
return|;
block|}
end_function

begin_function
name|__device__
name|long
name|long
name|read_clocks
parameter_list|()
block|{
comment|// CHECK: call i32 @llvm.ptx.read.clock()
comment|// CHECK: call i64 @llvm.ptx.read.clock64()
name|int
name|a
init|=
name|__builtin_ptx_read_clock
argument_list|()
decl_stmt|;
name|long
name|long
name|b
init|=
name|__builtin_ptx_read_clock64
argument_list|()
decl_stmt|;
return|return
name|a
operator|+
name|b
return|;
block|}
end_function

begin_function
name|__device__
name|int
name|read_pms
parameter_list|()
block|{
comment|// CHECK: call i32 @llvm.ptx.read.pm0()
comment|// CHECK: call i32 @llvm.ptx.read.pm1()
comment|// CHECK: call i32 @llvm.ptx.read.pm2()
comment|// CHECK: call i32 @llvm.ptx.read.pm3()
name|int
name|a
init|=
name|__builtin_ptx_read_pm0
argument_list|()
decl_stmt|;
name|int
name|b
init|=
name|__builtin_ptx_read_pm1
argument_list|()
decl_stmt|;
name|int
name|c
init|=
name|__builtin_ptx_read_pm2
argument_list|()
decl_stmt|;
name|int
name|d
init|=
name|__builtin_ptx_read_pm3
argument_list|()
decl_stmt|;
return|return
name|a
operator|+
name|b
operator|+
name|c
operator|+
name|d
return|;
block|}
end_function

begin_function
name|__device__
name|void
name|sync
parameter_list|()
block|{
comment|// CHECK: call void @llvm.ptx.bar.sync(i32 0)
name|__builtin_ptx_bar_sync
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// NVVM intrinsics
end_comment

begin_comment
comment|// The idea is not to test all intrinsics, just that Clang is recognizing the
end_comment

begin_comment
comment|// builtins defined in BuiltinsNVPTX.def
end_comment

begin_function
name|__device__
name|void
name|nvvm_math
parameter_list|(
name|float
name|f1
parameter_list|,
name|float
name|f2
parameter_list|,
name|double
name|d1
parameter_list|,
name|double
name|d2
parameter_list|)
block|{
comment|// CHECK: call float @llvm.nvvm.fmax.f
name|float
name|t1
init|=
name|__nvvm_fmax_f
argument_list|(
name|f1
argument_list|,
name|f2
argument_list|)
decl_stmt|;
comment|// CHECK: call float @llvm.nvvm.fmin.f
name|float
name|t2
init|=
name|__nvvm_fmin_f
argument_list|(
name|f1
argument_list|,
name|f2
argument_list|)
decl_stmt|;
comment|// CHECK: call float @llvm.nvvm.sqrt.rn.f
name|float
name|t3
init|=
name|__nvvm_sqrt_rn_f
argument_list|(
name|f1
argument_list|)
decl_stmt|;
comment|// CHECK: call float @llvm.nvvm.rcp.rn.f
name|float
name|t4
init|=
name|__nvvm_rcp_rn_f
argument_list|(
name|f2
argument_list|)
decl_stmt|;
comment|// CHECK: call float @llvm.nvvm.add.rn.f
name|float
name|t5
init|=
name|__nvvm_add_rn_f
argument_list|(
name|f1
argument_list|,
name|f2
argument_list|)
decl_stmt|;
comment|// CHECK: call double @llvm.nvvm.fmax.d
name|double
name|td1
init|=
name|__nvvm_fmax_d
argument_list|(
name|d1
argument_list|,
name|d2
argument_list|)
decl_stmt|;
comment|// CHECK: call double @llvm.nvvm.fmin.d
name|double
name|td2
init|=
name|__nvvm_fmin_d
argument_list|(
name|d1
argument_list|,
name|d2
argument_list|)
decl_stmt|;
comment|// CHECK: call double @llvm.nvvm.sqrt.rn.d
name|double
name|td3
init|=
name|__nvvm_sqrt_rn_d
argument_list|(
name|d1
argument_list|)
decl_stmt|;
comment|// CHECK: call double @llvm.nvvm.rcp.rn.d
name|double
name|td4
init|=
name|__nvvm_rcp_rn_d
argument_list|(
name|d2
argument_list|)
decl_stmt|;
comment|// CHECK: call void @llvm.nvvm.membar.cta()
name|__nvvm_membar_cta
argument_list|()
expr_stmt|;
comment|// CHECK: call void @llvm.nvvm.membar.gl()
name|__nvvm_membar_gl
argument_list|()
expr_stmt|;
comment|// CHECK: call void @llvm.nvvm.membar.sys()
name|__nvvm_membar_sys
argument_list|()
expr_stmt|;
comment|// CHECK: call void @llvm.nvvm.barrier0()
name|__nvvm_bar0
argument_list|()
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|__device__
name|int
name|di
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__shared__
name|int
name|si
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__device__
name|long
name|dl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__shared__
name|long
name|sl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__device__
name|long
name|long
name|dll
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__shared__
name|long
name|long
name|sll
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Check for atomic intrinsics
end_comment

begin_comment
comment|// CHECK-LABEL: nvvm_atom
end_comment

begin_function
name|__device__
name|void
name|nvvm_atom
parameter_list|(
name|float
modifier|*
name|fp
parameter_list|,
name|float
name|f
parameter_list|,
name|int
modifier|*
name|ip
parameter_list|,
name|int
name|i
parameter_list|,
name|long
modifier|*
name|lp
parameter_list|,
name|long
name|l
parameter_list|,
name|long
name|long
modifier|*
name|llp
parameter_list|,
name|long
name|long
name|ll
parameter_list|)
block|{
comment|// CHECK: atomicrmw add
name|__nvvm_atom_add_gen_i
argument_list|(
name|ip
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw add
name|__nvvm_atom_add_gen_l
argument_list|(
operator|&
name|dl
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw add
name|__nvvm_atom_add_gen_ll
argument_list|(
operator|&
name|sll
argument_list|,
name|ll
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw sub
name|__nvvm_atom_sub_gen_i
argument_list|(
name|ip
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw sub
name|__nvvm_atom_sub_gen_l
argument_list|(
operator|&
name|dl
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw sub
name|__nvvm_atom_sub_gen_ll
argument_list|(
operator|&
name|sll
argument_list|,
name|ll
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw and
name|__nvvm_atom_and_gen_i
argument_list|(
name|ip
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw and
name|__nvvm_atom_and_gen_l
argument_list|(
operator|&
name|dl
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw and
name|__nvvm_atom_and_gen_ll
argument_list|(
operator|&
name|sll
argument_list|,
name|ll
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw or
name|__nvvm_atom_or_gen_i
argument_list|(
name|ip
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw or
name|__nvvm_atom_or_gen_l
argument_list|(
operator|&
name|dl
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw or
name|__nvvm_atom_or_gen_ll
argument_list|(
operator|&
name|sll
argument_list|,
name|ll
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xor
name|__nvvm_atom_xor_gen_i
argument_list|(
name|ip
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xor
name|__nvvm_atom_xor_gen_l
argument_list|(
operator|&
name|dl
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xor
name|__nvvm_atom_xor_gen_ll
argument_list|(
operator|&
name|sll
argument_list|,
name|ll
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xchg
name|__nvvm_atom_xchg_gen_i
argument_list|(
name|ip
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xchg
name|__nvvm_atom_xchg_gen_l
argument_list|(
operator|&
name|dl
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xchg
name|__nvvm_atom_xchg_gen_ll
argument_list|(
operator|&
name|sll
argument_list|,
name|ll
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw max i32*
name|__nvvm_atom_max_gen_i
argument_list|(
name|ip
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw umax i32*
name|__nvvm_atom_max_gen_ui
argument_list|(
operator|(
name|unsigned
name|int
operator|*
operator|)
name|ip
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw max
name|__nvvm_atom_max_gen_l
argument_list|(
operator|&
name|dl
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw umax
name|__nvvm_atom_max_gen_ul
argument_list|(
operator|(
name|unsigned
name|long
operator|*
operator|)
operator|&
name|dl
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw max i64*
name|__nvvm_atom_max_gen_ll
argument_list|(
operator|&
name|sll
argument_list|,
name|ll
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw umax i64*
name|__nvvm_atom_max_gen_ull
argument_list|(
operator|(
name|unsigned
name|long
name|long
operator|*
operator|)
operator|&
name|sll
argument_list|,
name|ll
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw min i32*
name|__nvvm_atom_min_gen_i
argument_list|(
name|ip
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw umin i32*
name|__nvvm_atom_min_gen_ui
argument_list|(
operator|(
name|unsigned
name|int
operator|*
operator|)
name|ip
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw min
name|__nvvm_atom_min_gen_l
argument_list|(
operator|&
name|dl
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw umin
name|__nvvm_atom_min_gen_ul
argument_list|(
operator|(
name|unsigned
name|long
operator|*
operator|)
operator|&
name|dl
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw min i64*
name|__nvvm_atom_min_gen_ll
argument_list|(
operator|&
name|sll
argument_list|,
name|ll
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw umin i64*
name|__nvvm_atom_min_gen_ull
argument_list|(
operator|(
name|unsigned
name|long
name|long
operator|*
operator|)
operator|&
name|sll
argument_list|,
name|ll
argument_list|)
expr_stmt|;
comment|// CHECK: cmpxchg
comment|// CHECK-NEXT: extractvalue { i32, i1 } {{%[0-9]+}}, 0
name|__nvvm_atom_cas_gen_i
argument_list|(
name|ip
argument_list|,
literal|0
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// CHECK: cmpxchg
comment|// CHECK-NEXT: extractvalue { {{i32|i64}}, i1 } {{%[0-9]+}}, 0
name|__nvvm_atom_cas_gen_l
argument_list|(
operator|&
name|dl
argument_list|,
literal|0
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// CHECK: cmpxchg
comment|// CHECK-NEXT: extractvalue { i64, i1 } {{%[0-9]+}}, 0
name|__nvvm_atom_cas_gen_ll
argument_list|(
operator|&
name|sll
argument_list|,
literal|0
argument_list|,
name|ll
argument_list|)
expr_stmt|;
comment|// CHECK: call float @llvm.nvvm.atomic.load.add.f32.p0f32
name|__nvvm_atom_add_gen_f
argument_list|(
name|fp
argument_list|,
name|f
argument_list|)
expr_stmt|;
comment|// CHECK: ret
block|}
end_function

end_unit

