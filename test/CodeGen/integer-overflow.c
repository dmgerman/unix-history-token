begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - | FileCheck %s --check-prefix=DEFAULT
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -fwrapv | FileCheck %s --check-prefix=WRAPV
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -ftrapv | FileCheck %s --check-prefix=TRAPV
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
comment|// DEFAULT: define void @test1
comment|// WRAPV: define void @test1
comment|// TRAPV: define void @test1
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
name|f11G
operator|=
name|a
operator|+
name|b
expr_stmt|;
comment|// DEFAULT: sub nsw i32
comment|// WRAPV: sub i32
comment|// TRAPV: llvm.ssub.with.overflow.i32
name|f11G
operator|=
name|a
operator|-
name|b
expr_stmt|;
comment|// DEFAULT: mul nsw i32
comment|// WRAPV: mul i32
comment|// TRAPV: llvm.smul.with.overflow.i32
name|f11G
operator|=
name|a
operator|*
name|b
expr_stmt|;
comment|// DEFAULT: sub nsw i32 0,
comment|// WRAPV: sub i32 0,
comment|// TRAPV: llvm.ssub.with.overflow.i32(i32 0
name|f11G
operator|=
operator|-
name|a
expr_stmt|;
comment|// PR7426 - Overflow checking for increments.
comment|// DEFAULT: add nsw i32 {{.*}}, 1
comment|// WRAPV: add i32 {{.*}}, 1
comment|// TRAPV: llvm.sadd.with.overflow.i32({{.*}}, i32 1)
operator|++
name|a
expr_stmt|;
comment|// DEFAULT: add nsw i32 {{.*}}, -1
comment|// WRAPV: add i32 {{.*}}, -1
comment|// TRAPV: llvm.sadd.with.overflow.i32({{.*}}, i32 -1)
operator|--
name|a
expr_stmt|;
block|}
end_function

end_unit

