begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002 Networks Associates Technology, Inc.  * All rights reserved.  *  * This software was developed for the FreeBSD Project by Marshall  * Kirk McKusick and Network Associates Laboratories, the Security  * Research Division of Network Associates, Inc. under DARPA/SPAWAR  * contract N66001-01-C-8035 ("CBOSS"), as part of the DARPA CHATS  * research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Copyright (c) 1980, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)fsck.h	8.4 (Berkeley) 5/9/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FSCK_H_
end_ifndef

begin_define
define|#
directive|define
name|_FSCK_H_
end_define

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_define
define|#
directive|define
name|MAXDUP
value|10
end_define

begin_comment
comment|/* limit on dup blks (per inode) */
end_comment

begin_define
define|#
directive|define
name|MAXBAD
value|10
end_define

begin_comment
comment|/* limit on bad blks (per inode) */
end_comment

begin_define
define|#
directive|define
name|MINBUFS
value|10
end_define

begin_comment
comment|/* minimum number of buffers required */
end_comment

begin_define
define|#
directive|define
name|MAXBUFS
value|40
end_define

begin_comment
comment|/* maximum space to allocate to buffers */
end_comment

begin_define
define|#
directive|define
name|INOBUFSIZE
value|64*1024
end_define

begin_comment
comment|/* size of buffer to read inodes in pass1 */
end_comment

begin_define
define|#
directive|define
name|ZEROBUFSIZE
value|(dev_bsize * 128)
end_define

begin_comment
comment|/* size of zero buffer used by -Z */
end_comment

