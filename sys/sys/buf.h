begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)buf.h	8.9 (Berkeley) 3/30/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_BUF_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_BUF_H_
end_define

begin_include
include|#
directive|include
file|<sys/bufobj.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/lockmgr.h>
end_include

begin_struct_decl
struct_decl|struct
name|bio
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|buf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bufobj
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mount
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vnode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * To avoid including<ufs/ffs/softdep.h>   */
end_comment

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|workhead
argument_list|,
name|worklist
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * These are currently used only by the soft dependency code, hence  * are stored once in a global variable. If other subsystems wanted  * to use these hooks, a pointer to a set of bio_ops could be added  * to each buffer.  */
end_comment

begin_struct
specifier|extern
struct|struct
name|bio_ops
block|{
name|void
function_decl|(
modifier|*
name|io_start
function_decl|)
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|io_complete
function_decl|)
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|io_deallocate
function_decl|)
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|io_countdeps
function_decl|)
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
block|}
name|bioops
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|vm_object
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vm_page
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|unsigned
name|char
name|b_xflags_t
typedef|;
end_typedef

begin_comment
comment|/*  * The buffer header describes an I/O operation in the kernel.  *  * NOTES:  *	b_bufsize, b_bcount.  b_bufsize is the allocation size of the  *	buffer, either DEV_BSIZE or PAGE_SIZE aligned.  b_bcount is the  *	originally requested buffer size and can serve as a bounds check  *	against EOF.  For most, but not all uses, b_bcount == b_bufsize.  *  *	b_dirtyoff, b_dirtyend.  Buffers support piecemeal, unaligned  *	ranges of dirty data that need to be written to backing store.  *	The range is typically clipped at b_bcount ( not b_bufsize ).  *  *	b_resid.  Number of bytes remaining in I/O.  After an I/O operation  *	completes, b_resid is usually 0 indicating 100% success.  *  *	All fields are protected by the buffer lock except those marked:  *		V - Protected by owning bufobj lock  *		Q - Protected by the buf queue lock  *		D - Protected by an dependency implementation specific lock  */
end_comment

