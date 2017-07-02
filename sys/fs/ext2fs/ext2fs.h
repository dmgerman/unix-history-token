begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  *  modified for EXT2FS support in Lites 1.1  *  *  Aug 1995, Godmar Back (gback@cs.utah.edu)  *  University of Utah, Department of Computer Science  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2009 Aditya Sarawgi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FS_EXT2FS_EXT2FS_H_
end_ifndef

begin_define
define|#
directive|define
name|_FS_EXT2FS_EXT2FS_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/*  * Super block for an ext2fs file system.  */
end_comment

begin_struct
struct|struct
name|ext2fs
block|{
name|uint32_t
name|e2fs_icount
decl_stmt|;
comment|/* Inode count */
name|uint32_t
name|e2fs_bcount
decl_stmt|;
comment|/* blocks count */
name|uint32_t
name|e2fs_rbcount
decl_stmt|;
comment|/* reserved blocks count */
name|uint32_t
name|e2fs_fbcount
decl_stmt|;
comment|/* free blocks count */
name|uint32_t
name|e2fs_ficount
decl_stmt|;
comment|/* free inodes count */
name|uint32_t
name|e2fs_first_dblock
decl_stmt|;
comment|/* first data block */
name|uint32_t
name|e2fs_log_bsize
decl_stmt|;
comment|/* block size = 1024*(2^e2fs_log_bsize) */
name|uint32_t
name|e2fs_log_fsize
decl_stmt|;
comment|/* fragment size */
name|uint32_t
name|e2fs_bpg
decl_stmt|;
comment|/* blocks per group */
name|uint32_t
name|e2fs_fpg
decl_stmt|;
comment|/* frags per group */
name|uint32_t
name|e2fs_ipg
decl_stmt|;
comment|/* inodes per group */
name|uint32_t
name|e2fs_mtime
decl_stmt|;
comment|/* mount time */
name|uint32_t
name|e2fs_wtime
decl_stmt|;
comment|/* write time */
name|uint16_t
name|e2fs_mnt_count
decl_stmt|;
comment|/* mount count */
name|uint16_t
name|e2fs_max_mnt_count
decl_stmt|;
comment|/* max mount count */
name|uint16_t
name|e2fs_magic
decl_stmt|;
comment|/* magic number */
name|uint16_t
name|e2fs_state
decl_stmt|;
comment|/* file system state */
name|uint16_t
name|e2fs_beh
decl_stmt|;
comment|/* behavior on errors */
name|uint16_t
name|e2fs_minrev
decl_stmt|;
comment|/* minor revision level */
name|uint32_t
name|e2fs_lastfsck
decl_stmt|;
comment|/* time of last fsck */
name|uint32_t
name|e2fs_fsckintv
decl_stmt|;
comment|/* max time between fscks */
name|uint32_t
name|e2fs_creator
decl_stmt|;
comment|/* creator OS */
name|uint32_t
name|e2fs_rev
decl_stmt|;
comment|/* revision level */
name|uint16_t
name|e2fs_ruid
decl_stmt|;
comment|/* default uid for reserved blocks */
name|uint16_t
name|e2fs_rgid
decl_stmt|;
comment|/* default gid for reserved blocks */
comment|/* EXT2_DYNAMIC_REV superblocks */
name|uint32_t
name|e2fs_first_ino
decl_stmt|;
comment|/* first non-reserved inode */
name|uint16_t
name|e2fs_inode_size
decl_stmt|;
comment|/* size of inode structure */
name|uint16_t
name|e2fs_block_group_nr
decl_stmt|;
comment|/* block grp number of this sblk*/
name|uint32_t
name|e2fs_features_compat
decl_stmt|;
comment|/* compatible feature set */
name|uint32_t
name|e2fs_features_incompat
decl_stmt|;
comment|/* incompatible feature set */
name|uint32_t
name|e2fs_features_rocompat
decl_stmt|;
comment|/* RO-compatible feature set */
name|uint8_t
name|e2fs_uuid
index|[
literal|16
index|]
decl_stmt|;
comment|/* 128-bit uuid for volume */
name|char
name|e2fs_vname
index|[
literal|16
index|]
decl_stmt|;
comment|/* volume name */
name|char
name|e2fs_fsmnt
index|[
literal|64
index|]
decl_stmt|;
comment|/* name mounted on */
name|uint32_t
name|e2fs_algo
decl_stmt|;
comment|/* For compression */
name|uint8_t
name|e2fs_prealloc
decl_stmt|;
comment|/* # of blocks for old prealloc */
name|uint8_t
name|e2fs_dir_prealloc
decl_stmt|;
comment|/* # of blocks for old prealloc dirs */
name|uint16_t
name|e2fs_reserved_ngdb
decl_stmt|;
comment|/* # of reserved gd blocks for resize */
name|char
name|e3fs_journal_uuid
index|[
literal|16
index|]
decl_stmt|;
comment|/* uuid of journal superblock */
name|uint32_t
name|e3fs_journal_inum
decl_stmt|;
comment|/* inode number of journal file */
name|uint32_t
name|e3fs_journal_dev
decl_stmt|;
comment|/* device number of journal file */
name|uint32_t
name|e3fs_last_orphan
decl_stmt|;
comment|/* start of list of inodes to delete */
name|uint32_t
name|e3fs_hash_seed
index|[
literal|4
index|]
decl_stmt|;
comment|/* HTREE hash seed */
name|char
name|e3fs_def_hash_version
decl_stmt|;
comment|/* Default hash version to use */
name|char
name|e3fs_jnl_backup_type
decl_stmt|;
name|uint16_t
name|e3fs_desc_size
decl_stmt|;
comment|/* size of group descriptor */
name|uint32_t
name|e3fs_default_mount_opts
decl_stmt|;
name|uint32_t
name|e3fs_first_meta_bg
decl_stmt|;
comment|/* First metablock block group */
name|uint32_t
name|e3fs_mkfs_time
decl_stmt|;
comment|/* when the fs was created */
name|uint32_t
name|e3fs_jnl_blks
index|[
literal|17
index|]
decl_stmt|;
comment|/* backup of the journal inode */
name|uint32_t
name|e4fs_bcount_hi
decl_stmt|;
comment|/* high bits of blocks count */
name|uint32_t
name|e4fs_rbcount_hi
decl_stmt|;
comment|/* high bits of reserved blocks count */
name|uint32_t
name|e4fs_fbcount_hi
decl_stmt|;
comment|/* high bits of free blocks count */
name|uint16_t
name|e4fs_min_extra_isize
decl_stmt|;
comment|/* all inodes have some bytes */
name|uint16_t
name|e4fs_want_extra_isize
decl_stmt|;
comment|/* inodes must reserve some bytes */
name|uint32_t
name|e4fs_flags
decl_stmt|;
comment|/* miscellaneous flags */
name|uint16_t
name|e4fs_raid_stride
decl_stmt|;
comment|/* RAID stride */
name|uint16_t
name|e4fs_mmpintv
decl_stmt|;
comment|/* seconds to wait in MMP checking */
name|uint64_t
name|e4fs_mmpblk
decl_stmt|;
comment|/* block for multi-mount protection */
name|uint32_t
name|e4fs_raid_stripe_wid
decl_stmt|;
comment|/* blocks on data disks (N * stride) */
name|uint8_t
name|e4fs_log_gpf
decl_stmt|;
comment|/* FLEX_BG group size */
name|uint8_t
name|e4fs_chksum_type
decl_stmt|;
comment|/* metadata checksum algorithm used */
name|uint8_t
name|e4fs_encrypt
decl_stmt|;
comment|/* versioning level for encryption */
name|uint8_t
name|e4fs_reserved_pad
decl_stmt|;
name|uint64_t
name|e4fs_kbytes_written
decl_stmt|;
comment|/* number of lifetime kilobytes */
name|uint32_t
name|e4fs_snapinum
decl_stmt|;
comment|/* inode number of active snapshot */
name|uint32_t
name|e4fs_snapid
decl_stmt|;
comment|/* sequential ID of active snapshot */
name|uint64_t
name|e4fs_snaprbcount
decl_stmt|;
comment|/* reserved blocks for active snapshot */
name|uint32_t
name|e4fs_snaplist
decl_stmt|;
comment|/* inode number for on-disk snapshot */
name|uint32_t
name|e4fs_errcount
decl_stmt|;
comment|/* number of file system errors */
name|uint32_t
name|e4fs_first_errtime
decl_stmt|;
comment|/* first time an error happened */
name|uint32_t
name|e4fs_first_errino
decl_stmt|;
comment|/* inode involved in first error */
name|uint64_t
name|e4fs_first_errblk
decl_stmt|;
comment|/* block involved of first error */
name|uint8_t
name|e4fs_first_errfunc
index|[
literal|32
index|]
decl_stmt|;
comment|/* function where error happened */
name|uint32_t
name|e4fs_first_errline
decl_stmt|;
comment|/* line number where error happened */
name|uint32_t
name|e4fs_last_errtime
decl_stmt|;
comment|/* most recent time of an error */
name|uint32_t
name|e4fs_last_errino
decl_stmt|;
comment|/* inode involved in last error */
name|uint32_t
name|e4fs_last_errline
decl_stmt|;
comment|/* line number where error happened */
name|uint64_t
name|e4fs_last_errblk
decl_stmt|;
comment|/* block involved of last error */
name|uint8_t
name|e4fs_last_errfunc
index|[
literal|32
index|]
decl_stmt|;
comment|/* function where error happened */
name|uint8_t
name|e4fs_mount_opts
index|[
literal|64
index|]
decl_stmt|;
name|uint32_t
name|e4fs_usrquota_inum
decl_stmt|;
comment|/* inode for tracking user quota */
name|uint32_t
name|e4fs_grpquota_inum
decl_stmt|;
comment|/* inode for tracking group quota */
name|uint32_t
name|e4fs_overhead_clusters
decl_stmt|;
comment|/* overhead blocks/clusters */
name|uint32_t
name|e4fs_backup_bgs
index|[
literal|2
index|]
decl_stmt|;
comment|/* groups with sparse_super2 SBs */
name|uint8_t
name|e4fs_encrypt_algos
index|[
literal|4
index|]
decl_stmt|;
comment|/* encryption algorithms in use */
name|uint8_t
name|e4fs_encrypt_pw_salt
index|[
literal|16
index|]
decl_stmt|;
comment|/* salt used for string2key */
name|uint32_t
name|e4fs_lpf_ino
decl_stmt|;
comment|/* location of the lost+found inode */
name|uint32_t
name|e4fs_proj_quota_inum
decl_stmt|;
comment|/* inode for tracking project quota */
name|uint32_t
name|e4fs_chksum_seed
decl_stmt|;
comment|/* checksum seed */
name|uint32_t
name|e4fs_reserved
index|[
literal|98
index|]
decl_stmt|;
comment|/* padding to the end of the block */
name|uint32_t
name|e4fs_sbchksum
decl_stmt|;
comment|/* superblock checksum */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The path name on which the file system is mounted is maintained  * in fs_fsmnt. MAXMNTLEN defines the amount of space allocated in  * the super block for this name.  */
end_comment

begin_define
define|#
directive|define
name|MAXMNTLEN
value|512
end_define

begin_comment
comment|/*  * In-Memory Superblock  */
end_comment

begin_struct
struct|struct
name|m_ext2fs
block|{
name|struct
name|ext2fs
modifier|*
name|e2fs
decl_stmt|;
name|char
name|e2fs_fsmnt
index|[
name|MAXMNTLEN
index|]
decl_stmt|;
comment|/* name mounted on */
name|char
name|e2fs_ronly
decl_stmt|;
comment|/* mounted read-only flag */
name|char
name|e2fs_fmod
decl_stmt|;
comment|/* super block modified flag */
name|uint32_t
name|e2fs_bsize
decl_stmt|;
comment|/* Block size */
name|uint32_t
name|e2fs_bshift
decl_stmt|;
comment|/* calc of logical block no */
name|uint32_t
name|e2fs_bpg
decl_stmt|;
comment|/* Number of blocks per group */
name|int64_t
name|e2fs_qbmask
decl_stmt|;
comment|/* = s_blocksize -1 */
name|uint32_t
name|e2fs_fsbtodb
decl_stmt|;
comment|/* Shift to get disk block */
name|uint32_t
name|e2fs_ipg
decl_stmt|;
comment|/* Number of inodes per group */
name|uint32_t
name|e2fs_ipb
decl_stmt|;
comment|/* Number of inodes per block */
name|uint32_t
name|e2fs_itpg
decl_stmt|;
comment|/* Number of inode table per group */
name|uint32_t
name|e2fs_fsize
decl_stmt|;
comment|/* Size of fragments per block */
name|uint32_t
name|e2fs_fpb
decl_stmt|;
comment|/* Number of fragments per block */
name|uint32_t
name|e2fs_fpg
decl_stmt|;
comment|/* Number of fragments per group */
name|uint32_t
name|e2fs_gdbcount
decl_stmt|;
comment|/* Number of group descriptors */
name|uint32_t
name|e2fs_gcount
decl_stmt|;
comment|/* Number of groups */
name|uint32_t
name|e2fs_isize
decl_stmt|;
comment|/* Size of inode */
name|uint32_t
name|e2fs_total_dir
decl_stmt|;
comment|/* Total number of directories */
name|uint8_t
modifier|*
name|e2fs_contigdirs
decl_stmt|;
comment|/* (u) # of contig. allocated dirs */
name|char
name|e2fs_wasvalid
decl_stmt|;
comment|/* valid at mount time */
name|off_t
name|e2fs_maxfilesize
decl_stmt|;
name|struct
name|ext2_gd
modifier|*
name|e2fs_gd
decl_stmt|;
comment|/* Group Descriptors */
name|int32_t
name|e2fs_contigsumsize
decl_stmt|;
comment|/* size of cluster summary array */
name|int32_t
modifier|*
name|e2fs_maxcluster
decl_stmt|;
comment|/* max cluster in each cyl group */
name|struct
name|csum
modifier|*
name|e2fs_clustersum
decl_stmt|;
comment|/* cluster summary in each cyl group */
name|int32_t
name|e2fs_uhash
decl_stmt|;
comment|/* 3 if hash should be signed, 0 if not */
block|}
struct|;
end_struct

begin_comment
comment|/* cluster summary information */
end_comment

begin_struct
struct|struct
name|csum
block|{
name|int8_t
name|cs_init
decl_stmt|;
comment|/* cluster summary has been initialized */
name|int32_t
modifier|*
name|cs_sum
decl_stmt|;
comment|/* cluster summary array */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The second extended file system magic number  */
end_comment

begin_define
define|#
directive|define
name|E2FS_MAGIC
value|0xEF53
end_define

begin_comment
comment|/*  * Revision levels  */
end_comment

begin_define
define|#
directive|define
name|E2FS_REV0
value|0
end_define

begin_comment
comment|/* The good old (original) format */
end_comment

begin_define
define|#
directive|define
name|E2FS_REV1
value|1
end_define

begin_comment
comment|/* V2 format w/ dynamic inode sizes */
end_comment

begin_define
define|#
directive|define
name|E2FS_REV0_INODE_SIZE
value|128
end_define

begin_comment
comment|/*  * compatible/incompatible features  */
end_comment

begin_define
define|#
directive|define
name|EXT2F_COMPAT_PREALLOC
value|0x0001
end_define

begin_define
define|#
directive|define
name|EXT2F_COMPAT_IMAGIC_INODES
value|0x0002
end_define

begin_define
define|#
directive|define
name|EXT2F_COMPAT_HASJOURNAL
value|0x0004
end_define

begin_define
define|#
directive|define
name|EXT2F_COMPAT_EXT_ATTR
value|0x0008
end_define

begin_define
define|#
directive|define
name|EXT2F_COMPAT_RESIZE
value|0x0010
end_define

begin_define
define|#
directive|define
name|EXT2F_COMPAT_DIRHASHINDEX
value|0x0020
end_define

begin_define
define|#
directive|define
name|EXT2F_COMPAT_LAZY_BG
value|0x0040
end_define

begin_define
define|#
directive|define
name|EXT2F_COMPAT_EXCLUDE_BITMAP
value|0x0100
end_define

begin_define
define|#
directive|define
name|EXT2F_COMPAT_SPARSESUPER2
value|0x0200
end_define

begin_define
define|#
directive|define
name|EXT2F_ROCOMPAT_SPARSESUPER
value|0x0001
end_define

begin_define
define|#
directive|define
name|EXT2F_ROCOMPAT_LARGEFILE
value|0x0002
end_define

begin_define
define|#
directive|define
name|EXT2F_ROCOMPAT_BTREE_DIR
value|0x0004
end_define

begin_define
define|#
directive|define
name|EXT2F_ROCOMPAT_HUGE_FILE
value|0x0008
end_define

begin_define
define|#
directive|define
name|EXT2F_ROCOMPAT_GDT_CSUM
value|0x0010
end_define

begin_define
define|#
directive|define
name|EXT2F_ROCOMPAT_DIR_NLINK
value|0x0020
end_define

begin_define
define|#
directive|define
name|EXT2F_ROCOMPAT_EXTRA_ISIZE
value|0x0040
end_define

begin_define
define|#
directive|define
name|EXT2F_ROCOMPAT_HAS_SNAPSHOT
value|0x0080
end_define

begin_define
define|#
directive|define
name|EXT2F_ROCOMPAT_QUOTA
value|0x0100
end_define

begin_define
define|#
directive|define
name|EXT2F_ROCOMPAT_BIGALLOC
value|0x0200
end_define

begin_define
define|#
directive|define
name|EXT2F_ROCOMPAT_METADATA_CKSUM
value|0x0400
end_define

begin_define
define|#
directive|define
name|EXT2F_ROCOMPAT_REPLICA
value|0x0800
end_define

begin_define
define|#
directive|define
name|EXT2F_ROCOMPAT_READONLY
value|0x1000
end_define

begin_define
define|#
directive|define
name|EXT2F_ROCOMPAT_PROJECT
value|0x2000
end_define

begin_define
define|#
directive|define
name|EXT2F_INCOMPAT_COMP
value|0x0001
end_define

begin_define
define|#
directive|define
name|EXT2F_INCOMPAT_FTYPE
value|0x0002
end_define

begin_define
define|#
directive|define
name|EXT2F_INCOMPAT_RECOVER
value|0x0004
end_define

begin_define
define|#
directive|define
name|EXT2F_INCOMPAT_JOURNAL_DEV
value|0x0008
end_define

begin_define
define|#
directive|define
name|EXT2F_INCOMPAT_META_BG
value|0x0010
end_define

begin_define
define|#
directive|define
name|EXT2F_INCOMPAT_EXTENTS
value|0x0040
end_define

begin_define
define|#
directive|define
name|EXT2F_INCOMPAT_64BIT
value|0x0080
end_define

begin_define
define|#
directive|define
name|EXT2F_INCOMPAT_MMP
value|0x0100
end_define

begin_define
define|#
directive|define
name|EXT2F_INCOMPAT_FLEX_BG
value|0x0200
end_define

begin_define
define|#
directive|define
name|EXT2F_INCOMPAT_EA_INODE
value|0x0400
end_define

begin_define
define|#
directive|define
name|EXT2F_INCOMPAT_DIRDATA
value|0x1000
end_define

begin_define
define|#
directive|define
name|EXT2F_INCOMPAT_CSUM_SEED
value|0x2000
end_define

begin_define
define|#
directive|define
name|EXT2F_INCOMPAT_LARGEDIR
value|0x4000
end_define

begin_define
define|#
directive|define
name|EXT2F_INCOMPAT_INLINE_DATA
value|0x8000
end_define

begin_define
define|#
directive|define
name|EXT2F_INCOMPAT_ENCRYPT
value|0x10000
end_define

begin_struct
struct|struct
name|ext2_feature
block|{
name|int
name|mask
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|ext2_feature
name|compat
index|[]
init|=
block|{
block|{
name|EXT2F_COMPAT_PREALLOC
block|,
literal|"dir_prealloc"
block|}
block|,
block|{
name|EXT2F_COMPAT_IMAGIC_INODES
block|,
literal|"imagic_inodes"
block|}
block|,
block|{
name|EXT2F_COMPAT_HASJOURNAL
block|,
literal|"has_journal"
block|}
block|,
block|{
name|EXT2F_COMPAT_EXT_ATTR
block|,
literal|"ext_attr"
block|}
block|,
block|{
name|EXT2F_COMPAT_RESIZE
block|,
literal|"resize_inode"
block|}
block|,
block|{
name|EXT2F_COMPAT_DIRHASHINDEX
block|,
literal|"dir_index"
block|}
block|,
block|{
name|EXT2F_COMPAT_EXCLUDE_BITMAP
block|,
literal|"snapshot_bitmap"
block|}
block|,
block|{
name|EXT2F_COMPAT_SPARSESUPER2
block|,
literal|"sparse_super2"
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|ext2_feature
name|ro_compat
index|[]
init|=
block|{
block|{
name|EXT2F_ROCOMPAT_SPARSESUPER
block|,
literal|"sparse_super"
block|}
block|,
block|{
name|EXT2F_ROCOMPAT_LARGEFILE
block|,
literal|"large_file"
block|}
block|,
block|{
name|EXT2F_ROCOMPAT_BTREE_DIR
block|,
literal|"btree_dir"
block|}
block|,
block|{
name|EXT2F_ROCOMPAT_HUGE_FILE
block|,
literal|"huge_file"
block|}
block|,
block|{
name|EXT2F_ROCOMPAT_GDT_CSUM
block|,
literal|"uninit_groups"
block|}
block|,
block|{
name|EXT2F_ROCOMPAT_DIR_NLINK
block|,
literal|"dir_nlink"
block|}
block|,
block|{
name|EXT2F_ROCOMPAT_EXTRA_ISIZE
block|,
literal|"extra_isize"
block|}
block|,
block|{
name|EXT2F_ROCOMPAT_HAS_SNAPSHOT
block|,
literal|"snapshot"
block|}
block|,
block|{
name|EXT2F_ROCOMPAT_QUOTA
block|,
literal|"quota"
block|}
block|,
block|{
name|EXT2F_ROCOMPAT_BIGALLOC
block|,
literal|"bigalloc"
block|}
block|,
block|{
name|EXT2F_ROCOMPAT_METADATA_CKSUM
block|,
literal|"metadata_csum"
block|}
block|,
block|{
name|EXT2F_ROCOMPAT_REPLICA
block|,
literal|"replica"
block|}
block|,
block|{
name|EXT2F_ROCOMPAT_READONLY
block|,
literal|"ro"
block|}
block|,
block|{
name|EXT2F_ROCOMPAT_PROJECT
block|,
literal|"project"
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|ext2_feature
name|incompat
index|[]
init|=
block|{
block|{
name|EXT2F_INCOMPAT_COMP
block|,
literal|"compression"
block|}
block|,
block|{
name|EXT2F_INCOMPAT_FTYPE
block|,
literal|"filetype"
block|}
block|,
block|{
name|EXT2F_INCOMPAT_RECOVER
block|,
literal|"needs_recovery"
block|}
block|,
block|{
name|EXT2F_INCOMPAT_JOURNAL_DEV
block|,
literal|"journal_dev"
block|}
block|,
block|{
name|EXT2F_INCOMPAT_META_BG
block|,
literal|"meta_bg"
block|}
block|,
block|{
name|EXT2F_INCOMPAT_EXTENTS
block|,
literal|"extents"
block|}
block|,
block|{
name|EXT2F_INCOMPAT_64BIT
block|,
literal|"64bit"
block|}
block|,
block|{
name|EXT2F_INCOMPAT_MMP
block|,
literal|"mmp"
block|}
block|,
block|{
name|EXT2F_INCOMPAT_FLEX_BG
block|,
literal|"flex_bg"
block|}
block|,
block|{
name|EXT2F_INCOMPAT_EA_INODE
block|,
literal|"ea_inode"
block|}
block|,
block|{
name|EXT2F_INCOMPAT_DIRDATA
block|,
literal|"dirdata"
block|}
block|,
block|{
name|EXT2F_INCOMPAT_CSUM_SEED
block|,
literal|"metadata_csum_seed"
block|}
block|,
block|{
name|EXT2F_INCOMPAT_LARGEDIR
block|,
literal|"large_dir"
block|}
block|,
block|{
name|EXT2F_INCOMPAT_INLINE_DATA
block|,
literal|"inline_data"
block|}
block|,
block|{
name|EXT2F_INCOMPAT_ENCRYPT
block|,
literal|"encrypt"
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Features supported in this implementation  *  * We support the following REV1 features:  * - EXT2F_ROCOMPAT_SPARSESUPER  * - EXT2F_ROCOMPAT_LARGEFILE  * - EXT2F_ROCOMPAT_EXTRA_ISIZE  * - EXT2F_INCOMPAT_FTYPE  *  * We partially (read-only) support the following EXT4 features:  * - EXT2F_ROCOMPAT_HUGE_FILE  * - EXT2F_INCOMPAT_EXTENTS  *  * We do not support these EXT4 features but they are irrelevant  * for read-only support:  * - EXT2F_INCOMPAT_RECOVER  * - EXT2F_INCOMPAT_FLEX_BG  * - EXT2F_INCOMPAT_META_BG  */
end_comment

begin_define
define|#
directive|define
name|EXT2F_COMPAT_SUPP
value|EXT2F_COMPAT_DIRHASHINDEX
end_define

begin_define
define|#
directive|define
name|EXT2F_ROCOMPAT_SUPP
value|(EXT2F_ROCOMPAT_SPARSESUPER | \ 					 EXT2F_ROCOMPAT_LARGEFILE | \ 					 EXT2F_ROCOMPAT_GDT_CSUM | \ 					 EXT2F_ROCOMPAT_DIR_NLINK | \ 					 EXT2F_ROCOMPAT_HUGE_FILE | \ 					 EXT2F_ROCOMPAT_EXTRA_ISIZE)
end_define

begin_define
define|#
directive|define
name|EXT2F_INCOMPAT_SUPP
value|EXT2F_INCOMPAT_FTYPE
end_define

begin_define
define|#
directive|define
name|EXT4F_RO_INCOMPAT_SUPP
value|(EXT2F_INCOMPAT_EXTENTS | \ 					 EXT2F_INCOMPAT_RECOVER | \ 					 EXT2F_INCOMPAT_FLEX_BG | \ 					 EXT2F_INCOMPAT_META_BG )
end_define

begin_comment
comment|/* Assume that user mode programs are passing in an ext2fs superblock, not  * a kernel struct super_block.  This will allow us to call the feature-test  * macros from user land. */
end_comment

begin_define
define|#
directive|define
name|EXT2_SB
parameter_list|(
name|sb
parameter_list|)
value|(sb)
end_define

begin_comment
comment|/*  * Feature set definitions  */
end_comment

begin_define
define|#
directive|define
name|EXT2_HAS_COMPAT_FEATURE
parameter_list|(
name|sb
parameter_list|,
name|mask
parameter_list|)
define|\
value|( EXT2_SB(sb)->e2fs->e2fs_features_compat& htole32(mask) )
end_define

begin_define
define|#
directive|define
name|EXT2_HAS_RO_COMPAT_FEATURE
parameter_list|(
name|sb
parameter_list|,
name|mask
parameter_list|)
define|\
value|( EXT2_SB(sb)->e2fs->e2fs_features_rocompat& htole32(mask) )
end_define

begin_define
define|#
directive|define
name|EXT2_HAS_INCOMPAT_FEATURE
parameter_list|(
name|sb
parameter_list|,
name|mask
parameter_list|)
define|\
value|( EXT2_SB(sb)->e2fs->e2fs_features_incompat& htole32(mask) )
end_define

begin_comment
comment|/*  * File clean flags  */
end_comment

begin_define
define|#
directive|define
name|E2FS_ISCLEAN
value|0x0001
end_define

begin_comment
comment|/* Unmounted cleanly */
end_comment

begin_define
define|#
directive|define
name|E2FS_ERRORS
value|0x0002
end_define

begin_comment
comment|/* Errors detected */
end_comment

begin_comment
comment|/*  * Filesystem miscellaneous flags  */
end_comment

begin_define
define|#
directive|define
name|E2FS_SIGNED_HASH
value|0x0001
end_define

begin_define
define|#
directive|define
name|E2FS_UNSIGNED_HASH
value|0x0002
end_define

begin_define
define|#
directive|define
name|EXT2_BG_INODE_UNINIT
value|0x0001
end_define

begin_comment
comment|/* Inode table/bitmap not in use */
end_comment

begin_define
define|#
directive|define
name|EXT2_BG_BLOCK_UNINIT
value|0x0002
end_define

begin_comment
comment|/* Block bitmap not in use */
end_comment

begin_define
define|#
directive|define
name|EXT2_BG_INODE_ZEROED
value|0x0004
end_define

begin_comment
comment|/* On-disk itable initialized to zero */
end_comment

begin_comment
comment|/* ext2 file system block group descriptor */
end_comment

begin_struct
struct|struct
name|ext2_gd
block|{
name|uint32_t
name|ext2bgd_b_bitmap
decl_stmt|;
comment|/* blocks bitmap block */
name|uint32_t
name|ext2bgd_i_bitmap
decl_stmt|;
comment|/* inodes bitmap block */
name|uint32_t
name|ext2bgd_i_tables
decl_stmt|;
comment|/* inodes table block  */
name|uint16_t
name|ext2bgd_nbfree
decl_stmt|;
comment|/* number of free blocks */
name|uint16_t
name|ext2bgd_nifree
decl_stmt|;
comment|/* number of free inodes */
name|uint16_t
name|ext2bgd_ndirs
decl_stmt|;
comment|/* number of directories */
name|uint16_t
name|ext4bgd_flags
decl_stmt|;
comment|/* block group flags */
name|uint32_t
name|ext4bgd_x_bitmap
decl_stmt|;
comment|/* snapshot exclusion bitmap loc. */
name|uint16_t
name|ext4bgd_b_bmap_csum
decl_stmt|;
comment|/* block bitmap checksum */
name|uint16_t
name|ext4bgd_i_bmap_csum
decl_stmt|;
comment|/* inode bitmap checksum */
name|uint16_t
name|ext4bgd_i_unused
decl_stmt|;
comment|/* unused inode count */
name|uint16_t
name|ext4bgd_csum
decl_stmt|;
comment|/* group descriptor checksum */
block|}
struct|;
end_struct

begin_comment
comment|/* EXT2FS metadata is stored in little-endian byte order. These macros  * help reading it.  */
end_comment

begin_define
define|#
directive|define
name|e2fs_cgload
parameter_list|(
name|old
parameter_list|,
name|new
parameter_list|,
name|size
parameter_list|)
value|memcpy((new), (old), (size));
end_define

begin_define
define|#
directive|define
name|e2fs_cgsave
parameter_list|(
name|old
parameter_list|,
name|new
parameter_list|,
name|size
parameter_list|)
value|memcpy((new), (old), (size));
end_define

begin_comment
comment|/*  * Macro-instructions used to manage several block sizes  */
end_comment

begin_define
define|#
directive|define
name|EXT2_MAX_BLOCK_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|EXT2_MIN_BLOCK_LOG_SIZE
value|10
end_define

begin_define
define|#
directive|define
name|EXT2_BLOCK_SIZE
parameter_list|(
name|s
parameter_list|)
value|((s)->e2fs_bsize)
end_define

begin_define
define|#
directive|define
name|EXT2_ADDR_PER_BLOCK
parameter_list|(
name|s
parameter_list|)
value|(EXT2_BLOCK_SIZE(s) / sizeof(uint32_t))
end_define

begin_define
define|#
directive|define
name|EXT2_INODE_SIZE
parameter_list|(
name|s
parameter_list|)
value|(EXT2_SB(s)->e2fs_isize)
end_define

begin_comment
comment|/*  * Macro-instructions used to manage fragments  */
end_comment

begin_define
define|#
directive|define
name|EXT2_MIN_FRAG_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|EXT2_MAX_FRAG_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|EXT2_MIN_FRAG_LOG_SIZE
value|10
end_define

begin_define
define|#
directive|define
name|EXT2_FRAG_SIZE
parameter_list|(
name|s
parameter_list|)
value|(EXT2_SB(s)->e2fs_fsize)
end_define

begin_define
define|#
directive|define
name|EXT2_FRAGS_PER_BLOCK
parameter_list|(
name|s
parameter_list|)
value|(EXT2_SB(s)->e2fs_fpb)
end_define

begin_comment
comment|/*  * Macro-instructions used to manage group descriptors  */
end_comment

begin_define
define|#
directive|define
name|EXT2_BLOCKS_PER_GROUP
parameter_list|(
name|s
parameter_list|)
value|(EXT2_SB(s)->e2fs_bpg)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FS_EXT2FS_EXT2FS_H_ */
end_comment

end_unit

