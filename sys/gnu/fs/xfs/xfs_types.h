begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_TYPES_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_TYPES_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_comment
comment|/*  * POSIX Extensions  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uchar_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|ushort_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uint_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ulong_t
typedef|;
end_typedef

begin_comment
comment|/*  * Additional type declarations for XFS  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FreeBSD__
end_ifndef

begin_typedef
typedef|typedef
name|signed
name|char
name|__int8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|__uint8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|short
name|int
name|__int16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|int
name|__uint16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|int
name|__int32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|__uint32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|long
name|long
name|int
name|__int64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|int
name|__uint64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|B_FALSE
block|,
name|B_TRUE
block|}
name|boolean_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|__uint32_t
name|prid_t
typedef|;
end_typedef

begin_comment
comment|/* project ID */
end_comment

begin_typedef
typedef|typedef
name|__uint32_t
name|inst_t
typedef|;
end_typedef

begin_comment
comment|/* an instruction */
end_comment

begin_typedef
typedef|typedef
name|__s64
name|xfs_off_t
typedef|;
end_typedef

begin_comment
comment|/*<file offset> type */
end_comment

begin_typedef
typedef|typedef
name|__u64
name|xfs_ino_t
typedef|;
end_typedef

begin_comment
comment|/*<inode> type */
end_comment

begin_typedef
typedef|typedef
name|__s64
name|xfs_daddr_t
typedef|;
end_typedef

begin_comment
comment|/*<disk address> type */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|xfs_caddr_t
typedef|;
end_typedef

begin_comment
comment|/*<core address> type */
end_comment

begin_typedef
typedef|typedef
name|__u32
name|xfs_dev_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__u32
name|xfs_nlink_t
typedef|;
end_typedef

begin_comment
comment|/* __psint_t is the same size as a pointer */
end_comment

begin_if
if|#
directive|if
operator|(
name|BITS_PER_LONG
operator|==
literal|32
operator|)
end_if

begin_typedef
typedef|typedef
name|__int32_t
name|__psint_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint32_t
name|__psunsigned_t
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
operator|(
name|BITS_PER_LONG
operator|==
literal|64
operator|)
end_elif

begin_typedef
typedef|typedef
name|__int64_t
name|__psint_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint64_t
name|__psunsigned_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|BITS_PER_LONG must be 32 or 64
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KERNEL__ */
end_comment

begin_typedef
typedef|typedef
name|__uint32_t
name|xfs_agblock_t
typedef|;
end_typedef

begin_comment
comment|/* blockno in alloc. group */
end_comment

begin_typedef
typedef|typedef
name|__uint32_t
name|xfs_extlen_t
typedef|;
end_typedef

begin_comment
comment|/* extent length in blocks */
end_comment

begin_typedef
typedef|typedef
name|__uint32_t
name|xfs_agnumber_t
typedef|;
end_typedef

begin_comment
comment|/* allocation group number */
end_comment

begin_typedef
typedef|typedef
name|__int32_t
name|xfs_extnum_t
typedef|;
end_typedef

begin_comment
comment|/* # of extents in a file */
end_comment

begin_typedef
typedef|typedef
name|__int16_t
name|xfs_aextnum_t
typedef|;
end_typedef

begin_comment
comment|/* # extents in an attribute fork */
end_comment

begin_typedef
typedef|typedef
name|__int64_t
name|xfs_fsize_t
typedef|;
end_typedef

begin_comment
comment|/* bytes in a file */
end_comment

begin_typedef
typedef|typedef
name|__uint64_t
name|xfs_ufsize_t
typedef|;
end_typedef

begin_comment
comment|/* unsigned bytes in a file */
end_comment

begin_typedef
typedef|typedef
name|__int32_t
name|xfs_suminfo_t
typedef|;
end_typedef

begin_comment
comment|/* type of bitmap summary info */
end_comment

begin_typedef
typedef|typedef
name|__int32_t
name|xfs_rtword_t
typedef|;
end_typedef

begin_comment
comment|/* word type for bitmap manipulations */
end_comment

begin_typedef
typedef|typedef
name|__int64_t
name|xfs_lsn_t
typedef|;
end_typedef

begin_comment
comment|/* log sequence number */
end_comment

