begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000,2002,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_DINODE_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_DINODE_H__
end_define

begin_struct_decl
struct_decl|struct
name|xfs_buf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_mount
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|XFS_DINODE_VERSION_1
value|1
end_define

begin_define
define|#
directive|define
name|XFS_DINODE_VERSION_2
value|2
end_define

begin_define
define|#
directive|define
name|XFS_DINODE_GOOD_VERSION
parameter_list|(
name|v
parameter_list|)
define|\
value|(((v) == XFS_DINODE_VERSION_1 || (v) == XFS_DINODE_VERSION_2))
end_define

begin_define
define|#
directive|define
name|XFS_DINODE_MAGIC
value|0x494e
end_define

begin_comment
comment|/* 'IN' */
end_comment

begin_comment
comment|/*  * Disk inode structure.  * This is just the header; the inode is expanded to fill a variable size  * with the last field expanding.  It is split into the core and "other"  * because we only need the core part in the in-core inode.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_timestamp
block|{
name|__int32_t
name|t_sec
decl_stmt|;
comment|/* timestamp seconds */
name|__int32_t
name|t_nsec
decl_stmt|;
comment|/* timestamp nanoseconds */
block|}
name|xfs_timestamp_t
typedef|;
end_typedef

begin_comment
comment|/*  * Note: Coordinate changes to this structure with the XFS_DI_* #defines  * below and the offsets table in xfs_ialloc_log_di().  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_dinode_core
block|{
name|__uint16_t
name|di_magic
decl_stmt|;
comment|/* inode magic # = XFS_DINODE_MAGIC */
name|__uint16_t
name|di_mode
decl_stmt|;
comment|/* mode and type of file */
name|__int8_t
name|di_version
decl_stmt|;
comment|/* inode version */
name|__int8_t
name|di_format
decl_stmt|;
comment|/* format of di_c data */
name|__uint16_t
name|di_onlink
decl_stmt|;
comment|/* old number of links to file */
name|__uint32_t
name|di_uid
decl_stmt|;
comment|/* owner's user id */
name|__uint32_t
name|di_gid
decl_stmt|;
comment|/* owner's group id */
name|__uint32_t
name|di_nlink
decl_stmt|;
comment|/* number of links to file */
name|__uint16_t
name|di_projid
decl_stmt|;
comment|/* owner's project id */
name|__uint8_t
name|di_pad
index|[
literal|8
index|]
decl_stmt|;
comment|/* unused, zeroed space */
name|__uint16_t
name|di_flushiter
decl_stmt|;
comment|/* incremented on flush */
name|xfs_timestamp_t
name|di_atime
decl_stmt|;
comment|/* time last accessed */
name|xfs_timestamp_t
name|di_mtime
decl_stmt|;
comment|/* time last modified */
name|xfs_timestamp_t
name|di_ctime
decl_stmt|;
comment|/* time created/inode modified */
name|xfs_fsize_t
name|di_size
decl_stmt|;
comment|/* number of bytes in file */
name|xfs_drfsbno_t
name|di_nblocks
decl_stmt|;
comment|/* # of direct& btree blocks used */
name|xfs_extlen_t
name|di_extsize
decl_stmt|;
comment|/* basic/minimum extent size for file */
name|xfs_extnum_t
name|di_nextents
decl_stmt|;
comment|/* number of extents in data fork */
name|xfs_aextnum_t
name|di_anextents
decl_stmt|;
comment|/* number of extents in attribute fork*/
name|__uint8_t
name|di_forkoff
decl_stmt|;
comment|/* attr fork offs,<<3 for 64b align */
name|__int8_t
name|di_aformat
decl_stmt|;
comment|/* format of attr fork's data */
name|__uint32_t
name|di_dmevmask
decl_stmt|;
comment|/* DMIG event mask */
name|__uint16_t
name|di_dmstate
decl_stmt|;
comment|/* DMIG state info */
name|__uint16_t
name|di_flags
decl_stmt|;
comment|/* random flags, XFS_DIFLAG_... */
name|__uint32_t
name|di_gen
decl_stmt|;
comment|/* generation number */
block|}
name|xfs_dinode_core_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DI_MAX_FLUSH
value|0xffff
end_define

