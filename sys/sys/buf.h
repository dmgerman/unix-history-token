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
argument_list|(
argument|*io_start
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*io_complete
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*io_deallocate
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*io_fsync
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*io_sync
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*io_movedeps
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|,
expr|struct
name|buf
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*io_countdeps
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
block|}
name|bioops
struct|;
end_struct

begin_struct
struct|struct
name|iodone_chain
block|{
name|long
name|ic_prev_flags
decl_stmt|;
name|void
argument_list|(
argument|*ic_prev_iodone
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
modifier|*
name|ic_prev_iodone_chain
decl_stmt|;
struct|struct
block|{
name|long
name|ia_long
decl_stmt|;
name|void
modifier|*
name|ia_ptr
decl_stmt|;
block|}
name|ic_args
index|[
literal|5
index|]
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The buffer header describes an I/O operation in the kernel.  *  * NOTES:  *	b_bufsize, b_bcount.  b_bufsize is the allocation size of the  *	buffer, either DEV_BSIZE or PAGE_SIZE aligned.  b_bcount is the  *	originally requested buffer size and can serve as a bounds check  *	against EOF.  For most, but not all uses, b_bcount == b_bufsize.  *  *	b_dirtyoff, b_dirtyend.  Buffers support piecemeal, unaligned  *	ranges of dirty data that need to be written to backing store.  *	The range is typically clipped at b_bcount ( not b_bufsize ).  *  *	b_resid.  Number of bytes remaining in I/O.  After an I/O operation  *	completes, b_resid is usually 0 indicating 100% success.  */
end_comment

begin_struct
struct|struct
name|buf
block|{
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
name|int
name|b_error
decl_stmt|;
comment|/* Errno value. */
name|long
name|b_bufsize
decl_stmt|;
comment|/* Allocated buffer size. */
name|long
name|b_runningbufspace
decl_stmt|;
comment|/* when I/O is running, pipelining */
name|long
name|b_bcount
decl_stmt|;
comment|/* Valid bytes in buffer. */
name|long
name|b_resid
decl_stmt|;
comment|/* Remaining I/O. */
name|dev_t
name|b_dev
decl_stmt|;
comment|/* Device associated with buffer. */
name|caddr_t
name|b_data
decl_stmt|;
comment|/* Memory, superblocks, indirect etc. */
name|caddr_t
name|b_kvabase
decl_stmt|;
comment|/* base kva for buffer */
name|int
name|b_kvasize
decl_stmt|;
comment|/* size of kva for buffer */
name|daddr_t
name|b_lblkno
decl_stmt|;
comment|/* Logical block number. */
name|daddr_t
name|b_blkno
decl_stmt|;
comment|/* Underlying physical block number. */
name|off_t
name|b_offset
decl_stmt|;
comment|/* Offset into file */
comment|/* Function to call upon completion. */
name|void
argument_list|(
argument|*b_iodone
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* For nested b_iodone's. */
name|struct
name|iodone_chain
modifier|*
name|b_iodone_chain
decl_stmt|;
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
name|daddr_t
name|b_pblkno
decl_stmt|;
comment|/* physical block number */
name|void
modifier|*
name|b_saveaddr
decl_stmt|;
comment|/* Original b_addr for physio. */
name|void
modifier|*
name|b_driver1
decl_stmt|;
comment|/* for private use by the driver */
name|void
modifier|*
name|b_driver2
decl_stmt|;
comment|/* for private use by the driver */
name|void
modifier|*
name|b_caller1
decl_stmt|;
comment|/* for private use by the caller */
name|void
modifier|*
name|b_caller2
decl_stmt|;
comment|/* for private use by the caller */
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
struct|struct
name|chain_info
block|{
comment|/* buffer chaining */
name|struct
name|buf
modifier|*
name|parent
decl_stmt|;
name|int
name|count
decl_stmt|;
block|}
name|b_chain
struct|;
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
comment|/*  * These flags are kept in b_flags.  *  * Notes:  *  *	B_ASYNC		VOP calls on bp's are usually async whether or not  *			B_ASYNC is set, but some subsystems, such as NFS, like   *			to know what is best for the caller so they can  *			optimize the I/O.  *  *	B_PAGING	Indicates that bp is being used by the paging system or  *			some paging system and that the bp is not linked into  *			the b_vp's clean/dirty linked lists or ref counts.  *			Buffer vp reassignments are illegal in this case.  *  *	B_CACHE		This may only be set if the buffer is entirely valid.  *			The situation where B_DELWRI is set and B_CACHE is  *			clear MUST be committed to disk by getblk() so   *			B_DELWRI can also be cleared.  See the comments for  *			getblk() in kern/vfs_bio.c.  If B_CACHE is clear,  *			the caller is expected to clear B_ERROR|B_INVAL,  *			set B_READ, and initiate an I/O.  *  *			The 'entire buffer' is defined to be the range from  *			0 through b_bcount.  *  *	B_MALLOC	Request that the buffer be allocated from the malloc  *			pool, DEV_BSIZE aligned instead of PAGE_SIZE aligned.  *  *	B_CLUSTEROK	This flag is typically set for B_DELWRI buffers  *			by filesystems that allow clustering when the buffer  *			is fully dirty and indicates that it may be clustered  *			with other adjacent dirty buffers.  Note the clustering  *			may not be used with the stage 1 data write under NFS  *			but may be used for the commit rpc portion.  *  *	B_VMIO		Indicates that the buffer is tied into an VM object.  *			The buffer's data is always PAGE_SIZE aligned even  *			if b_bufsize and b_bcount are not.  ( b_bufsize is   *			always at least DEV_BSIZE aligned, though ).  *	  *	B_DIRECT	Hint that we should attempt to completely free  *			the pages underlying the buffer.   B_DIRECT is   *			sticky until the buffer is released and typically  *			only has an effect when B_RELBUF is also set.  */
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
name|B_CALL
value|0x00000040
end_define

begin_comment
comment|/* Call b_iodone from biodone. */
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
name|B_FREEBUF
value|0x00000100
end_define

begin_comment
comment|/* Instruct driver: free blocks */
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
name|B_ERROR
value|0x00000800
end_define

begin_comment
comment|/* I/O error occurred. */
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
name|B_READ
value|0x00100000
end_define

begin_comment
comment|/* Read buffer. */
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
name|B_WRITE
value|0x00000000
end_define

begin_comment
comment|/* Write buffer (pseudo flag). */
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
name|B_ORDERED
value|0x08000000
end_define

begin_comment
comment|/* Must guarantee I/O ordering */
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
name|B_AUTOCHAINDONE
value|0x80000000
end_define

begin_comment
comment|/* Available flag */
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
name|struct
name|simplelock
name|buftimelock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Interlock on setting prio and timo */
end_comment

begin_decl_stmt
specifier|extern
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
comment|/* XXX for curproc */
end_comment

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

begin_decl_stmt
specifier|static
name|__inline
name|int
name|BUF_LOCK
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|simple_lock
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
name|bp
operator|->
name|b_lock
operator|.
name|lk_timo
operator|=
literal|0
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
name|curproc
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

begin_decl_stmt
specifier|static
name|__inline
name|int
name|BUF_TIMELOCK
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|simple_lock
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
name|curproc
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

begin_decl_stmt
specifier|static
name|__inline
name|void
name|BUF_UNLOCK
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|curproc
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
value|if (BUF_REFCNT(bp)> 0)			\ 		panic("free locked buf")
end_define

begin_comment
comment|/*  * When initiating asynchronous I/O, change ownership of the lock to the  * kernel. Once done, the lock may legally released by biodone. The  * original owning process can no longer acquire it recursively, but must  * wait until the I/O is completed and the lock has been freed by biodone.  */
end_comment

begin_decl_stmt
specifier|static
name|__inline
name|void
name|BUF_KERNPROC
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|proc
modifier|*
name|p
init|=
name|curproc
decl_stmt|;
if|if
condition|(
name|p
operator|!=
name|NULL
operator|&&
name|bp
operator|->
name|b_lock
operator|.
name|lk_lockholder
operator|==
name|p
operator|->
name|p_pid
condition|)
name|p
operator|->
name|p_locks
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

begin_comment
comment|/*  * Find out the number of references to a lock.  */
end_comment

begin_decl_stmt
specifier|static
name|__inline
name|int
name|BUF_REFCNT
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|static
name|__inline
name|void
name|bufq_init
name|__P
argument_list|(
operator|(
expr|struct
name|buf_queue_head
operator|*
name|head
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline
name|void
name|bufq_insert_tail
name|__P
argument_list|(
operator|(
expr|struct
name|buf_queue_head
operator|*
name|head
operator|,
expr|struct
name|buf
operator|*
name|bp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline
name|void
name|bufq_remove
name|__P
argument_list|(
operator|(
expr|struct
name|buf_queue_head
operator|*
name|head
operator|,
expr|struct
name|buf
operator|*
name|bp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|buf
operator|*
name|bufq_first
name|__P
argument_list|(
operator|(
expr|struct
name|buf_queue_head
operator|*
name|head
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|__inline
name|void
name|bufq_init
parameter_list|(
name|struct
name|buf_queue_head
modifier|*
name|head
parameter_list|)
block|{
name|TAILQ_INIT
argument_list|(
operator|&
name|head
operator|->
name|queue
argument_list|)
expr_stmt|;
name|head
operator|->
name|last_pblkno
operator|=
literal|0
expr_stmt|;
name|head
operator|->
name|insert_point
operator|=
name|NULL
expr_stmt|;
name|head
operator|->
name|switch_point
operator|=
name|NULL
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bufq_insert_tail
parameter_list|(
name|struct
name|buf_queue_head
modifier|*
name|head
parameter_list|,
name|struct
name|buf
modifier|*
name|bp
parameter_list|)
block|{
if|if
condition|(
operator|(
name|bp
operator|->
name|b_flags
operator|&
name|B_ORDERED
operator|)
operator|!=
literal|0
condition|)
block|{
name|head
operator|->
name|insert_point
operator|=
name|bp
expr_stmt|;
name|head
operator|->
name|switch_point
operator|=
name|NULL
expr_stmt|;
block|}
name|TAILQ_INSERT_TAIL
argument_list|(
operator|&
name|head
operator|->
name|queue
argument_list|,
name|bp
argument_list|,
name|b_act
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bufq_remove
parameter_list|(
name|struct
name|buf_queue_head
modifier|*
name|head
parameter_list|,
name|struct
name|buf
modifier|*
name|bp
parameter_list|)
block|{
if|if
condition|(
name|bp
operator|==
name|head
operator|->
name|switch_point
condition|)
name|head
operator|->
name|switch_point
operator|=
name|TAILQ_NEXT
argument_list|(
name|bp
argument_list|,
name|b_act
argument_list|)
expr_stmt|;
if|if
condition|(
name|bp
operator|==
name|head
operator|->
name|insert_point
condition|)
block|{
name|head
operator|->
name|insert_point
operator|=
name|TAILQ_PREV
argument_list|(
name|bp
argument_list|,
name|buf_queue
argument_list|,
name|b_act
argument_list|)
expr_stmt|;
if|if
condition|(
name|head
operator|->
name|insert_point
operator|==
name|NULL
condition|)
name|head
operator|->
name|last_pblkno
operator|=
literal|0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|bp
operator|==
name|TAILQ_FIRST
argument_list|(
operator|&
name|head
operator|->
name|queue
argument_list|)
condition|)
name|head
operator|->
name|last_pblkno
operator|=
name|bp
operator|->
name|b_pblkno
expr_stmt|;
name|TAILQ_REMOVE
argument_list|(
operator|&
name|head
operator|->
name|queue
argument_list|,
name|bp
argument_list|,
name|b_act
argument_list|)
expr_stmt|;
if|if
condition|(
name|TAILQ_FIRST
argument_list|(
operator|&
name|head
operator|->
name|queue
argument_list|)
operator|==
name|head
operator|->
name|switch_point
condition|)
name|head
operator|->
name|switch_point
operator|=
name|NULL
expr_stmt|;
block|}
end_function

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|buf
operator|*
name|bufq_first
argument_list|(
argument|struct buf_queue_head *head
argument_list|)
block|{
return|return
operator|(
name|TAILQ_FIRST
argument_list|(
operator|&
name|head
operator|->
name|queue
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * Definitions for the buffer free lists.  */
end_comment

begin_define
define|#
directive|define
name|BUFFER_QUEUES
value|6
end_define

begin_comment
comment|/* number of free buffer queues */
end_comment

begin_define
define|#
directive|define
name|QUEUE_NONE
value|0
end_define

begin_comment
comment|/* on no queue */
end_comment

begin_define
define|#
directive|define
name|QUEUE_LOCKED
value|1
end_define

begin_comment
comment|/* locked buffers */
end_comment

begin_define
define|#
directive|define
name|QUEUE_CLEAN
value|2
end_define

begin_comment
comment|/* non-B_DELWRI buffers */
end_comment

begin_define
define|#
directive|define
name|QUEUE_DIRTY
value|3
end_define

begin_comment
comment|/* B_DELWRI buffers */
end_comment

begin_define
define|#
directive|define
name|QUEUE_EMPTYKVA
value|4
end_define

begin_comment
comment|/* empty buffer headers w/KVA assignment */
end_comment

begin_define
define|#
directive|define
name|QUEUE_EMPTY
value|5
end_define

begin_comment
comment|/* empty buffer headers */
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

begin_extern
extern|extern TAILQ_HEAD(swqueue
operator|,
extern|buf
end_extern

begin_expr_stmt
unit|)
name|bswlist
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern TAILQ_HEAD(bqueues
operator|,
extern|buf
end_extern

begin_expr_stmt
unit|)
name|bufqueues
index|[
name|BUFFER_QUEUES
index|]
expr_stmt|;
end_expr_stmt

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_decl_stmt
name|caddr_t
name|bufhashinit
name|__P
argument_list|(
operator|(
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bufinit
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bwillwrite
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
name|buf_dirty_count_severe
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bremfree
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bread
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|,
name|daddr_t
operator|,
name|int
operator|,
expr|struct
name|ucred
operator|*
operator|,
expr|struct
name|buf
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|breadn
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|,
name|daddr_t
operator|,
name|int
operator|,
name|daddr_t
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|,
expr|struct
name|ucred
operator|*
operator|,
expr|struct
name|buf
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bwrite
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bdwrite
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bawrite
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bdirty
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bundirty
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bowrite
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|brelse
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bqrelse
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vfs_bio_awrite
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|buf
modifier|*
name|getpbuf
name|__P
argument_list|(
operator|(
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|buf
modifier|*
name|incore
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|,
name|daddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|buf
modifier|*
name|gbincore
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|,
name|daddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|inmem
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|,
name|daddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|buf
modifier|*
name|getblk
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|,
name|daddr_t
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
name|struct
name|buf
modifier|*
name|geteblk
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
name|biowait
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|biodone
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cluster_callback
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cluster_read
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|,
name|u_quad_t
operator|,
name|daddr_t
operator|,
name|long
operator|,
expr|struct
name|ucred
operator|*
operator|,
name|long
operator|,
name|int
operator|,
expr|struct
name|buf
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cluster_wbuild
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|,
name|long
operator|,
name|daddr_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cluster_write
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|,
name|u_quad_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|physio
name|__P
argument_list|(
operator|(
name|dev_t
name|dev
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|,
name|int
name|ioflag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|physread
value|physio
end_define

begin_define
define|#
directive|define
name|physwrite
value|physio
end_define

begin_decl_stmt
name|void
name|vfs_bio_set_validclean
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|,
name|int
name|base
operator|,
name|int
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vfs_bio_clrbuf
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vfs_busy_pages
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|,
name|int
name|clear_modify
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vfs_unbusy_pages
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vwakeup
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vmapbuf
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vunmapbuf
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|relpbuf
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|brelvp
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bgetvp
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|,
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pbgetvp
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|,
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pbrelvp
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|allocbuf
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
name|bp
operator|,
name|int
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|reassignbuf
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|,
expr|struct
name|vnode
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pbreassignbuf
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|,
expr|struct
name|vnode
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|buf
modifier|*
name|trypbuf
name|__P
argument_list|(
operator|(
name|int
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

