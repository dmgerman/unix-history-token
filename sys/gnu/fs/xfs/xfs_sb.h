begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Silicon Graphics, Inc.  All Rights Reserved.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Further, this software is distributed without any warranty that it is  * free of the rightful claim of any third person regarding infringement  * or the like.  Any license provided herein, whether implied or  * otherwise, applies only to this software file.  Patent licenses, if  * any, provided herein do not apply to combinations of this program with  * other software, or any other product whatsoever.  *  * You should have received a copy of the GNU General Public License along  * with this program; if not, write the Free Software Foundation, Inc., 59  * Temple Place - Suite 330, Boston MA 02111-1307, USA.  *  * Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,  * Mountain View, CA  94043, or:  *  * http://www.sgi.com  *  * For further information regarding this notice, see:  *  * http://oss.sgi.com/projects/GenInfo/SGIGPLNoticeExplan/  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_SB_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_SB_H__
end_define

begin_comment
comment|/*  * Super block  * Fits into a sector-sized buffer at address 0 of each allocation group.  * Only the first of these is ever updated except during growfs.  */
end_comment

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
name|XFS_SB_MAGIC
value|0x58465342
end_define

begin_comment
comment|/* 'XFSB' */
end_comment

begin_define
define|#
directive|define
name|XFS_SB_VERSION_1
value|1
end_define

begin_comment
comment|/* 5.3, 6.0.1, 6.1 */
end_comment

begin_define
define|#
directive|define
name|XFS_SB_VERSION_2
value|2
end_define

begin_comment
comment|/* 6.2 - attributes */
end_comment

begin_define
define|#
directive|define
name|XFS_SB_VERSION_3
value|3
end_define

begin_comment
comment|/* 6.2 - new inode version */
end_comment

begin_define
define|#
directive|define
name|XFS_SB_VERSION_4
value|4
end_define

begin_comment
comment|/* 6.2+ - bitmask version */
end_comment

begin_define
define|#
directive|define
name|XFS_SB_VERSION_NUMBITS
value|0x000f
end_define

begin_define
define|#
directive|define
name|XFS_SB_VERSION_ALLFBITS
value|0xfff0
end_define

begin_define
define|#
directive|define
name|XFS_SB_VERSION_SASHFBITS
value|0xf000
end_define

begin_define
define|#
directive|define
name|XFS_SB_VERSION_REALFBITS
value|0x0ff0
end_define

begin_define
define|#
directive|define
name|XFS_SB_VERSION_ATTRBIT
value|0x0010
end_define

begin_define
define|#
directive|define
name|XFS_SB_VERSION_NLINKBIT
value|0x0020
end_define

begin_define
define|#
directive|define
name|XFS_SB_VERSION_QUOTABIT
value|0x0040
end_define

begin_define
define|#
directive|define
name|XFS_SB_VERSION_ALIGNBIT
value|0x0080
end_define

begin_define
define|#
directive|define
name|XFS_SB_VERSION_DALIGNBIT
value|0x0100
end_define

begin_define
define|#
directive|define
name|XFS_SB_VERSION_SHAREDBIT
value|0x0200
end_define

begin_define
define|#
directive|define
name|XFS_SB_VERSION_LOGV2BIT
value|0x0400
end_define

begin_define
define|#
directive|define
name|XFS_SB_VERSION_SECTORBIT
value|0x0800
end_define

begin_define
define|#
directive|define
name|XFS_SB_VERSION_EXTFLGBIT
value|0x1000
end_define

begin_define
define|#
directive|define
name|XFS_SB_VERSION_DIRV2BIT
value|0x2000
end_define

begin_define
define|#
directive|define
name|XFS_SB_VERSION_OKSASHFBITS
define|\
value|(XFS_SB_VERSION_EXTFLGBIT | \ 	 XFS_SB_VERSION_DIRV2BIT)
end_define

begin_define
define|#
directive|define
name|XFS_SB_VERSION_OKREALFBITS
define|\
value|(XFS_SB_VERSION_ATTRBIT | \ 	 XFS_SB_VERSION_NLINKBIT | \ 	 XFS_SB_VERSION_QUOTABIT | \ 	 XFS_SB_VERSION_ALIGNBIT | \ 	 XFS_SB_VERSION_DALIGNBIT | \ 	 XFS_SB_VERSION_SHAREDBIT | \ 	 XFS_SB_VERSION_LOGV2BIT | \ 	 XFS_SB_VERSION_SECTORBIT)
end_define

begin_define
define|#
directive|define
name|XFS_SB_VERSION_OKSASHBITS
define|\
value|(XFS_SB_VERSION_NUMBITS | \ 	 XFS_SB_VERSION_REALFBITS | \ 	 XFS_SB_VERSION_OKSASHFBITS)
end_define

begin_define
define|#
directive|define
name|XFS_SB_VERSION_OKREALBITS
define|\
value|(XFS_SB_VERSION_NUMBITS | \ 	 XFS_SB_VERSION_OKREALFBITS | \ 	 XFS_SB_VERSION_OKSASHFBITS)
end_define

begin_define
define|#
directive|define
name|XFS_SB_VERSION_MKFS
parameter_list|(
name|ia
parameter_list|,
name|dia
parameter_list|,
name|extflag
parameter_list|,
name|dirv2
parameter_list|,
name|na
parameter_list|,
name|sflag
parameter_list|)
define|\
value|(((ia) || (dia) || (extflag) || (dirv2) || (na) || (sflag)) ? \ 		(XFS_SB_VERSION_4 | \ 		 ((ia) ? XFS_SB_VERSION_ALIGNBIT : 0) | \ 		 ((dia) ? XFS_SB_VERSION_DALIGNBIT : 0) | \ 		 ((extflag) ? XFS_SB_VERSION_EXTFLGBIT : 0) | \ 		 ((dirv2) ? XFS_SB_VERSION_DIRV2BIT : 0) | \ 		 ((na) ? XFS_SB_VERSION_LOGV2BIT : 0) | \ 		 ((sflag) ? XFS_SB_VERSION_SECTORBIT : 0)) : \ 		XFS_SB_VERSION_1)
end_define

