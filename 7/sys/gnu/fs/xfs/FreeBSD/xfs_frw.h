begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2003 Silicon Graphics, Inc.  All Rights Reserved.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Further, this software is distributed without any warranty that it is  * free of the rightful claim of any third person regarding infringement  * or the like.  Any license provided herein, whether implied or  * otherwise, applies only to this software file.  Patent licenses, if  * any, provided herein do not apply to combinations of this program with  * other software, or any other product whatsoever.  *  * You should have received a copy of the GNU General Public License along  * with this program; if not, write the Free Software Foundation, Inc., 59  * Temple Place - Suite 330, Boston MA 02111-1307, USA.  *  * Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,  * Mountain View, CA  94043, or:  *  * http://www.sgi.com  *  * For further information regarding this notice, see:  *  * http://oss.sgi.com/projects/GenInfo/SGIGPLNoticeExplan/  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_FRW_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_FRW_H__
end_define

begin_struct_decl
struct_decl|struct
name|xfs_vnode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bhv_desc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_mount
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_iocore
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_inode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_bmbt_irec
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_buf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_iomap
struct_decl|;
end_struct_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|XFS_RW_TRACE
argument_list|)
end_if

begin_comment
comment|/*  * Defines for the trace mechanisms in xfs_lrw.c.  */
end_comment

begin_define
define|#
directive|define
name|XFS_RW_KTRACE_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|XFS_READ_ENTER
value|1
end_define

begin_define
define|#
directive|define
name|XFS_WRITE_ENTER
value|2
end_define

begin_define
define|#
directive|define
name|XFS_IOMAP_READ_ENTER
value|3
end_define

begin_define
define|#
directive|define
name|XFS_IOMAP_WRITE_ENTER
value|4
end_define

begin_define
define|#
directive|define
name|XFS_IOMAP_READ_MAP
value|5
end_define

begin_define
define|#
directive|define
name|XFS_IOMAP_WRITE_MAP
value|6
end_define

begin_define
define|#
directive|define
name|XFS_IOMAP_WRITE_NOSPACE
value|7
end_define

begin_define
define|#
directive|define
name|XFS_ITRUNC_START
value|8
end_define

begin_define
define|#
directive|define
name|XFS_ITRUNC_FINISH1
value|9
end_define

begin_define
define|#
directive|define
name|XFS_ITRUNC_FINISH2
value|10
end_define

begin_define
define|#
directive|define
name|XFS_CTRUNC1
value|11
end_define

begin_define
define|#
directive|define
name|XFS_CTRUNC2
value|12
end_define

begin_define
define|#
directive|define
name|XFS_CTRUNC3
value|13
end_define

begin_define
define|#
directive|define
name|XFS_CTRUNC4
value|14
end_define

begin_define
define|#
directive|define
name|XFS_CTRUNC5
value|15
end_define

begin_define
define|#
directive|define
name|XFS_CTRUNC6
value|16
end_define

begin_define
define|#
directive|define
name|XFS_BUNMAPI
value|17
end_define

begin_define
define|#
directive|define
name|XFS_INVAL_CACHED
value|18
end_define

begin_define
define|#
directive|define
name|XFS_DIORD_ENTER
value|19
end_define

begin_define
define|#
directive|define
name|XFS_DIOWR_ENTER
value|20
end_define

begin_define
define|#
directive|define
name|XFS_SENDFILE_ENTER
value|21
end_define

begin_define
define|#
directive|define
name|XFS_WRITEPAGE_ENTER
value|22
end_define

begin_define
define|#
directive|define
name|XFS_RELEASEPAGE_ENTER
value|23
end_define

begin_define
define|#
directive|define
name|XFS_IOMAP_ALLOC_ENTER
value|24
end_define

begin_define
define|#
directive|define
name|XFS_IOMAP_ALLOC_MAP
value|25
end_define

begin_define
define|#
directive|define
name|XFS_IOMAP_UNWRITTEN
value|26
end_define

begin_function_decl
specifier|extern
name|void
name|xfs_rw_enter_trace
parameter_list|(
name|int
parameter_list|,
name|struct
name|xfs_iocore
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|loff_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_inval_cached_trace
parameter_list|(
name|struct
name|xfs_iocore
modifier|*
parameter_list|,
name|xfs_off_t
parameter_list|,
name|xfs_off_t
parameter_list|,
name|xfs_off_t
parameter_list|,
name|xfs_off_t
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|xfs_rw_enter_trace
parameter_list|(
name|tag
parameter_list|,
name|io
parameter_list|,
name|buf
parameter_list|,
name|size
parameter_list|,
name|offset
parameter_list|,
name|ioflags
parameter_list|)
end_define

begin_define
define|#
directive|define
name|xfs_inval_cached_trace
parameter_list|(
name|io
parameter_list|,
name|offset
parameter_list|,
name|len
parameter_list|,
name|first
parameter_list|,
name|last
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Maximum count of bmaps used by read and write paths.  */
end_comment

begin_define
define|#
directive|define
name|XFS_MAX_RW_NBMAPS
value|4
end_define

begin_function_decl
specifier|extern
name|int
name|xfs_bmap
parameter_list|(
name|struct
name|bhv_desc
modifier|*
parameter_list|,
name|xfs_off_t
parameter_list|,
name|ssize_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|xfs_iomap
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfsbdstrat
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|,
name|struct
name|xfs_buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_bdstrat_cb
parameter_list|(
name|struct
name|xfs_buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_zero_eof
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
parameter_list|,
name|struct
name|xfs_iocore
modifier|*
parameter_list|,
name|xfs_off_t
parameter_list|,
name|xfs_fsize_t
parameter_list|,
name|xfs_fsize_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_inval_cached_pages
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
parameter_list|,
name|struct
name|xfs_iocore
modifier|*
parameter_list|,
name|xfs_off_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ssize_t
name|xfs_read
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|uio_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|cred_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ssize_t
name|xfs_write
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|uio_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|cred_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_dev_is_read_only
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_read_file
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|struct
name|xfs_inode
modifier|*
name|ip
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
name|ioflag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_write_file
parameter_list|(
name|struct
name|xfs_inode
modifier|*
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_FRW_H__ */
end_comment

end_unit

