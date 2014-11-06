begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- string.h - stub SDK header for compiler-rt -------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===-----------------------------------------------------------------------===  *  * This is a stub SDK header file. This file is not part of the interface of  * this library nor an official version of the appropriate SDK header. It is  * intended only to stub the features of this header required by compiler-rt.  *  * ===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STRING_H__
end_ifndef

begin_define
define|#
directive|define
name|__STRING_H__
end_define

begin_typedef
typedef|typedef
name|__SIZE_TYPE__
name|size_t
typedef|;
end_typedef

begin_function_decl
name|int
name|memcmp
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|memcpy
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|memset
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcat
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcpy
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strdup
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|strlen
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strncpy
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Determine the appropriate strerror() function. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386
argument_list|)
end_if

begin_define
define|#
directive|define
name|__STRERROR_NAME
value|"_strerror$UNIX2003"
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__arm
argument_list|)
end_elif

begin_define
define|#
directive|define
name|__STRERROR_NAME
value|"_strerror"
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"unrecognized architecture for targetting OS X"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__
argument_list|)
end_elif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64
argument_list|)
operator|||
name|defined
argument_list|(
name|__arm
argument_list|)
end_if

begin_define
define|#
directive|define
name|__STRERROR_NAME
value|"_strerror"
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"unrecognized architecture for targetting iOS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"unrecognized architecture for targetting Darwin"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
modifier|*
name|strerror
argument_list|(
name|int
argument_list|)
end_decl_stmt

begin_asm
asm|__asm(__STRERROR_NAME);
end_asm

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STRING_H__ */
end_comment

end_unit

