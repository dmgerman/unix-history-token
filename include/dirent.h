begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)dirent.h	8.2 (Berkeley) 7/28/94  * $FreeBSD$  */
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
file|<sys/dirent.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_SOURCE
end_ifdef

begin_typedef
typedef|typedef
name|void
modifier|*
name|DIR
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|d_ino
value|d_fileno
end_define

begin_comment
comment|/* backward compatibility */
end_comment

begin_comment
comment|/* definitions for library routines operating on directories. */
end_comment

begin_define
define|#
directive|define
name|DIRBLKSIZ
value|1024
end_define

begin_comment
comment|/* structure describing an open directory. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_dirdesc
block|{
name|int
name|dd_fd
decl_stmt|;
comment|/* file descriptor associated with directory */
name|long
name|dd_loc
decl_stmt|;
comment|/* offset in current buffer */
name|long
name|dd_size
decl_stmt|;
comment|/* amount of data returned by getdirentries */
name|char
modifier|*
name|dd_buf
decl_stmt|;
comment|/* data buffer */
name|int
name|dd_len
decl_stmt|;
comment|/* size of data buffer */
name|long
name|dd_seek
decl_stmt|;
comment|/* magic cookie returned by getdirentries */
name|long
name|dd_rewind
decl_stmt|;
comment|/* magic cookie for rewinding */
name|int
name|dd_flags
decl_stmt|;
comment|/* flags for readdir */
block|}
name|DIR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|dirfd
parameter_list|(
name|dirp
parameter_list|)
value|((dirp)->dd_fd)
end_define

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

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
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
comment|/* _POSIX_SOURCE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|DIR
modifier|*
name|opendir
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|dirent
modifier|*
name|readdir
name|__P
argument_list|(
operator|(
name|DIR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rewinddir
name|__P
argument_list|(
operator|(
name|DIR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|closedir
name|__P
argument_list|(
operator|(
name|DIR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_decl_stmt
name|DIR
modifier|*
name|__opendir2
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|telldir
name|__P
argument_list|(
operator|(
specifier|const
name|DIR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|seekdir
name|__P
argument_list|(
operator|(
name|DIR
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|scandir
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
expr|struct
name|dirent
operator|*
operator|*
operator|*
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
expr|struct
name|dirent
operator|*
argument_list|)
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
specifier|const
name|void
operator|*
argument_list|,
specifier|const
name|void
operator|*
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|alphasort
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
operator|,
specifier|const
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getdents
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getdirentries
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|readdir_r
name|__P
argument_list|(
operator|(
name|DIR
operator|*
operator|,
expr|struct
name|dirent
operator|*
operator|,
expr|struct
name|dirent
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not POSIX */
end_comment

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

