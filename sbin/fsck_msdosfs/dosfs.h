begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997 Wolfgang Solfrank  * Copyright (c) 1995 Martin Husemann  * Some structure declaration borrowed from Paul Popelka  * (paulp@uts.amdahl.com), see /sys/msdosfs/ for reference.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Martin Husemann  *	and Wolfgang Solfrank.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *	$NetBSD: dosfs.h,v 1.4 1997/01/03 14:32:48 ws Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DOSFS_H
end_ifndef

begin_define
define|#
directive|define
name|DOSFS_H
end_define

begin_define
define|#
directive|define
name|DOSBOOTBLOCKSIZE
value|512
end_define

begin_typedef
typedef|typedef
name|u_int32_t
name|cl_t
typedef|;
end_typedef

begin_comment
comment|/* type holding a cluster number */
end_comment

begin_comment
comment|/*  * architecture independent description of all the info stored in a  * FAT boot block.  */
end_comment

begin_struct
struct|struct
name|bootblock
block|{
name|u_int
name|BytesPerSec
decl_stmt|;
comment|/* bytes per sector */
name|u_int
name|SecPerClust
decl_stmt|;
comment|/* sectors per cluster */
name|u_int
name|ResSectors
decl_stmt|;
comment|/* number of reserved sectors */
name|u_int
name|FATs
decl_stmt|;
comment|/* number of FATs */
name|u_int
name|RootDirEnts
decl_stmt|;
comment|/* number of root directory entries */
name|u_int
name|Media
decl_stmt|;
comment|/* media descriptor */
name|u_int
name|FATsmall
decl_stmt|;
comment|/* number of sectors per FAT */
name|u_int
name|SecPerTrack
decl_stmt|;
comment|/* sectors per track */
name|u_int
name|Heads
decl_stmt|;
comment|/* number of heads */
name|u_int32_t
name|Sectors
decl_stmt|;
comment|/* total number of sectors */
name|u_int32_t
name|HiddenSecs
decl_stmt|;
comment|/* # of hidden sectors */
name|u_int32_t
name|HugeSectors
decl_stmt|;
comment|/* # of sectors if bpbSectors == 0 */
name|u_int
name|FSInfo
decl_stmt|;
comment|/* FSInfo sector */
name|u_int
name|Backup
decl_stmt|;
comment|/* Backup of Bootblocks */
name|cl_t
name|RootCl
decl_stmt|;
comment|/* Start of Root Directory */
name|cl_t
name|FSFree
decl_stmt|;
comment|/* Number of free clusters acc. FSInfo */
name|cl_t
name|FSNext
decl_stmt|;
comment|/* Next free cluster acc. FSInfo */
comment|/* and some more calculated values */
name|u_int
name|flags
decl_stmt|;
comment|/* some flags: */
define|#
directive|define
name|FAT32
value|1
comment|/* this is a FAT32 filesystem */
comment|/* 					 * Maybe, we should separate out 					 * various parts of FAT32?	XXX 					 */
name|int
name|ValidFat
decl_stmt|;
comment|/* valid fat if FAT32 non-mirrored */
name|cl_t
name|ClustMask
decl_stmt|;
comment|/* mask for entries in FAT */
name|cl_t
name|NumClusters
decl_stmt|;
comment|/* # of entries in a FAT */
name|u_int32_t
name|NumSectors
decl_stmt|;
comment|/* how many sectors are there */
name|u_int32_t
name|FATsecs
decl_stmt|;
comment|/* how many sectors are in FAT */
name|u_int32_t
name|NumFatEntries
decl_stmt|;
comment|/* how many entries really are there */
name|u_int
name|ClusterOffset
decl_stmt|;
comment|/* at what sector would sector 0 start */
name|u_int
name|ClusterSize
decl_stmt|;
comment|/* Cluster size in bytes */
comment|/* Now some statistics: */
name|u_int
name|NumFiles
decl_stmt|;
comment|/* # of plain files */
name|u_int
name|NumFree
decl_stmt|;
comment|/* # of free clusters */
name|u_int
name|NumBad
decl_stmt|;
comment|/* # of bad clusters */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fatEntry
block|{
name|cl_t
name|next
decl_stmt|;
comment|/* pointer to next cluster */
name|cl_t
name|head
decl_stmt|;
comment|/* pointer to start of chain */
name|u_int32_t
name|length
decl_stmt|;
comment|/* number of clusters on chain */
name|int
name|flags
decl_stmt|;
comment|/* see below */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CLUST_FREE
value|0
end_define

begin_comment
comment|/* 0 means cluster is free */
end_comment

begin_define
define|#
directive|define
name|CLUST_FIRST
value|2
end_define

begin_comment
comment|/* 2 is the minimum valid cluster number */
end_comment

begin_define
define|#
directive|define
name|CLUST_RSRVD
value|0xfffffff6
end_define

begin_comment
comment|/* start of reserved clusters */
end_comment

begin_define
define|#
directive|define
name|CLUST_BAD
value|0xfffffff7
end_define

begin_comment
comment|/* a cluster with a defect */
end_comment

begin_define
define|#
directive|define
name|CLUST_EOFS
value|0xfffffff8
end_define

begin_comment
comment|/* start of EOF indicators */
end_comment

begin_define
define|#
directive|define
name|CLUST_EOF
value|0xffffffff
end_define

begin_comment
comment|/* standard value for last cluster */
end_comment

begin_comment
comment|/*  * Masks for cluster values  */
end_comment

begin_define
define|#
directive|define
name|CLUST12_MASK
value|0xfff
end_define

begin_define
define|#
directive|define
name|CLUST16_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|CLUST32_MASK
value|0xfffffff
end_define

begin_define
define|#
directive|define
name|FAT_USED
value|1
end_define

begin_comment
comment|/* This fat chain is used in a file */
end_comment

begin_define
define|#
directive|define
name|DOSLONGNAMELEN
value|256
end_define

begin_comment
comment|/* long name maximal length */
end_comment

begin_define
define|#
directive|define
name|LRFIRST
value|0x40
end_define

begin_comment
comment|/* first long name record */
end_comment

begin_define
define|#
directive|define
name|LRNOMASK
value|0x1f
end_define

begin_comment
comment|/* mask to extract long record 					 * sequence number */
end_comment

begin_comment
comment|/*  * Architecture independent description of a directory entry  */
end_comment

begin_struct
struct|struct
name|dosDirEntry
block|{
name|struct
name|dosDirEntry
modifier|*
name|parent
decl_stmt|,
comment|/* previous tree level */
modifier|*
name|next
decl_stmt|,
comment|/* next brother */
modifier|*
name|child
decl_stmt|;
comment|/* if this is a directory */
name|char
name|name
index|[
literal|8
operator|+
literal|1
operator|+
literal|3
operator|+
literal|1
index|]
decl_stmt|;
comment|/* alias name first part */
name|char
name|lname
index|[
name|DOSLONGNAMELEN
index|]
decl_stmt|;
comment|/* real name */
name|uint
name|flags
decl_stmt|;
comment|/* attributes */
name|cl_t
name|head
decl_stmt|;
comment|/* cluster no */
name|u_int32_t
name|size
decl_stmt|;
comment|/* filesize in bytes */
name|uint
name|fsckflags
decl_stmt|;
comment|/* flags during fsck */
block|}
struct|;
end_struct

begin_comment
comment|/* Flags in fsckflags: */
end_comment

begin_define
define|#
directive|define
name|DIREMPTY
value|1
end_define

begin_define
define|#
directive|define
name|DIREMPWARN
value|2
end_define

begin_comment
comment|/*  *  TODO-list of unread directories  */
end_comment

begin_struct
struct|struct
name|dirTodoNode
block|{
name|struct
name|dosDirEntry
modifier|*
name|dir
decl_stmt|;
name|struct
name|dirTodoNode
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

