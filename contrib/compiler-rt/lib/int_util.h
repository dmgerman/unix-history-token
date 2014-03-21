begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- int_util.h - internal utility functions ----------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===-----------------------------------------------------------------------===  *  * This file is not part of the interface of this library.  *  * This file defines non-inline utilities which are available for use in the  * library. The function definitions themselves are all contained in int_util.c  * which will always be compiled into any compiler-rt library.  *  * ===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INT_UTIL_H
end_ifndef

begin_define
define|#
directive|define
name|INT_UTIL_H
end_define

begin_comment
comment|/** \brief Trigger a program abort (or panic for kernel code). */
end_comment

begin_define
define|#
directive|define
name|compilerrt_abort
parameter_list|()
value|compilerrt_abort_impl(__FILE__, __LINE__, \                                                  __FUNCTION__)
end_define

begin_function_decl
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
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INT_UTIL_H */
end_comment

end_unit

