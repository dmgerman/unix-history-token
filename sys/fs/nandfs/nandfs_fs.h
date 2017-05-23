begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010-2012 Semihalf  * Copyright (c) 2008, 2009 Reinoud Zandijk  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Original definitions written by Koji Sato<koji@osrg.net>  *                    and Ryusuke Konishi<ryusuke@osrg.net>  * From: NetBSD: nandfs_fs.h,v 1.1 2009/07/18 16:31:42 reinoud  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NANDFS_FS_H
end_ifndef

begin_define
define|#
directive|define
name|_NANDFS_FS_H
end_define

begin_include
include|#
directive|include
file|<sys/uuid.h>
end_include

begin_define
define|#
directive|define
name|MNINDIR
parameter_list|(
name|fsdev
parameter_list|)
value|((fsdev)->nd_blocksize / sizeof(nandfs_daddr_t))
end_define

begin_comment
comment|/*  * Inode structure. There are a few dedicated inode numbers that are  * defined here first.  */
end_comment

begin_define
define|#
directive|define
name|NANDFS_WHT_INO
value|1
end_define

begin_comment
comment|/* Whiteout ino			*/
end_comment

begin_define
define|#
directive|define
name|NANDFS_ROOT_INO
value|2
end_define

begin_comment
comment|/* Root file inode		*/
end_comment

begin_define
define|#
directive|define
name|NANDFS_DAT_INO
value|3
end_define

begin_comment
comment|/* DAT file			*/
end_comment

begin_define
define|#
directive|define
name|NANDFS_CPFILE_INO
value|4
end_define

begin_comment
comment|/* checkpoint file		*/
end_comment

begin_define
define|#
directive|define
name|NANDFS_SUFILE_INO
value|5
end_define

begin_comment
comment|/* segment usage file		*/
end_comment

begin_define
define|#
directive|define
name|NANDFS_IFILE_INO
value|6
end_define

begin_comment
comment|/* ifile			*/
end_comment

begin_define
define|#
directive|define
name|NANDFS_GC_INO
value|7
end_define

begin_comment
comment|/* Cleanerd node		*/
end_comment

begin_define
define|#
directive|define
name|NANDFS_ATIME_INO
value|8
end_define

begin_comment
comment|/* Atime file (reserved)	*/
end_comment

begin_define
define|#
directive|define
name|NANDFS_XATTR_INO
value|9
end_define

begin_comment
comment|/* Xattribute file (reserved)	*/
end_comment

begin_define
define|#
directive|define
name|NANDFS_SKETCH_INO
value|10
end_define

begin_comment
comment|/* Sketch file (obsolete)	*/
end_comment

begin_define
define|#
directive|define
name|NANDFS_USER_INO
value|11
end_define

begin_comment
comment|/* First user's file inode number */
end_comment

begin_define
define|#
directive|define
name|NANDFS_SYS_NODE
parameter_list|(
name|ino
parameter_list|)
define|\
value|(((ino)>= NANDFS_DAT_INO)&& ((ino)<= NANDFS_GC_INO))
end_define

begin_define
define|#
directive|define
name|NANDFS_NDADDR
value|12
end_define

begin_comment
comment|/* Direct addresses in inode. */
end_comment

begin_define
define|#
directive|define
name|NANDFS_NIADDR
value|3
end_define

begin_comment
comment|/* Indirect addresses in inode. */
end_comment

begin_typedef
typedef|typedef
name|int64_t
name|nandfs_daddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|nandfs_lbn_t
typedef|;
end_typedef

