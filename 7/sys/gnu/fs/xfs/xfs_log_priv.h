begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2003,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_LOG_PRIV_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_LOG_PRIV_H__
end_define

begin_struct_decl
struct_decl|struct
name|xfs_buf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ktrace
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|log
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xlog_ticket
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_buf_cancel
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_mount
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Macros, structures, prototypes for internal log manager use.  */
end_comment

begin_define
define|#
directive|define
name|XLOG_MIN_ICLOGS
value|2
end_define

begin_define
define|#
directive|define
name|XLOG_MED_ICLOGS
value|4
end_define

begin_define
define|#
directive|define
name|XLOG_MAX_ICLOGS
value|8
end_define

begin_define
define|#
directive|define
name|XLOG_CALLBACK_SIZE
value|10
end_define

begin_define
define|#
directive|define
name|XLOG_HEADER_MAGIC_NUM
value|0xFEEDbabe
end_define

begin_comment
comment|/* Invalid cycle number */
end_comment

begin_define
define|#
directive|define
name|XLOG_VERSION_1
value|1
end_define

begin_define
define|#
directive|define
name|XLOG_VERSION_2
value|2
end_define

begin_comment
comment|/* Large IClogs, Log sunit */
end_comment

begin_define
define|#
directive|define
name|XLOG_VERSION_OKBITS
value|(XLOG_VERSION_1 | XLOG_VERSION_2)
end_define

begin_define
define|#
directive|define
name|XLOG_RECORD_BSIZE
value|(16*1024)
end_define

begin_comment
comment|/* eventually 32k */
end_comment

begin_define
define|#
directive|define
name|XLOG_BIG_RECORD_BSIZE
value|(32*1024)
end_define

begin_comment
comment|/* 32k buffers */
end_comment

begin_define
define|#
directive|define
name|XLOG_MAX_RECORD_BSIZE
value|(256*1024)
end_define

begin_define
define|#
directive|define
name|XLOG_HEADER_CYCLE_SIZE
value|(32*1024)
end_define

begin_comment
comment|/* cycle data in header */
end_comment

begin_define
define|#
directive|define
name|XLOG_RECORD_BSHIFT
value|14
end_define

begin_comment
comment|/* 16384 == 1<< 14 */
end_comment

begin_define
define|#
directive|define
name|XLOG_BIG_RECORD_BSHIFT
value|15
end_define

begin_comment
comment|/* 32k == 1<< 15 */
end_comment

begin_define
define|#
directive|define
name|XLOG_MAX_RECORD_BSHIFT
value|18
end_define

begin_comment
comment|/* 256k == 1<< 18 */
end_comment

begin_define
define|#
directive|define
name|XLOG_BTOLSUNIT
parameter_list|(
name|log
parameter_list|,
name|b
parameter_list|)
value|(((b)+(log)->l_mp->m_sb.sb_logsunit-1) / \                                  (log)->l_mp->m_sb.sb_logsunit)
end_define

begin_define
define|#
directive|define
name|XLOG_LSUNITTOB
parameter_list|(
name|log
parameter_list|,
name|su
parameter_list|)
value|((su) * (log)->l_mp->m_sb.sb_logsunit)
end_define

begin_define
define|#
directive|define
name|XLOG_HEADER_SIZE
value|512
end_define

begin_define
define|#
directive|define
name|XLOG_REC_SHIFT
parameter_list|(
name|log
parameter_list|)
define|\
value|BTOBB(1<< (XFS_SB_VERSION_HASLOGV2(&log->l_mp->m_sb) ? \ 	 XLOG_MAX_RECORD_BSHIFT : XLOG_BIG_RECORD_BSHIFT))
end_define

begin_define
define|#
directive|define
name|XLOG_TOTAL_REC_SHIFT
parameter_list|(
name|log
parameter_list|)
define|\
value|BTOBB(XLOG_MAX_ICLOGS<< (XFS_SB_VERSION_HASLOGV2(&log->l_mp->m_sb) ? \ 	 XLOG_MAX_RECORD_BSHIFT : XLOG_BIG_RECORD_BSHIFT))
end_define

begin_comment
comment|/*  *  set lsns  */
end_comment

begin_define
define|#
directive|define
name|ASSIGN_ANY_LSN_HOST
parameter_list|(
name|lsn
parameter_list|,
name|cycle
parameter_list|,
name|block
parameter_list|)
define|\
value|{ \ 	(lsn) = ((xfs_lsn_t)(cycle)<<32)|(block); \     }
end_define

