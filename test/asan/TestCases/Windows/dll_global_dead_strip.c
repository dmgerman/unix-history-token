begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cl_asan -O0 %p/dll_host.cc -Fe%t
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cl_asan /Gw -LD -O0 %s -Fe%t.dll
end_comment

begin_comment
comment|// RUN: %env_asan_opts=report_globals=2 %run %t %t.dll 2>&1 | FileCheck %s --check-prefix=NOSTRIP
end_comment

begin_comment
comment|// RUN: %clang_cl_asan /Gw -LD -O2 %s -Fe%t.dll -link -opt:ref
end_comment

begin_comment
comment|// RUN: %env_asan_opts=report_globals=2 %run %t %t.dll 2>&1 | FileCheck %s --check-prefix=STRIP
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
name|int
name|dead_global
init|=
literal|42
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|live_global
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_function
name|int
name|test_function
parameter_list|()
block|{
name|puts
argument_list|(
literal|"main"
argument_list|)
expr_stmt|;
return|return
name|live_global
return|;
block|}
end_function

begin_comment
comment|// Check that our global registration scheme works with MSVC's linker dead
end_comment

begin_comment
comment|// stripping (/OPT:REF).
end_comment

begin_comment
comment|// NOSTRIP: Added Global{{.*}}name=dead_global
end_comment

begin_comment
comment|// NOSTRIP: Added Global{{.*}}name=live_global
end_comment

begin_comment
comment|// NOSTRIP: main
end_comment

begin_comment
comment|// STRIP-NOT: Added Global{{.*}}name=dead_global
end_comment

begin_comment
comment|// STRIP: Added Global{{.*}}name=live_global
end_comment

begin_comment
comment|// STRIP: main
end_comment

end_unit

