begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)buf.h	8.7 (Berkeley) 1/21/94  * $Id: buf.h,v 1.9 1994/10/10 00:58:31 phk Exp $  */
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

begin_define
define|#
directive|define
name|NOLIST
value|((struct buf *)0x87654321)
end_define

begin_comment
comment|/*  * The buffer header describes an I/O operation in the kernel.  */
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
name|LIST_ENTRY
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
name|struct
name|buf
modifier|*
name|b_actf
decl_stmt|,
modifier|*
modifier|*
name|b_actb
decl_stmt|;
comment|/* Device driver queue when active. */
name|struct
name|proc
modifier|*
name|b_proc
decl_stmt|;
comment|/* Associated proc; NULL if kernel. */
specifier|volatile
name|long
name|b_flags
decl_stmt|;
comment|/* B_* flags. */
name|int
name|b_qindex
decl_stmt|;
comment|/* buffer queue index */
name|int
name|b_error
decl_stmt|;
comment|/* Errno value. */
name|long
name|b_bufsize
decl_stmt|;
comment|/* Allocated buffer size. */
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
struct|struct
block|{
name|caddr_t
name|b_addr
decl_stmt|;
comment|/* Memory, superblocks, indirect etc. */
block|}
name|b_un
struct|;
name|void
modifier|*
name|b_saveaddr
decl_stmt|;
comment|/* Original b_addr for physio. */
name|daddr_t
name|b_lblkno
decl_stmt|;
comment|/* Logical block number. */
name|daddr_t
name|b_blkno
decl_stmt|;
comment|/* Underlying physical block number. */
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
name|struct
name|vnode
modifier|*
name|b_vp
decl_stmt|;
comment|/* Device vnode. */
name|int
name|b_pfcent
decl_stmt|;
comment|/* Center page when swapping cluster. */
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
name|int
name|b_validoff
decl_stmt|;
comment|/* Offset in buffer of valid region. */
name|int
name|b_validend
decl_stmt|;
comment|/* Offset of end of valid region. */
name|daddr_t
name|b_pblkno
decl_stmt|;
comment|/* physical block number */
name|caddr_t
name|b_savekva
decl_stmt|;
comment|/* saved kva for transfer while bouncing */
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
name|b_spc
decl_stmt|;
ifndef|#
directive|ifndef
name|VMIO
name|void
modifier|*
name|b_pages
index|[
operator|(
name|MAXBSIZE
operator|+
name|PAGE_SIZE
operator|-
literal|1
operator|)
operator|/
name|PAGE_SIZE
index|]
decl_stmt|;
else|#
directive|else
name|vm_page_t
name|b_pages
index|[
operator|(
name|MAXBSIZE
operator|+
name|PAGE_SIZE
operator|-
literal|1
operator|)
operator|/
name|PAGE_SIZE
index|]
decl_stmt|;
endif|#
directive|endif
name|int
name|b_npages
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Device driver compatibility definitions. */
end_comment

begin_define
define|#
directive|define
name|b_active
value|b_bcount
end_define

begin_comment
comment|/* Driver queue head: drive active. */
end_comment

begin_define
define|#
directive|define
name|b_data
value|b_un.b_addr
end_define

begin_comment
comment|/* b_un.b_addr is not changeable. */
end_comment

begin_define
define|#
directive|define
name|b_errcnt
value|b_resid
end_define

begin_comment
comment|/* Retry count while I/O in progress. */
end_comment

begin_define
define|#
directive|define
name|iodone
value|biodone
end_define

begin_comment
comment|/* Old name for biodone. */
end_comment

begin_define
define|#
directive|define
name|iowait
value|biowait
end_define

begin_comment
comment|/* Old name for biowait. */
end_comment

begin_comment
comment|/*  * These flags are kept in b_flags.  */
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
name|B_APPENDWRITE
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
name|B_BAD
value|0x00000008
end_define

begin_comment
comment|/* Bad block revectoring in progress. */
end_comment

begin_define
define|#
directive|define
name|B_BUSY
value|0x00000010
end_define

begin_comment
comment|/* I/O in progress. */
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
name|B_DIRTY
value|0x00000100
end_define

begin_comment
comment|/* Dirty page to be pushed out async. */
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
name|B_GATHERED
value|0x00001000
end_define

begin_comment
comment|/* LFS: already in a segment. */
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
name|B_PAGET
value|0x00010000
end_define

begin_comment
comment|/* Page in/out of page table space. */
end_comment

begin_define
define|#
directive|define
name|B_PGIN
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
name|B_TAPE
value|0x00200000
end_define

begin_comment
comment|/* Magnetic tape I/O. */
end_comment

begin_define
define|#
directive|define
name|B_UAREA
value|0x00400000
end_define

begin_comment
comment|/* Buffer describes Uarea I/O. */
end_comment

begin_define
define|#
directive|define
name|B_WANTED
value|0x00800000
end_define

begin_comment
comment|/* Process wants this buffer. */
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
name|B_BOUNCE
value|0x80000000
end_define

begin_comment
comment|/* bounce buffer flag */
end_comment

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

begin_comment
comment|/*   * number of buffer hash entries  */
end_comment

begin_define
define|#
directive|define
name|BUFHSZ
value|512
end_define

begin_comment
comment|/*  * buffer hash table calculation, originally by David Greenman  */
end_comment

begin_define
define|#
directive|define
name|BUFHASH
parameter_list|(
name|vnp
parameter_list|,
name|bn
parameter_list|)
define|\
value|(&bufhashtbl[(((int)(vnp) / sizeof(struct vnode))+(int)(bn)) % BUFHSZ])
end_define

begin_comment
comment|/*  * Definitions for the buffer free lists.  */
end_comment

begin_define
define|#
directive|define
name|BUFFER_QUEUES
value|5
end_define

begin_comment
comment|/* number of free buffer queues */
end_comment

begin_macro
name|LIST_HEAD
argument_list|(
argument|bufhashhdr
argument_list|,
argument|buf
argument_list|)
end_macro

begin_expr_stmt
name|bufhashtbl
index|[
name|BUFHSZ
index|]
operator|,
name|invalhash
expr_stmt|;
end_expr_stmt

begin_macro
name|TAILQ_HEAD
argument_list|(
argument|bqueues
argument_list|,
argument|buf
argument_list|)
end_macro

begin_expr_stmt
name|bufqueues
index|[
name|BUFFER_QUEUES
index|]
expr_stmt|;
end_expr_stmt

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
name|QUEUE_LRU
value|2
end_define

begin_comment
comment|/* useful buffers */
end_comment

begin_define
define|#
directive|define
name|QUEUE_AGE
value|3
end_define

begin_comment
comment|/* less useful buffers */
end_comment

begin_define
define|#
directive|define
name|QUEUE_EMPTY
value|4
end_define

begin_comment
comment|/* empty buffer headers*/
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
value|{							\ 	blkclr((bp)->b_data, (u_int)(bp)->b_bcount);			\ 	(bp)->b_resid = 0;						\ }
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
name|KERNEL
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

begin_decl_stmt
name|__BEGIN_DECLS
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
name|struct
name|buf
modifier|*
name|getnewbuf
name|__P
argument_list|(
operator|(
name|int
name|slpflag
operator|,
name|int
name|slptimeo
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
name|void
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
name|void
name|allocbuf
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
expr|struct
name|buf
operator|*
operator|*
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|minphys
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

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_BUF_H_ */
end_comment

end_unit

