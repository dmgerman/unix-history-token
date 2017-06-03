begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 1998, 2000 Marshall Kirk McKusick. All Rights Reserved.  *  * The soft updates code is derived from the appendix of a University  * of Michigan technical report (Gregory R. Ganger and Yale N. Patt,  * "Soft Updates: A Solution to the Metadata Update Problem in File  * Systems", CSE-TR-254-95, August 1995).  *  * Further information about soft updates can be obtained from:  *  *	Marshall Kirk McKusick		http://www.mckusick.com/softdep/  *	1614 Oxford Street		mckusick@mckusick.com  *	Berkeley, CA 94709-1608		+1-510-843-9542  *	USA  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY MARSHALL KIRK MCKUSICK ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL MARSHALL KIRK MCKUSICK BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)softdep.h	9.7 (McKusick) 6/21/00  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/*  * Allocation dependencies are handled with undo/redo on the in-memory  * copy of the data. A particular data dependency is eliminated when  * it is ALLCOMPLETE: that is ATTACHED, DEPCOMPLETE, and COMPLETE.  *   * The ATTACHED flag means that the data is not currently being written  * to disk.  *   * The UNDONE flag means that the data has been rolled back to a safe  * state for writing to the disk. When the I/O completes, the data is  * restored to its current form and the state reverts to ATTACHED.  * The data must be locked throughout the rollback, I/O, and roll  * forward so that the rolled back information is never visible to  * user processes.  *  * The COMPLETE flag indicates that the item has been written. For example,  * a dependency that requires that an inode be written will be marked  * COMPLETE after the inode has been written to disk.  *   * The DEPCOMPLETE flag indicates the completion of any other  * dependencies such as the writing of a cylinder group map has been  * completed. A dependency structure may be freed only when both it  * and its dependencies have completed and any rollbacks that are in  * progress have finished as indicated by the set of ALLCOMPLETE flags  * all being set.  *   * The two MKDIR flags indicate additional dependencies that must be done  * when creating a new directory. MKDIR_BODY is cleared when the directory  * data block containing the "." and ".." entries has been written.  * MKDIR_PARENT is cleared when the parent inode with the increased link  * count for ".." has been written. When both MKDIR flags have been  * cleared, the DEPCOMPLETE flag is set to indicate that the directory  * dependencies have been completed. The writing of the directory inode  * itself sets the COMPLETE flag which then allows the directory entry for  * the new directory to be written to disk. The RMDIR flag marks a dirrem  * structure as representing the removal of a directory rather than a  * file. When the removal dependencies are completed, additional work needs  * to be done* (an additional decrement of the associated inode, and a  * decrement of the parent inode).  *  * The DIRCHG flag marks a diradd structure as representing the changing  * of an existing entry rather than the addition of a new one. When  * the update is complete the dirrem associated with the inode for  * the old name must be added to the worklist to do the necessary  * reference count decrement.  *   * The GOINGAWAY flag indicates that the data structure is frozen from  * further change until its dependencies have been completed and its  * resources freed after which it will be discarded.  *  * The IOSTARTED flag prevents multiple calls to the I/O start routine from  * doing multiple rollbacks.  *  * The NEWBLOCK flag marks pagedep structures that have just been allocated,  * so must be claimed by the inode before all dependencies are complete.  *  * The INPROGRESS flag marks worklist structures that are still on the  * worklist, but are being considered for action by some process.  *  * The UFS1FMT flag indicates that the inode being processed is a ufs1 format.  *  * The EXTDATA flag indicates that the allocdirect describes an  * extended-attributes dependency.  *  * The ONWORKLIST flag shows whether the structure is currently linked  * onto a worklist.  *  * The UNLINK* flags track the progress of updating the on-disk linked  * list of active but unlinked inodes. When an inode is first unlinked  * it is marked as UNLINKED. When its on-disk di_freelink has been  * written its UNLINKNEXT flags is set. When its predecessor in the  * list has its di_freelink pointing at us its UNLINKPREV is set.  * When the on-disk list can reach it from the superblock, its  * UNLINKONLIST flag is set. Once all of these flags are set, it  * is safe to let its last name be removed.  */
end_comment

begin_define
define|#
directive|define
name|ATTACHED
value|0x000001
end_define

begin_define
define|#
directive|define
name|UNDONE
value|0x000002
end_define

begin_define
define|#
directive|define
name|COMPLETE
value|0x000004
end_define

begin_define
define|#
directive|define
name|DEPCOMPLETE
value|0x000008
end_define

begin_define
define|#
directive|define
name|MKDIR_PARENT
value|0x000010
end_define

begin_comment
comment|/* diradd, mkdir, jaddref, jsegdep only */
end_comment

begin_define
define|#
directive|define
name|MKDIR_BODY
value|0x000020
end_define

begin_comment
comment|/* diradd, mkdir, jaddref only */
end_comment

begin_define
define|#
directive|define
name|RMDIR
value|0x000040
end_define

begin_comment
comment|/* dirrem only */
end_comment

begin_define
define|#
directive|define
name|DIRCHG
value|0x000080
end_define

begin_comment
comment|/* diradd, dirrem only */
end_comment

begin_define
define|#
directive|define
name|GOINGAWAY
value|0x000100
end_define

begin_comment
comment|/* indirdep, jremref only */
end_comment

begin_define
define|#
directive|define
name|IOSTARTED
value|0x000200
end_define

begin_comment
comment|/* inodedep, pagedep, bmsafemap only */
end_comment

begin_define
define|#
directive|define
name|DELAYEDFREE
value|0x000400
end_define

begin_comment
comment|/* allocindirect free delayed. */
end_comment

begin_define
define|#
directive|define
name|NEWBLOCK
value|0x000800
end_define

begin_comment
comment|/* pagedep, jaddref only */
end_comment

begin_define
define|#
directive|define
name|INPROGRESS
value|0x001000
end_define

begin_comment
comment|/* dirrem, freeblks, freefrag, freefile only */
end_comment

begin_define
define|#
directive|define
name|UFS1FMT
value|0x002000
end_define

begin_comment
comment|/* indirdep only */
end_comment

begin_define
define|#
directive|define
name|EXTDATA
value|0x004000
end_define

begin_comment
comment|/* allocdirect only */
end_comment

begin_define
define|#
directive|define
name|ONWORKLIST
value|0x008000
end_define

begin_define
define|#
directive|define
name|IOWAITING
value|0x010000
end_define

begin_comment
comment|/* Thread is waiting for IO to complete. */
end_comment

begin_define
define|#
directive|define
name|ONDEPLIST
value|0x020000
end_define

begin_comment
comment|/* Structure is on a dependency list. */
end_comment

begin_define
define|#
directive|define
name|UNLINKED
value|0x040000
end_define

begin_comment
comment|/* inodedep has been unlinked. */
end_comment

begin_define
define|#
directive|define
name|UNLINKNEXT
value|0x080000
end_define

begin_comment
comment|/* inodedep has valid di_freelink */
end_comment

begin_define
define|#
directive|define
name|UNLINKPREV
value|0x100000
end_define

begin_comment
comment|/* inodedep is pointed at in the unlink list */
end_comment

begin_define
define|#
directive|define
name|UNLINKONLIST
value|0x200000
end_define

begin_comment
comment|/* inodedep is in the unlinked list on disk */
end_comment

