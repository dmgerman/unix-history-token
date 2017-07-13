begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- int_util.c - Implement internal utilities --------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_include
include|#
directive|include
file|"int_util.h"
end_include

begin_comment
comment|/* NOTE: The definitions in this file are declared weak because we clients to be  * able to arbitrarily package individual functions into separate .a files. If  * we did not declare these weak, some link situations might end up seeing  * duplicate strong definitions of the same symbol.  *  * We can't use this solution for kernel use (which may not support weak), but  * currently expect that when built for kernel use all the functionality is  * packaged into a single library.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL_USE
end_ifdef

begin_function_decl
name|NORETURN
specifier|extern
name|void
name|panic
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

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
name|void
name|compilerrt_abort_impl
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|function
parameter_list|)
block|{
name|panic
argument_list|(
literal|"%s:%d: abort in %s"
argument_list|,
name|file
argument_list|,
name|line
argument_list|,
name|function
argument_list|)
expr_stmt|;
block|}
end_function

begin_elif
elif|#
directive|elif
name|__APPLE__
end_elif

begin_comment
comment|/* from libSystem.dylib */
end_comment

begin_function_decl
name|NORETURN
specifier|extern
name|void
name|__assert_rtn
parameter_list|(
specifier|const
name|char
modifier|*
name|func
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|message
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_WIN32
end_ifndef

begin_macro
name|__attribute__
argument_list|(
argument|(weak)
argument_list|)
end_macro

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
name|void
name|compilerrt_abort_impl
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|function
parameter_list|)
block|{
name|__assert_rtn
argument_list|(
name|function
argument_list|,
name|file
argument_list|,
name|line
argument_list|,
literal|"libcompiler_rt abort"
argument_list|)
expr_stmt|;
block|}
end_function

begin_elif
elif|#
directive|elif
name|__Fuchsia__
end_elif

begin_ifndef
ifndef|#
directive|ifndef
name|_WIN32
end_ifndef

begin_macro
name|__attribute__
argument_list|(
argument|(weak)
argument_list|)
end_macro

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
name|void
name|compilerrt_abort_impl
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|function
parameter_list|)
block|{
name|__builtin_trap
argument_list|()
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Get the system definition of abort() */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_WIN32
end_ifndef

begin_macro
name|__attribute__
argument_list|(
argument|(weak)
argument_list|)
end_macro

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
name|void
name|compilerrt_abort_impl
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|function
parameter_list|)
block|{
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

