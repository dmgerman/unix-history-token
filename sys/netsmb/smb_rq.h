begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001, Boris Popov  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    This product includes software developed by Boris Popov.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETSMB_SMB_RQ_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETSMB_SMB_RQ_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MB_MSYSTEM
end_ifndef

begin_include
include|#
directive|include
file|<sys/mchain.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SMBR_ALLOCED
value|0x0001
end_define

begin_comment
comment|/* structure was malloced */
end_comment

begin_define
define|#
directive|define
name|SMBR_SENT
value|0x0002
end_define

begin_comment
comment|/* request successfully transmitted */
end_comment

begin_define
define|#
directive|define
name|SMBR_REXMIT
value|0x0004
end_define

begin_comment
comment|/* request should be retransmitted */
end_comment

begin_define
define|#
directive|define
name|SMBR_INTR
value|0x0008
end_define

begin_comment
comment|/* request interrupted */
end_comment

begin_define
define|#
directive|define
name|SMBR_RESTART
value|0x0010
end_define

begin_comment
comment|/* request should be repeated if possible */
end_comment

begin_define
define|#
directive|define
name|SMBR_NORESTART
value|0x0020
end_define

begin_comment
comment|/* request is not restartable */
end_comment

begin_define
define|#
directive|define
name|SMBR_MULTIPACKET
value|0x0040
end_define

begin_comment
comment|/* multiple packets can be sent and received */
end_comment

begin_define
define|#
directive|define
name|SMBR_INTERNAL
value|0x0080
end_define

begin_comment
comment|/* request is internal to smbrqd */
end_comment

begin_define
define|#
directive|define
name|SMBR_XLOCK
value|0x0100
end_define

begin_comment
comment|/* request locked and can't be moved */
end_comment

begin_define
define|#
directive|define
name|SMBR_XLOCKWANT
value|0x0200
end_define

begin_comment
comment|/* waiter on XLOCK */
end_comment

begin_define
define|#
directive|define
name|SMBT2_ALLSENT
value|0x0001
end_define

begin_comment
comment|/* all data and params are sent */
end_comment

begin_define
define|#
directive|define
name|SMBT2_ALLRECV
value|0x0002
end_define

begin_comment
comment|/* all data and params are received */
end_comment

begin_define
define|#
directive|define
name|SMBT2_ALLOCED
value|0x0004
end_define

begin_define
define|#
directive|define
name|SMBT2_RESTART
value|0x0008
end_define

begin_define
define|#
directive|define
name|SMBT2_NORESTART
value|0x0010
end_define

begin_define
define|#
directive|define
name|SMBRQ_SLOCK
parameter_list|(
name|rqp
parameter_list|)
value|smb_sl_lock(&(rqp)->sr_slock)
end_define

begin_define
define|#
directive|define
name|SMBRQ_SUNLOCK
parameter_list|(
name|rqp
parameter_list|)
value|smb_sl_unlock(&(rqp)->sr_slock)
end_define

begin_define
define|#
directive|define
name|SMBRQ_SLOCKPTR
parameter_list|(
name|rqp
parameter_list|)
value|(&(rqp)->sr_slock)
end_define

