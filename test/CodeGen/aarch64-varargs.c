begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-linux-gnu -emit-llvm -o - %s | FileCheck --check-prefix=CHECK --check-prefix=CHECK-LE %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple aarch64_be-linux-gnu -emit-llvm -o - %s | FileCheck --check-prefix=CHECK --check-prefix=CHECK-BE %s
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_comment
comment|// Obviously there's more than one way to implement va_arg. This test should at
end_comment

begin_comment
comment|// least prevent unintentional regressions caused by refactoring.
end_comment

begin_decl_stmt
name|va_list
name|the_list
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|simple_int
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: define i32 @simple_int
return|return
name|va_arg
argument_list|(
name|the_list
argument_list|,
name|int
argument_list|)
return|;
comment|// CHECK: [[GR_OFFS:%[a-z_0-9]+]] = load i32* getelementptr inbounds (%struct.__va_list* @the_list, i32 0, i32 3)
comment|// CHECK: [[EARLY_ONSTACK:%[a-z_0-9]+]] = icmp sge i32 [[GR_OFFS]], 0
comment|// CHECK: br i1 [[EARLY_ONSTACK]], label %[[VAARG_ON_STACK:[a-z_.0-9]+]], label %[[VAARG_MAYBE_REG:[a-z_.0-9]+]]
comment|// CHECK: [[VAARG_MAYBE_REG]]
comment|// CHECK: [[NEW_REG_OFFS:%[a-z_0-9]+]] = add i32 [[GR_OFFS]], 8
comment|// CHECK: store i32 [[NEW_REG_OFFS]], i32* getelementptr inbounds (%struct.__va_list* @the_list, i32 0, i32 3)
comment|// CHECK: [[INREG:%[a-z_0-9]+]] = icmp sle i32 [[NEW_REG_OFFS]], 0
comment|// CHECK: br i1 [[INREG]], label %[[VAARG_IN_REG:[a-z_.0-9]+]], label %[[VAARG_ON_STACK]]
comment|// CHECK: [[VAARG_IN_REG]]
comment|// CHECK: [[REG_TOP:%[a-z_0-9]+]] = load i8** getelementptr inbounds (%struct.__va_list* @the_list, i32 0, i32 1)
comment|// CHECK: [[REG_ADDR:%[a-z_0-9]+]] = getelementptr i8* [[REG_TOP]], i32 [[GR_OFFS]]
comment|// CHECK-BE: [[REG_ADDR_VAL:%[0-9]+]] = ptrtoint i8* [[REG_ADDR]] to i64
comment|// CHECK-BE: [[REG_ADDR_VAL_ALIGNED:%[a-z_0-9]*]] = add i64 [[REG_ADDR_VAL]], 4
comment|// CHECK-BE: [[REG_ADDR:%[0-9]+]] = inttoptr i64 [[REG_ADDR_VAL_ALIGNED]] to i8*
comment|// CHECK: [[FROMREG_ADDR:%[a-z_0-9]+]] = bitcast i8* [[REG_ADDR]] to i32*
comment|// CHECK: br label %[[VAARG_END:[a-z._0-9]+]]
comment|// CHECK: [[VAARG_ON_STACK]]
comment|// CHECK: [[STACK:%[a-z_0-9]+]] = load i8** getelementptr inbounds (%struct.__va_list* @the_list, i32 0, i32 0)
comment|// CHECK: [[NEW_STACK:%[a-z_0-9]+]] = getelementptr i8* [[STACK]], i32 8
comment|// CHECK: store i8* [[NEW_STACK]], i8** getelementptr inbounds (%struct.__va_list* @the_list, i32 0, i32 0)
comment|// CHECK-BE: [[STACK_VAL:%[0-9]+]] = ptrtoint i8* [[STACK]] to i64
comment|// CHECK-BE: [[STACK_VAL_ALIGNED:%[a-z_0-9]*]] = add i64 [[STACK_VAL]], 4
comment|// CHECK-BE: [[STACK:%[0-9]+]] = inttoptr i64 [[STACK_VAL_ALIGNED]] to i8*
comment|// CHECK: [[FROMSTACK_ADDR:%[a-z_0-9]+]] = bitcast i8* [[STACK]] to i32*
comment|// CHECK: br label %[[VAARG_END]]
comment|// CHECK: [[VAARG_END]]
comment|// CHECK: [[ADDR:%[a-z._0-9]+]] = phi i32* [ [[FROMREG_ADDR]], %[[VAARG_IN_REG]] ], [ [[FROMSTACK_ADDR]], %[[VAARG_ON_STACK]] ]
comment|// CHECK: [[RESULT:%[a-z_0-9]+]] = load i32* [[ADDR]]
comment|// CHECK: ret i32 [[RESULT]]
block|}
end_function