begin_struct
struct|struct
name|buf
block|{
name|struct
name|bufobj
modifier|*
name|b_bufobj
decl_stmt|;
name|long
name|b_bcount
decl_stmt|;
name|void
modifier|*
name|b_caller1
decl_stmt|;
name|caddr_t
name|b_data
decl_stmt|;
name|int
name|b_error
decl_stmt|;
name|uint16_t
name|b_iocmd
decl_stmt|;
comment|/* BIO_* bio_cmd from bio.h */
name|uint16_t
name|b_ioflags
decl_stmt|;
comment|/* BIO_* bio_flags from bio.h */
name|off_t
name|b_iooffset
decl_stmt|;
name|long
name|b_resid
decl_stmt|;
name|void
function_decl|(
modifier|*
name|b_iodone
function_decl|)
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
name|daddr_t
name|b_blkno
decl_stmt|;
comment|/* Underlying physical block number. */
name|off_t
name|b_offset
decl_stmt|;
comment|/* Offset into file. */
name|TAILQ_ENTRY
argument_list|(
argument|buf
argument_list|)
name|b_bobufs
expr_stmt|;
comment|/* (V) Buffer's associated vnode. */
name|uint32_t
name|b_vflags
decl_stmt|;
comment|/* (V) BV_* flags */
name|unsigned
name|short
name|b_qindex
decl_stmt|;
comment|/* (Q) buffer queue index */
name|uint32_t
name|b_flags
decl_stmt|;
comment|/* B_* flags. */
name|b_xflags_t
name|b_xflags
decl_stmt|;
comment|/* extra flags */
name|struct
name|lock
name|b_lock
decl_stmt|;
comment|/* Buffer lock */
name|long
name|b_bufsize
decl_stmt|;
comment|/* Allocated buffer size. */
name|int
name|b_runningbufspace
decl_stmt|;
comment|/* when I/O is running, pipelining */
name|int
name|b_kvasize
decl_stmt|;
comment|/* size of kva for buffer */
name|int
name|b_dirtyoff
decl_stmt|;
comment|/* Offset in buffer of dirty region. */
name|int
name|b_dirtyend
decl_stmt|;
comment|/* Offset of end of dirty region. */
name|caddr_t
name|b_kvabase
decl_stmt|;
comment|/* base kva for buffer */
name|daddr_t
name|b_lblkno
decl_stmt|;
comment|/* Logical block number. */
name|struct
name|vnode
modifier|*
name|b_vp
decl_stmt|;
comment|/* Device vnode. */
name|struct
name|ucred
modifier|*
name|b_rcred
decl_stmt|;
comment|/* Read credentials reference. */
name|struct
name|ucred
modifier|*
name|b_wcred
decl_stmt|;
comment|/* Write credentials reference. */
union|union
block|{
name|TAILQ_ENTRY
argument_list|(
argument|buf
argument_list|)
name|b_freelist
expr_stmt|;
comment|/* (Q) */
struct|struct
block|{
name|void
function_decl|(
modifier|*
name|b_pgiodone
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|vm_page_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
name|b_pgbefore
decl_stmt|;
name|int
name|b_pgafter
decl_stmt|;
block|}
struct|;
block|}
union|;
union|union
name|cluster_info
block|{
name|TAILQ_HEAD
argument_list|(
argument|cluster_list_head
argument_list|,
argument|buf
argument_list|)
name|cluster_head
expr_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|buf
argument_list|)
name|cluster_entry
expr_stmt|;
block|}
name|b_cluster
union|;
name|struct
name|vm_page
modifier|*
name|b_pages
index|[
name|btoc
argument_list|(
name|MAXPHYS
argument_list|)
index|]
decl_stmt|;
name|int
name|b_npages
decl_stmt|;
name|struct
name|workhead
name|b_dep
decl_stmt|;
comment|/* (D) List of filesystem dependencies. */
name|void
modifier|*
name|b_fsprivate1
decl_stmt|;
name|void
modifier|*
name|b_fsprivate2
decl_stmt|;
name|void
modifier|*
name|b_fsprivate3
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|FULL_BUF_TRACKING
argument_list|)
define|#
directive|define
name|BUF_TRACKING_SIZE
value|32
define|#
directive|define
name|BUF_TRACKING_ENTRY
parameter_list|(
name|x
parameter_list|)
value|((x)& (BUF_TRACKING_SIZE - 1))
specifier|const
name|char
modifier|*
name|b_io_tracking
index|[
name|BUF_TRACKING_SIZE
index|]
decl_stmt|;
name|uint32_t
name|b_io_tcnt
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|BUF_TRACKING
argument_list|)
specifier|const
name|char
modifier|*
name|b_io_tracking
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|b_object
value|b_bufobj->bo_object
end_define

begin_comment
comment|/*  * These flags are kept in b_flags.  *  * Notes:  *  *	B_ASYNC		VOP calls on bp's are usually async whether or not  *			B_ASYNC is set, but some subsystems, such as NFS, like   *			to know what is best for the caller so they can  *			optimize the I/O.  *  *	B_PAGING	Indicates that bp is being used by the paging system or  *			some paging system and that the bp is not linked into  *			the b_vp's clean/dirty linked lists or ref counts.  *			Buffer vp reassignments are illegal in this case.  *  *	B_CACHE		This may only be set if the buffer is entirely valid.  *			The situation where B_DELWRI is set and B_CACHE is  *			clear MUST be committed to disk by getblk() so   *			B_DELWRI can also be cleared.  See the comments for  *			getblk() in kern/vfs_bio.c.  If B_CACHE is clear,  *			the caller is expected to clear BIO_ERROR and B_INVAL,  *			set BIO_READ, and initiate an I/O.  *  *			The 'entire buffer' is defined to be the range from  *			0 through b_bcount.  *  *	B_MALLOC	Request that the buffer be allocated from the malloc  *			pool, DEV_BSIZE aligned instead of PAGE_SIZE aligned.  *  *	B_CLUSTEROK	This flag is typically set for B_DELWRI buffers  *			by filesystems that allow clustering when the buffer  *			is fully dirty and indicates that it may be clustered  *			with other adjacent dirty buffers.  Note the clustering  *			may not be used with the stage 1 data write under NFS  *			but may be used for the commit rpc portion.  *  *	B_VMIO		Indicates that the buffer is tied into an VM object.  *			The buffer's data is always PAGE_SIZE aligned even  *			if b_bufsize and b_bcount are not.  ( b_bufsize is   *			always at least DEV_BSIZE aligned, though ).  *  *	B_DIRECT	Hint that we should attempt to completely free  *			the pages underlying the buffer.  B_DIRECT is  *			sticky until the buffer is released and typically  *			only has an effect when B_RELBUF is also set.  *  */
end_comment

