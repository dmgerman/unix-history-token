begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test target codegen - host bc file has to be created first.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -verify -fopenmp -x c -triple powerpc64le-unknown-unknown -fopenmp-targets=nvptx64-nvidia-cuda -emit-llvm-bc %s -o %t-ppc-host.bc
end_comment

begin_comment
comment|// RUN: %clang_cc1 -verify -fopenmp -x c -triple nvptx64-unknown-unknown -fopenmp-targets=nvptx64-nvidia-cuda -emit-llvm %s -fopenmp-is-device -fopenmp-host-ir-file-path %t-ppc-host.bc -o - | FileCheck %s --check-prefix CHECK --check-prefix CHECK-64
end_comment

begin_comment
comment|// RUN: %clang_cc1 -verify -fopenmp -x c -triple i386-unknown-unknown -fopenmp-targets=nvptx-nvidia-cuda -emit-llvm-bc %s -o %t-x86-host.bc
end_comment

begin_comment
comment|// RUN: %clang_cc1 -verify -fopenmp -x c -triple nvptx-unknown-unknown -fopenmp-targets=nvptx-nvidia-cuda -emit-llvm %s -fopenmp-is-device -fopenmp-host-ir-file-path %t-x86-host.bc -o - | FileCheck %s --check-prefix CHECK --check-prefix CHECK-32
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_function_decl
specifier|extern
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vprintf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Check a simple call to printf end-to-end.
end_comment

begin_comment
comment|// CHECK: [[SIMPLE_PRINTF_TY:%[a-zA-Z0-9_]+]] = type { i32, i64, double }
end_comment

