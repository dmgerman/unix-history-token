begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1998, 2000 Marshall Kirk McKusick. All Rights Reserved.  *  * The soft updates code is derived from the appendix of a University  * of Michigan technical report (Gregory R. Ganger and Yale N. Patt,  * "Soft Updates: A Solution to the Metadata Update Problem in File  * Systems", CSE-TR-254-95, August 1995).  *  * Further information about soft updates can be obtained from:  *  *	Marshall Kirk McKusick		http://www.mckusick.com/softdep/  *	1614 Oxford Street		mckusick@mckusick.com  *	Berkeley, CA 94709-1608		+1-510-843-9542  *	USA  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY MARSHALL KIRK MCKUSICK ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL MARSHALL KIRK MCKUSICK BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)softdep.h	9.7 (McKusick) 6/21/00  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/*  * Allocation dependencies are handled with undo/redo on the in-memory  * copy of the data. A particular data dependency is eliminated when  * it is ALLCOMPLETE: that is ATTACHED, DEPCOMPLETE, and COMPLETE.  *   * ATTACHED means that the data is not currently being written to  * disk. UNDONE means that the data has been rolled back to a safe  * state for writing to the disk. When the I/O completes, the data is  * restored to its current form and the state reverts to ATTACHED.  * The data must be locked throughout the rollback, I/O, and roll  * forward so that the rolled back information is never visible to  * user processes. The COMPLETE flag indicates that the item has been  * written. For example, a dependency that requires that an inode be  * written will be marked COMPLETE after the inode has been written  * to disk. The DEPCOMPLETE flag indicates the completion of any other  * dependencies such as the writing of a cylinder group map has been  * completed. A dependency structure may be freed only when both it  * and its dependencies have completed and any rollbacks that are in  * progress have finished as indicated by the set of ALLCOMPLETE flags  * all being set. The two MKDIR flags indicate additional dependencies  * that must be done when creating a new directory. MKDIR_BODY is  * cleared when the directory data block containing the "." and ".."  * entries has been written. MKDIR_PARENT is cleared when the parent  * inode with the increased link count for ".." has been written. When  * both MKDIR flags have been cleared, the DEPCOMPLETE flag is set to  * indicate that the directory dependencies have been completed. The  * writing of the directory inode itself sets the COMPLETE flag which  * then allows the directory entry for the new directory to be written  * to disk. The RMDIR flag marks a dirrem structure as representing  * the removal of a directory rather than a file. When the removal  * dependencies are completed, additional work needs to be done  * (truncation of the "." and ".." entries, an additional decrement  * of the associated inode, and a decrement of the parent inode). The  * DIRCHG flag marks a diradd structure as representing the changing  * of an existing entry rather than the addition of a new one. When  * the update is complete the dirrem associated with the inode for  * the old name must be added to the worklist to do the necessary  * reference count decrement. The GOINGAWAY flag indicates that the  * data structure is frozen from further change until its dependencies  * have been completed and its resources freed after which it will be  * discarded. The IOSTARTED flag prevents multiple calls to the I/O  * start routine from doing multiple rollbacks. The SPACECOUNTED flag  * says that the files space has been accounted to the pending free  * space count. The NEWBLOCK flag marks pagedep structures that have  * just been allocated, so must be claimed by the inode before all  * dependencies are complete. The ONWORKLIST flag shows whether the  * structure is currently linked onto a worklist.  */
end_comment

begin_define
define|#
directive|define
name|ATTACHED
value|0x0001
end_define

begin_define
define|#
directive|define
name|UNDONE
value|0x0002
end_define

begin_define
define|#
directive|define
name|COMPLETE
value|0x0004
end_define

begin_define
define|#
directive|define
name|DEPCOMPLETE
value|0x0008
end_define

begin_define
define|#
directive|define
name|MKDIR_PARENT
value|0x0010
end_define

begin_comment
comment|/* diradd& mkdir only */
end_comment

begin_define
define|#
directive|define
name|MKDIR_BODY
value|0x0020
end_define

begin_comment
comment|/* diradd& mkdir only */
end_comment

begin_define
define|#
directive|define
name|RMDIR
value|0x0040
end_define

begin_comment
comment|/* dirrem only */
end_comment

begin_define
define|#
directive|define
name|DIRCHG
value|0x0080
end_define

begin_comment
comment|/* diradd& dirrem only */
end_comment

begin_define
define|#
directive|define
name|GOINGAWAY
value|0x0100
end_define

begin_comment
comment|/* indirdep only */
end_comment

begin_define
define|#
directive|define
name|IOSTARTED
value|0x0200
end_define

begin_comment
comment|/* inodedep& pagedep only */
end_comment

