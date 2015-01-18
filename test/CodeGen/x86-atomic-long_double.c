begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-linux-gnu -target-cpu core2 %s -S -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-linux-gnu -target-cpu core2 %s -S -emit-llvm -o - | FileCheck -check-prefix=CHECK32 %s
end_comment

begin_function
name|long
name|double
name|testinc
parameter_list|(
specifier|_Atomic
name|long
name|double
modifier|*
name|addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @testinc
comment|// CHECK: store x86_fp80* %{{.+}}, x86_fp80** [[ADDR_ADDR:%.+]], align 8
comment|// CHECK: [[ADDR:%.+]] = load x86_fp80** [[ADDR_ADDR]], align 8
comment|// CHECK: [[INT_ADDR:%.+]] = bitcast x86_fp80* [[ADDR]] to i128*
comment|// CHECK: [[INT_VALUE:%.+]] = load atomic i128* [[INT_ADDR]] seq_cst, align 16
comment|// CHECK: [[INT_LOAD_ADDR:%.+]] = bitcast x86_fp80* [[LD_ADDR:%.+]] to i128*
comment|// CHECK: store i128 [[INT_VALUE]], i128* [[INT_LOAD_ADDR]], align 16
comment|// CHECK: [[LD_VALUE:%.+]] = load x86_fp80* [[LD_ADDR]], align 16
comment|// CHECK: br label %[[ATOMIC_OP:.+]]
comment|// CHECK: [[ATOMIC_OP]]
comment|// CHECK: [[OLD_VALUE:%.+]] = phi x86_fp80 [ [[LD_VALUE]], %{{.+}} ], [ [[LD_VALUE:%.+]], %[[ATOMIC_OP]] ]
comment|// CHECK: [[INC_VALUE:%.+]] = fadd x86_fp80 [[OLD_VALUE]],
comment|// CHECK: [[OLD_VALUE_VOID_ADDR:%.+]] = bitcast x86_fp80* [[OLD_VALUE_ADDR:%.+]] to i8*
comment|// CHECK: call void @llvm.memset.p0i8.i64(i8* [[OLD_VALUE_VOID_ADDR]], i8 0, i64 16, i32 16, i1 false)
comment|// CHECK: store x86_fp80 [[OLD_VALUE]], x86_fp80* [[OLD_VALUE_ADDR]], align 16
comment|// CHECK: [[OLD_INT_ADDR:%.+]] = bitcast x86_fp80* [[OLD_VALUE_ADDR]] to i128*
comment|// CHECK: [[OLD_INT:%.+]] = load i128* [[OLD_INT_ADDR]], align 16
comment|// CHECK: [[NEW_VALUE_VOID_ADDR:%.+]] = bitcast x86_fp80* [[NEW_VALUE_ADDR:%.+]] to i8*
comment|// CHECK: call void @llvm.memset.p0i8.i64(i8* [[NEW_VALUE_VOID_ADDR]], i8 0, i64 16, i32 16, i1 false)
comment|// CHECK: store x86_fp80 [[INC_VALUE]], x86_fp80* [[NEW_VALUE_ADDR]], align 16
comment|// CHECK: [[NEW_INT_ADDR:%.+]] = bitcast x86_fp80* [[NEW_VALUE_ADDR]] to i128*
comment|// CHECK: [[NEW_INT:%.+]] = load i128* [[NEW_INT_ADDR]], align 16
comment|// CHECK: [[OBJ_INT_ADDR:%.+]] = bitcast x86_fp80* [[ADDR]] to i128*
comment|// CHECK: [[RES:%.+]] = cmpxchg i128* [[OBJ_INT_ADDR]], i128 [[OLD_INT]], i128 [[NEW_INT]] seq_cst seq_cst
comment|// CHECK: [[OLD_VALUE:%.+]] = extractvalue { i128, i1 } [[RES]], 0
comment|// CHECK: [[FAIL_SUCCESS:%.+]] = extractvalue { i128, i1 } [[RES]], 1
comment|// CHECK: [[OLD_VALUE_RES_INT_PTR:%.+]] = bitcast x86_fp80* [[OLD_VALUE_RES_PTR:%.+]] to i128*
comment|// CHECK: store i128 [[OLD_VALUE]], i128* [[OLD_VALUE_RES_INT_PTR]], align 16
comment|// CHECK: [[LD_VALUE]] = load x86_fp80* [[OLD_VALUE_RES_PTR]], align 16
comment|// CHECK: br i1 [[FAIL_SUCCESS]], label %[[ATOMIC_CONT:.+]], label %[[ATOMIC_OP]]
comment|// CHECK: [[ATOMIC_CONT]]
comment|// CHECK: ret x86_fp80 [[INC_VALUE]]
comment|// CHECK32-LABEL: @testinc
comment|// CHECK32: store x86_fp80* %{{.+}}, x86_fp80** [[ADDR_ADDR:%.+]], align 4
comment|// CHECK32: [[ADDR:%.+]] = load x86_fp80** [[ADDR_ADDR]], align 4
comment|// CHECK32: [[VOID_PTR:%.+]] = bitcast x86_fp80* [[ADDR]] to i8*
comment|// CHECK32: [[TEMP_LD_PTR:%.+]] = bitcast x86_fp80* [[TEMP_LD_ADDR:%.+]] to i8*
comment|// CHECK32: call void @__atomic_load(i32 12, i8* [[VOID_PTR]], i8* [[TEMP_LD_PTR]], i32 5)
comment|// CHECK32: [[LD_VALUE:%.+]] = load x86_fp80* [[TEMP_LD_ADDR]], align 4
comment|// CHECK32: br label %[[ATOMIC_OP:.+]]
comment|// CHECK32: [[ATOMIC_OP]]
comment|// CHECK32: [[OLD_VALUE:%.+]] = phi x86_fp80 [ [[LD_VALUE]], %{{.+}} ], [ [[LD_VALUE:%.+]], %[[ATOMIC_OP]] ]
comment|// CHECK32: [[INC_VALUE:%.+]] = fadd x86_fp80 [[OLD_VALUE]],
comment|// CHECK32: [[OLD_VALUE_VOID_ADDR:%.+]] = bitcast x86_fp80* [[OLD_VALUE_ADDR:%.+]] to i8*
comment|// CHECK32: call void @llvm.memset.p0i8.i64(i8* [[OLD_VALUE_VOID_ADDR]], i8 0, i64 12, i32 4, i1 false)
comment|// CHECK32: store x86_fp80 [[OLD_VALUE]], x86_fp80* [[OLD_VALUE_ADDR]], align 4
comment|// CHECK32: [[DESIRED_VALUE_VOID_ADDR:%.+]] = bitcast x86_fp80* [[DESIRED_VALUE_ADDR:%.+]] to i8*
comment|// CHECK32: call void @llvm.memset.p0i8.i64(i8* [[DESIRED_VALUE_VOID_ADDR]], i8 0, i64 12, i32 4, i1 false)
comment|// CHECK32: store x86_fp80 [[INC_VALUE]], x86_fp80* [[DESIRED_VALUE_ADDR]], align 4
comment|// CHECK32: [[OBJ:%.+]] = bitcast x86_fp80* [[ADDR]] to i8*
comment|// CHECK32: [[EXPECTED:%.+]] = bitcast x86_fp80* [[OLD_VALUE_ADDR]] to i8*
comment|// CHECK32: [[DESIRED:%.+]] = bitcast x86_fp80* [[DESIRED_VALUE_ADDR]] to i8*
comment|// CHECK32: [[FAIL_SUCCESS:%.+]] = call zeroext i1 @__atomic_compare_exchange(i32 12, i8* [[OBJ]], i8* [[EXPECTED]], i8* [[DESIRED]], i32 7, i32 7)
comment|// CHECK32: [[LD_VALUE:%.+]] = load x86_fp80* [[OLD_VALUE_ADDR]], align 4
comment|// CHECK32: br i1 [[FAIL_SUCCESS]], label %[[ATOMIC_CONT:.+]], label %[[ATOMIC_OP]]
comment|// CHECK32: [[ATOMIC_CONT]]
comment|// CHECK32: ret x86_fp80 [[INC_VALUE]]
return|return
operator|++
operator|*
name|addr
return|;
block|}
end_function

