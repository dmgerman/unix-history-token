begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2003,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_LOG_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_LOG_H__
end_define

begin_comment
comment|/* get lsn fields */
end_comment

begin_define
define|#
directive|define
name|CYCLE_LSN
parameter_list|(
name|lsn
parameter_list|)
value|((uint)((lsn)>>32))
end_define

begin_define
define|#
directive|define
name|BLOCK_LSN
parameter_list|(
name|lsn
parameter_list|)
value|((uint)(lsn))
end_define

begin_comment
comment|/* this is used in a spot where we might otherwise double-endian-flip */
end_comment

begin_define
define|#
directive|define
name|CYCLE_LSN_DISK
parameter_list|(
name|lsn
parameter_list|)
value|(((uint *)&(lsn))[0])
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_comment
comment|/*  * By comparing each component, we don't have to worry about extra  * endian issues in treating two 32 bit numbers as one 64 bit number  */
end_comment

begin_function
specifier|static
specifier|inline
name|xfs_lsn_t
name|_lsn_cmp
parameter_list|(
name|xfs_lsn_t
name|lsn1
parameter_list|,
name|xfs_lsn_t
name|lsn2
parameter_list|)
block|{
if|if
condition|(
name|CYCLE_LSN
argument_list|(
name|lsn1
argument_list|)
operator|!=
name|CYCLE_LSN
argument_list|(
name|lsn2
argument_list|)
condition|)
return|return
operator|(
name|CYCLE_LSN
argument_list|(
name|lsn1
argument_list|)
operator|<
name|CYCLE_LSN
argument_list|(
name|lsn2
argument_list|)
operator|)
condition|?
operator|-
literal|999
else|:
literal|999
return|;
if|if
condition|(
name|BLOCK_LSN
argument_list|(
name|lsn1
argument_list|)
operator|!=
name|BLOCK_LSN
argument_list|(
name|lsn2
argument_list|)
condition|)
return|return
operator|(
name|BLOCK_LSN
argument_list|(
name|lsn1
argument_list|)
operator|<
name|BLOCK_LSN
argument_list|(
name|lsn2
argument_list|)
operator|)
condition|?
operator|-
literal|999
else|:
literal|999
return|;
return|return
literal|0
return|;
block|}
end_function

begin_define
define|#
directive|define
name|XFS_LSN_CMP
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|_lsn_cmp(x,y)
end_define

begin_comment
comment|/*  * Macros, structures, prototypes for interface to the log manager.  */
end_comment

begin_comment
comment|/*  * Flags to xfs_log_mount  */
end_comment

begin_define
define|#
directive|define
name|XFS_LOG_RECOVER
value|0x1
end_define

begin_comment
comment|/*  * Flags to xfs_log_done()  */
end_comment

begin_define
define|#
directive|define
name|XFS_LOG_REL_PERM_RESERV
value|0x1
end_define

begin_comment
comment|/*  * Flags to xfs_log_reserve()  *  *	XFS_LOG_SLEEP:	 If space is not available, sleep (default)  *	XFS_LOG_NOSLEEP: If space is not available, return error  *	XFS_LOG_PERM_RESERV: Permanent reservation.  When writes are  *		performed against this type of reservation, the reservation  *		is not decreased.  Long running transactions should use this.  */
end_comment

begin_define
define|#
directive|define
name|XFS_LOG_SLEEP
value|0x0
end_define

begin_define
define|#
directive|define
name|XFS_LOG_NOSLEEP
value|0x1
end_define

begin_define
define|#
directive|define
name|XFS_LOG_PERM_RESERV
value|0x2
end_define

begin_define
define|#
directive|define
name|XFS_LOG_RESV_ALL
value|(XFS_LOG_NOSLEEP|XFS_LOG_PERM_RESERV)
end_define

begin_comment
comment|/*  * Flags to xfs_log_force()  *  *	XFS_LOG_SYNC:	Synchronous force in-core log to disk  *	XFS_LOG_FORCE:	Start in-core log write now.  *	XFS_LOG_URGE:	Start write within some window of time.  *  * Note: Either XFS_LOG_FORCE or XFS_LOG_URGE must be set.  */
end_comment

begin_define
define|#
directive|define
name|XFS_LOG_SYNC
value|0x1
end_define

begin_define
define|#
directive|define
name|XFS_LOG_FORCE
value|0x2
end_define

begin_define
define|#
directive|define
name|XFS_LOG_URGE
value|0x4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KERNEL__ */
end_comment

begin_comment
comment|/* Log Clients */
end_comment

begin_define
define|#
directive|define
name|XFS_TRANSACTION
value|0x69
end_define

begin_define
define|#
directive|define
name|XFS_VOLUME
value|0x2
end_define

begin_define
define|#
directive|define
name|XFS_LOG
value|0xaa
end_define

begin_comment
comment|/* Region types for iovec's i_type */
end_comment

begin_define
define|#
directive|define
name|XLOG_REG_TYPE_BFORMAT
value|1
end_define

begin_define
define|#
directive|define
name|XLOG_REG_TYPE_BCHUNK
value|2
end_define

begin_define
define|#
directive|define
name|XLOG_REG_TYPE_EFI_FORMAT
value|3
end_define

