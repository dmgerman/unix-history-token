begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Ariff Abdullah<ariff@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATIIXP_H_
end_ifndef

begin_define
define|#
directive|define
name|_ATIIXP_H_
end_define

begin_comment
comment|/*  * Constants, pretty much FreeBSD specific.  */
end_comment

begin_comment
comment|/* Number of playback / recording channel */
end_comment

begin_define
define|#
directive|define
name|ATI_IXP_NPCHAN
value|1
end_define

begin_define
define|#
directive|define
name|ATI_IXP_NRCHAN
value|1
end_define

begin_define
define|#
directive|define
name|ATI_IXP_NCHANS
value|(ATI_IXP_NPCHAN + ATI_IXP_NRCHAN)
end_define

begin_comment
comment|/*  * Maximum segments/descriptors is 256, but 2 for  * each channel should be more than enough for us.  */
end_comment

begin_define
define|#
directive|define
name|ATI_IXP_DMA_CHSEGS
value|2
end_define

begin_define
define|#
directive|define
name|ATI_IXP_DMA_CHSEGS_MIN
value|2
end_define

begin_define
define|#
directive|define
name|ATI_IXP_DMA_CHSEGS_MAX
value|256
end_define

begin_define
define|#
directive|define
name|ATI_IXP_DEFAULT_BUFSZ
value|(1<< 13)
end_define

begin_comment
comment|/* 8192 */
end_comment

begin_define
define|#
directive|define
name|ATI_VENDOR_ID
value|0x1002
end_define

begin_comment
comment|/* ATI Technologies */
end_comment

begin_define
define|#
directive|define
name|ATI_IXP_200_ID
value|0x4341
end_define

begin_define
define|#
directive|define
name|ATI_IXP_300_ID
value|0x4361
end_define

begin_define
define|#
directive|define
name|ATI_IXP_400_ID
value|0x4370
end_define

begin_define
define|#
directive|define
name|ATI_IXP_BASE_RATE
value|48000
end_define

begin_comment
comment|/*   * Register definitions for ATI IXP  *  * References: ALSA snd-atiixp.c , OpenBSD/NetBSD auixp-*.h  */
end_comment

begin_define
define|#
directive|define
name|ATI_IXP_CODECS
value|3
end_define

begin_define
define|#
directive|define
name|ATI_REG_ISR
value|0x00
end_define

begin_comment
comment|/* interrupt source */
end_comment

begin_define
define|#
directive|define
name|ATI_REG_ISR_IN_XRUN
value|(1U<<0)
end_define

begin_define
define|#
directive|define
name|ATI_REG_ISR_IN_STATUS
value|(1U<<1)
end_define

begin_define
define|#
directive|define
name|ATI_REG_ISR_OUT_XRUN
value|(1U<<2)
end_define

begin_define
define|#
directive|define
name|ATI_REG_ISR_OUT_STATUS
value|(1U<<3)
end_define

begin_define
define|#
directive|define
name|ATI_REG_ISR_SPDF_XRUN
value|(1U<<4)
end_define

begin_define
define|#
directive|define
name|ATI_REG_ISR_SPDF_STATUS
value|(1U<<5)
end_define

begin_define
define|#
directive|define
name|ATI_REG_ISR_PHYS_INTR
value|(1U<<8)
end_define

begin_define
define|#
directive|define
name|ATI_REG_ISR_PHYS_MISMATCH
value|(1U<<9)
end_define

begin_define
define|#
directive|define
name|ATI_REG_ISR_CODEC0_NOT_READY
value|(1U<<10)
end_define

begin_define
define|#
directive|define
name|ATI_REG_ISR_CODEC1_NOT_READY
value|(1U<<11)
end_define

begin_define
define|#
directive|define
name|ATI_REG_ISR_CODEC2_NOT_READY
value|(1U<<12)
end_define

begin_define
define|#
directive|define
name|ATI_REG_ISR_NEW_FRAME
value|(1U<<13)
end_define

begin_define
define|#
directive|define
name|ATI_REG_IER
value|0x04
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|ATI_REG_IER_IN_XRUN_EN
value|(1U<<0)
end_define

