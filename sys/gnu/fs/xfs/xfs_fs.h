begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995-2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU Lesser General Public License  * as published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU Lesser General Public License for more details.  *  * You should have received a copy of the GNU Lesser General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_FS_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_FS_H__
end_define

begin_comment
comment|/*  * SGI's XFS filesystem's major stuff (constants, structures)  */
end_comment

begin_define
define|#
directive|define
name|XFS_NAME
value|"xfs"
end_define

begin_comment
comment|/*  * Direct I/O attribute record used with XFS_IOC_DIOINFO  * d_miniosz is the min xfer size, xfer size multiple and file seek offset  * alignment.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_DIOATTR
end_ifndef

begin_struct
struct|struct
name|dioattr
block|{
name|__u32
name|d_mem
decl_stmt|;
comment|/* data buffer memory alignment */
name|__u32
name|d_miniosz
decl_stmt|;
comment|/* min xfer size		*/
name|__u32
name|d_maxiosz
decl_stmt|;
comment|/* max xfer size		*/
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Structure for XFS_IOC_FSGETXATTR[A] and XFS_IOC_FSSETXATTR.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_FSXATTR
end_ifndef

begin_struct
struct|struct
name|fsxattr
block|{
name|__u32
name|fsx_xflags
decl_stmt|;
comment|/* xflags field value (get/set) */
name|__u32
name|fsx_extsize
decl_stmt|;
comment|/* extsize field value (get/set)*/
name|__u32
name|fsx_nextents
decl_stmt|;
comment|/* nextents field value (get)	*/
name|__u32
name|fsx_projid
decl_stmt|;
comment|/* project identifier (get/set) */
name|unsigned
name|char
name|fsx_pad
index|[
literal|12
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Flags for the bs_xflags/fsx_xflags field  * There should be a one-to-one correspondence between these flags and the  * XFS_DIFLAG_s.  */
end_comment

begin_define
define|#
directive|define
name|XFS_XFLAG_REALTIME
value|0x00000001
end_define

begin_comment
comment|/* data in realtime volume */
end_comment

begin_define
define|#
directive|define
name|XFS_XFLAG_PREALLOC
value|0x00000002
end_define

begin_comment
comment|/* preallocated file extents */
end_comment

begin_define
define|#
directive|define
name|XFS_XFLAG_IMMUTABLE
value|0x00000008
end_define

begin_comment
comment|/* file cannot be modified */
end_comment

begin_define
define|#
directive|define
name|XFS_XFLAG_APPEND
value|0x00000010
end_define

begin_comment
comment|/* all writes append */
end_comment

begin_define
define|#
directive|define
name|XFS_XFLAG_SYNC
value|0x00000020
end_define

begin_comment
comment|/* all writes synchronous */
end_comment

begin_define
define|#
directive|define
name|XFS_XFLAG_NOATIME
value|0x00000040
end_define

begin_comment
comment|/* do not update access time */
end_comment

begin_define
define|#
directive|define
name|XFS_XFLAG_NODUMP
value|0x00000080
end_define

begin_comment
comment|/* do not include in backups */
end_comment

begin_define
define|#
directive|define
name|XFS_XFLAG_RTINHERIT
value|0x00000100
end_define

begin_comment
comment|/* create with rt bit set */
end_comment

begin_define
define|#
directive|define
name|XFS_XFLAG_PROJINHERIT
value|0x00000200
end_define

begin_comment
comment|/* create with parents projid */
end_comment

begin_define
define|#
directive|define
name|XFS_XFLAG_NOSYMLINKS
value|0x00000400
end_define

begin_comment
comment|/* disallow symlink creation */
end_comment

begin_define
define|#
directive|define
name|XFS_XFLAG_EXTSIZE
value|0x00000800
end_define

begin_comment
comment|/* extent size allocator hint */
end_comment

begin_define
define|#
directive|define
name|XFS_XFLAG_EXTSZINHERIT
value|0x00001000
end_define

begin_comment
comment|/* inherit inode extent size */
end_comment

begin_define
define|#
directive|define
name|XFS_XFLAG_HASATTR
value|0x80000000
end_define

begin_comment
comment|/* no DIFLAG for this	*/
end_comment

begin_comment
comment|/*  * Structure for XFS_IOC_GETBMAP.  * On input, fill in bmv_offset and bmv_length of the first structure  * to indicate the area of interest in the file, and bmv_entry with the  * number of array elements given.  The first structure is updated on  * return to give the offset and length for the next call.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GETBMAP
end_ifndef

begin_struct
struct|struct
name|getbmap
block|{
name|__s64
name|bmv_offset
decl_stmt|;
comment|/* file offset of segment in blocks */
name|__s64
name|bmv_block
decl_stmt|;
comment|/* starting block (64-bit daddr_t)  */
name|__s64
name|bmv_length
decl_stmt|;
comment|/* length of segment, blocks	    */
name|__s32
name|bmv_count
decl_stmt|;
comment|/* # of entries in array incl. 1st  */
name|__s32
name|bmv_entries
decl_stmt|;
comment|/* # of entries filled in (output)  */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	Structure for XFS_IOC_GETBMAPX.	 Fields bmv_offset through bmv_entries  *	are used exactly as in the getbmap structure.  The getbmapx structure  *	has additional bmv_iflags and bmv_oflags fields. The bmv_iflags field  *	is only used for the first structure.  It contains input flags  *	specifying XFS_IOC_GETBMAPX actions.  The bmv_oflags field is filled  *	in by the XFS_IOC_GETBMAPX command for each returned structure after  *	the first.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GETBMAPX
end_ifndef

begin_struct
struct|struct
name|getbmapx
block|{
name|__s64
name|bmv_offset
decl_stmt|;
comment|/* file offset of segment in blocks */
name|__s64
name|bmv_block
decl_stmt|;
comment|/* starting block (64-bit daddr_t)  */
name|__s64
name|bmv_length
decl_stmt|;
comment|/* length of segment, blocks	    */
name|__s32
name|bmv_count
decl_stmt|;
comment|/* # of entries in array incl. 1st  */
name|__s32
name|bmv_entries
decl_stmt|;
comment|/* # of entries filled in (output). */
name|__s32
name|bmv_iflags
decl_stmt|;
comment|/* input flags (1st structure)	    */
name|__s32
name|bmv_oflags
decl_stmt|;
comment|/* output flags (after 1st structure)*/
name|__s32
name|bmv_unused1
decl_stmt|;
comment|/* future use			    */
name|__s32
name|bmv_unused2
decl_stmt|;
comment|/* future use			    */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*	bmv_iflags values - set by XFS_IOC_GETBMAPX caller.	*/
end_comment

begin_define
define|#
directive|define
name|BMV_IF_ATTRFORK
value|0x1
end_define

begin_comment
comment|/* return attr fork rather than data */
end_comment

begin_define
define|#
directive|define
name|BMV_IF_NO_DMAPI_READ
value|0x2
end_define

begin_comment
comment|/* Do not generate DMAPI read event  */
end_comment

begin_define
define|#
directive|define
name|BMV_IF_PREALLOC
value|0x4
end_define

begin_comment
comment|/* rtn status BMV_OF_PREALLOC if req */
end_comment

begin_define
define|#
directive|define
name|BMV_IF_VALID
value|(BMV_IF_ATTRFORK|BMV_IF_NO_DMAPI_READ|BMV_IF_PREALLOC)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_define
define|#
directive|define
name|BMV_IF_EXTENDED
value|0x40000000
end_define

begin_comment
comment|/* getpmapx if set */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*	bmv_oflags values - returned for for each non-header segment */
end_comment

begin_define
define|#
directive|define
name|BMV_OF_PREALLOC
value|0x1
end_define

begin_comment
comment|/* segment = unwritten pre-allocation */
end_comment

begin_comment
comment|/*	Convert getbmap<-> getbmapx - move fields from p1 to p2. */
end_comment

begin_define
define|#
directive|define
name|GETBMAP_CONVERT
parameter_list|(
name|p1
parameter_list|,
name|p2
parameter_list|)
value|{	\ 	p2.bmv_offset = p1.bmv_offset;	\ 	p2.bmv_block = p1.bmv_block;	\ 	p2.bmv_length = p1.bmv_length;	\ 	p2.bmv_count = p1.bmv_count;	\ 	p2.bmv_entries = p1.bmv_entries; \ 	\ printf("offset 0x%jx block 0x%jx length 0x%jx count 0x%jx entries %d\n", \        (uint64_t)p2.bmv_offset, \        (uint64_t)p2.bmv_block, \        (uint64_t)p2.bmv_length, \        (uint64_t)p2.bmv_count, \        p2.bmv_entries); \   }
end_define

begin_comment
comment|/*  * Structure for XFS_IOC_FSSETDM.  * For use by backup and restore programs to set the XFS on-disk inode  * fields di_dmevmask and di_dmstate.  These must be set to exactly and  * only values previously obtained via xfs_bulkstat!  (Specifically the  * xfs_bstat_t fields bs_dmevmask and bs_dmstate.)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_FSDMIDATA
end_ifndef

begin_struct
struct|struct
name|fsdmidata
block|{
name|__u32
name|fsd_dmevmask
decl_stmt|;
comment|/* corresponds to di_dmevmask */
name|__u16
name|fsd_padding
decl_stmt|;
name|__u16
name|fsd_dmstate
decl_stmt|;
comment|/* corresponds to di_dmstate  */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * File segment locking set data type for 64 bit access.  * Also used for all the RESV/FREE interfaces.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_flock64
block|{
name|__s16
name|l_type
decl_stmt|;
name|__s16
name|l_whence
decl_stmt|;
name|__s64
name|l_start
decl_stmt|;
name|__s64
name|l_len
decl_stmt|;
comment|/* len == 0 means until end of file */
name|__s32
name|l_sysid
decl_stmt|;
name|__u32
name|l_pid
decl_stmt|;
name|__s32
name|l_pad
index|[
literal|4
index|]
decl_stmt|;
comment|/* reserve area			    */
block|}
name|xfs_flock64_t
typedef|;
end_typedef

begin_comment
comment|/*  * Output for XFS_IOC_FSGEOMETRY_V1  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_fsop_geom_v1
block|{
name|__u32
name|blocksize
decl_stmt|;
comment|/* filesystem (data) block size */
name|__u32
name|rtextsize
decl_stmt|;
comment|/* realtime extent size		*/
name|__u32
name|agblocks
decl_stmt|;
comment|/* fsblocks in an AG		*/
name|__u32
name|agcount
decl_stmt|;
comment|/* number of allocation groups	*/
name|__u32
name|logblocks
decl_stmt|;
comment|/* fsblocks in the log		*/
name|__u32
name|sectsize
decl_stmt|;
comment|/* (data) sector size, bytes	*/
name|__u32
name|inodesize
decl_stmt|;
comment|/* inode size in bytes		*/
name|__u32
name|imaxpct
decl_stmt|;
comment|/* max allowed inode space(%)	*/
name|__u64
name|datablocks
decl_stmt|;
comment|/* fsblocks in data subvolume	*/
name|__u64
name|rtblocks
decl_stmt|;
comment|/* fsblocks in realtime subvol	*/
name|__u64
name|rtextents
decl_stmt|;
comment|/* rt extents in realtime subvol*/
name|__u64
name|logstart
decl_stmt|;
comment|/* starting fsblock of the log	*/
name|unsigned
name|char
name|uuid
index|[
literal|16
index|]
decl_stmt|;
comment|/* unique id of the filesystem	*/
name|__u32
name|sunit
decl_stmt|;
comment|/* stripe unit, fsblocks	*/
name|__u32
name|swidth
decl_stmt|;
comment|/* stripe width, fsblocks	*/
name|__s32
name|version
decl_stmt|;
comment|/* structure version		*/
name|__u32
name|flags
decl_stmt|;
comment|/* superblock version flags	*/
name|__u32
name|logsectsize
decl_stmt|;
comment|/* log sector size, bytes	*/
name|__u32
name|rtsectsize
decl_stmt|;
comment|/* realtime sector size, bytes	*/
name|__u32
name|dirblocksize
decl_stmt|;
comment|/* directory block size, bytes	*/
block|}
name|xfs_fsop_geom_v1_t
typedef|;
end_typedef

begin_comment
comment|/*  * Output for XFS_IOC_FSGEOMETRY  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_fsop_geom
block|{
name|__u32
name|blocksize
decl_stmt|;
comment|/* filesystem (data) block size */
name|__u32
name|rtextsize
decl_stmt|;
comment|/* realtime extent size		*/
name|__u32
name|agblocks
decl_stmt|;
comment|/* fsblocks in an AG		*/
name|__u32
name|agcount
decl_stmt|;
comment|/* number of allocation groups	*/
name|__u32
name|logblocks
decl_stmt|;
comment|/* fsblocks in the log		*/
name|__u32
name|sectsize
decl_stmt|;
comment|/* (data) sector size, bytes	*/
name|__u32
name|inodesize
decl_stmt|;
comment|/* inode size in bytes		*/
name|__u32
name|imaxpct
decl_stmt|;
comment|/* max allowed inode space(%)	*/
name|__u64
name|datablocks
decl_stmt|;
comment|/* fsblocks in data subvolume	*/
name|__u64
name|rtblocks
decl_stmt|;
comment|/* fsblocks in realtime subvol	*/
name|__u64
name|rtextents
decl_stmt|;
comment|/* rt extents in realtime subvol*/
name|__u64
name|logstart
decl_stmt|;
comment|/* starting fsblock of the log	*/
name|unsigned
name|char
name|uuid
index|[
literal|16
index|]
decl_stmt|;
comment|/* unique id of the filesystem	*/
name|__u32
name|sunit
decl_stmt|;
comment|/* stripe unit, fsblocks	*/
name|__u32
name|swidth
decl_stmt|;
comment|/* stripe width, fsblocks	*/
name|__s32
name|version
decl_stmt|;
comment|/* structure version		*/
name|__u32
name|flags
decl_stmt|;
comment|/* superblock version flags	*/
name|__u32
name|logsectsize
decl_stmt|;
comment|/* log sector size, bytes	*/
name|__u32
name|rtsectsize
decl_stmt|;
comment|/* realtime sector size, bytes	*/
name|__u32
name|dirblocksize
decl_stmt|;
comment|/* directory block size, bytes	*/
name|__u32
name|logsunit
decl_stmt|;
comment|/* log stripe unit, bytes */
block|}
name|xfs_fsop_geom_t
typedef|;
end_typedef

begin_comment
comment|/* Output for XFS_FS_COUNTS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_fsop_counts
block|{
name|__u64
name|freedata
decl_stmt|;
comment|/* free data section blocks */
name|__u64
name|freertx
decl_stmt|;
comment|/* free rt extents */
name|__u64
name|freeino
decl_stmt|;
comment|/* free inodes */
name|__u64
name|allocino
decl_stmt|;
comment|/* total allocated inodes */
block|}
name|xfs_fsop_counts_t
typedef|;
end_typedef

