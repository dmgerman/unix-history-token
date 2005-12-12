begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000, 2002 Silicon Graphics, Inc.  All Rights Reserved.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Further, this software is distributed without any warranty that it is  * free of the rightful claim of any third person regarding infringement  * or the like.  Any license provided herein, whether implied or  * otherwise, applies only to this software file.  Patent licenses, if  * any, provided herein do not apply to combinations of this program with  * other software, or any other product whatsoever.  *  * You should have received a copy of the GNU General Public License along  * with this program; if not, write the Free Software Foundation, Inc., 59  * Temple Place - Suite 330, Boston MA 02111-1307, USA.  *  * Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,  * Mountain View, CA  94043, or:  *  * http://www.sgi.com  *  * For further information regarding this notice, see:  *  * http://oss.sgi.com/projects/GenInfo/SGIGPLNoticeExplan/  */
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

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DINODE_GOOD_VERSION
operator|)
end_if

begin_function_decl
name|int
name|xfs_dinode_good_version
parameter_list|(
name|int
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DINODE_GOOD_VERSION
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_DINODE_GOOD_VERSION
parameter_list|(
name|v
parameter_list|)
value|xfs_dinode_good_version(v)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_DINODE_GOOD_VERSION
parameter_list|(
name|v
parameter_list|)
value|(((v) == XFS_DINODE_VERSION_1) || \ 					 ((v) == XFS_DINODE_VERSION_2))
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_LITINO
operator|)
end_if

begin_function_decl
name|int
name|xfs_litino
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_LITINO
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_LITINO
parameter_list|(
name|mp
parameter_list|)
value|xfs_litino(mp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_LITINO
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_litino)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XFS_BROOT_SIZE_ADJ
define|\
value|(sizeof(xfs_bmbt_block_t) - sizeof(xfs_bmdr_block_t))
end_define

begin_comment
comment|/*  * Fork identifiers.  Here so utilities can use them without including  * xfs_inode.h.  */
end_comment

begin_define
define|#
directive|define
name|XFS_DATA_FORK
value|0
end_define

begin_define
define|#
directive|define
name|XFS_ATTR_FORK
value|1
end_define

begin_comment
comment|/*  * Inode data& attribute fork sizes, per inode.  */
end_comment

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_CFORK_Q
operator|)
end_if

