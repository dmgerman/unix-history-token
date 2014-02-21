begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011  *	Ben Gray<ben.r.gray@gmail.com>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TI_SDMAREG_H__
end_ifndef

begin_define
define|#
directive|define
name|__TI_SDMAREG_H__
end_define

begin_comment
comment|/**  * The number of DMA channels possible on the controller.  */
end_comment

begin_define
define|#
directive|define
name|NUM_DMA_CHANNELS
value|32
end_define

begin_define
define|#
directive|define
name|NUM_DMA_IRQS
value|4
end_define

begin_comment
comment|/**  * Register offsets  */
end_comment

begin_define
define|#
directive|define
name|DMA4_REVISION
value|0x0000
end_define

begin_define
define|#
directive|define
name|DMA4_IRQSTATUS_L
parameter_list|(
name|j
parameter_list|)
value|(0x0008 + ((j) * 0x4))
end_define

begin_define
define|#
directive|define
name|DMA4_IRQENABLE_L
parameter_list|(
name|j
parameter_list|)
value|(0x0018 + ((j) * 0x4))
end_define

begin_define
define|#
directive|define
name|DMA4_SYSSTATUS
value|0x0028
end_define

begin_define
define|#
directive|define
name|DMA4_OCP_SYSCONFIG
value|0x002C
end_define

begin_define
define|#
directive|define
name|DMA4_CAPS_0
value|0x0064
end_define

begin_define
define|#
directive|define
name|DMA4_CAPS_2
value|0x006C
end_define

begin_define
define|#
directive|define
name|DMA4_CAPS_3
value|0x0070
end_define

begin_define
define|#
directive|define
name|DMA4_CAPS_4
value|0x0074
end_define

begin_define
define|#
directive|define
name|DMA4_GCR
value|0x0078
end_define

begin_define
define|#
directive|define
name|DMA4_CCR
parameter_list|(
name|i
parameter_list|)
value|(0x0080 + ((i) * 0x60))
end_define

begin_define
define|#
directive|define
name|DMA4_CLNK_CTRL
parameter_list|(
name|i
parameter_list|)
value|(0x0084 + ((i) * 0x60))
end_define

begin_define
define|#
directive|define
name|DMA4_CICR
parameter_list|(
name|i
parameter_list|)
value|(0x0088 + ((i) * 0x60))
end_define

begin_define
define|#
directive|define
name|DMA4_CSR
parameter_list|(
name|i
parameter_list|)
value|(0x008C + ((i) * 0x60))
end_define

begin_define
define|#
directive|define
name|DMA4_CSDP
parameter_list|(
name|i
parameter_list|)
value|(0x0090 + ((i) * 0x60))
end_define

begin_define
define|#
directive|define
name|DMA4_CEN
parameter_list|(
name|i
parameter_list|)
value|(0x0094 + ((i) * 0x60))
end_define

begin_define
define|#
directive|define
name|DMA4_CFN
parameter_list|(
name|i
parameter_list|)
value|(0x0098 + ((i) * 0x60))
end_define

begin_define
define|#
directive|define
name|DMA4_CSSA
parameter_list|(
name|i
parameter_list|)
value|(0x009C + ((i) * 0x60))
end_define

begin_define
define|#
directive|define
name|DMA4_CDSA
parameter_list|(
name|i
parameter_list|)
value|(0x00A0 + ((i) * 0x60))
end_define

begin_define
define|#
directive|define
name|DMA4_CSE
parameter_list|(
name|i
parameter_list|)
value|(0x00A4 + ((i) * 0x60))
end_define

begin_define
define|#
directive|define
name|DMA4_CSF
parameter_list|(
name|i
parameter_list|)
value|(0x00A8 + ((i) * 0x60))
end_define

begin_define
define|#
directive|define
name|DMA4_CDE
parameter_list|(
name|i
parameter_list|)
value|(0x00AC + ((i) * 0x60))
end_define

begin_define
define|#
directive|define
name|DMA4_CDF
parameter_list|(
name|i
parameter_list|)
value|(0x00B0 + ((i) * 0x60))
end_define

begin_define
define|#
directive|define
name|DMA4_CSAC
parameter_list|(
name|i
parameter_list|)
value|(0x00B4 + ((i) * 0x60))
end_define

begin_define
define|#
directive|define
name|DMA4_CDAC
parameter_list|(
name|i
parameter_list|)
value|(0x00B8 + ((i) * 0x60))
end_define

begin_define
define|#
directive|define
name|DMA4_CCEN
parameter_list|(
name|i
parameter_list|)
value|(0x00BC + ((i) * 0x60))
end_define

begin_define
define|#
directive|define
name|DMA4_CCFN
parameter_list|(
name|i
parameter_list|)
value|(0x00C0 + ((i) * 0x60))
end_define

begin_define
define|#
directive|define
name|DMA4_COLOR
parameter_list|(
name|i
parameter_list|)
value|(0x00C4 + ((i) * 0x60))
end_define

begin_comment
comment|/* The following register are only defined on OMAP44xx (and newer?) */
end_comment

begin_define
define|#
directive|define
name|DMA4_CDP
parameter_list|(
name|i
parameter_list|)
value|(0x00D0 + ((i) * 0x60))
end_define

begin_define
define|#
directive|define
name|DMA4_CNDP
parameter_list|(
name|i
parameter_list|)
value|(0x00D4 + ((i) * 0x60))
end_define

begin_define
define|#
directive|define
name|DMA4_CCDN
parameter_list|(
name|i
parameter_list|)
value|(0x00D8 + ((i) * 0x60))
end_define

