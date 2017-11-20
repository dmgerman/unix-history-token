begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Scooter Morris at Genentech Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)lockf.h	8.1 (Berkeley) 6/11/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_LOCKF_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_LOCKF_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_sx.h>
end_include

begin_struct_decl
struct_decl|struct
name|flock
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vop_advlock_args
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vop_advlockasync_args
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * The lockf_entry structure is a kernel structure which contains the  * information associated with a byte range lock.  The lockf_entry  * structures are linked into the inode structure. Locks are sorted by  * the starting byte of the lock for efficiency.  *  * Active and pending locks on a vnode are organised into a  * graph. Each pending lock has an out-going edge to each active lock  * that blocks it.  *  * Locks:  * (i)		locked by the vnode interlock  * (s)		locked by state->ls_lock  * (S)		locked by lf_lock_states_lock  * (c)		const until freeing  */
end_comment

begin_struct
struct|struct
name|lockf_edge
block|{
name|LIST_ENTRY
argument_list|(
argument|lockf_edge
argument_list|)
name|le_outlink
expr_stmt|;
comment|/* (s) link from's out-edge list */
name|LIST_ENTRY
argument_list|(
argument|lockf_edge
argument_list|)
name|le_inlink
expr_stmt|;
comment|/* (s) link to's in-edge list */
name|struct
name|lockf_entry
modifier|*
name|le_from
decl_stmt|;
comment|/* (c) out-going from here */
name|struct
name|lockf_entry
modifier|*
name|le_to
decl_stmt|;
comment|/* (s) in-coming to here */
block|}
struct|;
end_struct

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|lockf_edge_list
argument_list|,
name|lockf_edge
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|lockf_entry
block|{
name|short
name|lf_flags
decl_stmt|;
comment|/* (c) Semantics: F_POSIX, F_FLOCK, F_WAIT */
name|short
name|lf_type
decl_stmt|;
comment|/* (s) Lock type: F_RDLCK, F_WRLCK */
name|off_t
name|lf_start
decl_stmt|;
comment|/* (s) Byte # of the start of the lock */
name|off_t
name|lf_end
decl_stmt|;
comment|/* (s) Byte # of the end of the lock (OFF_MAX=EOF) */
name|struct
name|lock_owner
modifier|*
name|lf_owner
decl_stmt|;
comment|/* (c) Owner of the lock */
name|struct
name|vnode
modifier|*
name|lf_vnode
decl_stmt|;
comment|/* (c) File being locked (only valid for active lock) */
name|struct
name|inode
modifier|*
name|lf_inode
decl_stmt|;
comment|/* (c) Back pointer to the inode */
name|struct
name|task
modifier|*
name|lf_async_task
decl_stmt|;
comment|/* (c) Async lock callback */
name|LIST_ENTRY
argument_list|(
argument|lockf_entry
argument_list|)
name|lf_link
expr_stmt|;
comment|/* (s) Linkage for lock lists */
name|struct
name|lockf_edge_list
name|lf_outedges
decl_stmt|;
comment|/* (s) list of out-edges */
name|struct
name|lockf_edge_list
name|lf_inedges
decl_stmt|;
comment|/* (s) list of out-edges */
name|int
name|lf_refs
decl_stmt|;
comment|/* (s) ref count */
block|}
struct|;
end_struct

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|lockf_entry_list
argument_list|,
name|lockf_entry
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Extra lf_flags bits used by the implementation  */
end_comment

begin_define
define|#
directive|define
name|F_INTR
value|0x8000
end_define

begin_comment
comment|/* lock was interrupted by lf_purgelocks */
end_comment

begin_comment
comment|/*  * Filesystem private node structures should include space for a  * pointer to a struct lockf_state. This pointer is used by the lock  * manager to track the locking state for a file.  *  * The ls_active list contains the set of active locks on the file. It  * is strictly ordered by the lock's lf_start value. Each active lock  * will have in-coming edges to any pending lock which it blocks.  *  * Lock requests which are blocked by some other active lock are  * listed in ls_pending with newer requests first in the list. Lock  * requests in this list will have out-going edges to each active lock  * that blocks then. They will also have out-going edges to each  * pending lock that is older in the queue - this helps to ensure  * fairness when several processes are contenting to lock the same  * record.   * The value of ls_threads is the number of threads currently using  * the state structure (typically either setting/clearing locks or  * sleeping waiting to do so). This is used to defer freeing the  * structure while some thread is still using it.  */
end_comment

begin_struct
struct|struct
name|lockf
block|{
name|LIST_ENTRY
argument_list|(
argument|lockf
argument_list|)
name|ls_link
expr_stmt|;
comment|/* (S) all active lockf states */
name|struct
name|sx
name|ls_lock
decl_stmt|;
name|struct
name|lockf_entry_list
name|ls_active
decl_stmt|;
comment|/* (s) Active locks */
name|struct
name|lockf_entry_list
name|ls_pending
decl_stmt|;
comment|/* (s) Pending locks */
name|int
name|ls_threads
decl_stmt|;
comment|/* (i) Thread count */
block|}
struct|;
end_struct

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|lockf_list
argument_list|,
name|lockf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|int
name|lf_iterator
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|flock
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|lf_advlock
parameter_list|(
name|struct
name|vop_advlock_args
modifier|*
parameter_list|,
name|struct
name|lockf
modifier|*
modifier|*
parameter_list|,
name|u_quad_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lf_advlockasync
parameter_list|(
name|struct
name|vop_advlockasync_args
modifier|*
parameter_list|,
name|struct
name|lockf
modifier|*
modifier|*
parameter_list|,
name|u_quad_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lf_purgelocks
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|lockf
modifier|*
modifier|*
name|statep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lf_iteratelocks_sysid
parameter_list|(
name|int
name|sysid
parameter_list|,
name|lf_iterator
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lf_iteratelocks_vnode
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|lf_iterator
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lf_countlocks
parameter_list|(
name|int
name|sysid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lf_clearremotesys
parameter_list|(
name|int
name|sysid
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_LOCKF_H_ */
end_comment

end_unit