begin_define
define|#
directive|define
name|UNLINKLINKS
value|(UNLINKNEXT | UNLINKPREV)
end_define

begin_define
define|#
directive|define
name|WRITESUCCEEDED
value|0x400000
end_define

begin_comment
comment|/* the disk write completed successfully */
end_comment

begin_define
define|#
directive|define
name|ALLCOMPLETE
value|(ATTACHED | COMPLETE | DEPCOMPLETE)
end_define

begin_comment
comment|/*  * Values for each of the soft dependency types.  */
end_comment

begin_define
define|#
directive|define
name|D_PAGEDEP
value|0
end_define

begin_define
define|#
directive|define
name|D_INODEDEP
value|1
end_define

begin_define
define|#
directive|define
name|D_BMSAFEMAP
value|2
end_define

begin_define
define|#
directive|define
name|D_NEWBLK
value|3
end_define

begin_define
define|#
directive|define
name|D_ALLOCDIRECT
value|4
end_define

begin_define
define|#
directive|define
name|D_INDIRDEP
value|5
end_define

begin_define
define|#
directive|define
name|D_ALLOCINDIR
value|6
end_define

begin_define
define|#
directive|define
name|D_FREEFRAG
value|7
end_define

begin_define
define|#
directive|define
name|D_FREEBLKS
value|8
end_define

begin_define
define|#
directive|define
name|D_FREEFILE
value|9
end_define

begin_define
define|#
directive|define
name|D_DIRADD
value|10
end_define

begin_define
define|#
directive|define
name|D_MKDIR
value|11
end_define

begin_define
define|#
directive|define
name|D_DIRREM
value|12
end_define

begin_define
define|#
directive|define
name|D_NEWDIRBLK
value|13
end_define

begin_define
define|#
directive|define
name|D_FREEWORK
value|14
end_define

begin_define
define|#
directive|define
name|D_FREEDEP
value|15
end_define

begin_define
define|#
directive|define
name|D_JADDREF
value|16
end_define

begin_define
define|#
directive|define
name|D_JREMREF
value|17
end_define

begin_define
define|#
directive|define
name|D_JMVREF
value|18
end_define

begin_define
define|#
directive|define
name|D_JNEWBLK
value|19
end_define

begin_define
define|#
directive|define
name|D_JFREEBLK
value|20
end_define

begin_define
define|#
directive|define
name|D_JFREEFRAG
value|21
end_define

begin_define
define|#
directive|define
name|D_JSEG
value|22
end_define

begin_define
define|#
directive|define
name|D_JSEGDEP
value|23
end_define

begin_define
define|#
directive|define
name|D_SBDEP
value|24
end_define

begin_define
define|#
directive|define
name|D_JTRUNC
value|25
end_define

begin_define
define|#
directive|define
name|D_JFSYNC
value|26
end_define

begin_define
define|#
directive|define
name|D_SENTINEL
value|27
end_define

begin_define
define|#
directive|define
name|D_LAST
value|D_SENTINEL
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
name|struct
name|mount
modifier|*
name|wk_mp
decl_stmt|;
comment|/* Mount we live in */
name|unsigned
name|int
name|wk_type
range|:
literal|8
decl_stmt|,
comment|/* type of request */
name|wk_state
range|:
literal|24
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
name|WK_BMSAFEMAP
parameter_list|(
name|wk
parameter_list|)
value|((struct bmsafemap *)(wk))
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
name|WK_FREEWORK
parameter_list|(
name|wk
parameter_list|)
value|((struct freework *)(wk))
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

begin_define
define|#
directive|define
name|WK_JADDREF
parameter_list|(
name|wk
parameter_list|)
value|((struct jaddref *)(wk))
end_define

begin_define
define|#
directive|define
name|WK_JREMREF
parameter_list|(
name|wk
parameter_list|)
value|((struct jremref *)(wk))
end_define

begin_define
define|#
directive|define
name|WK_JMVREF
parameter_list|(
name|wk
parameter_list|)
value|((struct jmvref *)(wk))
end_define

begin_define
define|#
directive|define
name|WK_JSEGDEP
parameter_list|(
name|wk
parameter_list|)
value|((struct jsegdep *)(wk))
end_define

begin_define
define|#
directive|define
name|WK_JSEG
parameter_list|(
name|wk
parameter_list|)
value|((struct jseg *)(wk))
end_define

begin_define
define|#
directive|define
name|WK_JNEWBLK
parameter_list|(
name|wk
parameter_list|)
value|((struct jnewblk *)(wk))
end_define

begin_define
define|#
directive|define
name|WK_JFREEBLK
parameter_list|(
name|wk
parameter_list|)
value|((struct jfreeblk *)(wk))
end_define

begin_define
define|#
directive|define
name|WK_FREEDEP
parameter_list|(
name|wk
parameter_list|)
value|((struct freedep *)(wk))
end_define

begin_define
define|#
directive|define
name|WK_JFREEFRAG
parameter_list|(
name|wk
parameter_list|)
value|((struct jfreefrag *)(wk))
end_define

begin_define
define|#
directive|define
name|WK_SBDEP
parameter_list|(
name|wk
parameter_list|)
value|((struct sbdep *)(wk))
end_define

begin_define
define|#
directive|define
name|WK_JTRUNC
parameter_list|(
name|wk
parameter_list|)
value|((struct jtrunc *)(wk))
end_define

begin_define
define|#
directive|define
name|WK_JFSYNC
parameter_list|(
name|wk
parameter_list|)
value|((struct jfsync *)(wk))
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

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|indirdephd
argument_list|,
name|indirdep
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|jaddrefhd
argument_list|,
name|jaddref
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|jremrefhd
argument_list|,
name|jremref
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|jmvrefhd
argument_list|,
name|jmvref
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|jnewblkhd
argument_list|,
name|jnewblk
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|jblkdephd
argument_list|,
name|jblkdep
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|freeworkhd
argument_list|,
name|freework
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|freeworklst
argument_list|,
name|freework
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|jseglst
argument_list|,
name|jseg
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|inoreflst
argument_list|,
name|inoref
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|freeblklst
argument_list|,
name|freeblks
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
value|5
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
name|ino_t
name|pd_ino
decl_stmt|;
comment|/* associated file */
name|ufs_lbn_t
name|pd_lbn
decl_stmt|;
comment|/* block within file */
name|struct
name|newdirblk
modifier|*
name|pd_newdirblk
decl_stmt|;
comment|/* associated newdirblk if NEWBLOCK */
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
name|struct
name|jmvrefhd
name|pd_jmvrefhd
decl_stmt|;
comment|/* Dependent journal writes. */
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
name|TAILQ_ENTRY
argument_list|(
argument|inodedep
argument_list|)
name|id_unlinked
expr_stmt|;
comment|/* Unlinked but ref'd inodes */
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
name|nlink_t
name|id_savednlink
decl_stmt|;
comment|/* Link saved during rollback */
name|LIST_ENTRY
argument_list|(
argument|inodedep
argument_list|)
name|id_deps
expr_stmt|;
comment|/* bmsafemap's list of inodedep's */
name|struct
name|bmsafemap
modifier|*
name|id_bmsafemap
decl_stmt|;
comment|/* related bmsafemap (if pending) */
name|struct
name|diradd
modifier|*
name|id_mkdiradd
decl_stmt|;
comment|/* diradd for a mkdir. */
name|struct
name|inoreflst
name|id_inoreflst
decl_stmt|;
comment|/* Inode reference adjustments. */
name|long
name|id_savedextsize
decl_stmt|;
comment|/* ext size saved during rollback */
name|off_t
name|id_savedsize
decl_stmt|;
comment|/* file size saved during rollback */
name|struct
name|dirremhd
name|id_dirremhd
decl_stmt|;
comment|/* Removals pending. */
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
name|struct
name|allocdirectlst
name|id_extupdt
decl_stmt|;
comment|/* extdata updates pre-inode write */
name|struct
name|allocdirectlst
name|id_newextupdt
decl_stmt|;
comment|/* extdata updates at ino write */
name|struct
name|freeblklst
name|id_freeblklst
decl_stmt|;
comment|/* List of partial truncates. */
union|union
block|{
name|struct
name|ufs1_dinode
modifier|*
name|idu_savedino1
decl_stmt|;
comment|/* saved ufs1_dinode contents */
name|struct
name|ufs2_dinode
modifier|*
name|idu_savedino2
decl_stmt|;
comment|/* saved ufs2_dinode contents */
block|}
name|id_un
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|id_savedino1
value|id_un.idu_savedino1
end_define