begin_define
define|#
directive|define
name|ATI_REG_IER_IO_STATUS_EN
value|(1U<<1)
end_define

begin_define
define|#
directive|define
name|ATI_REG_IER_OUT_XRUN_EN
value|(1U<<2)
end_define

begin_define
define|#
directive|define
name|ATI_REG_IER_OUT_XRUN_COND
value|(1U<<3)
end_define

begin_define
define|#
directive|define
name|ATI_REG_IER_SPDF_XRUN_EN
value|(1U<<4)
end_define

begin_define
define|#
directive|define
name|ATI_REG_IER_SPDF_STATUS_EN
value|(1U<<5)
end_define

begin_define
define|#
directive|define
name|ATI_REG_IER_PHYS_INTR_EN
value|(1U<<8)
end_define

begin_define
define|#
directive|define
name|ATI_REG_IER_PHYS_MISMATCH_EN
value|(1U<<9)
end_define

begin_define
define|#
directive|define
name|ATI_REG_IER_CODEC0_INTR_EN
value|(1U<<10)
end_define

begin_define
define|#
directive|define
name|ATI_REG_IER_CODEC1_INTR_EN
value|(1U<<11)
end_define

begin_define
define|#
directive|define
name|ATI_REG_IER_CODEC2_INTR_EN
value|(1U<<12)
end_define

begin_define
define|#
directive|define
name|ATI_REG_IER_NEW_FRAME_EN
value|(1U<<13)
end_define

begin_comment
comment|/* (RO) */
end_comment

begin_define
define|#
directive|define
name|ATI_REG_IER_SET_BUS_BUSY
value|(1U<<14)
end_define

begin_comment
comment|/* (WO) audio is running */
end_comment

begin_define
define|#
directive|define
name|ATI_REG_CMD
value|0x08
end_define

begin_comment
comment|/* command */
end_comment

begin_define
define|#
directive|define
name|ATI_REG_CMD_POWERDOWN
value|(1U<<0)
end_define

begin_define
define|#
directive|define
name|ATI_REG_CMD_RECEIVE_EN
value|(1U<<1)
end_define

begin_define
define|#
directive|define
name|ATI_REG_CMD_SEND_EN
value|(1U<<2)
end_define

begin_define
define|#
directive|define
name|ATI_REG_CMD_STATUS_MEM
value|(1U<<3)
end_define

begin_define
define|#
directive|define
name|ATI_REG_CMD_SPDF_OUT_EN
value|(1U<<4)
end_define

begin_define
define|#
directive|define
name|ATI_REG_CMD_SPDF_STATUS_MEM
value|(1U<<5)
end_define

begin_define
define|#
directive|define
name|ATI_REG_CMD_SPDF_THRESHOLD
value|(3U<<6)
end_define

begin_define
define|#
directive|define
name|ATI_REG_CMD_SPDF_THRESHOLD_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|ATI_REG_CMD_IN_DMA_EN
value|(1U<<8)
end_define

begin_define
define|#
directive|define
name|ATI_REG_CMD_OUT_DMA_EN
value|(1U<<9)
end_define

begin_define
define|#
directive|define
name|ATI_REG_CMD_SPDF_DMA_EN
value|(1U<<10)
end_define

begin_define
define|#
directive|define
name|ATI_REG_CMD_SPDF_OUT_STOPPED
value|(1U<<11)
end_define

begin_define
define|#
directive|define
name|ATI_REG_CMD_SPDF_CONFIG_MASK
value|(7U<<12)
end_define

begin_define
define|#
directive|define
name|ATI_REG_CMD_SPDF_CONFIG_34
value|(1U<<12)
end_define

begin_define
define|#
directive|define
name|ATI_REG_CMD_SPDF_CONFIG_78
value|(2U<<12)
end_define

begin_define
define|#
directive|define
name|ATI_REG_CMD_SPDF_CONFIG_69
value|(3U<<12)
end_define

begin_define
define|#
directive|define
name|ATI_REG_CMD_SPDF_CONFIG_01
value|(4U<<12)
end_define

begin_define
define|#
directive|define
name|ATI_REG_CMD_INTERLEAVE_SPDF
value|(1U<<16)
end_define