begin_typedef
typedef|typedef
struct|struct
name|xfs_sb
block|{
name|__uint32_t
name|sb_magicnum
decl_stmt|;
comment|/* magic number == XFS_SB_MAGIC */
name|__uint32_t
name|sb_blocksize
decl_stmt|;
comment|/* logical block size, bytes */
name|xfs_drfsbno_t
name|sb_dblocks
decl_stmt|;
comment|/* number of data blocks */
name|xfs_drfsbno_t
name|sb_rblocks
decl_stmt|;
comment|/* number of realtime blocks */
name|xfs_drtbno_t
name|sb_rextents
decl_stmt|;
comment|/* number of realtime extents */
name|uuid_t
name|sb_uuid
decl_stmt|;
comment|/* file system unique id */
name|xfs_dfsbno_t
name|sb_logstart
decl_stmt|;
comment|/* starting block of log if internal */
name|xfs_ino_t
name|sb_rootino
decl_stmt|;
comment|/* root inode number */
name|xfs_ino_t
name|sb_rbmino
decl_stmt|;
comment|/* bitmap inode for realtime extents */
name|xfs_ino_t
name|sb_rsumino
decl_stmt|;
comment|/* summary inode for rt bitmap */
name|xfs_agblock_t
name|sb_rextsize
decl_stmt|;
comment|/* realtime extent size, blocks */
name|xfs_agblock_t
name|sb_agblocks
decl_stmt|;
comment|/* size of an allocation group */
name|xfs_agnumber_t
name|sb_agcount
decl_stmt|;
comment|/* number of allocation groups */
name|xfs_extlen_t
name|sb_rbmblocks
decl_stmt|;
comment|/* number of rt bitmap blocks */
name|xfs_extlen_t
name|sb_logblocks
decl_stmt|;
comment|/* number of log blocks */
name|__uint16_t
name|sb_versionnum
decl_stmt|;
comment|/* header version == XFS_SB_VERSION */
name|__uint16_t
name|sb_sectsize
decl_stmt|;
comment|/* volume sector size, bytes */
name|__uint16_t
name|sb_inodesize
decl_stmt|;
comment|/* inode size, bytes */
name|__uint16_t
name|sb_inopblock
decl_stmt|;
comment|/* inodes per block */
name|char
name|sb_fname
index|[
literal|12
index|]
decl_stmt|;
comment|/* file system name */
name|__uint8_t
name|sb_blocklog
decl_stmt|;
comment|/* log2 of sb_blocksize */
name|__uint8_t
name|sb_sectlog
decl_stmt|;
comment|/* log2 of sb_sectsize */
name|__uint8_t
name|sb_inodelog
decl_stmt|;
comment|/* log2 of sb_inodesize */
name|__uint8_t
name|sb_inopblog
decl_stmt|;
comment|/* log2 of sb_inopblock */
name|__uint8_t
name|sb_agblklog
decl_stmt|;
comment|/* log2 of sb_agblocks (rounded up) */
name|__uint8_t
name|sb_rextslog
decl_stmt|;
comment|/* log2 of sb_rextents */
name|__uint8_t
name|sb_inprogress
decl_stmt|;
comment|/* mkfs is in progress, don't mount */
name|__uint8_t
name|sb_imax_pct
decl_stmt|;
comment|/* max % of fs for inode space */
comment|/* statistics */
comment|/* 	 * These fields must remain contiguous.  If you really 	 * want to change their layout, make sure you fix the 	 * code in xfs_trans_apply_sb_deltas(). 	 */
name|__uint64_t
name|sb_icount
decl_stmt|;
comment|/* allocated inodes */
name|__uint64_t
name|sb_ifree
decl_stmt|;
comment|/* free inodes */
name|__uint64_t
name|sb_fdblocks
decl_stmt|;
comment|/* free data blocks */
name|__uint64_t
name|sb_frextents
decl_stmt|;
comment|/* free realtime extents */
comment|/* 	 * End contiguous fields. 	 */
name|xfs_ino_t
name|sb_uquotino
decl_stmt|;
comment|/* user quota inode */
name|xfs_ino_t
name|sb_gquotino
decl_stmt|;
comment|/* group quota inode */
name|__uint16_t
name|sb_qflags
decl_stmt|;
comment|/* quota flags */
name|__uint8_t
name|sb_flags
decl_stmt|;
comment|/* misc. flags */
name|__uint8_t
name|sb_shared_vn
decl_stmt|;
comment|/* shared version number */
name|xfs_extlen_t
name|sb_inoalignmt
decl_stmt|;
comment|/* inode chunk alignment, fsblocks */
name|__uint32_t
name|sb_unit
decl_stmt|;
comment|/* stripe or raid unit */
name|__uint32_t
name|sb_width
decl_stmt|;
comment|/* stripe or raid width */
name|__uint8_t
name|sb_dirblklog
decl_stmt|;
comment|/* log2 of dir block size (fsbs) */
name|__uint8_t
name|sb_logsectlog
decl_stmt|;
comment|/* log2 of the log sector size */
name|__uint16_t
name|sb_logsectsize
decl_stmt|;
comment|/* sector size for the log, bytes */
name|__uint32_t
name|sb_logsunit
decl_stmt|;
comment|/* stripe unit size for the log */
block|}
name|xfs_sb_t
typedef|;
end_typedef

