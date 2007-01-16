begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: denode.h,v 1.25 1997/11/17 15:36:28 ws Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (C) 1994, 1995, 1997 Wolfgang Solfrank.  * Copyright (C) 1994, 1995, 1997 TooLs GmbH.  * All rights reserved.  * Original code by Paul Popelka (paulp@uts.amdahl.com) (see below).  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Written by Paul Popelka (paulp@uts.amdahl.com)  *  * You can do anything you want with this software, just don't say you wrote  * it, and don't remove this notice.  *  * This software is provided "as is".  *  * The author supplies this software to be publicly redistributed on the  * understanding that the author is not responsible for the correct  * functioning of this software in any circumstances and is not liable for  * any damages caused by this software.  *  * October 1992  */
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
name|u_long
name|fc_frcn
decl_stmt|;
comment|/* file relative cluster number */
name|u_long
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
value|3
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
name|FC_NEXTTOLASTFC
value|2
end_define

begin_comment
comment|/* entry for a close to the last cluster in 				 * the file */
end_comment

begin_define
define|#
directive|define
name|FCE_EMPTY
value|0xffffffff
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
value|(dep)->de_fc[(slot)].fc_frcn = (frcn); \ 	(dep)->de_fc[(slot)].fc_fsrcn = (fsrcn);
end_define

begin_define
define|#
directive|define
name|fc_last_to_nexttolast
parameter_list|(
name|dep
parameter_list|)
value|do {		 \ 	(dep)->de_fc[FC_NEXTTOLASTFC].fc_frcn =  \ 	(dep)->de_fc[FC_LASTFC].fc_frcn;	 \ 	(dep)->de_fc[FC_NEXTTOLASTFC].fc_fsrcn = \ 	(dep)->de_fc[FC_LASTFC].fc_fsrcn;	 \ } while (0)
end_define

begin_comment
comment|/*  * This is the in memory variant of a dos directory entry.  It is usually  * contained within a vnode.  */
end_comment

