begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_asan -O0 %s -o %t
end_comment

begin_comment
comment|// RUN: %run %t 0x00 2>&1 | FileCheck %s -check-prefix=X00
end_comment

begin_comment
comment|// RUN: not %run %t 0xf1 2>&1 | FileCheck %s -check-prefix=XF1
end_comment

begin_comment
comment|// RUN: not %run %t 0xf2 2>&1 | FileCheck %s -check-prefix=XF2
end_comment

begin_comment
comment|// RUN: not %run %t 0xf3 2>&1 | FileCheck %s -check-prefix=XF3
end_comment

begin_comment
comment|// RUN: not %run %t 0xf5 2>&1 | FileCheck %s -check-prefix=XF5
end_comment

begin_comment
comment|// RUN: not %run %t 0xf8 2>&1 | FileCheck %s -check-prefix=XF8
end_comment

begin_comment
comment|// XFAIL: win32
end_comment

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<sanitizer/asan_interface.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_function_decl
name|void
name|__asan_set_shadow_00
parameter_list|(
name|size_t
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__asan_set_shadow_f1
parameter_list|(
name|size_t
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__asan_set_shadow_f2
parameter_list|(
name|size_t
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__asan_set_shadow_f3
parameter_list|(
name|size_t
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__asan_set_shadow_f5
parameter_list|(
name|size_t
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__asan_set_shadow_f8
parameter_list|(
name|size_t
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|char
name|a
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|8
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f
parameter_list|(
name|long
name|arg
parameter_list|)
block|{
name|size_t
name|shadow_offset
decl_stmt|;
name|size_t
name|shadow_scale
decl_stmt|;
name|__asan_get_shadow_mapping
argument_list|(
operator|&
name|shadow_scale
argument_list|,
operator|&
name|shadow_offset
argument_list|)
expr_stmt|;
name|size_t
name|addr
init|=
operator|(
operator|(
operator|(
name|size_t
operator|)
operator|&
name|a
operator|)
operator|>>
name|shadow_scale
operator|)
operator|+
name|shadow_offset
decl_stmt|;
switch|switch
condition|(
name|arg
condition|)
block|{
comment|// X00-NOT: AddressSanitizer
comment|// X00: PASS
case|case
literal|0x00
case|:
return|return
name|__asan_set_shadow_00
argument_list|(
name|addr
argument_list|,
literal|1
argument_list|)
return|;
comment|// XF1: AddressSanitizer: stack-buffer-underflow
comment|// XF1: [f1]
case|case
literal|0xf1
case|:
return|return
name|__asan_set_shadow_f1
argument_list|(
name|addr
argument_list|,
literal|1
argument_list|)
return|;
comment|// XF2: AddressSanitizer: stack-buffer-overflow
comment|// XF2: [f2]
case|case
literal|0xf2
case|:
return|return
name|__asan_set_shadow_f2
argument_list|(
name|addr
argument_list|,
literal|1
argument_list|)
return|;
comment|// XF3: AddressSanitizer: stack-buffer-overflow
comment|// XF3: [f3]
case|case
literal|0xf3
case|:
return|return
name|__asan_set_shadow_f3
argument_list|(
name|addr
argument_list|,
literal|1
argument_list|)
return|;
comment|// XF5: AddressSanitizer: stack-use-after-return
comment|// XF5: [f5]
case|case
literal|0xf5
case|:
return|return
name|__asan_set_shadow_f5
argument_list|(
name|addr
argument_list|,
literal|1
argument_list|)
return|;
comment|// XF8: AddressSanitizer: stack-use-after-scope
comment|// XF8: [f8]
case|case
literal|0xf8
case|:
return|return
name|__asan_set_shadow_f8
argument_list|(
name|addr
argument_list|,
literal|1
argument_list|)
return|;
block|}
name|assert
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|assert
argument_list|(
name|argc
operator|>
literal|1
argument_list|)
expr_stmt|;
name|long
name|arg
init|=
name|strtol
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
literal|0
argument_list|,
literal|16
argument_list|)
decl_stmt|;
name|f
argument_list|(
name|arg
argument_list|)
expr_stmt|;
name|a
operator|=
literal|1
expr_stmt|;
name|printf
argument_list|(
literal|"PASS\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