begin_comment
comment|/* Input/Output for XFS_GET_RESBLKS and XFS_SET_RESBLKS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_fsop_resblks
block|{
name|__u64
name|resblks
decl_stmt|;
name|__u64
name|resblks_avail
decl_stmt|;
block|}
name|xfs_fsop_resblks_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_FSOP_GEOM_VERSION
value|0
end_define

begin_define
define|#
directive|define
name|XFS_FSOP_GEOM_FLAGS_ATTR
value|0x0001
end_define

begin_comment
comment|/* attributes in use	*/
end_comment

begin_define
define|#
directive|define
name|XFS_FSOP_GEOM_FLAGS_NLINK
value|0x0002
end_define

begin_comment
comment|/* 32-bit nlink values	*/
end_comment

begin_define
define|#
directive|define
name|XFS_FSOP_GEOM_FLAGS_QUOTA
value|0x0004
end_define

begin_comment
comment|/* quotas enabled	*/
end_comment

begin_define
define|#
directive|define
name|XFS_FSOP_GEOM_FLAGS_IALIGN
value|0x0008
end_define

begin_comment
comment|/* inode alignment	*/
end_comment

begin_define
define|#
directive|define
name|XFS_FSOP_GEOM_FLAGS_DALIGN
value|0x0010
end_define

