begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2014 Hans Petter Selasky<hselasky@FreeBSD.org>  * All rights reserved.  *  * This software was developed by SRI International and the University of  * Cambridge Computer Laboratory under DARPA/AFRL contract (FA8750-10-C-0237)  * ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SAF1761_OTG_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_SAF1761_OTG_REG_H_
end_define

begin_comment
comment|/* Global registers */
end_comment

begin_define
define|#
directive|define
name|SOTG_VEND_PROD_ID
value|0x370
end_define

begin_define
define|#
directive|define
name|SOTG_VEND_ID
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|SOTG_PROD_ID
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|SOTG_CTRL_SET_CLR
value|0x374
end_define

begin_define
define|#
directive|define
name|SOTG_CTRL_SET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|SOTG_CTRL_CLR
parameter_list|(
name|x
parameter_list|)
value|(((x)<< 16)& 0xFFFF0000)
end_define

begin_define
define|#
directive|define
name|SOTG_CTRL_OTG_DISABLE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|SOTG_CTRL_OTG_SE0_EN
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|SOTG_CTRL_BDIS_ACON_EN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|SOTG_CTRL_SW_SEL_HC_DC
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|SOTG_CTRL_VBUS_CHRG
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|SOTG_CTRL_VBUS_DISCHRG
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|SOTG_CTRL_VBUS_DRV
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|SOTG_CTRL_SEL_CP_EXT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SOTG_CTRL_DM_PULL_DOWN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SOTG_CTRL_DP_PULL_DOWN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SOTG_CTRL_DP_PULL_UP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SOTG_STATUS
value|0x378
end_define

begin_define
define|#
directive|define
name|SOTG_STATUS_B_SE0_SRP
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|SOTG_STATUS_B_SESS_END
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|SOTG_STATUS_RMT_CONN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|SOTG_STATUS_ID
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SOTG_STATUS_DP_SRP
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SOTG_STATUS_A_B_SESS_VLD
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SOTG_STATUS_VBUS_VLD
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SOTG_IRQ_LATCH_SET_CLR
value|0x37C
end_define

begin_define
define|#
directive|define
name|SOTG_IRQ_LATCH_SET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|SOTG_IRQ_LATCH_CLR
parameter_list|(
name|x
parameter_list|)
value|(((x)<< 16)& 0xFFFF0000)
end_define

begin_define
define|#
directive|define
name|SOTG_IRQ_ENABLE_SET_CLR
value|0x380
end_define

begin_define
define|#
directive|define
name|SOTG_IRQ_ENABLE_SET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|SOTG_IRQ_ENABLE_CLR
parameter_list|(
name|x
parameter_list|)
value|(((x)<< 16)& 0xFFFF0000)
end_define

begin_define
define|#
directive|define
name|SOTG_IRQ_RISE_SET_CLR
value|0x384
end_define

begin_define
define|#
directive|define
name|SOTG_IRQ_RISE_SET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|SOTG_IRQ_RISE_CLR
parameter_list|(
name|x
parameter_list|)
value|(((x)<< 16)& 0xFFFF0000)
end_define

begin_define
define|#
directive|define
name|SOTG_IRQ_OTG_TMR_TIMEOUT
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|SOTG_IRQ_B_SE0_SRP
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|SOTG_IRQ_B_SESS_END
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|SOTG_IRQ_BDIS_ACON
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|SOTG_IRQ_OTG_RESUME
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|SOTG_IRQ_RMT_CONN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|SOTG_IRQ_ID
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SOTG_IRQ_DP_SRP
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SOTG_IRQ_A_B_SESS_VLD
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SOTG_IRQ_VBUS_VLD
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SOTG_TIMER_LOW_SET_CLR
value|0x388
end_define

begin_define
define|#
directive|define
name|SOTG_TIMER_LOW_SET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|SOTG_TIMER_LOW_CLR
parameter_list|(
name|x
parameter_list|)
value|(((x)<< 16)& 0xFFFF0000)
end_define

begin_define
define|#
directive|define
name|SOTG_TIMER_HIGH_SET_CLR
value|0x38C
end_define

