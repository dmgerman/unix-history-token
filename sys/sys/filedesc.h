begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)filedesc.h	8.1 (Berkeley) 6/2/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_FILEDESC_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_FILEDESC_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/event.h>
end_include

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
end_include

begin_include
include|#
directive|include
file|<machine/_limits.h>
end_include

begin_comment
comment|/*  * This structure is used for the management of descriptors.  It may be  * shared by multiple processes.  */
end_comment

begin_define
define|#
directive|define
name|NDSLOTTYPE
value|u_long
end_define

begin_struct
struct|struct
name|filedesc
block|{
name|struct
name|file
modifier|*
modifier|*
name|fd_ofiles
decl_stmt|;
comment|/* file structures for open files */
name|char
modifier|*
name|fd_ofileflags
decl_stmt|;
comment|/* per-process open file flags */
name|struct
name|vnode
modifier|*
name|fd_cdir
decl_stmt|;
comment|/* current directory */
name|struct
name|vnode
modifier|*
name|fd_rdir
decl_stmt|;
comment|/* root directory */
name|struct
name|vnode
modifier|*
name|fd_jdir
decl_stmt|;
comment|/* jail root directory */
name|int
name|fd_nfiles
decl_stmt|;
comment|/* number of open files allocated */
name|NDSLOTTYPE
modifier|*
name|fd_map
decl_stmt|;
comment|/* bitmap of free fds */
name|int
name|fd_lastfile
decl_stmt|;
comment|/* high-water mark of fd_ofiles */
name|int
name|fd_freefile
decl_stmt|;
comment|/* approx. next free file */
name|u_short
name|fd_cmask
decl_stmt|;
comment|/* mask for file creation */
name|u_short
name|fd_refcnt
decl_stmt|;
comment|/* reference count */
name|struct
name|mtx
name|fd_mtx
decl_stmt|;
comment|/* protects members of this struct */
name|struct
name|kqlist
name|fd_kqlist
decl_stmt|;
comment|/* list of kqueues on this filedesc */
name|int
name|fd_holdleaderscount
decl_stmt|;
comment|/* block fdfree() for shared close() */
name|int
name|fd_holdleaderswakeup
decl_stmt|;
comment|/* fdfree() needs wakeup */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure to keep track of (process leader, struct fildedesc) tuples.  * Each process has a pointer to such a structure when detailed tracking  * is needed, e.g., when rfork(RFPROC | RFMEM) causes a file descriptor  * table to be shared by processes having different "p_leader" pointers  * and thus distinct POSIX style locks.  *  * fdl_refcount and fdl_holdcount are protected by struct filedesc mtx.  */
end_comment

begin_struct
struct|struct
name|filedesc_to_leader
block|{
name|int
name|fdl_refcount
decl_stmt|;
comment|/* references from struct proc */
name|int
name|fdl_holdcount
decl_stmt|;
comment|/* temporary hold during closef */
name|int
name|fdl_wakeup
decl_stmt|;
comment|/* fdfree() waits on closef() */
name|struct
name|proc
modifier|*
name|fdl_leader
decl_stmt|;
comment|/* owner of POSIX locks */
comment|/* Circular list: */
name|struct
name|filedesc_to_leader
modifier|*
name|fdl_prev
decl_stmt|;
name|struct
name|filedesc_to_leader
modifier|*
name|fdl_next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-process open flags.  */
end_comment

begin_define
define|#
directive|define
name|UF_EXCLOSE
value|0x01
end_define

begin_comment
comment|/* auto-close on exec */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* Lock a file descriptor table. */
end_comment

begin_define
define|#
directive|define
name|FILEDESC_LOCK
parameter_list|(
name|fd
parameter_list|)
value|mtx_lock(&(fd)->fd_mtx)
end_define

begin_define
define|#
directive|define
name|FILEDESC_UNLOCK
parameter_list|(
name|fd
parameter_list|)
value|mtx_unlock(&(fd)->fd_mtx)
end_define

begin_define
define|#
directive|define
name|FILEDESC_LOCKED
parameter_list|(
name|fd
parameter_list|)
value|mtx_owned(&(fd)->fd_mtx)
end_define

begin_define
define|#
directive|define
name|FILEDESC_LOCK_ASSERT
parameter_list|(
name|fd
parameter_list|,
name|type
parameter_list|)
value|mtx_assert(&(fd)->fd_mtx, (type))
end_define

begin_define
define|#
directive|define
name|FILEDESC_LOCK_DESC
value|"filedesc structure"
end_define

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|closef
parameter_list|(
name|struct
name|file
modifier|*
name|fp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dupfdopen
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|filedesc
modifier|*
name|fdp
parameter_list|,
name|int
name|indx
parameter_list|,
name|int
name|dfd
parameter_list|,
name|int
name|mode
parameter_list|,
name|int
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|falloc
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|file
modifier|*
modifier|*
name|resultfp
parameter_list|,
name|int
modifier|*
name|resultfd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdalloc
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|minfd
parameter_list|,
name|int
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdavail
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdcheckstd
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fdcloseexec
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|filedesc
modifier|*
name|fdcopy
parameter_list|(
name|struct
name|filedesc
modifier|*
name|fdp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fdfree
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|filedesc
modifier|*
name|fdinit
parameter_list|(
name|struct
name|filedesc
modifier|*
name|fdp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|filedesc
modifier|*
name|fdshare
parameter_list|(
name|struct
name|filedesc
modifier|*
name|fdp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fdunused
parameter_list|(
name|struct
name|filedesc
modifier|*
name|fdp
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fdused
parameter_list|(
name|struct
name|filedesc
modifier|*
name|fdp
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffree
parameter_list|(
name|struct
name|file
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|filedesc_to_leader
modifier|*
name|filedesc_to_leader_alloc
parameter_list|(
name|struct
name|filedesc_to_leader
modifier|*
name|old
parameter_list|,
name|struct
name|filedesc
modifier|*
name|fdp
parameter_list|,
name|struct
name|proc
modifier|*
name|leader
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getvnode
parameter_list|(
name|struct
name|filedesc
modifier|*
name|fdp
parameter_list|,
name|int
name|fd
parameter_list|,
name|struct
name|file
modifier|*
modifier|*
name|fpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setugidsafety
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|file
operator|*
name|fget_locked
argument_list|(
argument|struct filedesc *fdp
argument_list|,
argument|int fd
argument_list|)
block|{
return|return
operator|(
name|fd
operator|<
literal|0
operator|||
name|fd
operator|>=
name|fdp
operator|->
name|fd_nfiles
operator|?
name|NULL
operator|:
name|fdp
operator|->
name|fd_ofiles
index|[
name|fd
index|]
operator|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|fdesc_mtx
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_FILEDESC_H_ */
end_comment

end_unit

