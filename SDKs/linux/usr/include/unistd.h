begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- unistd.h - stub SDK header for compiler-rt -------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===-----------------------------------------------------------------------===  *  * This is a stub SDK header file. This file is not part of the interface of  * this library nor an official version of the appropriate SDK header. It is  * intended only to stub the features of this header required by compiler-rt.  *  * ===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__UNISTD_H__
end_ifndef

begin_define
define|#
directive|define
name|__UNISTD_H__
end_define

begin_enum
enum|enum
block|{
name|_SC_PAGESIZE
init|=
literal|30
block|}
enum|;
end_enum

begin_function_decl
specifier|extern
name|long
name|int
name|sysconf
parameter_list|(
name|int
name|__name
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__nothrow__
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
comment|/* __UNISTD_H__ */
end_comment

end_unit