begin_comment
comment|/**  * Various register field settings  */
end_comment

begin_define
define|#
directive|define
name|DMA4_CSDP_DATA_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 0)
end_define

begin_define
define|#
directive|define
name|DMA4_CSDP_SRC_BURST_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 7)
end_define

begin_define
define|#
directive|define
name|DMA4_CSDP_DST_BURST_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 14)
end_define

begin_define
define|#
directive|define
name|DMA4_CSDP_SRC_ENDIANISM
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 21)
end_define

begin_define
define|#
directive|define
name|DMA4_CSDP_DST_ENDIANISM
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 19)
end_define

begin_define
define|#
directive|define
name|DMA4_CSDP_WRITE_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 16)
end_define

begin_define
define|#
directive|define
name|DMA4_CSDP_SRC_PACKED
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 6)
end_define

begin_define
define|#
directive|define
name|DMA4_CSDP_DST_PACKED
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 13)
end_define

begin_define
define|#
directive|define
name|DMA4_CCR_DST_ADDRESS_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 14)
end_define

begin_define
define|#
directive|define
name|DMA4_CCR_SRC_ADDRESS_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 12)
end_define

begin_define
define|#
directive|define
name|DMA4_CCR_READ_PRIORITY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 6)
end_define

begin_define
define|#
directive|define
name|DMA4_CCR_WRITE_PRIORITY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 26)
end_define

begin_define
define|#
directive|define
name|DMA4_CCR_SYNC_TRIGGER
parameter_list|(
name|x
parameter_list|)
value|((((x)& 0x60)<< 14) \                                                  | ((x)& 0x1f))
end_define

begin_define
define|#
directive|define
name|DMA4_CCR_FRAME_SYNC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 5)
end_define

begin_define
define|#
directive|define
name|DMA4_CCR_BLOCK_SYNC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 18)
end_define

begin_define
define|#
directive|define
name|DMA4_CCR_SEL_SRC_DST_SYNC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 24)
end_define

begin_define
define|#
directive|define
name|DMA4_CCR_PACKET_TRANS
value|(DMA4_CCR_FRAME_SYNC(1) | \                                                  DMA4_CCR_BLOCK_SYNC(1) )
end_define

begin_define
define|#
directive|define
name|DMA4_CSR_DROP
value|(1UL<< 1)
end_define

begin_define
define|#
directive|define
name|DMA4_CSR_HALF
value|(1UL<< 2)
end_define

begin_define
define|#
directive|define
name|DMA4_CSR_FRAME
value|(1UL<< 3)
end_define

begin_define
define|#
directive|define
name|DMA4_CSR_LAST
value|(1UL<< 4)
end_define

begin_define
define|#
directive|define
name|DMA4_CSR_BLOCK
value|(1UL<< 5)
end_define

begin_define
define|#
directive|define
name|DMA4_CSR_SYNC
value|(1UL<< 6)
end_define

begin_define
define|#
directive|define
name|DMA4_CSR_PKT
value|(1UL<< 7)
end_define

begin_define
define|#
directive|define
name|DMA4_CSR_TRANS_ERR
value|(1UL<< 8)
end_define

begin_define
define|#
directive|define
name|DMA4_CSR_SECURE_ERR
value|(1UL<< 9)
end_define

begin_define
define|#
directive|define
name|DMA4_CSR_SUPERVISOR_ERR
value|(1UL<< 10)
end_define

begin_define
define|#
directive|define
name|DMA4_CSR_MISALIGNED_ADRS_ERR
value|(1UL<< 11)
end_define

begin_define
define|#
directive|define
name|DMA4_CSR_DRAIN_END
value|(1UL<< 12)
end_define

begin_define
define|#
directive|define
name|DMA4_CSR_CLEAR_MASK
value|(0xffe)
end_define

begin_define
define|#
directive|define
name|DMA4_CICR_DROP_IE
value|(1UL<< 1)
end_define

begin_define
define|#
directive|define
name|DMA4_CICR_HALF_IE
value|(1UL<< 2)
end_define

begin_define
define|#
directive|define
name|DMA4_CICR_FRAME_IE
value|(1UL<< 3)
end_define

begin_define
define|#
directive|define
name|DMA4_CICR_LAST_IE
value|(1UL<< 4)
end_define

begin_define
define|#
directive|define
name|DMA4_CICR_BLOCK_IE
value|(1UL<< 5)
end_define

begin_define
define|#
directive|define
name|DMA4_CICR_PKT_IE
value|(1UL<< 7)
end_define

begin_define
define|#
directive|define
name|DMA4_CICR_TRANS_ERR_IE
value|(1UL<< 8)
end_define

begin_define
define|#
directive|define
name|DMA4_CICR_SECURE_ERR_IE
value|(1UL<< 9)
end_define

begin_define
define|#
directive|define
name|DMA4_CICR_SUPERVISOR_ERR_IE
value|(1UL<< 10)
end_define

begin_define
define|#
directive|define
name|DMA4_CICR_MISALIGNED_ADRS_ERR_IE
value|(1UL<< 11)
end_define

begin_define
define|#
directive|define
name|DMA4_CICR_DRAIN_IE
value|(1UL<< 12)
end_define

begin_comment
comment|/**  *	The following H/W revision values were found be experimentation, TI don't  *	publish the revision numbers.  The TRM says "TI internal Data".  */
end_comment

begin_define
define|#
directive|define
name|DMA4_OMAP3_REV
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DMA4_OMAP4_REV
value|0x00010900
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __TI_SDMAREG_H__ */
end_comment

end_unit