begin_typedef
typedef|typedef
name|__int32_t
name|xfs_tid_t
typedef|;
end_typedef

begin_comment
comment|/* transaction identifier */
end_comment

begin_typedef
typedef|typedef
name|__uint32_t
name|xfs_dablk_t
typedef|;
end_typedef

begin_comment
comment|/* dir/attr block number (in file) */
end_comment

begin_typedef
typedef|typedef
name|__uint32_t
name|xfs_dahash_t
typedef|;
end_typedef

begin_comment
comment|/* dir/attr hash value */
end_comment

begin_typedef
typedef|typedef
name|__uint16_t
name|xfs_prid_t
typedef|;
end_typedef

begin_comment
comment|/* prid_t truncated to 16bits in XFS */
end_comment

begin_comment
comment|/*  * These types are 64 bits on disk but are either 32 or 64 bits in memory.  * Disk based types:  */
end_comment

begin_typedef
typedef|typedef
name|__uint64_t
name|xfs_dfsbno_t
typedef|;
end_typedef

begin_comment
comment|/* blockno in filesystem (agno|agbno) */
end_comment

begin_typedef
typedef|typedef
name|__uint64_t
name|xfs_drfsbno_t
typedef|;
end_typedef

begin_comment
comment|/* blockno in filesystem (raw) */
end_comment

begin_typedef
typedef|typedef
name|__uint64_t
name|xfs_drtbno_t
typedef|;
end_typedef

begin_comment
comment|/* extent (block) in realtime area */
end_comment

begin_typedef
typedef|typedef
name|__uint64_t
name|xfs_dfiloff_t
typedef|;
end_typedef

begin_comment
comment|/* block number in a file */
end_comment

begin_typedef
typedef|typedef
name|__uint64_t
name|xfs_dfilblks_t
typedef|;
end_typedef

begin_comment
comment|/* number of blocks in a file */
end_comment

begin_comment
comment|/*  * Memory based types are conditional.  */
end_comment

begin_if
if|#
directive|if
name|XFS_BIG_BLKNOS
end_if

begin_typedef
typedef|typedef
name|__uint64_t
name|xfs_fsblock_t
typedef|;
end_typedef

begin_comment
comment|/* blockno in filesystem (agno|agbno) */
end_comment

begin_typedef
typedef|typedef
name|__uint64_t
name|xfs_rfsblock_t
typedef|;
end_typedef

begin_comment
comment|/* blockno in filesystem (raw) */
end_comment

begin_typedef
typedef|typedef
name|__uint64_t
name|xfs_rtblock_t
typedef|;
end_typedef

begin_comment
comment|/* extent (block) in realtime area */
end_comment

begin_typedef
typedef|typedef
name|__int64_t
name|xfs_srtblock_t
typedef|;
end_typedef

begin_comment
comment|/* signed version of xfs_rtblock_t */
end_comment

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|__uint32_t
name|xfs_fsblock_t
typedef|;
end_typedef

begin_comment
comment|/* blockno in filesystem (agno|agbno) */
end_comment

begin_typedef
typedef|typedef
name|__uint32_t
name|xfs_rfsblock_t
typedef|;
end_typedef

begin_comment
comment|/* blockno in filesystem (raw) */
end_comment

begin_typedef
typedef|typedef
name|__uint32_t
name|xfs_rtblock_t
typedef|;
end_typedef

begin_comment
comment|/* extent (block) in realtime area */
end_comment

begin_typedef
typedef|typedef
name|__int32_t
name|xfs_srtblock_t
typedef|;
end_typedef

begin_comment
comment|/* signed version of xfs_rtblock_t */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|__uint64_t
name|xfs_fileoff_t
typedef|;
end_typedef

begin_comment
comment|/* block number in a file */
end_comment

begin_typedef
typedef|typedef
name|__int64_t
name|xfs_sfiloff_t
typedef|;
end_typedef

begin_comment
comment|/* signed block number in a file */
end_comment

begin_typedef
typedef|typedef
name|__uint64_t
name|xfs_filblks_t
typedef|;
end_typedef

begin_comment
comment|/* number of blocks in a file */
end_comment

begin_typedef
typedef|typedef
name|__uint8_t
name|xfs_arch_t
typedef|;
end_typedef