begin_enum
enum|enum
name|smbrq_state
block|{
name|SMBRQ_NOTSENT
block|,
comment|/* rq have data to send */
name|SMBRQ_SENT
block|,
comment|/* send procedure completed */
name|SMBRQ_REPLYRECEIVED
block|,
name|SMBRQ_NOTIFIED
comment|/* owner notified about completion */
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|smb_vc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|smb_t2rq
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|smb_rq
block|{
name|enum
name|smbrq_state
name|sr_state
decl_stmt|;
name|struct
name|smb_vc
modifier|*
name|sr_vc
decl_stmt|;
name|struct
name|smb_share
modifier|*
name|sr_share
decl_stmt|;
name|u_short
name|sr_mid
decl_stmt|;
name|struct
name|mbchain
name|sr_rq
decl_stmt|;
name|u_int8_t
name|sr_rqflags
decl_stmt|;
name|u_int16_t
name|sr_rqflags2
decl_stmt|;
name|u_char
modifier|*
name|sr_wcount
decl_stmt|;
name|u_short
modifier|*
name|sr_bcount
decl_stmt|;
name|struct
name|mdchain
name|sr_rp
decl_stmt|;
name|int
name|sr_rpgen
decl_stmt|;
name|int
name|sr_rplast
decl_stmt|;
name|int
name|sr_flags
decl_stmt|;
comment|/* SMBR_* */
name|int
name|sr_rpsize
decl_stmt|;
name|struct
name|smb_cred
modifier|*
name|sr_cred
decl_stmt|;
name|int
name|sr_timo
decl_stmt|;
name|int
name|sr_rexmit
decl_stmt|;
name|int
name|sr_sendcnt
decl_stmt|;
name|struct
name|timespec
name|sr_timesent
decl_stmt|;
name|int
name|sr_lerror
decl_stmt|;
name|u_int16_t
modifier|*
name|sr_rqtid
decl_stmt|;
name|u_int16_t
modifier|*
name|sr_rquid
decl_stmt|;
name|u_int8_t
name|sr_errclass
decl_stmt|;
name|u_int16_t
name|sr_serror
decl_stmt|;
name|u_int32_t
name|sr_error
decl_stmt|;
name|u_int8_t
name|sr_rpflags
decl_stmt|;
name|u_int16_t
name|sr_rpflags2
decl_stmt|;
name|u_int16_t
name|sr_rptid
decl_stmt|;
name|u_int16_t
name|sr_rppid
decl_stmt|;
name|u_int16_t
name|sr_rpuid
decl_stmt|;
name|u_int16_t
name|sr_rpmid
decl_stmt|;
name|struct
name|smb_slock
name|sr_slock
decl_stmt|;
comment|/* short term locks */
comment|/*	struct smb_t2rq*sr_t2;*/
name|TAILQ_ENTRY
argument_list|(
argument|smb_rq
argument_list|)
name|sr_link
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|smb_t2rq
block|{
name|u_int16_t
name|t2_setupcount
decl_stmt|;
name|u_int16_t
modifier|*
name|t2_setupdata
decl_stmt|;
name|u_int16_t
name|t2_setup
index|[
literal|2
index|]
decl_stmt|;
comment|/* most of rqs has setupcount of 1 */
name|u_int8_t
name|t2_maxscount
decl_stmt|;
comment|/* max setup words to return */
name|u_int16_t
name|t2_maxpcount
decl_stmt|;
comment|/* max param bytes to return */
name|u_int16_t
name|t2_maxdcount
decl_stmt|;
comment|/* max data bytes to return */
name|u_int16_t
name|t2_fid
decl_stmt|;
comment|/* for T2 request */
name|char
modifier|*
name|t_name
decl_stmt|;
comment|/* for T request, should be zero for T2 */
name|int
name|t2_flags
decl_stmt|;
comment|/* SMBT2_ */
name|struct
name|mbchain
name|t2_tparam
decl_stmt|;
comment|/* parameters to transmit */
name|struct
name|mbchain
name|t2_tdata
decl_stmt|;
comment|/* data to transmit */
name|struct
name|mdchain
name|t2_rparam
decl_stmt|;
comment|/* received paramters */
name|struct
name|mdchain
name|t2_rdata
decl_stmt|;
comment|/* received data */
name|struct
name|smb_cred
modifier|*
name|t2_cred
decl_stmt|;
name|struct
name|smb_connobj
modifier|*
name|t2_source
decl_stmt|;
name|struct
name|smb_rq
modifier|*
name|t2_rq
decl_stmt|;
name|struct
name|smb_vc
modifier|*
name|t2_vc
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|smb_rq_alloc
parameter_list|(
name|struct
name|smb_connobj
modifier|*
name|layer
parameter_list|,
name|u_char
name|cmd
parameter_list|,
name|struct
name|smb_cred
modifier|*
name|scred
parameter_list|,
name|struct
name|smb_rq
modifier|*
modifier|*
name|rqpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_rq_init
parameter_list|(
name|struct
name|smb_rq
modifier|*
name|rqp
parameter_list|,
name|struct
name|smb_connobj
modifier|*
name|layer
parameter_list|,
name|u_char
name|cmd
parameter_list|,
name|struct
name|smb_cred
modifier|*
name|scred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smb_rq_done
parameter_list|(
name|struct
name|smb_rq
modifier|*
name|rqp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_rq_getrequest
parameter_list|(
name|struct
name|smb_rq
modifier|*
name|rqp
parameter_list|,
name|struct
name|mbchain
modifier|*
modifier|*
name|mbpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_rq_getreply
parameter_list|(
name|struct
name|smb_rq
modifier|*
name|rqp
parameter_list|,
name|struct
name|mdchain
modifier|*
modifier|*
name|mbpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smb_rq_wstart
parameter_list|(
name|struct
name|smb_rq
modifier|*
name|rqp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smb_rq_wend
parameter_list|(
name|struct
name|smb_rq
modifier|*
name|rqp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smb_rq_bstart
parameter_list|(
name|struct
name|smb_rq
modifier|*
name|rqp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smb_rq_bend
parameter_list|(
name|struct
name|smb_rq
modifier|*
name|rqp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_rq_intr
parameter_list|(
name|struct
name|smb_rq
modifier|*
name|rqp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_rq_simple
parameter_list|(
name|struct
name|smb_rq
modifier|*
name|rqp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_t2_alloc
parameter_list|(
name|struct
name|smb_connobj
modifier|*
name|layer
parameter_list|,
name|u_short
name|setup
parameter_list|,
name|struct
name|smb_cred
modifier|*
name|scred
parameter_list|,
name|struct
name|smb_t2rq
modifier|*
modifier|*
name|rqpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_t2_init
parameter_list|(
name|struct
name|smb_t2rq
modifier|*
name|rqp
parameter_list|,
name|struct
name|smb_connobj
modifier|*
name|layer
parameter_list|,
name|u_short
name|setup
parameter_list|,
name|struct
name|smb_cred
modifier|*
name|scred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smb_t2_done
parameter_list|(
name|struct
name|smb_t2rq
modifier|*
name|t2p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_t2_request
parameter_list|(
name|struct
name|smb_t2rq
modifier|*
name|t2p
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETSMB_SMB_RQ_H_ */
end_comment

end_unit