begin_typedef
typedef|typedef
struct|struct
name|xfs_dinode
block|{
name|xfs_dinode_core_t
name|di_core
decl_stmt|;
comment|/* 	 * In adding anything between the core and the union, be 	 * sure to update the macros like XFS_LITINO below and 	 * XFS_BMAP_RBLOCK_DSIZE in xfs_bmap_btree.h. 	 */
name|xfs_agino_t
name|di_next_unlinked
decl_stmt|;
comment|/* agi unlinked list ptr */
union|union
block|{
name|xfs_bmdr_block_t
name|di_bmbt
decl_stmt|;
comment|/* btree root block */
name|xfs_bmbt_rec_32_t
name|di_bmx
index|[
literal|1
index|]
decl_stmt|;
comment|/* extent list */
name|xfs_dir_shortform_t
name|di_dirsf
decl_stmt|;
comment|/* shortform directory */
name|xfs_dir2_sf_t
name|di_dir2sf
decl_stmt|;
comment|/* shortform directory v2 */
name|char
name|di_c
index|[
literal|1
index|]
decl_stmt|;
comment|/* local contents */
name|xfs_dev_t
name|di_dev
decl_stmt|;
comment|/* device for S_IFCHR/S_IFBLK */
name|uuid_t
name|di_muuid
decl_stmt|;
comment|/* mount point value */
name|char
name|di_symlink
index|[
literal|1
index|]
decl_stmt|;
comment|/* local symbolic link */
block|}
name|di_u
union|;
union|union
block|{
name|xfs_bmdr_block_t
name|di_abmbt
decl_stmt|;
comment|/* btree root block */
name|xfs_bmbt_rec_32_t
name|di_abmx
index|[
literal|1
index|]
decl_stmt|;
comment|/* extent list */
name|xfs_attr_shortform_t
name|di_attrsf
decl_stmt|;
comment|/* shortform attribute list */
block|}
name|di_a
union|;
block|}
name|xfs_dinode_t
typedef|;
end_typedef

begin_comment
comment|/*  * The 32 bit link count in the inode theoretically maxes out at UINT_MAX.  * Since the pathconf interface is signed, we use 2^31 - 1 instead.  * The old inode format had a 16 bit link count, so its maximum is USHRT_MAX.  */
end_comment

begin_define
define|#
directive|define
name|XFS_MAXLINK
value|((1U<< 31) - 1U)
end_define

begin_define
define|#
directive|define
name|XFS_MAXLINK_1
value|65535U
end_define

begin_comment
comment|/*  * Bit names for logging disk inodes only  */
end_comment

begin_define
define|#
directive|define
name|XFS_DI_MAGIC
value|0x0000001
end_define

begin_define
define|#
directive|define
name|XFS_DI_MODE
value|0x0000002
end_define

begin_define
define|#
directive|define
name|XFS_DI_VERSION
value|0x0000004
end_define

begin_define
define|#
directive|define
name|XFS_DI_FORMAT
value|0x0000008
end_define

begin_define
define|#
directive|define
name|XFS_DI_ONLINK
value|0x0000010
end_define

begin_define
define|#
directive|define
name|XFS_DI_UID
value|0x0000020
end_define

begin_define
define|#
directive|define
name|XFS_DI_GID
value|0x0000040
end_define

begin_define
define|#
directive|define
name|XFS_DI_NLINK
value|0x0000080
end_define

begin_define
define|#
directive|define
name|XFS_DI_PROJID
value|0x0000100
end_define

begin_define
define|#
directive|define
name|XFS_DI_PAD
value|0x0000200
end_define

begin_define
define|#
directive|define
name|XFS_DI_ATIME
value|0x0000400
end_define

begin_define
define|#
directive|define
name|XFS_DI_MTIME
value|0x0000800
end_define

begin_define
define|#
directive|define
name|XFS_DI_CTIME
value|0x0001000
end_define

begin_define
define|#
directive|define
name|XFS_DI_SIZE
value|0x0002000
end_define

begin_define
define|#
directive|define
name|XFS_DI_NBLOCKS
value|0x0004000
end_define

begin_define
define|#
directive|define
name|XFS_DI_EXTSIZE
value|0x0008000
end_define

begin_define
define|#
directive|define
name|XFS_DI_NEXTENTS
value|0x0010000
end_define

begin_define
define|#
directive|define
name|XFS_DI_NAEXTENTS
value|0x0020000
end_define

