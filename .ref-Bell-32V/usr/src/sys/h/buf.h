begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Each buffer in the pool is usually doubly linked into 2 lists:  * the device with which it is currently associated (always)  * and also on a list of blocks available for allocation  * for other use (usually).  * The latter list is kept in last-used order, and the two  * lists are doubly linked to make it easy to remove  * a buffer from one list when it was found by  * looking through the other.  * A buffer is on the available list, and is liable  * to be reassigned to another disk block, if and only  * if it is not marked BUSY.  When a buffer is busy, the  * available-list pointers can be used for other purposes.  * Most drivers use the forward ptr as a link in their I/O  * active queue.  * A buffer header contains all the information required  * to perform I/O.  * Most of the routines which manipulate these things  * are in bio.c.  */
end_comment

begin_struct
struct|struct
name|buf
block|{
name|int
name|b_flags
decl_stmt|;
comment|/* see defines below */
name|struct
name|buf
modifier|*
name|b_forw
decl_stmt|;
comment|/* headed by d_tab of conf.c */
name|struct
name|buf
modifier|*
name|b_back
decl_stmt|;
comment|/*  "  */
name|struct
name|buf
modifier|*
name|av_forw
decl_stmt|;
comment|/* position on free list, */
name|struct
name|buf
modifier|*
name|av_back
decl_stmt|;
comment|/*     if not BUSY*/
name|dev_t
name|b_dev
decl_stmt|;
comment|/* major+minor device name */
name|unsigned
name|b_bcount
decl_stmt|;
comment|/* transfer count */
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
name|char
name|b_xmem
decl_stmt|;
comment|/* high order core address */
name|char
name|b_error
decl_stmt|;
comment|/* returned after I/O */
name|unsigned
name|int
name|b_resid
decl_stmt|;
comment|/* words not transferred after error */
name|struct
name|proc
modifier|*
name|b_proc
decl_stmt|;
comment|/* process doing physical or swap I/O */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|buf
name|buf
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The buffer pool itself */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|buf
name|bfreelist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of available list */
end_comment

begin_comment
comment|/*  * These flags are kept in b_flags.  */
end_comment

begin_define
define|#
directive|define
name|B_WRITE
value|0
end_define

begin_comment
comment|/* non-read pseudo-flag */
end_comment

begin_define
define|#
directive|define
name|B_READ
value|01
end_define

begin_comment
comment|/* read when I/O occurs */
end_comment

begin_define
define|#
directive|define
name|B_DONE
value|02
end_define

begin_comment
comment|/* transaction finished */
end_comment

begin_define
define|#
directive|define
name|B_ERROR
value|04
end_define

begin_comment
comment|/* transaction aborted */
end_comment

begin_define
define|#
directive|define
name|B_BUSY
value|010
end_define

begin_comment
comment|/* not on av_forw/back list */
end_comment

begin_define
define|#
directive|define
name|B_PHYS
value|020
end_define

begin_comment
comment|/* Physical IO potentially using UNIBUS map */
end_comment

begin_define
define|#
directive|define
name|B_MAP
value|040
end_define

begin_comment
comment|/* This block has the UNIBUS map allocated */
end_comment

begin_define
define|#
directive|define
name|B_WANTED
value|0100
end_define

begin_comment
comment|/* issue wakeup when BUSY goes off */
end_comment

begin_define
define|#
directive|define
name|B_AGE
value|0200
end_define

begin_comment
comment|/* delayed write for correct aging */
end_comment

begin_define
define|#
directive|define
name|B_ASYNC
value|0400
end_define

begin_comment
comment|/* don't wait for I/O completion */
end_comment

begin_define
define|#
directive|define
name|B_DELWRI
value|01000
end_define

begin_comment
comment|/* don't write till block leaves available list */
end_comment

begin_define
define|#
directive|define
name|B_UAREA
value|04000
end_define

begin_comment
comment|/* add u-area to a swap operation */
end_comment

begin_define
define|#
directive|define
name|B_TAPE
value|02000
end_define

begin_comment
comment|/* this is a magtape (no bdwrite) */
end_comment

begin_comment
comment|/*  * special redeclarations for  * the head of the queue per  * device driver.  */
end_comment

begin_define
define|#
directive|define
name|b_actf
value|av_forw
end_define

begin_define
define|#
directive|define
name|b_actl
value|av_back
end_define

begin_define
define|#
directive|define
name|b_active
value|b_bcount
end_define

begin_define
define|#
directive|define
name|b_errcnt
value|b_resid
end_define

end_unit