begin_define
define|#
directive|define
name|ASSIGN_ANY_LSN_DISK
parameter_list|(
name|lsn
parameter_list|,
name|cycle
parameter_list|,
name|block
parameter_list|)
define|\
value|{ \ 	INT_SET(((uint *)&(lsn))[0], ARCH_CONVERT, (cycle)); \ 	INT_SET(((uint *)&(lsn))[1], ARCH_CONVERT, (block)); \     }
end_define

begin_define
define|#
directive|define
name|ASSIGN_LSN
parameter_list|(
name|lsn
parameter_list|,
name|log
parameter_list|)
define|\
value|ASSIGN_ANY_LSN_DISK(lsn,(log)->l_curr_cycle,(log)->l_curr_block);
end_define

begin_define
define|#
directive|define
name|XLOG_SET
parameter_list|(
name|f
parameter_list|,
name|b
parameter_list|)
value|(((f)& (b)) == (b))
end_define

begin_define
define|#
directive|define
name|GET_CYCLE
parameter_list|(
name|ptr
parameter_list|,
name|arch
parameter_list|)
define|\
value|(INT_GET(*(uint *)(ptr), arch) == XLOG_HEADER_MAGIC_NUM ? \ 	 INT_GET(*((uint *)(ptr)+1), arch) : \ 	 INT_GET(*(uint *)(ptr), arch) \     )
end_define

begin_define
define|#
directive|define
name|BLK_AVG
parameter_list|(
name|blk1
parameter_list|,
name|blk2
parameter_list|)
value|((blk1+blk2)>> 1)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_comment
comment|/*  * get client id from packed copy.  *  * this hack is here because the xlog_pack code copies four bytes  * of xlog_op_header containing the fields oh_clientid, oh_flags  * and oh_res2 into the packed copy.  *  * later on this four byte chunk is treated as an int and the  * client id is pulled out.  *  * this has endian issues, of course.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XFS_NATIVE_HOST
end_ifndef

begin_define
define|#
directive|define
name|GET_CLIENT_ID
parameter_list|(
name|i
parameter_list|,
name|arch
parameter_list|)
define|\
value|((i)& 0xff)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GET_CLIENT_ID
parameter_list|(
name|i
parameter_list|,
name|arch
parameter_list|)
define|\
value|((i)>> 24)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|GRANT_LOCK
parameter_list|(
name|log
parameter_list|)
value|mutex_spinlock(&(log)->l_grant_lock)
end_define

begin_define
define|#
directive|define
name|GRANT_UNLOCK
parameter_list|(
name|log
parameter_list|,
name|s
parameter_list|)
value|mutex_spinunlock(&(log)->l_grant_lock, s)
end_define

begin_define
define|#
directive|define
name|LOG_LOCK
parameter_list|(
name|log
parameter_list|)
value|mutex_spinlock(&(log)->l_icloglock)
end_define

begin_define
define|#
directive|define
name|LOG_UNLOCK
parameter_list|(
name|log
parameter_list|,
name|s
parameter_list|)
value|mutex_spinunlock(&(log)->l_icloglock, s)
end_define

begin_define
define|#
directive|define
name|xlog_panic
parameter_list|(
name|args
modifier|...
parameter_list|)
value|cmn_err(CE_PANIC, ## args)
end_define

begin_define
define|#
directive|define
name|xlog_exit
parameter_list|(
name|args
modifier|...
parameter_list|)
value|cmn_err(CE_PANIC, ## args)
end_define

begin_define
define|#
directive|define
name|xlog_warn
parameter_list|(
name|args
modifier|...
parameter_list|)
value|cmn_err(CE_WARN, ## args)
end_define

begin_comment
comment|/*  * In core log state  */
end_comment

begin_define
define|#
directive|define
name|XLOG_STATE_ACTIVE
value|0x0001
end_define

begin_comment
comment|/* Current IC log being written to */
end_comment

begin_define
define|#
directive|define
name|XLOG_STATE_WANT_SYNC
value|0x0002
end_define

begin_comment
comment|/* Want to sync this iclog; no more writes */
end_comment

begin_define
define|#
directive|define
name|XLOG_STATE_SYNCING
value|0x0004
end_define

begin_comment
comment|/* This IC log is syncing */
end_comment

