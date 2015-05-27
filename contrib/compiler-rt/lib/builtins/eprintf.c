begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===---------- eprintf.c - Implements __eprintf --------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/*  * __eprintf() was used in an old version of<assert.h>.  * It can eventually go away, but it is needed when linking  * .o files built with the old<assert.h>.  *  * It should never be exported from a dylib, so it is marked  * visibility hidden.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_WIN32
end_ifndef

begin_macro
name|__attribute__
argument_list|(
argument|(visibility(
literal|"hidden"
argument|))
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|COMPILER_RT_ABI
name|void
name|__eprintf
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
specifier|const
name|char
modifier|*
name|assertion_expression
parameter_list|,
specifier|const
name|char
modifier|*
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|format
argument_list|,
name|assertion_expression
argument_list|,
name|line
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
name|compilerrt_abort
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

