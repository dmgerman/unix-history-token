begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: denode.h,v 1.5 1995/05/30 08:07:32 rgrimes Exp $ */
end_comment

begin_comment
comment|/*	$NetBSD: denode.h,v 1.8 1994/08/21 18:43:49 ws Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (C) 1994 Wolfgang Solfrank.  * Copyright (C) 1994 TooLs GmbH.  * All rights reserved.  * Original code by Paul Popelka (paulp@uts.amdahl.com) (see below).  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Written by Paul Popelka (paulp@uts.amdahl.com)  *  * You can do anything you want with this software, just don't say you wrote  * it, and don't remove this notice.  *  * This software is provided "as is".  *  * The author supplies this software to be publicly redistributed on the  * understanding that the author is not responsible for the correct  * functioning of this software in any circumstances and is not liable for  * any damages caused by this software.  *  * October 1992  */
end_comment

begin_comment
comment|/*  * This is the pc filesystem specific portion of the vnode structure.  *  * To describe a file uniquely the de_dirclust, de_diroffset, and  * de_StartCluster fields are used.  *  * de_dirclust contains the cluster number of the directory cluster  *	containing the entry for a file or directory.  * de_diroffset is the index into the cluster for the entry describing  *	a file or directory.  * de_StartCluster is the number of the first cluster of the file or directory.  *  * Now to describe the quirks of the pc filesystem.  * - Clusters 0 and 1 are reserved.  * - The first allocatable cluster is 2.  * - The root directory is of fixed size and all blocks that make it up  *   are contiguous.  * - Cluster 0 refers to the root directory when it is found in the  *   startcluster field of a directory entry that points to another directory.  * - Cluster 0 implies a 0 length file when found in the start cluster field  *   of a directory entry that points to a file.  * - You can't use the cluster number 0 to derive the address of the root  *   directory.  * - Multiple directory entries can point to a directory. The entry in the  *   parent directory points to a child directory.  Any directories in the  *   child directory contain a ".." entry that points back to the parent.  *   The child directory itself contains a "." entry that points to itself.  * - The root directory does not contain a "." or ".." entry.  * - Directory entries for directories are never changed once they are created  *   (except when removed).  The size stays 0, and the last modification time  *   is never changed.  This is because so many directory entries can point to  *   the physical clusters that make up a directory.  It would lead to an  *   update nightmare.  * - The length field in a directory entry pointing to a directory contains 0  *   (always).  The only way to find the end of a directory is to follow the  *   cluster chain until the "last cluster" marker is found.  *  * My extensions to make this house of cards work.  These apply only to the in  * memory copy of the directory entry.  * - A reference count for each denode will be kept since dos doesn't keep such  *   things.  */
end_comment

begin_comment
comment|/*  * Internal pseudo-offset for (nonexistent) directory entry for the root  * dir in the root dir  */
end_comment

begin_define
define|#
directive|define
name|MSDOSFSROOT_OFS
value|0x1fffffff
end_define

begin_comment
comment|/*  * The fat cache structure. fc_fsrcn is the filesystem relative cluster  * number that corresponds to the file relative cluster number in this  * structure (fc_frcn).  */
end_comment

