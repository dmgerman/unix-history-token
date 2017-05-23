begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)dirent.h	8.2 (Berkeley) 7/28/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DIRENT_H_
end_ifndef

begin_define
define|#
directive|define
name|_DIRENT_H_
end_define

begin_comment
comment|/*  * The kernel defines the format of directory entries returned by  * the getdirentries(2) system call.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_include
include|#
directive|include
file|<sys/dirent.h>
end_include

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

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

begin_ifndef
ifndef|#
directive|ifndef
name|_OFF_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__off_t
name|off_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_OFF_T_DECLARED
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
comment|/* __BSD_VISIBLE */
end_comment

begin_if
if|#
directive|if
name|__XSI_VISIBLE
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|_INO_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__ino_t
name|ino_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_INO_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * XXX this is probably illegal in the __XSI_VISIBLE case, but brings us closer  * to the specification.  */
end_comment

begin_define
define|#
directive|define
name|d_ino
value|d_fileno
end_define

begin_comment
comment|/* backward and XSI compatibility */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XSI_VISIBLE */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_include
include|#
directive|include
file|<sys/_null.h>
end_include

begin_comment
comment|/* definitions for library routines operating on directories. */
end_comment

begin_define
define|#
directive|define
name|DIRBLKSIZ
value|1024
end_define

begin_struct_decl
struct_decl|struct
name|_dirdesc
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|_dirdesc
name|DIR
typedef|;
end_typedef

begin_comment
comment|/* flags for opendir2 */
end_comment

begin_define
define|#
directive|define
name|DTF_HIDEW
value|0x0001
end_define

begin_comment
comment|/* hide whiteout entries */
end_comment

begin_define
define|#
directive|define
name|DTF_NODUP
value|0x0002
end_define

begin_comment
comment|/* don't return duplicate names */
end_comment

begin_define
define|#
directive|define
name|DTF_REWIND
value|0x0004
end_define

begin_comment
comment|/* rewind after reading union stack */
end_comment

begin_define
define|#
directive|define
name|__DTF_READALL
value|0x0008
end_define

begin_comment
comment|/* everything has been read */
end_comment

begin_define
define|#
directive|define
name|__DTF_SKIPREAD
value|0x0010
end_define

begin_comment
comment|/* assume internal buffer is populated */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__BSD_VISIBLE */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|DIR
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BSD_VISIBLE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_function_decl
name|__BEGIN_DECLS
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200809
operator|||
name|__XSI_VISIBLE
operator|>=
literal|700
name|int
name|alphasort
parameter_list|(
specifier|const
name|struct
name|dirent
modifier|*
modifier|*
parameter_list|,
specifier|const
name|struct
name|dirent
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dirfd
parameter_list|(
name|DIR
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
name|__BSD_VISIBLE
end_if

begin_function_decl
name|DIR
modifier|*
name|__opendir2
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdclosedir
parameter_list|(
name|DIR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|getdents
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

begin_function_decl
name|ssize_t
name|getdirentries
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|off_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|DIR
modifier|*
name|opendir
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DIR
modifier|*
name|fdopendir
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|dirent
modifier|*
name|readdir
parameter_list|(
name|DIR
modifier|*
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
name|int
name|readdir_r
parameter_list|(
name|DIR
modifier|*
parameter_list|,
name|struct
name|dirent
modifier|*
parameter_list|,
name|struct
name|dirent
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
name|void
name|rewinddir
parameter_list|(
name|DIR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200809
operator|||
name|__XSI_VISIBLE
operator|>=
literal|700
end_if

begin_function_decl
name|int
name|scandir
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|dirent
modifier|*
modifier|*
modifier|*
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
specifier|const
name|struct
name|dirent
modifier|*
parameter_list|)
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
specifier|const
name|struct
name|dirent
modifier|*
modifier|*
parameter_list|,
specifier|const
name|struct
name|dirent
modifier|*
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__BLOCKS__
end_ifdef

begin_function_decl
name|int
name|scandir_b
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|dirent
modifier|*
modifier|*
modifier|*
parameter_list|,
name|int
function_decl|(
modifier|^
function_decl|)
parameter_list|(
specifier|const
name|struct
name|dirent
modifier|*
parameter_list|)
parameter_list|,
name|int
function_decl|(
modifier|^
function_decl|)
parameter_list|(
specifier|const
name|struct
name|dirent
modifier|*
modifier|*
parameter_list|,
specifier|const
name|struct
name|dirent
modifier|*
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__XSI_VISIBLE
end_if

begin_function_decl
name|void
name|seekdir
parameter_list|(
name|DIR
modifier|*
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|telldir
parameter_list|(
name|DIR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|closedir
parameter_list|(
name|DIR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DIRENT_H_ */
end_comment

end_unit

