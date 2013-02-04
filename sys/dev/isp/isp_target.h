begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  *  Copyright (c) 1997-2009 by Matthew Jacob  *  All rights reserved.  *   *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *   *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *   *  THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  *  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  *  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  *  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  *  OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  *  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  *  OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  *  SUCH DAMAGE.  *   */
end_comment

begin_comment
comment|/*  * Qlogic Target Mode Structure and Flag Definitions  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ISP_TARGET_H
end_ifndef

begin_define
define|#
directive|define
name|_ISP_TARGET_H
end_define

begin_comment
comment|/*  * Notify structure- these are for asynchronous events that need to be sent  * as notifications to the outer layer. It should be pretty self-explanatory.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|NT_UNKNOWN
init|=
literal|0x999
block|,
name|NT_ABORT_TASK
init|=
literal|0x1000
block|,
name|NT_ABORT_TASK_SET
block|,
name|NT_CLEAR_ACA
block|,
name|NT_CLEAR_TASK_SET
block|,
name|NT_LUN_RESET
block|,
name|NT_TARGET_RESET
block|,
name|NT_BUS_RESET
block|,
name|NT_LIP_RESET
block|,
name|NT_LINK_UP
block|,
name|NT_LINK_DOWN
block|,
name|NT_LOGOUT
block|,
name|NT_GLOBAL_LOGOUT
block|,
name|NT_CHANGED
block|,
name|NT_ARRIVED
block|,
name|NT_DEPARTED
block|,
name|NT_HBA_RESET
block|}
name|isp_ncode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|isp_notify
block|{
name|void
modifier|*
name|nt_hba
decl_stmt|;
comment|/* HBA tag */
name|void
modifier|*
name|nt_tmd
decl_stmt|;
name|void
modifier|*
name|nt_lreserved
decl_stmt|;
name|void
modifier|*
name|nt_hreserved
decl_stmt|;
name|uint64_t
name|nt_wwn
decl_stmt|;
comment|/* source (wwn) */
name|uint64_t
name|nt_tgt
decl_stmt|;
comment|/* destination (wwn) */
name|uint64_t
name|nt_tagval
decl_stmt|;
comment|/* tag value */
name|uint32_t
name|nt_sid
range|:
literal|24
decl_stmt|;
comment|/* source port id */
name|uint32_t
name|nt_failed
range|:
literal|1
decl_stmt|,
comment|/* notify operation failed */
name|nt_need_ack
range|:
literal|1
decl_stmt|,
comment|/* this notify needs an ACK */
name|nt_did
range|:
literal|24
decl_stmt|;
comment|/* destination port id */
name|uint32_t
name|nt_lun
range|:
literal|16
decl_stmt|,
comment|/* logical unit */
name|nt_nphdl
range|:
literal|16
decl_stmt|;
comment|/* n-port handle */
name|uint8_t
name|nt_channel
decl_stmt|;
comment|/* channel id */
name|isp_ncode_t
name|nt_ncode
decl_stmt|;
comment|/* action */
block|}
name|isp_notify_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MATCH_TMD
parameter_list|(
name|tmd
parameter_list|,
name|iid
parameter_list|,
name|lun
parameter_list|,
name|tag
parameter_list|)
define|\
value|(                                                   \         (tmd)&&                                        \         (iid == INI_ANY || iid == tmd->cd_iid)&&       \         (lun == LUN_ANY || lun == tmd->cd_lun)&&       \         (tag == TAG_ANY || tag == tmd->cd_tagval)       \     )
end_define

begin_comment
comment|/*  * Debug macros  */
end_comment

begin_define
define|#
directive|define
name|ISP_TDQE
parameter_list|(
name|isp
parameter_list|,
name|msg
parameter_list|,
name|idx
parameter_list|,
name|arg
parameter_list|)
define|\
value|if (isp->isp_dblev& ISP_LOGTDEBUG2) isp_print_qentry(isp, msg, idx, arg)
end_define

begin_comment
comment|/*  * Special Constatns  */
end_comment

begin_define
define|#
directive|define
name|INI_ANY
value|((uint64_t) -1)
end_define

begin_define
define|#
directive|define
name|VALID_INI
parameter_list|(
name|ini
parameter_list|)
value|(ini != INI_NONE&& ini != INI_ANY)
end_define

begin_define
define|#
directive|define
name|LUN_ANY
value|0xffff
end_define

begin_define
define|#
directive|define
name|TGT_ANY
value|((uint64_t) -1)
end_define

begin_define
define|#
directive|define
name|TAG_ANY
value|((uint64_t) 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ISP_TARGET_H */
end_comment

end_unit