begin_define
define|#
directive|define
name|B_AGE
value|0x00000001
end_define

begin_comment
comment|/* Move to age queue when I/O done. */
end_comment

begin_define
define|#
directive|define
name|B_NEEDCOMMIT
value|0x00000002
end_define

begin_comment
comment|/* Append-write in progress. */
end_comment

begin_define
define|#
directive|define
name|B_ASYNC
value|0x00000004
end_define

begin_comment
comment|/* Start I/O, do not wait. */
end_comment

begin_define
define|#
directive|define
name|B_DIRECT
value|0x00000008
end_define

begin_comment
comment|/* direct I/O flag (pls free vmio) */
end_comment

begin_define
define|#
directive|define
name|B_DEFERRED
value|0x00000010
end_define

begin_comment
comment|/* Skipped over for cleaning */
end_comment

begin_define
define|#
directive|define
name|B_CACHE
value|0x00000020
end_define

begin_comment
comment|/* Bread found us in the cache. */
end_comment

begin_define
define|#
directive|define
name|B_VALIDSUSPWRT
value|0x00000040
end_define

begin_comment
comment|/* Valid write during suspension. */
end_comment

begin_define
define|#
directive|define
name|B_DELWRI
value|0x00000080
end_define

begin_comment
comment|/* Delay I/O until buffer reused. */
end_comment

begin_define
define|#
directive|define
name|B_00000100
value|0x00000100
end_define

begin_comment
comment|/* Available flag. */
end_comment

begin_define
define|#
directive|define
name|B_DONE
value|0x00000200
end_define

begin_comment
comment|/* I/O completed. */
end_comment

begin_define
define|#
directive|define
name|B_EINTR
value|0x00000400
end_define

begin_comment
comment|/* I/O was interrupted */
end_comment

begin_define
define|#
directive|define
name|B_NOREUSE
value|0x00000800
end_define

begin_comment
comment|/* Contents not reused once released. */
end_comment

begin_define
define|#
directive|define
name|B_00001000
value|0x00001000
end_define

begin_comment
comment|/* Available flag. */
end_comment

begin_define
define|#
directive|define
name|B_INVAL
value|0x00002000
end_define

begin_comment
comment|/* Does not contain valid info. */
end_comment

begin_define
define|#
directive|define
name|B_BARRIER
value|0x00004000
end_define

begin_comment
comment|/* Write this and all preceding first. */
end_comment

begin_define
define|#
directive|define
name|B_NOCACHE
value|0x00008000
end_define

begin_comment
comment|/* Do not cache block after use. */
end_comment

begin_define
define|#
directive|define
name|B_MALLOC
value|0x00010000
end_define

begin_comment
comment|/* malloced b_data */
end_comment

begin_define
define|#
directive|define
name|B_CLUSTEROK
value|0x00020000
end_define

begin_comment
comment|/* Pagein op, so swap() can count it. */
end_comment

begin_define
define|#
directive|define
name|B_00040000
value|0x00040000
end_define

begin_comment
comment|/* Available flag. */
end_comment

begin_define
define|#
directive|define
name|B_00080000
value|0x00080000
end_define

begin_comment
comment|/* Available flag. */
end_comment

begin_define
define|#
directive|define
name|B_00100000
value|0x00100000
end_define

begin_comment
comment|/* Available flag. */
end_comment

begin_define
define|#
directive|define
name|B_00200000
value|0x00200000
end_define

begin_comment
comment|/* Available flag. */
end_comment

begin_define
define|#
directive|define
name|B_RELBUF
value|0x00400000
end_define

begin_comment
comment|/* Release VMIO buffer. */
end_comment

begin_define
define|#
directive|define
name|B_FS_FLAG1
value|0x00800000
end_define

begin_comment
comment|/* Available flag for FS use. */
end_comment

begin_define
define|#
directive|define
name|B_NOCOPY
value|0x01000000
end_define

begin_comment
comment|/* Don't copy-on-write this buf. */
end_comment

