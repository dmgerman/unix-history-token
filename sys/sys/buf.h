begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)buf.h	8.9 (Berkeley) 3/30/95  * $FreeBSD$  */
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
name|mount
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vnode
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
name|void
function_decl|(
modifier|*
name|io_movedeps
function_decl|)
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|,
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

begin_struct
struct|struct
name|buf_ops
block|{
name|char
modifier|*
name|bop_name
decl_stmt|;
name|int
function_decl|(
modifier|*
name|bop_write
function_decl|)
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|buf_ops
name|buf_ops_bio
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The buffer header describes an I/O operation in the kernel.  *  * NOTES:  *	b_bufsize, b_bcount.  b_bufsize is the allocation size of the  *	buffer, either DEV_BSIZE or PAGE_SIZE aligned.  b_bcount is the  *	originally requested buffer size and can serve as a bounds check  *	against EOF.  For most, but not all uses, b_bcount == b_bufsize.  *  *	b_dirtyoff, b_dirtyend.  Buffers support piecemeal, unaligned  *	ranges of dirty data that need to be written to backing store.  *	The range is typically clipped at b_bcount ( not b_bufsize ).  *  *	b_resid.  Number of bytes remaining in I/O.  After an I/O operation  *	completes, b_resid is usually 0 indicating 100% success.  */
end_comment

begin_struct
struct|struct
name|buf
block|{
comment|/* XXX: b_io must be the first element of struct buf for now /phk */
comment|/* XXX: if you change this, fix BIOTOBUF macro below */
name|struct
name|bio
name|b_io
decl_stmt|;
comment|/* "Builtin" I/O request. */
define|#
directive|define
name|BIOTOBUF
parameter_list|(
name|biop
parameter_list|)
value|((struct buf *)(biop))
define|#
directive|define
name|b_bcount
value|b_io.bio_bcount
define|#
directive|define
name|b_blkno
value|b_io.bio_blkno
define|#
directive|define
name|b_caller1
value|b_io.bio_caller1
define|#
directive|define
name|b_data
value|b_io.bio_data
define|#
directive|define
name|b_dev
value|b_io.bio_dev
define|#
directive|define
name|b_driver1
value|b_io.bio_driver1
define|#
directive|define
name|b_driver2
value|b_io.bio_driver2
define|#
directive|define
name|b_error
value|b_io.bio_error
define|#
directive|define
name|b_iocmd
value|b_io.bio_cmd
define|#
directive|define
name|b_ioflags
value|b_io.bio_flags
define|#
directive|define
name|b_pblkno
value|b_io.bio_pblkno
define|#
directive|define
name|b_resid
value|b_io.bio_resid
name|struct
name|buf_ops
modifier|*
name|b_op
decl_stmt|;
name|unsigned
name|b_magic
decl_stmt|;
define|#
directive|define
name|B_MAGIC_BIO
value|0x10b10b10
define|#
directive|define
name|B_MAGIC_NFS
value|0x67238234
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
name|off_t
name|b_offset
decl_stmt|;
comment|/* Offset into file. */
name|LIST_ENTRY
argument_list|(
argument|buf
argument_list|)
name|b_hash
expr_stmt|;
comment|/* Hash chain. */
name|TAILQ_ENTRY
argument_list|(
argument|buf
argument_list|)
name|b_vnbufs
expr_stmt|;
comment|/* Buffer's associated vnode. */
name|TAILQ_ENTRY
argument_list|(
argument|buf
argument_list|)
name|b_freelist
expr_stmt|;
comment|/* Free list position if not active. */
name|TAILQ_ENTRY
argument_list|(
argument|buf
argument_list|)
name|b_act
expr_stmt|;
comment|/* Device driver queue when active. *new* */
name|long
name|b_flags
decl_stmt|;
comment|/* B_* flags. */
name|unsigned
name|short
name|b_qindex
decl_stmt|;
comment|/* buffer queue index */
name|unsigned
name|char
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
name|long
name|b_runningbufspace
decl_stmt|;
comment|/* when I/O is running, pipelining */
name|caddr_t
name|b_kvabase
decl_stmt|;
comment|/* base kva for buffer */
name|int
name|b_kvasize
decl_stmt|;
comment|/* size of kva for buffer */
name|daddr64_t
name|b_lblkno
decl_stmt|;
comment|/* Logical block number. */
name|struct
name|vnode
modifier|*
name|b_vp
decl_stmt|;
comment|/* Device vnode. */
name|int
name|b_dirtyoff
decl_stmt|;
comment|/* Offset in buffer of dirty region. */
name|int
name|b_dirtyend
decl_stmt|;
comment|/* Offset of end of dirty region. */
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
name|void
modifier|*
name|b_saveaddr
decl_stmt|;
comment|/* Original b_addr for physio. */
union|union
name|pager_info
block|{
name|void
modifier|*
name|pg_spc
decl_stmt|;
name|int
name|pg_reqpage
decl_stmt|;
block|}
name|b_pager
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
comment|/* List of filesystem dependencies. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|b_spc
value|b_pager.pg_spc
end_define

begin_comment
comment|/*  * These flags are kept in b_flags.  *  * Notes:  *  *	B_ASYNC		VOP calls on bp's are usually async whether or not  *			B_ASYNC is set, but some subsystems, such as NFS, like   *			to know what is best for the caller so they can  *			optimize the I/O.  *  *	B_PAGING	Indicates that bp is being used by the paging system or  *			some paging system and that the bp is not linked into  *			the b_vp's clean/dirty linked lists or ref counts.  *			Buffer vp reassignments are illegal in this case.  *  *	B_CACHE		This may only be set if the buffer is entirely valid.  *			The situation where B_DELWRI is set and B_CACHE is  *			clear MUST be committed to disk by getblk() so   *			B_DELWRI can also be cleared.  See the comments for  *			getblk() in kern/vfs_bio.c.  If B_CACHE is clear,  *			the caller is expected to clear BIO_ERROR and B_INVAL,  *			set BIO_READ, and initiate an I/O.  *  *			The 'entire buffer' is defined to be the range from  *			0 through b_bcount.  *  *	B_MALLOC	Request that the buffer be allocated from the malloc  *			pool, DEV_BSIZE aligned instead of PAGE_SIZE aligned.  *  *	B_CLUSTEROK	This flag is typically set for B_DELWRI buffers  *			by filesystems that allow clustering when the buffer  *			is fully dirty and indicates that it may be clustered  *			with other adjacent dirty buffers.  Note the clustering  *			may not be used with the stage 1 data write under NFS  *			but may be used for the commit rpc portion.  *  *	B_VMIO		Indicates that the buffer is tied into an VM object.  *			The buffer's data is always PAGE_SIZE aligned even  *			if b_bufsize and b_bcount are not.  ( b_bufsize is   *			always at least DEV_BSIZE aligned, though ).  *  *	B_DIRECT	Hint that we should attempt to completely free  *			the pages underlying the buffer.  B_DIRECT is  *			sticky until the buffer is released and typically  *			only has an effect when B_RELBUF is also set.  *  *	B_NOWDRAIN	This flag should be set when a device (like MD)  *			does a turn-around VOP_WRITE from its strategy  *			routine.  This flag prevents bwrite() from blocking  *			in wdrain, avoiding a deadlock situation.  */
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
name|B_NOWDRAIN
value|0x00000800
end_define

begin_comment
comment|/* Avoid wdrain deadlock */
end_comment

begin_define
define|#
directive|define
name|B_SCANNED
value|0x00001000
end_define

begin_comment
comment|/* VOP_FSYNC funcs mark written bufs */
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
name|B_LOCKED
value|0x00004000
end_define

begin_comment
comment|/* Locked in core (not reusable). */
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
name|B_PHYS
value|0x00040000
end_define

begin_comment
comment|/* I/O to user memory. */
end_comment

begin_define
define|#
directive|define
name|B_RAW
value|0x00080000
end_define

begin_comment
comment|/* Set by physio for raw transfers. */
end_comment

begin_define
define|#
directive|define
name|B_DIRTY
value|0x00200000
end_define

begin_comment
comment|/* Needs writing later. */
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
name|B_WANT
value|0x00800000
end_define

begin_comment
comment|/* Used by vm_pager.c */
end_comment

begin_define
define|#
directive|define
name|B_WRITEINPROG
value|0x01000000
end_define

begin_comment
comment|/* Write in progress. */
end_comment

begin_define
define|#
directive|define
name|B_XXX
value|0x02000000
end_define

begin_comment
comment|/* Debugging flag. */
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
name|B_08000000
value|0x08000000
end_define

begin_comment
comment|/* Available flag. */
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
name|B_80000000
value|0x80000000
end_define

begin_comment
comment|/* Available flag. */
end_comment

begin_define
define|#
directive|define
name|PRINT_BUF_FLAGS
value|"\20\40autochain\37cluster\36vmio\35ram\34ordered" \ 	"\33paging\32xxx\31writeinprog\30want\27relbuf\26dirty" \ 	"\25read\24raw\23phys\22clusterok\21malloc\20nocache" \ 	"\17locked\16inval\15scanned\14error\13eintr\12done\11freebuf" \ 	"\10delwri\7call\6cache\4direct\3async\2needcommit\1age"
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
value|0x00000004
end_define

begin_comment
comment|/* Do writes in background */
end_comment

begin_define
define|#
directive|define
name|BX_BKGRDINPROG
value|0x00000008
end_define

begin_comment
comment|/* Background write in progress */
end_comment

begin_define
define|#
directive|define
name|BX_BKGRDWAIT
value|0x00000010
end_define

begin_comment
comment|/* Background write waiting */
end_comment

begin_define
define|#
directive|define
name|NOOFFSET
value|(-1LL)
end_define

begin_comment
comment|/* No buffer offset calculated yet */
end_comment

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
name|struct
name|mtx
name|buftimelock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Interlock on setting prio and timo */
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

begin_function_decl
specifier|static
name|__inline
name|int
name|BUF_LOCK
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|int
name|BUF_LOCK
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|,
name|int
name|locktype
parameter_list|)
block|{
name|int
name|s
decl_stmt|,
name|ret
decl_stmt|;
name|s
operator|=
name|splbio
argument_list|()
expr_stmt|;
name|mtx_lock
argument_list|(
operator|&
name|buftimelock
argument_list|)
expr_stmt|;
name|locktype
operator||=
name|LK_INTERLOCK
expr_stmt|;
name|bp
operator|->
name|b_lock
operator|.
name|lk_wmesg
operator|=
name|buf_wmesg
expr_stmt|;
name|bp
operator|->
name|b_lock
operator|.
name|lk_prio
operator|=
name|PRIBIO
operator|+
literal|4
expr_stmt|;
name|ret
operator|=
name|lockmgr
argument_list|(
operator|&
operator|(
name|bp
operator|)
operator|->
name|b_lock
argument_list|,
name|locktype
argument_list|,
operator|&
name|buftimelock
argument_list|,
name|curthread
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_comment
comment|/*  * Get a lock sleeping with specified interruptably and timeout.  */
end_comment

begin_function_decl
specifier|static
name|__inline
name|int
name|BUF_TIMELOCK
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|int
name|BUF_TIMELOCK
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|,
name|int
name|locktype
parameter_list|,
name|char
modifier|*
name|wmesg
parameter_list|,
name|int
name|catch
parameter_list|,
name|int
name|timo
parameter_list|)
block|{
name|int
name|s
decl_stmt|,
name|ret
decl_stmt|;
name|s
operator|=
name|splbio
argument_list|()
expr_stmt|;
name|mtx_lock
argument_list|(
operator|&
name|buftimelock
argument_list|)
expr_stmt|;
name|locktype
operator||=
name|LK_INTERLOCK
operator||
name|LK_TIMELOCK
expr_stmt|;
name|bp
operator|->
name|b_lock
operator|.
name|lk_wmesg
operator|=
name|wmesg
expr_stmt|;
name|bp
operator|->
name|b_lock
operator|.
name|lk_prio
operator|=
operator|(
name|PRIBIO
operator|+
literal|4
operator|)
operator||
name|catch
expr_stmt|;
name|bp
operator|->
name|b_lock
operator|.
name|lk_timo
operator|=
name|timo
expr_stmt|;
name|ret
operator|=
name|lockmgr
argument_list|(
operator|&
operator|(
name|bp
operator|)
operator|->
name|b_lock
argument_list|,
operator|(
name|locktype
operator|)
argument_list|,
operator|&
name|buftimelock
argument_list|,
name|curthread
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_comment
comment|/*  * Release a lock. Only the acquiring process may free the lock unless  * it has been handed off to biodone.  */
end_comment

begin_function_decl
specifier|static
name|__inline
name|void
name|BUF_UNLOCK
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|BUF_UNLOCK
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|)
block|{
name|int
name|s
decl_stmt|;
name|s
operator|=
name|splbio
argument_list|()
expr_stmt|;
name|lockmgr
argument_list|(
operator|&
operator|(
name|bp
operator|)
operator|->
name|b_lock
argument_list|,
name|LK_RELEASE
argument_list|,
name|NULL
argument_list|,
name|curthread
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function

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
value|do {						\ 	if (BUF_REFCNT(bp)> 0)			\ 		panic("free locked buf");	\ 	lockdestroy(&(bp)->b_lock);		\ } while (0)
end_define

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

begin_function_decl
specifier|static
name|__inline
name|void
name|BUF_KERNPROC
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|BUF_KERNPROC
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|)
block|{
name|struct
name|thread
modifier|*
name|td
init|=
name|curthread
decl_stmt|;
if|if
condition|(
operator|(
name|td
operator|!=
name|PCPU_GET
argument_list|(
name|idlethread
argument_list|)
operator|)
operator|&&
name|bp
operator|->
name|b_lock
operator|.
name|lk_lockholder
operator|==
name|td
operator|->
name|td_proc
operator|->
name|p_pid
condition|)
name|td
operator|->
name|td_locks
operator|--
expr_stmt|;
name|bp
operator|->
name|b_lock
operator|.
name|lk_lockholder
operator|=
name|LK_KERNPROC
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Find out the number of references to a lock.  */
end_comment

begin_function_decl
specifier|static
name|__inline
name|int
name|BUF_REFCNT
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|int
name|BUF_REFCNT
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|)
block|{
name|int
name|s
decl_stmt|,
name|ret
decl_stmt|;
name|s
operator|=
name|splbio
argument_list|()
expr_stmt|;
name|ret
operator|=
name|lockcount
argument_list|(
operator|&
operator|(
name|bp
operator|)
operator|->
name|b_lock
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

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
name|daddr64_t
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
comment|/*  * This structure describes a clustered I/O.  It is stored in the b_saveaddr  * field of the buffer on which I/O is done.  At I/O completion, cluster  * callback uses the structure to parcel I/O's to individual buffers, and  * then free's this structure.  */
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
name|void
modifier|*
name|bs_saveaddr
decl_stmt|;
comment|/* Saved b_addr. */
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

begin_define
define|#
directive|define
name|BUF_WRITE
parameter_list|(
name|bp
parameter_list|)
define|\
value|(bp)->b_op->bop_write(bp)
end_define

begin_define
define|#
directive|define
name|BUF_STRATEGY
parameter_list|(
name|bp
parameter_list|)
value|VOP_STRATEGY((bp)->b_vp, (bp))
end_define

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
name|BUF_LOCKFREE
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
name|buf_movedeps
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|,
name|struct
name|buf
modifier|*
name|bp2
parameter_list|)
block|{
if|if
condition|(
name|bioops
operator|.
name|io_movedeps
condition|)
call|(
modifier|*
name|bioops
operator|.
name|io_movedeps
call|)
argument_list|(
name|bp
argument_list|,
name|bp2
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
comment|/* Flags to low-level allocation routines. */
end_comment

begin_define
define|#
directive|define
name|B_CLRBUF
value|0x01
end_define

begin_comment
comment|/* Request allocated buffer be cleared. */
end_comment

begin_define
define|#
directive|define
name|B_SYNC
value|0x02
end_define

begin_comment
comment|/* Do all allocations synchronously. */
end_comment

begin_define
define|#
directive|define
name|B_METAONLY
value|0x04
end_define

begin_comment
comment|/* Return indirect block buffer. */
end_comment

begin_define
define|#
directive|define
name|B_NOWAIT
value|0x08
end_define

begin_comment
comment|/* do not sleep to await lock */
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
name|int
name|maxswzone
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Max KVA for swap structures */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|maxbcache
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Max KVA for buffer cache */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|runningbufspace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|buf_maxio
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* nominal maximum I/O for buffer */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|buf
modifier|*
name|buf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The buffer headers. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|buffers
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The buffer contents. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|bufpages
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of memory pages in the buffer pool. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|buf
modifier|*
name|swbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Swap I/O buffer headers. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nswbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of swap I/O buffer headers. */
end_comment

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_function_decl
name|caddr_t
name|kern_vfs_bio_buffer_alloc
parameter_list|(
name|caddr_t
name|v
parameter_list|,
name|int
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
name|int
name|bread
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|daddr_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|ucred
modifier|*
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
name|breadn
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
name|struct
name|buf
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bwrite
parameter_list|(
name|struct
name|buf
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
name|vnode
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
name|vnode
modifier|*
parameter_list|,
name|daddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|inmem
parameter_list|(
name|struct
name|vnode
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
name|bufdonebio
parameter_list|(
name|struct
name|bio
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cluster_callback
parameter_list|(
name|struct
name|buf
modifier|*
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cluster_write
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|,
name|u_quad_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_bio_set_validclean
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
name|void
name|vwakeup
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmapbuf
parameter_list|(
name|struct
name|buf
modifier|*
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
parameter_list|,
name|struct
name|vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pbreassignbuf
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|,
name|struct
name|vnode
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