begin_comment
comment|/* architecture of an xfs fs */
end_comment

begin_comment
comment|/*  * Null values for the types.  */
end_comment

begin_define
define|#
directive|define
name|NULLDFSBNO
value|((xfs_dfsbno_t)-1)
end_define

begin_define
define|#
directive|define
name|NULLDRFSBNO
value|((xfs_drfsbno_t)-1)
end_define

begin_define
define|#
directive|define
name|NULLDRTBNO
value|((xfs_drtbno_t)-1)
end_define

begin_define
define|#
directive|define
name|NULLDFILOFF
value|((xfs_dfiloff_t)-1)
end_define

begin_define
define|#
directive|define
name|NULLFSBLOCK
value|((xfs_fsblock_t)-1)
end_define

begin_define
define|#
directive|define
name|NULLRFSBLOCK
value|((xfs_rfsblock_t)-1)
end_define

begin_define
define|#
directive|define
name|NULLRTBLOCK
value|((xfs_rtblock_t)-1)
end_define

begin_define
define|#
directive|define
name|NULLFILEOFF
value|((xfs_fileoff_t)-1)
end_define

begin_define
define|#
directive|define
name|NULLAGBLOCK
value|((xfs_agblock_t)-1)
end_define

begin_define
define|#
directive|define
name|NULLAGNUMBER
value|((xfs_agnumber_t)-1)
end_define

begin_define
define|#
directive|define
name|NULLEXTNUM
value|((xfs_extnum_t)-1)
end_define

begin_define
define|#
directive|define
name|NULLCOMMITLSN
value|((xfs_lsn_t)-1)
end_define

begin_comment
comment|/*  * Max values for extlen, extnum, aextnum.  */
end_comment

begin_define
define|#
directive|define
name|MAXEXTLEN
value|((xfs_extlen_t)0x001fffff)
end_define

begin_comment
comment|/* 21 bits */
end_comment

begin_define
define|#
directive|define
name|MAXEXTNUM
value|((xfs_extnum_t)0x7fffffff)
end_define

begin_comment
comment|/* signed int */
end_comment

begin_define
define|#
directive|define
name|MAXAEXTNUM
value|((xfs_aextnum_t)0x7fff)
end_define

begin_comment
comment|/* signed short */
end_comment

begin_comment
comment|/*  * Min numbers of data/attr fork btree root pointers.  */
end_comment

begin_define
define|#
directive|define
name|MINDBTPTRS
value|3
end_define

begin_define
define|#
directive|define
name|MINABTPTRS
value|2
end_define

begin_comment
comment|/*  * MAXNAMELEN is the length (including the terminating null) of  * the longest permissible file (component) name.  */
end_comment

begin_define
define|#
directive|define
name|MAXNAMELEN
value|256
end_define

begin_typedef
typedef|typedef
struct|struct
name|xfs_dirent
block|{
comment|/* data from readdir() */
name|xfs_ino_t
name|d_ino
decl_stmt|;
comment|/* inode number of entry */
name|xfs_off_t
name|d_off
decl_stmt|;
comment|/* offset of disk directory entry */
name|unsigned
name|short
name|d_reclen
decl_stmt|;
comment|/* length of this record */
name|char
name|d_name
index|[
literal|1
index|]
decl_stmt|;
comment|/* name of file */
block|}
name|xfs_dirent_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DIRENTBASESIZE
value|(((xfs_dirent_t *)0)->d_name - (char *)0)
end_define

begin_define
define|#
directive|define
name|DIRENTSIZE
parameter_list|(
name|namelen
parameter_list|)
define|\
value|((DIRENTBASESIZE + (namelen) + \ 		sizeof(xfs_off_t))& ~(sizeof(xfs_off_t) - 1))
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|XFS_LOOKUP_EQi
block|,
name|XFS_LOOKUP_LEi
block|,
name|XFS_LOOKUP_GEi
block|}
name|xfs_lookup_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XFS_BTNUM_BNOi
block|,
name|XFS_BTNUM_CNTi
block|,
name|XFS_BTNUM_BMAPi
block|,
name|XFS_BTNUM_INOi
block|,
name|XFS_BTNUM_MAX
block|}
name|xfs_btnum_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_TYPES_H__ */
end_comment

end_unit

