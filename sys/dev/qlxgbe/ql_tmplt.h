begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013-2014 Qlogic Corporation  * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * File: ql_tmplt.h  * Author : David C Somayajulu, Qlogic Corporation, Aliso Viejo, CA 92656.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_QL_TMPLT_H_
end_ifndef

begin_define
define|#
directive|define
name|_QL_TMPLT_H_
end_define

begin_typedef
typedef|typedef
struct|struct
name|_q8_tmplt_hdr
block|{
name|uint16_t
name|version
decl_stmt|;
name|uint16_t
name|signature
decl_stmt|;
name|uint16_t
name|size
decl_stmt|;
name|uint16_t
name|nentries
decl_stmt|;
name|uint16_t
name|stop_seq_off
decl_stmt|;
name|uint16_t
name|csum
decl_stmt|;
name|uint16_t
name|init_seq_off
decl_stmt|;
name|uint16_t
name|start_seq_off
decl_stmt|;
block|}
name|__packed
name|q8_tmplt_hdr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q8_ce_hdr
block|{
name|uint16_t
name|opcode
decl_stmt|;
name|uint16_t
name|size
decl_stmt|;
name|uint16_t
name|opcount
decl_stmt|;
name|uint16_t
name|delay_to
decl_stmt|;
block|}
name|__packed
name|q8_ce_hdr_t
typedef|;
end_typedef

begin_comment
comment|/*  * Values for opcode field in q8_ce_hdr_t  */
end_comment

begin_define
define|#
directive|define
name|Q8_CE_OPCODE_NOP
value|0x000
end_define

begin_define
define|#
directive|define
name|Q8_CE_OPCODE_WRITE_LIST
value|0x001
end_define

begin_define
define|#
directive|define
name|Q8_CE_OPCODE_READ_WRITE_LIST
value|0x002
end_define

begin_define
define|#
directive|define
name|Q8_CE_OPCODE_POLL_LIST
value|0x004
end_define

begin_define
define|#
directive|define
name|Q8_CE_OPCODE_POLL_WRITE_LIST
value|0x008
end_define

begin_define
define|#
directive|define
name|Q8_CE_OPCODE_READ_MODIFY_WRITE
value|0x010
end_define

begin_define
define|#
directive|define
name|Q8_CE_OPCODE_SEQ_PAUSE
value|0x020
end_define

begin_define
define|#
directive|define
name|Q8_CE_OPCODE_SEQ_END
value|0x040
end_define

begin_define
define|#
directive|define
name|Q8_CE_OPCODE_TMPLT_END
value|0x080
end_define

begin_define
define|#
directive|define
name|Q8_CE_OPCODE_POLL_RD_LIST
value|0x100
end_define

begin_comment
comment|/*  * structure for Q8_CE_OPCODE_WRITE_LIST  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q8_wrl_e
block|{
name|uint32_t
name|addr
decl_stmt|;
name|uint32_t
name|value
decl_stmt|;
block|}
name|__packed
name|q8_wrl_e_t
typedef|;
end_typedef

begin_comment
comment|/*  * structure for Q8_CE_OPCODE_READ_WRITE_LIST  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q8_rdwrl_e
block|{
name|uint32_t
name|rd_addr
decl_stmt|;
name|uint32_t
name|wr_addr
decl_stmt|;
block|}
name|__packed
name|q8_rdwrl_e_t
typedef|;
end_typedef

begin_comment
comment|/*  * common for  *	Q8_CE_OPCODE_POLL_LIST  *	Q8_CE_OPCODE_POLL_WRITE_LIST  *	Q8_CE_OPCODE_POLL_RD_LIST  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q8_poll_hdr
block|{
name|uint32_t
name|tmask
decl_stmt|;
name|uint32_t
name|tvalue
decl_stmt|;
block|}
name|q8_poll_hdr_t
typedef|;
end_typedef

begin_comment
comment|/*  * structure for Q8_CE_OPCODE_POLL_LIST  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q8_poll_e
block|{
name|uint32_t
name|addr
decl_stmt|;
name|uint32_t
name|to_addr
decl_stmt|;
block|}
name|q8_poll_e_t
typedef|;
end_typedef

begin_comment
comment|/*  * structure for Q8_CE_OPCODE_POLL_WRITE_LIST  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q8_poll_wr_e
block|{
name|uint32_t
name|dr_addr
decl_stmt|;
name|uint32_t
name|dr_value
decl_stmt|;
name|uint32_t
name|ar_addr
decl_stmt|;
name|uint32_t
name|ar_value
decl_stmt|;
block|}
name|q8_poll_wr_e_t
typedef|;
end_typedef

begin_comment
comment|/*  * structure for Q8_CE_OPCODE_POLL_RD_LIST  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q8_poll_rd_e
block|{
name|uint32_t
name|ar_addr
decl_stmt|;
name|uint32_t
name|ar_value
decl_stmt|;
name|uint32_t
name|dr_addr
decl_stmt|;
name|uint32_t
name|rsrvd
decl_stmt|;
block|}
name|q8_poll_rd_e_t
typedef|;
end_typedef

begin_comment
comment|/*  * structure for Q8_CE_OPCODE_READ_MODIFY_WRITE  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q8_rdmwr_hdr
block|{
name|uint32_t
name|and_value
decl_stmt|;
name|uint32_t
name|xor_value
decl_stmt|;
name|uint32_t
name|or_value
decl_stmt|;
name|uint8_t
name|shl
decl_stmt|;
name|uint8_t
name|shr
decl_stmt|;
name|uint8_t
name|index_a
decl_stmt|;
name|uint8_t
name|rsrvd
decl_stmt|;
block|}
name|q8_rdmwr_hdr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q8_rdmwr_e
block|{
name|uint32_t
name|rd_addr
decl_stmt|;
name|uint32_t
name|wr_addr
decl_stmt|;
block|}
name|q8_rdmwr_e_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|ql83xx_resetseq
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|ql83xx_resetseq_len
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef _QL_TMPLT_H_ */
end_comment

end_unit