begin_function
name|long
name|double
name|testdec
parameter_list|(
specifier|_Atomic
name|long
name|double
modifier|*
name|addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @testdec
comment|// CHECK: store x86_fp80* %{{.+}}, x86_fp80** [[ADDR_ADDR:%.+]], align 8
comment|// CHECK: [[ADDR:%.+]] = load x86_fp80** [[ADDR_ADDR]], align 8
comment|// CHECK: [[INT_ADDR:%.+]] = bitcast x86_fp80* [[ADDR]] to i128*
comment|// CHECK: [[INT_VALUE:%.+]] = load atomic i128* [[INT_ADDR]] seq_cst, align 16
comment|// CHECK: [[INT_LOAD_ADDR:%.+]] = bitcast x86_fp80* [[LD_ADDR:%.+]] to i128*
comment|// CHECK: store i128 [[INT_VALUE]], i128* [[INT_LOAD_ADDR]], align 16
comment|// CHECK: [[ORIG_LD_VALUE:%.+]] = load x86_fp80* [[LD_ADDR]], align 16
comment|// CHECK: br label %[[ATOMIC_OP:.+]]
comment|// CHECK: [[ATOMIC_OP]]
comment|// CHECK: [[OLD_VALUE:%.+]] = phi x86_fp80 [ [[ORIG_LD_VALUE]], %{{.+}} ], [ [[LD_VALUE:%.+]], %[[ATOMIC_OP]] ]
comment|// CHECK: [[DEC_VALUE:%.+]] = fadd x86_fp80 [[OLD_VALUE]],
comment|// CHECK: [[OLD_VALUE_VOID_ADDR:%.+]] = bitcast x86_fp80* [[OLD_VALUE_ADDR:%.+]] to i8*
comment|// CHECK: call void @llvm.memset.p0i8.i64(i8* [[OLD_VALUE_VOID_ADDR]], i8 0, i64 16, i32 16, i1 false)
comment|// CHECK: store x86_fp80 [[OLD_VALUE]], x86_fp80* [[OLD_VALUE_ADDR]], align 16
comment|// CHECK: [[OLD_INT_ADDR:%.+]] = bitcast x86_fp80* [[OLD_VALUE_ADDR]] to i128*
comment|// CHECK: [[OLD_INT:%.+]] = load i128* [[OLD_INT_ADDR]], align 16
comment|// CHECK: [[NEW_VALUE_VOID_ADDR:%.+]] = bitcast x86_fp80* [[NEW_VALUE_ADDR:%.+]] to i8*
comment|// CHECK: call void @llvm.memset.p0i8.i64(i8* [[NEW_VALUE_VOID_ADDR]], i8 0, i64 16, i32 16, i1 false)
comment|// CHECK: store x86_fp80 [[DEC_VALUE]], x86_fp80* [[NEW_VALUE_ADDR]], align 16
comment|// CHECK: [[NEW_INT_ADDR:%.+]] = bitcast x86_fp80* [[NEW_VALUE_ADDR]] to i128*
comment|// CHECK: [[NEW_INT:%.+]] = load i128* [[NEW_INT_ADDR]], align 16
comment|// CHECK: [[OBJ_INT_ADDR:%.+]] = bitcast x86_fp80* [[ADDR]] to i128*
comment|// CHECK: [[RES:%.+]] = cmpxchg i128* [[OBJ_INT_ADDR]], i128 [[OLD_INT]], i128 [[NEW_INT]] seq_cst seq_cst
comment|// CHECK: [[OLD_VALUE:%.+]] = extractvalue { i128, i1 } [[RES]], 0
comment|// CHECK: [[FAIL_SUCCESS:%.+]] = extractvalue { i128, i1 } [[RES]], 1
comment|// CHECK: [[OLD_VALUE_RES_INT_PTR:%.+]] = bitcast x86_fp80* [[OLD_VALUE_RES_PTR:%.+]] to i128*
comment|// CHECK: store i128 [[OLD_VALUE]], i128* [[OLD_VALUE_RES_INT_PTR]], align 16
comment|// CHECK: [[LD_VALUE]] = load x86_fp80* [[OLD_VALUE_RES_PTR]], align 16
comment|// CHECK: br i1 [[FAIL_SUCCESS]], label %[[ATOMIC_CONT:.+]], label %[[ATOMIC_OP]]
comment|// CHECK: [[ATOMIC_CONT]]
comment|// CHECK: ret x86_fp80 [[ORIG_LD_VALUE]]
comment|// CHECK32-LABEL: @testdec
comment|// CHECK32: store x86_fp80* %{{.+}}, x86_fp80** [[ADDR_ADDR:%.+]], align 4
comment|// CHECK32: [[ADDR:%.+]] = load x86_fp80** [[ADDR_ADDR]], align 4
comment|// CHECK32: [[VOID_PTR:%.+]] = bitcast x86_fp80* [[ADDR]] to i8*
comment|// CHECK32: [[TEMP_LD_PTR:%.+]] = bitcast x86_fp80* [[TEMP_LD_ADDR:%.+]] to i8*
comment|// CHECK32: call void @__atomic_load(i32 12, i8* [[VOID_PTR]], i8* [[TEMP_LD_PTR]], i32 5)
comment|// CHECK32: [[ORIG_LD_VALUE:%.+]] = load x86_fp80* [[TEMP_LD_ADDR]], align 4
comment|// CHECK32: br label %[[ATOMIC_OP:.+]]
comment|// CHECK32: [[ATOMIC_OP]]
comment|// CHECK32: [[OLD_VALUE:%.+]] = phi x86_fp80 [ [[ORIG_LD_VALUE]], %{{.+}} ], [ [[LD_VALUE:%.+]], %[[ATOMIC_OP]] ]
comment|// CHECK32: [[DEC_VALUE:%.+]] = fadd x86_fp80 [[OLD_VALUE]],
comment|// CHECK32: [[OLD_VALUE_VOID_ADDR:%.+]] = bitcast x86_fp80* [[OLD_VALUE_ADDR:%.+]] to i8*
comment|// CHECK32: call void @llvm.memset.p0i8.i64(i8* [[OLD_VALUE_VOID_ADDR]], i8 0, i64 12, i32 4, i1 false)
comment|// CHECK32: store x86_fp80 [[OLD_VALUE]], x86_fp80* [[OLD_VALUE_ADDR]], align 4
comment|// CHECK32: [[DESIRED_VALUE_VOID_ADDR:%.+]] = bitcast x86_fp80* [[DESIRED_VALUE_ADDR:%.+]] to i8*
comment|// CHECK32: call void @llvm.memset.p0i8.i64(i8* [[DESIRED_VALUE_VOID_ADDR]], i8 0, i64 12, i32 4, i1 false)
comment|// CHECK32: store x86_fp80 [[DEC_VALUE]], x86_fp80* [[DESIRED_VALUE_ADDR]], align 4
comment|// CHECK32: [[OBJ:%.+]] = bitcast x86_fp80* [[ADDR]] to i8*
comment|// CHECK32: [[EXPECTED:%.+]] = bitcast x86_fp80* [[OLD_VALUE_ADDR]] to i8*
comment|// CHECK32: [[DESIRED:%.+]] = bitcast x86_fp80* [[DESIRED_VALUE_ADDR]] to i8*
comment|// CHECK32: [[FAIL_SUCCESS:%.+]] = call zeroext i1 @__atomic_compare_exchange(i32 12, i8* [[OBJ]], i8* [[EXPECTED]], i8* [[DESIRED]], i32 7, i32 7)
comment|// CHECK32: [[LD_VALUE]] = load x86_fp80* [[OLD_VALUE_ADDR]], align 4
comment|// CHECK32: br i1 [[FAIL_SUCCESS]], label %[[ATOMIC_CONT:.+]], label %[[ATOMIC_OP]]
comment|// CHECK32: [[ATOMIC_CONT]]
comment|// CHECK32: ret x86_fp80 [[ORIG_LD_VALUE]]
return|return
operator|(
operator|*
name|addr
operator|)
operator|--
return|;
block|}
end_function

