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

begin_comment
comment|/* Only bits [4:0] are valid. */
end_comment

begin_define
define|#
directive|define
name|IOAT_XFERCAP_VALID_MASK
value|0x1f
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
name|IOAT_INTRDELAY_OFFSET
value|0x0C
end_define

begin_define
define|#
directive|define
name|IOAT_INTRDELAY_SUPPORTED
value|(1<< 15)
end_define

begin_comment
comment|/* Reserved.				(1<< 14) */
end_comment

begin_comment
comment|/* [13:0] is the coalesce period, in microseconds. */
end_comment

begin_define
define|#
directive|define
name|IOAT_INTRDELAY_US_MASK
value|((1<< 14) - 1)
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

begin_define
define|#
directive|define
name|IOAT_DMACAP_PB
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IOAT_DMACAP_CRC
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|IOAT_DMACAP_MARKER_SKIP
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|IOAT_DMACAP_OLD_XOR
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|IOAT_DMACAP_DCA
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|IOAT_DMACAP_MOVECRC
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|IOAT_DMACAP_BFILL
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|IOAT_DMACAP_EXT_APIC
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|IOAT_DMACAP_XOR
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|IOAT_DMACAP_PQ
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|IOAT_DMACAP_DMA_DIF
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|IOAT_DMACAP_DWBES
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|IOAT_DMACAP_RAID16SS
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|IOAT_DMACAP_DMAMC
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|IOAT_DMACAP_CTOS
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|IOAT_DMACAP_STR
define|\
value|"\20\24Completion_Timeout_Support\23DMA_with_Multicasting_Support" \     "\22RAID_Super_descriptors\16Descriptor_Write_Back_Error_Support" \     "\13DMA_with_DIF\12PQ\11XOR\10Extended_APIC_ID\07Block_Fill\06Move_CRC" \     "\05DCA\04Old_XOR\03Marker_Skipping\02CRC\01Page_Break"
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
value|(IOAT_CHANCTRL_INT_REARM |\ 						 IOAT_CHANCTRL_ERR_COMPLETION_EN |\ 						 IOAT_CHANCTRL_ANY_ERR_ABORT_EN |\ 						 IOAT_CHANCTRL_ERR_INT_EN)
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
name|IOAT_CHANSTS_ARMED
value|0x4
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
name|IOAT_CHANERR_XSADDERR
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IOAT_CHANERR_XDADDERR
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|IOAT_CHANERR_NDADDERR
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|IOAT_CHANERR_DERR
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|IOAT_CHANERR_CHADDERR
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|IOAT_CHANERR_CCMDERR
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|IOAT_CHANERR_CUNCORERR
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|IOAT_CHANERR_DUNCORERR
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|IOAT_CHANERR_RDERR
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|IOAT_CHANERR_WDERR
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|IOAT_CHANERR_DCERR
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|IOAT_CHANERR_DXSERR
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|IOAT_CHANERR_CMPADDERR
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|IOAT_CHANERR_INTCFGERR
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|IOAT_CHANERR_SEDERR
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|IOAT_CHANERR_UNAFFERR
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|IOAT_CHANERR_CXPERR
value|(1<< 16)
end_define

begin_comment
comment|/* Reserved.				(1<< 17) */
end_comment

begin_define
define|#
directive|define
name|IOAT_CHANERR_DCNTERR
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|IOAT_CHANERR_DIFFERR
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|IOAT_CHANERR_GTVERR
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|IOAT_CHANERR_ATVERR
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|IOAT_CHANERR_RTVERR
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|IOAT_CHANERR_BBERR
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|IOAT_CHANERR_RDIFFERR
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|IOAT_CHANERR_RGTVERR
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|IOAT_CHANERR_RATVERR
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|IOAT_CHANERR_RRTVERR
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|IOAT_CHANERR_STR
define|\
value|"\20\34RRTVERR\33RATVERR\32RGTVERR\31RDIFFERR\30BBERR\27RTVERR\26ATVERR" \     "\25GTVERR\24DIFFERR\23DCNTERR\21CXPERR\20UNAFFERR\17SEDERR\16INTCFGERR" \     "\15CMPADDERR\14DXSERR\13DCERR\12WDERR\11RDERR\10DUNCORERR\07CUNCORERR" \     "\06CCMDERR\05CHADDERR\04DERR\03NDADDERR\02XDADDERR\01XSADDERR"
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

