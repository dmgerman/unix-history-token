begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that on non-glibc platforms, a number of malloc-related functions are
end_comment

begin_comment
comment|// not intercepted.
end_comment

begin_comment
comment|// RUN: not %clang_asan -Dtestfunc=mallinfo %s -o %t
end_comment

begin_comment
comment|// RUN: not %clang_asan -Dtestfunc=mallopt  %s -o %t
end_comment

begin_comment
comment|// RUN: not %clang_asan -Dtestfunc=memalign %s -o %t
end_comment

begin_comment
comment|// RUN: not %clang_asan -Dtestfunc=pvalloc  %s -o %t
end_comment

begin_comment
comment|// RUN: not %clang_asan -Dtestfunc=cfree    %s -o %t
end_comment

begin_comment
comment|// Conflicts with BIONIC declarations.
end_comment

begin_comment
comment|// UNSUPPORTED: android
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|// For glibc, cause link failures by referencing a nonexistent function.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GLIBC__
end_ifdef

begin_undef
undef|#
directive|undef
name|testfunc
end_undef

begin_define
define|#
directive|define
name|testfunc
value|nonexistent_function
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|testfunc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|testfunc
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