begin_function
name|long
name|double
name|testcompassign
parameter_list|(
specifier|_Atomic
name|long
name|double
modifier|*
name|addr
parameter_list|)
block|{
operator|*
name|addr
operator|-=
literal|25
expr_stmt|;
comment|// CHECK-LABEL: @testcompassign
comment|// CHECK: store x86_fp80* %{{.+}}, x86_fp80** [[ADDR_ADDR:%.+]], align 8
comment|// CHECK: [[ADDR:%.+]] = load x86_fp80** [[ADDR_ADDR]], align 8
comment|// CHECK: [[INT_ADDR:%.+]] = bitcast x86_fp80* [[ADDR]] to i128*
comment|// CHECK: [[INT_VALUE:%.+]] = load atomic i128* [[INT_ADDR]] seq_cst, align 16
comment|// CHECK: [[INT_LOAD_ADDR:%.+]] = bitcast x86_fp80* [[LD_ADDR:%.+]] to i128*
comment|// CHECK: store i128 [[INT_VALUE]], i128* [[INT_LOAD_ADDR]], align 16
comment|// CHECK: [[LD_VALUE:%.+]] = load x86_fp80* [[LD_ADDR]], align 16
comment|// CHECK: br label %[[ATOMIC_OP:.+]]
comment|// CHECK: [[ATOMIC_OP]]
comment|// CHECK: [[OLD_VALUE:%.+]] = phi x86_fp80 [ [[LD_VALUE]], %{{.+}} ], [ [[LD_VALUE:%.+]], %[[ATOMIC_OP]] ]
comment|// CHECK: [[SUB_VALUE:%.+]] = fsub x86_fp80 [[OLD_VALUE]],
comment|// CHECK: [[OLD_VALUE_VOID_ADDR:%.+]] = bitcast x86_fp80* [[OLD_VALUE_ADDR:%.+]] to i8*
comment|// CHECK: call void @llvm.memset.p0i8.i64(i8* [[OLD_VALUE_VOID_ADDR]], i8 0, i64 16, i32 16, i1 false)
comment|// CHECK: store x86_fp80 [[OLD_VALUE]], x86_fp80* [[OLD_VALUE_ADDR]], align 16
comment|// CHECK: [[OLD_INT_ADDR:%.+]] = bitcast x86_fp80* [[OLD_VALUE_ADDR]] to i128*
comment|// CHECK: [[OLD_INT:%.+]] = load i128* [[OLD_INT_ADDR]], align 16
comment|// CHECK: [[NEW_VALUE_VOID_ADDR:%.+]] = bitcast x86_fp80* [[NEW_VALUE_ADDR:%.+]] to i8*
comment|// CHECK: call void @llvm.memset.p0i8.i64(i8* [[NEW_VALUE_VOID_ADDR]], i8 0, i64 16, i32 16, i1 false)
comment|// CHECK: store x86_fp80 [[SUB_VALUE]], x86_fp80* [[NEW_VALUE_ADDR]], align 16
comment|// CHECK: [[NEW_INT_ADDR:%.+]] = bitcast x86_fp80* [[NEW_VALUE_ADDR]] to i128*
comment|// CHECK: [[NEW_INT:%.+]] = load i128* [[NEW_INT_ADDR]], align 16
comment|// CHECK: [[OBJ_INT_ADDR:%.+]] = bitcast x86_fp80* [[ADDR]] to i128*
comment|// CHECK: [[RES:%.+]] = cmpxchg i128* [[OBJ_INT_ADDR]], i128 [[OLD_INT]], i128 [[NEW_INT]] seq_cst seq_cst
comment|// CHECK: [[OLD_VALUE:%.+]] = extractvalue { i128, i1 } [[RES]], 0
comment|// CHECK: [[FAIL_SUCCESS:%.+]] = extractvalue { i128, i1 } [[RES]], 1
comment|// CHECK: [[OLD_VALUE_RES_INT_PTR:%.+]] = bitcast x86_fp80* [[OLD_VALUE_RES_PTR:%.+]] to i128*
comment|// CHECK: store i128 [[OLD_VALUE]], i128* [[OLD_VALUE_RES_INT_PTR]], align 16
comment|// CHECK: [[LD_VALUE]] = load x86_fp80* [[OLD_VALUE_RES_PTR]], align 16
comment|// CHECK: br i1 [[FAIL_SUCCESS]], label %[[ATOMIC_CONT:.+]], label %[[ATOMIC_OP]]
comment|// CHECK: [[ATOMIC_CONT]]
comment|// CHECK: [[ADDR:%.+]] = load x86_fp80** %{{.+}}, align 8
comment|// CHECK: [[ADDR_INT:%.+]] = bitcast x86_fp80* [[ADDR]] to i128*
comment|// CHECK: [[INT_VAL:%.+]] = load atomic i128* [[ADDR_INT]] seq_cst, align 16
comment|// CHECK: [[INT_LD_TEMP:%.+]] = bitcast x86_fp80* [[LD_TEMP:%.+]] to i128*
comment|// CHECK: store i128 [[INT_VAL]], i128* [[INT_LD_TEMP:%.+]], align 16
comment|// CHECK: [[RET_VAL:%.+]] = load x86_fp80* [[LD_TEMP]], align 16
comment|// CHECK: ret x86_fp80 [[RET_VAL]]
comment|// CHECK32-LABEL: @testcompassign
comment|// CHECK32: store x86_fp80* %{{.+}}, x86_fp80** [[ADDR_ADDR:%.+]], align 4
comment|// CHECK32: [[ADDR:%.+]] = load x86_fp80** [[ADDR_ADDR]], align 4
comment|// CHECK32: [[VOID_PTR:%.+]] = bitcast x86_fp80* [[ADDR]] to i8*
comment|// CHECK32: [[TEMP_LD_PTR:%.+]] = bitcast x86_fp80* [[TEMP_LD_ADDR:%.+]] to i8*
comment|// CHECK32: call void @__atomic_load(i32 12, i8* [[VOID_PTR]], i8* [[TEMP_LD_PTR]], i32 5)
comment|// CHECK32: [[LD_VALUE:%.+]] = load x86_fp80* [[TEMP_LD_ADDR]], align 4
comment|// CHECK32: br label %[[ATOMIC_OP:.+]]
comment|// CHECK32: [[ATOMIC_OP]]
comment|// CHECK32: [[OLD_VALUE:%.+]] = phi x86_fp80 [ [[LD_VALUE]], %{{.+}} ], [ [[LD_VALUE:%.+]], %[[ATOMIC_OP]] ]
comment|// CHECK32: [[INC_VALUE:%.+]] = fsub x86_fp80 [[OLD_VALUE]],
comment|// CHECK32: [[OLD_VALUE_VOID_ADDR:%.+]] = bitcast x86_fp80* [[OLD_VALUE_ADDR:%.+]] to i8*
comment|// CHECK32: call void @llvm.memset.p0i8.i64(i8* [[OLD_VALUE_VOID_ADDR]], i8 0, i64 12, i32 4, i1 false)
comment|// CHECK32: store x86_fp80 [[OLD_VALUE]], x86_fp80* [[OLD_VALUE_ADDR]], align 4
comment|// CHECK32: [[DESIRED_VALUE_VOID_ADDR:%.+]] = bitcast x86_fp80* [[DESIRED_VALUE_ADDR:%.+]] to i8*
comment|// CHECK32: call void @llvm.memset.p0i8.i64(i8* [[DESIRED_VALUE_VOID_ADDR]], i8 0, i64 12, i32 4, i1 false)
comment|// CHECK32: store x86_fp80 [[INC_VALUE]], x86_fp80* [[DESIRED_VALUE_ADDR]], align 4
comment|// CHECK32: [[OBJ:%.+]] = bitcast x86_fp80* [[ADDR]] to i8*
comment|// CHECK32: [[EXPECTED:%.+]] = bitcast x86_fp80* [[OLD_VALUE_ADDR]] to i8*
comment|// CHECK32: [[DESIRED:%.+]] = bitcast x86_fp80* [[DESIRED_VALUE_ADDR]] to i8*
comment|// CHECK32: [[FAIL_SUCCESS:%.+]] = call zeroext i1 @__atomic_compare_exchange(i32 12, i8* [[OBJ]], i8* [[EXPECTED]], i8* [[DESIRED]], i32 7, i32 7)
comment|// CHECK32: [[LD_VALUE]] = load x86_fp80* [[OLD_VALUE_ADDR]], align 4
comment|// CHECK32: br i1 [[FAIL_SUCCESS]], label %[[ATOMIC_CONT:.+]], label %[[ATOMIC_OP]]
comment|// CHECK32: [[ATOMIC_CONT]]
comment|// CHECK32: [[ADDR:%.+]] = load x86_fp80** %{{.+}}, align 4
comment|// CHECK32: [[VOID_ADDR:%.+]] = bitcast x86_fp80* [[ADDR]] to i8*
comment|// CHECK32: [[VOID_GET_ADDR:%.+]] = bitcast x86_fp80* [[GET_ADDR:%.+]] to i8*
comment|// CHECK32: call void @__atomic_load(i32 12, i8* [[VOID_ADDR]], i8* [[VOID_GET_ADDR]], i32 5)
comment|// CHECK32: [[RET_VAL:%.+]] = load x86_fp80* [[GET_ADDR]], align 4
comment|// CHECK32: ret x86_fp80 [[RET_VAL]]
return|return
operator|*
name|addr
return|;
block|}
end_function

