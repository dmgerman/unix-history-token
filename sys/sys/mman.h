begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)mman.h	8.2 (Berkeley) 1/9/95  * $Id: mman.h,v 1.21 1998/03/04 10:26:35 dufault Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_MMAN_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_MMAN_H_
end_define

begin_include
include|#
directive|include
file|<sys/_posix.h>
end_include

begin_comment
comment|/*  * Protections are chosen from these bits, or-ed together  */
end_comment

begin_define
define|#
directive|define
name|PROT_NONE
value|0x00
end_define

begin_comment
comment|/* no permissions */
end_comment

begin_define
define|#
directive|define
name|PROT_READ
value|0x01
end_define

begin_comment
comment|/* pages can be read */
end_comment

begin_define
define|#
directive|define
name|PROT_WRITE
value|0x02
end_define

begin_comment
comment|/* pages can be written */
end_comment

begin_define
define|#
directive|define
name|PROT_EXEC
value|0x04
end_define

begin_comment
comment|/* pages can be executed */
end_comment

begin_comment
comment|/*  * Flags contain sharing type and options.  * Sharing types; choose one.  */
end_comment

begin_define
define|#
directive|define
name|MAP_SHARED
value|0x0001
end_define

begin_comment
comment|/* share changes */
end_comment

begin_define
define|#
directive|define
name|MAP_PRIVATE
value|0x0002
end_define

begin_comment
comment|/* changes are private */
end_comment

begin_define
define|#
directive|define
name|MAP_COPY
value|MAP_PRIVATE
end_define

begin_comment
comment|/* Obsolete */
end_comment

begin_comment
comment|/*  * Other flags  */
end_comment

begin_define
define|#
directive|define
name|MAP_FIXED
value|0x0010
end_define

begin_comment
comment|/* map addr must be exactly as requested */
end_comment

begin_define
define|#
directive|define
name|MAP_RENAME
value|0x0020
end_define

begin_comment
comment|/* Sun: rename private pages to file */
end_comment

begin_define
define|#
directive|define
name|MAP_NORESERVE
value|0x0040
end_define

begin_comment
comment|/* Sun: don't reserve needed swap area */
end_comment

begin_define
define|#
directive|define
name|MAP_INHERIT
value|0x0080
end_define

begin_comment
comment|/* region is retained after exec */
end_comment

begin_define
define|#
directive|define
name|MAP_NOEXTEND
value|0x0100
end_define

begin_comment
comment|/* for MAP_FILE, don't change file size */
end_comment

begin_define
define|#
directive|define
name|MAP_HASSEMAPHORE
value|0x0200
end_define

begin_comment
comment|/* region may contain semaphores */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX4_VISIBLE
end_ifdef

begin_comment
comment|/*  * Process memory locking  */
end_comment

begin_define
define|#
directive|define
name|MCL_CURRENT
value|0x0001
end_define

begin_comment
comment|/* Lock only current memory */
end_comment

begin_define
define|#
directive|define
name|MCL_FUTURE
value|0x0002
end_define

begin_comment
comment|/* Lock all future memory as well */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX4_VISIBLE */
end_comment

begin_comment
comment|/*  * Error return from mmap()  */
end_comment

begin_define
define|#
directive|define
name|MAP_FAILED
value|((void *)-1)
end_define

begin_comment
comment|/*  * msync() flags  */
end_comment

begin_define
define|#
directive|define
name|MS_SYNC
value|0x0000
end_define

begin_comment
comment|/* msync synchronously */
end_comment

begin_define
define|#
directive|define
name|MS_ASYNC
value|0x0001
end_define

begin_comment
comment|/* return immediately */
end_comment

begin_define
define|#
directive|define
name|MS_INVALIDATE
value|0x0002
end_define

begin_comment
comment|/* invalidate all cached data */
end_comment

begin_comment
comment|/*  * Mapping type  */
end_comment

begin_define
define|#
directive|define
name|MAP_FILE
value|0x0000
end_define

begin_comment
comment|/* map from file (default) */
end_comment

begin_define
define|#
directive|define
name|MAP_ANON
value|0x1000
end_define

begin_comment
comment|/* allocated from memory, swap space */
end_comment

begin_comment
comment|/*  * Advice to madvise  */
end_comment

begin_define
define|#
directive|define
name|MADV_NORMAL
value|0
end_define

begin_comment
comment|/* no further special treatment */
end_comment

begin_define
define|#
directive|define
name|MADV_RANDOM
value|1
end_define

begin_comment
comment|/* expect random page references */
end_comment

begin_define
define|#
directive|define
name|MADV_SEQUENTIAL
value|2
end_define

begin_comment
comment|/* expect sequential page references */
end_comment

begin_define
define|#
directive|define
name|MADV_WILLNEED
value|3
end_define

begin_comment
comment|/* will need these pages */
end_comment

begin_define
define|#
directive|define
name|MADV_DONTNEED
value|4
end_define

begin_comment
comment|/* dont need these pages */
end_comment

begin_define
define|#
directive|define
name|MADV_FREE
value|5
end_define

begin_comment
comment|/* dont need these pages, and junk contents */
end_comment

begin_comment
comment|/*  * Return bits from mincore  */
end_comment

begin_define
define|#
directive|define
name|MINCORE_INCORE
value|0x1
end_define

begin_comment
comment|/* Page is incore */
end_comment

begin_define
define|#
directive|define
name|MINCORE_REFERENCED
value|0x2
end_define

begin_comment
comment|/* Page has been referenced by us */
end_comment

begin_define
define|#
directive|define
name|MINCORE_MODIFIED
value|0x4
end_define

begin_comment
comment|/* Page has been modified by us */
end_comment

begin_define
define|#
directive|define
name|MINCORE_REFERENCED_OTHER
value|0x8
end_define

begin_comment
comment|/* Page has been referenced */
end_comment

begin_define
define|#
directive|define
name|MINCORE_MODIFIED_OTHER
value|0x10
end_define

begin_comment
comment|/* Page has been modified */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
ifdef|#
directive|ifdef
name|_POSIX4_VISIBLE
name|int
name|mlockall
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|munlockall
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|shm_open
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|mode_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|shm_unlink
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX4_VISIBLE */
end_comment

begin_decl_stmt
name|int
name|mlock
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|_MMAP_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_MMAP_DECLARED
end_define

begin_decl_stmt
name|void
modifier|*
name|mmap
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|size_t
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|off_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|mprotect
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
operator|,
name|size_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msync
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|size_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|munlock
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|munmap
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|size_t
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
name|int
name|madvise
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|size_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mincore
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
operator|,
name|size_t
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|minherit
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|size_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

