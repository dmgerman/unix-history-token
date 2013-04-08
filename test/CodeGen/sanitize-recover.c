begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -fsanitize=unsigned-integer-overflow %s -emit-llvm -o - | FileCheck %s --check-prefix=RECOVER
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -fsanitize=unsigned-integer-overflow -fno-sanitize-recover %s -emit-llvm -o - | FileCheck %s --check-prefix=ABORT
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

end_unit