begin_union
union|union
name|dinode
block|{
name|struct
name|ufs1_dinode
name|dp1
decl_stmt|;
name|struct
name|ufs2_dinode
name|dp2
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|DIP
parameter_list|(
name|dp
parameter_list|,
name|field
parameter_list|)
define|\
value|((sblock.fs_magic == FS_UFS1_MAGIC) ? \ 	(dp)->dp1.field : (dp)->dp2.field)
end_define

begin_define
define|#
directive|define
name|DIP_SET
parameter_list|(
name|dp
parameter_list|,
name|field
parameter_list|,
name|val
parameter_list|)
value|do { \ 	if (sblock.fs_magic == FS_UFS1_MAGIC) \ 		(dp)->dp1.field = (val); \ 	else \ 		(dp)->dp2.field = (val); \ 	} while (0)
end_define

begin_comment
comment|/*  * Each inode on the file system is described by the following structure.  * The linkcnt is initially set to the value in the inode. Each time it  * is found during the descent in passes 2, 3, and 4 the count is  * decremented. Any inodes whose count is non-zero after pass 4 needs to  * have its link count adjusted by the value remaining in ino_linkcnt.  */
end_comment

begin_struct
struct|struct
name|inostat
block|{
name|char
name|ino_state
decl_stmt|;
comment|/* state of inode, see below */
name|char
name|ino_type
decl_stmt|;
comment|/* type of inode */
name|short
name|ino_linkcnt
decl_stmt|;
comment|/* number of links not found */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Inode states.  */
end_comment

begin_define
define|#
directive|define
name|USTATE
value|0x1
end_define

begin_comment
comment|/* inode not allocated */
end_comment

begin_define
define|#
directive|define
name|FSTATE
value|0x2
end_define

begin_comment
comment|/* inode is file */
end_comment

begin_define
define|#
directive|define
name|FZLINK
value|0x3
end_define

begin_comment
comment|/* inode is file with a link count of zero */
end_comment

begin_define
define|#
directive|define
name|DSTATE
value|0x4
end_define

begin_comment
comment|/* inode is directory */
end_comment

begin_define
define|#
directive|define
name|DZLINK
value|0x5
end_define

begin_comment
comment|/* inode is directory with a zero link count  */
end_comment

begin_define
define|#
directive|define
name|DFOUND
value|0x6
end_define

begin_comment
comment|/* directory found during descent */
end_comment

begin_comment
comment|/*     		0x7		   UNUSED - see S_IS_DVALID() definition */
end_comment

begin_define
define|#
directive|define
name|DCLEAR
value|0x8
end_define

begin_comment
comment|/* directory is to be cleared */
end_comment

begin_define
define|#
directive|define
name|FCLEAR
value|0x9
end_define

begin_comment
comment|/* file is to be cleared */
end_comment

begin_comment
comment|/*     	DUNFOUND === (state == DSTATE || state == DZLINK) */
end_comment

begin_define
define|#
directive|define
name|S_IS_DUNFOUND
parameter_list|(
name|state
parameter_list|)
value|(((state)& ~0x1) == DSTATE)
end_define

begin_comment
comment|/*     	DVALID   === (state == DSTATE || state == DZLINK || state == DFOUND) */
end_comment

begin_define
define|#
directive|define
name|S_IS_DVALID
parameter_list|(
name|state
parameter_list|)
value|(((state)& ~0x3) == DSTATE)
end_define

begin_define
define|#
directive|define
name|INO_IS_DUNFOUND
parameter_list|(
name|ino
parameter_list|)
value|S_IS_DUNFOUND(inoinfo(ino)->ino_state)
end_define

begin_define
define|#
directive|define
name|INO_IS_DVALID
parameter_list|(
name|ino
parameter_list|)
value|S_IS_DVALID(inoinfo(ino)->ino_state)
end_define

begin_comment
comment|/*  * Inode state information is contained on per cylinder group lists  * which are described by the following structure.  */
end_comment

begin_struct
struct|struct
name|inostatlist
block|{
name|long
name|il_numalloced
decl_stmt|;
comment|/* number of inodes allocated in this cg */
name|struct
name|inostat
modifier|*
name|il_stat
decl_stmt|;
comment|/* inostat info for this cylinder group */
block|}
modifier|*
name|inostathead
struct|;
end_struct

begin_comment
comment|/*  * buffer cache structure.  */
end_comment

begin_struct
struct|struct
name|bufarea
block|{
name|TAILQ_ENTRY
argument_list|(
argument|bufarea
argument_list|)
name|b_list
expr_stmt|;
comment|/* buffer list */
name|ufs2_daddr_t
name|b_bno
decl_stmt|;
name|int
name|b_size
decl_stmt|;
name|int
name|b_errs
decl_stmt|;
name|int
name|b_flags
decl_stmt|;
name|int
name|b_type
decl_stmt|;
union|union
block|{
name|char
modifier|*
name|b_buf
decl_stmt|;
comment|/* buffer space */
name|ufs1_daddr_t
modifier|*
name|b_indir1
decl_stmt|;
comment|/* UFS1 indirect block */
name|ufs2_daddr_t
modifier|*
name|b_indir2
decl_stmt|;
comment|/* UFS2 indirect block */
name|struct
name|fs
modifier|*
name|b_fs
decl_stmt|;
comment|/* super block */
name|struct
name|cg
modifier|*
name|b_cg
decl_stmt|;
comment|/* cylinder group */
name|struct
name|ufs1_dinode
modifier|*
name|b_dinode1
decl_stmt|;
comment|/* UFS1 inode block */
name|struct
name|ufs2_dinode
modifier|*
name|b_dinode2
decl_stmt|;
comment|/* UFS2 inode block */
block|}
name|b_un
union|;
name|char
name|b_dirty
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IBLK
parameter_list|(
name|bp
parameter_list|,
name|i
parameter_list|)
define|\
value|((sblock.fs_magic == FS_UFS1_MAGIC) ? \ 	(bp)->b_un.b_indir1[i] : (bp)->b_un.b_indir2[i])
end_define

begin_define
define|#
directive|define
name|IBLK_SET
parameter_list|(
name|bp
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|do { \ 	if (sblock.fs_magic == FS_UFS1_MAGIC) \ 		(bp)->b_un.b_indir1[i] = (val); \ 	else \ 		(bp)->b_un.b_indir2[i] = (val); \ 	} while (0)
end_define

begin_comment
comment|/*  * Buffer flags  */
end_comment

begin_define
define|#
directive|define
name|B_INUSE
value|0x00000001
end_define

begin_comment
comment|/* Buffer is in use */
end_comment

begin_comment
comment|/*  * Type of data in buffer  */
end_comment

begin_define
define|#
directive|define
name|BT_UNKNOWN
value|0
end_define

begin_comment
comment|/* Buffer holds a superblock */
end_comment

begin_define
define|#
directive|define
name|BT_SUPERBLK
value|1
end_define

begin_comment
comment|/* Buffer holds a superblock */
end_comment

begin_define
define|#
directive|define
name|BT_CYLGRP
value|2
end_define

begin_comment
comment|/* Buffer holds a cylinder group map */
end_comment

begin_define
define|#
directive|define
name|BT_LEVEL1
value|3
end_define

begin_comment
comment|/* Buffer holds single level indirect */
end_comment

begin_define
define|#
directive|define
name|BT_LEVEL2
value|4
end_define

begin_comment
comment|/* Buffer holds double level indirect */
end_comment

begin_define
define|#
directive|define
name|BT_LEVEL3
value|5
end_define

begin_comment
comment|/* Buffer holds triple level indirect */
end_comment

begin_define
define|#
directive|define
name|BT_EXTATTR
value|6
end_define

begin_comment
comment|/* Buffer holds external attribute data */
end_comment

begin_define
define|#
directive|define
name|BT_INODES
value|7
end_define

begin_comment
comment|/* Buffer holds external attribute data */
end_comment

begin_define
define|#
directive|define
name|BT_DIRDATA
value|8
end_define

begin_comment
comment|/* Buffer holds directory data */
end_comment

begin_define
define|#
directive|define
name|BT_DATA
value|9
end_define

begin_comment
comment|/* Buffer holds user data */
end_comment

begin_define
define|#
directive|define
name|BT_NUMBUFTYPES
value|10
end_define

begin_define
define|#
directive|define
name|BT_NAMES
value|{			\ 	"unknown",			\ 	"Superblock",			\ 	"Cylinder Group",		\ 	"Single Level Indirect",	\ 	"Double Level Indirect",	\ 	"Triple Level Indirect",	\ 	"External Attribute",		\ 	"Inode Block",			\ 	"Directory Contents",		\ 	"User Data" }
end_define

begin_decl_stmt
specifier|extern
name|long
name|readcnt
index|[
name|BT_NUMBUFTYPES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|totalreadcnt
index|[
name|BT_NUMBUFTYPES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|timespec
name|readtime
index|[
name|BT_NUMBUFTYPES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|timespec
name|totalreadtime
index|[
name|BT_NUMBUFTYPES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|timespec
name|startprog
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|bufarea
name|sblk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file system superblock */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|bufarea
modifier|*
name|pdirbp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current directory contents */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|bufarea
modifier|*
name|pbp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current inode block */
end_comment

begin_define
define|#
directive|define
name|dirty
parameter_list|(
name|bp
parameter_list|)
value|do { \ 	if (fswritefd< 0) \ 		pfatal("SETTING DIRTY FLAG IN READ_ONLY MODE\n"); \ 	else \ 		(bp)->b_dirty = 1; \ } while (0)
end_define

begin_define
define|#
directive|define
name|initbarea
parameter_list|(
name|bp
parameter_list|,
name|type
parameter_list|)
value|do { \ 	(bp)->b_dirty = 0; \ 	(bp)->b_bno = (ufs2_daddr_t)-1; \ 	(bp)->b_flags = 0; \ 	(bp)->b_type = type; \ } while (0)
end_define

begin_define
define|#
directive|define
name|sbdirty
parameter_list|()
value|dirty(&sblk)
end_define

begin_define
define|#
directive|define
name|sblock
value|(*sblk.b_un.b_fs)
end_define

begin_enum
enum|enum
name|fixstate
block|{
name|DONTKNOW
block|,
name|NOFIX
block|,
name|FIX
block|,
name|IGNORE
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|ino_t
name|cursnapshot
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|inodesc
block|{
name|enum
name|fixstate
name|id_fix
decl_stmt|;
comment|/* policy on fixing errors */
name|int
function_decl|(
modifier|*
name|id_func
function_decl|)
parameter_list|(
name|struct
name|inodesc
modifier|*
parameter_list|)
function_decl|;
comment|/* function to be applied to blocks of inode */
name|ino_t
name|id_number
decl_stmt|;
comment|/* inode number described */
name|ino_t
name|id_parent
decl_stmt|;
comment|/* for DATA nodes, their parent */
name|ufs_lbn_t
name|id_lbn
decl_stmt|;
comment|/* logical block number of current block */
name|ufs2_daddr_t
name|id_blkno
decl_stmt|;
comment|/* current block number being examined */
name|int
name|id_numfrags
decl_stmt|;
comment|/* number of frags contained in block */
name|off_t
name|id_filesize
decl_stmt|;
comment|/* for DATA nodes, the size of the directory */
name|ufs2_daddr_t
name|id_entryno
decl_stmt|;
comment|/* for DATA nodes, current entry number */
name|int
name|id_loc
decl_stmt|;
comment|/* for DATA nodes, current location in dir */
name|struct
name|direct
modifier|*
name|id_dirp
decl_stmt|;
comment|/* for DATA nodes, ptr to current entry */
name|char
modifier|*
name|id_name
decl_stmt|;
comment|/* for DATA nodes, name to find or enter */
name|char
name|id_type
decl_stmt|;
comment|/* type of descriptor, DATA or ADDR */
block|}
struct|;
end_struct

begin_comment
comment|/* file types */
end_comment

begin_define
define|#
directive|define
name|DATA
value|1
end_define

begin_comment
comment|/* a directory */
end_comment

begin_define
define|#
directive|define
name|SNAP
value|2
end_define

begin_comment
comment|/* a snapshot */
end_comment

begin_define
define|#
directive|define
name|ADDR
value|3
end_define

begin_comment
comment|/* anything but a directory or a snapshot */
end_comment

begin_comment
comment|/*  * Linked list of duplicate blocks.  *  * The list is composed of two parts. The first part of the  * list (from duplist through the node pointed to by muldup)  * contains a single copy of each duplicate block that has been  * found. The second part of the list (from muldup to the end)  * contains duplicate blocks that have been found more than once.  * To check if a block has been found as a duplicate it is only  * necessary to search from duplist through muldup. To find the  * total number of times that a block has been found as a duplicate  * the entire list must be searched for occurrences of the block  * in question. The following diagram shows a sample list where  * w (found twice), x (found once), y (found three times), and z  * (found once) are duplicate block numbers:  *  *    w -> y -> x -> z -> y -> w -> y  *    ^		     ^  *    |		     |  * duplist	  muldup  */
end_comment

begin_struct
struct|struct
name|dups
block|{
name|struct
name|dups
modifier|*
name|next
decl_stmt|;
name|ufs2_daddr_t
name|dup
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|dups
modifier|*
name|duplist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of dup list */
end_comment

begin_decl_stmt
name|struct
name|dups
modifier|*
name|muldup
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of unique duplicate dup block numbers */
end_comment

begin_comment
comment|/*  * Inode cache data structures.  */
end_comment

begin_struct
struct|struct
name|inoinfo
block|{
name|struct
name|inoinfo
modifier|*
name|i_nexthash
decl_stmt|;
comment|/* next entry in hash chain */
name|ino_t
name|i_number
decl_stmt|;
comment|/* inode number of this entry */
name|ino_t
name|i_parent
decl_stmt|;
comment|/* inode number of parent */
name|ino_t
name|i_dotdot
decl_stmt|;
comment|/* inode number of `..' */
name|size_t
name|i_isize
decl_stmt|;
comment|/* size of inode */
name|u_int
name|i_numblks
decl_stmt|;
comment|/* size of block array in bytes */
name|ufs2_daddr_t
name|i_blks
index|[
literal|1
index|]
decl_stmt|;
comment|/* actually longer */
block|}
modifier|*
modifier|*
name|inphead
struct|,
modifier|*
modifier|*
name|inpsort
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|long
name|dirhash
decl_stmt|,
name|inplast
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|numdirs
decl_stmt|,
name|listmax
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|countdirs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of directories we actually found */
end_comment

begin_define
define|#
directive|define
name|MIBSIZE
value|3
end_define

begin_comment
comment|/* size of fsck sysctl MIBs */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|adjrefcnt
index|[
name|MIBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MIB command to adjust inode reference cnt */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|adjblkcnt
index|[
name|MIBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MIB command to adjust inode block count */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|adjndir
index|[
name|MIBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MIB command to adjust number of directories */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|adjnbfree
index|[
name|MIBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MIB command to adjust number of free blocks */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|adjnifree
index|[
name|MIBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MIB command to adjust number of free inodes */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|adjnffree
index|[
name|MIBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MIB command to adjust number of free frags */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|adjnumclusters
index|[
name|MIBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MIB command to adjust number of free clusters */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|freefiles
index|[
name|MIBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MIB command to free a set of files */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|freedirs
index|[
name|MIBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MIB command to free a set of directories */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|freeblks
index|[
name|MIBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MIB command to free a set of data blocks */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|fsck_cmd
name|cmd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sysctl file system update commands */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|snapname
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* when doing snapshots, the name of the file */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|cdevname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of device being checked */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|dev_bsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* computed value of DEV_BSIZE */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|secsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* actual disk sector size */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|real_dev_bsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* actual disk sector size, not overridden */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|nflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* assume a no response */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|yflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* assume a yes response */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|bkgrdflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use a snapshot to run on an active system */
end_comment

begin_decl_stmt
specifier|extern
name|ufs2_daddr_t
name|bflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* location of alternate super block */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output debugging info */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Eflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* delete empty data blocks */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Zflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* zero empty data blocks */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|inoopt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* trim out unused inodes */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|ckclean
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* only do work if not cleanly unmounted */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cvtlevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* convert to newer file system format */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|bkgrdcheck
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* determine if background check is possible */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|bkgrdsumadj
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* whether the kernel have ability to adjust superblock summary */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|usedsoftdep
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* just fix soft dependency inconsistencies */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|preen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* just fix normal inconsistencies */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|rerun
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rerun fsck. Only used in non-preen mode */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|returntosingle
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 => return to single user mode on exit */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|resolved
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cleared if unresolved changes => not clean */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|havesb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* superblock has been read */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|skipclean
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* skip clean file systems if preening */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|fsmodified
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 => write done to file system */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|fsreadfd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file descriptor for reading file system */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|fswritefd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file descriptor for writing file system */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|surrender
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Give up if reads fail */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|wantrestart
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Restart fsck on early termination */
end_comment

begin_decl_stmt
specifier|extern
name|ufs2_daddr_t
name|maxfsblock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of blocks in the file system */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|blockmap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to primary blk allocation map */
end_comment

begin_decl_stmt
specifier|extern
name|ino_t
name|maxino
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of inodes in file system */
end_comment

begin_decl_stmt
specifier|extern
name|ino_t
name|lfdir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lost& found directory inode number */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|lfname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lost& found directory name */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lfmode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lost& found directory creation mode */
end_comment

begin_decl_stmt
specifier|extern
name|ufs2_daddr_t
name|n_blks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of blocks in use */
end_comment

begin_decl_stmt
specifier|extern
name|ino_t
name|n_files
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of files in use */
end_comment

begin_decl_stmt
specifier|extern
specifier|volatile
name|sig_atomic_t
name|got_siginfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* received a SIGINFO */
end_comment

begin_decl_stmt
specifier|extern
specifier|volatile
name|sig_atomic_t
name|got_sigalarm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* received a SIGALRM */
end_comment

begin_define
define|#
directive|define
name|clearinode
parameter_list|(
name|dp
parameter_list|)
define|\
value|if (sblock.fs_magic == FS_UFS1_MAGIC) { \ 		(dp)->dp1 = ufs1_zino; \ 	} else { \ 		(dp)->dp2 = ufs2_zino; \ 	}
end_define

begin_decl_stmt
specifier|extern
name|struct
name|ufs1_dinode
name|ufs1_zino
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ufs2_dinode
name|ufs2_zino
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|setbmap
parameter_list|(
name|blkno
parameter_list|)
value|setbit(blockmap, blkno)
end_define

begin_define
define|#
directive|define
name|testbmap
parameter_list|(
name|blkno
parameter_list|)
value|isset(blockmap, blkno)
end_define

begin_define
define|#
directive|define
name|clrbmap
parameter_list|(
name|blkno
parameter_list|)
value|clrbit(blockmap, blkno)
end_define

begin_define
define|#
directive|define
name|STOP
value|0x01
end_define

begin_define
define|#
directive|define
name|SKIP
value|0x02
end_define

begin_define
define|#
directive|define
name|KEEPON
value|0x04
end_define

begin_define
define|#
directive|define
name|ALTERED
value|0x08
end_define

begin_define
define|#
directive|define
name|FOUND
value|0x10
end_define

begin_define
define|#
directive|define
name|EEXIT
value|8
end_define

begin_comment
comment|/* Standard error exit. */
end_comment

begin_define
define|#
directive|define
name|ERESTART
value|-1
end_define

begin_function_decl
name|int
name|flushentry
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Wrapper for malloc() that flushes the cylinder group cache to try   * to get space.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|Malloc
parameter_list|(
name|size_t
name|size
parameter_list|)
block|{
name|void
modifier|*
name|retval
decl_stmt|;
while|while
condition|(
operator|(
name|retval
operator|=
name|malloc
argument_list|(
name|size
argument_list|)
operator|)
operator|==
name|NULL
condition|)
if|if
condition|(
name|flushentry
argument_list|()
operator|==
literal|0
condition|)
break|break;
return|return
operator|(
name|retval
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Wrapper for calloc() that flushes the cylinder group cache to try   * to get space.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|Calloc
parameter_list|(
name|size_t
name|cnt
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
name|void
modifier|*
name|retval
decl_stmt|;
while|while
condition|(
operator|(
name|retval
operator|=
name|calloc
argument_list|(
name|cnt
argument_list|,
name|size
argument_list|)
operator|)
operator|==
name|NULL
condition|)
if|if
condition|(
name|flushentry
argument_list|()
operator|==
literal|0
condition|)
break|break;
return|return
operator|(
name|retval
operator|)
return|;
block|}
end_function

begin_struct_decl
struct_decl|struct
name|fstab
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|adjust
parameter_list|(
name|struct
name|inodesc
modifier|*
parameter_list|,
name|int
name|lcnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ufs2_daddr_t
name|allocblk
parameter_list|(
name|long
name|frags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ino_t
name|allocdir
parameter_list|(
name|ino_t
name|parent
parameter_list|,
name|ino_t
name|request
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ino_t
name|allocino
parameter_list|(
name|ino_t
name|request
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|blkerror
parameter_list|(
name|ino_t
name|ino
parameter_list|,
specifier|const
name|char
modifier|*
name|type
parameter_list|,
name|ufs2_daddr_t
name|blk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|blockcheck
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|blread
parameter_list|(
name|int
name|fd
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|ufs2_daddr_t
name|blk
parameter_list|,
name|long
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bufinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|blwrite
parameter_list|(
name|int
name|fd
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|ufs2_daddr_t
name|blk
parameter_list|,
name|ssize_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|blerase
parameter_list|(
name|int
name|fd
parameter_list|,
name|ufs2_daddr_t
name|blk
parameter_list|,
name|long
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|blzero
parameter_list|(
name|int
name|fd
parameter_list|,
name|ufs2_daddr_t
name|blk
parameter_list|,
name|long
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cacheino
parameter_list|(
name|union
name|dinode
modifier|*
name|dp
parameter_list|,
name|ino_t
name|inumber
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|catch
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|catchquit
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|changeino
parameter_list|(
name|ino_t
name|dir
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|ino_t
name|newnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|check_cgmagic
parameter_list|(
name|int
name|cg
parameter_list|,
name|struct
name|bufarea
modifier|*
name|cgbp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chkrange
parameter_list|(
name|ufs2_daddr_t
name|blk
parameter_list|,
name|int
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ckfini
parameter_list|(
name|int
name|markclean
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ckinode
parameter_list|(
name|union
name|dinode
modifier|*
name|dp
parameter_list|,
name|struct
name|inodesc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clri
parameter_list|(
name|struct
name|inodesc
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|type
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|clearentry
parameter_list|(
name|struct
name|inodesc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|direrror
parameter_list|(
name|ino_t
name|ino
parameter_list|,
specifier|const
name|char
modifier|*
name|errmesg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dirscan
parameter_list|(
name|struct
name|inodesc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dofix
parameter_list|(
name|struct
name|inodesc
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eascan
parameter_list|(
name|struct
name|inodesc
modifier|*
parameter_list|,
name|struct
name|ufs2_dinode
modifier|*
name|dp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fileerror
parameter_list|(
name|ino_t
name|cwd
parameter_list|,
name|ino_t
name|ino
parameter_list|,
specifier|const
name|char
modifier|*
name|errmesg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|finalIOstats
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|findino
parameter_list|(
name|struct
name|inodesc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|findname
parameter_list|(
name|struct
name|inodesc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|flush
parameter_list|(
name|int
name|fd
parameter_list|,
name|struct
name|bufarea
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freeblk
parameter_list|(
name|ufs2_daddr_t
name|blkno
parameter_list|,
name|long
name|frags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freeino
parameter_list|(
name|ino_t
name|ino
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freeinodebuf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fsutilinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ftypeok
parameter_list|(
name|union
name|dinode
modifier|*
name|dp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|getblk
parameter_list|(
name|struct
name|bufarea
modifier|*
name|bp
parameter_list|,
name|ufs2_daddr_t
name|blk
parameter_list|,
name|long
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bufarea
modifier|*
name|cgget
parameter_list|(
name|int
name|cg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bufarea
modifier|*
name|getdatablk
parameter_list|(
name|ufs2_daddr_t
name|blkno
parameter_list|,
name|long
name|size
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|inoinfo
modifier|*
name|getinoinfo
parameter_list|(
name|ino_t
name|inumber
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|union
name|dinode
modifier|*
name|getnextinode
parameter_list|(
name|ino_t
name|inumber
parameter_list|,
name|int
name|rebuildcg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|getpathname
parameter_list|(
name|char
modifier|*
name|namebuf
parameter_list|,
name|ino_t
name|curdir
parameter_list|,
name|ino_t
name|ino
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|union
name|dinode
modifier|*
name|ginode
parameter_list|(
name|ino_t
name|inumber
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|infohandler
parameter_list|(
name|int
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|alarmhandler
parameter_list|(
name|int
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|inocleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|inodirty
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|inostat
modifier|*
name|inoinfo
parameter_list|(
name|ino_t
name|inum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|IOstats
parameter_list|(
name|char
modifier|*
name|what
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linkup
parameter_list|(
name|ino_t
name|orphan
parameter_list|,
name|ino_t
name|parentdir
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|makeentry
parameter_list|(
name|ino_t
name|parent
parameter_list|,
name|ino_t
name|ino
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|panic
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|pass1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pass1b
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pass1check
parameter_list|(
name|struct
name|inodesc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pass2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pass3
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pass4
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pass4check
parameter_list|(
name|struct
name|inodesc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pass5
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pfatal
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|pinode
parameter_list|(
name|ino_t
name|ino
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|propagate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pwarn
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|readsb
parameter_list|(
name|int
name|listerr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|reply
parameter_list|(
specifier|const
name|char
modifier|*
name|question
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rwerror
parameter_list|(
specifier|const
name|char
modifier|*
name|mesg
parameter_list|,
name|ufs2_daddr_t
name|blk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sblock_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setinodebuf
parameter_list|(
name|ino_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setup
parameter_list|(
name|char
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gjournal_check
parameter_list|(
specifier|const
name|char
modifier|*
name|filesys
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|suj_check
parameter_list|(
specifier|const
name|char
modifier|*
name|filesys
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|update_maps
parameter_list|(
name|struct
name|cg
modifier|*
parameter_list|,
name|struct
name|cg
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fsckinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FSCK_H_ */
end_comment

end_unit