begin_define
define|#
directive|define
name|XFS_DI_FORKOFF
value|0x0040000
end_define

begin_define
define|#
directive|define
name|XFS_DI_AFORMAT
value|0x0080000
end_define

begin_define
define|#
directive|define
name|XFS_DI_DMEVMASK
value|0x0100000
end_define

begin_define
define|#
directive|define
name|XFS_DI_DMSTATE
value|0x0200000
end_define

begin_define
define|#
directive|define
name|XFS_DI_FLAGS
value|0x0400000
end_define

begin_define
define|#
directive|define
name|XFS_DI_GEN
value|0x0800000
end_define

begin_define
define|#
directive|define
name|XFS_DI_NEXT_UNLINKED
value|0x1000000
end_define

begin_define
define|#
directive|define
name|XFS_DI_U
value|0x2000000
end_define

begin_define
define|#
directive|define
name|XFS_DI_A
value|0x4000000
end_define

begin_define
define|#
directive|define
name|XFS_DI_NUM_BITS
value|27
end_define

begin_define
define|#
directive|define
name|XFS_DI_ALL_BITS
value|((1<< XFS_DI_NUM_BITS) - 1)
end_define

begin_define
define|#
directive|define
name|XFS_DI_CORE_BITS
value|(XFS_DI_ALL_BITS& ~(XFS_DI_U|XFS_DI_A))
end_define

begin_comment
comment|/*  * Values for di_format  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|xfs_dinode_fmt
block|{
name|XFS_DINODE_FMT_DEV
block|,
comment|/* CHR, BLK: di_dev */
name|XFS_DINODE_FMT_LOCAL
block|,
comment|/* DIR, REG: di_c */
comment|/* LNK: di_symlink */
name|XFS_DINODE_FMT_EXTENTS
block|,
comment|/* DIR, REG, LNK: di_bmx */
name|XFS_DINODE_FMT_BTREE
block|,
comment|/* DIR, REG, LNK: di_bmbt */
name|XFS_DINODE_FMT_UUID
comment|/* MNT: di_uuid */
block|}
name|xfs_dinode_fmt_t
typedef|;
end_typedef

begin_comment
comment|/*  * Inode minimum and maximum sizes.  */
end_comment

begin_define
define|#
directive|define
name|XFS_DINODE_MIN_LOG
value|8
end_define

begin_define
define|#
directive|define
name|XFS_DINODE_MAX_LOG
value|11
end_define

begin_define
define|#
directive|define
name|XFS_DINODE_MIN_SIZE
value|(1<< XFS_DINODE_MIN_LOG)
end_define

begin_define
define|#
directive|define
name|XFS_DINODE_MAX_SIZE
value|(1<< XFS_DINODE_MAX_LOG)
end_define

begin_comment
comment|/*  * Inode size for given fs.  */
end_comment

begin_define
define|#
directive|define
name|XFS_LITINO
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_litino)
end_define

begin_define
define|#
directive|define
name|XFS_BROOT_SIZE_ADJ
define|\
value|(sizeof(xfs_bmbt_block_t) - sizeof(xfs_bmdr_block_t))
end_define

begin_comment
comment|/*  * Inode data& attribute fork sizes, per inode.  */
end_comment

begin_define
define|#
directive|define
name|XFS_CFORK_Q
parameter_list|(
name|dcp
parameter_list|)
value|((dcp)->di_forkoff != 0)
end_define

begin_define
define|#
directive|define
name|XFS_CFORK_Q_DISK
parameter_list|(
name|dcp
parameter_list|)
value|((dcp)->di_forkoff != 0)
end_define

begin_define
define|#
directive|define
name|XFS_CFORK_BOFF
parameter_list|(
name|dcp
parameter_list|)
value|((int)((dcp)->di_forkoff<< 3))
end_define

begin_define
define|#
directive|define
name|XFS_CFORK_BOFF_DISK
parameter_list|(
name|dcp
parameter_list|)
define|\
value|((int)(INT_GET((dcp)->di_forkoff, ARCH_CONVERT)<< 3))
end_define

begin_define
define|#
directive|define
name|XFS_CFORK_DSIZE_DISK
parameter_list|(
name|dcp
parameter_list|,
name|mp
parameter_list|)
define|\
value|(XFS_CFORK_Q_DISK(dcp) ? XFS_CFORK_BOFF_DISK(dcp) : XFS_LITINO(mp))
end_define

