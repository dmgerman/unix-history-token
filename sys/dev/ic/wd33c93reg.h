begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NecBSD: wd33c93reg.h,v 1.21.24.1 2001/06/13 05:52:05 honda Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD$	*/
end_comment

begin_comment
comment|/*  * [NetBSD for NEC PC-98 series]  *  Copyright (c) 1996, 1997, 1998  *	NetBSD/pc98 porting staff. All rights reserved.  *  Copyright (c) 1996, 1997, 1998  *	Naofumi Honda. All rights reserved.  *   *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  3. The name of the author may not be used to endorse or promote products  *     derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_WD33C93REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_WD33C93REG_H_
end_define

begin_comment
comment|/* wd33c93 register */
end_comment

begin_define
define|#
directive|define
name|wd3s_oid
value|0x00
end_define

begin_define
define|#
directive|define
name|IDR_FS_16_20
value|0x80
end_define

begin_define
define|#
directive|define
name|IDR_FS_12_15
value|0x40
end_define

begin_define
define|#
directive|define
name|IDR_FS_8_10
value|0x00
end_define

begin_define
define|#
directive|define
name|IDR_RAF
value|0x20
end_define

begin_define
define|#
directive|define
name|IDR_EHP
value|0x10
end_define

begin_define
define|#
directive|define
name|IDR_EAF
value|0x08
end_define

begin_define
define|#
directive|define
name|IDR_IDM
value|0x07
end_define

begin_define
define|#
directive|define
name|wd3s_ctrl
value|0x01
end_define

begin_define
define|#
directive|define
name|CR_DMA
value|0x80
end_define

begin_define
define|#
directive|define
name|CR_DMAD
value|0x40
end_define

begin_define
define|#
directive|define
name|CR_HLT_HOST_PARITY
value|0x10
end_define

begin_define
define|#
directive|define
name|CR_DIS_INT
value|0x08
end_define

begin_define
define|#
directive|define
name|CR_IDIS_INT
value|0x04
end_define

begin_define
define|#
directive|define
name|CR_HLT_ATN
value|0x02
end_define

begin_define
define|#
directive|define
name|CR_HLT_BUS_PARITY
value|0x01
end_define

begin_define
define|#
directive|define
name|CR_DEFAULT
value|(CR_DIS_INT | CR_IDIS_INT)
end_define

begin_define
define|#
directive|define
name|CR_DEFAULT_HP
value|(CR_DEFAULT | CR_HLT_BUS_PARITY)
end_define

begin_define
define|#
directive|define
name|wd3s_tout
value|0x02
end_define

begin_define
define|#
directive|define
name|wd3s_cdb
value|0x03
end_define

begin_define
define|#
directive|define
name|wd3s_lun
value|0x0f
end_define

begin_define
define|#
directive|define
name|wd3s_cph
value|0x10
end_define

begin_define
define|#
directive|define
name|wd3s_synch
value|0x11
end_define

begin_define
define|#
directive|define
name|wd3s_cnt
value|0x12
end_define

begin_define
define|#
directive|define
name|wd3s_did
value|0x15
end_define

begin_define
define|#
directive|define
name|DIDR_SCC
value|0x80
end_define

begin_define
define|#
directive|define
name|DIDR_DPD
value|0x40
end_define

begin_define
define|#
directive|define
name|wd3s_sid
value|0x16
end_define

begin_define
define|#
directive|define
name|SIDR_RESEL
value|0x80
end_define

begin_define
define|#
directive|define
name|SIDR_SEL
value|0x40
end_define

begin_define
define|#
directive|define
name|SIDR_VALID
value|0x08
end_define

begin_define
define|#
directive|define
name|SIDR_IDM
value|0x07
end_define

begin_define
define|#
directive|define
name|wd3s_stat
value|0x17
end_define

begin_define
define|#
directive|define
name|BSR_CM
value|0xf0
end_define

begin_define
define|#
directive|define
name|BSR_CMDCPL
value|0x10
end_define

begin_define
define|#
directive|define
name|BSR_CMDABT
value|0x20
end_define

begin_define
define|#
directive|define
name|BSR_CMDERR
value|0x40
end_define

begin_define
define|#
directive|define
name|BSR_CMDREQ
value|0x80
end_define

begin_define
define|#
directive|define
name|BSR_SM
value|0x0f
end_define

begin_define
define|#
directive|define
name|BSR_PM
value|0x07
end_define

begin_define
define|#
directive|define
name|BSR_PHVALID
value|0x08
end_define

begin_define
define|#
directive|define
name|BSR_IOR
value|0x01
end_define

begin_define
define|#
directive|define
name|BSR_DATAOUT
value|0x00
end_define

begin_define
define|#
directive|define
name|BSR_DATAIN
value|0x01
end_define

begin_define
define|#
directive|define
name|BSR_CMDOUT
value|0x02
end_define

begin_define
define|#
directive|define
name|BSR_STATIN
value|0x03
end_define

begin_define
define|#
directive|define
name|BSR_UNSPINFO0
value|0x04
end_define

begin_define
define|#
directive|define
name|BSR_UNSPINFO1
value|0x05
end_define

begin_define
define|#
directive|define
name|BSR_MSGOUT
value|0x06
end_define

begin_define
define|#
directive|define
name|BSR_MSGIN
value|0x07
end_define

begin_define
define|#
directive|define
name|BSR_RESET
value|0x00
end_define

begin_define
define|#
directive|define
name|BSR_AFM_RESET
value|0x01
end_define

begin_define
define|#
directive|define
name|BSR_SELECTED
value|0x11
end_define

