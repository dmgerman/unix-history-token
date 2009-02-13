begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2002,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_ERROR_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_ERROR_H__
end_define

begin_define
define|#
directive|define
name|XFS_ERECOVER
value|1
end_define

begin_comment
comment|/* Failure to recover log */
end_comment

begin_define
define|#
directive|define
name|XFS_ELOGSTAT
value|2
end_define

begin_comment
comment|/* Failure to stat log in user space */
end_comment

begin_define
define|#
directive|define
name|XFS_ENOLOGSPACE
value|3
end_define

begin_comment
comment|/* Reservation too large */
end_comment

begin_define
define|#
directive|define
name|XFS_ENOTSUP
value|4
end_define

begin_comment
comment|/* Operation not supported */
end_comment

begin_define
define|#
directive|define
name|XFS_ENOLSN
value|5
end_define

begin_comment
comment|/* Can't find the lsn you asked for */
end_comment

begin_define
define|#
directive|define
name|XFS_ENOTFOUND
value|6
end_define

begin_define
define|#
directive|define
name|XFS_ENOTXFS
value|7
end_define

begin_comment
comment|/* Not XFS filesystem */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|XFS_ERROR_NTRAP
value|10
end_define

begin_decl_stmt
specifier|extern
name|int
name|xfs_etrap
index|[
name|XFS_ERROR_NTRAP
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|xfs_error_trap
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|XFS_ERROR
parameter_list|(
name|e
parameter_list|)
value|xfs_error_trap(e)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_ERROR
parameter_list|(
name|e
parameter_list|)
value|(e)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|xfs_mount
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|xfs_error_report
parameter_list|(
name|char
modifier|*
name|tag
parameter_list|,
name|int
name|level
parameter_list|,
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|char
modifier|*
name|fname
parameter_list|,
name|int
name|linenum
parameter_list|,
name|inst_t
modifier|*
name|ra
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_corruption_error
parameter_list|(
name|char
modifier|*
name|tag
parameter_list|,
name|int
name|level
parameter_list|,
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|void
modifier|*
name|p
parameter_list|,
name|char
modifier|*
name|fname
parameter_list|,
name|int
name|linenum
parameter_list|,
name|inst_t
modifier|*
name|ra
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|XFS_ERROR_REPORT
parameter_list|(
name|e
parameter_list|,
name|lvl
parameter_list|,
name|mp
parameter_list|)
define|\
value|xfs_error_report(e, lvl, mp, __FILE__, __LINE__, __return_address)
end_define

begin_define
define|#
directive|define
name|XFS_CORRUPTION_ERROR
parameter_list|(
name|e
parameter_list|,
name|lvl
parameter_list|,
name|mp
parameter_list|,
name|mem
parameter_list|)
define|\
value|xfs_corruption_error(e, lvl, mp, mem, \ 			     __FILE__, __LINE__, __return_address)
end_define

begin_define
define|#
directive|define
name|XFS_ERRLEVEL_OFF
value|0
end_define

begin_define
define|#
directive|define
name|XFS_ERRLEVEL_LOW
value|1
end_define

begin_define
define|#
directive|define
name|XFS_ERRLEVEL_HIGH
value|5
end_define

begin_comment
comment|/*  * Macros to set EFSCORRUPTED& return/branch.  */
end_comment

begin_define
define|#
directive|define
name|XFS_WANT_CORRUPTED_GOTO
parameter_list|(
name|x
parameter_list|,
name|l
parameter_list|)
define|\
value|{ \ 		int fs_is_ok = (x); \ 		ASSERT(fs_is_ok); \ 		if (unlikely(!fs_is_ok)) { \ 			XFS_ERROR_REPORT("XFS_WANT_CORRUPTED_GOTO", \ 					 XFS_ERRLEVEL_LOW, NULL); \ 			error = XFS_ERROR(EFSCORRUPTED); \ 			goto l; \ 		} \ 	}
end_define

begin_define
define|#
directive|define
name|XFS_WANT_CORRUPTED_RETURN
parameter_list|(
name|x
parameter_list|)
define|\
value|{ \ 		int fs_is_ok = (x); \ 		ASSERT(fs_is_ok); \ 		if (unlikely(!fs_is_ok)) { \ 			XFS_ERROR_REPORT("XFS_WANT_CORRUPTED_RETURN", \ 					 XFS_ERRLEVEL_LOW, NULL); \ 			return XFS_ERROR(EFSCORRUPTED); \ 		} \ 	}
end_define

begin_comment
comment|/*  * error injection tags - the labels can be anything you want  * but each tag should have its own unique number  */
end_comment

begin_define
define|#
directive|define
name|XFS_ERRTAG_NOERROR
value|0
end_define

begin_define
define|#
directive|define
name|XFS_ERRTAG_IFLUSH_1
value|1
end_define

begin_define
define|#
directive|define
name|XFS_ERRTAG_IFLUSH_2
value|2
end_define

begin_define
define|#
directive|define
name|XFS_ERRTAG_IFLUSH_3
value|3
end_define

begin_define
define|#
directive|define
name|XFS_ERRTAG_IFLUSH_4
value|4
end_define

begin_define
define|#
directive|define
name|XFS_ERRTAG_IFLUSH_5
value|5
end_define

begin_define
define|#
directive|define
name|XFS_ERRTAG_IFLUSH_6
value|6
end_define

begin_define
define|#
directive|define
name|XFS_ERRTAG_DA_READ_BUF
value|7
end_define

begin_define
define|#
directive|define
name|XFS_ERRTAG_BTREE_CHECK_LBLOCK
value|8
end_define

begin_define
define|#
directive|define
name|XFS_ERRTAG_BTREE_CHECK_SBLOCK
value|9
end_define

begin_define
define|#
directive|define
name|XFS_ERRTAG_ALLOC_READ_AGF
value|10
end_define

begin_define
define|#
directive|define
name|XFS_ERRTAG_IALLOC_READ_AGI
value|11
end_define

begin_define
define|#
directive|define
name|XFS_ERRTAG_ITOBP_INOTOBP
value|12
end_define

begin_define
define|#
directive|define
name|XFS_ERRTAG_IUNLINK
value|13
end_define

begin_define
define|#
directive|define
name|XFS_ERRTAG_IUNLINK_REMOVE
value|14
end_define

begin_define
define|#
directive|define
name|XFS_ERRTAG_DIR_INO_VALIDATE
value|15
end_define

begin_define
define|#
directive|define
name|XFS_ERRTAG_BULKSTAT_READ_CHUNK
value|16
end_define

begin_define
define|#
directive|define
name|XFS_ERRTAG_IODONE_IOERR
value|17
end_define

begin_define
define|#
directive|define
name|XFS_ERRTAG_STRATREAD_IOERR
value|18
end_define

begin_define
define|#
directive|define
name|XFS_ERRTAG_STRATCMPL_IOERR
value|19
end_define

begin_define
define|#
directive|define
name|XFS_ERRTAG_DIOWRITE_IOERR
value|20
end_define

begin_define
define|#
directive|define
name|XFS_ERRTAG_BMAPIFORMAT
value|21
end_define

begin_define
define|#
directive|define
name|XFS_ERRTAG_MAX
value|22
end_define

begin_comment
comment|/*  * Random factors for above tags, 1 means always, 2 means 1/2 time, etc.  */
end_comment

begin_define
define|#
directive|define
name|XFS_RANDOM_DEFAULT
value|100
end_define

begin_define
define|#
directive|define
name|XFS_RANDOM_IFLUSH_1
value|XFS_RANDOM_DEFAULT
end_define

begin_define
define|#
directive|define
name|XFS_RANDOM_IFLUSH_2
value|XFS_RANDOM_DEFAULT
end_define

begin_define
define|#
directive|define
name|XFS_RANDOM_IFLUSH_3
value|XFS_RANDOM_DEFAULT
end_define

begin_define
define|#
directive|define
name|XFS_RANDOM_IFLUSH_4
value|XFS_RANDOM_DEFAULT
end_define

begin_define
define|#
directive|define
name|XFS_RANDOM_IFLUSH_5
value|XFS_RANDOM_DEFAULT
end_define

begin_define
define|#
directive|define
name|XFS_RANDOM_IFLUSH_6
value|XFS_RANDOM_DEFAULT
end_define

begin_define
define|#
directive|define
name|XFS_RANDOM_DA_READ_BUF
value|XFS_RANDOM_DEFAULT
end_define

begin_define
define|#
directive|define
name|XFS_RANDOM_BTREE_CHECK_LBLOCK
value|(XFS_RANDOM_DEFAULT/4)
end_define

begin_define
define|#
directive|define
name|XFS_RANDOM_BTREE_CHECK_SBLOCK
value|XFS_RANDOM_DEFAULT
end_define

begin_define
define|#
directive|define
name|XFS_RANDOM_ALLOC_READ_AGF
value|XFS_RANDOM_DEFAULT
end_define

begin_define
define|#
directive|define
name|XFS_RANDOM_IALLOC_READ_AGI
value|XFS_RANDOM_DEFAULT
end_define

begin_define
define|#
directive|define
name|XFS_RANDOM_ITOBP_INOTOBP
value|XFS_RANDOM_DEFAULT
end_define

begin_define
define|#
directive|define
name|XFS_RANDOM_IUNLINK
value|XFS_RANDOM_DEFAULT
end_define

begin_define
define|#
directive|define
name|XFS_RANDOM_IUNLINK_REMOVE
value|XFS_RANDOM_DEFAULT
end_define

begin_define
define|#
directive|define
name|XFS_RANDOM_DIR_INO_VALIDATE
value|XFS_RANDOM_DEFAULT
end_define

begin_define
define|#
directive|define
name|XFS_RANDOM_BULKSTAT_READ_CHUNK
value|XFS_RANDOM_DEFAULT
end_define

begin_define
define|#
directive|define
name|XFS_RANDOM_IODONE_IOERR
value|(XFS_RANDOM_DEFAULT/10)
end_define

begin_define
define|#
directive|define
name|XFS_RANDOM_STRATREAD_IOERR
value|(XFS_RANDOM_DEFAULT/10)
end_define

begin_define
define|#
directive|define
name|XFS_RANDOM_STRATCMPL_IOERR
value|(XFS_RANDOM_DEFAULT/10)
end_define

begin_define
define|#
directive|define
name|XFS_RANDOM_DIOWRITE_IOERR
value|(XFS_RANDOM_DEFAULT/10)
end_define

begin_define
define|#
directive|define
name|XFS_RANDOM_BMAPIFORMAT
value|XFS_RANDOM_DEFAULT
end_define

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|DEBUG
argument_list|)
operator|||
name|defined
argument_list|(
name|INDUCE_IO_ERROR
argument_list|)
operator|)
end_if

begin_function_decl
specifier|extern
name|int
name|xfs_error_test
parameter_list|(
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_error_test_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|XFS_NUM_INJECT_ERROR
value|10
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__ANSI_CPP__
end_ifdef

begin_define
define|#
directive|define
name|XFS_TEST_ERROR
parameter_list|(
name|expr
parameter_list|,
name|mp
parameter_list|,
name|tag
parameter_list|,
name|rf
parameter_list|)
define|\
value|((expr) || \ 	 xfs_error_test((tag), (mp)->m_fixedfsid, #expr, __LINE__, __FILE__, \ 			 (rf)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_TEST_ERROR
parameter_list|(
name|expr
parameter_list|,
name|mp
parameter_list|,
name|tag
parameter_list|,
name|rf
parameter_list|)
define|\
value|((expr) || \ 	 xfs_error_test((tag), (mp)->m_fixedfsid, "expr", __LINE__, __FILE__, \ 			(rf)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ANSI_CPP__ */
end_comment

begin_function_decl
specifier|extern
name|int
name|xfs_errortag_add
parameter_list|(
name|int
name|error_tag
parameter_list|,
name|xfs_mount_t
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_errortag_clear
parameter_list|(
name|int
name|error_tag
parameter_list|,
name|xfs_mount_t
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_errortag_clearall
parameter_list|(
name|xfs_mount_t
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_errortag_clearall_umount
parameter_list|(
name|int64_t
name|fsid
parameter_list|,
name|char
modifier|*
name|fsname
parameter_list|,
name|int
name|loud
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
name|XFS_TEST_ERROR
parameter_list|(
name|expr
parameter_list|,
name|mp
parameter_list|,
name|tag
parameter_list|,
name|rf
parameter_list|)
value|(expr)
end_define

begin_define
define|#
directive|define
name|xfs_errortag_add
parameter_list|(
name|tag
parameter_list|,
name|mp
parameter_list|)
value|(ENOSYS)
end_define

begin_define
define|#
directive|define
name|xfs_errortag_clearall
parameter_list|(
name|mp
parameter_list|)
value|(ENOSYS)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (DEBUG || INDUCE_IO_ERROR) */
end_comment

begin_comment
comment|/*  * XFS panic tags -- allow a call to xfs_cmn_err() be turned into  *			a panic by setting xfs_panic_mask in a  *			sysctl.  update xfs_max[XFS_PARAM] if  *			more are added.  */
end_comment

begin_define
define|#
directive|define
name|XFS_NO_PTAG
value|0
end_define

begin_define
define|#
directive|define
name|XFS_PTAG_IFLUSH
value|0x00000001
end_define

begin_define
define|#
directive|define
name|XFS_PTAG_LOGRES
value|0x00000002
end_define

begin_define
define|#
directive|define
name|XFS_PTAG_AILDELETE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|XFS_PTAG_ERROR_REPORT
value|0x00000008
end_define

begin_define
define|#
directive|define
name|XFS_PTAG_SHUTDOWN_CORRUPT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|XFS_PTAG_SHUTDOWN_IOERROR
value|0x00000020
end_define

begin_define
define|#
directive|define
name|XFS_PTAG_SHUTDOWN_LOGERROR
value|0x00000040
end_define

begin_struct_decl
struct_decl|struct
name|xfs_mount
struct_decl|;
end_struct_decl

begin_comment
comment|/* PRINTFLIKE4 */
end_comment

begin_function_decl
specifier|extern
name|void
name|xfs_cmn_err
parameter_list|(
name|int
name|panic_tag
parameter_list|,
name|int
name|level
parameter_list|,
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* PRINTFLIKE3 */
end_comment

begin_function_decl
specifier|extern
name|void
name|xfs_fs_cmn_err
parameter_list|(
name|int
name|level
parameter_list|,
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|xfs_fs_repair_cmn_err
parameter_list|(
name|level
parameter_list|,
name|mp
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|xfs_fs_cmn_err(level, mp, fmt "  Unmount and run xfs_repair.", ## args)
end_define

begin_define
define|#
directive|define
name|xfs_fs_mount_cmn_err
parameter_list|(
name|f
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|((f& XFS_MFSI_QUIET)? cmn_err(CE_WARN, "XFS: " fmt, ## args) : (void)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_ERROR_H__ */
end_comment

end_unit