begin_comment
comment|/*  * Sequence number values for the fields.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|XFS_SBS_MAGICNUM
block|,
name|XFS_SBS_BLOCKSIZE
block|,
name|XFS_SBS_DBLOCKS
block|,
name|XFS_SBS_RBLOCKS
block|,
name|XFS_SBS_REXTENTS
block|,
name|XFS_SBS_UUID
block|,
name|XFS_SBS_LOGSTART
block|,
name|XFS_SBS_ROOTINO
block|,
name|XFS_SBS_RBMINO
block|,
name|XFS_SBS_RSUMINO
block|,
name|XFS_SBS_REXTSIZE
block|,
name|XFS_SBS_AGBLOCKS
block|,
name|XFS_SBS_AGCOUNT
block|,
name|XFS_SBS_RBMBLOCKS
block|,
name|XFS_SBS_LOGBLOCKS
block|,
name|XFS_SBS_VERSIONNUM
block|,
name|XFS_SBS_SECTSIZE
block|,
name|XFS_SBS_INODESIZE
block|,
name|XFS_SBS_INOPBLOCK
block|,
name|XFS_SBS_FNAME
block|,
name|XFS_SBS_BLOCKLOG
block|,
name|XFS_SBS_SECTLOG
block|,
name|XFS_SBS_INODELOG
block|,
name|XFS_SBS_INOPBLOG
block|,
name|XFS_SBS_AGBLKLOG
block|,
name|XFS_SBS_REXTSLOG
block|,
name|XFS_SBS_INPROGRESS
block|,
name|XFS_SBS_IMAX_PCT
block|,
name|XFS_SBS_ICOUNT
block|,
name|XFS_SBS_IFREE
block|,
name|XFS_SBS_FDBLOCKS
block|,
name|XFS_SBS_FREXTENTS
block|,
name|XFS_SBS_UQUOTINO
block|,
name|XFS_SBS_GQUOTINO
block|,
name|XFS_SBS_QFLAGS
block|,
name|XFS_SBS_FLAGS
block|,
name|XFS_SBS_SHARED_VN
block|,
name|XFS_SBS_INOALIGNMT
block|,
name|XFS_SBS_UNIT
block|,
name|XFS_SBS_WIDTH
block|,
name|XFS_SBS_DIRBLKLOG
block|,
name|XFS_SBS_LOGSECTLOG
block|,
name|XFS_SBS_LOGSECTSIZE
block|,
name|XFS_SBS_LOGSUNIT
block|,
name|XFS_SBS_FIELDCOUNT
block|}
name|xfs_sb_field_t
typedef|;
end_typedef

begin_comment
comment|/*  * Mask values, defined based on the xfs_sb_field_t values.  * Only define the ones we're using.  */
end_comment

begin_define
define|#
directive|define
name|XFS_SB_MVAL
parameter_list|(
name|x
parameter_list|)
value|(1LL<< XFS_SBS_ ## x)
end_define

begin_define
define|#
directive|define
name|XFS_SB_UUID
value|XFS_SB_MVAL(UUID)
end_define

begin_define
define|#
directive|define
name|XFS_SB_FNAME
value|XFS_SB_MVAL(FNAME)
end_define

begin_define
define|#
directive|define
name|XFS_SB_ROOTINO
value|XFS_SB_MVAL(ROOTINO)
end_define

begin_define
define|#
directive|define
name|XFS_SB_RBMINO
value|XFS_SB_MVAL(RBMINO)
end_define

begin_define
define|#
directive|define
name|XFS_SB_RSUMINO
value|XFS_SB_MVAL(RSUMINO)
end_define

begin_define
define|#
directive|define
name|XFS_SB_VERSIONNUM
value|XFS_SB_MVAL(VERSIONNUM)
end_define

begin_define
define|#
directive|define
name|XFS_SB_UQUOTINO
value|XFS_SB_MVAL(UQUOTINO)
end_define

begin_define
define|#
directive|define
name|XFS_SB_GQUOTINO
value|XFS_SB_MVAL(GQUOTINO)
end_define

begin_define
define|#
directive|define
name|XFS_SB_QFLAGS
value|XFS_SB_MVAL(QFLAGS)
end_define

begin_define
define|#
directive|define
name|XFS_SB_SHARED_VN
value|XFS_SB_MVAL(SHARED_VN)
end_define

begin_define
define|#
directive|define
name|XFS_SB_UNIT
value|XFS_SB_MVAL(UNIT)
end_define

begin_define
define|#
directive|define
name|XFS_SB_WIDTH
value|XFS_SB_MVAL(WIDTH)
end_define

begin_define
define|#
directive|define
name|XFS_SB_NUM_BITS
value|((int)XFS_SBS_FIELDCOUNT)
end_define

begin_define
define|#
directive|define
name|XFS_SB_ALL_BITS
value|((1LL<< XFS_SB_NUM_BITS) - 1)
end_define

begin_define
define|#
directive|define
name|XFS_SB_MOD_BITS
define|\
value|(XFS_SB_UUID | XFS_SB_ROOTINO | XFS_SB_RBMINO | XFS_SB_RSUMINO | \ 	 XFS_SB_VERSIONNUM | XFS_SB_UQUOTINO | XFS_SB_GQUOTINO | \ 	 XFS_SB_QFLAGS | XFS_SB_SHARED_VN | XFS_SB_UNIT | XFS_SB_WIDTH)
end_define

begin_comment
comment|/*  * Misc. Flags - warning - these will be cleared by xfs_repair unless  * a feature bit is set when the flag is used.  */
end_comment

begin_define
define|#
directive|define
name|XFS_SBF_NOFLAGS
value|0x00
end_define

begin_comment
comment|/* no flags set */
end_comment

begin_define
define|#
directive|define
name|XFS_SBF_READONLY
value|0x01
end_define

begin_comment
comment|/* only read-only mounts allowed */
end_comment

begin_comment
comment|/*  * define max. shared version we can interoperate with  */
end_comment

begin_define
define|#
directive|define
name|XFS_SB_MAX_SHARED_VN
value|0
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
name|XFSSO_XFS_SB_VERSION_NUM
operator|)
end_if

