begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- int_endianness.h - configuration header for compiler-rt ------------===  *  *		       The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file is a configuration header for compiler-rt.  * This file is not part of the interface of this library.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INT_ENDIANNESS_H
end_ifndef

begin_define
define|#
directive|define
name|INT_ENDIANNESS_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SVR4
argument_list|)
operator|&&
name|defined
argument_list|(
name|__sun
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/byteorder.h>
end_include

begin_if
if|#
directive|if
name|_BYTE_ORDER
operator|==
name|_BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|_YUGA_LITTLE_ENDIAN
value|0
end_define

begin_define
define|#
directive|define
name|_YUGA_BIG_ENDIAN
value|1
end_define

begin_elif
elif|#
directive|elif
name|_BYTE_ORDER
operator|==
name|_LITTLE_ENDIAN
end_elif

begin_define
define|#
directive|define
name|_YUGA_LITTLE_ENDIAN
value|1
end_define

begin_define
define|#
directive|define
name|_YUGA_BIG_ENDIAN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BYTE_ORDER */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Solaris and AuroraUX. */
end_comment

begin_comment
comment|/* .. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__DragonFly__
argument_list|)
operator|||
name|defined
argument_list|(
name|__minix
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_if
if|#
directive|if
name|_BYTE_ORDER
operator|==
name|_BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|_YUGA_LITTLE_ENDIAN
value|0
end_define

begin_define
define|#
directive|define
name|_YUGA_BIG_ENDIAN
value|1
end_define

begin_elif
elif|#
directive|elif
name|_BYTE_ORDER
operator|==
name|_LITTLE_ENDIAN
end_elif

begin_define
define|#
directive|define
name|_YUGA_LITTLE_ENDIAN
value|1
end_define

begin_define
define|#
directive|define
name|_YUGA_BIG_ENDIAN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BYTE_ORDER */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* *BSD */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__Bitrig__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_if
if|#
directive|if
name|_BYTE_ORDER
operator|==
name|_BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|_YUGA_LITTLE_ENDIAN
value|0
end_define

begin_define
define|#
directive|define
name|_YUGA_BIG_ENDIAN
value|1
end_define

begin_elif
elif|#
directive|elif
name|_BYTE_ORDER
operator|==
name|_LITTLE_ENDIAN
end_elif

begin_define
define|#
directive|define
name|_YUGA_LITTLE_ENDIAN
value|1
end_define

begin_define
define|#
directive|define
name|_YUGA_BIG_ENDIAN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BYTE_ORDER */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OpenBSD and Bitrig. */
end_comment

begin_comment
comment|/* .. */
end_comment

begin_comment
comment|/* Mac OSX has __BIG_ENDIAN__ or __LITTLE_ENDIAN__ automatically set by the compiler (at least with GCC) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__MACH__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ellcc__
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__BIG_ENDIAN__
end_ifdef

begin_if
if|#
directive|if
name|__BIG_ENDIAN__
end_if

begin_define
define|#
directive|define
name|_YUGA_LITTLE_ENDIAN
value|0
end_define

begin_define
define|#
directive|define
name|_YUGA_BIG_ENDIAN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BIG_ENDIAN__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__LITTLE_ENDIAN__
end_ifdef

begin_if
if|#
directive|if
name|__LITTLE_ENDIAN__
end_if

begin_define
define|#
directive|define
name|_YUGA_LITTLE_ENDIAN
value|1
end_define

begin_define
define|#
directive|define
name|_YUGA_BIG_ENDIAN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __LITTLE_ENDIAN__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Mac OSX */
end_comment

begin_comment
comment|/* .. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<endian.h>
end_include

begin_if
if|#
directive|if
name|__BYTE_ORDER
operator|==
name|__BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|_YUGA_LITTLE_ENDIAN
value|0
end_define

begin_define
define|#
directive|define
name|_YUGA_BIG_ENDIAN
value|1
end_define

begin_elif
elif|#
directive|elif
name|__BYTE_ORDER
operator|==
name|__LITTLE_ENDIAN
end_elif

begin_define
define|#
directive|define
name|_YUGA_LITTLE_ENDIAN
value|1
end_define

begin_define
define|#
directive|define
name|_YUGA_BIG_ENDIAN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BYTE_ORDER */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GNU/Linux */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_define
define|#
directive|define
name|_YUGA_LITTLE_ENDIAN
value|1
end_define

begin_define
define|#
directive|define
name|_YUGA_BIG_ENDIAN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Windows */
end_comment

begin_comment
comment|/* . */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_YUGA_LITTLE_ENDIAN
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|_YUGA_BIG_ENDIAN
argument_list|)
end_if

begin_error
error|#
directive|error
error|Unable to determine endian
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Check we found an endianness correctly. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INT_ENDIANNESS_H */
end_comment

end_unit

