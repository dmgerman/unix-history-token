begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -fsanitize=unsigned-integer-overflow -fsanitize-recover=unsigned-integer-overflow %s -emit-llvm -o - | FileCheck %s --check-prefix=RECOVER
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -fsanitize=unsigned-integer-overflow %s -emit-llvm -o - | FileCheck %s --check-prefix=ABORT
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -fsanitize=null,object-size,alignment -fsanitize-recover=object-size %s -emit-llvm -o - | FileCheck %s --check-prefix=PARTIAL
end_comment

begin_comment
comment|// RECOVER: @test
end_comment

begin_comment
comment|// ABORT: @test
end_comment

begin_function
name|void
name|test
parameter_list|()
block|{
specifier|extern
specifier|volatile
name|unsigned
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|;
comment|// RECOVER: uadd.with.overflow.i32
comment|// RECOVER: ubsan_handle_add_overflow(
comment|// RECOVER-NOT: unreachable
comment|// ABORT: uadd.with.overflow.i32
comment|// ABORT: ubsan_handle_add_overflow_abort(
comment|// ABORT: unreachable
name|x
operator|=
name|y
operator|+
name|z
expr_stmt|;
block|}
end_function

begin_function
name|void
name|foo
parameter_list|()
block|{
union|union
block|{
name|int
name|i
decl_stmt|;
block|}
name|u
union|;
name|u
operator|.
name|i
operator|=
literal|1
expr_stmt|;
comment|// PARTIAL:      %[[CHECK0:.*]] = icmp ne {{.*}}* %[[PTR:.*]], null
comment|// PARTIAL:      %[[SIZE:.*]] = call i64 @llvm.objectsize.i64.p0i8(i8* {{.*}}, i1 false)
comment|// PARTIAL-NEXT: %[[CHECK1:.*]] = icmp uge i64 %[[SIZE]], 4
comment|// PARTIAL:      %[[MISALIGN:.*]] = and i64 {{.*}}, 3
comment|// PARTIAL-NEXT: %[[CHECK2:.*]] = icmp eq i64 %[[MISALIGN]], 0
comment|// PARTIAL:      %[[CHECK02:.*]] = and i1 %[[CHECK0]], %[[CHECK2]]
comment|// PARTIAL-NEXT: %[[CHECK012:.*]] = and i1 %[[CHECK02]], %[[CHECK1]]
comment|// PARTIAL:      br i1 %[[CHECK012]], {{.*}} !prof ![[WEIGHT_MD:.*]], !nosanitize
comment|// PARTIAL:      br i1 %[[CHECK02]], {{.*}}
comment|// PARTIAL:      call void @__ubsan_handle_type_mismatch_abort(
comment|// PARTIAL-NEXT: unreachable
comment|// PARTIAL:      call void @__ubsan_handle_type_mismatch(
block|}
end_function

end_unit