begin_define
define|#
directive|define
name|id_savedino2
value|id_un.idu_savedino2
end_define

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
define|#
directive|define
name|sm_state
value|sm_list.wk_state
name|LIST_ENTRY
argument_list|(
argument|bmsafemap
argument_list|)
name|sm_hash
expr_stmt|;
comment|/* Hash links. */
name|LIST_ENTRY
argument_list|(
argument|bmsafemap
argument_list|)
name|sm_next
expr_stmt|;
comment|/* Mount list. */
name|int
name|sm_cg
decl_stmt|;
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
name|allocdirecthd
name|sm_allocdirectwr
decl_stmt|;
comment|/* writing allocdirect deps */
name|struct
name|allocindirhd
name|sm_allocindirhd
decl_stmt|;
comment|/* allocindir deps */
name|struct
name|allocindirhd
name|sm_allocindirwr
decl_stmt|;
comment|/* writing allocindir deps */
name|struct
name|inodedephd
name|sm_inodedephd
decl_stmt|;
comment|/* inodedep deps */
name|struct
name|inodedephd
name|sm_inodedepwr
decl_stmt|;
comment|/* writing inodedep deps */
name|struct
name|newblkhd
name|sm_newblkhd
decl_stmt|;
comment|/* newblk deps */
name|struct
name|newblkhd
name|sm_newblkwr
decl_stmt|;
comment|/* writing newblk deps */
name|struct
name|jaddrefhd
name|sm_jaddrefhd
decl_stmt|;
comment|/* Pending inode allocations. */
name|struct
name|jnewblkhd
name|sm_jnewblkhd
decl_stmt|;
comment|/* Pending block allocations. */
name|struct
name|workhead
name|sm_freehd
decl_stmt|;
comment|/* Freedep deps. */
name|struct
name|workhead
name|sm_freewr
decl_stmt|;
comment|/* Written freedeps. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A "newblk" structure is attached to a bmsafemap structure when a block  * or fragment is allocated from a cylinder group. Its state is set to  * DEPCOMPLETE when its cylinder group map is written. It is converted to  * an allocdirect or allocindir allocation once the allocator calls the  * appropriate setup function. It will initially be linked onto a bmsafemap  * list. Once converted it can be linked onto the lists described for  * allocdirect or allocindir as described below.  */
end_comment

begin_struct
struct|struct
name|newblk
block|{
name|struct
name|worklist
name|nb_list
decl_stmt|;
comment|/* See comment above. */
define|#
directive|define
name|nb_state
value|nb_list.wk_state
name|LIST_ENTRY
argument_list|(
argument|newblk
argument_list|)
name|nb_hash
expr_stmt|;
comment|/* Hashed lookup. */
name|LIST_ENTRY
argument_list|(
argument|newblk
argument_list|)
name|nb_deps
expr_stmt|;
comment|/* Bmsafemap's list of newblks. */
name|struct
name|jnewblk
modifier|*
name|nb_jnewblk
decl_stmt|;
comment|/* New block journal entry. */
name|struct
name|bmsafemap
modifier|*
name|nb_bmsafemap
decl_stmt|;
comment|/* Cylgrp dep (if pending). */
name|struct
name|freefrag
modifier|*
name|nb_freefrag
decl_stmt|;
comment|/* Fragment to be freed (if any). */
name|struct
name|indirdephd
name|nb_indirdeps
decl_stmt|;
comment|/* Children indirect blocks. */
name|struct
name|workhead
name|nb_newdirblk
decl_stmt|;
comment|/* Dir block to notify when written. */
name|struct
name|workhead
name|nb_jwork
decl_stmt|;
comment|/* Journal work pending. */
name|ufs2_daddr_t
name|nb_newblkno
decl_stmt|;
comment|/* New value of block pointer. */
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
name|newblk
name|ad_block
decl_stmt|;
comment|/* Common block logic */
define|#
directive|define
name|ad_list
value|ad_block.nb_list
comment|/* block pointer worklist */
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
name|struct
name|inodedep
modifier|*
name|ad_inodedep
decl_stmt|;
comment|/* associated inodedep */
name|ufs2_daddr_t
name|ad_oldblkno
decl_stmt|;
comment|/* old value of block pointer */
name|int
name|ad_offset
decl_stmt|;
comment|/* Pointer offset in parent. */
name|long
name|ad_newsize
decl_stmt|;
comment|/* size of new block */
name|long
name|ad_oldsize
decl_stmt|;
comment|/* size of old block */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ad_newblkno
value|ad_block.nb_newblkno
end_define

begin_define
define|#
directive|define
name|ad_freefrag
value|ad_block.nb_freefrag
end_define

begin_define
define|#
directive|define
name|ad_newdirblk
value|ad_block.nb_newdirblk
end_define

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
name|LIST_ENTRY
argument_list|(
argument|indirdep
argument_list|)
name|ir_next
expr_stmt|;
comment|/* alloc{direct,indir} list */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|freework
argument_list|)
name|ir_trunc
expr_stmt|;
comment|/* List of truncations. */
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
name|buf
modifier|*
name|ir_bp
decl_stmt|;
comment|/* buffer holding live copy */
name|struct
name|allocindirhd
name|ir_completehd
decl_stmt|;
comment|/* waiting for indirdep complete */
name|struct
name|allocindirhd
name|ir_writehd
decl_stmt|;
comment|/* Waiting for the pointer write. */
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
name|struct
name|freeblks
modifier|*
name|ir_freeblks
decl_stmt|;
comment|/* Freeblks that frees this indir. */
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
name|newblk
name|ai_block
decl_stmt|;
comment|/* Common block area */
define|#
directive|define
name|ai_state
value|ai_block.nb_list.wk_state
comment|/* indirect pointer state */
name|LIST_ENTRY
argument_list|(
argument|allocindir
argument_list|)
name|ai_next
expr_stmt|;
comment|/* indirdep's list of allocindir's */
name|struct
name|indirdep
modifier|*
name|ai_indirdep
decl_stmt|;
comment|/* address of associated indirdep */
name|ufs2_daddr_t
name|ai_oldblkno
decl_stmt|;
comment|/* old value of block pointer */
name|ufs_lbn_t
name|ai_lbn
decl_stmt|;
comment|/* Logical block number. */
name|int
name|ai_offset
decl_stmt|;
comment|/* Pointer offset in parent. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ai_newblkno
value|ai_block.nb_newblkno
end_define

begin_define
define|#
directive|define
name|ai_freefrag
value|ai_block.nb_freefrag
end_define

begin_define
define|#
directive|define
name|ai_newdirblk
value|ai_block.nb_newdirblk
end_define

begin_comment
comment|/*  * The allblk union is used to size the newblk structure on allocation so  * that it may be any one of three types.  */
end_comment

