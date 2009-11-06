begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)mman.h	8.2 (Berkeley) 1/9/95  * $FreeBSD$  */
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
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_comment
comment|/*  * Inheritance for minherit()  */
end_comment

begin_define
define|#
directive|define
name|INHERIT_SHARE
value|0
end_define

begin_define
define|#
directive|define
name|INHERIT_COPY
value|1
end_define

begin_define
define|#
directive|define
name|INHERIT_NONE
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|MAP_COPY
value|MAP_PRIVATE
end_define

begin_comment
comment|/* Obsolete */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

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
name|MAP_RESERVED0080
value|0x0080
end_define

begin_comment
comment|/* previously misimplemented MAP_INHERIT */
end_comment

begin_define
define|#
directive|define
name|MAP_RESERVED0100
value|0x0100
end_define

begin_comment
comment|/* previously unimplemented MAP_NOEXTEND */
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

begin_define
define|#
directive|define
name|MAP_STACK
value|0x0400
end_define

begin_comment
comment|/* region grows down, like a stack */
end_comment

begin_define
define|#
directive|define
name|MAP_NOSYNC
value|0x0800
end_define

begin_comment
comment|/* page to but do not sync underlying file */
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

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_define
define|#
directive|define
name|MAP_ANONYMOUS
value|MAP_ANON
end_define

begin_comment
comment|/* For compatibility. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_comment
comment|/*  * Extended flags  */
end_comment

begin_define
define|#
directive|define
name|MAP_NOCORE
value|0x00020000
end_define

begin_comment
comment|/* dont include these pages in a coredump */
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
literal|199309
end_if

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
comment|/*  * Advice to madvise  */
end_comment

begin_define
define|#
directive|define
name|_MADV_NORMAL
value|0
end_define

begin_comment
comment|/* no further special treatment */
end_comment

begin_define
define|#
directive|define
name|_MADV_RANDOM
value|1
end_define

begin_comment
comment|/* expect random page references */
end_comment

begin_define
define|#
directive|define
name|_MADV_SEQUENTIAL
value|2
end_define

begin_comment
comment|/* expect sequential page references */
end_comment

begin_define
define|#
directive|define
name|_MADV_WILLNEED
value|3
end_define

begin_comment
comment|/* will need these pages */
end_comment

begin_define
define|#
directive|define
name|_MADV_DONTNEED
value|4
end_define

begin_comment
comment|/* dont need these pages */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|MADV_NORMAL
value|_MADV_NORMAL
end_define

begin_define
define|#
directive|define
name|MADV_RANDOM
value|_MADV_RANDOM
end_define

begin_define
define|#
directive|define
name|MADV_SEQUENTIAL
value|_MADV_SEQUENTIAL
end_define

begin_define
define|#
directive|define
name|MADV_WILLNEED
value|_MADV_WILLNEED
end_define

begin_define
define|#
directive|define
name|MADV_DONTNEED
value|_MADV_DONTNEED
end_define

begin_define
define|#
directive|define
name|MADV_FREE
value|5
end_define

begin_comment
comment|/* dont need these pages, and junk contents */
end_comment

begin_define
define|#
directive|define
name|MADV_NOSYNC
value|6
end_define

begin_comment
comment|/* try to avoid flushes to physical media */
end_comment

begin_define
define|#
directive|define
name|MADV_AUTOSYNC
value|7
end_define

begin_comment
comment|/* revert to default flushing strategy */
end_comment

begin_define
define|#
directive|define
name|MADV_NOCORE
value|8
end_define

begin_comment
comment|/* do not include these pages in a core file */
end_comment

begin_define
define|#
directive|define
name|MADV_CORE
value|9
end_define

begin_comment
comment|/* revert to including pages in a core file */
end_comment

begin_define
define|#
directive|define
name|MADV_PROTECT
value|10
end_define

begin_comment
comment|/* protect process from pageout kill */
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

begin_define
define|#
directive|define
name|MINCORE_SUPER
value|0x20
end_define

begin_comment
comment|/* Page is a "super" page */
end_comment

begin_comment
comment|/*  * Anonymous object constant for shm_open().  */
end_comment

begin_define
define|#
directive|define
name|SHM_ANON
value|((char *)1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BSD_VISIBLE */
end_comment

begin_comment
comment|/*  * XXX missing POSIX_TYPED_MEM_* macros and  * posix_typed_mem_info structure.  */
end_comment

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200112
end_if

begin_define
define|#
directive|define
name|POSIX_MADV_NORMAL
value|_MADV_NORMAL
end_define

begin_define
define|#
directive|define
name|POSIX_MADV_RANDOM
value|_MADV_RANDOM
end_define

begin_define
define|#
directive|define
name|POSIX_MADV_SEQUENTIAL
value|_MADV_SEQUENTIAL
end_define

begin_define
define|#
directive|define
name|POSIX_MADV_WILLNEED
value|_MADV_WILLNEED
end_define

begin_define
define|#
directive|define
name|POSIX_MADV_DONTNEED
value|_MADV_DONTNEED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_MODE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__mode_t
name|mode_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_MODE_T_DECLARED
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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_struct
struct|struct
name|shmfd
block|{
name|size_t
name|shm_size
decl_stmt|;
name|vm_object_t
name|shm_object
decl_stmt|;
name|int
name|shm_refs
decl_stmt|;
name|uid_t
name|shm_uid
decl_stmt|;
name|gid_t
name|shm_gid
decl_stmt|;
name|mode_t
name|shm_mode
decl_stmt|;
comment|/* 	 * Values maintained solely to make this a better-behaved file 	 * descriptor for fstat() to run on. 	 */
name|struct
name|timespec
name|shm_atime
decl_stmt|;
name|struct
name|timespec
name|shm_mtime
decl_stmt|;
name|struct
name|timespec
name|shm_ctime
decl_stmt|;
name|struct
name|timespec
name|shm_birthtime
decl_stmt|;
name|struct
name|label
modifier|*
name|shm_label
decl_stmt|;
comment|/* MAC label */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|shm_mmap
parameter_list|(
name|struct
name|shmfd
modifier|*
name|shmfd
parameter_list|,
name|vm_size_t
name|objsize
parameter_list|,
name|vm_ooffset_t
name|foff
parameter_list|,
name|vm_object_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_function_decl
name|__BEGIN_DECLS
comment|/*  * XXX not yet implemented: posix_mem_offset(), posix_typed_mem_get_info(),  * posix_typed_mem_open().  */
if|#
directive|if
name|__BSD_VISIBLE
name|int
name|getpagesizes
parameter_list|(
name|size_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|madvise
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mincore
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|minherit
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|mlock
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|void
modifier|*
name|mmap
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|mprotect
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|msync
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|munlock
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|munmap
parameter_list|(
name|void
modifier|*
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
literal|200112
end_if

begin_function_decl
name|int
name|posix_madvise
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
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
literal|199309
end_if

begin_function_decl
name|int
name|mlockall
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|munlockall
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|shm_open
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|shm_unlink
parameter_list|(
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
comment|/* !_SYS_MMAN_H_ */
end_comment

end_unit

