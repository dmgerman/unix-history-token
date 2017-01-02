begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Make sure -finline-functions family flags are behaving correctly.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-pc-win32 -emit-llvm %s -o - | FileCheck -check-prefix=NOINLINE %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-pc-win32 -fexperimental-new-pass-manager -emit-llvm %s -o - | FileCheck -check-prefix=NOINLINE %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-pc-win32 -O3 -fno-inline-functions -emit-llvm %s -o - | FileCheck -check-prefix=NOINLINE %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-pc-win32 -fexperimental-new-pass-manager -O3 -fno-inline-functions -emit-llvm %s -o - | FileCheck -check-prefix=NOINLINE %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-pc-win32 -O3 -finline-hint-functions -emit-llvm %s -o - | FileCheck -check-prefix=HINT %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-pc-win32 -fexperimental-new-pass-manager -O3 -finline-hint-functions -emit-llvm %s -o - | FileCheck -check-prefix=HINT %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-pc-win32 -O3 -finline-functions -emit-llvm %s -o - | FileCheck -check-prefix=INLINE %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-pc-win32 -fexperimental-new-pass-manager -O3 -finline-functions -emit-llvm %s -o - | FileCheck -check-prefix=INLINE %s
end_comment

begin_function
specifier|inline
name|int
name|inline_hint
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
return|return
operator|(
name|a
operator|+
name|b
operator|)
return|;
block|}
end_function

begin_function
name|int
name|inline_no_hint
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
return|return
operator|(
name|a
operator|/
name|b
operator|)
return|;
block|}
end_function

begin_expr_stmt
specifier|inline
name|__attribute__
argument_list|(
argument|(__always_inline__)
argument_list|)
name|int
name|inline_always
argument_list|(
argument|int a
argument_list|,
argument|int b
argument_list|)
block|{
return|return
operator|(
name|a
operator|*
name|b
operator|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
specifier|volatile
name|int
modifier|*
name|pa
init|=
operator|(
name|int
operator|*
operator|)
literal|0x1000
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|foo
parameter_list|()
block|{
comment|// NOINLINE-LABEL: @foo
comment|// HINT-LABEL: @foo
comment|// INLINE-LABEL: @foo
comment|// NOINLINE: call i32 @inline_hint
comment|// HINT-NOT: call i32 @inline_hint
comment|// INLINE-NOT: call i32 @inline_hint
name|pa
index|[
literal|0
index|]
operator|=
name|inline_hint
argument_list|(
name|pa
index|[
literal|1
index|]
argument_list|,
name|pa
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
comment|// NOINLINE-NOT: call i32 @inline_always
comment|// HINT-NOT: call i32 @inline_always
comment|// INLINE-NOT: call i32 @inline_always
name|pa
index|[
literal|3
index|]
operator|=
name|inline_always
argument_list|(
name|pa
index|[
literal|4
index|]
argument_list|,
name|pa
index|[
literal|5
index|]
argument_list|)
expr_stmt|;
comment|// NOINLINE: call i32 @inline_no_hint
comment|// HINT: call i32 @inline_no_hint
comment|// INLINE-NOT: call i32 @inline_no_hint
name|pa
index|[
literal|6
index|]
operator|=
name|inline_no_hint
argument_list|(
name|pa
index|[
literal|7
index|]
argument_list|,
name|pa
index|[
literal|8
index|]
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