begin_define
define|#
directive|define
name|B_INFREECNT
value|0x02000000
end_define

begin_comment
comment|/* buf is counted in numfreebufs */
end_comment

begin_define
define|#
directive|define
name|B_PAGING
value|0x04000000
end_define

begin_comment
comment|/* volatile paging I/O -- bypass VMIO */
end_comment

begin_define
define|#
directive|define
name|B_MANAGED
value|0x08000000
end_define

begin_comment
comment|/* Managed by FS. */
end_comment

begin_define
define|#
directive|define
name|B_RAM
value|0x10000000
end_define

begin_comment
comment|/* Read ahead mark (flag) */
end_comment

begin_define
define|#
directive|define
name|B_VMIO
value|0x20000000
end_define

begin_comment
comment|/* VMIO flag */
end_comment

begin_define
define|#
directive|define
name|B_CLUSTER
value|0x40000000
end_define

begin_comment
comment|/* pagein op, so swap() can count it */
end_comment

begin_define
define|#
directive|define
name|B_REMFREE
value|0x80000000
end_define

begin_comment
comment|/* Delayed bremfree */
end_comment

begin_define
define|#
directive|define
name|PRINT_BUF_FLAGS
value|"\20\40remfree\37cluster\36vmio\35ram\34managed" \ 	"\33paging\32infreecnt\31nocopy\30b23\27relbuf\26b21\25b20" \ 	"\24b19\23b18\22clusterok\21malloc\20nocache\17b14\16inval" \ 	"\15b12\14noreuse\13eintr\12done\11b8\10delwri" \ 	"\7validsuspwrt\6cache\5deferred\4direct\3async\2needcommit\1age"
end_define

begin_comment
comment|/*  * These flags are kept in b_xflags.  */
end_comment

begin_define
define|#
directive|define
name|BX_VNDIRTY
value|0x00000001
end_define

begin_comment
comment|/* On vnode dirty list */
end_comment

begin_define
define|#
directive|define
name|BX_VNCLEAN
value|0x00000002
end_define

begin_comment
comment|/* On vnode clean list */
end_comment

begin_define
define|#
directive|define
name|BX_BKGRDWRITE
value|0x00000010
end_define

begin_comment
comment|/* Do writes in background */
end_comment

begin_define
define|#
directive|define
name|BX_BKGRDMARKER
value|0x00000020
end_define

begin_comment
comment|/* Mark buffer for splay tree */
end_comment

begin_define
define|#
directive|define
name|BX_ALTDATA
value|0x00000040
end_define

begin_comment
comment|/* Holds extended data */
end_comment

begin_define
define|#
directive|define
name|PRINT_BUF_XFLAGS
value|"\20\7altdata\6bkgrdmarker\5bkgrdwrite\2clean\1dirty"
end_define

begin_define
define|#
directive|define
name|NOOFFSET
value|(-1LL)
end_define

begin_comment
comment|/* No buffer offset calculated yet */
end_comment

begin_comment
comment|/*  * These flags are kept in b_vflags.  */
end_comment

begin_define
define|#
directive|define
name|BV_SCANNED
value|0x00000001
end_define

begin_comment
comment|/* VOP_FSYNC funcs mark written bufs */
end_comment

begin_define
define|#
directive|define
name|BV_BKGRDINPROG
value|0x00000002
end_define

begin_comment
comment|/* Background write in progress */
end_comment

begin_define
define|#
directive|define
name|BV_BKGRDWAIT
value|0x00000004
end_define

begin_comment
comment|/* Background write waiting */
end_comment

begin_define
define|#
directive|define
name|BV_BKGRDERR
value|0x00000008
end_define

begin_comment
comment|/* Error from background write */
end_comment

begin_define
define|#
directive|define
name|PRINT_BUF_VFLAGS
value|"\20\4bkgrderr\3bkgrdwait\2bkgrdinprog\1scanned"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Buffer locking  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|buf_wmesg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default buffer lock message */
end_comment

begin_define
define|#
directive|define
name|BUF_WMESG
value|"bufwait"
end_define

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_comment
comment|/* XXX for curthread */
end_comment

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_comment
comment|/*  * Initialize a lock.  */
end_comment