begin_define
define|#
directive|define
name|XLOG_STATE_DONE_SYNC
value|0x0008
end_define

begin_comment
comment|/* Done syncing to disk */
end_comment

begin_define
define|#
directive|define
name|XLOG_STATE_DO_CALLBACK
define|\
value|0x0010
end_define

begin_comment
comment|/* Process callback functions */
end_comment

begin_define
define|#
directive|define
name|XLOG_STATE_CALLBACK
value|0x0020
end_define

begin_comment
comment|/* Callback functions now */
end_comment

begin_define
define|#
directive|define
name|XLOG_STATE_DIRTY
value|0x0040
end_define

begin_comment
comment|/* Dirty IC log, not ready for ACTIVE status*/
end_comment

begin_define
define|#
directive|define
name|XLOG_STATE_IOERROR
value|0x0080
end_define

begin_comment
comment|/* IO error happened in sync'ing log */
end_comment

begin_define
define|#
directive|define
name|XLOG_STATE_ALL
value|0x7FFF
end_define

begin_comment
comment|/* All possible valid flags */
end_comment

begin_define
define|#
directive|define
name|XLOG_STATE_NOTUSED
value|0x8000
end_define

begin_comment
comment|/* This IC log not being used */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KERNEL__ */
end_comment

begin_comment
comment|/*  * Flags to log operation header  *  * The first write of a new transaction will be preceded with a start  * record, XLOG_START_TRANS.  Once a transaction is committed, a commit  * record is written, XLOG_COMMIT_TRANS.  If a single region can not fit into  * the remainder of the current active in-core log, it is split up into  * multiple regions.  Each partial region will be marked with a  * XLOG_CONTINUE_TRANS until the last one, which gets marked with XLOG_END_TRANS.  *  */
end_comment

begin_define
define|#
directive|define
name|XLOG_START_TRANS
value|0x01
end_define

begin_comment
comment|/* Start a new transaction */
end_comment

begin_define
define|#
directive|define
name|XLOG_COMMIT_TRANS
value|0x02
end_define

begin_comment
comment|/* Commit this transaction */
end_comment

begin_define
define|#
directive|define
name|XLOG_CONTINUE_TRANS
value|0x04
end_define

begin_comment
comment|/* Cont this trans into new region */
end_comment

begin_define
define|#
directive|define
name|XLOG_WAS_CONT_TRANS
value|0x08
end_define

begin_comment
comment|/* Cont this trans into new region */
end_comment

begin_define
define|#
directive|define
name|XLOG_END_TRANS
value|0x10
end_define

begin_comment
comment|/* End a continued transaction */
end_comment

begin_define
define|#
directive|define
name|XLOG_UNMOUNT_TRANS
value|0x20
end_define

begin_comment
comment|/* Unmount a filesystem transaction */
end_comment

begin_define
define|#
directive|define
name|XLOG_SKIP_TRANS
value|(XLOG_COMMIT_TRANS | XLOG_CONTINUE_TRANS | \ 				 XLOG_WAS_CONT_TRANS | XLOG_END_TRANS | \ 				 XLOG_UNMOUNT_TRANS)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_comment
comment|/*  * Flags to log ticket  */
end_comment

begin_define
define|#
directive|define
name|XLOG_TIC_INITED
value|0x1
end_define

begin_comment
comment|/* has been initialized */
end_comment

begin_define
define|#
directive|define
name|XLOG_TIC_PERM_RESERV
value|0x2
end_define

begin_comment
comment|/* permanent reservation */
end_comment

begin_define
define|#
directive|define
name|XLOG_TIC_IN_Q
value|0x4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KERNEL__ */
end_comment

begin_define
define|#
directive|define
name|XLOG_UNMOUNT_TYPE
value|0x556e
end_define

begin_comment
comment|/* Un for Unmount */
end_comment

begin_comment
comment|/*  * Flags for log structure  */
end_comment

begin_define
define|#
directive|define
name|XLOG_CHKSUM_MISMATCH
value|0x1
end_define

begin_comment
comment|/* used only during recovery */
end_comment

begin_define
define|#
directive|define
name|XLOG_ACTIVE_RECOVERY
value|0x2
end_define

begin_comment
comment|/* in the middle of recovery */
end_comment

begin_define
define|#
directive|define
name|XLOG_RECOVERY_NEEDED
value|0x4
end_define

begin_comment
comment|/* log was recovered */
end_comment

begin_define
define|#
directive|define
name|XLOG_IO_ERROR
value|0x8
end_define