begin_define
define|#
directive|define
name|XFS_CFORK_DSIZE
parameter_list|(
name|dcp
parameter_list|,
name|mp
parameter_list|)
define|\
value|(XFS_CFORK_Q(dcp) ? XFS_CFORK_BOFF(dcp) : XFS_LITINO(mp))
end_define

begin_define
define|#
directive|define
name|XFS_CFORK_ASIZE_DISK
parameter_list|(
name|dcp
parameter_list|,
name|mp
parameter_list|)
define|\
value|(XFS_CFORK_Q_DISK(dcp) ? XFS_LITINO(mp) - XFS_CFORK_BOFF_DISK(dcp) : 0)
end_define

begin_define
define|#
directive|define
name|XFS_CFORK_ASIZE
parameter_list|(
name|dcp
parameter_list|,
name|mp
parameter_list|)
define|\
value|(XFS_CFORK_Q(dcp) ? XFS_LITINO(mp) - XFS_CFORK_BOFF(dcp) : 0)
end_define

begin_define
define|#
directive|define
name|XFS_CFORK_SIZE_DISK
parameter_list|(
name|dcp
parameter_list|,
name|mp
parameter_list|,
name|w
parameter_list|)
define|\
value|((w) == XFS_DATA_FORK ? \ 		XFS_CFORK_DSIZE_DISK(dcp, mp) : \ 	 	XFS_CFORK_ASIZE_DISK(dcp, mp))
end_define

begin_define
define|#
directive|define
name|XFS_CFORK_SIZE
parameter_list|(
name|dcp
parameter_list|,
name|mp
parameter_list|,
name|w
parameter_list|)
define|\
value|((w) == XFS_DATA_FORK ? \ 		XFS_CFORK_DSIZE(dcp, mp) : XFS_CFORK_ASIZE(dcp, mp))
end_define

begin_define
define|#
directive|define
name|XFS_DFORK_DSIZE
parameter_list|(
name|dip
parameter_list|,
name|mp
parameter_list|)
define|\
value|XFS_CFORK_DSIZE_DISK(&(dip)->di_core, mp)
end_define

begin_define
define|#
directive|define
name|XFS_DFORK_DSIZE_HOST
parameter_list|(
name|dip
parameter_list|,
name|mp
parameter_list|)
define|\
value|XFS_CFORK_DSIZE(&(dip)->di_core, mp)
end_define

begin_define
define|#
directive|define
name|XFS_DFORK_ASIZE
parameter_list|(
name|dip
parameter_list|,
name|mp
parameter_list|)
define|\
value|XFS_CFORK_ASIZE_DISK(&(dip)->di_core, mp)
end_define

begin_define
define|#
directive|define
name|XFS_DFORK_ASIZE_HOST
parameter_list|(
name|dip
parameter_list|,
name|mp
parameter_list|)
define|\
value|XFS_CFORK_ASIZE(&(dip)->di_core, mp)
end_define

begin_define
define|#
directive|define
name|XFS_DFORK_SIZE
parameter_list|(
name|dip
parameter_list|,
name|mp
parameter_list|,
name|w
parameter_list|)
define|\
value|XFS_CFORK_SIZE_DISK(&(dip)->di_core, mp, w)
end_define

begin_define
define|#
directive|define
name|XFS_DFORK_SIZE_HOST
parameter_list|(
name|dip
parameter_list|,
name|mp
parameter_list|,
name|w
parameter_list|)
define|\
value|XFS_CFORK_SIZE(&(dip)->di_core, mp, w)
end_define

begin_define
define|#
directive|define
name|XFS_DFORK_Q
parameter_list|(
name|dip
parameter_list|)
value|XFS_CFORK_Q_DISK(&(dip)->di_core)
end_define

begin_define
define|#
directive|define
name|XFS_DFORK_BOFF
parameter_list|(
name|dip
parameter_list|)
value|XFS_CFORK_BOFF_DISK(&(dip)->di_core)
end_define

begin_define
define|#
directive|define
name|XFS_DFORK_DPTR
parameter_list|(
name|dip
parameter_list|)
value|((dip)->di_u.di_c)
end_define

begin_define
define|#
directive|define
name|XFS_DFORK_APTR
parameter_list|(
name|dip
parameter_list|)
define|\
value|((dip)->di_u.di_c + XFS_DFORK_BOFF(dip))
end_define