begin_comment
comment|/* large data alignment */
end_comment

begin_define
define|#
directive|define
name|XFS_FSOP_GEOM_FLAGS_SHARED
value|0x0020
end_define

begin_comment
comment|/* read-only shared	*/
end_comment

begin_define
define|#
directive|define
name|XFS_FSOP_GEOM_FLAGS_EXTFLG
value|0x0040
end_define

begin_comment
comment|/* special extent flag	*/
end_comment

begin_define
define|#
directive|define
name|XFS_FSOP_GEOM_FLAGS_DIRV2
value|0x0080
end_define

begin_comment
comment|/* directory version 2	*/
end_comment

begin_define
define|#
directive|define
name|XFS_FSOP_GEOM_FLAGS_LOGV2
value|0x0100
end_define

begin_comment
comment|/* log format version 2	*/
end_comment

begin_define
define|#
directive|define
name|XFS_FSOP_GEOM_FLAGS_SECTOR
value|0x0200
end_define

begin_comment
comment|/* sector sizes>1BB	*/
end_comment

begin_define
define|#
directive|define
name|XFS_FSOP_GEOM_FLAGS_ATTR2
value|0x0400
end_define

begin_comment
comment|/* inline attributes rework */
end_comment

begin_comment
comment|/*  * Minimum and maximum sizes need for growth checks  */
end_comment