begin_comment
comment|/* log hit an I/O error, and being 					   shutdown */
end_comment

begin_typedef
typedef|typedef
name|__uint32_t
name|xlog_tid_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_comment
comment|/*  * Below are states for covering allocation transactions.  * By covering, we mean changing the h_tail_lsn in the last on-disk  * log write such that no allocation transactions will be re-done during  * recovery after a system crash. Recovery starts at the last on-disk  * log write.  *  * These states are used to insert dummy log entries to cover  * space allocation transactions which can undo non-transactional changes  * after a crash. Writes to a file with space  * already allocated do not result in any transactions. Allocations  * might include space beyond the EOF. So if we just push the EOF a  * little, the last transaction for the file could contain the wrong  * size. If there is no file system activity, after an allocation  * transaction, and the system crashes, the allocation transaction  * will get replayed and the file will be truncated. This could  * be hours/days/... after the allocation occurred.  *  * The fix for this is to do two dummy transactions when the  * system is idle. We need two dummy transaction because the h_tail_lsn  * in the log record header needs to point beyond the last possible  * non-dummy transaction. The first dummy changes the h_tail_lsn to  * the first transaction before the dummy. The second dummy causes  * h_tail_lsn to point to the first dummy. Recovery starts at h_tail_lsn.  *  * These dummy transactions get committed when everything  * is idle (after there has been some activity).  *  * There are 5 states used to control this.  *  *  IDLE -- no logging has been done on the file system or  *		we are done covering previous transactions.  *  NEED -- logging has occurred and we need a dummy transaction  *		when the log becomes idle.  *  DONE -- we were in the NEED state and have committed a dummy  *		transaction.  *  NEED2 -- we detected that a dummy transaction has gone to the  *		on disk log with no other transactions.  *  DONE2 -- we committed a dummy transaction when in the NEED2 state.  *  * There are two places where we switch states:  *  * 1.) In xfs_sync, when we detect an idle log and are in NEED or NEED2.  *	We commit the dummy transaction and switch to DONE or DONE2,  *	respectively. In all other states, we don't do anything.  *  * 2.) When we finish writing the on-disk log (xlog_state_clean_log).  *  *	No matter what state we are in, if this isn't the dummy  *	transaction going out, the next state is NEED.  *	So, if we aren't in the DONE or DONE2 states, the next state  *	is NEED. We can't be finishing a write of the dummy record  *	unless it was committed and the state switched to DONE or DONE2.  *  *	If we are in the DONE state and this was a write of the  *		dummy transaction, we move to NEED2.  *  *	If we are in the DONE2 state and this was a write of the  *		dummy transaction, we move to IDLE.  *  *  * Writing only one dummy transaction can get appended to  * one file space allocation. When this happens, the log recovery  * code replays the space allocation and a file could be truncated.  * This is why we have the NEED2 and DONE2 states before going idle.  */
end_comment

begin_define
define|#
directive|define
name|XLOG_STATE_COVER_IDLE
value|0
end_define

begin_define
define|#
directive|define
name|XLOG_STATE_COVER_NEED
value|1
end_define

begin_define
define|#
directive|define
name|XLOG_STATE_COVER_DONE
value|2
end_define

begin_define
define|#
directive|define
name|XLOG_STATE_COVER_NEED2
value|3
end_define

begin_define
define|#
directive|define
name|XLOG_STATE_COVER_DONE2
value|4
end_define

begin_define
define|#
directive|define
name|XLOG_COVER_OPS
value|5
end_define

begin_comment
comment|/* Ticket reservation region accounting */
end_comment

begin_define
define|#
directive|define
name|XLOG_TIC_LEN_MAX
value|15
end_define

begin_define
define|#
directive|define
name|XLOG_TIC_RESET_RES
parameter_list|(
name|t
parameter_list|)
value|((t)->t_res_num = \ 				(t)->t_res_arr_sum = (t)->t_res_num_ophdrs = 0)
end_define

begin_define
define|#
directive|define
name|XLOG_TIC_ADD_OPHDR
parameter_list|(
name|t
parameter_list|)
value|((t)->t_res_num_ophdrs++)
end_define