begin_union
union|union
name|allblk
block|{
name|struct
name|allocindir
name|ab_allocindir
decl_stmt|;
name|struct
name|allocdirect
name|ab_allocdirect
decl_stmt|;
name|struct
name|newblk
name|ab_newblk
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * A "freefrag" structure is attached to an "inodedep" when a previously  * allocated fragment is replaced with a larger fragment, rather than extended.  * The "freefrag" structure is constructed and attached when the replacement  * block is first allocated. It is processed after the inode claiming the  * bigger block that replaces it has been written to disk.  */
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
name|struct
name|worklist
modifier|*
name|ff_jdep
decl_stmt|;
comment|/* Associated journal entry. */
name|struct
name|workhead
name|ff_jwork
decl_stmt|;
comment|/* Journal work pending. */
name|ufs2_daddr_t
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
name|enum
name|vtype
name|ff_vtype
decl_stmt|;
comment|/* owning inode's file type */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A "freeblks" structure is attached to an "inodedep" when the  * corresponding file's length is reduced to zero. It records all  * the information needed to free the blocks of a file after its  * zero'ed inode has been written to disk.  The actual work is done  * by child freework structures which are responsible for individual  * inode pointers while freeblks is responsible for retiring the  * entire operation when it is complete and holding common members.  */
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
define|#
directive|define
name|fb_state
value|fb_list.wk_state
comment|/* inode and dirty block state */
name|TAILQ_ENTRY
argument_list|(
argument|freeblks
argument_list|)
name|fb_next
expr_stmt|;
comment|/* List of inode truncates. */
name|struct
name|jblkdephd
name|fb_jblkdephd
decl_stmt|;
comment|/* Journal entries pending */
name|struct
name|workhead
name|fb_freeworkhd
decl_stmt|;
comment|/* Work items pending */
name|struct
name|workhead
name|fb_jwork
decl_stmt|;
comment|/* Journal work pending */
name|struct
name|vnode
modifier|*
name|fb_devvp
decl_stmt|;
comment|/* filesystem device vnode */
ifdef|#
directive|ifdef
name|QUOTA
name|struct
name|dquot
modifier|*
name|fb_quota
index|[
name|MAXQUOTAS
index|]
decl_stmt|;
comment|/* quotas to be adjusted */
endif|#
directive|endif
name|uint64_t
name|fb_modrev
decl_stmt|;
comment|/* Inode revision at start of trunc. */
name|off_t
name|fb_len
decl_stmt|;
comment|/* Length we're truncating to. */
name|ufs2_daddr_t
name|fb_chkcnt
decl_stmt|;
comment|/* Blocks released. */
name|ino_t
name|fb_inum
decl_stmt|;
comment|/* inode owner of blocks */
name|enum
name|vtype
name|fb_vtype
decl_stmt|;
comment|/* inode owner's file type */
name|uid_t
name|fb_uid
decl_stmt|;
comment|/* uid of previous owner of blocks */
name|int
name|fb_ref
decl_stmt|;
comment|/* Children outstanding. */
name|int
name|fb_cgwait
decl_stmt|;
comment|/* cg writes outstanding. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A "freework" structure handles the release of a tree of blocks or a single  * block.  Each indirect block in a tree is allocated its own freework  * structure so that the indirect block may be freed only when all of its  * children are freed.  In this way we enforce the rule that an allocated  * block must have a valid path to a root that is journaled.  Each child  * block acquires a reference and when the ref hits zero the parent ref  * is decremented.  If there is no parent the freeblks ref is decremented.  */
end_comment

begin_struct
struct|struct
name|freework
block|{
name|struct
name|worklist
name|fw_list
decl_stmt|;
comment|/* Delayed worklist. */
define|#
directive|define
name|fw_state
value|fw_list.wk_state
name|LIST_ENTRY
argument_list|(
argument|freework
argument_list|)
name|fw_segs
expr_stmt|;
comment|/* Seg list. */
name|TAILQ_ENTRY
argument_list|(
argument|freework
argument_list|)
name|fw_next
expr_stmt|;
comment|/* Hash/Trunc list. */
name|struct
name|jnewblk
modifier|*
name|fw_jnewblk
decl_stmt|;
comment|/* Journal entry to cancel. */
name|struct
name|freeblks
modifier|*
name|fw_freeblks
decl_stmt|;
comment|/* Root of operation. */
name|struct
name|freework
modifier|*
name|fw_parent
decl_stmt|;
comment|/* Parent indirect. */
name|struct
name|indirdep
modifier|*
name|fw_indir
decl_stmt|;
comment|/* indirect block. */
name|ufs2_daddr_t
name|fw_blkno
decl_stmt|;
comment|/* Our block #. */
name|ufs_lbn_t
name|fw_lbn
decl_stmt|;
comment|/* Original lbn before free. */
name|uint16_t
name|fw_frags
decl_stmt|;
comment|/* Number of frags. */
name|uint16_t
name|fw_ref
decl_stmt|;
comment|/* Number of children out. */
name|uint16_t
name|fw_off
decl_stmt|;
comment|/* Current working position. */
name|uint16_t
name|fw_start
decl_stmt|;
comment|/* Start of partial truncate. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A "freedep" structure is allocated to track the completion of a bitmap  * write for a freework.  One freedep may cover many freed blocks so long  * as they reside in the same cylinder group.  When the cg is written  * the freedep decrements the ref on the freework which may permit it  * to be freed as well.  */
end_comment

begin_struct
struct|struct
name|freedep
block|{
name|struct
name|worklist
name|fd_list
decl_stmt|;
comment|/* Delayed worklist. */
name|struct
name|freework
modifier|*
name|fd_freework
decl_stmt|;
comment|/* Parent freework. */
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
name|workhead
name|fx_jwork
decl_stmt|;
comment|/* journal work pending. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A "diradd" structure is linked to an "inodedep" id_inowait list when a  * new directory entry is allocated that references the inode described  * by "inodedep". When the inode itself is written (either the initial  * allocation for new inodes or with the increased link count for  * existing inodes), the COMPLETE flag is set in da_state. If the entry  * is for a newly allocated inode, the "inodedep" structure is associated  * with a bmsafemap which prevents the inode from being written to disk  * until the cylinder group has been updated. Thus the da_state COMPLETE  * flag cannot be set until the inode bitmap dependency has been removed.  * When creating a new file, it is safe to write the directory entry that  * claims the inode once the referenced inode has been written. Since  * writing the inode clears the bitmap dependencies, the DEPCOMPLETE flag  * in the diradd can be set unconditionally when creating a file. When  * creating a directory, there are two additional dependencies described by  * mkdir structures (see their description below). When these dependencies  * are resolved the DEPCOMPLETE flag is set in the diradd structure.  * If there are multiple links created to the same inode, there will be  * a separate diradd structure created for each link. The diradd is  * linked onto the pg_diraddhd list of the pagedep for the directory  * page that contains the entry. When a directory page is written,  * the pg_diraddhd list is traversed to rollback any entries that are  * not yet ready to be written to disk. If a directory entry is being  * changed (by rename) rather than added, the DIRCHG flag is set and  * the da_previous entry points to the entry that will be "removed"  * once the new entry has been committed. During rollback, entries  * with da_previous are replaced with the previous inode number rather  * than zero.  *  * The overlaying of da_pagedep and da_previous is done to keep the  * structure down. If a da_previous entry is present, the pointer to its  * pagedep is available in the associated dirrem entry. If the DIRCHG flag  * is set, the da_previous entry is valid; if not set the da_pagedep entry  * is valid. The DIRCHG flag never changes; it is set when the structure  * is created if appropriate and is never cleared.  */
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
name|struct
name|workhead
name|da_jwork
decl_stmt|;
comment|/* Journal work awaiting completion. */
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
comment|/*  * Two "mkdir" structures are needed to track the additional dependencies  * associated with creating a new directory entry. Normally a directory  * addition can be committed as soon as the newly referenced inode has been  * written to disk with its increased link count. When a directory is  * created there are two additional dependencies: writing the directory  * data block containing the "." and ".." entries (MKDIR_BODY) and writing  * the parent inode with the increased link count for ".." (MKDIR_PARENT).  * These additional dependencies are tracked by two mkdir structures that  * reference the associated "diradd" structure. When they have completed,  * they set the DEPCOMPLETE flag on the diradd so that it knows that its  * extra dependencies have been completed. The md_state field is used only  * to identify which type of dependency the mkdir structure is tracking.  * It is not used in the mainline code for any purpose other than consistency  * checking. All the mkdir structures in the system are linked together on  * a list. This list is needed so that a diradd can find its associated  * mkdir structures and deallocate them if it is prematurely freed (as for  * example if a mkdir is immediately followed by a rmdir of the same directory).  * Here, the free of the diradd must traverse the list to find the associated  * mkdir structures that reference it. The deletion would be faster if the  * diradd structure were simply augmented to have two pointers that referenced  * the associated mkdir's. However, this would increase the size of the diradd  * structure to speed a very infrequent operation.  */
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
name|jaddref
modifier|*
name|md_jaddref
decl_stmt|;
comment|/* dependent jaddref. */
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

begin_comment
comment|/*  * A "dirrem" structure describes an operation to decrement the link  * count on an inode. The dirrem structure is attached to the pg_dirremhd  * list of the pagedep for the directory page that contains the entry.  * It is processed after the directory page with the deleted entry has  * been written to disk.  */
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
name|LIST_ENTRY
argument_list|(
argument|dirrem
argument_list|)
name|dm_inonext
expr_stmt|;
comment|/* inodedep's list of dirrem's */
name|struct
name|jremrefhd
name|dm_jremrefhd
decl_stmt|;
comment|/* Pending remove reference deps. */
name|ino_t
name|dm_oldinum
decl_stmt|;
comment|/* inum of the removed dir entry */
name|doff_t
name|dm_offset
decl_stmt|;
comment|/* offset of removed dir entry in blk */
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
name|struct
name|workhead
name|dm_jwork
decl_stmt|;
comment|/* Journal work awaiting completion. */
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
comment|/*  * A "newdirblk" structure tracks the progress of a newly allocated  * directory block from its creation until it is claimed by its on-disk  * inode. When a block is allocated to a directory, an fsync of a file  * whose name is within that block must ensure not only that the block  * containing the file name has been written, but also that the on-disk  * inode references that block. When a new directory block is created,  * we allocate a newdirblk structure which is linked to the associated  * allocdirect (on its ad_newdirblk list). When the allocdirect has been  * satisfied, the newdirblk structure is moved to the inodedep id_bufwait  * list of its directory to await the inode being written. When the inode  * is written, the directory entries are fully committed and can be  * deleted from their pagedep->id_pendinghd and inodedep->id_pendinghd  * lists. Note that we could track directory blocks allocated to indirect  * blocks using a similar scheme with the allocindir structures. Rather  * than adding this level of complexity, we simply write those newly   * allocated indirect blocks synchronously as such allocations are rare.  * In the case of a new directory the . and .. links are tracked with  * a mkdir rather than a pagedep.  In this case we track the mkdir  * so it can be released when it is written.  A workhead is used  * to simplify canceling a mkdir that is removed by a subsequent dirrem.  */
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
name|struct
name|pagedep
modifier|*
name|db_pagedep
decl_stmt|;
comment|/* associated pagedep */
name|struct
name|workhead
name|db_mkdir
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The inoref structure holds the elements common to jaddref and jremref  * so they may easily be queued in-order on the inodedep.  */
end_comment

begin_struct
struct|struct
name|inoref
block|{
name|struct
name|worklist
name|if_list
decl_stmt|;
comment|/* Journal pending or jseg entries. */
define|#
directive|define
name|if_state
value|if_list.wk_state
name|TAILQ_ENTRY
argument_list|(
argument|inoref
argument_list|)
name|if_deps
expr_stmt|;
comment|/* Links for inodedep. */
name|struct
name|jsegdep
modifier|*
name|if_jsegdep
decl_stmt|;
comment|/* Will track our journal record. */
name|off_t
name|if_diroff
decl_stmt|;
comment|/* Directory offset. */
name|ino_t
name|if_ino
decl_stmt|;
comment|/* Inode number. */
name|ino_t
name|if_parent
decl_stmt|;
comment|/* Parent inode number. */
name|nlink_t
name|if_nlink
decl_stmt|;
comment|/* nlink before addition. */
name|uint16_t
name|if_mode
decl_stmt|;
comment|/* File mode, needed for IFMT. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A "jaddref" structure tracks a new reference (link count) on an inode  * and prevents the link count increase and bitmap allocation until a  * journal entry can be written.  Once the journal entry is written,  * the inode is put on the pendinghd of the bmsafemap and a diradd or  * mkdir entry is placed on the bufwait list of the inode.  The DEPCOMPLETE  * flag is used to indicate that all of the required information for writing  * the journal entry is present.  MKDIR_BODY and MKDIR_PARENT are used to  * differentiate . and .. links from regular file names.  NEWBLOCK indicates  * a bitmap is still pending.  If a new reference is canceled by a delete  * prior to writing the journal the jaddref write is canceled and the  * structure persists to prevent any disk-visible changes until it is  * ultimately released when the file is freed or the link is dropped again.  */
end_comment

begin_struct
struct|struct
name|jaddref
block|{
name|struct
name|inoref
name|ja_ref
decl_stmt|;
comment|/* see inoref above. */
define|#
directive|define
name|ja_list
value|ja_ref.if_list
comment|/* Jrnl pending, id_inowait, dm_jwork.*/
define|#
directive|define
name|ja_state
value|ja_ref.if_list.wk_state
name|LIST_ENTRY
argument_list|(
argument|jaddref
argument_list|)
name|ja_bmdeps
expr_stmt|;
comment|/* Links for bmsafemap. */
union|union
block|{
name|struct
name|diradd
modifier|*
name|jau_diradd
decl_stmt|;
comment|/* Pending diradd. */
name|struct
name|mkdir
modifier|*
name|jau_mkdir
decl_stmt|;
comment|/* MKDIR_{PARENT,BODY} */
block|}
name|ja_un
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ja_diradd
value|ja_un.jau_diradd
end_define

begin_define
define|#
directive|define
name|ja_mkdir
value|ja_un.jau_mkdir
end_define

begin_define
define|#
directive|define
name|ja_diroff
value|ja_ref.if_diroff
end_define

begin_define
define|#
directive|define
name|ja_ino
value|ja_ref.if_ino
end_define

begin_define
define|#
directive|define
name|ja_parent
value|ja_ref.if_parent
end_define

begin_define
define|#
directive|define
name|ja_mode
value|ja_ref.if_mode
end_define

begin_comment
comment|/*  * A "jremref" structure tracks a removed reference (unlink) on an  * inode and prevents the directory remove from proceeding until the  * journal entry is written.  Once the journal has been written the remove  * may proceed as normal.   */
end_comment

begin_struct
struct|struct
name|jremref
block|{
name|struct
name|inoref
name|jr_ref
decl_stmt|;
comment|/* see inoref above. */
define|#
directive|define
name|jr_list
value|jr_ref.if_list
comment|/* Linked to softdep_journal_pending. */
define|#
directive|define
name|jr_state
value|jr_ref.if_list.wk_state
name|LIST_ENTRY
argument_list|(
argument|jremref
argument_list|)
name|jr_deps
expr_stmt|;
comment|/* Links for dirrem. */
name|struct
name|dirrem
modifier|*
name|jr_dirrem
decl_stmt|;
comment|/* Back pointer to dirrem. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A "jmvref" structure tracks a name relocations within the same  * directory block that occur as a result of directory compaction.  * It prevents the updated directory entry from being written to disk  * until the journal entry is written. Once the journal has been  * written the compacted directory may be written to disk.  */
end_comment

begin_struct
struct|struct
name|jmvref
block|{
name|struct
name|worklist
name|jm_list
decl_stmt|;
comment|/* Linked to softdep_journal_pending. */
name|LIST_ENTRY
argument_list|(
argument|jmvref
argument_list|)
name|jm_deps
expr_stmt|;
comment|/* Jmvref on pagedep. */
name|struct
name|pagedep
modifier|*
name|jm_pagedep
decl_stmt|;
comment|/* Back pointer to pagedep. */
name|ino_t
name|jm_parent
decl_stmt|;
comment|/* Containing directory inode number. */
name|ino_t
name|jm_ino
decl_stmt|;
comment|/* Inode number of our entry. */
name|off_t
name|jm_oldoff
decl_stmt|;
comment|/* Our old offset in directory. */
name|off_t
name|jm_newoff
decl_stmt|;
comment|/* Our new offset in directory. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A "jnewblk" structure tracks a newly allocated block or fragment and  * prevents the direct or indirect block pointer as well as the cg bitmap  * from being written until it is logged.  After it is logged the jsegdep  * is attached to the allocdirect or allocindir until the operation is  * completed or reverted.  If the operation is reverted prior to the journal  * write the jnewblk structure is maintained to prevent the bitmaps from  * reaching the disk.  Ultimately the jnewblk structure will be passed  * to the free routine as the in memory cg is modified back to the free  * state at which time it can be released. It may be held on any of the  * fx_jwork, fw_jwork, fb_jwork, ff_jwork, nb_jwork, or ir_jwork lists.  */
end_comment

begin_struct
struct|struct
name|jnewblk
block|{
name|struct
name|worklist
name|jn_list
decl_stmt|;
comment|/* See lists above. */
define|#
directive|define
name|jn_state
value|jn_list.wk_state
name|struct
name|jsegdep
modifier|*
name|jn_jsegdep
decl_stmt|;
comment|/* Will track our journal record. */
name|LIST_ENTRY
argument_list|(
argument|jnewblk
argument_list|)
name|jn_deps
expr_stmt|;
comment|/* Jnewblks on sm_jnewblkhd. */
name|struct
name|worklist
modifier|*
name|jn_dep
decl_stmt|;
comment|/* Dependency to ref completed seg. */
name|ufs_lbn_t
name|jn_lbn
decl_stmt|;
comment|/* Lbn to which allocated. */
name|ufs2_daddr_t
name|jn_blkno
decl_stmt|;
comment|/* Blkno allocated */
name|ino_t
name|jn_ino
decl_stmt|;
comment|/* Ino to which allocated. */
name|int
name|jn_oldfrags
decl_stmt|;
comment|/* Previous fragments when extended. */
name|int
name|jn_frags
decl_stmt|;
comment|/* Number of fragments. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A "jblkdep" structure tracks jfreeblk and jtrunc records attached to a  * freeblks structure.  */
end_comment

begin_struct
struct|struct
name|jblkdep
block|{
name|struct
name|worklist
name|jb_list
decl_stmt|;
comment|/* For softdep journal pending. */
name|struct
name|jsegdep
modifier|*
name|jb_jsegdep
decl_stmt|;
comment|/* Reference to the jseg. */
name|struct
name|freeblks
modifier|*
name|jb_freeblks
decl_stmt|;
comment|/* Back pointer to freeblks. */
name|LIST_ENTRY
argument_list|(
argument|jblkdep
argument_list|)
name|jb_deps
expr_stmt|;
comment|/* Dep list on freeblks. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A "jfreeblk" structure tracks the journal write for freeing a block  * or tree of blocks.  The block pointer must not be cleared in the inode  * or indirect prior to the jfreeblk being written to the journal.  */
end_comment

begin_struct
struct|struct
name|jfreeblk
block|{
name|struct
name|jblkdep
name|jf_dep
decl_stmt|;
comment|/* freeblks linkage. */
name|ufs_lbn_t
name|jf_lbn
decl_stmt|;
comment|/* Lbn from which blocks freed. */
name|ufs2_daddr_t
name|jf_blkno
decl_stmt|;
comment|/* Blkno being freed. */
name|ino_t
name|jf_ino
decl_stmt|;
comment|/* Ino from which blocks freed. */
name|int
name|jf_frags
decl_stmt|;
comment|/* Number of frags being freed. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A "jfreefrag" tracks the freeing of a single block when a fragment is  * extended or an indirect page is replaced.  It is not part of a larger  * freeblks operation.  */
end_comment

begin_struct
struct|struct
name|jfreefrag
block|{
name|struct
name|worklist
name|fr_list
decl_stmt|;
comment|/* Linked to softdep_journal_pending. */
define|#
directive|define
name|fr_state
value|fr_list.wk_state
name|struct
name|jsegdep
modifier|*
name|fr_jsegdep
decl_stmt|;
comment|/* Will track our journal record. */
name|struct
name|freefrag
modifier|*
name|fr_freefrag
decl_stmt|;
comment|/* Back pointer to freefrag. */
name|ufs_lbn_t
name|fr_lbn
decl_stmt|;
comment|/* Lbn from which frag freed. */
name|ufs2_daddr_t
name|fr_blkno
decl_stmt|;
comment|/* Blkno being freed. */
name|ino_t
name|fr_ino
decl_stmt|;
comment|/* Ino from which frag freed. */
name|int
name|fr_frags
decl_stmt|;
comment|/* Size of frag being freed. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A "jtrunc" journals the intent to truncate an inode's data or extent area.  */
end_comment

begin_struct
struct|struct
name|jtrunc
block|{
name|struct
name|jblkdep
name|jt_dep
decl_stmt|;
comment|/* freeblks linkage. */
name|off_t
name|jt_size
decl_stmt|;
comment|/* Final file size. */
name|int
name|jt_extsize
decl_stmt|;
comment|/* Final extent size. */
name|ino_t
name|jt_ino
decl_stmt|;
comment|/* Ino being truncated. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A "jfsync" journals the completion of an fsync which invalidates earlier  * jtrunc records in the journal.  */
end_comment

begin_struct
struct|struct
name|jfsync
block|{
name|struct
name|worklist
name|jfs_list
decl_stmt|;
comment|/* For softdep journal pending. */
name|off_t
name|jfs_size
decl_stmt|;
comment|/* Sync file size. */
name|int
name|jfs_extsize
decl_stmt|;
comment|/* Sync extent size. */
name|ino_t
name|jfs_ino
decl_stmt|;
comment|/* ino being synced. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A "jsegdep" structure tracks a single reference to a written journal  * segment so the journal space can be reclaimed when all dependencies  * have been written. It can hang off of id_inowait, dm_jwork, da_jwork,  * nb_jwork, ff_jwork, or fb_jwork lists.  */
end_comment

begin_struct
struct|struct
name|jsegdep
block|{
name|struct
name|worklist
name|jd_list
decl_stmt|;
comment|/* See above for lists. */
define|#
directive|define
name|jd_state
value|jd_list.wk_state
name|struct
name|jseg
modifier|*
name|jd_seg
decl_stmt|;
comment|/* Our journal record. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A "jseg" structure contains all of the journal records written in a  * single disk write.  The jaddref and jremref structures are linked into  * js_entries so thay may be completed when the write completes.  The  * js_entries also include the write dependency structures: jmvref,  * jnewblk, jfreeblk, jfreefrag, and jtrunc.  The js_refs field counts  * the number of entries on the js_entries list. Thus there is a single  * jseg entry to describe each journal write.  */
end_comment

begin_struct
struct|struct
name|jseg
block|{
name|struct
name|worklist
name|js_list
decl_stmt|;
comment|/* b_deps link for journal */
define|#
directive|define
name|js_state
value|js_list.wk_state
name|struct
name|workhead
name|js_entries
decl_stmt|;
comment|/* Entries awaiting write */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|freework
argument_list|)
name|js_indirs
expr_stmt|;
comment|/* List of indirects in this seg. */
name|TAILQ_ENTRY
argument_list|(
argument|jseg
argument_list|)
name|js_next
expr_stmt|;
comment|/* List of all unfinished segments. */
name|struct
name|jblocks
modifier|*
name|js_jblocks
decl_stmt|;
comment|/* Back pointer to block/seg list */
name|struct
name|buf
modifier|*
name|js_buf
decl_stmt|;
comment|/* Buffer while unwritten */
name|uint64_t
name|js_seq
decl_stmt|;
comment|/* Journal record sequence number. */
name|uint64_t
name|js_oldseq
decl_stmt|;
comment|/* Oldest valid sequence number. */
name|int
name|js_size
decl_stmt|;
comment|/* Size of journal record in bytes. */
name|int
name|js_cnt
decl_stmt|;
comment|/* Total items allocated. */
name|int
name|js_refs
decl_stmt|;
comment|/* Count of js_entries items. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A 'sbdep' structure tracks the head of the free inode list and  * superblock writes.  This makes sure the superblock is always pointing at  * the first possible unlinked inode for the suj recovery process.  If a  * block write completes and we discover a new head is available the buf  * is dirtied and the dep is kept. See the description of the UNLINK*  * flags above for more details.  */
end_comment

begin_struct
struct|struct
name|sbdep
block|{
name|struct
name|worklist
name|sb_list
decl_stmt|;
comment|/* b_dep linkage */
name|struct
name|fs
modifier|*
name|sb_fs
decl_stmt|;
comment|/* Filesystem pointer within buf. */
name|struct
name|ufsmount
modifier|*
name|sb_ump
decl_stmt|;
comment|/* Our mount structure */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Private journaling structures.  */
end_comment

begin_struct
struct|struct
name|jblocks
block|{
name|struct
name|jseglst
name|jb_segs
decl_stmt|;
comment|/* TAILQ of current segments. */
name|struct
name|jseg
modifier|*
name|jb_writeseg
decl_stmt|;
comment|/* Next write to complete. */
name|struct
name|jseg
modifier|*
name|jb_oldestseg
decl_stmt|;
comment|/* Oldest segment with valid entries. */
name|struct
name|jextent
modifier|*
name|jb_extent
decl_stmt|;
comment|/* Extent array. */
name|uint64_t
name|jb_nextseq
decl_stmt|;
comment|/* Next sequence number. */
name|uint64_t
name|jb_oldestwrseq
decl_stmt|;
comment|/* Oldest written sequence number. */
name|uint8_t
name|jb_needseg
decl_stmt|;
comment|/* Need a forced segment. */
name|uint8_t
name|jb_suspended
decl_stmt|;
comment|/* Did journal suspend writes? */
name|int
name|jb_avail
decl_stmt|;
comment|/* Available extents. */
name|int
name|jb_used
decl_stmt|;
comment|/* Last used extent. */
name|int
name|jb_head
decl_stmt|;
comment|/* Allocator head. */
name|int
name|jb_off
decl_stmt|;
comment|/* Allocator extent offset. */
name|int
name|jb_blocks
decl_stmt|;
comment|/* Total disk blocks covered. */
name|int
name|jb_free
decl_stmt|;
comment|/* Total disk blocks free. */
name|int
name|jb_min
decl_stmt|;
comment|/* Minimum free space. */
name|int
name|jb_low
decl_stmt|;
comment|/* Low on space. */
name|int
name|jb_age
decl_stmt|;
comment|/* Insertion time of oldest rec. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|jextent
block|{
name|ufs2_daddr_t
name|je_daddr
decl_stmt|;
comment|/* Disk block address. */
name|int
name|je_blocks
decl_stmt|;
comment|/* Disk block count. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Hash table declarations.  */
end_comment

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|mkdirlist
argument_list|,
name|mkdir
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|pagedep_hashhead
argument_list|,
name|pagedep
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|inodedep_hashhead
argument_list|,
name|inodedep
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|newblk_hashhead
argument_list|,
name|newblk
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|bmsafemap_hashhead
argument_list|,
name|bmsafemap
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|indir_hashhead
argument_list|,
name|freework
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Per-filesystem soft dependency data.  * Allocated at mount and freed at unmount.  */
end_comment

begin_struct
struct|struct
name|mount_softdeps
block|{
name|struct
name|rwlock
name|sd_fslock
decl_stmt|;
comment|/* softdep lock */
name|struct
name|workhead
name|sd_workitem_pending
decl_stmt|;
comment|/* softdep work queue */
name|struct
name|worklist
modifier|*
name|sd_worklist_tail
decl_stmt|;
comment|/* Tail pointer for above */
name|struct
name|workhead
name|sd_journal_pending
decl_stmt|;
comment|/* journal work queue */
name|struct
name|worklist
modifier|*
name|sd_journal_tail
decl_stmt|;
comment|/* Tail pointer for above */
name|struct
name|jblocks
modifier|*
name|sd_jblocks
decl_stmt|;
comment|/* Journal block information */
name|struct
name|inodedeplst
name|sd_unlinked
decl_stmt|;
comment|/* Unlinked inodes */
name|struct
name|bmsafemaphd
name|sd_dirtycg
decl_stmt|;
comment|/* Dirty CGs */
name|struct
name|mkdirlist
name|sd_mkdirlisthd
decl_stmt|;
comment|/* Track mkdirs */
name|struct
name|pagedep_hashhead
modifier|*
name|sd_pdhash
decl_stmt|;
comment|/* pagedep hash table */
name|u_long
name|sd_pdhashsize
decl_stmt|;
comment|/* pagedep hash table size-1 */
name|long
name|sd_pdnextclean
decl_stmt|;
comment|/* next hash bucket to clean */
name|struct
name|inodedep_hashhead
modifier|*
name|sd_idhash
decl_stmt|;
comment|/* inodedep hash table */
name|u_long
name|sd_idhashsize
decl_stmt|;
comment|/* inodedep hash table size-1 */
name|long
name|sd_idnextclean
decl_stmt|;
comment|/* next hash bucket to clean */
name|struct
name|newblk_hashhead
modifier|*
name|sd_newblkhash
decl_stmt|;
comment|/* newblk hash table */
name|u_long
name|sd_newblkhashsize
decl_stmt|;
comment|/* newblk hash table size-1 */
name|struct
name|bmsafemap_hashhead
modifier|*
name|sd_bmhash
decl_stmt|;
comment|/* bmsafemap hash table */
name|u_long
name|sd_bmhashsize
decl_stmt|;
comment|/* bmsafemap hash table size-1*/
name|struct
name|indir_hashhead
modifier|*
name|sd_indirhash
decl_stmt|;
comment|/* indir hash table */
name|u_long
name|sd_indirhashsize
decl_stmt|;
comment|/* indir hash table size-1 */
name|int
name|sd_on_journal
decl_stmt|;
comment|/* Items on the journal list */
name|int
name|sd_on_worklist
decl_stmt|;
comment|/* Items on the worklist */
name|int
name|sd_deps
decl_stmt|;
comment|/* Total dependency count */
name|int
name|sd_accdeps
decl_stmt|;
comment|/* accumulated dep count */
name|int
name|sd_req
decl_stmt|;
comment|/* Wakeup when deps hits 0. */
name|int
name|sd_flags
decl_stmt|;
comment|/* comm with flushing thread */
name|int
name|sd_cleanups
decl_stmt|;
comment|/* Calls to cleanup */
name|struct
name|thread
modifier|*
name|sd_flushtd
decl_stmt|;
comment|/* thread handling flushing */
name|TAILQ_ENTRY
argument_list|(
argument|mount_softdeps
argument_list|)
name|sd_next
expr_stmt|;
comment|/* List of softdep filesystem */
name|struct
name|ufsmount
modifier|*
name|sd_ump
decl_stmt|;
comment|/* our ufsmount structure */
name|u_long
name|sd_curdeps
index|[
name|D_LAST
operator|+
literal|1
index|]
decl_stmt|;
comment|/* count of current deps */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags for communicating with the syncer thread.  */
end_comment

begin_define
define|#
directive|define
name|FLUSH_EXIT
value|0x0001
end_define

begin_comment
comment|/* time to exit */
end_comment

begin_define
define|#
directive|define
name|FLUSH_CLEANUP
value|0x0002
end_define

begin_comment
comment|/* need to clear out softdep structures */
end_comment

begin_define
define|#
directive|define
name|FLUSH_STARTING
value|0x0004
end_define

begin_comment
comment|/* flush thread not yet started */
end_comment

begin_define
define|#
directive|define
name|FLUSH_RC_ACTIVE
value|0x0008
end_define

begin_comment
comment|/* a thread is flushing the mount point */
end_comment

begin_comment
comment|/*  * Keep the old names from when these were in the ufsmount structure.  */
end_comment

begin_define
define|#
directive|define
name|softdep_workitem_pending
value|um_softdep->sd_workitem_pending
end_define

begin_define
define|#
directive|define
name|softdep_worklist_tail
value|um_softdep->sd_worklist_tail
end_define

begin_define
define|#
directive|define
name|softdep_journal_pending
value|um_softdep->sd_journal_pending
end_define

begin_define
define|#
directive|define
name|softdep_journal_tail
value|um_softdep->sd_journal_tail
end_define

begin_define
define|#
directive|define
name|softdep_jblocks
value|um_softdep->sd_jblocks
end_define

begin_define
define|#
directive|define
name|softdep_unlinked
value|um_softdep->sd_unlinked
end_define

begin_define
define|#
directive|define
name|softdep_dirtycg
value|um_softdep->sd_dirtycg
end_define

begin_define
define|#
directive|define
name|softdep_mkdirlisthd
value|um_softdep->sd_mkdirlisthd
end_define

begin_define
define|#
directive|define
name|pagedep_hashtbl
value|um_softdep->sd_pdhash
end_define

begin_define
define|#
directive|define
name|pagedep_hash_size
value|um_softdep->sd_pdhashsize
end_define

begin_define
define|#
directive|define
name|pagedep_nextclean
value|um_softdep->sd_pdnextclean
end_define

begin_define
define|#
directive|define
name|inodedep_hashtbl
value|um_softdep->sd_idhash
end_define

begin_define
define|#
directive|define
name|inodedep_hash_size
value|um_softdep->sd_idhashsize
end_define

begin_define
define|#
directive|define
name|inodedep_nextclean
value|um_softdep->sd_idnextclean
end_define

begin_define
define|#
directive|define
name|newblk_hashtbl
value|um_softdep->sd_newblkhash
end_define

begin_define
define|#
directive|define
name|newblk_hash_size
value|um_softdep->sd_newblkhashsize
end_define

begin_define
define|#
directive|define
name|bmsafemap_hashtbl
value|um_softdep->sd_bmhash
end_define

begin_define
define|#
directive|define
name|bmsafemap_hash_size
value|um_softdep->sd_bmhashsize
end_define

begin_define
define|#
directive|define
name|indir_hashtbl
value|um_softdep->sd_indirhash
end_define

begin_define
define|#
directive|define
name|indir_hash_size
value|um_softdep->sd_indirhashsize
end_define

begin_define
define|#
directive|define
name|softdep_on_journal
value|um_softdep->sd_on_journal
end_define

begin_define
define|#
directive|define
name|softdep_on_worklist
value|um_softdep->sd_on_worklist
end_define

begin_define
define|#
directive|define
name|softdep_deps
value|um_softdep->sd_deps
end_define

begin_define
define|#
directive|define
name|softdep_accdeps
value|um_softdep->sd_accdeps
end_define

begin_define
define|#
directive|define
name|softdep_req
value|um_softdep->sd_req
end_define

begin_define
define|#
directive|define
name|softdep_flags
value|um_softdep->sd_flags
end_define

begin_define
define|#
directive|define
name|softdep_flushtd
value|um_softdep->sd_flushtd
end_define

begin_define
define|#
directive|define
name|softdep_curdeps
value|um_softdep->sd_curdeps
end_define

end_unit