begin_define
define|#
directive|define
name|BUF_LOCKINIT
parameter_list|(
name|bp
parameter_list|)
define|\
value|lockinit(&(bp)->b_lock, PRIBIO + 4, buf_wmesg, 0, 0)
end_define

begin_comment
comment|/*  *  * Get a lock sleeping non-interruptably until it becomes available.  */
end_comment

begin_define
define|#
directive|define
name|BUF_LOCK
parameter_list|(
name|bp
parameter_list|,
name|locktype
parameter_list|,
name|interlock
parameter_list|)
define|\
value|_lockmgr_args_rw(&(bp)->b_lock, (locktype), (interlock),	\ 	    LK_WMESG_DEFAULT, LK_PRIO_DEFAULT, LK_TIMO_DEFAULT,		\ 	    LOCK_FILE, LOCK_LINE)
end_define

begin_comment
comment|/*  * Get a lock sleeping with specified interruptably and timeout.  */
end_comment

begin_define
define|#
directive|define
name|BUF_TIMELOCK
parameter_list|(
name|bp
parameter_list|,
name|locktype
parameter_list|,
name|interlock
parameter_list|,
name|wmesg
parameter_list|,
name|catch
parameter_list|,
name|timo
parameter_list|)
define|\
value|_lockmgr_args_rw(&(bp)->b_lock, (locktype) | LK_TIMELOCK,	\ 	    (interlock), (wmesg), (PRIBIO + 4) | (catch), (timo),	\ 	    LOCK_FILE, LOCK_LINE)
end_define

begin_comment
comment|/*  * Release a lock. Only the acquiring process may free the lock unless  * it has been handed off to biodone.  */
end_comment

begin_define
define|#
directive|define
name|BUF_UNLOCK
parameter_list|(
name|bp
parameter_list|)
value|do {						\ 	KASSERT(((bp)->b_flags& B_REMFREE) == 0,			\ 	    ("BUF_UNLOCK %p while B_REMFREE is still set.", (bp)));	\ 									\ 	(void)_lockmgr_args(&(bp)->b_lock, LK_RELEASE, NULL,		\ 	    LK_WMESG_DEFAULT, LK_PRIO_DEFAULT, LK_TIMO_DEFAULT,		\ 	    LOCK_FILE, LOCK_LINE);					\ } while (0)
end_define

begin_comment
comment|/*  * Check if a buffer lock is recursed.  */
end_comment

begin_define
define|#
directive|define
name|BUF_LOCKRECURSED
parameter_list|(
name|bp
parameter_list|)
define|\
value|lockmgr_recursed(&(bp)->b_lock)
end_define

begin_comment
comment|/*  * Check if a buffer lock is currently held.  */
end_comment

begin_define
define|#
directive|define
name|BUF_ISLOCKED
parameter_list|(
name|bp
parameter_list|)
define|\
value|lockstatus(&(bp)->b_lock)
end_define

begin_comment
comment|/*  * Free a buffer lock.  */
end_comment

begin_define
define|#
directive|define
name|BUF_LOCKFREE
parameter_list|(
name|bp
parameter_list|)
define|\
value|lockdestroy(&(bp)->b_lock)
end_define

begin_comment
comment|/*  * Print informations on a buffer lock.  */
end_comment

begin_define
define|#
directive|define
name|BUF_LOCKPRINTINFO
parameter_list|(
name|bp
parameter_list|)
define|\
value|lockmgr_printinfo(&(bp)->b_lock)
end_define