begin_define
define|#
directive|define
name|XLOG_TIC_ADD_REGION
parameter_list|(
name|t
parameter_list|,
name|len
parameter_list|,
name|type
parameter_list|)
define|\
value|do {								\ 		if ((t)->t_res_num == XLOG_TIC_LEN_MAX) { 		\
comment|/* add to overflow and start again */
value|\ 			(t)->t_res_o_flow += (t)->t_res_arr_sum;	\ 			(t)->t_res_num = 0;				\ 			(t)->t_res_arr_sum = 0;				\ 		}							\ 		(t)->t_res_arr[(t)->t_res_num].r_len = (len);		\ 		(t)->t_res_arr[(t)->t_res_num].r_type = (type);		\ 		(t)->t_res_arr_sum += (len);				\ 		(t)->t_res_num++;					\ 	} while (0)
end_define

begin_comment
comment|/*  * Reservation region  * As would be stored in xfs_log_iovec but without the i_addr which  * we don't care about.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xlog_res
block|{
name|uint
name|r_len
decl_stmt|;
comment|/* region length		:4 */
name|uint
name|r_type
decl_stmt|;
comment|/* region's transaction type	:4 */
block|}
name|xlog_res_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xlog_ticket
block|{
name|sv_t
name|t_sema
decl_stmt|;
comment|/* sleep on this semaphore      : 20 */
name|struct
name|xlog_ticket
modifier|*
name|t_next
decl_stmt|;
comment|/*			         :4|8 */
name|struct
name|xlog_ticket
modifier|*
name|t_prev
decl_stmt|;
comment|/*				 :4|8 */
name|xlog_tid_t
name|t_tid
decl_stmt|;
comment|/* transaction identifier	 : 4  */
name|int
name|t_curr_res
decl_stmt|;
comment|/* current reservation in bytes : 4  */
name|int
name|t_unit_res
decl_stmt|;
comment|/* unit reservation in bytes    : 4  */
name|char
name|t_ocnt
decl_stmt|;
comment|/* original count		 : 1  */
name|char
name|t_cnt
decl_stmt|;
comment|/* current count		 : 1  */
name|char
name|t_clientid
decl_stmt|;
comment|/* who does this belong to;	 : 1  */
name|char
name|t_flags
decl_stmt|;
comment|/* properties of reservation	 : 1  */
name|uint
name|t_trans_type
decl_stmt|;
comment|/* transaction type             : 4  */
comment|/* reservation array fields */
name|uint
name|t_res_num
decl_stmt|;
comment|/* num in array : 4 */
name|uint
name|t_res_num_ophdrs
decl_stmt|;
comment|/* num op hdrs  : 4 */
name|uint
name|t_res_arr_sum
decl_stmt|;
comment|/* array sum    : 4 */
name|uint
name|t_res_o_flow
decl_stmt|;
comment|/* sum overflow : 4 */
name|xlog_res_t
name|t_res_arr
index|[
name|XLOG_TIC_LEN_MAX
index|]
decl_stmt|;
comment|/* array of res : 8 * 15 */
block|}
name|xlog_ticket_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|xlog_op_header
block|{
name|xlog_tid_t
name|oh_tid
decl_stmt|;
comment|/* transaction id of operation	:  4 b */
name|int
name|oh_len
decl_stmt|;
comment|/* bytes in data region		:  4 b */
name|__uint8_t
name|oh_clientid
decl_stmt|;
comment|/* who sent me this		:  1 b */
name|__uint8_t
name|oh_flags
decl_stmt|;
comment|/*				:  1 b */
name|ushort
name|oh_res2
decl_stmt|;
comment|/* 32 bit align			:  2 b */
block|}
name|xlog_op_header_t
typedef|;
end_typedef

begin_comment
comment|/* valid values for h_fmt */
end_comment

begin_define
define|#
directive|define
name|XLOG_FMT_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|XLOG_FMT_LINUX_LE
value|1
end_define

begin_define
define|#
directive|define
name|XLOG_FMT_LINUX_BE
value|2
end_define

begin_define
define|#
directive|define
name|XLOG_FMT_IRIX_BE
value|3
end_define

begin_comment
comment|/* our fmt */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XFS_NATIVE_HOST
end_ifdef