begin_function
name|__int128
name|aligned_int
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: define i128 @aligned_int
return|return
name|va_arg
argument_list|(
name|the_list
argument_list|,
name|__int128
argument_list|)
return|;
comment|// CHECK: [[GR_OFFS:%[a-z_0-9]+]] = load i32* getelementptr inbounds (%struct.__va_list* @the_list, i32 0, i32 3)
comment|// CHECK: [[EARLY_ONSTACK:%[a-z_0-9]+]] = icmp sge i32 [[GR_OFFS]], 0
comment|// CHECK: br i1 [[EARLY_ONSTACK]], label %[[VAARG_ON_STACK:[a-z_.0-9]+]], label %[[VAARG_MAYBE_REG:[a-z_.0-9]+]]
comment|// CHECK: [[VAARG_MAYBE_REG]]
comment|// CHECK: [[ALIGN_REGOFFS:%[a-z_0-9]+]] = add i32 [[GR_OFFS]], 15
comment|// CHECK: [[ALIGNED_REGOFFS:%[a-z_0-9]+]] = and i32 [[ALIGN_REGOFFS]], -16
comment|// CHECK: [[NEW_REG_OFFS:%[a-z_0-9]+]] = add i32 [[ALIGNED_REGOFFS]], 16
comment|// CHECK: store i32 [[NEW_REG_OFFS]], i32* getelementptr inbounds (%struct.__va_list* @the_list, i32 0, i32 3)
comment|// CHECK: [[INREG:%[a-z_0-9]+]] = icmp sle i32 [[NEW_REG_OFFS]], 0
comment|// CHECK: br i1 [[INREG]], label %[[VAARG_IN_REG:[a-z_.0-9]+]], label %[[VAARG_ON_STACK]]
comment|// CHECK: [[VAARG_IN_REG]]
comment|// CHECK: [[REG_TOP:%[a-z_0-9]+]] = load i8** getelementptr inbounds (%struct.__va_list* @the_list, i32 0, i32 1)
comment|// CHECK: [[REG_ADDR:%[a-z_0-9]+]] = getelementptr i8* [[REG_TOP]], i32 [[ALIGNED_REGOFFS]]
comment|// CHECK: [[FROMREG_ADDR:%[a-z_0-9]+]] = bitcast i8* [[REG_ADDR]] to i128*
comment|// CHECK: br label %[[VAARG_END:[a-z._0-9]+]]
comment|// CHECK: [[VAARG_ON_STACK]]
comment|// CHECK: [[STACK:%[a-z_0-9]+]] = load i8** getelementptr inbounds (%struct.__va_list* @the_list, i32 0, i32 0)
comment|// CHECK: [[STACKINT:%[a-z_0-9]+]] = ptrtoint i8* [[STACK]] to i64
comment|// CHECK: [[ALIGN_STACK:%[a-z_0-9]+]] = add i64 [[STACKINT]], 15
comment|// CHECK: [[ALIGNED_STACK_INT:%[a-z_0-9]+]] = and i64 [[ALIGN_STACK]], -16
comment|// CHECK: [[ALIGNED_STACK_PTR:%[a-z_0-9]+]] = inttoptr i64 [[ALIGNED_STACK_INT]] to i8*
comment|// CHECK: [[NEW_STACK:%[a-z_0-9]+]] = getelementptr i8* [[ALIGNED_STACK_PTR]], i32 16
comment|// CHECK: store i8* [[NEW_STACK]], i8** getelementptr inbounds (%struct.__va_list* @the_list, i32 0, i32 0)
comment|// CHECK: [[FROMSTACK_ADDR:%[a-z_0-9]+]] = bitcast i8* [[ALIGNED_STACK_PTR]] to i128*
comment|// CHECK: br label %[[VAARG_END]]
comment|// CHECK: [[VAARG_END]]
comment|// CHECK: [[ADDR:%[a-z._0-9]+]] = phi i128* [ [[FROMREG_ADDR]], %[[VAARG_IN_REG]] ], [ [[FROMSTACK_ADDR]], %[[VAARG_ON_STACK]] ]
comment|// CHECK: [[RESULT:%[a-z_0-9]+]] = load i128* [[ADDR]]
comment|// CHECK: ret i128 [[RESULT]]
block|}
end_function