begin_define
define|#
directive|define
name|SOTG_TIMER_HIGH_SET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|SOTG_TIMER_HIGH_CLR
parameter_list|(
name|x
parameter_list|)
value|(((x)<< 16)& 0xFFFF0000)
end_define

begin_define
define|#
directive|define
name|SOTG_TIMER_HIGH_START
value|(1U<< 15)
end_define

begin_define
define|#
directive|define
name|SOTG_MEMORY_REG
value|0x33c
end_define

begin_comment
comment|/* Peripheral controller specific registers */
end_comment

begin_define
define|#
directive|define
name|SOTG_ADDRESS
value|0x200
end_define

begin_define
define|#
directive|define
name|SOTG_ADDRESS_ENABLE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|SOTG_MODE
value|0x20C
end_define

begin_define
define|#
directive|define
name|SOTG_MODE_DMACLK_ON
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|SOTG_MODE_VBUSSTAT
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|SOTG_MODE_CLKAON
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|SOTG_MODE_SNDRSU
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|SOTG_MODE_GOSUSP
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|SOTG_MODE_SFRESET
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|SOTG_MODE_GLINTENA
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SOTG_MODE_WKUPCS
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SOTG_INTERRUPT_CFG
value|0x210
end_define

begin_define
define|#
directive|define
name|SOTG_INTERRUPT_CFG_DEBUG_SET
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|SOTG_INTERRUPT_CFG_CDBGMOD
value|(1<< 6)
end_define

begin_comment
comment|/* ACK only */
end_comment

begin_define
define|#
directive|define
name|SOTG_INTERRUPT_CFG_DDBGMODIN
value|(1<< 4)
end_define

begin_comment
comment|/* ACK only */
end_comment

begin_define
define|#
directive|define
name|SOTG_INTERRUPT_CFG_DDBGMODOUT
value|(1<< 2)
end_define

begin_comment
comment|/* ACK and NYET only */
end_comment

begin_define
define|#
directive|define
name|SOTG_INTERRUPT_CFG_INTLVL
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SOTG_INTERRUPT_CFG_INTPOL
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SOTG_DCINTERRUPT_EN
value|0x214
end_define

begin_define
define|#
directive|define
name|SOTG_HW_MODE_CTRL
value|0x300
end_define

begin_define
define|#
directive|define
name|SOTG_HW_MODE_CTRL_ALL_ATX_RESET
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|SOTG_HW_MODE_CTRL_ANA_DIGI_OC
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|SOTG_HW_MODE_CTRL_DEV_DMA
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|SOTG_HW_MODE_CTRL_COMN_INT
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|SOTG_HW_MODE_CTRL_COMN_DMA
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|SOTG_HW_MODE_CTRL_DATA_BUS_WIDTH
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|SOTG_HW_MODE_CTRL_DACK_POL
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|SOTG_HW_MODE_CTRL_DREQ_POL
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|SOTG_HW_MODE_CTRL_INTR_POL
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SOTG_HW_MODE_CTRL_INTR_LEVEL
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SOTG_HW_MODE_CTRL_GLOBAL_INTR_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SOTG_OTG_CTRL
value|0x374
end_define

begin_define
define|#
directive|define
name|SOTG_EP_INDEX
value|0x22c
end_define

begin_define
define|#
directive|define
name|SOTG_EP_INDEX_EP0SETUP
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|SOTG_EP_INDEX_ENDP_INDEX_MASK
value|(15<< 1)
end_define

begin_define
define|#
directive|define
name|SOTG_EP_INDEX_ENDP_INDEX_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|SOTG_EP_INDEX_DIR_IN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SOTG_EP_INDEX_DIR_OUT
value|0
end_define

begin_define
define|#
directive|define
name|SOTG_CTRL_FUNC
value|0x228
end_define

begin_define
define|#
directive|define
name|SOTG_CTRL_FUNC_CLBUF
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|SOTG_CTRL_FUNC_VENDP
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SOTG_CTRL_FUNC_DSEN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SOTG_CTRL_FUNC_STATUS
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SOTG_CTRL_FUNC_STALL
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SOTG_DATA_PORT
value|0x220
end_define