begin_define
define|#
directive|define
name|XLOG_FMT
value|XLOG_FMT_LINUX_BE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XLOG_FMT
value|XLOG_FMT_LINUX_LE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|xlog_rec_header
block|{
name|uint
name|h_magicno
decl_stmt|;
comment|/* log record (LR) identifier		:  4 */
name|uint
name|h_cycle
decl_stmt|;
comment|/* write cycle of log			:  4 */
name|int
name|h_version
decl_stmt|;
comment|/* LR version				:  4 */
name|int
name|h_len
decl_stmt|;
comment|/* len in bytes; should be 64-bit aligned: 4 */
name|xfs_lsn_t
name|h_lsn
decl_stmt|;
comment|/* lsn of this LR			:  8 */
name|xfs_lsn_t
name|h_tail_lsn
decl_stmt|;
comment|/* lsn of 1st LR w/ buffers not committed: 8 */
name|uint
name|h_chksum
decl_stmt|;
comment|/* may not be used; non-zero if used	:  4 */
name|int
name|h_prev_block
decl_stmt|;
comment|/* block number to previous LR		:  4 */
name|int
name|h_num_logops
decl_stmt|;
comment|/* number of log operations in this LR	:  4 */
name|uint
name|h_cycle_data
index|[
name|XLOG_HEADER_CYCLE_SIZE
operator|/
name|BBSIZE
index|]
decl_stmt|;
comment|/* new fields */
name|int
name|h_fmt
decl_stmt|;
comment|/* format of log record                 :  4 */
name|uuid_t
name|h_fs_uuid
decl_stmt|;
comment|/* uuid of FS                           : 16 */
name|int
name|h_size
decl_stmt|;
comment|/* iclog size				:  4 */
block|}
name|xlog_rec_header_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xlog_rec_ext_header
block|{
name|uint
name|xh_cycle
decl_stmt|;
comment|/* write cycle of log			: 4 */
name|uint
name|xh_cycle_data
index|[
name|XLOG_HEADER_CYCLE_SIZE
operator|/
name|BBSIZE
index|]
decl_stmt|;
comment|/*	: 256 */
block|}
name|xlog_rec_ext_header_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_comment
comment|/*  * - A log record header is 512 bytes.  There is plenty of room to grow the  *	xlog_rec_header_t into the reserved space.  * - ic_data follows, so a write to disk can start at the beginning of  *	the iclog.  * - ic_forcesema is used to implement synchronous forcing of the iclog to disk.  * - ic_next is the pointer to the next iclog in the ring.  * - ic_bp is a pointer to the buffer used to write this incore log to disk.  * - ic_log is a pointer back to the global log structure.  * - ic_callback is a linked list of callback function/argument pairs to be  *	called after an iclog finishes writing.  * - ic_size is the full size of the header plus data.  * - ic_offset is the current number of bytes written to in this iclog.  * - ic_refcnt is bumped when someone is writing to the log.  * - ic_state is the state of the iclog.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xlog_iclog_fields
block|{
name|sv_t
name|ic_forcesema
decl_stmt|;
name|sv_t
name|ic_writesema
decl_stmt|;
name|struct
name|xlog_in_core
modifier|*
name|ic_next
decl_stmt|;
name|struct
name|xlog_in_core
modifier|*
name|ic_prev
decl_stmt|;
name|struct
name|xfs_buf
modifier|*
name|ic_bp
decl_stmt|;
name|struct
name|log
modifier|*
name|ic_log
decl_stmt|;
name|xfs_log_callback_t
modifier|*
name|ic_callback
decl_stmt|;
name|xfs_log_callback_t
modifier|*
modifier|*
name|ic_callback_tail
decl_stmt|;
ifdef|#
directive|ifdef
name|XFS_LOG_TRACE
name|struct
name|ktrace
modifier|*
name|ic_trace
decl_stmt|;
endif|#
directive|endif
name|int
name|ic_size
decl_stmt|;
name|int
name|ic_offset
decl_stmt|;
name|int
name|ic_refcnt
decl_stmt|;
name|int
name|ic_bwritecnt
decl_stmt|;
name|ushort_t
name|ic_state
decl_stmt|;
name|char
modifier|*
name|ic_datap
decl_stmt|;
comment|/* pointer to iclog data */
block|}
name|xlog_iclog_fields_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|xlog_in_core2
block|{
name|xlog_rec_header_t
name|hic_header
decl_stmt|;
name|xlog_rec_ext_header_t
name|hic_xheader
decl_stmt|;
name|char
name|hic_sector
index|[
name|XLOG_HEADER_SIZE
index|]
decl_stmt|;
block|}
name|xlog_in_core_2_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xlog_in_core
block|{
name|xlog_iclog_fields_t
name|hic_fields
decl_stmt|;
name|xlog_in_core_2_t
modifier|*
name|hic_data
decl_stmt|;
block|}
name|xlog_in_core_t
typedef|;
end_typedef