begin_struct
struct|struct
name|bigstruct
block|{
name|int
name|a
index|[
literal|10
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|bigstruct
name|simple_indirect
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @simple_indirect
return|return
name|va_arg
argument_list|(
name|the_list
argument_list|,
expr|struct
name|bigstruct
argument_list|)
return|;
comment|// CHECK: [[GR_OFFS:%[a-z_0-9]+]] = load i32* getelementptr inbounds (%struct.__va_list* @the_list, i32 0, i32 3)
comment|// CHECK: [[EARLY_ONSTACK:%[a-z_0-9]+]] = icmp sge i32 [[GR_OFFS]], 0
comment|// CHECK: br i1 [[EARLY_ONSTACK]], label %[[VAARG_ON_STACK:[a-z_.0-9]+]], label %[[VAARG_MAYBE_REG:[a-z_.0-9]+]]
comment|// CHECK: [[VAARG_MAYBE_REG]]
comment|// CHECK-NOT: and i32
comment|// CHECK: [[NEW_REG_OFFS:%[a-z_0-9]+]] = add i32 [[GR_OFFS]], 8
comment|// CHECK: store i32 [[NEW_REG_OFFS]], i32* getelementptr inbounds (%struct.__va_list* @the_list, i32 0, i32 3)
comment|// CHECK: [[INREG:%[a-z_0-9]+]] = icmp sle i32 [[NEW_REG_OFFS]], 0
comment|// CHECK: br i1 [[INREG]], label %[[VAARG_IN_REG:[a-z_.0-9]+]], label %[[VAARG_ON_STACK]]
comment|// CHECK: [[VAARG_IN_REG]]
comment|// CHECK: [[REG_TOP:%[a-z_0-9]+]] = load i8** getelementptr inbounds (%struct.__va_list* @the_list, i32 0, i32 1)
comment|// CHECK: [[REG_ADDR:%[a-z_0-9]+]] = getelementptr i8* [[REG_TOP]], i32 [[GR_OFFS]]
comment|// CHECK: [[FROMREG_ADDR:%[a-z_0-9]+]] = bitcast i8* [[REG_ADDR]] to %struct.bigstruct**
comment|// CHECK: br label %[[VAARG_END:[a-z._0-9]+]]
comment|// CHECK: [[VAARG_ON_STACK]]
comment|// CHECK: [[STACK:%[a-z_0-9]+]] = load i8** getelementptr inbounds (%struct.__va_list* @the_list, i32 0, i32 0)
comment|// CHECK-NOT: and i64
comment|// CHECK: [[NEW_STACK:%[a-z_0-9]+]] = getelementptr i8* [[STACK]], i32 8
comment|// CHECK: store i8* [[NEW_STACK]], i8** getelementptr inbounds (%struct.__va_list* @the_list, i32 0, i32 0)
comment|// CHECK: [[FROMSTACK_ADDR:%[a-z_0-9]+]] = bitcast i8* [[STACK]] to %struct.bigstruct**
comment|// CHECK: br label %[[VAARG_END]]
comment|// CHECK: [[VAARG_END]]
comment|// CHECK: [[ADDR:%[a-z._0-9]+]] = phi %struct.bigstruct** [ [[FROMREG_ADDR]], %[[VAARG_IN_REG]] ], [ [[FROMSTACK_ADDR]], %[[VAARG_ON_STACK]] ]
comment|// CHECK: load %struct.bigstruct** [[ADDR]]
block|}
end_function

begin_struct
struct|struct
name|aligned_bigstruct
block|{
name|float
name|a
decl_stmt|;
name|long
name|double
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|aligned_bigstruct
name|simple_aligned_indirect
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @simple_aligned_indirect
return|return
name|va_arg
argument_list|(
name|the_list
argument_list|,
expr|struct
name|aligned_bigstruct
argument_list|)
return|;
comment|// CHECK: [[GR_OFFS:%[a-z_0-9]+]] = load i32* getelementptr inbounds (%struct.__va_list* @the_list, i32 0, i32 3)
comment|// CHECK: [[EARLY_ONSTACK:%[a-z_0-9]+]] = icmp sge i32 [[GR_OFFS]], 0
comment|// CHECK: br i1 [[EARLY_ONSTACK]], label %[[VAARG_ON_STACK:[a-z_.0-9]+]], label %[[VAARG_MAYBE_REG:[a-z_.0-9]+]]
comment|// CHECK: [[VAARG_MAYBE_REG]]
comment|// CHECK: [[NEW_REG_OFFS:%[a-z_0-9]+]] = add i32 [[GR_OFFS]], 8
comment|// CHECK: store i32 [[NEW_REG_OFFS]], i32* getelementptr inbounds (%struct.__va_list* @the_list, i32 0, i32 3)
comment|// CHECK: [[INREG:%[a-z_0-9]+]] = icmp sle i32 [[NEW_REG_OFFS]], 0
comment|// CHECK: br i1 [[INREG]], label %[[VAARG_IN_REG:[a-z_.0-9]+]], label %[[VAARG_ON_STACK]]
comment|// CHECK: [[VAARG_IN_REG]]
comment|// CHECK: [[REG_TOP:%[a-z_0-9]+]] = load i8** getelementptr inbounds (%struct.__va_list* @the_list, i32 0, i32 1)
comment|// CHECK: [[REG_ADDR:%[a-z_0-9]+]] = getelementptr i8* [[REG_TOP]], i32 [[GR_OFFS]]
comment|// CHECK: [[FROMREG_ADDR:%[a-z_0-9]+]] = bitcast i8* [[REG_ADDR]] to %struct.aligned_bigstruct**
comment|// CHECK: br label %[[VAARG_END:[a-z._0-9]+]]
comment|// CHECK: [[VAARG_ON_STACK]]
comment|// CHECK: [[STACK:%[a-z_0-9]+]] = load i8** getelementptr inbounds (%struct.__va_list* @the_list, i32 0, i32 0)
comment|// CHECK: [[NEW_STACK:%[a-z_0-9]+]] = getelementptr i8* [[STACK]], i32 8
comment|// CHECK: store i8* [[NEW_STACK]], i8** getelementptr inbounds (%struct.__va_list* @the_list, i32 0, i32 0)
comment|// CHECK: [[FROMSTACK_ADDR:%[a-z_0-9]+]] = bitcast i8* [[STACK]] to %struct.aligned_bigstruct**
comment|// CHECK: br label %[[VAARG_END]]
comment|// CHECK: [[VAARG_END]]
comment|// CHECK: [[ADDR:%[a-z._0-9]+]] = phi %struct.aligned_bigstruct** [ [[FROMREG_ADDR]], %[[VAARG_IN_REG]] ], [ [[FROMSTACK_ADDR]], %[[VAARG_ON_STACK]] ]
comment|// CHECK: load %struct.aligned_bigstruct** [[ADDR]]
block|}
end_function

begin_function
name|double
name|simple_double
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: define double @simple_double
return|return
name|va_arg
argument_list|(
name|the_list
argument_list|,
name|double
argument_list|)
return|;
comment|// CHECK: [[VR_OFFS:%[a-z_0-9]+]] = load i32* getelementptr inbounds (%struct.__va_list* @the_list, i32 0, i32 4)
comment|// CHECK: [[EARLY_ONSTACK:%[a-z_0-9]+]] = icmp sge i32 [[VR_OFFS]], 0
comment|// CHECK: br i1 [[EARLY_ONSTACK]], label %[[VAARG_ON_STACK:[a-z_.0-9]+]], label %[[VAARG_MAYBE_REG]]
comment|// CHECK: [[VAARG_MAYBE_REG]]
comment|// CHECK: [[NEW_REG_OFFS:%[a-z_0-9]+]] = add i32 [[VR_OFFS]], 16
comment|// CHECK: store i32 [[NEW_REG_OFFS]], i32* getelementptr inbounds (%struct.__va_list* @the_list, i32 0, i32 4)
comment|// CHECK: [[INREG:%[a-z_0-9]+]] = icmp sle i32 [[NEW_REG_OFFS]], 0
comment|// CHECK: br i1 [[INREG]], label %[[VAARG_IN_REG:[a-z_.0-9]+]], label %[[VAARG_ON_STACK]]
comment|// CHECK: [[VAARG_IN_REG]]
comment|// CHECK: [[REG_TOP:%[a-z_0-9]+]] = load i8** getelementptr inbounds (%struct.__va_list* @the_list, i32 0, i32 2)
comment|// CHECK: [[REG_ADDR:%[a-z_0-9]+]] = getelementptr i8* [[REG_TOP]], i32 [[VR_OFFS]]
comment|// CHECK-BE: [[REG_ADDR_VAL:%[0-9]+]] = ptrtoint i8* [[REG_ADDR]] to i64
comment|// CHECK-BE: [[REG_ADDR_VAL_ALIGNED:%[a-z_0-9]*]] = add i64 [[REG_ADDR_VAL]], 8
comment|// CHECK-BE: [[REG_ADDR:%[0-9]+]] = inttoptr i64 [[REG_ADDR_VAL_ALIGNED]] to i8*
comment|// CHECK: [[FROMREG_ADDR:%[a-z_0-9]+]] = bitcast i8* [[REG_ADDR]] to double*
comment|// CHECK: br label %[[VAARG_END:[a-z._0-9]+]]
comment|// CHECK: [[VAARG_ON_STACK]]
comment|// CHECK: [[STACK:%[a-z_0-9]+]] = load i8** getelementptr inbounds (%struct.__va_list* @the_list, i32 0, i32 0)
comment|// CHECK: [[NEW_STACK:%[a-z_0-9]+]] = getelementptr i8* [[STACK]], i32 8
comment|// CHECK: store i8* [[NEW_STACK]], i8** getelementptr inbounds (%struct.__va_list* @the_list, i32 0, i32 0)
comment|// CHECK: [[FROMSTACK_ADDR:%[a-z_0-9]+]] = bitcast i8* [[STACK]] to double*
comment|// CHECK: br label %[[VAARG_END]]
comment|// CHECK: [[VAARG_END]]
comment|// CHECK: [[ADDR:%[a-z._0-9]+]] = phi double* [ [[FROMREG_ADDR]], %[[VAARG_IN_REG]] ], [ [[FROMSTACK_ADDR]], %[[VAARG_ON_STACK]] ]
comment|// CHECK: [[RESULT:%[a-z_0-9]+]] = load double* [[ADDR]]
comment|// CHECK: ret double [[RESULT]]
block|}
end_function