begin_struct
struct|struct
name|fatcache
block|{
name|u_short
name|fc_frcn
decl_stmt|;
comment|/* file relative cluster number */
name|u_short
name|fc_fsrcn
decl_stmt|;
comment|/* filesystem relative cluster number */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The fat entry cache as it stands helps make extending files a "quick"  * operation by avoiding having to scan the fat to discover the last  * cluster of the file. The cache also helps sequential reads by  * remembering the last cluster read from the file.  This also prevents us  * from having to rescan the fat to find the next cluster to read.  This  * cache is probably pretty worthless if a file is opened by multiple  * processes.  */
end_comment

begin_define
define|#
directive|define
name|FC_SIZE
value|2
end_define

begin_comment
comment|/* number of entries in the cache */
end_comment

begin_define
define|#
directive|define
name|FC_LASTMAP
value|0
end_define

begin_comment
comment|/* entry the last call to pcbmap() resolved 				 * to */
end_comment

begin_define
define|#
directive|define
name|FC_LASTFC
value|1
end_define

begin_comment
comment|/* entry for the last cluster in the file */
end_comment

begin_define
define|#
directive|define
name|FCE_EMPTY
value|0xffff
end_define

begin_comment
comment|/* doesn't represent an actual cluster # */
end_comment

begin_comment
comment|/*  * Set a slot in the fat cache.  */
end_comment

begin_define
define|#
directive|define
name|fc_setcache
parameter_list|(
name|dep
parameter_list|,
name|slot
parameter_list|,
name|frcn
parameter_list|,
name|fsrcn
parameter_list|)
define|\
value|(dep)->de_fc[slot].fc_frcn = frcn; \ 	(dep)->de_fc[slot].fc_fsrcn = fsrcn;
end_define

begin_comment
comment|/*  * This is the in memory variant of a dos directory entry.  It is usually  * contained within a vnode.  */
end_comment

begin_struct
struct|struct
name|denode
block|{
name|struct
name|denode
modifier|*
name|de_next
decl_stmt|;
comment|/* Hash chain forward */
name|struct
name|denode
modifier|*
modifier|*
name|de_prev
decl_stmt|;
comment|/* Hash chain back */
name|struct
name|vnode
modifier|*
name|de_vnode
decl_stmt|;
comment|/* addr of vnode we are part of */
name|struct
name|vnode
modifier|*
name|de_devvp
decl_stmt|;
comment|/* vnode of blk dev we live on */
name|u_long
name|de_flag
decl_stmt|;
comment|/* flag bits */
name|dev_t
name|de_dev
decl_stmt|;
comment|/* device where direntry lives */
name|u_long
name|de_dirclust
decl_stmt|;
comment|/* cluster of the directory file containing this entry */
name|u_long
name|de_diroffset
decl_stmt|;
comment|/* ordinal of this entry in the directory */
name|u_long
name|de_fndclust
decl_stmt|;
comment|/* cluster of found dir entry */
name|u_long
name|de_fndoffset
decl_stmt|;
comment|/* offset of found dir entry */
name|long
name|de_refcnt
decl_stmt|;
comment|/* reference count */
name|struct
name|msdosfsmount
modifier|*
name|de_pmp
decl_stmt|;
comment|/* addr of our mount struct */
name|struct
name|lockf
modifier|*
name|de_lockf
decl_stmt|;
comment|/* byte level lock list */
name|pid_t
name|de_lockholder
decl_stmt|;
comment|/* current lock holder */
name|pid_t
name|de_lockwaiter
decl_stmt|;
comment|/* lock wanter */
comment|/* the next two fields must be contiguous in memory... */
name|u_char
name|de_Name
index|[
literal|8
index|]
decl_stmt|;
comment|/* name, from directory entry */
name|u_char
name|de_Extension
index|[
literal|3
index|]
decl_stmt|;
comment|/* extension, from directory entry */
name|u_char
name|de_Attributes
decl_stmt|;
comment|/* attributes, from directory entry */
name|u_short
name|de_Time
decl_stmt|;
comment|/* creation time */
name|u_short
name|de_Date
decl_stmt|;
comment|/* creation date */
name|u_short
name|de_StartCluster
decl_stmt|;
comment|/* starting cluster of file */
name|u_long
name|de_FileSize
decl_stmt|;
comment|/* size of file in bytes */
name|struct
name|fatcache
name|de_fc
index|[
name|FC_SIZE
index|]
decl_stmt|;
comment|/* fat cache */
name|u_quad_t
name|de_modrev
decl_stmt|;
comment|/* Revision level for lease. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Values for the de_flag field of the denode.  */
end_comment

begin_define
define|#
directive|define
name|DE_LOCKED
value|0x0001
end_define

begin_comment
comment|/* directory entry is locked */
end_comment

begin_define
define|#
directive|define
name|DE_WANTED
value|0x0002
end_define

begin_comment
comment|/* someone wants this de */
end_comment

begin_define
define|#
directive|define
name|DE_UPDATE
value|0x0004
end_define

begin_comment
comment|/* modification time update request */
end_comment

begin_define
define|#
directive|define
name|DE_MODIFIED
value|0x0080
end_define

begin_comment
comment|/* denode has been modified, but DE_UPDATE 				 * isn't set */
end_comment

begin_comment
comment|/*  * Transfer directory entries between internal and external form.  * dep is a struct denode * (internal form),  * dp is a struct direntry * (external form).  */
end_comment

begin_define
define|#
directive|define
name|DE_INTERNALIZE
parameter_list|(
name|dep
parameter_list|,
name|dp
parameter_list|)
define|\
value|(bcopy((dp)->deName, (dep)->de_Name, 11),	\ 	 (dep)->de_Attributes = (dp)->deAttributes,	\ 	 (dep)->de_Time = getushort((dp)->deTime),	\ 	 (dep)->de_Date = getushort((dp)->deDate),	\ 	 (dep)->de_StartCluster = getushort((dp)->deStartCluster), \ 	 (dep)->de_FileSize = getulong((dp)->deFileSize))
end_define

begin_define
define|#
directive|define
name|DE_EXTERNALIZE
parameter_list|(
name|dp
parameter_list|,
name|dep
parameter_list|)
define|\
value|(bcopy((dep)->de_Name, (dp)->deName, 11),	\ 	 (dp)->deAttributes = (dep)->de_Attributes,	\ 	 putushort((dp)->deTime, (dep)->de_Time),	\ 	 putushort((dp)->deDate, (dep)->de_Date),	\ 	 putushort((dp)->deStartCluster, (dep)->de_StartCluster), \ 	 putulong((dp)->deFileSize, (dep)->de_FileSize))
end_define

begin_define
define|#
directive|define
name|de_forw
value|de_chain[0]
end_define

begin_define
define|#
directive|define
name|de_back
value|de_chain[1]
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|VTODE
parameter_list|(
name|vp
parameter_list|)
value|((struct denode *)(vp)->v_data)
end_define

begin_define
define|#
directive|define
name|DETOV
parameter_list|(
name|de
parameter_list|)
value|((de)->de_vnode)
end_define

begin_define
define|#
directive|define
name|DE_TIMES
parameter_list|(
name|dep
parameter_list|,
name|t
parameter_list|)
define|\
value|if ((dep)->de_flag& DE_UPDATE) { \ 		if (!((dep)->de_Attributes& ATTR_DIRECTORY)) { \ 			struct timespec DE_TIMES_ts; \ 			(dep)->de_flag |= DE_MODIFIED; \ 			TIMEVAL_TO_TIMESPEC((t),&DE_TIMES_ts); \ 			unix2dostime(&DE_TIMES_ts,&(dep)->de_Date, \&(dep)->de_Time); \ 			(dep)->de_Attributes |= ATTR_ARCHIVE; \ 		} \ 		(dep)->de_flag&= ~DE_UPDATE; \ 	}
end_define

begin_comment
comment|/*  * This overlays the fid structure (see mount.h)  */
end_comment

begin_struct
struct|struct
name|defid
block|{
name|u_short
name|defid_len
decl_stmt|;
comment|/* length of structure */
name|u_short
name|defid_pad
decl_stmt|;
comment|/* force long alignment */
name|u_long
name|defid_dirclust
decl_stmt|;
comment|/* cluster this dir entry came from */
name|u_long
name|defid_dirofs
decl_stmt|;
comment|/* index of entry within the cluster */
comment|/* u_long	defid_gen;	 generation number */
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
modifier|*
name|msdosfs_vnodeop_p
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Prototypes for MSDOSFS vnode operations  */
end_comment

begin_decl_stmt
name|int
name|msdosfs_lookup
name|__P
argument_list|(
operator|(
expr|struct
name|vop_lookup_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_create
name|__P
argument_list|(
operator|(
expr|struct
name|vop_create_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_mknod
name|__P
argument_list|(
operator|(
expr|struct
name|vop_mknod_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_open
name|__P
argument_list|(
operator|(
expr|struct
name|vop_open_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_close
name|__P
argument_list|(
operator|(
expr|struct
name|vop_close_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_access
name|__P
argument_list|(
operator|(
expr|struct
name|vop_access_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_getattr
name|__P
argument_list|(
operator|(
expr|struct
name|vop_getattr_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_setattr
name|__P
argument_list|(
operator|(
expr|struct
name|vop_setattr_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_read
name|__P
argument_list|(
operator|(
expr|struct
name|vop_read_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_write
name|__P
argument_list|(
operator|(
expr|struct
name|vop_write_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_ioctl
name|__P
argument_list|(
operator|(
expr|struct
name|vop_ioctl_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_select
name|__P
argument_list|(
operator|(
expr|struct
name|vop_select_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_mmap
name|__P
argument_list|(
operator|(
expr|struct
name|vop_mmap_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_fsync
name|__P
argument_list|(
operator|(
expr|struct
name|vop_fsync_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_seek
name|__P
argument_list|(
operator|(
expr|struct
name|vop_seek_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_remove
name|__P
argument_list|(
operator|(
expr|struct
name|vop_remove_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_link
name|__P
argument_list|(
operator|(
expr|struct
name|vop_link_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_rename
name|__P
argument_list|(
operator|(
expr|struct
name|vop_rename_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_mkdir
name|__P
argument_list|(
operator|(
expr|struct
name|vop_mkdir_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_rmdir
name|__P
argument_list|(
operator|(
expr|struct
name|vop_rmdir_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_symlink
name|__P
argument_list|(
operator|(
expr|struct
name|vop_symlink_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_readdir
name|__P
argument_list|(
operator|(
expr|struct
name|vop_readdir_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_readlink
name|__P
argument_list|(
operator|(
expr|struct
name|vop_readlink_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_abortop
name|__P
argument_list|(
operator|(
expr|struct
name|vop_abortop_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_inactive
name|__P
argument_list|(
operator|(
expr|struct
name|vop_inactive_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_reclaim
name|__P
argument_list|(
operator|(
expr|struct
name|vop_reclaim_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_lock
name|__P
argument_list|(
operator|(
expr|struct
name|vop_lock_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_unlock
name|__P
argument_list|(
operator|(
expr|struct
name|vop_unlock_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_bmap
name|__P
argument_list|(
operator|(
expr|struct
name|vop_bmap_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_strategy
name|__P
argument_list|(
operator|(
expr|struct
name|vop_strategy_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_print
name|__P
argument_list|(
operator|(
expr|struct
name|vop_print_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_islocked
name|__P
argument_list|(
operator|(
expr|struct
name|vop_islocked_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_advlock
name|__P
argument_list|(
operator|(
expr|struct
name|vop_advlock_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_reallocblks
name|__P
argument_list|(
operator|(
expr|struct
name|vop_reallocblks_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Internal service routine prototypes.  */
end_comment

begin_decl_stmt
name|int
name|deget
name|__P
argument_list|(
operator|(
expr|struct
name|msdosfsmount
operator|*
name|pmp
operator|,
name|u_long
name|dirclust
operator|,
name|u_long
name|diroffset
operator|,
expr|struct
name|direntry
operator|*
name|direntptr
operator|,
expr|struct
name|denode
operator|*
operator|*
name|depp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

end_unit