begin_function
name|int
name|CheckSimple
parameter_list|()
block|{
comment|// CHECK: define {{.*}}void [[T1:@__omp_offloading_.+CheckSimple.+]]_worker()
pragma|#
directive|pragma
name|omp
name|target
block|{
comment|// Entry point.
comment|// CHECK: define {{.*}}void [[T1]]()
comment|// Alloca in entry block.
comment|// CHECK: [[BUF:%[a-zA-Z0-9_]+]] = alloca [[SIMPLE_PRINTF_TY]]
comment|// CHECK: {{call|invoke}} void [[T1]]_worker()
comment|// CHECK: br label {{%?}}[[EXIT:.+]]
comment|//
comment|// CHECK-DAG: [[CMTID:%.+]] = call i32 @llvm.nvvm.read.ptx.sreg.tid.x()
comment|// CHECK-DAG: [[CMNTH:%.+]] = call i32 @llvm.nvvm.read.ptx.sreg.ntid.x()
comment|// CHECK-DAG: [[CMWS:%.+]] = call i32 @llvm.nvvm.read.ptx.sreg.warpsize()
comment|// CHECK: [[IS_MASTER:%.+]] = icmp eq i32 [[CMTID]],
comment|// CHECK: br i1 [[IS_MASTER]], label {{%?}}[[MASTER:.+]], label {{%?}}[[EXIT]]
comment|//
comment|// CHECK: [[MASTER]]
comment|// CHECK-DAG: [[MNTH:%.+]] = call i32 @llvm.nvvm.read.ptx.sreg.ntid.x()
comment|// CHECK-DAG: [[MWS:%.+]] = call i32 @llvm.nvvm.read.ptx.sreg.warpsize()
comment|// CHECK: [[MTMP1:%.+]] = sub i32 [[MNTH]], [[MWS]]
comment|// CHECK: call void @__kmpc_kernel_init(i32 [[MTMP1]]
comment|// printf in master-only basic block.
comment|// CHECK: [[FMT:%[0-9]+]] = load{{.*}}%fmt
specifier|const
name|char
modifier|*
name|fmt
init|=
literal|"%d %lld %f"
decl_stmt|;
comment|// CHECK: [[PTR0:%[0-9]+]] = getelementptr inbounds [[SIMPLE_PRINTF_TY]], [[SIMPLE_PRINTF_TY]]* [[BUF]], i32 0, i32 0
comment|// CHECK: store i32 1, i32* [[PTR0]], align 4
comment|// CHECK: [[PTR1:%[0-9]+]] = getelementptr inbounds [[SIMPLE_PRINTF_TY]], [[SIMPLE_PRINTF_TY]]* [[BUF]], i32 0, i32 1
comment|// CHECK: store i64 2, i64* [[PTR1]], align 8
comment|// CHECK: [[PTR2:%[0-9]+]] = getelementptr inbounds [[SIMPLE_PRINTF_TY]], [[SIMPLE_PRINTF_TY]]* [[BUF]], i32 0, i32 2
comment|// CHECK: store double 3.0{{[^,]*}}, double* [[PTR2]], align 8
comment|// CHECK: [[BUF_CAST:%[0-9]+]] = bitcast [[SIMPLE_PRINTF_TY]]* [[BUF]] to i8*
comment|// CHECK: [[RET:%[0-9]+]] = call i32 @vprintf(i8* [[FMT]], i8* [[BUF_CAST]])
name|printf
argument_list|(
name|fmt
argument_list|,
literal|1
argument_list|,
literal|2ll
argument_list|,
literal|3.0
argument_list|)
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
name|CheckNoArgs
parameter_list|()
block|{
comment|// CHECK: define {{.*}}void [[T2:@__omp_offloading_.+CheckNoArgs.+]]_worker()
pragma|#
directive|pragma
name|omp
name|target
block|{
comment|// Entry point.
comment|// CHECK: define {{.*}}void [[T2]]()
comment|// CHECK: {{call|invoke}} void [[T2]]_worker()
comment|// CHECK: br label {{%?}}[[EXIT:.+]]
comment|//
comment|// CHECK-DAG: [[CMTID:%.+]] = call i32 @llvm.nvvm.read.ptx.sreg.tid.x()
comment|// CHECK-DAG: [[CMNTH:%.+]] = call i32 @llvm.nvvm.read.ptx.sreg.ntid.x()
comment|// CHECK-DAG: [[CMWS:%.+]] = call i32 @llvm.nvvm.read.ptx.sreg.warpsize()
comment|// CHECK: [[IS_MASTER:%.+]] = icmp eq i32 [[CMTID]],
comment|// CHECK: br i1 [[IS_MASTER]], label {{%?}}[[MASTER:.+]], label {{%?}}[[EXIT]]
comment|//
comment|// CHECK: [[MASTER]]
comment|// CHECK-DAG: [[MNTH:%.+]] = call i32 @llvm.nvvm.read.ptx.sreg.ntid.x()
comment|// CHECK-DAG: [[MWS:%.+]] = call i32 @llvm.nvvm.read.ptx.sreg.warpsize()
comment|// CHECK: [[MTMP1:%.+]] = sub i32 [[MNTH]], [[MWS]]
comment|// CHECK: call void @__kmpc_kernel_init(i32 [[MTMP1]]
comment|// printf in master-only basic block.
comment|// CHECK: call i32 @vprintf({{.*}}, i8* null){{$}}
name|printf
argument_list|(
literal|"hello, world!"
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|// Check that printf's alloca happens in the entry block, not inside the if
end_comment

begin_comment
comment|// statement.
end_comment

begin_decl_stmt
name|int
name|foo
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|CheckAllocaIsInEntryBlock
parameter_list|()
block|{
comment|// CHECK: define {{.*}}void [[T3:@__omp_offloading_.+CheckAllocaIsInEntryBlock.+]]_worker()
pragma|#
directive|pragma
name|omp
name|target
block|{
comment|// Entry point.
comment|// CHECK: define {{.*}}void [[T3]](
comment|// Alloca in entry block.
comment|// CHECK: alloca %printf_args
comment|// CHECK: {{call|invoke}} void [[T3]]_worker()
comment|// CHECK: br label {{%?}}[[EXIT:.+]]
comment|//
comment|// CHECK-DAG: [[CMTID:%.+]] = call i32 @llvm.nvvm.read.ptx.sreg.tid.x()
comment|// CHECK-DAG: [[CMNTH:%.+]] = call i32 @llvm.nvvm.read.ptx.sreg.ntid.x()
comment|// CHECK-DAG: [[CMWS:%.+]] = call i32 @llvm.nvvm.read.ptx.sreg.warpsize()
comment|// CHECK: [[IS_MASTER:%.+]] = icmp eq i32 [[CMTID]],
comment|// CHECK: br i1 [[IS_MASTER]], label {{%?}}[[MASTER:.+]], label {{%?}}[[EXIT]]
comment|//
comment|// CHECK: [[MASTER]]
comment|// CHECK-DAG: [[MNTH:%.+]] = call i32 @llvm.nvvm.read.ptx.sreg.ntid.x()
comment|// CHECK-DAG: [[MWS:%.+]] = call i32 @llvm.nvvm.read.ptx.sreg.warpsize()
comment|// CHECK: [[MTMP1:%.+]] = sub i32 [[MNTH]], [[MWS]]
comment|// CHECK: call void @__kmpc_kernel_init(i32 [[MTMP1]]
if|if
condition|(
name|foo
condition|)
block|{
name|printf
argument_list|(
literal|"%d"
argument_list|,
literal|42
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

end_unit

