begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin %s -emit-llvm -o - -fsanitize=unsigned-integer-overflow | FileCheck %s --check-prefix=UNSIGNED
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin %s -emit-llvm -o - -ftrapv | FileCheck %s --check-prefix=TRAPV
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin %s -emit-llvm -o - -fsanitize=unsigned-integer-overflow -ftrapv | FileCheck %s --check-prefix=BOTH
end_comment

begin_comment
comment|// Verify that -ftrapv and -fsanitize=unsigned-integer-overflow
end_comment

begin_comment
comment|// work together as expected
end_comment

begin_comment
comment|// UNSIGNED: @test_signed
end_comment

begin_comment
comment|// TRAPV: @test_signed
end_comment

begin_comment
comment|// BOTH: @test_signed
end_comment

begin_function
name|void
name|test_signed
parameter_list|()
block|{
specifier|extern
specifier|volatile
name|int
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|;
comment|// UNSIGNED: add nsw i32
comment|// UNSIGNED-NOT: overflow
comment|// TRAPV: sadd.with.overflow.i32
comment|// TRAPV-NOT: ubsan
comment|// TRAPV: llvm.trap
comment|// BOTH: sadd.with.overflow.i32
comment|// BOTH-NOT: ubsan
comment|// BOTH: llvm.trap
name|a
operator|=
name|b
operator|+
name|c
expr_stmt|;
block|}
end_function

begin_comment
comment|// UNSIGNED: @test_unsigned
end_comment

begin_comment
comment|// TRAPV: @test_unsigned
end_comment

begin_comment
comment|// BOTH: @test_unsigned
end_comment

begin_function
name|void
name|test_unsigned
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
comment|// UNSIGNED: uadd.with.overflow.i32
comment|// UNSIGNED-NOT: llvm.trap
comment|// UNSIGNED: ubsan
comment|// TRAPV-NOT: overflow
comment|// TRAPV-NOT: llvm.trap
comment|// BOTH: uadd.with.overflow.i32
comment|// BOTH: ubsan
comment|// BOTH-NOT: llvm.trap
name|x
operator|=
name|y
operator|+
name|z
expr_stmt|;
block|}
end_function

end_unit

