begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Hidetoshi Shimokawa  * Copyright (c) 1998-2002 Katsushi Kobayashi and Hidetoshi Shimokawa  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the acknowledgement as bellow:  *  *    This product includes software developed by K. Kobayashi and H. Shimokawa  *  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *   * $FreeBSD$  *  */
end_comment

begin_define
define|#
directive|define
name|ORB_NOTIFY
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|ORB_FMT_STD
value|(0<< 29)
end_define

begin_define
define|#
directive|define
name|ORB_FMT_VED
value|(2<< 29)
end_define

begin_define
define|#
directive|define
name|ORB_FMT_NOP
value|(3<< 29)
end_define

begin_define
define|#
directive|define
name|ORB_FMT_MSK
value|(3<< 29)
end_define

begin_define
define|#
directive|define
name|ORB_EXV
value|(1<< 28)
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|ORB_CMD_IN
value|(1<< 27)
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|ORB_CMD_SPD
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
end_define

begin_define
define|#
directive|define
name|ORB_CMD_MAXP
parameter_list|(
name|x
parameter_list|)
value|((x)<< 20)
end_define

begin_define
define|#
directive|define
name|ORB_RCN_TMO
parameter_list|(
name|x
parameter_list|)
value|((x)<< 20)
end_define

begin_define
define|#
directive|define
name|ORB_CMD_PTBL
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|ORB_CMD_PSZ
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|ORB_FUN_LGI
value|(0<< 16)
end_define

begin_define
define|#
directive|define
name|ORB_FUN_QLG
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|ORB_FUN_RCN
value|(3<< 16)
end_define

begin_define
define|#
directive|define
name|ORB_FUN_LGO
value|(7<< 16)
end_define

begin_define
define|#
directive|define
name|ORB_FUN_ATA
value|(0xb<< 16)
end_define

begin_define
define|#
directive|define
name|ORB_FUN_ATS
value|(0xc<< 16)
end_define

begin_define
define|#
directive|define
name|ORB_FUN_LUR
value|(0xe<< 16)
end_define

begin_define
define|#
directive|define
name|ORB_FUN_RST
value|(0xf<< 16)
end_define

begin_define
define|#
directive|define
name|ORB_FUN_MSK
value|(0xf<< 16)
end_define

begin_define
define|#
directive|define
name|ORB_FUN_RUNQUEUE
value|0xffff
end_define

begin_define
define|#
directive|define
name|ORB_RES_CMPL
value|0
end_define

begin_define
define|#
directive|define
name|ORB_RES_FAIL
value|1
end_define

begin_define
define|#
directive|define
name|ORB_RES_ILLE
value|2
end_define

begin_define
define|#
directive|define
name|ORB_RES_VEND
value|3
end_define

begin_define
define|#
directive|define
name|SBP_DEBUG
parameter_list|(
name|x
parameter_list|)
value|if (debug> x) {
end_define

begin_define
define|#
directive|define
name|END_DEBUG
value|}
end_define