begin_comment
comment|/*  * Buffer lock assertions.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|INVARIANTS
argument_list|)
operator|&&
name|defined
argument_list|(
name|INVARIANT_SUPPORT
argument_list|)
end_if

begin_define
define|#
directive|define
name|BUF_ASSERT_LOCKED
parameter_list|(
name|bp
parameter_list|)
define|\
value|_lockmgr_assert(&(bp)->b_lock, KA_LOCKED, LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|BUF_ASSERT_SLOCKED
parameter_list|(
name|bp
parameter_list|)
define|\
value|_lockmgr_assert(&(bp)->b_lock, KA_SLOCKED, LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|BUF_ASSERT_XLOCKED
parameter_list|(
name|bp
parameter_list|)
define|\
value|_lockmgr_assert(&(bp)->b_lock, KA_XLOCKED, LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|BUF_ASSERT_UNLOCKED
parameter_list|(
name|bp
parameter_list|)
define|\
value|_lockmgr_assert(&(bp)->b_lock, KA_UNLOCKED, LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|BUF_ASSERT_HELD
parameter_list|(
name|bp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|BUF_ASSERT_UNHELD
parameter_list|(
name|bp
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BUF_ASSERT_LOCKED
parameter_list|(
name|bp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|BUF_ASSERT_SLOCKED
parameter_list|(
name|bp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|BUF_ASSERT_XLOCKED
parameter_list|(
name|bp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|BUF_ASSERT_UNLOCKED
parameter_list|(
name|bp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|BUF_ASSERT_HELD
parameter_list|(
name|bp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|BUF_ASSERT_UNHELD
parameter_list|(
name|bp
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_PROC_H_
end_ifdef

begin_comment
comment|/* Avoid #include<sys/proc.h> pollution */
end_comment

begin_comment
comment|/*  * When initiating asynchronous I/O, change ownership of the lock to the  * kernel. Once done, the lock may legally released by biodone. The  * original owning process can no longer acquire it recursively, but must  * wait until the I/O is completed and the lock has been freed by biodone.  */
end_comment

begin_define
define|#
directive|define
name|BUF_KERNPROC
parameter_list|(
name|bp
parameter_list|)
define|\
value|_lockmgr_disown(&(bp)->b_lock, LOCK_FILE, LOCK_LINE)
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
comment|/* _KERNEL */
end_comment