begin_struct
struct|struct
name|hfa
block|{
name|float
name|a
decl_stmt|,
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|hfa
name|simple_hfa
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: define %struct.hfa @simple_hfa
return|return
name|va_arg
argument_list|(
name|the_list
argument_list|,
expr|struct
name|hfa
argument_list|)
return|;
comment|// CHECK: [[VR_OFFS:%[a-z_0-9]+]] = load i32* getelementptr inbounds (%struct.__va_list* @the_list, i32 0, i32 4)
comment|// CHECK: [[EARLY_ONSTACK:%[a-z_0-9]+]] = icmp sge i32 [[VR_OFFS]], 0
comment|// CHECK: br i1 [[EARLY_ONSTACK]], label %[[VAARG_ON_STACK:[a-z_.0-9]+]], label %[[VAARG_MAYBE_REG:[a-z_.0-9]+]]
comment|// CHECK: [[VAARG_MAYBE_REG]]
comment|// CHECK: [[NEW_REG_OFFS:%[a-z_0-9]+]] = add i32 [[VR_OFFS]], 32
comment|// CHECK: store i32 [[NEW_REG_OFFS]], i32* getelementptr inbounds (%struct.__va_list* @the_list, i32 0, i32 4)
comment|// CHECK: [[INREG:%[a-z_0-9]+]] = icmp sle i32 [[NEW_REG_OFFS]], 0
comment|// CHECK: br i1 [[INREG]], label %[[VAARG_IN_REG:[a-z_.0-9]+]], label %[[VAARG_ON_STACK]]
comment|// CHECK: [[VAARG_IN_REG]]
comment|// CHECK: [[REG_TOP:%[a-z_0-9]+]] = load i8** getelementptr inbounds (%struct.__va_list* @the_list, i32 0, i32 2)
comment|// CHECK: [[FIRST_REG:%[a-z_0-9]+]] = getelementptr i8* [[REG_TOP]], i32 [[VR_OFFS]]
comment|// CHECK-LE: [[EL_ADDR:%[a-z_0-9]+]] = getelementptr i8* [[FIRST_REG]], i32 0
comment|// CHECK-BE: [[EL_ADDR:%[a-z_0-9]+]] = getelementptr i8* [[FIRST_REG]], i32 12
comment|// CHECK: [[EL_TYPED:%[a-z_0-9]+]] = bitcast i8* [[EL_ADDR]] to float*
comment|// CHECK: [[EL_TMPADDR:%[a-z_0-9]+]] = getelementptr inbounds [2 x float]* %[[TMP_HFA:[a-z_.0-9]+]], i32 0, i32 0
comment|// CHECK: [[EL:%[a-z_0-9]+]] = load float* [[EL_TYPED]]
comment|// CHECK: store float [[EL]], float* [[EL_TMPADDR]]
comment|// CHECK-LE: [[EL_ADDR:%[a-z_0-9]+]] = getelementptr i8* [[FIRST_REG]], i32 16
comment|// CHECK-BE: [[EL_ADDR:%[a-z_0-9]+]] = getelementptr i8* [[FIRST_REG]], i32 28
comment|// CHECK: [[EL_TYPED:%[a-z_0-9]+]] = bitcast i8* [[EL_ADDR]] to float*
comment|// CHECK: [[EL_TMPADDR:%[a-z_0-9]+]] = getelementptr inbounds [2 x float]* %[[TMP_HFA]], i32 0, i32 1
comment|// CHECK: [[EL:%[a-z_0-9]+]] = load float* [[EL_TYPED]]
comment|// CHECK: store float [[EL]], float* [[EL_TMPADDR]]
comment|// CHECK: [[FROMREG_ADDR:%[a-z_0-9]+]] = bitcast [2 x float]* %[[TMP_HFA]] to %struct.hfa*
comment|// CHECK: br label %[[VAARG_END:[a-z_.0-9]+]]
comment|// CHECK: [[VAARG_ON_STACK]]
comment|// CHECK: [[STACK:%[a-z_0-9]+]] = load i8** getelementptr inbounds (%struct.__va_list* @the_list, i32 0, i32 0)
comment|// CHECK: [[NEW_STACK:%[a-z_0-9]+]] = getelementptr i8* [[STACK]], i32 8
comment|// CHECK: store i8* [[NEW_STACK]], i8** getelementptr inbounds (%struct.__va_list* @the_list, i32 0, i32 0)
comment|// CHECK: [[FROMSTACK_ADDR:%[a-z_0-9]+]] = bitcast i8* [[STACK]] to %struct.hfa*
comment|// CHECK: br label %[[VAARG_END]]
comment|// CHECK: [[VAARG_END]]
comment|// CHECK: [[ADDR:%[a-z._0-9]+]] = phi %struct.hfa* [ [[FROMREG_ADDR]], %[[VAARG_IN_REG]] ], [ [[FROMSTACK_ADDR]], %[[VAARG_ON_STACK]] ]
block|}
end_function

begin_function
name|void
name|check_start
parameter_list|(
name|int
name|n
parameter_list|,
modifier|...
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @check_start(i32 %n, ...)
name|va_list
name|the_list
decl_stmt|;
name|va_start
argument_list|(
name|the_list
argument_list|,
name|n
argument_list|)
expr_stmt|;
comment|// CHECK: [[THE_LIST:%[a-z_0-9]+]] = alloca %struct.__va_list
comment|// CHECK: [[VOIDP_THE_LIST:%[a-z_0-9]+]] = bitcast %struct.__va_list* [[THE_LIST]] to i8*
comment|// CHECK: call void @llvm.va_start(i8* [[VOIDP_THE_LIST]])
block|}
end_function

end_unit