begin_comment
comment|/*  * Defines to save our code from this glop.  */
end_comment

begin_define
define|#
directive|define
name|ic_forcesema
value|hic_fields.ic_forcesema
end_define

begin_define
define|#
directive|define
name|ic_writesema
value|hic_fields.ic_writesema
end_define

begin_define
define|#
directive|define
name|ic_next
value|hic_fields.ic_next
end_define

begin_define
define|#
directive|define
name|ic_prev
value|hic_fields.ic_prev
end_define

begin_define
define|#
directive|define
name|ic_bp
value|hic_fields.ic_bp
end_define

begin_define
define|#
directive|define
name|ic_log
value|hic_fields.ic_log
end_define

begin_define
define|#
directive|define
name|ic_callback
value|hic_fields.ic_callback
end_define

begin_define
define|#
directive|define
name|ic_callback_tail
value|hic_fields.ic_callback_tail
end_define

begin_define
define|#
directive|define
name|ic_trace
value|hic_fields.ic_trace
end_define

begin_define
define|#
directive|define
name|ic_size
value|hic_fields.ic_size
end_define

begin_define
define|#
directive|define
name|ic_offset
value|hic_fields.ic_offset
end_define

begin_define
define|#
directive|define
name|ic_refcnt
value|hic_fields.ic_refcnt
end_define

begin_define
define|#
directive|define
name|ic_bwritecnt
value|hic_fields.ic_bwritecnt
end_define

begin_define
define|#
directive|define
name|ic_state
value|hic_fields.ic_state
end_define

begin_define
define|#
directive|define
name|ic_datap
value|hic_fields.ic_datap
end_define

begin_define
define|#
directive|define
name|ic_header
value|hic_data->hic_header
end_define