begin_define
define|#
directive|define
name|SOTG_BUF_LENGTH
value|0x21C
end_define

begin_define
define|#
directive|define
name|SOTG_BUF_LENGTH_BUFLEN_MASK
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|SOTG_BUF_LENGTH_FILLED_MASK
value|(3<< 16)
end_define

begin_define
define|#
directive|define
name|SOTG_EP_MAXPACKET
value|0x204
end_define

begin_define
define|#
directive|define
name|SOTG_EP_TYPE
value|0x208
end_define

begin_define
define|#
directive|define
name|SOTG_EP_TYPE_NOEMPPKT
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|SOTG_EP_TYPE_ENABLE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SOTG_EP_TYPE_DBLBUF
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SOTG_EP_TYPE_EP_TYPE
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|SOTG_DMA_CMD
value|0x230
end_define

begin_define
define|#
directive|define
name|SOTG_DMA_XFER_COUNT
value|0x234
end_define

begin_define
define|#
directive|define
name|SOTG_DCDMA_CFG
value|0x238
end_define

begin_define
define|#
directive|define
name|SOTG_DMA_HW
value|0x23C
end_define

begin_define
define|#
directive|define
name|SOTG_DMA_IRQ_REASON
value|0x250
end_define

begin_define
define|#
directive|define
name|SOTG_DMA_IRQ_ENABLE
value|0x254
end_define

begin_define
define|#
directive|define
name|SOTG_DMA_EP
value|0x258
end_define

begin_define
define|#
directive|define
name|SOTG_BURST_COUNTER
value|0x264
end_define

begin_define
define|#
directive|define
name|SOTG_DCINTERRUPT
value|0x218
end_define

begin_define
define|#
directive|define
name|SOTG_DCINTERRUPT_IEPRX
parameter_list|(
name|n
parameter_list|)
value|(1<< (10 + (2*(n))))
end_define

begin_define
define|#
directive|define
name|SOTG_DCINTERRUPT_IEPTX
parameter_list|(
name|n
parameter_list|)
value|(1<< (11 + (2*(n))))
end_define

begin_define
define|#
directive|define
name|SOTG_DCINTERRUPT_IEP0SETUP
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|SOTG_DCINTERRUPT_IEVBUS
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|SOTG_DCINTERRUPT_IEDMA
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|SOTG_DCINTERRUPT_IEHS_STA
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|SOTG_DCINTERRUPT_IERESM
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|SOTG_DCINTERRUPT_IESUSP
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SOTG_DCINTERRUPT_IEPSOF
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SOTG_DCINTERRUPT_IESOF
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SOTG_DCINTERRUPT_IEBRST
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SOTG_DCCHIP_ID
value|0x270
end_define

begin_define
define|#
directive|define
name|SOTG_FRAME_NUM
value|0x274
end_define

begin_define
define|#
directive|define
name|SOTG_FRAME_NUM_MICROSOFR_MASK
value|0x3800
end_define

begin_define
define|#
directive|define
name|SOTG_FRAME_NUM_MICROSOFR_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|SOTG_FRAME_NUM_SOFR_MASK
value|0x7FF
end_define

begin_define
define|#
directive|define
name|SOTG_DCSCRATCH
value|0x278
end_define

begin_define
define|#
directive|define
name|SOTG_UNLOCK_DEVICE
value|0x27C
end_define

begin_define
define|#
directive|define
name|SOTG_UNLOCK_DEVICE_CODE
value|0xAA37
end_define

begin_define
define|#
directive|define
name|SOTG_IRQ_PULSE_WIDTH
value|0x280
end_define

begin_define
define|#
directive|define
name|SOTG_TEST_MODE
value|0x284
end_define

begin_define
define|#
directive|define
name|SOTG_TEST_MODE_FORCEHS
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|SOTG_TEST_MODE_FORCEFS
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|SOTG_TEST_MODE_PRBS
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SOTG_TEST_MODE_KSTATE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SOTG_TEST_MODE_JSTATE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SOTG_TEST_MODE_SE0_NAK
value|(1<< 0)
end_define

begin_comment
comment|/* Host controller specific registers */
end_comment