begin_function
name|long
name|double
name|testassign
parameter_list|(
specifier|_Atomic
name|long
name|double
modifier|*
name|addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @testassign
comment|// CHECK: store x86_fp80* %{{.+}}, x86_fp80** [[ADDR_ADDR:%.+]], align 8
comment|// CHECK: [[ADDR:%.+]] = load x86_fp80** [[ADDR_ADDR]], align 8
comment|// CHECK: [[STORE_TEMP_VOID_PTR:%.+]] = bitcast x86_fp80* [[STORE_TEMP_PTR:%.+]] to i8*
comment|// CHECK: call void @llvm.memset.p0i8.i64(i8* [[STORE_TEMP_VOID_PTR]], i8 0, i64 16, i32 16, i1 false)
comment|// CHECK: store x86_fp80 {{.+}}, x86_fp80* [[STORE_TEMP_PTR]], align 16
comment|// CHECK: [[STORE_TEMP_INT_PTR:%.+]] = bitcast x86_fp80* [[STORE_TEMP_PTR]] to i128*
comment|// CHECK: [[STORE_TEMP_INT:%.+]] = load i128* [[STORE_TEMP_INT_PTR]], align 16
comment|// CHECK: [[ADDR_INT:%.+]] = bitcast x86_fp80* [[ADDR]] to i128*
comment|// CHECK: store atomic i128 [[STORE_TEMP_INT]], i128* [[ADDR_INT]] seq_cst, align 16
comment|// CHECK32-LABEL: @testassign
comment|// CHECK32: store x86_fp80* %{{.+}}, x86_fp80** [[ADDR_ADDR:%.+]], align 4
comment|// CHECK32: [[ADDR:%.+]] = load x86_fp80** [[ADDR_ADDR]], align 4
comment|// CHECK32: [[STORE_TEMP_VOID_PTR:%.+]] = bitcast x86_fp80* [[STORE_TEMP_PTR:%.+]] to i8*
comment|// CHECK32: call void @llvm.memset.p0i8.i64(i8* [[STORE_TEMP_VOID_PTR]], i8 0, i64 12, i32 4, i1 false)
comment|// CHECK32: store x86_fp80 {{.+}}, x86_fp80* [[STORE_TEMP_PTR]], align 4
comment|// CHECK32: [[ADDR_VOID:%.+]] = bitcast x86_fp80* [[ADDR]] to i8*
comment|// CHECK32: [[STORE_TEMP_VOID_PTR:%.+]] = bitcast x86_fp80* [[STORE_TEMP_PTR]] to i8*
comment|// CHECK32: call void @__atomic_store(i32 12, i8* [[ADDR_VOID]], i8* [[STORE_TEMP_VOID_PTR]], i32 5)
operator|*
name|addr
operator|=
literal|115
expr_stmt|;
comment|// CHECK: [[ADDR:%.+]] = load x86_fp80** %{{.+}}, align 8
comment|// CHECK: [[ADDR_INT:%.+]] = bitcast x86_fp80* [[ADDR]] to i128*
comment|// CHECK: [[INT_VAL:%.+]] = load atomic i128* [[ADDR_INT]] seq_cst, align 16
comment|// CHECK: [[INT_LD_TEMP:%.+]] = bitcast x86_fp80* [[LD_TEMP:%.+]] to i128*
comment|// CHECK: store i128 [[INT_VAL]], i128* [[INT_LD_TEMP:%.+]], align 16
comment|// CHECK: [[RET_VAL:%.+]] = load x86_fp80* [[LD_TEMP]], align 16
comment|// CHECK: ret x86_fp80 [[RET_VAL]]
comment|// CHECK32: [[ADDR:%.+]] = load x86_fp80** %{{.+}}, align 4
comment|// CHECK32: [[VOID_ADDR:%.+]] = bitcast x86_fp80* [[ADDR]] to i8*
comment|// CHECK32: [[VOID_LD_TEMP:%.+]] = bitcast x86_fp80* [[LD_TEMP:%.+]] to i8*
comment|// CHECK32: call void @__atomic_load(i32 12, i8* [[VOID_ADDR]], i8* [[VOID_LD_TEMP]], i32 5)
comment|// CHECK32: [[RET_VAL:%.+]] = load x86_fp80* [[LD_TEMP]], align 4
comment|// CHECK32: ret x86_fp80 [[RET_VAL]]
return|return
operator|*
name|addr
return|;
block|}
end_function

