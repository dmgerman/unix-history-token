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
value|compilerrt_abort_impl(__FILE__, __LINE__, __func__)
end_define

begin_function_decl
name|NORETURN
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
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|COMPILE_TIME_ASSERT
parameter_list|(
name|expr
parameter_list|)
value|COMPILE_TIME_ASSERT1(expr, __COUNTER__)
end_define

begin_define
define|#
directive|define
name|COMPILE_TIME_ASSERT1
parameter_list|(
name|expr
parameter_list|,
name|cnt
parameter_list|)
value|COMPILE_TIME_ASSERT2(expr, cnt)
end_define

begin_define
define|#
directive|define
name|COMPILE_TIME_ASSERT2
parameter_list|(
name|expr
parameter_list|,
name|cnt
parameter_list|)
define|\
value|typedef char ct_assert_##cnt[(expr) ? 1 : -1] UNUSED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INT_UTIL_H */
end_comment

end_unit

