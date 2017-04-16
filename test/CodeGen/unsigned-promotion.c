begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check -fsanitize=signed-integer-overflow and
end_comment

begin_comment
comment|// -fsanitize=unsigned-integer-overflow with promoted unsigned types
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -emit-llvm -o - %s \
end_comment

begin_comment
comment|// RUN:   -fsanitize=signed-integer-overflow | FileCheck %s --check-prefix=CHECKS
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -emit-llvm -o - %s \
end_comment

begin_comment
comment|// RUN:   -fsanitize=unsigned-integer-overflow | FileCheck %s --check-prefix=CHECKU
end_comment

begin_decl_stmt
name|unsigned
name|short
name|si
decl_stmt|,
name|sj
decl_stmt|,
name|sk
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECKS-LABEL:   define void @testshortmul()
end_comment

begin_comment
comment|// CHECKU-LABEL: define void @testshortmul()
end_comment

begin_function
name|void
name|testshortmul
parameter_list|()
block|{
comment|// CHECKS:        load i16, i16* @sj
comment|// CHECKS:        load i16, i16* @sk
comment|// CHECKS:        [[T1:%.*]] = call { i32, i1 } @llvm.smul.with.overflow.i32(i32 [[T2:%.*]], i32 [[T3:%.*]])
comment|// CHECKS-NEXT:   [[T4:%.*]] = extractvalue { i32, i1 } [[T1]], 0
comment|// CHECKS-NEXT:   [[T5:%.*]] = extractvalue { i32, i1 } [[T1]], 1
comment|// CHECKS:        call void @__ubsan_handle_mul_overflow
comment|//
comment|// CHECKU:      [[T1:%.*]] = load i16, i16* @sj
comment|// CHECKU:      [[T2:%.*]] = zext i16 [[T1]]
comment|// CHECKU:      [[T3:%.*]] = load i16, i16* @sk
comment|// CHECKU:      [[T4:%.*]] = zext i16 [[T3]]
comment|// CHECKU-NOT:  llvm.smul
comment|// CHECKU-NOT:  llvm.umul
comment|// CHECKU:      [[T5:%.*]] = mul nsw i32 [[T2]], [[T4]]
name|si
operator|=
name|sj
operator|*
name|sk
expr_stmt|;
block|}
end_function

end_unit