begin_function_decl
name|int
name|xfs_cfork_q_arch
parameter_list|(
name|xfs_dinode_core_t
modifier|*
name|dcp
parameter_list|,
name|xfs_arch_t
name|arch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_cfork_q
parameter_list|(
name|xfs_dinode_core_t
modifier|*
name|dcp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_CFORK_Q
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_CFORK_Q_ARCH
parameter_list|(
name|dcp
parameter_list|,
name|arch
parameter_list|)
value|xfs_cfork_q_arch(dcp,arch)
end_define

begin_define
define|#
directive|define
name|XFS_CFORK_Q
parameter_list|(
name|dcp
parameter_list|)
value|xfs_cfork_q(dcp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_CFORK_Q_ARCH
parameter_list|(
name|dcp
parameter_list|,
name|arch
parameter_list|)
value|(!INT_ISZERO((dcp)->di_forkoff, arch))
end_define

begin_define
define|#
directive|define
name|XFS_CFORK_Q
parameter_list|(
name|dcp
parameter_list|)
value|((dcp)->di_forkoff != 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_CFORK_BOFF
operator|)
end_if

begin_function_decl
name|int
name|xfs_cfork_boff_arch
parameter_list|(
name|xfs_dinode_core_t
modifier|*
name|dcp
parameter_list|,
name|xfs_arch_t
name|arch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_cfork_boff
parameter_list|(
name|xfs_dinode_core_t
modifier|*
name|dcp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_CFORK_BOFF
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_CFORK_BOFF_ARCH
parameter_list|(
name|dcp
parameter_list|,
name|arch
parameter_list|)
value|xfs_cfork_boff_arch(dcp,arch)
end_define

begin_define
define|#
directive|define
name|XFS_CFORK_BOFF
parameter_list|(
name|dcp
parameter_list|)
value|xfs_cfork_boff(dcp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_CFORK_BOFF_ARCH
parameter_list|(
name|dcp
parameter_list|,
name|arch
parameter_list|)
value|((int)(INT_GET((dcp)->di_forkoff, arch)<< 3))
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

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_CFORK_DSIZE
operator|)
end_if

begin_function_decl
name|int
name|xfs_cfork_dsize_arch
parameter_list|(
name|xfs_dinode_core_t
modifier|*
name|dcp
parameter_list|,
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_arch_t
name|arch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_cfork_dsize
parameter_list|(
name|xfs_dinode_core_t
modifier|*
name|dcp
parameter_list|,
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_CFORK_DSIZE
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_CFORK_DSIZE_ARCH
parameter_list|(
name|dcp
parameter_list|,
name|mp
parameter_list|,
name|arch
parameter_list|)
value|xfs_cfork_dsize_arch(dcp,mp,arch)
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
value|xfs_cfork_dsize(dcp,mp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_CFORK_DSIZE_ARCH
parameter_list|(
name|dcp
parameter_list|,
name|mp
parameter_list|,
name|arch
parameter_list|)
define|\
value|(XFS_CFORK_Q_ARCH(dcp, arch) ? XFS_CFORK_BOFF_ARCH(dcp, arch) : XFS_LITINO(mp))
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

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_CFORK_ASIZE
operator|)
end_if

begin_function_decl
name|int
name|xfs_cfork_asize_arch
parameter_list|(
name|xfs_dinode_core_t
modifier|*
name|dcp
parameter_list|,
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_arch_t
name|arch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_cfork_asize
parameter_list|(
name|xfs_dinode_core_t
modifier|*
name|dcp
parameter_list|,
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_CFORK_ASIZE
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_CFORK_ASIZE_ARCH
parameter_list|(
name|dcp
parameter_list|,
name|mp
parameter_list|,
name|arch
parameter_list|)
value|xfs_cfork_asize_arch(dcp,mp,arch)
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
value|xfs_cfork_asize(dcp,mp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_CFORK_ASIZE_ARCH
parameter_list|(
name|dcp
parameter_list|,
name|mp
parameter_list|,
name|arch
parameter_list|)
define|\
value|(XFS_CFORK_Q_ARCH(dcp, arch) ? XFS_LITINO(mp) - XFS_CFORK_BOFF_ARCH(dcp, arch) : 0)
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

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_CFORK_SIZE
operator|)
end_if

begin_function_decl
name|int
name|xfs_cfork_size_arch
parameter_list|(
name|xfs_dinode_core_t
modifier|*
name|dcp
parameter_list|,
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|int
name|w
parameter_list|,
name|xfs_arch_t
name|arch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_cfork_size
parameter_list|(
name|xfs_dinode_core_t
modifier|*
name|dcp
parameter_list|,
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|int
name|w
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_CFORK_SIZE
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_CFORK_SIZE_ARCH
parameter_list|(
name|dcp
parameter_list|,
name|mp
parameter_list|,
name|w
parameter_list|,
name|arch
parameter_list|)
value|xfs_cfork_size_arch(dcp,mp,w,arch)
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
value|xfs_cfork_size(dcp,mp,w)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_CFORK_SIZE_ARCH
parameter_list|(
name|dcp
parameter_list|,
name|mp
parameter_list|,
name|w
parameter_list|,
name|arch
parameter_list|)
define|\
value|((w) == XFS_DATA_FORK ? \ 		XFS_CFORK_DSIZE_ARCH(dcp, mp, arch) : XFS_CFORK_ASIZE_ARCH(dcp, mp, arch))
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

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DFORK_DSIZE
operator|)
end_if

begin_function_decl
name|int
name|xfs_dfork_dsize_arch
parameter_list|(
name|xfs_dinode_t
modifier|*
name|dip
parameter_list|,
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_arch_t
name|arch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_dfork_dsize
parameter_list|(
name|xfs_dinode_t
modifier|*
name|dip
parameter_list|,
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DFORK_DSIZE
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_DFORK_DSIZE_ARCH
parameter_list|(
name|dip
parameter_list|,
name|mp
parameter_list|,
name|arch
parameter_list|)
value|xfs_dfork_dsize_arch(dip,mp,arch)
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
value|xfs_dfork_dsize(dip,mp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_DFORK_DSIZE_ARCH
parameter_list|(
name|dip
parameter_list|,
name|mp
parameter_list|,
name|arch
parameter_list|)
value|XFS_CFORK_DSIZE_ARCH(&(dip)->di_core, mp, arch)
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
value|XFS_DFORK_DSIZE_ARCH(dip,mp,ARCH_NOCONVERT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DFORK_ASIZE
operator|)
end_if

begin_function_decl
name|int
name|xfs_dfork_asize_arch
parameter_list|(
name|xfs_dinode_t
modifier|*
name|dip
parameter_list|,
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_arch_t
name|arch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_dfork_asize
parameter_list|(
name|xfs_dinode_t
modifier|*
name|dip
parameter_list|,
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DFORK_ASIZE
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_DFORK_ASIZE_ARCH
parameter_list|(
name|dip
parameter_list|,
name|mp
parameter_list|,
name|arch
parameter_list|)
value|xfs_dfork_asize_arch(dip,mp,arch)
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
value|xfs_dfork_asize(dip,mp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_DFORK_ASIZE_ARCH
parameter_list|(
name|dip
parameter_list|,
name|mp
parameter_list|,
name|arch
parameter_list|)
value|XFS_CFORK_ASIZE_ARCH(&(dip)->di_core, mp, arch)
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
value|XFS_DFORK_ASIZE_ARCH(dip,mp,ARCH_NOCONVERT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DFORK_ASIZE
operator|)
end_if

begin_function_decl
name|int
name|xfs_dfork_size_arch
parameter_list|(
name|xfs_dinode_t
modifier|*
name|dip
parameter_list|,
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|int
name|w
parameter_list|,
name|xfs_arch_t
name|arch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_dfork_size
parameter_list|(
name|xfs_dinode_t
modifier|*
name|dip
parameter_list|,
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|int
name|w
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DFORK_SIZE
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_DFORK_SIZE_ARCH
parameter_list|(
name|dip
parameter_list|,
name|mp
parameter_list|,
name|w
parameter_list|,
name|arch
parameter_list|)
value|xfs_dfork_size_arch(dip,mp,w,arch)
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
value|xfs_dfork_size(dip,mp,w)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_DFORK_SIZE_ARCH
parameter_list|(
name|dip
parameter_list|,
name|mp
parameter_list|,
name|w
parameter_list|,
name|arch
parameter_list|)
value|XFS_CFORK_SIZE_ARCH(&(dip)->di_core, mp, w, arch)
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
value|XFS_DFORK_SIZE_ARCH(dip,mp,w,ARCH_NOCONVERT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Macros for accessing per-fork disk inode information.  */
end_comment

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DFORK_Q
operator|)
end_if

begin_function_decl
name|int
name|xfs_dfork_q_arch
parameter_list|(
name|xfs_dinode_t
modifier|*
name|dip
parameter_list|,
name|xfs_arch_t
name|arch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_dfork_q
parameter_list|(
name|xfs_dinode_t
modifier|*
name|dip
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DFORK_Q
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_DFORK_Q_ARCH
parameter_list|(
name|dip
parameter_list|,
name|arch
parameter_list|)
value|xfs_dfork_q_arch(dip,arch)
end_define

begin_define
define|#
directive|define
name|XFS_DFORK_Q
parameter_list|(
name|dip
parameter_list|)
value|xfs_dfork_q(dip)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_DFORK_Q_ARCH
parameter_list|(
name|dip
parameter_list|,
name|arch
parameter_list|)
value|XFS_CFORK_Q_ARCH(&(dip)->di_core, arch)
end_define

begin_define
define|#
directive|define
name|XFS_DFORK_Q
parameter_list|(
name|dip
parameter_list|)
value|XFS_DFORK_Q_ARCH(dip,ARCH_NOCONVERT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DFORK_BOFF
operator|)
end_if

begin_function_decl
name|int
name|xfs_dfork_boff_arch
parameter_list|(
name|xfs_dinode_t
modifier|*
name|dip
parameter_list|,
name|xfs_arch_t
name|arch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_dfork_boff
parameter_list|(
name|xfs_dinode_t
modifier|*
name|dip
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DFORK_BOFF
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_DFORK_BOFF_ARCH
parameter_list|(
name|dip
parameter_list|,
name|arch
parameter_list|)
value|xfs_dfork_boff_arch(dip,arch)
end_define

begin_define
define|#
directive|define
name|XFS_DFORK_BOFF
parameter_list|(
name|dip
parameter_list|)
value|xfs_dfork_boff(dip)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_DFORK_BOFF_ARCH
parameter_list|(
name|dip
parameter_list|,
name|arch
parameter_list|)
value|XFS_CFORK_BOFF_ARCH(&(dip)->di_core, arch)
end_define

begin_define
define|#
directive|define
name|XFS_DFORK_BOFF
parameter_list|(
name|dip
parameter_list|)
value|XFS_DFORK_BOFF_ARCH(dip,ARCH_NOCONVERT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DFORK_DPTR
operator|)
end_if

begin_function_decl
name|char
modifier|*
name|xfs_dfork_dptr_arch
parameter_list|(
name|xfs_dinode_t
modifier|*
name|dip
parameter_list|,
name|xfs_arch_t
name|arch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|xfs_dfork_dptr
parameter_list|(
name|xfs_dinode_t
modifier|*
name|dip
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DFORK_DPTR
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_DFORK_DPTR_ARCH
parameter_list|(
name|dip
parameter_list|,
name|arch
parameter_list|)
value|xfs_dfork_dptr_arch(dip,arch)
end_define

begin_define
define|#
directive|define
name|XFS_DFORK_DPTR
parameter_list|(
name|dip
parameter_list|)
value|xfs_dfork_dptr(dip)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_DFORK_DPTR_ARCH
parameter_list|(
name|dip
parameter_list|,
name|arch
parameter_list|)
value|((dip)->di_u.di_c)
end_define

begin_define
define|#
directive|define
name|XFS_DFORK_DPTR
parameter_list|(
name|dip
parameter_list|)
value|XFS_DFORK_DPTR_ARCH(dip,ARCH_NOCONVERT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DFORK_APTR
operator|)
end_if

begin_function_decl
name|char
modifier|*
name|xfs_dfork_aptr_arch
parameter_list|(
name|xfs_dinode_t
modifier|*
name|dip
parameter_list|,
name|xfs_arch_t
name|arch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|xfs_dfork_aptr
parameter_list|(
name|xfs_dinode_t
modifier|*
name|dip
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DFORK_APTR
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_DFORK_APTR_ARCH
parameter_list|(
name|dip
parameter_list|,
name|arch
parameter_list|)
value|xfs_dfork_aptr_arch(dip,arch)
end_define

begin_define
define|#
directive|define
name|XFS_DFORK_APTR
parameter_list|(
name|dip
parameter_list|)
value|xfs_dfork_aptr(dip)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_DFORK_APTR_ARCH
parameter_list|(
name|dip
parameter_list|,
name|arch
parameter_list|)
value|((dip)->di_u.di_c + XFS_DFORK_BOFF_ARCH(dip, arch))
end_define

begin_define
define|#
directive|define
name|XFS_DFORK_APTR
parameter_list|(
name|dip
parameter_list|)
value|XFS_DFORK_APTR_ARCH(dip,ARCH_NOCONVERT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DFORK_PTR
operator|)
end_if

begin_function_decl
name|char
modifier|*
name|xfs_dfork_ptr_arch
parameter_list|(
name|xfs_dinode_t
modifier|*
name|dip
parameter_list|,
name|int
name|w
parameter_list|,
name|xfs_arch_t
name|arch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|xfs_dfork_ptr
parameter_list|(
name|xfs_dinode_t
modifier|*
name|dip
parameter_list|,
name|int
name|w
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DFORK_PTR
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_DFORK_PTR_ARCH
parameter_list|(
name|dip
parameter_list|,
name|w
parameter_list|,
name|arch
parameter_list|)
value|xfs_dfork_ptr_arch(dip,w,arch)
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
value|xfs_dfork_ptr(dip,w)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_DFORK_PTR_ARCH
parameter_list|(
name|dip
parameter_list|,
name|w
parameter_list|,
name|arch
parameter_list|)
define|\
value|((w) == XFS_DATA_FORK ? XFS_DFORK_DPTR_ARCH(dip, arch) : XFS_DFORK_APTR_ARCH(dip, arch))
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
value|XFS_DFORK_PTR_ARCH(dip,w,ARCH_NOCONVERT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_CFORK_FORMAT
operator|)
end_if

begin_function_decl
name|int
name|xfs_cfork_format_arch
parameter_list|(
name|xfs_dinode_core_t
modifier|*
name|dcp
parameter_list|,
name|int
name|w
parameter_list|,
name|xfs_arch_t
name|arch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_cfork_format
parameter_list|(
name|xfs_dinode_core_t
modifier|*
name|dcp
parameter_list|,
name|int
name|w
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_CFORK_FORMAT
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_CFORK_FORMAT_ARCH
parameter_list|(
name|dcp
parameter_list|,
name|w
parameter_list|,
name|arch
parameter_list|)
value|xfs_cfork_format_arch(dcp,w,arch)
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
value|xfs_cfork_format(dcp,w)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_CFORK_FORMAT_ARCH
parameter_list|(
name|dcp
parameter_list|,
name|w
parameter_list|,
name|arch
parameter_list|)
define|\
value|((w) == XFS_DATA_FORK ? INT_GET((dcp)->di_format, arch) : INT_GET((dcp)->di_aformat, arch))
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
value|XFS_CFORK_FORMAT_ARCH(dcp,w,ARCH_NOCONVERT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_CFORK_FMT_SET
operator|)
end_if

begin_function_decl
name|void
name|xfs_cfork_fmt_set_arch
parameter_list|(
name|xfs_dinode_core_t
modifier|*
name|dcp
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|n
parameter_list|,
name|xfs_arch_t
name|arch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_cfork_fmt_set
parameter_list|(
name|xfs_dinode_core_t
modifier|*
name|dcp
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_CFORK_FMT_SET
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_CFORK_FMT_SET_ARCH
parameter_list|(
name|dcp
parameter_list|,
name|w
parameter_list|,
name|n
parameter_list|,
name|arch
parameter_list|)
value|xfs_cfork_fmt_set_arch(dcp,w,n,arch)
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
value|xfs_cfork_fmt_set(dcp,w,n)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_CFORK_FMT_SET_ARCH
parameter_list|(
name|dcp
parameter_list|,
name|w
parameter_list|,
name|n
parameter_list|,
name|arch
parameter_list|)
define|\
value|((w) == XFS_DATA_FORK ? \ 		(INT_SET((dcp)->di_format, arch, (n))) : \ 		(INT_SET((dcp)->di_aformat, arch, (n))))
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
value|XFS_CFORK_FMT_SET_ARCH(dcp,w,n,ARCH_NOCONVERT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_CFORK_NEXTENTS
operator|)
end_if

begin_function_decl
name|int
name|xfs_cfork_nextents_arch
parameter_list|(
name|xfs_dinode_core_t
modifier|*
name|dcp
parameter_list|,
name|int
name|w
parameter_list|,
name|xfs_arch_t
name|arch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_cfork_nextents
parameter_list|(
name|xfs_dinode_core_t
modifier|*
name|dcp
parameter_list|,
name|int
name|w
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_CFORK_NEXTENTS
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_CFORK_NEXTENTS_ARCH
parameter_list|(
name|dcp
parameter_list|,
name|w
parameter_list|,
name|arch
parameter_list|)
value|xfs_cfork_nextents_arch(dcp,w,arch)
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
value|xfs_cfork_nextents(dcp,w)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_CFORK_NEXTENTS_ARCH
parameter_list|(
name|dcp
parameter_list|,
name|w
parameter_list|,
name|arch
parameter_list|)
define|\
value|((w) == XFS_DATA_FORK ? INT_GET((dcp)->di_nextents, arch) : INT_GET((dcp)->di_anextents, arch))
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
value|XFS_CFORK_NEXTENTS_ARCH(dcp,w,ARCH_NOCONVERT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_CFORK_NEXT_SET
operator|)
end_if

begin_function_decl
name|void
name|xfs_cfork_next_set_arch
parameter_list|(
name|xfs_dinode_core_t
modifier|*
name|dcp
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|n
parameter_list|,
name|xfs_arch_t
name|arch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_cfork_next_set
parameter_list|(
name|xfs_dinode_core_t
modifier|*
name|dcp
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_CFORK_NEXT_SET
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_CFORK_NEXT_SET_ARCH
parameter_list|(
name|dcp
parameter_list|,
name|w
parameter_list|,
name|n
parameter_list|,
name|arch
parameter_list|)
value|xfs_cfork_next_set_arch(dcp,w,n,arch)
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
value|xfs_cfork_next_set(dcp,w,n)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_CFORK_NEXT_SET_ARCH
parameter_list|(
name|dcp
parameter_list|,
name|w
parameter_list|,
name|n
parameter_list|,
name|arch
parameter_list|)
define|\
value|((w) == XFS_DATA_FORK ? \ 		(INT_SET((dcp)->di_nextents, arch, (n))) : \ 		(INT_SET((dcp)->di_anextents, arch, (n))))
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
value|XFS_CFORK_NEXT_SET_ARCH(dcp,w,n,ARCH_NOCONVERT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DFORK_FORMAT
operator|)
end_if

begin_function_decl
name|int
name|xfs_dfork_format_arch
parameter_list|(
name|xfs_dinode_t
modifier|*
name|dip
parameter_list|,
name|int
name|w
parameter_list|,
name|xfs_arch_t
name|arch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_dfork_format
parameter_list|(
name|xfs_dinode_t
modifier|*
name|dip
parameter_list|,
name|int
name|w
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DFORK_FORMAT
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_DFORK_FORMAT_ARCH
parameter_list|(
name|dip
parameter_list|,
name|w
parameter_list|,
name|arch
parameter_list|)
value|xfs_dfork_format_arch(dip,w,arch)
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
value|xfs_dfork_format(dip,w)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_DFORK_FORMAT_ARCH
parameter_list|(
name|dip
parameter_list|,
name|w
parameter_list|,
name|arch
parameter_list|)
value|XFS_CFORK_FORMAT_ARCH(&(dip)->di_core, w, arch)
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
value|XFS_DFORK_FORMAT_ARCH(dip,w,ARCH_NOCONVERT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DFORK_FMT_SET
operator|)
end_if

begin_function_decl
name|void
name|xfs_dfork_fmt_set_arch
parameter_list|(
name|xfs_dinode_t
modifier|*
name|dip
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|n
parameter_list|,
name|xfs_arch_t
name|arch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_dfork_fmt_set
parameter_list|(
name|xfs_dinode_t
modifier|*
name|dip
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DFORK_FMT_SET
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_DFORK_FMT_SET_ARCH
parameter_list|(
name|dip
parameter_list|,
name|w
parameter_list|,
name|n
parameter_list|,
name|arch
parameter_list|)
value|xfs_dfork_fmt_set_arch(dip,w,n,arch)
end_define

begin_define
define|#
directive|define
name|XFS_DFORK_FMT_SET
parameter_list|(
name|dip
parameter_list|,
name|w
parameter_list|,
name|n
parameter_list|)
value|xfs_dfork_fmt_set(dip,w,n)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_DFORK_FMT_SET_ARCH
parameter_list|(
name|dip
parameter_list|,
name|w
parameter_list|,
name|n
parameter_list|,
name|arch
parameter_list|)
value|XFS_CFORK_FMT_SET_ARCH(&(dip)->di_core, w, n, arch)
end_define

begin_define
define|#
directive|define
name|XFS_DFORK_FMT_SET
parameter_list|(
name|dip
parameter_list|,
name|w
parameter_list|,
name|n
parameter_list|)
value|XFS_DFORK_FMT_SET_ARCH(dip,w,n,ARCH_NOCONVERT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DFORK_NEXTENTS
operator|)
end_if

begin_function_decl
name|int
name|xfs_dfork_nextents_arch
parameter_list|(
name|xfs_dinode_t
modifier|*
name|dip
parameter_list|,
name|int
name|w
parameter_list|,
name|xfs_arch_t
name|arch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_dfork_nextents
parameter_list|(
name|xfs_dinode_t
modifier|*
name|dip
parameter_list|,
name|int
name|w
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DFORK_NEXTENTS
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_DFORK_NEXTENTS_ARCH
parameter_list|(
name|dip
parameter_list|,
name|w
parameter_list|,
name|arch
parameter_list|)
value|xfs_dfork_nextents_arch(dip,w,arch)
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
value|xfs_dfork_nextents(dip,w)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_DFORK_NEXTENTS_ARCH
parameter_list|(
name|dip
parameter_list|,
name|w
parameter_list|,
name|arch
parameter_list|)
value|XFS_CFORK_NEXTENTS_ARCH(&(dip)->di_core, w, arch)
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
value|XFS_DFORK_NEXTENTS_ARCH(dip,w,ARCH_NOCONVERT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DFORK_NEXT_SET
operator|)
end_if

begin_function_decl
name|void
name|xfs_dfork_next_set_arch
parameter_list|(
name|xfs_dinode_t
modifier|*
name|dip
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|n
parameter_list|,
name|xfs_arch_t
name|arch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_dfork_next_set
parameter_list|(
name|xfs_dinode_t
modifier|*
name|dip
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DFORK_NEXT_SET
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_DFORK_NEXT_SET_ARCH
parameter_list|(
name|dip
parameter_list|,
name|w
parameter_list|,
name|n
parameter_list|,
name|arch
parameter_list|)
value|xfs_dfork_next_set_arch(dip,w,n,arch)
end_define

begin_define
define|#
directive|define
name|XFS_DFORK_NEXT_SET
parameter_list|(
name|dip
parameter_list|,
name|w
parameter_list|,
name|n
parameter_list|)
value|xfs_dfork_next_set(dip,w,n)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_DFORK_NEXT_SET_ARCH
parameter_list|(
name|dip
parameter_list|,
name|w
parameter_list|,
name|n
parameter_list|,
name|arch
parameter_list|)
value|XFS_CFORK_NEXT_SET_ARCH(&(dip)->di_core, w, n, arch)
end_define

begin_define
define|#
directive|define
name|XFS_DFORK_NEXT_SET
parameter_list|(
name|dip
parameter_list|,
name|w
parameter_list|,
name|n
parameter_list|)
value|XFS_DFORK_NEXT_SET_ARCH(dip,w,n,ARCH_NOCONVERT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_BUF_TO_DINODE
operator|)
end_if

begin_function_decl
name|xfs_dinode_t
modifier|*
name|xfs_buf_to_dinode
parameter_list|(
name|struct
name|xfs_buf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_BUF_TO_DINODE
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BUF_TO_DINODE
parameter_list|(
name|bp
parameter_list|)
value|xfs_buf_to_dinode(bp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BUF_TO_DINODE
parameter_list|(
name|bp
parameter_list|)
value|((xfs_dinode_t *)(XFS_BUF_PTR(bp)))
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_DINODE_H__ */
end_comment

end_unit