begin_define
define|#
directive|define
name|SOTG_FRINDEX
value|0x002c
end_define

begin_define
define|#
directive|define
name|SOTG_FRINDEX_MASK
value|0x3fff
end_define

begin_define
define|#
directive|define
name|SOTG_CONFIGFLAG
value|0x0060
end_define

begin_define
define|#
directive|define
name|SOTG_CONFIGFLAG_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SOTG_PORTSC1
value|0x0064
end_define

begin_define
define|#
directive|define
name|SOTG_PORTSC1_PIC
value|(3<< 14)
end_define

begin_define
define|#
directive|define
name|SOTG_PORTSC1_PO
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|SOTG_PORTSC1_PP
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|SOTG_PORTSC1_LS
value|(3<< 10)
end_define

begin_define
define|#
directive|define
name|SOTG_PORTSC1_PR
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|SOTG_PORTSC1_SUSP
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|SOTG_PORTSC1_FPR
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|SOTG_PORTSC1_PED
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SOTG_PORTSC1_ECSC
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SOTG_PORTSC1_ECCS
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SOTG_PTD_DW0
value|0
end_define

begin_define
define|#
directive|define
name|SOTG_PTD_DW0_VALID
value|1U
end_define

begin_define
define|#
directive|define
name|SOTG_PTD_DW1
value|4
end_define

begin_define
define|#
directive|define
name|SOTG_PTD_DW1_ENABLE_SPLIT
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|SOTG_PTD_DW2
value|8
end_define

begin_define
define|#
directive|define
name|SOTG_PTD_DW2_RL
value|(0xf<< 25)
end_define

begin_define
define|#
directive|define
name|SOTG_PTD_DW3
value|12
end_define

begin_define
define|#
directive|define
name|SOTG_PTD_DW3_NRL
value|(0xf<< 19)
end_define

begin_define
define|#
directive|define
name|SOTG_PTD_DW3_ACTIVE
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|SOTG_PTD_DW3_HALTED
value|(1U<< 30)
end_define

begin_define
define|#
directive|define
name|SOTG_PTD_DW3_ERRORS
value|(3U<< 28)
end_define

begin_define
define|#
directive|define
name|SOTG_PTD_DW3_CERR_3
value|(3U<< 23)
end_define

begin_define
define|#
directive|define
name|SOTG_PTD_DW3_CERR_2
value|(2U<< 23)
end_define

begin_comment
comment|/* infinite NAKs */
end_comment

begin_define
define|#
directive|define
name|SOTG_PTD_DW3_CERR_1
value|(1U<< 23)
end_define

begin_define
define|#
directive|define
name|SOTG_PTD_DW3_XFER_COUNT
value|0x7FFF
end_define

begin_define
define|#
directive|define
name|SOTG_PTD_DW4
value|16
end_define

begin_define
define|#
directive|define
name|SOTG_PTD_DW5
value|20
end_define

begin_define
define|#
directive|define
name|SOTG_PTD_DW6
value|24
end_define

begin_define
define|#
directive|define
name|SOTG_PTD_DW7
value|28
end_define

begin_define
define|#
directive|define
name|SOTG_DATA_ADDR
parameter_list|(
name|x
parameter_list|)
value|(0x1000 + (512 * (x)))
end_define

begin_define
define|#
directive|define
name|SOTG_ASYNC_PTD
parameter_list|(
name|x
parameter_list|)
value|(0xC00 + ((x) * 32))
end_define

begin_define
define|#
directive|define
name|SOTG_INTR_PTD
parameter_list|(
name|x
parameter_list|)
value|(0x800 + ((x) * 32))
end_define

begin_define
define|#
directive|define
name|SOTG_ISOC_PTD
parameter_list|(
name|x
parameter_list|)
value|(0x400 + ((x) * 32))
end_define

begin_define
define|#
directive|define
name|SOTG_PTD
parameter_list|(
name|x
parameter_list|)
value|(0x400 + ((x) * 32))
end_define

begin_define
define|#
directive|define
name|SOTG_HC_MEMORY_ADDR
parameter_list|(
name|x
parameter_list|)
value|(((x) - 0x400)>> 3)
end_define