begin_function
name|long
name|double
name|test_volatile_inc
parameter_list|(
specifier|volatile
specifier|_Atomic
name|long
name|double
modifier|*
name|addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_volatile_inc
comment|// CHECK: store x86_fp80* %{{.+}}, x86_fp80** [[ADDR_ADDR:%.+]], align 8
comment|// CHECK: [[ADDR:%.+]] = load x86_fp80** [[ADDR_ADDR]], align 8
comment|// CHECK: [[INT_ADDR:%.+]] = bitcast x86_fp80* [[ADDR]] to i128*
comment|// CHECK: [[INT_VALUE:%.+]] = load atomic volatile i128* [[INT_ADDR]] seq_cst, align 16
comment|// CHECK: [[INT_LOAD_ADDR:%.+]] = bitcast x86_fp80* [[LD_ADDR:%.+]] to i128*
comment|// CHECK: store i128 [[INT_VALUE]], i128* [[INT_LOAD_ADDR]], align 16
comment|// CHECK: [[LD_VALUE:%.+]] = load x86_fp80* [[LD_ADDR]], align 16
comment|// CHECK: br label %[[ATOMIC_OP:.+]]
comment|// CHECK: [[ATOMIC_OP]]
comment|// CHECK: [[OLD_VALUE:%.+]] = phi x86_fp80 [ [[LD_VALUE]], %{{.+}} ], [ [[LD_VALUE:%.+]], %[[ATOMIC_OP]] ]
comment|// CHECK: [[INC_VALUE:%.+]] = fadd x86_fp80 [[OLD_VALUE]],
comment|// CHECK: [[OLD_VALUE_VOID_ADDR:%.+]] = bitcast x86_fp80* [[OLD_VALUE_ADDR:%.+]] to i8*
comment|// CHECK: call void @llvm.memset.p0i8.i64(i8* [[OLD_VALUE_VOID_ADDR]], i8 0, i64 16, i32 16, i1 false)
comment|// CHECK: store x86_fp80 [[OLD_VALUE]], x86_fp80* [[OLD_VALUE_ADDR]], align 16
comment|// CHECK: [[OLD_INT_ADDR:%.+]] = bitcast x86_fp80* [[OLD_VALUE_ADDR]] to i128*
comment|// CHECK: [[OLD_INT:%.+]] = load i128* [[OLD_INT_ADDR]], align 16
comment|// CHECK: [[NEW_VALUE_VOID_ADDR:%.+]] = bitcast x86_fp80* [[NEW_VALUE_ADDR:%.+]] to i8*
comment|// CHECK: call void @llvm.memset.p0i8.i64(i8* [[NEW_VALUE_VOID_ADDR]], i8 0, i64 16, i32 16, i1 false)
comment|// CHECK: store x86_fp80 [[INC_VALUE]], x86_fp80* [[NEW_VALUE_ADDR]], align 16
comment|// CHECK: [[NEW_INT_ADDR:%.+]] = bitcast x86_fp80* [[NEW_VALUE_ADDR]] to i128*
comment|// CHECK: [[NEW_INT:%.+]] = load i128* [[NEW_INT_ADDR]], align 16
comment|// CHECK: [[OBJ_INT_ADDR:%.+]] = bitcast x86_fp80* [[ADDR]] to i128*
comment|// CHECK: [[RES:%.+]] = cmpxchg volatile i128* [[OBJ_INT_ADDR]], i128 [[OLD_INT]], i128 [[NEW_INT]] seq_cst seq_cst
comment|// CHECK: [[OLD_VALUE:%.+]] = extractvalue { i128, i1 } [[RES]], 0
comment|// CHECK: [[FAIL_SUCCESS:%.+]] = extractvalue { i128, i1 } [[RES]], 1
comment|// CHECK: [[OLD_VALUE_RES_INT_PTR:%.+]] = bitcast x86_fp80* [[OLD_VALUE_RES_PTR:%.+]] to i128*
comment|// CHECK: store i128 [[OLD_VALUE]], i128* [[OLD_VALUE_RES_INT_PTR]], align 16
comment|// CHECK: [[LD_VALUE]] = load x86_fp80* [[OLD_VALUE_RES_PTR]], align 16
comment|// CHECK: br i1 [[FAIL_SUCCESS]], label %[[ATOMIC_CONT:.+]], label %[[ATOMIC_OP]]
comment|// CHECK: [[ATOMIC_CONT]]
comment|// CHECK: ret x86_fp80 [[INC_VALUE]]
comment|// CHECK32-LABEL: @test_volatile_inc
comment|// CHECK32: store x86_fp80* %{{.+}}, x86_fp80** [[ADDR_ADDR:%.+]], align 4
comment|// CHECK32: [[ADDR:%.+]] = load x86_fp80** [[ADDR_ADDR]], align 4
comment|// CHECK32: [[VOID_PTR:%.+]] = bitcast x86_fp80* [[ADDR]] to i8*
comment|// CHECK32: [[TEMP_LD_PTR:%.+]] = bitcast x86_fp80* [[TEMP_LD_ADDR:%.+]] to i8*
comment|// CHECK32: call void @__atomic_load(i32 12, i8* [[VOID_PTR]], i8* [[TEMP_LD_PTR]], i32 5)
comment|// CHECK32: [[LD_VALUE:%.+]] = load x86_fp80* [[TEMP_LD_ADDR]], align 4
comment|// CHECK32: br label %[[ATOMIC_OP:.+]]
comment|// CHECK32: [[ATOMIC_OP]]
comment|// CHECK32: [[OLD_VALUE:%.+]] = phi x86_fp80 [ [[LD_VALUE]], %{{.+}} ], [ [[LD_VALUE:%.+]], %[[ATOMIC_OP]] ]
comment|// CHECK32: [[INC_VALUE:%.+]] = fadd x86_fp80 [[OLD_VALUE]],
comment|// CHECK32: [[OLD_VALUE_VOID_ADDR:%.+]] = bitcast x86_fp80* [[OLD_VALUE_ADDR:%.+]] to i8*
comment|// CHECK32: call void @llvm.memset.p0i8.i64(i8* [[OLD_VALUE_VOID_ADDR]], i8 0, i64 12, i32 4, i1 false)
comment|// CHECK32: store x86_fp80 [[OLD_VALUE]], x86_fp80* [[OLD_VALUE_ADDR]], align 4
comment|// CHECK32: [[DESIRED_VALUE_VOID_ADDR:%.+]] = bitcast x86_fp80* [[DESIRED_VALUE_ADDR:%.+]] to i8*
comment|// CHECK32: call void @llvm.memset.p0i8.i64(i8* [[DESIRED_VALUE_VOID_ADDR]], i8 0, i64 12, i32 4, i1 false)
comment|// CHECK32: store x86_fp80 [[INC_VALUE]], x86_fp80* [[DESIRED_VALUE_ADDR]], align 4
comment|// CHECK32: [[OBJ:%.+]] = bitcast x86_fp80* [[ADDR]] to i8*
comment|// CHECK32: [[EXPECTED:%.+]] = bitcast x86_fp80* [[OLD_VALUE_ADDR]] to i8*
comment|// CHECK32: [[DESIRED:%.+]] = bitcast x86_fp80* [[DESIRED_VALUE_ADDR]] to i8*
comment|// CHECK32: [[FAIL_SUCCESS:%.+]] = call zeroext i1 @__atomic_compare_exchange(i32 12, i8* [[OBJ]], i8* [[EXPECTED]], i8* [[DESIRED]], i32 7, i32 7)
comment|// CHECK32: [[LD_VALUE]] = load x86_fp80* [[OLD_VALUE_ADDR]], align 4
comment|// CHECK32: br i1 [[FAIL_SUCCESS]], label %[[ATOMIC_CONT:.+]], label %[[ATOMIC_OP]]
comment|// CHECK32: [[ATOMIC_CONT]]
comment|// CHECK32: ret x86_fp80 [[INC_VALUE]]
return|return
operator|++
operator|*
name|addr
return|;
block|}
end_function

