begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	buf.h	4.7	%G%	*/
end_comment

begin_comment
comment|/*  * The header for buffers in the buffer pool and otherwise used  * to describe a block i/o request is given here.  The routines  * which manipulate these things are given in bio.c.  *  * Each buffer in the pool is usually doubly linked into 2 lists:  * hashed into a chain by<dev,blkno> so it can be located in the cache,  * and (usually) on (one of several) queues.  These lists are circular and  * doubly linked for easy removal.  *  * There are currently three queues for buffers:  *	one for buffers which must be kept permanently (super blocks)  * 	one for buffers containing ``useful'' information (the cache)  *	one for buffers containing ``non-useful'' information  *		(and empty buffers, pushed onto the front)  * The latter two queues contain the buffers which are available for  * reallocation, are kept in lru order.  When not on one of these queues,  * the buffers are ``checked out'' to drivers which use the available list  * pointers to keep track of them in their i/o active queues.  */
end_comment

begin_comment
comment|/*  * Bufhd structures used at the head of the hashed buffer queues.  * We only need three words for these, so this abbreviated  * definition saves some space.  */
end_comment

begin_struct
struct|struct
name|bufhd
block|{
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
name|filsys
modifier|*
name|b_filsys
decl_stmt|;
comment|/* superblocks */
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
name|b_blkno
decl_stmt|;
comment|/* block # on device */
name|long
name|b_resid
decl_stmt|;
comment|/* words not transferred after error */
define|#
directive|define
name|b_errcnt
value|b_resid
comment|/* while i/o in progress: # retries */
define|#
directive|define
name|b_pfcent
value|b_resid
comment|/* garbage: don't ask */
name|struct
name|proc
modifier|*
name|b_proc
decl_stmt|;
comment|/* proc doing physical or swap I/O */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BQUEUES
value|3
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|buf
name|buf
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the buffer pool itself */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|buf
name|swbuf
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* swap I/O headers */
end_comment

begin_decl_stmt
specifier|extern
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
specifier|extern
name|struct
name|buf
name|bswlist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of free swap header list */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|buf
modifier|*
name|bclnlist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of cleaned page list */
end_comment

begin_function_decl
name|struct
name|buf
modifier|*
name|alloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|buf
modifier|*
name|baddr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|buf
modifier|*
name|getblk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|buf
modifier|*
name|geteblk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|buf
modifier|*
name|bread
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|buf
modifier|*
name|breada
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|minphys
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NSWBUF
value|48
end_define

begin_comment
comment|/* number of swap I/O headers */
end_comment

begin_comment
comment|/*  * These flags are kept in b_flags.  */
end_comment

begin_define
define|#
directive|define
name|B_WRITE
value|0x00000
end_define

begin_comment
comment|/* non-read pseudo-flag */
end_comment

begin_define
define|#
directive|define
name|B_READ
value|0x00001
end_define

begin_comment
comment|/* read when I/O occurs */
end_comment

begin_define
define|#
directive|define
name|B_DONE
value|0x00002
end_define

begin_comment
comment|/* transaction finished */
end_comment

begin_define
define|#
directive|define
name|B_ERROR
value|0x00004
end_define

begin_comment
comment|/* transaction aborted */
end_comment

begin_define
define|#
directive|define
name|B_BUSY
value|0x00008
end_define

begin_comment
comment|/* not on av_forw/back list */
end_comment

begin_define
define|#
directive|define
name|B_PHYS
value|0x00010
end_define

begin_comment
comment|/* physical IO */
end_comment

begin_define
define|#
directive|define
name|B_XXX
value|0x00020
end_define

begin_comment
comment|/* was B_MAP, alloc UNIBUS on pdp-11 */
end_comment

begin_define
define|#
directive|define
name|B_WANTED
value|0x00040
end_define

begin_comment
comment|/* issue wakeup when BUSY goes off */
end_comment

begin_define
define|#
directive|define
name|B_AGE
value|0x00080
end_define

begin_comment
comment|/* delayed write for correct aging */
end_comment

begin_define
define|#
directive|define
name|B_ASYNC
value|0x00100
end_define

begin_comment
comment|/* don't wait for I/O completion */
end_comment

begin_define
define|#
directive|define
name|B_DELWRI
value|0x00200
end_define

begin_comment
comment|/* write at exit of avail list */
end_comment

begin_define
define|#
directive|define
name|B_TAPE
value|0x00400
end_define

begin_comment
comment|/* this is a magtape (no bdwrite) */
end_comment

begin_define
define|#
directive|define
name|B_UAREA
value|0x00800
end_define

begin_comment
comment|/* add u-area to a swap operation */
end_comment

begin_define
define|#
directive|define
name|B_PAGET
value|0x01000
end_define

begin_comment
comment|/* page in/out of page table space */
end_comment

begin_define
define|#
directive|define
name|B_DIRTY
value|0x02000
end_define

begin_comment
comment|/* dirty page to be pushed out async */
end_comment

begin_define
define|#
directive|define
name|B_PGIN
value|0x04000
end_define

begin_comment
comment|/* pagein op, so swap() can count it */
end_comment

begin_define
define|#
directive|define
name|B_CACHE
value|0x08000
end_define

begin_comment
comment|/* did bread find us in the cache ? */
end_comment

begin_define
define|#
directive|define
name|B_INVAL
value|0x10000
end_define

begin_comment
comment|/* does not contain valid info  */
end_comment

begin_define
define|#
directive|define
name|B_LOCKED
value|0x20000
end_define

begin_comment
comment|/* locked in core (not reusable) */
end_comment

begin_define
define|#
directive|define
name|B_HEAD
value|0x40000
end_define

begin_comment
comment|/* a buffer header, not a buffer */
end_comment

end_unit