begin_struct
struct|struct
name|buf_queue_head
block|{
name|TAILQ_HEAD
argument_list|(
argument|buf_queue
argument_list|,
argument|buf
argument_list|)
name|queue
expr_stmt|;
name|daddr_t
name|last_pblkno
decl_stmt|;
name|struct
name|buf
modifier|*
name|insert_point
decl_stmt|;
name|struct
name|buf
modifier|*
name|switch_point
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This structure describes a clustered I/O.   */
end_comment

begin_struct
struct|struct
name|cluster_save
block|{
name|long
name|bs_bcount
decl_stmt|;
comment|/* Saved b_bcount. */
name|long
name|bs_bufsize
decl_stmt|;
comment|/* Saved b_bufsize. */
name|int
name|bs_nchildren
decl_stmt|;
comment|/* Number of associated buffers. */
name|struct
name|buf
modifier|*
modifier|*
name|bs_children
decl_stmt|;
comment|/* List of associated buffers. */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function
specifier|static
name|__inline
name|int
name|bwrite
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|)
block|{
name|KASSERT
argument_list|(
name|bp
operator|->
name|b_bufobj
operator|!=
name|NULL
argument_list|,
operator|(
literal|"bwrite: no bufobj bp=%p"
operator|,
name|bp
operator|)
argument_list|)
expr_stmt|;
name|KASSERT
argument_list|(
name|bp
operator|->
name|b_bufobj
operator|->
name|bo_ops
operator|!=
name|NULL
argument_list|,
operator|(
literal|"bwrite: no bo_ops bp=%p"
operator|,
name|bp
operator|)
argument_list|)
expr_stmt|;
name|KASSERT
argument_list|(
name|bp
operator|->
name|b_bufobj
operator|->
name|bo_ops
operator|->
name|bop_write
operator|!=
name|NULL
argument_list|,
operator|(
literal|"bwrite: no bop_write bp=%p"
operator|,
name|bp
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|BO_WRITE
argument_list|(
name|bp
operator|->
name|b_bufobj
argument_list|,
name|bp
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bstrategy
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|)
block|{
name|KASSERT
argument_list|(
name|bp
operator|->
name|b_bufobj
operator|!=
name|NULL
argument_list|,
operator|(
literal|"bstrategy: no bufobj bp=%p"
operator|,
name|bp
operator|)
argument_list|)
expr_stmt|;
name|KASSERT
argument_list|(
name|bp
operator|->
name|b_bufobj
operator|->
name|bo_ops
operator|!=
name|NULL
argument_list|,
operator|(
literal|"bstrategy: no bo_ops bp=%p"
operator|,
name|bp
operator|)
argument_list|)
expr_stmt|;
name|KASSERT
argument_list|(
name|bp
operator|->
name|b_bufobj
operator|->
name|bo_ops
operator|->
name|bop_strategy
operator|!=
name|NULL
argument_list|,
operator|(
literal|"bstrategy: no bop_strategy bp=%p"
operator|,
name|bp
operator|)
argument_list|)
expr_stmt|;
name|BO_STRATEGY
argument_list|(
name|bp
operator|->
name|b_bufobj
argument_list|,
name|bp
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|buf_start
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|)
block|{
if|if
condition|(
name|bioops
operator|.
name|io_start
condition|)
call|(
modifier|*
name|bioops
operator|.
name|io_start
call|)
argument_list|(
name|bp
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|buf_complete
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|)
block|{
if|if
condition|(
name|bioops
operator|.
name|io_complete
condition|)
call|(
modifier|*
name|bioops
operator|.
name|io_complete
call|)
argument_list|(
name|bp
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|buf_deallocate
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|)
block|{
if|if
condition|(
name|bioops
operator|.
name|io_deallocate
condition|)
call|(
modifier|*
name|bioops
operator|.
name|io_deallocate
call|)
argument_list|(
name|bp
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|buf_countdeps
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|,
name|int
name|i
parameter_list|)
block|{
if|if
condition|(
name|bioops
operator|.
name|io_countdeps
condition|)
return|return
operator|(
call|(
modifier|*
name|bioops
operator|.
name|io_countdeps
call|)
argument_list|(
name|bp
argument_list|,
name|i
argument_list|)
operator|)
return|;
else|else
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|buf_track
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|,
specifier|const
name|char
modifier|*
name|location
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|FULL_BUF_TRACKING
argument_list|)
name|bp
operator|->
name|b_io_tracking
index|[
name|BUF_TRACKING_ENTRY
argument_list|(
name|bp
operator|->
name|b_io_tcnt
operator|++
argument_list|)
index|]
operator|=
name|location
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|BUF_TRACKING
argument_list|)
name|bp
operator|->
name|b_io_tracking
operator|=
name|location
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * Zero out the buffer's data area.  */
end_comment

begin_define
define|#
directive|define
name|clrbuf
parameter_list|(
name|bp
parameter_list|)
value|{							\ 	bzero((bp)->b_data, (u_int)(bp)->b_bcount);			\ 	(bp)->b_resid = 0;						\ }
end_define

begin_comment
comment|/*  * Flags for getblk's last parameter.  */
end_comment

begin_define
define|#
directive|define
name|GB_LOCK_NOWAIT
value|0x0001
end_define

begin_comment
comment|/* Fail if we block on a buf lock. */
end_comment

begin_define
define|#
directive|define
name|GB_NOCREAT
value|0x0002
end_define

begin_comment
comment|/* Don't create a buf if not found. */
end_comment

begin_define
define|#
directive|define
name|GB_NOWAIT_BD
value|0x0004
end_define

begin_comment
comment|/* Do not wait for bufdaemon. */
end_comment

begin_define
define|#
directive|define
name|GB_UNMAPPED
value|0x0008
end_define

begin_comment
comment|/* Do not mmap buffer pages. */
end_comment

begin_define
define|#
directive|define
name|GB_KVAALLOC
value|0x0010
end_define

begin_comment
comment|/* But allocate KVA. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|nbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The number of buffer headers */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|maxswzone
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Max KVA for swap structures */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|maxbcache
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Max KVA for buffer cache */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|maxbcachebuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Max buffer cache block size */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|runningbufspace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|hibufspace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dirtybufthresh
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bdwriteskip
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dirtybufferflushes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|altbufferflushes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nswbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of swap I/O buffer headers. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cluster_pbuf_freecnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of pbufs for clusters */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|vnode_pbuf_freecnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of pbufs for vnode pager */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|vnode_async_pbuf_freecnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of pbufs for vnode pager, 					     asynchronous reads */
end_comment

begin_decl_stmt
specifier|extern
name|caddr_t
name|unmapped_buf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Data address for unmapped buffers. */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|buf_mapped
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|)
block|{
return|return
operator|(
name|bp
operator|->
name|b_data
operator|!=
name|unmapped_buf
operator|)
return|;
block|}
end_function

begin_function_decl
name|void
name|runningbufwakeup
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|waitrunningbufspace
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|caddr_t
name|kern_vfs_bio_buffer_alloc
parameter_list|(
name|caddr_t
name|v
parameter_list|,
name|long
name|physmem_est
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bufinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bufshutdown
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bdata2bio
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|,
name|struct
name|bio
modifier|*
name|bip
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwillwrite
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|buf_dirty_count_severe
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bremfree
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bremfreef
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX Force bremfree, only for nfs. */
end_comment

begin_define
define|#
directive|define
name|bread
parameter_list|(
name|vp
parameter_list|,
name|blkno
parameter_list|,
name|size
parameter_list|,
name|cred
parameter_list|,
name|bpp
parameter_list|)
define|\
value|breadn_flags(vp, blkno, size, NULL, NULL, 0, cred, 0, bpp)
end_define

begin_define
define|#
directive|define
name|bread_gb
parameter_list|(
name|vp
parameter_list|,
name|blkno
parameter_list|,
name|size
parameter_list|,
name|cred
parameter_list|,
name|gbflags
parameter_list|,
name|bpp
parameter_list|)
define|\
value|breadn_flags(vp, blkno, size, NULL, NULL, 0, cred, \ 		gbflags, bpp)
end_define

begin_define
define|#
directive|define
name|breadn
parameter_list|(
name|vp
parameter_list|,
name|blkno
parameter_list|,
name|size
parameter_list|,
name|rablkno
parameter_list|,
name|rabsize
parameter_list|,
name|cnt
parameter_list|,
name|cred
parameter_list|,
name|bpp
parameter_list|)
define|\
value|breadn_flags(vp, blkno, size, rablkno, rabsize, cnt, cred, 0, bpp)
end_define

begin_function_decl
name|int
name|breadn_flags
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|daddr_t
parameter_list|,
name|int
parameter_list|,
name|daddr_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|buf
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|breada
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|daddr_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bdwrite
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bawrite
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|babarrierwrite
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bbarrierwrite
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bdirty
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bundirty
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bufstrategy
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
end_function_decl

begin_function_decl
name|void
name|brelse
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bqrelse
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfs_bio_awrite
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_drain_busy_pages
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|buf
modifier|*
name|getpbuf
parameter_list|(
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|buf
modifier|*
name|incore
parameter_list|(
name|struct
name|bufobj
modifier|*
parameter_list|,
name|daddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|buf
modifier|*
name|gbincore
parameter_list|(
name|struct
name|bufobj
modifier|*
parameter_list|,
name|daddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|buf
modifier|*
name|getblk
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|daddr_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|buf
modifier|*
name|geteblk
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bufwait
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bufwrite
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bufdone
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bufdone_finish
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bd_speedup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cluster_read
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|u_quad_t
parameter_list|,
name|daddr_t
parameter_list|,
name|long
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|long
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|buf
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cluster_wbuild
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|long
parameter_list|,
name|daddr_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cluster_write
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|buf
modifier|*
parameter_list|,
name|u_quad_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_bio_brelse
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|,
name|int
name|ioflags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_bio_bzero_buf
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|,
name|int
name|base
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_bio_clrbuf
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_bio_set_flags
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|,
name|int
name|ioflags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_bio_set_valid
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|,
name|int
name|base
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_busy_pages
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|,
name|int
name|clear_modify
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_unbusy_pages
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmapbuf
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vunmapbuf
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|relpbuf
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|brelvp
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bgetvp
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pbgetbo
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

begin_function_decl
name|void
name|pbgetvp
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pbrelbo
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pbrelvp
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|allocbuf
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reassignbuf
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|buf
modifier|*
name|trypbuf
parameter_list|(
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwait
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|,
name|u_char
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bdone
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|daddr_t
function_decl|(
name|vbg_get_lblkno_t
function_decl|)
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|vm_ooffset_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|vbg_get_blksize_t
function_decl|)
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|daddr_t
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|vfs_bio_getpages
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|vm_page
modifier|*
modifier|*
name|ma
parameter_list|,
name|int
name|count
parameter_list|,
name|int
modifier|*
name|rbehind
parameter_list|,
name|int
modifier|*
name|rahead
parameter_list|,
name|vbg_get_lblkno_t
name|get_lblkno
parameter_list|,
name|vbg_get_blksize_t
name|get_blksize
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* !_SYS_BUF_H_ */
end_comment

end_unit