begin_define
define|#
directive|define
name|XFS_MIN_AG_BLOCKS
value|64
end_define

begin_define
define|#
directive|define
name|XFS_MIN_LOG_BLOCKS
value|512
end_define

begin_define
define|#
directive|define
name|XFS_MAX_LOG_BLOCKS
value|(64 * 1024)
end_define

begin_define
define|#
directive|define
name|XFS_MIN_LOG_BYTES
value|(256 * 1024)
end_define

begin_define
define|#
directive|define
name|XFS_MAX_LOG_BYTES
value|(128 * 1024 * 1024)
end_define

begin_comment
comment|/*  * Structures for XFS_IOC_FSGROWFSDATA, XFS_IOC_FSGROWFSLOG& XFS_IOC_FSGROWFSRT  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_growfs_data
block|{
name|__u64
name|newblocks
decl_stmt|;
comment|/* new data subvol size, fsblocks */
name|__u32
name|imaxpct
decl_stmt|;
comment|/* new inode space percentage limit */
block|}
name|xfs_growfs_data_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_growfs_log
block|{
name|__u32
name|newblocks
decl_stmt|;
comment|/* new log size, fsblocks */
name|__u32
name|isint
decl_stmt|;
comment|/* 1 if new log is internal */
block|}
name|xfs_growfs_log_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_growfs_rt
block|{
name|__u64
name|newblocks
decl_stmt|;
comment|/* new realtime size, fsblocks */
name|__u32
name|extsize
decl_stmt|;
comment|/* new realtime extent size, fsblocks */
block|}
name|xfs_growfs_rt_t
typedef|;
end_typedef

