begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)string.h	8.1 (Berkeley) 6/2/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STRING_H_
end_ifndef

begin_define
define|#
directive|define
name|_STRING_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_null.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_comment
comment|/*  * Prototype functions which were historically defined in<string.h>, but  * are required by POSIX to be prototyped in<strings.h>.  */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_SIZE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__size_t
name|size_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_SIZE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|__BEGIN_DECLS
if|#
directive|if
name|__XSI_VISIBLE
operator|>=
literal|600
name|void
modifier|*
name|memccpy
parameter_list|(
name|void
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|void
modifier|*
name|__restrict
parameter_list|,
name|int
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
modifier|*
name|memchr
argument_list|(
specifier|const
name|void
operator|*
argument_list|,
name|int
argument_list|,
name|size_t
argument_list|)
name|__pure
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_decl_stmt
name|void
modifier|*
name|memrchr
argument_list|(
specifier|const
name|void
operator|*
argument_list|,
name|int
argument_list|,
name|size_t
argument_list|)
name|__pure
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|memcmp
argument_list|(
specifier|const
name|void
operator|*
argument_list|,
specifier|const
name|void
operator|*
argument_list|,
name|size_t
argument_list|)
name|__pure
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
modifier|*
name|memcpy
parameter_list|(
name|void
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|void
modifier|*
name|__restrict
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_decl_stmt
name|void
modifier|*
name|memmem
argument_list|(
specifier|const
name|void
operator|*
argument_list|,
name|size_t
argument_list|,
specifier|const
name|void
operator|*
argument_list|,
name|size_t
argument_list|)
name|__pure
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
modifier|*
name|memmove
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

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200809
end_if

begin_function_decl
name|char
modifier|*
name|stpcpy
parameter_list|(
name|char
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|stpncpy
parameter_list|(
name|char
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_decl_stmt
name|char
modifier|*
name|strcasestr
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
name|__pure
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|char
modifier|*
name|strcat
parameter_list|(
name|char
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|char
modifier|*
name|strchr
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|)
name|__pure
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_decl_stmt
name|char
modifier|*
name|strchrnul
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|)
name|__pure
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|strcmp
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
name|__pure
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|strcoll
parameter_list|(
specifier|const
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
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|size_t
name|strcspn
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
name|__pure
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200112
operator|||
name|__XSI_VISIBLE
end_if

begin_decl_stmt
name|char
modifier|*
name|strdup
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
name|__malloc_like
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|char
modifier|*
name|strerror
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200112
end_if

begin_function_decl
name|int
name|strerror_r
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_function_decl
name|size_t
name|strlcat
parameter_list|(
name|char
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|strlcpy
parameter_list|(
name|char
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|size_t
name|strlen
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
name|__pure
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_function_decl
name|void
name|strmode
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|char
modifier|*
name|strncat
parameter_list|(
name|char
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|strncmp
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|size_t
argument_list|)
name|__pure
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|strncpy
parameter_list|(
name|char
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200809
end_if

begin_decl_stmt
name|char
modifier|*
name|strndup
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|size_t
argument_list|)
name|__malloc_like
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|strnlen
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|size_t
argument_list|)
name|__pure
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_decl_stmt
name|char
modifier|*
name|strnstr
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|size_t
argument_list|)
name|__pure
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
modifier|*
name|strpbrk
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
name|__pure
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|strrchr
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|)
name|__pure
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_function_decl
name|char
modifier|*
name|strsep
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200809
end_if

begin_function_decl
name|char
modifier|*
name|strsignal
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|size_t
name|strspn
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
name|__pure
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|strstr
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
name|__pure
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|strtok
parameter_list|(
name|char
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|199506
operator|||
name|__XSI_VISIBLE
operator|>=
literal|500
end_if

begin_function_decl
name|char
modifier|*
name|strtok_r
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|size_t
name|strxfrm
parameter_list|(
name|char
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|_SWAB_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_SWAB_DECLARED
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_SSIZE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__ssize_t
name|ssize_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_SSIZE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SIZE_T_DECLARED */
end_comment

begin_function_decl
name|void
name|swab
parameter_list|(
specifier|const
name|void
modifier|*
name|__restrict
parameter_list|,
name|void
modifier|*
name|__restrict
parameter_list|,
name|ssize_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SWAB_DECLARED */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BSD_VISIBLE */
end_comment

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200809
operator|||
name|defined
argument_list|(
name|_XLOCALE_H_
argument_list|)
end_if

begin_include
include|#
directive|include
file|<xlocale/_string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__EXT1_VISIBLE
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|_RSIZE_T_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|_RSIZE_T_DEFINED
end_define

begin_typedef
typedef|typedef
name|size_t
name|rsize_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_ERRNO_T_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|_ERRNO_T_DEFINED
end_define

begin_typedef
typedef|typedef
name|int
name|errno_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISO/IEC 9899:2011 K.3.7.4.1.1 */
end_comment

begin_function_decl
name|errno_t
name|memset_s
parameter_list|(
name|void
modifier|*
parameter_list|,
name|rsize_t
parameter_list|,
name|int
parameter_list|,
name|rsize_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __EXT1_VISIBLE */
end_comment

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STRING_H_ */
end_comment

end_unit

