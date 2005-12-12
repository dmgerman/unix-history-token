begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2003 Silicon Graphics, Inc.  All Rights Reserved.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Further, this software is distributed without any warranty that it is  * free of the rightful claim of any third person regarding infringement  * or the like.  Any license provided herein, whether implied or  * otherwise, applies only to this software file.  Patent licenses, if  * any, provided herein do not apply to combinations of this program with  * other software, or any other product whatsoever.  *  * You should have received a copy of the GNU General Public License along  * with this program; if not, write the Free Software Foundation, Inc., 59  * Temple Place - Suite 330, Boston MA 02111-1307, USA.  *  * Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,  * Mountain View, CA  94043, or:  *  * http://www.sgi.com  *  * For further information regarding this notice, see:  *  * http://oss.sgi.com/projects/GenInfo/SGIGPLNoticeExplan/  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_RW_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_RW_H__
end_define

begin_struct_decl
struct_decl|struct
name|xfs_buf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_inode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_mount
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Maximum count of bmaps used by read and write paths.  */
end_comment

begin_define
define|#
directive|define
name|XFS_MAX_RW_NBMAPS
value|4
end_define

begin_comment
comment|/*  * Counts of readahead buffers to use based on physical memory size.  * None of these should be more than XFS_MAX_RW_NBMAPS.  */
end_comment

begin_define
define|#
directive|define
name|XFS_RW_NREADAHEAD_16MB
value|2
end_define

begin_define
define|#
directive|define
name|XFS_RW_NREADAHEAD_32MB
value|3
end_define

begin_define
define|#
directive|define
name|XFS_RW_NREADAHEAD_K32
value|4
end_define

begin_define
define|#
directive|define
name|XFS_RW_NREADAHEAD_K64
value|4
end_define

begin_comment
comment|/*  * Maximum size of a buffer that we\'ll map.  Making this  * too big will degrade performance due to the number of  * pages which need to be gathered.  Making it too small  * will prevent us from doing large I/O\'s to hardware that  * needs it.  *  * This is currently set to 512 KB.  */
end_comment

begin_define
define|#
directive|define
name|XFS_MAX_BMAP_LEN_BB
value|1024
end_define

begin_define
define|#
directive|define
name|XFS_MAX_BMAP_LEN_BYTES
value|524288
end_define

begin_comment
comment|/*  * Convert the given file system block to a disk block.  * We have to treat it differently based on whether the  * file is a real time file or not, because the bmap code  * does.  */
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
name|XFSSO_XFS_FSB_TO_DB
operator|)
end_if

begin_function_decl
name|xfs_daddr_t
name|xfs_fsb_to_db
parameter_list|(
name|struct
name|xfs_inode
modifier|*
name|ip
parameter_list|,
name|xfs_fsblock_t
name|fsb
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
name|XFSSO_XFS_FSB_TO_DB
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_FSB_TO_DB
parameter_list|(
name|ip
parameter_list|,
name|fsb
parameter_list|)
value|xfs_fsb_to_db(ip,fsb)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_FSB_TO_DB
parameter_list|(
name|ip
parameter_list|,
name|fsb
parameter_list|)
define|\
value|(((ip)->i_d.di_flags& XFS_DIFLAG_REALTIME) ? \ 		 (xfs_daddr_t)XFS_FSB_TO_BB((ip)->i_mount, (fsb)) : \ 		 XFS_FSB_TO_DADDR((ip)->i_mount, (fsb)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XFS_FSB_TO_DB_IO
parameter_list|(
name|io
parameter_list|,
name|fsb
parameter_list|)
define|\
value|(((io)->io_flags& XFS_IOCORE_RT) ? \ 		 XFS_FSB_TO_BB((io)->io_mount, (fsb)) : \ 		 XFS_FSB_TO_DADDR((io)->io_mount, (fsb)))
end_define

begin_comment
comment|/*  * Prototypes for functions in xfs_rw.c.  */
end_comment

begin_function_decl
name|int
name|xfs_write_clear_setuid
parameter_list|(
name|struct
name|xfs_inode
modifier|*
name|ip
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_bwrite
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|struct
name|xfs_buf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_bioerror
parameter_list|(
name|struct
name|xfs_buf
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_bioerror_relse
parameter_list|(
name|struct
name|xfs_buf
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_read_buf
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_buftarg_t
modifier|*
name|target
parameter_list|,
name|xfs_daddr_t
name|blkno
parameter_list|,
name|int
name|len
parameter_list|,
name|uint
name|flags
parameter_list|,
name|struct
name|xfs_buf
modifier|*
modifier|*
name|bpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_ioerror_alert
parameter_list|(
name|char
modifier|*
name|func
parameter_list|,
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_buf_t
modifier|*
name|bp
parameter_list|,
name|xfs_daddr_t
name|blkno
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Prototypes for functions in xfs_vnodeops.c.  */
end_comment

begin_function_decl
name|int
name|xfs_rwlock
parameter_list|(
name|bhv_desc_t
modifier|*
name|bdp
parameter_list|,
name|vrwlock_t
name|write_lock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_rwunlock
parameter_list|(
name|bhv_desc_t
modifier|*
name|bdp
parameter_list|,
name|vrwlock_t
name|write_lock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_change_file_space
parameter_list|(
name|bhv_desc_t
modifier|*
name|bdp
parameter_list|,
name|int
name|cmd
parameter_list|,
name|xfs_flock64_t
modifier|*
name|bf
parameter_list|,
name|xfs_off_t
name|offset
parameter_list|,
name|cred_t
modifier|*
name|credp
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_set_dmattrs
parameter_list|(
name|bhv_desc_t
modifier|*
name|bdp
parameter_list|,
name|u_int
name|evmask
parameter_list|,
name|u_int16_t
name|state
parameter_list|,
name|cred_t
modifier|*
name|credp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_RW_H__ */
end_comment

end_unit

