begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux -O0 -fsanitize-cfi-cross-dso \
end_comment

begin_comment
comment|// RUN:     -fsanitize=cfi-icall,cfi-nvcall,cfi-vcall,cfi-unrelated-cast,cfi-derived-cast \
end_comment

begin_comment
comment|// RUN:     -fsanitize-trap=cfi-icall,cfi-nvcall -fsanitize-recover=cfi-vcall,cfi-unrelated-cast \
end_comment

begin_comment
comment|// RUN:     -emit-llvm -o - %s | FileCheck %s
end_comment

begin_function
name|void
name|caller
parameter_list|(
name|void
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|()
parameter_list|)
block|{
name|f
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: define weak_odr hidden void @__cfi_check_fail(i8*, i8*)
end_comment

begin_comment
comment|// CHECK: store i8* %0, i8** %[[ALLOCA0:.*]], align 8
end_comment

begin_comment
comment|// CHECK: store i8* %1, i8** %[[ALLOCA1:.*]], align 8
end_comment

begin_comment
comment|// CHECK: %[[DATA:.*]] = load i8*, i8** %[[ALLOCA0]], align 8
end_comment

begin_comment
comment|// CHECK: %[[ADDR:.*]] = load i8*, i8** %[[ALLOCA1]], align 8
end_comment

begin_comment
comment|// CHECK: %[[ICMP_NOT_NULL:.*]] = icmp ne i8* %[[DATA]], null
end_comment

begin_comment
comment|// CHECK: br i1 %[[ICMP_NOT_NULL]], label %[[CONT0:.*]], label %[[TRAP:.*]],
end_comment

begin_comment
comment|// CHECK: [[TRAP]]:
end_comment

begin_comment
comment|// CHECK-NEXT:   call void @llvm.trap()
end_comment

begin_comment
comment|// CHECK-NEXT:   unreachable
end_comment

begin_comment
comment|// CHECK: [[CONT0]]:
end_comment

begin_comment
comment|// CHECK:   %[[A:.*]] = bitcast i8* %[[DATA]] to { i8, { i8*, i32, i32 }, i8* }*
end_comment

begin_comment
comment|// CHECK:   %[[KINDPTR:.*]] = getelementptr {{.*}} %[[A]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   %[[KIND:.*]] = load i8, i8* %[[KINDPTR]], align 4
end_comment

begin_comment
comment|// CHECK:   %[[VTVALID0:.*]] = call i1 @llvm.type.test(i8* %[[ADDR]], metadata !"all-vtables")
end_comment

begin_comment
comment|// CHECK:   %[[VTVALID:.*]] = zext i1 %[[VTVALID0]] to i64
end_comment

begin_comment
comment|// CHECK:   %[[NOT_0:.*]] = icmp ne i8 %[[KIND]], 0
end_comment

begin_comment
comment|// CHECK:   br i1 %[[NOT_0]], label %[[CONT1:.*]], label %[[HANDLE0:.*]], !prof
end_comment

begin_comment
comment|// CHECK: [[HANDLE0]]:
end_comment

begin_comment
comment|// CHECK:   %[[DATA0:.*]] = ptrtoint i8* %[[DATA]] to i64,
end_comment

begin_comment
comment|// CHECK:   %[[ADDR0:.*]] = ptrtoint i8* %[[ADDR]] to i64,
end_comment

begin_comment
comment|// CHECK:   call void @__ubsan_handle_cfi_check_fail(i64 %[[DATA0]], i64 %[[ADDR0]], i64 %[[VTVALID]])
end_comment

begin_comment
comment|// CHECK:   br label %[[CONT1]]
end_comment

begin_comment
comment|// CHECK: [[CONT1]]:
end_comment

begin_comment
comment|// CHECK:   %[[NOT_1:.*]] = icmp ne i8 %[[KIND]], 1
end_comment

begin_comment
comment|// CHECK:   br i1 %[[NOT_1]], label %[[CONT2:.*]], label %[[HANDLE1:.*]], !nosanitize
end_comment

begin_comment
comment|// CHECK: [[HANDLE1]]:
end_comment

begin_comment
comment|// CHECK-NEXT:   call void @llvm.trap()
end_comment

begin_comment
comment|// CHECK-NEXT:   unreachable
end_comment

begin_comment
comment|// CHECK: [[CONT2]]:
end_comment

begin_comment
comment|// CHECK:   %[[NOT_2:.*]] = icmp ne i8 %[[KIND]], 2
end_comment

begin_comment
comment|// CHECK:   br i1 %[[NOT_2]], label %[[CONT3:.*]], label %[[HANDLE2:.*]], !prof
end_comment

begin_comment
comment|// CHECK: [[HANDLE2]]:
end_comment

begin_comment
comment|// CHECK:   %[[DATA2:.*]] = ptrtoint i8* %[[DATA]] to i64,
end_comment

begin_comment
comment|// CHECK:   %[[ADDR2:.*]] = ptrtoint i8* %[[ADDR]] to i64,
end_comment

begin_comment
comment|// CHECK:   call void @__ubsan_handle_cfi_check_fail_abort(i64 %[[DATA2]], i64 %[[ADDR2]], i64 %[[VTVALID]])
end_comment

begin_comment
comment|// CHECK:   unreachable
end_comment

begin_comment
comment|// CHECK: [[CONT3]]:
end_comment

begin_comment
comment|// CHECK:   %[[NOT_3:.*]] = icmp ne i8 %[[KIND]], 3
end_comment

begin_comment
comment|// CHECK:   br i1 %[[NOT_3]], label %[[CONT4:.*]], label %[[HANDLE3:.*]], !prof
end_comment

begin_comment
comment|// CHECK: [[HANDLE3]]:
end_comment

begin_comment
comment|// CHECK:   %[[DATA3:.*]] = ptrtoint i8* %[[DATA]] to i64,
end_comment

begin_comment
comment|// CHECK:   %[[ADDR3:.*]] = ptrtoint i8* %[[ADDR]] to i64,
end_comment

begin_comment
comment|// CHECK:   call void @__ubsan_handle_cfi_check_fail(i64 %[[DATA3]], i64 %[[ADDR3]], i64 %[[VTVALID]])
end_comment

begin_comment
comment|// CHECK:   br label %[[CONT4]]
end_comment

begin_comment
comment|// CHECK: [[CONT4]]:
end_comment

begin_comment
comment|// CHECK:   %[[NOT_4:.*]] = icmp ne i8 %[[KIND]], 4
end_comment

begin_comment
comment|// CHECK:   br i1 %[[NOT_4]], label %[[CONT5:.*]], label %[[HANDLE4:.*]], !nosanitize
end_comment

begin_comment
comment|// CHECK: [[HANDLE4]]:
end_comment

begin_comment
comment|// CHECK-NEXT:   call void @llvm.trap()
end_comment

begin_comment
comment|// CHECK-NEXT:   unreachable
end_comment

begin_comment
comment|// CHECK: [[CONT5]]:
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_comment
comment|// CHECK: define weak void @__cfi_check(i64, i8*, i8*)
end_comment

begin_comment
comment|// CHECK-NOT: }
end_comment

begin_comment
comment|// CHECK: call void @llvm.trap()
end_comment

begin_comment
comment|// CHECK-NEXT: ret void
end_comment

end_unit