begin_define
define|#
directive|define
name|SPACECOUNTED
value|0x0400
end_define

begin_comment
comment|/* inodedep only */
end_comment

begin_define
define|#
directive|define
name|NEWBLOCK
value|0x0800
end_define

begin_comment
comment|/* pagedep only */
end_comment

begin_define
define|#
directive|define
name|INPROGRESS
value|0x1000
end_define

begin_comment
comment|/* dirrem, freeblks, freefrag, freefile only */
end_comment

begin_define
define|#
directive|define
name|ONWORKLIST
value|0x8000
end_define

begin_define
define|#
directive|define
name|ALLCOMPLETE
value|(ATTACHED | COMPLETE | DEPCOMPLETE)
end_define

begin_comment
comment|/*  * The workitem queue.  *   * It is sometimes useful and/or necessary to clean up certain dependencies  * in the background rather than during execution of an application process  * or interrupt service routine. To realize this, we append dependency  * structures corresponding to such tasks to a "workitem" queue. In a soft  * updates implementation, most pending workitems should not wait for more  * than a couple of seconds, so the filesystem syncer process awakens once  * per second to process the items on the queue.  */
end_comment

begin_comment
comment|/* LIST_HEAD(workhead, worklist);	-- declared in buf.h */
end_comment

begin_comment
comment|/*  * Each request can be linked onto a work queue through its worklist structure.  * To avoid the need for a pointer to the structure itself, this structure  * MUST be declared FIRST in each type in which it appears! If more than one  * worklist is needed in the structure, then a wk_data field must be added  * and the macros below changed to use it.  */
end_comment

