begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- fcntl.h - stub SDK header for compiler-rt --------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===-----------------------------------------------------------------------===  *  * This is a stub SDK header file. This file is not part of the interface of  * this library nor an official version of the appropriate SDK header. It is  * intended only to stub the features of this header required by compiler-rt.  *  * ===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_FCNTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_FCNTL_H_
end_define

begin_comment
comment|/* Determine the appropriate open function. */
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
name|__OPEN_NAME
value|"_open$UNIX2003"
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
name|__OPEN_NAME
value|"_open"
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
name|__OPEN_NAME
value|"_open"
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
name|__OPEN_NAME
value|"_open"
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
name|__OPEN_NAME
value|"_open"
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
name|O_RDONLY
value|0x0000
end_define

begin_comment
comment|/* open for reading only */
end_comment

begin_define
define|#
directive|define
name|O_WRONLY
value|0x0001
end_define

begin_comment
comment|/* open for writing only */
end_comment

begin_define
define|#
directive|define
name|O_RDWR
value|0x0002
end_define

begin_comment
comment|/* open for reading and writing */
end_comment

begin_define
define|#
directive|define
name|O_ACCMODE
value|0x0003
end_define

begin_comment
comment|/* mask for above modes */
end_comment

begin_define
define|#
directive|define
name|O_CREAT
value|0x0200
end_define

begin_comment
comment|/* create if nonexistant */
end_comment

begin_decl_stmt
name|int
name|open
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|,
operator|...
argument_list|)
end_decl_stmt

begin_asm
asm|__asm(__OPEN_NAME);
end_asm

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_FCNTL_H_ */
end_comment

end_unit