begin_struct
struct|struct
name|nandfs_inode
block|{
name|uint64_t
name|i_blocks
decl_stmt|;
comment|/* 0: size in device blocks		*/
name|uint64_t
name|i_size
decl_stmt|;
comment|/* 8: size in bytes			*/
name|uint64_t
name|i_ctime
decl_stmt|;
comment|/* 16: creation time in seconds		*/
name|uint64_t
name|i_mtime
decl_stmt|;
comment|/* 24: modification time in seconds part*/
name|uint32_t
name|i_ctime_nsec
decl_stmt|;
comment|/* 32: creation time nanoseconds part	*/
name|uint32_t
name|i_mtime_nsec
decl_stmt|;
comment|/* 36: modification time in nanoseconds	*/
name|uint32_t
name|i_uid
decl_stmt|;
comment|/* 40: user id				*/
name|uint32_t
name|i_gid
decl_stmt|;
comment|/* 44: group id				*/
name|uint16_t
name|i_mode
decl_stmt|;
comment|/* 48: file mode			*/
name|uint16_t
name|i_links_count
decl_stmt|;
comment|/* 50: number of references to the inode*/
name|uint32_t
name|i_flags
decl_stmt|;
comment|/* 52: NANDFS_*_FL flags		*/
name|nandfs_daddr_t
name|i_special
decl_stmt|;
comment|/* 56: special				*/
name|nandfs_daddr_t
name|i_db
index|[
name|NANDFS_NDADDR
index|]
decl_stmt|;
comment|/* 64: Direct disk blocks.		*/
name|nandfs_daddr_t
name|i_ib
index|[
name|NANDFS_NIADDR
index|]
decl_stmt|;
comment|/* 160: Indirect disk blocks.	*/
name|uint64_t
name|i_xattr
decl_stmt|;
comment|/* 184: reserved for extended attributes*/
name|uint32_t
name|i_generation
decl_stmt|;
comment|/* 192: file generation for NFS		*/
name|uint32_t
name|i_pad
index|[
literal|15
index|]
decl_stmt|;
comment|/* 196: make it 64 bits aligned		*/
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|nandfs_inode
argument_list|)
operator|==
literal|256
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Each checkpoint/snapshot has a super root.  *  * The super root holds the inodes of the three system files: `dat', `cp' and  * 'su' files. All other FS state is defined by those.  *  * It is CRC checksum'ed and time stamped.  */
end_comment

