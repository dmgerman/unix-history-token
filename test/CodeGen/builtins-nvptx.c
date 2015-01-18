begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: nvptx-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple nvptx-unknown-unknown -S -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple nvptx64-unknown-unknown -S -emit-llvm -o - %s | FileCheck %s
end_comment

begin_function
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
name|b
init|=
name|__builtin_ptx_read_clock64
argument_list|()
decl_stmt|;
return|return
operator|(
name|long
operator|)
name|a
operator|+
name|b
return|;
block|}
end_function

begin_function
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

end_unit

