begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- stdio.h - stub SDK header for compiler-rt --------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===-----------------------------------------------------------------------===  *  * This is a stub SDK header file. This file is not part of the interface of  * this library nor an official version of the appropriate SDK header. It is  * intended only to stub the features of this header required by compiler-rt.  *  * ===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDIO_H__
end_ifndef

begin_define
define|#
directive|define
name|__STDIO_H__
end_define

begin_typedef
typedef|typedef
name|struct
name|__sFILE
name|FILE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__SIZE_TYPE__
name|size_t
typedef|;
end_typedef

begin_comment
comment|/* Determine the appropriate fopen() and fwrite() functions. */
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
name|__FOPEN_NAME
value|"_fopen$UNIX2003"
end_define

begin_define
define|#
directive|define
name|__FWRITE_NAME
value|"_fwrite$UNIX2003"
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|__FOPEN_NAME
value|"_fopen"
end_define

begin_define
define|#
directive|define
name|__FWRITE_NAME
value|"_fwrite"
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__arm
argument_list|)
end_elif

begin_define
define|#
directive|define
name|__FOPEN_NAME
value|"_fopen"
end_define

begin_define
define|#
directive|define
name|__FWRITE_NAME
value|"_fwrite"
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
end_if

begin_define
define|#
directive|define
name|__FOPEN_NAME
value|"_fopen"
end_define

begin_define
define|#
directive|define
name|__FWRITE_NAME
value|"_fwrite"
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__arm
argument_list|)
end_elif

begin_define
define|#
directive|define
name|__FOPEN_NAME
value|"_fopen"
end_define

begin_define
define|#
directive|define
name|__FWRITE_NAME
value|"_fwrite"
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

begin_define
define|#
directive|define
name|stderr
value|__stderrp
end_define

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|__stderrp
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|fclose
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fflush
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|FILE
modifier|*
name|fopen
argument_list|(
specifier|const
name|char
operator|*
specifier|restrict
argument_list|,
specifier|const
name|char
operator|*
specifier|restrict
argument_list|)
asm|__asm(__FOPEN_NAME);
name|int
name|fprintf
argument_list|(
name|FILE
operator|*
specifier|restrict
argument_list|,
specifier|const
name|char
operator|*
specifier|restrict
argument_list|,
operator|...
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|fwrite
argument_list|(
specifier|const
name|void
operator|*
specifier|restrict
argument_list|,
name|size_t
argument_list|,
name|size_t
argument_list|,
name|FILE
operator|*
specifier|restrict
argument_list|)
end_decl_stmt

begin_asm
asm|__asm(__FWRITE_NAME);
end_asm

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDIO_H__ */
end_comment

end_unit