begin_define
define|#
directive|define
name|ATI_REG_CMD_AUDIO_PRESENT
value|(1U<<20)
end_define

begin_define
define|#
directive|define
name|ATI_REG_CMD_INTERLEAVE_IN
value|(1U<<21)
end_define

begin_define
define|#
directive|define
name|ATI_REG_CMD_INTERLEAVE_OUT
value|(1U<<22)
end_define

begin_define
define|#
directive|define
name|ATI_REG_CMD_LOOPBACK_EN
value|(1U<<23)
end_define

begin_define
define|#
directive|define
name|ATI_REG_CMD_PACKED_DIS
value|(1U<<24)
end_define

begin_define
define|#
directive|define
name|ATI_REG_CMD_BURST_EN
value|(1U<<25)
end_define

begin_define
define|#
directive|define
name|ATI_REG_CMD_PANIC_EN
value|(1U<<26)
end_define

begin_define
define|#
directive|define
name|ATI_REG_CMD_MODEM_PRESENT
value|(1U<<27)
end_define

begin_define
define|#
directive|define
name|ATI_REG_CMD_ACLINK_ACTIVE
value|(1U<<28)
end_define

begin_define
define|#
directive|define
name|ATI_REG_CMD_AC_SOFT_RESET
value|(1U<<29)
end_define

begin_define
define|#
directive|define
name|ATI_REG_CMD_AC_SYNC
value|(1U<<30)
end_define

begin_define
define|#
directive|define
name|ATI_REG_CMD_AC_RESET
value|(1U<<31)
end_define

begin_define
define|#
directive|define
name|ATI_REG_PHYS_OUT_ADDR
value|0x0c
end_define

begin_define
define|#
directive|define
name|ATI_REG_PHYS_OUT_CODEC_MASK
value|(3U<<0)
end_define

begin_define
define|#
directive|define
name|ATI_REG_PHYS_OUT_RW
value|(1U<<2)
end_define

begin_define
define|#
directive|define
name|ATI_REG_PHYS_OUT_ADDR_EN
value|(1U<<8)
end_define

begin_define
define|#
directive|define
name|ATI_REG_PHYS_OUT_ADDR_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|ATI_REG_PHYS_OUT_DATA_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ATI_REG_PHYS_IN_ADDR
value|0x10
end_define

begin_define
define|#
directive|define
name|ATI_REG_PHYS_IN_READ_FLAG
value|(1U<<8)
end_define

begin_define
define|#
directive|define
name|ATI_REG_PHYS_IN_ADDR_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|ATI_REG_PHYS_IN_DATA_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ATI_REG_SLOTREQ
value|0x14
end_define

begin_define
define|#
directive|define
name|ATI_REG_COUNTER
value|0x18
end_define

begin_define
define|#
directive|define
name|ATI_REG_COUNTER_SLOT
value|(3U<<0)
end_define

begin_comment
comment|/* slot # */
end_comment

begin_define
define|#
directive|define
name|ATI_REG_COUNTER_BITCLOCK
value|(31U<<8)
end_define

begin_define
define|#
directive|define
name|ATI_REG_IN_FIFO_THRESHOLD
value|0x1c
end_define

begin_define
define|#
directive|define
name|ATI_REG_IN_DMA_LINKPTR
value|0x20
end_define

begin_define
define|#
directive|define
name|ATI_REG_IN_DMA_DT_START
value|0x24
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|ATI_REG_IN_DMA_DT_NEXT
value|0x28
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|ATI_REG_IN_DMA_DT_CUR
value|0x2c
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|ATI_REG_IN_DMA_DT_SIZE
value|0x30
end_define

begin_define
define|#
directive|define
name|ATI_REG_OUT_DMA_SLOT
value|0x34
end_define

begin_define
define|#
directive|define
name|ATI_REG_OUT_DMA_SLOT_BIT
parameter_list|(
name|x
parameter_list|)
value|(1U<< ((x) - 3))
end_define

begin_define
define|#
directive|define
name|ATI_REG_OUT_DMA_SLOT_MASK
value|0x1ff
end_define

