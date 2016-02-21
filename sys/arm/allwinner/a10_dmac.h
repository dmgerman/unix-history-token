begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014-2016 Jared D. McNeill<jmcneill@invisible.ca>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_A10_DMAC_H_
end_ifndef

begin_define
define|#
directive|define
name|_A10_DMAC_H_
end_define

begin_define
define|#
directive|define
name|AWIN_DMA_IRQ_EN_REG
value|0x0000
end_define

begin_define
define|#
directive|define
name|AWIN_DMA_IRQ_PEND_STA_REG
value|0x0004
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_AUTO_GATE_REG
value|0x0008
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_REG
parameter_list|(
name|n
parameter_list|)
value|(0x100+0x20*(n))
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_REG
value|0x0000
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_SRC_ADDR_REG
value|0x0004
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_DEST_ADDR_REG
value|0x0008
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_BC_REG
value|0x000c
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_REG
parameter_list|(
name|n
parameter_list|)
value|(0x300+0x20*(n))
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_REG
value|0x0000
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_SRC_START_ADDR_REG
value|0x0004
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_DEST_START_ADDR_REG
value|0x0008
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_BC_REG
value|0x000c
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_PARA_REG
value|0x0018
end_define

begin_define
define|#
directive|define
name|AWIN_DMA_IRQ_END_MASK
value|0xaaaaaaaa
end_define

begin_define
define|#
directive|define
name|AWIN_DMA_IRQ_HF_MASK
value|0x55555555
end_define

begin_define
define|#
directive|define
name|AWIN_DMA_IRQ_DDMA
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|AWIN_DMA_IRQ_DDMA_END
parameter_list|(
name|n
parameter_list|)
value|(1U<< (17+2*(n)))
end_define

begin_define
define|#
directive|define
name|AWIN_DMA_IRQ_DDMA_HF
parameter_list|(
name|n
parameter_list|)
value|(1U<< (16+2*(n)))
end_define

begin_define
define|#
directive|define
name|AWIN_DMA_IRQ_NDMA
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|AWIN_DMA_IRQ_NDMA_END
parameter_list|(
name|n
parameter_list|)
value|(1U<< (1+2*(n)))
end_define

begin_define
define|#
directive|define
name|AWIN_DMA_IRQ_NDMA_HF
parameter_list|(
name|n
parameter_list|)
value|(1U<< (0+2*(n)))
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_AUTO_GATING_DIS
value|(1U<< 16)
end_define

begin_define
define|#
directive|define
name|AWIN_DMA_CTL_DST_DATA_WIDTH_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|AWIN_DMA_CTL_DST_DATA_WIDTH_MASK
value|(3U<< AWIN_DMA_CTL_DST_DATA_WIDTH_SHIFT)
end_define

begin_define
define|#
directive|define
name|AWIN_DMA_CTL_DATA_WIDTH_8
value|0
end_define

begin_define
define|#
directive|define
name|AWIN_DMA_CTL_DATA_WIDTH_16
value|1
end_define

begin_define
define|#
directive|define
name|AWIN_DMA_CTL_DATA_WIDTH_32
value|2
end_define

begin_define
define|#
directive|define
name|AWIN_DMA_CTL_DST_BURST_LEN_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|AWIN_DMA_CTL_DST_BURST_LEN_MASK
value|(3<< AWIN_DMA_CTL_DST_BURST_LEN_SHIFT)
end_define

begin_define
define|#
directive|define
name|AWIN_DMA_CTL_BURST_LEN_1
value|0
end_define

begin_define
define|#
directive|define
name|AWIN_DMA_CTL_BURST_LEN_4
value|1
end_define

begin_define
define|#
directive|define
name|AWIN_DMA_CTL_BURST_LEN_8
value|2
end_define

