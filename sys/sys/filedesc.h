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

begin_struct_decl
struct_decl|struct
name|klist
struct_decl|;
end_struct_decl

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
name|u_short
name|fd_lastfile
decl_stmt|;
comment|/* high-water mark of fd_ofiles */
name|u_short
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
comment|/*  * This structure that holds the information needed to send a SIGIO or  * a SIGURG signal to a process or process group when new data arrives  * on a device or socket.  The structure is placed on an SLIST belonging  * to the proc or pgrp so that the entire list may be revoked when the  * process exits or the process group disappears.  */
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
comment|/* process to receive SIGIO/SIGURG */
name|struct
name|pgrp
modifier|*
name|siu_pgrp
decl_stmt|;
comment|/* process group to receive ... */
block|}
name|sio_u
union|;
name|SLIST_ENTRY
argument_list|(
argument|sigio
argument_list|)
name|sio_pgsigio
expr_stmt|;
comment|/* sigio's for process or group */
name|struct
name|sigio
modifier|*
modifier|*
name|sio_myref
decl_stmt|;
comment|/* location of the pointer that holds 					 * the reference to this structure */
name|struct
name|ucred
modifier|*
name|sio_ucred
decl_stmt|;
comment|/* current credentials */
name|uid_t
name|sio_ruid
decl_stmt|;
comment|/* real user id */
name|pid_t
name|sio_pgid
decl_stmt|;
comment|/* pgid for signals */
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
comment|/*  * Kernel global variables and routines.  */
end_comment

begin_decl_stmt
name|int
name|dupfdopen
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|filedesc
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fdalloc
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
name|int
name|want
operator|,
name|int
operator|*
name|result
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fdavail
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
name|int
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|falloc
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
expr|struct
name|file
operator|*
operator|*
name|resultfp
operator|,
name|int
operator|*
name|resultfd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ffree
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|filedesc
modifier|*
name|fdinit
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|filedesc
modifier|*
name|fdshare
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|filedesc
modifier|*
name|fdcopy
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fdfree
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|closef
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
name|fp
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fdcloseexec
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|file
modifier|*
name|holdfp
name|__P
argument_list|(
operator|(
expr|struct
name|filedesc
operator|*
name|fdp
operator|,
name|int
name|fd
operator|,
name|int
name|flag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getvnode
name|__P
argument_list|(
operator|(
expr|struct
name|filedesc
operator|*
name|fdp
operator|,
name|int
name|fd
operator|,
expr|struct
name|file
operator|*
operator|*
name|fpp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fdissequential
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fdsequential
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pid_t
name|fgetown
name|__P
argument_list|(
operator|(
expr|struct
name|sigio
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fsetown
name|__P
argument_list|(
operator|(
name|pid_t
operator|,
expr|struct
name|sigio
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|funsetown
name|__P
argument_list|(
operator|(
expr|struct
name|sigio
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|funsetownlst
name|__P
argument_list|(
operator|(
expr|struct
name|sigiolst
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setugidsafety
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