begin_define
define|#
directive|define
name|ATI_REG_OUT_DMA_THRESHOLD_MASK
value|0xf800
end_define

begin_define
define|#
directive|define
name|ATI_REG_OUT_DMA_THRESHOLD_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|ATI_REG_OUT_DMA_LINKPTR
value|0x38
end_define

begin_define
define|#
directive|define
name|ATI_REG_OUT_DMA_DT_START
value|0x3c
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|ATI_REG_OUT_DMA_DT_NEXT
value|0x40
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|ATI_REG_OUT_DMA_DT_CUR
value|0x44
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|ATI_REG_OUT_DMA_DT_SIZE
value|0x48
end_define

begin_define
define|#
directive|define
name|ATI_REG_SPDF_CMD
value|0x4c
end_define

begin_define
define|#
directive|define
name|ATI_REG_SPDF_CMD_LFSR
value|(1U<<4)
end_define

begin_define
define|#
directive|define
name|ATI_REG_SPDF_CMD_SINGLE_CH
value|(1U<<5)
end_define

begin_define
define|#
directive|define
name|ATI_REG_SPDF_CMD_LFSR_ACC
value|(0xff<<8)
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|ATI_REG_SPDF_DMA_LINKPTR
value|0x50
end_define

begin_define
define|#
directive|define
name|ATI_REG_SPDF_DMA_DT_START
value|0x54
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|ATI_REG_SPDF_DMA_DT_NEXT
value|0x58
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|ATI_REG_SPDF_DMA_DT_CUR
value|0x5c
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|ATI_REG_SPDF_DMA_DT_SIZE
value|0x60
end_define

begin_define
define|#
directive|define
name|ATI_REG_MODEM_MIRROR
value|0x7c
end_define

begin_define
define|#
directive|define
name|ATI_REG_AUDIO_MIRROR
value|0x80
end_define

begin_define
define|#
directive|define
name|ATI_REG_6CH_REORDER
value|0x84
end_define

begin_comment
comment|/* reorder slots for 6ch */
end_comment

begin_define
define|#
directive|define
name|ATI_REG_6CH_REORDER_EN
value|(1U<<0)
end_define

begin_comment
comment|/* 3,4,7,8,6,9 -> 3,4,6,9,7,8 */
end_comment

begin_define
define|#
directive|define
name|ATI_REG_FIFO_FLUSH
value|0x88
end_define

begin_define
define|#
directive|define
name|ATI_REG_FIFO_OUT_FLUSH
value|(1U<<0)
end_define

begin_define
define|#
directive|define
name|ATI_REG_FIFO_IN_FLUSH
value|(1U<<1)
end_define

begin_comment
comment|/* LINKPTR */
end_comment

begin_define
define|#
directive|define
name|ATI_REG_LINKPTR_EN
value|(1U<<0)
end_define

begin_comment
comment|/* [INT|OUT|SPDIF]_DMA_DT_SIZE */
end_comment

begin_define
define|#
directive|define
name|ATI_REG_DMA_DT_SIZE
value|(0xffffU<<0)
end_define

begin_define
define|#
directive|define
name|ATI_REG_DMA_FIFO_USED
value|(0x1fU<<16)
end_define

begin_define
define|#
directive|define
name|ATI_REG_DMA_FIFO_FREE
value|(0x1fU<<21)
end_define

begin_define
define|#
directive|define
name|ATI_REG_DMA_STATE
value|(7U<<26)
end_define

begin_define
define|#
directive|define
name|ATI_MAX_DESCRIPTORS
value|256
end_define

begin_comment
comment|/* max number of descriptor packets */
end_comment

begin_comment
comment|/* codec detection constant indicating the interrupt flags */
end_comment

begin_define
define|#
directive|define
name|ALL_CODECS_NOT_READY
define|\
value|(ATI_REG_ISR_CODEC0_NOT_READY | ATI_REG_ISR_CODEC1_NOT_READY |\      ATI_REG_ISR_CODEC2_NOT_READY)
end_define

begin_define
define|#
directive|define
name|CODEC_CHECK_BITS
value|(ALL_CODECS_NOT_READY|ATI_REG_ISR_NEW_FRAME)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