begin_struct
struct|struct
name|nandfs_super_root
block|{
name|uint32_t
name|sr_sum
decl_stmt|;
comment|/* check-sum				*/
name|uint16_t
name|sr_bytes
decl_stmt|;
comment|/* byte count of this structure		*/
name|uint16_t
name|sr_flags
decl_stmt|;
comment|/* reserved for flags			*/
name|uint64_t
name|sr_nongc_ctime
decl_stmt|;
comment|/* timestamp, not for cleaner(?)	*/
name|struct
name|nandfs_inode
name|sr_dat
decl_stmt|;
comment|/* DAT, virt->phys translation inode	*/
name|struct
name|nandfs_inode
name|sr_cpfile
decl_stmt|;
comment|/* CP, checkpoints inode		*/
name|struct
name|nandfs_inode
name|sr_sufile
decl_stmt|;
comment|/* SU, segment usage inode		*/
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NANDFS_SR_MDT_OFFSET
parameter_list|(
name|inode_size
parameter_list|,
name|i
parameter_list|)
define|\
value|((uint32_t)&((struct nandfs_super_root *)0)->sr_dat +	\ 	(inode_size) * (i))
end_define

begin_define
define|#
directive|define
name|NANDFS_SR_DAT_OFFSET
parameter_list|(
name|inode_size
parameter_list|)
value|NANDFS_SR_MDT_OFFSET(inode_size, 0)
end_define

begin_define
define|#
directive|define
name|NANDFS_SR_CPFILE_OFFSET
parameter_list|(
name|inode_size
parameter_list|)
value|NANDFS_SR_MDT_OFFSET(inode_size, 1)
end_define

begin_define
define|#
directive|define
name|NANDFS_SR_SUFILE_OFFSET
parameter_list|(
name|inode_size
parameter_list|)
value|NANDFS_SR_MDT_OFFSET(inode_size, 2)
end_define

begin_define
define|#
directive|define
name|NANDFS_SR_BYTES
value|(sizeof(struct nandfs_super_root))
end_define

begin_comment
comment|/*  * The superblock describes the basic structure and mount history. It also  * records some sizes of structures found on the disc for sanity checks.  *  * The superblock is stored at two places: NANDFS_SB_OFFSET_BYTES and  * NANDFS_SB2_OFFSET_BYTES.  */
end_comment

begin_comment
comment|/* File system states stored on media in superblock's sbp->s_state */
end_comment

begin_define
define|#
directive|define
name|NANDFS_VALID_FS
value|0x0001
end_define

begin_comment
comment|/* cleanly unmounted and all is ok  */
end_comment

begin_define
define|#
directive|define
name|NANDFS_ERROR_FS
value|0x0002
end_define

begin_comment
comment|/* there were errors detected, fsck */
end_comment

begin_define
define|#
directive|define
name|NANDFS_RESIZE_FS
value|0x0004
end_define

begin_comment
comment|/* resize required, XXX unknown flag*/
end_comment

begin_define
define|#
directive|define
name|NANDFS_MOUNT_STATE_BITS
value|"\20\1VALID_FS\2ERROR_FS\3RESIZE_FS"
end_define

begin_comment
comment|/*  * Brief description of control structures:  *  * NANDFS_NFSAREAS first blocks contain fsdata and some amount of super blocks.  * Simple round-robin policy is used in order to choose which block will  * contain new super block.  *  * Simple case with 2 blocks:  * 1: fsdata sblock1 [sblock3 [sblock5 ..]]  * 2: fsdata sblock2 [sblock4 [sblock6 ..]]  */
end_comment

begin_struct
struct|struct
name|nandfs_fsdata
block|{
name|uint16_t
name|f_magic
decl_stmt|;
name|uint16_t
name|f_bytes
decl_stmt|;
name|uint32_t
name|f_sum
decl_stmt|;
comment|/* checksum of fsdata		*/
name|uint32_t
name|f_rev_level
decl_stmt|;
comment|/* major disk format revision	*/
name|uint64_t
name|f_ctime
decl_stmt|;
comment|/* creation time (execution time 					   of newfs)			*/
comment|/* Block size represented as: blocksize = 1<< (f_log_block_size + 10)	*/
name|uint32_t
name|f_log_block_size
decl_stmt|;
name|uint16_t
name|f_inode_size
decl_stmt|;
comment|/* size of an inode		*/
name|uint16_t
name|f_dat_entry_size
decl_stmt|;
comment|/* size of a dat entry		*/
name|uint16_t
name|f_checkpoint_size
decl_stmt|;
comment|/* size of a checkpoint		*/
name|uint16_t
name|f_segment_usage_size
decl_stmt|;
comment|/* size of a segment usage	*/
name|uint16_t
name|f_sbbytes
decl_stmt|;
comment|/* byte count of CRC calculation 						   for super blocks. s_reserved 						   is excluded!			*/
name|uint16_t
name|f_errors
decl_stmt|;
comment|/* behaviour on detecting errors	*/
name|uint32_t
name|f_erasesize
decl_stmt|;
name|uint64_t
name|f_nsegments
decl_stmt|;
comment|/* number of segm. in filesystem	*/
name|nandfs_daddr_t
name|f_first_data_block
decl_stmt|;
comment|/* 1st seg disk block number		*/
name|uint32_t
name|f_blocks_per_segment
decl_stmt|;
comment|/* number of blocks per segment		*/
name|uint32_t
name|f_r_segments_percentage
decl_stmt|;
comment|/* reserved segments percentage		*/
name|struct
name|uuid
name|f_uuid
decl_stmt|;
comment|/* 128-bit uuid for volume		*/
name|char
name|f_volume_name
index|[
literal|16
index|]
decl_stmt|;
comment|/* volume name				*/
name|uint32_t
name|f_pad
index|[
literal|104
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|nandfs_fsdata
argument_list|)
operator|==
literal|512
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|nandfs_super_block
block|{
name|uint16_t
name|s_magic
decl_stmt|;
comment|/* magic value for identification */
name|uint32_t
name|s_sum
decl_stmt|;
comment|/* check sum of super block       */
name|uint64_t
name|s_last_cno
decl_stmt|;
comment|/* last checkpoint number         */
name|uint64_t
name|s_last_pseg
decl_stmt|;
comment|/* addr part. segm. written last  */
name|uint64_t
name|s_last_seq
decl_stmt|;
comment|/* seq.number of seg written last */
name|uint64_t
name|s_free_blocks_count
decl_stmt|;
comment|/* free blocks count              */
name|uint64_t
name|s_mtime
decl_stmt|;
comment|/* mount time                     */
name|uint64_t
name|s_wtime
decl_stmt|;
comment|/* write time                     */
name|uint16_t
name|s_state
decl_stmt|;
comment|/* file system state              */
name|char
name|s_last_mounted
index|[
literal|64
index|]
decl_stmt|;
comment|/* directory where last mounted   */
name|uint32_t
name|s_c_interval
decl_stmt|;
comment|/* commit interval of segment     */
name|uint32_t
name|s_c_block_max
decl_stmt|;
comment|/* threshold of data amount for 						   the segment construction */
name|uint32_t
name|s_reserved
index|[
literal|32
index|]
decl_stmt|;
comment|/* padding to end of the block    */
block|}
name|__packed
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|nandfs_super_block
argument_list|)
operator|==
literal|256
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NANDFS_FSDATA_MAGIC
value|0xf8da
end_define

begin_define
define|#
directive|define
name|NANDFS_SUPER_MAGIC
value|0x8008
end_define

begin_define
define|#
directive|define
name|NANDFS_NFSAREAS
value|4
end_define

begin_define
define|#
directive|define
name|NANDFS_DATA_OFFSET_BYTES
parameter_list|(
name|esize
parameter_list|)
value|(NANDFS_NFSAREAS * (esize))
end_define

begin_define
define|#
directive|define
name|NANDFS_SBLOCK_OFFSET_BYTES
value|(sizeof(struct nandfs_fsdata))
end_define

begin_define
define|#
directive|define
name|NANDFS_DEF_BLOCKSIZE
value|4096
end_define

begin_define
define|#
directive|define
name|NANDFS_MIN_BLOCKSIZE
value|512
end_define

begin_define
define|#
directive|define
name|NANDFS_DEF_ERASESIZE
value|(2<< 16)
end_define

begin_define
define|#
directive|define
name|NANDFS_MIN_SEGSIZE
value|NANDFS_DEF_ERASESIZE
end_define

begin_define
define|#
directive|define
name|NANDFS_CURRENT_REV
value|9
end_define

begin_comment
comment|/* current major revision */
end_comment

begin_define
define|#
directive|define
name|NANDFS_FSDATA_CRC_BYTES
value|offsetof(struct nandfs_fsdata, f_pad)
end_define

begin_comment
comment|/* Bytes count of super_block for CRC-calculation */
end_comment

begin_define
define|#
directive|define
name|NANDFS_SB_BYTES
value|offsetof(struct nandfs_super_block, s_reserved)
end_define

begin_comment
comment|/* Maximal count of links to a file */
end_comment

begin_define
define|#
directive|define
name|NANDFS_LINK_MAX
value|32000
end_define

begin_comment
comment|/*  * Structure of a directory entry.  *  * Note that they can't span blocks; the rec_len fills out.  */
end_comment

begin_define
define|#
directive|define
name|NANDFS_NAME_LEN
value|255
end_define

begin_struct
struct|struct
name|nandfs_dir_entry
block|{
name|uint64_t
name|inode
decl_stmt|;
comment|/* inode number */
name|uint16_t
name|rec_len
decl_stmt|;
comment|/* directory entry length */
name|uint8_t
name|name_len
decl_stmt|;
comment|/* name length */
name|uint8_t
name|file_type
decl_stmt|;
name|char
name|name
index|[
name|NANDFS_NAME_LEN
index|]
decl_stmt|;
comment|/* file name */
name|char
name|pad
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * NANDFS_DIR_PAD defines the directory entries boundaries  *  * NOTE: It must be a multiple of 8  */
end_comment

begin_define
define|#
directive|define
name|NANDFS_DIR_PAD
value|8
end_define

begin_define
define|#
directive|define
name|NANDFS_DIR_ROUND
value|(NANDFS_DIR_PAD - 1)
end_define

begin_define
define|#
directive|define
name|NANDFS_DIR_NAME_OFFSET
value|(offsetof(struct nandfs_dir_entry, name))
end_define

begin_define
define|#
directive|define
name|NANDFS_DIR_REC_LEN
parameter_list|(
name|name_len
parameter_list|)
define|\
value|(((name_len) + NANDFS_DIR_NAME_OFFSET + NANDFS_DIR_ROUND)	\& ~NANDFS_DIR_ROUND)
end_define

begin_define
define|#
directive|define
name|NANDFS_DIR_NAME_LEN
parameter_list|(
name|name_len
parameter_list|)
define|\
value|(NANDFS_DIR_REC_LEN(name_len) - NANDFS_DIR_NAME_OFFSET)
end_define

begin_comment
comment|/*  * NiLFS/NANDFS devides the disc into fixed length segments. Each segment is  * filled with one or more partial segments of variable lengths.  *  * Each partial segment has a segment summary header followed by updates of  * files and optionally a super root.  */
end_comment

begin_comment
comment|/*  * Virtual to physical block translation information. For data blocks it maps  * logical block number bi_blkoff to virtual block nr bi_vblocknr. For non  * datablocks it is the virtual block number assigned to an indirect block  * and has no bi_blkoff. The physical block number is the next  * available data block in the partial segment after all the binfo's.  */
end_comment

begin_struct
struct|struct
name|nandfs_binfo_v
block|{
name|uint64_t
name|bi_ino
decl_stmt|;
comment|/* file's inode			     */
name|uint64_t
name|bi_vblocknr
decl_stmt|;
comment|/* assigned virtual block number     */
name|uint64_t
name|bi_blkoff
decl_stmt|;
comment|/* for file's logical block number   */
block|}
struct|;
end_struct

begin_comment
comment|/*  * DAT allocation. For data blocks just the logical block number that maps on  * the next available data block in the partial segment after the binfo's.  */
end_comment

begin_struct
struct|struct
name|nandfs_binfo_dat
block|{
name|uint64_t
name|bi_ino
decl_stmt|;
name|uint64_t
name|bi_blkoff
decl_stmt|;
comment|/* DAT file's logical block number */
name|uint8_t
name|bi_level
decl_stmt|;
comment|/* whether this is meta block */
name|uint8_t
name|bi_pad
index|[
literal|7
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|nandfs_binfo_v
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
expr|struct
name|nandfs_binfo_dat
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Convenience union for both types of binfo's */
end_comment

begin_union
union|union
name|nandfs_binfo
block|{
name|struct
name|nandfs_binfo_v
name|bi_v
decl_stmt|;
name|struct
name|nandfs_binfo_dat
name|bi_dat
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* Indirect buffers path */
end_comment

begin_struct
struct|struct
name|nandfs_indir
block|{
name|nandfs_daddr_t
name|in_lbn
decl_stmt|;
name|int
name|in_off
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The (partial) segment summary */
end_comment

begin_struct
struct|struct
name|nandfs_segment_summary
block|{
name|uint32_t
name|ss_datasum
decl_stmt|;
comment|/* CRC of complete data block        */
name|uint32_t
name|ss_sumsum
decl_stmt|;
comment|/* CRC of segment summary only       */
name|uint32_t
name|ss_magic
decl_stmt|;
comment|/* magic to identify segment summary */
name|uint16_t
name|ss_bytes
decl_stmt|;
comment|/* size of segment summary structure */
name|uint16_t
name|ss_flags
decl_stmt|;
comment|/* NANDFS_SS_* flags                  */
name|uint64_t
name|ss_seq
decl_stmt|;
comment|/* sequence number of this segm. sum */
name|uint64_t
name|ss_create
decl_stmt|;
comment|/* creation timestamp in seconds     */
name|uint64_t
name|ss_next
decl_stmt|;
comment|/* blocknumber of next segment       */
name|uint32_t
name|ss_nblocks
decl_stmt|;
comment|/* number of blocks used by summary  */
name|uint32_t
name|ss_nbinfos
decl_stmt|;
comment|/* number of binfo structures	     */
name|uint32_t
name|ss_sumbytes
decl_stmt|;
comment|/* total size of segment summary     */
name|uint32_t
name|ss_pad
decl_stmt|;
comment|/* stream of binfo structures */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NANDFS_SEGSUM_MAGIC
value|0x8e680011
end_define

begin_comment
comment|/* segment summary magic number */
end_comment

begin_comment
comment|/* Segment summary flags */
end_comment

begin_define
define|#
directive|define
name|NANDFS_SS_LOGBGN
value|0x0001
end_define

begin_comment
comment|/* begins a logical segment */
end_comment

begin_define
define|#
directive|define
name|NANDFS_SS_LOGEND
value|0x0002
end_define

begin_comment
comment|/* ends a logical segment */
end_comment

begin_define
define|#
directive|define
name|NANDFS_SS_SR
value|0x0004
end_define

begin_comment
comment|/* has super root */
end_comment

begin_define
define|#
directive|define
name|NANDFS_SS_SYNDT
value|0x0008
end_define

begin_comment
comment|/* includes data only updates */
end_comment

begin_define
define|#
directive|define
name|NANDFS_SS_GC
value|0x0010
end_define

begin_comment
comment|/* segment written for cleaner operation */
end_comment

begin_define
define|#
directive|define
name|NANDFS_SS_FLAG_BITS
value|"\20\1LOGBGN\2LOGEND\3SR\4SYNDT\5GC"
end_define

begin_comment
comment|/* Segment summary constrains */
end_comment

begin_define
define|#
directive|define
name|NANDFS_SEG_MIN_BLOCKS
value|16
end_define

begin_comment
comment|/* minimum number of blocks in a 					   full segment */
end_comment

begin_define
define|#
directive|define
name|NANDFS_PSEG_MIN_BLOCKS
value|2
end_define

begin_comment
comment|/* minimum number of blocks in a 					   partial segment */
end_comment

begin_define
define|#
directive|define
name|NANDFS_MIN_NRSVSEGS
value|8
end_define

begin_comment
comment|/* minimum number of reserved 					   segments */
end_comment

begin_comment
comment|/*  * Structure of DAT/inode file.  *  * A DAT file is divided into groups. The maximum number of groups is the  * number of block group descriptors that fit into one block; this descriptor  * only gives the number of free entries in the associated group.  *  * Each group has a block sized bitmap indicating if an entry is taken or  * empty. Each bit stands for a DAT entry.  *  * The inode file has exactly the same format only the entries are inode  * entries.  */
end_comment

begin_struct
struct|struct
name|nandfs_block_group_desc
block|{
name|uint32_t
name|bg_nfrees
decl_stmt|;
comment|/* num. free entries in block group  */
block|}
struct|;
end_struct

begin_comment
comment|/* DAT entry in a super root's DAT file */
end_comment

begin_struct
struct|struct
name|nandfs_dat_entry
block|{
name|uint64_t
name|de_blocknr
decl_stmt|;
comment|/* block number                      */
name|uint64_t
name|de_start
decl_stmt|;
comment|/* valid from checkpoint             */
name|uint64_t
name|de_end
decl_stmt|;
comment|/* valid till checkpoint             */
name|uint64_t
name|de_rsv
decl_stmt|;
comment|/* reserved for future use           */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure of CP file.  *  * A snapshot is just a checkpoint only it's protected against removal by the  * cleaner. The snapshots are kept on a double linked list of checkpoints.  */
end_comment

begin_struct
struct|struct
name|nandfs_snapshot_list
block|{
name|uint64_t
name|ssl_next
decl_stmt|;
comment|/* checkpoint nr. forward */
name|uint64_t
name|ssl_prev
decl_stmt|;
comment|/* checkpoint nr. back    */
block|}
struct|;
end_struct

begin_comment
comment|/* Checkpoint entry structure */
end_comment

begin_struct
struct|struct
name|nandfs_checkpoint
block|{
name|uint32_t
name|cp_flags
decl_stmt|;
comment|/* NANDFS_CHECKPOINT_* flags          */
name|uint32_t
name|cp_checkpoints_count
decl_stmt|;
comment|/* ZERO, not used anymore?           */
name|struct
name|nandfs_snapshot_list
name|cp_snapshot_list
decl_stmt|;
comment|/* list of snapshots   */
name|uint64_t
name|cp_cno
decl_stmt|;
comment|/* checkpoint number                 */
name|uint64_t
name|cp_create
decl_stmt|;
comment|/* creation timestamp                */
name|uint64_t
name|cp_nblk_inc
decl_stmt|;
comment|/* number of blocks incremented      */
name|uint64_t
name|cp_blocks_count
decl_stmt|;
comment|/* reserved (might be deleted)       */
name|struct
name|nandfs_inode
name|cp_ifile_inode
decl_stmt|;
comment|/* inode file inode          */
block|}
struct|;
end_struct

begin_comment
comment|/* Checkpoint flags */
end_comment

begin_define
define|#
directive|define
name|NANDFS_CHECKPOINT_SNAPSHOT
value|1
end_define

begin_define
define|#
directive|define
name|NANDFS_CHECKPOINT_INVALID
value|2
end_define

begin_define
define|#
directive|define
name|NANDFS_CHECKPOINT_SKETCH
value|4
end_define

begin_define
define|#
directive|define
name|NANDFS_CHECKPOINT_MINOR
value|8
end_define

begin_define
define|#
directive|define
name|NANDFS_CHECKPOINT_BITS
value|"\20\1SNAPSHOT\2INVALID\3SKETCH\4MINOR"
end_define

begin_comment
comment|/* Header of the checkpoint file */
end_comment

begin_struct
struct|struct
name|nandfs_cpfile_header
block|{
name|uint64_t
name|ch_ncheckpoints
decl_stmt|;
comment|/* number of checkpoints             */
name|uint64_t
name|ch_nsnapshots
decl_stmt|;
comment|/* number of snapshots               */
name|struct
name|nandfs_snapshot_list
name|ch_snapshot_list
decl_stmt|;
comment|/* snapshot list     */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NANDFS_CPFILE_FIRST_CHECKPOINT_OFFSET
define|\
value|((sizeof(struct nandfs_cpfile_header) +		\ 	sizeof(struct nandfs_checkpoint) - 1) /		\ 	sizeof(struct nandfs_checkpoint))
end_define

begin_define
define|#
directive|define
name|NANDFS_NOSEGMENT
value|0xffffffff
end_define

begin_comment
comment|/*  * Structure of SU file.  *  * The segment usage file sums up how each of the segments are used. They are  * indexed by their segment number.  */
end_comment

begin_comment
comment|/* Segment usage entry */
end_comment

begin_struct
struct|struct
name|nandfs_segment_usage
block|{
name|uint64_t
name|su_lastmod
decl_stmt|;
comment|/* last modified timestamp           */
name|uint32_t
name|su_nblocks
decl_stmt|;
comment|/* number of blocks in segment       */
name|uint32_t
name|su_flags
decl_stmt|;
comment|/* NANDFS_SEGMENT_USAGE_* flags       */
block|}
struct|;
end_struct

begin_comment
comment|/* Segment usage flag */
end_comment

begin_define
define|#
directive|define
name|NANDFS_SEGMENT_USAGE_ACTIVE
value|1
end_define

begin_define
define|#
directive|define
name|NANDFS_SEGMENT_USAGE_DIRTY
value|2
end_define

begin_define
define|#
directive|define
name|NANDFS_SEGMENT_USAGE_ERROR
value|4
end_define

begin_define
define|#
directive|define
name|NANDFS_SEGMENT_USAGE_GC
value|8
end_define

begin_define
define|#
directive|define
name|NANDFS_SEGMENT_USAGE_BITS
value|"\20\1ACTIVE\2DIRTY\3ERROR"
end_define

begin_comment
comment|/* Header of the segment usage file */
end_comment

begin_struct
struct|struct
name|nandfs_sufile_header
block|{
name|uint64_t
name|sh_ncleansegs
decl_stmt|;
comment|/* number of segments marked clean   */
name|uint64_t
name|sh_ndirtysegs
decl_stmt|;
comment|/* number of segments marked dirty   */
name|uint64_t
name|sh_last_alloc
decl_stmt|;
comment|/* last allocated segment number     */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NANDFS_SUFILE_FIRST_SEGMENT_USAGE_OFFSET
define|\
value|((sizeof(struct nandfs_sufile_header) +		\ 	sizeof(struct nandfs_segment_usage) - 1) /	\ 	sizeof(struct nandfs_segment_usage))
end_define

begin_struct
struct|struct
name|nandfs_seg_stat
block|{
name|uint64_t
name|nss_nsegs
decl_stmt|;
name|uint64_t
name|nss_ncleansegs
decl_stmt|;
name|uint64_t
name|nss_ndirtysegs
decl_stmt|;
name|uint64_t
name|nss_ctime
decl_stmt|;
name|uint64_t
name|nss_nongc_ctime
decl_stmt|;
name|uint64_t
name|nss_prot_seq
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|NANDFS_CHECKPOINT
block|,
name|NANDFS_SNAPSHOT
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|NANDFS_CPINFO_MAX
value|512
end_define

begin_struct
struct|struct
name|nandfs_cpinfo
block|{
name|uint32_t
name|nci_flags
decl_stmt|;
name|uint32_t
name|nci_pad
decl_stmt|;
name|uint64_t
name|nci_cno
decl_stmt|;
name|uint64_t
name|nci_create
decl_stmt|;
name|uint64_t
name|nci_nblk_inc
decl_stmt|;
name|uint64_t
name|nci_blocks_count
decl_stmt|;
name|uint64_t
name|nci_next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NANDFS_SEGMENTS_MAX
value|512
end_define

begin_struct
struct|struct
name|nandfs_suinfo
block|{
name|uint64_t
name|nsi_num
decl_stmt|;
name|uint64_t
name|nsi_lastmod
decl_stmt|;
name|uint32_t
name|nsi_blocks
decl_stmt|;
name|uint32_t
name|nsi_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NANDFS_VINFO_MAX
value|512
end_define

begin_struct
struct|struct
name|nandfs_vinfo
block|{
name|uint64_t
name|nvi_ino
decl_stmt|;
name|uint64_t
name|nvi_vblocknr
decl_stmt|;
name|uint64_t
name|nvi_start
decl_stmt|;
name|uint64_t
name|nvi_end
decl_stmt|;
name|uint64_t
name|nvi_blocknr
decl_stmt|;
name|int
name|nvi_alive
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nandfs_cpmode
block|{
name|uint64_t
name|ncpm_cno
decl_stmt|;
name|uint32_t
name|ncpm_mode
decl_stmt|;
name|uint32_t
name|ncpm_pad
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nandfs_argv
block|{
name|uint64_t
name|nv_base
decl_stmt|;
name|uint32_t
name|nv_nmembs
decl_stmt|;
name|uint16_t
name|nv_size
decl_stmt|;
name|uint16_t
name|nv_flags
decl_stmt|;
name|uint64_t
name|nv_index
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nandfs_cpstat
block|{
name|uint64_t
name|ncp_cno
decl_stmt|;
name|uint64_t
name|ncp_ncps
decl_stmt|;
name|uint64_t
name|ncp_nss
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nandfs_period
block|{
name|uint64_t
name|p_start
decl_stmt|;
name|uint64_t
name|p_end
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nandfs_vdesc
block|{
name|uint64_t
name|vd_ino
decl_stmt|;
name|uint64_t
name|vd_cno
decl_stmt|;
name|uint64_t
name|vd_vblocknr
decl_stmt|;
name|struct
name|nandfs_period
name|vd_period
decl_stmt|;
name|uint64_t
name|vd_blocknr
decl_stmt|;
name|uint64_t
name|vd_offset
decl_stmt|;
name|uint32_t
name|vd_flags
decl_stmt|;
name|uint32_t
name|vd_pad
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nandfs_bdesc
block|{
name|uint64_t
name|bd_ino
decl_stmt|;
name|uint64_t
name|bd_oblocknr
decl_stmt|;
name|uint64_t
name|bd_blocknr
decl_stmt|;
name|uint64_t
name|bd_offset
decl_stmt|;
name|uint32_t
name|bd_level
decl_stmt|;
name|uint32_t
name|bd_alive
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|MNAMELEN
end_ifndef

begin_define
define|#
directive|define
name|MNAMELEN
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|nandfs_fsinfo
block|{
name|struct
name|nandfs_fsdata
name|fs_fsdata
decl_stmt|;
name|struct
name|nandfs_super_block
name|fs_super
decl_stmt|;
name|char
name|fs_dev
index|[
name|MNAMELEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NANDFS_MAX_MOUNTS
value|65535
end_define

begin_define
define|#
directive|define
name|NANDFS_IOCTL_GET_SUSTAT
value|_IOR('N', 100, struct nandfs_seg_stat)
end_define

begin_define
define|#
directive|define
name|NANDFS_IOCTL_CHANGE_CPMODE
value|_IOWR('N', 101, struct nandfs_cpmode)
end_define

begin_define
define|#
directive|define
name|NANDFS_IOCTL_GET_CPINFO
value|_IOWR('N', 102, struct nandfs_argv)
end_define

begin_define
define|#
directive|define
name|NANDFS_IOCTL_DELETE_CP
value|_IOWR('N', 103, uint64_t[2])
end_define

begin_define
define|#
directive|define
name|NANDFS_IOCTL_GET_CPSTAT
value|_IOR('N', 104, struct nandfs_cpstat)
end_define

begin_define
define|#
directive|define
name|NANDFS_IOCTL_GET_SUINFO
value|_IOWR('N', 105, struct nandfs_argv)
end_define

begin_define
define|#
directive|define
name|NANDFS_IOCTL_GET_VINFO
value|_IOWR('N', 106, struct nandfs_argv)
end_define

begin_define
define|#
directive|define
name|NANDFS_IOCTL_GET_BDESCS
value|_IOWR('N', 107, struct nandfs_argv)
end_define

begin_define
define|#
directive|define
name|NANDFS_IOCTL_GET_FSINFO
value|_IOR('N', 108, struct nandfs_fsinfo)
end_define

begin_define
define|#
directive|define
name|NANDFS_IOCTL_MAKE_SNAP
value|_IOWR('N', 109, uint64_t)
end_define

begin_define
define|#
directive|define
name|NANDFS_IOCTL_DELETE_SNAP
value|_IOWR('N', 110, uint64_t)
end_define

begin_define
define|#
directive|define
name|NANDFS_IOCTL_SYNC
value|_IOWR('N', 111, uint64_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NANDFS_FS_H */
end_comment

end_unit

