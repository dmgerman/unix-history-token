begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2012 Intel Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|__IOAT_HW_H__
end_ifndef

begin_define
define|#
directive|define
name|__IOAT_HW_H__
end_define

begin_define
define|#
directive|define
name|IOAT_MAX_CHANNELS
value|32
end_define

begin_define
define|#
directive|define
name|IOAT_CHANCNT_OFFSET
value|0x00
end_define

begin_define
define|#
directive|define
name|IOAT_XFERCAP_OFFSET
value|0x01
end_define

begin_define
define|#
directive|define
name|IOAT_GENCTRL_OFFSET
value|0x02
end_define

begin_define
define|#
directive|define
name|IOAT_INTRCTRL_OFFSET
value|0x03
end_define

begin_define
define|#
directive|define
name|IOAT_INTRCTRL_MASTER_INT_EN
value|0x01
end_define

begin_define
define|#
directive|define
name|IOAT_ATTNSTATUS_OFFSET
value|0x04
end_define

begin_define
define|#
directive|define
name|IOAT_CBVER_OFFSET
value|0x08
end_define

begin_define
define|#
directive|define
name|IOAT_VER_3_0
value|0x30
end_define

begin_define
define|#
directive|define
name|IOAT_VER_3_3
value|0x33
end_define

begin_define
define|#
directive|define
name|IOAT_INTRDELAY_OFFSET
value|0x0C
end_define

begin_define
define|#
directive|define
name|IOAT_CS_STATUS_OFFSET
value|0x0E
end_define

begin_define
define|#
directive|define
name|IOAT_DMACAPABILITY_OFFSET
value|0x10
end_define

begin_comment
comment|/* DMA Channel Registers */
end_comment

begin_define
define|#
directive|define
name|IOAT_CHANCTRL_OFFSET
value|0x80
end_define

begin_define
define|#
directive|define
name|IOAT_CHANCTRL_CHANNEL_PRIORITY_MASK
value|0xF000
end_define

begin_define
define|#
directive|define
name|IOAT_CHANCTRL_COMPL_DCA_EN
value|0x0200
end_define

begin_define
define|#
directive|define
name|IOAT_CHANCTRL_CHANNEL_IN_USE
value|0x0100
end_define

begin_define
define|#
directive|define
name|IOAT_CHANCTRL_DESCRIPTOR_ADDR_SNOOP_CONTROL
value|0x0020
end_define

begin_define
define|#
directive|define
name|IOAT_CHANCTRL_ERR_INT_EN
value|0x0010
end_define

begin_define
define|#
directive|define
name|IOAT_CHANCTRL_ANY_ERR_ABORT_EN
value|0x0008
end_define

begin_define
define|#
directive|define
name|IOAT_CHANCTRL_ERR_COMPLETION_EN
value|0x0004
end_define

begin_define
define|#
directive|define
name|IOAT_CHANCTRL_INT_REARM
value|0x0001
end_define

begin_define
define|#
directive|define
name|IOAT_CHANCTRL_RUN
value|(IOAT_CHANCTRL_INT_REARM |\ 						 IOAT_CHANCTRL_ANY_ERR_ABORT_EN)
end_define

begin_define
define|#
directive|define
name|IOAT_CHANCMD_OFFSET
value|0x84
end_define

begin_define
define|#
directive|define
name|IOAT_CHANCMD_RESET
value|0x20
end_define

begin_define
define|#
directive|define
name|IOAT_CHANCMD_SUSPEND
value|0x04
end_define

begin_define
define|#
directive|define
name|IOAT_DMACOUNT_OFFSET
value|0x86
end_define

begin_define
define|#
directive|define
name|IOAT_CHANSTS_OFFSET_LOW
value|0x88
end_define

begin_define
define|#
directive|define
name|IOAT_CHANSTS_OFFSET_HIGH
value|0x8C
end_define

begin_define
define|#
directive|define
name|IOAT_CHANSTS_OFFSET
value|0x88
end_define

begin_define
define|#
directive|define
name|IOAT_CHANSTS_STATUS
value|0x7ULL
end_define

begin_define
define|#
directive|define
name|IOAT_CHANSTS_ACTIVE
value|0x0
end_define

begin_define
define|#
directive|define
name|IOAT_CHANSTS_IDLE
value|0x1
end_define

begin_define
define|#
directive|define
name|IOAT_CHANSTS_SUSPENDED
value|0x2
end_define

begin_define
define|#
directive|define
name|IOAT_CHANSTS_HALTED
value|0x3
end_define

begin_define
define|#
directive|define
name|IOAT_CHANSTS_UNAFFILIATED_ERROR
value|0x8ULL
end_define

begin_define
define|#
directive|define
name|IOAT_CHANSTS_SOFT_ERROR
value|0x10ULL
end_define

begin_define
define|#
directive|define
name|IOAT_CHANSTS_COMPLETED_DESCRIPTOR_MASK
value|(~0x3FULL)
end_define

begin_define
define|#
directive|define
name|IOAT_CHAINADDR_OFFSET_LOW
value|0x90
end_define

begin_define
define|#
directive|define
name|IOAT_CHAINADDR_OFFSET_HIGH
value|0x94
end_define

begin_define
define|#
directive|define
name|IOAT_CHANCMP_OFFSET_LOW
value|0x98
end_define

begin_define
define|#
directive|define
name|IOAT_CHANCMP_OFFSET_HIGH
value|0x9C
end_define

begin_define
define|#
directive|define
name|IOAT_CHANERR_OFFSET
value|0xA8
end_define

begin_define
define|#
directive|define
name|IOAT_CFG_CHANERR_INT_OFFSET
value|0x180
end_define

begin_define
define|#
directive|define
name|IOAT_CFG_CHANERRMASK_INT_OFFSET
value|0x184
end_define

begin_define
define|#
directive|define
name|IOAT_MIN_ORDER
value|4
end_define

begin_define
define|#
directive|define
name|IOAT_MAX_ORDER
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IOAT_HW_H__ */
end_comment

end_unit