begin_comment
comment|/*  * Structures returned from ioctl XFS_IOC_FSBULKSTAT& XFS_IOC_FSBULKSTAT_SINGLE  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_bstime
block|{
name|time_t
name|tv_sec
decl_stmt|;
comment|/* seconds		*/
name|__s32
name|tv_nsec
decl_stmt|;
comment|/* and nanoseconds	*/
block|}
name|xfs_bstime_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_bstat
block|{
name|__u64
name|bs_ino
decl_stmt|;
comment|/* inode number			*/
name|__u16
name|bs_mode
decl_stmt|;
comment|/* type and mode		*/
name|__u16
name|bs_nlink
decl_stmt|;
comment|/* number of links		*/
name|__u32
name|bs_uid
decl_stmt|;
comment|/* user id			*/
name|__u32
name|bs_gid
decl_stmt|;
comment|/* group id			*/
name|__u32
name|bs_rdev
decl_stmt|;
comment|/* device value			*/
name|__s32
name|bs_blksize
decl_stmt|;
comment|/* block size			*/
name|__s64
name|bs_size
decl_stmt|;
comment|/* file size			*/
name|xfs_bstime_t
name|bs_atime
decl_stmt|;
comment|/* access time			*/
name|xfs_bstime_t
name|bs_mtime
decl_stmt|;
comment|/* modify time			*/
name|xfs_bstime_t
name|bs_ctime
decl_stmt|;
comment|/* inode change time		*/
name|int64_t
name|bs_blocks
decl_stmt|;
comment|/* number of blocks		*/
name|__u32
name|bs_xflags
decl_stmt|;
comment|/* extended flags		*/
name|__s32
name|bs_extsize
decl_stmt|;
comment|/* extent size			*/
name|__s32
name|bs_extents
decl_stmt|;
comment|/* number of extents		*/
name|__u32
name|bs_gen
decl_stmt|;
comment|/* generation count		*/
name|__u16
name|bs_projid
decl_stmt|;
comment|/* project id			*/
name|unsigned
name|char
name|bs_pad
index|[
literal|14
index|]
decl_stmt|;
comment|/* pad space, unused		*/
name|__u32
name|bs_dmevmask
decl_stmt|;
comment|/* DMIG event mask		*/
name|__u16
name|bs_dmstate
decl_stmt|;
comment|/* DMIG state info		*/
name|__u16
name|bs_aextents
decl_stmt|;
comment|/* attribute number of extents	*/
block|}
name|xfs_bstat_t
typedef|;
end_typedef

begin_comment
comment|/*  * The user-level BulkStat Request interface structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_fsop_bulkreq
block|{
name|__u64
name|__user
modifier|*
name|lastip
decl_stmt|;
comment|/* last inode # pointer		*/
name|__s32
name|icount
decl_stmt|;
comment|/* count of entries in buffer	*/
name|void
name|__user
modifier|*
name|ubuffer
decl_stmt|;
comment|/* user buffer for inode desc.	*/
name|__s32
name|__user
modifier|*
name|ocount
decl_stmt|;
comment|/* output count pointer		*/
block|}
name|xfs_fsop_bulkreq_t
typedef|;
end_typedef

begin_comment
comment|/*  * Structures returned from xfs_inumbers routine (XFS_IOC_FSINUMBERS).  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_inogrp
block|{
name|__u64
name|xi_startino
decl_stmt|;
comment|/* starting inode number	*/
name|__s32
name|xi_alloccount
decl_stmt|;
comment|/* # bits set in allocmask	*/
name|__u64
name|xi_allocmask
decl_stmt|;
comment|/* mask of allocated inodes	*/
block|}
name|xfs_inogrp_t
typedef|;
end_typedef