begin_function
name|long
name|double
name|test_volatile_dec
parameter_list|(
specifier|volatile
specifier|_Atomic
name|long
name|double
modifier|*
name|addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_volatile_dec
comment|// CHECK: store x86_fp80* %{{.+}}, x86_fp80** [[ADDR_ADDR:%.+]], align 8
comment|// CHECK: [[ADDR:%.+]] = load x86_fp80** [[ADDR_ADDR]], align 8
comment|// CHECK: [[INT_ADDR:%.+]] = bitcast x86_fp80* [[ADDR]] to i128*
comment|// CHECK: [[INT_VALUE:%.+]] = load atomic volatile i128* [[INT_ADDR]] seq_cst, align 16
comment|// CHECK: [[INT_LOAD_ADDR:%.+]] = bitcast x86_fp80* [[LD_ADDR:%.+]] to i128*
comment|// CHECK: store i128 [[INT_VALUE]], i128* [[INT_LOAD_ADDR]], align 16
comment|// CHECK: [[ORIG_LD_VALUE:%.+]] = load x86_fp80* [[LD_ADDR]], align 16
comment|// CHECK: br label %[[ATOMIC_OP:.+]]
comment|// CHECK: [[ATOMIC_OP]]
comment|// CHECK: [[OLD_VALUE:%.+]] = phi x86_fp80 [ [[ORIG_LD_VALUE]], %{{.+}} ], [ [[LD_VALUE:%.+]], %[[ATOMIC_OP]] ]
comment|// CHECK: [[DEC_VALUE:%.+]] = fadd x86_fp80 [[OLD_VALUE]],
comment|// CHECK: [[OLD_VALUE_VOID_ADDR:%.+]] = bitcast x86_fp80* [[OLD_VALUE_ADDR:%.+]] to i8*
comment|// CHECK: call void @llvm.memset.p0i8.i64(i8* [[OLD_VALUE_VOID_ADDR]], i8 0, i64 16, i32 16, i1 false)
comment|// CHECK: store x86_fp80 [[OLD_VALUE]], x86_fp80* [[OLD_VALUE_ADDR]], align 16
comment|// CHECK: [[OLD_INT_ADDR:%.+]] = bitcast x86_fp80* [[OLD_VALUE_ADDR]] to i128*
comment|// CHECK: [[OLD_INT:%.+]] = load i128* [[OLD_INT_ADDR]], align 16
comment|// CHECK: [[NEW_VALUE_VOID_ADDR:%.+]] = bitcast x86_fp80* [[NEW_VALUE_ADDR:%.+]] to i8*
comment|// CHECK: call void @llvm.memset.p0i8.i64(i8* [[NEW_VALUE_VOID_ADDR]], i8 0, i64 16, i32 16, i1 false)
comment|// CHECK: store x86_fp80 [[DEC_VALUE]], x86_fp80* [[NEW_VALUE_ADDR]], align 16
comment|// CHECK: [[NEW_INT_ADDR:%.+]] = bitcast x86_fp80* [[NEW_VALUE_ADDR]] to i128*
comment|// CHECK: [[NEW_INT:%.+]] = load i128* [[NEW_INT_ADDR]], align 16
comment|// CHECK: [[OBJ_INT_ADDR:%.+]] = bitcast x86_fp80* [[ADDR]] to i128*
comment|// CHECK: [[RES:%.+]] = cmpxchg volatile i128* [[OBJ_INT_ADDR]], i128 [[OLD_INT]], i128 [[NEW_INT]] seq_cst seq_cst
comment|// CHECK: [[OLD_VALUE:%.+]] = extractvalue { i128, i1 } [[RES]], 0
comment|// CHECK: [[FAIL_SUCCESS:%.+]] = extractvalue { i128, i1 } [[RES]], 1
comment|// CHECK: [[OLD_VALUE_RES_INT_PTR:%.+]] = bitcast x86_fp80* [[OLD_VALUE_RES_PTR:%.+]] to i128*
comment|// CHECK: store i128 [[OLD_VALUE]], i128* [[OLD_VALUE_RES_INT_PTR]], align 16
comment|// CHECK: [[LD_VALUE]] = load x86_fp80* [[OLD_VALUE_RES_PTR]], align 16
comment|// CHECK: br i1 [[FAIL_SUCCESS]], label %[[ATOMIC_CONT:.+]], label %[[ATOMIC_OP]]
comment|// CHECK: [[ATOMIC_CONT]]
comment|// CHECK: ret x86_fp80 [[ORIG_LD_VALUE]]
comment|// CHECK32-LABEL: @test_volatile_dec
comment|// CHECK32: store x86_fp80* %{{.+}}, x86_fp80** [[ADDR_ADDR:%.+]], align 4
comment|// CHECK32: [[ADDR:%.+]] = load x86_fp80** [[ADDR_ADDR]], align 4
comment|// CHECK32: [[VOID_PTR:%.+]] = bitcast x86_fp80* [[ADDR]] to i8*
comment|// CHECK32: [[TEMP_LD_PTR:%.+]] = bitcast x86_fp80* [[TEMP_LD_ADDR:%.+]] to i8*
comment|// CHECK32: call void @__atomic_load(i32 12, i8* [[VOID_PTR]], i8* [[TEMP_LD_PTR]], i32 5)
comment|// CHECK32: [[ORIG_LD_VALUE:%.+]] = load x86_fp80* [[TEMP_LD_ADDR]], align 4
comment|// CHECK32: br label %[[ATOMIC_OP:.+]]
comment|// CHECK32: [[ATOMIC_OP]]
comment|// CHECK32: [[OLD_VALUE:%.+]] = phi x86_fp80 [ [[ORIG_LD_VALUE]], %{{.+}} ], [ [[LD_VALUE:%.+]], %[[ATOMIC_OP]] ]
comment|// CHECK32: [[DEC_VALUE:%.+]] = fadd x86_fp80 [[OLD_VALUE]],
comment|// CHECK32: [[OLD_VALUE_VOID_ADDR:%.+]] = bitcast x86_fp80* [[OLD_VALUE_ADDR:%.+]] to i8*
comment|// CHECK32: call void @llvm.memset.p0i8.i64(i8* [[OLD_VALUE_VOID_ADDR]], i8 0, i64 12, i32 4, i1 false)
comment|// CHECK32: store x86_fp80 [[OLD_VALUE]], x86_fp80* [[OLD_VALUE_ADDR]], align 4
comment|// CHECK32: [[DESIRED_VALUE_VOID_ADDR:%.+]] = bitcast x86_fp80* [[DESIRED_VALUE_ADDR:%.+]] to i8*
comment|// CHECK32: call void @llvm.memset.p0i8.i64(i8* [[DESIRED_VALUE_VOID_ADDR]], i8 0, i64 12, i32 4, i1 false)
comment|// CHECK32: store x86_fp80 [[DEC_VALUE]], x86_fp80* [[DESIRED_VALUE_ADDR]], align 4
comment|// CHECK32: [[OBJ:%.+]] = bitcast x86_fp80* [[ADDR]] to i8*
comment|// CHECK32: [[EXPECTED:%.+]] = bitcast x86_fp80* [[OLD_VALUE_ADDR]] to i8*
comment|// CHECK32: [[DESIRED:%.+]] = bitcast x86_fp80* [[DESIRED_VALUE_ADDR]] to i8*
comment|// CHECK32: [[FAIL_SUCCESS:%.+]] = call zeroext i1 @__atomic_compare_exchange(i32 12, i8* [[OBJ]], i8* [[EXPECTED]], i8* [[DESIRED]], i32 7, i32 7)
comment|// CHECK32: [[LD_VALUE]] = load x86_fp80* [[OLD_VALUE_ADDR]], align 4
comment|// CHECK32: br i1 [[FAIL_SUCCESS]], label %[[ATOMIC_CONT:.+]], label %[[ATOMIC_OP]]
comment|// CHECK32: [[ATOMIC_CONT]]
comment|// CHECK32: ret x86_fp80 [[ORIG_LD_VALUE]]
return|return
operator|(
operator|*
name|addr
operator|)
operator|--
return|;
block|}
end_function

