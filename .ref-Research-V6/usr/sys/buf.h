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
comment|/* headed by devtab of b_dev */
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
name|int
name|b_dev
decl_stmt|;
comment|/* major+minor device name */
name|int
name|b_wcount
decl_stmt|;
comment|/* transfer count (usu. words) */
name|char
modifier|*
name|b_addr
decl_stmt|;
comment|/* low order core address */
name|char
modifier|*
name|b_xmem
decl_stmt|;
comment|/* high order core address */
name|char
modifier|*
name|b_blkno
decl_stmt|;
comment|/* block # on device */
name|char
name|b_error
decl_stmt|;
comment|/* returned after I/O */
name|char
modifier|*
name|b_resid
decl_stmt|;
comment|/* words not transferred after error */
block|}
name|buf
index|[
name|NBUF
index|]
struct|;
end_struct

begin_comment
comment|/*  * Each block device has a devtab, which contains private state stuff  * and 2 list heads: the b_forw/b_back list, which is doubly linked  * and has all the buffers currently associated with that major  * device; and the d_actf/d_actl list, which is private to the  * device but in fact is always used for the head and tail  * of the I/O queue for the device.  * Various routines in bio.c look at b_forw/b_back  * (notice they are the same as in the buf structure)  * but the rest is private to each device driver.  */
end_comment

begin_struct
struct|struct
name|devtab
block|{
name|char
name|d_active
decl_stmt|;
comment|/* busy flag */
name|char
name|d_errcnt
decl_stmt|;
comment|/* error count (for recovery) */
name|struct
name|buf
modifier|*
name|b_forw
decl_stmt|;
comment|/* first buffer for this dev */
name|struct
name|buf
modifier|*
name|b_back
decl_stmt|;
comment|/* last buffer for this dev */
name|struct
name|buf
modifier|*
name|d_actf
decl_stmt|;
comment|/* head of I/O queue */
name|struct
name|buf
modifier|*
name|d_actl
decl_stmt|;
comment|/* tail of I/O queue */
block|}
struct|;
end_struct

begin_comment
comment|/*  * This is the head of the queue of available  * buffers-- all unused except for the 2 list heads.  */
end_comment

begin_decl_stmt
name|struct
name|buf
name|bfreelist
decl_stmt|;
end_decl_stmt

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
name|B_RELOC
value|0200
end_define

begin_comment
comment|/* no longer used */
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

end_unit