begin_comment
comment|/*  * Error injection.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_error_injection
block|{
name|__s32
name|fd
decl_stmt|;
name|__s32
name|errtag
decl_stmt|;
block|}
name|xfs_error_injection_t
typedef|;
end_typedef

begin_comment
comment|/*  * The user-level Handle Request interface structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_fsop_handlereq
block|{
name|__u32
name|fd
decl_stmt|;
comment|/* fd for FD_TO_HANDLE		*/
name|void
name|__user
modifier|*
name|path
decl_stmt|;
comment|/* user pathname		*/
name|__u32
name|oflags
decl_stmt|;
comment|/* open flags			*/
name|void
name|__user
modifier|*
name|ihandle
decl_stmt|;
comment|/* user supplied handle		*/
name|__u32
name|ihandlen
decl_stmt|;
comment|/* user supplied length		*/
name|void
name|__user
modifier|*
name|ohandle
decl_stmt|;
comment|/* user buffer for handle	*/
name|__u32
name|__user
modifier|*
name|ohandlen
decl_stmt|;
comment|/* user buffer length		*/
block|}
name|xfs_fsop_handlereq_t
typedef|;
end_typedef

begin_comment
comment|/*  * Compound structures for passing args through Handle Request interfaces  * xfs_fssetdm_by_handle, xfs_attrlist_by_handle, xfs_attrmulti_by_handle  * - ioctls: XFS_IOC_FSSETDM_BY_HANDLE, XFS_IOC_ATTRLIST_BY_HANDLE, and  *	     XFS_IOC_ATTRMULTI_BY_HANDLE  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_fsop_setdm_handlereq
block|{
name|struct
name|xfs_fsop_handlereq
name|hreq
decl_stmt|;
comment|/* handle information	*/
name|struct
name|fsdmidata
name|__user
modifier|*
name|data
decl_stmt|;
comment|/* DMAPI data	*/
block|}
name|xfs_fsop_setdm_handlereq_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_attrlist_cursor
block|{
name|__u32
name|opaque
index|[
literal|4
index|]
decl_stmt|;
block|}
name|xfs_attrlist_cursor_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_fsop_attrlist_handlereq
block|{
name|struct
name|xfs_fsop_handlereq
name|hreq
decl_stmt|;
comment|/* handle interface structure */
name|struct
name|xfs_attrlist_cursor
name|pos
decl_stmt|;
comment|/* opaque cookie, list offset */
name|__u32
name|flags
decl_stmt|;
comment|/* which namespace to use */
name|__u32
name|buflen
decl_stmt|;
comment|/* length of buffer supplied */
name|void
name|__user
modifier|*
name|buffer
decl_stmt|;
comment|/* returned names */
block|}
name|xfs_fsop_attrlist_handlereq_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_attr_multiop
block|{
name|__u32
name|am_opcode
decl_stmt|;
name|__s32
name|am_error
decl_stmt|;
name|void
name|__user
modifier|*
name|am_attrname
decl_stmt|;
name|void
name|__user
modifier|*
name|am_attrvalue
decl_stmt|;
name|__u32
name|am_length
decl_stmt|;
name|__u32
name|am_flags
decl_stmt|;
block|}
name|xfs_attr_multiop_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_fsop_attrmulti_handlereq
block|{
name|struct
name|xfs_fsop_handlereq
name|hreq
decl_stmt|;
comment|/* handle interface structure */
name|__u32
name|opcount
decl_stmt|;
comment|/* count of following multiop */
name|struct
name|xfs_attr_multiop
name|__user
modifier|*
name|ops
decl_stmt|;
comment|/* attr_multi data */
block|}
name|xfs_fsop_attrmulti_handlereq_t
typedef|;
end_typedef

begin_comment
comment|/*  * per machine unique filesystem identifier types.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|__u32
name|val
index|[
literal|2
index|]
decl_stmt|;
block|}
name|xfs_fsid_t
typedef|;
end_typedef

begin_comment
comment|/* file system id type */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_FID
end_ifndef

begin_define
define|#
directive|define
name|MAXFIDSZ
value|46
end_define