begin_function
name|long
name|double
name|test_volatile_compassign
parameter_list|(
specifier|volatile
specifier|_Atomic
name|long
name|double
modifier|*
name|addr
parameter_list|)
block|{
operator|*
name|addr
operator|-=
literal|25
expr_stmt|;
comment|// CHECK-LABEL: @test_volatile_compassign
comment|// CHECK: store x86_fp80* %{{.+}}, x86_fp80** [[ADDR_ADDR:%.+]], align 8
comment|// CHECK: [[ADDR:%.+]] = load x86_fp80** [[ADDR_ADDR]], align 8
comment|// CHECK: [[INT_ADDR:%.+]] = bitcast x86_fp80* [[ADDR]] to i128*
comment|// CHECK: [[INT_VALUE:%.+]] = load atomic volatile i128* [[INT_ADDR]] seq_cst, align 16
comment|// CHECK: [[INT_LOAD_ADDR:%.+]] = bitcast x86_fp80* [[LD_ADDR:%.+]] to i128*
comment|// CHECK: store i128 [[INT_VALUE]], i128* [[INT_LOAD_ADDR]], align 16
comment|// CHECK: [[LD_VALUE:%.+]] = load x86_fp80* [[LD_ADDR]], align 16
comment|// CHECK: br label %[[ATOMIC_OP:.+]]
comment|// CHECK: [[ATOMIC_OP]]
comment|// CHECK: [[OLD_VALUE:%.+]] = phi x86_fp80 [ [[LD_VALUE]], %{{.+}} ], [ [[LD_VALUE:%.+]], %[[ATOMIC_OP]] ]
comment|// CHECK: [[SUB_VALUE:%.+]] = fsub x86_fp80 [[OLD_VALUE]],
comment|// CHECK: [[OLD_VALUE_VOID_ADDR:%.+]] = bitcast x86_fp80* [[OLD_VALUE_ADDR:%.+]] to i8*
comment|// CHECK: call void @llvm.memset.p0i8.i64(i8* [[OLD_VALUE_VOID_ADDR]], i8 0, i64 16, i32 16, i1 false)
comment|// CHECK: store x86_fp80 [[OLD_VALUE]], x86_fp80* [[OLD_VALUE_ADDR]], align 16
comment|// CHECK: [[OLD_INT_ADDR:%.+]] = bitcast x86_fp80* [[OLD_VALUE_ADDR]] to i128*
comment|// CHECK: [[OLD_INT:%.+]] = load i128* [[OLD_INT_ADDR]], align 16
comment|// CHECK: [[NEW_VALUE_VOID_ADDR:%.+]] = bitcast x86_fp80* [[NEW_VALUE_ADDR:%.+]] to i8*
comment|// CHECK: call void @llvm.memset.p0i8.i64(i8* [[NEW_VALUE_VOID_ADDR]], i8 0, i64 16, i32 16, i1 false)
comment|// CHECK: store x86_fp80 [[SUB_VALUE]], x86_fp80* [[NEW_VALUE_ADDR]], align 16
comment|// CHECK: [[NEW_INT_ADDR:%.+]] = bitcast x86_fp80* [[NEW_VALUE_ADDR]] to i128*
comment|// CHECK: [[NEW_INT:%.+]] = load i128* [[NEW_INT_ADDR]], align 16
comment|// CHECK: [[OBJ_INT_ADDR:%.+]] = bitcast x86_fp80* [[ADDR]] to i128*
comment|// CHECK: [[RES:%.+]] = cmpxchg volatile i128* [[OBJ_INT_ADDR]], i128 [[OLD_INT]], i128 [[NEW_INT]] seq_cst seq_cst
comment|// CHECK: [[OLD_VALUE:%.+]] = extractvalue { i128, i1 } [[RES]], 0
comment|// CHECK: [[FAIL_SUCCESS:%.+]] = extractvalue { i128, i1 } [[RES]], 1
comment|// CHECK: [[OLD_VALUE_RES_INT_PTR:%.+]] = bitcast x86_fp80* [[OLD_VALUE_RES_PTR:%.+]] to i128*
comment|// CHECK: store i128 [[OLD_VALUE]], i128* [[OLD_VALUE_RES_INT_PTR]], align 16
comment|// CHECK: [[LD_VALUE]] = load x86_fp80* [[OLD_VALUE_RES_PTR]], align 16
comment|// CHECK: br i1 [[FAIL_SUCCESS]], label %[[ATOMIC_CONT:.+]], label %[[ATOMIC_OP]]
comment|// CHECK: [[ATOMIC_CONT]]
comment|// CHECK: [[ADDR:%.+]] = load x86_fp80** %{{.+}}, align 8
comment|// CHECK: [[ADDR_INT:%.+]] = bitcast x86_fp80* [[ADDR]] to i128*
comment|// CHECK: [[INT_VAL:%.+]] = load atomic volatile i128* [[ADDR_INT]] seq_cst, align 16
comment|// CHECK: [[INT_LD_TEMP:%.+]] = bitcast x86_fp80* [[LD_TEMP:%.+]] to i128*
comment|// CHECK: store i128 [[INT_VAL]], i128* [[INT_LD_TEMP:%.+]], align 16
comment|// CHECK: [[RET_VAL:%.+]] = load x86_fp80* [[LD_TEMP]], align 16
comment|// CHECK32-LABEL: @test_volatile_compassign
comment|// CHECK32: store x86_fp80* %{{.+}}, x86_fp80** [[ADDR_ADDR:%.+]], align 4
comment|// CHECK32: [[ADDR:%.+]] = load x86_fp80** [[ADDR_ADDR]], align 4
comment|// CHECK32: [[VOID_PTR:%.+]] = bitcast x86_fp80* [[ADDR]] to i8*
comment|// CHECK32: [[TEMP_LD_PTR:%.+]] = bitcast x86_fp80* [[TEMP_LD_ADDR:%.+]] to i8*
comment|// CHECK32: call void @__atomic_load(i32 12, i8* [[VOID_PTR]], i8* [[TEMP_LD_PTR]], i32 5)
comment|// CHECK32: [[LD_VALUE:%.+]] = load x86_fp80* [[TEMP_LD_ADDR]], align 4
comment|// CHECK32: br label %[[ATOMIC_OP:.+]]
comment|// CHECK32: [[ATOMIC_OP]]
comment|// CHECK32: [[OLD_VALUE:%.+]] = phi x86_fp80 [ [[LD_VALUE]], %{{.+}} ], [ [[LD_VALUE:%.+]], %[[ATOMIC_OP]] ]
comment|// CHECK32: [[INC_VALUE:%.+]] = fsub x86_fp80 [[OLD_VALUE]],
comment|// CHECK32: [[OLD_VALUE_VOID_ADDR:%.+]] = bitcast x86_fp80* [[OLD_VALUE_ADDR:%.+]] to i8*
comment|// CHECK32: call void @llvm.memset.p0i8.i64(i8* [[OLD_VALUE_VOID_ADDR]], i8 0, i64 12, i32 4, i1 false)
comment|// CHECK32: store x86_fp80 [[OLD_VALUE]], x86_fp80* [[OLD_VALUE_ADDR]], align 4
comment|// CHECK32: [[DESIRED_VALUE_VOID_ADDR:%.+]] = bitcast x86_fp80* [[DESIRED_VALUE_ADDR:%.+]] to i8*
comment|// CHECK32: call void @llvm.memset.p0i8.i64(i8* [[DESIRED_VALUE_VOID_ADDR]], i8 0, i64 12, i32 4, i1 false)
comment|// CHECK32: store x86_fp80 [[INC_VALUE]], x86_fp80* [[DESIRED_VALUE_ADDR]], align 4
comment|// CHECK32: [[OBJ:%.+]] = bitcast x86_fp80* [[ADDR]] to i8*
comment|// CHECK32: [[EXPECTED:%.+]] = bitcast x86_fp80* [[OLD_VALUE_ADDR]] to i8*
comment|// CHECK32: [[DESIRED:%.+]] = bitcast x86_fp80* [[DESIRED_VALUE_ADDR]] to i8*
comment|// CHECK32: [[FAIL_SUCCESS:%.+]] = call zeroext i1 @__atomic_compare_exchange(i32 12, i8* [[OBJ]], i8* [[EXPECTED]], i8* [[DESIRED]], i32 7, i32 7)
comment|// CHECK32: [[LD_VALUE]] = load x86_fp80* [[OLD_VALUE_ADDR]], align 4
comment|// CHECK32: br i1 [[FAIL_SUCCESS]], label %[[ATOMIC_CONT:.+]], label %[[ATOMIC_OP]]
comment|// CHECK32: [[ATOMIC_CONT]]
comment|// CHECK32: [[ADDR:%.+]] = load x86_fp80** %{{.+}}, align 4
comment|// CHECK32: [[VOID_ADDR:%.+]] = bitcast x86_fp80* [[ADDR]] to i8*
comment|// CHECK32: [[VOID_GET_ADDR:%.+]] = bitcast x86_fp80* [[GET_ADDR:%.+]] to i8*
comment|// CHECK32: call void @__atomic_load(i32 12, i8* [[VOID_ADDR]], i8* [[VOID_GET_ADDR]], i32 5)
comment|// CHECK32: [[RET_VAL:%.+]] = load x86_fp80* [[GET_ADDR]], align 4
comment|// CHECK32: ret x86_fp80 [[RET_VAL]]
return|return
operator|*
name|addr
return|;
block|}
end_function

