begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)buf.h	7.16 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * The header for buffers in the buffer pool and otherwise used  * to describe a block i/o request is given here.  *  * Each buffer in the pool is usually doubly linked into 2 lists:  * hashed into a chain by<dev,blkno> so it can be located in the cache,  * and (usually) on (one of several) queues.  These lists are circular and  * doubly linked for easy removal.  *  * There are currently three queues for buffers:  *	one for buffers which must be kept permanently (super blocks)  * 	one for buffers containing ``useful'' information (the cache)  *	one for buffers containing ``non-useful'' information  *		(and empty buffers, pushed onto the front)  * The latter two queues contain the buffers which are available for  * reallocation, are kept in lru order.  When not on one of these queues,  * the buffers are ``checked out'' to drivers which use the available list  * pointers to keep track of them in their i/o active queues.  */
end_comment

begin_comment
comment|/*  * Bufhd structures used at the head of the hashed buffer queues.  * We only need three words for these, so this abbreviated  * definition saves some space.  */
end_comment

begin_struct
struct|struct
name|bufhd
block|{
specifier|volatile
name|long
name|b_flags
decl_stmt|;
comment|/* see defines below */
name|struct
name|buf
modifier|*
name|b_forw
decl_stmt|,
modifier|*
name|b_back
decl_stmt|;
comment|/* fwd/bkwd pointer in chain */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|buf
block|{
specifier|volatile
name|long
name|b_flags
decl_stmt|;
comment|/* too much goes here to describe */
name|struct
name|buf
modifier|*
name|b_forw
decl_stmt|,
modifier|*
name|b_back
decl_stmt|;
comment|/* hash chain (2 way street) */
name|struct
name|buf
modifier|*
name|av_forw
decl_stmt|,
modifier|*
name|av_back
decl_stmt|;
comment|/* position on free list if not BUSY */
name|struct
name|buf
modifier|*
name|b_blockf
decl_stmt|,
modifier|*
modifier|*
name|b_blockb
decl_stmt|;
comment|/* associated vnode */
define|#
directive|define
name|b_actf
value|av_forw
comment|/* alternate names for driver queue */
define|#
directive|define
name|b_actl
value|av_back
comment|/*    head - isn't history wonderful */
name|long
name|b_bcount
decl_stmt|;
comment|/* transfer count */
name|long
name|b_bufsize
decl_stmt|;
comment|/* size of allocated buffer */
define|#
directive|define
name|b_active
value|b_bcount
comment|/* driver queue head: drive active */
name|short
name|b_error
decl_stmt|;
comment|/* returned after I/O */
name|dev_t
name|b_dev
decl_stmt|;
comment|/* major+minor device name */
union|union
block|{
name|caddr_t
name|b_addr
decl_stmt|;
comment|/* low order core address */
name|int
modifier|*
name|b_words
decl_stmt|;
comment|/* words for clearing */
name|struct
name|fs
modifier|*
name|b_fs
decl_stmt|;
comment|/* UFS superblocks */
name|struct
name|lfs
modifier|*
name|b_lfs
decl_stmt|;
comment|/* LFS superblocks */
name|struct
name|csum
modifier|*
name|b_cs
decl_stmt|;
comment|/* superblock summary information */
name|struct
name|cg
modifier|*
name|b_cg
decl_stmt|;
comment|/* cylinder group block */
name|struct
name|dinode
modifier|*
name|b_dino
decl_stmt|;
comment|/* ilist */
name|daddr_t
modifier|*
name|b_daddr
decl_stmt|;
comment|/* indirect block */
block|}
name|b_un
union|;
name|daddr_t
name|b_lblkno
decl_stmt|;
comment|/* logical block number */
name|daddr_t
name|b_blkno
decl_stmt|;
comment|/* block # on device */
ifdef|#
directive|ifdef
name|SECSIZE
name|long
name|b_blksize
decl_stmt|;
comment|/* size of device blocks */
endif|#
directive|endif
endif|SECSIZE
name|long
name|b_resid
decl_stmt|;
comment|/* words not transferred after error */
define|#
directive|define
name|b_errcnt
value|b_resid
comment|/* while i/o in progress: # retries */
name|struct
name|proc
modifier|*
name|b_proc
decl_stmt|;
comment|/* proc doing physical or swap I/O */
name|void
function_decl|(
modifier|*
name|b_iodone
function_decl|)
parameter_list|()
function_decl|;
comment|/* function called by iodone */
name|struct
name|vnode
modifier|*
name|b_vp
decl_stmt|;
comment|/* vnode for dev */
name|int
name|b_pfcent
decl_stmt|;
comment|/* center page when swapping cluster */
name|struct
name|ucred
modifier|*
name|b_rcred
decl_stmt|;
comment|/* ref to read credentials */
name|struct
name|ucred
modifier|*
name|b_wcred
decl_stmt|;
comment|/* ref to write credendtials */
name|int
name|b_dirtyoff
decl_stmt|;
comment|/* offset in buffer of dirty region */
name|int
name|b_dirtyend
decl_stmt|;
comment|/* offset of end of dirty region */
name|caddr_t
name|b_saveaddr
decl_stmt|;
comment|/* original b_addr for PHYSIO */
name|int
name|b_validoff
decl_stmt|;
comment|/* offset in buffer of valid region */
name|int
name|b_validend
decl_stmt|;
comment|/* offset of end of valid region */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BQUEUES
value|4
end_define

begin_comment
comment|/* number of free buffer queues */
end_comment

begin_define
define|#
directive|define
name|BQ_LOCKED
value|0
end_define

begin_comment
comment|/* super-blocks&c */
end_comment

begin_define
define|#
directive|define
name|BQ_LRU
value|1
end_define

begin_comment
comment|/* lru, useful buffers */
end_comment

begin_define
define|#
directive|define
name|BQ_AGE
value|2
end_define

begin_comment
comment|/* rubbish */
end_comment

begin_define
define|#
directive|define
name|BQ_EMPTY
value|3
end_define

begin_comment
comment|/* buffer headers with no memory */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SECSIZE
end_ifdef

begin_define
define|#
directive|define
name|BUFHSZ
value|512
end_define

begin_define
define|#
directive|define
name|MINSECSIZE
value|512
end_define

begin_define
define|#
directive|define
name|RND
value|(MAXBSIZE/MINSECSIZE)
end_define

begin_else
else|#
directive|else
else|SECSIZE
end_else

begin_define
define|#
directive|define
name|BUFHSZ
value|512
end_define

begin_define
define|#
directive|define
name|RND
value|(MAXBSIZE/DEV_BSIZE)
end_define

begin_endif
endif|#
directive|endif
endif|SECSIZE
end_endif

begin_if
if|#
directive|if
operator|(
operator|(
name|BUFHSZ
operator|&
operator|(
name|BUFHSZ
operator|-
literal|1
operator|)
operator|)
operator|==
literal|0
operator|)
end_if

begin_define
define|#
directive|define
name|BUFHASH
parameter_list|(
name|dvp
parameter_list|,
name|dblkno
parameter_list|)
define|\
value|((struct buf *)&bufhash[((int)(dvp)+(((int)(dblkno))/RND))&(BUFHSZ-1)])
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BUFHASH
parameter_list|(
name|dvp
parameter_list|,
name|dblkno
parameter_list|)
define|\
value|((struct buf *)&bufhash[((int)(dvp)+(((int)(dblkno))/RND)) % BUFHSZ])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|buf
modifier|*
name|buf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the buffer pool itself */
end_comment

begin_decl_stmt
name|char
modifier|*
name|buffers
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of buffer headers */
end_comment

begin_decl_stmt
name|int
name|bufpages
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of memory pages in the buffer pool */
end_comment

begin_decl_stmt
name|struct
name|buf
modifier|*
name|swbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* swap I/O headers */
end_comment

begin_decl_stmt
name|int
name|nswbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|bufhd
name|bufhash
index|[
name|BUFHSZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* heads of hash lists */
end_comment

begin_decl_stmt
name|struct
name|buf
name|bfreelist
index|[
name|BQUEUES
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* heads of available lists */
end_comment

begin_decl_stmt
name|struct
name|buf
name|bswlist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of free swap header list */
end_comment

begin_decl_stmt
name|struct
name|buf
modifier|*
name|bclnlist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of cleaned page list */
end_comment

begin_decl_stmt
name|__BEGIN_DECLS
name|int
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
name|int
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
name|struct
name|buf
modifier|*
name|getnewbuf
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
name|u_int
name|minphys
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
name|bp
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

begin_comment
comment|/*  * These flags are kept in b_flags.  */
end_comment

begin_define
define|#
directive|define
name|B_WRITE
value|0x000000
end_define

begin_comment
comment|/* non-read pseudo-flag */
end_comment

begin_define
define|#
directive|define
name|B_READ
value|0x000001
end_define

begin_comment
comment|/* read when I/O occurs */
end_comment

begin_define
define|#
directive|define
name|B_DONE
value|0x000002
end_define

begin_comment
comment|/* transaction finished */
end_comment

begin_define
define|#
directive|define
name|B_ERROR
value|0x000004
end_define

begin_comment
comment|/* transaction aborted */
end_comment

begin_define
define|#
directive|define
name|B_BUSY
value|0x000008
end_define

begin_comment
comment|/* not on av_forw/back list */
end_comment

begin_define
define|#
directive|define
name|B_PHYS
value|0x000010
end_define

begin_comment
comment|/* physical IO */
end_comment

begin_define
define|#
directive|define
name|B_XXX
value|0x000020
end_define

begin_comment
comment|/* was B_MAP, alloc UNIBUS on pdp-11 */
end_comment

begin_define
define|#
directive|define
name|B_WANTED
value|0x000040
end_define

begin_comment
comment|/* issue wakeup when BUSY goes off */
end_comment

begin_define
define|#
directive|define
name|B_AGE
value|0x000080
end_define

begin_comment
comment|/* delayed write for correct aging */
end_comment

begin_define
define|#
directive|define
name|B_ASYNC
value|0x000100
end_define

begin_comment
comment|/* don't wait for I/O completion */
end_comment

begin_define
define|#
directive|define
name|B_DELWRI
value|0x000200
end_define

begin_comment
comment|/* write at exit of avail list */
end_comment

begin_define
define|#
directive|define
name|B_TAPE
value|0x000400
end_define

begin_comment
comment|/* this is a magtape (no bdwrite) */
end_comment

begin_define
define|#
directive|define
name|B_UAREA
value|0x000800
end_define

begin_comment
comment|/* add u-area to a swap operation */
end_comment

begin_define
define|#
directive|define
name|B_PAGET
value|0x001000
end_define

begin_comment
comment|/* page in/out of page table space */
end_comment

begin_define
define|#
directive|define
name|B_DIRTY
value|0x002000
end_define

begin_comment
comment|/* dirty page to be pushed out async */
end_comment

begin_define
define|#
directive|define
name|B_PGIN
value|0x004000
end_define

begin_comment
comment|/* pagein op, so swap() can count it */
end_comment

begin_define
define|#
directive|define
name|B_CACHE
value|0x008000
end_define

begin_comment
comment|/* did bread find us in the cache ? */
end_comment

begin_define
define|#
directive|define
name|B_INVAL
value|0x010000
end_define

begin_comment
comment|/* does not contain valid info  */
end_comment

begin_define
define|#
directive|define
name|B_LOCKED
value|0x020000
end_define

begin_comment
comment|/* locked in core (not reusable) */
end_comment

begin_define
define|#
directive|define
name|B_HEAD
value|0x040000
end_define

begin_comment
comment|/* a buffer header, not a buffer */
end_comment

begin_define
define|#
directive|define
name|B_BAD
value|0x100000
end_define

begin_comment
comment|/* bad block revectoring in progress */
end_comment

begin_define
define|#
directive|define
name|B_CALL
value|0x200000
end_define

begin_comment
comment|/* call b_iodone from iodone */
end_comment

begin_define
define|#
directive|define
name|B_RAW
value|0x400000
end_define

begin_comment
comment|/* set by physio for raw transfers */
end_comment

begin_define
define|#
directive|define
name|B_NOCACHE
value|0x800000
end_define

begin_comment
comment|/* do not cache block after use */
end_comment

begin_comment
comment|/*  * Insq/Remq for the buffer hash lists.  */
end_comment

begin_define
define|#
directive|define
name|bremhash
parameter_list|(
name|bp
parameter_list|)
value|{ \ 	(bp)->b_back->b_forw = (bp)->b_forw; \ 	(bp)->b_forw->b_back = (bp)->b_back; \ }
end_define

begin_define
define|#
directive|define
name|binshash
parameter_list|(
name|bp
parameter_list|,
name|dp
parameter_list|)
value|{ \ 	(bp)->b_forw = (dp)->b_forw; \ 	(bp)->b_back = (dp); \ 	(dp)->b_forw->b_back = (bp); \ 	(dp)->b_forw = (bp); \ }
end_define

begin_comment
comment|/*  * Insq/Remq for the buffer free lists.  */
end_comment

begin_define
define|#
directive|define
name|bremfree
parameter_list|(
name|bp
parameter_list|)
value|{ \ 	(bp)->av_back->av_forw = (bp)->av_forw; \ 	(bp)->av_forw->av_back = (bp)->av_back; \ }
end_define

begin_define
define|#
directive|define
name|binsheadfree
parameter_list|(
name|bp
parameter_list|,
name|dp
parameter_list|)
value|{ \ 	(dp)->av_forw->av_back = (bp); \ 	(bp)->av_forw = (dp)->av_forw; \ 	(dp)->av_forw = (bp); \ 	(bp)->av_back = (dp); \ }
end_define

begin_define
define|#
directive|define
name|binstailfree
parameter_list|(
name|bp
parameter_list|,
name|dp
parameter_list|)
value|{ \ 	(dp)->av_back->av_forw = (bp); \ 	(bp)->av_back = (dp)->av_back; \ 	(dp)->av_back = (bp); \ 	(bp)->av_forw = (dp); \ }
end_define

begin_define
define|#
directive|define
name|iodone
value|biodone
end_define

begin_define
define|#
directive|define
name|iowait
value|biowait
end_define

begin_comment
comment|/*  * Zero out a buffer's data portion.  */
end_comment

begin_define
define|#
directive|define
name|clrbuf
parameter_list|(
name|bp
parameter_list|)
value|{ \ 	blkclr((bp)->b_un.b_addr, (unsigned)(bp)->b_bcount); \ 	(bp)->b_resid = 0; \ }
end_define

begin_define
define|#
directive|define
name|B_CLRBUF
value|0x1
end_define

begin_comment
comment|/* request allocated buffer be cleared */
end_comment

begin_define
define|#
directive|define
name|B_SYNC
value|0x2
end_define

begin_comment
comment|/* do all allocations synchronously */
end_comment

end_unit