begin_struct
struct|struct
name|ind_ptr
block|{
name|uint32_t
name|hi
decl_stmt|,
name|lo
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SBP_RECV_LEN
value|32
end_define

begin_struct
struct|struct
name|sbp_login_res
block|{
name|uint16_t
name|len
decl_stmt|;
name|uint16_t
name|id
decl_stmt|;
name|uint16_t
name|res0
decl_stmt|;
name|uint16_t
name|cmd_hi
decl_stmt|;
name|uint32_t
name|cmd_lo
decl_stmt|;
name|uint16_t
name|res1
decl_stmt|;
name|uint16_t
name|recon_hold
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sbp_status
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|uint8_t
name|src
range|:
literal|2
decl_stmt|,
name|resp
range|:
literal|2
decl_stmt|,
name|dead
range|:
literal|1
decl_stmt|,
name|len
range|:
literal|3
decl_stmt|;
else|#
directive|else
name|uint8_t
name|len
range|:
literal|3
decl_stmt|,
name|dead
range|:
literal|1
decl_stmt|,
name|resp
range|:
literal|2
decl_stmt|,
name|src
range|:
literal|2
decl_stmt|;
endif|#
directive|endif
name|uint8_t
name|status
decl_stmt|;
name|uint16_t
name|orb_hi
decl_stmt|;
name|uint32_t
name|orb_lo
decl_stmt|;
name|uint32_t
name|data
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* src */
end_comment

begin_define
define|#
directive|define
name|SRC_NEXT_EXISTS
value|0
end_define

begin_define
define|#
directive|define
name|SRC_NO_NEXT
value|1
end_define

begin_define
define|#
directive|define
name|SRC_UNSOL
value|2
end_define

begin_comment
comment|/* resp */
end_comment

begin_define
define|#
directive|define
name|SBP_REQ_CMP
value|0
end_define

begin_comment
comment|/* request complete */
end_comment

begin_define
define|#
directive|define
name|SBP_TRANS_FAIL
value|1
end_define

begin_comment
comment|/* transport failure */
end_comment

begin_define
define|#
directive|define
name|SBP_ILLE_REQ
value|2
end_define

begin_comment
comment|/* illegal request */
end_comment

begin_define
define|#
directive|define
name|SBP_VEND_DEP
value|3
end_define

begin_comment
comment|/* vendor dependent */
end_comment

begin_comment
comment|/* status (resp == 0) */
end_comment

begin_comment
comment|/*   0: No additional Information to report */
end_comment

begin_comment
comment|/*   1: Request Type not supported */
end_comment

begin_comment
comment|/*   2: Speed not supported */
end_comment

begin_comment
comment|/*   3: Page size not supported */
end_comment

begin_comment
comment|/*   4: Access denied */
end_comment

begin_define
define|#
directive|define
name|STATUS_ACCESS_DENY
value|4
end_define

begin_define
define|#
directive|define
name|STATUS_LUR
value|5
end_define

begin_comment
comment|/*   6: Maximum payload too small */
end_comment

begin_comment
comment|/*   7: Reserved for future standardization */
end_comment

begin_comment
comment|/*   8: Resource unavailabe */
end_comment

begin_define
define|#
directive|define
name|STATUS_RES_UNAVAIL
value|8
end_define

begin_comment
comment|/*   9: Function Rejected */
end_comment

begin_comment
comment|/*  10: Login ID not recognized */
end_comment

begin_comment
comment|/*  11: Dummy ORB completed */
end_comment

begin_comment
comment|/*  12: Request aborted */
end_comment

begin_comment
comment|/* 255: Unspecified error */
end_comment

begin_comment
comment|/* status (resp == 1) */
end_comment

begin_comment
comment|/* Referenced object */
end_comment

begin_define
define|#
directive|define
name|OBJ_ORB
value|(0<< 6)
end_define

begin_comment
comment|/* 0: ORB */
end_comment

begin_define
define|#
directive|define
name|OBJ_DATA
value|(1<< 6)
end_define

begin_comment
comment|/* 1: Data buffer */
end_comment

begin_define
define|#
directive|define
name|OBJ_PT
value|(2<< 6)
end_define

begin_comment
comment|/* 2: Page table */
end_comment

begin_define
define|#
directive|define
name|OBJ_UNSPEC
value|(3<< 6)
end_define

begin_comment
comment|/* 3: Unable to specify */
end_comment

begin_comment
comment|/* Serial bus error */
end_comment

begin_comment
comment|/* 0: Missing acknowledge */
end_comment

begin_comment
comment|/* 1: Reserved; not to be used */
end_comment

begin_comment
comment|/* 2: Time-out error */
end_comment

begin_define
define|#
directive|define
name|SBE_TIMEOUT
value|2
end_define

begin_comment
comment|/* 3: Reserved; not to be used */
end_comment

begin_comment
comment|/* 4: Busy retry limit exceeded: ack_busy_X */
end_comment

begin_comment
comment|/* 5: Busy retry limit exceeded: ack_busy_A */
end_comment

begin_comment
comment|/* 6: Busy retry limit exceeded: ack_busy_B */
end_comment

begin_comment
comment|/* 7-A: Reserved for future standardization */
end_comment

begin_comment
comment|/* B: Tardy retry limit exceeded */
end_comment

begin_comment
comment|/* C: Confilict error */
end_comment

begin_comment
comment|/* D: Data error */
end_comment

begin_comment
comment|/* E: Type error */
end_comment

begin_comment
comment|/* F: Address error */
end_comment

begin_struct
struct|struct
name|sbp_cmd_status
block|{
define|#
directive|define
name|SBP_SFMT_CURR
value|0
define|#
directive|define
name|SBP_SFMT_DEFER
value|1
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|uint8_t
name|sfmt
range|:
literal|2
decl_stmt|,
name|status
range|:
literal|6
decl_stmt|;
name|uint8_t
name|valid
range|:
literal|1
decl_stmt|,
name|mark
range|:
literal|1
decl_stmt|,
name|eom
range|:
literal|1
decl_stmt|,
name|ill_len
range|:
literal|1
decl_stmt|,
name|s_key
range|:
literal|4
decl_stmt|;
else|#
directive|else
name|uint8_t
name|status
range|:
literal|6
decl_stmt|,
name|sfmt
range|:
literal|2
decl_stmt|;
name|uint8_t
name|s_key
range|:
literal|4
decl_stmt|,
name|ill_len
range|:
literal|1
decl_stmt|,
name|eom
range|:
literal|1
decl_stmt|,
name|mark
range|:
literal|1
decl_stmt|,
name|valid
range|:
literal|1
decl_stmt|;
endif|#
directive|endif
name|uint8_t
name|s_code
decl_stmt|;
name|uint8_t
name|s_qlfr
decl_stmt|;
name|uint32_t
name|info
decl_stmt|;
name|uint32_t
name|cdb
decl_stmt|;
name|uint8_t
name|fru
decl_stmt|;
name|uint8_t
name|s_keydep
index|[
literal|3
index|]
decl_stmt|;
name|uint32_t
name|vend
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ORB_FUN_NAMES
define|\
comment|/* 0 */
value|"LOGIN", \
comment|/* 1 */
value|"QUERY LOGINS", \
comment|/* 2 */
value|"Reserved", \
comment|/* 3 */
value|"RECONNECT", \
comment|/* 4 */
value|"SET PASSWORD", \
comment|/* 5 */
value|"Reserved", \
comment|/* 6 */
value|"Reserved", \
comment|/* 7 */
value|"LOGOUT", \
comment|/* 8 */
value|"Reserved", \
comment|/* 9 */
value|"Reserved", \
comment|/* A */
value|"Reserved", \
comment|/* B */
value|"ABORT TASK", \
comment|/* C */
value|"ABORT TASK SET", \
comment|/* D */
value|"Reserved", \
comment|/* E */
value|"LOGICAL UNIT RESET", \
comment|/* F */
value|"TARGET RESET"
end_define

end_unit