begin_define
define|#
directive|define
name|XLOG_REG_TYPE_EFD_FORMAT
value|4
end_define

begin_define
define|#
directive|define
name|XLOG_REG_TYPE_IFORMAT
value|5
end_define

begin_define
define|#
directive|define
name|XLOG_REG_TYPE_ICORE
value|6
end_define

begin_define
define|#
directive|define
name|XLOG_REG_TYPE_IEXT
value|7
end_define

begin_define
define|#
directive|define
name|XLOG_REG_TYPE_IBROOT
value|8
end_define

begin_define
define|#
directive|define
name|XLOG_REG_TYPE_ILOCAL
value|9
end_define

begin_define
define|#
directive|define
name|XLOG_REG_TYPE_IATTR_EXT
value|10
end_define

begin_define
define|#
directive|define
name|XLOG_REG_TYPE_IATTR_BROOT
value|11
end_define

begin_define
define|#
directive|define
name|XLOG_REG_TYPE_IATTR_LOCAL
value|12
end_define

begin_define
define|#
directive|define
name|XLOG_REG_TYPE_QFORMAT
value|13
end_define

begin_define
define|#
directive|define
name|XLOG_REG_TYPE_DQUOT
value|14
end_define

begin_define
define|#
directive|define
name|XLOG_REG_TYPE_QUOTAOFF
value|15
end_define

begin_define
define|#
directive|define
name|XLOG_REG_TYPE_LRHEADER
value|16
end_define

begin_define
define|#
directive|define
name|XLOG_REG_TYPE_UNMOUNT
value|17
end_define

begin_define
define|#
directive|define
name|XLOG_REG_TYPE_COMMIT
value|18
end_define

begin_define
define|#
directive|define
name|XLOG_REG_TYPE_TRANSHDR
value|19
end_define

begin_define
define|#
directive|define
name|XLOG_REG_TYPE_MAX
value|19
end_define

begin_define
define|#
directive|define
name|XLOG_VEC_SET_TYPE
parameter_list|(
name|vecp
parameter_list|,
name|t
parameter_list|)
value|((vecp)->i_type = (t))
end_define

begin_typedef
typedef|typedef
struct|struct
name|xfs_log_iovec
block|{
name|xfs_caddr_t
name|i_addr
decl_stmt|;
comment|/* beginning address of region */
name|int
name|i_len
decl_stmt|;
comment|/* length in bytes of region */
name|uint
name|i_type
decl_stmt|;
comment|/* type of region */
block|}
name|xfs_log_iovec_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|xfs_log_ticket_t
typedef|;
end_typedef

begin_comment
comment|/*  * Structure used to pass callback function and the function's argument  * to the log manager.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_log_callback
block|{
name|struct
name|xfs_log_callback
modifier|*
name|cb_next
decl_stmt|;
name|void
function_decl|(
modifier|*
name|cb_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
modifier|*
name|cb_arg
decl_stmt|;
block|}
name|xfs_log_callback_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_comment
comment|/* Log manager interfaces */
end_comment

begin_struct_decl
struct_decl|struct
name|xfs_mount
struct_decl|;
end_struct_decl

begin_function_decl
name|xfs_lsn_t
name|xfs_log_done
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_log_ticket_t
name|ticket
parameter_list|,
name|void
modifier|*
modifier|*
name|iclog
parameter_list|,
name|uint
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_xfs_log_force
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_lsn_t
name|lsn
parameter_list|,
name|uint
name|flags
parameter_list|,
name|int
modifier|*
name|log_forced
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|xfs_log_force
parameter_list|(
name|mp
parameter_list|,
name|lsn
parameter_list|,
name|flags
parameter_list|)
define|\
value|_xfs_log_force(mp, lsn, flags, NULL);
end_define

begin_function_decl
name|int
name|xfs_log_mount
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|struct
name|xfs_buftarg
modifier|*
name|log_target
parameter_list|,
name|xfs_daddr_t
name|start_block
parameter_list|,
name|int
name|num_bblocks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_log_mount_finish
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_log_move_tail
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_lsn_t
name|tail_lsn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_log_notify
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|void
modifier|*
name|iclog
parameter_list|,
name|xfs_log_callback_t
modifier|*
name|callback_entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_log_release_iclog
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|void
modifier|*
name|iclog_hndl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_log_reserve
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|int
name|length
parameter_list|,
name|int
name|count
parameter_list|,
name|xfs_log_ticket_t
modifier|*
name|ticket
parameter_list|,
name|__uint8_t
name|clientid
parameter_list|,
name|uint
name|flags
parameter_list|,
name|uint
name|t_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_log_write
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_log_iovec_t
name|region
index|[]
parameter_list|,
name|int
name|nentries
parameter_list|,
name|xfs_log_ticket_t
name|ticket
parameter_list|,
name|xfs_lsn_t
modifier|*
name|start_lsn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_log_unmount
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_log_unmount_write
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_log_unmount_dealloc
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_log_force_umount
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|int
name|logerror
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_log_need_covered
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xlog_iodone
parameter_list|(
name|struct
name|xfs_buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|xlog_debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to 1 to enable real log */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_LOG_H__ */
end_comment

end_unit

