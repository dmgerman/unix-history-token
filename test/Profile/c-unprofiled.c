begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that unprofiled files are recognized. Here, we have two functions in the
end_comment

begin_comment
comment|// profile, main() and function_in_header, but we use the profile on a file that
end_comment

begin_comment
comment|// has the profile-less some_unprofiled_function so that the only profiled code
end_comment

begin_comment
comment|// in #included in a header.
end_comment

begin_comment
comment|// FIXME: It would be nice to use -verify here instead of FileCheck, but -verify
end_comment

begin_comment
comment|// doesn't play well with warnings that have no line number.
end_comment

begin_comment
comment|// RUN: llvm-profdata merge %S/Inputs/c-unprofiled.proftext -o %t.profdata
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macosx10.9 -main-file-name c-unprofiled.c -I %S/Inputs/ %s -o /dev/null -emit-llvm -fprofile-instr-use=%t.profdata -Wprofile-instr-unprofiled 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: warning: no profile data available for file "c-unprofiled.c"
end_comment

begin_include
include|#
directive|include
file|"profiled_header.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|GENERATE_OUTDATED_DATA
end_ifdef

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|function_in_header
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function
name|void
name|some_unprofiled_function
parameter_list|(
name|int
name|i
parameter_list|)
block|{
if|if
condition|(
name|i
condition|)
name|function_in_header
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

