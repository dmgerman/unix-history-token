begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2003 Silicon Graphics, Inc.  All Rights Reserved.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Further, this software is distributed without any warranty that it is  * free of the rightful claim of any third person regarding infringement  * or the like.  Any license provided herein, whether implied or  * otherwise, applies only to this software file.  Patent licenses, if  * any, provided herein do not apply to combinations of this program with  * other software, or any other product whatsoever.  *  * You should have received a copy of the GNU General Public License along  * with this program; if not, write the Free Software Foundation, Inc., 59  * Temple Place - Suite 330, Boston MA 02111-1307, USA.  *  * Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,  * Mountain View, CA  94043, or:  *  * http://www.sgi.com  *  * For further information regarding this notice, see:  *  * http://oss.sgi.com/projects/GenInfo/SGIGPLNoticeExplan/  */
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

begin_if
if|#
directive|if
name|__BYTE_ORDER
operator|==
name|__LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|LSN_FIELD_CYCLE
parameter_list|(
name|arch
parameter_list|)
value|(((arch)==ARCH_NOCONVERT)?1:0)
end_define

begin_define
define|#
directive|define
name|LSN_FIELD_BLOCK
parameter_list|(
name|arch
parameter_list|)
value|(((arch)==ARCH_NOCONVERT)?0:1)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LSN_FIELD_CYCLE
parameter_list|(
name|arch
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|LSN_FIELD_BLOCK
parameter_list|(
name|arch
parameter_list|)
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* get lsn fields */
end_comment

begin_define
define|#
directive|define
name|CYCLE_LSN
parameter_list|(
name|lsn
parameter_list|,
name|arch
parameter_list|)
value|(INT_GET(((uint *)&(lsn))[LSN_FIELD_CYCLE(arch)], arch))
end_define

begin_define
define|#
directive|define
name|BLOCK_LSN
parameter_list|(
name|lsn
parameter_list|,
name|arch
parameter_list|)
value|(INT_GET(((uint *)&(lsn))[LSN_FIELD_BLOCK(arch)], arch))
end_define

begin_comment
comment|/* this is used in a spot where we might otherwise double-endian-flip */
end_comment

begin_define
define|#
directive|define
name|CYCLE_LSN_NOCONV
parameter_list|(
name|lsn
parameter_list|,
name|arch
parameter_list|)
value|(((uint *)&(lsn))[LSN_FIELD_CYCLE(arch)])
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_comment
comment|/*  * By comparing each compnent, we don't have to worry about extra  * endian issues in treating two 32 bit numbers as one 64 bit number  */
end_comment

begin_expr_stmt
specifier|static
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|==
literal|2
operator|)
operator|&&
operator|(
operator|(
name|__GNUC_MINOR__
operator|==
literal|95
operator|)
operator|||
operator|(
name|__GNUC_MINOR__
operator|==
literal|96
operator|)
operator|)
name|__attribute__
argument_list|(
argument|(unused)
argument_list|)
comment|/* gcc 2.95, 2.96 miscompile this when inlined */
else|#
directive|else
name|__inline__
endif|#
directive|endif
name|xfs_lsn_t
name|_lsn_cmp
argument_list|(
argument|xfs_lsn_t lsn1
argument_list|,
argument|xfs_lsn_t lsn2
argument_list|,
argument|xfs_arch_t arch
argument_list|)
block|{
if|if
condition|(
name|CYCLE_LSN
argument_list|(
name|lsn1
argument_list|,
name|arch
argument_list|)
operator|!=
name|CYCLE_LSN
argument_list|(
name|lsn2
argument_list|,
name|arch
argument_list|)
condition|)
return|return
operator|(
name|CYCLE_LSN
argument_list|(
name|lsn1
argument_list|,
name|arch
argument_list|)
operator|<
name|CYCLE_LSN
argument_list|(
name|lsn2
argument_list|,
name|arch
argument_list|)
operator|)
operator|?
operator|-
literal|999
operator|:
literal|999
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|BLOCK_LSN
argument_list|(
name|lsn1
argument_list|,
name|arch
argument_list|)
operator|!=
name|BLOCK_LSN
argument_list|(
name|lsn2
argument_list|,
name|arch
argument_list|)
condition|)
return|return
operator|(
name|BLOCK_LSN
argument_list|(
name|lsn1
argument_list|,
name|arch
argument_list|)
operator|<
name|BLOCK_LSN
argument_list|(
name|lsn2
argument_list|,
name|arch
argument_list|)
operator|)
condition|?
operator|-
literal|999
else|:
literal|999
return|;
end_if

begin_return
return|return
literal|0
return|;
end_return

begin_define
unit|}
define|#
directive|define
name|XFS_LSN_CMP_ARCH
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|arch
parameter_list|)
value|_lsn_cmp(x, y, arch)
end_define

begin_define
define|#
directive|define
name|XFS_LSN_CMP
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|XFS_LSN_CMP_ARCH(x,y,ARCH_NOCONVERT)
end_define

begin_define
define|#
directive|define
name|XFS_LSN_DIFF_ARCH
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|arch
parameter_list|)
value|_lsn_cmp(x, y, arch)
end_define

begin_define
define|#
directive|define
name|XFS_LSN_DIFF
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|XFS_LSN_DIFF_ARCH(x,y,ARCH_NOCONVERT)
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

begin_struct
unit|typedef
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
block|}
name|xfs_log_iovec_t
struct|;
end_struct

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
name|xfs_log_force
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
parameter_list|)
function_decl|;
end_function_decl

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