begin_define
define|#
directive|define
name|BSR_SATFIN
value|0x16
end_define

begin_define
define|#
directive|define
name|BSR_ACKREQ
value|0x20
end_define

begin_define
define|#
directive|define
name|BSR_SATSDP
value|0x21
end_define

begin_define
define|#
directive|define
name|BSR_RESEL
value|0x80
end_define

begin_define
define|#
directive|define
name|BSR_AFM_RESEL
value|0x81
end_define

begin_define
define|#
directive|define
name|BSR_DISC
value|0x85
end_define

begin_define
define|#
directive|define
name|wd3s_cmd
value|0x18
end_define

begin_define
define|#
directive|define
name|wd3s_data
value|0x19
end_define

begin_define
define|#
directive|define
name|wd3s_qtag
value|0x1a
end_define

begin_define
define|#
directive|define
name|wd3s_mbank
value|0x30
end_define

begin_define
define|#
directive|define
name|MBR_RST
value|0x02
end_define

begin_define
define|#
directive|define
name|MBR_IEN
value|0x04
end_define

begin_define
define|#
directive|define
name|wd3s_mwin
value|0x31
end_define

begin_define
define|#
directive|define
name|wd3s_auxc
value|0x33
end_define

begin_define
define|#
directive|define
name|AUXCR_HIDM
value|0x07
end_define

begin_define
define|#
directive|define
name|AUXCR_INTM
value|0x38
end_define

begin_define
define|#
directive|define
name|AUXCR_RRST
value|0x80
end_define

begin_comment
comment|/* status port */
end_comment

begin_define
define|#
directive|define
name|STR_INT
value|0x80
end_define

begin_define
define|#
directive|define
name|STR_LCI
value|0x40
end_define

begin_define
define|#
directive|define
name|STR_BSY
value|0x20
end_define

begin_define
define|#
directive|define
name|STR_CIP
value|0x10
end_define

begin_define
define|#
directive|define
name|STR_PE
value|0x02
end_define

begin_define
define|#
directive|define
name|STR_DBR
value|0x01
end_define

begin_define
define|#
directive|define
name|STR_BUSY
value|0xf0
end_define

begin_comment
comment|/* cmd port */
end_comment

begin_define
define|#
directive|define
name|CMDP_DMES
value|0x01
end_define

begin_define
define|#
directive|define
name|CMDP_DMER
value|0x02
end_define

begin_define
define|#
directive|define
name|CMDP_TCMS
value|0x04
end_define

begin_define
define|#
directive|define
name|CMDP_TCMR
value|0x08
end_define

begin_define
define|#
directive|define
name|CMDP_TCIR
value|0x10
end_define

begin_comment
comment|/* wd33c93 chip cmds */
end_comment

begin_define
define|#
directive|define
name|WD3S_SBT
value|0x80
end_define

begin_define
define|#
directive|define
name|WD3S_RESET
value|0x00
end_define

begin_define
define|#
directive|define
name|WD3S_ABORT
value|0x01
end_define

begin_define
define|#
directive|define
name|WD3S_ASSERT_ATN
value|0x02
end_define

begin_define
define|#
directive|define
name|WD3S_NEGATE_ACK
value|0x03
end_define

begin_define
define|#
directive|define
name|WD3S_DISCONNECT
value|0x04
end_define

begin_define
define|#
directive|define
name|WD3S_RESELECT
value|0x05
end_define

begin_define
define|#
directive|define
name|WD3S_SELECT_ATN
value|0x06
end_define

begin_define
define|#
directive|define
name|WD3S_SELECT_NO_ATN
value|0x07
end_define

begin_define
define|#
directive|define
name|WD3S_SELECT_ATN_TFR
value|0x08
end_define

begin_define
define|#
directive|define
name|WD3S_SELECT_NO_ATN_TFR
value|0x09
end_define

begin_define
define|#
directive|define
name|WD3S_RESELECT_RCV_DATA
value|0x0a
end_define

begin_define
define|#
directive|define
name|WD3S_RESELECT_SEND_DATA
value|0x0b
end_define

begin_define
define|#
directive|define
name|WD3S_WAIT_SELECT_RCV
value|0x0c
end_define

begin_define
define|#
directive|define
name|WD3S_CMD_COMPSEQ
value|0x0d
end_define

begin_define
define|#
directive|define
name|WD3S_SEND_DISC_MSG
value|0x0e
end_define

begin_define
define|#
directive|define
name|WD3S_SET_IDI
value|0x0f
end_define

begin_define
define|#
directive|define
name|WD3S_RCV_CMD
value|0x10
end_define

begin_define
define|#
directive|define
name|WD3S_RCV_DATA
value|0x11
end_define

begin_define
define|#
directive|define
name|WD3S_RCV_MSG_OUT
value|0x12
end_define

begin_define
define|#
directive|define
name|WD3S_RCV_UNSP_INFO_OUT
value|0x13
end_define

begin_define
define|#
directive|define
name|WD3S_SEND_STATUS
value|0x14
end_define

begin_define
define|#
directive|define
name|WD3S_SEND_DATA
value|0x15
end_define

begin_define
define|#
directive|define
name|WD3S_SEND_MSG_IN
value|0x16
end_define

begin_define
define|#
directive|define
name|WD3S_SEND_UNSP_INFO_IN
value|0x17
end_define

begin_define
define|#
directive|define
name|WD3S_TRANSLATE_ADDRESS
value|0x18
end_define

begin_define
define|#
directive|define
name|WD3S_TFR_INFO
value|0x20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_WD33C93REG_H_ */
end_comment

end_unit

