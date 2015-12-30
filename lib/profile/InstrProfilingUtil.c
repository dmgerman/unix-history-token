begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===- InstrProfilingUtil.c - Support library for PGO instrumentation -----===*\ |* |*                     The LLVM Compiler Infrastructure |* |* This file is distributed under the University of Illinois Open Source |* License. See LICENSE.TXT for details. |* \*===----------------------------------------------------------------------===*/
end_comment

begin_include
include|#
directive|include
file|"InstrProfilingUtil.h"
end_include

begin_include
include|#
directive|include
file|"InstrProfiling.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_include
include|#
directive|include
file|<direct.h>
end_include

begin_elif
elif|#
directive|elif
name|I386_FREEBSD
end_elif

begin_function_decl
name|int
name|mkdir
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|COMPILER_RT_VISIBILITY
name|void
name|__llvm_profile_recursive_mkdir
parameter_list|(
name|char
modifier|*
name|path
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|1
init|;
name|path
index|[
name|i
index|]
operator|!=
literal|'\0'
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|path
index|[
name|i
index|]
operator|!=
literal|'/'
condition|)
continue|continue;
name|path
index|[
name|i
index|]
operator|=
literal|'\0'
expr_stmt|;
ifdef|#
directive|ifdef
name|_WIN32
name|_mkdir
argument_list|(
name|path
argument_list|)
expr_stmt|;
else|#
directive|else
name|mkdir
argument_list|(
name|path
argument_list|,
literal|0755
argument_list|)
expr_stmt|;
comment|/* Some of these will fail, ignore it. */
endif|#
directive|endif
name|path
index|[
name|i
index|]
operator|=
literal|'/'
expr_stmt|;
block|}
block|}
end_function

end_unit

