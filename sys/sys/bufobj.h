begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Poul-Henning Kamp  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Architectural notes:  *  * bufobj is a new object which is what buffers hang from in the buffer  * cache.  *  * This used to be vnodes, but we need non-vnode code to be able  * to use the buffer cache as well, specifically geom classes like gbde,  * raid3 and raid5.  *  * All vnodes will contain a bufobj initially, but down the road we may  * want to only allocate bufobjs when they are needed.  There could be a  * large number of vnodes in the system which wouldn't need a bufobj during  * their lifetime.  *  * The exact relationship to the vmobject is not determined at this point,  * it may in fact be that we find them to be two sides of the same object   * once things starts to crystalize.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_BUFOBJ_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_BUFOBJ_H_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_KVM_VNODE
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_struct_decl
struct_decl|struct
name|bufobj
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|buf_ops
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|struct
name|buf_ops
name|buf_ops_bio
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|buflists
argument_list|,
name|buf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* A Buffer splay list */
end_comment

begin_struct
struct|struct
name|bufv
block|{
name|struct
name|buflists
name|bv_hd
decl_stmt|;
comment|/* Sorted blocklist */
name|struct
name|buf
modifier|*
name|bv_root
decl_stmt|;
comment|/* Buf splay tree */
name|int
name|bv_cnt
decl_stmt|;
comment|/* Number of buffers */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|void
name|b_strategy_t
parameter_list|(
name|struct
name|bufobj
modifier|*
parameter_list|,
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|b_write_t
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|b_sync_t
parameter_list|(
name|struct
name|bufobj
modifier|*
parameter_list|,
name|int
name|waitfor
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|b_bdflush_t
parameter_list|(
name|struct
name|bufobj
modifier|*
parameter_list|,
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|buf_ops
block|{
name|char
modifier|*
name|bop_name
decl_stmt|;
name|b_write_t
modifier|*
name|bop_write
decl_stmt|;
name|b_strategy_t
modifier|*
name|bop_strategy
decl_stmt|;
name|b_sync_t
modifier|*
name|bop_sync
decl_stmt|;
name|b_bdflush_t
modifier|*
name|bop_bdflush
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BO_STRATEGY
parameter_list|(
name|bo
parameter_list|,
name|bp
parameter_list|)
value|((bo)->bo_ops->bop_strategy((bo), (bp)))
end_define

begin_define
define|#
directive|define
name|BO_SYNC
parameter_list|(
name|bo
parameter_list|,
name|w
parameter_list|,
name|td
parameter_list|)
value|((bo)->bo_ops->bop_sync((bo), (w), (td)))
end_define

begin_define
define|#
directive|define
name|BO_WRITE
parameter_list|(
name|bo
parameter_list|,
name|bp
parameter_list|)
value|((bo)->bo_ops->bop_write((bp)))
end_define

begin_define
define|#
directive|define
name|BO_BDFLUSH
parameter_list|(
name|bo
parameter_list|,
name|bp
parameter_list|)
value|((bo)->bo_ops->bop_bdflush((bo), (bp)))
end_define

begin_struct
struct|struct
name|bufobj
block|{
name|struct
name|mtx
modifier|*
name|bo_mtx
decl_stmt|;
comment|/* Mutex which protects "i" things */
name|struct
name|bufv
name|bo_clean
decl_stmt|;
comment|/* i Clean buffers */
name|struct
name|bufv
name|bo_dirty
decl_stmt|;
comment|/* i Dirty buffers */
name|long
name|bo_numoutput
decl_stmt|;
comment|/* i Writes in progress */
name|u_int
name|bo_flag
decl_stmt|;
comment|/* i Flags */
name|struct
name|buf_ops
modifier|*
name|bo_ops
decl_stmt|;
comment|/* - Buffer operations */
name|int
name|bo_bsize
decl_stmt|;
comment|/* - Block size for i/o */
name|struct
name|vm_object
modifier|*
name|bo_object
decl_stmt|;
comment|/* v Place to store VM object */
name|LIST_ENTRY
argument_list|(
argument|bufobj
argument_list|)
name|bo_synclist
expr_stmt|;
comment|/* S dirty vnode list */
name|void
modifier|*
name|bo_private
decl_stmt|;
comment|/* private pointer */
name|struct
name|vnode
modifier|*
name|__bo_vnode
decl_stmt|;
comment|/* 					 * XXX: This vnode pointer is here 					 * XXX: only to keep the syncer working 					 * XXX: for now. 					 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * XXX BO_ONWORKLST could be replaced with a check for NULL list elements  * in v_synclist.  */
end_comment

begin_define
define|#
directive|define
name|BO_ONWORKLST
value|(1<< 0)
end_define

begin_comment
comment|/* On syncer work-list */
end_comment

begin_define
define|#
directive|define
name|BO_WWAIT
value|(1<< 1)
end_define

begin_comment
comment|/* Wait for output to complete */
end_comment

begin_define
define|#
directive|define
name|BO_NEEDSGIANT
value|(1<< 2)
end_define

begin_comment
comment|/* Require giant for child buffers. */
end_comment

begin_define
define|#
directive|define
name|BO_LOCK
parameter_list|(
name|bo
parameter_list|)
define|\
value|do { \ 		KASSERT((bo)->bo_mtx != NULL, ("No lock in bufobj")); \ 		mtx_lock((bo)->bo_mtx); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|BO_UNLOCK
parameter_list|(
name|bo
parameter_list|)
define|\
value|do { \ 		KASSERT((bo)->bo_mtx != NULL, ("No lock in bufobj")); \ 		mtx_unlock((bo)->bo_mtx); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|BO_MTX
parameter_list|(
name|bo
parameter_list|)
value|((bo)->bo_mtx)
end_define

begin_define
define|#
directive|define
name|ASSERT_BO_LOCKED
parameter_list|(
name|bo
parameter_list|)
value|mtx_assert(bo->bo_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|ASSERT_BO_UNLOCKED
parameter_list|(
name|bo
parameter_list|)
value|mtx_assert(bo->bo_mtx, MA_NOTOWNED)
end_define

begin_function_decl
name|void
name|bufobj_wdrop
parameter_list|(
name|struct
name|bufobj
modifier|*
name|bo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bufobj_wref
parameter_list|(
name|struct
name|bufobj
modifier|*
name|bo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bufobj_wrefl
parameter_list|(
name|struct
name|bufobj
modifier|*
name|bo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bufobj_invalbuf
parameter_list|(
name|struct
name|bufobj
modifier|*
name|bo
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|slpflag
parameter_list|,
name|int
name|slptimeo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bufobj_wwait
parameter_list|(
name|struct
name|bufobj
modifier|*
name|bo
parameter_list|,
name|int
name|slpflag
parameter_list|,
name|int
name|timeo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bufsync
parameter_list|(
name|struct
name|bufobj
modifier|*
name|bo
parameter_list|,
name|int
name|waitfor
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bufbdflush
parameter_list|(
name|struct
name|bufobj
modifier|*
name|bo
parameter_list|,
name|struct
name|buf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(_KERNEL) || defined(_KVM_VNODE) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_BUFOBJ_H_ */
end_comment

end_unit