begin_function
name|long
name|double
name|test_volatile_assign
parameter_list|(
specifier|volatile
specifier|_Atomic
name|long
name|double
modifier|*
name|addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_volatile_assign
comment|// CHECK: store x86_fp80* %{{.+}}, x86_fp80** [[ADDR_ADDR:%.+]], align 8
comment|// CHECK: [[ADDR:%.+]] = load x86_fp80** [[ADDR_ADDR]], align 8
comment|// CHECK: [[STORE_TEMP_VOID_PTR:%.+]] = bitcast x86_fp80* [[STORE_TEMP_PTR:%.+]] to i8*
comment|// CHECK: call void @llvm.memset.p0i8.i64(i8* [[STORE_TEMP_VOID_PTR]], i8 0, i64 16, i32 16, i1 false)
comment|// CHECK: store x86_fp80 {{.+}}, x86_fp80* [[STORE_TEMP_PTR]], align 16
comment|// CHECK: [[STORE_TEMP_INT_PTR:%.+]] = bitcast x86_fp80* [[STORE_TEMP_PTR]] to i128*
comment|// CHECK: [[STORE_TEMP_INT:%.+]] = load i128* [[STORE_TEMP_INT_PTR]], align 16
comment|// CHECK: [[ADDR_INT:%.+]] = bitcast x86_fp80* [[ADDR]] to i128*
comment|// CHECK: store atomic volatile i128 [[STORE_TEMP_INT]], i128* [[ADDR_INT]] seq_cst, align 16
comment|// CHECK32-LABEL: @test_volatile_assign
comment|// CHECK32: store x86_fp80* %{{.+}}, x86_fp80** [[ADDR_ADDR:%.+]], align 4
comment|// CHECK32: [[ADDR:%.+]] = load x86_fp80** [[ADDR_ADDR]], align 4
comment|// CHECK32: [[STORE_TEMP_VOID_PTR:%.+]] = bitcast x86_fp80* [[STORE_TEMP_PTR:%.+]] to i8*
comment|// CHECK32: call void @llvm.memset.p0i8.i64(i8* [[STORE_TEMP_VOID_PTR]], i8 0, i64 12, i32 4, i1 false)
comment|// CHECK32: store x86_fp80 {{.+}}, x86_fp80* [[STORE_TEMP_PTR]], align 4
comment|// CHECK32: [[ADDR_VOID:%.+]] = bitcast x86_fp80* [[ADDR]] to i8*
comment|// CHECK32: [[STORE_TEMP_VOID_PTR:%.+]] = bitcast x86_fp80* [[STORE_TEMP_PTR]] to i8*
comment|// CHECK32: call void @__atomic_store(i32 12, i8* [[ADDR_VOID]], i8* [[STORE_TEMP_VOID_PTR]], i32 5)
operator|*
name|addr
operator|=
literal|115
expr_stmt|;
comment|// CHECK: [[ADDR:%.+]] = load x86_fp80** %{{.+}}, align 8
comment|// CHECK: [[ADDR_INT:%.+]] = bitcast x86_fp80* [[ADDR]] to i128*
comment|// CHECK: [[INT_VAL:%.+]] = load atomic volatile i128* [[ADDR_INT]] seq_cst, align 16
comment|// CHECK: [[INT_LD_TEMP:%.+]] = bitcast x86_fp80* [[LD_TEMP:%.+]] to i128*
comment|// CHECK: store i128 [[INT_VAL]], i128* [[INT_LD_TEMP:%.+]], align 16
comment|// CHECK: [[RET_VAL:%.+]] = load x86_fp80* [[LD_TEMP]], align 16
comment|// CHECK: ret x86_fp80 [[RET_VAL]]
comment|// CHECK32: [[ADDR:%.+]] = load x86_fp80** %{{.+}}, align 4
comment|// CHECK32: [[VOID_ADDR:%.+]] = bitcast x86_fp80* [[ADDR]] to i8*
comment|// CHECK32: [[VOID_LD_TEMP:%.+]] = bitcast x86_fp80* [[LD_TEMP:%.+]] to i8*
comment|// CHECK32: call void @__atomic_load(i32 12, i8* [[VOID_ADDR]], i8* [[VOID_LD_TEMP]], i32 5)
comment|// CHECK32: [[RET_VAL:%.+]] = load x86_fp80* [[LD_TEMP]], align 4
comment|// CHECK32: ret x86_fp80 [[RET_VAL]]
return|return
operator|*
name|addr
return|;
block|}
end_function

end_unit

