begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin %s -emit-llvm -o - | FileCheck %s --check-prefix=DEFAULT
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin %s -emit-llvm -o - -fwrapv | FileCheck %s --check-prefix=WRAPV
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin %s -emit-llvm -o - -ftrapv | FileCheck %s --check-prefix=TRAPV
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin %s -emit-llvm -o - -fsanitize=signed-integer-overflow | FileCheck %s --check-prefix=CATCH_UB
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin %s -emit-llvm -o - -ftrapv -ftrapv-handler foo | FileCheck %s --check-prefix=TRAPV_HANDLER
end_comment

begin_comment
comment|// Tests for signed integer overflow stuff.
end_comment

begin_comment
comment|// rdar://7432000 rdar://7221421
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
comment|// DEFAULT-LABEL: define void @test1
comment|// WRAPV-LABEL: define void @test1
comment|// TRAPV-LABEL: define void @test1
specifier|extern
specifier|volatile
name|int
name|f11G
decl_stmt|,
name|a
decl_stmt|,
name|b
decl_stmt|;
comment|// DEFAULT: add nsw i32
comment|// WRAPV: add i32
comment|// TRAPV: llvm.sadd.with.overflow.i32
comment|// CATCH_UB: llvm.sadd.with.overflow.i32
comment|// TRAPV_HANDLER: foo(
name|f11G
operator|=
name|a
operator|+
name|b
expr_stmt|;
comment|// DEFAULT: sub nsw i32
comment|// WRAPV: sub i32
comment|// TRAPV: llvm.ssub.with.overflow.i32
comment|// CATCH_UB: llvm.ssub.with.overflow.i32
comment|// TRAPV_HANDLER: foo(
name|f11G
operator|=
name|a
operator|-
name|b
expr_stmt|;
comment|// DEFAULT: mul nsw i32
comment|// WRAPV: mul i32
comment|// TRAPV: llvm.smul.with.overflow.i32
comment|// CATCH_UB: llvm.smul.with.overflow.i32
comment|// TRAPV_HANDLER: foo(
name|f11G
operator|=
name|a
operator|*
name|b
expr_stmt|;
comment|// DEFAULT: sub nsw i32 0,
comment|// WRAPV: sub i32 0,
comment|// TRAPV: llvm.ssub.with.overflow.i32(i32 0
comment|// CATCH_UB: llvm.ssub.with.overflow.i32(i32 0
comment|// TRAPV_HANDLER: foo(
name|f11G
operator|=
operator|-
name|a
expr_stmt|;
comment|// PR7426 - Overflow checking for increments.
comment|// DEFAULT: add nsw i32 {{.*}}, 1
comment|// WRAPV: add i32 {{.*}}, 1
comment|// TRAPV: llvm.sadd.with.overflow.i32({{.*}}, i32 1)
comment|// CATCH_UB: llvm.sadd.with.overflow.i32({{.*}}, i32 1)
comment|// TRAPV_HANDLER: foo(
operator|++
name|a
expr_stmt|;
comment|// DEFAULT: add nsw i32 {{.*}}, -1
comment|// WRAPV: add i32 {{.*}}, -1
comment|// TRAPV: llvm.sadd.with.overflow.i32({{.*}}, i32 -1)
comment|// CATCH_UB: llvm.sadd.with.overflow.i32({{.*}}, i32 -1)
comment|// TRAPV_HANDLER: foo(
operator|--
name|a
expr_stmt|;
comment|// -fwrapv should turn off inbounds for GEP's, PR9256
specifier|extern
name|int
modifier|*
name|P
decl_stmt|;
operator|++
name|P
expr_stmt|;
comment|// DEFAULT: getelementptr inbounds i32*
comment|// WRAPV: getelementptr i32*
comment|// TRAPV: getelementptr inbounds i32*
comment|// CATCH_UB: getelementptr inbounds i32*
comment|// PR9350: char increment never overflows.
specifier|extern
specifier|volatile
name|signed
name|char
name|PR9350
decl_stmt|;
comment|// DEFAULT: add i8 {{.*}}, 1
comment|// WRAPV: add i8 {{.*}}, 1
comment|// TRAPV: add i8 {{.*}}, 1
comment|// CATCH_UB: add i8 {{.*}}, 1
operator|++
name|PR9350
expr_stmt|;
block|}
end_function

end_unit