begin_struct
struct|struct
name|denode
block|{
name|struct
name|vnode
modifier|*
name|de_vnode
decl_stmt|;
comment|/* addr of vnode we are part of */
name|u_long
name|de_flag
decl_stmt|;
comment|/* flag bits */
name|struct
name|cdev
modifier|*
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
comment|/* offset of this entry in the directory cluster */
name|u_long
name|de_fndoffset
decl_stmt|;
comment|/* offset of found dir entry */
name|int
name|de_fndcnt
decl_stmt|;
comment|/* number of slots before de_fndoffset */
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
name|u_char
name|de_Name
index|[
literal|12
index|]
decl_stmt|;
comment|/* name, from DOS directory entry */
name|u_char
name|de_Attributes
decl_stmt|;
comment|/* attributes, from directory entry */
name|u_char
name|de_LowerCase
decl_stmt|;
comment|/* NT VFAT lower case flags */
name|u_char
name|de_CHun
decl_stmt|;
comment|/* Hundredth of second of CTime*/
name|u_short
name|de_CTime
decl_stmt|;
comment|/* creation time */
name|u_short
name|de_CDate
decl_stmt|;
comment|/* creation date */
name|u_short
name|de_ADate
decl_stmt|;
comment|/* access date */
name|u_short
name|de_MTime
decl_stmt|;
comment|/* modification time */
name|u_short
name|de_MDate
decl_stmt|;
comment|/* modification date */
name|u_long
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
name|struct
name|lockf
modifier|*
name|de_lockf
decl_stmt|;
comment|/* lockf */
name|u_int64_t
name|de_inode
decl_stmt|;
comment|/* Inode number (really byte offset of direntry) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Values for the de_flag field of the denode.  */
end_comment

begin_define
define|#
directive|define
name|DE_UPDATE
value|0x0004
end_define

begin_comment
comment|/* Modification time update request */
end_comment

begin_define
define|#
directive|define
name|DE_CREATE
value|0x0008
end_define

begin_comment
comment|/* Creation time update */
end_comment

begin_define
define|#
directive|define
name|DE_ACCESS
value|0x0010
end_define

begin_comment
comment|/* Access time update */
end_comment

begin_define
define|#
directive|define
name|DE_MODIFIED
value|0x0020
end_define

begin_comment
comment|/* Denode has been modified */
end_comment

begin_define
define|#
directive|define
name|DE_RENAME
value|0x0040
end_define

begin_comment
comment|/* Denode is in the process of being renamed */
end_comment

begin_comment
comment|/*  * Transfer directory entries between internal and external form.  * dep is a struct denode * (internal form),  * dp is a struct direntry * (external form).  */
end_comment

begin_define
define|#
directive|define
name|DE_INTERNALIZE32
parameter_list|(
name|dep
parameter_list|,
name|dp
parameter_list|)
define|\
value|((dep)->de_StartCluster |= getushort((dp)->deHighClust)<< 16)
end_define

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
value|(bcopy((dp)->deName, (dep)->de_Name, 11),	\ 	 (dep)->de_Attributes = (dp)->deAttributes,	\ 	 (dep)->de_LowerCase = (dp)->deLowerCase,	\ 	 (dep)->de_CHun = (dp)->deCHundredth,		\ 	 (dep)->de_CTime = getushort((dp)->deCTime),	\ 	 (dep)->de_CDate = getushort((dp)->deCDate),	\ 	 (dep)->de_ADate = getushort((dp)->deADate),	\ 	 (dep)->de_MTime = getushort((dp)->deMTime),	\ 	 (dep)->de_MDate = getushort((dp)->deMDate),	\ 	 (dep)->de_StartCluster = getushort((dp)->deStartCluster), \ 	 (dep)->de_FileSize = getulong((dp)->deFileSize), \ 	 (FAT32((dep)->de_pmp) ? DE_INTERNALIZE32((dep), (dp)) : 0))
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
value|(bcopy((dep)->de_Name, (dp)->deName, 11),	\ 	 (dp)->deAttributes = (dep)->de_Attributes,	\ 	 (dp)->deLowerCase = (dep)->de_LowerCase,	\ 	 (dp)->deCHundredth = (dep)->de_CHun,		\ 	 putushort((dp)->deCTime, (dep)->de_CTime),	\ 	 putushort((dp)->deCDate, (dep)->de_CDate),	\ 	 putushort((dp)->deADate, (dep)->de_ADate),	\ 	 putushort((dp)->deMTime, (dep)->de_MTime),	\ 	 putushort((dp)->deMDate, (dep)->de_MDate),	\ 	 putushort((dp)->deStartCluster, (dep)->de_StartCluster), \ 	 putulong((dp)->deFileSize,			\ 	     ((dep)->de_Attributes& ATTR_DIRECTORY) ? 0 : (dep)->de_FileSize), \ 	 putushort((dp)->deHighClust, (dep)->de_StartCluster>> 16))
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
name|_KERNEL
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
name|DETIMES
parameter_list|(
name|dep
parameter_list|,
name|acc
parameter_list|,
name|mod
parameter_list|,
name|cre
parameter_list|)
value|do {				\ 	if ((dep)->de_flag& DE_UPDATE) { 				\ 		(dep)->de_flag |= DE_MODIFIED;				\ 		timespec2fattime((mod), 0,&(dep)->de_MDate,		\&(dep)->de_MTime, NULL);				\ 		(dep)->de_Attributes |= ATTR_ARCHIVE; 			\ 	}								\ 	if ((dep)->de_pmp->pm_flags& MSDOSFSMNT_NOWIN95) {		\ 		(dep)->de_flag&= ~(DE_UPDATE | DE_CREATE | DE_ACCESS);	\ 		break;							\ 	}								\ 	if ((dep)->de_flag& DE_ACCESS) {				\ 	    	u_int16_t adate;					\ 									\ 		timespec2fattime((acc), 0,&adate, NULL, NULL);		\ 		if (adate != (dep)->de_ADate) {				\ 			(dep)->de_flag |= DE_MODIFIED;			\ 			(dep)->de_ADate = adate;			\ 		}							\ 	}								\ 	if ((dep)->de_flag& DE_CREATE) {				\ 		timespec2fattime((cre), 0,&(dep)->de_CDate,		\&(dep)->de_CTime,&(dep)->de_CHun);			\ 		    (dep)->de_flag |= DE_MODIFIED;			\ 	}								\ 	(dep)->de_flag&= ~(DE_UPDATE | DE_CREATE | DE_ACCESS);		\ } while (0)
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
name|u_int32_t
name|defid_dirclust
decl_stmt|;
comment|/* cluster this dir entry came from */
name|u_int32_t
name|defid_dirofs
decl_stmt|;
comment|/* offset of entry within the cluster */
if|#
directive|if
literal|0
block|u_int32_t defid_gen;
comment|/* generation number */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vop_vector
name|msdosfs_vnodeops
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|msdosfs_lookup
parameter_list|(
name|struct
name|vop_cachedlookup_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|msdosfs_inactive
parameter_list|(
name|struct
name|vop_inactive_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|msdosfs_reclaim
parameter_list|(
name|struct
name|vop_reclaim_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Internal service routine prototypes.  */
end_comment

begin_function_decl
name|int
name|deget
parameter_list|(
name|struct
name|msdosfsmount
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|,
name|struct
name|denode
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uniqdosname
parameter_list|(
name|struct
name|denode
modifier|*
parameter_list|,
name|struct
name|componentname
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|findwin95
parameter_list|(
name|struct
name|denode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|readep
parameter_list|(
name|struct
name|msdosfsmount
modifier|*
name|pmp
parameter_list|,
name|u_long
name|dirclu
parameter_list|,
name|u_long
name|dirofs
parameter_list|,
name|struct
name|buf
modifier|*
modifier|*
name|bpp
parameter_list|,
name|struct
name|direntry
modifier|*
modifier|*
name|epp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|readde
parameter_list|(
name|struct
name|denode
modifier|*
name|dep
parameter_list|,
name|struct
name|buf
modifier|*
modifier|*
name|bpp
parameter_list|,
name|struct
name|direntry
modifier|*
modifier|*
name|epp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|deextend
parameter_list|(
name|struct
name|denode
modifier|*
name|dep
parameter_list|,
name|u_long
name|length
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fillinusemap
parameter_list|(
name|struct
name|msdosfsmount
modifier|*
name|pmp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reinsert
parameter_list|(
name|struct
name|denode
modifier|*
name|dep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dosdirempty
parameter_list|(
name|struct
name|denode
modifier|*
name|dep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|createde
parameter_list|(
name|struct
name|denode
modifier|*
name|dep
parameter_list|,
name|struct
name|denode
modifier|*
name|ddep
parameter_list|,
name|struct
name|denode
modifier|*
modifier|*
name|depp
parameter_list|,
name|struct
name|componentname
modifier|*
name|cnp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|deupdat
parameter_list|(
name|struct
name|denode
modifier|*
name|dep
parameter_list|,
name|int
name|waitfor
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|removede
parameter_list|(
name|struct
name|denode
modifier|*
name|pdep
parameter_list|,
name|struct
name|denode
modifier|*
name|dep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|detrunc
parameter_list|(
name|struct
name|denode
modifier|*
name|dep
parameter_list|,
name|u_long
name|length
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|doscheckpath
parameter_list|(
name|struct
name|denode
modifier|*
name|source
parameter_list|,
name|struct
name|denode
modifier|*
name|target
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

end_unit