begin_define
define|#
directive|define
name|XFS_DFORK_PTR
parameter_list|(
name|dip
parameter_list|,
name|w
parameter_list|)
define|\
value|((w) == XFS_DATA_FORK ? XFS_DFORK_DPTR(dip) : XFS_DFORK_APTR(dip))
end_define

begin_define
define|#
directive|define
name|XFS_CFORK_FORMAT
parameter_list|(
name|dcp
parameter_list|,
name|w
parameter_list|)
define|\
value|((w) == XFS_DATA_FORK ? (dcp)->di_format : (dcp)->di_aformat)
end_define

begin_define
define|#
directive|define
name|XFS_CFORK_FMT_SET
parameter_list|(
name|dcp
parameter_list|,
name|w
parameter_list|,
name|n
parameter_list|)
define|\
value|((w) == XFS_DATA_FORK ? \ 		((dcp)->di_format = (n)) : ((dcp)->di_aformat = (n)))
end_define

begin_define
define|#
directive|define
name|XFS_DFORK_FORMAT
parameter_list|(
name|dip
parameter_list|,
name|w
parameter_list|)
value|XFS_CFORK_FORMAT(&(dip)->di_core, w)
end_define

begin_define
define|#
directive|define
name|XFS_CFORK_NEXTENTS_DISK
parameter_list|(
name|dcp
parameter_list|,
name|w
parameter_list|)
define|\
value|((w) == XFS_DATA_FORK ? \ 	 	INT_GET((dcp)->di_nextents, ARCH_CONVERT) : \ 	 	INT_GET((dcp)->di_anextents, ARCH_CONVERT))
end_define

begin_define
define|#
directive|define
name|XFS_CFORK_NEXTENTS
parameter_list|(
name|dcp
parameter_list|,
name|w
parameter_list|)
define|\
value|((w) == XFS_DATA_FORK ? (dcp)->di_nextents : (dcp)->di_anextents)
end_define

begin_define
define|#
directive|define
name|XFS_DFORK_NEXTENTS
parameter_list|(
name|dip
parameter_list|,
name|w
parameter_list|)
value|XFS_CFORK_NEXTENTS_DISK(&(dip)->di_core, w)
end_define

begin_define
define|#
directive|define
name|XFS_DFORK_NEXTENTS_HOST
parameter_list|(
name|dip
parameter_list|,
name|w
parameter_list|)
value|XFS_CFORK_NEXTENTS(&(dip)->di_core, w)
end_define

begin_define
define|#
directive|define
name|XFS_CFORK_NEXT_SET
parameter_list|(
name|dcp
parameter_list|,
name|w
parameter_list|,
name|n
parameter_list|)
define|\
value|((w) == XFS_DATA_FORK ? \ 		((dcp)->di_nextents = (n)) : ((dcp)->di_anextents = (n)))
end_define

begin_define
define|#
directive|define
name|XFS_BUF_TO_DINODE
parameter_list|(
name|bp
parameter_list|)
value|((xfs_dinode_t *)XFS_BUF_PTR(bp))
end_define

begin_comment
comment|/*  * Values for di_flags  * There should be a one-to-one correspondence between these flags and the  * XFS_XFLAG_s.  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIFLAG_REALTIME_BIT
value|0
end_define

begin_comment
comment|/* file's blocks come from rt area */
end_comment

begin_define
define|#
directive|define
name|XFS_DIFLAG_PREALLOC_BIT
value|1
end_define

begin_comment
comment|/* file space has been preallocated */
end_comment

begin_define
define|#
directive|define
name|XFS_DIFLAG_NEWRTBM_BIT
value|2
end_define

begin_comment
comment|/* for rtbitmap inode, new format */
end_comment

begin_define
define|#
directive|define
name|XFS_DIFLAG_IMMUTABLE_BIT
value|3
end_define

begin_comment
comment|/* inode is immutable */
end_comment

begin_define
define|#
directive|define
name|XFS_DIFLAG_APPEND_BIT
value|4
end_define

begin_comment
comment|/* inode is append-only */
end_comment

begin_define
define|#
directive|define
name|XFS_DIFLAG_SYNC_BIT
value|5
end_define

begin_comment
comment|/* inode is written synchronously */
end_comment