begin_comment
comment|/*  * The reservation head lsn is not made up of a cycle number and block number.  * Instead, it uses a cycle number and byte number.  Logs don't expect to  * overflow 31 bits worth of byte offset, so using a byte number will mean  * that round off problems won't occur when releasing partial reservations.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|log
block|{
comment|/* The following block of fields are changed while holding icloglock */
name|sema_t
name|l_flushsema
decl_stmt|;
comment|/* iclog flushing semaphore */
name|int
name|l_flushcnt
decl_stmt|;
comment|/* # of procs waiting on this 						 * sema */
name|int
name|l_ticket_cnt
decl_stmt|;
comment|/* free ticket count */
name|int
name|l_ticket_tcnt
decl_stmt|;
comment|/* total ticket count */
name|int
name|l_covered_state
decl_stmt|;
comment|/* state of "covering disk 						 * log entries" */
name|xlog_ticket_t
modifier|*
name|l_freelist
decl_stmt|;
comment|/* free list of tickets */
name|xlog_ticket_t
modifier|*
name|l_unmount_free
decl_stmt|;
comment|/* kmem_free these addresses */
name|xlog_ticket_t
modifier|*
name|l_tail
decl_stmt|;
comment|/* free list of tickets */
name|xlog_in_core_t
modifier|*
name|l_iclog
decl_stmt|;
comment|/* head log queue	*/
name|lock_t
name|l_icloglock
decl_stmt|;
comment|/* grab to change iclog state */
name|xfs_lsn_t
name|l_tail_lsn
decl_stmt|;
comment|/* lsn of 1st LR with unflushed 						 * buffers */
name|xfs_lsn_t
name|l_last_sync_lsn
decl_stmt|;
comment|/* lsn of last LR on disk */
name|struct
name|xfs_mount
modifier|*
name|l_mp
decl_stmt|;
comment|/* mount point */
name|struct
name|xfs_buf
modifier|*
name|l_xbuf
decl_stmt|;
comment|/* extra buffer for log 						 * wrapping */
name|struct
name|xfs_buftarg
modifier|*
name|l_targ
decl_stmt|;
comment|/* buftarg of log */
name|xfs_daddr_t
name|l_logBBstart
decl_stmt|;
comment|/* start block of log */
name|int
name|l_logsize
decl_stmt|;
comment|/* size of log in bytes */
name|int
name|l_logBBsize
decl_stmt|;
comment|/* size of log in BB chunks */
name|int
name|l_curr_cycle
decl_stmt|;
comment|/* Cycle number of log writes */
name|int
name|l_prev_cycle
decl_stmt|;
comment|/* Cycle number before last 						 * block increment */
name|int
name|l_curr_block
decl_stmt|;
comment|/* current logical log block */
name|int
name|l_prev_block
decl_stmt|;
comment|/* previous logical log block */
name|int
name|l_iclog_size
decl_stmt|;
comment|/* size of log in bytes */
name|int
name|l_iclog_size_log
decl_stmt|;
comment|/* log power size of log */
name|int
name|l_iclog_bufs
decl_stmt|;
comment|/* number of iclog buffers */
comment|/* The following field are used for debugging; need to hold icloglock */
name|char
modifier|*
name|l_iclog_bak
index|[
name|XLOG_MAX_ICLOGS
index|]
decl_stmt|;
comment|/* The following block of fields are changed while holding grant_lock */
name|lock_t
name|l_grant_lock
decl_stmt|;
name|xlog_ticket_t
modifier|*
name|l_reserve_headq
decl_stmt|;
name|xlog_ticket_t
modifier|*
name|l_write_headq
decl_stmt|;
name|int
name|l_grant_reserve_cycle
decl_stmt|;
name|int
name|l_grant_reserve_bytes
decl_stmt|;
name|int
name|l_grant_write_cycle
decl_stmt|;
name|int
name|l_grant_write_bytes
decl_stmt|;
comment|/* The following fields don't need locking */
ifdef|#
directive|ifdef
name|XFS_LOG_TRACE
name|struct
name|ktrace
modifier|*
name|l_trace
decl_stmt|;
name|struct
name|ktrace
modifier|*
name|l_grant_trace
decl_stmt|;
endif|#
directive|endif
name|uint
name|l_flags
decl_stmt|;
name|uint
name|l_quotaoffs_flag
decl_stmt|;
comment|/* XFS_DQ_*, for QUOTAOFFs */
name|struct
name|xfs_buf_cancel
modifier|*
modifier|*
name|l_buf_cancel_table
decl_stmt|;
name|int
name|l_iclog_hsize
decl_stmt|;
comment|/* size of iclog header */
name|int
name|l_iclog_heads
decl_stmt|;
comment|/* # of iclog header sectors */
name|uint
name|l_sectbb_log
decl_stmt|;
comment|/* log2 of sector size in BBs */
name|uint
name|l_sectbb_mask
decl_stmt|;
comment|/* sector size (in BBs) 						 * alignment mask */
block|}
name|xlog_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XLOG_FORCED_SHUTDOWN
parameter_list|(
name|log
parameter_list|)
value|((log)->l_flags& XLOG_IO_ERROR)
end_define

begin_comment
comment|/* common routines */
end_comment

begin_function_decl
specifier|extern
name|xfs_lsn_t
name|xlog_assign_tail_lsn
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xlog_find_tail
parameter_list|(
name|xlog_t
modifier|*
name|log
parameter_list|,
name|xfs_daddr_t
modifier|*
name|head_blk
parameter_list|,
name|xfs_daddr_t
modifier|*
name|tail_blk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xlog_recover
parameter_list|(
name|xlog_t
modifier|*
name|log
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xlog_recover_finish
parameter_list|(
name|xlog_t
modifier|*
name|log
parameter_list|,
name|int
name|mfsi_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xlog_pack_data
parameter_list|(
name|xlog_t
modifier|*
name|log
parameter_list|,
name|xlog_in_core_t
modifier|*
name|iclog
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xlog_recover_process_iunlinks
parameter_list|(
name|xlog_t
modifier|*
name|log
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|xfs_buf
modifier|*
name|xlog_get_bp
parameter_list|(
name|xlog_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xlog_put_bp
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
name|xlog_bread
parameter_list|(
name|xlog_t
modifier|*
parameter_list|,
name|xfs_daddr_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|xfs_buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* iclog tracing */
end_comment

begin_define
define|#
directive|define
name|XLOG_TRACE_GRAB_FLUSH
value|1
end_define

begin_define
define|#
directive|define
name|XLOG_TRACE_REL_FLUSH
value|2
end_define

begin_define
define|#
directive|define
name|XLOG_TRACE_SLEEP_FLUSH
value|3
end_define

begin_define
define|#
directive|define
name|XLOG_TRACE_WAKE_FLUSH
value|4
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

begin_comment
comment|/* __XFS_LOG_PRIV_H__ */
end_comment

end_unit