begin_function_decl
name|int
name|xfs_sb_version_num
parameter_list|(
name|xfs_sb_t
modifier|*
name|sbp
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
name|XFSSO_XFS_SB_VERSION_NUM
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_SB_VERSION_NUM
parameter_list|(
name|sbp
parameter_list|)
value|xfs_sb_version_num(sbp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_SB_VERSION_NUM
parameter_list|(
name|sbp
parameter_list|)
value|((sbp)->sb_versionnum& XFS_SB_VERSION_NUMBITS)
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
name|XFSSO_XFS_SB_GOOD_VERSION
operator|)
end_if

begin_function_decl
name|int
name|xfs_sb_good_version
parameter_list|(
name|xfs_sb_t
modifier|*
name|sbp
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
name|XFSSO_XFS_SB_GOOD_VERSION
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_SB_GOOD_VERSION
parameter_list|(
name|sbp
parameter_list|)
value|xfs_sb_good_version(sbp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_SB_GOOD_VERSION_INT
parameter_list|(
name|sbp
parameter_list|)
define|\
value|((((sbp)->sb_versionnum>= XFS_SB_VERSION_1)&& \ 	  ((sbp)->sb_versionnum<= XFS_SB_VERSION_3)) || \ 	 ((XFS_SB_VERSION_NUM(sbp) == XFS_SB_VERSION_4)&& \ 	  !((sbp)->sb_versionnum& ~XFS_SB_VERSION_OKREALBITS)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_define
define|#
directive|define
name|XFS_SB_GOOD_VERSION
parameter_list|(
name|sbp
parameter_list|)
define|\
value|(XFS_SB_GOOD_VERSION_INT(sbp)&& \ 	  (sbp)->sb_shared_vn<= XFS_SB_MAX_SHARED_VN) ))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * extra 2 paren's here (( to unconfuse paren-matching editors  * like vi because XFS_SB_GOOD_VERSION_INT is a partial expression  * and the two XFS_SB_GOOD_VERSION's each 2 more close paren's to  * complete the expression.  */
end_comment

begin_define
define|#
directive|define
name|XFS_SB_GOOD_VERSION
parameter_list|(
name|sbp
parameter_list|)
define|\
value|(XFS_SB_GOOD_VERSION_INT(sbp)&& \ 	  (!((sbp)->sb_versionnum& XFS_SB_VERSION_SHAREDBIT) || \ 	   (sbp)->sb_shared_vn<= XFS_SB_MAX_SHARED_VN)) ))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KERNEL__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XFS_SB_GOOD_SASH_VERSION
parameter_list|(
name|sbp
parameter_list|)
define|\
value|((((sbp)->sb_versionnum>= XFS_SB_VERSION_1)&& \ 	  ((sbp)->sb_versionnum<= XFS_SB_VERSION_3)) || \ 	 ((XFS_SB_VERSION_NUM(sbp) == XFS_SB_VERSION_4)&& \ 	  !((sbp)->sb_versionnum& ~XFS_SB_VERSION_OKSASHBITS)))
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
name|XFSSO_XFS_SB_VERSION_TONEW
operator|)
end_if

begin_function_decl
name|unsigned
name|xfs_sb_version_tonew
parameter_list|(
name|unsigned
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
name|XFSSO_XFS_SB_VERSION_TONEW
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_SB_VERSION_TONEW
parameter_list|(
name|v
parameter_list|)
value|xfs_sb_version_tonew(v)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_SB_VERSION_TONEW
parameter_list|(
name|v
parameter_list|)
define|\
value|((((v) == XFS_SB_VERSION_1) ? \ 		0 : \ 		(((v) == XFS_SB_VERSION_2) ? \ 			XFS_SB_VERSION_ATTRBIT : \ 			(XFS_SB_VERSION_ATTRBIT | XFS_SB_VERSION_NLINKBIT))) | \ 	 XFS_SB_VERSION_4)
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
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_SB_VERSION_TOOLD
operator|)
end_if

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
name|XFSSO_XFS_SB_VERSION_TOOLD
operator|)
end_if

begin_function_decl
name|unsigned
name|xfs_sb_version_toold
parameter_list|(
name|unsigned
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
name|XFSSO_XFS_SB_VERSION_TOOLD
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_SB_VERSION_TOOLD
parameter_list|(
name|v
parameter_list|)
value|xfs_sb_version_toold(v)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_SB_VERSION_TOOLD
parameter_list|(
name|v
parameter_list|)
define|\
value|(((v)& (XFS_SB_VERSION_QUOTABIT | XFS_SB_VERSION_ALIGNBIT)) ? \ 		0 : \ 		(((v)& XFS_SB_VERSION_NLINKBIT) ? \ 			XFS_SB_VERSION_3 : \ 			(((v)& XFS_SB_VERSION_ATTRBIT) ?  \ 				XFS_SB_VERSION_2 : \ 				XFS_SB_VERSION_1)))
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
name|XFSSO_XFS_SB_VERSION_HASATTR
operator|)
end_if