begin_typedef
typedef|typedef
struct|struct
name|fid
block|{
name|__u16
name|fid_len
decl_stmt|;
comment|/* length of data in bytes */
name|unsigned
name|char
name|fid_data
index|[
name|MAXFIDSZ
index|]
decl_stmt|;
comment|/* data (fid_len worth)  */
block|}
name|fid_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|xfs_fid
block|{
name|__u16
name|xfs_fid_len
decl_stmt|;
comment|/* length of remainder	*/
name|__u16
name|xfs_fid_pad
decl_stmt|;
name|__u32
name|xfs_fid_gen
decl_stmt|;
comment|/* generation number	*/
name|__u64
name|xfs_fid_ino
decl_stmt|;
comment|/* 64 bits inode number */
block|}
name|xfs_fid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_fid2
block|{
name|__u16
name|fid_len
decl_stmt|;
comment|/* length of remainder */
name|__u16
name|fid_pad
decl_stmt|;
comment|/* padding, must be zero */
name|__u32
name|fid_gen
decl_stmt|;
comment|/* generation number */
name|__u64
name|fid_ino
decl_stmt|;
comment|/* inode number */
block|}
name|xfs_fid2_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_handle
block|{
union|union
block|{
name|__s64
name|align
decl_stmt|;
comment|/* force alignment of ha_fid	 */
name|xfs_fsid_t
name|_ha_fsid
decl_stmt|;
comment|/* unique file system identifier */
block|}
name|ha_u
union|;
name|xfs_fid_t
name|ha_fid
decl_stmt|;
comment|/* file system specific file ID	 */
block|}
name|xfs_handle_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ha_fsid
value|ha_u._ha_fsid
end_define

begin_define
define|#
directive|define
name|XFS_HSIZE
parameter_list|(
name|handle
parameter_list|)
value|(((char *)&(handle).ha_fid.xfs_fid_pad	 \ 				 - (char *)&(handle))			  \ 				 + (handle).ha_fid.xfs_fid_len)
end_define

begin_define
define|#
directive|define
name|XFS_HANDLE_CMP
parameter_list|(
name|h1
parameter_list|,
name|h2
parameter_list|)
value|memcmp(h1, h2, sizeof(xfs_handle_t))
end_define

begin_define
define|#
directive|define
name|FSHSIZE
value|sizeof(fsid_t)
end_define

begin_comment
comment|/*   * Flags for going down operation  */
end_comment

begin_define
define|#
directive|define
name|XFS_FSOP_GOING_FLAGS_DEFAULT
value|0x0
end_define

begin_comment
comment|/* going down */
end_comment

begin_define
define|#
directive|define
name|XFS_FSOP_GOING_FLAGS_LOGFLUSH
value|0x1
end_define

begin_comment
comment|/* flush log but not data */
end_comment

begin_define
define|#
directive|define
name|XFS_FSOP_GOING_FLAGS_NOLOGFLUSH
value|0x2
end_define

begin_comment
comment|/* don't flush log nor data */
end_comment

begin_comment
comment|/*  * ioctl commands that are used by Linux filesystems  */
end_comment

begin_define
define|#
directive|define
name|XFS_IOC_GETXFLAGS
value|_IOR('f', 1, long)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_SETXFLAGS
value|_IOW('f', 2, long)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_GETVERSION
value|_IOR('v', 1, long)
end_define

begin_comment
comment|/*  * ioctl commands that replace IRIX fcntl()'s  * For 'documentation' purposed more than anything else,  * the "cmd #" field reflects the IRIX fcntl number.  */
end_comment

begin_define
define|#
directive|define
name|XFS_IOC_ALLOCSP
value|_IOW ('X', 10, struct xfs_flock64)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_FREESP
value|_IOW ('X', 11, struct xfs_flock64)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_DIOINFO
value|_IOR ('X', 30, struct dioattr)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_FSGETXATTR
value|_IOR ('X', 31, struct fsxattr)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_FSSETXATTR
value|_IOW ('X', 32, struct fsxattr)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_ALLOCSP64
value|_IOW ('X', 36, struct xfs_flock64)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_FREESP64
value|_IOW ('X', 37, struct xfs_flock64)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_GETBMAP
value|_IOWR('X', 38, struct getbmap)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_FSSETDM
value|_IOW ('X', 39, struct fsdmidata)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_RESVSP
value|_IOW ('X', 40, struct xfs_flock64)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_UNRESVSP
value|_IOW ('X', 41, struct xfs_flock64)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_RESVSP64
value|_IOW ('X', 42, struct xfs_flock64)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_UNRESVSP64
value|_IOW ('X', 43, struct xfs_flock64)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_GETBMAPA
value|_IOWR('X', 44, struct getbmap)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_FSGETXATTRA
value|_IOR ('X', 45, struct fsxattr)
end_define

begin_comment
comment|/*	XFS_IOC_SETBIOSIZE ---- deprecated 46	   */
end_comment