begin_define
define|#
directive|define
name|SOTG_SW_RESET
value|0x30C
end_define

begin_define
define|#
directive|define
name|SOTG_SW_RESET_HC
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SOTG_SW_RESET_ALL
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SOTG_POWER_DOWN
value|0x354
end_define

begin_define
define|#
directive|define
name|SOTG_POWER_DOWN_PORT3_PD
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|SOTG_POWER_DOWN_PORT2_PD
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|SOTG_POWER_DOWN_VBATDET_PWR
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|SOTG_POWER_DOWN_BIAS_EN
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|SOTG_POWER_DOWN_VREG_ON
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|SOTG_POWER_DOWN_OC3_PWR
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SOTG_POWER_DOWN_OC2_PWR
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SOTG_POWER_DOWN_OC1_PWR
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SOTG_POWER_DOWN_HC_CLK_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SOTG_USBCMD
value|0x20
end_define

begin_define
define|#
directive|define
name|SOTG_USBCMD_LHCR
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|SOTG_USBCMD_HCRESET
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SOTG_USBCMD_RS
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SOTG_HCSCRATCH
value|0x308
end_define

begin_define
define|#
directive|define
name|SOTG_HCINTERRUPT
value|0x310
end_define

begin_define
define|#
directive|define
name|SOTG_HCINTERRUPT_OTG_IRQ
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|SOTG_HCINTERRUPT_ISO_IRQ
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|SOTG_HCINTERRUPT_ALT_IRQ
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|SOTG_HCINTERRUPT_INT_IRQ
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|SOTG_HCINTERRUPT_CLKREADY
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|SOTG_HCINTERRUPT_HCSUSP
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|SOTG_HCINTERRUPT_DMAEOTINT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SOTG_HCINTERRUPT_SOFITLINT
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SOTG_HCINTERRUPT_ENABLE
value|0x314
end_define

begin_define
define|#
directive|define
name|SOTG_ATL_PTD_DONE_PTD
value|0x150
end_define

begin_define
define|#
directive|define
name|SOTG_ATL_PTD_SKIP_PTD
value|0x154
end_define

begin_define
define|#
directive|define
name|SOTG_ATL_PTD_LAST_PTD
value|0x158
end_define

begin_define
define|#
directive|define
name|SOTG_INT_PTD_DONE_PTD
value|0x140
end_define

begin_define
define|#
directive|define
name|SOTG_INT_PTD_SKIP_PTD
value|0x144
end_define

begin_define
define|#
directive|define
name|SOTG_INT_PTD_LAST_PTD
value|0x148
end_define

begin_define
define|#
directive|define
name|SOTG_ISO_PTD_DONE_PTD
value|0x130
end_define

begin_define
define|#
directive|define
name|SOTG_ISO_PTD_SKIP_PTD
value|0x134
end_define

begin_define
define|#
directive|define
name|SOTG_ISO_PTD_LAST_PTD
value|0x138
end_define

begin_define
define|#
directive|define
name|SOTG_HCBUFFERSTATUS
value|0x334
end_define

begin_define
define|#
directive|define
name|SOTG_HCBUFFERSTATUS_ISO_BUF_FILL
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SOTG_HCBUFFERSTATUS_INT_BUF_FILL
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SOTG_HCBUFFERSTATUS_ATL_BUF_FILL
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SOTG_ISO_IRQ_MASK_OR
value|0x318
end_define

begin_define
define|#
directive|define
name|SOTG_INT_IRQ_MASK_OR
value|0x31C
end_define

begin_define
define|#
directive|define
name|SOTG_ATL_IRQ_MASK_OR
value|0x320
end_define

begin_define
define|#
directive|define
name|SOTG_ISO_IRQ_MASK_AND
value|0x324
end_define

begin_define
define|#
directive|define
name|SOTG_INT_IRQ_MASK_AND
value|0x328
end_define

begin_define
define|#
directive|define
name|SOTG_ATL_IRQ_MASK_AND
value|0x32C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SAF1761_OTG_REG_H_ */
end_comment

end_unit

