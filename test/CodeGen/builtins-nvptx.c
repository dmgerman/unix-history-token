begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: nvptx-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple nvptx-unknown-unknown -target-cpu sm_60 \
end_comment

begin_comment
comment|// RUN:            -fcuda-is-device -S -emit-llvm -o - -x cuda %s \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK -check-prefix=LP32 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple nvptx64-unknown-unknown -target-cpu sm_60 \
end_comment

begin_comment
comment|// RUN:            -fcuda-is-device -S -emit-llvm -o - -x cuda %s \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK -check-prefix=LP64 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple nvptx-unknown-unknown -target-cpu sm_53 \
end_comment

begin_comment
comment|// RUN:   -DERROR_CHECK -fcuda-is-device -S -o /dev/null -x cuda -verify %s
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
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.tid.x()
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.tid.y()
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.tid.z()
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.tid.w()
name|int
name|x
init|=
name|__nvvm_read_ptx_sreg_tid_x
argument_list|()
decl_stmt|;
name|int
name|y
init|=
name|__nvvm_read_ptx_sreg_tid_y
argument_list|()
decl_stmt|;
name|int
name|z
init|=
name|__nvvm_read_ptx_sreg_tid_z
argument_list|()
decl_stmt|;
name|int
name|w
init|=
name|__nvvm_read_ptx_sreg_tid_w
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
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.ntid.x()
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.ntid.y()
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.ntid.z()
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.ntid.w()
name|int
name|x
init|=
name|__nvvm_read_ptx_sreg_ntid_x
argument_list|()
decl_stmt|;
name|int
name|y
init|=
name|__nvvm_read_ptx_sreg_ntid_y
argument_list|()
decl_stmt|;
name|int
name|z
init|=
name|__nvvm_read_ptx_sreg_ntid_z
argument_list|()
decl_stmt|;
name|int
name|w
init|=
name|__nvvm_read_ptx_sreg_ntid_w
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
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.ctaid.x()
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.ctaid.y()
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.ctaid.z()
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.ctaid.w()
name|int
name|x
init|=
name|__nvvm_read_ptx_sreg_ctaid_x
argument_list|()
decl_stmt|;
name|int
name|y
init|=
name|__nvvm_read_ptx_sreg_ctaid_y
argument_list|()
decl_stmt|;
name|int
name|z
init|=
name|__nvvm_read_ptx_sreg_ctaid_z
argument_list|()
decl_stmt|;
name|int
name|w
init|=
name|__nvvm_read_ptx_sreg_ctaid_w
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
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.nctaid.x()
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.nctaid.y()
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.nctaid.z()
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.nctaid.w()
name|int
name|x
init|=
name|__nvvm_read_ptx_sreg_nctaid_x
argument_list|()
decl_stmt|;
name|int
name|y
init|=
name|__nvvm_read_ptx_sreg_nctaid_y
argument_list|()
decl_stmt|;
name|int
name|z
init|=
name|__nvvm_read_ptx_sreg_nctaid_z
argument_list|()
decl_stmt|;
name|int
name|w
init|=
name|__nvvm_read_ptx_sreg_nctaid_w
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
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.laneid()
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.warpid()
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.nwarpid()
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.smid()
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.nsmid()
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.gridid()
name|int
name|a
init|=
name|__nvvm_read_ptx_sreg_laneid
argument_list|()
decl_stmt|;
name|int
name|b
init|=
name|__nvvm_read_ptx_sreg_warpid
argument_list|()
decl_stmt|;
name|int
name|c
init|=
name|__nvvm_read_ptx_sreg_nwarpid
argument_list|()
decl_stmt|;
name|int
name|d
init|=
name|__nvvm_read_ptx_sreg_smid
argument_list|()
decl_stmt|;
name|int
name|e
init|=
name|__nvvm_read_ptx_sreg_nsmid
argument_list|()
decl_stmt|;
name|int
name|f
init|=
name|__nvvm_read_ptx_sreg_gridid
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
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.lanemask.eq()
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.lanemask.le()
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.lanemask.lt()
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.lanemask.ge()
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.lanemask.gt()
name|int
name|a
init|=
name|__nvvm_read_ptx_sreg_lanemask_eq
argument_list|()
decl_stmt|;
name|int
name|b
init|=
name|__nvvm_read_ptx_sreg_lanemask_le
argument_list|()
decl_stmt|;
name|int
name|c
init|=
name|__nvvm_read_ptx_sreg_lanemask_lt
argument_list|()
decl_stmt|;
name|int
name|d
init|=
name|__nvvm_read_ptx_sreg_lanemask_ge
argument_list|()
decl_stmt|;
name|int
name|e
init|=
name|__nvvm_read_ptx_sreg_lanemask_gt
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
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.clock()
comment|// CHECK: call i64 @llvm.nvvm.read.ptx.sreg.clock64()
name|int
name|a
init|=
name|__nvvm_read_ptx_sreg_clock
argument_list|()
decl_stmt|;
name|long
name|long
name|b
init|=
name|__nvvm_read_ptx_sreg_clock64
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
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.pm0()
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.pm1()
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.pm2()
comment|// CHECK: call i32 @llvm.nvvm.read.ptx.sreg.pm3()
name|int
name|a
init|=
name|__nvvm_read_ptx_sreg_pm0
argument_list|()
decl_stmt|;
name|int
name|b
init|=
name|__nvvm_read_ptx_sreg_pm1
argument_list|()
decl_stmt|;
name|int
name|c
init|=
name|__nvvm_read_ptx_sreg_pm2
argument_list|()
decl_stmt|;
name|int
name|d
init|=
name|__nvvm_read_ptx_sreg_pm3
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
comment|// CHECK: call void @llvm.nvvm.bar.sync(i32 0)
name|__nvvm_bar_sync
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
name|__syncthreads
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
name|double
modifier|*
name|dfp
parameter_list|,
name|double
name|df
parameter_list|,
name|int
modifier|*
name|ip
parameter_list|,
name|int
name|i
parameter_list|,
name|unsigned
name|int
modifier|*
name|uip
parameter_list|,
name|unsigned
name|ui
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
comment|// CHECK: call i32 @llvm.nvvm.atomic.load.inc.32.p0i32
name|__nvvm_atom_inc_gen_ui
argument_list|(
name|uip
argument_list|,
name|ui
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.nvvm.atomic.load.dec.32.p0i32
name|__nvvm_atom_dec_gen_ui
argument_list|(
name|uip
argument_list|,
name|ui
argument_list|)
expr_stmt|;
comment|//////////////////////////////////////////////////////////////////
comment|// Atomics with scope (only supported on sm_60+).
if|#
directive|if
name|ERROR_CHECK
operator|||
name|__CUDA_ARCH__
operator|>=
literal|600
comment|// CHECK: call i32 @llvm.nvvm.atomic.add.gen.i.cta.i32.p0i32
comment|// expected-error@+1 {{'__nvvm_atom_cta_add_gen_i' needs target feature satom}}
name|__nvvm_atom_cta_add_gen_i
argument_list|(
name|ip
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// LP32: call i32 @llvm.nvvm.atomic.add.gen.i.cta.i32.p0i32
comment|// LP64: call i64 @llvm.nvvm.atomic.add.gen.i.cta.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_cta_add_gen_l' needs target feature satom}}
name|__nvvm_atom_cta_add_gen_l
argument_list|(
operator|&
name|dl
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.nvvm.atomic.add.gen.i.cta.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_cta_add_gen_ll' needs target feature satom}}
name|__nvvm_atom_cta_add_gen_ll
argument_list|(
operator|&
name|sll
argument_list|,
name|ll
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.nvvm.atomic.add.gen.i.sys.i32.p0i32
comment|// expected-error@+1 {{'__nvvm_atom_sys_add_gen_i' needs target feature satom}}
name|__nvvm_atom_sys_add_gen_i
argument_list|(
name|ip
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// LP32: call i32 @llvm.nvvm.atomic.add.gen.i.sys.i32.p0i32
comment|// LP64: call i64 @llvm.nvvm.atomic.add.gen.i.sys.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_sys_add_gen_l' needs target feature satom}}
name|__nvvm_atom_sys_add_gen_l
argument_list|(
operator|&
name|dl
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.nvvm.atomic.add.gen.i.sys.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_sys_add_gen_ll' needs target feature satom}}
name|__nvvm_atom_sys_add_gen_ll
argument_list|(
operator|&
name|sll
argument_list|,
name|ll
argument_list|)
expr_stmt|;
comment|// CHECK: call float @llvm.nvvm.atomic.add.gen.f.cta.f32.p0f32
comment|// expected-error@+1 {{'__nvvm_atom_cta_add_gen_f' needs target feature satom}}
name|__nvvm_atom_cta_add_gen_f
argument_list|(
name|fp
argument_list|,
name|f
argument_list|)
expr_stmt|;
comment|// CHECK: call double @llvm.nvvm.atomic.add.gen.f.cta.f64.p0f64
comment|// expected-error@+1 {{'__nvvm_atom_cta_add_gen_d' needs target feature satom}}
name|__nvvm_atom_cta_add_gen_d
argument_list|(
name|dfp
argument_list|,
name|df
argument_list|)
expr_stmt|;
comment|// CHECK: call float @llvm.nvvm.atomic.add.gen.f.sys.f32.p0f32
comment|// expected-error@+1 {{'__nvvm_atom_sys_add_gen_f' needs target feature satom}}
name|__nvvm_atom_sys_add_gen_f
argument_list|(
name|fp
argument_list|,
name|f
argument_list|)
expr_stmt|;
comment|// CHECK: call double @llvm.nvvm.atomic.add.gen.f.sys.f64.p0f64
comment|// expected-error@+1 {{'__nvvm_atom_sys_add_gen_d' needs target feature satom}}
name|__nvvm_atom_sys_add_gen_d
argument_list|(
name|dfp
argument_list|,
name|df
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.nvvm.atomic.exch.gen.i.cta.i32.p0i32
comment|// expected-error@+1 {{'__nvvm_atom_cta_xchg_gen_i' needs target feature satom}}
name|__nvvm_atom_cta_xchg_gen_i
argument_list|(
name|ip
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// LP32: call i32 @llvm.nvvm.atomic.exch.gen.i.cta.i32.p0i32
comment|// LP64: call i64 @llvm.nvvm.atomic.exch.gen.i.cta.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_cta_xchg_gen_l' needs target feature satom}}
name|__nvvm_atom_cta_xchg_gen_l
argument_list|(
operator|&
name|dl
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.nvvm.atomic.exch.gen.i.cta.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_cta_xchg_gen_ll' needs target feature satom}}
name|__nvvm_atom_cta_xchg_gen_ll
argument_list|(
operator|&
name|sll
argument_list|,
name|ll
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.nvvm.atomic.exch.gen.i.sys.i32.p0i32
comment|// expected-error@+1 {{'__nvvm_atom_sys_xchg_gen_i' needs target feature satom}}
name|__nvvm_atom_sys_xchg_gen_i
argument_list|(
name|ip
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// LP32: call i32 @llvm.nvvm.atomic.exch.gen.i.sys.i32.p0i32
comment|// LP64: call i64 @llvm.nvvm.atomic.exch.gen.i.sys.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_sys_xchg_gen_l' needs target feature satom}}
name|__nvvm_atom_sys_xchg_gen_l
argument_list|(
operator|&
name|dl
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.nvvm.atomic.exch.gen.i.sys.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_sys_xchg_gen_ll' needs target feature satom}}
name|__nvvm_atom_sys_xchg_gen_ll
argument_list|(
operator|&
name|sll
argument_list|,
name|ll
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.nvvm.atomic.max.gen.i.cta.i32.p0i32
comment|// expected-error@+1 {{'__nvvm_atom_cta_max_gen_i' needs target feature satom}}
name|__nvvm_atom_cta_max_gen_i
argument_list|(
name|ip
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.nvvm.atomic.max.gen.i.cta.i32.p0i32
comment|// expected-error@+1 {{'__nvvm_atom_cta_max_gen_ui' needs target feature satom}}
name|__nvvm_atom_cta_max_gen_ui
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
comment|// LP32: call i32 @llvm.nvvm.atomic.max.gen.i.cta.i32.p0i32
comment|// LP64: call i64 @llvm.nvvm.atomic.max.gen.i.cta.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_cta_max_gen_l' needs target feature satom}}
name|__nvvm_atom_cta_max_gen_l
argument_list|(
operator|&
name|dl
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// LP32: call i32 @llvm.nvvm.atomic.max.gen.i.cta.i32.p0i32
comment|// LP64: call i64 @llvm.nvvm.atomic.max.gen.i.cta.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_cta_max_gen_ul' needs target feature satom}}
name|__nvvm_atom_cta_max_gen_ul
argument_list|(
operator|(
name|unsigned
name|long
operator|*
operator|)
name|lp
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.nvvm.atomic.max.gen.i.cta.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_cta_max_gen_ll' needs target feature satom}}
name|__nvvm_atom_cta_max_gen_ll
argument_list|(
operator|&
name|sll
argument_list|,
name|ll
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.nvvm.atomic.max.gen.i.cta.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_cta_max_gen_ull' needs target feature satom}}
name|__nvvm_atom_cta_max_gen_ull
argument_list|(
operator|(
name|unsigned
name|long
name|long
operator|*
operator|)
name|llp
argument_list|,
name|ll
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.nvvm.atomic.max.gen.i.sys.i32.p0i32
comment|// expected-error@+1 {{'__nvvm_atom_sys_max_gen_i' needs target feature satom}}
name|__nvvm_atom_sys_max_gen_i
argument_list|(
name|ip
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.nvvm.atomic.max.gen.i.sys.i32.p0i32
comment|// expected-error@+1 {{'__nvvm_atom_sys_max_gen_ui' needs target feature satom}}
name|__nvvm_atom_sys_max_gen_ui
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
comment|// LP32: call i32 @llvm.nvvm.atomic.max.gen.i.sys.i32.p0i32
comment|// LP64: call i64 @llvm.nvvm.atomic.max.gen.i.sys.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_sys_max_gen_l' needs target feature satom}}
name|__nvvm_atom_sys_max_gen_l
argument_list|(
operator|&
name|dl
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// LP32: call i32 @llvm.nvvm.atomic.max.gen.i.sys.i32.p0i32
comment|// LP64: call i64 @llvm.nvvm.atomic.max.gen.i.sys.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_sys_max_gen_ul' needs target feature satom}}
name|__nvvm_atom_sys_max_gen_ul
argument_list|(
operator|(
name|unsigned
name|long
operator|*
operator|)
name|lp
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.nvvm.atomic.max.gen.i.sys.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_sys_max_gen_ll' needs target feature satom}}
name|__nvvm_atom_sys_max_gen_ll
argument_list|(
operator|&
name|sll
argument_list|,
name|ll
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.nvvm.atomic.max.gen.i.sys.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_sys_max_gen_ull' needs target feature satom}}
name|__nvvm_atom_sys_max_gen_ull
argument_list|(
operator|(
name|unsigned
name|long
name|long
operator|*
operator|)
name|llp
argument_list|,
name|ll
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.nvvm.atomic.min.gen.i.cta.i32.p0i32
comment|// expected-error@+1 {{'__nvvm_atom_cta_min_gen_i' needs target feature satom}}
name|__nvvm_atom_cta_min_gen_i
argument_list|(
name|ip
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.nvvm.atomic.min.gen.i.cta.i32.p0i32
comment|// expected-error@+1 {{'__nvvm_atom_cta_min_gen_ui' needs target feature satom}}
name|__nvvm_atom_cta_min_gen_ui
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
comment|// LP32: call i32 @llvm.nvvm.atomic.min.gen.i.cta.i32.p0i32
comment|// LP64: call i64 @llvm.nvvm.atomic.min.gen.i.cta.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_cta_min_gen_l' needs target feature satom}}
name|__nvvm_atom_cta_min_gen_l
argument_list|(
operator|&
name|dl
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// LP32: call i32 @llvm.nvvm.atomic.min.gen.i.cta.i32.p0i32
comment|// LP64: call i64 @llvm.nvvm.atomic.min.gen.i.cta.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_cta_min_gen_ul' needs target feature satom}}
name|__nvvm_atom_cta_min_gen_ul
argument_list|(
operator|(
name|unsigned
name|long
operator|*
operator|)
name|lp
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.nvvm.atomic.min.gen.i.cta.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_cta_min_gen_ll' needs target feature satom}}
name|__nvvm_atom_cta_min_gen_ll
argument_list|(
operator|&
name|sll
argument_list|,
name|ll
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.nvvm.atomic.min.gen.i.cta.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_cta_min_gen_ull' needs target feature satom}}
name|__nvvm_atom_cta_min_gen_ull
argument_list|(
operator|(
name|unsigned
name|long
name|long
operator|*
operator|)
name|llp
argument_list|,
name|ll
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.nvvm.atomic.min.gen.i.sys.i32.p0i32
comment|// expected-error@+1 {{'__nvvm_atom_sys_min_gen_i' needs target feature satom}}
name|__nvvm_atom_sys_min_gen_i
argument_list|(
name|ip
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.nvvm.atomic.min.gen.i.sys.i32.p0i32
comment|// expected-error@+1 {{'__nvvm_atom_sys_min_gen_ui' needs target feature satom}}
name|__nvvm_atom_sys_min_gen_ui
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
comment|// LP32: call i32 @llvm.nvvm.atomic.min.gen.i.sys.i32.p0i32
comment|// LP64: call i64 @llvm.nvvm.atomic.min.gen.i.sys.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_sys_min_gen_l' needs target feature satom}}
name|__nvvm_atom_sys_min_gen_l
argument_list|(
operator|&
name|dl
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// LP32: call i32 @llvm.nvvm.atomic.min.gen.i.sys.i32.p0i32
comment|// LP64: call i64 @llvm.nvvm.atomic.min.gen.i.sys.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_sys_min_gen_ul' needs target feature satom}}
name|__nvvm_atom_sys_min_gen_ul
argument_list|(
operator|(
name|unsigned
name|long
operator|*
operator|)
name|lp
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.nvvm.atomic.min.gen.i.sys.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_sys_min_gen_ll' needs target feature satom}}
name|__nvvm_atom_sys_min_gen_ll
argument_list|(
operator|&
name|sll
argument_list|,
name|ll
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.nvvm.atomic.min.gen.i.sys.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_sys_min_gen_ull' needs target feature satom}}
name|__nvvm_atom_sys_min_gen_ull
argument_list|(
operator|(
name|unsigned
name|long
name|long
operator|*
operator|)
name|llp
argument_list|,
name|ll
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.nvvm.atomic.inc.gen.i.cta.i32.p0i32
comment|// expected-error@+1 {{'__nvvm_atom_cta_inc_gen_ui' needs target feature satom}}
name|__nvvm_atom_cta_inc_gen_ui
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
comment|// CHECK: call i32 @llvm.nvvm.atomic.inc.gen.i.sys.i32.p0i32
comment|// expected-error@+1 {{'__nvvm_atom_sys_inc_gen_ui' needs target feature satom}}
name|__nvvm_atom_sys_inc_gen_ui
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
comment|// CHECK: call i32 @llvm.nvvm.atomic.dec.gen.i.cta.i32.p0i32
comment|// expected-error@+1 {{'__nvvm_atom_cta_dec_gen_ui' needs target feature satom}}
name|__nvvm_atom_cta_dec_gen_ui
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
comment|// CHECK: call i32 @llvm.nvvm.atomic.dec.gen.i.sys.i32.p0i32
comment|// expected-error@+1 {{'__nvvm_atom_sys_dec_gen_ui' needs target feature satom}}
name|__nvvm_atom_sys_dec_gen_ui
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
comment|// CHECK: call i32 @llvm.nvvm.atomic.and.gen.i.cta.i32.p0i32
comment|// expected-error@+1 {{'__nvvm_atom_cta_and_gen_i' needs target feature satom}}
name|__nvvm_atom_cta_and_gen_i
argument_list|(
name|ip
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// LP32: call i32 @llvm.nvvm.atomic.and.gen.i.cta.i32.p0i32
comment|// LP64: call i64 @llvm.nvvm.atomic.and.gen.i.cta.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_cta_and_gen_l' needs target feature satom}}
name|__nvvm_atom_cta_and_gen_l
argument_list|(
operator|&
name|dl
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.nvvm.atomic.and.gen.i.cta.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_cta_and_gen_ll' needs target feature satom}}
name|__nvvm_atom_cta_and_gen_ll
argument_list|(
operator|&
name|sll
argument_list|,
name|ll
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.nvvm.atomic.and.gen.i.sys.i32.p0i32
comment|// expected-error@+1 {{'__nvvm_atom_sys_and_gen_i' needs target feature satom}}
name|__nvvm_atom_sys_and_gen_i
argument_list|(
name|ip
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// LP32: call i32 @llvm.nvvm.atomic.and.gen.i.sys.i32.p0i32
comment|// LP64: call i64 @llvm.nvvm.atomic.and.gen.i.sys.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_sys_and_gen_l' needs target feature satom}}
name|__nvvm_atom_sys_and_gen_l
argument_list|(
operator|&
name|dl
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.nvvm.atomic.and.gen.i.sys.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_sys_and_gen_ll' needs target feature satom}}
name|__nvvm_atom_sys_and_gen_ll
argument_list|(
operator|&
name|sll
argument_list|,
name|ll
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.nvvm.atomic.or.gen.i.cta.i32.p0i32
comment|// expected-error@+1 {{'__nvvm_atom_cta_or_gen_i' needs target feature satom}}
name|__nvvm_atom_cta_or_gen_i
argument_list|(
name|ip
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// LP32: call i32 @llvm.nvvm.atomic.or.gen.i.cta.i32.p0i32
comment|// LP64: call i64 @llvm.nvvm.atomic.or.gen.i.cta.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_cta_or_gen_l' needs target feature satom}}
name|__nvvm_atom_cta_or_gen_l
argument_list|(
operator|&
name|dl
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.nvvm.atomic.or.gen.i.cta.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_cta_or_gen_ll' needs target feature satom}}
name|__nvvm_atom_cta_or_gen_ll
argument_list|(
operator|&
name|sll
argument_list|,
name|ll
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.nvvm.atomic.or.gen.i.sys.i32.p0i32
comment|// expected-error@+1 {{'__nvvm_atom_sys_or_gen_i' needs target feature satom}}
name|__nvvm_atom_sys_or_gen_i
argument_list|(
name|ip
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// LP32: call i32 @llvm.nvvm.atomic.or.gen.i.sys.i32.p0i32
comment|// LP64: call i64 @llvm.nvvm.atomic.or.gen.i.sys.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_sys_or_gen_l' needs target feature satom}}
name|__nvvm_atom_sys_or_gen_l
argument_list|(
operator|&
name|dl
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.nvvm.atomic.or.gen.i.sys.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_sys_or_gen_ll' needs target feature satom}}
name|__nvvm_atom_sys_or_gen_ll
argument_list|(
operator|&
name|sll
argument_list|,
name|ll
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.nvvm.atomic.xor.gen.i.cta.i32.p0i32
comment|// expected-error@+1 {{'__nvvm_atom_cta_xor_gen_i' needs target feature satom}}
name|__nvvm_atom_cta_xor_gen_i
argument_list|(
name|ip
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// LP32: call i32 @llvm.nvvm.atomic.xor.gen.i.cta.i32.p0i32
comment|// LP64: call i64 @llvm.nvvm.atomic.xor.gen.i.cta.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_cta_xor_gen_l' needs target feature satom}}
name|__nvvm_atom_cta_xor_gen_l
argument_list|(
operator|&
name|dl
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.nvvm.atomic.xor.gen.i.cta.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_cta_xor_gen_ll' needs target feature satom}}
name|__nvvm_atom_cta_xor_gen_ll
argument_list|(
operator|&
name|sll
argument_list|,
name|ll
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.nvvm.atomic.xor.gen.i.sys.i32.p0i32
comment|// expected-error@+1 {{'__nvvm_atom_sys_xor_gen_i' needs target feature satom}}
name|__nvvm_atom_sys_xor_gen_i
argument_list|(
name|ip
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// LP32: call i32 @llvm.nvvm.atomic.xor.gen.i.sys.i32.p0i32
comment|// LP64: call i64 @llvm.nvvm.atomic.xor.gen.i.sys.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_sys_xor_gen_l' needs target feature satom}}
name|__nvvm_atom_sys_xor_gen_l
argument_list|(
operator|&
name|dl
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.nvvm.atomic.xor.gen.i.sys.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_sys_xor_gen_ll' needs target feature satom}}
name|__nvvm_atom_sys_xor_gen_ll
argument_list|(
operator|&
name|sll
argument_list|,
name|ll
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.nvvm.atomic.cas.gen.i.cta.i32.p0i32
comment|// expected-error@+1 {{'__nvvm_atom_cta_cas_gen_i' needs target feature satom}}
name|__nvvm_atom_cta_cas_gen_i
argument_list|(
name|ip
argument_list|,
name|i
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// LP32: call i32 @llvm.nvvm.atomic.cas.gen.i.cta.i32.p0i32
comment|// LP64: call i64 @llvm.nvvm.atomic.cas.gen.i.cta.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_cta_cas_gen_l' needs target feature satom}}
name|__nvvm_atom_cta_cas_gen_l
argument_list|(
operator|&
name|dl
argument_list|,
name|l
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.nvvm.atomic.cas.gen.i.cta.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_cta_cas_gen_ll' needs target feature satom}}
name|__nvvm_atom_cta_cas_gen_ll
argument_list|(
operator|&
name|sll
argument_list|,
name|ll
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.nvvm.atomic.cas.gen.i.sys.i32.p0i32
comment|// expected-error@+1 {{'__nvvm_atom_sys_cas_gen_i' needs target feature satom}}
name|__nvvm_atom_sys_cas_gen_i
argument_list|(
name|ip
argument_list|,
name|i
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// LP32: call i32 @llvm.nvvm.atomic.cas.gen.i.sys.i32.p0i32
comment|// LP64: call i64 @llvm.nvvm.atomic.cas.gen.i.sys.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_sys_cas_gen_l' needs target feature satom}}
name|__nvvm_atom_sys_cas_gen_l
argument_list|(
operator|&
name|dl
argument_list|,
name|l
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.nvvm.atomic.cas.gen.i.sys.i64.p0i64
comment|// expected-error@+1 {{'__nvvm_atom_sys_cas_gen_ll' needs target feature satom}}
name|__nvvm_atom_sys_cas_gen_ll
argument_list|(
operator|&
name|sll
argument_list|,
name|ll
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// CHECK: ret
block|}
end_function

begin_comment
comment|// CHECK-LABEL: nvvm_ldg
end_comment

begin_function
name|__device__
name|void
name|nvvm_ldg
parameter_list|(
specifier|const
name|void
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK: call i8 @llvm.nvvm.ldg.global.i.i8.p0i8(i8* {{%[0-9]+}}, i32 1)
comment|// CHECK: call i8 @llvm.nvvm.ldg.global.i.i8.p0i8(i8* {{%[0-9]+}}, i32 1)
name|__nvvm_ldg_c
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
name|__nvvm_ldg_uc
argument_list|(
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
comment|// CHECK: call i16 @llvm.nvvm.ldg.global.i.i16.p0i16(i16* {{%[0-9]+}}, i32 2)
comment|// CHECK: call i16 @llvm.nvvm.ldg.global.i.i16.p0i16(i16* {{%[0-9]+}}, i32 2)
name|__nvvm_ldg_s
argument_list|(
operator|(
specifier|const
name|short
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
name|__nvvm_ldg_us
argument_list|(
operator|(
specifier|const
name|unsigned
name|short
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.nvvm.ldg.global.i.i32.p0i32(i32* {{%[0-9]+}}, i32 4)
comment|// CHECK: call i32 @llvm.nvvm.ldg.global.i.i32.p0i32(i32* {{%[0-9]+}}, i32 4)
name|__nvvm_ldg_i
argument_list|(
operator|(
specifier|const
name|int
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
name|__nvvm_ldg_ui
argument_list|(
operator|(
specifier|const
name|unsigned
name|int
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
comment|// LP32: call i32 @llvm.nvvm.ldg.global.i.i32.p0i32(i32* {{%[0-9]+}}, i32 4)
comment|// LP32: call i32 @llvm.nvvm.ldg.global.i.i32.p0i32(i32* {{%[0-9]+}}, i32 4)
comment|// LP64: call i64 @llvm.nvvm.ldg.global.i.i64.p0i64(i64* {{%[0-9]+}}, i32 8)
comment|// LP64: call i64 @llvm.nvvm.ldg.global.i.i64.p0i64(i64* {{%[0-9]+}}, i32 8)
name|__nvvm_ldg_l
argument_list|(
operator|(
specifier|const
name|long
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
name|__nvvm_ldg_ul
argument_list|(
operator|(
specifier|const
name|unsigned
name|long
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
comment|// CHECK: call float @llvm.nvvm.ldg.global.f.f32.p0f32(float* {{%[0-9]+}}, i32 4)
name|__nvvm_ldg_f
argument_list|(
operator|(
specifier|const
name|float
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
comment|// CHECK: call double @llvm.nvvm.ldg.global.f.f64.p0f64(double* {{%[0-9]+}}, i32 8)
name|__nvvm_ldg_d
argument_list|(
operator|(
specifier|const
name|double
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
comment|// In practice, the pointers we pass to __ldg will be aligned as appropriate
comment|// for the CUDA<type>N vector types (e.g. short4), which are not the same as
comment|// the LLVM vector types.  However, each LLVM vector type has an alignment
comment|// less than or equal to its corresponding CUDA type, so we're OK.
comment|//
comment|// PTX Interoperability section 2.2: "For a vector with an even number of
comment|// elements, its alignment is set to number of elements times the alignment of
comment|// its member: n*alignof(t)."
comment|// CHECK: call<2 x i8> @llvm.nvvm.ldg.global.i.v2i8.p0v2i8(<2 x i8>* {{%[0-9]+}}, i32 2)
comment|// CHECK: call<2 x i8> @llvm.nvvm.ldg.global.i.v2i8.p0v2i8(<2 x i8>* {{%[0-9]+}}, i32 2)
typedef|typedef
name|char
name|char2
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(2)));
typedef|typedef
name|unsigned
name|char
name|uchar2
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(2)));
name|__nvvm_ldg_c2
argument_list|(
operator|(
specifier|const
name|char2
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
name|__nvvm_ldg_uc2
argument_list|(
operator|(
specifier|const
name|uchar2
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x i8> @llvm.nvvm.ldg.global.i.v4i8.p0v4i8(<4 x i8>* {{%[0-9]+}}, i32 4)
comment|// CHECK: call<4 x i8> @llvm.nvvm.ldg.global.i.v4i8.p0v4i8(<4 x i8>* {{%[0-9]+}}, i32 4)
typedef|typedef
name|char
name|char4
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(4)));
typedef|typedef
name|unsigned
name|char
name|uchar4
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(4)));
name|__nvvm_ldg_c4
argument_list|(
operator|(
specifier|const
name|char4
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
name|__nvvm_ldg_uc4
argument_list|(
operator|(
specifier|const
name|uchar4
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x i16> @llvm.nvvm.ldg.global.i.v2i16.p0v2i16(<2 x i16>* {{%[0-9]+}}, i32 4)
comment|// CHECK: call<2 x i16> @llvm.nvvm.ldg.global.i.v2i16.p0v2i16(<2 x i16>* {{%[0-9]+}}, i32 4)
typedef|typedef
name|short
name|short2
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(2)));
typedef|typedef
name|unsigned
name|short
name|ushort2
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(2)));
name|__nvvm_ldg_s2
argument_list|(
operator|(
specifier|const
name|short2
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
name|__nvvm_ldg_us2
argument_list|(
operator|(
specifier|const
name|ushort2
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x i16> @llvm.nvvm.ldg.global.i.v4i16.p0v4i16(<4 x i16>* {{%[0-9]+}}, i32 8)
comment|// CHECK: call<4 x i16> @llvm.nvvm.ldg.global.i.v4i16.p0v4i16(<4 x i16>* {{%[0-9]+}}, i32 8)
typedef|typedef
name|short
name|short4
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(4)));
typedef|typedef
name|unsigned
name|short
name|ushort4
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(4)));
name|__nvvm_ldg_s4
argument_list|(
operator|(
specifier|const
name|short4
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
name|__nvvm_ldg_us4
argument_list|(
operator|(
specifier|const
name|ushort4
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x i32> @llvm.nvvm.ldg.global.i.v2i32.p0v2i32(<2 x i32>* {{%[0-9]+}}, i32 8)
comment|// CHECK: call<2 x i32> @llvm.nvvm.ldg.global.i.v2i32.p0v2i32(<2 x i32>* {{%[0-9]+}}, i32 8)
typedef|typedef
name|int
name|int2
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(2)));
typedef|typedef
name|unsigned
name|int
name|uint2
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(2)));
name|__nvvm_ldg_i2
argument_list|(
operator|(
specifier|const
name|int2
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
name|__nvvm_ldg_ui2
argument_list|(
operator|(
specifier|const
name|uint2
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x i32> @llvm.nvvm.ldg.global.i.v4i32.p0v4i32(<4 x i32>* {{%[0-9]+}}, i32 16)
comment|// CHECK: call<4 x i32> @llvm.nvvm.ldg.global.i.v4i32.p0v4i32(<4 x i32>* {{%[0-9]+}}, i32 16)
typedef|typedef
name|int
name|int4
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(4)));
typedef|typedef
name|unsigned
name|int
name|uint4
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(4)));
name|__nvvm_ldg_i4
argument_list|(
operator|(
specifier|const
name|int4
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
name|__nvvm_ldg_ui4
argument_list|(
operator|(
specifier|const
name|uint4
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x i64> @llvm.nvvm.ldg.global.i.v2i64.p0v2i64(<2 x i64>* {{%[0-9]+}}, i32 16)
comment|// CHECK: call<2 x i64> @llvm.nvvm.ldg.global.i.v2i64.p0v2i64(<2 x i64>* {{%[0-9]+}}, i32 16)
typedef|typedef
name|long
name|long
name|longlong2
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(2)));
typedef|typedef
name|unsigned
name|long
name|long
name|ulonglong2
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(2)));
name|__nvvm_ldg_ll2
argument_list|(
operator|(
specifier|const
name|longlong2
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
name|__nvvm_ldg_ull2
argument_list|(
operator|(
specifier|const
name|ulonglong2
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x float> @llvm.nvvm.ldg.global.f.v2f32.p0v2f32(<2 x float>* {{%[0-9]+}}, i32 8)
typedef|typedef
name|float
name|float2
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(2)));
name|__nvvm_ldg_f2
argument_list|(
operator|(
specifier|const
name|float2
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x float> @llvm.nvvm.ldg.global.f.v4f32.p0v4f32(<4 x float>* {{%[0-9]+}}, i32 16)
typedef|typedef
name|float
name|float4
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(4)));
name|__nvvm_ldg_f4
argument_list|(
operator|(
specifier|const
name|float4
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x double> @llvm.nvvm.ldg.global.f.v2f64.p0v2f64(<2 x double>* {{%[0-9]+}}, i32 16)
typedef|typedef
name|double
name|double2
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(2)));
name|__nvvm_ldg_d2
argument_list|(
operator|(
specifier|const
name|double2
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