begin_struct
struct|struct
name|worklist
block|{
name|LIST_ENTRY
argument_list|(
argument|worklist
argument_list|)
name|wk_list
expr_stmt|;
comment|/* list of work requests */
name|unsigned
name|short
name|wk_type
decl_stmt|;
comment|/* type of request */
name|unsigned
name|short
name|wk_state
decl_stmt|;
comment|/* state flags */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WK_DATA
parameter_list|(
name|wk
parameter_list|)
value|((void *)(wk))
end_define

begin_define
define|#
directive|define
name|WK_PAGEDEP
parameter_list|(
name|wk
parameter_list|)
value|((struct pagedep *)(wk))
end_define

begin_define
define|#
directive|define
name|WK_INODEDEP
parameter_list|(
name|wk
parameter_list|)
value|((struct inodedep *)(wk))
end_define

begin_define
define|#
directive|define
name|WK_NEWBLK
parameter_list|(
name|wk
parameter_list|)
value|((struct newblk *)(wk))
end_define

begin_define
define|#
directive|define
name|WK_BMSAFEMAP
parameter_list|(
name|wk
parameter_list|)
value|((struct bmsafemap *)(wk))
end_define

begin_define
define|#
directive|define
name|WK_ALLOCDIRECT
parameter_list|(
name|wk
parameter_list|)
value|((struct allocdirect *)(wk))
end_define

begin_define
define|#
directive|define
name|WK_INDIRDEP
parameter_list|(
name|wk
parameter_list|)
value|((struct indirdep *)(wk))
end_define

begin_define
define|#
directive|define
name|WK_ALLOCINDIR
parameter_list|(
name|wk
parameter_list|)
value|((struct allocindir *)(wk))
end_define

begin_define
define|#
directive|define
name|WK_FREEFRAG
parameter_list|(
name|wk
parameter_list|)
value|((struct freefrag *)(wk))
end_define

begin_define
define|#
directive|define
name|WK_FREEBLKS
parameter_list|(
name|wk
parameter_list|)
value|((struct freeblks *)(wk))
end_define

begin_define
define|#
directive|define
name|WK_FREEFILE
parameter_list|(
name|wk
parameter_list|)
value|((struct freefile *)(wk))
end_define

begin_define
define|#
directive|define
name|WK_DIRADD
parameter_list|(
name|wk
parameter_list|)
value|((struct diradd *)(wk))
end_define

begin_define
define|#
directive|define
name|WK_MKDIR
parameter_list|(
name|wk
parameter_list|)
value|((struct mkdir *)(wk))
end_define

begin_define
define|#
directive|define
name|WK_DIRREM
parameter_list|(
name|wk
parameter_list|)
value|((struct dirrem *)(wk))
end_define

begin_define
define|#
directive|define
name|WK_NEWDIRBLK
parameter_list|(
name|wk
parameter_list|)
value|((struct newdirblk *)(wk))
end_define

begin_comment
comment|/*  * Various types of lists  */
end_comment

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|dirremhd
argument_list|,
name|dirrem
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|diraddhd
argument_list|,
name|diradd
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|newblkhd
argument_list|,
name|newblk
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|inodedephd
argument_list|,
name|inodedep
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|allocindirhd
argument_list|,
name|allocindir
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|allocdirecthd
argument_list|,
name|allocdirect
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|allocdirectlst
argument_list|,
name|allocdirect
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * The "pagedep" structure tracks the various dependencies related to  * a particular directory page. If a directory page has any dependencies,  * it will have a pagedep linked to its associated buffer. The  * pd_dirremhd list holds the list of dirrem requests which decrement  * inode reference counts. These requests are processed after the  * directory page with the corresponding zero'ed entries has been  * written. The pd_diraddhd list maintains the list of diradd requests  * which cannot be committed until their corresponding inode has been  * written to disk. Because a directory may have many new entries  * being created, several lists are maintained hashed on bits of the  * offset of the entry into the directory page to keep the lists from  * getting too long. Once a new directory entry has been cleared to  * be written, it is moved to the pd_pendinghd list. After the new  * entry has been written to disk it is removed from the pd_pendinghd  * list, any removed operations are done, and the dependency structure  * is freed.  */
end_comment

begin_define
define|#
directive|define
name|DAHASHSZ
value|6
end_define

begin_define
define|#
directive|define
name|DIRADDHASH
parameter_list|(
name|offset
parameter_list|)
value|(((offset)>> 2) % DAHASHSZ)
end_define

begin_struct
struct|struct
name|pagedep
block|{
name|struct
name|worklist
name|pd_list
decl_stmt|;
comment|/* page buffer */
define|#
directive|define
name|pd_state
value|pd_list.wk_state
comment|/* check for multiple I/O starts */
name|LIST_ENTRY
argument_list|(
argument|pagedep
argument_list|)
name|pd_hash
expr_stmt|;
comment|/* hashed lookup */
name|struct
name|mount
modifier|*
name|pd_mnt
decl_stmt|;
comment|/* associated mount point */
name|ino_t
name|pd_ino
decl_stmt|;
comment|/* associated file */
name|ufs_lbn_t
name|pd_lbn
decl_stmt|;
comment|/* block within file */
name|struct
name|dirremhd
name|pd_dirremhd
decl_stmt|;
comment|/* dirrem's waiting for page */
name|struct
name|diraddhd
name|pd_diraddhd
index|[
name|DAHASHSZ
index|]
decl_stmt|;
comment|/* diradd dir entry updates */
name|struct
name|diraddhd
name|pd_pendinghd
decl_stmt|;
comment|/* directory entries awaiting write */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The "inodedep" structure tracks the set of dependencies associated  * with an inode. One task that it must manage is delayed operations  * (i.e., work requests that must be held until the inodedep's associated  * inode has been written to disk). Getting an inode from its incore   * state to the disk requires two steps to be taken by the filesystem  * in this order: first the inode must be copied to its disk buffer by  * the VOP_UPDATE operation; second the inode's buffer must be written  * to disk. To ensure that both operations have happened in the required  * order, the inodedep maintains two lists. Delayed operations are  * placed on the id_inowait list. When the VOP_UPDATE is done, all  * operations on the id_inowait list are moved to the id_bufwait list.  * When the buffer is written, the items on the id_bufwait list can be  * safely moved to the work queue to be processed. A second task of the  * inodedep structure is to track the status of block allocation within  * the inode.  Each block that is allocated is represented by an  * "allocdirect" structure (see below). It is linked onto the id_newinoupdt  * list until both its contents and its allocation in the cylinder  * group map have been written to disk. Once these dependencies have been  * satisfied, it is removed from the id_newinoupdt list and any followup  * actions such as releasing the previous block or fragment are placed  * on the id_inowait list. When an inode is updated (a VOP_UPDATE is  * done), the "inodedep" structure is linked onto the buffer through  * its worklist. Thus, it will be notified when the buffer is about  * to be written and when it is done. At the update time, all the  * elements on the id_newinoupdt list are moved to the id_inoupdt list  * since those changes are now relevant to the copy of the inode in the  * buffer. Also at update time, the tasks on the id_inowait list are  * moved to the id_bufwait list so that they will be executed when  * the updated inode has been written to disk. When the buffer containing  * the inode is written to disk, any updates listed on the id_inoupdt  * list are rolled back as they are not yet safe. Following the write,  * the changes are once again rolled forward and any actions on the  * id_bufwait list are processed (since those actions are now safe).  * The entries on the id_inoupdt and id_newinoupdt lists must be kept  * sorted by logical block number to speed the calculation of the size  * of the rolled back inode (see explanation in initiate_write_inodeblock).  * When a directory entry is created, it is represented by a diradd.  * The diradd is added to the id_inowait list as it cannot be safely  * written to disk until the inode that it represents is on disk. After  * the inode is written, the id_bufwait list is processed and the diradd  * entries are moved to the id_pendinghd list where they remain until  * the directory block containing the name has been written to disk.  * The purpose of keeping the entries on the id_pendinghd list is so that  * the softdep_fsync function can find and push the inode's directory  * name(s) as part of the fsync operation for that file.  */
end_comment

begin_struct
struct|struct
name|inodedep
block|{
name|struct
name|worklist
name|id_list
decl_stmt|;
comment|/* buffer holding inode block */
define|#
directive|define
name|id_state
value|id_list.wk_state
comment|/* inode dependency state */
name|LIST_ENTRY
argument_list|(
argument|inodedep
argument_list|)
name|id_hash
expr_stmt|;
comment|/* hashed lookup */
name|struct
name|fs
modifier|*
name|id_fs
decl_stmt|;
comment|/* associated filesystem */
name|ino_t
name|id_ino
decl_stmt|;
comment|/* dependent inode */
name|nlink_t
name|id_nlinkdelta
decl_stmt|;
comment|/* saved effective link count */
name|struct
name|dinode
modifier|*
name|id_savedino
decl_stmt|;
comment|/* saved dinode contents */
name|LIST_ENTRY
argument_list|(
argument|inodedep
argument_list|)
name|id_deps
expr_stmt|;
comment|/* bmsafemap's list of inodedep's */
name|struct
name|buf
modifier|*
name|id_buf
decl_stmt|;
comment|/* related bmsafemap (if pending) */
name|off_t
name|id_savedsize
decl_stmt|;
comment|/* file size saved during rollback */
name|struct
name|workhead
name|id_pendinghd
decl_stmt|;
comment|/* entries awaiting directory write */
name|struct
name|workhead
name|id_bufwait
decl_stmt|;
comment|/* operations after inode written */
name|struct
name|workhead
name|id_inowait
decl_stmt|;
comment|/* operations waiting inode update */
name|struct
name|allocdirectlst
name|id_inoupdt
decl_stmt|;
comment|/* updates before inode written */
name|struct
name|allocdirectlst
name|id_newinoupdt
decl_stmt|;
comment|/* updates when inode written */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A "newblk" structure is attached to a bmsafemap structure when a block  * or fragment is allocated from a cylinder group. Its state is set to  * DEPCOMPLETE when its cylinder group map is written. It is consumed by  * an associated allocdirect or allocindir allocation which will attach  * themselves to the bmsafemap structure if the newblk's DEPCOMPLETE flag  * is not set (i.e., its cylinder group map has not been written).  */
end_comment

begin_struct
struct|struct
name|newblk
block|{
name|LIST_ENTRY
argument_list|(
argument|newblk
argument_list|)
name|nb_hash
expr_stmt|;
comment|/* hashed lookup */
name|struct
name|fs
modifier|*
name|nb_fs
decl_stmt|;
comment|/* associated filesystem */
name|ufs_daddr_t
name|nb_newblkno
decl_stmt|;
comment|/* allocated block number */
name|int
name|nb_state
decl_stmt|;
comment|/* state of bitmap dependency */
name|LIST_ENTRY
argument_list|(
argument|newblk
argument_list|)
name|nb_deps
expr_stmt|;
comment|/* bmsafemap's list of newblk's */
name|struct
name|bmsafemap
modifier|*
name|nb_bmsafemap
decl_stmt|;
comment|/* associated bmsafemap */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A "bmsafemap" structure maintains a list of dependency structures  * that depend on the update of a particular cylinder group map.  * It has lists for newblks, allocdirects, allocindirs, and inodedeps.  * It is attached to the buffer of a cylinder group block when any of  * these things are allocated from the cylinder group. It is freed  * after the cylinder group map is written and the state of its  * dependencies are updated with DEPCOMPLETE to indicate that it has  * been processed.  */
end_comment

begin_struct
struct|struct
name|bmsafemap
block|{
name|struct
name|worklist
name|sm_list
decl_stmt|;
comment|/* cylgrp buffer */
name|struct
name|buf
modifier|*
name|sm_buf
decl_stmt|;
comment|/* associated buffer */
name|struct
name|allocdirecthd
name|sm_allocdirecthd
decl_stmt|;
comment|/* allocdirect deps */
name|struct
name|allocindirhd
name|sm_allocindirhd
decl_stmt|;
comment|/* allocindir deps */
name|struct
name|inodedephd
name|sm_inodedephd
decl_stmt|;
comment|/* inodedep deps */
name|struct
name|newblkhd
name|sm_newblkhd
decl_stmt|;
comment|/* newblk deps */
block|}
struct|;
end_struct

begin_comment
comment|/*  * An "allocdirect" structure is attached to an "inodedep" when a new block  * or fragment is allocated and pointed to by the inode described by  * "inodedep". The worklist is linked to the buffer that holds the block.  * When the block is first allocated, it is linked to the bmsafemap  * structure associated with the buffer holding the cylinder group map  * from which it was allocated. When the cylinder group map is written  * to disk, ad_state has the DEPCOMPLETE flag set. When the block itself  * is written, the COMPLETE flag is set. Once both the cylinder group map  * and the data itself have been written, it is safe to write the inode  * that claims the block. If there was a previous fragment that had been  * allocated before the file was increased in size, the old fragment may  * be freed once the inode claiming the new block is written to disk.  * This ad_fragfree request is attached to the id_inowait list of the  * associated inodedep (pointed to by ad_inodedep) for processing after  * the inode is written. When a block is allocated to a directory, an  * fsync of a file whose name is within that block must ensure not only  * that the block containing the file name has been written, but also  * that the on-disk inode references that block. When a new directory  * block is created, we allocate a newdirblk structure which is linked  * to the associated allocdirect (on its ad_newdirblk list). When the  * allocdirect has been satisfied, the newdirblk structure is moved to  * the inodedep id_bufwait list of its directory to await the inode  * being written. When the inode is written, the directory entries are  * fully committed and can be deleted from their pagedep->id_pendinghd  * and inodedep->id_pendinghd lists.  */
end_comment

begin_struct
struct|struct
name|allocdirect
block|{
name|struct
name|worklist
name|ad_list
decl_stmt|;
comment|/* buffer holding block */
define|#
directive|define
name|ad_state
value|ad_list.wk_state
comment|/* block pointer state */
name|TAILQ_ENTRY
argument_list|(
argument|allocdirect
argument_list|)
name|ad_next
expr_stmt|;
comment|/* inodedep's list of allocdirect's */
name|ufs_lbn_t
name|ad_lbn
decl_stmt|;
comment|/* block within file */
name|ufs_daddr_t
name|ad_newblkno
decl_stmt|;
comment|/* new value of block pointer */
name|ufs_daddr_t
name|ad_oldblkno
decl_stmt|;
comment|/* old value of block pointer */
name|long
name|ad_newsize
decl_stmt|;
comment|/* size of new block */
name|long
name|ad_oldsize
decl_stmt|;
comment|/* size of old block */
name|LIST_ENTRY
argument_list|(
argument|allocdirect
argument_list|)
name|ad_deps
expr_stmt|;
comment|/* bmsafemap's list of allocdirect's */
name|struct
name|buf
modifier|*
name|ad_buf
decl_stmt|;
comment|/* cylgrp buffer (if pending) */
name|struct
name|inodedep
modifier|*
name|ad_inodedep
decl_stmt|;
comment|/* associated inodedep */
name|struct
name|freefrag
modifier|*
name|ad_freefrag
decl_stmt|;
comment|/* fragment to be freed (if any) */
name|struct
name|workhead
name|ad_newdirblk
decl_stmt|;
comment|/* dir block to notify when written */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A single "indirdep" structure manages all allocation dependencies for  * pointers in an indirect block. The up-to-date state of the indirect  * block is stored in ir_savedata. The set of pointers that may be safely  * written to the disk is stored in ir_safecopy. The state field is used  * only to track whether the buffer is currently being written (in which  * case it is not safe to update ir_safecopy). Ir_deplisthd contains the  * list of allocindir structures, one for each block that needs to be  * written to disk. Once the block and its bitmap allocation have been  * written the safecopy can be updated to reflect the allocation and the  * allocindir structure freed. If ir_state indicates that an I/O on the  * indirect block is in progress when ir_safecopy is to be updated, the  * update is deferred by placing the allocindir on the ir_donehd list.  * When the I/O on the indirect block completes, the entries on the  * ir_donehd list are processed by updating their corresponding ir_safecopy  * pointers and then freeing the allocindir structure.  */
end_comment

begin_struct
struct|struct
name|indirdep
block|{
name|struct
name|worklist
name|ir_list
decl_stmt|;
comment|/* buffer holding indirect block */
define|#
directive|define
name|ir_state
value|ir_list.wk_state
comment|/* indirect block pointer state */
name|caddr_t
name|ir_saveddata
decl_stmt|;
comment|/* buffer cache contents */
name|struct
name|buf
modifier|*
name|ir_savebp
decl_stmt|;
comment|/* buffer holding safe copy */
name|struct
name|allocindirhd
name|ir_donehd
decl_stmt|;
comment|/* done waiting to update safecopy */
name|struct
name|allocindirhd
name|ir_deplisthd
decl_stmt|;
comment|/* allocindir deps for this block */
block|}
struct|;
end_struct

begin_comment
comment|/*  * An "allocindir" structure is attached to an "indirdep" when a new block  * is allocated and pointed to by the indirect block described by the  * "indirdep". The worklist is linked to the buffer that holds the new block.  * When the block is first allocated, it is linked to the bmsafemap  * structure associated with the buffer holding the cylinder group map  * from which it was allocated. When the cylinder group map is written  * to disk, ai_state has the DEPCOMPLETE flag set. When the block itself  * is written, the COMPLETE flag is set. Once both the cylinder group map  * and the data itself have been written, it is safe to write the entry in  * the indirect block that claims the block; the "allocindir" dependency   * can then be freed as it is no longer applicable.  */
end_comment

begin_struct
struct|struct
name|allocindir
block|{
name|struct
name|worklist
name|ai_list
decl_stmt|;
comment|/* buffer holding indirect block */
define|#
directive|define
name|ai_state
value|ai_list.wk_state
comment|/* indirect block pointer state */
name|LIST_ENTRY
argument_list|(
argument|allocindir
argument_list|)
name|ai_next
expr_stmt|;
comment|/* indirdep's list of allocindir's */
name|int
name|ai_offset
decl_stmt|;
comment|/* pointer offset in indirect block */
name|ufs_daddr_t
name|ai_newblkno
decl_stmt|;
comment|/* new block pointer value */
name|ufs_daddr_t
name|ai_oldblkno
decl_stmt|;
comment|/* old block pointer value */
name|struct
name|freefrag
modifier|*
name|ai_freefrag
decl_stmt|;
comment|/* block to be freed when complete */
name|struct
name|indirdep
modifier|*
name|ai_indirdep
decl_stmt|;
comment|/* address of associated indirdep */
name|LIST_ENTRY
argument_list|(
argument|allocindir
argument_list|)
name|ai_deps
expr_stmt|;
comment|/* bmsafemap's list of allocindir's */
name|struct
name|buf
modifier|*
name|ai_buf
decl_stmt|;
comment|/* cylgrp buffer (if pending) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A "freefrag" structure is attached to an "inodedep" when a previously  * allocated fragment is replaced with a larger fragment, rather than extended.  * The "freefrag" structure is constructed and attached when the replacement  * block is first allocated. It is processed after the inode claiming the  * bigger block that replaces it has been written to disk. Note that the  * ff_state field is is used to store the uid, so may lose data. However,  * the uid is used only in printing an error message, so is not critical.  * Keeping it in a short keeps the data structure down to 32 bytes.  */
end_comment

begin_struct
struct|struct
name|freefrag
block|{
name|struct
name|worklist
name|ff_list
decl_stmt|;
comment|/* id_inowait or delayed worklist */
define|#
directive|define
name|ff_state
value|ff_list.wk_state
comment|/* owning user; should be uid_t */
name|struct
name|vnode
modifier|*
name|ff_devvp
decl_stmt|;
comment|/* filesystem device vnode */
name|struct
name|mount
modifier|*
name|ff_mnt
decl_stmt|;
comment|/* associated mount point */
name|ufs_daddr_t
name|ff_blkno
decl_stmt|;
comment|/* fragment physical block number */
name|long
name|ff_fragsize
decl_stmt|;
comment|/* size of fragment being deleted */
name|ino_t
name|ff_inum
decl_stmt|;
comment|/* owning inode number */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A "freeblks" structure is attached to an "inodedep" when the  * corresponding file's length is reduced to zero. It records all  * the information needed to free the blocks of a file after its  * zero'ed inode has been written to disk.  */
end_comment

begin_struct
struct|struct
name|freeblks
block|{
name|struct
name|worklist
name|fb_list
decl_stmt|;
comment|/* id_inowait or delayed worklist */
name|ino_t
name|fb_previousinum
decl_stmt|;
comment|/* inode of previous owner of blocks */
name|struct
name|vnode
modifier|*
name|fb_devvp
decl_stmt|;
comment|/* filesystem device vnode */
name|struct
name|mount
modifier|*
name|fb_mnt
decl_stmt|;
comment|/* associated mount point */
name|off_t
name|fb_oldsize
decl_stmt|;
comment|/* previous file size */
name|off_t
name|fb_newsize
decl_stmt|;
comment|/* new file size */
name|int
name|fb_chkcnt
decl_stmt|;
comment|/* used to check cnt of blks released */
name|uid_t
name|fb_uid
decl_stmt|;
comment|/* uid of previous owner of blocks */
name|ufs_daddr_t
name|fb_dblks
index|[
name|NDADDR
index|]
decl_stmt|;
comment|/* direct blk ptrs to deallocate */
name|ufs_daddr_t
name|fb_iblks
index|[
name|NIADDR
index|]
decl_stmt|;
comment|/* indirect blk ptrs to deallocate */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A "freefile" structure is attached to an inode when its  * link count is reduced to zero. It marks the inode as free in  * the cylinder group map after the zero'ed inode has been written  * to disk and any associated blocks and fragments have been freed.  */
end_comment

begin_struct
struct|struct
name|freefile
block|{
name|struct
name|worklist
name|fx_list
decl_stmt|;
comment|/* id_inowait or delayed worklist */
name|mode_t
name|fx_mode
decl_stmt|;
comment|/* mode of inode */
name|ino_t
name|fx_oldinum
decl_stmt|;
comment|/* inum of the unlinked file */
name|struct
name|vnode
modifier|*
name|fx_devvp
decl_stmt|;
comment|/* filesystem device vnode */
name|struct
name|mount
modifier|*
name|fx_mnt
decl_stmt|;
comment|/* associated mount point */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A "diradd" structure is linked to an "inodedep" id_inowait list when a  * new directory entry is allocated that references the inode described  * by "inodedep". When the inode itself is written (either the initial  * allocation for new inodes or with the increased link count for  * existing inodes), the COMPLETE flag is set in da_state. If the entry  * is for a newly allocated inode, the "inodedep" structure is associated  * with a bmsafemap which prevents the inode from being written to disk  * until the cylinder group has been updated. Thus the da_state COMPLETE  * flag cannot be set until the inode bitmap dependency has been removed.  * When creating a new file, it is safe to write the directory entry that  * claims the inode once the referenced inode has been written. Since  * writing the inode clears the bitmap dependencies, the DEPCOMPLETE flag  * in the diradd can be set unconditionally when creating a file. When  * creating a directory, there are two additional dependencies described by  * mkdir structures (see their description below). When these dependencies  * are resolved the DEPCOMPLETE flag is set in the diradd structure.  * If there are multiple links created to the same inode, there will be  * a separate diradd structure created for each link. The diradd is  * linked onto the pg_diraddhd list of the pagedep for the directory  * page that contains the entry. When a directory page is written,  * the pg_diraddhd list is traversed to rollback any entries that are  * not yet ready to be written to disk. If a directory entry is being  * changed (by rename) rather than added, the DIRCHG flag is set and  * the da_previous entry points to the entry that will be "removed"  * once the new entry has been committed. During rollback, entries  * with da_previous are replaced with the previous inode number rather  * than zero.  *  * The overlaying of da_pagedep and da_previous is done to keep the  * structure down to 32 bytes in size on a 32-bit machine. If a  * da_previous entry is present, the pointer to its pagedep is available  * in the associated dirrem entry. If the DIRCHG flag is set, the  * da_previous entry is valid; if not set the da_pagedep entry is valid.  * The DIRCHG flag never changes; it is set when the structure is created  * if appropriate and is never cleared.  */
end_comment

begin_struct
struct|struct
name|diradd
block|{
name|struct
name|worklist
name|da_list
decl_stmt|;
comment|/* id_inowait or id_pendinghd list */
define|#
directive|define
name|da_state
value|da_list.wk_state
comment|/* state of the new directory entry */
name|LIST_ENTRY
argument_list|(
argument|diradd
argument_list|)
name|da_pdlist
expr_stmt|;
comment|/* pagedep holding directory block */
name|doff_t
name|da_offset
decl_stmt|;
comment|/* offset of new dir entry in dir blk */
name|ino_t
name|da_newinum
decl_stmt|;
comment|/* inode number for the new dir entry */
union|union
block|{
name|struct
name|dirrem
modifier|*
name|dau_previous
decl_stmt|;
comment|/* entry being replaced in dir change */
name|struct
name|pagedep
modifier|*
name|dau_pagedep
decl_stmt|;
comment|/* pagedep dependency for addition */
block|}
name|da_un
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|da_previous
value|da_un.dau_previous
end_define

begin_define
define|#
directive|define
name|da_pagedep
value|da_un.dau_pagedep
end_define

begin_comment
comment|/*  * Two "mkdir" structures are needed to track the additional dependencies  * associated with creating a new directory entry. Normally a directory  * addition can be committed as soon as the newly referenced inode has been  * written to disk with its increased link count. When a directory is  * created there are two additional dependencies: writing the directory  * data block containing the "." and ".." entries (MKDIR_BODY) and writing  * the parent inode with the increased link count for ".." (MKDIR_PARENT).  * These additional dependencies are tracked by two mkdir structures that  * reference the associated "diradd" structure. When they have completed,  * they set the DEPCOMPLETE flag on the diradd so that it knows that its  * extra dependencies have been completed. The md_state field is used only  * to identify which type of dependency the mkdir structure is tracking.  * It is not used in the mainline code for any purpose other than consistency  * checking. All the mkdir structures in the system are linked together on  * a list. This list is needed so that a diradd can find its associated  * mkdir structures and deallocate them if it is prematurely freed (as for  * example if a mkdir is immediately followed by a rmdir of the same directory).  * Here, the free of the diradd must traverse the list to find the associated  * mkdir structures that reference it. The deletion would be faster if the  * diradd structure were simply augmented to have two pointers that referenced  * the associated mkdir's. However, this would increase the size of the diradd  * structure from 32 to 64-bits to speed a very infrequent operation.  */
end_comment

begin_struct
struct|struct
name|mkdir
block|{
name|struct
name|worklist
name|md_list
decl_stmt|;
comment|/* id_inowait or buffer holding dir */
define|#
directive|define
name|md_state
value|md_list.wk_state
comment|/* type: MKDIR_PARENT or MKDIR_BODY */
name|struct
name|diradd
modifier|*
name|md_diradd
decl_stmt|;
comment|/* associated diradd */
name|struct
name|buf
modifier|*
name|md_buf
decl_stmt|;
comment|/* MKDIR_BODY: buffer holding dir */
name|LIST_ENTRY
argument_list|(
argument|mkdir
argument_list|)
name|md_mkdirs
expr_stmt|;
comment|/* list of all mkdirs */
block|}
struct|;
end_struct

begin_macro
name|LIST_HEAD
argument_list|(
argument|mkdirlist
argument_list|,
argument|mkdir
argument_list|)
end_macro

begin_expr_stmt
name|mkdirlisthd
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * A "dirrem" structure describes an operation to decrement the link  * count on an inode. The dirrem structure is attached to the pg_dirremhd  * list of the pagedep for the directory page that contains the entry.  * It is processed after the directory page with the deleted entry has  * been written to disk.  *  * The overlaying of dm_pagedep and dm_dirinum is done to keep the  * structure down to 32 bytes in size on a 32-bit machine. It works  * because they are never used concurrently.  */
end_comment

begin_struct
struct|struct
name|dirrem
block|{
name|struct
name|worklist
name|dm_list
decl_stmt|;
comment|/* delayed worklist */
define|#
directive|define
name|dm_state
value|dm_list.wk_state
comment|/* state of the old directory entry */
name|LIST_ENTRY
argument_list|(
argument|dirrem
argument_list|)
name|dm_next
expr_stmt|;
comment|/* pagedep's list of dirrem's */
name|struct
name|mount
modifier|*
name|dm_mnt
decl_stmt|;
comment|/* associated mount point */
name|ino_t
name|dm_oldinum
decl_stmt|;
comment|/* inum of the removed dir entry */
union|union
block|{
name|struct
name|pagedep
modifier|*
name|dmu_pagedep
decl_stmt|;
comment|/* pagedep dependency for remove */
name|ino_t
name|dmu_dirinum
decl_stmt|;
comment|/* parent inode number (for rmdir) */
block|}
name|dm_un
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|dm_pagedep
value|dm_un.dmu_pagedep
end_define

begin_define
define|#
directive|define
name|dm_dirinum
value|dm_un.dmu_dirinum
end_define

begin_comment
comment|/*  * A "newdirblk" structure tracks the progress of a newly allocated  * directory block from its creation until it is claimed by its on-disk  * inode. When a block is allocated to a directory, an fsync of a file  * whose name is within that block must ensure not only that the block  * containing the file name has been written, but also that the on-disk  * inode references that block. When a new directory block is created,  * we allocate a newdirblk structure which is linked to the associated  * allocdirect (on its ad_newdirblk list). When the allocdirect has been  * satisfied, the newdirblk structure is moved to the inodedep id_bufwait  * list of its directory to await the inode being written. When the inode  * is written, the directory entries are fully committed and can be  * deleted from their pagedep->id_pendinghd and inodedep->id_pendinghd  * lists. Note that we could track directory blocks allocated to indirect  * blocks using a similar scheme with the allocindir structures. Rather  * than adding this level of complexity, we simply write those newly   * allocated indirect blocks synchronously as such allocations are rare.  */
end_comment

begin_struct
struct|struct
name|newdirblk
block|{
name|struct
name|worklist
name|db_list
decl_stmt|;
comment|/* id_inowait or pg_newdirblk */
define|#
directive|define
name|db_state
value|db_list.wk_state
comment|/* unused */
name|struct
name|pagedep
modifier|*
name|db_pagedep
decl_stmt|;
comment|/* associated pagedep */
block|}
struct|;
end_struct

end_unit

