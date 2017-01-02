begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cl_asan /O0 %s /Fe%t.exe
end_comment

begin_comment
comment|// RUN: %env_asan_opts=report_globals=2 %t.exe 2>&1 | FileCheck %s --check-prefix=NOSTRIP
end_comment

begin_comment
comment|// RUN: %clang_cl_asan /O2 %s /Fe%t.exe -link -opt:ref
end_comment

begin_comment
comment|// RUN: %env_asan_opts=report_globals=2 %t.exe 2>&1 | FileCheck %s --check-prefix=STRIP
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

begin_function
name|int
name|main
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