begin_function_decl
name|int
name|xfs_sb_version_hasattr
parameter_list|(
name|xfs_sb_t
modifier|*
name|sbp
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
name|XFSSO_XFS_SB_VERSION_HASATTR
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_SB_VERSION_HASATTR
parameter_list|(
name|sbp
parameter_list|)
value|xfs_sb_version_hasattr(sbp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_SB_VERSION_HASATTR
parameter_list|(
name|sbp
parameter_list|)
define|\
value|(((sbp)->sb_versionnum == XFS_SB_VERSION_2) || \ 	 ((sbp)->sb_versionnum == XFS_SB_VERSION_3) || \ 	 ((XFS_SB_VERSION_NUM(sbp) == XFS_SB_VERSION_4)&& \ 	  ((sbp)->sb_versionnum& XFS_SB_VERSION_ATTRBIT)))
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
name|XFSSO_XFS_SB_VERSION_ADDATTR
operator|)
end_if

begin_function_decl
name|void
name|xfs_sb_version_addattr
parameter_list|(
name|xfs_sb_t
modifier|*
name|sbp
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
name|XFSSO_XFS_SB_VERSION_ADDATTR
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_SB_VERSION_ADDATTR
parameter_list|(
name|sbp
parameter_list|)
value|xfs_sb_version_addattr(sbp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_SB_VERSION_ADDATTR
parameter_list|(
name|sbp
parameter_list|)
define|\
value|((sbp)->sb_versionnum = \ 	 (((sbp)->sb_versionnum == XFS_SB_VERSION_1) ? \ 		XFS_SB_VERSION_2 : \ 		((XFS_SB_VERSION_NUM(sbp) == XFS_SB_VERSION_4) ? \ 			((sbp)->sb_versionnum | XFS_SB_VERSION_ATTRBIT) : \ 			(XFS_SB_VERSION_4 | XFS_SB_VERSION_ATTRBIT))))
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
name|XFSSO_XFS_SB_VERSION_HASNLINK
operator|)
end_if

begin_function_decl
name|int
name|xfs_sb_version_hasnlink
parameter_list|(
name|xfs_sb_t
modifier|*
name|sbp
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
name|XFSSO_XFS_SB_VERSION_HASNLINK
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_SB_VERSION_HASNLINK
parameter_list|(
name|sbp
parameter_list|)
value|xfs_sb_version_hasnlink(sbp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_SB_VERSION_HASNLINK
parameter_list|(
name|sbp
parameter_list|)
define|\
value|(((sbp)->sb_versionnum == XFS_SB_VERSION_3) || \ 	 ((XFS_SB_VERSION_NUM(sbp) == XFS_SB_VERSION_4)&& \ 	  ((sbp)->sb_versionnum& XFS_SB_VERSION_NLINKBIT)))
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
name|XFSSO_XFS_SB_VERSION_ADDNLINK
operator|)
end_if

begin_function_decl
name|void
name|xfs_sb_version_addnlink
parameter_list|(
name|xfs_sb_t
modifier|*
name|sbp
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
name|XFSSO_XFS_SB_VERSION_ADDNLINK
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_SB_VERSION_ADDNLINK
parameter_list|(
name|sbp
parameter_list|)
value|xfs_sb_version_addnlink(sbp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_SB_VERSION_ADDNLINK
parameter_list|(
name|sbp
parameter_list|)
define|\
value|((sbp)->sb_versionnum = \ 	 ((sbp)->sb_versionnum<= XFS_SB_VERSION_2 ? \ 		XFS_SB_VERSION_3 : \ 		((sbp)->sb_versionnum | XFS_SB_VERSION_NLINKBIT)))
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
name|XFSSO_XFS_SB_VERSION_HASQUOTA
operator|)
end_if

begin_function_decl
name|int
name|xfs_sb_version_hasquota
parameter_list|(
name|xfs_sb_t
modifier|*
name|sbp
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
name|XFSSO_XFS_SB_VERSION_HASQUOTA
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_SB_VERSION_HASQUOTA
parameter_list|(
name|sbp
parameter_list|)
value|xfs_sb_version_hasquota(sbp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_SB_VERSION_HASQUOTA
parameter_list|(
name|sbp
parameter_list|)
define|\
value|((XFS_SB_VERSION_NUM(sbp) == XFS_SB_VERSION_4)&& \ 	 ((sbp)->sb_versionnum& XFS_SB_VERSION_QUOTABIT))
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
name|XFSSO_XFS_SB_VERSION_ADDQUOTA
operator|)
end_if

begin_function_decl
name|void
name|xfs_sb_version_addquota
parameter_list|(
name|xfs_sb_t
modifier|*
name|sbp
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
name|XFSSO_XFS_SB_VERSION_ADDQUOTA
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_SB_VERSION_ADDQUOTA
parameter_list|(
name|sbp
parameter_list|)
value|xfs_sb_version_addquota(sbp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_SB_VERSION_ADDQUOTA
parameter_list|(
name|sbp
parameter_list|)
define|\
value|((sbp)->sb_versionnum = \ 	 (XFS_SB_VERSION_NUM(sbp) == XFS_SB_VERSION_4 ? \ 		((sbp)->sb_versionnum | XFS_SB_VERSION_QUOTABIT) : \ 		(XFS_SB_VERSION_TONEW((sbp)->sb_versionnum) | \ 		 XFS_SB_VERSION_QUOTABIT)))
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
name|XFSSO_XFS_SB_VERSION_HASALIGN
operator|)
end_if

begin_function_decl
name|int
name|xfs_sb_version_hasalign
parameter_list|(
name|xfs_sb_t
modifier|*
name|sbp
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
name|XFSSO_XFS_SB_VERSION_HASALIGN
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_SB_VERSION_HASALIGN
parameter_list|(
name|sbp
parameter_list|)
value|xfs_sb_version_hasalign(sbp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_SB_VERSION_HASALIGN
parameter_list|(
name|sbp
parameter_list|)
define|\
value|((XFS_SB_VERSION_NUM(sbp) == XFS_SB_VERSION_4)&& \ 	 ((sbp)->sb_versionnum& XFS_SB_VERSION_ALIGNBIT))
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
name|XFSSO_XFS_SB_VERSION_SUBALIGN
operator|)
end_if

begin_function_decl
name|void
name|xfs_sb_version_subalign
parameter_list|(
name|xfs_sb_t
modifier|*
name|sbp
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
name|XFSSO_XFS_SB_VERSION_SUBALIGN
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_SB_VERSION_SUBALIGN
parameter_list|(
name|sbp
parameter_list|)
value|xfs_sb_version_subalign(sbp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_SB_VERSION_SUBALIGN
parameter_list|(
name|sbp
parameter_list|)
define|\
value|((sbp)->sb_versionnum = \ 	 XFS_SB_VERSION_TOOLD((sbp)->sb_versionnum& ~XFS_SB_VERSION_ALIGNBIT))
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
name|XFSSO_XFS_SB_VERSION_HASDALIGN
operator|)
end_if

begin_function_decl
name|int
name|xfs_sb_version_hasdalign
parameter_list|(
name|xfs_sb_t
modifier|*
name|sbp
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
name|XFSSO_XFS_SB_VERSION_HASDALIGN
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_SB_VERSION_HASDALIGN
parameter_list|(
name|sbp
parameter_list|)
value|xfs_sb_version_hasdalign(sbp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_SB_VERSION_HASDALIGN
parameter_list|(
name|sbp
parameter_list|)
define|\
value|((XFS_SB_VERSION_NUM(sbp) == XFS_SB_VERSION_4)&& \ 	 ((sbp)->sb_versionnum& XFS_SB_VERSION_DALIGNBIT))
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
name|XFSSO_XFS_SB_VERSION_ADDDALIGN
operator|)
end_if

begin_function_decl
name|int
name|xfs_sb_version_adddalign
parameter_list|(
name|xfs_sb_t
modifier|*
name|sbp
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
name|XFSSO_XFS_SB_VERSION_ADDDALIGN
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_SB_VERSION_ADDDALIGN
parameter_list|(
name|sbp
parameter_list|)
value|xfs_sb_version_adddalign(sbp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_SB_VERSION_ADDDALIGN
parameter_list|(
name|sbp
parameter_list|)
define|\
value|((sbp)->sb_versionnum = \ 		((sbp)->sb_versionnum | XFS_SB_VERSION_DALIGNBIT))
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
name|XFSSO_XFS_SB_VERSION_HASSHARED
operator|)
end_if

begin_function_decl
name|int
name|xfs_sb_version_hasshared
parameter_list|(
name|xfs_sb_t
modifier|*
name|sbp
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
name|XFSSO_XFS_SB_VERSION_HASSHARED
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_SB_VERSION_HASSHARED
parameter_list|(
name|sbp
parameter_list|)
value|xfs_sb_version_hasshared(sbp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_SB_VERSION_HASSHARED
parameter_list|(
name|sbp
parameter_list|)
define|\
value|((XFS_SB_VERSION_NUM(sbp) == XFS_SB_VERSION_4)&& \ 	 ((sbp)->sb_versionnum& XFS_SB_VERSION_SHAREDBIT))
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
name|XFSSO_XFS_SB_VERSION_ADDSHARED
operator|)
end_if

begin_function_decl
name|int
name|xfs_sb_version_addshared
parameter_list|(
name|xfs_sb_t
modifier|*
name|sbp
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
name|XFSSO_XFS_SB_VERSION_ADDSHARED
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_SB_VERSION_ADDSHARED
parameter_list|(
name|sbp
parameter_list|)
value|xfs_sb_version_addshared(sbp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_SB_VERSION_ADDSHARED
parameter_list|(
name|sbp
parameter_list|)
define|\
value|((sbp)->sb_versionnum = \ 		((sbp)->sb_versionnum | XFS_SB_VERSION_SHAREDBIT))
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
name|XFSSO_XFS_SB_VERSION_SUBSHARED
operator|)
end_if

begin_function_decl
name|int
name|xfs_sb_version_subshared
parameter_list|(
name|xfs_sb_t
modifier|*
name|sbp
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
name|XFSSO_XFS_SB_VERSION_SUBSHARED
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_SB_VERSION_SUBSHARED
parameter_list|(
name|sbp
parameter_list|)
value|xfs_sb_version_subshared(sbp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_SB_VERSION_SUBSHARED
parameter_list|(
name|sbp
parameter_list|)
define|\
value|((sbp)->sb_versionnum = \ 		((sbp)->sb_versionnum& ~XFS_SB_VERSION_SHAREDBIT))
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
name|XFSSO_XFS_SB_VERSION_HASDIRV2
operator|)
end_if

begin_function_decl
name|int
name|xfs_sb_version_hasdirv2
parameter_list|(
name|xfs_sb_t
modifier|*
name|sbp
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
name|XFSSO_XFS_SB_VERSION_HASDIRV2
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_SB_VERSION_HASDIRV2
parameter_list|(
name|sbp
parameter_list|)
value|xfs_sb_version_hasdirv2(sbp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_SB_VERSION_HASDIRV2
parameter_list|(
name|sbp
parameter_list|)
define|\
value|((XFS_SB_VERSION_NUM(sbp) == XFS_SB_VERSION_4)&& \ 	 ((sbp)->sb_versionnum& XFS_SB_VERSION_DIRV2BIT))
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
name|XFSSO_XFS_SB_VERSION_HASLOGV2
operator|)
end_if

begin_function_decl
name|int
name|xfs_sb_version_haslogv2
parameter_list|(
name|xfs_sb_t
modifier|*
name|sbp
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
name|XFSSO_XFS_SB_VERSION_HASLOGV2
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_SB_VERSION_HASLOGV2
parameter_list|(
name|sbp
parameter_list|)
value|xfs_sb_version_haslogv2(sbp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_SB_VERSION_HASLOGV2
parameter_list|(
name|sbp
parameter_list|)
define|\
value|((XFS_SB_VERSION_NUM(sbp) == XFS_SB_VERSION_4)&& \ 	((sbp)->sb_versionnum& XFS_SB_VERSION_LOGV2BIT))
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
name|XFSSO_XFS_SB_VERSION_HASEXTFLGBIT
operator|)
end_if

begin_function_decl
name|int
name|xfs_sb_version_hasextflgbit
parameter_list|(
name|xfs_sb_t
modifier|*
name|sbp
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
name|XFSSO_XFS_SB_VERSION_HASEXTFLGBIT
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_SB_VERSION_HASEXTFLGBIT
parameter_list|(
name|sbp
parameter_list|)
value|xfs_sb_version_hasextflgbit(sbp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_SB_VERSION_HASEXTFLGBIT
parameter_list|(
name|sbp
parameter_list|)
define|\
value|((XFS_SB_VERSION_NUM(sbp) == XFS_SB_VERSION_4)&& \ 	 ((sbp)->sb_versionnum& XFS_SB_VERSION_EXTFLGBIT))
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
name|XFSSO_XFS_SB_VERSION_ADDEXTFLGBIT
operator|)
end_if

begin_function_decl
name|int
name|xfs_sb_version_addextflgbit
parameter_list|(
name|xfs_sb_t
modifier|*
name|sbp
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
name|XFSSO_XFS_SB_VERSION_ADDEXTFLGBIT
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_SB_VERSION_ADDEXTFLGBIT
parameter_list|(
name|sbp
parameter_list|)
value|xfs_sb_version_addextflgbit(sbp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_SB_VERSION_ADDEXTFLGBIT
parameter_list|(
name|sbp
parameter_list|)
define|\
value|((sbp)->sb_versionnum = \ 		((sbp)->sb_versionnum | XFS_SB_VERSION_EXTFLGBIT))
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
name|XFSSO_XFS_SB_VERSION_SUBEXTFLGBIT
operator|)
end_if

begin_function_decl
name|int
name|xfs_sb_version_subextflgbit
parameter_list|(
name|xfs_sb_t
modifier|*
name|sbp
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
name|XFSSO_XFS_SB_VERSION_SUBEXTFLGBIT
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_SB_VERSION_SUBEXTFLGBIT
parameter_list|(
name|sbp
parameter_list|)
value|xfs_sb_version_subextflgbit(sbp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_SB_VERSION_SUBEXTFLGBIT
parameter_list|(
name|sbp
parameter_list|)
define|\
value|((sbp)->sb_versionnum = \ 		((sbp)->sb_versionnum& ~XFS_SB_VERSION_EXTFLGBIT))
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
name|XFSSO_XFS_SB_VERSION_HASSECTOR
operator|)
end_if

begin_function_decl
name|int
name|xfs_sb_version_hassector
parameter_list|(
name|xfs_sb_t
modifier|*
name|sbp
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
name|XFSSO_XFS_SB_VERSION_HASSECTOR
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_SB_VERSION_HASSECTOR
parameter_list|(
name|sbp
parameter_list|)
value|xfs_sb_version_hassector(sbp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_SB_VERSION_HASSECTOR
parameter_list|(
name|sbp
parameter_list|)
define|\
value|((XFS_SB_VERSION_NUM(sbp) == XFS_SB_VERSION_4)&& \ 	((sbp)->sb_versionnum& XFS_SB_VERSION_SECTORBIT))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * end of superblock version macros  */
end_comment

begin_define
define|#
directive|define
name|XFS_SB_DADDR
value|((xfs_daddr_t)0)
end_define

begin_comment
comment|/* daddr in filesystem/ag */
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
name|XFSSO_XFS_SB_BLOCK
operator|)
end_if

begin_function_decl
name|xfs_agblock_t
name|xfs_sb_block
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
name|XFSSO_XFS_SB_BLOCK
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_SB_BLOCK
parameter_list|(
name|mp
parameter_list|)
value|xfs_sb_block(mp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_SB_BLOCK
parameter_list|(
name|mp
parameter_list|)
value|XFS_HDR_BLOCK(mp, XFS_SB_DADDR)
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
name|XFSSO_XFS_HDR_BLOCK
operator|)
end_if

begin_function_decl
name|xfs_agblock_t
name|xfs_hdr_block
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_daddr_t
name|d
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
name|XFSSO_XFS_HDR_BLOCK
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_HDR_BLOCK
parameter_list|(
name|mp
parameter_list|,
name|d
parameter_list|)
value|xfs_hdr_block(mp,d)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_HDR_BLOCK
parameter_list|(
name|mp
parameter_list|,
name|d
parameter_list|)
value|((xfs_agblock_t)(XFS_BB_TO_FSBT(mp,d)))
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
name|XFSSO_XFS_DADDR_TO_FSB
operator|)
end_if

begin_function_decl
name|xfs_fsblock_t
name|xfs_daddr_to_fsb
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_daddr_t
name|d
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
name|XFSSO_XFS_DADDR_TO_FSB
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_DADDR_TO_FSB
parameter_list|(
name|mp
parameter_list|,
name|d
parameter_list|)
value|xfs_daddr_to_fsb(mp,d)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_DADDR_TO_FSB
parameter_list|(
name|mp
parameter_list|,
name|d
parameter_list|)
define|\
value|XFS_AGB_TO_FSB(mp, XFS_DADDR_TO_AGNO(mp,d), XFS_DADDR_TO_AGBNO(mp,d))
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
name|XFSSO_XFS_FSB_TO_DADDR
operator|)
end_if

begin_function_decl
name|xfs_daddr_t
name|xfs_fsb_to_daddr
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_fsblock_t
name|fsbno
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
name|XFSSO_XFS_FSB_TO_DADDR
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_FSB_TO_DADDR
parameter_list|(
name|mp
parameter_list|,
name|fsbno
parameter_list|)
value|xfs_fsb_to_daddr(mp,fsbno)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_FSB_TO_DADDR
parameter_list|(
name|mp
parameter_list|,
name|fsbno
parameter_list|)
define|\
value|XFS_AGB_TO_DADDR(mp, XFS_FSB_TO_AGNO(mp,fsbno), \ 			 XFS_FSB_TO_AGBNO(mp,fsbno))
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
name|XFSSO_XFS_BUF_TO_SBP
operator|)
end_if

begin_function_decl
name|xfs_sb_t
modifier|*
name|xfs_buf_to_sbp
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
name|XFSSO_XFS_BUF_TO_SBP
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BUF_TO_SBP
parameter_list|(
name|bp
parameter_list|)
value|xfs_buf_to_sbp(bp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BUF_TO_SBP
parameter_list|(
name|bp
parameter_list|)
value|((xfs_sb_t *)XFS_BUF_PTR(bp))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * File system sector to basic block conversions.  */
end_comment

begin_define
define|#
directive|define
name|XFS_FSS_TO_BB
parameter_list|(
name|mp
parameter_list|,
name|sec
parameter_list|)
value|((sec)<< (mp)->m_sectbb_log)
end_define

begin_define
define|#
directive|define
name|XFS_BB_TO_FSS
parameter_list|(
name|mp
parameter_list|,
name|bb
parameter_list|)
define|\
value|(((bb) + (XFS_FSS_TO_BB(mp,1) - 1))>> (mp)->m_sectbb_log)
end_define

begin_define
define|#
directive|define
name|XFS_BB_TO_FSST
parameter_list|(
name|mp
parameter_list|,
name|bb
parameter_list|)
value|((bb)>> (mp)->m_sectbb_log)
end_define

begin_comment
comment|/*  * File system sector to byte conversions.  */
end_comment

begin_define
define|#
directive|define
name|XFS_FSS_TO_B
parameter_list|(
name|mp
parameter_list|,
name|sectno
parameter_list|)
value|((xfs_fsize_t)(sectno)<< (mp)->m_sb.sb_sectlog)
end_define

begin_define
define|#
directive|define
name|XFS_B_TO_FSST
parameter_list|(
name|mp
parameter_list|,
name|b
parameter_list|)
value|(((__uint64_t)(b))>> (mp)->m_sb.sb_sectlog)
end_define

begin_comment
comment|/*  * File system block to basic block conversions.  */
end_comment

begin_define
define|#
directive|define
name|XFS_FSB_TO_BB
parameter_list|(
name|mp
parameter_list|,
name|fsbno
parameter_list|)
value|((fsbno)<< (mp)->m_blkbb_log)
end_define

begin_define
define|#
directive|define
name|XFS_BB_TO_FSB
parameter_list|(
name|mp
parameter_list|,
name|bb
parameter_list|)
define|\
value|(((bb) + (XFS_FSB_TO_BB(mp,1) - 1))>> (mp)->m_blkbb_log)
end_define

begin_define
define|#
directive|define
name|XFS_BB_TO_FSBT
parameter_list|(
name|mp
parameter_list|,
name|bb
parameter_list|)
value|((bb)>> (mp)->m_blkbb_log)
end_define

begin_define
define|#
directive|define
name|XFS_BB_FSB_OFFSET
parameter_list|(
name|mp
parameter_list|,
name|bb
parameter_list|)
value|((bb)& ((mp)->m_bsize - 1))
end_define

begin_comment
comment|/*  * File system block to byte conversions.  */
end_comment

begin_define
define|#
directive|define
name|XFS_FSB_TO_B
parameter_list|(
name|mp
parameter_list|,
name|fsbno
parameter_list|)
value|((xfs_fsize_t)(fsbno)<< (mp)->m_sb.sb_blocklog)
end_define

begin_define
define|#
directive|define
name|XFS_B_TO_FSB
parameter_list|(
name|mp
parameter_list|,
name|b
parameter_list|)
define|\
value|((((__uint64_t)(b)) + (mp)->m_blockmask)>> (mp)->m_sb.sb_blocklog)
end_define

begin_define
define|#
directive|define
name|XFS_B_TO_FSBT
parameter_list|(
name|mp
parameter_list|,
name|b
parameter_list|)
value|(((__uint64_t)(b))>> (mp)->m_sb.sb_blocklog)
end_define

begin_define
define|#
directive|define
name|XFS_B_FSB_OFFSET
parameter_list|(
name|mp
parameter_list|,
name|b
parameter_list|)
value|((b)& (mp)->m_blockmask)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_SB_H__ */
end_comment

end_unit

