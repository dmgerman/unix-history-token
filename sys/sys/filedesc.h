begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)filedesc.h	8.1 (Berkeley) 6/2/93  * $FreeBSD$  */
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
file|<sys/queue.h>
end_include

begin_comment
comment|/*  * This structure is used for the management of descriptors.  It may be  * shared by multiple processes.  *  * A process is initially started out with NDFILE descriptors stored within  * this structure, selected to be enough for typical applications based on  * the historical limit of 20 open files (and the usage of descriptors by  * shells).  If these descriptors are exhausted, a larger descriptor table  * may be allocated, up to a process' resource limit; the internal arrays  * are then unused.  The initial expansion is set to NDEXTENT; each time  * it runs out, it is doubled until the resource limit is reached. NDEXTENT  * should be selected to be the biggest multiple of OFILESIZE (see below)  * that will fit in a power-of-two sized piece of memory.  */
end_comment

begin_define
define|#
directive|define
name|NDFILE
value|20
end_define

begin_define
define|#
directive|define
name|NDEXTENT
value|50
end_define

begin_comment
comment|/* 250 bytes in 256-byte alloc. */
end_comment

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
name|int
name|fd_knlistsize
decl_stmt|;
comment|/* size of knlist */
name|struct
name|klist
modifier|*
name|fd_knlist
decl_stmt|;
comment|/* list of attached knotes */
name|u_long
name|fd_knhashmask
decl_stmt|;
comment|/* size of knhash */
name|struct
name|klist
modifier|*
name|fd_knhash
decl_stmt|;
comment|/* hash table for attached knotes */
name|struct
name|mtx
name|fd_mtx
decl_stmt|;
comment|/* mtx to protect the members of struct filedesc */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Basic allocation of descriptors:  * one of the above, plus arrays for NDFILE descriptors.  */
end_comment

begin_struct
struct|struct
name|filedesc0
block|{
name|struct
name|filedesc
name|fd_fd
decl_stmt|;
comment|/* 	 * These arrays are used when the number of open files is 	 *<= NDFILE, and are then pointed to by the pointers above. 	 */
name|struct
name|file
modifier|*
name|fd_dfiles
index|[
name|NDFILE
index|]
decl_stmt|;
name|char
name|fd_dfileflags
index|[
name|NDFILE
index|]
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

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|UF_MAPPED
value|0x02
end_define

begin_comment
comment|/* mapped from device */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Storage required per open file descriptor.  */
end_comment

begin_define
define|#
directive|define
name|OFILESIZE
value|(sizeof(struct file *) + sizeof(char))
end_define

begin_comment
comment|/*  * This structure holds the information needed to send a SIGIO or  * a SIGURG signal to a process or process group when new data arrives  * on a device or socket.  The structure is placed on an SLIST belonging  * to the proc or pgrp so that the entire list may be revoked when the  * process exits or the process group disappears.  *  * (c)	const  * (pg)	locked by either the process or process group lock  */
end_comment

begin_struct
struct|struct
name|sigio
block|{
union|union
block|{
name|struct
name|proc
modifier|*
name|siu_proc
decl_stmt|;
comment|/* (c)	process to receive SIGIO/SIGURG */
name|struct
name|pgrp
modifier|*
name|siu_pgrp
decl_stmt|;
comment|/* (c)	process group to receive ... */
block|}
name|sio_u
union|;
name|SLIST_ENTRY
argument_list|(
argument|sigio
argument_list|)
name|sio_pgsigio
expr_stmt|;
comment|/* (pg)	sigio's for process or group */
name|struct
name|sigio
modifier|*
modifier|*
name|sio_myref
decl_stmt|;
comment|/* (c)	location of the pointer that holds 					 * 	the reference to this structure */
name|struct
name|ucred
modifier|*
name|sio_ucred
decl_stmt|;
comment|/* (c)	current credentials */
name|pid_t
name|sio_pgid
decl_stmt|;
comment|/* (c)	pgid for signals */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sio_proc
value|sio_u.siu_proc
end_define

begin_define
define|#
directive|define
name|sio_pgrp
value|sio_u.siu_pgrp
end_define

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|sigiolst
argument_list|,
name|sigio
argument_list|)
expr_stmt|;
end_expr_stmt

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
name|p
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
name|p
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
name|p
parameter_list|,
name|int
name|want
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
name|thread
modifier|*
name|td
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
name|fdshare
parameter_list|(
name|struct
name|proc
modifier|*
name|p
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
expr_stmt|;
end_expr_stmt

begin_function_decl
name|pid_t
name|fgetown
parameter_list|(
name|struct
name|sigio
modifier|*
name|sigio
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fsetown
parameter_list|(
name|pid_t
name|pgid
parameter_list|,
name|struct
name|sigio
modifier|*
modifier|*
name|sigiop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|funsetown
parameter_list|(
name|struct
name|sigio
modifier|*
name|sigio
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|funsetownlst
parameter_list|(
name|struct
name|sigiolst
modifier|*
name|sigiolst
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
argument|fdp
argument_list|,
argument|fd
argument_list|)
expr|struct
name|filedesc
operator|*
name|fdp
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|fd
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* u_int cast checks for negative descriptors. */
return|return
operator|(
operator|(
name|u_int
operator|)
name|fd
operator|>=
name|fdp
operator|->
name|fd_nfiles
condition|?
name|NULL
else|:
name|fdp
operator|->
name|fd_ofiles
index|[
name|fd
index|]
operator|)
return|;
block|}
end_block

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