begin_comment
comment|/*	XFS_IOC_GETBIOSIZE ---- deprecated 47	   */
end_comment

begin_comment
comment|//#define XFS_IOC_GETBMAPX	_IOWR('X', 56, struct getbmapx)
end_comment

begin_define
define|#
directive|define
name|XFS_IOC_GETBMAPX
value|_IOC(IOC_INOUT, 'X', 56, (256 * sizeof(struct getbmapx)))
end_define

begin_comment
comment|/*  * ioctl commands that replace IRIX syssgi()'s  */
end_comment

begin_define
define|#
directive|define
name|XFS_IOC_FSGEOMETRY_V1
value|_IOR ('X', 100, struct xfs_fsop_geom_v1)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_FSBULKSTAT
value|_IOWR('X', 101, struct xfs_fsop_bulkreq)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_FSBULKSTAT_SINGLE
value|_IOWR('X', 102, struct xfs_fsop_bulkreq)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_FSINUMBERS
value|_IOWR('X', 103, struct xfs_fsop_bulkreq)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_PATH_TO_FSHANDLE
value|_IOWR('X', 104, struct xfs_fsop_handlereq)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_PATH_TO_HANDLE
value|_IOWR('X', 105, struct xfs_fsop_handlereq)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_FD_TO_HANDLE
value|_IOWR('X', 106, struct xfs_fsop_handlereq)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_OPEN_BY_HANDLE
value|_IOWR('X', 107, struct xfs_fsop_handlereq)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_READLINK_BY_HANDLE
value|_IOWR('X', 108, struct xfs_fsop_handlereq)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_SWAPEXT
value|_IOWR('X', 109, struct xfs_swapext)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_FSGROWFSDATA
value|_IOW ('X', 110, struct xfs_growfs_data)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_FSGROWFSLOG
value|_IOW ('X', 111, struct xfs_growfs_log)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_FSGROWFSRT
value|_IOW ('X', 112, struct xfs_growfs_rt)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_FSCOUNTS
value|_IOR ('X', 113, struct xfs_fsop_counts)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_SET_RESBLKS
value|_IOWR('X', 114, struct xfs_fsop_resblks)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_GET_RESBLKS
value|_IOR ('X', 115, struct xfs_fsop_resblks)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_ERROR_INJECTION
value|_IOW ('X', 116, struct xfs_error_injection)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_ERROR_CLEARALL
value|_IOW ('X', 117, struct xfs_error_injection)
end_define

begin_comment
comment|/*	XFS_IOC_ATTRCTL_BY_HANDLE -- deprecated 118	 */
end_comment

begin_define
define|#
directive|define
name|XFS_IOC_FREEZE
value|_IOWR('X', 119, int)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_THAW
value|_IOWR('X', 120, int)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_FSSETDM_BY_HANDLE
value|_IOW ('X', 121, struct xfs_fsop_setdm_handlereq)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_ATTRLIST_BY_HANDLE
value|_IOW ('X', 122, struct xfs_fsop_attrlist_handlereq)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_ATTRMULTI_BY_HANDLE
value|_IOW ('X', 123, struct xfs_fsop_attrmulti_handlereq)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_FSGEOMETRY
value|_IOR ('X', 124, struct xfs_fsop_geom)
end_define

begin_define
define|#
directive|define
name|XFS_IOC_GOINGDOWN
value|_IOR ('X', 125, __uint32_t)
end_define

begin_comment
comment|/*	XFS_IOC_GETFSUUID ---------- deprecated 140	 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_BBMACROS
end_ifndef

begin_comment
comment|/*  * Block I/O parameterization.	A basic block (BB) is the lowest size of  * filesystem allocation, and must equal 512.  Length units given to bio  * routines are in BB's.  */
end_comment

begin_define
define|#
directive|define
name|BBSHIFT
value|9
end_define

begin_define
define|#
directive|define
name|BBSIZE
value|(1<<BBSHIFT)
end_define

begin_define
define|#
directive|define
name|BBMASK
value|(BBSIZE-1)
end_define

begin_define
define|#
directive|define
name|BTOBB
parameter_list|(
name|bytes
parameter_list|)
value|(((__u64)(bytes) + BBSIZE - 1)>> BBSHIFT)
end_define

begin_define
define|#
directive|define
name|BTOBBT
parameter_list|(
name|bytes
parameter_list|)
value|((__u64)(bytes)>> BBSHIFT)
end_define

begin_define
define|#
directive|define
name|BBTOB
parameter_list|(
name|bbs
parameter_list|)
value|((bbs)<< BBSHIFT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_FS_H__ */
end_comment

end_unit