begin_define
define|#
directive|define
name|AWIN_DMA_CTL_DST_DRQ_TYPE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|AWIN_DMA_CTL_DST_DRQ_TYPE_MASK
value|(0x1f<< AWIN_DMA_CTL_DST_DRQ_TYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|AWIN_DMA_CTL_BC_REMAINING
value|(1U<< 15)
end_define

begin_define
define|#
directive|define
name|AWIN_DMA_CTL_SRC_DATA_WIDTH_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|AWIN_DMA_CTL_SRC_DATA_WIDTH_MASK
value|(3U<< AWIN_DMA_CTL_SRC_DATA_WIDTH_SHIFT)
end_define

begin_define
define|#
directive|define
name|AWIN_DMA_CTL_SRC_BURST_LEN_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|AWIN_DMA_CTL_SRC_BURST_LEN_MASK
value|(3U<< AWIN_DMA_CTL_SRC_BURST_LEN_SHIFT)
end_define

begin_define
define|#
directive|define
name|AWIN_DMA_CTL_SRC_DRQ_TYPE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AWIN_DMA_CTL_SRC_DRQ_TYPE_MASK
value|(0x1f<< AWIN_DMA_CTL_SRC_DRQ_TYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DMA_LOADING
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DMA_CONTIN_MODE
value|(1U<< 30)
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_WAIT_STATE_LOG2_SHIFT
value|27
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_WAIT_STATE_LOG2_MASK
value|(7U<< AWIN_NDMA_CTL_WAIT_STATE_LOG2_SHIFT)
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DST_NON_SECURE
value|(1U<< 22)
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DST_ADDR_NOINCR
value|(1U<< 21)
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DRQ_IRO
value|0
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DRQ_IR1
value|1
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DRQ_SPDIF
value|2
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DRQ_IISO
value|3
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DRQ_IIS1
value|4
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DRQ_AC97
value|5
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DRQ_IIS2
value|6
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DRQ_UARTO
value|8
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DRQ_UART1
value|9
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DRQ_UART2
value|10
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DRQ_UART3
value|11
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DRQ_UART4
value|12
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DRQ_UART5
value|13
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DRQ_UART6
value|14
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DRQ_UART7
value|15
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DRQ_DDC
value|16
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DRQ_USB_EP1
value|17
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DRQ_CODEC
value|19
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DRQ_SRAM
value|21
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DRQ_SDRAM
value|22
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DRQ_TP_AD
value|23
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DRQ_SPI0
value|24
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DRQ_SPI1
value|25
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DRQ_SPI2
value|26
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DRQ_SPI3
value|27
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DRQ_USB_EP2
value|28
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DRQ_USB_EP3
value|29
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DRQ_USB_EP4
value|30
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_DRQ_USB_EP5
value|31
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_SRC_NON_SECURE
value|(1U<< 6)
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_CTL_SRC_ADDR_NOINCR
value|(1U<< 5)
end_define

begin_define
define|#
directive|define
name|AWIN_NDMA_BC_COUNT
value|0x0003ffff
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DMA_LOADING
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_BUSY
value|(1U<< 30)
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DMA_CONTIN_MODE
value|(1U<< 29)
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DST_NON_SECURE
value|(1U<< 28)
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DST_ADDR_MODE_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DST_ADDR_MODE_MASK
value|(3U<< AWIN_DDMA_CTL_DST_ADDR_MODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DMA_ADDR_LINEAR
value|0
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DMA_ADDR_IO
value|1
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DMA_ADDR_HPAGE
value|2
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DMA_ADDR_VPAGE
value|3
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DST_DRQ_TYPE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DST_DRQ_TYPE_MASK
value|(0x1f<< AWIN_DDMA_CTL_DST_DRQ_TYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DRQ_SRAM
value|0
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DRQ_SDRAM
value|1
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DRQ_NFC
value|3
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DRQ_USB0
value|4
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DRQ_EMAC_TX
value|6
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DRQ_EMAC_RX
value|7
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DRQ_SPI1_TX
value|8
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DRQ_SPI1_RX
value|9
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DRQ_SS_TX
value|10
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DRQ_SS_RX
value|11
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DRQ_TCON0
value|14
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DRQ_TCON1
value|15
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DRQ_MS_TX
value|23
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DRQ_MS_RX
value|23
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DRQ_HDMI_AUDIO
value|24
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DRQ_SPI0_TX
value|26
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DRQ_SPI0_RX
value|27
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DRQ_SPI2_TX
value|28
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DRQ_SPI2_RX
value|29
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DRQ_SPI3_TX
value|30
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_DRQ_SPI3_RX
value|31
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_SRC_NON_SECURE
value|(1U<< 12)
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_SRC_ADDR_MODE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_CTL_SRC_ADDR_MODE_MASK
value|(3U<< AWIN_DDMA_CTL_SRC_ADDR_MODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_BC_COUNT
value|0x00003fff
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_PARA_DST_DATA_BLK_SIZ_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_PARA_DST_DATA_BLK_SIZ_MASK
value|(0xff<< AWIN_DDMA_PARA_DST_DATA_BLK_SIZ_SHIFT)
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_PARA_DST_WAIT_CYC_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_PARA_DST_WAIT_CYC_MASK
value|(0xff<< AWIN_DDMA_PARA_DST_WAIT_CYC_SHIFT)
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_PARA_SRC_DATA_BLK_SIZ_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_PARA_SRC_DATA_BLK_SIZ_MASK
value|(0xff<< AWIN_DDMA_PARA_SRC_DATA_BLK_SIZ_SHIFT)
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_PARA_SRC_WAIT_CYC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AWIN_DDMA_PARA_SRC_WAIT_CYC_MASK
value|(0xff<< AWIN_DDMA_PARA_SRC_WAIT_CYC_SHIFT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_A10_DMAC_H_ */
end_comment

end_unit