begin_define
define|#
directive|define
name|XFS_DIFLAG_NOATIME_BIT
value|6
end_define

begin_comment
comment|/* do not update atime */
end_comment

begin_define
define|#
directive|define
name|XFS_DIFLAG_NODUMP_BIT
value|7
end_define

begin_comment
comment|/* do not dump */
end_comment

begin_define
define|#
directive|define
name|XFS_DIFLAG_RTINHERIT_BIT
value|8
end_define

begin_comment
comment|/* create with realtime bit set */
end_comment

begin_define
define|#
directive|define
name|XFS_DIFLAG_PROJINHERIT_BIT
value|9
end_define

begin_comment
comment|/* create with parents projid */
end_comment

begin_define
define|#
directive|define
name|XFS_DIFLAG_NOSYMLINKS_BIT
value|10
end_define

begin_comment
comment|/* disallow symlink creation */
end_comment

begin_define
define|#
directive|define
name|XFS_DIFLAG_EXTSIZE_BIT
value|11
end_define

begin_comment
comment|/* inode extent size allocator hint */
end_comment

begin_define
define|#
directive|define
name|XFS_DIFLAG_EXTSZINHERIT_BIT
value|12
end_define

begin_comment
comment|/* inherit inode extent size */
end_comment

begin_define
define|#
directive|define
name|XFS_DIFLAG_REALTIME
value|(1<< XFS_DIFLAG_REALTIME_BIT)
end_define

begin_define
define|#
directive|define
name|XFS_DIFLAG_PREALLOC
value|(1<< XFS_DIFLAG_PREALLOC_BIT)
end_define

begin_define
define|#
directive|define
name|XFS_DIFLAG_NEWRTBM
value|(1<< XFS_DIFLAG_NEWRTBM_BIT)
end_define

begin_define
define|#
directive|define
name|XFS_DIFLAG_IMMUTABLE
value|(1<< XFS_DIFLAG_IMMUTABLE_BIT)
end_define

begin_define
define|#
directive|define
name|XFS_DIFLAG_APPEND
value|(1<< XFS_DIFLAG_APPEND_BIT)
end_define

begin_define
define|#
directive|define
name|XFS_DIFLAG_SYNC
value|(1<< XFS_DIFLAG_SYNC_BIT)
end_define

begin_define
define|#
directive|define
name|XFS_DIFLAG_NOATIME
value|(1<< XFS_DIFLAG_NOATIME_BIT)
end_define

begin_define
define|#
directive|define
name|XFS_DIFLAG_NODUMP
value|(1<< XFS_DIFLAG_NODUMP_BIT)
end_define

begin_define
define|#
directive|define
name|XFS_DIFLAG_RTINHERIT
value|(1<< XFS_DIFLAG_RTINHERIT_BIT)
end_define

begin_define
define|#
directive|define
name|XFS_DIFLAG_PROJINHERIT
value|(1<< XFS_DIFLAG_PROJINHERIT_BIT)
end_define

begin_define
define|#
directive|define
name|XFS_DIFLAG_NOSYMLINKS
value|(1<< XFS_DIFLAG_NOSYMLINKS_BIT)
end_define

begin_define
define|#
directive|define
name|XFS_DIFLAG_EXTSIZE
value|(1<< XFS_DIFLAG_EXTSIZE_BIT)
end_define

begin_define
define|#
directive|define
name|XFS_DIFLAG_EXTSZINHERIT
value|(1<< XFS_DIFLAG_EXTSZINHERIT_BIT)
end_define

begin_define
define|#
directive|define
name|XFS_DIFLAG_ANY
define|\
value|(XFS_DIFLAG_REALTIME | XFS_DIFLAG_PREALLOC | XFS_DIFLAG_NEWRTBM | \ 	 XFS_DIFLAG_IMMUTABLE | XFS_DIFLAG_APPEND | XFS_DIFLAG_SYNC | \ 	 XFS_DIFLAG_NOATIME | XFS_DIFLAG_NODUMP | XFS_DIFLAG_RTINHERIT | \ 	 XFS_DIFLAG_PROJINHERIT | XFS_DIFLAG_NOSYMLINKS | XFS_DIFLAG_EXTSIZE | \ 	 XFS_DIFLAG_EXTSZINHERIT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_DINODE_H__ */
end_comment

end_unit

